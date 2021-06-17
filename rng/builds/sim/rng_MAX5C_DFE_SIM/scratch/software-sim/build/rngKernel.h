#ifndef RNGKERNEL_H_
#define RNGKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class rngKernel : public KernelManagerBlockSync {
public:
  rngKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void ramInitialise();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_y;
  HWOffsetFix<1,0,UNSIGNED> id152out_io_y_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id218out_value;

  HWOffsetFix<11,0,UNSIGNED> id217out_value;

  HWOffsetFix<10,0,UNSIGNED> id3out_count;
  HWOffsetFix<1,0,UNSIGNED> id3out_wrap;

  HWOffsetFix<11,0,UNSIGNED> id3st_count;

  HWOffsetFix<10,0,UNSIGNED> id216out_value;

  HWOffsetFix<1,0,UNSIGNED> id171out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id225out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id9out_dataa[3];

  HWOffsetFix<32,0,UNSIGNED> id222out_output[397];

  HWRawBits<1> id224out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id123out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id116out_value;

  HWOffsetFix<32,0,UNSIGNED> id215out_value;

  HWOffsetFix<32,0,UNSIGNED> id120out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id126out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id226out_output[225];

  HWOffsetFix<32,0,UNSIGNED> id17out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id29out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id227out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id214out_value;

  HWOffsetFix<32,0,UNSIGNED> id44out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id47out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id228out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id213out_value;

  HWOffsetFix<32,0,UNSIGNED> id62out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id65out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id77out_result[2];

  HWFloat<8,24> id144out_o[6];

  HWFloat<8,24> id219out_floatOut[2];

  HWOffsetFix<32,0,UNSIGNED> id7out_dataa[3];

  HWOffsetFix<32,0,UNSIGNED> id229out_output[397];

  HWRawBits<1> id231out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id122out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id119out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id125out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id233out_output[225];

  HWOffsetFix<32,0,UNSIGNED> id16out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id28out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id234out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id211out_value;

  HWOffsetFix<32,0,UNSIGNED> id42out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id46out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id235out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id210out_value;

  HWOffsetFix<32,0,UNSIGNED> id60out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id64out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id76out_result[2];

  HWFloat<8,24> id143out_o[6];

  HWFloat<8,24> id220out_floatOut[2];

  HWOffsetFix<32,0,UNSIGNED> id5out_dataa[3];

  HWOffsetFix<32,0,UNSIGNED> id236out_output[397];

  HWRawBits<1> id238out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id121out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id118out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id124out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id240out_output[225];

  HWOffsetFix<32,0,UNSIGNED> id15out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id27out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id241out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id208out_value;

  HWOffsetFix<32,0,UNSIGNED> id40out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id45out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id242out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id207out_value;

  HWOffsetFix<32,0,UNSIGNED> id58out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id63out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id75out_result[2];

  HWFloat<8,24> id142out_o[6];

  HWFloat<8,24> id221out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id165out_value;

  HWOffsetFix<1,0,UNSIGNED> id205out_value;

  HWOffsetFix<49,0,UNSIGNED> id162out_value;

  HWOffsetFix<48,0,UNSIGNED> id163out_count;
  HWOffsetFix<1,0,UNSIGNED> id163out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id163st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_value;

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<11,0,UNSIGNED> c_hw_fix_11_0_uns_bits;
  const HWOffsetFix<11,0,UNSIGNED> c_hw_fix_11_0_uns_bits_1;
  const HWOffsetFix<11,0,UNSIGNED> c_hw_fix_11_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<10,0,UNSIGNED> c_hw_fix_10_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_3;
  const HWFloat<8,24> c_hw_flt_8_24_2_3283064365386963En10val;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* RNGKERNEL_H_ */
