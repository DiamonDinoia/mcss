#include "stdsimheader.h"
#include "secondKernel.h"

namespace maxcompilersim {

secondKernel::secondKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 18, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x0000000cl))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x100000000l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_flt_8_24_bits((HWFloat<8,24>(varint_u<32>(0x00000000l))))
, c_hw_flt_8_24_bits_1((HWFloat<8,24>(varint_u<32>(0x41200000l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
{
  { // Node ID: 32 (NodeConstantRawBits)
    id32out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 41 (NodeConstantRawBits)
    id41out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 33 (NodeOutput)
    m_internal_watch_llv_output = registerOutput("internal_watch_llv_output",1 );
  }
  { // Node ID: 36 (NodeConstantRawBits)
    id36out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 5 (NodeConstantRawBits)
    id5out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 34 (NodeOutput)
    m_internal_watch_countloopkernel_output = registerOutput("internal_watch_countloopkernel_output",2 );
  }
  { // Node ID: 10 (NodeConstantRawBits)
    id10out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 12 (NodeConstantRawBits)
    id12out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 9 (NodeInput)
     m_y =  registerInput("y",0,5);
  }
  { // Node ID: 1 (NodeConstantRawBits)
    id1out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 18 (NodeInputMappedReg)
    registerMappedRegister("io_z_force_disabled", Data(1));
  }
  { // Node ID: 21 (NodeOutput)
    m_z = registerOutput("z",0 );
  }
  { // Node ID: 26 (NodeConstantRawBits)
    id26out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 35 (NodeConstantRawBits)
    id35out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 23 (NodeConstantRawBits)
    id23out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 27 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 0 (NodeConstantRawBits)
    id0out_value = (c_hw_fix_1_0_uns_bits_1);
  }
}

void secondKernel::ramInitialise() {
}

void secondKernel::resetComputation() {
  resetComputationAfterFlush();
}

void secondKernel::resetComputationAfterFlush() {
  { // Node ID: 6 (NodeCounter)

    (id6st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 11 (NodePulse)

    (id11st_count) = (0l);
    (id11st_value) = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 9 (NodeInput)

    (id9st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id9st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 18 (NodeInputMappedReg)
    id18out_io_z_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_z_force_disabled");
  }
  { // Node ID: 40 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id40out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 24 (NodeCounter)

    (id24st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
}

void secondKernel::updateState() {
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 18 (NodeInputMappedReg)
    id18out_io_z_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_z_force_disabled");
  }
}

void secondKernel::preExecute() {
  { // Node ID: 9 (NodeInput)
    if(((needsToReadInput(m_y))&(((getFlushLevel())<((0l)+(5)))|(!(isFlushingActive()))))) {
      (id9st_last_read_value) = (readInput<HWFloat<8,24> >(m_y));
    }
    id9out_data = (id9st_last_read_value);
  }
}

void secondKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "secondKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int secondKernel::getFlushLevelStart() {
  return ((0l)+(0l));
}

}
