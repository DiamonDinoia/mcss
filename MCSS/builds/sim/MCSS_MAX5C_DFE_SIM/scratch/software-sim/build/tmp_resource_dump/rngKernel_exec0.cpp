#include "stdsimheader.h"

namespace maxcompilersim {

void rngKernel::execute0() {
  { // Node ID: 164 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id165out_result;

  { // Node ID: 165 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id165in_a = id164out_io_y_force_disabled;

    id165out_result = (not_fixed(id165in_a));
  }
  { // Node ID: 226 (NodeConstantRawBits)
  }
  { // Node ID: 225 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 105 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id105in_enable = id226out_value;
    const HWOffsetFix<11,0,UNSIGNED> &id105in_max = id225out_value;

    HWOffsetFix<11,0,UNSIGNED> id105x_1;
    HWOffsetFix<1,0,UNSIGNED> id105x_2;
    HWOffsetFix<1,0,UNSIGNED> id105x_3;
    HWOffsetFix<1,0,UNSIGNED> id105x_4;
    HWOffsetFix<11,0,UNSIGNED> id105x_5t_1e_1;

    id105out_count = (cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>((id105st_count)));
    (id105x_1) = (add_fixed<11,0,UNSIGNED,TRUNCATE>((id105st_count),(c_hw_fix_11_0_uns_bits_2)));
    (id105x_2) = (gt_fixed((id105x_1),id105in_max));
    (id105x_3) = (and_fixed(id105in_enable,(not_fixed((id105x_2)))));
    (id105x_4) = (c_hw_fix_1_0_uns_bits_1);
    id105out_wrap = (id105x_4);
    if(((id105x_3).getValueAsBool())) {
      if(((id105x_4).getValueAsBool())) {
        (id105st_count) = (c_hw_fix_11_0_uns_bits_1);
      }
      else {
        (id105x_5t_1e_1) = (id105x_1);
        (id105st_count) = (id105x_5t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 224 (NodeConstantRawBits)
  }
  { // Node ID: 183 (NodeGteInlined)
    const HWOffsetFix<10,0,UNSIGNED> &id183in_a = id105out_count;
    const HWOffsetFix<10,0,UNSIGNED> &id183in_b = id224out_value;

    id183out_result[(getCycle()+1)%2] = (gte_fixed(id183in_a,id183in_b));
  }
  { // Node ID: 233 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id233in_input = id183out_result[getCycle()%2];

    id233out_output[(getCycle()+1)%2] = id233in_input;
  }
  { // Node ID: 107 (NodeMappedRom)
    const HWOffsetFix<10,0,UNSIGNED> &id107in_addra = id105out_count;

    long id107x_1;
    HWOffsetFix<32,0,UNSIGNED> id107x_2;

    (id107x_1) = (id107in_addra.getValueAsLong());
    switch(((long)((id107x_1)<(624l)))) {
      case 0l:
        id107x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id107x_2 = (getMappedMemValue< HWOffsetFix<32,0,UNSIGNED> > ("rngKernelgen3_seeds0", id107x_1) );
        break;
      default:
        id107x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id107out_dataa[(getCycle()+2)%3] = (id107x_2);
  }
  HWOffsetFix<32,0,UNSIGNED> id133out_output;

  { // Node ID: 133 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id133in_input = id111out_result[getCycle()%2];

    id133out_output = id133in_input;
  }
  { // Node ID: 230 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id230in_input = id111out_result[getCycle()%2];

    id230out_output[(getCycle()+396)%397] = id230in_input;
  }
  HWRawBits<1> id134out_result;

  { // Node ID: 134 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id134in_a = id230out_output[getCycle()%397];

    id134out_result = (slice<31,1>(id134in_a));
  }
  { // Node ID: 232 (NodeFIFO)
    const HWRawBits<1> &id232in_input = id134out_result;

    id232out_output[(getCycle()+1)%2] = id232in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id132out_output;

  { // Node ID: 132 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id132in_input = id230out_output[getCycle()%397];

    id132out_output = id132in_input;
  }
  HWRawBits<31> id135out_result;

  { // Node ID: 135 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id135in_a = id132out_output;

    id135out_result = (slice<0,31>(id135in_a));
  }
  HWRawBits<32> id136out_result;

  { // Node ID: 136 (NodeCat)
    const HWRawBits<1> &id136in_in0 = id232out_output[getCycle()%2];
    const HWRawBits<31> &id136in_in1 = id135out_result;

    id136out_result = (cat(id136in_in0,id136in_in1));
  }
  HWOffsetFix<32,0,UNSIGNED> id139out_output;

  { // Node ID: 139 (NodeReinterpret)
    const HWRawBits<32> &id139in_input = id136out_result;

    id139out_output = (cast_bits2fixed<32,0,UNSIGNED>(id139in_input));
  }
  HWRawBits<32> id184out_dataout;

  { // Node ID: 184 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id184in_datain = id139out_output;

    id184out_dataout = (shift_right_fixed(id184in_datain,(1l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id142out_output;

  { // Node ID: 142 (NodeReinterpret)
    const HWRawBits<32> &id142in_input = id184out_dataout;

    id142out_output = (cast_bits2fixed<32,0,UNSIGNED>(id142in_input));
  }
  { // Node ID: 147 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id147in_a = id133out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id147in_b = id142out_output;

    HWOffsetFix<32,0,UNSIGNED> id147x_1;

    (id147x_1) = (xor_fixed(id147in_a,id147in_b));
    id147out_result[(getCycle()+1)%2] = (id147x_1);
  }
  HWRawBits<1> id143out_result;

  { // Node ID: 143 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id143in_a = id132out_output;

    id143out_result = (slice<0,1>(id143in_a));
  }
  { // Node ID: 144 (NodeConstantRawBits)
  }
  { // Node ID: 223 (NodeConstantRawBits)
  }
  { // Node ID: 146 (NodeMux)
    const HWRawBits<1> &id146in_sel = id143out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id146in_option0 = id144out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id146in_option1 = id223out_value;

    HWOffsetFix<32,0,UNSIGNED> id146x_1;

    switch((id146in_sel.getValueAsLong())) {
      case 0l:
        id146x_1 = id146in_option0;
        break;
      case 1l:
        id146x_1 = id146in_option1;
        break;
      default:
        id146x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id146out_result[(getCycle()+1)%2] = (id146x_1);
  }
  { // Node ID: 148 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id148in_a = id147out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id148in_b = id146out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id148x_1;

    (id148x_1) = (xor_fixed(id148in_a,id148in_b));
    id148out_result[(getCycle()+1)%2] = (id148x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id110out_output;

  { // Node ID: 110 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id110in_input = id148out_result[getCycle()%2];

    id110out_output = id110in_input;
  }
  { // Node ID: 234 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id234in_input = id110out_output;

    id234out_output[(getCycle()+224)%225] = id234in_input;
  }
  { // Node ID: 111 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_sel = id233out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id111in_option0 = id107out_dataa[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id111in_option1 = id234out_output[getCycle()%225];

    HWOffsetFix<32,0,UNSIGNED> id111x_1;

    switch((id111in_sel.getValueAsLong())) {
      case 0l:
        id111x_1 = id111in_option0;
        break;
      case 1l:
        id111x_1 = id111in_option1;
        break;
      default:
        id111x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id111out_result[(getCycle()+1)%2] = (id111x_1);
  }
  HWRawBits<32> id185out_dataout;

  { // Node ID: 185 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id185in_datain = id111out_result[getCycle()%2];

    id185out_dataout = (shift_right_fixed(id185in_datain,(11l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id114out_output;

  { // Node ID: 114 (NodeReinterpret)
    const HWRawBits<32> &id114in_input = id185out_dataout;

    id114out_output = (cast_bits2fixed<32,0,UNSIGNED>(id114in_input));
  }
  { // Node ID: 115 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id115in_a = id111out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id115in_b = id114out_output;

    HWOffsetFix<32,0,UNSIGNED> id115x_1;

    (id115x_1) = (xor_fixed(id115in_a,id115in_b));
    id115out_result[(getCycle()+1)%2] = (id115x_1);
  }
  { // Node ID: 235 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id235in_input = id115out_result[getCycle()%2];

    id235out_output[(getCycle()+1)%2] = id235in_input;
  }
  HWRawBits<32> id186out_dataout;

  { // Node ID: 186 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id186in_datain = id115out_result[getCycle()%2];

    id186out_dataout = (shift_left_fixed(id186in_datain,(7l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id118out_output;

  { // Node ID: 118 (NodeReinterpret)
    const HWRawBits<32> &id118in_input = id186out_dataout;

    id118out_output = (cast_bits2fixed<32,0,UNSIGNED>(id118in_input));
  }
  { // Node ID: 222 (NodeConstantRawBits)
  }
  { // Node ID: 120 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id120in_a = id118out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id120in_b = id222out_value;

    HWOffsetFix<32,0,UNSIGNED> id120x_1;

    (id120x_1) = (and_fixed(id120in_a,id120in_b));
    id120out_result[(getCycle()+1)%2] = (id120x_1);
  }
  { // Node ID: 121 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id121in_a = id235out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id121in_b = id120out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id121x_1;

    (id121x_1) = (xor_fixed(id121in_a,id121in_b));
    id121out_result[(getCycle()+1)%2] = (id121x_1);
  }
  { // Node ID: 236 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id236in_input = id121out_result[getCycle()%2];

    id236out_output[(getCycle()+1)%2] = id236in_input;
  }
  HWRawBits<32> id187out_dataout;

  { // Node ID: 187 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id187in_datain = id121out_result[getCycle()%2];

    id187out_dataout = (shift_left_fixed(id187in_datain,(15l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id124out_output;

  { // Node ID: 124 (NodeReinterpret)
    const HWRawBits<32> &id124in_input = id187out_dataout;

    id124out_output = (cast_bits2fixed<32,0,UNSIGNED>(id124in_input));
  }
  { // Node ID: 221 (NodeConstantRawBits)
  }
  { // Node ID: 126 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id126in_a = id124out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id126in_b = id221out_value;

    HWOffsetFix<32,0,UNSIGNED> id126x_1;

    (id126x_1) = (and_fixed(id126in_a,id126in_b));
    id126out_result[(getCycle()+1)%2] = (id126x_1);
  }
  { // Node ID: 127 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id127in_a = id236out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id127in_b = id126out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id127x_1;

    (id127x_1) = (xor_fixed(id127in_a,id127in_b));
    id127out_result[(getCycle()+1)%2] = (id127x_1);
  }
  HWRawBits<32> id188out_dataout;

  { // Node ID: 188 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id188in_datain = id127out_result[getCycle()%2];

    id188out_dataout = (shift_right_fixed(id188in_datain,(18l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id130out_output;

  { // Node ID: 130 (NodeReinterpret)
    const HWRawBits<32> &id130in_input = id188out_dataout;

    id130out_output = (cast_bits2fixed<32,0,UNSIGNED>(id130in_input));
  }
  { // Node ID: 131 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id131in_a = id127out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id131in_b = id130out_output;

    HWOffsetFix<32,0,UNSIGNED> id131x_1;

    (id131x_1) = (xor_fixed(id131in_a,id131in_b));
    id131out_result[(getCycle()+1)%2] = (id131x_1);
  }
  { // Node ID: 160 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id160in_i = id131out_result[getCycle()%2];

    id160out_o[(getCycle()+5)%6] = (cast_fixed2float<8,24>(id160in_i));
  }
  { // Node ID: 227 (NodePO2FPMult)
    const HWFloat<8,24> &id227in_floatIn = id160out_o[getCycle()%6];

    id227out_floatOut[(getCycle()+1)%2] = (mul_float(id227in_floatIn,(c_hw_flt_8_24_2_3283064365386963En10val)));
  }
  { // Node ID: 219 (NodeConstantRawBits)
  }
  { // Node ID: 218 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 54 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id54in_enable = id219out_value;
    const HWOffsetFix<11,0,UNSIGNED> &id54in_max = id218out_value;

    HWOffsetFix<11,0,UNSIGNED> id54x_1;
    HWOffsetFix<1,0,UNSIGNED> id54x_2;
    HWOffsetFix<1,0,UNSIGNED> id54x_3;
    HWOffsetFix<1,0,UNSIGNED> id54x_4;
    HWOffsetFix<11,0,UNSIGNED> id54x_5t_1e_1;

    id54out_count = (cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>((id54st_count)));
    (id54x_1) = (add_fixed<11,0,UNSIGNED,TRUNCATE>((id54st_count),(c_hw_fix_11_0_uns_bits_2)));
    (id54x_2) = (gt_fixed((id54x_1),id54in_max));
    (id54x_3) = (and_fixed(id54in_enable,(not_fixed((id54x_2)))));
    (id54x_4) = (c_hw_fix_1_0_uns_bits_1);
    id54out_wrap = (id54x_4);
    if(((id54x_3).getValueAsBool())) {
      if(((id54x_4).getValueAsBool())) {
        (id54st_count) = (c_hw_fix_11_0_uns_bits_1);
      }
      else {
        (id54x_5t_1e_1) = (id54x_1);
        (id54st_count) = (id54x_5t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 217 (NodeConstantRawBits)
  }
  { // Node ID: 190 (NodeGteInlined)
    const HWOffsetFix<10,0,UNSIGNED> &id190in_a = id54out_count;
    const HWOffsetFix<10,0,UNSIGNED> &id190in_b = id217out_value;

    id190out_result[(getCycle()+1)%2] = (gte_fixed(id190in_a,id190in_b));
  }
  { // Node ID: 240 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id240in_input = id190out_result[getCycle()%2];

    id240out_output[(getCycle()+1)%2] = id240in_input;
  }
  { // Node ID: 56 (NodeMappedRom)
    const HWOffsetFix<10,0,UNSIGNED> &id56in_addra = id54out_count;

    long id56x_1;
    HWOffsetFix<32,0,UNSIGNED> id56x_2;

    (id56x_1) = (id56in_addra.getValueAsLong());
    switch(((long)((id56x_1)<(624l)))) {
      case 0l:
        id56x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id56x_2 = (getMappedMemValue< HWOffsetFix<32,0,UNSIGNED> > ("rngKernelgen2_seeds0", id56x_1) );
        break;
      default:
        id56x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id56out_dataa[(getCycle()+2)%3] = (id56x_2);
  }
  HWOffsetFix<32,0,UNSIGNED> id82out_output;

  { // Node ID: 82 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id82in_input = id60out_result[getCycle()%2];

    id82out_output = id82in_input;
  }
  { // Node ID: 237 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id237in_input = id60out_result[getCycle()%2];

    id237out_output[(getCycle()+396)%397] = id237in_input;
  }
  HWRawBits<1> id83out_result;

  { // Node ID: 83 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id83in_a = id237out_output[getCycle()%397];

    id83out_result = (slice<31,1>(id83in_a));
  }
  { // Node ID: 239 (NodeFIFO)
    const HWRawBits<1> &id239in_input = id83out_result;

    id239out_output[(getCycle()+1)%2] = id239in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id81out_output;

  { // Node ID: 81 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id81in_input = id237out_output[getCycle()%397];

    id81out_output = id81in_input;
  }
  HWRawBits<31> id84out_result;

  { // Node ID: 84 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id84in_a = id81out_output;

    id84out_result = (slice<0,31>(id84in_a));
  }
  HWRawBits<32> id85out_result;

  { // Node ID: 85 (NodeCat)
    const HWRawBits<1> &id85in_in0 = id239out_output[getCycle()%2];
    const HWRawBits<31> &id85in_in1 = id84out_result;

    id85out_result = (cat(id85in_in0,id85in_in1));
  }
  HWOffsetFix<32,0,UNSIGNED> id88out_output;

  { // Node ID: 88 (NodeReinterpret)
    const HWRawBits<32> &id88in_input = id85out_result;

    id88out_output = (cast_bits2fixed<32,0,UNSIGNED>(id88in_input));
  }
  HWRawBits<32> id191out_dataout;

  { // Node ID: 191 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id191in_datain = id88out_output;

    id191out_dataout = (shift_right_fixed(id191in_datain,(1l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id91out_output;

  { // Node ID: 91 (NodeReinterpret)
    const HWRawBits<32> &id91in_input = id191out_dataout;

    id91out_output = (cast_bits2fixed<32,0,UNSIGNED>(id91in_input));
  }
  { // Node ID: 96 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id96in_a = id82out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id96in_b = id91out_output;

    HWOffsetFix<32,0,UNSIGNED> id96x_1;

    (id96x_1) = (xor_fixed(id96in_a,id96in_b));
    id96out_result[(getCycle()+1)%2] = (id96x_1);
  }
  HWRawBits<1> id92out_result;

  { // Node ID: 92 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id92in_a = id81out_output;

    id92out_result = (slice<0,1>(id92in_a));
  }
  { // Node ID: 93 (NodeConstantRawBits)
  }
  { // Node ID: 216 (NodeConstantRawBits)
  }
  { // Node ID: 95 (NodeMux)
    const HWRawBits<1> &id95in_sel = id92out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id95in_option0 = id93out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id95in_option1 = id216out_value;

    HWOffsetFix<32,0,UNSIGNED> id95x_1;

    switch((id95in_sel.getValueAsLong())) {
      case 0l:
        id95x_1 = id95in_option0;
        break;
      case 1l:
        id95x_1 = id95in_option1;
        break;
      default:
        id95x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id95out_result[(getCycle()+1)%2] = (id95x_1);
  }
  { // Node ID: 97 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id97in_a = id96out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id97in_b = id95out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id97x_1;

    (id97x_1) = (xor_fixed(id97in_a,id97in_b));
    id97out_result[(getCycle()+1)%2] = (id97x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id59out_output;

  { // Node ID: 59 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id59in_input = id97out_result[getCycle()%2];

    id59out_output = id59in_input;
  }
  { // Node ID: 241 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id241in_input = id59out_output;

    id241out_output[(getCycle()+224)%225] = id241in_input;
  }
  { // Node ID: 60 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id60in_sel = id240out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id60in_option0 = id56out_dataa[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id60in_option1 = id241out_output[getCycle()%225];

    HWOffsetFix<32,0,UNSIGNED> id60x_1;

    switch((id60in_sel.getValueAsLong())) {
      case 0l:
        id60x_1 = id60in_option0;
        break;
      case 1l:
        id60x_1 = id60in_option1;
        break;
      default:
        id60x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id60out_result[(getCycle()+1)%2] = (id60x_1);
  }
  HWRawBits<32> id192out_dataout;

  { // Node ID: 192 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id192in_datain = id60out_result[getCycle()%2];

    id192out_dataout = (shift_right_fixed(id192in_datain,(11l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id63out_output;

  { // Node ID: 63 (NodeReinterpret)
    const HWRawBits<32> &id63in_input = id192out_dataout;

    id63out_output = (cast_bits2fixed<32,0,UNSIGNED>(id63in_input));
  }
  { // Node ID: 64 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id64in_a = id60out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id64in_b = id63out_output;

    HWOffsetFix<32,0,UNSIGNED> id64x_1;

    (id64x_1) = (xor_fixed(id64in_a,id64in_b));
    id64out_result[(getCycle()+1)%2] = (id64x_1);
  }
  { // Node ID: 242 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id242in_input = id64out_result[getCycle()%2];

    id242out_output[(getCycle()+1)%2] = id242in_input;
  }
  HWRawBits<32> id193out_dataout;

  { // Node ID: 193 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id193in_datain = id64out_result[getCycle()%2];

    id193out_dataout = (shift_left_fixed(id193in_datain,(7l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id67out_output;

  { // Node ID: 67 (NodeReinterpret)
    const HWRawBits<32> &id67in_input = id193out_dataout;

    id67out_output = (cast_bits2fixed<32,0,UNSIGNED>(id67in_input));
  }
  { // Node ID: 215 (NodeConstantRawBits)
  }
  { // Node ID: 69 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id69in_a = id67out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id69in_b = id215out_value;

    HWOffsetFix<32,0,UNSIGNED> id69x_1;

    (id69x_1) = (and_fixed(id69in_a,id69in_b));
    id69out_result[(getCycle()+1)%2] = (id69x_1);
  }
  { // Node ID: 70 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id70in_a = id242out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id70in_b = id69out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id70x_1;

    (id70x_1) = (xor_fixed(id70in_a,id70in_b));
    id70out_result[(getCycle()+1)%2] = (id70x_1);
  }
  { // Node ID: 243 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id243in_input = id70out_result[getCycle()%2];

    id243out_output[(getCycle()+1)%2] = id243in_input;
  }
  HWRawBits<32> id194out_dataout;

  { // Node ID: 194 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id194in_datain = id70out_result[getCycle()%2];

    id194out_dataout = (shift_left_fixed(id194in_datain,(15l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id73out_output;

  { // Node ID: 73 (NodeReinterpret)
    const HWRawBits<32> &id73in_input = id194out_dataout;

    id73out_output = (cast_bits2fixed<32,0,UNSIGNED>(id73in_input));
  }
  { // Node ID: 214 (NodeConstantRawBits)
  }
  { // Node ID: 75 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id75in_a = id73out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id75in_b = id214out_value;

    HWOffsetFix<32,0,UNSIGNED> id75x_1;

    (id75x_1) = (and_fixed(id75in_a,id75in_b));
    id75out_result[(getCycle()+1)%2] = (id75x_1);
  }
  { // Node ID: 76 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id76in_a = id243out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id76in_b = id75out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id76x_1;

    (id76x_1) = (xor_fixed(id76in_a,id76in_b));
    id76out_result[(getCycle()+1)%2] = (id76x_1);
  }
  HWRawBits<32> id195out_dataout;

  { // Node ID: 195 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id195in_datain = id76out_result[getCycle()%2];

    id195out_dataout = (shift_right_fixed(id195in_datain,(18l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id79out_output;

  { // Node ID: 79 (NodeReinterpret)
    const HWRawBits<32> &id79in_input = id195out_dataout;

    id79out_output = (cast_bits2fixed<32,0,UNSIGNED>(id79in_input));
  }
  { // Node ID: 80 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id80in_a = id76out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id80in_b = id79out_output;

    HWOffsetFix<32,0,UNSIGNED> id80x_1;

    (id80x_1) = (xor_fixed(id80in_a,id80in_b));
    id80out_result[(getCycle()+1)%2] = (id80x_1);
  }
  { // Node ID: 157 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id157in_i = id80out_result[getCycle()%2];

    id157out_o[(getCycle()+5)%6] = (cast_fixed2float<8,24>(id157in_i));
  }
  { // Node ID: 228 (NodePO2FPMult)
    const HWFloat<8,24> &id228in_floatIn = id157out_o[getCycle()%6];

    id228out_floatOut[(getCycle()+1)%2] = (mul_float(id228in_floatIn,(c_hw_flt_8_24_2_3283064365386963En10val)));
  }
  { // Node ID: 212 (NodeConstantRawBits)
  }
  { // Node ID: 211 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 3 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_enable = id212out_value;
    const HWOffsetFix<11,0,UNSIGNED> &id3in_max = id211out_value;

    HWOffsetFix<11,0,UNSIGNED> id3x_1;
    HWOffsetFix<1,0,UNSIGNED> id3x_2;
    HWOffsetFix<1,0,UNSIGNED> id3x_3;
    HWOffsetFix<1,0,UNSIGNED> id3x_4;
    HWOffsetFix<11,0,UNSIGNED> id3x_5t_1e_1;

    id3out_count = (cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>((id3st_count)));
    (id3x_1) = (add_fixed<11,0,UNSIGNED,TRUNCATE>((id3st_count),(c_hw_fix_11_0_uns_bits_2)));
    (id3x_2) = (gt_fixed((id3x_1),id3in_max));
    (id3x_3) = (and_fixed(id3in_enable,(not_fixed((id3x_2)))));
    (id3x_4) = (c_hw_fix_1_0_uns_bits_1);
    id3out_wrap = (id3x_4);
    if(((id3x_3).getValueAsBool())) {
      if(((id3x_4).getValueAsBool())) {
        (id3st_count) = (c_hw_fix_11_0_uns_bits_1);
      }
      else {
        (id3x_5t_1e_1) = (id3x_1);
        (id3st_count) = (id3x_5t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 210 (NodeConstantRawBits)
  }
  { // Node ID: 197 (NodeGteInlined)
    const HWOffsetFix<10,0,UNSIGNED> &id197in_a = id3out_count;
    const HWOffsetFix<10,0,UNSIGNED> &id197in_b = id210out_value;

    id197out_result[(getCycle()+1)%2] = (gte_fixed(id197in_a,id197in_b));
  }
  { // Node ID: 247 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id247in_input = id197out_result[getCycle()%2];

    id247out_output[(getCycle()+1)%2] = id247in_input;
  }
  { // Node ID: 5 (NodeMappedRom)
    const HWOffsetFix<10,0,UNSIGNED> &id5in_addra = id3out_count;

    long id5x_1;
    HWOffsetFix<32,0,UNSIGNED> id5x_2;

    (id5x_1) = (id5in_addra.getValueAsLong());
    switch(((long)((id5x_1)<(624l)))) {
      case 0l:
        id5x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id5x_2 = (getMappedMemValue< HWOffsetFix<32,0,UNSIGNED> > ("rngKernelgen1_seeds0", id5x_1) );
        break;
      default:
        id5x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id5out_dataa[(getCycle()+2)%3] = (id5x_2);
  }
  HWOffsetFix<32,0,UNSIGNED> id31out_output;

  { // Node ID: 31 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id31in_input = id9out_result[getCycle()%2];

    id31out_output = id31in_input;
  }
  { // Node ID: 244 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id244in_input = id9out_result[getCycle()%2];

    id244out_output[(getCycle()+396)%397] = id244in_input;
  }
  HWRawBits<1> id32out_result;

  { // Node ID: 32 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id32in_a = id244out_output[getCycle()%397];

    id32out_result = (slice<31,1>(id32in_a));
  }
  { // Node ID: 246 (NodeFIFO)
    const HWRawBits<1> &id246in_input = id32out_result;

    id246out_output[(getCycle()+1)%2] = id246in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id30out_output;

  { // Node ID: 30 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id30in_input = id244out_output[getCycle()%397];

    id30out_output = id30in_input;
  }
  HWRawBits<31> id33out_result;

  { // Node ID: 33 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id33in_a = id30out_output;

    id33out_result = (slice<0,31>(id33in_a));
  }
  HWRawBits<32> id34out_result;

  { // Node ID: 34 (NodeCat)
    const HWRawBits<1> &id34in_in0 = id246out_output[getCycle()%2];
    const HWRawBits<31> &id34in_in1 = id33out_result;

    id34out_result = (cat(id34in_in0,id34in_in1));
  }
  HWOffsetFix<32,0,UNSIGNED> id37out_output;

  { // Node ID: 37 (NodeReinterpret)
    const HWRawBits<32> &id37in_input = id34out_result;

    id37out_output = (cast_bits2fixed<32,0,UNSIGNED>(id37in_input));
  }
  HWRawBits<32> id198out_dataout;

  { // Node ID: 198 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id198in_datain = id37out_output;

    id198out_dataout = (shift_right_fixed(id198in_datain,(1l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id40out_output;

  { // Node ID: 40 (NodeReinterpret)
    const HWRawBits<32> &id40in_input = id198out_dataout;

    id40out_output = (cast_bits2fixed<32,0,UNSIGNED>(id40in_input));
  }
  { // Node ID: 45 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id45in_a = id31out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id45in_b = id40out_output;

    HWOffsetFix<32,0,UNSIGNED> id45x_1;

    (id45x_1) = (xor_fixed(id45in_a,id45in_b));
    id45out_result[(getCycle()+1)%2] = (id45x_1);
  }
  HWRawBits<1> id41out_result;

  { // Node ID: 41 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id41in_a = id30out_output;

    id41out_result = (slice<0,1>(id41in_a));
  }
  { // Node ID: 42 (NodeConstantRawBits)
  }
  { // Node ID: 209 (NodeConstantRawBits)
  }
  { // Node ID: 44 (NodeMux)
    const HWRawBits<1> &id44in_sel = id41out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id44in_option0 = id42out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id44in_option1 = id209out_value;

    HWOffsetFix<32,0,UNSIGNED> id44x_1;

    switch((id44in_sel.getValueAsLong())) {
      case 0l:
        id44x_1 = id44in_option0;
        break;
      case 1l:
        id44x_1 = id44in_option1;
        break;
      default:
        id44x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id44out_result[(getCycle()+1)%2] = (id44x_1);
  }
  { // Node ID: 46 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id46in_a = id45out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id46in_b = id44out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id46x_1;

    (id46x_1) = (xor_fixed(id46in_a,id46in_b));
    id46out_result[(getCycle()+1)%2] = (id46x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id8out_output;

  { // Node ID: 8 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id8in_input = id46out_result[getCycle()%2];

    id8out_output = id8in_input;
  }
  { // Node ID: 248 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id248in_input = id8out_output;

    id248out_output[(getCycle()+224)%225] = id248in_input;
  }
  { // Node ID: 9 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_sel = id247out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id9in_option0 = id5out_dataa[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id9in_option1 = id248out_output[getCycle()%225];

    HWOffsetFix<32,0,UNSIGNED> id9x_1;

    switch((id9in_sel.getValueAsLong())) {
      case 0l:
        id9x_1 = id9in_option0;
        break;
      case 1l:
        id9x_1 = id9in_option1;
        break;
      default:
        id9x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id9out_result[(getCycle()+1)%2] = (id9x_1);
  }
  HWRawBits<32> id199out_dataout;

  { // Node ID: 199 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id199in_datain = id9out_result[getCycle()%2];

    id199out_dataout = (shift_right_fixed(id199in_datain,(11l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id12out_output;

  { // Node ID: 12 (NodeReinterpret)
    const HWRawBits<32> &id12in_input = id199out_dataout;

    id12out_output = (cast_bits2fixed<32,0,UNSIGNED>(id12in_input));
  }
  { // Node ID: 13 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id13in_a = id9out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id13in_b = id12out_output;

    HWOffsetFix<32,0,UNSIGNED> id13x_1;

    (id13x_1) = (xor_fixed(id13in_a,id13in_b));
    id13out_result[(getCycle()+1)%2] = (id13x_1);
  }
  { // Node ID: 249 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id249in_input = id13out_result[getCycle()%2];

    id249out_output[(getCycle()+1)%2] = id249in_input;
  }
  HWRawBits<32> id200out_dataout;

  { // Node ID: 200 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id200in_datain = id13out_result[getCycle()%2];

    id200out_dataout = (shift_left_fixed(id200in_datain,(7l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id16out_output;

  { // Node ID: 16 (NodeReinterpret)
    const HWRawBits<32> &id16in_input = id200out_dataout;

    id16out_output = (cast_bits2fixed<32,0,UNSIGNED>(id16in_input));
  }
  { // Node ID: 208 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id18in_a = id16out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id18in_b = id208out_value;

    HWOffsetFix<32,0,UNSIGNED> id18x_1;

    (id18x_1) = (and_fixed(id18in_a,id18in_b));
    id18out_result[(getCycle()+1)%2] = (id18x_1);
  }
  { // Node ID: 19 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id19in_a = id249out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id19in_b = id18out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id19x_1;

    (id19x_1) = (xor_fixed(id19in_a,id19in_b));
    id19out_result[(getCycle()+1)%2] = (id19x_1);
  }
  { // Node ID: 250 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id250in_input = id19out_result[getCycle()%2];

    id250out_output[(getCycle()+1)%2] = id250in_input;
  }
  HWRawBits<32> id201out_dataout;

  { // Node ID: 201 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id201in_datain = id19out_result[getCycle()%2];

    id201out_dataout = (shift_left_fixed(id201in_datain,(15l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id22out_output;

  { // Node ID: 22 (NodeReinterpret)
    const HWRawBits<32> &id22in_input = id201out_dataout;

    id22out_output = (cast_bits2fixed<32,0,UNSIGNED>(id22in_input));
  }
  { // Node ID: 207 (NodeConstantRawBits)
  }
  { // Node ID: 24 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id24in_a = id22out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id24in_b = id207out_value;

    HWOffsetFix<32,0,UNSIGNED> id24x_1;

    (id24x_1) = (and_fixed(id24in_a,id24in_b));
    id24out_result[(getCycle()+1)%2] = (id24x_1);
  }
  { // Node ID: 25 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id25in_a = id250out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id25in_b = id24out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id25x_1;

    (id25x_1) = (xor_fixed(id25in_a,id25in_b));
    id25out_result[(getCycle()+1)%2] = (id25x_1);
  }
  HWRawBits<32> id202out_dataout;

  { // Node ID: 202 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id202in_datain = id25out_result[getCycle()%2];

    id202out_dataout = (shift_right_fixed(id202in_datain,(18l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id28out_output;

  { // Node ID: 28 (NodeReinterpret)
    const HWRawBits<32> &id28in_input = id202out_dataout;

    id28out_output = (cast_bits2fixed<32,0,UNSIGNED>(id28in_input));
  }
  { // Node ID: 29 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id29in_a = id25out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id29in_b = id28out_output;

    HWOffsetFix<32,0,UNSIGNED> id29x_1;

    (id29x_1) = (xor_fixed(id29in_a,id29in_b));
    id29out_result[(getCycle()+1)%2] = (id29x_1);
  }
  { // Node ID: 154 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id154in_i = id29out_result[getCycle()%2];

    id154out_o[(getCycle()+5)%6] = (cast_fixed2float<8,24>(id154in_i));
  }
  { // Node ID: 229 (NodePO2FPMult)
    const HWFloat<8,24> &id229in_floatIn = id154out_o[getCycle()%6];

    id229out_floatOut[(getCycle()+1)%2] = (mul_float(id229in_floatIn,(c_hw_flt_8_24_2_3283064365386963En10val)));
  }
  HWRawBits<96> id204out_result;

  { // Node ID: 204 (NodeCat)
    const HWFloat<8,24> &id204in_in0 = id227out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id204in_in1 = id228out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id204in_in2 = id229out_floatOut[getCycle()%2];

    id204out_result = (cat((cat(id204in_in0,id204in_in1)),id204in_in2));
  }
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 167 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id167in_output_control = id165out_result;
    const HWRawBits<96> &id167in_data = id204out_result;

    bool id167x_1;

    (id167x_1) = ((id167in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(15l))&(isFlushingActive()))));
    if((id167x_1)) {
      writeOutput(m_y, id167in_data);
    }
  }
  { // Node ID: 177 (NodeConstantRawBits)
  }
  { // Node ID: 205 (NodeConstantRawBits)
  }
  { // Node ID: 174 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 175 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id175in_enable = id205out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id175in_max = id174out_value;

    HWOffsetFix<49,0,UNSIGNED> id175x_1;
    HWOffsetFix<1,0,UNSIGNED> id175x_2;
    HWOffsetFix<1,0,UNSIGNED> id175x_3;
    HWOffsetFix<49,0,UNSIGNED> id175x_4t_1e_1;

    id175out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id175st_count)));
    (id175x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id175st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id175x_2) = (gte_fixed((id175x_1),id175in_max));
    (id175x_3) = (and_fixed((id175x_2),id175in_enable));
    id175out_wrap = (id175x_3);
    if((id175in_enable.getValueAsBool())) {
      if(((id175x_3).getValueAsBool())) {
        (id175st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id175x_4t_1e_1) = (id175x_1);
        (id175st_count) = (id175x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id176out_output;

  { // Node ID: 176 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id176in_input = id175out_count;

    id176out_output = id176in_input;
  }
  if ( (getFillLevel() >= (1l)) && (getFlushLevel() < (1l)|| !isFlushingActive() ))
  { // Node ID: 178 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id178in_load = id177out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id178in_data = id176out_output;

    bool id178x_1;

    (id178x_1) = ((id178in_load.getValueAsBool())&(!(((getFlushLevel())>=(1l))&(isFlushingActive()))));
    if((id178x_1)) {
      setMappedRegValue("current_run_cycle_count", id178in_data);
    }
  }
  { // Node ID: 0 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 182 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id182in_start = id0out_value;

    if((id182in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
