#ifndef SECONDKERNEL_H_
#define SECONDKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class secondKernel : public KernelManagerBlockSync {
public:
  secondKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void ramInitialise();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_internal_watch_llv_output;
  t_port_number m_internal_watch_countloopkernel_output;
  t_port_number m_y;
  t_port_number m_z;
  HWOffsetFix<1,0,UNSIGNED> id32out_value;

  HWOffsetFix<32,0,UNSIGNED> id41out_value;

  HWOffsetFix<1,0,UNSIGNED> id36out_value;

  HWOffsetFix<33,0,UNSIGNED> id5out_value;

  HWOffsetFix<32,0,UNSIGNED> id6out_count;
  HWOffsetFix<1,0,UNSIGNED> id6out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id6st_count;

  HWOffsetFix<1,0,UNSIGNED> id10out_value;

  HWOffsetFix<1,0,UNSIGNED> id11out_output;

  long id11st_count;
  HWOffsetFix<1,0,UNSIGNED> id11st_value;

  HWFloat<8,24> id12out_value;

  HWFloat<8,24> id13out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id7out_io_y_force_disabled;

  HWFloat<8,24> id9out_data;

  HWOffsetFix<1,0,UNSIGNED> id9st_read_next_cycle;
  HWFloat<8,24> id9st_last_read_value;

  HWFloat<8,24> id15out_result[12];

  HWFloat<8,24> id1out_value;

  HWOffsetFix<1,0,UNSIGNED> id17out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id18out_io_z_force_disabled;

  HWFloat<8,24> id40out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id26out_value;

  HWOffsetFix<1,0,UNSIGNED> id35out_value;

  HWOffsetFix<49,0,UNSIGNED> id23out_value;

  HWOffsetFix<48,0,UNSIGNED> id24out_count;
  HWOffsetFix<1,0,UNSIGNED> id24out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id24st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_value;

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* SECONDKERNEL_H_ */
