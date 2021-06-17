#include "stdsimheader.h"

namespace maxcompilersim {

void rngKernel::execute0() {
  { // Node ID: 152 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id153out_result;

  { // Node ID: 153 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_a = id152out_io_y_force_disabled;

    id153out_result = (not_fixed(id153in_a));
  }
  { // Node ID: 218 (NodeConstantRawBits)
  }
  { // Node ID: 217 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 3 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_enable = id218out_value;
    const HWOffsetFix<11,0,UNSIGNED> &id3in_max = id217out_value;

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
  { // Node ID: 216 (NodeConstantRawBits)
  }
  { // Node ID: 171 (NodeGteInlined)
    const HWOffsetFix<10,0,UNSIGNED> &id171in_a = id3out_count;
    const HWOffsetFix<10,0,UNSIGNED> &id171in_b = id216out_value;

    id171out_result[(getCycle()+1)%2] = (gte_fixed(id171in_a,id171in_b));
  }
  { // Node ID: 225 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id225in_input = id171out_result[getCycle()%2];

    id225out_output[(getCycle()+1)%2] = id225in_input;
  }
  { // Node ID: 9 (NodeMappedRom)
    const HWOffsetFix<10,0,UNSIGNED> &id9in_addra = id3out_count;

    long id9x_1;
    HWOffsetFix<32,0,UNSIGNED> id9x_2;

    (id9x_1) = (id9in_addra.getValueAsLong());
    switch(((long)((id9x_1)<(624l)))) {
      case 0l:
        id9x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id9x_2 = (getMappedMemValue< HWOffsetFix<32,0,UNSIGNED> > ("rngKernelgen_seeds2", id9x_1) );
        break;
      default:
        id9x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id9out_dataa[(getCycle()+2)%3] = (id9x_2);
  }
  HWOffsetFix<32,0,UNSIGNED> id83out_output;

  { // Node ID: 83 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id83in_input = id17out_result[getCycle()%2];

    id83out_output = id83in_input;
  }
  { // Node ID: 222 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id222in_input = id17out_result[getCycle()%2];

    id222out_output[(getCycle()+396)%397] = id222in_input;
  }
  HWRawBits<1> id86out_result;

  { // Node ID: 86 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id86in_a = id222out_output[getCycle()%397];

    id86out_result = (slice<31,1>(id86in_a));
  }
  { // Node ID: 224 (NodeFIFO)
    const HWRawBits<1> &id224in_input = id86out_result;

    id224out_output[(getCycle()+1)%2] = id224in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id80out_output;

  { // Node ID: 80 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id80in_input = id222out_output[getCycle()%397];

    id80out_output = id80in_input;
  }
  HWRawBits<31> id89out_result;

  { // Node ID: 89 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id89in_a = id80out_output;

    id89out_result = (slice<0,31>(id89in_a));
  }
  HWRawBits<32> id179out_result;

  { // Node ID: 179 (NodeCat)
    const HWRawBits<1> &id179in_in0 = id224out_output[getCycle()%2];
    const HWRawBits<31> &id179in_in1 = id89out_result;

    id179out_result = (cat(id179in_in0,id179in_in1));
  }
  HWOffsetFix<32,0,UNSIGNED> id103out_output;

  { // Node ID: 103 (NodeReinterpret)
    const HWRawBits<32> &id103in_input = id179out_result;

    id103out_output = (cast_bits2fixed<32,0,UNSIGNED>(id103in_input));
  }
  HWRawBits<32> id180out_dataout;

  { // Node ID: 180 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id180in_datain = id103out_output;

    id180out_dataout = (shift_right_fixed(id180in_datain,(1l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id112out_output;

  { // Node ID: 112 (NodeReinterpret)
    const HWRawBits<32> &id112in_input = id180out_dataout;

    id112out_output = (cast_bits2fixed<32,0,UNSIGNED>(id112in_input));
  }
  { // Node ID: 123 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id123in_a = id83out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id123in_b = id112out_output;

    HWOffsetFix<32,0,UNSIGNED> id123x_1;

    (id123x_1) = (xor_fixed(id123in_a,id123in_b));
    id123out_result[(getCycle()+1)%2] = (id123x_1);
  }
  HWRawBits<1> id115out_result;

  { // Node ID: 115 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id115in_a = id80out_output;

    id115out_result = (slice<0,1>(id115in_a));
  }
  { // Node ID: 116 (NodeConstantRawBits)
  }
  { // Node ID: 215 (NodeConstantRawBits)
  }
  { // Node ID: 120 (NodeMux)
    const HWRawBits<1> &id120in_sel = id115out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id120in_option0 = id116out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id120in_option1 = id215out_value;

    HWOffsetFix<32,0,UNSIGNED> id120x_1;

    switch((id120in_sel.getValueAsLong())) {
      case 0l:
        id120x_1 = id120in_option0;
        break;
      case 1l:
        id120x_1 = id120in_option1;
        break;
      default:
        id120x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id120out_result[(getCycle()+1)%2] = (id120x_1);
  }
  { // Node ID: 126 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id126in_a = id123out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id126in_b = id120out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id126x_1;

    (id126x_1) = (xor_fixed(id126in_a,id126in_b));
    id126out_result[(getCycle()+1)%2] = (id126x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id14out_output;

  { // Node ID: 14 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id14in_input = id126out_result[getCycle()%2];

    id14out_output = id14in_input;
  }
  { // Node ID: 226 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id226in_input = id14out_output;

    id226out_output[(getCycle()+224)%225] = id226in_input;
  }
  { // Node ID: 17 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id17in_sel = id225out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id17in_option0 = id9out_dataa[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id17in_option1 = id226out_output[getCycle()%225];

    HWOffsetFix<32,0,UNSIGNED> id17x_1;

    switch((id17in_sel.getValueAsLong())) {
      case 0l:
        id17x_1 = id17in_option0;
        break;
      case 1l:
        id17x_1 = id17in_option1;
        break;
      default:
        id17x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id17out_result[(getCycle()+1)%2] = (id17x_1);
  }
  HWRawBits<32> id181out_dataout;

  { // Node ID: 181 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id181in_datain = id17out_result[getCycle()%2];

    id181out_dataout = (shift_right_fixed(id181in_datain,(11l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id26out_output;

  { // Node ID: 26 (NodeReinterpret)
    const HWRawBits<32> &id26in_input = id181out_dataout;

    id26out_output = (cast_bits2fixed<32,0,UNSIGNED>(id26in_input));
  }
  { // Node ID: 29 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id29in_a = id17out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id29in_b = id26out_output;

    HWOffsetFix<32,0,UNSIGNED> id29x_1;

    (id29x_1) = (xor_fixed(id29in_a,id29in_b));
    id29out_result[(getCycle()+1)%2] = (id29x_1);
  }
  { // Node ID: 227 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id227in_input = id29out_result[getCycle()%2];

    id227out_output[(getCycle()+1)%2] = id227in_input;
  }
  HWRawBits<32> id182out_dataout;

  { // Node ID: 182 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id182in_datain = id29out_result[getCycle()%2];

    id182out_dataout = (shift_left_fixed(id182in_datain,(7l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id38out_output;

  { // Node ID: 38 (NodeReinterpret)
    const HWRawBits<32> &id38in_input = id182out_dataout;

    id38out_output = (cast_bits2fixed<32,0,UNSIGNED>(id38in_input));
  }
  { // Node ID: 214 (NodeConstantRawBits)
  }
  { // Node ID: 44 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id44in_a = id38out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id44in_b = id214out_value;

    HWOffsetFix<32,0,UNSIGNED> id44x_1;

    (id44x_1) = (and_fixed(id44in_a,id44in_b));
    id44out_result[(getCycle()+1)%2] = (id44x_1);
  }
  { // Node ID: 47 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id47in_a = id227out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id47in_b = id44out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id47x_1;

    (id47x_1) = (xor_fixed(id47in_a,id47in_b));
    id47out_result[(getCycle()+1)%2] = (id47x_1);
  }
  { // Node ID: 228 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id228in_input = id47out_result[getCycle()%2];

    id228out_output[(getCycle()+1)%2] = id228in_input;
  }
  HWRawBits<32> id183out_dataout;

  { // Node ID: 183 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id183in_datain = id47out_result[getCycle()%2];

    id183out_dataout = (shift_left_fixed(id183in_datain,(15l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id56out_output;

  { // Node ID: 56 (NodeReinterpret)
    const HWRawBits<32> &id56in_input = id183out_dataout;

    id56out_output = (cast_bits2fixed<32,0,UNSIGNED>(id56in_input));
  }
  { // Node ID: 213 (NodeConstantRawBits)
  }
  { // Node ID: 62 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id62in_a = id56out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id62in_b = id213out_value;

    HWOffsetFix<32,0,UNSIGNED> id62x_1;

    (id62x_1) = (and_fixed(id62in_a,id62in_b));
    id62out_result[(getCycle()+1)%2] = (id62x_1);
  }
  { // Node ID: 65 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id65in_a = id228out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id65in_b = id62out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id65x_1;

    (id65x_1) = (xor_fixed(id65in_a,id65in_b));
    id65out_result[(getCycle()+1)%2] = (id65x_1);
  }
  HWRawBits<32> id184out_dataout;

  { // Node ID: 184 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id184in_datain = id65out_result[getCycle()%2];

    id184out_dataout = (shift_right_fixed(id184in_datain,(18l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id74out_output;

  { // Node ID: 74 (NodeReinterpret)
    const HWRawBits<32> &id74in_input = id184out_dataout;

    id74out_output = (cast_bits2fixed<32,0,UNSIGNED>(id74in_input));
  }
  { // Node ID: 77 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id77in_a = id65out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id77in_b = id74out_output;

    HWOffsetFix<32,0,UNSIGNED> id77x_1;

    (id77x_1) = (xor_fixed(id77in_a,id77in_b));
    id77out_result[(getCycle()+1)%2] = (id77x_1);
  }
  { // Node ID: 144 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id144in_i = id77out_result[getCycle()%2];

    id144out_o[(getCycle()+5)%6] = (cast_fixed2float<8,24>(id144in_i));
  }
  { // Node ID: 219 (NodePO2FPMult)
    const HWFloat<8,24> &id219in_floatIn = id144out_o[getCycle()%6];

    id219out_floatOut[(getCycle()+1)%2] = (mul_float(id219in_floatIn,(c_hw_flt_8_24_2_3283064365386963En10val)));
  }
  { // Node ID: 7 (NodeMappedRom)
    const HWOffsetFix<10,0,UNSIGNED> &id7in_addra = id3out_count;

    long id7x_1;
    HWOffsetFix<32,0,UNSIGNED> id7x_2;

    (id7x_1) = (id7in_addra.getValueAsLong());
    switch(((long)((id7x_1)<(624l)))) {
      case 0l:
        id7x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id7x_2 = (getMappedMemValue< HWOffsetFix<32,0,UNSIGNED> > ("rngKernelgen_seeds1", id7x_1) );
        break;
      default:
        id7x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id7out_dataa[(getCycle()+2)%3] = (id7x_2);
  }
  HWOffsetFix<32,0,UNSIGNED> id82out_output;

  { // Node ID: 82 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id82in_input = id16out_result[getCycle()%2];

    id82out_output = id82in_input;
  }
  { // Node ID: 229 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id229in_input = id16out_result[getCycle()%2];

    id229out_output[(getCycle()+396)%397] = id229in_input;
  }
  HWRawBits<1> id85out_result;

  { // Node ID: 85 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id85in_a = id229out_output[getCycle()%397];

    id85out_result = (slice<31,1>(id85in_a));
  }
  { // Node ID: 231 (NodeFIFO)
    const HWRawBits<1> &id231in_input = id85out_result;

    id231out_output[(getCycle()+1)%2] = id231in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id79out_output;

  { // Node ID: 79 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id79in_input = id229out_output[getCycle()%397];

    id79out_output = id79in_input;
  }
  HWRawBits<31> id88out_result;

  { // Node ID: 88 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id88in_a = id79out_output;

    id88out_result = (slice<0,31>(id88in_a));
  }
  HWRawBits<32> id202out_result;

  { // Node ID: 202 (NodeCat)
    const HWRawBits<1> &id202in_in0 = id231out_output[getCycle()%2];
    const HWRawBits<31> &id202in_in1 = id88out_result;

    id202out_result = (cat(id202in_in0,id202in_in1));
  }
  HWOffsetFix<32,0,UNSIGNED> id101out_output;

  { // Node ID: 101 (NodeReinterpret)
    const HWRawBits<32> &id101in_input = id202out_result;

    id101out_output = (cast_bits2fixed<32,0,UNSIGNED>(id101in_input));
  }
  HWRawBits<32> id173out_dataout;

  { // Node ID: 173 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id173in_datain = id101out_output;

    id173out_dataout = (shift_right_fixed(id173in_datain,(1l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id109out_output;

  { // Node ID: 109 (NodeReinterpret)
    const HWRawBits<32> &id109in_input = id173out_dataout;

    id109out_output = (cast_bits2fixed<32,0,UNSIGNED>(id109in_input));
  }
  { // Node ID: 122 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id122in_a = id82out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id122in_b = id109out_output;

    HWOffsetFix<32,0,UNSIGNED> id122x_1;

    (id122x_1) = (xor_fixed(id122in_a,id122in_b));
    id122out_result[(getCycle()+1)%2] = (id122x_1);
  }
  HWRawBits<1> id114out_result;

  { // Node ID: 114 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id114in_a = id79out_output;

    id114out_result = (slice<0,1>(id114in_a));
  }
  { // Node ID: 119 (NodeMux)
    const HWRawBits<1> &id119in_sel = id114out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id119in_option0 = id116out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id119in_option1 = id215out_value;

    HWOffsetFix<32,0,UNSIGNED> id119x_1;

    switch((id119in_sel.getValueAsLong())) {
      case 0l:
        id119x_1 = id119in_option0;
        break;
      case 1l:
        id119x_1 = id119in_option1;
        break;
      default:
        id119x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id119out_result[(getCycle()+1)%2] = (id119x_1);
  }
  { // Node ID: 125 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id125in_a = id122out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id125in_b = id119out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id125x_1;

    (id125x_1) = (xor_fixed(id125in_a,id125in_b));
    id125out_result[(getCycle()+1)%2] = (id125x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id13out_output;

  { // Node ID: 13 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id13in_input = id125out_result[getCycle()%2];

    id13out_output = id13in_input;
  }
  { // Node ID: 233 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id233in_input = id13out_output;

    id233out_output[(getCycle()+224)%225] = id233in_input;
  }
  { // Node ID: 16 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_sel = id225out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id16in_option0 = id7out_dataa[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id16in_option1 = id233out_output[getCycle()%225];

    HWOffsetFix<32,0,UNSIGNED> id16x_1;

    switch((id16in_sel.getValueAsLong())) {
      case 0l:
        id16x_1 = id16in_option0;
        break;
      case 1l:
        id16x_1 = id16in_option1;
        break;
      default:
        id16x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id16out_result[(getCycle()+1)%2] = (id16x_1);
  }
  HWRawBits<32> id185out_dataout;

  { // Node ID: 185 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id185in_datain = id16out_result[getCycle()%2];

    id185out_dataout = (shift_right_fixed(id185in_datain,(11l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id23out_output;

  { // Node ID: 23 (NodeReinterpret)
    const HWRawBits<32> &id23in_input = id185out_dataout;

    id23out_output = (cast_bits2fixed<32,0,UNSIGNED>(id23in_input));
  }
  { // Node ID: 28 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id28in_a = id16out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id28in_b = id23out_output;

    HWOffsetFix<32,0,UNSIGNED> id28x_1;

    (id28x_1) = (xor_fixed(id28in_a,id28in_b));
    id28out_result[(getCycle()+1)%2] = (id28x_1);
  }
  { // Node ID: 234 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id234in_input = id28out_result[getCycle()%2];

    id234out_output[(getCycle()+1)%2] = id234in_input;
  }
  HWRawBits<32> id186out_dataout;

  { // Node ID: 186 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id186in_datain = id28out_result[getCycle()%2];

    id186out_dataout = (shift_left_fixed(id186in_datain,(7l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id35out_output;

  { // Node ID: 35 (NodeReinterpret)
    const HWRawBits<32> &id35in_input = id186out_dataout;

    id35out_output = (cast_bits2fixed<32,0,UNSIGNED>(id35in_input));
  }
  { // Node ID: 211 (NodeConstantRawBits)
  }
  { // Node ID: 42 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id42in_a = id35out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id42in_b = id211out_value;

    HWOffsetFix<32,0,UNSIGNED> id42x_1;

    (id42x_1) = (and_fixed(id42in_a,id42in_b));
    id42out_result[(getCycle()+1)%2] = (id42x_1);
  }
  { // Node ID: 46 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id46in_a = id234out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id46in_b = id42out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id46x_1;

    (id46x_1) = (xor_fixed(id46in_a,id46in_b));
    id46out_result[(getCycle()+1)%2] = (id46x_1);
  }
  { // Node ID: 235 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id235in_input = id46out_result[getCycle()%2];

    id235out_output[(getCycle()+1)%2] = id235in_input;
  }
  HWRawBits<32> id187out_dataout;

  { // Node ID: 187 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id187in_datain = id46out_result[getCycle()%2];

    id187out_dataout = (shift_left_fixed(id187in_datain,(15l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id53out_output;

  { // Node ID: 53 (NodeReinterpret)
    const HWRawBits<32> &id53in_input = id187out_dataout;

    id53out_output = (cast_bits2fixed<32,0,UNSIGNED>(id53in_input));
  }
  { // Node ID: 210 (NodeConstantRawBits)
  }
  { // Node ID: 60 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id60in_a = id53out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id60in_b = id210out_value;

    HWOffsetFix<32,0,UNSIGNED> id60x_1;

    (id60x_1) = (and_fixed(id60in_a,id60in_b));
    id60out_result[(getCycle()+1)%2] = (id60x_1);
  }
  { // Node ID: 64 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id64in_a = id235out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id64in_b = id60out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id64x_1;

    (id64x_1) = (xor_fixed(id64in_a,id64in_b));
    id64out_result[(getCycle()+1)%2] = (id64x_1);
  }
  HWRawBits<32> id188out_dataout;

  { // Node ID: 188 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id188in_datain = id64out_result[getCycle()%2];

    id188out_dataout = (shift_right_fixed(id188in_datain,(18l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id71out_output;

  { // Node ID: 71 (NodeReinterpret)
    const HWRawBits<32> &id71in_input = id188out_dataout;

    id71out_output = (cast_bits2fixed<32,0,UNSIGNED>(id71in_input));
  }
  { // Node ID: 76 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id76in_a = id64out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id76in_b = id71out_output;

    HWOffsetFix<32,0,UNSIGNED> id76x_1;

    (id76x_1) = (xor_fixed(id76in_a,id76in_b));
    id76out_result[(getCycle()+1)%2] = (id76x_1);
  }
  { // Node ID: 143 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id143in_i = id76out_result[getCycle()%2];

    id143out_o[(getCycle()+5)%6] = (cast_fixed2float<8,24>(id143in_i));
  }
  { // Node ID: 220 (NodePO2FPMult)
    const HWFloat<8,24> &id220in_floatIn = id143out_o[getCycle()%6];

    id220out_floatOut[(getCycle()+1)%2] = (mul_float(id220in_floatIn,(c_hw_flt_8_24_2_3283064365386963En10val)));
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
        id5x_2 = (getMappedMemValue< HWOffsetFix<32,0,UNSIGNED> > ("rngKernelgen_seeds0", id5x_1) );
        break;
      default:
        id5x_2 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id5out_dataa[(getCycle()+2)%3] = (id5x_2);
  }
  HWOffsetFix<32,0,UNSIGNED> id81out_output;

  { // Node ID: 81 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id81in_input = id15out_result[getCycle()%2];

    id81out_output = id81in_input;
  }
  { // Node ID: 236 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id236in_input = id15out_result[getCycle()%2];

    id236out_output[(getCycle()+396)%397] = id236in_input;
  }
  HWRawBits<1> id84out_result;

  { // Node ID: 84 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id84in_a = id236out_output[getCycle()%397];

    id84out_result = (slice<31,1>(id84in_a));
  }
  { // Node ID: 238 (NodeFIFO)
    const HWRawBits<1> &id238in_input = id84out_result;

    id238out_output[(getCycle()+1)%2] = id238in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id78out_output;

  { // Node ID: 78 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id78in_input = id236out_output[getCycle()%397];

    id78out_output = id78in_input;
  }
  HWRawBits<31> id87out_result;

  { // Node ID: 87 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id87in_a = id78out_output;

    id87out_result = (slice<0,31>(id87in_a));
  }
  HWRawBits<32> id200out_result;

  { // Node ID: 200 (NodeCat)
    const HWRawBits<1> &id200in_in0 = id238out_output[getCycle()%2];
    const HWRawBits<31> &id200in_in1 = id87out_result;

    id200out_result = (cat(id200in_in0,id200in_in1));
  }
  HWOffsetFix<32,0,UNSIGNED> id99out_output;

  { // Node ID: 99 (NodeReinterpret)
    const HWRawBits<32> &id99in_input = id200out_result;

    id99out_output = (cast_bits2fixed<32,0,UNSIGNED>(id99in_input));
  }
  HWRawBits<32> id175out_dataout;

  { // Node ID: 175 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id175in_datain = id99out_output;

    id175out_dataout = (shift_right_fixed(id175in_datain,(1l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id106out_output;

  { // Node ID: 106 (NodeReinterpret)
    const HWRawBits<32> &id106in_input = id175out_dataout;

    id106out_output = (cast_bits2fixed<32,0,UNSIGNED>(id106in_input));
  }
  { // Node ID: 121 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id121in_a = id81out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id121in_b = id106out_output;

    HWOffsetFix<32,0,UNSIGNED> id121x_1;

    (id121x_1) = (xor_fixed(id121in_a,id121in_b));
    id121out_result[(getCycle()+1)%2] = (id121x_1);
  }
  HWRawBits<1> id113out_result;

  { // Node ID: 113 (NodeSlice)
    const HWOffsetFix<32,0,UNSIGNED> &id113in_a = id78out_output;

    id113out_result = (slice<0,1>(id113in_a));
  }
  { // Node ID: 118 (NodeMux)
    const HWRawBits<1> &id118in_sel = id113out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id118in_option0 = id116out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id118in_option1 = id215out_value;

    HWOffsetFix<32,0,UNSIGNED> id118x_1;

    switch((id118in_sel.getValueAsLong())) {
      case 0l:
        id118x_1 = id118in_option0;
        break;
      case 1l:
        id118x_1 = id118in_option1;
        break;
      default:
        id118x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id118out_result[(getCycle()+1)%2] = (id118x_1);
  }
  { // Node ID: 124 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id124in_a = id121out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id124in_b = id118out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id124x_1;

    (id124x_1) = (xor_fixed(id124in_a,id124in_b));
    id124out_result[(getCycle()+1)%2] = (id124x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id12out_output;

  { // Node ID: 12 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id12in_input = id124out_result[getCycle()%2];

    id12out_output = id12in_input;
  }
  { // Node ID: 240 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id240in_input = id12out_output;

    id240out_output[(getCycle()+224)%225] = id240in_input;
  }
  { // Node ID: 15 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_sel = id225out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id15in_option0 = id5out_dataa[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id15in_option1 = id240out_output[getCycle()%225];

    HWOffsetFix<32,0,UNSIGNED> id15x_1;

    switch((id15in_sel.getValueAsLong())) {
      case 0l:
        id15x_1 = id15in_option0;
        break;
      case 1l:
        id15x_1 = id15in_option1;
        break;
      default:
        id15x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id15out_result[(getCycle()+1)%2] = (id15x_1);
  }
  HWRawBits<32> id189out_dataout;

  { // Node ID: 189 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id189in_datain = id15out_result[getCycle()%2];

    id189out_dataout = (shift_right_fixed(id189in_datain,(11l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id20out_output;

  { // Node ID: 20 (NodeReinterpret)
    const HWRawBits<32> &id20in_input = id189out_dataout;

    id20out_output = (cast_bits2fixed<32,0,UNSIGNED>(id20in_input));
  }
  { // Node ID: 27 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id27in_a = id15out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id27in_b = id20out_output;

    HWOffsetFix<32,0,UNSIGNED> id27x_1;

    (id27x_1) = (xor_fixed(id27in_a,id27in_b));
    id27out_result[(getCycle()+1)%2] = (id27x_1);
  }
  { // Node ID: 241 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id241in_input = id27out_result[getCycle()%2];

    id241out_output[(getCycle()+1)%2] = id241in_input;
  }
  HWRawBits<32> id190out_dataout;

  { // Node ID: 190 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id190in_datain = id27out_result[getCycle()%2];

    id190out_dataout = (shift_left_fixed(id190in_datain,(7l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id32out_output;

  { // Node ID: 32 (NodeReinterpret)
    const HWRawBits<32> &id32in_input = id190out_dataout;

    id32out_output = (cast_bits2fixed<32,0,UNSIGNED>(id32in_input));
  }
  { // Node ID: 208 (NodeConstantRawBits)
  }
  { // Node ID: 40 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id40in_a = id32out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id40in_b = id208out_value;

    HWOffsetFix<32,0,UNSIGNED> id40x_1;

    (id40x_1) = (and_fixed(id40in_a,id40in_b));
    id40out_result[(getCycle()+1)%2] = (id40x_1);
  }
  { // Node ID: 45 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id45in_a = id241out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id45in_b = id40out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id45x_1;

    (id45x_1) = (xor_fixed(id45in_a,id45in_b));
    id45out_result[(getCycle()+1)%2] = (id45x_1);
  }
  { // Node ID: 242 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id242in_input = id45out_result[getCycle()%2];

    id242out_output[(getCycle()+1)%2] = id242in_input;
  }
  HWRawBits<32> id191out_dataout;

  { // Node ID: 191 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id191in_datain = id45out_result[getCycle()%2];

    id191out_dataout = (shift_left_fixed(id191in_datain,(15l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id50out_output;

  { // Node ID: 50 (NodeReinterpret)
    const HWRawBits<32> &id50in_input = id191out_dataout;

    id50out_output = (cast_bits2fixed<32,0,UNSIGNED>(id50in_input));
  }
  { // Node ID: 207 (NodeConstantRawBits)
  }
  { // Node ID: 58 (NodeAnd)
    const HWOffsetFix<32,0,UNSIGNED> &id58in_a = id50out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id58in_b = id207out_value;

    HWOffsetFix<32,0,UNSIGNED> id58x_1;

    (id58x_1) = (and_fixed(id58in_a,id58in_b));
    id58out_result[(getCycle()+1)%2] = (id58x_1);
  }
  { // Node ID: 63 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id63in_a = id242out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id63in_b = id58out_result[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id63x_1;

    (id63x_1) = (xor_fixed(id63in_a,id63in_b));
    id63out_result[(getCycle()+1)%2] = (id63x_1);
  }
  HWRawBits<32> id192out_dataout;

  { // Node ID: 192 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id192in_datain = id63out_result[getCycle()%2];

    id192out_dataout = (shift_right_fixed(id192in_datain,(18l)));
  }
  HWOffsetFix<32,0,UNSIGNED> id68out_output;

  { // Node ID: 68 (NodeReinterpret)
    const HWRawBits<32> &id68in_input = id192out_dataout;

    id68out_output = (cast_bits2fixed<32,0,UNSIGNED>(id68in_input));
  }
  { // Node ID: 75 (NodeXor)
    const HWOffsetFix<32,0,UNSIGNED> &id75in_a = id63out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id75in_b = id68out_output;

    HWOffsetFix<32,0,UNSIGNED> id75x_1;

    (id75x_1) = (xor_fixed(id75in_a,id75in_b));
    id75out_result[(getCycle()+1)%2] = (id75x_1);
  }
  { // Node ID: 142 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id142in_i = id75out_result[getCycle()%2];

    id142out_o[(getCycle()+5)%6] = (cast_fixed2float<8,24>(id142in_i));
  }
  { // Node ID: 221 (NodePO2FPMult)
    const HWFloat<8,24> &id221in_floatIn = id142out_o[getCycle()%6];

    id221out_floatOut[(getCycle()+1)%2] = (mul_float(id221in_floatIn,(c_hw_flt_8_24_2_3283064365386963En10val)));
  }
  HWRawBits<96> id197out_result;

  { // Node ID: 197 (NodeCat)
    const HWFloat<8,24> &id197in_in0 = id219out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id197in_in1 = id220out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id197in_in2 = id221out_floatOut[getCycle()%2];

    id197out_result = (cat((cat(id197in_in0,id197in_in1)),id197in_in2));
  }
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 155 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id155in_output_control = id153out_result;
    const HWRawBits<96> &id155in_data = id197out_result;

    bool id155x_1;

    (id155x_1) = ((id155in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(15l))&(isFlushingActive()))));
    if((id155x_1)) {
      writeOutput(m_y, id155in_data);
    }
  }
  { // Node ID: 165 (NodeConstantRawBits)
  }
  { // Node ID: 205 (NodeConstantRawBits)
  }
  { // Node ID: 162 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 163 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id163in_enable = id205out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id163in_max = id162out_value;

    HWOffsetFix<49,0,UNSIGNED> id163x_1;
    HWOffsetFix<1,0,UNSIGNED> id163x_2;
    HWOffsetFix<1,0,UNSIGNED> id163x_3;
    HWOffsetFix<49,0,UNSIGNED> id163x_4t_1e_1;

    id163out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id163st_count)));
    (id163x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id163st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id163x_2) = (gte_fixed((id163x_1),id163in_max));
    (id163x_3) = (and_fixed((id163x_2),id163in_enable));
    id163out_wrap = (id163x_3);
    if((id163in_enable.getValueAsBool())) {
      if(((id163x_3).getValueAsBool())) {
        (id163st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id163x_4t_1e_1) = (id163x_1);
        (id163st_count) = (id163x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id164out_output;

  { // Node ID: 164 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id164in_input = id163out_count;

    id164out_output = id164in_input;
  }
  if ( (getFillLevel() >= (1l)) && (getFlushLevel() < (1l)|| !isFlushingActive() ))
  { // Node ID: 166 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id166in_load = id165out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id166in_data = id164out_output;

    bool id166x_1;

    (id166x_1) = ((id166in_load.getValueAsBool())&(!(((getFlushLevel())>=(1l))&(isFlushingActive()))));
    if((id166x_1)) {
      setMappedRegValue("current_run_cycle_count", id166in_data);
    }
  }
  { // Node ID: 0 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 170 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id170in_start = id0out_value;

    if((id170in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
