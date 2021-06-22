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
	
	DFEVar sampleCosTheta(double theScrPar2, DFEVar randNum) {
	    DFEVar cost = 1.0 - 2 * theScrPar2 * randNum / (1.0 - randNum + theScrPar2);
	    return KernelMath.max(constant.var(dfeFloat(8, 24), -1.0),  KernelMath.min(constant.var(dfeFloat(8, 24), 1.0), cost));
	}
	
	public LoopKernel(final KernelParameters parameters) {
		super(parameters);

		flush.disabled();
		
		OffsetExpr loopLength = stream.makeOffsetAutoLoop("loopLength");
		DFEVar loopLengthVal = loopLength.getDFEVar(this, dfeUInt(32));
//		loopLengthVal.simWatch("llv");
		
		DFEVar p = control.count.pulse(1);
		DFEVar count = control.count.simpleCounter(32, loopLengthVal);
//		DFEVar correctTick = KernelMath.modulo(count, 90) === 0;
		
		DFEVar carriedPosX = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedPosY = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedPosZ = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedDirX = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedDirY = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedDirZ = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedTrackLength = dfeFloat(8, 24).newInstance(this);
		DFEVar carriedLength = dfeFloat(8, 24).newInstance(this);
		
		DFEVar reset = carriedLength > Constants.theLimit | p;
//		carriedPosX.simWatch("carriedPosX");
//		carriedPosZ.simWatch("carriedPosZ");
//		carriedDirX.simWatch("carriedDirX");
//		carriedLength.simWatch("carriedLength");
		DFEVar posX = reset ? 0.0 : carriedPosX;
		DFEVar posY = reset ? 0.0 : carriedPosY;
		DFEVar posZ = reset ? 0.0 : carriedPosZ;
		DFEVar dirX = reset ? 0.0 : carriedDirX;
		DFEVar dirY = reset ? 0.0 : carriedDirY;
		DFEVar dirZ = reset ? 1.0 : carriedDirZ;
		DFEVar trackLength = reset ? 0.0 : carriedTrackLength;
		DFEVar length = reset ? 0.0 : carriedLength;
		
//		posZ.simWatch("posZ");
//		dirX.simWatch("dirX");
		
//		trackLength.simWatch("trackLength"); //
		
		DFEVectorType<DFEVar> randNumType = new DFEVectorType<DFEVar>(dfeFloat(8, 24), 3);
		DFEVector<DFEVar> randNums = io.input("y", randNumType, count === 0);
		DFEVar stepLength = -Constants.theMFP * Arithmetic.log(randNums[0]);
		length += stepLength;
		DFEVar pastLimit = length > Constants.theLimit;
//		reset.simWatch("reset");
//		pastLimit.simWatch("pastLimit");
		stepLength = pastLimit ? Constants.theLimit - trackLength : stepLength;
		
		posX += dirX * stepLength;
		posY += dirY * stepLength;
		posZ += dirZ * stepLength;
		trackLength += stepLength;
//		debug.simPrintf(count === (loopLengthVal - 1), "%f %i\n", trackLength, pastLimit);
		
		DFEVar cost = sampleCosTheta(Constants.theScrPar, randNums[1]);
		DFEVar dum0 = 1.0 - cost;
		DFEVar sint = KernelMath.sqrt(dum0 * (2.0 - dum0));
		DFEVar phi = 2.0 * Constants.pi * randNums[2];
		DFEVar u1 = sint * Trigonometric.cos(phi);
		DFEVar u2 = sint * Trigonometric.sin(phi);
		DFEVar u3 = cost;
		
//		u1.simWatch("u1");
//		u2.simWatch("u2");
//		u3.simWatch("u3");
//		debug.simPrintf("U %.10f %.10f %.10f\n", u1, u2, u3);
	
		DFEVar up = dirX * dirX + dirY * dirY;
		DFEVar upGreater = up > 0.0;
		up = ~pastLimit & upGreater ? KernelMath.sqrt(up) : up;
		DFEVar px = u1;
		DFEVar py = u2;
		DFEVar pz = u3;
		u1 = ~pastLimit & upGreater ? (dirX * dirZ * px - dirY * py) / up + dirX * pz : u1;
		u2 = ~pastLimit & upGreater ? (dirY * dirZ * px + dirX * py) / up + dirY * pz : u2;
		u3 = ~pastLimit & upGreater ? -up * px + dirZ * pz : u3;
		
//		u1.simWatch("v1");
//		u2.simWatch("v2");
//		u3.simWatch("v3");
//		debug.simPrintf("V %.10f %.10f %.10f\n", u1, u2, u3);
		
		DFEVar yLess = dirZ < 0.0 & ~upGreater;
		u1 = ~pastLimit & yLess ? -u1 : u1;
		u3 = ~pastLimit & yLess ? -u3 : u3;
		
//		u1.simWatch("w1");
//		u2.simWatch("w2");
//		u3.simWatch("w3");
//		debug.simPrintf("W %.10f %.10f %.10f\n\n", u1, u2, u3);
		
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
//		lengthOffset.simWatch("lengthOffset");
		
		track[0] <== posX;
		track[1] <== posY;
		track[2] <== posZ;
		track[3] <== trackLength;
		
//		debug.simPrintf(count === (loopLengthVal - 1), "%f %.10f %.10f %f %f %i\n", Constants.theLimit, trackLength, length, lengthOffset, trackLengthOffset, length > Constants.theLimit);
//		debug.simPrintf(count === (loopLengthVal - 1), "%.10f %.10f %.10f %.10f\n\n", track[0], track[1], track[2], track[3]);
//		length.simWatch("length");
//		track.simWatch("track");
		
		// Output
		io.output("z", track, trackType, pastLimit & count === (loopLengthVal - 1));
//		io.output("z", track, trackType, count === (loopLengthVal - 1));
	}

}