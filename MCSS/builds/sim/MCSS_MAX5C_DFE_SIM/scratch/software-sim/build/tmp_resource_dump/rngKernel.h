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
  HWOffsetFix<1,0,UNSIGNED> id164out_io_y_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id226out_value;

  HWOffsetFix<11,0,UNSIGNED> id225out_value;

  HWOffsetFix<10,0,UNSIGNED> id105out_count;
  HWOffsetFix<1,0,UNSIGNED> id105out_wrap;

  HWOffsetFix<11,0,UNSIGNED> id105st_count;

  HWOffsetFix<10,0,UNSIGNED> id224out_value;

  HWOffsetFix<1,0,UNSIGNED> id183out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id233out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id107out_dataa[3];

  HWOffsetFix<32,0,UNSIGNED> id230out_output[397];

  HWRawBits<1> id232out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id147out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id144out_value;

  HWOffsetFix<32,0,UNSIGNED> id223out_value;

  HWOffsetFix<32,0,UNSIGNED> id146out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id148out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id234out_output[225];

  HWOffsetFix<32,0,UNSIGNED> id111out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id115out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id235out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id222out_value;

  HWOffsetFix<32,0,UNSIGNED> id120out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id121out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id236out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id221out_value;

  HWOffsetFix<32,0,UNSIGNED> id126out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id127out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id131out_result[2];

  HWFloat<8,24> id160out_o[6];

  HWFloat<8,24> id227out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id219out_value;

  HWOffsetFix<11,0,UNSIGNED> id218out_value;

  HWOffsetFix<10,0,UNSIGNED> id54out_count;
  HWOffsetFix<1,0,UNSIGNED> id54out_wrap;

  HWOffsetFix<11,0,UNSIGNED> id54st_count;

  HWOffsetFix<10,0,UNSIGNED> id217out_value;

  HWOffsetFix<1,0,UNSIGNED> id190out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id240out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id56out_dataa[3];

  HWOffsetFix<32,0,UNSIGNED> id237out_output[397];

  HWRawBits<1> id239out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id96out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id93out_value;

  HWOffsetFix<32,0,UNSIGNED> id216out_value;

  HWOffsetFix<32,0,UNSIGNED> id95out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id97out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id241out_output[225];

  HWOffsetFix<32,0,UNSIGNED> id60out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id64out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id242out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id215out_value;

  HWOffsetFix<32,0,UNSIGNED> id69out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id70out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id243out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id214out_value;

  HWOffsetFix<32,0,UNSIGNED> id75out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id76out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id80out_result[2];

  HWFloat<8,24> id157out_o[6];

  HWFloat<8,24> id228out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id212out_value;

  HWOffsetFix<11,0,UNSIGNED> id211out_value;

  HWOffsetFix<10,0,UNSIGNED> id3out_count;
  HWOffsetFix<1,0,UNSIGNED> id3out_wrap;

  HWOffsetFix<11,0,UNSIGNED> id3st_count;

  HWOffsetFix<10,0,UNSIGNED> id210out_value;

  HWOffsetFix<1,0,UNSIGNED> id197out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id247out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id5out_dataa[3];

  HWOffsetFix<32,0,UNSIGNED> id244out_output[397];

  HWRawBits<1> id246out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id45out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id42out_value;

  HWOffsetFix<32,0,UNSIGNED> id209out_value;

  HWOffsetFix<32,0,UNSIGNED> id44out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id46out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id248out_output[225];

  HWOffsetFix<32,0,UNSIGNED> id9out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id13out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id249out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id208out_value;

  HWOffsetFix<32,0,UNSIGNED> id18out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id19out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id250out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id207out_value;

  HWOffsetFix<32,0,UNSIGNED> id24out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id25out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id29out_result[2];

  HWFloat<8,24> id154out_o[6];

  HWFloat<8,24> id229out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id177out_value;

  HWOffsetFix<1,0,UNSIGNED> id205out_value;

  HWOffsetFix<49,0,UNSIGNED> id174out_value;

  HWOffsetFix<48,0,UNSIGNED> id175out_count;
  HWOffsetFix<1,0,UNSIGNED> id175out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id175st_count;

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
