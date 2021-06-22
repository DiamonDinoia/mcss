#include "stdsimheader.h"

namespace maxcompilersim {

void processingKernel::execute0() {
  { // Node ID: 2520 (NodeConstantRawBits)
  }
  { // Node ID: 4 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id5out_result;

  { // Node ID: 5 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_a = id4out_io_z_force_disabled;

    id5out_result = (not_fixed(id5in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 6 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id6in_enable = id5out_result;

    (id6st_read_next_cycle) = ((id6in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_z, id6st_read_next_cycle.getValueAsBool());
  }
  HWRawBits<32> id11out_result;

  { // Node ID: 11 (NodeSlice)
    const HWRawBits<128> &id11in_a = id6out_data;

    id11out_result = (slice<64,32>(id11in_a));
  }
  HWFloat<8,24> id12out_output;

  { // Node ID: 12 (NodeReinterpret)
    const HWRawBits<32> &id12in_input = id11out_result;

    id12out_output = (cast_bits2float<8,24>(id12in_input));
  }
  if ( (getFillLevel() >= (9l)) && (getFlushLevel() < (9l)|| !isFlushingActive() ))
  { // Node ID: 2521 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id2521in_output_control = id2520out_value;
    const HWFloat<8,24> &id2521in_data = id12out_output;

    bool id2521x_1;

    (id2521x_1) = ((id2521in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(9l))&(isFlushingActive()))));
    if((id2521x_1)) {
      writeOutput(m_internal_watch_track2_output, id2521in_data);
    }
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 16 (NodeWatch)
  }
  { // Node ID: 22 (NodeConstantRawBits)
  }
  { // Node ID: 3447 (NodeConstantRawBits)
  }
  { // Node ID: 2 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 3 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_enable = id3447out_value;
    const HWOffsetFix<65,0,UNSIGNED> &id3in_max = id2out_value;

    HWOffsetFix<65,0,UNSIGNED> id3x_1;
    HWOffsetFix<1,0,UNSIGNED> id3x_2;
    HWOffsetFix<1,0,UNSIGNED> id3x_3;
    HWOffsetFix<65,0,UNSIGNED> id3x_4t_1e_1;

    id3out_count = (cast_fixed2fixed<64,0,UNSIGNED,TRUNCATE>((id3st_count)));
    (id3x_1) = (add_fixed<65,0,UNSIGNED,TRUNCATE>((id3st_count),(c_hw_fix_65_0_uns_bits_2)));
    (id3x_2) = (gte_fixed((id3x_1),id3in_max));
    (id3x_3) = (and_fixed((id3x_2),id3in_enable));
    id3out_wrap = (id3x_3);
    if((id3in_enable.getValueAsBool())) {
      if(((id3x_3).getValueAsBool())) {
        (id3st_count) = (c_hw_fix_65_0_uns_bits_1);
      }
      else {
        (id3x_4t_1e_1) = (id3x_1);
        (id3st_count) = (id3x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWRawBits<32> id7out_result;

  { // Node ID: 7 (NodeSlice)
    const HWRawBits<128> &id7in_a = id6out_data;

    id7out_result = (slice<0,32>(id7in_a));
  }
  HWFloat<8,24> id8out_output;

  { // Node ID: 8 (NodeReinterpret)
    const HWRawBits<32> &id8in_input = id7out_result;

    id8out_output = (cast_bits2float<8,24>(id8in_input));
  }
  HWRawBits<32> id9out_result;

  { // Node ID: 9 (NodeSlice)
    const HWRawBits<128> &id9in_a = id6out_data;

    id9out_result = (slice<32,32>(id9in_a));
  }
  HWFloat<8,24> id10out_output;

  { // Node ID: 10 (NodeReinterpret)
    const HWRawBits<32> &id10in_input = id9out_result;

    id10out_output = (cast_bits2float<8,24>(id10in_input));
  }
  HWRawBits<32> id13out_result;

  { // Node ID: 13 (NodeSlice)
    const HWRawBits<128> &id13in_a = id6out_data;

    id13out_result = (slice<96,32>(id13in_a));
  }
  HWFloat<8,24> id14out_output;

  { // Node ID: 14 (NodeReinterpret)
    const HWRawBits<32> &id14in_input = id13out_result;

    id14out_output = (cast_bits2float<8,24>(id14in_input));
  }
  if ( (getFillLevel() >= (9l)) && (getFlushLevel() < (9l)|| !isFlushingActive() ))
  { // Node ID: 23 (NodePrintf)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_condition = id22out_value;
    const HWOffsetFix<64,0,UNSIGNED> &id23in_arg0 = id3out_count;
    const HWFloat<8,24> &id23in_arg1 = id8out_output;
    const HWFloat<8,24> &id23in_arg2 = id10out_output;
    const HWFloat<8,24> &id23in_arg3 = id12out_output;
    const HWFloat<8,24> &id23in_arg4 = id14out_output;

    if((id23in_condition.getValueAsBool())) {
      const HWOffsetFix<64,0,UNSIGNED> &_format_arg_0 = id23in_arg0;
      const HWFloat<8,24> &_format_arg_1 = id23in_arg1;
      const HWFloat<8,24> &_format_arg_2 = id23in_arg2;
      const HWFloat<8,24> &_format_arg_3 = id23in_arg3;
      const HWFloat<8,24> &_format_arg_4 = id23in_arg4;
      simPrintf("", 23, format_string_processingKernel_1("COUNT %i track: %.10f %.10f %.10f %.10f\n", _format_arg_0, _format_arg_1, _format_arg_2, _format_arg_3, _format_arg_4));
    }
  }
  { // Node ID: 3446 (NodeConstantRawBits)
  }
  { // Node ID: 1892 (NodeAdd)
    const HWOffsetFix<64,0,UNSIGNED> &id1892in_a = id3out_count;
    const HWOffsetFix<64,0,UNSIGNED> &id1892in_b = id3446out_value;

    id1892out_result[(getCycle()+1)%2] = (add_fixed<64,0,UNSIGNED,TONEAREVEN>(id1892in_a,id1892in_b));
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  { // Node ID: 2522 (NodeEqInlined)
    const HWOffsetFix<64,0,UNSIGNED> &id2522in_a = id1892out_result[getCycle()%2];
    const HWOffsetFix<64,0,UNSIGNED> &id2522in_b = id0out_numHists;

    id2522out_result[(getCycle()+1)%2] = (eq_fixed(id2522in_a,id2522in_b));
  }
  { // Node ID: 1894 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1895out_result;

  { // Node ID: 1895 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1895in_a = id1894out_io_output_force_disabled;

    id1895out_result = (not_fixed(id1895in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1896out_result;

  { // Node ID: 1896 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1896in_a = id2522out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1896in_b = id1895out_result;

    HWOffsetFix<1,0,UNSIGNED> id1896x_1;

    (id1896x_1) = (and_fixed(id1896in_a,id1896in_b));
    id1896out_result = (id1896x_1);
  }
  { // Node ID: 4478 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4478in_input = id1896out_result;

    id4478out_output[(getCycle()+111)%112] = id4478in_input;
  }
  { // Node ID: 2517 (NodeConstantRawBits)
  }
  { // Node ID: 2518 (NodeConstantRawBits)
  }
  { // Node ID: 75 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (112l)))
  { // Node ID: 76 (NodePulse)
    const HWOffsetFix<1,0,UNSIGNED> &id76in_enable = id75out_value;

    if(((id76st_count)==(1l))) {
      (id76st_value) = (c_hw_fix_1_0_uns_bits_1);
    }
    if((id76in_enable.getValueAsBool())) {
      (id76st_count) = ((id76st_count)+(1l));
    }
    id76out_output = (id76st_value);
  }
  { // Node ID: 3456 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3456in_input = id76out_output;

    id3456out_output[(getCycle()+1)%2] = id3456in_input;
  }
  { // Node ID: 3455 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3455in_input = id3456out_output[getCycle()%2];

    id3455out_output[(getCycle()+1)%2] = id3455in_input;
  }
  { // Node ID: 3454 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3454in_input = id3455out_output[getCycle()%2];

    id3454out_output[(getCycle()+1)%2] = id3454in_input;
  }
  { // Node ID: 3893 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3893in_input = id3454out_output[getCycle()%2];

    id3893out_output[(getCycle()+6)%7] = id3893in_input;
  }
  { // Node ID: 4480 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4480in_input = id3893out_output[getCycle()%7];

    id4480out_output[(getCycle()+1)%2] = id4480in_input;
  }
  { // Node ID: 3445 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2528out_result;

  { // Node ID: 2528 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2528in_a = id3445out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2528in_b = id3457out_output[getCycle()%2];

    id2528out_result = (eq_fixed(id2528in_a,id2528in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1285out_o;

  { // Node ID: 1285 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1285in_i = id2528out_result;

    id1285out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1285in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1287out_result;

  { // Node ID: 1287 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1287in_a = id3477out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1287in_b = id1285out_o;

    id1287out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1287in_a,id1287in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1288out_result;

  { // Node ID: 1288 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1288in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1288in_option0 = id1287out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1288in_option1 = id1285out_o;

    HWOffsetFix<32,0,UNSIGNED> id1288x_1;

    switch((id1288in_sel.getValueAsLong())) {
      case 0l:
        id1288x_1 = id1288in_option0;
        break;
      case 1l:
        id1288x_1 = id1288in_option1;
        break;
      default:
        id1288x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1288out_result = (id1288x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1286out_output;

  { // Node ID: 1286 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1286in_input = id1288out_result;

    id1286out_output = id1286in_input;
  }
  { // Node ID: 3477 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3477in_input = id1286out_output;

    id3477out_output[(getCycle()+1)%2] = id3477in_input;
  }
  { // Node ID: 24 (NodeMul)
    const HWFloat<8,24> &id24in_a = id8out_output;
    const HWFloat<8,24> &id24in_b = id8out_output;

    id24out_result[(getCycle()+8)%9] = (mul_float(id24in_a,id24in_b));
  }
  { // Node ID: 25 (NodeMul)
    const HWFloat<8,24> &id25in_a = id10out_output;
    const HWFloat<8,24> &id25in_b = id10out_output;

    id25out_result[(getCycle()+8)%9] = (mul_float(id25in_a,id25in_b));
  }
  { // Node ID: 26 (NodeAdd)
    const HWFloat<8,24> &id26in_a = id24out_result[getCycle()%9];
    const HWFloat<8,24> &id26in_b = id25out_result[getCycle()%9];

    id26out_result[(getCycle()+11)%12] = (add_float(id26in_a,id26in_b));
  }
  { // Node ID: 27 (NodeSqrt)
    const HWFloat<8,24> &id27in_a = id26out_result[getCycle()%12];

    id27out_result[(getCycle()+28)%29] = (sqrt_float(id27in_a));
  }
  { // Node ID: 3466 (NodeFIFO)
    const HWFloat<8,24> &id3466in_input = id14out_output;

    id3466out_output[(getCycle()+47)%48] = id3466in_input;
  }
  { // Node ID: 29 (NodeDiv)
    const HWFloat<8,24> &id29in_a = id27out_result[getCycle()%29];
    const HWFloat<8,24> &id29in_b = id3466out_output[getCycle()%48];

    id29out_result[(getCycle()+28)%29] = (div_float(id29in_a,id29in_b));
  }
  { // Node ID: 3444 (NodeConstantRawBits)
  }
  { // Node ID: 31 (NodeMul)
    const HWFloat<8,24> &id31in_a = id29out_result[getCycle()%29];
    const HWFloat<8,24> &id31in_b = id3444out_value;

    id31out_result[(getCycle()+8)%9] = (mul_float(id31in_a,id31in_b));
  }
  HWFloat<8,24> id32out_result;

  { // Node ID: 32 (NodeNeg)
    const HWFloat<8,24> &id32in_a = id31out_result[getCycle()%9];

    id32out_result = (neg_float(id32in_a));
  }
  HWRawBits<8> id33out_result;

  { // Node ID: 33 (NodeSlice)
    const HWFloat<8,24> &id33in_a = id32out_result;

    id33out_result = (slice<23,8>(id33in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id34out_output;

  { // Node ID: 34 (NodeReinterpret)
    const HWRawBits<8> &id34in_input = id33out_result;

    id34out_output = (cast_bits2fixed<8,0,UNSIGNED>(id34in_input));
  }
  { // Node ID: 3443 (NodeConstantRawBits)
  }
  { // Node ID: 36 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id36in_a = id34out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id36in_b = id3443out_value;

    id36out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id36in_a,id36in_b));
  }
  HWRawBits<1> id2523out_result;

  { // Node ID: 2523 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2523in_a = id36out_result[getCycle()%2];

    id2523out_result = (slice<8,1>(id2523in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id2524out_output;

  { // Node ID: 2524 (NodeReinterpret)
    const HWRawBits<1> &id2524in_input = id2523out_result;

    id2524out_output = (cast_bits2fixed<1,0,UNSIGNED>(id2524in_input));
  }
  { // Node ID: 3467 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3467in_input = id2524out_output;

    id3467out_output[(getCycle()+1)%2] = id3467in_input;
  }
  { // Node ID: 3442 (NodeConstantRawBits)
  }
  { // Node ID: 2525 (NodeEqInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2525in_a = id36out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2525in_b = id3442out_value;

    id2525out_result[(getCycle()+1)%2] = (eq_fixed(id2525in_a,id2525in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id56out_result;

  { // Node ID: 56 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id56in_a = id2525out_result[getCycle()%2];

    id56out_result = (not_fixed(id56in_a));
  }
  { // Node ID: 57 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id57in_a = id3467out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id57in_b = id56out_result;

    HWOffsetFix<1,0,UNSIGNED> id57x_1;

    (id57x_1) = (and_fixed(id57in_a,id57in_b));
    id57out_result[(getCycle()+1)%2] = (id57x_1);
  }
  { // Node ID: 3474 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3474in_input = id57out_result[getCycle()%2];

    id3474out_output[(getCycle()+8)%9] = id3474in_input;
  }
  { // Node ID: 3472 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3472in_input = id2525out_result[getCycle()%2];

    id3472out_output[(getCycle()+9)%10] = id3472in_input;
  }
  { // Node ID: 3469 (NodeFIFO)
    const HWFloat<8,24> &id3469in_input = id32out_result;

    id3469out_output[(getCycle()+7)%8] = id3469in_input;
  }
  { // Node ID: 4481 (NodeFIFO)
    const HWFloat<8,24> &id4481in_input = id3469out_output[getCycle()%8];

    id4481out_output[(getCycle()+1)%2] = id4481in_input;
  }
  { // Node ID: 3441 (NodeConstantRawBits)
  }
  { // Node ID: 51 (NodeGt)
    const HWFloat<8,24> &id51in_a = id4481out_output[getCycle()%2];
    const HWFloat<8,24> &id51in_b = id3441out_value;

    id51out_result[(getCycle()+2)%3] = (gt_float(id51in_a,id51in_b));
  }
  HWRawBits<32> id2526out_output;

  { // Node ID: 2526 (NodeReinterpret)
    const HWFloat<8,24> &id2526in_input = id3469out_output[getCycle()%8];

    id2526out_output = (cast_float2bits(id2526in_input));
  }
  { // Node ID: 3440 (NodeConstantRawBits)
  }
  { // Node ID: 39 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id39in_a = id3440out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id39in_b = id36out_result[getCycle()%2];

    id39out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id39in_a,id39in_b));
  }
  { // Node ID: 3439 (NodeConstantRawBits)
  }
  { // Node ID: 2527 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2527in_a = id39out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2527in_b = id3439out_value;

    id2527out_result[(getCycle()+1)%2] = (gt_fixed(id2527in_a,id2527in_b));
  }
  { // Node ID: 3470 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3470in_input = id2527out_result[getCycle()%2];

    id3470out_output[(getCycle()+3)%4] = id3470in_input;
  }
  { // Node ID: 40 (NodeConstantRawBits)
  }
  HWOffsetFix<5,0,UNSIGNED> id43out_o;

  { // Node ID: 43 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id43in_i = id39out_result[getCycle()%2];

    id43out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id43in_i));
  }
  { // Node ID: 44 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id44in_datain = id40out_value;
    const HWOffsetFix<5,0,UNSIGNED> &id44in_shift = id43out_o;

    id44out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id44in_datain,(id44in_shift.getValueAsLong())));
  }
  HWOffsetFix<32,0,UNSIGNED> id45out_output;

  { // Node ID: 45 (NodeReinterpret)
    const HWRawBits<32> &id45in_input = id44out_dataout[getCycle()%5];

    id45out_output = (cast_bits2fixed<32,0,UNSIGNED>(id45in_input));
  }
  { // Node ID: 46 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id46in_sel = id3470out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id46in_option0 = id40out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id46in_option1 = id45out_output;

    HWOffsetFix<32,0,UNSIGNED> id46x_1;

    switch((id46in_sel.getValueAsLong())) {
      case 0l:
        id46x_1 = id46in_option0;
        break;
      case 1l:
        id46x_1 = id46in_option1;
        break;
      default:
        id46x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id46out_result[(getCycle()+1)%2] = (id46x_1);
  }
  HWRawBits<32> id47out_output;

  { // Node ID: 47 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id47in_input = id46out_result[getCycle()%2];

    id47out_output = (cast_fixed2bits(id47in_input));
  }
  { // Node ID: 48 (NodeAnd)
    const HWRawBits<32> &id48in_a = id2526out_output;
    const HWRawBits<32> &id48in_b = id47out_output;

    HWRawBits<32> id48x_1;

    (id48x_1) = (and_bits(id48in_a,id48in_b));
    id48out_result[(getCycle()+1)%2] = (id48x_1);
  }
  HWFloat<8,24> id49out_output;

  { // Node ID: 49 (NodeReinterpret)
    const HWRawBits<32> &id49in_input = id48out_result[getCycle()%2];

    id49out_output = (cast_bits2float<8,24>(id49in_input));
  }
  { // Node ID: 58 (NodeNeq)
    const HWFloat<8,24> &id58in_a = id49out_output;
    const HWFloat<8,24> &id58in_b = id4481out_output[getCycle()%2];

    id58out_result[(getCycle()+2)%3] = (neq_float(id58in_a,id58in_b));
  }
  { // Node ID: 59 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id59in_a = id51out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id59in_b = id58out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id59x_1;

    (id59x_1) = (and_fixed(id59in_a,id59in_b));
    id59out_result[(getCycle()+1)%2] = (id59x_1);
  }
  { // Node ID: 62 (NodeConstantRawBits)
  }
  { // Node ID: 61 (NodeConstantRawBits)
  }
  HWOffsetFix<2,0,UNSIGNED> id63out_result;

  { // Node ID: 63 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id63in_sel = id59out_result[getCycle()%2];
    const HWOffsetFix<2,0,UNSIGNED> &id63in_option0 = id62out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id63in_option1 = id61out_value;

    HWOffsetFix<2,0,UNSIGNED> id63x_1;

    switch((id63in_sel.getValueAsLong())) {
      case 0l:
        id63x_1 = id63in_option0;
        break;
      case 1l:
        id63x_1 = id63in_option1;
        break;
      default:
        id63x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id63out_result = (id63x_1);
  }
  { // Node ID: 64 (NodeConstantRawBits)
  }
  HWOffsetFix<2,0,UNSIGNED> id65out_result;

  { // Node ID: 65 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id65in_sel = id3472out_output[getCycle()%10];
    const HWOffsetFix<2,0,UNSIGNED> &id65in_option0 = id63out_result;
    const HWOffsetFix<2,0,UNSIGNED> &id65in_option1 = id64out_value;

    HWOffsetFix<2,0,UNSIGNED> id65x_1;

    switch((id65in_sel.getValueAsLong())) {
      case 0l:
        id65x_1 = id65in_option0;
        break;
      case 1l:
        id65x_1 = id65in_option1;
        break;
      default:
        id65x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id65out_result = (id65x_1);
  }
  { // Node ID: 3473 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3473in_input = id51out_result[getCycle()%3];

    id3473out_output[(getCycle()+1)%2] = id3473in_input;
  }
  HWOffsetFix<2,0,UNSIGNED> id60out_o;

  { // Node ID: 60 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id60in_i = id3473out_output[getCycle()%2];

    id60out_o = (cast_fixed2fixed<2,0,UNSIGNED,TONEAREVEN>(id60in_i));
  }
  HWOffsetFix<2,0,UNSIGNED> id66out_result;

  { // Node ID: 66 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_sel = id3474out_output[getCycle()%9];
    const HWOffsetFix<2,0,UNSIGNED> &id66in_option0 = id65out_result;
    const HWOffsetFix<2,0,UNSIGNED> &id66in_option1 = id60out_o;

    HWOffsetFix<2,0,UNSIGNED> id66x_1;

    switch((id66in_sel.getValueAsLong())) {
      case 0l:
        id66x_1 = id66in_option0;
        break;
      case 1l:
        id66x_1 = id66in_option1;
        break;
      default:
        id66x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id66out_result = (id66x_1);
  }
  { // Node ID: 3475 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id3475in_input = id66out_result;

    id3475out_output[(getCycle()+8)%9] = id3475in_input;
  }
  { // Node ID: 2519 (NodeConstantRawBits)
  }
  { // Node ID: 67 (NodeConstantRawBits)
  }
  { // Node ID: 3476 (NodeFIFO)
    const HWFloat<8,24> &id3476in_input = id49out_output;

    id3476out_output[(getCycle()+11)%12] = id3476in_input;
  }
  { // Node ID: 3438 (NodeConstantRawBits)
  }
  { // Node ID: 71 (NodeAdd)
    const HWFloat<8,24> &id71in_a = id49out_output;
    const HWFloat<8,24> &id71in_b = id3438out_value;

    id71out_result[(getCycle()+11)%12] = (add_float(id71in_a,id71in_b));
  }
  { // Node ID: 72 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id72in_sel = id3475out_output[getCycle()%9];
    const HWFloat<8,24> &id72in_option0 = id2519out_value;
    const HWFloat<8,24> &id72in_option1 = id67out_value;
    const HWFloat<8,24> &id72in_option2 = id3476out_output[getCycle()%12];
    const HWFloat<8,24> &id72in_option3 = id71out_result[getCycle()%12];

    HWFloat<8,24> id72x_1;

    switch((id72in_sel.getValueAsLong())) {
      case 0l:
        id72x_1 = id72in_option0;
        break;
      case 1l:
        id72x_1 = id72in_option1;
        break;
      case 2l:
        id72x_1 = id72in_option2;
        break;
      case 3l:
        id72x_1 = id72in_option3;
        break;
      default:
        id72x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id72out_result[(getCycle()+1)%2] = (id72x_1);
  }
  HWFloat<8,24> id73out_result;

  { // Node ID: 73 (NodeNeg)
    const HWFloat<8,24> &id73in_a = id72out_result[getCycle()%2];

    id73out_result = (neg_float(id73in_a));
  }
  { // Node ID: 74 (NodeCast)
    const HWFloat<8,24> &id74in_i = id73out_result;

    id74out_o[(getCycle()+7)%8] = (cast_float2fixed<32,0,UNSIGNED,TONEAREVEN>(id74in_i));
  }
  { // Node ID: 3459 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3459in_input = id74out_o[getCycle()%8];

    id3459out_output[(getCycle()+1)%2] = id3459in_input;
  }
  { // Node ID: 3458 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3458in_input = id3459out_output[getCycle()%2];

    id3458out_output[(getCycle()+1)%2] = id3458in_input;
  }
  { // Node ID: 3457 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3457in_input = id3458out_output[getCycle()%2];

    id3457out_output[(getCycle()+1)%2] = id3457in_input;
  }
  { // Node ID: 3437 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2529out_result;

  { // Node ID: 2529 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2529in_a = id3437out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2529in_b = id3457out_output[getCycle()%2];

    id2529out_result = (eq_fixed(id2529in_a,id2529in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1273out_o;

  { // Node ID: 1273 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1273in_i = id2529out_result;

    id1273out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1273in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1275out_result;

  { // Node ID: 1275 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1275in_a = id3479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1275in_b = id1273out_o;

    id1275out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1275in_a,id1275in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1276out_result;

  { // Node ID: 1276 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1276in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1276in_option0 = id1275out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1276in_option1 = id1273out_o;

    HWOffsetFix<32,0,UNSIGNED> id1276x_1;

    switch((id1276in_sel.getValueAsLong())) {
      case 0l:
        id1276x_1 = id1276in_option0;
        break;
      case 1l:
        id1276x_1 = id1276in_option1;
        break;
      default:
        id1276x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1276out_result = (id1276x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1274out_output;

  { // Node ID: 1274 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1274in_input = id1276out_result;

    id1274out_output = id1274in_input;
  }
  { // Node ID: 3479 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3479in_input = id1274out_output;

    id3479out_output[(getCycle()+1)%2] = id3479in_input;
  }
  { // Node ID: 3436 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2530out_result;

  { // Node ID: 2530 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2530in_a = id3436out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2530in_b = id3457out_output[getCycle()%2];

    id2530out_result = (eq_fixed(id2530in_a,id2530in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1261out_o;

  { // Node ID: 1261 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1261in_i = id2530out_result;

    id1261out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1261in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1263out_result;

  { // Node ID: 1263 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1263in_a = id3481out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1263in_b = id1261out_o;

    id1263out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1263in_a,id1263in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1264out_result;

  { // Node ID: 1264 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1264in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1264in_option0 = id1263out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1264in_option1 = id1261out_o;

    HWOffsetFix<32,0,UNSIGNED> id1264x_1;

    switch((id1264in_sel.getValueAsLong())) {
      case 0l:
        id1264x_1 = id1264in_option0;
        break;
      case 1l:
        id1264x_1 = id1264in_option1;
        break;
      default:
        id1264x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1264out_result = (id1264x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1262out_output;

  { // Node ID: 1262 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1262in_input = id1264out_result;

    id1262out_output = id1262in_input;
  }
  { // Node ID: 3481 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3481in_input = id1262out_output;

    id3481out_output[(getCycle()+1)%2] = id3481in_input;
  }
  { // Node ID: 3435 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2531out_result;

  { // Node ID: 2531 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2531in_a = id3435out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2531in_b = id3457out_output[getCycle()%2];

    id2531out_result = (eq_fixed(id2531in_a,id2531in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1249out_o;

  { // Node ID: 1249 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1249in_i = id2531out_result;

    id1249out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1249in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1251out_result;

  { // Node ID: 1251 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1251in_a = id3483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1251in_b = id1249out_o;

    id1251out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1251in_a,id1251in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1252out_result;

  { // Node ID: 1252 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1252in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1252in_option0 = id1251out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1252in_option1 = id1249out_o;

    HWOffsetFix<32,0,UNSIGNED> id1252x_1;

    switch((id1252in_sel.getValueAsLong())) {
      case 0l:
        id1252x_1 = id1252in_option0;
        break;
      case 1l:
        id1252x_1 = id1252in_option1;
        break;
      default:
        id1252x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1252out_result = (id1252x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1250out_output;

  { // Node ID: 1250 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1250in_input = id1252out_result;

    id1250out_output = id1250in_input;
  }
  { // Node ID: 3483 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3483in_input = id1250out_output;

    id3483out_output[(getCycle()+1)%2] = id3483in_input;
  }
  { // Node ID: 3434 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2532out_result;

  { // Node ID: 2532 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2532in_a = id3434out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2532in_b = id3457out_output[getCycle()%2];

    id2532out_result = (eq_fixed(id2532in_a,id2532in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1237out_o;

  { // Node ID: 1237 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1237in_i = id2532out_result;

    id1237out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1237in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1239out_result;

  { // Node ID: 1239 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1239in_a = id3485out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1239in_b = id1237out_o;

    id1239out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1239in_a,id1239in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1240out_result;

  { // Node ID: 1240 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1240in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1240in_option0 = id1239out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1240in_option1 = id1237out_o;

    HWOffsetFix<32,0,UNSIGNED> id1240x_1;

    switch((id1240in_sel.getValueAsLong())) {
      case 0l:
        id1240x_1 = id1240in_option0;
        break;
      case 1l:
        id1240x_1 = id1240in_option1;
        break;
      default:
        id1240x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1240out_result = (id1240x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1238out_output;

  { // Node ID: 1238 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1238in_input = id1240out_result;

    id1238out_output = id1238in_input;
  }
  { // Node ID: 3485 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3485in_input = id1238out_output;

    id3485out_output[(getCycle()+1)%2] = id3485in_input;
  }
  { // Node ID: 3433 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2533out_result;

  { // Node ID: 2533 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2533in_a = id3433out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2533in_b = id3457out_output[getCycle()%2];

    id2533out_result = (eq_fixed(id2533in_a,id2533in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1225out_o;

  { // Node ID: 1225 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1225in_i = id2533out_result;

    id1225out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1225in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1227out_result;

  { // Node ID: 1227 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1227in_a = id3487out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1227in_b = id1225out_o;

    id1227out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1227in_a,id1227in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1228out_result;

  { // Node ID: 1228 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1228in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1228in_option0 = id1227out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1228in_option1 = id1225out_o;

    HWOffsetFix<32,0,UNSIGNED> id1228x_1;

    switch((id1228in_sel.getValueAsLong())) {
      case 0l:
        id1228x_1 = id1228in_option0;
        break;
      case 1l:
        id1228x_1 = id1228in_option1;
        break;
      default:
        id1228x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1228out_result = (id1228x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1226out_output;

  { // Node ID: 1226 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1226in_input = id1228out_result;

    id1226out_output = id1226in_input;
  }
  { // Node ID: 3487 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3487in_input = id1226out_output;

    id3487out_output[(getCycle()+1)%2] = id3487in_input;
  }
  { // Node ID: 3432 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2534out_result;

  { // Node ID: 2534 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2534in_a = id3432out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2534in_b = id3457out_output[getCycle()%2];

    id2534out_result = (eq_fixed(id2534in_a,id2534in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1213out_o;

  { // Node ID: 1213 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1213in_i = id2534out_result;

    id1213out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1213in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1215out_result;

  { // Node ID: 1215 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1215in_a = id3489out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1215in_b = id1213out_o;

    id1215out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1215in_a,id1215in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1216out_result;

  { // Node ID: 1216 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1216in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1216in_option0 = id1215out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1216in_option1 = id1213out_o;

    HWOffsetFix<32,0,UNSIGNED> id1216x_1;

    switch((id1216in_sel.getValueAsLong())) {
      case 0l:
        id1216x_1 = id1216in_option0;
        break;
      case 1l:
        id1216x_1 = id1216in_option1;
        break;
      default:
        id1216x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1216out_result = (id1216x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1214out_output;

  { // Node ID: 1214 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1214in_input = id1216out_result;

    id1214out_output = id1214in_input;
  }
  { // Node ID: 3489 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3489in_input = id1214out_output;

    id3489out_output[(getCycle()+1)%2] = id3489in_input;
  }
  { // Node ID: 3431 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2535out_result;

  { // Node ID: 2535 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2535in_a = id3431out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2535in_b = id3457out_output[getCycle()%2];

    id2535out_result = (eq_fixed(id2535in_a,id2535in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1201out_o;

  { // Node ID: 1201 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1201in_i = id2535out_result;

    id1201out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1201in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1203out_result;

  { // Node ID: 1203 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1203in_a = id3491out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1203in_b = id1201out_o;

    id1203out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1203in_a,id1203in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1204out_result;

  { // Node ID: 1204 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1204in_sel = id4480out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1204in_option0 = id1203out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1204in_option1 = id1201out_o;

    HWOffsetFix<32,0,UNSIGNED> id1204x_1;

    switch((id1204in_sel.getValueAsLong())) {
      case 0l:
        id1204x_1 = id1204in_option0;
        break;
      case 1l:
        id1204x_1 = id1204in_option1;
        break;
      default:
        id1204x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1204out_result = (id1204x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1202out_output;

  { // Node ID: 1202 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1202in_input = id1204out_result;

    id1202out_output = id1202in_input;
  }
  { // Node ID: 3491 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3491in_input = id1202out_output;

    id3491out_output[(getCycle()+1)%2] = id3491in_input;
  }
  { // Node ID: 3453 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3453in_input = id3454out_output[getCycle()%2];

    id3453out_output[(getCycle()+1)%2] = id3453in_input;
  }
  { // Node ID: 3962 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3962in_input = id3453out_output[getCycle()%2];

    id3962out_output[(getCycle()+5)%6] = id3962in_input;
  }
  { // Node ID: 4482 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4482in_input = id3962out_output[getCycle()%6];

    id4482out_output[(getCycle()+1)%2] = id4482in_input;
  }
  { // Node ID: 3430 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2536out_result;

  { // Node ID: 2536 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2536in_a = id3430out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2536in_b = id3457out_output[getCycle()%2];

    id2536out_result = (eq_fixed(id2536in_a,id2536in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1189out_o;

  { // Node ID: 1189 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1189in_i = id2536out_result;

    id1189out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1189in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1191out_result;

  { // Node ID: 1191 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1191in_a = id3493out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1191in_b = id1189out_o;

    id1191out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1191in_a,id1191in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1192out_result;

  { // Node ID: 1192 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1192in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1192in_option0 = id1191out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1192in_option1 = id1189out_o;

    HWOffsetFix<32,0,UNSIGNED> id1192x_1;

    switch((id1192in_sel.getValueAsLong())) {
      case 0l:
        id1192x_1 = id1192in_option0;
        break;
      case 1l:
        id1192x_1 = id1192in_option1;
        break;
      default:
        id1192x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1192out_result = (id1192x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1190out_output;

  { // Node ID: 1190 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1190in_input = id1192out_result;

    id1190out_output = id1190in_input;
  }
  { // Node ID: 3493 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3493in_input = id1190out_output;

    id3493out_output[(getCycle()+1)%2] = id3493in_input;
  }
  { // Node ID: 3429 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2537out_result;

  { // Node ID: 2537 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2537in_a = id3429out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2537in_b = id3457out_output[getCycle()%2];

    id2537out_result = (eq_fixed(id2537in_a,id2537in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1177out_o;

  { // Node ID: 1177 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1177in_i = id2537out_result;

    id1177out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1177in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1179out_result;

  { // Node ID: 1179 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1179in_a = id3495out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1179in_b = id1177out_o;

    id1179out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1179in_a,id1179in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1180out_result;

  { // Node ID: 1180 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1180in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1180in_option0 = id1179out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1180in_option1 = id1177out_o;

    HWOffsetFix<32,0,UNSIGNED> id1180x_1;

    switch((id1180in_sel.getValueAsLong())) {
      case 0l:
        id1180x_1 = id1180in_option0;
        break;
      case 1l:
        id1180x_1 = id1180in_option1;
        break;
      default:
        id1180x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1180out_result = (id1180x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1178out_output;

  { // Node ID: 1178 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1178in_input = id1180out_result;

    id1178out_output = id1178in_input;
  }
  { // Node ID: 3495 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3495in_input = id1178out_output;

    id3495out_output[(getCycle()+1)%2] = id3495in_input;
  }
  { // Node ID: 3428 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2538out_result;

  { // Node ID: 2538 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2538in_a = id3428out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2538in_b = id3457out_output[getCycle()%2];

    id2538out_result = (eq_fixed(id2538in_a,id2538in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1165out_o;

  { // Node ID: 1165 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1165in_i = id2538out_result;

    id1165out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1165in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1167out_result;

  { // Node ID: 1167 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1167in_a = id3497out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1167in_b = id1165out_o;

    id1167out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1167in_a,id1167in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1168out_result;

  { // Node ID: 1168 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1168in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1168in_option0 = id1167out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1168in_option1 = id1165out_o;

    HWOffsetFix<32,0,UNSIGNED> id1168x_1;

    switch((id1168in_sel.getValueAsLong())) {
      case 0l:
        id1168x_1 = id1168in_option0;
        break;
      case 1l:
        id1168x_1 = id1168in_option1;
        break;
      default:
        id1168x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1168out_result = (id1168x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1166out_output;

  { // Node ID: 1166 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1166in_input = id1168out_result;

    id1166out_output = id1166in_input;
  }
  { // Node ID: 3497 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3497in_input = id1166out_output;

    id3497out_output[(getCycle()+1)%2] = id3497in_input;
  }
  { // Node ID: 3427 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2539out_result;

  { // Node ID: 2539 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2539in_a = id3427out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2539in_b = id3457out_output[getCycle()%2];

    id2539out_result = (eq_fixed(id2539in_a,id2539in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1153out_o;

  { // Node ID: 1153 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1153in_i = id2539out_result;

    id1153out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1153in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1155out_result;

  { // Node ID: 1155 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1155in_a = id3499out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1155in_b = id1153out_o;

    id1155out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1155in_a,id1155in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1156out_result;

  { // Node ID: 1156 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1156in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1156in_option0 = id1155out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1156in_option1 = id1153out_o;

    HWOffsetFix<32,0,UNSIGNED> id1156x_1;

    switch((id1156in_sel.getValueAsLong())) {
      case 0l:
        id1156x_1 = id1156in_option0;
        break;
      case 1l:
        id1156x_1 = id1156in_option1;
        break;
      default:
        id1156x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1156out_result = (id1156x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1154out_output;

  { // Node ID: 1154 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1154in_input = id1156out_result;

    id1154out_output = id1154in_input;
  }
  { // Node ID: 3499 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3499in_input = id1154out_output;

    id3499out_output[(getCycle()+1)%2] = id3499in_input;
  }
  { // Node ID: 3426 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2540out_result;

  { // Node ID: 2540 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2540in_a = id3426out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2540in_b = id3457out_output[getCycle()%2];

    id2540out_result = (eq_fixed(id2540in_a,id2540in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1141out_o;

  { // Node ID: 1141 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1141in_i = id2540out_result;

    id1141out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1141in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1143out_result;

  { // Node ID: 1143 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1143in_a = id3501out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1143in_b = id1141out_o;

    id1143out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1143in_a,id1143in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1144out_result;

  { // Node ID: 1144 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1144in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1144in_option0 = id1143out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1144in_option1 = id1141out_o;

    HWOffsetFix<32,0,UNSIGNED> id1144x_1;

    switch((id1144in_sel.getValueAsLong())) {
      case 0l:
        id1144x_1 = id1144in_option0;
        break;
      case 1l:
        id1144x_1 = id1144in_option1;
        break;
      default:
        id1144x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1144out_result = (id1144x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1142out_output;

  { // Node ID: 1142 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1142in_input = id1144out_result;

    id1142out_output = id1142in_input;
  }
  { // Node ID: 3501 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3501in_input = id1142out_output;

    id3501out_output[(getCycle()+1)%2] = id3501in_input;
  }
  { // Node ID: 3425 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2541out_result;

  { // Node ID: 2541 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2541in_a = id3425out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2541in_b = id3457out_output[getCycle()%2];

    id2541out_result = (eq_fixed(id2541in_a,id2541in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1129out_o;

  { // Node ID: 1129 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1129in_i = id2541out_result;

    id1129out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1129in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1131out_result;

  { // Node ID: 1131 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1131in_a = id3503out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1131in_b = id1129out_o;

    id1131out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1131in_a,id1131in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1132out_result;

  { // Node ID: 1132 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1132in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1132in_option0 = id1131out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1132in_option1 = id1129out_o;

    HWOffsetFix<32,0,UNSIGNED> id1132x_1;

    switch((id1132in_sel.getValueAsLong())) {
      case 0l:
        id1132x_1 = id1132in_option0;
        break;
      case 1l:
        id1132x_1 = id1132in_option1;
        break;
      default:
        id1132x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1132out_result = (id1132x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1130out_output;

  { // Node ID: 1130 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1130in_input = id1132out_result;

    id1130out_output = id1130in_input;
  }
  { // Node ID: 3503 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3503in_input = id1130out_output;

    id3503out_output[(getCycle()+1)%2] = id3503in_input;
  }
  { // Node ID: 3424 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2542out_result;

  { // Node ID: 2542 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2542in_a = id3424out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2542in_b = id3457out_output[getCycle()%2];

    id2542out_result = (eq_fixed(id2542in_a,id2542in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1117out_o;

  { // Node ID: 1117 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1117in_i = id2542out_result;

    id1117out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1117in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1119out_result;

  { // Node ID: 1119 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1119in_a = id3505out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1119in_b = id1117out_o;

    id1119out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1119in_a,id1119in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1120out_result;

  { // Node ID: 1120 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1120in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1120in_option0 = id1119out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1120in_option1 = id1117out_o;

    HWOffsetFix<32,0,UNSIGNED> id1120x_1;

    switch((id1120in_sel.getValueAsLong())) {
      case 0l:
        id1120x_1 = id1120in_option0;
        break;
      case 1l:
        id1120x_1 = id1120in_option1;
        break;
      default:
        id1120x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1120out_result = (id1120x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1118out_output;

  { // Node ID: 1118 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1118in_input = id1120out_result;

    id1118out_output = id1118in_input;
  }
  { // Node ID: 3505 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3505in_input = id1118out_output;

    id3505out_output[(getCycle()+1)%2] = id3505in_input;
  }
  { // Node ID: 3423 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2543out_result;

  { // Node ID: 2543 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2543in_a = id3423out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2543in_b = id3457out_output[getCycle()%2];

    id2543out_result = (eq_fixed(id2543in_a,id2543in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1105out_o;

  { // Node ID: 1105 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1105in_i = id2543out_result;

    id1105out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1105in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1107out_result;

  { // Node ID: 1107 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1107in_a = id3507out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1107in_b = id1105out_o;

    id1107out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1107in_a,id1107in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1108out_result;

  { // Node ID: 1108 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1108in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1108in_option0 = id1107out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1108in_option1 = id1105out_o;

    HWOffsetFix<32,0,UNSIGNED> id1108x_1;

    switch((id1108in_sel.getValueAsLong())) {
      case 0l:
        id1108x_1 = id1108in_option0;
        break;
      case 1l:
        id1108x_1 = id1108in_option1;
        break;
      default:
        id1108x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1108out_result = (id1108x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1106out_output;

  { // Node ID: 1106 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1106in_input = id1108out_result;

    id1106out_output = id1106in_input;
  }
  { // Node ID: 3507 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3507in_input = id1106out_output;

    id3507out_output[(getCycle()+1)%2] = id3507in_input;
  }
  { // Node ID: 3422 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2544out_result;

  { // Node ID: 2544 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2544in_a = id3422out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2544in_b = id3457out_output[getCycle()%2];

    id2544out_result = (eq_fixed(id2544in_a,id2544in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1093out_o;

  { // Node ID: 1093 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1093in_i = id2544out_result;

    id1093out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1093in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1095out_result;

  { // Node ID: 1095 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1095in_a = id3509out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1095in_b = id1093out_o;

    id1095out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1095in_a,id1095in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1096out_result;

  { // Node ID: 1096 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1096in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1096in_option0 = id1095out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1096in_option1 = id1093out_o;

    HWOffsetFix<32,0,UNSIGNED> id1096x_1;

    switch((id1096in_sel.getValueAsLong())) {
      case 0l:
        id1096x_1 = id1096in_option0;
        break;
      case 1l:
        id1096x_1 = id1096in_option1;
        break;
      default:
        id1096x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1096out_result = (id1096x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1094out_output;

  { // Node ID: 1094 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1094in_input = id1096out_result;

    id1094out_output = id1094in_input;
  }
  { // Node ID: 3509 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3509in_input = id1094out_output;

    id3509out_output[(getCycle()+1)%2] = id3509in_input;
  }
  { // Node ID: 3421 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2545out_result;

  { // Node ID: 2545 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2545in_a = id3421out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2545in_b = id3457out_output[getCycle()%2];

    id2545out_result = (eq_fixed(id2545in_a,id2545in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1081out_o;

  { // Node ID: 1081 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1081in_i = id2545out_result;

    id1081out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1081in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1083out_result;

  { // Node ID: 1083 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1083in_a = id3511out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1083in_b = id1081out_o;

    id1083out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1083in_a,id1083in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1084out_result;

  { // Node ID: 1084 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1084in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1084in_option0 = id1083out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1084in_option1 = id1081out_o;

    HWOffsetFix<32,0,UNSIGNED> id1084x_1;

    switch((id1084in_sel.getValueAsLong())) {
      case 0l:
        id1084x_1 = id1084in_option0;
        break;
      case 1l:
        id1084x_1 = id1084in_option1;
        break;
      default:
        id1084x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1084out_result = (id1084x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1082out_output;

  { // Node ID: 1082 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1082in_input = id1084out_result;

    id1082out_output = id1082in_input;
  }
  { // Node ID: 3511 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3511in_input = id1082out_output;

    id3511out_output[(getCycle()+1)%2] = id3511in_input;
  }
  { // Node ID: 3420 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2546out_result;

  { // Node ID: 2546 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2546in_a = id3420out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2546in_b = id3457out_output[getCycle()%2];

    id2546out_result = (eq_fixed(id2546in_a,id2546in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1069out_o;

  { // Node ID: 1069 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1069in_i = id2546out_result;

    id1069out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1069in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1071out_result;

  { // Node ID: 1071 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1071in_a = id3513out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1071in_b = id1069out_o;

    id1071out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1071in_a,id1071in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1072out_result;

  { // Node ID: 1072 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1072in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1072in_option0 = id1071out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1072in_option1 = id1069out_o;

    HWOffsetFix<32,0,UNSIGNED> id1072x_1;

    switch((id1072in_sel.getValueAsLong())) {
      case 0l:
        id1072x_1 = id1072in_option0;
        break;
      case 1l:
        id1072x_1 = id1072in_option1;
        break;
      default:
        id1072x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1072out_result = (id1072x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1070out_output;

  { // Node ID: 1070 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1070in_input = id1072out_result;

    id1070out_output = id1070in_input;
  }
  { // Node ID: 3513 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3513in_input = id1070out_output;

    id3513out_output[(getCycle()+1)%2] = id3513in_input;
  }
  { // Node ID: 3419 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2547out_result;

  { // Node ID: 2547 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2547in_a = id3419out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2547in_b = id3457out_output[getCycle()%2];

    id2547out_result = (eq_fixed(id2547in_a,id2547in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1057out_o;

  { // Node ID: 1057 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1057in_i = id2547out_result;

    id1057out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1057in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1059out_result;

  { // Node ID: 1059 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1059in_a = id3515out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1059in_b = id1057out_o;

    id1059out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1059in_a,id1059in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1060out_result;

  { // Node ID: 1060 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1060in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1060in_option0 = id1059out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1060in_option1 = id1057out_o;

    HWOffsetFix<32,0,UNSIGNED> id1060x_1;

    switch((id1060in_sel.getValueAsLong())) {
      case 0l:
        id1060x_1 = id1060in_option0;
        break;
      case 1l:
        id1060x_1 = id1060in_option1;
        break;
      default:
        id1060x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1060out_result = (id1060x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1058out_output;

  { // Node ID: 1058 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1058in_input = id1060out_result;

    id1058out_output = id1058in_input;
  }
  { // Node ID: 3515 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3515in_input = id1058out_output;

    id3515out_output[(getCycle()+1)%2] = id3515in_input;
  }
  { // Node ID: 3418 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2548out_result;

  { // Node ID: 2548 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2548in_a = id3418out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2548in_b = id3457out_output[getCycle()%2];

    id2548out_result = (eq_fixed(id2548in_a,id2548in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1045out_o;

  { // Node ID: 1045 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1045in_i = id2548out_result;

    id1045out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1045in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1047out_result;

  { // Node ID: 1047 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1047in_a = id3517out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1047in_b = id1045out_o;

    id1047out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1047in_a,id1047in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1048out_result;

  { // Node ID: 1048 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1048in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1048in_option0 = id1047out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1048in_option1 = id1045out_o;

    HWOffsetFix<32,0,UNSIGNED> id1048x_1;

    switch((id1048in_sel.getValueAsLong())) {
      case 0l:
        id1048x_1 = id1048in_option0;
        break;
      case 1l:
        id1048x_1 = id1048in_option1;
        break;
      default:
        id1048x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1048out_result = (id1048x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1046out_output;

  { // Node ID: 1046 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1046in_input = id1048out_result;

    id1046out_output = id1046in_input;
  }
  { // Node ID: 3517 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3517in_input = id1046out_output;

    id3517out_output[(getCycle()+1)%2] = id3517in_input;
  }
  { // Node ID: 3417 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2549out_result;

  { // Node ID: 2549 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2549in_a = id3417out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2549in_b = id3457out_output[getCycle()%2];

    id2549out_result = (eq_fixed(id2549in_a,id2549in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1033out_o;

  { // Node ID: 1033 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1033in_i = id2549out_result;

    id1033out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1033in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1035out_result;

  { // Node ID: 1035 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1035in_a = id3519out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1035in_b = id1033out_o;

    id1035out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1035in_a,id1035in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1036out_result;

  { // Node ID: 1036 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1036in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1036in_option0 = id1035out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1036in_option1 = id1033out_o;

    HWOffsetFix<32,0,UNSIGNED> id1036x_1;

    switch((id1036in_sel.getValueAsLong())) {
      case 0l:
        id1036x_1 = id1036in_option0;
        break;
      case 1l:
        id1036x_1 = id1036in_option1;
        break;
      default:
        id1036x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1036out_result = (id1036x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1034out_output;

  { // Node ID: 1034 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1034in_input = id1036out_result;

    id1034out_output = id1034in_input;
  }
  { // Node ID: 3519 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3519in_input = id1034out_output;

    id3519out_output[(getCycle()+1)%2] = id3519in_input;
  }
  { // Node ID: 3416 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2550out_result;

  { // Node ID: 2550 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2550in_a = id3416out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2550in_b = id3457out_output[getCycle()%2];

    id2550out_result = (eq_fixed(id2550in_a,id2550in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1021out_o;

  { // Node ID: 1021 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1021in_i = id2550out_result;

    id1021out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1021in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1023out_result;

  { // Node ID: 1023 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1023in_a = id3521out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1023in_b = id1021out_o;

    id1023out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1023in_a,id1023in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1024out_result;

  { // Node ID: 1024 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1024in_sel = id4482out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1024in_option0 = id1023out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1024in_option1 = id1021out_o;

    HWOffsetFix<32,0,UNSIGNED> id1024x_1;

    switch((id1024in_sel.getValueAsLong())) {
      case 0l:
        id1024x_1 = id1024in_option0;
        break;
      case 1l:
        id1024x_1 = id1024in_option1;
        break;
      default:
        id1024x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1024out_result = (id1024x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1022out_output;

  { // Node ID: 1022 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1022in_input = id1024out_result;

    id1022out_output = id1022in_input;
  }
  { // Node ID: 3521 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3521in_input = id1022out_output;

    id3521out_output[(getCycle()+1)%2] = id3521in_input;
  }
  { // Node ID: 3452 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3452in_input = id3453out_output[getCycle()%2];

    id3452out_output[(getCycle()+1)%2] = id3452in_input;
  }
  { // Node ID: 3542 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3542in_input = id3452out_output[getCycle()%2];

    id3542out_output[(getCycle()+4)%5] = id3542in_input;
  }
  { // Node ID: 4483 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4483in_input = id3542out_output[getCycle()%5];

    id4483out_output[(getCycle()+1)%2] = id4483in_input;
  }
  { // Node ID: 3415 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2551out_result;

  { // Node ID: 2551 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2551in_a = id3415out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2551in_b = id3457out_output[getCycle()%2];

    id2551out_result = (eq_fixed(id2551in_a,id2551in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1009out_o;

  { // Node ID: 1009 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1009in_i = id2551out_result;

    id1009out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1009in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1011out_result;

  { // Node ID: 1011 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1011in_a = id3523out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1011in_b = id1009out_o;

    id1011out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1011in_a,id1011in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1012out_result;

  { // Node ID: 1012 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1012in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1012in_option0 = id1011out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1012in_option1 = id1009out_o;

    HWOffsetFix<32,0,UNSIGNED> id1012x_1;

    switch((id1012in_sel.getValueAsLong())) {
      case 0l:
        id1012x_1 = id1012in_option0;
        break;
      case 1l:
        id1012x_1 = id1012in_option1;
        break;
      default:
        id1012x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1012out_result = (id1012x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1010out_output;

  { // Node ID: 1010 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1010in_input = id1012out_result;

    id1010out_output = id1010in_input;
  }
  { // Node ID: 3523 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3523in_input = id1010out_output;

    id3523out_output[(getCycle()+1)%2] = id3523in_input;
  }
  { // Node ID: 3414 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2552out_result;

  { // Node ID: 2552 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2552in_a = id3414out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2552in_b = id3457out_output[getCycle()%2];

    id2552out_result = (eq_fixed(id2552in_a,id2552in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id997out_o;

  { // Node ID: 997 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id997in_i = id2552out_result;

    id997out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id997in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id999out_result;

  { // Node ID: 999 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id999in_a = id3525out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id999in_b = id997out_o;

    id999out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id999in_a,id999in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1000out_result;

  { // Node ID: 1000 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1000in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1000in_option0 = id999out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1000in_option1 = id997out_o;

    HWOffsetFix<32,0,UNSIGNED> id1000x_1;

    switch((id1000in_sel.getValueAsLong())) {
      case 0l:
        id1000x_1 = id1000in_option0;
        break;
      case 1l:
        id1000x_1 = id1000in_option1;
        break;
      default:
        id1000x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1000out_result = (id1000x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id998out_output;

  { // Node ID: 998 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id998in_input = id1000out_result;

    id998out_output = id998in_input;
  }
  { // Node ID: 3525 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3525in_input = id998out_output;

    id3525out_output[(getCycle()+1)%2] = id3525in_input;
  }
  { // Node ID: 3413 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2553out_result;

  { // Node ID: 2553 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2553in_a = id3413out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2553in_b = id3457out_output[getCycle()%2];

    id2553out_result = (eq_fixed(id2553in_a,id2553in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id985out_o;

  { // Node ID: 985 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id985in_i = id2553out_result;

    id985out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id985in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id987out_result;

  { // Node ID: 987 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id987in_a = id3527out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id987in_b = id985out_o;

    id987out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id987in_a,id987in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id988out_result;

  { // Node ID: 988 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id988in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id988in_option0 = id987out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id988in_option1 = id985out_o;

    HWOffsetFix<32,0,UNSIGNED> id988x_1;

    switch((id988in_sel.getValueAsLong())) {
      case 0l:
        id988x_1 = id988in_option0;
        break;
      case 1l:
        id988x_1 = id988in_option1;
        break;
      default:
        id988x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id988out_result = (id988x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id986out_output;

  { // Node ID: 986 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id986in_input = id988out_result;

    id986out_output = id986in_input;
  }
  { // Node ID: 3527 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3527in_input = id986out_output;

    id3527out_output[(getCycle()+1)%2] = id3527in_input;
  }
  { // Node ID: 3412 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2554out_result;

  { // Node ID: 2554 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2554in_a = id3412out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2554in_b = id3457out_output[getCycle()%2];

    id2554out_result = (eq_fixed(id2554in_a,id2554in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id973out_o;

  { // Node ID: 973 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id973in_i = id2554out_result;

    id973out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id973in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id975out_result;

  { // Node ID: 975 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id975in_a = id3529out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id975in_b = id973out_o;

    id975out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id975in_a,id975in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id976out_result;

  { // Node ID: 976 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id976in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id976in_option0 = id975out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id976in_option1 = id973out_o;

    HWOffsetFix<32,0,UNSIGNED> id976x_1;

    switch((id976in_sel.getValueAsLong())) {
      case 0l:
        id976x_1 = id976in_option0;
        break;
      case 1l:
        id976x_1 = id976in_option1;
        break;
      default:
        id976x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id976out_result = (id976x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id974out_output;

  { // Node ID: 974 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id974in_input = id976out_result;

    id974out_output = id974in_input;
  }
  { // Node ID: 3529 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3529in_input = id974out_output;

    id3529out_output[(getCycle()+1)%2] = id3529in_input;
  }
  { // Node ID: 3411 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2555out_result;

  { // Node ID: 2555 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2555in_a = id3411out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2555in_b = id3457out_output[getCycle()%2];

    id2555out_result = (eq_fixed(id2555in_a,id2555in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id961out_o;

  { // Node ID: 961 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id961in_i = id2555out_result;

    id961out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id961in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id963out_result;

  { // Node ID: 963 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id963in_a = id3531out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id963in_b = id961out_o;

    id963out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id963in_a,id963in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id964out_result;

  { // Node ID: 964 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id964in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id964in_option0 = id963out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id964in_option1 = id961out_o;

    HWOffsetFix<32,0,UNSIGNED> id964x_1;

    switch((id964in_sel.getValueAsLong())) {
      case 0l:
        id964x_1 = id964in_option0;
        break;
      case 1l:
        id964x_1 = id964in_option1;
        break;
      default:
        id964x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id964out_result = (id964x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id962out_output;

  { // Node ID: 962 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id962in_input = id964out_result;

    id962out_output = id962in_input;
  }
  { // Node ID: 3531 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3531in_input = id962out_output;

    id3531out_output[(getCycle()+1)%2] = id3531in_input;
  }
  { // Node ID: 3410 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2556out_result;

  { // Node ID: 2556 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2556in_a = id3410out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2556in_b = id3457out_output[getCycle()%2];

    id2556out_result = (eq_fixed(id2556in_a,id2556in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id949out_o;

  { // Node ID: 949 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id949in_i = id2556out_result;

    id949out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id949in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id951out_result;

  { // Node ID: 951 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id951in_a = id3533out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id951in_b = id949out_o;

    id951out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id951in_a,id951in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id952out_result;

  { // Node ID: 952 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id952in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id952in_option0 = id951out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id952in_option1 = id949out_o;

    HWOffsetFix<32,0,UNSIGNED> id952x_1;

    switch((id952in_sel.getValueAsLong())) {
      case 0l:
        id952x_1 = id952in_option0;
        break;
      case 1l:
        id952x_1 = id952in_option1;
        break;
      default:
        id952x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id952out_result = (id952x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id950out_output;

  { // Node ID: 950 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id950in_input = id952out_result;

    id950out_output = id950in_input;
  }
  { // Node ID: 3533 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3533in_input = id950out_output;

    id3533out_output[(getCycle()+1)%2] = id3533in_input;
  }
  { // Node ID: 3409 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2557out_result;

  { // Node ID: 2557 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2557in_a = id3409out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2557in_b = id3457out_output[getCycle()%2];

    id2557out_result = (eq_fixed(id2557in_a,id2557in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id937out_o;

  { // Node ID: 937 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id937in_i = id2557out_result;

    id937out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id937in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id939out_result;

  { // Node ID: 939 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id939in_a = id3535out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id939in_b = id937out_o;

    id939out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id939in_a,id939in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id940out_result;

  { // Node ID: 940 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id940in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id940in_option0 = id939out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id940in_option1 = id937out_o;

    HWOffsetFix<32,0,UNSIGNED> id940x_1;

    switch((id940in_sel.getValueAsLong())) {
      case 0l:
        id940x_1 = id940in_option0;
        break;
      case 1l:
        id940x_1 = id940in_option1;
        break;
      default:
        id940x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id940out_result = (id940x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id938out_output;

  { // Node ID: 938 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id938in_input = id940out_result;

    id938out_output = id938in_input;
  }
  { // Node ID: 3535 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3535in_input = id938out_output;

    id3535out_output[(getCycle()+1)%2] = id3535in_input;
  }
  { // Node ID: 3408 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2558out_result;

  { // Node ID: 2558 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2558in_a = id3408out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2558in_b = id3457out_output[getCycle()%2];

    id2558out_result = (eq_fixed(id2558in_a,id2558in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id925out_o;

  { // Node ID: 925 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id925in_i = id2558out_result;

    id925out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id925in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id927out_result;

  { // Node ID: 927 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id927in_a = id3537out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id927in_b = id925out_o;

    id927out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id927in_a,id927in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id928out_result;

  { // Node ID: 928 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id928in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id928in_option0 = id927out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id928in_option1 = id925out_o;

    HWOffsetFix<32,0,UNSIGNED> id928x_1;

    switch((id928in_sel.getValueAsLong())) {
      case 0l:
        id928x_1 = id928in_option0;
        break;
      case 1l:
        id928x_1 = id928in_option1;
        break;
      default:
        id928x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id928out_result = (id928x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id926out_output;

  { // Node ID: 926 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id926in_input = id928out_result;

    id926out_output = id926in_input;
  }
  { // Node ID: 3537 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3537in_input = id926out_output;

    id3537out_output[(getCycle()+1)%2] = id3537in_input;
  }
  { // Node ID: 3407 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2559out_result;

  { // Node ID: 2559 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2559in_a = id3407out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2559in_b = id3457out_output[getCycle()%2];

    id2559out_result = (eq_fixed(id2559in_a,id2559in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id913out_o;

  { // Node ID: 913 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id913in_i = id2559out_result;

    id913out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id913in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id915out_result;

  { // Node ID: 915 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id915in_a = id3539out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id915in_b = id913out_o;

    id915out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id915in_a,id915in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id916out_result;

  { // Node ID: 916 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id916in_sel = id4483out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id916in_option0 = id915out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id916in_option1 = id913out_o;

    HWOffsetFix<32,0,UNSIGNED> id916x_1;

    switch((id916in_sel.getValueAsLong())) {
      case 0l:
        id916x_1 = id916in_option0;
        break;
      case 1l:
        id916x_1 = id916in_option1;
        break;
      default:
        id916x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id916out_result = (id916x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id914out_output;

  { // Node ID: 914 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id914in_input = id916out_result;

    id914out_output = id914in_input;
  }
  { // Node ID: 3539 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3539in_input = id914out_output;

    id3539out_output[(getCycle()+1)%2] = id3539in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id902out_output;

  { // Node ID: 902 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id902in_input = id3541out_output[getCycle()%2];

    id902out_output = id902in_input;
  }
  { // Node ID: 3406 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2560out_result;

  { // Node ID: 2560 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2560in_a = id3406out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2560in_b = id3458out_output[getCycle()%2];

    id2560out_result = (eq_fixed(id2560in_a,id2560in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id901out_o;

  { // Node ID: 901 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id901in_i = id2560out_result;

    id901out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id901in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id903out_result;

  { // Node ID: 903 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id903in_a = id902out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id903in_b = id901out_o;

    id903out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id903in_a,id903in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id904out_result;

  { // Node ID: 904 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id904in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id904in_option0 = id903out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id904in_option1 = id901out_o;

    HWOffsetFix<32,0,UNSIGNED> id904x_1;

    switch((id904in_sel.getValueAsLong())) {
      case 0l:
        id904x_1 = id904in_option0;
        break;
      case 1l:
        id904x_1 = id904in_option1;
        break;
      default:
        id904x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id904out_result = (id904x_1);
  }
  { // Node ID: 3541 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3541in_input = id904out_result;

    id3541out_output[(getCycle()+1)%2] = id3541in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id890out_output;

  { // Node ID: 890 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id890in_input = id3543out_output[getCycle()%2];

    id890out_output = id890in_input;
  }
  { // Node ID: 3405 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2561out_result;

  { // Node ID: 2561 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2561in_a = id3405out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2561in_b = id3458out_output[getCycle()%2];

    id2561out_result = (eq_fixed(id2561in_a,id2561in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id889out_o;

  { // Node ID: 889 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id889in_i = id2561out_result;

    id889out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id889in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id891out_result;

  { // Node ID: 891 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id891in_a = id890out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id891in_b = id889out_o;

    id891out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id891in_a,id891in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id892out_result;

  { // Node ID: 892 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id892in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id892in_option0 = id891out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id892in_option1 = id889out_o;

    HWOffsetFix<32,0,UNSIGNED> id892x_1;

    switch((id892in_sel.getValueAsLong())) {
      case 0l:
        id892x_1 = id892in_option0;
        break;
      case 1l:
        id892x_1 = id892in_option1;
        break;
      default:
        id892x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id892out_result = (id892x_1);
  }
  { // Node ID: 3543 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3543in_input = id892out_result;

    id3543out_output[(getCycle()+1)%2] = id3543in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id878out_output;

  { // Node ID: 878 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id878in_input = id3545out_output[getCycle()%2];

    id878out_output = id878in_input;
  }
  { // Node ID: 3404 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2562out_result;

  { // Node ID: 2562 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2562in_a = id3404out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2562in_b = id3458out_output[getCycle()%2];

    id2562out_result = (eq_fixed(id2562in_a,id2562in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id877out_o;

  { // Node ID: 877 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id877in_i = id2562out_result;

    id877out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id877in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id879out_result;

  { // Node ID: 879 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id879in_a = id878out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id879in_b = id877out_o;

    id879out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id879in_a,id879in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id880out_result;

  { // Node ID: 880 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id880in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id880in_option0 = id879out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id880in_option1 = id877out_o;

    HWOffsetFix<32,0,UNSIGNED> id880x_1;

    switch((id880in_sel.getValueAsLong())) {
      case 0l:
        id880x_1 = id880in_option0;
        break;
      case 1l:
        id880x_1 = id880in_option1;
        break;
      default:
        id880x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id880out_result = (id880x_1);
  }
  { // Node ID: 3545 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3545in_input = id880out_result;

    id3545out_output[(getCycle()+1)%2] = id3545in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id866out_output;

  { // Node ID: 866 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id866in_input = id3547out_output[getCycle()%2];

    id866out_output = id866in_input;
  }
  { // Node ID: 3403 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2563out_result;

  { // Node ID: 2563 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2563in_a = id3403out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2563in_b = id3458out_output[getCycle()%2];

    id2563out_result = (eq_fixed(id2563in_a,id2563in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id865out_o;

  { // Node ID: 865 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id865in_i = id2563out_result;

    id865out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id865in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id867out_result;

  { // Node ID: 867 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id867in_a = id866out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id867in_b = id865out_o;

    id867out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id867in_a,id867in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id868out_result;

  { // Node ID: 868 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id868in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id868in_option0 = id867out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id868in_option1 = id865out_o;

    HWOffsetFix<32,0,UNSIGNED> id868x_1;

    switch((id868in_sel.getValueAsLong())) {
      case 0l:
        id868x_1 = id868in_option0;
        break;
      case 1l:
        id868x_1 = id868in_option1;
        break;
      default:
        id868x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id868out_result = (id868x_1);
  }
  { // Node ID: 3547 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3547in_input = id868out_result;

    id3547out_output[(getCycle()+1)%2] = id3547in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id854out_output;

  { // Node ID: 854 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id854in_input = id3549out_output[getCycle()%2];

    id854out_output = id854in_input;
  }
  { // Node ID: 3402 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2564out_result;

  { // Node ID: 2564 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2564in_a = id3402out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2564in_b = id3458out_output[getCycle()%2];

    id2564out_result = (eq_fixed(id2564in_a,id2564in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id853out_o;

  { // Node ID: 853 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id853in_i = id2564out_result;

    id853out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id853in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id855out_result;

  { // Node ID: 855 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id855in_a = id854out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id855in_b = id853out_o;

    id855out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id855in_a,id855in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id856out_result;

  { // Node ID: 856 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id856in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id856in_option0 = id855out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id856in_option1 = id853out_o;

    HWOffsetFix<32,0,UNSIGNED> id856x_1;

    switch((id856in_sel.getValueAsLong())) {
      case 0l:
        id856x_1 = id856in_option0;
        break;
      case 1l:
        id856x_1 = id856in_option1;
        break;
      default:
        id856x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id856out_result = (id856x_1);
  }
  { // Node ID: 3549 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3549in_input = id856out_result;

    id3549out_output[(getCycle()+1)%2] = id3549in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id842out_output;

  { // Node ID: 842 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id842in_input = id3551out_output[getCycle()%2];

    id842out_output = id842in_input;
  }
  { // Node ID: 3401 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2565out_result;

  { // Node ID: 2565 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2565in_a = id3401out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2565in_b = id3458out_output[getCycle()%2];

    id2565out_result = (eq_fixed(id2565in_a,id2565in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id841out_o;

  { // Node ID: 841 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id841in_i = id2565out_result;

    id841out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id841in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id843out_result;

  { // Node ID: 843 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id843in_a = id842out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id843in_b = id841out_o;

    id843out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id843in_a,id843in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id844out_result;

  { // Node ID: 844 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id844in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id844in_option0 = id843out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id844in_option1 = id841out_o;

    HWOffsetFix<32,0,UNSIGNED> id844x_1;

    switch((id844in_sel.getValueAsLong())) {
      case 0l:
        id844x_1 = id844in_option0;
        break;
      case 1l:
        id844x_1 = id844in_option1;
        break;
      default:
        id844x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id844out_result = (id844x_1);
  }
  { // Node ID: 3551 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3551in_input = id844out_result;

    id3551out_output[(getCycle()+1)%2] = id3551in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id830out_output;

  { // Node ID: 830 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id830in_input = id3553out_output[getCycle()%2];

    id830out_output = id830in_input;
  }
  { // Node ID: 3400 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2566out_result;

  { // Node ID: 2566 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2566in_a = id3400out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2566in_b = id3458out_output[getCycle()%2];

    id2566out_result = (eq_fixed(id2566in_a,id2566in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id829out_o;

  { // Node ID: 829 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id829in_i = id2566out_result;

    id829out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id829in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id831out_result;

  { // Node ID: 831 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id831in_a = id830out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id831in_b = id829out_o;

    id831out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id831in_a,id831in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id832out_result;

  { // Node ID: 832 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id832in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id832in_option0 = id831out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id832in_option1 = id829out_o;

    HWOffsetFix<32,0,UNSIGNED> id832x_1;

    switch((id832in_sel.getValueAsLong())) {
      case 0l:
        id832x_1 = id832in_option0;
        break;
      case 1l:
        id832x_1 = id832in_option1;
        break;
      default:
        id832x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id832out_result = (id832x_1);
  }
  { // Node ID: 3553 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3553in_input = id832out_result;

    id3553out_output[(getCycle()+1)%2] = id3553in_input;
  }
  { // Node ID: 3451 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3451in_input = id3452out_output[getCycle()%2];

    id3451out_output[(getCycle()+1)%2] = id3451in_input;
  }
  { // Node ID: 3556 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3556in_input = id3451out_output[getCycle()%2];

    id3556out_output[(getCycle()+3)%4] = id3556in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id818out_output;

  { // Node ID: 818 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id818in_input = id3555out_output[getCycle()%2];

    id818out_output = id818in_input;
  }
  { // Node ID: 3399 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2567out_result;

  { // Node ID: 2567 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2567in_a = id3399out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2567in_b = id3458out_output[getCycle()%2];

    id2567out_result = (eq_fixed(id2567in_a,id2567in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id817out_o;

  { // Node ID: 817 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id817in_i = id2567out_result;

    id817out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id817in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id819out_result;

  { // Node ID: 819 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id819in_a = id818out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id819in_b = id817out_o;

    id819out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id819in_a,id819in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id820out_result;

  { // Node ID: 820 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id820in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id820in_option0 = id819out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id820in_option1 = id817out_o;

    HWOffsetFix<32,0,UNSIGNED> id820x_1;

    switch((id820in_sel.getValueAsLong())) {
      case 0l:
        id820x_1 = id820in_option0;
        break;
      case 1l:
        id820x_1 = id820in_option1;
        break;
      default:
        id820x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id820out_result = (id820x_1);
  }
  { // Node ID: 3555 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3555in_input = id820out_result;

    id3555out_output[(getCycle()+1)%2] = id3555in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id806out_output;

  { // Node ID: 806 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id806in_input = id3557out_output[getCycle()%2];

    id806out_output = id806in_input;
  }
  { // Node ID: 3398 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2568out_result;

  { // Node ID: 2568 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2568in_a = id3398out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2568in_b = id3458out_output[getCycle()%2];

    id2568out_result = (eq_fixed(id2568in_a,id2568in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id805out_o;

  { // Node ID: 805 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id805in_i = id2568out_result;

    id805out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id805in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id807out_result;

  { // Node ID: 807 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id807in_a = id806out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id807in_b = id805out_o;

    id807out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id807in_a,id807in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id808out_result;

  { // Node ID: 808 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id808in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id808in_option0 = id807out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id808in_option1 = id805out_o;

    HWOffsetFix<32,0,UNSIGNED> id808x_1;

    switch((id808in_sel.getValueAsLong())) {
      case 0l:
        id808x_1 = id808in_option0;
        break;
      case 1l:
        id808x_1 = id808in_option1;
        break;
      default:
        id808x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id808out_result = (id808x_1);
  }
  { // Node ID: 3557 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3557in_input = id808out_result;

    id3557out_output[(getCycle()+1)%2] = id3557in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id794out_output;

  { // Node ID: 794 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id794in_input = id3559out_output[getCycle()%2];

    id794out_output = id794in_input;
  }
  { // Node ID: 3397 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2569out_result;

  { // Node ID: 2569 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2569in_a = id3397out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2569in_b = id3458out_output[getCycle()%2];

    id2569out_result = (eq_fixed(id2569in_a,id2569in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id793out_o;

  { // Node ID: 793 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id793in_i = id2569out_result;

    id793out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id793in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id795out_result;

  { // Node ID: 795 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id795in_a = id794out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id795in_b = id793out_o;

    id795out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id795in_a,id795in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id796out_result;

  { // Node ID: 796 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id796in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id796in_option0 = id795out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id796in_option1 = id793out_o;

    HWOffsetFix<32,0,UNSIGNED> id796x_1;

    switch((id796in_sel.getValueAsLong())) {
      case 0l:
        id796x_1 = id796in_option0;
        break;
      case 1l:
        id796x_1 = id796in_option1;
        break;
      default:
        id796x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id796out_result = (id796x_1);
  }
  { // Node ID: 3559 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3559in_input = id796out_result;

    id3559out_output[(getCycle()+1)%2] = id3559in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id782out_output;

  { // Node ID: 782 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id782in_input = id3561out_output[getCycle()%2];

    id782out_output = id782in_input;
  }
  { // Node ID: 3396 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2570out_result;

  { // Node ID: 2570 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2570in_a = id3396out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2570in_b = id3458out_output[getCycle()%2];

    id2570out_result = (eq_fixed(id2570in_a,id2570in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id781out_o;

  { // Node ID: 781 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id781in_i = id2570out_result;

    id781out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id781in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id783out_result;

  { // Node ID: 783 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id783in_a = id782out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id783in_b = id781out_o;

    id783out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id783in_a,id783in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id784out_result;

  { // Node ID: 784 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id784in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id784in_option0 = id783out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id784in_option1 = id781out_o;

    HWOffsetFix<32,0,UNSIGNED> id784x_1;

    switch((id784in_sel.getValueAsLong())) {
      case 0l:
        id784x_1 = id784in_option0;
        break;
      case 1l:
        id784x_1 = id784in_option1;
        break;
      default:
        id784x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id784out_result = (id784x_1);
  }
  { // Node ID: 3561 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3561in_input = id784out_result;

    id3561out_output[(getCycle()+1)%2] = id3561in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id770out_output;

  { // Node ID: 770 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id770in_input = id3563out_output[getCycle()%2];

    id770out_output = id770in_input;
  }
  { // Node ID: 3395 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2571out_result;

  { // Node ID: 2571 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2571in_a = id3395out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2571in_b = id3458out_output[getCycle()%2];

    id2571out_result = (eq_fixed(id2571in_a,id2571in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id769out_o;

  { // Node ID: 769 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id769in_i = id2571out_result;

    id769out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id769in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id771out_result;

  { // Node ID: 771 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id771in_a = id770out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id771in_b = id769out_o;

    id771out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id771in_a,id771in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id772out_result;

  { // Node ID: 772 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id772in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id772in_option0 = id771out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id772in_option1 = id769out_o;

    HWOffsetFix<32,0,UNSIGNED> id772x_1;

    switch((id772in_sel.getValueAsLong())) {
      case 0l:
        id772x_1 = id772in_option0;
        break;
      case 1l:
        id772x_1 = id772in_option1;
        break;
      default:
        id772x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id772out_result = (id772x_1);
  }
  { // Node ID: 3563 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3563in_input = id772out_result;

    id3563out_output[(getCycle()+1)%2] = id3563in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id758out_output;

  { // Node ID: 758 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id758in_input = id3565out_output[getCycle()%2];

    id758out_output = id758in_input;
  }
  { // Node ID: 3394 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2572out_result;

  { // Node ID: 2572 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2572in_a = id3394out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2572in_b = id3458out_output[getCycle()%2];

    id2572out_result = (eq_fixed(id2572in_a,id2572in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id757out_o;

  { // Node ID: 757 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id757in_i = id2572out_result;

    id757out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id757in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id759out_result;

  { // Node ID: 759 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id759in_a = id758out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id759in_b = id757out_o;

    id759out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id759in_a,id759in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id760out_result;

  { // Node ID: 760 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id760in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id760in_option0 = id759out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id760in_option1 = id757out_o;

    HWOffsetFix<32,0,UNSIGNED> id760x_1;

    switch((id760in_sel.getValueAsLong())) {
      case 0l:
        id760x_1 = id760in_option0;
        break;
      case 1l:
        id760x_1 = id760in_option1;
        break;
      default:
        id760x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id760out_result = (id760x_1);
  }
  { // Node ID: 3565 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3565in_input = id760out_result;

    id3565out_output[(getCycle()+1)%2] = id3565in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id746out_output;

  { // Node ID: 746 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id746in_input = id3567out_output[getCycle()%2];

    id746out_output = id746in_input;
  }
  { // Node ID: 3393 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2573out_result;

  { // Node ID: 2573 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2573in_a = id3393out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2573in_b = id3458out_output[getCycle()%2];

    id2573out_result = (eq_fixed(id2573in_a,id2573in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id745out_o;

  { // Node ID: 745 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id745in_i = id2573out_result;

    id745out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id745in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id747out_result;

  { // Node ID: 747 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id747in_a = id746out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id747in_b = id745out_o;

    id747out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id747in_a,id747in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id748out_result;

  { // Node ID: 748 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id748in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id748in_option0 = id747out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id748in_option1 = id745out_o;

    HWOffsetFix<32,0,UNSIGNED> id748x_1;

    switch((id748in_sel.getValueAsLong())) {
      case 0l:
        id748x_1 = id748in_option0;
        break;
      case 1l:
        id748x_1 = id748in_option1;
        break;
      default:
        id748x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id748out_result = (id748x_1);
  }
  { // Node ID: 3567 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3567in_input = id748out_result;

    id3567out_output[(getCycle()+1)%2] = id3567in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id734out_output;

  { // Node ID: 734 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id734in_input = id3569out_output[getCycle()%2];

    id734out_output = id734in_input;
  }
  { // Node ID: 3392 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2574out_result;

  { // Node ID: 2574 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2574in_a = id3392out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2574in_b = id3458out_output[getCycle()%2];

    id2574out_result = (eq_fixed(id2574in_a,id2574in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id733out_o;

  { // Node ID: 733 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id733in_i = id2574out_result;

    id733out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id733in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id735out_result;

  { // Node ID: 735 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id735in_a = id734out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id735in_b = id733out_o;

    id735out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id735in_a,id735in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id736out_result;

  { // Node ID: 736 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id736in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id736in_option0 = id735out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id736in_option1 = id733out_o;

    HWOffsetFix<32,0,UNSIGNED> id736x_1;

    switch((id736in_sel.getValueAsLong())) {
      case 0l:
        id736x_1 = id736in_option0;
        break;
      case 1l:
        id736x_1 = id736in_option1;
        break;
      default:
        id736x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id736out_result = (id736x_1);
  }
  { // Node ID: 3569 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3569in_input = id736out_result;

    id3569out_output[(getCycle()+1)%2] = id3569in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id722out_output;

  { // Node ID: 722 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id722in_input = id3571out_output[getCycle()%2];

    id722out_output = id722in_input;
  }
  { // Node ID: 3391 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2575out_result;

  { // Node ID: 2575 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2575in_a = id3391out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2575in_b = id3458out_output[getCycle()%2];

    id2575out_result = (eq_fixed(id2575in_a,id2575in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id721out_o;

  { // Node ID: 721 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id721in_i = id2575out_result;

    id721out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id721in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id723out_result;

  { // Node ID: 723 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id723in_a = id722out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id723in_b = id721out_o;

    id723out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id723in_a,id723in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id724out_result;

  { // Node ID: 724 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id724in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id724in_option0 = id723out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id724in_option1 = id721out_o;

    HWOffsetFix<32,0,UNSIGNED> id724x_1;

    switch((id724in_sel.getValueAsLong())) {
      case 0l:
        id724x_1 = id724in_option0;
        break;
      case 1l:
        id724x_1 = id724in_option1;
        break;
      default:
        id724x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id724out_result = (id724x_1);
  }
  { // Node ID: 3571 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3571in_input = id724out_result;

    id3571out_output[(getCycle()+1)%2] = id3571in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id710out_output;

  { // Node ID: 710 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id710in_input = id3573out_output[getCycle()%2];

    id710out_output = id710in_input;
  }
  { // Node ID: 3390 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2576out_result;

  { // Node ID: 2576 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2576in_a = id3390out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2576in_b = id3458out_output[getCycle()%2];

    id2576out_result = (eq_fixed(id2576in_a,id2576in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id709out_o;

  { // Node ID: 709 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id709in_i = id2576out_result;

    id709out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id709in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id711out_result;

  { // Node ID: 711 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id711in_a = id710out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id711in_b = id709out_o;

    id711out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id711in_a,id711in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id712out_result;

  { // Node ID: 712 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id712in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id712in_option0 = id711out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id712in_option1 = id709out_o;

    HWOffsetFix<32,0,UNSIGNED> id712x_1;

    switch((id712in_sel.getValueAsLong())) {
      case 0l:
        id712x_1 = id712in_option0;
        break;
      case 1l:
        id712x_1 = id712in_option1;
        break;
      default:
        id712x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id712out_result = (id712x_1);
  }
  { // Node ID: 3573 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3573in_input = id712out_result;

    id3573out_output[(getCycle()+1)%2] = id3573in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id698out_output;

  { // Node ID: 698 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id698in_input = id3575out_output[getCycle()%2];

    id698out_output = id698in_input;
  }
  { // Node ID: 3389 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2577out_result;

  { // Node ID: 2577 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2577in_a = id3389out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2577in_b = id3458out_output[getCycle()%2];

    id2577out_result = (eq_fixed(id2577in_a,id2577in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id697out_o;

  { // Node ID: 697 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id697in_i = id2577out_result;

    id697out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id697in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id699out_result;

  { // Node ID: 699 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id699in_a = id698out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id699in_b = id697out_o;

    id699out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id699in_a,id699in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id700out_result;

  { // Node ID: 700 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id700in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id700in_option0 = id699out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id700in_option1 = id697out_o;

    HWOffsetFix<32,0,UNSIGNED> id700x_1;

    switch((id700in_sel.getValueAsLong())) {
      case 0l:
        id700x_1 = id700in_option0;
        break;
      case 1l:
        id700x_1 = id700in_option1;
        break;
      default:
        id700x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id700out_result = (id700x_1);
  }
  { // Node ID: 3575 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3575in_input = id700out_result;

    id3575out_output[(getCycle()+1)%2] = id3575in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id686out_output;

  { // Node ID: 686 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id686in_input = id3577out_output[getCycle()%2];

    id686out_output = id686in_input;
  }
  { // Node ID: 3388 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2578out_result;

  { // Node ID: 2578 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2578in_a = id3388out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2578in_b = id3458out_output[getCycle()%2];

    id2578out_result = (eq_fixed(id2578in_a,id2578in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id685out_o;

  { // Node ID: 685 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id685in_i = id2578out_result;

    id685out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id685in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id687out_result;

  { // Node ID: 687 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id687in_a = id686out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id687in_b = id685out_o;

    id687out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id687in_a,id687in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id688out_result;

  { // Node ID: 688 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id688in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id688in_option0 = id687out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id688in_option1 = id685out_o;

    HWOffsetFix<32,0,UNSIGNED> id688x_1;

    switch((id688in_sel.getValueAsLong())) {
      case 0l:
        id688x_1 = id688in_option0;
        break;
      case 1l:
        id688x_1 = id688in_option1;
        break;
      default:
        id688x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id688out_result = (id688x_1);
  }
  { // Node ID: 3577 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3577in_input = id688out_result;

    id3577out_output[(getCycle()+1)%2] = id3577in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id674out_output;

  { // Node ID: 674 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id674in_input = id3579out_output[getCycle()%2];

    id674out_output = id674in_input;
  }
  { // Node ID: 3387 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2579out_result;

  { // Node ID: 2579 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2579in_a = id3387out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2579in_b = id3458out_output[getCycle()%2];

    id2579out_result = (eq_fixed(id2579in_a,id2579in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id673out_o;

  { // Node ID: 673 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id673in_i = id2579out_result;

    id673out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id673in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id675out_result;

  { // Node ID: 675 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id675in_a = id674out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id675in_b = id673out_o;

    id675out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id675in_a,id675in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id676out_result;

  { // Node ID: 676 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id676in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id676in_option0 = id675out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id676in_option1 = id673out_o;

    HWOffsetFix<32,0,UNSIGNED> id676x_1;

    switch((id676in_sel.getValueAsLong())) {
      case 0l:
        id676x_1 = id676in_option0;
        break;
      case 1l:
        id676x_1 = id676in_option1;
        break;
      default:
        id676x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id676out_result = (id676x_1);
  }
  { // Node ID: 3579 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3579in_input = id676out_result;

    id3579out_output[(getCycle()+1)%2] = id3579in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id662out_output;

  { // Node ID: 662 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id662in_input = id3581out_output[getCycle()%2];

    id662out_output = id662in_input;
  }
  { // Node ID: 3386 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2580out_result;

  { // Node ID: 2580 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2580in_a = id3386out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2580in_b = id3458out_output[getCycle()%2];

    id2580out_result = (eq_fixed(id2580in_a,id2580in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id661out_o;

  { // Node ID: 661 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id661in_i = id2580out_result;

    id661out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id661in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id663out_result;

  { // Node ID: 663 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id663in_a = id662out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id663in_b = id661out_o;

    id663out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id663in_a,id663in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id664out_result;

  { // Node ID: 664 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id664in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id664in_option0 = id663out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id664in_option1 = id661out_o;

    HWOffsetFix<32,0,UNSIGNED> id664x_1;

    switch((id664in_sel.getValueAsLong())) {
      case 0l:
        id664x_1 = id664in_option0;
        break;
      case 1l:
        id664x_1 = id664in_option1;
        break;
      default:
        id664x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id664out_result = (id664x_1);
  }
  { // Node ID: 3581 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3581in_input = id664out_result;

    id3581out_output[(getCycle()+1)%2] = id3581in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id650out_output;

  { // Node ID: 650 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id650in_input = id3583out_output[getCycle()%2];

    id650out_output = id650in_input;
  }
  { // Node ID: 3385 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2581out_result;

  { // Node ID: 2581 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2581in_a = id3385out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2581in_b = id3458out_output[getCycle()%2];

    id2581out_result = (eq_fixed(id2581in_a,id2581in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id649out_o;

  { // Node ID: 649 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id649in_i = id2581out_result;

    id649out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id649in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id651out_result;

  { // Node ID: 651 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id651in_a = id650out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id651in_b = id649out_o;

    id651out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id651in_a,id651in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id652out_result;

  { // Node ID: 652 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id652in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id652in_option0 = id651out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id652in_option1 = id649out_o;

    HWOffsetFix<32,0,UNSIGNED> id652x_1;

    switch((id652in_sel.getValueAsLong())) {
      case 0l:
        id652x_1 = id652in_option0;
        break;
      case 1l:
        id652x_1 = id652in_option1;
        break;
      default:
        id652x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id652out_result = (id652x_1);
  }
  { // Node ID: 3583 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3583in_input = id652out_result;

    id3583out_output[(getCycle()+1)%2] = id3583in_input;
  }
  { // Node ID: 3450 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3450in_input = id3451out_output[getCycle()%2];

    id3450out_output[(getCycle()+1)%2] = id3450in_input;
  }
  { // Node ID: 3586 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3586in_input = id3450out_output[getCycle()%2];

    id3586out_output[(getCycle()+2)%3] = id3586in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id638out_output;

  { // Node ID: 638 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id638in_input = id3585out_output[getCycle()%2];

    id638out_output = id638in_input;
  }
  { // Node ID: 3384 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2582out_result;

  { // Node ID: 2582 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2582in_a = id3384out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2582in_b = id3458out_output[getCycle()%2];

    id2582out_result = (eq_fixed(id2582in_a,id2582in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id637out_o;

  { // Node ID: 637 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id637in_i = id2582out_result;

    id637out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id637in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id639out_result;

  { // Node ID: 639 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id639in_a = id638out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id639in_b = id637out_o;

    id639out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id639in_a,id639in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id640out_result;

  { // Node ID: 640 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id640in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id640in_option0 = id639out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id640in_option1 = id637out_o;

    HWOffsetFix<32,0,UNSIGNED> id640x_1;

    switch((id640in_sel.getValueAsLong())) {
      case 0l:
        id640x_1 = id640in_option0;
        break;
      case 1l:
        id640x_1 = id640in_option1;
        break;
      default:
        id640x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id640out_result = (id640x_1);
  }
  { // Node ID: 3585 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3585in_input = id640out_result;

    id3585out_output[(getCycle()+1)%2] = id3585in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id626out_output;

  { // Node ID: 626 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id626in_input = id3587out_output[getCycle()%2];

    id626out_output = id626in_input;
  }
  { // Node ID: 3383 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2583out_result;

  { // Node ID: 2583 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2583in_a = id3383out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2583in_b = id3458out_output[getCycle()%2];

    id2583out_result = (eq_fixed(id2583in_a,id2583in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id625out_o;

  { // Node ID: 625 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id625in_i = id2583out_result;

    id625out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id625in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id627out_result;

  { // Node ID: 627 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id627in_a = id626out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id627in_b = id625out_o;

    id627out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id627in_a,id627in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id628out_result;

  { // Node ID: 628 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id628in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id628in_option0 = id627out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id628in_option1 = id625out_o;

    HWOffsetFix<32,0,UNSIGNED> id628x_1;

    switch((id628in_sel.getValueAsLong())) {
      case 0l:
        id628x_1 = id628in_option0;
        break;
      case 1l:
        id628x_1 = id628in_option1;
        break;
      default:
        id628x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id628out_result = (id628x_1);
  }
  { // Node ID: 3587 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3587in_input = id628out_result;

    id3587out_output[(getCycle()+1)%2] = id3587in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id614out_output;

  { // Node ID: 614 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id614in_input = id3589out_output[getCycle()%2];

    id614out_output = id614in_input;
  }
  { // Node ID: 3382 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2584out_result;

  { // Node ID: 2584 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2584in_a = id3382out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2584in_b = id3458out_output[getCycle()%2];

    id2584out_result = (eq_fixed(id2584in_a,id2584in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id613out_o;

  { // Node ID: 613 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id613in_i = id2584out_result;

    id613out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id613in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id615out_result;

  { // Node ID: 615 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id615in_a = id614out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id615in_b = id613out_o;

    id615out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id615in_a,id615in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id616out_result;

  { // Node ID: 616 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id616in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id616in_option0 = id615out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id616in_option1 = id613out_o;

    HWOffsetFix<32,0,UNSIGNED> id616x_1;

    switch((id616in_sel.getValueAsLong())) {
      case 0l:
        id616x_1 = id616in_option0;
        break;
      case 1l:
        id616x_1 = id616in_option1;
        break;
      default:
        id616x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id616out_result = (id616x_1);
  }
  { // Node ID: 3589 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3589in_input = id616out_result;

    id3589out_output[(getCycle()+1)%2] = id3589in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id602out_output;

  { // Node ID: 602 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id602in_input = id3591out_output[getCycle()%2];

    id602out_output = id602in_input;
  }
  { // Node ID: 3381 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2585out_result;

  { // Node ID: 2585 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2585in_a = id3381out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2585in_b = id3458out_output[getCycle()%2];

    id2585out_result = (eq_fixed(id2585in_a,id2585in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id601out_o;

  { // Node ID: 601 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id601in_i = id2585out_result;

    id601out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id601in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id603out_result;

  { // Node ID: 603 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id603in_a = id602out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id603in_b = id601out_o;

    id603out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id603in_a,id603in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id604out_result;

  { // Node ID: 604 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id604in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id604in_option0 = id603out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id604in_option1 = id601out_o;

    HWOffsetFix<32,0,UNSIGNED> id604x_1;

    switch((id604in_sel.getValueAsLong())) {
      case 0l:
        id604x_1 = id604in_option0;
        break;
      case 1l:
        id604x_1 = id604in_option1;
        break;
      default:
        id604x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id604out_result = (id604x_1);
  }
  { // Node ID: 3591 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3591in_input = id604out_result;

    id3591out_output[(getCycle()+1)%2] = id3591in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id590out_output;

  { // Node ID: 590 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id590in_input = id3593out_output[getCycle()%2];

    id590out_output = id590in_input;
  }
  { // Node ID: 3380 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2586out_result;

  { // Node ID: 2586 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2586in_a = id3380out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2586in_b = id3458out_output[getCycle()%2];

    id2586out_result = (eq_fixed(id2586in_a,id2586in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id589out_o;

  { // Node ID: 589 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id589in_i = id2586out_result;

    id589out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id589in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id591out_result;

  { // Node ID: 591 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id591in_a = id590out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id591in_b = id589out_o;

    id591out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id591in_a,id591in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id592out_result;

  { // Node ID: 592 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id592in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id592in_option0 = id591out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id592in_option1 = id589out_o;

    HWOffsetFix<32,0,UNSIGNED> id592x_1;

    switch((id592in_sel.getValueAsLong())) {
      case 0l:
        id592x_1 = id592in_option0;
        break;
      case 1l:
        id592x_1 = id592in_option1;
        break;
      default:
        id592x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id592out_result = (id592x_1);
  }
  { // Node ID: 3593 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3593in_input = id592out_result;

    id3593out_output[(getCycle()+1)%2] = id3593in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id578out_output;

  { // Node ID: 578 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id578in_input = id3595out_output[getCycle()%2];

    id578out_output = id578in_input;
  }
  { // Node ID: 3379 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2587out_result;

  { // Node ID: 2587 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2587in_a = id3379out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2587in_b = id3458out_output[getCycle()%2];

    id2587out_result = (eq_fixed(id2587in_a,id2587in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id577out_o;

  { // Node ID: 577 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id577in_i = id2587out_result;

    id577out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id577in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id579out_result;

  { // Node ID: 579 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id579in_a = id578out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id579in_b = id577out_o;

    id579out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id579in_a,id579in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id580out_result;

  { // Node ID: 580 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id580in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id580in_option0 = id579out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id580in_option1 = id577out_o;

    HWOffsetFix<32,0,UNSIGNED> id580x_1;

    switch((id580in_sel.getValueAsLong())) {
      case 0l:
        id580x_1 = id580in_option0;
        break;
      case 1l:
        id580x_1 = id580in_option1;
        break;
      default:
        id580x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id580out_result = (id580x_1);
  }
  { // Node ID: 3595 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3595in_input = id580out_result;

    id3595out_output[(getCycle()+1)%2] = id3595in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id566out_output;

  { // Node ID: 566 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id566in_input = id3597out_output[getCycle()%2];

    id566out_output = id566in_input;
  }
  { // Node ID: 3378 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2588out_result;

  { // Node ID: 2588 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2588in_a = id3378out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2588in_b = id3458out_output[getCycle()%2];

    id2588out_result = (eq_fixed(id2588in_a,id2588in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id565out_o;

  { // Node ID: 565 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id565in_i = id2588out_result;

    id565out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id565in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id567out_result;

  { // Node ID: 567 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id567in_a = id566out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id567in_b = id565out_o;

    id567out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id567in_a,id567in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id568out_result;

  { // Node ID: 568 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id568in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id568in_option0 = id567out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id568in_option1 = id565out_o;

    HWOffsetFix<32,0,UNSIGNED> id568x_1;

    switch((id568in_sel.getValueAsLong())) {
      case 0l:
        id568x_1 = id568in_option0;
        break;
      case 1l:
        id568x_1 = id568in_option1;
        break;
      default:
        id568x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id568out_result = (id568x_1);
  }
  { // Node ID: 3597 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3597in_input = id568out_result;

    id3597out_output[(getCycle()+1)%2] = id3597in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id554out_output;

  { // Node ID: 554 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id554in_input = id3599out_output[getCycle()%2];

    id554out_output = id554in_input;
  }
  { // Node ID: 3377 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2589out_result;

  { // Node ID: 2589 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2589in_a = id3377out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2589in_b = id3458out_output[getCycle()%2];

    id2589out_result = (eq_fixed(id2589in_a,id2589in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id553out_o;

  { // Node ID: 553 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id553in_i = id2589out_result;

    id553out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id553in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id555out_result;

  { // Node ID: 555 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id555in_a = id554out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id555in_b = id553out_o;

    id555out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id555in_a,id555in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id556out_result;

  { // Node ID: 556 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id556in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id556in_option0 = id555out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id556in_option1 = id553out_o;

    HWOffsetFix<32,0,UNSIGNED> id556x_1;

    switch((id556in_sel.getValueAsLong())) {
      case 0l:
        id556x_1 = id556in_option0;
        break;
      case 1l:
        id556x_1 = id556in_option1;
        break;
      default:
        id556x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id556out_result = (id556x_1);
  }
  { // Node ID: 3599 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3599in_input = id556out_result;

    id3599out_output[(getCycle()+1)%2] = id3599in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id542out_output;

  { // Node ID: 542 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id542in_input = id3601out_output[getCycle()%2];

    id542out_output = id542in_input;
  }
  { // Node ID: 3376 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2590out_result;

  { // Node ID: 2590 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2590in_a = id3376out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2590in_b = id3458out_output[getCycle()%2];

    id2590out_result = (eq_fixed(id2590in_a,id2590in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id541out_o;

  { // Node ID: 541 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id541in_i = id2590out_result;

    id541out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id541in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id543out_result;

  { // Node ID: 543 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id543in_a = id542out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id543in_b = id541out_o;

    id543out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id543in_a,id543in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id544out_result;

  { // Node ID: 544 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id544in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id544in_option0 = id543out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id544in_option1 = id541out_o;

    HWOffsetFix<32,0,UNSIGNED> id544x_1;

    switch((id544in_sel.getValueAsLong())) {
      case 0l:
        id544x_1 = id544in_option0;
        break;
      case 1l:
        id544x_1 = id544in_option1;
        break;
      default:
        id544x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id544out_result = (id544x_1);
  }
  { // Node ID: 3601 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3601in_input = id544out_result;

    id3601out_output[(getCycle()+1)%2] = id3601in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id530out_output;

  { // Node ID: 530 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id530in_input = id3603out_output[getCycle()%2];

    id530out_output = id530in_input;
  }
  { // Node ID: 3375 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2591out_result;

  { // Node ID: 2591 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2591in_a = id3375out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2591in_b = id3459out_output[getCycle()%2];

    id2591out_result = (eq_fixed(id2591in_a,id2591in_b));
  }
  { // Node ID: 3604 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3604in_input = id2591out_result;

    id3604out_output[(getCycle()+1)%2] = id3604in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id529out_o;

  { // Node ID: 529 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id529in_i = id3604out_output[getCycle()%2];

    id529out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id529in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id531out_result;

  { // Node ID: 531 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id531in_a = id530out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id531in_b = id529out_o;

    id531out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id531in_a,id531in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id532out_result;

  { // Node ID: 532 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id532in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id532in_option0 = id531out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id532in_option1 = id529out_o;

    HWOffsetFix<32,0,UNSIGNED> id532x_1;

    switch((id532in_sel.getValueAsLong())) {
      case 0l:
        id532x_1 = id532in_option0;
        break;
      case 1l:
        id532x_1 = id532in_option1;
        break;
      default:
        id532x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id532out_result = (id532x_1);
  }
  { // Node ID: 3603 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3603in_input = id532out_result;

    id3603out_output[(getCycle()+1)%2] = id3603in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id518out_output;

  { // Node ID: 518 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id518in_input = id3606out_output[getCycle()%2];

    id518out_output = id518in_input;
  }
  { // Node ID: 3374 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2592out_result;

  { // Node ID: 2592 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2592in_a = id3374out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2592in_b = id3459out_output[getCycle()%2];

    id2592out_result = (eq_fixed(id2592in_a,id2592in_b));
  }
  { // Node ID: 3607 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3607in_input = id2592out_result;

    id3607out_output[(getCycle()+1)%2] = id3607in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id517out_o;

  { // Node ID: 517 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id517in_i = id3607out_output[getCycle()%2];

    id517out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id517in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id519out_result;

  { // Node ID: 519 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id519in_a = id518out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id519in_b = id517out_o;

    id519out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id519in_a,id519in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id520out_result;

  { // Node ID: 520 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id520in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id520in_option0 = id519out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id520in_option1 = id517out_o;

    HWOffsetFix<32,0,UNSIGNED> id520x_1;

    switch((id520in_sel.getValueAsLong())) {
      case 0l:
        id520x_1 = id520in_option0;
        break;
      case 1l:
        id520x_1 = id520in_option1;
        break;
      default:
        id520x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id520out_result = (id520x_1);
  }
  { // Node ID: 3606 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3606in_input = id520out_result;

    id3606out_output[(getCycle()+1)%2] = id3606in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id506out_output;

  { // Node ID: 506 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id506in_input = id3609out_output[getCycle()%2];

    id506out_output = id506in_input;
  }
  { // Node ID: 3373 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2593out_result;

  { // Node ID: 2593 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2593in_a = id3373out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2593in_b = id3459out_output[getCycle()%2];

    id2593out_result = (eq_fixed(id2593in_a,id2593in_b));
  }
  { // Node ID: 3610 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3610in_input = id2593out_result;

    id3610out_output[(getCycle()+1)%2] = id3610in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id505out_o;

  { // Node ID: 505 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id505in_i = id3610out_output[getCycle()%2];

    id505out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id505in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id507out_result;

  { // Node ID: 507 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id507in_a = id506out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id507in_b = id505out_o;

    id507out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id507in_a,id507in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id508out_result;

  { // Node ID: 508 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id508in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id508in_option0 = id507out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id508in_option1 = id505out_o;

    HWOffsetFix<32,0,UNSIGNED> id508x_1;

    switch((id508in_sel.getValueAsLong())) {
      case 0l:
        id508x_1 = id508in_option0;
        break;
      case 1l:
        id508x_1 = id508in_option1;
        break;
      default:
        id508x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id508out_result = (id508x_1);
  }
  { // Node ID: 3609 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3609in_input = id508out_result;

    id3609out_output[(getCycle()+1)%2] = id3609in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id494out_output;

  { // Node ID: 494 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id494in_input = id3612out_output[getCycle()%2];

    id494out_output = id494in_input;
  }
  { // Node ID: 3372 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2594out_result;

  { // Node ID: 2594 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2594in_a = id3372out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2594in_b = id3459out_output[getCycle()%2];

    id2594out_result = (eq_fixed(id2594in_a,id2594in_b));
  }
  { // Node ID: 3613 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3613in_input = id2594out_result;

    id3613out_output[(getCycle()+1)%2] = id3613in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id493out_o;

  { // Node ID: 493 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id493in_i = id3613out_output[getCycle()%2];

    id493out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id493in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id495out_result;

  { // Node ID: 495 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id495in_a = id494out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id495in_b = id493out_o;

    id495out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id495in_a,id495in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id496out_result;

  { // Node ID: 496 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id496in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id496in_option0 = id495out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id496in_option1 = id493out_o;

    HWOffsetFix<32,0,UNSIGNED> id496x_1;

    switch((id496in_sel.getValueAsLong())) {
      case 0l:
        id496x_1 = id496in_option0;
        break;
      case 1l:
        id496x_1 = id496in_option1;
        break;
      default:
        id496x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id496out_result = (id496x_1);
  }
  { // Node ID: 3612 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3612in_input = id496out_result;

    id3612out_output[(getCycle()+1)%2] = id3612in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id482out_output;

  { // Node ID: 482 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id482in_input = id3615out_output[getCycle()%2];

    id482out_output = id482in_input;
  }
  { // Node ID: 3371 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2595out_result;

  { // Node ID: 2595 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2595in_a = id3371out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2595in_b = id3459out_output[getCycle()%2];

    id2595out_result = (eq_fixed(id2595in_a,id2595in_b));
  }
  { // Node ID: 3616 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3616in_input = id2595out_result;

    id3616out_output[(getCycle()+1)%2] = id3616in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id481out_o;

  { // Node ID: 481 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id481in_i = id3616out_output[getCycle()%2];

    id481out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id481in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id483out_result;

  { // Node ID: 483 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id483in_a = id482out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id483in_b = id481out_o;

    id483out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id483in_a,id483in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id484out_result;

  { // Node ID: 484 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id484in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id484in_option0 = id483out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id484in_option1 = id481out_o;

    HWOffsetFix<32,0,UNSIGNED> id484x_1;

    switch((id484in_sel.getValueAsLong())) {
      case 0l:
        id484x_1 = id484in_option0;
        break;
      case 1l:
        id484x_1 = id484in_option1;
        break;
      default:
        id484x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id484out_result = (id484x_1);
  }
  { // Node ID: 3615 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3615in_input = id484out_result;

    id3615out_output[(getCycle()+1)%2] = id3615in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id470out_output;

  { // Node ID: 470 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id470in_input = id3618out_output[getCycle()%2];

    id470out_output = id470in_input;
  }
  { // Node ID: 3370 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2596out_result;

  { // Node ID: 2596 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2596in_a = id3370out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2596in_b = id3459out_output[getCycle()%2];

    id2596out_result = (eq_fixed(id2596in_a,id2596in_b));
  }
  { // Node ID: 3619 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3619in_input = id2596out_result;

    id3619out_output[(getCycle()+1)%2] = id3619in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id469out_o;

  { // Node ID: 469 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id469in_i = id3619out_output[getCycle()%2];

    id469out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id469in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id471out_result;

  { // Node ID: 471 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id471in_a = id470out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id471in_b = id469out_o;

    id471out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id471in_a,id471in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id472out_result;

  { // Node ID: 472 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id472in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id472in_option0 = id471out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id472in_option1 = id469out_o;

    HWOffsetFix<32,0,UNSIGNED> id472x_1;

    switch((id472in_sel.getValueAsLong())) {
      case 0l:
        id472x_1 = id472in_option0;
        break;
      case 1l:
        id472x_1 = id472in_option1;
        break;
      default:
        id472x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id472out_result = (id472x_1);
  }
  { // Node ID: 3618 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3618in_input = id472out_result;

    id3618out_output[(getCycle()+1)%2] = id3618in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id458out_output;

  { // Node ID: 458 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id458in_input = id3621out_output[getCycle()%2];

    id458out_output = id458in_input;
  }
  { // Node ID: 3369 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2597out_result;

  { // Node ID: 2597 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2597in_a = id3369out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2597in_b = id3459out_output[getCycle()%2];

    id2597out_result = (eq_fixed(id2597in_a,id2597in_b));
  }
  { // Node ID: 3622 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3622in_input = id2597out_result;

    id3622out_output[(getCycle()+1)%2] = id3622in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id457out_o;

  { // Node ID: 457 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id457in_i = id3622out_output[getCycle()%2];

    id457out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id457in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id459out_result;

  { // Node ID: 459 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id459in_a = id458out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id459in_b = id457out_o;

    id459out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id459in_a,id459in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id460out_result;

  { // Node ID: 460 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id460in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id460in_option0 = id459out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id460in_option1 = id457out_o;

    HWOffsetFix<32,0,UNSIGNED> id460x_1;

    switch((id460in_sel.getValueAsLong())) {
      case 0l:
        id460x_1 = id460in_option0;
        break;
      case 1l:
        id460x_1 = id460in_option1;
        break;
      default:
        id460x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id460out_result = (id460x_1);
  }
  { // Node ID: 3621 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3621in_input = id460out_result;

    id3621out_output[(getCycle()+1)%2] = id3621in_input;
  }
  { // Node ID: 3449 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3449in_input = id3450out_output[getCycle()%2];

    id3449out_output[(getCycle()+1)%2] = id3449in_input;
  }
  { // Node ID: 3626 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3626in_input = id3449out_output[getCycle()%2];

    id3626out_output[(getCycle()+1)%2] = id3626in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id446out_output;

  { // Node ID: 446 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id446in_input = id3624out_output[getCycle()%2];

    id446out_output = id446in_input;
  }
  { // Node ID: 3368 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2598out_result;

  { // Node ID: 2598 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2598in_a = id3368out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2598in_b = id3459out_output[getCycle()%2];

    id2598out_result = (eq_fixed(id2598in_a,id2598in_b));
  }
  { // Node ID: 3625 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3625in_input = id2598out_result;

    id3625out_output[(getCycle()+1)%2] = id3625in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id445out_o;

  { // Node ID: 445 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id445in_i = id3625out_output[getCycle()%2];

    id445out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id445in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id447out_result;

  { // Node ID: 447 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id447in_a = id446out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id447in_b = id445out_o;

    id447out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id447in_a,id447in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id448out_result;

  { // Node ID: 448 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id448in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id448in_option0 = id447out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id448in_option1 = id445out_o;

    HWOffsetFix<32,0,UNSIGNED> id448x_1;

    switch((id448in_sel.getValueAsLong())) {
      case 0l:
        id448x_1 = id448in_option0;
        break;
      case 1l:
        id448x_1 = id448in_option1;
        break;
      default:
        id448x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id448out_result = (id448x_1);
  }
  { // Node ID: 3624 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3624in_input = id448out_result;

    id3624out_output[(getCycle()+1)%2] = id3624in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id434out_output;

  { // Node ID: 434 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id434in_input = id3627out_output[getCycle()%2];

    id434out_output = id434in_input;
  }
  { // Node ID: 3367 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2599out_result;

  { // Node ID: 2599 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2599in_a = id3367out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2599in_b = id3459out_output[getCycle()%2];

    id2599out_result = (eq_fixed(id2599in_a,id2599in_b));
  }
  { // Node ID: 3628 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3628in_input = id2599out_result;

    id3628out_output[(getCycle()+1)%2] = id3628in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id433out_o;

  { // Node ID: 433 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id433in_i = id3628out_output[getCycle()%2];

    id433out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id433in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id435out_result;

  { // Node ID: 435 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id435in_a = id434out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id435in_b = id433out_o;

    id435out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id435in_a,id435in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id436out_result;

  { // Node ID: 436 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id436in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id436in_option0 = id435out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id436in_option1 = id433out_o;

    HWOffsetFix<32,0,UNSIGNED> id436x_1;

    switch((id436in_sel.getValueAsLong())) {
      case 0l:
        id436x_1 = id436in_option0;
        break;
      case 1l:
        id436x_1 = id436in_option1;
        break;
      default:
        id436x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id436out_result = (id436x_1);
  }
  { // Node ID: 3627 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3627in_input = id436out_result;

    id3627out_output[(getCycle()+1)%2] = id3627in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id422out_output;

  { // Node ID: 422 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id422in_input = id3630out_output[getCycle()%2];

    id422out_output = id422in_input;
  }
  { // Node ID: 3366 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2600out_result;

  { // Node ID: 2600 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2600in_a = id3366out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2600in_b = id3459out_output[getCycle()%2];

    id2600out_result = (eq_fixed(id2600in_a,id2600in_b));
  }
  { // Node ID: 3631 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3631in_input = id2600out_result;

    id3631out_output[(getCycle()+1)%2] = id3631in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id421out_o;

  { // Node ID: 421 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id421in_i = id3631out_output[getCycle()%2];

    id421out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id421in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id423out_result;

  { // Node ID: 423 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id423in_a = id422out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id423in_b = id421out_o;

    id423out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id423in_a,id423in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id424out_result;

  { // Node ID: 424 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id424in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id424in_option0 = id423out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id424in_option1 = id421out_o;

    HWOffsetFix<32,0,UNSIGNED> id424x_1;

    switch((id424in_sel.getValueAsLong())) {
      case 0l:
        id424x_1 = id424in_option0;
        break;
      case 1l:
        id424x_1 = id424in_option1;
        break;
      default:
        id424x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id424out_result = (id424x_1);
  }
  { // Node ID: 3630 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3630in_input = id424out_result;

    id3630out_output[(getCycle()+1)%2] = id3630in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id410out_output;

  { // Node ID: 410 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id410in_input = id3633out_output[getCycle()%2];

    id410out_output = id410in_input;
  }
  { // Node ID: 3365 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2601out_result;

  { // Node ID: 2601 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2601in_a = id3365out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2601in_b = id3459out_output[getCycle()%2];

    id2601out_result = (eq_fixed(id2601in_a,id2601in_b));
  }
  { // Node ID: 3634 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3634in_input = id2601out_result;

    id3634out_output[(getCycle()+1)%2] = id3634in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id409out_o;

  { // Node ID: 409 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id409in_i = id3634out_output[getCycle()%2];

    id409out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id409in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id411out_result;

  { // Node ID: 411 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id411in_a = id410out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id411in_b = id409out_o;

    id411out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id411in_a,id411in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id412out_result;

  { // Node ID: 412 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id412in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id412in_option0 = id411out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id412in_option1 = id409out_o;

    HWOffsetFix<32,0,UNSIGNED> id412x_1;

    switch((id412in_sel.getValueAsLong())) {
      case 0l:
        id412x_1 = id412in_option0;
        break;
      case 1l:
        id412x_1 = id412in_option1;
        break;
      default:
        id412x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id412out_result = (id412x_1);
  }
  { // Node ID: 3633 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3633in_input = id412out_result;

    id3633out_output[(getCycle()+1)%2] = id3633in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id398out_output;

  { // Node ID: 398 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id398in_input = id3636out_output[getCycle()%2];

    id398out_output = id398in_input;
  }
  { // Node ID: 3364 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2602out_result;

  { // Node ID: 2602 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2602in_a = id3364out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2602in_b = id3459out_output[getCycle()%2];

    id2602out_result = (eq_fixed(id2602in_a,id2602in_b));
  }
  { // Node ID: 3637 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3637in_input = id2602out_result;

    id3637out_output[(getCycle()+1)%2] = id3637in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id397out_o;

  { // Node ID: 397 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id397in_i = id3637out_output[getCycle()%2];

    id397out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id397in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id399out_result;

  { // Node ID: 399 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id399in_a = id398out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id399in_b = id397out_o;

    id399out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id399in_a,id399in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id400out_result;

  { // Node ID: 400 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id400in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id400in_option0 = id399out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id400in_option1 = id397out_o;

    HWOffsetFix<32,0,UNSIGNED> id400x_1;

    switch((id400in_sel.getValueAsLong())) {
      case 0l:
        id400x_1 = id400in_option0;
        break;
      case 1l:
        id400x_1 = id400in_option1;
        break;
      default:
        id400x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id400out_result = (id400x_1);
  }
  { // Node ID: 3636 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3636in_input = id400out_result;

    id3636out_output[(getCycle()+1)%2] = id3636in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id386out_output;

  { // Node ID: 386 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id386in_input = id3639out_output[getCycle()%2];

    id386out_output = id386in_input;
  }
  { // Node ID: 3363 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2603out_result;

  { // Node ID: 2603 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2603in_a = id3363out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2603in_b = id3459out_output[getCycle()%2];

    id2603out_result = (eq_fixed(id2603in_a,id2603in_b));
  }
  { // Node ID: 3640 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3640in_input = id2603out_result;

    id3640out_output[(getCycle()+1)%2] = id3640in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id385out_o;

  { // Node ID: 385 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id385in_i = id3640out_output[getCycle()%2];

    id385out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id385in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id387out_result;

  { // Node ID: 387 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id387in_a = id386out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id387in_b = id385out_o;

    id387out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id387in_a,id387in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id388out_result;

  { // Node ID: 388 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id388in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id388in_option0 = id387out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id388in_option1 = id385out_o;

    HWOffsetFix<32,0,UNSIGNED> id388x_1;

    switch((id388in_sel.getValueAsLong())) {
      case 0l:
        id388x_1 = id388in_option0;
        break;
      case 1l:
        id388x_1 = id388in_option1;
        break;
      default:
        id388x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id388out_result = (id388x_1);
  }
  { // Node ID: 3639 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3639in_input = id388out_result;

    id3639out_output[(getCycle()+1)%2] = id3639in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id374out_output;

  { // Node ID: 374 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id374in_input = id3642out_output[getCycle()%2];

    id374out_output = id374in_input;
  }
  { // Node ID: 3362 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2604out_result;

  { // Node ID: 2604 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2604in_a = id3362out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2604in_b = id3459out_output[getCycle()%2];

    id2604out_result = (eq_fixed(id2604in_a,id2604in_b));
  }
  { // Node ID: 3643 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3643in_input = id2604out_result;

    id3643out_output[(getCycle()+1)%2] = id3643in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id373out_o;

  { // Node ID: 373 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id373in_i = id3643out_output[getCycle()%2];

    id373out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id373in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id375out_result;

  { // Node ID: 375 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id375in_a = id374out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id375in_b = id373out_o;

    id375out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id375in_a,id375in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id376out_result;

  { // Node ID: 376 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id376in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id376in_option0 = id375out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id376in_option1 = id373out_o;

    HWOffsetFix<32,0,UNSIGNED> id376x_1;

    switch((id376in_sel.getValueAsLong())) {
      case 0l:
        id376x_1 = id376in_option0;
        break;
      case 1l:
        id376x_1 = id376in_option1;
        break;
      default:
        id376x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id376out_result = (id376x_1);
  }
  { // Node ID: 3642 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3642in_input = id376out_result;

    id3642out_output[(getCycle()+1)%2] = id3642in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id362out_output;

  { // Node ID: 362 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id362in_input = id3645out_output[getCycle()%2];

    id362out_output = id362in_input;
  }
  { // Node ID: 3361 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2605out_result;

  { // Node ID: 2605 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2605in_a = id3361out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2605in_b = id3459out_output[getCycle()%2];

    id2605out_result = (eq_fixed(id2605in_a,id2605in_b));
  }
  { // Node ID: 3646 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3646in_input = id2605out_result;

    id3646out_output[(getCycle()+1)%2] = id3646in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id361out_o;

  { // Node ID: 361 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id361in_i = id3646out_output[getCycle()%2];

    id361out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id361in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id363out_result;

  { // Node ID: 363 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id363in_a = id362out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id363in_b = id361out_o;

    id363out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id363in_a,id363in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id364out_result;

  { // Node ID: 364 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id364in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id364in_option0 = id363out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id364in_option1 = id361out_o;

    HWOffsetFix<32,0,UNSIGNED> id364x_1;

    switch((id364in_sel.getValueAsLong())) {
      case 0l:
        id364x_1 = id364in_option0;
        break;
      case 1l:
        id364x_1 = id364in_option1;
        break;
      default:
        id364x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id364out_result = (id364x_1);
  }
  { // Node ID: 3645 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3645in_input = id364out_result;

    id3645out_output[(getCycle()+1)%2] = id3645in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id350out_output;

  { // Node ID: 350 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id350in_input = id3648out_output[getCycle()%2];

    id350out_output = id350in_input;
  }
  { // Node ID: 3360 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2606out_result;

  { // Node ID: 2606 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2606in_a = id3360out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2606in_b = id3459out_output[getCycle()%2];

    id2606out_result = (eq_fixed(id2606in_a,id2606in_b));
  }
  { // Node ID: 3649 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3649in_input = id2606out_result;

    id3649out_output[(getCycle()+1)%2] = id3649in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id349out_o;

  { // Node ID: 349 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id349in_i = id3649out_output[getCycle()%2];

    id349out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id349in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id351out_result;

  { // Node ID: 351 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id351in_a = id350out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id351in_b = id349out_o;

    id351out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id351in_a,id351in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id352out_result;

  { // Node ID: 352 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id352in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id352in_option0 = id351out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id352in_option1 = id349out_o;

    HWOffsetFix<32,0,UNSIGNED> id352x_1;

    switch((id352in_sel.getValueAsLong())) {
      case 0l:
        id352x_1 = id352in_option0;
        break;
      case 1l:
        id352x_1 = id352in_option1;
        break;
      default:
        id352x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id352out_result = (id352x_1);
  }
  { // Node ID: 3648 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3648in_input = id352out_result;

    id3648out_output[(getCycle()+1)%2] = id3648in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id338out_output;

  { // Node ID: 338 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id338in_input = id3651out_output[getCycle()%2];

    id338out_output = id338in_input;
  }
  { // Node ID: 3359 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2607out_result;

  { // Node ID: 2607 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2607in_a = id3359out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2607in_b = id3459out_output[getCycle()%2];

    id2607out_result = (eq_fixed(id2607in_a,id2607in_b));
  }
  { // Node ID: 3652 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3652in_input = id2607out_result;

    id3652out_output[(getCycle()+1)%2] = id3652in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id337out_o;

  { // Node ID: 337 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id337in_i = id3652out_output[getCycle()%2];

    id337out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id337in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id339out_result;

  { // Node ID: 339 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id339in_a = id338out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id339in_b = id337out_o;

    id339out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id339in_a,id339in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id340out_result;

  { // Node ID: 340 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id340in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id340in_option0 = id339out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id340in_option1 = id337out_o;

    HWOffsetFix<32,0,UNSIGNED> id340x_1;

    switch((id340in_sel.getValueAsLong())) {
      case 0l:
        id340x_1 = id340in_option0;
        break;
      case 1l:
        id340x_1 = id340in_option1;
        break;
      default:
        id340x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id340out_result = (id340x_1);
  }
  { // Node ID: 3651 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3651in_input = id340out_result;

    id3651out_output[(getCycle()+1)%2] = id3651in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id326out_output;

  { // Node ID: 326 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id326in_input = id3654out_output[getCycle()%2];

    id326out_output = id326in_input;
  }
  { // Node ID: 3358 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2608out_result;

  { // Node ID: 2608 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2608in_a = id3358out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2608in_b = id3459out_output[getCycle()%2];

    id2608out_result = (eq_fixed(id2608in_a,id2608in_b));
  }
  { // Node ID: 3655 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3655in_input = id2608out_result;

    id3655out_output[(getCycle()+1)%2] = id3655in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id325out_o;

  { // Node ID: 325 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id325in_i = id3655out_output[getCycle()%2];

    id325out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id325in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id327out_result;

  { // Node ID: 327 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id327in_a = id326out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id327in_b = id325out_o;

    id327out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id327in_a,id327in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id328out_result;

  { // Node ID: 328 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id328in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id328in_option0 = id327out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id328in_option1 = id325out_o;

    HWOffsetFix<32,0,UNSIGNED> id328x_1;

    switch((id328in_sel.getValueAsLong())) {
      case 0l:
        id328x_1 = id328in_option0;
        break;
      case 1l:
        id328x_1 = id328in_option1;
        break;
      default:
        id328x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id328out_result = (id328x_1);
  }
  { // Node ID: 3654 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3654in_input = id328out_result;

    id3654out_output[(getCycle()+1)%2] = id3654in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id314out_output;

  { // Node ID: 314 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id314in_input = id3657out_output[getCycle()%2];

    id314out_output = id314in_input;
  }
  { // Node ID: 3357 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2609out_result;

  { // Node ID: 2609 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2609in_a = id3357out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2609in_b = id3459out_output[getCycle()%2];

    id2609out_result = (eq_fixed(id2609in_a,id2609in_b));
  }
  { // Node ID: 3658 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3658in_input = id2609out_result;

    id3658out_output[(getCycle()+1)%2] = id3658in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id313out_o;

  { // Node ID: 313 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id313in_i = id3658out_output[getCycle()%2];

    id313out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id313in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id315out_result;

  { // Node ID: 315 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id315in_a = id314out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id315in_b = id313out_o;

    id315out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id315in_a,id315in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id316out_result;

  { // Node ID: 316 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id316in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id316in_option0 = id315out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id316in_option1 = id313out_o;

    HWOffsetFix<32,0,UNSIGNED> id316x_1;

    switch((id316in_sel.getValueAsLong())) {
      case 0l:
        id316x_1 = id316in_option0;
        break;
      case 1l:
        id316x_1 = id316in_option1;
        break;
      default:
        id316x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id316out_result = (id316x_1);
  }
  { // Node ID: 3657 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3657in_input = id316out_result;

    id3657out_output[(getCycle()+1)%2] = id3657in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id302out_output;

  { // Node ID: 302 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id302in_input = id3660out_output[getCycle()%2];

    id302out_output = id302in_input;
  }
  { // Node ID: 3356 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2610out_result;

  { // Node ID: 2610 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2610in_a = id3356out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2610in_b = id3459out_output[getCycle()%2];

    id2610out_result = (eq_fixed(id2610in_a,id2610in_b));
  }
  { // Node ID: 3661 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3661in_input = id2610out_result;

    id3661out_output[(getCycle()+1)%2] = id3661in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id301out_o;

  { // Node ID: 301 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id301in_i = id3661out_output[getCycle()%2];

    id301out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id301in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id303out_result;

  { // Node ID: 303 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id303in_a = id302out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id303in_b = id301out_o;

    id303out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id303in_a,id303in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id304out_result;

  { // Node ID: 304 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id304in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id304in_option0 = id303out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id304in_option1 = id301out_o;

    HWOffsetFix<32,0,UNSIGNED> id304x_1;

    switch((id304in_sel.getValueAsLong())) {
      case 0l:
        id304x_1 = id304in_option0;
        break;
      case 1l:
        id304x_1 = id304in_option1;
        break;
      default:
        id304x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id304out_result = (id304x_1);
  }
  { // Node ID: 3660 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3660in_input = id304out_result;

    id3660out_output[(getCycle()+1)%2] = id3660in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id290out_output;

  { // Node ID: 290 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id290in_input = id3663out_output[getCycle()%2];

    id290out_output = id290in_input;
  }
  { // Node ID: 3355 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2611out_result;

  { // Node ID: 2611 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2611in_a = id3355out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2611in_b = id3459out_output[getCycle()%2];

    id2611out_result = (eq_fixed(id2611in_a,id2611in_b));
  }
  { // Node ID: 3664 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3664in_input = id2611out_result;

    id3664out_output[(getCycle()+1)%2] = id3664in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id289out_o;

  { // Node ID: 289 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id289in_i = id3664out_output[getCycle()%2];

    id289out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id289in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id291out_result;

  { // Node ID: 291 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id291in_a = id290out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id291in_b = id289out_o;

    id291out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id291in_a,id291in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id292out_result;

  { // Node ID: 292 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id292in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id292in_option0 = id291out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id292in_option1 = id289out_o;

    HWOffsetFix<32,0,UNSIGNED> id292x_1;

    switch((id292in_sel.getValueAsLong())) {
      case 0l:
        id292x_1 = id292in_option0;
        break;
      case 1l:
        id292x_1 = id292in_option1;
        break;
      default:
        id292x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id292out_result = (id292x_1);
  }
  { // Node ID: 3663 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3663in_input = id292out_result;

    id3663out_output[(getCycle()+1)%2] = id3663in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id278out_output;

  { // Node ID: 278 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id278in_input = id3666out_output[getCycle()%2];

    id278out_output = id278in_input;
  }
  { // Node ID: 3354 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2612out_result;

  { // Node ID: 2612 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2612in_a = id3354out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2612in_b = id3459out_output[getCycle()%2];

    id2612out_result = (eq_fixed(id2612in_a,id2612in_b));
  }
  { // Node ID: 3667 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3667in_input = id2612out_result;

    id3667out_output[(getCycle()+1)%2] = id3667in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id277out_o;

  { // Node ID: 277 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id277in_i = id3667out_output[getCycle()%2];

    id277out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id277in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id279out_result;

  { // Node ID: 279 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id279in_a = id278out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id279in_b = id277out_o;

    id279out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id279in_a,id279in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id280out_result;

  { // Node ID: 280 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id280in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id280in_option0 = id279out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id280in_option1 = id277out_o;

    HWOffsetFix<32,0,UNSIGNED> id280x_1;

    switch((id280in_sel.getValueAsLong())) {
      case 0l:
        id280x_1 = id280in_option0;
        break;
      case 1l:
        id280x_1 = id280in_option1;
        break;
      default:
        id280x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id280out_result = (id280x_1);
  }
  { // Node ID: 3666 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3666in_input = id280out_result;

    id3666out_output[(getCycle()+1)%2] = id3666in_input;
  }
  { // Node ID: 3448 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3448in_input = id3449out_output[getCycle()%2];

    id3448out_output[(getCycle()+1)%2] = id3448in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id266out_output;

  { // Node ID: 266 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id266in_input = id3669out_output[getCycle()%2];

    id266out_output = id266in_input;
  }
  { // Node ID: 3353 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2613out_result;

  { // Node ID: 2613 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2613in_a = id3353out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2613in_b = id3459out_output[getCycle()%2];

    id2613out_result = (eq_fixed(id2613in_a,id2613in_b));
  }
  { // Node ID: 3670 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3670in_input = id2613out_result;

    id3670out_output[(getCycle()+1)%2] = id3670in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id265out_o;

  { // Node ID: 265 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id265in_i = id3670out_output[getCycle()%2];

    id265out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id265in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id267out_result;

  { // Node ID: 267 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id267in_a = id266out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id267in_b = id265out_o;

    id267out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id267in_a,id267in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id268out_result;

  { // Node ID: 268 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id268in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id268in_option0 = id267out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id268in_option1 = id265out_o;

    HWOffsetFix<32,0,UNSIGNED> id268x_1;

    switch((id268in_sel.getValueAsLong())) {
      case 0l:
        id268x_1 = id268in_option0;
        break;
      case 1l:
        id268x_1 = id268in_option1;
        break;
      default:
        id268x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id268out_result = (id268x_1);
  }
  { // Node ID: 3669 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3669in_input = id268out_result;

    id3669out_output[(getCycle()+1)%2] = id3669in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id254out_output;

  { // Node ID: 254 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id254in_input = id3671out_output[getCycle()%2];

    id254out_output = id254in_input;
  }
  { // Node ID: 3352 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2614out_result;

  { // Node ID: 2614 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2614in_a = id3352out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2614in_b = id3459out_output[getCycle()%2];

    id2614out_result = (eq_fixed(id2614in_a,id2614in_b));
  }
  { // Node ID: 3672 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3672in_input = id2614out_result;

    id3672out_output[(getCycle()+1)%2] = id3672in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id253out_o;

  { // Node ID: 253 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id253in_i = id3672out_output[getCycle()%2];

    id253out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id253in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id255out_result;

  { // Node ID: 255 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id255in_a = id254out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id255in_b = id253out_o;

    id255out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id255in_a,id255in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id256out_result;

  { // Node ID: 256 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id256in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id256in_option0 = id255out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id256in_option1 = id253out_o;

    HWOffsetFix<32,0,UNSIGNED> id256x_1;

    switch((id256in_sel.getValueAsLong())) {
      case 0l:
        id256x_1 = id256in_option0;
        break;
      case 1l:
        id256x_1 = id256in_option1;
        break;
      default:
        id256x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id256out_result = (id256x_1);
  }
  { // Node ID: 3671 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3671in_input = id256out_result;

    id3671out_output[(getCycle()+1)%2] = id3671in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id242out_output;

  { // Node ID: 242 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id242in_input = id3673out_output[getCycle()%2];

    id242out_output = id242in_input;
  }
  { // Node ID: 3351 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2615out_result;

  { // Node ID: 2615 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2615in_a = id3351out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2615in_b = id3459out_output[getCycle()%2];

    id2615out_result = (eq_fixed(id2615in_a,id2615in_b));
  }
  { // Node ID: 3674 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3674in_input = id2615out_result;

    id3674out_output[(getCycle()+1)%2] = id3674in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id241out_o;

  { // Node ID: 241 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id241in_i = id3674out_output[getCycle()%2];

    id241out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id241in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id243out_result;

  { // Node ID: 243 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id243in_a = id242out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id243in_b = id241out_o;

    id243out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id243in_a,id243in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id244out_result;

  { // Node ID: 244 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id244in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id244in_option0 = id243out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id244in_option1 = id241out_o;

    HWOffsetFix<32,0,UNSIGNED> id244x_1;

    switch((id244in_sel.getValueAsLong())) {
      case 0l:
        id244x_1 = id244in_option0;
        break;
      case 1l:
        id244x_1 = id244in_option1;
        break;
      default:
        id244x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id244out_result = (id244x_1);
  }
  { // Node ID: 3673 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3673in_input = id244out_result;

    id3673out_output[(getCycle()+1)%2] = id3673in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id230out_output;

  { // Node ID: 230 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id230in_input = id3675out_output[getCycle()%2];

    id230out_output = id230in_input;
  }
  { // Node ID: 3350 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2616out_result;

  { // Node ID: 2616 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2616in_a = id3350out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2616in_b = id3459out_output[getCycle()%2];

    id2616out_result = (eq_fixed(id2616in_a,id2616in_b));
  }
  { // Node ID: 3676 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3676in_input = id2616out_result;

    id3676out_output[(getCycle()+1)%2] = id3676in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id229out_o;

  { // Node ID: 229 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id229in_i = id3676out_output[getCycle()%2];

    id229out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id229in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id231out_result;

  { // Node ID: 231 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id231in_a = id230out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id231in_b = id229out_o;

    id231out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id231in_a,id231in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id232out_result;

  { // Node ID: 232 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id232in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id232in_option0 = id231out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id232in_option1 = id229out_o;

    HWOffsetFix<32,0,UNSIGNED> id232x_1;

    switch((id232in_sel.getValueAsLong())) {
      case 0l:
        id232x_1 = id232in_option0;
        break;
      case 1l:
        id232x_1 = id232in_option1;
        break;
      default:
        id232x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id232out_result = (id232x_1);
  }
  { // Node ID: 3675 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3675in_input = id232out_result;

    id3675out_output[(getCycle()+1)%2] = id3675in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id218out_output;

  { // Node ID: 218 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id218in_input = id3677out_output[getCycle()%2];

    id218out_output = id218in_input;
  }
  { // Node ID: 3349 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2617out_result;

  { // Node ID: 2617 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2617in_a = id3349out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2617in_b = id3459out_output[getCycle()%2];

    id2617out_result = (eq_fixed(id2617in_a,id2617in_b));
  }
  { // Node ID: 3678 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3678in_input = id2617out_result;

    id3678out_output[(getCycle()+1)%2] = id3678in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id217out_o;

  { // Node ID: 217 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id217in_i = id3678out_output[getCycle()%2];

    id217out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id217in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id219out_result;

  { // Node ID: 219 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id219in_a = id218out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id219in_b = id217out_o;

    id219out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id219in_a,id219in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id220out_result;

  { // Node ID: 220 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id220in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id220in_option0 = id219out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id220in_option1 = id217out_o;

    HWOffsetFix<32,0,UNSIGNED> id220x_1;

    switch((id220in_sel.getValueAsLong())) {
      case 0l:
        id220x_1 = id220in_option0;
        break;
      case 1l:
        id220x_1 = id220in_option1;
        break;
      default:
        id220x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id220out_result = (id220x_1);
  }
  { // Node ID: 3677 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3677in_input = id220out_result;

    id3677out_output[(getCycle()+1)%2] = id3677in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id206out_output;

  { // Node ID: 206 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id206in_input = id3679out_output[getCycle()%2];

    id206out_output = id206in_input;
  }
  { // Node ID: 3348 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2618out_result;

  { // Node ID: 2618 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2618in_a = id3348out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2618in_b = id3459out_output[getCycle()%2];

    id2618out_result = (eq_fixed(id2618in_a,id2618in_b));
  }
  { // Node ID: 3680 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3680in_input = id2618out_result;

    id3680out_output[(getCycle()+1)%2] = id3680in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id205out_o;

  { // Node ID: 205 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id205in_i = id3680out_output[getCycle()%2];

    id205out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id205in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id207out_result;

  { // Node ID: 207 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id207in_a = id206out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id207in_b = id205out_o;

    id207out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id207in_a,id207in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id208out_result;

  { // Node ID: 208 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id208in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id208in_option0 = id207out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id208in_option1 = id205out_o;

    HWOffsetFix<32,0,UNSIGNED> id208x_1;

    switch((id208in_sel.getValueAsLong())) {
      case 0l:
        id208x_1 = id208in_option0;
        break;
      case 1l:
        id208x_1 = id208in_option1;
        break;
      default:
        id208x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id208out_result = (id208x_1);
  }
  { // Node ID: 3679 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3679in_input = id208out_result;

    id3679out_output[(getCycle()+1)%2] = id3679in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id194out_output;

  { // Node ID: 194 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id194in_input = id3681out_output[getCycle()%2];

    id194out_output = id194in_input;
  }
  { // Node ID: 3347 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2619out_result;

  { // Node ID: 2619 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2619in_a = id3347out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2619in_b = id3459out_output[getCycle()%2];

    id2619out_result = (eq_fixed(id2619in_a,id2619in_b));
  }
  { // Node ID: 3682 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3682in_input = id2619out_result;

    id3682out_output[(getCycle()+1)%2] = id3682in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id193out_o;

  { // Node ID: 193 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id193in_i = id3682out_output[getCycle()%2];

    id193out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id193in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id195out_result;

  { // Node ID: 195 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id195in_a = id194out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id195in_b = id193out_o;

    id195out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id195in_a,id195in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id196out_result;

  { // Node ID: 196 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id196in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id196in_option0 = id195out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id196in_option1 = id193out_o;

    HWOffsetFix<32,0,UNSIGNED> id196x_1;

    switch((id196in_sel.getValueAsLong())) {
      case 0l:
        id196x_1 = id196in_option0;
        break;
      case 1l:
        id196x_1 = id196in_option1;
        break;
      default:
        id196x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id196out_result = (id196x_1);
  }
  { // Node ID: 3681 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3681in_input = id196out_result;

    id3681out_output[(getCycle()+1)%2] = id3681in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id182out_output;

  { // Node ID: 182 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id182in_input = id3683out_output[getCycle()%2];

    id182out_output = id182in_input;
  }
  { // Node ID: 3346 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2620out_result;

  { // Node ID: 2620 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2620in_a = id3346out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2620in_b = id3459out_output[getCycle()%2];

    id2620out_result = (eq_fixed(id2620in_a,id2620in_b));
  }
  { // Node ID: 3684 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3684in_input = id2620out_result;

    id3684out_output[(getCycle()+1)%2] = id3684in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id181out_o;

  { // Node ID: 181 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id181in_i = id3684out_output[getCycle()%2];

    id181out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id181in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id183out_result;

  { // Node ID: 183 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id183in_a = id182out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id183in_b = id181out_o;

    id183out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id183in_a,id183in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id184out_result;

  { // Node ID: 184 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id184in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id184in_option0 = id183out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id184in_option1 = id181out_o;

    HWOffsetFix<32,0,UNSIGNED> id184x_1;

    switch((id184in_sel.getValueAsLong())) {
      case 0l:
        id184x_1 = id184in_option0;
        break;
      case 1l:
        id184x_1 = id184in_option1;
        break;
      default:
        id184x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id184out_result = (id184x_1);
  }
  { // Node ID: 3683 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3683in_input = id184out_result;

    id3683out_output[(getCycle()+1)%2] = id3683in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id170out_output;

  { // Node ID: 170 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id170in_input = id3685out_output[getCycle()%2];

    id170out_output = id170in_input;
  }
  { // Node ID: 3345 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2621out_result;

  { // Node ID: 2621 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2621in_a = id3345out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2621in_b = id3459out_output[getCycle()%2];

    id2621out_result = (eq_fixed(id2621in_a,id2621in_b));
  }
  { // Node ID: 3686 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3686in_input = id2621out_result;

    id3686out_output[(getCycle()+1)%2] = id3686in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id169out_o;

  { // Node ID: 169 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id169in_i = id3686out_output[getCycle()%2];

    id169out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id169in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id171out_result;

  { // Node ID: 171 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id171in_a = id170out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id171in_b = id169out_o;

    id171out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id171in_a,id171in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id172out_result;

  { // Node ID: 172 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id172in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id172in_option0 = id171out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id172in_option1 = id169out_o;

    HWOffsetFix<32,0,UNSIGNED> id172x_1;

    switch((id172in_sel.getValueAsLong())) {
      case 0l:
        id172x_1 = id172in_option0;
        break;
      case 1l:
        id172x_1 = id172in_option1;
        break;
      default:
        id172x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id172out_result = (id172x_1);
  }
  { // Node ID: 3685 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3685in_input = id172out_result;

    id3685out_output[(getCycle()+1)%2] = id3685in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id158out_output;

  { // Node ID: 158 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id158in_input = id3687out_output[getCycle()%2];

    id158out_output = id158in_input;
  }
  { // Node ID: 3344 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2622out_result;

  { // Node ID: 2622 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2622in_a = id3344out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2622in_b = id74out_o[getCycle()%8];

    id2622out_result = (eq_fixed(id2622in_a,id2622in_b));
  }
  { // Node ID: 3688 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3688in_input = id2622out_result;

    id3688out_output[(getCycle()+2)%3] = id3688in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id157out_o;

  { // Node ID: 157 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_i = id3688out_output[getCycle()%3];

    id157out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id157in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id159out_result;

  { // Node ID: 159 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id159in_a = id158out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id159in_b = id157out_o;

    id159out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id159in_a,id159in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id160out_result;

  { // Node ID: 160 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id160in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id160in_option0 = id159out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id160in_option1 = id157out_o;

    HWOffsetFix<32,0,UNSIGNED> id160x_1;

    switch((id160in_sel.getValueAsLong())) {
      case 0l:
        id160x_1 = id160in_option0;
        break;
      case 1l:
        id160x_1 = id160in_option1;
        break;
      default:
        id160x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id160out_result = (id160x_1);
  }
  { // Node ID: 3687 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3687in_input = id160out_result;

    id3687out_output[(getCycle()+1)%2] = id3687in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id146out_output;

  { // Node ID: 146 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id146in_input = id3689out_output[getCycle()%2];

    id146out_output = id146in_input;
  }
  { // Node ID: 3343 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2623out_result;

  { // Node ID: 2623 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2623in_a = id3343out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2623in_b = id74out_o[getCycle()%8];

    id2623out_result = (eq_fixed(id2623in_a,id2623in_b));
  }
  { // Node ID: 3690 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3690in_input = id2623out_result;

    id3690out_output[(getCycle()+2)%3] = id3690in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id145out_o;

  { // Node ID: 145 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id145in_i = id3690out_output[getCycle()%3];

    id145out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id145in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id147out_result;

  { // Node ID: 147 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id147in_a = id146out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id147in_b = id145out_o;

    id147out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id147in_a,id147in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id148out_result;

  { // Node ID: 148 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id148in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id148in_option0 = id147out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id148in_option1 = id145out_o;

    HWOffsetFix<32,0,UNSIGNED> id148x_1;

    switch((id148in_sel.getValueAsLong())) {
      case 0l:
        id148x_1 = id148in_option0;
        break;
      case 1l:
        id148x_1 = id148in_option1;
        break;
      default:
        id148x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id148out_result = (id148x_1);
  }
  { // Node ID: 3689 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3689in_input = id148out_result;

    id3689out_output[(getCycle()+1)%2] = id3689in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id134out_output;

  { // Node ID: 134 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id134in_input = id3691out_output[getCycle()%2];

    id134out_output = id134in_input;
  }
  { // Node ID: 3342 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2624out_result;

  { // Node ID: 2624 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2624in_a = id3342out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2624in_b = id74out_o[getCycle()%8];

    id2624out_result = (eq_fixed(id2624in_a,id2624in_b));
  }
  { // Node ID: 3692 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3692in_input = id2624out_result;

    id3692out_output[(getCycle()+2)%3] = id3692in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id133out_o;

  { // Node ID: 133 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id133in_i = id3692out_output[getCycle()%3];

    id133out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id133in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id135out_result;

  { // Node ID: 135 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id135in_a = id134out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id135in_b = id133out_o;

    id135out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id135in_a,id135in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id136out_result;

  { // Node ID: 136 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id136in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id136in_option0 = id135out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id136in_option1 = id133out_o;

    HWOffsetFix<32,0,UNSIGNED> id136x_1;

    switch((id136in_sel.getValueAsLong())) {
      case 0l:
        id136x_1 = id136in_option0;
        break;
      case 1l:
        id136x_1 = id136in_option1;
        break;
      default:
        id136x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id136out_result = (id136x_1);
  }
  { // Node ID: 3691 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3691in_input = id136out_result;

    id3691out_output[(getCycle()+1)%2] = id3691in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id122out_output;

  { // Node ID: 122 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id122in_input = id3693out_output[getCycle()%2];

    id122out_output = id122in_input;
  }
  { // Node ID: 3341 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2625out_result;

  { // Node ID: 2625 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2625in_a = id3341out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2625in_b = id74out_o[getCycle()%8];

    id2625out_result = (eq_fixed(id2625in_a,id2625in_b));
  }
  { // Node ID: 3694 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3694in_input = id2625out_result;

    id3694out_output[(getCycle()+2)%3] = id3694in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id121out_o;

  { // Node ID: 121 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id121in_i = id3694out_output[getCycle()%3];

    id121out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id121in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id123out_result;

  { // Node ID: 123 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id123in_a = id122out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id123in_b = id121out_o;

    id123out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id123in_a,id123in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id124out_result;

  { // Node ID: 124 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id124in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id124in_option0 = id123out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id124in_option1 = id121out_o;

    HWOffsetFix<32,0,UNSIGNED> id124x_1;

    switch((id124in_sel.getValueAsLong())) {
      case 0l:
        id124x_1 = id124in_option0;
        break;
      case 1l:
        id124x_1 = id124in_option1;
        break;
      default:
        id124x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id124out_result = (id124x_1);
  }
  { // Node ID: 3693 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3693in_input = id124out_result;

    id3693out_output[(getCycle()+1)%2] = id3693in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id110out_output;

  { // Node ID: 110 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id110in_input = id3695out_output[getCycle()%2];

    id110out_output = id110in_input;
  }
  { // Node ID: 3340 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2626out_result;

  { // Node ID: 2626 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2626in_a = id3340out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2626in_b = id74out_o[getCycle()%8];

    id2626out_result = (eq_fixed(id2626in_a,id2626in_b));
  }
  { // Node ID: 3696 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3696in_input = id2626out_result;

    id3696out_output[(getCycle()+2)%3] = id3696in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id109out_o;

  { // Node ID: 109 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id109in_i = id3696out_output[getCycle()%3];

    id109out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id109in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id111out_result;

  { // Node ID: 111 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id111in_a = id110out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id111in_b = id109out_o;

    id111out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id111in_a,id111in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id112out_result;

  { // Node ID: 112 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id112in_option0 = id111out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id112in_option1 = id109out_o;

    HWOffsetFix<32,0,UNSIGNED> id112x_1;

    switch((id112in_sel.getValueAsLong())) {
      case 0l:
        id112x_1 = id112in_option0;
        break;
      case 1l:
        id112x_1 = id112in_option1;
        break;
      default:
        id112x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id112out_result = (id112x_1);
  }
  { // Node ID: 3695 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3695in_input = id112out_result;

    id3695out_output[(getCycle()+1)%2] = id3695in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id98out_output;

  { // Node ID: 98 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id98in_input = id3697out_output[getCycle()%2];

    id98out_output = id98in_input;
  }
  { // Node ID: 3339 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2627out_result;

  { // Node ID: 2627 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2627in_a = id3339out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2627in_b = id74out_o[getCycle()%8];

    id2627out_result = (eq_fixed(id2627in_a,id2627in_b));
  }
  { // Node ID: 3698 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3698in_input = id2627out_result;

    id3698out_output[(getCycle()+2)%3] = id3698in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id97out_o;

  { // Node ID: 97 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id97in_i = id3698out_output[getCycle()%3];

    id97out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id97in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id99out_result;

  { // Node ID: 99 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id99in_a = id98out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id99in_b = id97out_o;

    id99out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id99in_a,id99in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id100out_result;

  { // Node ID: 100 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id100in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id100in_option0 = id99out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id100in_option1 = id97out_o;

    HWOffsetFix<32,0,UNSIGNED> id100x_1;

    switch((id100in_sel.getValueAsLong())) {
      case 0l:
        id100x_1 = id100in_option0;
        break;
      case 1l:
        id100x_1 = id100in_option1;
        break;
      default:
        id100x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id100out_result = (id100x_1);
  }
  { // Node ID: 3697 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3697in_input = id100out_result;

    id3697out_output[(getCycle()+1)%2] = id3697in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id86out_output;

  { // Node ID: 86 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id86in_input = id3699out_output[getCycle()%2];

    id86out_output = id86in_input;
  }
  { // Node ID: 3338 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2628out_result;

  { // Node ID: 2628 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2628in_a = id3338out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2628in_b = id74out_o[getCycle()%8];

    id2628out_result = (eq_fixed(id2628in_a,id2628in_b));
  }
  { // Node ID: 3700 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3700in_input = id2628out_result;

    id3700out_output[(getCycle()+2)%3] = id3700in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id85out_o;

  { // Node ID: 85 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id85in_i = id3700out_output[getCycle()%3];

    id85out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id85in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id87out_result;

  { // Node ID: 87 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id87in_a = id86out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id87in_b = id85out_o;

    id87out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id87in_a,id87in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id88out_result;

  { // Node ID: 88 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id88in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id88in_option0 = id87out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id88in_option1 = id85out_o;

    HWOffsetFix<32,0,UNSIGNED> id88x_1;

    switch((id88in_sel.getValueAsLong())) {
      case 0l:
        id88x_1 = id88in_option0;
        break;
      case 1l:
        id88x_1 = id88in_option1;
        break;
      default:
        id88x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id88out_result = (id88x_1);
  }
  { // Node ID: 3699 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3699in_input = id88out_result;

    id3699out_output[(getCycle()+1)%2] = id3699in_input;
  }
  { // Node ID: 3703 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3703in_input = id76out_output;

    id3703out_output[(getCycle()+10)%11] = id3703in_input;
  }
  { // Node ID: 3337 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2629out_result;

  { // Node ID: 2629 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2629in_a = id3337out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2629in_b = id3460out_output[getCycle()%2];

    id2629out_result = (eq_fixed(id2629in_a,id2629in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1885out_o;

  { // Node ID: 1885 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1885in_i = id2629out_result;

    id1885out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1885in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1887out_result;

  { // Node ID: 1887 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1887in_a = id3702out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1887in_b = id1885out_o;

    id1887out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1887in_a,id1887in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1888out_result;

  { // Node ID: 1888 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1888in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1888in_option0 = id1887out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1888in_option1 = id1885out_o;

    HWOffsetFix<32,0,UNSIGNED> id1888x_1;

    switch((id1888in_sel.getValueAsLong())) {
      case 0l:
        id1888x_1 = id1888in_option0;
        break;
      case 1l:
        id1888x_1 = id1888in_option1;
        break;
      default:
        id1888x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1888out_result = (id1888x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1886out_output;

  { // Node ID: 1886 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1886in_input = id1888out_result;

    id1886out_output = id1886in_input;
  }
  { // Node ID: 3702 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3702in_input = id1886out_output;

    id3702out_output[(getCycle()+1)%2] = id3702in_input;
  }
  { // Node ID: 15 (NodeDiv)
    const HWFloat<8,24> &id15in_a = id12out_output;
    const HWFloat<8,24> &id15in_b = id14out_output;

    id15out_result[(getCycle()+28)%29] = (div_float(id15in_a,id15in_b));
  }
  { // Node ID: 3336 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeAdd)
    const HWFloat<8,24> &id18in_a = id15out_result[getCycle()%29];
    const HWFloat<8,24> &id18in_b = id3336out_value;

    id18out_result[(getCycle()+11)%12] = (add_float(id18in_a,id18in_b));
  }
  { // Node ID: 3335 (NodeConstantRawBits)
  }
  { // Node ID: 20 (NodeMul)
    const HWFloat<8,24> &id20in_a = id18out_result[getCycle()%12];
    const HWFloat<8,24> &id20in_b = id3335out_value;

    id20out_result[(getCycle()+8)%9] = (mul_float(id20in_a,id20in_b));
  }
  { // Node ID: 21 (NodeCast)
    const HWFloat<8,24> &id21in_i = id20out_result[getCycle()%9];

    id21out_o[(getCycle()+7)%8] = (cast_float2fixed<32,0,UNSIGNED,TONEAREVEN>(id21in_i));
  }
  { // Node ID: 3701 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3701in_input = id21out_o[getCycle()%8];

    id3701out_output[(getCycle()+53)%54] = id3701in_input;
  }
  { // Node ID: 3465 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3465in_input = id3701out_output[getCycle()%54];

    id3465out_output[(getCycle()+1)%2] = id3465in_input;
  }
  { // Node ID: 3464 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3464in_input = id3465out_output[getCycle()%2];

    id3464out_output[(getCycle()+1)%2] = id3464in_input;
  }
  { // Node ID: 3463 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3463in_input = id3464out_output[getCycle()%2];

    id3463out_output[(getCycle()+1)%2] = id3463in_input;
  }
  { // Node ID: 3462 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3462in_input = id3463out_output[getCycle()%2];

    id3462out_output[(getCycle()+1)%2] = id3462in_input;
  }
  { // Node ID: 3461 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3461in_input = id3462out_output[getCycle()%2];

    id3461out_output[(getCycle()+1)%2] = id3461in_input;
  }
  { // Node ID: 3460 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3460in_input = id3461out_output[getCycle()%2];

    id3460out_output[(getCycle()+1)%2] = id3460in_input;
  }
  { // Node ID: 3334 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2630out_result;

  { // Node ID: 2630 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2630in_a = id3334out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2630in_b = id3460out_output[getCycle()%2];

    id2630out_result = (eq_fixed(id2630in_a,id2630in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1879out_o;

  { // Node ID: 1879 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1879in_i = id2630out_result;

    id1879out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1879in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1881out_result;

  { // Node ID: 1881 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1881in_a = id3704out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1881in_b = id1879out_o;

    id1881out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1881in_a,id1881in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1882out_result;

  { // Node ID: 1882 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1882in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1882in_option0 = id1881out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1882in_option1 = id1879out_o;

    HWOffsetFix<32,0,UNSIGNED> id1882x_1;

    switch((id1882in_sel.getValueAsLong())) {
      case 0l:
        id1882x_1 = id1882in_option0;
        break;
      case 1l:
        id1882x_1 = id1882in_option1;
        break;
      default:
        id1882x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1882out_result = (id1882x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1880out_output;

  { // Node ID: 1880 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1880in_input = id1882out_result;

    id1880out_output = id1880in_input;
  }
  { // Node ID: 3704 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3704in_input = id1880out_output;

    id3704out_output[(getCycle()+1)%2] = id3704in_input;
  }
  { // Node ID: 3333 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2631out_result;

  { // Node ID: 2631 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2631in_a = id3333out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2631in_b = id3460out_output[getCycle()%2];

    id2631out_result = (eq_fixed(id2631in_a,id2631in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1873out_o;

  { // Node ID: 1873 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1873in_i = id2631out_result;

    id1873out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1873in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1875out_result;

  { // Node ID: 1875 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1875in_a = id3706out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1875in_b = id1873out_o;

    id1875out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1875in_a,id1875in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1876out_result;

  { // Node ID: 1876 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1876in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1876in_option0 = id1875out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1876in_option1 = id1873out_o;

    HWOffsetFix<32,0,UNSIGNED> id1876x_1;

    switch((id1876in_sel.getValueAsLong())) {
      case 0l:
        id1876x_1 = id1876in_option0;
        break;
      case 1l:
        id1876x_1 = id1876in_option1;
        break;
      default:
        id1876x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1876out_result = (id1876x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1874out_output;

  { // Node ID: 1874 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1874in_input = id1876out_result;

    id1874out_output = id1874in_input;
  }
  { // Node ID: 3706 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3706in_input = id1874out_output;

    id3706out_output[(getCycle()+1)%2] = id3706in_input;
  }
  { // Node ID: 3332 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2632out_result;

  { // Node ID: 2632 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2632in_a = id3332out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2632in_b = id3460out_output[getCycle()%2];

    id2632out_result = (eq_fixed(id2632in_a,id2632in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1867out_o;

  { // Node ID: 1867 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1867in_i = id2632out_result;

    id1867out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1867in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1869out_result;

  { // Node ID: 1869 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1869in_a = id3708out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1869in_b = id1867out_o;

    id1869out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1869in_a,id1869in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1870out_result;

  { // Node ID: 1870 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1870in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1870in_option0 = id1869out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1870in_option1 = id1867out_o;

    HWOffsetFix<32,0,UNSIGNED> id1870x_1;

    switch((id1870in_sel.getValueAsLong())) {
      case 0l:
        id1870x_1 = id1870in_option0;
        break;
      case 1l:
        id1870x_1 = id1870in_option1;
        break;
      default:
        id1870x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1870out_result = (id1870x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1868out_output;

  { // Node ID: 1868 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1868in_input = id1870out_result;

    id1868out_output = id1868in_input;
  }
  { // Node ID: 3708 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3708in_input = id1868out_output;

    id3708out_output[(getCycle()+1)%2] = id3708in_input;
  }
  { // Node ID: 3331 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2633out_result;

  { // Node ID: 2633 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2633in_a = id3331out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2633in_b = id3460out_output[getCycle()%2];

    id2633out_result = (eq_fixed(id2633in_a,id2633in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1861out_o;

  { // Node ID: 1861 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1861in_i = id2633out_result;

    id1861out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1861in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1863out_result;

  { // Node ID: 1863 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1863in_a = id3710out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1863in_b = id1861out_o;

    id1863out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1863in_a,id1863in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1864out_result;

  { // Node ID: 1864 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1864in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1864in_option0 = id1863out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1864in_option1 = id1861out_o;

    HWOffsetFix<32,0,UNSIGNED> id1864x_1;

    switch((id1864in_sel.getValueAsLong())) {
      case 0l:
        id1864x_1 = id1864in_option0;
        break;
      case 1l:
        id1864x_1 = id1864in_option1;
        break;
      default:
        id1864x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1864out_result = (id1864x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1862out_output;

  { // Node ID: 1862 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1862in_input = id1864out_result;

    id1862out_output = id1862in_input;
  }
  { // Node ID: 3710 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3710in_input = id1862out_output;

    id3710out_output[(getCycle()+1)%2] = id3710in_input;
  }
  { // Node ID: 3330 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2634out_result;

  { // Node ID: 2634 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2634in_a = id3330out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2634in_b = id3460out_output[getCycle()%2];

    id2634out_result = (eq_fixed(id2634in_a,id2634in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1855out_o;

  { // Node ID: 1855 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1855in_i = id2634out_result;

    id1855out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1855in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1857out_result;

  { // Node ID: 1857 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1857in_a = id3712out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1857in_b = id1855out_o;

    id1857out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1857in_a,id1857in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1858out_result;

  { // Node ID: 1858 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1858in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1858in_option0 = id1857out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1858in_option1 = id1855out_o;

    HWOffsetFix<32,0,UNSIGNED> id1858x_1;

    switch((id1858in_sel.getValueAsLong())) {
      case 0l:
        id1858x_1 = id1858in_option0;
        break;
      case 1l:
        id1858x_1 = id1858in_option1;
        break;
      default:
        id1858x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1858out_result = (id1858x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1856out_output;

  { // Node ID: 1856 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1856in_input = id1858out_result;

    id1856out_output = id1856in_input;
  }
  { // Node ID: 3712 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3712in_input = id1856out_output;

    id3712out_output[(getCycle()+1)%2] = id3712in_input;
  }
  { // Node ID: 3329 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2635out_result;

  { // Node ID: 2635 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2635in_a = id3329out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2635in_b = id3460out_output[getCycle()%2];

    id2635out_result = (eq_fixed(id2635in_a,id2635in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1849out_o;

  { // Node ID: 1849 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1849in_i = id2635out_result;

    id1849out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1849in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1851out_result;

  { // Node ID: 1851 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1851in_a = id3714out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1851in_b = id1849out_o;

    id1851out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1851in_a,id1851in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1852out_result;

  { // Node ID: 1852 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1852in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1852in_option0 = id1851out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1852in_option1 = id1849out_o;

    HWOffsetFix<32,0,UNSIGNED> id1852x_1;

    switch((id1852in_sel.getValueAsLong())) {
      case 0l:
        id1852x_1 = id1852in_option0;
        break;
      case 1l:
        id1852x_1 = id1852in_option1;
        break;
      default:
        id1852x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1852out_result = (id1852x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1850out_output;

  { // Node ID: 1850 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1850in_input = id1852out_result;

    id1850out_output = id1850in_input;
  }
  { // Node ID: 3714 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3714in_input = id1850out_output;

    id3714out_output[(getCycle()+1)%2] = id3714in_input;
  }
  { // Node ID: 3328 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2636out_result;

  { // Node ID: 2636 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2636in_a = id3328out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2636in_b = id3460out_output[getCycle()%2];

    id2636out_result = (eq_fixed(id2636in_a,id2636in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1843out_o;

  { // Node ID: 1843 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1843in_i = id2636out_result;

    id1843out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1843in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1845out_result;

  { // Node ID: 1845 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1845in_a = id3716out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1845in_b = id1843out_o;

    id1845out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1845in_a,id1845in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1846out_result;

  { // Node ID: 1846 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1846in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1846in_option0 = id1845out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1846in_option1 = id1843out_o;

    HWOffsetFix<32,0,UNSIGNED> id1846x_1;

    switch((id1846in_sel.getValueAsLong())) {
      case 0l:
        id1846x_1 = id1846in_option0;
        break;
      case 1l:
        id1846x_1 = id1846in_option1;
        break;
      default:
        id1846x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1846out_result = (id1846x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1844out_output;

  { // Node ID: 1844 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1844in_input = id1846out_result;

    id1844out_output = id1844in_input;
  }
  { // Node ID: 3716 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3716in_input = id1844out_output;

    id3716out_output[(getCycle()+1)%2] = id3716in_input;
  }
  { // Node ID: 3327 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2637out_result;

  { // Node ID: 2637 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2637in_a = id3327out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2637in_b = id3460out_output[getCycle()%2];

    id2637out_result = (eq_fixed(id2637in_a,id2637in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1837out_o;

  { // Node ID: 1837 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1837in_i = id2637out_result;

    id1837out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1837in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1839out_result;

  { // Node ID: 1839 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1839in_a = id3718out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1839in_b = id1837out_o;

    id1839out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1839in_a,id1839in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1840out_result;

  { // Node ID: 1840 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1840in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1840in_option0 = id1839out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1840in_option1 = id1837out_o;

    HWOffsetFix<32,0,UNSIGNED> id1840x_1;

    switch((id1840in_sel.getValueAsLong())) {
      case 0l:
        id1840x_1 = id1840in_option0;
        break;
      case 1l:
        id1840x_1 = id1840in_option1;
        break;
      default:
        id1840x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1840out_result = (id1840x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1838out_output;

  { // Node ID: 1838 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1838in_input = id1840out_result;

    id1838out_output = id1838in_input;
  }
  { // Node ID: 3718 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3718in_input = id1838out_output;

    id3718out_output[(getCycle()+1)%2] = id3718in_input;
  }
  { // Node ID: 3326 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2638out_result;

  { // Node ID: 2638 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2638in_a = id3326out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2638in_b = id3460out_output[getCycle()%2];

    id2638out_result = (eq_fixed(id2638in_a,id2638in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1831out_o;

  { // Node ID: 1831 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1831in_i = id2638out_result;

    id1831out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1831in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1833out_result;

  { // Node ID: 1833 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1833in_a = id3720out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1833in_b = id1831out_o;

    id1833out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1833in_a,id1833in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1834out_result;

  { // Node ID: 1834 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1834in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1834in_option0 = id1833out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1834in_option1 = id1831out_o;

    HWOffsetFix<32,0,UNSIGNED> id1834x_1;

    switch((id1834in_sel.getValueAsLong())) {
      case 0l:
        id1834x_1 = id1834in_option0;
        break;
      case 1l:
        id1834x_1 = id1834in_option1;
        break;
      default:
        id1834x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1834out_result = (id1834x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1832out_output;

  { // Node ID: 1832 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1832in_input = id1834out_result;

    id1832out_output = id1832in_input;
  }
  { // Node ID: 3720 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3720in_input = id1832out_output;

    id3720out_output[(getCycle()+1)%2] = id3720in_input;
  }
  { // Node ID: 3325 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2639out_result;

  { // Node ID: 2639 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2639in_a = id3325out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2639in_b = id3460out_output[getCycle()%2];

    id2639out_result = (eq_fixed(id2639in_a,id2639in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1825out_o;

  { // Node ID: 1825 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1825in_i = id2639out_result;

    id1825out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1825in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1827out_result;

  { // Node ID: 1827 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1827in_a = id3722out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1827in_b = id1825out_o;

    id1827out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1827in_a,id1827in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1828out_result;

  { // Node ID: 1828 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1828in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1828in_option0 = id1827out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1828in_option1 = id1825out_o;

    HWOffsetFix<32,0,UNSIGNED> id1828x_1;

    switch((id1828in_sel.getValueAsLong())) {
      case 0l:
        id1828x_1 = id1828in_option0;
        break;
      case 1l:
        id1828x_1 = id1828in_option1;
        break;
      default:
        id1828x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1828out_result = (id1828x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1826out_output;

  { // Node ID: 1826 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1826in_input = id1828out_result;

    id1826out_output = id1826in_input;
  }
  { // Node ID: 3722 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3722in_input = id1826out_output;

    id3722out_output[(getCycle()+1)%2] = id3722in_input;
  }
  { // Node ID: 3324 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2640out_result;

  { // Node ID: 2640 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2640in_a = id3324out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2640in_b = id3460out_output[getCycle()%2];

    id2640out_result = (eq_fixed(id2640in_a,id2640in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1819out_o;

  { // Node ID: 1819 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1819in_i = id2640out_result;

    id1819out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1819in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1821out_result;

  { // Node ID: 1821 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1821in_a = id3724out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1821in_b = id1819out_o;

    id1821out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1821in_a,id1821in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1822out_result;

  { // Node ID: 1822 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1822in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1822in_option0 = id1821out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1822in_option1 = id1819out_o;

    HWOffsetFix<32,0,UNSIGNED> id1822x_1;

    switch((id1822in_sel.getValueAsLong())) {
      case 0l:
        id1822x_1 = id1822in_option0;
        break;
      case 1l:
        id1822x_1 = id1822in_option1;
        break;
      default:
        id1822x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1822out_result = (id1822x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1820out_output;

  { // Node ID: 1820 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1820in_input = id1822out_result;

    id1820out_output = id1820in_input;
  }
  { // Node ID: 3724 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3724in_input = id1820out_output;

    id3724out_output[(getCycle()+1)%2] = id3724in_input;
  }
  { // Node ID: 3323 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2641out_result;

  { // Node ID: 2641 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2641in_a = id3323out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2641in_b = id3460out_output[getCycle()%2];

    id2641out_result = (eq_fixed(id2641in_a,id2641in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1813out_o;

  { // Node ID: 1813 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1813in_i = id2641out_result;

    id1813out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1813in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1815out_result;

  { // Node ID: 1815 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1815in_a = id3726out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1815in_b = id1813out_o;

    id1815out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1815in_a,id1815in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1816out_result;

  { // Node ID: 1816 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1816in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1816in_option0 = id1815out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1816in_option1 = id1813out_o;

    HWOffsetFix<32,0,UNSIGNED> id1816x_1;

    switch((id1816in_sel.getValueAsLong())) {
      case 0l:
        id1816x_1 = id1816in_option0;
        break;
      case 1l:
        id1816x_1 = id1816in_option1;
        break;
      default:
        id1816x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1816out_result = (id1816x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1814out_output;

  { // Node ID: 1814 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1814in_input = id1816out_result;

    id1814out_output = id1814in_input;
  }
  { // Node ID: 3726 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3726in_input = id1814out_output;

    id3726out_output[(getCycle()+1)%2] = id3726in_input;
  }
  { // Node ID: 3322 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2642out_result;

  { // Node ID: 2642 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2642in_a = id3322out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2642in_b = id3460out_output[getCycle()%2];

    id2642out_result = (eq_fixed(id2642in_a,id2642in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1807out_o;

  { // Node ID: 1807 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1807in_i = id2642out_result;

    id1807out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1807in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1809out_result;

  { // Node ID: 1809 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1809in_a = id3728out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1809in_b = id1807out_o;

    id1809out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1809in_a,id1809in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1810out_result;

  { // Node ID: 1810 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1810in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1810in_option0 = id1809out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1810in_option1 = id1807out_o;

    HWOffsetFix<32,0,UNSIGNED> id1810x_1;

    switch((id1810in_sel.getValueAsLong())) {
      case 0l:
        id1810x_1 = id1810in_option0;
        break;
      case 1l:
        id1810x_1 = id1810in_option1;
        break;
      default:
        id1810x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1810out_result = (id1810x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1808out_output;

  { // Node ID: 1808 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1808in_input = id1810out_result;

    id1808out_output = id1808in_input;
  }
  { // Node ID: 3728 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3728in_input = id1808out_output;

    id3728out_output[(getCycle()+1)%2] = id3728in_input;
  }
  { // Node ID: 3321 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2643out_result;

  { // Node ID: 2643 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2643in_a = id3321out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2643in_b = id3460out_output[getCycle()%2];

    id2643out_result = (eq_fixed(id2643in_a,id2643in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1801out_o;

  { // Node ID: 1801 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1801in_i = id2643out_result;

    id1801out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1801in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1803out_result;

  { // Node ID: 1803 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1803in_a = id3730out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1803in_b = id1801out_o;

    id1803out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1803in_a,id1803in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1804out_result;

  { // Node ID: 1804 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1804in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1804in_option0 = id1803out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1804in_option1 = id1801out_o;

    HWOffsetFix<32,0,UNSIGNED> id1804x_1;

    switch((id1804in_sel.getValueAsLong())) {
      case 0l:
        id1804x_1 = id1804in_option0;
        break;
      case 1l:
        id1804x_1 = id1804in_option1;
        break;
      default:
        id1804x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1804out_result = (id1804x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1802out_output;

  { // Node ID: 1802 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1802in_input = id1804out_result;

    id1802out_output = id1802in_input;
  }
  { // Node ID: 3730 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3730in_input = id1802out_output;

    id3730out_output[(getCycle()+1)%2] = id3730in_input;
  }
  { // Node ID: 3320 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2644out_result;

  { // Node ID: 2644 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2644in_a = id3320out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2644in_b = id3460out_output[getCycle()%2];

    id2644out_result = (eq_fixed(id2644in_a,id2644in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1795out_o;

  { // Node ID: 1795 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1795in_i = id2644out_result;

    id1795out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1795in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1797out_result;

  { // Node ID: 1797 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1797in_a = id3732out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1797in_b = id1795out_o;

    id1797out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1797in_a,id1797in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1798out_result;

  { // Node ID: 1798 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1798in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1798in_option0 = id1797out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1798in_option1 = id1795out_o;

    HWOffsetFix<32,0,UNSIGNED> id1798x_1;

    switch((id1798in_sel.getValueAsLong())) {
      case 0l:
        id1798x_1 = id1798in_option0;
        break;
      case 1l:
        id1798x_1 = id1798in_option1;
        break;
      default:
        id1798x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1798out_result = (id1798x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1796out_output;

  { // Node ID: 1796 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1796in_input = id1798out_result;

    id1796out_output = id1796in_input;
  }
  { // Node ID: 3732 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3732in_input = id1796out_output;

    id3732out_output[(getCycle()+1)%2] = id3732in_input;
  }
  { // Node ID: 3319 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2645out_result;

  { // Node ID: 2645 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2645in_a = id3319out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2645in_b = id3460out_output[getCycle()%2];

    id2645out_result = (eq_fixed(id2645in_a,id2645in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1789out_o;

  { // Node ID: 1789 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1789in_i = id2645out_result;

    id1789out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1789in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1791out_result;

  { // Node ID: 1791 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1791in_a = id3734out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1791in_b = id1789out_o;

    id1791out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1791in_a,id1791in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1792out_result;

  { // Node ID: 1792 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1792in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1792in_option0 = id1791out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1792in_option1 = id1789out_o;

    HWOffsetFix<32,0,UNSIGNED> id1792x_1;

    switch((id1792in_sel.getValueAsLong())) {
      case 0l:
        id1792x_1 = id1792in_option0;
        break;
      case 1l:
        id1792x_1 = id1792in_option1;
        break;
      default:
        id1792x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1792out_result = (id1792x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1790out_output;

  { // Node ID: 1790 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1790in_input = id1792out_result;

    id1790out_output = id1790in_input;
  }
  { // Node ID: 3734 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3734in_input = id1790out_output;

    id3734out_output[(getCycle()+1)%2] = id3734in_input;
  }
  { // Node ID: 3318 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2646out_result;

  { // Node ID: 2646 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2646in_a = id3318out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2646in_b = id3460out_output[getCycle()%2];

    id2646out_result = (eq_fixed(id2646in_a,id2646in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1783out_o;

  { // Node ID: 1783 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1783in_i = id2646out_result;

    id1783out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1783in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1785out_result;

  { // Node ID: 1785 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1785in_a = id3736out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1785in_b = id1783out_o;

    id1785out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1785in_a,id1785in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1786out_result;

  { // Node ID: 1786 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1786in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1786in_option0 = id1785out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1786in_option1 = id1783out_o;

    HWOffsetFix<32,0,UNSIGNED> id1786x_1;

    switch((id1786in_sel.getValueAsLong())) {
      case 0l:
        id1786x_1 = id1786in_option0;
        break;
      case 1l:
        id1786x_1 = id1786in_option1;
        break;
      default:
        id1786x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1786out_result = (id1786x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1784out_output;

  { // Node ID: 1784 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1784in_input = id1786out_result;

    id1784out_output = id1784in_input;
  }
  { // Node ID: 3736 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3736in_input = id1784out_output;

    id3736out_output[(getCycle()+1)%2] = id3736in_input;
  }
  { // Node ID: 3317 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2647out_result;

  { // Node ID: 2647 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2647in_a = id3317out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2647in_b = id3460out_output[getCycle()%2];

    id2647out_result = (eq_fixed(id2647in_a,id2647in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1777out_o;

  { // Node ID: 1777 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1777in_i = id2647out_result;

    id1777out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1777in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1779out_result;

  { // Node ID: 1779 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1779in_a = id3738out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1779in_b = id1777out_o;

    id1779out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1779in_a,id1779in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1780out_result;

  { // Node ID: 1780 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1780in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1780in_option0 = id1779out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1780in_option1 = id1777out_o;

    HWOffsetFix<32,0,UNSIGNED> id1780x_1;

    switch((id1780in_sel.getValueAsLong())) {
      case 0l:
        id1780x_1 = id1780in_option0;
        break;
      case 1l:
        id1780x_1 = id1780in_option1;
        break;
      default:
        id1780x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1780out_result = (id1780x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1778out_output;

  { // Node ID: 1778 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1778in_input = id1780out_result;

    id1778out_output = id1778in_input;
  }
  { // Node ID: 3738 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3738in_input = id1778out_output;

    id3738out_output[(getCycle()+1)%2] = id3738in_input;
  }
  { // Node ID: 3316 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2648out_result;

  { // Node ID: 2648 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2648in_a = id3316out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2648in_b = id3460out_output[getCycle()%2];

    id2648out_result = (eq_fixed(id2648in_a,id2648in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1771out_o;

  { // Node ID: 1771 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1771in_i = id2648out_result;

    id1771out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1771in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1773out_result;

  { // Node ID: 1773 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1773in_a = id3740out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1773in_b = id1771out_o;

    id1773out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1773in_a,id1773in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1774out_result;

  { // Node ID: 1774 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1774in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1774in_option0 = id1773out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1774in_option1 = id1771out_o;

    HWOffsetFix<32,0,UNSIGNED> id1774x_1;

    switch((id1774in_sel.getValueAsLong())) {
      case 0l:
        id1774x_1 = id1774in_option0;
        break;
      case 1l:
        id1774x_1 = id1774in_option1;
        break;
      default:
        id1774x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1774out_result = (id1774x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1772out_output;

  { // Node ID: 1772 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1772in_input = id1774out_result;

    id1772out_output = id1772in_input;
  }
  { // Node ID: 3740 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3740in_input = id1772out_output;

    id3740out_output[(getCycle()+1)%2] = id3740in_input;
  }
  { // Node ID: 3315 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2649out_result;

  { // Node ID: 2649 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2649in_a = id3315out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2649in_b = id3460out_output[getCycle()%2];

    id2649out_result = (eq_fixed(id2649in_a,id2649in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1765out_o;

  { // Node ID: 1765 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1765in_i = id2649out_result;

    id1765out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1765in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1767out_result;

  { // Node ID: 1767 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1767in_a = id3742out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1767in_b = id1765out_o;

    id1767out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1767in_a,id1767in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1768out_result;

  { // Node ID: 1768 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1768in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1768in_option0 = id1767out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1768in_option1 = id1765out_o;

    HWOffsetFix<32,0,UNSIGNED> id1768x_1;

    switch((id1768in_sel.getValueAsLong())) {
      case 0l:
        id1768x_1 = id1768in_option0;
        break;
      case 1l:
        id1768x_1 = id1768in_option1;
        break;
      default:
        id1768x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1768out_result = (id1768x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1766out_output;

  { // Node ID: 1766 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1766in_input = id1768out_result;

    id1766out_output = id1766in_input;
  }
  { // Node ID: 3742 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3742in_input = id1766out_output;

    id3742out_output[(getCycle()+1)%2] = id3742in_input;
  }
  { // Node ID: 3314 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2650out_result;

  { // Node ID: 2650 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2650in_a = id3314out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2650in_b = id3460out_output[getCycle()%2];

    id2650out_result = (eq_fixed(id2650in_a,id2650in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1759out_o;

  { // Node ID: 1759 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1759in_i = id2650out_result;

    id1759out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1759in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1761out_result;

  { // Node ID: 1761 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1761in_a = id3744out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1761in_b = id1759out_o;

    id1761out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1761in_a,id1761in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1762out_result;

  { // Node ID: 1762 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1762in_sel = id3703out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1762in_option0 = id1761out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1762in_option1 = id1759out_o;

    HWOffsetFix<32,0,UNSIGNED> id1762x_1;

    switch((id1762in_sel.getValueAsLong())) {
      case 0l:
        id1762x_1 = id1762in_option0;
        break;
      case 1l:
        id1762x_1 = id1762in_option1;
        break;
      default:
        id1762x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1762out_result = (id1762x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1760out_output;

  { // Node ID: 1760 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1760in_input = id1762out_result;

    id1760out_output = id1760in_input;
  }
  { // Node ID: 3744 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3744in_input = id1760out_output;

    id3744out_output[(getCycle()+1)%2] = id3744in_input;
  }
  { // Node ID: 3767 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3767in_input = id3456out_output[getCycle()%2];

    id3767out_output[(getCycle()+8)%9] = id3767in_input;
  }
  { // Node ID: 4479 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4479in_input = id3767out_output[getCycle()%9];

    id4479out_output[(getCycle()+1)%2] = id4479in_input;
  }
  { // Node ID: 3313 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2651out_result;

  { // Node ID: 2651 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2651in_a = id3313out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2651in_b = id3460out_output[getCycle()%2];

    id2651out_result = (eq_fixed(id2651in_a,id2651in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1753out_o;

  { // Node ID: 1753 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1753in_i = id2651out_result;

    id1753out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1753in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1755out_result;

  { // Node ID: 1755 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1755in_a = id3746out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1755in_b = id1753out_o;

    id1755out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1755in_a,id1755in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1756out_result;

  { // Node ID: 1756 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1756in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1756in_option0 = id1755out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1756in_option1 = id1753out_o;

    HWOffsetFix<32,0,UNSIGNED> id1756x_1;

    switch((id1756in_sel.getValueAsLong())) {
      case 0l:
        id1756x_1 = id1756in_option0;
        break;
      case 1l:
        id1756x_1 = id1756in_option1;
        break;
      default:
        id1756x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1756out_result = (id1756x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1754out_output;

  { // Node ID: 1754 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1754in_input = id1756out_result;

    id1754out_output = id1754in_input;
  }
  { // Node ID: 3746 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3746in_input = id1754out_output;

    id3746out_output[(getCycle()+1)%2] = id3746in_input;
  }
  { // Node ID: 3312 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2652out_result;

  { // Node ID: 2652 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2652in_a = id3312out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2652in_b = id3460out_output[getCycle()%2];

    id2652out_result = (eq_fixed(id2652in_a,id2652in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1747out_o;

  { // Node ID: 1747 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1747in_i = id2652out_result;

    id1747out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1747in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1749out_result;

  { // Node ID: 1749 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1749in_a = id3748out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1749in_b = id1747out_o;

    id1749out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1749in_a,id1749in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1750out_result;

  { // Node ID: 1750 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1750in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1750in_option0 = id1749out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1750in_option1 = id1747out_o;

    HWOffsetFix<32,0,UNSIGNED> id1750x_1;

    switch((id1750in_sel.getValueAsLong())) {
      case 0l:
        id1750x_1 = id1750in_option0;
        break;
      case 1l:
        id1750x_1 = id1750in_option1;
        break;
      default:
        id1750x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1750out_result = (id1750x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1748out_output;

  { // Node ID: 1748 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1748in_input = id1750out_result;

    id1748out_output = id1748in_input;
  }
  { // Node ID: 3748 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3748in_input = id1748out_output;

    id3748out_output[(getCycle()+1)%2] = id3748in_input;
  }
  { // Node ID: 3311 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2653out_result;

  { // Node ID: 2653 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2653in_a = id3311out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2653in_b = id3460out_output[getCycle()%2];

    id2653out_result = (eq_fixed(id2653in_a,id2653in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1741out_o;

  { // Node ID: 1741 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1741in_i = id2653out_result;

    id1741out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1741in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1743out_result;

  { // Node ID: 1743 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1743in_a = id3750out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1743in_b = id1741out_o;

    id1743out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1743in_a,id1743in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1744out_result;

  { // Node ID: 1744 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1744in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1744in_option0 = id1743out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1744in_option1 = id1741out_o;

    HWOffsetFix<32,0,UNSIGNED> id1744x_1;

    switch((id1744in_sel.getValueAsLong())) {
      case 0l:
        id1744x_1 = id1744in_option0;
        break;
      case 1l:
        id1744x_1 = id1744in_option1;
        break;
      default:
        id1744x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1744out_result = (id1744x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1742out_output;

  { // Node ID: 1742 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1742in_input = id1744out_result;

    id1742out_output = id1742in_input;
  }
  { // Node ID: 3750 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3750in_input = id1742out_output;

    id3750out_output[(getCycle()+1)%2] = id3750in_input;
  }
  { // Node ID: 3310 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2654out_result;

  { // Node ID: 2654 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2654in_a = id3310out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2654in_b = id3460out_output[getCycle()%2];

    id2654out_result = (eq_fixed(id2654in_a,id2654in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1735out_o;

  { // Node ID: 1735 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1735in_i = id2654out_result;

    id1735out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1735in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1737out_result;

  { // Node ID: 1737 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1737in_a = id3752out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1737in_b = id1735out_o;

    id1737out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1737in_a,id1737in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1738out_result;

  { // Node ID: 1738 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1738in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1738in_option0 = id1737out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1738in_option1 = id1735out_o;

    HWOffsetFix<32,0,UNSIGNED> id1738x_1;

    switch((id1738in_sel.getValueAsLong())) {
      case 0l:
        id1738x_1 = id1738in_option0;
        break;
      case 1l:
        id1738x_1 = id1738in_option1;
        break;
      default:
        id1738x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1738out_result = (id1738x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1736out_output;

  { // Node ID: 1736 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1736in_input = id1738out_result;

    id1736out_output = id1736in_input;
  }
  { // Node ID: 3752 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3752in_input = id1736out_output;

    id3752out_output[(getCycle()+1)%2] = id3752in_input;
  }
  { // Node ID: 3309 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2655out_result;

  { // Node ID: 2655 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2655in_a = id3309out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2655in_b = id3460out_output[getCycle()%2];

    id2655out_result = (eq_fixed(id2655in_a,id2655in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1729out_o;

  { // Node ID: 1729 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1729in_i = id2655out_result;

    id1729out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1729in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1731out_result;

  { // Node ID: 1731 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1731in_a = id3754out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1731in_b = id1729out_o;

    id1731out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1731in_a,id1731in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1732out_result;

  { // Node ID: 1732 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1732in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1732in_option0 = id1731out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1732in_option1 = id1729out_o;

    HWOffsetFix<32,0,UNSIGNED> id1732x_1;

    switch((id1732in_sel.getValueAsLong())) {
      case 0l:
        id1732x_1 = id1732in_option0;
        break;
      case 1l:
        id1732x_1 = id1732in_option1;
        break;
      default:
        id1732x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1732out_result = (id1732x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1730out_output;

  { // Node ID: 1730 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1730in_input = id1732out_result;

    id1730out_output = id1730in_input;
  }
  { // Node ID: 3754 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3754in_input = id1730out_output;

    id3754out_output[(getCycle()+1)%2] = id3754in_input;
  }
  { // Node ID: 3308 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2656out_result;

  { // Node ID: 2656 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2656in_a = id3308out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2656in_b = id3460out_output[getCycle()%2];

    id2656out_result = (eq_fixed(id2656in_a,id2656in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1723out_o;

  { // Node ID: 1723 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1723in_i = id2656out_result;

    id1723out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1723in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1725out_result;

  { // Node ID: 1725 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1725in_a = id3756out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1725in_b = id1723out_o;

    id1725out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1725in_a,id1725in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1726out_result;

  { // Node ID: 1726 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1726in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1726in_option0 = id1725out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1726in_option1 = id1723out_o;

    HWOffsetFix<32,0,UNSIGNED> id1726x_1;

    switch((id1726in_sel.getValueAsLong())) {
      case 0l:
        id1726x_1 = id1726in_option0;
        break;
      case 1l:
        id1726x_1 = id1726in_option1;
        break;
      default:
        id1726x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1726out_result = (id1726x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1724out_output;

  { // Node ID: 1724 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1724in_input = id1726out_result;

    id1724out_output = id1724in_input;
  }
  { // Node ID: 3756 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3756in_input = id1724out_output;

    id3756out_output[(getCycle()+1)%2] = id3756in_input;
  }
  { // Node ID: 3307 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2657out_result;

  { // Node ID: 2657 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2657in_a = id3307out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2657in_b = id3460out_output[getCycle()%2];

    id2657out_result = (eq_fixed(id2657in_a,id2657in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1717out_o;

  { // Node ID: 1717 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1717in_i = id2657out_result;

    id1717out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1717in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1719out_result;

  { // Node ID: 1719 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1719in_a = id3758out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1719in_b = id1717out_o;

    id1719out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1719in_a,id1719in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1720out_result;

  { // Node ID: 1720 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1720in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1720in_option0 = id1719out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1720in_option1 = id1717out_o;

    HWOffsetFix<32,0,UNSIGNED> id1720x_1;

    switch((id1720in_sel.getValueAsLong())) {
      case 0l:
        id1720x_1 = id1720in_option0;
        break;
      case 1l:
        id1720x_1 = id1720in_option1;
        break;
      default:
        id1720x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1720out_result = (id1720x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1718out_output;

  { // Node ID: 1718 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1718in_input = id1720out_result;

    id1718out_output = id1718in_input;
  }
  { // Node ID: 3758 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3758in_input = id1718out_output;

    id3758out_output[(getCycle()+1)%2] = id3758in_input;
  }
  { // Node ID: 3306 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2658out_result;

  { // Node ID: 2658 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2658in_a = id3306out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2658in_b = id3460out_output[getCycle()%2];

    id2658out_result = (eq_fixed(id2658in_a,id2658in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1711out_o;

  { // Node ID: 1711 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1711in_i = id2658out_result;

    id1711out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1711in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1713out_result;

  { // Node ID: 1713 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1713in_a = id3760out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1713in_b = id1711out_o;

    id1713out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1713in_a,id1713in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1714out_result;

  { // Node ID: 1714 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1714in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1714in_option0 = id1713out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1714in_option1 = id1711out_o;

    HWOffsetFix<32,0,UNSIGNED> id1714x_1;

    switch((id1714in_sel.getValueAsLong())) {
      case 0l:
        id1714x_1 = id1714in_option0;
        break;
      case 1l:
        id1714x_1 = id1714in_option1;
        break;
      default:
        id1714x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1714out_result = (id1714x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1712out_output;

  { // Node ID: 1712 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1712in_input = id1714out_result;

    id1712out_output = id1712in_input;
  }
  { // Node ID: 3760 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3760in_input = id1712out_output;

    id3760out_output[(getCycle()+1)%2] = id3760in_input;
  }
  { // Node ID: 3305 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2659out_result;

  { // Node ID: 2659 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2659in_a = id3305out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2659in_b = id3460out_output[getCycle()%2];

    id2659out_result = (eq_fixed(id2659in_a,id2659in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1705out_o;

  { // Node ID: 1705 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1705in_i = id2659out_result;

    id1705out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1705in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1707out_result;

  { // Node ID: 1707 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1707in_a = id3762out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1707in_b = id1705out_o;

    id1707out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1707in_a,id1707in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1708out_result;

  { // Node ID: 1708 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1708in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1708in_option0 = id1707out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1708in_option1 = id1705out_o;

    HWOffsetFix<32,0,UNSIGNED> id1708x_1;

    switch((id1708in_sel.getValueAsLong())) {
      case 0l:
        id1708x_1 = id1708in_option0;
        break;
      case 1l:
        id1708x_1 = id1708in_option1;
        break;
      default:
        id1708x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1708out_result = (id1708x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1706out_output;

  { // Node ID: 1706 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1706in_input = id1708out_result;

    id1706out_output = id1706in_input;
  }
  { // Node ID: 3762 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3762in_input = id1706out_output;

    id3762out_output[(getCycle()+1)%2] = id3762in_input;
  }
  { // Node ID: 3304 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2660out_result;

  { // Node ID: 2660 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2660in_a = id3304out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2660in_b = id3460out_output[getCycle()%2];

    id2660out_result = (eq_fixed(id2660in_a,id2660in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1699out_o;

  { // Node ID: 1699 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1699in_i = id2660out_result;

    id1699out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1699in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1701out_result;

  { // Node ID: 1701 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1701in_a = id3764out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1701in_b = id1699out_o;

    id1701out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1701in_a,id1701in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1702out_result;

  { // Node ID: 1702 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1702in_sel = id4479out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1702in_option0 = id1701out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1702in_option1 = id1699out_o;

    HWOffsetFix<32,0,UNSIGNED> id1702x_1;

    switch((id1702in_sel.getValueAsLong())) {
      case 0l:
        id1702x_1 = id1702in_option0;
        break;
      case 1l:
        id1702x_1 = id1702in_option1;
        break;
      default:
        id1702x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1702out_result = (id1702x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1700out_output;

  { // Node ID: 1700 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1700in_input = id1702out_result;

    id1700out_output = id1700in_input;
  }
  { // Node ID: 3764 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3764in_input = id1700out_output;

    id3764out_output[(getCycle()+1)%2] = id3764in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1694out_output;

  { // Node ID: 1694 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1694in_input = id3766out_output[getCycle()%2];

    id1694out_output = id1694in_input;
  }
  { // Node ID: 3303 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2661out_result;

  { // Node ID: 2661 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2661in_a = id3303out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2661in_b = id3461out_output[getCycle()%2];

    id2661out_result = (eq_fixed(id2661in_a,id2661in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1693out_o;

  { // Node ID: 1693 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1693in_i = id2661out_result;

    id1693out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1693in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1695out_result;

  { // Node ID: 1695 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1695in_a = id1694out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1695in_b = id1693out_o;

    id1695out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1695in_a,id1695in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1696out_result;

  { // Node ID: 1696 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1696in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1696in_option0 = id1695out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1696in_option1 = id1693out_o;

    HWOffsetFix<32,0,UNSIGNED> id1696x_1;

    switch((id1696in_sel.getValueAsLong())) {
      case 0l:
        id1696x_1 = id1696in_option0;
        break;
      case 1l:
        id1696x_1 = id1696in_option1;
        break;
      default:
        id1696x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1696out_result = (id1696x_1);
  }
  { // Node ID: 3766 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3766in_input = id1696out_result;

    id3766out_output[(getCycle()+1)%2] = id3766in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1688out_output;

  { // Node ID: 1688 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1688in_input = id3768out_output[getCycle()%2];

    id1688out_output = id1688in_input;
  }
  { // Node ID: 3302 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2662out_result;

  { // Node ID: 2662 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2662in_a = id3302out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2662in_b = id3461out_output[getCycle()%2];

    id2662out_result = (eq_fixed(id2662in_a,id2662in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1687out_o;

  { // Node ID: 1687 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1687in_i = id2662out_result;

    id1687out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1687in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1689out_result;

  { // Node ID: 1689 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1689in_a = id1688out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1689in_b = id1687out_o;

    id1689out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1689in_a,id1689in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1690out_result;

  { // Node ID: 1690 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1690in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1690in_option0 = id1689out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1690in_option1 = id1687out_o;

    HWOffsetFix<32,0,UNSIGNED> id1690x_1;

    switch((id1690in_sel.getValueAsLong())) {
      case 0l:
        id1690x_1 = id1690in_option0;
        break;
      case 1l:
        id1690x_1 = id1690in_option1;
        break;
      default:
        id1690x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1690out_result = (id1690x_1);
  }
  { // Node ID: 3768 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3768in_input = id1690out_result;

    id3768out_output[(getCycle()+1)%2] = id3768in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1682out_output;

  { // Node ID: 1682 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1682in_input = id3770out_output[getCycle()%2];

    id1682out_output = id1682in_input;
  }
  { // Node ID: 3301 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2663out_result;

  { // Node ID: 2663 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2663in_a = id3301out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2663in_b = id3461out_output[getCycle()%2];

    id2663out_result = (eq_fixed(id2663in_a,id2663in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1681out_o;

  { // Node ID: 1681 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1681in_i = id2663out_result;

    id1681out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1681in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1683out_result;

  { // Node ID: 1683 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1683in_a = id1682out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1683in_b = id1681out_o;

    id1683out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1683in_a,id1683in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1684out_result;

  { // Node ID: 1684 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1684in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1684in_option0 = id1683out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1684in_option1 = id1681out_o;

    HWOffsetFix<32,0,UNSIGNED> id1684x_1;

    switch((id1684in_sel.getValueAsLong())) {
      case 0l:
        id1684x_1 = id1684in_option0;
        break;
      case 1l:
        id1684x_1 = id1684in_option1;
        break;
      default:
        id1684x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1684out_result = (id1684x_1);
  }
  { // Node ID: 3770 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3770in_input = id1684out_result;

    id3770out_output[(getCycle()+1)%2] = id3770in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1676out_output;

  { // Node ID: 1676 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1676in_input = id3772out_output[getCycle()%2];

    id1676out_output = id1676in_input;
  }
  { // Node ID: 3300 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2664out_result;

  { // Node ID: 2664 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2664in_a = id3300out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2664in_b = id3461out_output[getCycle()%2];

    id2664out_result = (eq_fixed(id2664in_a,id2664in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1675out_o;

  { // Node ID: 1675 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1675in_i = id2664out_result;

    id1675out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1675in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1677out_result;

  { // Node ID: 1677 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1677in_a = id1676out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1677in_b = id1675out_o;

    id1677out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1677in_a,id1677in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1678out_result;

  { // Node ID: 1678 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1678in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1678in_option0 = id1677out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1678in_option1 = id1675out_o;

    HWOffsetFix<32,0,UNSIGNED> id1678x_1;

    switch((id1678in_sel.getValueAsLong())) {
      case 0l:
        id1678x_1 = id1678in_option0;
        break;
      case 1l:
        id1678x_1 = id1678in_option1;
        break;
      default:
        id1678x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1678out_result = (id1678x_1);
  }
  { // Node ID: 3772 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3772in_input = id1678out_result;

    id3772out_output[(getCycle()+1)%2] = id3772in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1670out_output;

  { // Node ID: 1670 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1670in_input = id3774out_output[getCycle()%2];

    id1670out_output = id1670in_input;
  }
  { // Node ID: 3299 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2665out_result;

  { // Node ID: 2665 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2665in_a = id3299out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2665in_b = id3461out_output[getCycle()%2];

    id2665out_result = (eq_fixed(id2665in_a,id2665in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1669out_o;

  { // Node ID: 1669 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1669in_i = id2665out_result;

    id1669out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1669in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1671out_result;

  { // Node ID: 1671 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1671in_a = id1670out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1671in_b = id1669out_o;

    id1671out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1671in_a,id1671in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1672out_result;

  { // Node ID: 1672 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1672in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1672in_option0 = id1671out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1672in_option1 = id1669out_o;

    HWOffsetFix<32,0,UNSIGNED> id1672x_1;

    switch((id1672in_sel.getValueAsLong())) {
      case 0l:
        id1672x_1 = id1672in_option0;
        break;
      case 1l:
        id1672x_1 = id1672in_option1;
        break;
      default:
        id1672x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1672out_result = (id1672x_1);
  }
  { // Node ID: 3774 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3774in_input = id1672out_result;

    id3774out_output[(getCycle()+1)%2] = id3774in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1664out_output;

  { // Node ID: 1664 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1664in_input = id3776out_output[getCycle()%2];

    id1664out_output = id1664in_input;
  }
  { // Node ID: 3298 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2666out_result;

  { // Node ID: 2666 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2666in_a = id3298out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2666in_b = id3461out_output[getCycle()%2];

    id2666out_result = (eq_fixed(id2666in_a,id2666in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1663out_o;

  { // Node ID: 1663 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1663in_i = id2666out_result;

    id1663out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1663in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1665out_result;

  { // Node ID: 1665 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1665in_a = id1664out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1665in_b = id1663out_o;

    id1665out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1665in_a,id1665in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1666out_result;

  { // Node ID: 1666 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1666in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1666in_option0 = id1665out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1666in_option1 = id1663out_o;

    HWOffsetFix<32,0,UNSIGNED> id1666x_1;

    switch((id1666in_sel.getValueAsLong())) {
      case 0l:
        id1666x_1 = id1666in_option0;
        break;
      case 1l:
        id1666x_1 = id1666in_option1;
        break;
      default:
        id1666x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1666out_result = (id1666x_1);
  }
  { // Node ID: 3776 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3776in_input = id1666out_result;

    id3776out_output[(getCycle()+1)%2] = id3776in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1658out_output;

  { // Node ID: 1658 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1658in_input = id3778out_output[getCycle()%2];

    id1658out_output = id1658in_input;
  }
  { // Node ID: 3297 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2667out_result;

  { // Node ID: 2667 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2667in_a = id3297out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2667in_b = id3461out_output[getCycle()%2];

    id2667out_result = (eq_fixed(id2667in_a,id2667in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1657out_o;

  { // Node ID: 1657 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1657in_i = id2667out_result;

    id1657out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1657in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1659out_result;

  { // Node ID: 1659 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1659in_a = id1658out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1659in_b = id1657out_o;

    id1659out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1659in_a,id1659in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1660out_result;

  { // Node ID: 1660 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1660in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1660in_option0 = id1659out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1660in_option1 = id1657out_o;

    HWOffsetFix<32,0,UNSIGNED> id1660x_1;

    switch((id1660in_sel.getValueAsLong())) {
      case 0l:
        id1660x_1 = id1660in_option0;
        break;
      case 1l:
        id1660x_1 = id1660in_option1;
        break;
      default:
        id1660x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1660out_result = (id1660x_1);
  }
  { // Node ID: 3778 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3778in_input = id1660out_result;

    id3778out_output[(getCycle()+1)%2] = id3778in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1652out_output;

  { // Node ID: 1652 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1652in_input = id3780out_output[getCycle()%2];

    id1652out_output = id1652in_input;
  }
  { // Node ID: 3296 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2668out_result;

  { // Node ID: 2668 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2668in_a = id3296out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2668in_b = id3461out_output[getCycle()%2];

    id2668out_result = (eq_fixed(id2668in_a,id2668in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1651out_o;

  { // Node ID: 1651 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1651in_i = id2668out_result;

    id1651out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1651in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1653out_result;

  { // Node ID: 1653 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1653in_a = id1652out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1653in_b = id1651out_o;

    id1653out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1653in_a,id1653in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1654out_result;

  { // Node ID: 1654 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1654in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1654in_option0 = id1653out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1654in_option1 = id1651out_o;

    HWOffsetFix<32,0,UNSIGNED> id1654x_1;

    switch((id1654in_sel.getValueAsLong())) {
      case 0l:
        id1654x_1 = id1654in_option0;
        break;
      case 1l:
        id1654x_1 = id1654in_option1;
        break;
      default:
        id1654x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1654out_result = (id1654x_1);
  }
  { // Node ID: 3780 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3780in_input = id1654out_result;

    id3780out_output[(getCycle()+1)%2] = id3780in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1646out_output;

  { // Node ID: 1646 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1646in_input = id3782out_output[getCycle()%2];

    id1646out_output = id1646in_input;
  }
  { // Node ID: 3295 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2669out_result;

  { // Node ID: 2669 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2669in_a = id3295out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2669in_b = id3461out_output[getCycle()%2];

    id2669out_result = (eq_fixed(id2669in_a,id2669in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1645out_o;

  { // Node ID: 1645 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1645in_i = id2669out_result;

    id1645out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1645in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1647out_result;

  { // Node ID: 1647 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1647in_a = id1646out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1647in_b = id1645out_o;

    id1647out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1647in_a,id1647in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1648out_result;

  { // Node ID: 1648 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1648in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1648in_option0 = id1647out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1648in_option1 = id1645out_o;

    HWOffsetFix<32,0,UNSIGNED> id1648x_1;

    switch((id1648in_sel.getValueAsLong())) {
      case 0l:
        id1648x_1 = id1648in_option0;
        break;
      case 1l:
        id1648x_1 = id1648in_option1;
        break;
      default:
        id1648x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1648out_result = (id1648x_1);
  }
  { // Node ID: 3782 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3782in_input = id1648out_result;

    id3782out_output[(getCycle()+1)%2] = id3782in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1640out_output;

  { // Node ID: 1640 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1640in_input = id3784out_output[getCycle()%2];

    id1640out_output = id1640in_input;
  }
  { // Node ID: 3294 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2670out_result;

  { // Node ID: 2670 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2670in_a = id3294out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2670in_b = id3461out_output[getCycle()%2];

    id2670out_result = (eq_fixed(id2670in_a,id2670in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1639out_o;

  { // Node ID: 1639 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1639in_i = id2670out_result;

    id1639out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1639in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1641out_result;

  { // Node ID: 1641 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1641in_a = id1640out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1641in_b = id1639out_o;

    id1641out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1641in_a,id1641in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1642out_result;

  { // Node ID: 1642 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1642in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1642in_option0 = id1641out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1642in_option1 = id1639out_o;

    HWOffsetFix<32,0,UNSIGNED> id1642x_1;

    switch((id1642in_sel.getValueAsLong())) {
      case 0l:
        id1642x_1 = id1642in_option0;
        break;
      case 1l:
        id1642x_1 = id1642in_option1;
        break;
      default:
        id1642x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1642out_result = (id1642x_1);
  }
  { // Node ID: 3784 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3784in_input = id1642out_result;

    id3784out_output[(getCycle()+1)%2] = id3784in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1634out_output;

  { // Node ID: 1634 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1634in_input = id3786out_output[getCycle()%2];

    id1634out_output = id1634in_input;
  }
  { // Node ID: 3293 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2671out_result;

  { // Node ID: 2671 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2671in_a = id3293out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2671in_b = id3461out_output[getCycle()%2];

    id2671out_result = (eq_fixed(id2671in_a,id2671in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1633out_o;

  { // Node ID: 1633 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1633in_i = id2671out_result;

    id1633out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1633in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1635out_result;

  { // Node ID: 1635 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1635in_a = id1634out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1635in_b = id1633out_o;

    id1635out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1635in_a,id1635in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1636out_result;

  { // Node ID: 1636 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1636in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1636in_option0 = id1635out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1636in_option1 = id1633out_o;

    HWOffsetFix<32,0,UNSIGNED> id1636x_1;

    switch((id1636in_sel.getValueAsLong())) {
      case 0l:
        id1636x_1 = id1636in_option0;
        break;
      case 1l:
        id1636x_1 = id1636in_option1;
        break;
      default:
        id1636x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1636out_result = (id1636x_1);
  }
  { // Node ID: 3786 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3786in_input = id1636out_result;

    id3786out_output[(getCycle()+1)%2] = id3786in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1628out_output;

  { // Node ID: 1628 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1628in_input = id3788out_output[getCycle()%2];

    id1628out_output = id1628in_input;
  }
  { // Node ID: 3292 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2672out_result;

  { // Node ID: 2672 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2672in_a = id3292out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2672in_b = id3461out_output[getCycle()%2];

    id2672out_result = (eq_fixed(id2672in_a,id2672in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1627out_o;

  { // Node ID: 1627 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1627in_i = id2672out_result;

    id1627out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1627in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1629out_result;

  { // Node ID: 1629 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1629in_a = id1628out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1629in_b = id1627out_o;

    id1629out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1629in_a,id1629in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1630out_result;

  { // Node ID: 1630 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1630in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1630in_option0 = id1629out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1630in_option1 = id1627out_o;

    HWOffsetFix<32,0,UNSIGNED> id1630x_1;

    switch((id1630in_sel.getValueAsLong())) {
      case 0l:
        id1630x_1 = id1630in_option0;
        break;
      case 1l:
        id1630x_1 = id1630in_option1;
        break;
      default:
        id1630x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1630out_result = (id1630x_1);
  }
  { // Node ID: 3788 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3788in_input = id1630out_result;

    id3788out_output[(getCycle()+1)%2] = id3788in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1622out_output;

  { // Node ID: 1622 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1622in_input = id3790out_output[getCycle()%2];

    id1622out_output = id1622in_input;
  }
  { // Node ID: 3291 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2673out_result;

  { // Node ID: 2673 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2673in_a = id3291out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2673in_b = id3461out_output[getCycle()%2];

    id2673out_result = (eq_fixed(id2673in_a,id2673in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1621out_o;

  { // Node ID: 1621 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1621in_i = id2673out_result;

    id1621out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1621in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1623out_result;

  { // Node ID: 1623 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1623in_a = id1622out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1623in_b = id1621out_o;

    id1623out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1623in_a,id1623in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1624out_result;

  { // Node ID: 1624 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1624in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1624in_option0 = id1623out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1624in_option1 = id1621out_o;

    HWOffsetFix<32,0,UNSIGNED> id1624x_1;

    switch((id1624in_sel.getValueAsLong())) {
      case 0l:
        id1624x_1 = id1624in_option0;
        break;
      case 1l:
        id1624x_1 = id1624in_option1;
        break;
      default:
        id1624x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1624out_result = (id1624x_1);
  }
  { // Node ID: 3790 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3790in_input = id1624out_result;

    id3790out_output[(getCycle()+1)%2] = id3790in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1616out_output;

  { // Node ID: 1616 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1616in_input = id3792out_output[getCycle()%2];

    id1616out_output = id1616in_input;
  }
  { // Node ID: 3290 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2674out_result;

  { // Node ID: 2674 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2674in_a = id3290out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2674in_b = id3461out_output[getCycle()%2];

    id2674out_result = (eq_fixed(id2674in_a,id2674in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1615out_o;

  { // Node ID: 1615 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1615in_i = id2674out_result;

    id1615out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1615in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1617out_result;

  { // Node ID: 1617 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1617in_a = id1616out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1617in_b = id1615out_o;

    id1617out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1617in_a,id1617in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1618out_result;

  { // Node ID: 1618 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1618in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1618in_option0 = id1617out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1618in_option1 = id1615out_o;

    HWOffsetFix<32,0,UNSIGNED> id1618x_1;

    switch((id1618in_sel.getValueAsLong())) {
      case 0l:
        id1618x_1 = id1618in_option0;
        break;
      case 1l:
        id1618x_1 = id1618in_option1;
        break;
      default:
        id1618x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1618out_result = (id1618x_1);
  }
  { // Node ID: 3792 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3792in_input = id1618out_result;

    id3792out_output[(getCycle()+1)%2] = id3792in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1610out_output;

  { // Node ID: 1610 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1610in_input = id3794out_output[getCycle()%2];

    id1610out_output = id1610in_input;
  }
  { // Node ID: 3289 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2675out_result;

  { // Node ID: 2675 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2675in_a = id3289out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2675in_b = id3461out_output[getCycle()%2];

    id2675out_result = (eq_fixed(id2675in_a,id2675in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1609out_o;

  { // Node ID: 1609 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1609in_i = id2675out_result;

    id1609out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1609in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1611out_result;

  { // Node ID: 1611 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1611in_a = id1610out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1611in_b = id1609out_o;

    id1611out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1611in_a,id1611in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1612out_result;

  { // Node ID: 1612 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1612in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1612in_option0 = id1611out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1612in_option1 = id1609out_o;

    HWOffsetFix<32,0,UNSIGNED> id1612x_1;

    switch((id1612in_sel.getValueAsLong())) {
      case 0l:
        id1612x_1 = id1612in_option0;
        break;
      case 1l:
        id1612x_1 = id1612in_option1;
        break;
      default:
        id1612x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1612out_result = (id1612x_1);
  }
  { // Node ID: 3794 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3794in_input = id1612out_result;

    id3794out_output[(getCycle()+1)%2] = id3794in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1604out_output;

  { // Node ID: 1604 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1604in_input = id3796out_output[getCycle()%2];

    id1604out_output = id1604in_input;
  }
  { // Node ID: 3288 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2676out_result;

  { // Node ID: 2676 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2676in_a = id3288out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2676in_b = id3461out_output[getCycle()%2];

    id2676out_result = (eq_fixed(id2676in_a,id2676in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1603out_o;

  { // Node ID: 1603 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1603in_i = id2676out_result;

    id1603out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1603in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1605out_result;

  { // Node ID: 1605 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1605in_a = id1604out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1605in_b = id1603out_o;

    id1605out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1605in_a,id1605in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1606out_result;

  { // Node ID: 1606 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1606in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1606in_option0 = id1605out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1606in_option1 = id1603out_o;

    HWOffsetFix<32,0,UNSIGNED> id1606x_1;

    switch((id1606in_sel.getValueAsLong())) {
      case 0l:
        id1606x_1 = id1606in_option0;
        break;
      case 1l:
        id1606x_1 = id1606in_option1;
        break;
      default:
        id1606x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1606out_result = (id1606x_1);
  }
  { // Node ID: 3796 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3796in_input = id1606out_result;

    id3796out_output[(getCycle()+1)%2] = id3796in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1598out_output;

  { // Node ID: 1598 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1598in_input = id3798out_output[getCycle()%2];

    id1598out_output = id1598in_input;
  }
  { // Node ID: 3287 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2677out_result;

  { // Node ID: 2677 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2677in_a = id3287out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2677in_b = id3461out_output[getCycle()%2];

    id2677out_result = (eq_fixed(id2677in_a,id2677in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1597out_o;

  { // Node ID: 1597 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1597in_i = id2677out_result;

    id1597out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1597in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1599out_result;

  { // Node ID: 1599 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1599in_a = id1598out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1599in_b = id1597out_o;

    id1599out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1599in_a,id1599in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1600out_result;

  { // Node ID: 1600 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1600in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1600in_option0 = id1599out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1600in_option1 = id1597out_o;

    HWOffsetFix<32,0,UNSIGNED> id1600x_1;

    switch((id1600in_sel.getValueAsLong())) {
      case 0l:
        id1600x_1 = id1600in_option0;
        break;
      case 1l:
        id1600x_1 = id1600in_option1;
        break;
      default:
        id1600x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1600out_result = (id1600x_1);
  }
  { // Node ID: 3798 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3798in_input = id1600out_result;

    id3798out_output[(getCycle()+1)%2] = id3798in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1592out_output;

  { // Node ID: 1592 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1592in_input = id3800out_output[getCycle()%2];

    id1592out_output = id1592in_input;
  }
  { // Node ID: 3286 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2678out_result;

  { // Node ID: 2678 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2678in_a = id3286out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2678in_b = id3461out_output[getCycle()%2];

    id2678out_result = (eq_fixed(id2678in_a,id2678in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1591out_o;

  { // Node ID: 1591 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1591in_i = id2678out_result;

    id1591out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1591in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1593out_result;

  { // Node ID: 1593 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1593in_a = id1592out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1593in_b = id1591out_o;

    id1593out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1593in_a,id1593in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1594out_result;

  { // Node ID: 1594 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1594in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1594in_option0 = id1593out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1594in_option1 = id1591out_o;

    HWOffsetFix<32,0,UNSIGNED> id1594x_1;

    switch((id1594in_sel.getValueAsLong())) {
      case 0l:
        id1594x_1 = id1594in_option0;
        break;
      case 1l:
        id1594x_1 = id1594in_option1;
        break;
      default:
        id1594x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1594out_result = (id1594x_1);
  }
  { // Node ID: 3800 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3800in_input = id1594out_result;

    id3800out_output[(getCycle()+1)%2] = id3800in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1586out_output;

  { // Node ID: 1586 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1586in_input = id3802out_output[getCycle()%2];

    id1586out_output = id1586in_input;
  }
  { // Node ID: 3285 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2679out_result;

  { // Node ID: 2679 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2679in_a = id3285out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2679in_b = id3461out_output[getCycle()%2];

    id2679out_result = (eq_fixed(id2679in_a,id2679in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1585out_o;

  { // Node ID: 1585 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1585in_i = id2679out_result;

    id1585out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1585in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1587out_result;

  { // Node ID: 1587 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1587in_a = id1586out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1587in_b = id1585out_o;

    id1587out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1587in_a,id1587in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1588out_result;

  { // Node ID: 1588 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1588in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1588in_option0 = id1587out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1588in_option1 = id1585out_o;

    HWOffsetFix<32,0,UNSIGNED> id1588x_1;

    switch((id1588in_sel.getValueAsLong())) {
      case 0l:
        id1588x_1 = id1588in_option0;
        break;
      case 1l:
        id1588x_1 = id1588in_option1;
        break;
      default:
        id1588x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1588out_result = (id1588x_1);
  }
  { // Node ID: 3802 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3802in_input = id1588out_result;

    id3802out_output[(getCycle()+1)%2] = id3802in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1580out_output;

  { // Node ID: 1580 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1580in_input = id3804out_output[getCycle()%2];

    id1580out_output = id1580in_input;
  }
  { // Node ID: 3284 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2680out_result;

  { // Node ID: 2680 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2680in_a = id3284out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2680in_b = id3461out_output[getCycle()%2];

    id2680out_result = (eq_fixed(id2680in_a,id2680in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1579out_o;

  { // Node ID: 1579 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1579in_i = id2680out_result;

    id1579out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1579in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1581out_result;

  { // Node ID: 1581 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1581in_a = id1580out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1581in_b = id1579out_o;

    id1581out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1581in_a,id1581in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1582out_result;

  { // Node ID: 1582 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1582in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1582in_option0 = id1581out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1582in_option1 = id1579out_o;

    HWOffsetFix<32,0,UNSIGNED> id1582x_1;

    switch((id1582in_sel.getValueAsLong())) {
      case 0l:
        id1582x_1 = id1582in_option0;
        break;
      case 1l:
        id1582x_1 = id1582in_option1;
        break;
      default:
        id1582x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1582out_result = (id1582x_1);
  }
  { // Node ID: 3804 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3804in_input = id1582out_result;

    id3804out_output[(getCycle()+1)%2] = id3804in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1574out_output;

  { // Node ID: 1574 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1574in_input = id3806out_output[getCycle()%2];

    id1574out_output = id1574in_input;
  }
  { // Node ID: 3283 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2681out_result;

  { // Node ID: 2681 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2681in_a = id3283out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2681in_b = id3461out_output[getCycle()%2];

    id2681out_result = (eq_fixed(id2681in_a,id2681in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1573out_o;

  { // Node ID: 1573 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1573in_i = id2681out_result;

    id1573out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1573in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1575out_result;

  { // Node ID: 1575 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1575in_a = id1574out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1575in_b = id1573out_o;

    id1575out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1575in_a,id1575in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1576out_result;

  { // Node ID: 1576 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1576in_sel = id3767out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1576in_option0 = id1575out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1576in_option1 = id1573out_o;

    HWOffsetFix<32,0,UNSIGNED> id1576x_1;

    switch((id1576in_sel.getValueAsLong())) {
      case 0l:
        id1576x_1 = id1576in_option0;
        break;
      case 1l:
        id1576x_1 = id1576in_option1;
        break;
      default:
        id1576x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1576out_result = (id1576x_1);
  }
  { // Node ID: 3806 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3806in_input = id1576out_result;

    id3806out_output[(getCycle()+1)%2] = id3806in_input;
  }
  { // Node ID: 3809 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3809in_input = id3455out_output[getCycle()%2];

    id3809out_output[(getCycle()+7)%8] = id3809in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1568out_output;

  { // Node ID: 1568 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1568in_input = id3808out_output[getCycle()%2];

    id1568out_output = id1568in_input;
  }
  { // Node ID: 3282 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2682out_result;

  { // Node ID: 2682 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2682in_a = id3282out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2682in_b = id3461out_output[getCycle()%2];

    id2682out_result = (eq_fixed(id2682in_a,id2682in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1567out_o;

  { // Node ID: 1567 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1567in_i = id2682out_result;

    id1567out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1567in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1569out_result;

  { // Node ID: 1569 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1569in_a = id1568out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1569in_b = id1567out_o;

    id1569out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1569in_a,id1569in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1570out_result;

  { // Node ID: 1570 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1570in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1570in_option0 = id1569out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1570in_option1 = id1567out_o;

    HWOffsetFix<32,0,UNSIGNED> id1570x_1;

    switch((id1570in_sel.getValueAsLong())) {
      case 0l:
        id1570x_1 = id1570in_option0;
        break;
      case 1l:
        id1570x_1 = id1570in_option1;
        break;
      default:
        id1570x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1570out_result = (id1570x_1);
  }
  { // Node ID: 3808 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3808in_input = id1570out_result;

    id3808out_output[(getCycle()+1)%2] = id3808in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1562out_output;

  { // Node ID: 1562 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1562in_input = id3810out_output[getCycle()%2];

    id1562out_output = id1562in_input;
  }
  { // Node ID: 3281 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2683out_result;

  { // Node ID: 2683 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2683in_a = id3281out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2683in_b = id3461out_output[getCycle()%2];

    id2683out_result = (eq_fixed(id2683in_a,id2683in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1561out_o;

  { // Node ID: 1561 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1561in_i = id2683out_result;

    id1561out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1561in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1563out_result;

  { // Node ID: 1563 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1563in_a = id1562out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1563in_b = id1561out_o;

    id1563out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1563in_a,id1563in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1564out_result;

  { // Node ID: 1564 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1564in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1564in_option0 = id1563out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1564in_option1 = id1561out_o;

    HWOffsetFix<32,0,UNSIGNED> id1564x_1;

    switch((id1564in_sel.getValueAsLong())) {
      case 0l:
        id1564x_1 = id1564in_option0;
        break;
      case 1l:
        id1564x_1 = id1564in_option1;
        break;
      default:
        id1564x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1564out_result = (id1564x_1);
  }
  { // Node ID: 3810 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3810in_input = id1564out_result;

    id3810out_output[(getCycle()+1)%2] = id3810in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1556out_output;

  { // Node ID: 1556 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1556in_input = id3812out_output[getCycle()%2];

    id1556out_output = id1556in_input;
  }
  { // Node ID: 3280 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2684out_result;

  { // Node ID: 2684 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2684in_a = id3280out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2684in_b = id3461out_output[getCycle()%2];

    id2684out_result = (eq_fixed(id2684in_a,id2684in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1555out_o;

  { // Node ID: 1555 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1555in_i = id2684out_result;

    id1555out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1555in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1557out_result;

  { // Node ID: 1557 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1557in_a = id1556out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1557in_b = id1555out_o;

    id1557out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1557in_a,id1557in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1558out_result;

  { // Node ID: 1558 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1558in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1558in_option0 = id1557out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1558in_option1 = id1555out_o;

    HWOffsetFix<32,0,UNSIGNED> id1558x_1;

    switch((id1558in_sel.getValueAsLong())) {
      case 0l:
        id1558x_1 = id1558in_option0;
        break;
      case 1l:
        id1558x_1 = id1558in_option1;
        break;
      default:
        id1558x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1558out_result = (id1558x_1);
  }
  { // Node ID: 3812 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3812in_input = id1558out_result;

    id3812out_output[(getCycle()+1)%2] = id3812in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1550out_output;

  { // Node ID: 1550 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1550in_input = id3814out_output[getCycle()%2];

    id1550out_output = id1550in_input;
  }
  { // Node ID: 3279 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2685out_result;

  { // Node ID: 2685 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2685in_a = id3279out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2685in_b = id3461out_output[getCycle()%2];

    id2685out_result = (eq_fixed(id2685in_a,id2685in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1549out_o;

  { // Node ID: 1549 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1549in_i = id2685out_result;

    id1549out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1549in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1551out_result;

  { // Node ID: 1551 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1551in_a = id1550out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1551in_b = id1549out_o;

    id1551out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1551in_a,id1551in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1552out_result;

  { // Node ID: 1552 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1552in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1552in_option0 = id1551out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1552in_option1 = id1549out_o;

    HWOffsetFix<32,0,UNSIGNED> id1552x_1;

    switch((id1552in_sel.getValueAsLong())) {
      case 0l:
        id1552x_1 = id1552in_option0;
        break;
      case 1l:
        id1552x_1 = id1552in_option1;
        break;
      default:
        id1552x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1552out_result = (id1552x_1);
  }
  { // Node ID: 3814 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3814in_input = id1552out_result;

    id3814out_output[(getCycle()+1)%2] = id3814in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1544out_output;

  { // Node ID: 1544 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1544in_input = id3816out_output[getCycle()%2];

    id1544out_output = id1544in_input;
  }
  { // Node ID: 3278 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2686out_result;

  { // Node ID: 2686 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2686in_a = id3278out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2686in_b = id3461out_output[getCycle()%2];

    id2686out_result = (eq_fixed(id2686in_a,id2686in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1543out_o;

  { // Node ID: 1543 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1543in_i = id2686out_result;

    id1543out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1543in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1545out_result;

  { // Node ID: 1545 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1545in_a = id1544out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1545in_b = id1543out_o;

    id1545out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1545in_a,id1545in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1546out_result;

  { // Node ID: 1546 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1546in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1546in_option0 = id1545out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1546in_option1 = id1543out_o;

    HWOffsetFix<32,0,UNSIGNED> id1546x_1;

    switch((id1546in_sel.getValueAsLong())) {
      case 0l:
        id1546x_1 = id1546in_option0;
        break;
      case 1l:
        id1546x_1 = id1546in_option1;
        break;
      default:
        id1546x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1546out_result = (id1546x_1);
  }
  { // Node ID: 3816 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3816in_input = id1546out_result;

    id3816out_output[(getCycle()+1)%2] = id3816in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1538out_output;

  { // Node ID: 1538 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1538in_input = id3818out_output[getCycle()%2];

    id1538out_output = id1538in_input;
  }
  { // Node ID: 3277 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2687out_result;

  { // Node ID: 2687 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2687in_a = id3277out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2687in_b = id3461out_output[getCycle()%2];

    id2687out_result = (eq_fixed(id2687in_a,id2687in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1537out_o;

  { // Node ID: 1537 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1537in_i = id2687out_result;

    id1537out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1537in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1539out_result;

  { // Node ID: 1539 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1539in_a = id1538out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1539in_b = id1537out_o;

    id1539out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1539in_a,id1539in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1540out_result;

  { // Node ID: 1540 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1540in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1540in_option0 = id1539out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1540in_option1 = id1537out_o;

    HWOffsetFix<32,0,UNSIGNED> id1540x_1;

    switch((id1540in_sel.getValueAsLong())) {
      case 0l:
        id1540x_1 = id1540in_option0;
        break;
      case 1l:
        id1540x_1 = id1540in_option1;
        break;
      default:
        id1540x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1540out_result = (id1540x_1);
  }
  { // Node ID: 3818 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3818in_input = id1540out_result;

    id3818out_output[(getCycle()+1)%2] = id3818in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1532out_output;

  { // Node ID: 1532 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1532in_input = id3820out_output[getCycle()%2];

    id1532out_output = id1532in_input;
  }
  { // Node ID: 3276 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2688out_result;

  { // Node ID: 2688 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2688in_a = id3276out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2688in_b = id3461out_output[getCycle()%2];

    id2688out_result = (eq_fixed(id2688in_a,id2688in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1531out_o;

  { // Node ID: 1531 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1531in_i = id2688out_result;

    id1531out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1531in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1533out_result;

  { // Node ID: 1533 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1533in_a = id1532out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1533in_b = id1531out_o;

    id1533out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1533in_a,id1533in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1534out_result;

  { // Node ID: 1534 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1534in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1534in_option0 = id1533out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1534in_option1 = id1531out_o;

    HWOffsetFix<32,0,UNSIGNED> id1534x_1;

    switch((id1534in_sel.getValueAsLong())) {
      case 0l:
        id1534x_1 = id1534in_option0;
        break;
      case 1l:
        id1534x_1 = id1534in_option1;
        break;
      default:
        id1534x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1534out_result = (id1534x_1);
  }
  { // Node ID: 3820 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3820in_input = id1534out_result;

    id3820out_output[(getCycle()+1)%2] = id3820in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1526out_output;

  { // Node ID: 1526 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1526in_input = id3822out_output[getCycle()%2];

    id1526out_output = id1526in_input;
  }
  { // Node ID: 3275 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2689out_result;

  { // Node ID: 2689 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2689in_a = id3275out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2689in_b = id3461out_output[getCycle()%2];

    id2689out_result = (eq_fixed(id2689in_a,id2689in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1525out_o;

  { // Node ID: 1525 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1525in_i = id2689out_result;

    id1525out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1525in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1527out_result;

  { // Node ID: 1527 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1527in_a = id1526out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1527in_b = id1525out_o;

    id1527out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1527in_a,id1527in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1528out_result;

  { // Node ID: 1528 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1528in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1528in_option0 = id1527out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1528in_option1 = id1525out_o;

    HWOffsetFix<32,0,UNSIGNED> id1528x_1;

    switch((id1528in_sel.getValueAsLong())) {
      case 0l:
        id1528x_1 = id1528in_option0;
        break;
      case 1l:
        id1528x_1 = id1528in_option1;
        break;
      default:
        id1528x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1528out_result = (id1528x_1);
  }
  { // Node ID: 3822 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3822in_input = id1528out_result;

    id3822out_output[(getCycle()+1)%2] = id3822in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1520out_output;

  { // Node ID: 1520 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1520in_input = id3824out_output[getCycle()%2];

    id1520out_output = id1520in_input;
  }
  { // Node ID: 3274 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2690out_result;

  { // Node ID: 2690 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2690in_a = id3274out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2690in_b = id3461out_output[getCycle()%2];

    id2690out_result = (eq_fixed(id2690in_a,id2690in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1519out_o;

  { // Node ID: 1519 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1519in_i = id2690out_result;

    id1519out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1519in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1521out_result;

  { // Node ID: 1521 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1521in_a = id1520out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1521in_b = id1519out_o;

    id1521out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1521in_a,id1521in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1522out_result;

  { // Node ID: 1522 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1522in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1522in_option0 = id1521out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1522in_option1 = id1519out_o;

    HWOffsetFix<32,0,UNSIGNED> id1522x_1;

    switch((id1522in_sel.getValueAsLong())) {
      case 0l:
        id1522x_1 = id1522in_option0;
        break;
      case 1l:
        id1522x_1 = id1522in_option1;
        break;
      default:
        id1522x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1522out_result = (id1522x_1);
  }
  { // Node ID: 3824 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3824in_input = id1522out_result;

    id3824out_output[(getCycle()+1)%2] = id3824in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1514out_output;

  { // Node ID: 1514 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1514in_input = id3826out_output[getCycle()%2];

    id1514out_output = id1514in_input;
  }
  { // Node ID: 3273 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2691out_result;

  { // Node ID: 2691 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2691in_a = id3273out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2691in_b = id3461out_output[getCycle()%2];

    id2691out_result = (eq_fixed(id2691in_a,id2691in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1513out_o;

  { // Node ID: 1513 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1513in_i = id2691out_result;

    id1513out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1513in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1515out_result;

  { // Node ID: 1515 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1515in_a = id1514out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1515in_b = id1513out_o;

    id1515out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1515in_a,id1515in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1516out_result;

  { // Node ID: 1516 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1516in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1516in_option0 = id1515out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1516in_option1 = id1513out_o;

    HWOffsetFix<32,0,UNSIGNED> id1516x_1;

    switch((id1516in_sel.getValueAsLong())) {
      case 0l:
        id1516x_1 = id1516in_option0;
        break;
      case 1l:
        id1516x_1 = id1516in_option1;
        break;
      default:
        id1516x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1516out_result = (id1516x_1);
  }
  { // Node ID: 3826 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3826in_input = id1516out_result;

    id3826out_output[(getCycle()+1)%2] = id3826in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1508out_output;

  { // Node ID: 1508 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1508in_input = id3828out_output[getCycle()%2];

    id1508out_output = id1508in_input;
  }
  { // Node ID: 3272 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2692out_result;

  { // Node ID: 2692 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2692in_a = id3272out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2692in_b = id3462out_output[getCycle()%2];

    id2692out_result = (eq_fixed(id2692in_a,id2692in_b));
  }
  { // Node ID: 3829 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3829in_input = id2692out_result;

    id3829out_output[(getCycle()+1)%2] = id3829in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1507out_o;

  { // Node ID: 1507 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1507in_i = id3829out_output[getCycle()%2];

    id1507out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1507in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1509out_result;

  { // Node ID: 1509 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1509in_a = id1508out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1509in_b = id1507out_o;

    id1509out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1509in_a,id1509in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1510out_result;

  { // Node ID: 1510 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1510in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1510in_option0 = id1509out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1510in_option1 = id1507out_o;

    HWOffsetFix<32,0,UNSIGNED> id1510x_1;

    switch((id1510in_sel.getValueAsLong())) {
      case 0l:
        id1510x_1 = id1510in_option0;
        break;
      case 1l:
        id1510x_1 = id1510in_option1;
        break;
      default:
        id1510x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1510out_result = (id1510x_1);
  }
  { // Node ID: 3828 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3828in_input = id1510out_result;

    id3828out_output[(getCycle()+1)%2] = id3828in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1502out_output;

  { // Node ID: 1502 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1502in_input = id3831out_output[getCycle()%2];

    id1502out_output = id1502in_input;
  }
  { // Node ID: 3271 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2693out_result;

  { // Node ID: 2693 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2693in_a = id3271out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2693in_b = id3462out_output[getCycle()%2];

    id2693out_result = (eq_fixed(id2693in_a,id2693in_b));
  }
  { // Node ID: 3832 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3832in_input = id2693out_result;

    id3832out_output[(getCycle()+1)%2] = id3832in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1501out_o;

  { // Node ID: 1501 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1501in_i = id3832out_output[getCycle()%2];

    id1501out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1501in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1503out_result;

  { // Node ID: 1503 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1503in_a = id1502out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1503in_b = id1501out_o;

    id1503out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1503in_a,id1503in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1504out_result;

  { // Node ID: 1504 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1504in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1504in_option0 = id1503out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1504in_option1 = id1501out_o;

    HWOffsetFix<32,0,UNSIGNED> id1504x_1;

    switch((id1504in_sel.getValueAsLong())) {
      case 0l:
        id1504x_1 = id1504in_option0;
        break;
      case 1l:
        id1504x_1 = id1504in_option1;
        break;
      default:
        id1504x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1504out_result = (id1504x_1);
  }
  { // Node ID: 3831 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3831in_input = id1504out_result;

    id3831out_output[(getCycle()+1)%2] = id3831in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1496out_output;

  { // Node ID: 1496 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1496in_input = id3834out_output[getCycle()%2];

    id1496out_output = id1496in_input;
  }
  { // Node ID: 3270 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2694out_result;

  { // Node ID: 2694 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2694in_a = id3270out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2694in_b = id3462out_output[getCycle()%2];

    id2694out_result = (eq_fixed(id2694in_a,id2694in_b));
  }
  { // Node ID: 3835 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3835in_input = id2694out_result;

    id3835out_output[(getCycle()+1)%2] = id3835in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1495out_o;

  { // Node ID: 1495 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1495in_i = id3835out_output[getCycle()%2];

    id1495out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1495in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1497out_result;

  { // Node ID: 1497 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1497in_a = id1496out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1497in_b = id1495out_o;

    id1497out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1497in_a,id1497in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1498out_result;

  { // Node ID: 1498 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1498in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1498in_option0 = id1497out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1498in_option1 = id1495out_o;

    HWOffsetFix<32,0,UNSIGNED> id1498x_1;

    switch((id1498in_sel.getValueAsLong())) {
      case 0l:
        id1498x_1 = id1498in_option0;
        break;
      case 1l:
        id1498x_1 = id1498in_option1;
        break;
      default:
        id1498x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1498out_result = (id1498x_1);
  }
  { // Node ID: 3834 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3834in_input = id1498out_result;

    id3834out_output[(getCycle()+1)%2] = id3834in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1490out_output;

  { // Node ID: 1490 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1490in_input = id3837out_output[getCycle()%2];

    id1490out_output = id1490in_input;
  }
  { // Node ID: 3269 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2695out_result;

  { // Node ID: 2695 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2695in_a = id3269out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2695in_b = id3462out_output[getCycle()%2];

    id2695out_result = (eq_fixed(id2695in_a,id2695in_b));
  }
  { // Node ID: 3838 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3838in_input = id2695out_result;

    id3838out_output[(getCycle()+1)%2] = id3838in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1489out_o;

  { // Node ID: 1489 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1489in_i = id3838out_output[getCycle()%2];

    id1489out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1489in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1491out_result;

  { // Node ID: 1491 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1491in_a = id1490out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1491in_b = id1489out_o;

    id1491out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1491in_a,id1491in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1492out_result;

  { // Node ID: 1492 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1492in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1492in_option0 = id1491out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1492in_option1 = id1489out_o;

    HWOffsetFix<32,0,UNSIGNED> id1492x_1;

    switch((id1492in_sel.getValueAsLong())) {
      case 0l:
        id1492x_1 = id1492in_option0;
        break;
      case 1l:
        id1492x_1 = id1492in_option1;
        break;
      default:
        id1492x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1492out_result = (id1492x_1);
  }
  { // Node ID: 3837 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3837in_input = id1492out_result;

    id3837out_output[(getCycle()+1)%2] = id3837in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1484out_output;

  { // Node ID: 1484 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1484in_input = id3840out_output[getCycle()%2];

    id1484out_output = id1484in_input;
  }
  { // Node ID: 3268 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2696out_result;

  { // Node ID: 2696 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2696in_a = id3268out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2696in_b = id3462out_output[getCycle()%2];

    id2696out_result = (eq_fixed(id2696in_a,id2696in_b));
  }
  { // Node ID: 3841 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3841in_input = id2696out_result;

    id3841out_output[(getCycle()+1)%2] = id3841in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1483out_o;

  { // Node ID: 1483 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1483in_i = id3841out_output[getCycle()%2];

    id1483out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1483in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1485out_result;

  { // Node ID: 1485 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1485in_a = id1484out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1485in_b = id1483out_o;

    id1485out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1485in_a,id1485in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1486out_result;

  { // Node ID: 1486 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1486in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1486in_option0 = id1485out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1486in_option1 = id1483out_o;

    HWOffsetFix<32,0,UNSIGNED> id1486x_1;

    switch((id1486in_sel.getValueAsLong())) {
      case 0l:
        id1486x_1 = id1486in_option0;
        break;
      case 1l:
        id1486x_1 = id1486in_option1;
        break;
      default:
        id1486x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1486out_result = (id1486x_1);
  }
  { // Node ID: 3840 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3840in_input = id1486out_result;

    id3840out_output[(getCycle()+1)%2] = id3840in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1478out_output;

  { // Node ID: 1478 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1478in_input = id3843out_output[getCycle()%2];

    id1478out_output = id1478in_input;
  }
  { // Node ID: 3267 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2697out_result;

  { // Node ID: 2697 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2697in_a = id3267out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2697in_b = id3462out_output[getCycle()%2];

    id2697out_result = (eq_fixed(id2697in_a,id2697in_b));
  }
  { // Node ID: 3844 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3844in_input = id2697out_result;

    id3844out_output[(getCycle()+1)%2] = id3844in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1477out_o;

  { // Node ID: 1477 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1477in_i = id3844out_output[getCycle()%2];

    id1477out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1477in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1479out_result;

  { // Node ID: 1479 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1479in_a = id1478out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1479in_b = id1477out_o;

    id1479out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1479in_a,id1479in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1480out_result;

  { // Node ID: 1480 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1480in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1480in_option0 = id1479out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1480in_option1 = id1477out_o;

    HWOffsetFix<32,0,UNSIGNED> id1480x_1;

    switch((id1480in_sel.getValueAsLong())) {
      case 0l:
        id1480x_1 = id1480in_option0;
        break;
      case 1l:
        id1480x_1 = id1480in_option1;
        break;
      default:
        id1480x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1480out_result = (id1480x_1);
  }
  { // Node ID: 3843 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3843in_input = id1480out_result;

    id3843out_output[(getCycle()+1)%2] = id3843in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1472out_output;

  { // Node ID: 1472 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1472in_input = id3846out_output[getCycle()%2];

    id1472out_output = id1472in_input;
  }
  { // Node ID: 3266 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2698out_result;

  { // Node ID: 2698 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2698in_a = id3266out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2698in_b = id3462out_output[getCycle()%2];

    id2698out_result = (eq_fixed(id2698in_a,id2698in_b));
  }
  { // Node ID: 3847 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3847in_input = id2698out_result;

    id3847out_output[(getCycle()+1)%2] = id3847in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1471out_o;

  { // Node ID: 1471 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1471in_i = id3847out_output[getCycle()%2];

    id1471out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1471in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1473out_result;

  { // Node ID: 1473 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1473in_a = id1472out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1473in_b = id1471out_o;

    id1473out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1473in_a,id1473in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1474out_result;

  { // Node ID: 1474 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1474in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1474in_option0 = id1473out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1474in_option1 = id1471out_o;

    HWOffsetFix<32,0,UNSIGNED> id1474x_1;

    switch((id1474in_sel.getValueAsLong())) {
      case 0l:
        id1474x_1 = id1474in_option0;
        break;
      case 1l:
        id1474x_1 = id1474in_option1;
        break;
      default:
        id1474x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1474out_result = (id1474x_1);
  }
  { // Node ID: 3846 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3846in_input = id1474out_result;

    id3846out_output[(getCycle()+1)%2] = id3846in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1466out_output;

  { // Node ID: 1466 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1466in_input = id3849out_output[getCycle()%2];

    id1466out_output = id1466in_input;
  }
  { // Node ID: 3265 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2699out_result;

  { // Node ID: 2699 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2699in_a = id3265out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2699in_b = id3462out_output[getCycle()%2];

    id2699out_result = (eq_fixed(id2699in_a,id2699in_b));
  }
  { // Node ID: 3850 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3850in_input = id2699out_result;

    id3850out_output[(getCycle()+1)%2] = id3850in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1465out_o;

  { // Node ID: 1465 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1465in_i = id3850out_output[getCycle()%2];

    id1465out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1465in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1467out_result;

  { // Node ID: 1467 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1467in_a = id1466out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1467in_b = id1465out_o;

    id1467out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1467in_a,id1467in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1468out_result;

  { // Node ID: 1468 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1468in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1468in_option0 = id1467out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1468in_option1 = id1465out_o;

    HWOffsetFix<32,0,UNSIGNED> id1468x_1;

    switch((id1468in_sel.getValueAsLong())) {
      case 0l:
        id1468x_1 = id1468in_option0;
        break;
      case 1l:
        id1468x_1 = id1468in_option1;
        break;
      default:
        id1468x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1468out_result = (id1468x_1);
  }
  { // Node ID: 3849 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3849in_input = id1468out_result;

    id3849out_output[(getCycle()+1)%2] = id3849in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1460out_output;

  { // Node ID: 1460 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1460in_input = id3852out_output[getCycle()%2];

    id1460out_output = id1460in_input;
  }
  { // Node ID: 3264 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2700out_result;

  { // Node ID: 2700 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2700in_a = id3264out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2700in_b = id3462out_output[getCycle()%2];

    id2700out_result = (eq_fixed(id2700in_a,id2700in_b));
  }
  { // Node ID: 3853 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3853in_input = id2700out_result;

    id3853out_output[(getCycle()+1)%2] = id3853in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1459out_o;

  { // Node ID: 1459 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1459in_i = id3853out_output[getCycle()%2];

    id1459out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1459in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1461out_result;

  { // Node ID: 1461 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1461in_a = id1460out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1461in_b = id1459out_o;

    id1461out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1461in_a,id1461in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1462out_result;

  { // Node ID: 1462 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1462in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1462in_option0 = id1461out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1462in_option1 = id1459out_o;

    HWOffsetFix<32,0,UNSIGNED> id1462x_1;

    switch((id1462in_sel.getValueAsLong())) {
      case 0l:
        id1462x_1 = id1462in_option0;
        break;
      case 1l:
        id1462x_1 = id1462in_option1;
        break;
      default:
        id1462x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1462out_result = (id1462x_1);
  }
  { // Node ID: 3852 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3852in_input = id1462out_result;

    id3852out_output[(getCycle()+1)%2] = id3852in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1454out_output;

  { // Node ID: 1454 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1454in_input = id3855out_output[getCycle()%2];

    id1454out_output = id1454in_input;
  }
  { // Node ID: 3263 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2701out_result;

  { // Node ID: 2701 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2701in_a = id3263out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2701in_b = id3462out_output[getCycle()%2];

    id2701out_result = (eq_fixed(id2701in_a,id2701in_b));
  }
  { // Node ID: 3856 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3856in_input = id2701out_result;

    id3856out_output[(getCycle()+1)%2] = id3856in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1453out_o;

  { // Node ID: 1453 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1453in_i = id3856out_output[getCycle()%2];

    id1453out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1453in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1455out_result;

  { // Node ID: 1455 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1455in_a = id1454out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1455in_b = id1453out_o;

    id1455out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1455in_a,id1455in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1456out_result;

  { // Node ID: 1456 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1456in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1456in_option0 = id1455out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1456in_option1 = id1453out_o;

    HWOffsetFix<32,0,UNSIGNED> id1456x_1;

    switch((id1456in_sel.getValueAsLong())) {
      case 0l:
        id1456x_1 = id1456in_option0;
        break;
      case 1l:
        id1456x_1 = id1456in_option1;
        break;
      default:
        id1456x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1456out_result = (id1456x_1);
  }
  { // Node ID: 3855 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3855in_input = id1456out_result;

    id3855out_output[(getCycle()+1)%2] = id3855in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1448out_output;

  { // Node ID: 1448 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1448in_input = id3858out_output[getCycle()%2];

    id1448out_output = id1448in_input;
  }
  { // Node ID: 3262 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2702out_result;

  { // Node ID: 2702 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2702in_a = id3262out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2702in_b = id3462out_output[getCycle()%2];

    id2702out_result = (eq_fixed(id2702in_a,id2702in_b));
  }
  { // Node ID: 3859 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3859in_input = id2702out_result;

    id3859out_output[(getCycle()+1)%2] = id3859in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1447out_o;

  { // Node ID: 1447 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1447in_i = id3859out_output[getCycle()%2];

    id1447out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1447in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1449out_result;

  { // Node ID: 1449 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1449in_a = id1448out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1449in_b = id1447out_o;

    id1449out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1449in_a,id1449in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1450out_result;

  { // Node ID: 1450 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1450in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1450in_option0 = id1449out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1450in_option1 = id1447out_o;

    HWOffsetFix<32,0,UNSIGNED> id1450x_1;

    switch((id1450in_sel.getValueAsLong())) {
      case 0l:
        id1450x_1 = id1450in_option0;
        break;
      case 1l:
        id1450x_1 = id1450in_option1;
        break;
      default:
        id1450x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1450out_result = (id1450x_1);
  }
  { // Node ID: 3858 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3858in_input = id1450out_result;

    id3858out_output[(getCycle()+1)%2] = id3858in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1442out_output;

  { // Node ID: 1442 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1442in_input = id3861out_output[getCycle()%2];

    id1442out_output = id1442in_input;
  }
  { // Node ID: 3261 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2703out_result;

  { // Node ID: 2703 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2703in_a = id3261out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2703in_b = id3462out_output[getCycle()%2];

    id2703out_result = (eq_fixed(id2703in_a,id2703in_b));
  }
  { // Node ID: 3862 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3862in_input = id2703out_result;

    id3862out_output[(getCycle()+1)%2] = id3862in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1441out_o;

  { // Node ID: 1441 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1441in_i = id3862out_output[getCycle()%2];

    id1441out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1441in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1443out_result;

  { // Node ID: 1443 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1443in_a = id1442out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1443in_b = id1441out_o;

    id1443out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1443in_a,id1443in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1444out_result;

  { // Node ID: 1444 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1444in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1444in_option0 = id1443out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1444in_option1 = id1441out_o;

    HWOffsetFix<32,0,UNSIGNED> id1444x_1;

    switch((id1444in_sel.getValueAsLong())) {
      case 0l:
        id1444x_1 = id1444in_option0;
        break;
      case 1l:
        id1444x_1 = id1444in_option1;
        break;
      default:
        id1444x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1444out_result = (id1444x_1);
  }
  { // Node ID: 3861 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3861in_input = id1444out_result;

    id3861out_output[(getCycle()+1)%2] = id3861in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1436out_output;

  { // Node ID: 1436 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1436in_input = id3864out_output[getCycle()%2];

    id1436out_output = id1436in_input;
  }
  { // Node ID: 3260 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2704out_result;

  { // Node ID: 2704 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2704in_a = id3260out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2704in_b = id3462out_output[getCycle()%2];

    id2704out_result = (eq_fixed(id2704in_a,id2704in_b));
  }
  { // Node ID: 3865 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3865in_input = id2704out_result;

    id3865out_output[(getCycle()+1)%2] = id3865in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1435out_o;

  { // Node ID: 1435 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1435in_i = id3865out_output[getCycle()%2];

    id1435out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1435in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1437out_result;

  { // Node ID: 1437 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1437in_a = id1436out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1437in_b = id1435out_o;

    id1437out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1437in_a,id1437in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1438out_result;

  { // Node ID: 1438 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1438in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1438in_option0 = id1437out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1438in_option1 = id1435out_o;

    HWOffsetFix<32,0,UNSIGNED> id1438x_1;

    switch((id1438in_sel.getValueAsLong())) {
      case 0l:
        id1438x_1 = id1438in_option0;
        break;
      case 1l:
        id1438x_1 = id1438in_option1;
        break;
      default:
        id1438x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1438out_result = (id1438x_1);
  }
  { // Node ID: 3864 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3864in_input = id1438out_result;

    id3864out_output[(getCycle()+1)%2] = id3864in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1430out_output;

  { // Node ID: 1430 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1430in_input = id3867out_output[getCycle()%2];

    id1430out_output = id1430in_input;
  }
  { // Node ID: 3259 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2705out_result;

  { // Node ID: 2705 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2705in_a = id3259out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2705in_b = id3462out_output[getCycle()%2];

    id2705out_result = (eq_fixed(id2705in_a,id2705in_b));
  }
  { // Node ID: 3868 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3868in_input = id2705out_result;

    id3868out_output[(getCycle()+1)%2] = id3868in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1429out_o;

  { // Node ID: 1429 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1429in_i = id3868out_output[getCycle()%2];

    id1429out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1429in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1431out_result;

  { // Node ID: 1431 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1431in_a = id1430out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1431in_b = id1429out_o;

    id1431out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1431in_a,id1431in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1432out_result;

  { // Node ID: 1432 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1432in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1432in_option0 = id1431out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1432in_option1 = id1429out_o;

    HWOffsetFix<32,0,UNSIGNED> id1432x_1;

    switch((id1432in_sel.getValueAsLong())) {
      case 0l:
        id1432x_1 = id1432in_option0;
        break;
      case 1l:
        id1432x_1 = id1432in_option1;
        break;
      default:
        id1432x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1432out_result = (id1432x_1);
  }
  { // Node ID: 3867 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3867in_input = id1432out_result;

    id3867out_output[(getCycle()+1)%2] = id3867in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1424out_output;

  { // Node ID: 1424 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1424in_input = id3870out_output[getCycle()%2];

    id1424out_output = id1424in_input;
  }
  { // Node ID: 3258 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2706out_result;

  { // Node ID: 2706 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2706in_a = id3258out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2706in_b = id3462out_output[getCycle()%2];

    id2706out_result = (eq_fixed(id2706in_a,id2706in_b));
  }
  { // Node ID: 3871 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3871in_input = id2706out_result;

    id3871out_output[(getCycle()+1)%2] = id3871in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1423out_o;

  { // Node ID: 1423 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1423in_i = id3871out_output[getCycle()%2];

    id1423out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1423in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1425out_result;

  { // Node ID: 1425 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1425in_a = id1424out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1425in_b = id1423out_o;

    id1425out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1425in_a,id1425in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1426out_result;

  { // Node ID: 1426 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1426in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1426in_option0 = id1425out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1426in_option1 = id1423out_o;

    HWOffsetFix<32,0,UNSIGNED> id1426x_1;

    switch((id1426in_sel.getValueAsLong())) {
      case 0l:
        id1426x_1 = id1426in_option0;
        break;
      case 1l:
        id1426x_1 = id1426in_option1;
        break;
      default:
        id1426x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1426out_result = (id1426x_1);
  }
  { // Node ID: 3870 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3870in_input = id1426out_result;

    id3870out_output[(getCycle()+1)%2] = id3870in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1418out_output;

  { // Node ID: 1418 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1418in_input = id3873out_output[getCycle()%2];

    id1418out_output = id1418in_input;
  }
  { // Node ID: 3257 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2707out_result;

  { // Node ID: 2707 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2707in_a = id3257out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2707in_b = id3462out_output[getCycle()%2];

    id2707out_result = (eq_fixed(id2707in_a,id2707in_b));
  }
  { // Node ID: 3874 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3874in_input = id2707out_result;

    id3874out_output[(getCycle()+1)%2] = id3874in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1417out_o;

  { // Node ID: 1417 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1417in_i = id3874out_output[getCycle()%2];

    id1417out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1417in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1419out_result;

  { // Node ID: 1419 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1419in_a = id1418out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1419in_b = id1417out_o;

    id1419out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1419in_a,id1419in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1420out_result;

  { // Node ID: 1420 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1420in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1420in_option0 = id1419out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1420in_option1 = id1417out_o;

    HWOffsetFix<32,0,UNSIGNED> id1420x_1;

    switch((id1420in_sel.getValueAsLong())) {
      case 0l:
        id1420x_1 = id1420in_option0;
        break;
      case 1l:
        id1420x_1 = id1420in_option1;
        break;
      default:
        id1420x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1420out_result = (id1420x_1);
  }
  { // Node ID: 3873 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3873in_input = id1420out_result;

    id3873out_output[(getCycle()+1)%2] = id3873in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1412out_output;

  { // Node ID: 1412 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1412in_input = id3876out_output[getCycle()%2];

    id1412out_output = id1412in_input;
  }
  { // Node ID: 3256 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2708out_result;

  { // Node ID: 2708 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2708in_a = id3256out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2708in_b = id3462out_output[getCycle()%2];

    id2708out_result = (eq_fixed(id2708in_a,id2708in_b));
  }
  { // Node ID: 3877 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3877in_input = id2708out_result;

    id3877out_output[(getCycle()+1)%2] = id3877in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1411out_o;

  { // Node ID: 1411 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1411in_i = id3877out_output[getCycle()%2];

    id1411out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1411in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1413out_result;

  { // Node ID: 1413 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1413in_a = id1412out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1413in_b = id1411out_o;

    id1413out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1413in_a,id1413in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1414out_result;

  { // Node ID: 1414 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1414in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1414in_option0 = id1413out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1414in_option1 = id1411out_o;

    HWOffsetFix<32,0,UNSIGNED> id1414x_1;

    switch((id1414in_sel.getValueAsLong())) {
      case 0l:
        id1414x_1 = id1414in_option0;
        break;
      case 1l:
        id1414x_1 = id1414in_option1;
        break;
      default:
        id1414x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1414out_result = (id1414x_1);
  }
  { // Node ID: 3876 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3876in_input = id1414out_result;

    id3876out_output[(getCycle()+1)%2] = id3876in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1406out_output;

  { // Node ID: 1406 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1406in_input = id3879out_output[getCycle()%2];

    id1406out_output = id1406in_input;
  }
  { // Node ID: 3255 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2709out_result;

  { // Node ID: 2709 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2709in_a = id3255out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2709in_b = id3462out_output[getCycle()%2];

    id2709out_result = (eq_fixed(id2709in_a,id2709in_b));
  }
  { // Node ID: 3880 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3880in_input = id2709out_result;

    id3880out_output[(getCycle()+1)%2] = id3880in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1405out_o;

  { // Node ID: 1405 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1405in_i = id3880out_output[getCycle()%2];

    id1405out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1405in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1407out_result;

  { // Node ID: 1407 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1407in_a = id1406out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1407in_b = id1405out_o;

    id1407out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1407in_a,id1407in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1408out_result;

  { // Node ID: 1408 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1408in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1408in_option0 = id1407out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1408in_option1 = id1405out_o;

    HWOffsetFix<32,0,UNSIGNED> id1408x_1;

    switch((id1408in_sel.getValueAsLong())) {
      case 0l:
        id1408x_1 = id1408in_option0;
        break;
      case 1l:
        id1408x_1 = id1408in_option1;
        break;
      default:
        id1408x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1408out_result = (id1408x_1);
  }
  { // Node ID: 3879 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3879in_input = id1408out_result;

    id3879out_output[(getCycle()+1)%2] = id3879in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1400out_output;

  { // Node ID: 1400 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1400in_input = id3882out_output[getCycle()%2];

    id1400out_output = id1400in_input;
  }
  { // Node ID: 3254 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2710out_result;

  { // Node ID: 2710 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2710in_a = id3254out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2710in_b = id3462out_output[getCycle()%2];

    id2710out_result = (eq_fixed(id2710in_a,id2710in_b));
  }
  { // Node ID: 3883 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3883in_input = id2710out_result;

    id3883out_output[(getCycle()+1)%2] = id3883in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1399out_o;

  { // Node ID: 1399 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1399in_i = id3883out_output[getCycle()%2];

    id1399out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1399in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1401out_result;

  { // Node ID: 1401 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1401in_a = id1400out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1401in_b = id1399out_o;

    id1401out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1401in_a,id1401in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1402out_result;

  { // Node ID: 1402 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1402in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1402in_option0 = id1401out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1402in_option1 = id1399out_o;

    HWOffsetFix<32,0,UNSIGNED> id1402x_1;

    switch((id1402in_sel.getValueAsLong())) {
      case 0l:
        id1402x_1 = id1402in_option0;
        break;
      case 1l:
        id1402x_1 = id1402in_option1;
        break;
      default:
        id1402x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1402out_result = (id1402x_1);
  }
  { // Node ID: 3882 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3882in_input = id1402out_result;

    id3882out_output[(getCycle()+1)%2] = id3882in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1394out_output;

  { // Node ID: 1394 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1394in_input = id3885out_output[getCycle()%2];

    id1394out_output = id1394in_input;
  }
  { // Node ID: 3253 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2711out_result;

  { // Node ID: 2711 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2711in_a = id3253out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2711in_b = id3462out_output[getCycle()%2];

    id2711out_result = (eq_fixed(id2711in_a,id2711in_b));
  }
  { // Node ID: 3886 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3886in_input = id2711out_result;

    id3886out_output[(getCycle()+1)%2] = id3886in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1393out_o;

  { // Node ID: 1393 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1393in_i = id3886out_output[getCycle()%2];

    id1393out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1393in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1395out_result;

  { // Node ID: 1395 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1395in_a = id1394out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1395in_b = id1393out_o;

    id1395out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1395in_a,id1395in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1396out_result;

  { // Node ID: 1396 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1396in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1396in_option0 = id1395out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1396in_option1 = id1393out_o;

    HWOffsetFix<32,0,UNSIGNED> id1396x_1;

    switch((id1396in_sel.getValueAsLong())) {
      case 0l:
        id1396x_1 = id1396in_option0;
        break;
      case 1l:
        id1396x_1 = id1396in_option1;
        break;
      default:
        id1396x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1396out_result = (id1396x_1);
  }
  { // Node ID: 3885 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3885in_input = id1396out_result;

    id3885out_output[(getCycle()+1)%2] = id3885in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1388out_output;

  { // Node ID: 1388 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1388in_input = id3888out_output[getCycle()%2];

    id1388out_output = id1388in_input;
  }
  { // Node ID: 3252 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2712out_result;

  { // Node ID: 2712 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2712in_a = id3252out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2712in_b = id3462out_output[getCycle()%2];

    id2712out_result = (eq_fixed(id2712in_a,id2712in_b));
  }
  { // Node ID: 3889 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3889in_input = id2712out_result;

    id3889out_output[(getCycle()+1)%2] = id3889in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1387out_o;

  { // Node ID: 1387 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1387in_i = id3889out_output[getCycle()%2];

    id1387out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1387in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1389out_result;

  { // Node ID: 1389 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1389in_a = id1388out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1389in_b = id1387out_o;

    id1389out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1389in_a,id1389in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1390out_result;

  { // Node ID: 1390 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1390in_sel = id3809out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1390in_option0 = id1389out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1390in_option1 = id1387out_o;

    HWOffsetFix<32,0,UNSIGNED> id1390x_1;

    switch((id1390in_sel.getValueAsLong())) {
      case 0l:
        id1390x_1 = id1390in_option0;
        break;
      case 1l:
        id1390x_1 = id1390in_option1;
        break;
      default:
        id1390x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1390out_result = (id1390x_1);
  }
  { // Node ID: 3888 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3888in_input = id1390out_result;

    id3888out_output[(getCycle()+1)%2] = id3888in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1382out_output;

  { // Node ID: 1382 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1382in_input = id3891out_output[getCycle()%2];

    id1382out_output = id1382in_input;
  }
  { // Node ID: 3251 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2713out_result;

  { // Node ID: 2713 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2713in_a = id3251out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2713in_b = id3462out_output[getCycle()%2];

    id2713out_result = (eq_fixed(id2713in_a,id2713in_b));
  }
  { // Node ID: 3892 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3892in_input = id2713out_result;

    id3892out_output[(getCycle()+1)%2] = id3892in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1381out_o;

  { // Node ID: 1381 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1381in_i = id3892out_output[getCycle()%2];

    id1381out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1381in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1383out_result;

  { // Node ID: 1383 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1383in_a = id1382out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1383in_b = id1381out_o;

    id1383out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1383in_a,id1383in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1384out_result;

  { // Node ID: 1384 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1384in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1384in_option0 = id1383out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1384in_option1 = id1381out_o;

    HWOffsetFix<32,0,UNSIGNED> id1384x_1;

    switch((id1384in_sel.getValueAsLong())) {
      case 0l:
        id1384x_1 = id1384in_option0;
        break;
      case 1l:
        id1384x_1 = id1384in_option1;
        break;
      default:
        id1384x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1384out_result = (id1384x_1);
  }
  { // Node ID: 3891 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3891in_input = id1384out_result;

    id3891out_output[(getCycle()+1)%2] = id3891in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1376out_output;

  { // Node ID: 1376 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1376in_input = id3894out_output[getCycle()%2];

    id1376out_output = id1376in_input;
  }
  { // Node ID: 3250 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2714out_result;

  { // Node ID: 2714 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2714in_a = id3250out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2714in_b = id3462out_output[getCycle()%2];

    id2714out_result = (eq_fixed(id2714in_a,id2714in_b));
  }
  { // Node ID: 3895 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3895in_input = id2714out_result;

    id3895out_output[(getCycle()+1)%2] = id3895in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1375out_o;

  { // Node ID: 1375 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1375in_i = id3895out_output[getCycle()%2];

    id1375out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1375in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1377out_result;

  { // Node ID: 1377 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1377in_a = id1376out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1377in_b = id1375out_o;

    id1377out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1377in_a,id1377in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1378out_result;

  { // Node ID: 1378 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1378in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1378in_option0 = id1377out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1378in_option1 = id1375out_o;

    HWOffsetFix<32,0,UNSIGNED> id1378x_1;

    switch((id1378in_sel.getValueAsLong())) {
      case 0l:
        id1378x_1 = id1378in_option0;
        break;
      case 1l:
        id1378x_1 = id1378in_option1;
        break;
      default:
        id1378x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1378out_result = (id1378x_1);
  }
  { // Node ID: 3894 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3894in_input = id1378out_result;

    id3894out_output[(getCycle()+1)%2] = id3894in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1370out_output;

  { // Node ID: 1370 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1370in_input = id3897out_output[getCycle()%2];

    id1370out_output = id1370in_input;
  }
  { // Node ID: 3249 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2715out_result;

  { // Node ID: 2715 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2715in_a = id3249out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2715in_b = id3462out_output[getCycle()%2];

    id2715out_result = (eq_fixed(id2715in_a,id2715in_b));
  }
  { // Node ID: 3898 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3898in_input = id2715out_result;

    id3898out_output[(getCycle()+1)%2] = id3898in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1369out_o;

  { // Node ID: 1369 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1369in_i = id3898out_output[getCycle()%2];

    id1369out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1369in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1371out_result;

  { // Node ID: 1371 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1371in_a = id1370out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1371in_b = id1369out_o;

    id1371out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1371in_a,id1371in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1372out_result;

  { // Node ID: 1372 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1372in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1372in_option0 = id1371out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1372in_option1 = id1369out_o;

    HWOffsetFix<32,0,UNSIGNED> id1372x_1;

    switch((id1372in_sel.getValueAsLong())) {
      case 0l:
        id1372x_1 = id1372in_option0;
        break;
      case 1l:
        id1372x_1 = id1372in_option1;
        break;
      default:
        id1372x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1372out_result = (id1372x_1);
  }
  { // Node ID: 3897 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3897in_input = id1372out_result;

    id3897out_output[(getCycle()+1)%2] = id3897in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1364out_output;

  { // Node ID: 1364 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1364in_input = id3900out_output[getCycle()%2];

    id1364out_output = id1364in_input;
  }
  { // Node ID: 3248 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2716out_result;

  { // Node ID: 2716 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2716in_a = id3248out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2716in_b = id3462out_output[getCycle()%2];

    id2716out_result = (eq_fixed(id2716in_a,id2716in_b));
  }
  { // Node ID: 3901 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3901in_input = id2716out_result;

    id3901out_output[(getCycle()+1)%2] = id3901in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1363out_o;

  { // Node ID: 1363 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1363in_i = id3901out_output[getCycle()%2];

    id1363out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1363in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1365out_result;

  { // Node ID: 1365 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1365in_a = id1364out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1365in_b = id1363out_o;

    id1365out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1365in_a,id1365in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1366out_result;

  { // Node ID: 1366 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1366in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1366in_option0 = id1365out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1366in_option1 = id1363out_o;

    HWOffsetFix<32,0,UNSIGNED> id1366x_1;

    switch((id1366in_sel.getValueAsLong())) {
      case 0l:
        id1366x_1 = id1366in_option0;
        break;
      case 1l:
        id1366x_1 = id1366in_option1;
        break;
      default:
        id1366x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1366out_result = (id1366x_1);
  }
  { // Node ID: 3900 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3900in_input = id1366out_result;

    id3900out_output[(getCycle()+1)%2] = id3900in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1358out_output;

  { // Node ID: 1358 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1358in_input = id3903out_output[getCycle()%2];

    id1358out_output = id1358in_input;
  }
  { // Node ID: 3247 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2717out_result;

  { // Node ID: 2717 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2717in_a = id3247out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2717in_b = id3462out_output[getCycle()%2];

    id2717out_result = (eq_fixed(id2717in_a,id2717in_b));
  }
  { // Node ID: 3904 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3904in_input = id2717out_result;

    id3904out_output[(getCycle()+1)%2] = id3904in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1357out_o;

  { // Node ID: 1357 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1357in_i = id3904out_output[getCycle()%2];

    id1357out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1357in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1359out_result;

  { // Node ID: 1359 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1359in_a = id1358out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1359in_b = id1357out_o;

    id1359out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1359in_a,id1359in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1360out_result;

  { // Node ID: 1360 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1360in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1360in_option0 = id1359out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1360in_option1 = id1357out_o;

    HWOffsetFix<32,0,UNSIGNED> id1360x_1;

    switch((id1360in_sel.getValueAsLong())) {
      case 0l:
        id1360x_1 = id1360in_option0;
        break;
      case 1l:
        id1360x_1 = id1360in_option1;
        break;
      default:
        id1360x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1360out_result = (id1360x_1);
  }
  { // Node ID: 3903 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3903in_input = id1360out_result;

    id3903out_output[(getCycle()+1)%2] = id3903in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1352out_output;

  { // Node ID: 1352 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1352in_input = id3906out_output[getCycle()%2];

    id1352out_output = id1352in_input;
  }
  { // Node ID: 3246 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2718out_result;

  { // Node ID: 2718 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2718in_a = id3246out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2718in_b = id3462out_output[getCycle()%2];

    id2718out_result = (eq_fixed(id2718in_a,id2718in_b));
  }
  { // Node ID: 3907 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3907in_input = id2718out_result;

    id3907out_output[(getCycle()+1)%2] = id3907in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1351out_o;

  { // Node ID: 1351 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1351in_i = id3907out_output[getCycle()%2];

    id1351out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1351in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1353out_result;

  { // Node ID: 1353 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1353in_a = id1352out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1353in_b = id1351out_o;

    id1353out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1353in_a,id1353in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1354out_result;

  { // Node ID: 1354 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1354in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1354in_option0 = id1353out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1354in_option1 = id1351out_o;

    HWOffsetFix<32,0,UNSIGNED> id1354x_1;

    switch((id1354in_sel.getValueAsLong())) {
      case 0l:
        id1354x_1 = id1354in_option0;
        break;
      case 1l:
        id1354x_1 = id1354in_option1;
        break;
      default:
        id1354x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1354out_result = (id1354x_1);
  }
  { // Node ID: 3906 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3906in_input = id1354out_result;

    id3906out_output[(getCycle()+1)%2] = id3906in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1346out_output;

  { // Node ID: 1346 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1346in_input = id3909out_output[getCycle()%2];

    id1346out_output = id1346in_input;
  }
  { // Node ID: 3245 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2719out_result;

  { // Node ID: 2719 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2719in_a = id3245out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2719in_b = id3462out_output[getCycle()%2];

    id2719out_result = (eq_fixed(id2719in_a,id2719in_b));
  }
  { // Node ID: 3910 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3910in_input = id2719out_result;

    id3910out_output[(getCycle()+1)%2] = id3910in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1345out_o;

  { // Node ID: 1345 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1345in_i = id3910out_output[getCycle()%2];

    id1345out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1345in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1347out_result;

  { // Node ID: 1347 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1347in_a = id1346out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1347in_b = id1345out_o;

    id1347out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1347in_a,id1347in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1348out_result;

  { // Node ID: 1348 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1348in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1348in_option0 = id1347out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1348in_option1 = id1345out_o;

    HWOffsetFix<32,0,UNSIGNED> id1348x_1;

    switch((id1348in_sel.getValueAsLong())) {
      case 0l:
        id1348x_1 = id1348in_option0;
        break;
      case 1l:
        id1348x_1 = id1348in_option1;
        break;
      default:
        id1348x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1348out_result = (id1348x_1);
  }
  { // Node ID: 3909 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3909in_input = id1348out_result;

    id3909out_output[(getCycle()+1)%2] = id3909in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1340out_output;

  { // Node ID: 1340 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1340in_input = id3912out_output[getCycle()%2];

    id1340out_output = id1340in_input;
  }
  { // Node ID: 3244 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2720out_result;

  { // Node ID: 2720 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2720in_a = id3244out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2720in_b = id3462out_output[getCycle()%2];

    id2720out_result = (eq_fixed(id2720in_a,id2720in_b));
  }
  { // Node ID: 3913 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3913in_input = id2720out_result;

    id3913out_output[(getCycle()+1)%2] = id3913in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1339out_o;

  { // Node ID: 1339 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1339in_i = id3913out_output[getCycle()%2];

    id1339out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1339in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1341out_result;

  { // Node ID: 1341 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1341in_a = id1340out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1341in_b = id1339out_o;

    id1341out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1341in_a,id1341in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1342out_result;

  { // Node ID: 1342 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1342in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1342in_option0 = id1341out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1342in_option1 = id1339out_o;

    HWOffsetFix<32,0,UNSIGNED> id1342x_1;

    switch((id1342in_sel.getValueAsLong())) {
      case 0l:
        id1342x_1 = id1342in_option0;
        break;
      case 1l:
        id1342x_1 = id1342in_option1;
        break;
      default:
        id1342x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1342out_result = (id1342x_1);
  }
  { // Node ID: 3912 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3912in_input = id1342out_result;

    id3912out_output[(getCycle()+1)%2] = id3912in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1334out_output;

  { // Node ID: 1334 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1334in_input = id3915out_output[getCycle()%2];

    id1334out_output = id1334in_input;
  }
  { // Node ID: 3243 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2721out_result;

  { // Node ID: 2721 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2721in_a = id3243out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2721in_b = id3462out_output[getCycle()%2];

    id2721out_result = (eq_fixed(id2721in_a,id2721in_b));
  }
  { // Node ID: 3916 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3916in_input = id2721out_result;

    id3916out_output[(getCycle()+1)%2] = id3916in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1333out_o;

  { // Node ID: 1333 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1333in_i = id3916out_output[getCycle()%2];

    id1333out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1333in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1335out_result;

  { // Node ID: 1335 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1335in_a = id1334out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1335in_b = id1333out_o;

    id1335out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1335in_a,id1335in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1336out_result;

  { // Node ID: 1336 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1336in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1336in_option0 = id1335out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1336in_option1 = id1333out_o;

    HWOffsetFix<32,0,UNSIGNED> id1336x_1;

    switch((id1336in_sel.getValueAsLong())) {
      case 0l:
        id1336x_1 = id1336in_option0;
        break;
      case 1l:
        id1336x_1 = id1336in_option1;
        break;
      default:
        id1336x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1336out_result = (id1336x_1);
  }
  { // Node ID: 3915 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3915in_input = id1336out_result;

    id3915out_output[(getCycle()+1)%2] = id3915in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1328out_output;

  { // Node ID: 1328 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1328in_input = id3918out_output[getCycle()%2];

    id1328out_output = id1328in_input;
  }
  { // Node ID: 3242 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2722out_result;

  { // Node ID: 2722 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2722in_a = id3242out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2722in_b = id3462out_output[getCycle()%2];

    id2722out_result = (eq_fixed(id2722in_a,id2722in_b));
  }
  { // Node ID: 3919 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3919in_input = id2722out_result;

    id3919out_output[(getCycle()+1)%2] = id3919in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1327out_o;

  { // Node ID: 1327 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1327in_i = id3919out_output[getCycle()%2];

    id1327out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1327in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1329out_result;

  { // Node ID: 1329 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1329in_a = id1328out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1329in_b = id1327out_o;

    id1329out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1329in_a,id1329in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1330out_result;

  { // Node ID: 1330 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1330in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1330in_option0 = id1329out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1330in_option1 = id1327out_o;

    HWOffsetFix<32,0,UNSIGNED> id1330x_1;

    switch((id1330in_sel.getValueAsLong())) {
      case 0l:
        id1330x_1 = id1330in_option0;
        break;
      case 1l:
        id1330x_1 = id1330in_option1;
        break;
      default:
        id1330x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1330out_result = (id1330x_1);
  }
  { // Node ID: 3918 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3918in_input = id1330out_result;

    id3918out_output[(getCycle()+1)%2] = id3918in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1322out_output;

  { // Node ID: 1322 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1322in_input = id3921out_output[getCycle()%2];

    id1322out_output = id1322in_input;
  }
  { // Node ID: 3241 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2723out_result;

  { // Node ID: 2723 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2723in_a = id3241out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2723in_b = id3463out_output[getCycle()%2];

    id2723out_result = (eq_fixed(id2723in_a,id2723in_b));
  }
  { // Node ID: 3922 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3922in_input = id2723out_result;

    id3922out_output[(getCycle()+2)%3] = id3922in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1321out_o;

  { // Node ID: 1321 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1321in_i = id3922out_output[getCycle()%3];

    id1321out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1321in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1323out_result;

  { // Node ID: 1323 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1323in_a = id1322out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1323in_b = id1321out_o;

    id1323out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1323in_a,id1323in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1324out_result;

  { // Node ID: 1324 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1324in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1324in_option0 = id1323out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1324in_option1 = id1321out_o;

    HWOffsetFix<32,0,UNSIGNED> id1324x_1;

    switch((id1324in_sel.getValueAsLong())) {
      case 0l:
        id1324x_1 = id1324in_option0;
        break;
      case 1l:
        id1324x_1 = id1324in_option1;
        break;
      default:
        id1324x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1324out_result = (id1324x_1);
  }
  { // Node ID: 3921 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3921in_input = id1324out_result;

    id3921out_output[(getCycle()+1)%2] = id3921in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1316out_output;

  { // Node ID: 1316 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1316in_input = id3924out_output[getCycle()%2];

    id1316out_output = id1316in_input;
  }
  { // Node ID: 3240 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2724out_result;

  { // Node ID: 2724 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2724in_a = id3240out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2724in_b = id3463out_output[getCycle()%2];

    id2724out_result = (eq_fixed(id2724in_a,id2724in_b));
  }
  { // Node ID: 3925 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3925in_input = id2724out_result;

    id3925out_output[(getCycle()+2)%3] = id3925in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1315out_o;

  { // Node ID: 1315 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1315in_i = id3925out_output[getCycle()%3];

    id1315out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1315in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1317out_result;

  { // Node ID: 1317 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1317in_a = id1316out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1317in_b = id1315out_o;

    id1317out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1317in_a,id1317in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1318out_result;

  { // Node ID: 1318 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1318in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1318in_option0 = id1317out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1318in_option1 = id1315out_o;

    HWOffsetFix<32,0,UNSIGNED> id1318x_1;

    switch((id1318in_sel.getValueAsLong())) {
      case 0l:
        id1318x_1 = id1318in_option0;
        break;
      case 1l:
        id1318x_1 = id1318in_option1;
        break;
      default:
        id1318x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1318out_result = (id1318x_1);
  }
  { // Node ID: 3924 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3924in_input = id1318out_result;

    id3924out_output[(getCycle()+1)%2] = id3924in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1310out_output;

  { // Node ID: 1310 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1310in_input = id3927out_output[getCycle()%2];

    id1310out_output = id1310in_input;
  }
  { // Node ID: 3239 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2725out_result;

  { // Node ID: 2725 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2725in_a = id3239out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2725in_b = id3463out_output[getCycle()%2];

    id2725out_result = (eq_fixed(id2725in_a,id2725in_b));
  }
  { // Node ID: 3928 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3928in_input = id2725out_result;

    id3928out_output[(getCycle()+2)%3] = id3928in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1309out_o;

  { // Node ID: 1309 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1309in_i = id3928out_output[getCycle()%3];

    id1309out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1309in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1311out_result;

  { // Node ID: 1311 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1311in_a = id1310out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1311in_b = id1309out_o;

    id1311out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1311in_a,id1311in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1312out_result;

  { // Node ID: 1312 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1312in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1312in_option0 = id1311out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1312in_option1 = id1309out_o;

    HWOffsetFix<32,0,UNSIGNED> id1312x_1;

    switch((id1312in_sel.getValueAsLong())) {
      case 0l:
        id1312x_1 = id1312in_option0;
        break;
      case 1l:
        id1312x_1 = id1312in_option1;
        break;
      default:
        id1312x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1312out_result = (id1312x_1);
  }
  { // Node ID: 3927 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3927in_input = id1312out_result;

    id3927out_output[(getCycle()+1)%2] = id3927in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1304out_output;

  { // Node ID: 1304 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1304in_input = id3930out_output[getCycle()%2];

    id1304out_output = id1304in_input;
  }
  { // Node ID: 3238 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2726out_result;

  { // Node ID: 2726 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2726in_a = id3238out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2726in_b = id3463out_output[getCycle()%2];

    id2726out_result = (eq_fixed(id2726in_a,id2726in_b));
  }
  { // Node ID: 3931 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3931in_input = id2726out_result;

    id3931out_output[(getCycle()+2)%3] = id3931in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1303out_o;

  { // Node ID: 1303 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1303in_i = id3931out_output[getCycle()%3];

    id1303out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1303in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1305out_result;

  { // Node ID: 1305 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1305in_a = id1304out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1305in_b = id1303out_o;

    id1305out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1305in_a,id1305in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1306out_result;

  { // Node ID: 1306 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1306in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1306in_option0 = id1305out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1306in_option1 = id1303out_o;

    HWOffsetFix<32,0,UNSIGNED> id1306x_1;

    switch((id1306in_sel.getValueAsLong())) {
      case 0l:
        id1306x_1 = id1306in_option0;
        break;
      case 1l:
        id1306x_1 = id1306in_option1;
        break;
      default:
        id1306x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1306out_result = (id1306x_1);
  }
  { // Node ID: 3930 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3930in_input = id1306out_result;

    id3930out_output[(getCycle()+1)%2] = id3930in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1298out_output;

  { // Node ID: 1298 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1298in_input = id3933out_output[getCycle()%2];

    id1298out_output = id1298in_input;
  }
  { // Node ID: 3237 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2727out_result;

  { // Node ID: 2727 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2727in_a = id3237out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2727in_b = id3463out_output[getCycle()%2];

    id2727out_result = (eq_fixed(id2727in_a,id2727in_b));
  }
  { // Node ID: 3934 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3934in_input = id2727out_result;

    id3934out_output[(getCycle()+2)%3] = id3934in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1297out_o;

  { // Node ID: 1297 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1297in_i = id3934out_output[getCycle()%3];

    id1297out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1297in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1299out_result;

  { // Node ID: 1299 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1299in_a = id1298out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1299in_b = id1297out_o;

    id1299out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1299in_a,id1299in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1300out_result;

  { // Node ID: 1300 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1300in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1300in_option0 = id1299out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1300in_option1 = id1297out_o;

    HWOffsetFix<32,0,UNSIGNED> id1300x_1;

    switch((id1300in_sel.getValueAsLong())) {
      case 0l:
        id1300x_1 = id1300in_option0;
        break;
      case 1l:
        id1300x_1 = id1300in_option1;
        break;
      default:
        id1300x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1300out_result = (id1300x_1);
  }
  { // Node ID: 3933 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3933in_input = id1300out_result;

    id3933out_output[(getCycle()+1)%2] = id3933in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1292out_output;

  { // Node ID: 1292 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1292in_input = id3936out_output[getCycle()%2];

    id1292out_output = id1292in_input;
  }
  { // Node ID: 3236 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2728out_result;

  { // Node ID: 2728 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2728in_a = id3236out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2728in_b = id3463out_output[getCycle()%2];

    id2728out_result = (eq_fixed(id2728in_a,id2728in_b));
  }
  { // Node ID: 3937 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3937in_input = id2728out_result;

    id3937out_output[(getCycle()+2)%3] = id3937in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1291out_o;

  { // Node ID: 1291 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1291in_i = id3937out_output[getCycle()%3];

    id1291out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1291in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1293out_result;

  { // Node ID: 1293 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1293in_a = id1292out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1293in_b = id1291out_o;

    id1293out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1293in_a,id1293in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1294out_result;

  { // Node ID: 1294 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1294in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1294in_option0 = id1293out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1294in_option1 = id1291out_o;

    HWOffsetFix<32,0,UNSIGNED> id1294x_1;

    switch((id1294in_sel.getValueAsLong())) {
      case 0l:
        id1294x_1 = id1294in_option0;
        break;
      case 1l:
        id1294x_1 = id1294in_option1;
        break;
      default:
        id1294x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1294out_result = (id1294x_1);
  }
  { // Node ID: 3936 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3936in_input = id1294out_result;

    id3936out_output[(getCycle()+1)%2] = id3936in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1280out_output;

  { // Node ID: 1280 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1280in_input = id3939out_output[getCycle()%2];

    id1280out_output = id1280in_input;
  }
  { // Node ID: 3235 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2729out_result;

  { // Node ID: 2729 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2729in_a = id3235out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2729in_b = id3463out_output[getCycle()%2];

    id2729out_result = (eq_fixed(id2729in_a,id2729in_b));
  }
  { // Node ID: 3940 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3940in_input = id2729out_result;

    id3940out_output[(getCycle()+2)%3] = id3940in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1279out_o;

  { // Node ID: 1279 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1279in_i = id3940out_output[getCycle()%3];

    id1279out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1279in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1281out_result;

  { // Node ID: 1281 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1281in_a = id1280out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1281in_b = id1279out_o;

    id1281out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1281in_a,id1281in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1282out_result;

  { // Node ID: 1282 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1282in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1282in_option0 = id1281out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1282in_option1 = id1279out_o;

    HWOffsetFix<32,0,UNSIGNED> id1282x_1;

    switch((id1282in_sel.getValueAsLong())) {
      case 0l:
        id1282x_1 = id1282in_option0;
        break;
      case 1l:
        id1282x_1 = id1282in_option1;
        break;
      default:
        id1282x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1282out_result = (id1282x_1);
  }
  { // Node ID: 3939 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3939in_input = id1282out_result;

    id3939out_output[(getCycle()+1)%2] = id3939in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1268out_output;

  { // Node ID: 1268 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1268in_input = id3942out_output[getCycle()%2];

    id1268out_output = id1268in_input;
  }
  { // Node ID: 3234 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2730out_result;

  { // Node ID: 2730 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2730in_a = id3234out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2730in_b = id3463out_output[getCycle()%2];

    id2730out_result = (eq_fixed(id2730in_a,id2730in_b));
  }
  { // Node ID: 3943 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3943in_input = id2730out_result;

    id3943out_output[(getCycle()+2)%3] = id3943in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1267out_o;

  { // Node ID: 1267 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1267in_i = id3943out_output[getCycle()%3];

    id1267out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1267in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1269out_result;

  { // Node ID: 1269 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1269in_a = id1268out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1269in_b = id1267out_o;

    id1269out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1269in_a,id1269in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1270out_result;

  { // Node ID: 1270 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1270in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1270in_option0 = id1269out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1270in_option1 = id1267out_o;

    HWOffsetFix<32,0,UNSIGNED> id1270x_1;

    switch((id1270in_sel.getValueAsLong())) {
      case 0l:
        id1270x_1 = id1270in_option0;
        break;
      case 1l:
        id1270x_1 = id1270in_option1;
        break;
      default:
        id1270x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1270out_result = (id1270x_1);
  }
  { // Node ID: 3942 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3942in_input = id1270out_result;

    id3942out_output[(getCycle()+1)%2] = id3942in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1256out_output;

  { // Node ID: 1256 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1256in_input = id3945out_output[getCycle()%2];

    id1256out_output = id1256in_input;
  }
  { // Node ID: 3233 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2731out_result;

  { // Node ID: 2731 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2731in_a = id3233out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2731in_b = id3463out_output[getCycle()%2];

    id2731out_result = (eq_fixed(id2731in_a,id2731in_b));
  }
  { // Node ID: 3946 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3946in_input = id2731out_result;

    id3946out_output[(getCycle()+2)%3] = id3946in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1255out_o;

  { // Node ID: 1255 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1255in_i = id3946out_output[getCycle()%3];

    id1255out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1255in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1257out_result;

  { // Node ID: 1257 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1257in_a = id1256out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1257in_b = id1255out_o;

    id1257out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1257in_a,id1257in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1258out_result;

  { // Node ID: 1258 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1258in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1258in_option0 = id1257out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1258in_option1 = id1255out_o;

    HWOffsetFix<32,0,UNSIGNED> id1258x_1;

    switch((id1258in_sel.getValueAsLong())) {
      case 0l:
        id1258x_1 = id1258in_option0;
        break;
      case 1l:
        id1258x_1 = id1258in_option1;
        break;
      default:
        id1258x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1258out_result = (id1258x_1);
  }
  { // Node ID: 3945 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3945in_input = id1258out_result;

    id3945out_output[(getCycle()+1)%2] = id3945in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1244out_output;

  { // Node ID: 1244 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1244in_input = id3948out_output[getCycle()%2];

    id1244out_output = id1244in_input;
  }
  { // Node ID: 3232 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2732out_result;

  { // Node ID: 2732 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2732in_a = id3232out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2732in_b = id3463out_output[getCycle()%2];

    id2732out_result = (eq_fixed(id2732in_a,id2732in_b));
  }
  { // Node ID: 3949 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3949in_input = id2732out_result;

    id3949out_output[(getCycle()+2)%3] = id3949in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1243out_o;

  { // Node ID: 1243 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1243in_i = id3949out_output[getCycle()%3];

    id1243out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1243in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1245out_result;

  { // Node ID: 1245 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1245in_a = id1244out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1245in_b = id1243out_o;

    id1245out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1245in_a,id1245in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1246out_result;

  { // Node ID: 1246 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1246in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1246in_option0 = id1245out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1246in_option1 = id1243out_o;

    HWOffsetFix<32,0,UNSIGNED> id1246x_1;

    switch((id1246in_sel.getValueAsLong())) {
      case 0l:
        id1246x_1 = id1246in_option0;
        break;
      case 1l:
        id1246x_1 = id1246in_option1;
        break;
      default:
        id1246x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1246out_result = (id1246x_1);
  }
  { // Node ID: 3948 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3948in_input = id1246out_result;

    id3948out_output[(getCycle()+1)%2] = id3948in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1232out_output;

  { // Node ID: 1232 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1232in_input = id3951out_output[getCycle()%2];

    id1232out_output = id1232in_input;
  }
  { // Node ID: 3231 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2733out_result;

  { // Node ID: 2733 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2733in_a = id3231out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2733in_b = id3463out_output[getCycle()%2];

    id2733out_result = (eq_fixed(id2733in_a,id2733in_b));
  }
  { // Node ID: 3952 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3952in_input = id2733out_result;

    id3952out_output[(getCycle()+2)%3] = id3952in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1231out_o;

  { // Node ID: 1231 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1231in_i = id3952out_output[getCycle()%3];

    id1231out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1231in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1233out_result;

  { // Node ID: 1233 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1233in_a = id1232out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1233in_b = id1231out_o;

    id1233out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1233in_a,id1233in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1234out_result;

  { // Node ID: 1234 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1234in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1234in_option0 = id1233out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1234in_option1 = id1231out_o;

    HWOffsetFix<32,0,UNSIGNED> id1234x_1;

    switch((id1234in_sel.getValueAsLong())) {
      case 0l:
        id1234x_1 = id1234in_option0;
        break;
      case 1l:
        id1234x_1 = id1234in_option1;
        break;
      default:
        id1234x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1234out_result = (id1234x_1);
  }
  { // Node ID: 3951 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3951in_input = id1234out_result;

    id3951out_output[(getCycle()+1)%2] = id3951in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1220out_output;

  { // Node ID: 1220 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1220in_input = id3954out_output[getCycle()%2];

    id1220out_output = id1220in_input;
  }
  { // Node ID: 3230 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2734out_result;

  { // Node ID: 2734 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2734in_a = id3230out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2734in_b = id3463out_output[getCycle()%2];

    id2734out_result = (eq_fixed(id2734in_a,id2734in_b));
  }
  { // Node ID: 3955 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3955in_input = id2734out_result;

    id3955out_output[(getCycle()+2)%3] = id3955in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1219out_o;

  { // Node ID: 1219 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1219in_i = id3955out_output[getCycle()%3];

    id1219out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1219in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1221out_result;

  { // Node ID: 1221 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1221in_a = id1220out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1221in_b = id1219out_o;

    id1221out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1221in_a,id1221in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1222out_result;

  { // Node ID: 1222 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1222in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1222in_option0 = id1221out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1222in_option1 = id1219out_o;

    HWOffsetFix<32,0,UNSIGNED> id1222x_1;

    switch((id1222in_sel.getValueAsLong())) {
      case 0l:
        id1222x_1 = id1222in_option0;
        break;
      case 1l:
        id1222x_1 = id1222in_option1;
        break;
      default:
        id1222x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1222out_result = (id1222x_1);
  }
  { // Node ID: 3954 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3954in_input = id1222out_result;

    id3954out_output[(getCycle()+1)%2] = id3954in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1208out_output;

  { // Node ID: 1208 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1208in_input = id3957out_output[getCycle()%2];

    id1208out_output = id1208in_input;
  }
  { // Node ID: 3229 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2735out_result;

  { // Node ID: 2735 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2735in_a = id3229out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2735in_b = id3463out_output[getCycle()%2];

    id2735out_result = (eq_fixed(id2735in_a,id2735in_b));
  }
  { // Node ID: 3958 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3958in_input = id2735out_result;

    id3958out_output[(getCycle()+2)%3] = id3958in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1207out_o;

  { // Node ID: 1207 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1207in_i = id3958out_output[getCycle()%3];

    id1207out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1207in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1209out_result;

  { // Node ID: 1209 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1209in_a = id1208out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1209in_b = id1207out_o;

    id1209out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1209in_a,id1209in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1210out_result;

  { // Node ID: 1210 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1210in_sel = id3893out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1210in_option0 = id1209out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1210in_option1 = id1207out_o;

    HWOffsetFix<32,0,UNSIGNED> id1210x_1;

    switch((id1210in_sel.getValueAsLong())) {
      case 0l:
        id1210x_1 = id1210in_option0;
        break;
      case 1l:
        id1210x_1 = id1210in_option1;
        break;
      default:
        id1210x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1210out_result = (id1210x_1);
  }
  { // Node ID: 3957 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3957in_input = id1210out_result;

    id3957out_output[(getCycle()+1)%2] = id3957in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1196out_output;

  { // Node ID: 1196 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1196in_input = id3960out_output[getCycle()%2];

    id1196out_output = id1196in_input;
  }
  { // Node ID: 3228 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2736out_result;

  { // Node ID: 2736 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2736in_a = id3228out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2736in_b = id3463out_output[getCycle()%2];

    id2736out_result = (eq_fixed(id2736in_a,id2736in_b));
  }
  { // Node ID: 3961 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3961in_input = id2736out_result;

    id3961out_output[(getCycle()+2)%3] = id3961in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1195out_o;

  { // Node ID: 1195 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1195in_i = id3961out_output[getCycle()%3];

    id1195out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1195in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1197out_result;

  { // Node ID: 1197 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1197in_a = id1196out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1197in_b = id1195out_o;

    id1197out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1197in_a,id1197in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1198out_result;

  { // Node ID: 1198 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1198in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1198in_option0 = id1197out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1198in_option1 = id1195out_o;

    HWOffsetFix<32,0,UNSIGNED> id1198x_1;

    switch((id1198in_sel.getValueAsLong())) {
      case 0l:
        id1198x_1 = id1198in_option0;
        break;
      case 1l:
        id1198x_1 = id1198in_option1;
        break;
      default:
        id1198x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1198out_result = (id1198x_1);
  }
  { // Node ID: 3960 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3960in_input = id1198out_result;

    id3960out_output[(getCycle()+1)%2] = id3960in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1184out_output;

  { // Node ID: 1184 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1184in_input = id3963out_output[getCycle()%2];

    id1184out_output = id1184in_input;
  }
  { // Node ID: 3227 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2737out_result;

  { // Node ID: 2737 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2737in_a = id3227out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2737in_b = id3463out_output[getCycle()%2];

    id2737out_result = (eq_fixed(id2737in_a,id2737in_b));
  }
  { // Node ID: 3964 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3964in_input = id2737out_result;

    id3964out_output[(getCycle()+2)%3] = id3964in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1183out_o;

  { // Node ID: 1183 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1183in_i = id3964out_output[getCycle()%3];

    id1183out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1183in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1185out_result;

  { // Node ID: 1185 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1185in_a = id1184out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1185in_b = id1183out_o;

    id1185out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1185in_a,id1185in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1186out_result;

  { // Node ID: 1186 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1186in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1186in_option0 = id1185out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1186in_option1 = id1183out_o;

    HWOffsetFix<32,0,UNSIGNED> id1186x_1;

    switch((id1186in_sel.getValueAsLong())) {
      case 0l:
        id1186x_1 = id1186in_option0;
        break;
      case 1l:
        id1186x_1 = id1186in_option1;
        break;
      default:
        id1186x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1186out_result = (id1186x_1);
  }
  { // Node ID: 3963 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3963in_input = id1186out_result;

    id3963out_output[(getCycle()+1)%2] = id3963in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1172out_output;

  { // Node ID: 1172 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1172in_input = id3966out_output[getCycle()%2];

    id1172out_output = id1172in_input;
  }
  { // Node ID: 3226 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2738out_result;

  { // Node ID: 2738 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2738in_a = id3226out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2738in_b = id3463out_output[getCycle()%2];

    id2738out_result = (eq_fixed(id2738in_a,id2738in_b));
  }
  { // Node ID: 3967 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3967in_input = id2738out_result;

    id3967out_output[(getCycle()+2)%3] = id3967in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1171out_o;

  { // Node ID: 1171 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1171in_i = id3967out_output[getCycle()%3];

    id1171out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1171in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1173out_result;

  { // Node ID: 1173 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1173in_a = id1172out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1173in_b = id1171out_o;

    id1173out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1173in_a,id1173in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1174out_result;

  { // Node ID: 1174 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1174in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1174in_option0 = id1173out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1174in_option1 = id1171out_o;

    HWOffsetFix<32,0,UNSIGNED> id1174x_1;

    switch((id1174in_sel.getValueAsLong())) {
      case 0l:
        id1174x_1 = id1174in_option0;
        break;
      case 1l:
        id1174x_1 = id1174in_option1;
        break;
      default:
        id1174x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1174out_result = (id1174x_1);
  }
  { // Node ID: 3966 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3966in_input = id1174out_result;

    id3966out_output[(getCycle()+1)%2] = id3966in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1160out_output;

  { // Node ID: 1160 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1160in_input = id3969out_output[getCycle()%2];

    id1160out_output = id1160in_input;
  }
  { // Node ID: 3225 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2739out_result;

  { // Node ID: 2739 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2739in_a = id3225out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2739in_b = id3463out_output[getCycle()%2];

    id2739out_result = (eq_fixed(id2739in_a,id2739in_b));
  }
  { // Node ID: 3970 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3970in_input = id2739out_result;

    id3970out_output[(getCycle()+2)%3] = id3970in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1159out_o;

  { // Node ID: 1159 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1159in_i = id3970out_output[getCycle()%3];

    id1159out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1159in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1161out_result;

  { // Node ID: 1161 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1161in_a = id1160out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1161in_b = id1159out_o;

    id1161out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1161in_a,id1161in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1162out_result;

  { // Node ID: 1162 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1162in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1162in_option0 = id1161out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1162in_option1 = id1159out_o;

    HWOffsetFix<32,0,UNSIGNED> id1162x_1;

    switch((id1162in_sel.getValueAsLong())) {
      case 0l:
        id1162x_1 = id1162in_option0;
        break;
      case 1l:
        id1162x_1 = id1162in_option1;
        break;
      default:
        id1162x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1162out_result = (id1162x_1);
  }
  { // Node ID: 3969 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3969in_input = id1162out_result;

    id3969out_output[(getCycle()+1)%2] = id3969in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1148out_output;

  { // Node ID: 1148 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1148in_input = id3972out_output[getCycle()%2];

    id1148out_output = id1148in_input;
  }
  { // Node ID: 3224 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2740out_result;

  { // Node ID: 2740 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2740in_a = id3224out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2740in_b = id3463out_output[getCycle()%2];

    id2740out_result = (eq_fixed(id2740in_a,id2740in_b));
  }
  { // Node ID: 3973 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3973in_input = id2740out_result;

    id3973out_output[(getCycle()+2)%3] = id3973in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1147out_o;

  { // Node ID: 1147 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1147in_i = id3973out_output[getCycle()%3];

    id1147out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1147in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1149out_result;

  { // Node ID: 1149 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1149in_a = id1148out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1149in_b = id1147out_o;

    id1149out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1149in_a,id1149in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1150out_result;

  { // Node ID: 1150 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1150in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1150in_option0 = id1149out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1150in_option1 = id1147out_o;

    HWOffsetFix<32,0,UNSIGNED> id1150x_1;

    switch((id1150in_sel.getValueAsLong())) {
      case 0l:
        id1150x_1 = id1150in_option0;
        break;
      case 1l:
        id1150x_1 = id1150in_option1;
        break;
      default:
        id1150x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1150out_result = (id1150x_1);
  }
  { // Node ID: 3972 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3972in_input = id1150out_result;

    id3972out_output[(getCycle()+1)%2] = id3972in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1136out_output;

  { // Node ID: 1136 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1136in_input = id3975out_output[getCycle()%2];

    id1136out_output = id1136in_input;
  }
  { // Node ID: 3223 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2741out_result;

  { // Node ID: 2741 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2741in_a = id3223out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2741in_b = id3463out_output[getCycle()%2];

    id2741out_result = (eq_fixed(id2741in_a,id2741in_b));
  }
  { // Node ID: 3976 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3976in_input = id2741out_result;

    id3976out_output[(getCycle()+2)%3] = id3976in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1135out_o;

  { // Node ID: 1135 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1135in_i = id3976out_output[getCycle()%3];

    id1135out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1135in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1137out_result;

  { // Node ID: 1137 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1137in_a = id1136out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1137in_b = id1135out_o;

    id1137out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1137in_a,id1137in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1138out_result;

  { // Node ID: 1138 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1138in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1138in_option0 = id1137out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1138in_option1 = id1135out_o;

    HWOffsetFix<32,0,UNSIGNED> id1138x_1;

    switch((id1138in_sel.getValueAsLong())) {
      case 0l:
        id1138x_1 = id1138in_option0;
        break;
      case 1l:
        id1138x_1 = id1138in_option1;
        break;
      default:
        id1138x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1138out_result = (id1138x_1);
  }
  { // Node ID: 3975 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3975in_input = id1138out_result;

    id3975out_output[(getCycle()+1)%2] = id3975in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1124out_output;

  { // Node ID: 1124 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1124in_input = id3978out_output[getCycle()%2];

    id1124out_output = id1124in_input;
  }
  { // Node ID: 3222 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2742out_result;

  { // Node ID: 2742 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2742in_a = id3222out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2742in_b = id3463out_output[getCycle()%2];

    id2742out_result = (eq_fixed(id2742in_a,id2742in_b));
  }
  { // Node ID: 3979 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3979in_input = id2742out_result;

    id3979out_output[(getCycle()+2)%3] = id3979in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1123out_o;

  { // Node ID: 1123 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1123in_i = id3979out_output[getCycle()%3];

    id1123out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1123in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1125out_result;

  { // Node ID: 1125 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1125in_a = id1124out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1125in_b = id1123out_o;

    id1125out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1125in_a,id1125in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1126out_result;

  { // Node ID: 1126 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1126in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1126in_option0 = id1125out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1126in_option1 = id1123out_o;

    HWOffsetFix<32,0,UNSIGNED> id1126x_1;

    switch((id1126in_sel.getValueAsLong())) {
      case 0l:
        id1126x_1 = id1126in_option0;
        break;
      case 1l:
        id1126x_1 = id1126in_option1;
        break;
      default:
        id1126x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1126out_result = (id1126x_1);
  }
  { // Node ID: 3978 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3978in_input = id1126out_result;

    id3978out_output[(getCycle()+1)%2] = id3978in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1112out_output;

  { // Node ID: 1112 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1112in_input = id3981out_output[getCycle()%2];

    id1112out_output = id1112in_input;
  }
  { // Node ID: 3221 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2743out_result;

  { // Node ID: 2743 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2743in_a = id3221out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2743in_b = id3463out_output[getCycle()%2];

    id2743out_result = (eq_fixed(id2743in_a,id2743in_b));
  }
  { // Node ID: 3982 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3982in_input = id2743out_result;

    id3982out_output[(getCycle()+2)%3] = id3982in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1111out_o;

  { // Node ID: 1111 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1111in_i = id3982out_output[getCycle()%3];

    id1111out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1111in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1113out_result;

  { // Node ID: 1113 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1113in_a = id1112out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1113in_b = id1111out_o;

    id1113out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1113in_a,id1113in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1114out_result;

  { // Node ID: 1114 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1114in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1114in_option0 = id1113out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1114in_option1 = id1111out_o;

    HWOffsetFix<32,0,UNSIGNED> id1114x_1;

    switch((id1114in_sel.getValueAsLong())) {
      case 0l:
        id1114x_1 = id1114in_option0;
        break;
      case 1l:
        id1114x_1 = id1114in_option1;
        break;
      default:
        id1114x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1114out_result = (id1114x_1);
  }
  { // Node ID: 3981 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3981in_input = id1114out_result;

    id3981out_output[(getCycle()+1)%2] = id3981in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1100out_output;

  { // Node ID: 1100 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1100in_input = id3984out_output[getCycle()%2];

    id1100out_output = id1100in_input;
  }
  { // Node ID: 3220 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2744out_result;

  { // Node ID: 2744 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2744in_a = id3220out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2744in_b = id3463out_output[getCycle()%2];

    id2744out_result = (eq_fixed(id2744in_a,id2744in_b));
  }
  { // Node ID: 3985 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3985in_input = id2744out_result;

    id3985out_output[(getCycle()+2)%3] = id3985in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1099out_o;

  { // Node ID: 1099 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1099in_i = id3985out_output[getCycle()%3];

    id1099out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1099in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1101out_result;

  { // Node ID: 1101 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1101in_a = id1100out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1101in_b = id1099out_o;

    id1101out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1101in_a,id1101in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1102out_result;

  { // Node ID: 1102 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1102in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1102in_option0 = id1101out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1102in_option1 = id1099out_o;

    HWOffsetFix<32,0,UNSIGNED> id1102x_1;

    switch((id1102in_sel.getValueAsLong())) {
      case 0l:
        id1102x_1 = id1102in_option0;
        break;
      case 1l:
        id1102x_1 = id1102in_option1;
        break;
      default:
        id1102x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1102out_result = (id1102x_1);
  }
  { // Node ID: 3984 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3984in_input = id1102out_result;

    id3984out_output[(getCycle()+1)%2] = id3984in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1088out_output;

  { // Node ID: 1088 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1088in_input = id3987out_output[getCycle()%2];

    id1088out_output = id1088in_input;
  }
  { // Node ID: 3219 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2745out_result;

  { // Node ID: 2745 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2745in_a = id3219out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2745in_b = id3463out_output[getCycle()%2];

    id2745out_result = (eq_fixed(id2745in_a,id2745in_b));
  }
  { // Node ID: 3988 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3988in_input = id2745out_result;

    id3988out_output[(getCycle()+2)%3] = id3988in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1087out_o;

  { // Node ID: 1087 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1087in_i = id3988out_output[getCycle()%3];

    id1087out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1087in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1089out_result;

  { // Node ID: 1089 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1089in_a = id1088out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1089in_b = id1087out_o;

    id1089out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1089in_a,id1089in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1090out_result;

  { // Node ID: 1090 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1090in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1090in_option0 = id1089out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1090in_option1 = id1087out_o;

    HWOffsetFix<32,0,UNSIGNED> id1090x_1;

    switch((id1090in_sel.getValueAsLong())) {
      case 0l:
        id1090x_1 = id1090in_option0;
        break;
      case 1l:
        id1090x_1 = id1090in_option1;
        break;
      default:
        id1090x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1090out_result = (id1090x_1);
  }
  { // Node ID: 3987 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3987in_input = id1090out_result;

    id3987out_output[(getCycle()+1)%2] = id3987in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1076out_output;

  { // Node ID: 1076 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1076in_input = id3990out_output[getCycle()%2];

    id1076out_output = id1076in_input;
  }
  { // Node ID: 3218 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2746out_result;

  { // Node ID: 2746 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2746in_a = id3218out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2746in_b = id3463out_output[getCycle()%2];

    id2746out_result = (eq_fixed(id2746in_a,id2746in_b));
  }
  { // Node ID: 3991 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3991in_input = id2746out_result;

    id3991out_output[(getCycle()+2)%3] = id3991in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1075out_o;

  { // Node ID: 1075 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1075in_i = id3991out_output[getCycle()%3];

    id1075out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1075in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1077out_result;

  { // Node ID: 1077 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1077in_a = id1076out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1077in_b = id1075out_o;

    id1077out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1077in_a,id1077in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1078out_result;

  { // Node ID: 1078 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1078in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1078in_option0 = id1077out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1078in_option1 = id1075out_o;

    HWOffsetFix<32,0,UNSIGNED> id1078x_1;

    switch((id1078in_sel.getValueAsLong())) {
      case 0l:
        id1078x_1 = id1078in_option0;
        break;
      case 1l:
        id1078x_1 = id1078in_option1;
        break;
      default:
        id1078x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1078out_result = (id1078x_1);
  }
  { // Node ID: 3990 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3990in_input = id1078out_result;

    id3990out_output[(getCycle()+1)%2] = id3990in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1064out_output;

  { // Node ID: 1064 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1064in_input = id3993out_output[getCycle()%2];

    id1064out_output = id1064in_input;
  }
  { // Node ID: 3217 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2747out_result;

  { // Node ID: 2747 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2747in_a = id3217out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2747in_b = id3463out_output[getCycle()%2];

    id2747out_result = (eq_fixed(id2747in_a,id2747in_b));
  }
  { // Node ID: 3994 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3994in_input = id2747out_result;

    id3994out_output[(getCycle()+2)%3] = id3994in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1063out_o;

  { // Node ID: 1063 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1063in_i = id3994out_output[getCycle()%3];

    id1063out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1063in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1065out_result;

  { // Node ID: 1065 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1065in_a = id1064out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1065in_b = id1063out_o;

    id1065out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1065in_a,id1065in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1066out_result;

  { // Node ID: 1066 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1066in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1066in_option0 = id1065out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1066in_option1 = id1063out_o;

    HWOffsetFix<32,0,UNSIGNED> id1066x_1;

    switch((id1066in_sel.getValueAsLong())) {
      case 0l:
        id1066x_1 = id1066in_option0;
        break;
      case 1l:
        id1066x_1 = id1066in_option1;
        break;
      default:
        id1066x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1066out_result = (id1066x_1);
  }
  { // Node ID: 3993 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3993in_input = id1066out_result;

    id3993out_output[(getCycle()+1)%2] = id3993in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1052out_output;

  { // Node ID: 1052 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1052in_input = id3996out_output[getCycle()%2];

    id1052out_output = id1052in_input;
  }
  { // Node ID: 3216 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2748out_result;

  { // Node ID: 2748 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2748in_a = id3216out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2748in_b = id3463out_output[getCycle()%2];

    id2748out_result = (eq_fixed(id2748in_a,id2748in_b));
  }
  { // Node ID: 3997 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3997in_input = id2748out_result;

    id3997out_output[(getCycle()+2)%3] = id3997in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1051out_o;

  { // Node ID: 1051 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1051in_i = id3997out_output[getCycle()%3];

    id1051out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1051in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1053out_result;

  { // Node ID: 1053 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1053in_a = id1052out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1053in_b = id1051out_o;

    id1053out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1053in_a,id1053in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1054out_result;

  { // Node ID: 1054 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1054in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1054in_option0 = id1053out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1054in_option1 = id1051out_o;

    HWOffsetFix<32,0,UNSIGNED> id1054x_1;

    switch((id1054in_sel.getValueAsLong())) {
      case 0l:
        id1054x_1 = id1054in_option0;
        break;
      case 1l:
        id1054x_1 = id1054in_option1;
        break;
      default:
        id1054x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1054out_result = (id1054x_1);
  }
  { // Node ID: 3996 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3996in_input = id1054out_result;

    id3996out_output[(getCycle()+1)%2] = id3996in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1040out_output;

  { // Node ID: 1040 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1040in_input = id3999out_output[getCycle()%2];

    id1040out_output = id1040in_input;
  }
  { // Node ID: 3215 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2749out_result;

  { // Node ID: 2749 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2749in_a = id3215out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2749in_b = id3463out_output[getCycle()%2];

    id2749out_result = (eq_fixed(id2749in_a,id2749in_b));
  }
  { // Node ID: 4000 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4000in_input = id2749out_result;

    id4000out_output[(getCycle()+2)%3] = id4000in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1039out_o;

  { // Node ID: 1039 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1039in_i = id4000out_output[getCycle()%3];

    id1039out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1039in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1041out_result;

  { // Node ID: 1041 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1041in_a = id1040out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1041in_b = id1039out_o;

    id1041out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1041in_a,id1041in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1042out_result;

  { // Node ID: 1042 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1042in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1042in_option0 = id1041out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1042in_option1 = id1039out_o;

    HWOffsetFix<32,0,UNSIGNED> id1042x_1;

    switch((id1042in_sel.getValueAsLong())) {
      case 0l:
        id1042x_1 = id1042in_option0;
        break;
      case 1l:
        id1042x_1 = id1042in_option1;
        break;
      default:
        id1042x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1042out_result = (id1042x_1);
  }
  { // Node ID: 3999 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3999in_input = id1042out_result;

    id3999out_output[(getCycle()+1)%2] = id3999in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1028out_output;

  { // Node ID: 1028 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1028in_input = id4002out_output[getCycle()%2];

    id1028out_output = id1028in_input;
  }
  { // Node ID: 3214 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2750out_result;

  { // Node ID: 2750 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2750in_a = id3214out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2750in_b = id3463out_output[getCycle()%2];

    id2750out_result = (eq_fixed(id2750in_a,id2750in_b));
  }
  { // Node ID: 4003 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4003in_input = id2750out_result;

    id4003out_output[(getCycle()+2)%3] = id4003in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1027out_o;

  { // Node ID: 1027 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1027in_i = id4003out_output[getCycle()%3];

    id1027out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1027in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1029out_result;

  { // Node ID: 1029 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1029in_a = id1028out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1029in_b = id1027out_o;

    id1029out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1029in_a,id1029in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1030out_result;

  { // Node ID: 1030 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1030in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1030in_option0 = id1029out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1030in_option1 = id1027out_o;

    HWOffsetFix<32,0,UNSIGNED> id1030x_1;

    switch((id1030in_sel.getValueAsLong())) {
      case 0l:
        id1030x_1 = id1030in_option0;
        break;
      case 1l:
        id1030x_1 = id1030in_option1;
        break;
      default:
        id1030x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1030out_result = (id1030x_1);
  }
  { // Node ID: 4002 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4002in_input = id1030out_result;

    id4002out_output[(getCycle()+1)%2] = id4002in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1016out_output;

  { // Node ID: 1016 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1016in_input = id4005out_output[getCycle()%2];

    id1016out_output = id1016in_input;
  }
  { // Node ID: 3213 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2751out_result;

  { // Node ID: 2751 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2751in_a = id3213out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2751in_b = id3463out_output[getCycle()%2];

    id2751out_result = (eq_fixed(id2751in_a,id2751in_b));
  }
  { // Node ID: 4006 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4006in_input = id2751out_result;

    id4006out_output[(getCycle()+2)%3] = id4006in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1015out_o;

  { // Node ID: 1015 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1015in_i = id4006out_output[getCycle()%3];

    id1015out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1015in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1017out_result;

  { // Node ID: 1017 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1017in_a = id1016out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1017in_b = id1015out_o;

    id1017out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1017in_a,id1017in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1018out_result;

  { // Node ID: 1018 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1018in_sel = id3962out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1018in_option0 = id1017out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1018in_option1 = id1015out_o;

    HWOffsetFix<32,0,UNSIGNED> id1018x_1;

    switch((id1018in_sel.getValueAsLong())) {
      case 0l:
        id1018x_1 = id1018in_option0;
        break;
      case 1l:
        id1018x_1 = id1018in_option1;
        break;
      default:
        id1018x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1018out_result = (id1018x_1);
  }
  { // Node ID: 4005 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4005in_input = id1018out_result;

    id4005out_output[(getCycle()+1)%2] = id4005in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1004out_output;

  { // Node ID: 1004 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1004in_input = id4008out_output[getCycle()%2];

    id1004out_output = id1004in_input;
  }
  { // Node ID: 3212 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2752out_result;

  { // Node ID: 2752 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2752in_a = id3212out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2752in_b = id3463out_output[getCycle()%2];

    id2752out_result = (eq_fixed(id2752in_a,id2752in_b));
  }
  { // Node ID: 4009 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4009in_input = id2752out_result;

    id4009out_output[(getCycle()+2)%3] = id4009in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1003out_o;

  { // Node ID: 1003 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1003in_i = id4009out_output[getCycle()%3];

    id1003out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1003in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1005out_result;

  { // Node ID: 1005 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1005in_a = id1004out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1005in_b = id1003out_o;

    id1005out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1005in_a,id1005in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1006out_result;

  { // Node ID: 1006 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1006in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id1006in_option0 = id1005out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1006in_option1 = id1003out_o;

    HWOffsetFix<32,0,UNSIGNED> id1006x_1;

    switch((id1006in_sel.getValueAsLong())) {
      case 0l:
        id1006x_1 = id1006in_option0;
        break;
      case 1l:
        id1006x_1 = id1006in_option1;
        break;
      default:
        id1006x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1006out_result = (id1006x_1);
  }
  { // Node ID: 4008 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4008in_input = id1006out_result;

    id4008out_output[(getCycle()+1)%2] = id4008in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id992out_output;

  { // Node ID: 992 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id992in_input = id4011out_output[getCycle()%2];

    id992out_output = id992in_input;
  }
  { // Node ID: 3211 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2753out_result;

  { // Node ID: 2753 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2753in_a = id3211out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2753in_b = id3463out_output[getCycle()%2];

    id2753out_result = (eq_fixed(id2753in_a,id2753in_b));
  }
  { // Node ID: 4012 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4012in_input = id2753out_result;

    id4012out_output[(getCycle()+2)%3] = id4012in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id991out_o;

  { // Node ID: 991 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id991in_i = id4012out_output[getCycle()%3];

    id991out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id991in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id993out_result;

  { // Node ID: 993 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id993in_a = id992out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id993in_b = id991out_o;

    id993out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id993in_a,id993in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id994out_result;

  { // Node ID: 994 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id994in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id994in_option0 = id993out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id994in_option1 = id991out_o;

    HWOffsetFix<32,0,UNSIGNED> id994x_1;

    switch((id994in_sel.getValueAsLong())) {
      case 0l:
        id994x_1 = id994in_option0;
        break;
      case 1l:
        id994x_1 = id994in_option1;
        break;
      default:
        id994x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id994out_result = (id994x_1);
  }
  { // Node ID: 4011 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4011in_input = id994out_result;

    id4011out_output[(getCycle()+1)%2] = id4011in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id980out_output;

  { // Node ID: 980 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id980in_input = id4014out_output[getCycle()%2];

    id980out_output = id980in_input;
  }
  { // Node ID: 3210 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2754out_result;

  { // Node ID: 2754 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2754in_a = id3210out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2754in_b = id3464out_output[getCycle()%2];

    id2754out_result = (eq_fixed(id2754in_a,id2754in_b));
  }
  { // Node ID: 4015 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4015in_input = id2754out_result;

    id4015out_output[(getCycle()+3)%4] = id4015in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id979out_o;

  { // Node ID: 979 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id979in_i = id4015out_output[getCycle()%4];

    id979out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id979in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id981out_result;

  { // Node ID: 981 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id981in_a = id980out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id981in_b = id979out_o;

    id981out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id981in_a,id981in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id982out_result;

  { // Node ID: 982 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id982in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id982in_option0 = id981out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id982in_option1 = id979out_o;

    HWOffsetFix<32,0,UNSIGNED> id982x_1;

    switch((id982in_sel.getValueAsLong())) {
      case 0l:
        id982x_1 = id982in_option0;
        break;
      case 1l:
        id982x_1 = id982in_option1;
        break;
      default:
        id982x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id982out_result = (id982x_1);
  }
  { // Node ID: 4014 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4014in_input = id982out_result;

    id4014out_output[(getCycle()+1)%2] = id4014in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id968out_output;

  { // Node ID: 968 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id968in_input = id4017out_output[getCycle()%2];

    id968out_output = id968in_input;
  }
  { // Node ID: 3209 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2755out_result;

  { // Node ID: 2755 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2755in_a = id3209out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2755in_b = id3464out_output[getCycle()%2];

    id2755out_result = (eq_fixed(id2755in_a,id2755in_b));
  }
  { // Node ID: 4018 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4018in_input = id2755out_result;

    id4018out_output[(getCycle()+3)%4] = id4018in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id967out_o;

  { // Node ID: 967 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id967in_i = id4018out_output[getCycle()%4];

    id967out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id967in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id969out_result;

  { // Node ID: 969 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id969in_a = id968out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id969in_b = id967out_o;

    id969out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id969in_a,id969in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id970out_result;

  { // Node ID: 970 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id970in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id970in_option0 = id969out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id970in_option1 = id967out_o;

    HWOffsetFix<32,0,UNSIGNED> id970x_1;

    switch((id970in_sel.getValueAsLong())) {
      case 0l:
        id970x_1 = id970in_option0;
        break;
      case 1l:
        id970x_1 = id970in_option1;
        break;
      default:
        id970x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id970out_result = (id970x_1);
  }
  { // Node ID: 4017 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4017in_input = id970out_result;

    id4017out_output[(getCycle()+1)%2] = id4017in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id956out_output;

  { // Node ID: 956 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id956in_input = id4020out_output[getCycle()%2];

    id956out_output = id956in_input;
  }
  { // Node ID: 3208 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2756out_result;

  { // Node ID: 2756 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2756in_a = id3208out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2756in_b = id3464out_output[getCycle()%2];

    id2756out_result = (eq_fixed(id2756in_a,id2756in_b));
  }
  { // Node ID: 4021 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4021in_input = id2756out_result;

    id4021out_output[(getCycle()+3)%4] = id4021in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id955out_o;

  { // Node ID: 955 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id955in_i = id4021out_output[getCycle()%4];

    id955out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id955in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id957out_result;

  { // Node ID: 957 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id957in_a = id956out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id957in_b = id955out_o;

    id957out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id957in_a,id957in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id958out_result;

  { // Node ID: 958 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id958in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id958in_option0 = id957out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id958in_option1 = id955out_o;

    HWOffsetFix<32,0,UNSIGNED> id958x_1;

    switch((id958in_sel.getValueAsLong())) {
      case 0l:
        id958x_1 = id958in_option0;
        break;
      case 1l:
        id958x_1 = id958in_option1;
        break;
      default:
        id958x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id958out_result = (id958x_1);
  }
  { // Node ID: 4020 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4020in_input = id958out_result;

    id4020out_output[(getCycle()+1)%2] = id4020in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id944out_output;

  { // Node ID: 944 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id944in_input = id4023out_output[getCycle()%2];

    id944out_output = id944in_input;
  }
  { // Node ID: 3207 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2757out_result;

  { // Node ID: 2757 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2757in_a = id3207out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2757in_b = id3464out_output[getCycle()%2];

    id2757out_result = (eq_fixed(id2757in_a,id2757in_b));
  }
  { // Node ID: 4024 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4024in_input = id2757out_result;

    id4024out_output[(getCycle()+3)%4] = id4024in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id943out_o;

  { // Node ID: 943 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id943in_i = id4024out_output[getCycle()%4];

    id943out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id943in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id945out_result;

  { // Node ID: 945 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id945in_a = id944out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id945in_b = id943out_o;

    id945out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id945in_a,id945in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id946out_result;

  { // Node ID: 946 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id946in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id946in_option0 = id945out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id946in_option1 = id943out_o;

    HWOffsetFix<32,0,UNSIGNED> id946x_1;

    switch((id946in_sel.getValueAsLong())) {
      case 0l:
        id946x_1 = id946in_option0;
        break;
      case 1l:
        id946x_1 = id946in_option1;
        break;
      default:
        id946x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id946out_result = (id946x_1);
  }
  { // Node ID: 4023 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4023in_input = id946out_result;

    id4023out_output[(getCycle()+1)%2] = id4023in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id932out_output;

  { // Node ID: 932 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id932in_input = id4026out_output[getCycle()%2];

    id932out_output = id932in_input;
  }
  { // Node ID: 3206 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2758out_result;

  { // Node ID: 2758 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2758in_a = id3206out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2758in_b = id3464out_output[getCycle()%2];

    id2758out_result = (eq_fixed(id2758in_a,id2758in_b));
  }
  { // Node ID: 4027 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4027in_input = id2758out_result;

    id4027out_output[(getCycle()+3)%4] = id4027in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id931out_o;

  { // Node ID: 931 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id931in_i = id4027out_output[getCycle()%4];

    id931out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id931in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id933out_result;

  { // Node ID: 933 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id933in_a = id932out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id933in_b = id931out_o;

    id933out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id933in_a,id933in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id934out_result;

  { // Node ID: 934 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id934in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id934in_option0 = id933out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id934in_option1 = id931out_o;

    HWOffsetFix<32,0,UNSIGNED> id934x_1;

    switch((id934in_sel.getValueAsLong())) {
      case 0l:
        id934x_1 = id934in_option0;
        break;
      case 1l:
        id934x_1 = id934in_option1;
        break;
      default:
        id934x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id934out_result = (id934x_1);
  }
  { // Node ID: 4026 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4026in_input = id934out_result;

    id4026out_output[(getCycle()+1)%2] = id4026in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id920out_output;

  { // Node ID: 920 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id920in_input = id4029out_output[getCycle()%2];

    id920out_output = id920in_input;
  }
  { // Node ID: 3205 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2759out_result;

  { // Node ID: 2759 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2759in_a = id3205out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2759in_b = id3464out_output[getCycle()%2];

    id2759out_result = (eq_fixed(id2759in_a,id2759in_b));
  }
  { // Node ID: 4030 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4030in_input = id2759out_result;

    id4030out_output[(getCycle()+3)%4] = id4030in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id919out_o;

  { // Node ID: 919 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id919in_i = id4030out_output[getCycle()%4];

    id919out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id919in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id921out_result;

  { // Node ID: 921 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id921in_a = id920out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id921in_b = id919out_o;

    id921out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id921in_a,id921in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id922out_result;

  { // Node ID: 922 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id922in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id922in_option0 = id921out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id922in_option1 = id919out_o;

    HWOffsetFix<32,0,UNSIGNED> id922x_1;

    switch((id922in_sel.getValueAsLong())) {
      case 0l:
        id922x_1 = id922in_option0;
        break;
      case 1l:
        id922x_1 = id922in_option1;
        break;
      default:
        id922x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id922out_result = (id922x_1);
  }
  { // Node ID: 4029 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4029in_input = id922out_result;

    id4029out_output[(getCycle()+1)%2] = id4029in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id908out_output;

  { // Node ID: 908 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id908in_input = id4032out_output[getCycle()%2];

    id908out_output = id908in_input;
  }
  { // Node ID: 3204 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2760out_result;

  { // Node ID: 2760 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2760in_a = id3204out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2760in_b = id3464out_output[getCycle()%2];

    id2760out_result = (eq_fixed(id2760in_a,id2760in_b));
  }
  { // Node ID: 4033 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4033in_input = id2760out_result;

    id4033out_output[(getCycle()+3)%4] = id4033in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id907out_o;

  { // Node ID: 907 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id907in_i = id4033out_output[getCycle()%4];

    id907out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id907in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id909out_result;

  { // Node ID: 909 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id909in_a = id908out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id909in_b = id907out_o;

    id909out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id909in_a,id909in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id910out_result;

  { // Node ID: 910 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id910in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id910in_option0 = id909out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id910in_option1 = id907out_o;

    HWOffsetFix<32,0,UNSIGNED> id910x_1;

    switch((id910in_sel.getValueAsLong())) {
      case 0l:
        id910x_1 = id910in_option0;
        break;
      case 1l:
        id910x_1 = id910in_option1;
        break;
      default:
        id910x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id910out_result = (id910x_1);
  }
  { // Node ID: 4032 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4032in_input = id910out_result;

    id4032out_output[(getCycle()+1)%2] = id4032in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id896out_output;

  { // Node ID: 896 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id896in_input = id4035out_output[getCycle()%2];

    id896out_output = id896in_input;
  }
  { // Node ID: 3203 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2761out_result;

  { // Node ID: 2761 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2761in_a = id3203out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2761in_b = id3464out_output[getCycle()%2];

    id2761out_result = (eq_fixed(id2761in_a,id2761in_b));
  }
  { // Node ID: 4036 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4036in_input = id2761out_result;

    id4036out_output[(getCycle()+3)%4] = id4036in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id895out_o;

  { // Node ID: 895 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id895in_i = id4036out_output[getCycle()%4];

    id895out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id895in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id897out_result;

  { // Node ID: 897 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id897in_a = id896out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id897in_b = id895out_o;

    id897out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id897in_a,id897in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id898out_result;

  { // Node ID: 898 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id898in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id898in_option0 = id897out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id898in_option1 = id895out_o;

    HWOffsetFix<32,0,UNSIGNED> id898x_1;

    switch((id898in_sel.getValueAsLong())) {
      case 0l:
        id898x_1 = id898in_option0;
        break;
      case 1l:
        id898x_1 = id898in_option1;
        break;
      default:
        id898x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id898out_result = (id898x_1);
  }
  { // Node ID: 4035 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4035in_input = id898out_result;

    id4035out_output[(getCycle()+1)%2] = id4035in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id884out_output;

  { // Node ID: 884 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id884in_input = id4038out_output[getCycle()%2];

    id884out_output = id884in_input;
  }
  { // Node ID: 3202 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2762out_result;

  { // Node ID: 2762 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2762in_a = id3202out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2762in_b = id3464out_output[getCycle()%2];

    id2762out_result = (eq_fixed(id2762in_a,id2762in_b));
  }
  { // Node ID: 4039 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4039in_input = id2762out_result;

    id4039out_output[(getCycle()+3)%4] = id4039in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id883out_o;

  { // Node ID: 883 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id883in_i = id4039out_output[getCycle()%4];

    id883out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id883in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id885out_result;

  { // Node ID: 885 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id885in_a = id884out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id885in_b = id883out_o;

    id885out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id885in_a,id885in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id886out_result;

  { // Node ID: 886 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id886in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id886in_option0 = id885out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id886in_option1 = id883out_o;

    HWOffsetFix<32,0,UNSIGNED> id886x_1;

    switch((id886in_sel.getValueAsLong())) {
      case 0l:
        id886x_1 = id886in_option0;
        break;
      case 1l:
        id886x_1 = id886in_option1;
        break;
      default:
        id886x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id886out_result = (id886x_1);
  }
  { // Node ID: 4038 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4038in_input = id886out_result;

    id4038out_output[(getCycle()+1)%2] = id4038in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id872out_output;

  { // Node ID: 872 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id872in_input = id4041out_output[getCycle()%2];

    id872out_output = id872in_input;
  }
  { // Node ID: 3201 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2763out_result;

  { // Node ID: 2763 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2763in_a = id3201out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2763in_b = id3464out_output[getCycle()%2];

    id2763out_result = (eq_fixed(id2763in_a,id2763in_b));
  }
  { // Node ID: 4042 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4042in_input = id2763out_result;

    id4042out_output[(getCycle()+3)%4] = id4042in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id871out_o;

  { // Node ID: 871 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id871in_i = id4042out_output[getCycle()%4];

    id871out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id871in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id873out_result;

  { // Node ID: 873 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id873in_a = id872out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id873in_b = id871out_o;

    id873out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id873in_a,id873in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id874out_result;

  { // Node ID: 874 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id874in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id874in_option0 = id873out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id874in_option1 = id871out_o;

    HWOffsetFix<32,0,UNSIGNED> id874x_1;

    switch((id874in_sel.getValueAsLong())) {
      case 0l:
        id874x_1 = id874in_option0;
        break;
      case 1l:
        id874x_1 = id874in_option1;
        break;
      default:
        id874x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id874out_result = (id874x_1);
  }
  { // Node ID: 4041 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4041in_input = id874out_result;

    id4041out_output[(getCycle()+1)%2] = id4041in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id860out_output;

  { // Node ID: 860 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id860in_input = id4044out_output[getCycle()%2];

    id860out_output = id860in_input;
  }
  { // Node ID: 3200 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2764out_result;

  { // Node ID: 2764 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2764in_a = id3200out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2764in_b = id3464out_output[getCycle()%2];

    id2764out_result = (eq_fixed(id2764in_a,id2764in_b));
  }
  { // Node ID: 4045 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4045in_input = id2764out_result;

    id4045out_output[(getCycle()+3)%4] = id4045in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id859out_o;

  { // Node ID: 859 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id859in_i = id4045out_output[getCycle()%4];

    id859out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id859in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id861out_result;

  { // Node ID: 861 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id861in_a = id860out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id861in_b = id859out_o;

    id861out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id861in_a,id861in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id862out_result;

  { // Node ID: 862 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id862in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id862in_option0 = id861out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id862in_option1 = id859out_o;

    HWOffsetFix<32,0,UNSIGNED> id862x_1;

    switch((id862in_sel.getValueAsLong())) {
      case 0l:
        id862x_1 = id862in_option0;
        break;
      case 1l:
        id862x_1 = id862in_option1;
        break;
      default:
        id862x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id862out_result = (id862x_1);
  }
  { // Node ID: 4044 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4044in_input = id862out_result;

    id4044out_output[(getCycle()+1)%2] = id4044in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id848out_output;

  { // Node ID: 848 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id848in_input = id4047out_output[getCycle()%2];

    id848out_output = id848in_input;
  }
  { // Node ID: 3199 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2765out_result;

  { // Node ID: 2765 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2765in_a = id3199out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2765in_b = id3464out_output[getCycle()%2];

    id2765out_result = (eq_fixed(id2765in_a,id2765in_b));
  }
  { // Node ID: 4048 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4048in_input = id2765out_result;

    id4048out_output[(getCycle()+3)%4] = id4048in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id847out_o;

  { // Node ID: 847 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id847in_i = id4048out_output[getCycle()%4];

    id847out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id847in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id849out_result;

  { // Node ID: 849 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id849in_a = id848out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id849in_b = id847out_o;

    id849out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id849in_a,id849in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id850out_result;

  { // Node ID: 850 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id850in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id850in_option0 = id849out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id850in_option1 = id847out_o;

    HWOffsetFix<32,0,UNSIGNED> id850x_1;

    switch((id850in_sel.getValueAsLong())) {
      case 0l:
        id850x_1 = id850in_option0;
        break;
      case 1l:
        id850x_1 = id850in_option1;
        break;
      default:
        id850x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id850out_result = (id850x_1);
  }
  { // Node ID: 4047 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4047in_input = id850out_result;

    id4047out_output[(getCycle()+1)%2] = id4047in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id836out_output;

  { // Node ID: 836 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id836in_input = id4050out_output[getCycle()%2];

    id836out_output = id836in_input;
  }
  { // Node ID: 3198 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2766out_result;

  { // Node ID: 2766 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2766in_a = id3198out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2766in_b = id3464out_output[getCycle()%2];

    id2766out_result = (eq_fixed(id2766in_a,id2766in_b));
  }
  { // Node ID: 4051 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4051in_input = id2766out_result;

    id4051out_output[(getCycle()+3)%4] = id4051in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id835out_o;

  { // Node ID: 835 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id835in_i = id4051out_output[getCycle()%4];

    id835out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id835in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id837out_result;

  { // Node ID: 837 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id837in_a = id836out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id837in_b = id835out_o;

    id837out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id837in_a,id837in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id838out_result;

  { // Node ID: 838 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id838in_sel = id3542out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id838in_option0 = id837out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id838in_option1 = id835out_o;

    HWOffsetFix<32,0,UNSIGNED> id838x_1;

    switch((id838in_sel.getValueAsLong())) {
      case 0l:
        id838x_1 = id838in_option0;
        break;
      case 1l:
        id838x_1 = id838in_option1;
        break;
      default:
        id838x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id838out_result = (id838x_1);
  }
  { // Node ID: 4050 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4050in_input = id838out_result;

    id4050out_output[(getCycle()+1)%2] = id4050in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id824out_output;

  { // Node ID: 824 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id824in_input = id4053out_output[getCycle()%2];

    id824out_output = id824in_input;
  }
  { // Node ID: 3197 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2767out_result;

  { // Node ID: 2767 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2767in_a = id3197out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2767in_b = id3464out_output[getCycle()%2];

    id2767out_result = (eq_fixed(id2767in_a,id2767in_b));
  }
  { // Node ID: 4054 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4054in_input = id2767out_result;

    id4054out_output[(getCycle()+3)%4] = id4054in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id823out_o;

  { // Node ID: 823 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id823in_i = id4054out_output[getCycle()%4];

    id823out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id823in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id825out_result;

  { // Node ID: 825 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id825in_a = id824out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id825in_b = id823out_o;

    id825out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id825in_a,id825in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id826out_result;

  { // Node ID: 826 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id826in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id826in_option0 = id825out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id826in_option1 = id823out_o;

    HWOffsetFix<32,0,UNSIGNED> id826x_1;

    switch((id826in_sel.getValueAsLong())) {
      case 0l:
        id826x_1 = id826in_option0;
        break;
      case 1l:
        id826x_1 = id826in_option1;
        break;
      default:
        id826x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id826out_result = (id826x_1);
  }
  { // Node ID: 4053 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4053in_input = id826out_result;

    id4053out_output[(getCycle()+1)%2] = id4053in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id812out_output;

  { // Node ID: 812 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id812in_input = id4056out_output[getCycle()%2];

    id812out_output = id812in_input;
  }
  { // Node ID: 3196 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2768out_result;

  { // Node ID: 2768 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2768in_a = id3196out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2768in_b = id3464out_output[getCycle()%2];

    id2768out_result = (eq_fixed(id2768in_a,id2768in_b));
  }
  { // Node ID: 4057 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4057in_input = id2768out_result;

    id4057out_output[(getCycle()+3)%4] = id4057in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id811out_o;

  { // Node ID: 811 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id811in_i = id4057out_output[getCycle()%4];

    id811out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id811in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id813out_result;

  { // Node ID: 813 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id813in_a = id812out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id813in_b = id811out_o;

    id813out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id813in_a,id813in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id814out_result;

  { // Node ID: 814 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id814in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id814in_option0 = id813out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id814in_option1 = id811out_o;

    HWOffsetFix<32,0,UNSIGNED> id814x_1;

    switch((id814in_sel.getValueAsLong())) {
      case 0l:
        id814x_1 = id814in_option0;
        break;
      case 1l:
        id814x_1 = id814in_option1;
        break;
      default:
        id814x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id814out_result = (id814x_1);
  }
  { // Node ID: 4056 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4056in_input = id814out_result;

    id4056out_output[(getCycle()+1)%2] = id4056in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id800out_output;

  { // Node ID: 800 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id800in_input = id4059out_output[getCycle()%2];

    id800out_output = id800in_input;
  }
  { // Node ID: 3195 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2769out_result;

  { // Node ID: 2769 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2769in_a = id3195out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2769in_b = id3464out_output[getCycle()%2];

    id2769out_result = (eq_fixed(id2769in_a,id2769in_b));
  }
  { // Node ID: 4060 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4060in_input = id2769out_result;

    id4060out_output[(getCycle()+3)%4] = id4060in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id799out_o;

  { // Node ID: 799 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id799in_i = id4060out_output[getCycle()%4];

    id799out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id799in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id801out_result;

  { // Node ID: 801 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id801in_a = id800out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id801in_b = id799out_o;

    id801out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id801in_a,id801in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id802out_result;

  { // Node ID: 802 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id802in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id802in_option0 = id801out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id802in_option1 = id799out_o;

    HWOffsetFix<32,0,UNSIGNED> id802x_1;

    switch((id802in_sel.getValueAsLong())) {
      case 0l:
        id802x_1 = id802in_option0;
        break;
      case 1l:
        id802x_1 = id802in_option1;
        break;
      default:
        id802x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id802out_result = (id802x_1);
  }
  { // Node ID: 4059 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4059in_input = id802out_result;

    id4059out_output[(getCycle()+1)%2] = id4059in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id788out_output;

  { // Node ID: 788 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id788in_input = id4062out_output[getCycle()%2];

    id788out_output = id788in_input;
  }
  { // Node ID: 3194 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2770out_result;

  { // Node ID: 2770 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2770in_a = id3194out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2770in_b = id3464out_output[getCycle()%2];

    id2770out_result = (eq_fixed(id2770in_a,id2770in_b));
  }
  { // Node ID: 4063 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4063in_input = id2770out_result;

    id4063out_output[(getCycle()+3)%4] = id4063in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id787out_o;

  { // Node ID: 787 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id787in_i = id4063out_output[getCycle()%4];

    id787out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id787in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id789out_result;

  { // Node ID: 789 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id789in_a = id788out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id789in_b = id787out_o;

    id789out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id789in_a,id789in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id790out_result;

  { // Node ID: 790 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id790in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id790in_option0 = id789out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id790in_option1 = id787out_o;

    HWOffsetFix<32,0,UNSIGNED> id790x_1;

    switch((id790in_sel.getValueAsLong())) {
      case 0l:
        id790x_1 = id790in_option0;
        break;
      case 1l:
        id790x_1 = id790in_option1;
        break;
      default:
        id790x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id790out_result = (id790x_1);
  }
  { // Node ID: 4062 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4062in_input = id790out_result;

    id4062out_output[(getCycle()+1)%2] = id4062in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id776out_output;

  { // Node ID: 776 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id776in_input = id4065out_output[getCycle()%2];

    id776out_output = id776in_input;
  }
  { // Node ID: 3193 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2771out_result;

  { // Node ID: 2771 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2771in_a = id3193out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2771in_b = id3464out_output[getCycle()%2];

    id2771out_result = (eq_fixed(id2771in_a,id2771in_b));
  }
  { // Node ID: 4066 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4066in_input = id2771out_result;

    id4066out_output[(getCycle()+3)%4] = id4066in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id775out_o;

  { // Node ID: 775 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id775in_i = id4066out_output[getCycle()%4];

    id775out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id775in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id777out_result;

  { // Node ID: 777 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id777in_a = id776out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id777in_b = id775out_o;

    id777out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id777in_a,id777in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id778out_result;

  { // Node ID: 778 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id778in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id778in_option0 = id777out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id778in_option1 = id775out_o;

    HWOffsetFix<32,0,UNSIGNED> id778x_1;

    switch((id778in_sel.getValueAsLong())) {
      case 0l:
        id778x_1 = id778in_option0;
        break;
      case 1l:
        id778x_1 = id778in_option1;
        break;
      default:
        id778x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id778out_result = (id778x_1);
  }
  { // Node ID: 4065 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4065in_input = id778out_result;

    id4065out_output[(getCycle()+1)%2] = id4065in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id764out_output;

  { // Node ID: 764 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id764in_input = id4068out_output[getCycle()%2];

    id764out_output = id764in_input;
  }
  { // Node ID: 3192 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2772out_result;

  { // Node ID: 2772 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2772in_a = id3192out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2772in_b = id3464out_output[getCycle()%2];

    id2772out_result = (eq_fixed(id2772in_a,id2772in_b));
  }
  { // Node ID: 4069 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4069in_input = id2772out_result;

    id4069out_output[(getCycle()+3)%4] = id4069in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id763out_o;

  { // Node ID: 763 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id763in_i = id4069out_output[getCycle()%4];

    id763out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id763in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id765out_result;

  { // Node ID: 765 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id765in_a = id764out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id765in_b = id763out_o;

    id765out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id765in_a,id765in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id766out_result;

  { // Node ID: 766 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id766in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id766in_option0 = id765out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id766in_option1 = id763out_o;

    HWOffsetFix<32,0,UNSIGNED> id766x_1;

    switch((id766in_sel.getValueAsLong())) {
      case 0l:
        id766x_1 = id766in_option0;
        break;
      case 1l:
        id766x_1 = id766in_option1;
        break;
      default:
        id766x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id766out_result = (id766x_1);
  }
  { // Node ID: 4068 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4068in_input = id766out_result;

    id4068out_output[(getCycle()+1)%2] = id4068in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id752out_output;

  { // Node ID: 752 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id752in_input = id4071out_output[getCycle()%2];

    id752out_output = id752in_input;
  }
  { // Node ID: 3191 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2773out_result;

  { // Node ID: 2773 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2773in_a = id3191out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2773in_b = id3464out_output[getCycle()%2];

    id2773out_result = (eq_fixed(id2773in_a,id2773in_b));
  }
  { // Node ID: 4072 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4072in_input = id2773out_result;

    id4072out_output[(getCycle()+3)%4] = id4072in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id751out_o;

  { // Node ID: 751 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id751in_i = id4072out_output[getCycle()%4];

    id751out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id751in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id753out_result;

  { // Node ID: 753 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id753in_a = id752out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id753in_b = id751out_o;

    id753out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id753in_a,id753in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id754out_result;

  { // Node ID: 754 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id754in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id754in_option0 = id753out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id754in_option1 = id751out_o;

    HWOffsetFix<32,0,UNSIGNED> id754x_1;

    switch((id754in_sel.getValueAsLong())) {
      case 0l:
        id754x_1 = id754in_option0;
        break;
      case 1l:
        id754x_1 = id754in_option1;
        break;
      default:
        id754x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id754out_result = (id754x_1);
  }
  { // Node ID: 4071 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4071in_input = id754out_result;

    id4071out_output[(getCycle()+1)%2] = id4071in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id740out_output;

  { // Node ID: 740 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id740in_input = id4074out_output[getCycle()%2];

    id740out_output = id740in_input;
  }
  { // Node ID: 3190 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2774out_result;

  { // Node ID: 2774 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2774in_a = id3190out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2774in_b = id3464out_output[getCycle()%2];

    id2774out_result = (eq_fixed(id2774in_a,id2774in_b));
  }
  { // Node ID: 4075 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4075in_input = id2774out_result;

    id4075out_output[(getCycle()+3)%4] = id4075in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id739out_o;

  { // Node ID: 739 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id739in_i = id4075out_output[getCycle()%4];

    id739out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id739in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id741out_result;

  { // Node ID: 741 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id741in_a = id740out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id741in_b = id739out_o;

    id741out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id741in_a,id741in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id742out_result;

  { // Node ID: 742 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id742in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id742in_option0 = id741out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id742in_option1 = id739out_o;

    HWOffsetFix<32,0,UNSIGNED> id742x_1;

    switch((id742in_sel.getValueAsLong())) {
      case 0l:
        id742x_1 = id742in_option0;
        break;
      case 1l:
        id742x_1 = id742in_option1;
        break;
      default:
        id742x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id742out_result = (id742x_1);
  }
  { // Node ID: 4074 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4074in_input = id742out_result;

    id4074out_output[(getCycle()+1)%2] = id4074in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id728out_output;

  { // Node ID: 728 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id728in_input = id4077out_output[getCycle()%2];

    id728out_output = id728in_input;
  }
  { // Node ID: 3189 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2775out_result;

  { // Node ID: 2775 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2775in_a = id3189out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2775in_b = id3464out_output[getCycle()%2];

    id2775out_result = (eq_fixed(id2775in_a,id2775in_b));
  }
  { // Node ID: 4078 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4078in_input = id2775out_result;

    id4078out_output[(getCycle()+3)%4] = id4078in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id727out_o;

  { // Node ID: 727 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id727in_i = id4078out_output[getCycle()%4];

    id727out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id727in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id729out_result;

  { // Node ID: 729 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id729in_a = id728out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id729in_b = id727out_o;

    id729out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id729in_a,id729in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id730out_result;

  { // Node ID: 730 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id730in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id730in_option0 = id729out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id730in_option1 = id727out_o;

    HWOffsetFix<32,0,UNSIGNED> id730x_1;

    switch((id730in_sel.getValueAsLong())) {
      case 0l:
        id730x_1 = id730in_option0;
        break;
      case 1l:
        id730x_1 = id730in_option1;
        break;
      default:
        id730x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id730out_result = (id730x_1);
  }
  { // Node ID: 4077 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4077in_input = id730out_result;

    id4077out_output[(getCycle()+1)%2] = id4077in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id716out_output;

  { // Node ID: 716 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id716in_input = id4080out_output[getCycle()%2];

    id716out_output = id716in_input;
  }
  { // Node ID: 3188 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2776out_result;

  { // Node ID: 2776 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2776in_a = id3188out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2776in_b = id3464out_output[getCycle()%2];

    id2776out_result = (eq_fixed(id2776in_a,id2776in_b));
  }
  { // Node ID: 4081 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4081in_input = id2776out_result;

    id4081out_output[(getCycle()+3)%4] = id4081in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id715out_o;

  { // Node ID: 715 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id715in_i = id4081out_output[getCycle()%4];

    id715out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id715in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id717out_result;

  { // Node ID: 717 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id717in_a = id716out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id717in_b = id715out_o;

    id717out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id717in_a,id717in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id718out_result;

  { // Node ID: 718 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id718in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id718in_option0 = id717out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id718in_option1 = id715out_o;

    HWOffsetFix<32,0,UNSIGNED> id718x_1;

    switch((id718in_sel.getValueAsLong())) {
      case 0l:
        id718x_1 = id718in_option0;
        break;
      case 1l:
        id718x_1 = id718in_option1;
        break;
      default:
        id718x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id718out_result = (id718x_1);
  }
  { // Node ID: 4080 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4080in_input = id718out_result;

    id4080out_output[(getCycle()+1)%2] = id4080in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id704out_output;

  { // Node ID: 704 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id704in_input = id4083out_output[getCycle()%2];

    id704out_output = id704in_input;
  }
  { // Node ID: 3187 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2777out_result;

  { // Node ID: 2777 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2777in_a = id3187out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2777in_b = id3464out_output[getCycle()%2];

    id2777out_result = (eq_fixed(id2777in_a,id2777in_b));
  }
  { // Node ID: 4084 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4084in_input = id2777out_result;

    id4084out_output[(getCycle()+3)%4] = id4084in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id703out_o;

  { // Node ID: 703 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id703in_i = id4084out_output[getCycle()%4];

    id703out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id703in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id705out_result;

  { // Node ID: 705 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id705in_a = id704out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id705in_b = id703out_o;

    id705out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id705in_a,id705in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id706out_result;

  { // Node ID: 706 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id706in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id706in_option0 = id705out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id706in_option1 = id703out_o;

    HWOffsetFix<32,0,UNSIGNED> id706x_1;

    switch((id706in_sel.getValueAsLong())) {
      case 0l:
        id706x_1 = id706in_option0;
        break;
      case 1l:
        id706x_1 = id706in_option1;
        break;
      default:
        id706x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id706out_result = (id706x_1);
  }
  { // Node ID: 4083 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4083in_input = id706out_result;

    id4083out_output[(getCycle()+1)%2] = id4083in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id692out_output;

  { // Node ID: 692 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id692in_input = id4086out_output[getCycle()%2];

    id692out_output = id692in_input;
  }
  { // Node ID: 3186 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2778out_result;

  { // Node ID: 2778 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2778in_a = id3186out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2778in_b = id3464out_output[getCycle()%2];

    id2778out_result = (eq_fixed(id2778in_a,id2778in_b));
  }
  { // Node ID: 4087 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4087in_input = id2778out_result;

    id4087out_output[(getCycle()+3)%4] = id4087in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id691out_o;

  { // Node ID: 691 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id691in_i = id4087out_output[getCycle()%4];

    id691out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id691in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id693out_result;

  { // Node ID: 693 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id693in_a = id692out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id693in_b = id691out_o;

    id693out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id693in_a,id693in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id694out_result;

  { // Node ID: 694 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id694in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id694in_option0 = id693out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id694in_option1 = id691out_o;

    HWOffsetFix<32,0,UNSIGNED> id694x_1;

    switch((id694in_sel.getValueAsLong())) {
      case 0l:
        id694x_1 = id694in_option0;
        break;
      case 1l:
        id694x_1 = id694in_option1;
        break;
      default:
        id694x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id694out_result = (id694x_1);
  }
  { // Node ID: 4086 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4086in_input = id694out_result;

    id4086out_output[(getCycle()+1)%2] = id4086in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id680out_output;

  { // Node ID: 680 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id680in_input = id4089out_output[getCycle()%2];

    id680out_output = id680in_input;
  }
  { // Node ID: 3185 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2779out_result;

  { // Node ID: 2779 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2779in_a = id3185out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2779in_b = id3464out_output[getCycle()%2];

    id2779out_result = (eq_fixed(id2779in_a,id2779in_b));
  }
  { // Node ID: 4090 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4090in_input = id2779out_result;

    id4090out_output[(getCycle()+3)%4] = id4090in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id679out_o;

  { // Node ID: 679 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id679in_i = id4090out_output[getCycle()%4];

    id679out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id679in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id681out_result;

  { // Node ID: 681 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id681in_a = id680out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id681in_b = id679out_o;

    id681out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id681in_a,id681in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id682out_result;

  { // Node ID: 682 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id682in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id682in_option0 = id681out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id682in_option1 = id679out_o;

    HWOffsetFix<32,0,UNSIGNED> id682x_1;

    switch((id682in_sel.getValueAsLong())) {
      case 0l:
        id682x_1 = id682in_option0;
        break;
      case 1l:
        id682x_1 = id682in_option1;
        break;
      default:
        id682x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id682out_result = (id682x_1);
  }
  { // Node ID: 4089 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4089in_input = id682out_result;

    id4089out_output[(getCycle()+1)%2] = id4089in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id668out_output;

  { // Node ID: 668 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id668in_input = id4092out_output[getCycle()%2];

    id668out_output = id668in_input;
  }
  { // Node ID: 3184 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2780out_result;

  { // Node ID: 2780 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2780in_a = id3184out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2780in_b = id3464out_output[getCycle()%2];

    id2780out_result = (eq_fixed(id2780in_a,id2780in_b));
  }
  { // Node ID: 4093 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4093in_input = id2780out_result;

    id4093out_output[(getCycle()+3)%4] = id4093in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id667out_o;

  { // Node ID: 667 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id667in_i = id4093out_output[getCycle()%4];

    id667out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id667in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id669out_result;

  { // Node ID: 669 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id669in_a = id668out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id669in_b = id667out_o;

    id669out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id669in_a,id669in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id670out_result;

  { // Node ID: 670 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id670in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id670in_option0 = id669out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id670in_option1 = id667out_o;

    HWOffsetFix<32,0,UNSIGNED> id670x_1;

    switch((id670in_sel.getValueAsLong())) {
      case 0l:
        id670x_1 = id670in_option0;
        break;
      case 1l:
        id670x_1 = id670in_option1;
        break;
      default:
        id670x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id670out_result = (id670x_1);
  }
  { // Node ID: 4092 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4092in_input = id670out_result;

    id4092out_output[(getCycle()+1)%2] = id4092in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id656out_output;

  { // Node ID: 656 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id656in_input = id4095out_output[getCycle()%2];

    id656out_output = id656in_input;
  }
  { // Node ID: 3183 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2781out_result;

  { // Node ID: 2781 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2781in_a = id3183out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2781in_b = id3464out_output[getCycle()%2];

    id2781out_result = (eq_fixed(id2781in_a,id2781in_b));
  }
  { // Node ID: 4096 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4096in_input = id2781out_result;

    id4096out_output[(getCycle()+3)%4] = id4096in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id655out_o;

  { // Node ID: 655 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id655in_i = id4096out_output[getCycle()%4];

    id655out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id655in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id657out_result;

  { // Node ID: 657 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id657in_a = id656out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id657in_b = id655out_o;

    id657out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id657in_a,id657in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id658out_result;

  { // Node ID: 658 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id658in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id658in_option0 = id657out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id658in_option1 = id655out_o;

    HWOffsetFix<32,0,UNSIGNED> id658x_1;

    switch((id658in_sel.getValueAsLong())) {
      case 0l:
        id658x_1 = id658in_option0;
        break;
      case 1l:
        id658x_1 = id658in_option1;
        break;
      default:
        id658x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id658out_result = (id658x_1);
  }
  { // Node ID: 4095 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4095in_input = id658out_result;

    id4095out_output[(getCycle()+1)%2] = id4095in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id644out_output;

  { // Node ID: 644 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id644in_input = id4098out_output[getCycle()%2];

    id644out_output = id644in_input;
  }
  { // Node ID: 3182 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2782out_result;

  { // Node ID: 2782 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2782in_a = id3182out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2782in_b = id3464out_output[getCycle()%2];

    id2782out_result = (eq_fixed(id2782in_a,id2782in_b));
  }
  { // Node ID: 4099 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4099in_input = id2782out_result;

    id4099out_output[(getCycle()+3)%4] = id4099in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id643out_o;

  { // Node ID: 643 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id643in_i = id4099out_output[getCycle()%4];

    id643out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id643in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id645out_result;

  { // Node ID: 645 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id645in_a = id644out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id645in_b = id643out_o;

    id645out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id645in_a,id645in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id646out_result;

  { // Node ID: 646 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id646in_sel = id3556out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id646in_option0 = id645out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id646in_option1 = id643out_o;

    HWOffsetFix<32,0,UNSIGNED> id646x_1;

    switch((id646in_sel.getValueAsLong())) {
      case 0l:
        id646x_1 = id646in_option0;
        break;
      case 1l:
        id646x_1 = id646in_option1;
        break;
      default:
        id646x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id646out_result = (id646x_1);
  }
  { // Node ID: 4098 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4098in_input = id646out_result;

    id4098out_output[(getCycle()+1)%2] = id4098in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id632out_output;

  { // Node ID: 632 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id632in_input = id4101out_output[getCycle()%2];

    id632out_output = id632in_input;
  }
  { // Node ID: 3181 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2783out_result;

  { // Node ID: 2783 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2783in_a = id3181out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2783in_b = id3464out_output[getCycle()%2];

    id2783out_result = (eq_fixed(id2783in_a,id2783in_b));
  }
  { // Node ID: 4102 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4102in_input = id2783out_result;

    id4102out_output[(getCycle()+3)%4] = id4102in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id631out_o;

  { // Node ID: 631 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id631in_i = id4102out_output[getCycle()%4];

    id631out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id631in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id633out_result;

  { // Node ID: 633 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id633in_a = id632out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id633in_b = id631out_o;

    id633out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id633in_a,id633in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id634out_result;

  { // Node ID: 634 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id634in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id634in_option0 = id633out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id634in_option1 = id631out_o;

    HWOffsetFix<32,0,UNSIGNED> id634x_1;

    switch((id634in_sel.getValueAsLong())) {
      case 0l:
        id634x_1 = id634in_option0;
        break;
      case 1l:
        id634x_1 = id634in_option1;
        break;
      default:
        id634x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id634out_result = (id634x_1);
  }
  { // Node ID: 4101 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4101in_input = id634out_result;

    id4101out_output[(getCycle()+1)%2] = id4101in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id620out_output;

  { // Node ID: 620 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id620in_input = id4104out_output[getCycle()%2];

    id620out_output = id620in_input;
  }
  { // Node ID: 3180 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2784out_result;

  { // Node ID: 2784 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2784in_a = id3180out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2784in_b = id3464out_output[getCycle()%2];

    id2784out_result = (eq_fixed(id2784in_a,id2784in_b));
  }
  { // Node ID: 4105 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4105in_input = id2784out_result;

    id4105out_output[(getCycle()+3)%4] = id4105in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id619out_o;

  { // Node ID: 619 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id619in_i = id4105out_output[getCycle()%4];

    id619out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id619in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id621out_result;

  { // Node ID: 621 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id621in_a = id620out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id621in_b = id619out_o;

    id621out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id621in_a,id621in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id622out_result;

  { // Node ID: 622 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id622in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id622in_option0 = id621out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id622in_option1 = id619out_o;

    HWOffsetFix<32,0,UNSIGNED> id622x_1;

    switch((id622in_sel.getValueAsLong())) {
      case 0l:
        id622x_1 = id622in_option0;
        break;
      case 1l:
        id622x_1 = id622in_option1;
        break;
      default:
        id622x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id622out_result = (id622x_1);
  }
  { // Node ID: 4104 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4104in_input = id622out_result;

    id4104out_output[(getCycle()+1)%2] = id4104in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id608out_output;

  { // Node ID: 608 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id608in_input = id4107out_output[getCycle()%2];

    id608out_output = id608in_input;
  }
  { // Node ID: 3179 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2785out_result;

  { // Node ID: 2785 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2785in_a = id3179out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2785in_b = id3465out_output[getCycle()%2];

    id2785out_result = (eq_fixed(id2785in_a,id2785in_b));
  }
  { // Node ID: 4108 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4108in_input = id2785out_result;

    id4108out_output[(getCycle()+4)%5] = id4108in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id607out_o;

  { // Node ID: 607 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id607in_i = id4108out_output[getCycle()%5];

    id607out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id607in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id609out_result;

  { // Node ID: 609 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id609in_a = id608out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id609in_b = id607out_o;

    id609out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id609in_a,id609in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id610out_result;

  { // Node ID: 610 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id610in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id610in_option0 = id609out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id610in_option1 = id607out_o;

    HWOffsetFix<32,0,UNSIGNED> id610x_1;

    switch((id610in_sel.getValueAsLong())) {
      case 0l:
        id610x_1 = id610in_option0;
        break;
      case 1l:
        id610x_1 = id610in_option1;
        break;
      default:
        id610x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id610out_result = (id610x_1);
  }
  { // Node ID: 4107 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4107in_input = id610out_result;

    id4107out_output[(getCycle()+1)%2] = id4107in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id596out_output;

  { // Node ID: 596 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id596in_input = id4110out_output[getCycle()%2];

    id596out_output = id596in_input;
  }
  { // Node ID: 3178 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2786out_result;

  { // Node ID: 2786 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2786in_a = id3178out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2786in_b = id3465out_output[getCycle()%2];

    id2786out_result = (eq_fixed(id2786in_a,id2786in_b));
  }
  { // Node ID: 4111 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4111in_input = id2786out_result;

    id4111out_output[(getCycle()+4)%5] = id4111in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id595out_o;

  { // Node ID: 595 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id595in_i = id4111out_output[getCycle()%5];

    id595out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id595in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id597out_result;

  { // Node ID: 597 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id597in_a = id596out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id597in_b = id595out_o;

    id597out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id597in_a,id597in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id598out_result;

  { // Node ID: 598 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id598in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id598in_option0 = id597out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id598in_option1 = id595out_o;

    HWOffsetFix<32,0,UNSIGNED> id598x_1;

    switch((id598in_sel.getValueAsLong())) {
      case 0l:
        id598x_1 = id598in_option0;
        break;
      case 1l:
        id598x_1 = id598in_option1;
        break;
      default:
        id598x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id598out_result = (id598x_1);
  }
  { // Node ID: 4110 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4110in_input = id598out_result;

    id4110out_output[(getCycle()+1)%2] = id4110in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id584out_output;

  { // Node ID: 584 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id584in_input = id4113out_output[getCycle()%2];

    id584out_output = id584in_input;
  }
  { // Node ID: 3177 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2787out_result;

  { // Node ID: 2787 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2787in_a = id3177out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2787in_b = id3465out_output[getCycle()%2];

    id2787out_result = (eq_fixed(id2787in_a,id2787in_b));
  }
  { // Node ID: 4114 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4114in_input = id2787out_result;

    id4114out_output[(getCycle()+4)%5] = id4114in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id583out_o;

  { // Node ID: 583 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id583in_i = id4114out_output[getCycle()%5];

    id583out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id583in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id585out_result;

  { // Node ID: 585 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id585in_a = id584out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id585in_b = id583out_o;

    id585out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id585in_a,id585in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id586out_result;

  { // Node ID: 586 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id586in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id586in_option0 = id585out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id586in_option1 = id583out_o;

    HWOffsetFix<32,0,UNSIGNED> id586x_1;

    switch((id586in_sel.getValueAsLong())) {
      case 0l:
        id586x_1 = id586in_option0;
        break;
      case 1l:
        id586x_1 = id586in_option1;
        break;
      default:
        id586x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id586out_result = (id586x_1);
  }
  { // Node ID: 4113 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4113in_input = id586out_result;

    id4113out_output[(getCycle()+1)%2] = id4113in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id572out_output;

  { // Node ID: 572 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id572in_input = id4116out_output[getCycle()%2];

    id572out_output = id572in_input;
  }
  { // Node ID: 3176 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2788out_result;

  { // Node ID: 2788 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2788in_a = id3176out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2788in_b = id3465out_output[getCycle()%2];

    id2788out_result = (eq_fixed(id2788in_a,id2788in_b));
  }
  { // Node ID: 4117 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4117in_input = id2788out_result;

    id4117out_output[(getCycle()+4)%5] = id4117in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id571out_o;

  { // Node ID: 571 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id571in_i = id4117out_output[getCycle()%5];

    id571out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id571in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id573out_result;

  { // Node ID: 573 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id573in_a = id572out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id573in_b = id571out_o;

    id573out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id573in_a,id573in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id574out_result;

  { // Node ID: 574 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id574in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id574in_option0 = id573out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id574in_option1 = id571out_o;

    HWOffsetFix<32,0,UNSIGNED> id574x_1;

    switch((id574in_sel.getValueAsLong())) {
      case 0l:
        id574x_1 = id574in_option0;
        break;
      case 1l:
        id574x_1 = id574in_option1;
        break;
      default:
        id574x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id574out_result = (id574x_1);
  }
  { // Node ID: 4116 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4116in_input = id574out_result;

    id4116out_output[(getCycle()+1)%2] = id4116in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id560out_output;

  { // Node ID: 560 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id560in_input = id4119out_output[getCycle()%2];

    id560out_output = id560in_input;
  }
  { // Node ID: 3175 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2789out_result;

  { // Node ID: 2789 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2789in_a = id3175out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2789in_b = id3465out_output[getCycle()%2];

    id2789out_result = (eq_fixed(id2789in_a,id2789in_b));
  }
  { // Node ID: 4120 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4120in_input = id2789out_result;

    id4120out_output[(getCycle()+4)%5] = id4120in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id559out_o;

  { // Node ID: 559 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id559in_i = id4120out_output[getCycle()%5];

    id559out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id559in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id561out_result;

  { // Node ID: 561 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id561in_a = id560out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id561in_b = id559out_o;

    id561out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id561in_a,id561in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id562out_result;

  { // Node ID: 562 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id562in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id562in_option0 = id561out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id562in_option1 = id559out_o;

    HWOffsetFix<32,0,UNSIGNED> id562x_1;

    switch((id562in_sel.getValueAsLong())) {
      case 0l:
        id562x_1 = id562in_option0;
        break;
      case 1l:
        id562x_1 = id562in_option1;
        break;
      default:
        id562x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id562out_result = (id562x_1);
  }
  { // Node ID: 4119 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4119in_input = id562out_result;

    id4119out_output[(getCycle()+1)%2] = id4119in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id548out_output;

  { // Node ID: 548 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id548in_input = id4122out_output[getCycle()%2];

    id548out_output = id548in_input;
  }
  { // Node ID: 3174 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2790out_result;

  { // Node ID: 2790 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2790in_a = id3174out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2790in_b = id3465out_output[getCycle()%2];

    id2790out_result = (eq_fixed(id2790in_a,id2790in_b));
  }
  { // Node ID: 4123 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4123in_input = id2790out_result;

    id4123out_output[(getCycle()+4)%5] = id4123in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id547out_o;

  { // Node ID: 547 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id547in_i = id4123out_output[getCycle()%5];

    id547out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id547in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id549out_result;

  { // Node ID: 549 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id549in_a = id548out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id549in_b = id547out_o;

    id549out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id549in_a,id549in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id550out_result;

  { // Node ID: 550 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id550in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id550in_option0 = id549out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id550in_option1 = id547out_o;

    HWOffsetFix<32,0,UNSIGNED> id550x_1;

    switch((id550in_sel.getValueAsLong())) {
      case 0l:
        id550x_1 = id550in_option0;
        break;
      case 1l:
        id550x_1 = id550in_option1;
        break;
      default:
        id550x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id550out_result = (id550x_1);
  }
  { // Node ID: 4122 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4122in_input = id550out_result;

    id4122out_output[(getCycle()+1)%2] = id4122in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id536out_output;

  { // Node ID: 536 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id536in_input = id4125out_output[getCycle()%2];

    id536out_output = id536in_input;
  }
  { // Node ID: 3173 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2791out_result;

  { // Node ID: 2791 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2791in_a = id3173out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2791in_b = id3465out_output[getCycle()%2];

    id2791out_result = (eq_fixed(id2791in_a,id2791in_b));
  }
  { // Node ID: 4126 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4126in_input = id2791out_result;

    id4126out_output[(getCycle()+4)%5] = id4126in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id535out_o;

  { // Node ID: 535 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id535in_i = id4126out_output[getCycle()%5];

    id535out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id535in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id537out_result;

  { // Node ID: 537 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id537in_a = id536out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id537in_b = id535out_o;

    id537out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id537in_a,id537in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id538out_result;

  { // Node ID: 538 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id538in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id538in_option0 = id537out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id538in_option1 = id535out_o;

    HWOffsetFix<32,0,UNSIGNED> id538x_1;

    switch((id538in_sel.getValueAsLong())) {
      case 0l:
        id538x_1 = id538in_option0;
        break;
      case 1l:
        id538x_1 = id538in_option1;
        break;
      default:
        id538x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id538out_result = (id538x_1);
  }
  { // Node ID: 4125 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4125in_input = id538out_result;

    id4125out_output[(getCycle()+1)%2] = id4125in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id524out_output;

  { // Node ID: 524 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id524in_input = id4128out_output[getCycle()%2];

    id524out_output = id524in_input;
  }
  { // Node ID: 3172 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2792out_result;

  { // Node ID: 2792 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2792in_a = id3172out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2792in_b = id3465out_output[getCycle()%2];

    id2792out_result = (eq_fixed(id2792in_a,id2792in_b));
  }
  { // Node ID: 4129 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4129in_input = id2792out_result;

    id4129out_output[(getCycle()+4)%5] = id4129in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id523out_o;

  { // Node ID: 523 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id523in_i = id4129out_output[getCycle()%5];

    id523out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id523in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id525out_result;

  { // Node ID: 525 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id525in_a = id524out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id525in_b = id523out_o;

    id525out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id525in_a,id525in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id526out_result;

  { // Node ID: 526 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id526in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id526in_option0 = id525out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id526in_option1 = id523out_o;

    HWOffsetFix<32,0,UNSIGNED> id526x_1;

    switch((id526in_sel.getValueAsLong())) {
      case 0l:
        id526x_1 = id526in_option0;
        break;
      case 1l:
        id526x_1 = id526in_option1;
        break;
      default:
        id526x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id526out_result = (id526x_1);
  }
  { // Node ID: 4128 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4128in_input = id526out_result;

    id4128out_output[(getCycle()+1)%2] = id4128in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id512out_output;

  { // Node ID: 512 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id512in_input = id4131out_output[getCycle()%2];

    id512out_output = id512in_input;
  }
  { // Node ID: 3171 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2793out_result;

  { // Node ID: 2793 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2793in_a = id3171out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2793in_b = id3465out_output[getCycle()%2];

    id2793out_result = (eq_fixed(id2793in_a,id2793in_b));
  }
  { // Node ID: 4132 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4132in_input = id2793out_result;

    id4132out_output[(getCycle()+4)%5] = id4132in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id511out_o;

  { // Node ID: 511 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id511in_i = id4132out_output[getCycle()%5];

    id511out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id511in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id513out_result;

  { // Node ID: 513 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id513in_a = id512out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id513in_b = id511out_o;

    id513out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id513in_a,id513in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id514out_result;

  { // Node ID: 514 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id514in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id514in_option0 = id513out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id514in_option1 = id511out_o;

    HWOffsetFix<32,0,UNSIGNED> id514x_1;

    switch((id514in_sel.getValueAsLong())) {
      case 0l:
        id514x_1 = id514in_option0;
        break;
      case 1l:
        id514x_1 = id514in_option1;
        break;
      default:
        id514x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id514out_result = (id514x_1);
  }
  { // Node ID: 4131 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4131in_input = id514out_result;

    id4131out_output[(getCycle()+1)%2] = id4131in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id500out_output;

  { // Node ID: 500 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id500in_input = id4134out_output[getCycle()%2];

    id500out_output = id500in_input;
  }
  { // Node ID: 3170 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2794out_result;

  { // Node ID: 2794 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2794in_a = id3170out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2794in_b = id3465out_output[getCycle()%2];

    id2794out_result = (eq_fixed(id2794in_a,id2794in_b));
  }
  { // Node ID: 4135 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4135in_input = id2794out_result;

    id4135out_output[(getCycle()+4)%5] = id4135in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id499out_o;

  { // Node ID: 499 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id499in_i = id4135out_output[getCycle()%5];

    id499out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id499in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id501out_result;

  { // Node ID: 501 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id501in_a = id500out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id501in_b = id499out_o;

    id501out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id501in_a,id501in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id502out_result;

  { // Node ID: 502 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id502in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id502in_option0 = id501out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id502in_option1 = id499out_o;

    HWOffsetFix<32,0,UNSIGNED> id502x_1;

    switch((id502in_sel.getValueAsLong())) {
      case 0l:
        id502x_1 = id502in_option0;
        break;
      case 1l:
        id502x_1 = id502in_option1;
        break;
      default:
        id502x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id502out_result = (id502x_1);
  }
  { // Node ID: 4134 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4134in_input = id502out_result;

    id4134out_output[(getCycle()+1)%2] = id4134in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id488out_output;

  { // Node ID: 488 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id488in_input = id4137out_output[getCycle()%2];

    id488out_output = id488in_input;
  }
  { // Node ID: 3169 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2795out_result;

  { // Node ID: 2795 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2795in_a = id3169out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2795in_b = id3465out_output[getCycle()%2];

    id2795out_result = (eq_fixed(id2795in_a,id2795in_b));
  }
  { // Node ID: 4138 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4138in_input = id2795out_result;

    id4138out_output[(getCycle()+4)%5] = id4138in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id487out_o;

  { // Node ID: 487 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id487in_i = id4138out_output[getCycle()%5];

    id487out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id487in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id489out_result;

  { // Node ID: 489 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id489in_a = id488out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id489in_b = id487out_o;

    id489out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id489in_a,id489in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id490out_result;

  { // Node ID: 490 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id490in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id490in_option0 = id489out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id490in_option1 = id487out_o;

    HWOffsetFix<32,0,UNSIGNED> id490x_1;

    switch((id490in_sel.getValueAsLong())) {
      case 0l:
        id490x_1 = id490in_option0;
        break;
      case 1l:
        id490x_1 = id490in_option1;
        break;
      default:
        id490x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id490out_result = (id490x_1);
  }
  { // Node ID: 4137 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4137in_input = id490out_result;

    id4137out_output[(getCycle()+1)%2] = id4137in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id476out_output;

  { // Node ID: 476 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id476in_input = id4140out_output[getCycle()%2];

    id476out_output = id476in_input;
  }
  { // Node ID: 3168 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2796out_result;

  { // Node ID: 2796 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2796in_a = id3168out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2796in_b = id3465out_output[getCycle()%2];

    id2796out_result = (eq_fixed(id2796in_a,id2796in_b));
  }
  { // Node ID: 4141 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4141in_input = id2796out_result;

    id4141out_output[(getCycle()+4)%5] = id4141in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id475out_o;

  { // Node ID: 475 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id475in_i = id4141out_output[getCycle()%5];

    id475out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id475in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id477out_result;

  { // Node ID: 477 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id477in_a = id476out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id477in_b = id475out_o;

    id477out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id477in_a,id477in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id478out_result;

  { // Node ID: 478 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id478in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id478in_option0 = id477out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id478in_option1 = id475out_o;

    HWOffsetFix<32,0,UNSIGNED> id478x_1;

    switch((id478in_sel.getValueAsLong())) {
      case 0l:
        id478x_1 = id478in_option0;
        break;
      case 1l:
        id478x_1 = id478in_option1;
        break;
      default:
        id478x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id478out_result = (id478x_1);
  }
  { // Node ID: 4140 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4140in_input = id478out_result;

    id4140out_output[(getCycle()+1)%2] = id4140in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id464out_output;

  { // Node ID: 464 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id464in_input = id4143out_output[getCycle()%2];

    id464out_output = id464in_input;
  }
  { // Node ID: 3167 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2797out_result;

  { // Node ID: 2797 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2797in_a = id3167out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2797in_b = id3465out_output[getCycle()%2];

    id2797out_result = (eq_fixed(id2797in_a,id2797in_b));
  }
  { // Node ID: 4144 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4144in_input = id2797out_result;

    id4144out_output[(getCycle()+4)%5] = id4144in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id463out_o;

  { // Node ID: 463 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id463in_i = id4144out_output[getCycle()%5];

    id463out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id463in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id465out_result;

  { // Node ID: 465 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id465in_a = id464out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id465in_b = id463out_o;

    id465out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id465in_a,id465in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id466out_result;

  { // Node ID: 466 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id466in_sel = id3586out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id466in_option0 = id465out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id466in_option1 = id463out_o;

    HWOffsetFix<32,0,UNSIGNED> id466x_1;

    switch((id466in_sel.getValueAsLong())) {
      case 0l:
        id466x_1 = id466in_option0;
        break;
      case 1l:
        id466x_1 = id466in_option1;
        break;
      default:
        id466x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id466out_result = (id466x_1);
  }
  { // Node ID: 4143 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4143in_input = id466out_result;

    id4143out_output[(getCycle()+1)%2] = id4143in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id452out_output;

  { // Node ID: 452 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id452in_input = id4146out_output[getCycle()%2];

    id452out_output = id452in_input;
  }
  { // Node ID: 3166 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2798out_result;

  { // Node ID: 2798 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2798in_a = id3166out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2798in_b = id3465out_output[getCycle()%2];

    id2798out_result = (eq_fixed(id2798in_a,id2798in_b));
  }
  { // Node ID: 4147 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4147in_input = id2798out_result;

    id4147out_output[(getCycle()+4)%5] = id4147in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id451out_o;

  { // Node ID: 451 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id451in_i = id4147out_output[getCycle()%5];

    id451out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id451in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id453out_result;

  { // Node ID: 453 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id453in_a = id452out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id453in_b = id451out_o;

    id453out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id453in_a,id453in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id454out_result;

  { // Node ID: 454 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id454in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id454in_option0 = id453out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id454in_option1 = id451out_o;

    HWOffsetFix<32,0,UNSIGNED> id454x_1;

    switch((id454in_sel.getValueAsLong())) {
      case 0l:
        id454x_1 = id454in_option0;
        break;
      case 1l:
        id454x_1 = id454in_option1;
        break;
      default:
        id454x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id454out_result = (id454x_1);
  }
  { // Node ID: 4146 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4146in_input = id454out_result;

    id4146out_output[(getCycle()+1)%2] = id4146in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id440out_output;

  { // Node ID: 440 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id440in_input = id4149out_output[getCycle()%2];

    id440out_output = id440in_input;
  }
  { // Node ID: 3165 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2799out_result;

  { // Node ID: 2799 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2799in_a = id3165out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2799in_b = id3465out_output[getCycle()%2];

    id2799out_result = (eq_fixed(id2799in_a,id2799in_b));
  }
  { // Node ID: 4150 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4150in_input = id2799out_result;

    id4150out_output[(getCycle()+4)%5] = id4150in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id439out_o;

  { // Node ID: 439 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id439in_i = id4150out_output[getCycle()%5];

    id439out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id439in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id441out_result;

  { // Node ID: 441 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id441in_a = id440out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id441in_b = id439out_o;

    id441out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id441in_a,id441in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id442out_result;

  { // Node ID: 442 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id442in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id442in_option0 = id441out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id442in_option1 = id439out_o;

    HWOffsetFix<32,0,UNSIGNED> id442x_1;

    switch((id442in_sel.getValueAsLong())) {
      case 0l:
        id442x_1 = id442in_option0;
        break;
      case 1l:
        id442x_1 = id442in_option1;
        break;
      default:
        id442x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id442out_result = (id442x_1);
  }
  { // Node ID: 4149 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4149in_input = id442out_result;

    id4149out_output[(getCycle()+1)%2] = id4149in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id428out_output;

  { // Node ID: 428 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id428in_input = id4152out_output[getCycle()%2];

    id428out_output = id428in_input;
  }
  { // Node ID: 3164 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2800out_result;

  { // Node ID: 2800 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2800in_a = id3164out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2800in_b = id3465out_output[getCycle()%2];

    id2800out_result = (eq_fixed(id2800in_a,id2800in_b));
  }
  { // Node ID: 4153 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4153in_input = id2800out_result;

    id4153out_output[(getCycle()+4)%5] = id4153in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id427out_o;

  { // Node ID: 427 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id427in_i = id4153out_output[getCycle()%5];

    id427out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id427in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id429out_result;

  { // Node ID: 429 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id429in_a = id428out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id429in_b = id427out_o;

    id429out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id429in_a,id429in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id430out_result;

  { // Node ID: 430 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id430in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id430in_option0 = id429out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id430in_option1 = id427out_o;

    HWOffsetFix<32,0,UNSIGNED> id430x_1;

    switch((id430in_sel.getValueAsLong())) {
      case 0l:
        id430x_1 = id430in_option0;
        break;
      case 1l:
        id430x_1 = id430in_option1;
        break;
      default:
        id430x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id430out_result = (id430x_1);
  }
  { // Node ID: 4152 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4152in_input = id430out_result;

    id4152out_output[(getCycle()+1)%2] = id4152in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id416out_output;

  { // Node ID: 416 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id416in_input = id4155out_output[getCycle()%2];

    id416out_output = id416in_input;
  }
  { // Node ID: 3163 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2801out_result;

  { // Node ID: 2801 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2801in_a = id3163out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2801in_b = id3465out_output[getCycle()%2];

    id2801out_result = (eq_fixed(id2801in_a,id2801in_b));
  }
  { // Node ID: 4156 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4156in_input = id2801out_result;

    id4156out_output[(getCycle()+4)%5] = id4156in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id415out_o;

  { // Node ID: 415 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id415in_i = id4156out_output[getCycle()%5];

    id415out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id415in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id417out_result;

  { // Node ID: 417 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id417in_a = id416out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id417in_b = id415out_o;

    id417out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id417in_a,id417in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id418out_result;

  { // Node ID: 418 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id418in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id418in_option0 = id417out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id418in_option1 = id415out_o;

    HWOffsetFix<32,0,UNSIGNED> id418x_1;

    switch((id418in_sel.getValueAsLong())) {
      case 0l:
        id418x_1 = id418in_option0;
        break;
      case 1l:
        id418x_1 = id418in_option1;
        break;
      default:
        id418x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id418out_result = (id418x_1);
  }
  { // Node ID: 4155 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4155in_input = id418out_result;

    id4155out_output[(getCycle()+1)%2] = id4155in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id404out_output;

  { // Node ID: 404 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id404in_input = id4158out_output[getCycle()%2];

    id404out_output = id404in_input;
  }
  { // Node ID: 3162 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2802out_result;

  { // Node ID: 2802 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2802in_a = id3162out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2802in_b = id3465out_output[getCycle()%2];

    id2802out_result = (eq_fixed(id2802in_a,id2802in_b));
  }
  { // Node ID: 4159 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4159in_input = id2802out_result;

    id4159out_output[(getCycle()+4)%5] = id4159in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id403out_o;

  { // Node ID: 403 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id403in_i = id4159out_output[getCycle()%5];

    id403out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id403in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id405out_result;

  { // Node ID: 405 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id405in_a = id404out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id405in_b = id403out_o;

    id405out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id405in_a,id405in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id406out_result;

  { // Node ID: 406 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id406in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id406in_option0 = id405out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id406in_option1 = id403out_o;

    HWOffsetFix<32,0,UNSIGNED> id406x_1;

    switch((id406in_sel.getValueAsLong())) {
      case 0l:
        id406x_1 = id406in_option0;
        break;
      case 1l:
        id406x_1 = id406in_option1;
        break;
      default:
        id406x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id406out_result = (id406x_1);
  }
  { // Node ID: 4158 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4158in_input = id406out_result;

    id4158out_output[(getCycle()+1)%2] = id4158in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id392out_output;

  { // Node ID: 392 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id392in_input = id4161out_output[getCycle()%2];

    id392out_output = id392in_input;
  }
  { // Node ID: 3161 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2803out_result;

  { // Node ID: 2803 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2803in_a = id3161out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2803in_b = id3465out_output[getCycle()%2];

    id2803out_result = (eq_fixed(id2803in_a,id2803in_b));
  }
  { // Node ID: 4162 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4162in_input = id2803out_result;

    id4162out_output[(getCycle()+4)%5] = id4162in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id391out_o;

  { // Node ID: 391 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id391in_i = id4162out_output[getCycle()%5];

    id391out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id391in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id393out_result;

  { // Node ID: 393 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id393in_a = id392out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id393in_b = id391out_o;

    id393out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id393in_a,id393in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id394out_result;

  { // Node ID: 394 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id394in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id394in_option0 = id393out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id394in_option1 = id391out_o;

    HWOffsetFix<32,0,UNSIGNED> id394x_1;

    switch((id394in_sel.getValueAsLong())) {
      case 0l:
        id394x_1 = id394in_option0;
        break;
      case 1l:
        id394x_1 = id394in_option1;
        break;
      default:
        id394x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id394out_result = (id394x_1);
  }
  { // Node ID: 4161 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4161in_input = id394out_result;

    id4161out_output[(getCycle()+1)%2] = id4161in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id380out_output;

  { // Node ID: 380 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id380in_input = id4164out_output[getCycle()%2];

    id380out_output = id380in_input;
  }
  { // Node ID: 3160 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2804out_result;

  { // Node ID: 2804 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2804in_a = id3160out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2804in_b = id3465out_output[getCycle()%2];

    id2804out_result = (eq_fixed(id2804in_a,id2804in_b));
  }
  { // Node ID: 4165 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4165in_input = id2804out_result;

    id4165out_output[(getCycle()+4)%5] = id4165in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id379out_o;

  { // Node ID: 379 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id379in_i = id4165out_output[getCycle()%5];

    id379out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id379in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id381out_result;

  { // Node ID: 381 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id381in_a = id380out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id381in_b = id379out_o;

    id381out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id381in_a,id381in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id382out_result;

  { // Node ID: 382 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id382in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id382in_option0 = id381out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id382in_option1 = id379out_o;

    HWOffsetFix<32,0,UNSIGNED> id382x_1;

    switch((id382in_sel.getValueAsLong())) {
      case 0l:
        id382x_1 = id382in_option0;
        break;
      case 1l:
        id382x_1 = id382in_option1;
        break;
      default:
        id382x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id382out_result = (id382x_1);
  }
  { // Node ID: 4164 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4164in_input = id382out_result;

    id4164out_output[(getCycle()+1)%2] = id4164in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id368out_output;

  { // Node ID: 368 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id368in_input = id4167out_output[getCycle()%2];

    id368out_output = id368in_input;
  }
  { // Node ID: 3159 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2805out_result;

  { // Node ID: 2805 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2805in_a = id3159out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2805in_b = id3465out_output[getCycle()%2];

    id2805out_result = (eq_fixed(id2805in_a,id2805in_b));
  }
  { // Node ID: 4168 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4168in_input = id2805out_result;

    id4168out_output[(getCycle()+4)%5] = id4168in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id367out_o;

  { // Node ID: 367 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id367in_i = id4168out_output[getCycle()%5];

    id367out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id367in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id369out_result;

  { // Node ID: 369 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id369in_a = id368out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id369in_b = id367out_o;

    id369out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id369in_a,id369in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id370out_result;

  { // Node ID: 370 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id370in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id370in_option0 = id369out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id370in_option1 = id367out_o;

    HWOffsetFix<32,0,UNSIGNED> id370x_1;

    switch((id370in_sel.getValueAsLong())) {
      case 0l:
        id370x_1 = id370in_option0;
        break;
      case 1l:
        id370x_1 = id370in_option1;
        break;
      default:
        id370x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id370out_result = (id370x_1);
  }
  { // Node ID: 4167 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4167in_input = id370out_result;

    id4167out_output[(getCycle()+1)%2] = id4167in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id356out_output;

  { // Node ID: 356 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id356in_input = id4170out_output[getCycle()%2];

    id356out_output = id356in_input;
  }
  { // Node ID: 3158 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2806out_result;

  { // Node ID: 2806 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2806in_a = id3158out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2806in_b = id3465out_output[getCycle()%2];

    id2806out_result = (eq_fixed(id2806in_a,id2806in_b));
  }
  { // Node ID: 4171 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4171in_input = id2806out_result;

    id4171out_output[(getCycle()+4)%5] = id4171in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id355out_o;

  { // Node ID: 355 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id355in_i = id4171out_output[getCycle()%5];

    id355out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id355in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id357out_result;

  { // Node ID: 357 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id357in_a = id356out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id357in_b = id355out_o;

    id357out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id357in_a,id357in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id358out_result;

  { // Node ID: 358 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id358in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id358in_option0 = id357out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id358in_option1 = id355out_o;

    HWOffsetFix<32,0,UNSIGNED> id358x_1;

    switch((id358in_sel.getValueAsLong())) {
      case 0l:
        id358x_1 = id358in_option0;
        break;
      case 1l:
        id358x_1 = id358in_option1;
        break;
      default:
        id358x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id358out_result = (id358x_1);
  }
  { // Node ID: 4170 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4170in_input = id358out_result;

    id4170out_output[(getCycle()+1)%2] = id4170in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id344out_output;

  { // Node ID: 344 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id344in_input = id4173out_output[getCycle()%2];

    id344out_output = id344in_input;
  }
  { // Node ID: 3157 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2807out_result;

  { // Node ID: 2807 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2807in_a = id3157out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2807in_b = id3465out_output[getCycle()%2];

    id2807out_result = (eq_fixed(id2807in_a,id2807in_b));
  }
  { // Node ID: 4174 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4174in_input = id2807out_result;

    id4174out_output[(getCycle()+4)%5] = id4174in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id343out_o;

  { // Node ID: 343 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id343in_i = id4174out_output[getCycle()%5];

    id343out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id343in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id345out_result;

  { // Node ID: 345 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id345in_a = id344out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id345in_b = id343out_o;

    id345out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id345in_a,id345in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id346out_result;

  { // Node ID: 346 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id346in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id346in_option0 = id345out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id346in_option1 = id343out_o;

    HWOffsetFix<32,0,UNSIGNED> id346x_1;

    switch((id346in_sel.getValueAsLong())) {
      case 0l:
        id346x_1 = id346in_option0;
        break;
      case 1l:
        id346x_1 = id346in_option1;
        break;
      default:
        id346x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id346out_result = (id346x_1);
  }
  { // Node ID: 4173 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4173in_input = id346out_result;

    id4173out_output[(getCycle()+1)%2] = id4173in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id332out_output;

  { // Node ID: 332 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id332in_input = id4176out_output[getCycle()%2];

    id332out_output = id332in_input;
  }
  { // Node ID: 3156 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2808out_result;

  { // Node ID: 2808 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2808in_a = id3156out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2808in_b = id3465out_output[getCycle()%2];

    id2808out_result = (eq_fixed(id2808in_a,id2808in_b));
  }
  { // Node ID: 4177 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4177in_input = id2808out_result;

    id4177out_output[(getCycle()+4)%5] = id4177in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id331out_o;

  { // Node ID: 331 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id331in_i = id4177out_output[getCycle()%5];

    id331out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id331in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id333out_result;

  { // Node ID: 333 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id333in_a = id332out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id333in_b = id331out_o;

    id333out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id333in_a,id333in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id334out_result;

  { // Node ID: 334 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id334in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id334in_option0 = id333out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id334in_option1 = id331out_o;

    HWOffsetFix<32,0,UNSIGNED> id334x_1;

    switch((id334in_sel.getValueAsLong())) {
      case 0l:
        id334x_1 = id334in_option0;
        break;
      case 1l:
        id334x_1 = id334in_option1;
        break;
      default:
        id334x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id334out_result = (id334x_1);
  }
  { // Node ID: 4176 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4176in_input = id334out_result;

    id4176out_output[(getCycle()+1)%2] = id4176in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id320out_output;

  { // Node ID: 320 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id320in_input = id4179out_output[getCycle()%2];

    id320out_output = id320in_input;
  }
  { // Node ID: 3155 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2809out_result;

  { // Node ID: 2809 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2809in_a = id3155out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2809in_b = id3465out_output[getCycle()%2];

    id2809out_result = (eq_fixed(id2809in_a,id2809in_b));
  }
  { // Node ID: 4180 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4180in_input = id2809out_result;

    id4180out_output[(getCycle()+4)%5] = id4180in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id319out_o;

  { // Node ID: 319 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id319in_i = id4180out_output[getCycle()%5];

    id319out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id319in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id321out_result;

  { // Node ID: 321 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id321in_a = id320out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id321in_b = id319out_o;

    id321out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id321in_a,id321in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id322out_result;

  { // Node ID: 322 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id322in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id322in_option0 = id321out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id322in_option1 = id319out_o;

    HWOffsetFix<32,0,UNSIGNED> id322x_1;

    switch((id322in_sel.getValueAsLong())) {
      case 0l:
        id322x_1 = id322in_option0;
        break;
      case 1l:
        id322x_1 = id322in_option1;
        break;
      default:
        id322x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id322out_result = (id322x_1);
  }
  { // Node ID: 4179 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4179in_input = id322out_result;

    id4179out_output[(getCycle()+1)%2] = id4179in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id308out_output;

  { // Node ID: 308 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id308in_input = id4182out_output[getCycle()%2];

    id308out_output = id308in_input;
  }
  { // Node ID: 3154 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2810out_result;

  { // Node ID: 2810 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2810in_a = id3154out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2810in_b = id3465out_output[getCycle()%2];

    id2810out_result = (eq_fixed(id2810in_a,id2810in_b));
  }
  { // Node ID: 4183 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4183in_input = id2810out_result;

    id4183out_output[(getCycle()+4)%5] = id4183in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id307out_o;

  { // Node ID: 307 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id307in_i = id4183out_output[getCycle()%5];

    id307out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id307in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id309out_result;

  { // Node ID: 309 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id309in_a = id308out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id309in_b = id307out_o;

    id309out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id309in_a,id309in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id310out_result;

  { // Node ID: 310 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id310in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id310in_option0 = id309out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id310in_option1 = id307out_o;

    HWOffsetFix<32,0,UNSIGNED> id310x_1;

    switch((id310in_sel.getValueAsLong())) {
      case 0l:
        id310x_1 = id310in_option0;
        break;
      case 1l:
        id310x_1 = id310in_option1;
        break;
      default:
        id310x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id310out_result = (id310x_1);
  }
  { // Node ID: 4182 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4182in_input = id310out_result;

    id4182out_output[(getCycle()+1)%2] = id4182in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id296out_output;

  { // Node ID: 296 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id296in_input = id4185out_output[getCycle()%2];

    id296out_output = id296in_input;
  }
  { // Node ID: 3153 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2811out_result;

  { // Node ID: 2811 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2811in_a = id3153out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2811in_b = id3465out_output[getCycle()%2];

    id2811out_result = (eq_fixed(id2811in_a,id2811in_b));
  }
  { // Node ID: 4186 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4186in_input = id2811out_result;

    id4186out_output[(getCycle()+4)%5] = id4186in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id295out_o;

  { // Node ID: 295 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id295in_i = id4186out_output[getCycle()%5];

    id295out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id295in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id297out_result;

  { // Node ID: 297 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id297in_a = id296out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id297in_b = id295out_o;

    id297out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id297in_a,id297in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id298out_result;

  { // Node ID: 298 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id298in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id298in_option0 = id297out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id298in_option1 = id295out_o;

    HWOffsetFix<32,0,UNSIGNED> id298x_1;

    switch((id298in_sel.getValueAsLong())) {
      case 0l:
        id298x_1 = id298in_option0;
        break;
      case 1l:
        id298x_1 = id298in_option1;
        break;
      default:
        id298x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id298out_result = (id298x_1);
  }
  { // Node ID: 4185 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4185in_input = id298out_result;

    id4185out_output[(getCycle()+1)%2] = id4185in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id284out_output;

  { // Node ID: 284 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id284in_input = id4188out_output[getCycle()%2];

    id284out_output = id284in_input;
  }
  { // Node ID: 3152 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2812out_result;

  { // Node ID: 2812 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2812in_a = id3152out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2812in_b = id3465out_output[getCycle()%2];

    id2812out_result = (eq_fixed(id2812in_a,id2812in_b));
  }
  { // Node ID: 4189 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4189in_input = id2812out_result;

    id4189out_output[(getCycle()+4)%5] = id4189in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id283out_o;

  { // Node ID: 283 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id283in_i = id4189out_output[getCycle()%5];

    id283out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id283in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id285out_result;

  { // Node ID: 285 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id285in_a = id284out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id285in_b = id283out_o;

    id285out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id285in_a,id285in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id286out_result;

  { // Node ID: 286 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id286in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id286in_option0 = id285out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id286in_option1 = id283out_o;

    HWOffsetFix<32,0,UNSIGNED> id286x_1;

    switch((id286in_sel.getValueAsLong())) {
      case 0l:
        id286x_1 = id286in_option0;
        break;
      case 1l:
        id286x_1 = id286in_option1;
        break;
      default:
        id286x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id286out_result = (id286x_1);
  }
  { // Node ID: 4188 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4188in_input = id286out_result;

    id4188out_output[(getCycle()+1)%2] = id4188in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id272out_output;

  { // Node ID: 272 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id272in_input = id4191out_output[getCycle()%2];

    id272out_output = id272in_input;
  }
  { // Node ID: 3151 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2813out_result;

  { // Node ID: 2813 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2813in_a = id3151out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2813in_b = id3465out_output[getCycle()%2];

    id2813out_result = (eq_fixed(id2813in_a,id2813in_b));
  }
  { // Node ID: 4192 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4192in_input = id2813out_result;

    id4192out_output[(getCycle()+4)%5] = id4192in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id271out_o;

  { // Node ID: 271 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id271in_i = id4192out_output[getCycle()%5];

    id271out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id271in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id273out_result;

  { // Node ID: 273 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id273in_a = id272out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id273in_b = id271out_o;

    id273out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id273in_a,id273in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id274out_result;

  { // Node ID: 274 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id274in_sel = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id274in_option0 = id273out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id274in_option1 = id271out_o;

    HWOffsetFix<32,0,UNSIGNED> id274x_1;

    switch((id274in_sel.getValueAsLong())) {
      case 0l:
        id274x_1 = id274in_option0;
        break;
      case 1l:
        id274x_1 = id274in_option1;
        break;
      default:
        id274x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id274out_result = (id274x_1);
  }
  { // Node ID: 4191 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4191in_input = id274out_result;

    id4191out_output[(getCycle()+1)%2] = id4191in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id260out_output;

  { // Node ID: 260 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id260in_input = id4194out_output[getCycle()%2];

    id260out_output = id260in_input;
  }
  { // Node ID: 3150 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2814out_result;

  { // Node ID: 2814 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2814in_a = id3150out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2814in_b = id3465out_output[getCycle()%2];

    id2814out_result = (eq_fixed(id2814in_a,id2814in_b));
  }
  { // Node ID: 4195 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4195in_input = id2814out_result;

    id4195out_output[(getCycle()+4)%5] = id4195in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id259out_o;

  { // Node ID: 259 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id259in_i = id4195out_output[getCycle()%5];

    id259out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id259in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id261out_result;

  { // Node ID: 261 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id261in_a = id260out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id261in_b = id259out_o;

    id261out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id261in_a,id261in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id262out_result;

  { // Node ID: 262 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id262in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id262in_option0 = id261out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id262in_option1 = id259out_o;

    HWOffsetFix<32,0,UNSIGNED> id262x_1;

    switch((id262in_sel.getValueAsLong())) {
      case 0l:
        id262x_1 = id262in_option0;
        break;
      case 1l:
        id262x_1 = id262in_option1;
        break;
      default:
        id262x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id262out_result = (id262x_1);
  }
  { // Node ID: 4194 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4194in_input = id262out_result;

    id4194out_output[(getCycle()+1)%2] = id4194in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id248out_output;

  { // Node ID: 248 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id248in_input = id4196out_output[getCycle()%2];

    id248out_output = id248in_input;
  }
  { // Node ID: 3149 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2815out_result;

  { // Node ID: 2815 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2815in_a = id3149out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2815in_b = id3465out_output[getCycle()%2];

    id2815out_result = (eq_fixed(id2815in_a,id2815in_b));
  }
  { // Node ID: 4197 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4197in_input = id2815out_result;

    id4197out_output[(getCycle()+4)%5] = id4197in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id247out_o;

  { // Node ID: 247 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id247in_i = id4197out_output[getCycle()%5];

    id247out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id247in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id249out_result;

  { // Node ID: 249 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id249in_a = id248out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id249in_b = id247out_o;

    id249out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id249in_a,id249in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id250out_result;

  { // Node ID: 250 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id250in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id250in_option0 = id249out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id250in_option1 = id247out_o;

    HWOffsetFix<32,0,UNSIGNED> id250x_1;

    switch((id250in_sel.getValueAsLong())) {
      case 0l:
        id250x_1 = id250in_option0;
        break;
      case 1l:
        id250x_1 = id250in_option1;
        break;
      default:
        id250x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id250out_result = (id250x_1);
  }
  { // Node ID: 4196 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4196in_input = id250out_result;

    id4196out_output[(getCycle()+1)%2] = id4196in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id236out_output;

  { // Node ID: 236 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id236in_input = id4198out_output[getCycle()%2];

    id236out_output = id236in_input;
  }
  { // Node ID: 3148 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2816out_result;

  { // Node ID: 2816 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2816in_a = id3148out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2816in_b = id3701out_output[getCycle()%54];

    id2816out_result = (eq_fixed(id2816in_a,id2816in_b));
  }
  { // Node ID: 4200 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4200in_input = id2816out_result;

    id4200out_output[(getCycle()+5)%6] = id4200in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id235out_o;

  { // Node ID: 235 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id235in_i = id4200out_output[getCycle()%6];

    id235out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id235in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id237out_result;

  { // Node ID: 237 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id237in_a = id236out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id237in_b = id235out_o;

    id237out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id237in_a,id237in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id238out_result;

  { // Node ID: 238 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id238in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id238in_option0 = id237out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id238in_option1 = id235out_o;

    HWOffsetFix<32,0,UNSIGNED> id238x_1;

    switch((id238in_sel.getValueAsLong())) {
      case 0l:
        id238x_1 = id238in_option0;
        break;
      case 1l:
        id238x_1 = id238in_option1;
        break;
      default:
        id238x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id238out_result = (id238x_1);
  }
  { // Node ID: 4198 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4198in_input = id238out_result;

    id4198out_output[(getCycle()+1)%2] = id4198in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id224out_output;

  { // Node ID: 224 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id224in_input = id4201out_output[getCycle()%2];

    id224out_output = id224in_input;
  }
  { // Node ID: 3147 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2817out_result;

  { // Node ID: 2817 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2817in_a = id3147out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2817in_b = id3701out_output[getCycle()%54];

    id2817out_result = (eq_fixed(id2817in_a,id2817in_b));
  }
  { // Node ID: 4203 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4203in_input = id2817out_result;

    id4203out_output[(getCycle()+5)%6] = id4203in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id223out_o;

  { // Node ID: 223 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id223in_i = id4203out_output[getCycle()%6];

    id223out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id223in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id225out_result;

  { // Node ID: 225 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id225in_a = id224out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id225in_b = id223out_o;

    id225out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id225in_a,id225in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id226out_result;

  { // Node ID: 226 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id226in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id226in_option0 = id225out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id226in_option1 = id223out_o;

    HWOffsetFix<32,0,UNSIGNED> id226x_1;

    switch((id226in_sel.getValueAsLong())) {
      case 0l:
        id226x_1 = id226in_option0;
        break;
      case 1l:
        id226x_1 = id226in_option1;
        break;
      default:
        id226x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id226out_result = (id226x_1);
  }
  { // Node ID: 4201 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4201in_input = id226out_result;

    id4201out_output[(getCycle()+1)%2] = id4201in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id212out_output;

  { // Node ID: 212 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id212in_input = id4204out_output[getCycle()%2];

    id212out_output = id212in_input;
  }
  { // Node ID: 3146 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2818out_result;

  { // Node ID: 2818 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2818in_a = id3146out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2818in_b = id3701out_output[getCycle()%54];

    id2818out_result = (eq_fixed(id2818in_a,id2818in_b));
  }
  { // Node ID: 4206 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4206in_input = id2818out_result;

    id4206out_output[(getCycle()+5)%6] = id4206in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id211out_o;

  { // Node ID: 211 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id211in_i = id4206out_output[getCycle()%6];

    id211out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id211in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id213out_result;

  { // Node ID: 213 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id213in_a = id212out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id213in_b = id211out_o;

    id213out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id213in_a,id213in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id214out_result;

  { // Node ID: 214 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id214in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id214in_option0 = id213out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id214in_option1 = id211out_o;

    HWOffsetFix<32,0,UNSIGNED> id214x_1;

    switch((id214in_sel.getValueAsLong())) {
      case 0l:
        id214x_1 = id214in_option0;
        break;
      case 1l:
        id214x_1 = id214in_option1;
        break;
      default:
        id214x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id214out_result = (id214x_1);
  }
  { // Node ID: 4204 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4204in_input = id214out_result;

    id4204out_output[(getCycle()+1)%2] = id4204in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id200out_output;

  { // Node ID: 200 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id200in_input = id4207out_output[getCycle()%2];

    id200out_output = id200in_input;
  }
  { // Node ID: 3145 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2819out_result;

  { // Node ID: 2819 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2819in_a = id3145out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2819in_b = id3701out_output[getCycle()%54];

    id2819out_result = (eq_fixed(id2819in_a,id2819in_b));
  }
  { // Node ID: 4209 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4209in_input = id2819out_result;

    id4209out_output[(getCycle()+5)%6] = id4209in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id199out_o;

  { // Node ID: 199 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id199in_i = id4209out_output[getCycle()%6];

    id199out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id199in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id201out_result;

  { // Node ID: 201 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id201in_a = id200out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id201in_b = id199out_o;

    id201out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id201in_a,id201in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id202out_result;

  { // Node ID: 202 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id202in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id202in_option0 = id201out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id202in_option1 = id199out_o;

    HWOffsetFix<32,0,UNSIGNED> id202x_1;

    switch((id202in_sel.getValueAsLong())) {
      case 0l:
        id202x_1 = id202in_option0;
        break;
      case 1l:
        id202x_1 = id202in_option1;
        break;
      default:
        id202x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id202out_result = (id202x_1);
  }
  { // Node ID: 4207 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4207in_input = id202out_result;

    id4207out_output[(getCycle()+1)%2] = id4207in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id188out_output;

  { // Node ID: 188 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id188in_input = id4210out_output[getCycle()%2];

    id188out_output = id188in_input;
  }
  { // Node ID: 3144 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2820out_result;

  { // Node ID: 2820 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2820in_a = id3144out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2820in_b = id3701out_output[getCycle()%54];

    id2820out_result = (eq_fixed(id2820in_a,id2820in_b));
  }
  { // Node ID: 4212 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4212in_input = id2820out_result;

    id4212out_output[(getCycle()+5)%6] = id4212in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id187out_o;

  { // Node ID: 187 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id187in_i = id4212out_output[getCycle()%6];

    id187out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id187in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id189out_result;

  { // Node ID: 189 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id189in_a = id188out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id189in_b = id187out_o;

    id189out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id189in_a,id189in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id190out_result;

  { // Node ID: 190 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id190in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id190in_option0 = id189out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id190in_option1 = id187out_o;

    HWOffsetFix<32,0,UNSIGNED> id190x_1;

    switch((id190in_sel.getValueAsLong())) {
      case 0l:
        id190x_1 = id190in_option0;
        break;
      case 1l:
        id190x_1 = id190in_option1;
        break;
      default:
        id190x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id190out_result = (id190x_1);
  }
  { // Node ID: 4210 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4210in_input = id190out_result;

    id4210out_output[(getCycle()+1)%2] = id4210in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id176out_output;

  { // Node ID: 176 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id176in_input = id4213out_output[getCycle()%2];

    id176out_output = id176in_input;
  }
  { // Node ID: 3143 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2821out_result;

  { // Node ID: 2821 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2821in_a = id3143out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2821in_b = id3701out_output[getCycle()%54];

    id2821out_result = (eq_fixed(id2821in_a,id2821in_b));
  }
  { // Node ID: 4215 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4215in_input = id2821out_result;

    id4215out_output[(getCycle()+5)%6] = id4215in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id175out_o;

  { // Node ID: 175 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id175in_i = id4215out_output[getCycle()%6];

    id175out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id175in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id177out_result;

  { // Node ID: 177 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id177in_a = id176out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id177in_b = id175out_o;

    id177out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id177in_a,id177in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id178out_result;

  { // Node ID: 178 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id178in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id178in_option0 = id177out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id178in_option1 = id175out_o;

    HWOffsetFix<32,0,UNSIGNED> id178x_1;

    switch((id178in_sel.getValueAsLong())) {
      case 0l:
        id178x_1 = id178in_option0;
        break;
      case 1l:
        id178x_1 = id178in_option1;
        break;
      default:
        id178x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id178out_result = (id178x_1);
  }
  { // Node ID: 4213 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4213in_input = id178out_result;

    id4213out_output[(getCycle()+1)%2] = id4213in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id164out_output;

  { // Node ID: 164 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id164in_input = id4216out_output[getCycle()%2];

    id164out_output = id164in_input;
  }
  { // Node ID: 3142 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2822out_result;

  { // Node ID: 2822 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2822in_a = id3142out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2822in_b = id3701out_output[getCycle()%54];

    id2822out_result = (eq_fixed(id2822in_a,id2822in_b));
  }
  { // Node ID: 4218 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4218in_input = id2822out_result;

    id4218out_output[(getCycle()+5)%6] = id4218in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id163out_o;

  { // Node ID: 163 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id163in_i = id4218out_output[getCycle()%6];

    id163out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id163in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id165out_result;

  { // Node ID: 165 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id165in_a = id164out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id165in_b = id163out_o;

    id165out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id165in_a,id165in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id166out_result;

  { // Node ID: 166 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id166in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id166in_option0 = id165out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id166in_option1 = id163out_o;

    HWOffsetFix<32,0,UNSIGNED> id166x_1;

    switch((id166in_sel.getValueAsLong())) {
      case 0l:
        id166x_1 = id166in_option0;
        break;
      case 1l:
        id166x_1 = id166in_option1;
        break;
      default:
        id166x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id166out_result = (id166x_1);
  }
  { // Node ID: 4216 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4216in_input = id166out_result;

    id4216out_output[(getCycle()+1)%2] = id4216in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id152out_output;

  { // Node ID: 152 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id152in_input = id4219out_output[getCycle()%2];

    id152out_output = id152in_input;
  }
  { // Node ID: 3141 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2823out_result;

  { // Node ID: 2823 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2823in_a = id3141out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2823in_b = id3701out_output[getCycle()%54];

    id2823out_result = (eq_fixed(id2823in_a,id2823in_b));
  }
  { // Node ID: 4221 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4221in_input = id2823out_result;

    id4221out_output[(getCycle()+5)%6] = id4221in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id151out_o;

  { // Node ID: 151 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_i = id4221out_output[getCycle()%6];

    id151out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id151in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id153out_result;

  { // Node ID: 153 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id153in_a = id152out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id153in_b = id151out_o;

    id153out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id153in_a,id153in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id154out_result;

  { // Node ID: 154 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id154in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id154in_option0 = id153out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id154in_option1 = id151out_o;

    HWOffsetFix<32,0,UNSIGNED> id154x_1;

    switch((id154in_sel.getValueAsLong())) {
      case 0l:
        id154x_1 = id154in_option0;
        break;
      case 1l:
        id154x_1 = id154in_option1;
        break;
      default:
        id154x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id154out_result = (id154x_1);
  }
  { // Node ID: 4219 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4219in_input = id154out_result;

    id4219out_output[(getCycle()+1)%2] = id4219in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id140out_output;

  { // Node ID: 140 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id140in_input = id4222out_output[getCycle()%2];

    id140out_output = id140in_input;
  }
  { // Node ID: 3140 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2824out_result;

  { // Node ID: 2824 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2824in_a = id3140out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2824in_b = id3701out_output[getCycle()%54];

    id2824out_result = (eq_fixed(id2824in_a,id2824in_b));
  }
  { // Node ID: 4224 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4224in_input = id2824out_result;

    id4224out_output[(getCycle()+5)%6] = id4224in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id139out_o;

  { // Node ID: 139 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id139in_i = id4224out_output[getCycle()%6];

    id139out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id139in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id141out_result;

  { // Node ID: 141 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id141in_a = id140out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id141in_b = id139out_o;

    id141out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id141in_a,id141in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id142out_result;

  { // Node ID: 142 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id142in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id142in_option0 = id141out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id142in_option1 = id139out_o;

    HWOffsetFix<32,0,UNSIGNED> id142x_1;

    switch((id142in_sel.getValueAsLong())) {
      case 0l:
        id142x_1 = id142in_option0;
        break;
      case 1l:
        id142x_1 = id142in_option1;
        break;
      default:
        id142x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id142out_result = (id142x_1);
  }
  { // Node ID: 4222 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4222in_input = id142out_result;

    id4222out_output[(getCycle()+1)%2] = id4222in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id128out_output;

  { // Node ID: 128 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id128in_input = id4225out_output[getCycle()%2];

    id128out_output = id128in_input;
  }
  { // Node ID: 3139 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2825out_result;

  { // Node ID: 2825 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2825in_a = id3139out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2825in_b = id3701out_output[getCycle()%54];

    id2825out_result = (eq_fixed(id2825in_a,id2825in_b));
  }
  { // Node ID: 4227 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4227in_input = id2825out_result;

    id4227out_output[(getCycle()+5)%6] = id4227in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id127out_o;

  { // Node ID: 127 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id127in_i = id4227out_output[getCycle()%6];

    id127out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id127in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id129out_result;

  { // Node ID: 129 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id129in_a = id128out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id129in_b = id127out_o;

    id129out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id129in_a,id129in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id130out_result;

  { // Node ID: 130 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id130in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id130in_option0 = id129out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id130in_option1 = id127out_o;

    HWOffsetFix<32,0,UNSIGNED> id130x_1;

    switch((id130in_sel.getValueAsLong())) {
      case 0l:
        id130x_1 = id130in_option0;
        break;
      case 1l:
        id130x_1 = id130in_option1;
        break;
      default:
        id130x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id130out_result = (id130x_1);
  }
  { // Node ID: 4225 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4225in_input = id130out_result;

    id4225out_output[(getCycle()+1)%2] = id4225in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id116out_output;

  { // Node ID: 116 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id116in_input = id4228out_output[getCycle()%2];

    id116out_output = id116in_input;
  }
  { // Node ID: 3138 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2826out_result;

  { // Node ID: 2826 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2826in_a = id3138out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2826in_b = id3701out_output[getCycle()%54];

    id2826out_result = (eq_fixed(id2826in_a,id2826in_b));
  }
  { // Node ID: 4230 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4230in_input = id2826out_result;

    id4230out_output[(getCycle()+5)%6] = id4230in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id115out_o;

  { // Node ID: 115 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id115in_i = id4230out_output[getCycle()%6];

    id115out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id115in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id117out_result;

  { // Node ID: 117 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id117in_a = id116out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id117in_b = id115out_o;

    id117out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id117in_a,id117in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id118out_result;

  { // Node ID: 118 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id118in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id118in_option0 = id117out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id118in_option1 = id115out_o;

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
    id118out_result = (id118x_1);
  }
  { // Node ID: 4228 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4228in_input = id118out_result;

    id4228out_output[(getCycle()+1)%2] = id4228in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id104out_output;

  { // Node ID: 104 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id104in_input = id4231out_output[getCycle()%2];

    id104out_output = id104in_input;
  }
  { // Node ID: 3137 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2827out_result;

  { // Node ID: 2827 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2827in_a = id3137out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2827in_b = id3701out_output[getCycle()%54];

    id2827out_result = (eq_fixed(id2827in_a,id2827in_b));
  }
  { // Node ID: 4233 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4233in_input = id2827out_result;

    id4233out_output[(getCycle()+5)%6] = id4233in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id103out_o;

  { // Node ID: 103 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_i = id4233out_output[getCycle()%6];

    id103out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id103in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id105out_result;

  { // Node ID: 105 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id105in_a = id104out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id105in_b = id103out_o;

    id105out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id105in_a,id105in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id106out_result;

  { // Node ID: 106 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id106in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id106in_option0 = id105out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id106in_option1 = id103out_o;

    HWOffsetFix<32,0,UNSIGNED> id106x_1;

    switch((id106in_sel.getValueAsLong())) {
      case 0l:
        id106x_1 = id106in_option0;
        break;
      case 1l:
        id106x_1 = id106in_option1;
        break;
      default:
        id106x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id106out_result = (id106x_1);
  }
  { // Node ID: 4231 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4231in_input = id106out_result;

    id4231out_output[(getCycle()+1)%2] = id4231in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id92out_output;

  { // Node ID: 92 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id92in_input = id4234out_output[getCycle()%2];

    id92out_output = id92in_input;
  }
  { // Node ID: 3136 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2828out_result;

  { // Node ID: 2828 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2828in_a = id3136out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2828in_b = id3701out_output[getCycle()%54];

    id2828out_result = (eq_fixed(id2828in_a,id2828in_b));
  }
  { // Node ID: 4236 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4236in_input = id2828out_result;

    id4236out_output[(getCycle()+5)%6] = id4236in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id91out_o;

  { // Node ID: 91 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id91in_i = id4236out_output[getCycle()%6];

    id91out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id91in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id93out_result;

  { // Node ID: 93 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id93in_a = id92out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id93in_b = id91out_o;

    id93out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id93in_a,id93in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id94out_result;

  { // Node ID: 94 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id94in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id94in_option0 = id93out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id94in_option1 = id91out_o;

    HWOffsetFix<32,0,UNSIGNED> id94x_1;

    switch((id94in_sel.getValueAsLong())) {
      case 0l:
        id94x_1 = id94in_option0;
        break;
      case 1l:
        id94x_1 = id94in_option1;
        break;
      default:
        id94x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id94out_result = (id94x_1);
  }
  { // Node ID: 4234 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4234in_input = id94out_result;

    id4234out_output[(getCycle()+1)%2] = id4234in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id80out_output;

  { // Node ID: 80 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id80in_input = id4237out_output[getCycle()%2];

    id80out_output = id80in_input;
  }
  { // Node ID: 3135 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2829out_result;

  { // Node ID: 2829 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2829in_a = id3135out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2829in_b = id3701out_output[getCycle()%54];

    id2829out_result = (eq_fixed(id2829in_a,id2829in_b));
  }
  { // Node ID: 4239 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4239in_input = id2829out_result;

    id4239out_output[(getCycle()+5)%6] = id4239in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id79out_o;

  { // Node ID: 79 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_i = id4239out_output[getCycle()%6];

    id79out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id79in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id81out_result;

  { // Node ID: 81 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id81in_a = id80out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id81in_b = id79out_o;

    id81out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id81in_a,id81in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id82out_result;

  { // Node ID: 82 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id82in_sel = id3448out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id82in_option0 = id81out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id82in_option1 = id79out_o;

    HWOffsetFix<32,0,UNSIGNED> id82x_1;

    switch((id82in_sel.getValueAsLong())) {
      case 0l:
        id82x_1 = id82in_option0;
        break;
      case 1l:
        id82x_1 = id82in_option1;
        break;
      default:
        id82x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id82out_result = (id82x_1);
  }
  { // Node ID: 4237 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4237in_input = id82out_result;

    id4237out_output[(getCycle()+1)%2] = id4237in_input;
  }
  HWRawBits<9728> id3131out_result;

  { // Node ID: 3131 (NodeCat)
    const HWRawBits<32> &id3131in_in0 = id2517out_value;
    const HWRawBits<32> &id3131in_in1 = id2518out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in2 = id1288out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in3 = id1276out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in4 = id1264out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in5 = id1252out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in6 = id1240out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in7 = id1228out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in8 = id1216out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in9 = id1204out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in10 = id1192out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in11 = id1180out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in12 = id1168out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in13 = id1156out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in14 = id1144out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in15 = id1132out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in16 = id1120out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in17 = id1108out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in18 = id1096out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in19 = id1084out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in20 = id1072out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in21 = id1060out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in22 = id1048out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in23 = id1036out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in24 = id1024out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in25 = id1012out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in26 = id1000out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in27 = id988out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in28 = id976out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in29 = id964out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in30 = id952out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in31 = id940out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in32 = id928out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in33 = id916out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in34 = id3541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in35 = id3543out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in36 = id3545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in37 = id3547out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in38 = id3549out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in39 = id3551out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in40 = id3553out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in41 = id3555out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in42 = id3557out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in43 = id3559out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in44 = id3561out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in45 = id3563out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in46 = id3565out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in47 = id3567out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in48 = id3569out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in49 = id3571out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in50 = id3573out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in51 = id3575out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in52 = id3577out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in53 = id3579out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in54 = id3581out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in55 = id3583out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in56 = id3585out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in57 = id3587out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in58 = id3589out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in59 = id3591out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in60 = id3593out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in61 = id3595out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in62 = id3597out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in63 = id3599out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in64 = id3601out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in65 = id3603out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in66 = id3606out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in67 = id3609out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in68 = id3612out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in69 = id3615out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in70 = id3618out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in71 = id3621out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in72 = id3624out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in73 = id3627out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in74 = id3630out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in75 = id3633out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in76 = id3636out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in77 = id3639out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in78 = id3642out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in79 = id3645out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in80 = id3648out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in81 = id3651out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in82 = id3654out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in83 = id3657out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in84 = id3660out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in85 = id3663out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in86 = id3666out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in87 = id3669out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in88 = id3671out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in89 = id3673out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in90 = id3675out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in91 = id3677out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in92 = id3679out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in93 = id3681out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in94 = id3683out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in95 = id3685out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in96 = id3687out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in97 = id3689out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in98 = id3691out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in99 = id3693out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in100 = id3695out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in101 = id3697out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in102 = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in103 = id1888out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in104 = id1882out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in105 = id1876out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in106 = id1870out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in107 = id1864out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in108 = id1858out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in109 = id1852out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in110 = id1846out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in111 = id1840out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in112 = id1834out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in113 = id1828out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in114 = id1822out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in115 = id1816out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in116 = id1810out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in117 = id1804out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in118 = id1798out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in119 = id1792out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in120 = id1786out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in121 = id1780out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in122 = id1774out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in123 = id1768out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in124 = id1762out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in125 = id1756out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in126 = id1750out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in127 = id1744out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in128 = id1738out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in129 = id1732out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in130 = id1726out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in131 = id1720out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in132 = id1714out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in133 = id1708out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in134 = id1702out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in135 = id3766out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in136 = id3768out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in137 = id3770out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in138 = id3772out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in139 = id3774out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in140 = id3776out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in141 = id3778out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in142 = id3780out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in143 = id3782out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in144 = id3784out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in145 = id3786out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in146 = id3788out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in147 = id3790out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in148 = id3792out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in149 = id3794out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in150 = id3796out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in151 = id3798out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in152 = id3800out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in153 = id3802out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in154 = id3804out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in155 = id3806out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in156 = id3808out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in157 = id3810out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in158 = id3812out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in159 = id3814out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in160 = id3816out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in161 = id3818out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in162 = id3820out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in163 = id3822out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in164 = id3824out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in165 = id3826out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in166 = id3828out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in167 = id3831out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in168 = id3834out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in169 = id3837out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in170 = id3840out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in171 = id3843out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in172 = id3846out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in173 = id3849out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in174 = id3852out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in175 = id3855out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in176 = id3858out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in177 = id3861out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in178 = id3864out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in179 = id3867out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in180 = id3870out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in181 = id3873out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in182 = id3876out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in183 = id3879out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in184 = id3882out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in185 = id3885out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in186 = id3888out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in187 = id3891out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in188 = id3894out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in189 = id3897out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in190 = id3900out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in191 = id3903out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in192 = id3906out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in193 = id3909out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in194 = id3912out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in195 = id3915out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in196 = id3918out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in197 = id3921out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in198 = id3924out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in199 = id3927out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in200 = id3930out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in201 = id3933out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in202 = id3936out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in203 = id3939out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in204 = id3942out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in205 = id3945out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in206 = id3948out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in207 = id3951out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in208 = id3954out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in209 = id3957out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in210 = id3960out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in211 = id3963out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in212 = id3966out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in213 = id3969out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in214 = id3972out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in215 = id3975out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in216 = id3978out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in217 = id3981out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in218 = id3984out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in219 = id3987out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in220 = id3990out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in221 = id3993out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in222 = id3996out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in223 = id3999out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in224 = id4002out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in225 = id4005out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in226 = id4008out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in227 = id4011out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in228 = id4014out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in229 = id4017out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in230 = id4020out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in231 = id4023out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in232 = id4026out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in233 = id4029out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in234 = id4032out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in235 = id4035out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in236 = id4038out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in237 = id4041out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in238 = id4044out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in239 = id4047out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in240 = id4050out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in241 = id4053out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in242 = id4056out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in243 = id4059out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in244 = id4062out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in245 = id4065out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in246 = id4068out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in247 = id4071out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in248 = id4074out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in249 = id4077out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in250 = id4080out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in251 = id4083out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in252 = id4086out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in253 = id4089out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in254 = id4092out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in255 = id4095out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in256 = id4098out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in257 = id4101out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in258 = id4104out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in259 = id4107out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in260 = id4110out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in261 = id4113out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in262 = id4116out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in263 = id4119out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in264 = id4122out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in265 = id4125out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in266 = id4128out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in267 = id4131out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in268 = id4134out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in269 = id4137out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in270 = id4140out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in271 = id4143out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in272 = id4146out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in273 = id4149out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in274 = id4152out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in275 = id4155out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in276 = id4158out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in277 = id4161out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in278 = id4164out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in279 = id4167out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in280 = id4170out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in281 = id4173out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in282 = id4176out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in283 = id4179out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in284 = id4182out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in285 = id4185out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in286 = id4188out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in287 = id4191out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in288 = id4194out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in289 = id4196out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in290 = id4198out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in291 = id4201out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in292 = id4204out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in293 = id4207out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in294 = id4210out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in295 = id4213out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in296 = id4216out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in297 = id4219out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in298 = id4222out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in299 = id4225out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in300 = id4228out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in301 = id4231out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in302 = id4234out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3131in_in303 = id4237out_output[getCycle()%2];

    id3131out_result = (cat((cat((cat((cat((cat((cat((cat((cat((cat(id3131in_in0,id3131in_in1)),id3131in_in2)),(cat(id3131in_in3,id3131in_in4)))),(cat((cat((cat(id3131in_in5,id3131in_in6)),id3131in_in7)),(cat(id3131in_in8,id3131in_in9)))))),(cat((cat((cat((cat(id3131in_in10,id3131in_in11)),id3131in_in12)),(cat(id3131in_in13,id3131in_in14)))),(cat((cat(id3131in_in15,id3131in_in16)),(cat(id3131in_in17,id3131in_in18)))))))),(cat((cat((cat((cat((cat(id3131in_in19,id3131in_in20)),id3131in_in21)),(cat(id3131in_in22,id3131in_in23)))),(cat((cat((cat(id3131in_in24,id3131in_in25)),id3131in_in26)),(cat(id3131in_in27,id3131in_in28)))))),(cat((cat((cat((cat(id3131in_in29,id3131in_in30)),id3131in_in31)),(cat(id3131in_in32,id3131in_in33)))),(cat((cat(id3131in_in34,id3131in_in35)),(cat(id3131in_in36,id3131in_in37)))))))))),(cat((cat((cat((cat((cat((cat(id3131in_in38,id3131in_in39)),id3131in_in40)),(cat(id3131in_in41,id3131in_in42)))),(cat((cat((cat(id3131in_in43,id3131in_in44)),id3131in_in45)),(cat(id3131in_in46,id3131in_in47)))))),(cat((cat((cat((cat(id3131in_in48,id3131in_in49)),id3131in_in50)),(cat(id3131in_in51,id3131in_in52)))),(cat((cat(id3131in_in53,id3131in_in54)),(cat(id3131in_in55,id3131in_in56)))))))),(cat((cat((cat((cat((cat(id3131in_in57,id3131in_in58)),id3131in_in59)),(cat(id3131in_in60,id3131in_in61)))),(cat((cat((cat(id3131in_in62,id3131in_in63)),id3131in_in64)),(cat(id3131in_in65,id3131in_in66)))))),(cat((cat((cat((cat(id3131in_in67,id3131in_in68)),id3131in_in69)),(cat(id3131in_in70,id3131in_in71)))),(cat((cat(id3131in_in72,id3131in_in73)),(cat(id3131in_in74,id3131in_in75)))))))))))),(cat((cat((cat((cat((cat((cat((cat(id3131in_in76,id3131in_in77)),id3131in_in78)),(cat(id3131in_in79,id3131in_in80)))),(cat((cat((cat(id3131in_in81,id3131in_in82)),id3131in_in83)),(cat(id3131in_in84,id3131in_in85)))))),(cat((cat((cat((cat(id3131in_in86,id3131in_in87)),id3131in_in88)),(cat(id3131in_in89,id3131in_in90)))),(cat((cat(id3131in_in91,id3131in_in92)),(cat(id3131in_in93,id3131in_in94)))))))),(cat((cat((cat((cat((cat(id3131in_in95,id3131in_in96)),id3131in_in97)),(cat(id3131in_in98,id3131in_in99)))),(cat((cat((cat(id3131in_in100,id3131in_in101)),id3131in_in102)),(cat(id3131in_in103,id3131in_in104)))))),(cat((cat((cat((cat(id3131in_in105,id3131in_in106)),id3131in_in107)),(cat(id3131in_in108,id3131in_in109)))),(cat((cat(id3131in_in110,id3131in_in111)),(cat(id3131in_in112,id3131in_in113)))))))))),(cat((cat((cat((cat((cat((cat(id3131in_in114,id3131in_in115)),id3131in_in116)),(cat(id3131in_in117,id3131in_in118)))),(cat((cat((cat(id3131in_in119,id3131in_in120)),id3131in_in121)),(cat(id3131in_in122,id3131in_in123)))))),(cat((cat((cat((cat(id3131in_in124,id3131in_in125)),id3131in_in126)),(cat(id3131in_in127,id3131in_in128)))),(cat((cat(id3131in_in129,id3131in_in130)),(cat(id3131in_in131,id3131in_in132)))))))),(cat((cat((cat((cat((cat(id3131in_in133,id3131in_in134)),id3131in_in135)),(cat(id3131in_in136,id3131in_in137)))),(cat((cat((cat(id3131in_in138,id3131in_in139)),id3131in_in140)),(cat(id3131in_in141,id3131in_in142)))))),(cat((cat((cat((cat(id3131in_in143,id3131in_in144)),id3131in_in145)),(cat(id3131in_in146,id3131in_in147)))),(cat((cat(id3131in_in148,id3131in_in149)),(cat(id3131in_in150,id3131in_in151)))))))))))))),(cat((cat((cat((cat((cat((cat((cat((cat(id3131in_in152,id3131in_in153)),id3131in_in154)),(cat(id3131in_in155,id3131in_in156)))),(cat((cat((cat(id3131in_in157,id3131in_in158)),id3131in_in159)),(cat(id3131in_in160,id3131in_in161)))))),(cat((cat((cat((cat(id3131in_in162,id3131in_in163)),id3131in_in164)),(cat(id3131in_in165,id3131in_in166)))),(cat((cat(id3131in_in167,id3131in_in168)),(cat(id3131in_in169,id3131in_in170)))))))),(cat((cat((cat((cat((cat(id3131in_in171,id3131in_in172)),id3131in_in173)),(cat(id3131in_in174,id3131in_in175)))),(cat((cat((cat(id3131in_in176,id3131in_in177)),id3131in_in178)),(cat(id3131in_in179,id3131in_in180)))))),(cat((cat((cat((cat(id3131in_in181,id3131in_in182)),id3131in_in183)),(cat(id3131in_in184,id3131in_in185)))),(cat((cat(id3131in_in186,id3131in_in187)),(cat(id3131in_in188,id3131in_in189)))))))))),(cat((cat((cat((cat((cat((cat(id3131in_in190,id3131in_in191)),id3131in_in192)),(cat(id3131in_in193,id3131in_in194)))),(cat((cat((cat(id3131in_in195,id3131in_in196)),id3131in_in197)),(cat(id3131in_in198,id3131in_in199)))))),(cat((cat((cat((cat(id3131in_in200,id3131in_in201)),id3131in_in202)),(cat(id3131in_in203,id3131in_in204)))),(cat((cat(id3131in_in205,id3131in_in206)),(cat(id3131in_in207,id3131in_in208)))))))),(cat((cat((cat((cat((cat(id3131in_in209,id3131in_in210)),id3131in_in211)),(cat(id3131in_in212,id3131in_in213)))),(cat((cat((cat(id3131in_in214,id3131in_in215)),id3131in_in216)),(cat(id3131in_in217,id3131in_in218)))))),(cat((cat((cat((cat(id3131in_in219,id3131in_in220)),id3131in_in221)),(cat(id3131in_in222,id3131in_in223)))),(cat((cat(id3131in_in224,id3131in_in225)),(cat(id3131in_in226,id3131in_in227)))))))))))),(cat((cat((cat((cat((cat((cat((cat(id3131in_in228,id3131in_in229)),id3131in_in230)),(cat(id3131in_in231,id3131in_in232)))),(cat((cat((cat(id3131in_in233,id3131in_in234)),id3131in_in235)),(cat(id3131in_in236,id3131in_in237)))))),(cat((cat((cat((cat(id3131in_in238,id3131in_in239)),id3131in_in240)),(cat(id3131in_in241,id3131in_in242)))),(cat((cat(id3131in_in243,id3131in_in244)),(cat(id3131in_in245,id3131in_in246)))))))),(cat((cat((cat((cat((cat(id3131in_in247,id3131in_in248)),id3131in_in249)),(cat(id3131in_in250,id3131in_in251)))),(cat((cat((cat(id3131in_in252,id3131in_in253)),id3131in_in254)),(cat(id3131in_in255,id3131in_in256)))))),(cat((cat((cat((cat(id3131in_in257,id3131in_in258)),id3131in_in259)),(cat(id3131in_in260,id3131in_in261)))),(cat((cat(id3131in_in262,id3131in_in263)),(cat(id3131in_in264,id3131in_in265)))))))))),(cat((cat((cat((cat((cat((cat(id3131in_in266,id3131in_in267)),id3131in_in268)),(cat(id3131in_in269,id3131in_in270)))),(cat((cat((cat(id3131in_in271,id3131in_in272)),id3131in_in273)),(cat(id3131in_in274,id3131in_in275)))))),(cat((cat((cat((cat(id3131in_in276,id3131in_in277)),id3131in_in278)),(cat(id3131in_in279,id3131in_in280)))),(cat((cat(id3131in_in281,id3131in_in282)),(cat(id3131in_in283,id3131in_in284)))))))),(cat((cat((cat((cat((cat(id3131in_in285,id3131in_in286)),id3131in_in287)),(cat(id3131in_in288,id3131in_in289)))),(cat((cat((cat(id3131in_in290,id3131in_in291)),id3131in_in292)),(cat(id3131in_in293,id3131in_in294)))))),(cat((cat((cat((cat(id3131in_in295,id3131in_in296)),id3131in_in297)),(cat(id3131in_in298,id3131in_in299)))),(cat((cat(id3131in_in300,id3131in_in301)),(cat(id3131in_in302,id3131in_in303))))))))))))))));
  }
  if ( (getFillLevel() >= (122l)) && (getFlushLevel() < (122l)|| !isFlushingActive() ))
  { // Node ID: 1897 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1897in_output_control = id4478out_output[getCycle()%112];
    const HWRawBits<9728> &id1897in_data = id3131out_result;

    bool id1897x_1;

    (id1897x_1) = ((id1897in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(122l))&(isFlushingActive()))));
    if((id1897x_1)) {
      writeOutput(m_output, id1897in_data);
    }
  }
  { // Node ID: 2509 (NodeConstantRawBits)
  }
  { // Node ID: 3134 (NodeConstantRawBits)
  }
  { // Node ID: 2506 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 2507 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id2507in_enable = id3134out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id2507in_max = id2506out_value;

    HWOffsetFix<49,0,UNSIGNED> id2507x_1;
    HWOffsetFix<1,0,UNSIGNED> id2507x_2;
    HWOffsetFix<1,0,UNSIGNED> id2507x_3;
    HWOffsetFix<49,0,UNSIGNED> id2507x_4t_1e_1;

    id2507out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id2507st_count)));
    (id2507x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id2507st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id2507x_2) = (gte_fixed((id2507x_1),id2507in_max));
    (id2507x_3) = (and_fixed((id2507x_2),id2507in_enable));
    id2507out_wrap = (id2507x_3);
    if((id2507in_enable.getValueAsBool())) {
      if(((id2507x_3).getValueAsBool())) {
        (id2507st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id2507x_4t_1e_1) = (id2507x_1);
        (id2507st_count) = (id2507x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id2508out_output;

  { // Node ID: 2508 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id2508in_input = id2507out_count;

    id2508out_output = id2508in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 2510 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id2510in_load = id2509out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id2510in_data = id2508out_output;

    bool id2510x_1;

    (id2510x_1) = ((id2510in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id2510x_1)) {
      setMappedRegValue("current_run_cycle_count", id2510in_data);
    }
  }
  { // Node ID: 3133 (NodeConstantRawBits)
  }
  { // Node ID: 2512 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 2513 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id2513in_enable = id3133out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id2513in_max = id2512out_value;

    HWOffsetFix<49,0,UNSIGNED> id2513x_1;
    HWOffsetFix<1,0,UNSIGNED> id2513x_2;
    HWOffsetFix<1,0,UNSIGNED> id2513x_3;
    HWOffsetFix<49,0,UNSIGNED> id2513x_4t_1e_1;

    id2513out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id2513st_count)));
    (id2513x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id2513st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id2513x_2) = (gte_fixed((id2513x_1),id2513in_max));
    (id2513x_3) = (and_fixed((id2513x_2),id2513in_enable));
    id2513out_wrap = (id2513x_3);
    if((id2513in_enable.getValueAsBool())) {
      if(((id2513x_3).getValueAsBool())) {
        (id2513st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id2513x_4t_1e_1) = (id2513x_1);
        (id2513st_count) = (id2513x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 2515 (NodeInputMappedReg)
  }
  { // Node ID: 3132 (NodeEqInlined)
    const HWOffsetFix<48,0,UNSIGNED> &id3132in_a = id2513out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id3132in_b = id2515out_run_cycle_count;

    id3132out_result[(getCycle()+1)%2] = (eq_fixed(id3132in_a,id3132in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 2514 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id2514in_start = id3132out_result[getCycle()%2];

    if((id2514in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
