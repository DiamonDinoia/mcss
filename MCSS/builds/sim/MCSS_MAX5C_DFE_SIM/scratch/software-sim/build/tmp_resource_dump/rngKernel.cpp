#include "stdsimheader.h"
#include "rngKernel.h"

namespace maxcompilersim {

rngKernel::rngKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 402, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_11_0_uns_bits((HWOffsetFix<11,0,UNSIGNED>(varint_u<11>(0x270l))))
, c_hw_fix_11_0_uns_bits_1((HWOffsetFix<11,0,UNSIGNED>(varint_u<11>(0x000l))))
, c_hw_fix_11_0_uns_bits_2((HWOffsetFix<11,0,UNSIGNED>(varint_u<11>(0x001l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_10_0_uns_bits((HWOffsetFix<10,0,UNSIGNED>(varint_u<10>(0x270l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x9908b0dfl))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x9d2c5680l))))
, c_hw_fix_32_0_uns_bits_3((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0xefc60000l))))
, c_hw_flt_8_24_2_3283064365386963En10val((HWFloat<8,24>(varint_u<32>(0x2f800000l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
{
  { // Node ID: 164 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 226 (NodeConstantRawBits)
    id226out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 225 (NodeConstantRawBits)
    id225out_value = (c_hw_fix_11_0_uns_bits);
  }
  { // Node ID: 224 (NodeConstantRawBits)
    id224out_value = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 107 (NodeMappedRom)
    registerMappedMemory("rngKernelgen3_seeds0", 32, 624);
  }
  { // Node ID: 144 (NodeConstantRawBits)
    id144out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 223 (NodeConstantRawBits)
    id223out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 222 (NodeConstantRawBits)
    id222out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 221 (NodeConstantRawBits)
    id221out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 219 (NodeConstantRawBits)
    id219out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 218 (NodeConstantRawBits)
    id218out_value = (c_hw_fix_11_0_uns_bits);
  }
  { // Node ID: 217 (NodeConstantRawBits)
    id217out_value = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 56 (NodeMappedRom)
    registerMappedMemory("rngKernelgen2_seeds0", 32, 624);
  }
  { // Node ID: 93 (NodeConstantRawBits)
    id93out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 216 (NodeConstantRawBits)
    id216out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 215 (NodeConstantRawBits)
    id215out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 214 (NodeConstantRawBits)
    id214out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 212 (NodeConstantRawBits)
    id212out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 211 (NodeConstantRawBits)
    id211out_value = (c_hw_fix_11_0_uns_bits);
  }
  { // Node ID: 210 (NodeConstantRawBits)
    id210out_value = (c_hw_fix_10_0_uns_bits);
  }
  { // Node ID: 5 (NodeMappedRom)
    registerMappedMemory("rngKernelgen1_seeds0", 32, 624);
  }
  { // Node ID: 42 (NodeConstantRawBits)
    id42out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 209 (NodeConstantRawBits)
    id209out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 208 (NodeConstantRawBits)
    id208out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 207 (NodeConstantRawBits)
    id207out_value = (c_hw_fix_32_0_uns_bits_3);
  }
  { // Node ID: 167 (NodeOutput)
    m_y = registerOutput("y",0 );
  }
  { // Node ID: 177 (NodeConstantRawBits)
    id177out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 205 (NodeConstantRawBits)
    id205out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 174 (NodeConstantRawBits)
    id174out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 178 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 0 (NodeConstantRawBits)
    id0out_value = (c_hw_fix_1_0_uns_bits_1);
  }
}

void rngKernel::ramInitialise() {
}

void rngKernel::resetComputation() {
  resetComputationAfterFlush();
}

void rngKernel::resetComputationAfterFlush() {
  { // Node ID: 164 (NodeInputMappedReg)
    id164out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 105 (NodeCounter)

    (id105st_count) = (c_hw_fix_11_0_uns_bits_1);
  }
  { // Node ID: 233 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id233out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 230 (NodeFIFO)

    for(int i=0; i<397; i++)
    {
      id230out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 232 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id232out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 234 (NodeFIFO)

    for(int i=0; i<225; i++)
    {
      id234out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 235 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id235out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 236 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id236out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 54 (NodeCounter)

    (id54st_count) = (c_hw_fix_11_0_uns_bits_1);
  }
  { // Node ID: 240 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id240out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 237 (NodeFIFO)

    for(int i=0; i<397; i++)
    {
      id237out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 239 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id239out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 241 (NodeFIFO)

    for(int i=0; i<225; i++)
    {
      id241out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 242 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id242out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 243 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id243out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 3 (NodeCounter)

    (id3st_count) = (c_hw_fix_11_0_uns_bits_1);
  }
  { // Node ID: 247 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id247out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 244 (NodeFIFO)

    for(int i=0; i<397; i++)
    {
      id244out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 246 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id246out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 248 (NodeFIFO)

    for(int i=0; i<225; i++)
    {
      id248out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 249 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id249out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 250 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id250out_output[i] = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 175 (NodeCounter)

    (id175st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
}

void rngKernel::updateState() {
  { // Node ID: 164 (NodeInputMappedReg)
    id164out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
}

void rngKernel::preExecute() {
}

void rngKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "rngKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int rngKernel::getFlushLevelStart() {
  return ((0l)+(0l));
}

}
