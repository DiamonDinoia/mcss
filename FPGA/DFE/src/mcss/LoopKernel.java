package mcss;

import maxpower.math.functions.Arithmetic;
import maxpower.math.functions.Trigonometric;

import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;
import com.maxeler.maxcompiler.v2.kernelcompiler.KernelParameters;
import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.KernelMath;
import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.core.Stream.OffsetExpr;
import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar;
import com.maxeler.maxcompiler.v2.kernelcompiler.types.composite.DFEVector;
import com.maxeler.maxcompiler.v2.kernelcompiler.types.composite.DFEVectorType;

public class LoopKernel extends Kernel {
	
	DFEVar sampleCosTheta(DFEVar theScrPar2, DFEVar randNum) {
	    DFEVar cost = 1.0 - 2 * theScrPar2 * randNum / (1.0 - randNum + theScrPar2);
	    return KernelMath.max(constant.var(dfeFloat(8, 24), -1.0),  KernelMath.min(constant.var(dfeFloat(8, 24), 1.0), cost));
	}
	
	DFEVar computeScrParam(DFEVar molierBc, DFEVar molierXc2, double ptot2) {
		return molierXc2 / (4.0 * ptot2 * molierBc);
	}
	
	DFEVar computeMFP(DFEVar molierBc,  double beta2, DFEVar scrpar) {
		return beta2 * (1.0 + scrpar) / molierBc;
	}
	
	public LoopKernel(final KernelParameters parameters) {
		super(parameters);

		flush.disabled();
		
		DFEVar molierBc = io.scalarInput("molierBc", dfeFloat(8, 24));
		DFEVar molierXc2 = io.scalarInput("molierXc2", dfeFloat(8, 24));
		DFEVar theScrPar = computeScrParam(molierBc, molierXc2, Constants.thePC2);
		DFEVar theMFP = computeMFP(molierBc, Constants.theBeta2, theScrPar);
		DFEVar theLimit = theMFP * 33.5;
		
		OffsetExpr loopLength = stream.makeOffsetAutoLoop("loopLength");
		DFEVar loopLengthVal = loopLength.getDFEVar(this, dfeUInt(32));
		
		DFEVar count = control.count.simpleCounter(32);
		DFEVar init = count <= loopLengthVal;
		
		DFEVar carriedPosX = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedPosY = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedPosZ = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedDirX = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedDirY = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedDirZ = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedTrackLength = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedLength = dfeFloat(8, 24).newInstance(this);
		
		DFEVar reset = carriedLength > theLimit | init;
		DFEVar posX = reset ? 0.0 : carriedPosX;
		DFEVar posY = reset ? 0.0 : carriedPosY;
		DFEVar posZ = reset ? 0.0 : carriedPosZ;
		DFEVar dirX = reset ? 0.0 : carriedDirX;
		DFEVar dirY = reset ? 0.0 : carriedDirY;
		DFEVar dirZ = reset ? 1.0 : carriedDirZ;
		DFEVar trackLength = reset ? 0.0 : carriedTrackLength;
		DFEVar length = reset ? 0.0 : carriedLength;
		
		DFEVectorType<DFEVar> randNumType = new DFEVectorType<DFEVar>(dfeFloat(8, 24), 3);
		DFEVector<DFEVar> randNums = io.input("y", randNumType);
		DFEVar stepLength = -theMFP * Arithmetic.log(randNums[0]);
		length += stepLength;
		DFEVar pastLimit = length > theLimit;
		stepLength = pastLimit ? theLimit - trackLength : stepLength;
		
		posX += dirX * stepLength;
		posY += dirY * stepLength;
		posZ += dirZ * stepLength;
		trackLength += stepLength;
		
		DFEVar cost = sampleCosTheta(theScrPar, randNums[1]);
		DFEVar dum0 = 1.0 - cost;
		DFEVar sint = KernelMath.sqrt(dum0 * (2.0 - dum0));
		DFEVar phi = 2.0 * Constants.pi * randNums[2];
		DFEVar u1 = sint * Trigonometric.cos(phi);
		DFEVar u2 = sint * Trigonometric.sin(phi);
		DFEVar u3 = cost;
	
		DFEVar up = dirX * dirX + dirY * dirY;
		DFEVar upGreater = up > 0.0;
		up = ~pastLimit & upGreater ? KernelMath.sqrt(up) : up;
		DFEVar px = u1;
		DFEVar py = u2;
		DFEVar pz = u3;
		u1 = ~pastLimit & upGreater ? (dirX * dirZ * px - dirY * py) / up + dirX * pz : u1;
		u2 = ~pastLimit & upGreater ? (dirY * dirZ * px + dirX * py) / up + dirY * pz : u2;
		u3 = ~pastLimit & upGreater ? -up * px + dirZ * pz : u3;
		
		DFEVar yLess = dirZ < 0.0 & ~upGreater;
		u1 = ~pastLimit & yLess ? -u1 : u1;
		u3 = ~pastLimit & yLess ? -u3 : u3;
		
		dirX = ~pastLimit ? u1 : dirX;
		dirY = ~pastLimit ? u2 : dirY;
		dirZ = ~pastLimit ? u3 : dirZ;
		
		DFEVectorType<DFEVar> trackType = new DFEVectorType<DFEVar>(dfeFloat(8, 24), 4);
		DFEVector<DFEVar> track = trackType.newInstance(this);
		
		DFEVar posXOffset = stream.offset(posX, -loopLength);
		DFEVar posYOffset = stream.offset(posY, -loopLength);
		DFEVar posZOffset = stream.offset(posZ, -loopLength);
		DFEVar dirXOffset = stream.offset(dirX, -loopLength);
		DFEVar dirYOffset = stream.offset(dirY, -loopLength);
		DFEVar dirZOffset = stream.offset(dirZ, -loopLength);
		DFEVar trackLengthOffset = stream.offset(trackLength, -loopLength);
		DFEVar lengthOffset = stream.offset(length, -loopLength);
		
		carriedPosX <== posXOffset;
		carriedPosY <== posYOffset;
		carriedPosZ <== posZOffset;
		carriedDirX <== dirXOffset;
		carriedDirY <== dirYOffset;
		carriedDirZ <== dirZOffset;
		carriedTrackLength <== trackLengthOffset;
		carriedLength <== lengthOffset;
		
		track[0] <== posX;
		track[1] <== posY;
		track[2] <== posZ;
		track[3] <== trackLength;
		
		io.output("z", track, trackType, pastLimit);
	}

}