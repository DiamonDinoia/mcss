#include "stdsimheader.h"

namespace maxcompilersim {

void processingKernel::execute0() {
  { // Node ID: 2567 (NodeConstantRawBits)
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
  HWRawBits<32> id19out_result;

  { // Node ID: 19 (NodeSlice)
    const HWRawBits<224> &id19in_a = id6out_data;

    id19out_result = (slice<192,32>(id19in_a));
  }
  HWFloat<8,24> id20out_output;

  { // Node ID: 20 (NodeReinterpret)
    const HWRawBits<32> &id20in_input = id19out_result;

    id20out_output = (cast_bits2float<8,24>(id20in_input));
  }
  { // Node ID: 3539 (NodeFIFO)
    const HWFloat<8,24> &id3539in_input = id20out_output;

    id3539out_output[(getCycle()+47)%48] = id3539in_input;
  }
  { // Node ID: 4538 (NodeFIFO)
    const HWFloat<8,24> &id4538in_input = id3539out_output[getCycle()%48];

    id4538out_output[(getCycle()+66)%67] = id4538in_input;
  }
  if ( (getFillLevel() >= (122l)) && (getFlushLevel() < (122l)|| !isFlushingActive() ))
  { // Node ID: 2568 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id2568in_output_control = id2567out_value;
    const HWFloat<8,24> &id2568in_data = id4538out_output[getCycle()%67];

    bool id2568x_1;

    (id2568x_1) = ((id2568in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(122l))&(isFlushingActive()))));
    if((id2568x_1)) {
      writeOutput(m_internal_watch_tracklength_output, id2568in_data);
    }
  }
  HWRawBits<32> id11out_result;

  { // Node ID: 11 (NodeSlice)
    const HWRawBits<224> &id11in_a = id6out_data;

    id11out_result = (slice<64,32>(id11in_a));
  }
  HWFloat<8,24> id12out_output;

  { // Node ID: 12 (NodeReinterpret)
    const HWRawBits<32> &id12in_input = id11out_result;

    id12out_output = (cast_bits2float<8,24>(id12in_input));
  }
  { // Node ID: 22 (NodeDiv)
    const HWFloat<8,24> &id22in_a = id12out_output;
    const HWFloat<8,24> &id22in_b = id20out_output;

    id22out_result[(getCycle()+28)%29] = (div_float(id22in_a,id22in_b));
  }
  { // Node ID: 3527 (NodeFIFO)
    const HWFloat<8,24> &id3527in_input = id22out_result[getCycle()%29];

    id3527out_output[(getCycle()+33)%34] = id3527in_input;
  }
  { // Node ID: 3507 (NodeConstantRawBits)
  }
  { // Node ID: 24 (NodeAdd)
    const HWFloat<8,24> &id24in_a = id3527out_output[getCycle()%34];
    const HWFloat<8,24> &id24in_b = id3507out_value;

    id24out_result[(getCycle()+11)%12] = (add_float(id24in_a,id24in_b));
  }
  { // Node ID: 3506 (NodeConstantRawBits)
  }
  { // Node ID: 26 (NodeMul)
    const HWFloat<8,24> &id26in_a = id24out_result[getCycle()%12];
    const HWFloat<8,24> &id26in_b = id3506out_value;

    id26out_result[(getCycle()+8)%9] = (mul_float(id26in_a,id26in_b));
  }
  HWFloat<8,24> id27out_result;

  { // Node ID: 27 (NodeNeg)
    const HWFloat<8,24> &id27in_a = id26out_result[getCycle()%9];

    id27out_result = (neg_float(id27in_a));
  }
  HWRawBits<8> id28out_result;

  { // Node ID: 28 (NodeSlice)
    const HWFloat<8,24> &id28in_a = id27out_result;

    id28out_result = (slice<23,8>(id28in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id29out_output;

  { // Node ID: 29 (NodeReinterpret)
    const HWRawBits<8> &id29in_input = id28out_result;

    id29out_output = (cast_bits2fixed<8,0,UNSIGNED>(id29in_input));
  }
  { // Node ID: 3505 (NodeConstantRawBits)
  }
  { // Node ID: 31 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id31in_a = id29out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id31in_b = id3505out_value;

    id31out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id31in_a,id31in_b));
  }
  HWRawBits<1> id2571out_result;

  { // Node ID: 2571 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2571in_a = id31out_result[getCycle()%2];

    id2571out_result = (slice<8,1>(id2571in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id2572out_output;

  { // Node ID: 2572 (NodeReinterpret)
    const HWRawBits<1> &id2572in_input = id2571out_result;

    id2572out_output = (cast_bits2fixed<1,0,UNSIGNED>(id2572in_input));
  }
  { // Node ID: 3528 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3528in_input = id2572out_output;

    id3528out_output[(getCycle()+1)%2] = id3528in_input;
  }
  { // Node ID: 3504 (NodeConstantRawBits)
  }
  { // Node ID: 2573 (NodeEqInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2573in_a = id31out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2573in_b = id3504out_value;

    id2573out_result[(getCycle()+1)%2] = (eq_fixed(id2573in_a,id2573in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id51out_result;

  { // Node ID: 51 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id51in_a = id2573out_result[getCycle()%2];

    id51out_result = (not_fixed(id51in_a));
  }
  { // Node ID: 52 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id52in_a = id3528out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id52in_b = id51out_result;

    HWOffsetFix<1,0,UNSIGNED> id52x_1;

    (id52x_1) = (and_fixed(id52in_a,id52in_b));
    id52out_result[(getCycle()+1)%2] = (id52x_1);
  }
  { // Node ID: 3535 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3535in_input = id52out_result[getCycle()%2];

    id3535out_output[(getCycle()+8)%9] = id3535in_input;
  }
  { // Node ID: 3533 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3533in_input = id2573out_result[getCycle()%2];

    id3533out_output[(getCycle()+9)%10] = id3533in_input;
  }
  { // Node ID: 3530 (NodeFIFO)
    const HWFloat<8,24> &id3530in_input = id27out_result;

    id3530out_output[(getCycle()+7)%8] = id3530in_input;
  }
  { // Node ID: 4540 (NodeFIFO)
    const HWFloat<8,24> &id4540in_input = id3530out_output[getCycle()%8];

    id4540out_output[(getCycle()+1)%2] = id4540in_input;
  }
  { // Node ID: 3503 (NodeConstantRawBits)
  }
  { // Node ID: 46 (NodeGt)
    const HWFloat<8,24> &id46in_a = id4540out_output[getCycle()%2];
    const HWFloat<8,24> &id46in_b = id3503out_value;

    id46out_result[(getCycle()+2)%3] = (gt_float(id46in_a,id46in_b));
  }
  HWRawBits<32> id2574out_output;

  { // Node ID: 2574 (NodeReinterpret)
    const HWFloat<8,24> &id2574in_input = id3530out_output[getCycle()%8];

    id2574out_output = (cast_float2bits(id2574in_input));
  }
  { // Node ID: 3502 (NodeConstantRawBits)
  }
  { // Node ID: 34 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id34in_a = id3502out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id34in_b = id31out_result[getCycle()%2];

    id34out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id34in_a,id34in_b));
  }
  { // Node ID: 3501 (NodeConstantRawBits)
  }
  { // Node ID: 2575 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2575in_a = id34out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2575in_b = id3501out_value;

    id2575out_result[(getCycle()+1)%2] = (gt_fixed(id2575in_a,id2575in_b));
  }
  { // Node ID: 3531 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3531in_input = id2575out_result[getCycle()%2];

    id3531out_output[(getCycle()+3)%4] = id3531in_input;
  }
  { // Node ID: 35 (NodeConstantRawBits)
  }
  HWOffsetFix<5,0,UNSIGNED> id38out_o;

  { // Node ID: 38 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id38in_i = id34out_result[getCycle()%2];

    id38out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id38in_i));
  }
  { // Node ID: 39 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id39in_datain = id35out_value;
    const HWOffsetFix<5,0,UNSIGNED> &id39in_shift = id38out_o;

    id39out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id39in_datain,(id39in_shift.getValueAsLong())));
  }
  HWOffsetFix<32,0,UNSIGNED> id40out_output;

  { // Node ID: 40 (NodeReinterpret)
    const HWRawBits<32> &id40in_input = id39out_dataout[getCycle()%5];

    id40out_output = (cast_bits2fixed<32,0,UNSIGNED>(id40in_input));
  }
  { // Node ID: 41 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id41in_sel = id3531out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id41in_option0 = id35out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id41in_option1 = id40out_output;

    HWOffsetFix<32,0,UNSIGNED> id41x_1;

    switch((id41in_sel.getValueAsLong())) {
      case 0l:
        id41x_1 = id41in_option0;
        break;
      case 1l:
        id41x_1 = id41in_option1;
        break;
      default:
        id41x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id41out_result[(getCycle()+1)%2] = (id41x_1);
  }
  HWRawBits<32> id42out_output;

  { // Node ID: 42 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id42in_input = id41out_result[getCycle()%2];

    id42out_output = (cast_fixed2bits(id42in_input));
  }
  { // Node ID: 43 (NodeAnd)
    const HWRawBits<32> &id43in_a = id2574out_output;
    const HWRawBits<32> &id43in_b = id42out_output;

    HWRawBits<32> id43x_1;

    (id43x_1) = (and_bits(id43in_a,id43in_b));
    id43out_result[(getCycle()+1)%2] = (id43x_1);
  }
  HWFloat<8,24> id44out_output;

  { // Node ID: 44 (NodeReinterpret)
    const HWRawBits<32> &id44in_input = id43out_result[getCycle()%2];

    id44out_output = (cast_bits2float<8,24>(id44in_input));
  }
  { // Node ID: 53 (NodeNeq)
    const HWFloat<8,24> &id53in_a = id44out_output;
    const HWFloat<8,24> &id53in_b = id4540out_output[getCycle()%2];

    id53out_result[(getCycle()+2)%3] = (neq_float(id53in_a,id53in_b));
  }
  { // Node ID: 54 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id54in_a = id46out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id54in_b = id53out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id54x_1;

    (id54x_1) = (and_fixed(id54in_a,id54in_b));
    id54out_result[(getCycle()+1)%2] = (id54x_1);
  }
  { // Node ID: 57 (NodeConstantRawBits)
  }
  { // Node ID: 56 (NodeConstantRawBits)
  }
  HWOffsetFix<2,0,UNSIGNED> id58out_result;

  { // Node ID: 58 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id58in_sel = id54out_result[getCycle()%2];
    const HWOffsetFix<2,0,UNSIGNED> &id58in_option0 = id57out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id58in_option1 = id56out_value;

    HWOffsetFix<2,0,UNSIGNED> id58x_1;

    switch((id58in_sel.getValueAsLong())) {
      case 0l:
        id58x_1 = id58in_option0;
        break;
      case 1l:
        id58x_1 = id58in_option1;
        break;
      default:
        id58x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id58out_result = (id58x_1);
  }
  { // Node ID: 59 (NodeConstantRawBits)
  }
  HWOffsetFix<2,0,UNSIGNED> id60out_result;

  { // Node ID: 60 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id60in_sel = id3533out_output[getCycle()%10];
    const HWOffsetFix<2,0,UNSIGNED> &id60in_option0 = id58out_result;
    const HWOffsetFix<2,0,UNSIGNED> &id60in_option1 = id59out_value;

    HWOffsetFix<2,0,UNSIGNED> id60x_1;

    switch((id60in_sel.getValueAsLong())) {
      case 0l:
        id60x_1 = id60in_option0;
        break;
      case 1l:
        id60x_1 = id60in_option1;
        break;
      default:
        id60x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id60out_result = (id60x_1);
  }
  { // Node ID: 3534 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3534in_input = id46out_result[getCycle()%3];

    id3534out_output[(getCycle()+1)%2] = id3534in_input;
  }
  HWOffsetFix<2,0,UNSIGNED> id55out_o;

  { // Node ID: 55 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id55in_i = id3534out_output[getCycle()%2];

    id55out_o = (cast_fixed2fixed<2,0,UNSIGNED,TONEAREVEN>(id55in_i));
  }
  HWOffsetFix<2,0,UNSIGNED> id61out_result;

  { // Node ID: 61 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id61in_sel = id3535out_output[getCycle()%9];
    const HWOffsetFix<2,0,UNSIGNED> &id61in_option0 = id60out_result;
    const HWOffsetFix<2,0,UNSIGNED> &id61in_option1 = id55out_o;

    HWOffsetFix<2,0,UNSIGNED> id61x_1;

    switch((id61in_sel.getValueAsLong())) {
      case 0l:
        id61x_1 = id61in_option0;
        break;
      case 1l:
        id61x_1 = id61in_option1;
        break;
      default:
        id61x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id61out_result = (id61x_1);
  }
  { // Node ID: 3536 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id3536in_input = id61out_result;

    id3536out_output[(getCycle()+8)%9] = id3536in_input;
  }
  { // Node ID: 2563 (NodeConstantRawBits)
  }
  { // Node ID: 62 (NodeConstantRawBits)
  }
  { // Node ID: 3537 (NodeFIFO)
    const HWFloat<8,24> &id3537in_input = id44out_output;

    id3537out_output[(getCycle()+11)%12] = id3537in_input;
  }
  { // Node ID: 3500 (NodeConstantRawBits)
  }
  { // Node ID: 66 (NodeAdd)
    const HWFloat<8,24> &id66in_a = id44out_output;
    const HWFloat<8,24> &id66in_b = id3500out_value;

    id66out_result[(getCycle()+11)%12] = (add_float(id66in_a,id66in_b));
  }
  { // Node ID: 67 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id67in_sel = id3536out_output[getCycle()%9];
    const HWFloat<8,24> &id67in_option0 = id2563out_value;
    const HWFloat<8,24> &id67in_option1 = id62out_value;
    const HWFloat<8,24> &id67in_option2 = id3537out_output[getCycle()%12];
    const HWFloat<8,24> &id67in_option3 = id66out_result[getCycle()%12];

    HWFloat<8,24> id67x_1;

    switch((id67in_sel.getValueAsLong())) {
      case 0l:
        id67x_1 = id67in_option0;
        break;
      case 1l:
        id67x_1 = id67in_option1;
        break;
      case 2l:
        id67x_1 = id67in_option2;
        break;
      case 3l:
        id67x_1 = id67in_option3;
        break;
      default:
        id67x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id67out_result[(getCycle()+1)%2] = (id67x_1);
  }
  HWFloat<8,24> id68out_result;

  { // Node ID: 68 (NodeNeg)
    const HWFloat<8,24> &id68in_a = id67out_result[getCycle()%2];

    id68out_result = (neg_float(id68in_a));
  }
  { // Node ID: 69 (NodeCast)
    const HWFloat<8,24> &id69in_i = id68out_result;

    id69out_o[(getCycle()+7)%8] = (cast_float2fixed<32,0,UNSIGNED,TONEAREVEN>(id69in_i));
  }
  { // Node ID: 3513 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3513in_input = id69out_o[getCycle()%8];

    id3513out_output[(getCycle()+1)%2] = id3513in_input;
  }
  { // Node ID: 3512 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3512in_input = id3513out_output[getCycle()%2];

    id3512out_output[(getCycle()+1)%2] = id3512in_input;
  }
  { // Node ID: 3511 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3511in_input = id3512out_output[getCycle()%2];

    id3511out_output[(getCycle()+1)%2] = id3511in_input;
  }
  { // Node ID: 3510 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3510in_input = id3511out_output[getCycle()%2];

    id3510out_output[(getCycle()+1)%2] = id3510in_input;
  }
  { // Node ID: 3509 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3509in_input = id3510out_output[getCycle()%2];

    id3509out_output[(getCycle()+1)%2] = id3509in_input;
  }
  { // Node ID: 3508 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3508in_input = id3509out_output[getCycle()%2];

    id3508out_output[(getCycle()+1)%2] = id3508in_input;
  }
  if ( (getFillLevel() >= (122l)) && (getFlushLevel() < (122l)|| !isFlushingActive() ))
  { // Node ID: 2569 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id2569in_output_control = id2567out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2569in_data = id3508out_output[getCycle()%2];

    bool id2569x_1;

    (id2569x_1) = ((id2569in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(122l))&(isFlushingActive()))));
    if((id2569x_1)) {
      writeOutput(m_internal_watch_lind_output, id2569in_data);
    }
  }
  { // Node ID: 4539 (NodeFIFO)
    const HWFloat<8,24> &id4539in_input = id3527out_output[getCycle()%34];

    id4539out_output[(getCycle()+52)%53] = id4539in_input;
  }
  if ( (getFillLevel() >= (122l)) && (getFlushLevel() < (122l)|| !isFlushingActive() ))
  { // Node ID: 2570 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id2570in_output_control = id2567out_value;
    const HWFloat<8,24> &id2570in_data = id4539out_output[getCycle()%53];

    bool id2570x_1;

    (id2570x_1) = ((id2570in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(122l))&(isFlushingActive()))));
    if((id2570x_1)) {
      writeOutput(m_internal_watch_longi_output, id2570in_data);
    }
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 21 (NodeWatch)
  }
  { // Node ID: 3499 (NodeConstantRawBits)
  }
  { // Node ID: 2 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (120l)))
  { // Node ID: 3 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_enable = id3499out_value;
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
  { // Node ID: 3498 (NodeConstantRawBits)
  }
  { // Node ID: 1938 (NodeAdd)
    const HWOffsetFix<64,0,UNSIGNED> &id1938in_a = id3out_count;
    const HWOffsetFix<64,0,UNSIGNED> &id1938in_b = id3498out_value;

    id1938out_result[(getCycle()+1)%2] = (add_fixed<64,0,UNSIGNED,TONEAREVEN>(id1938in_a,id1938in_b));
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  { // Node ID: 2576 (NodeEqInlined)
    const HWOffsetFix<64,0,UNSIGNED> &id2576in_a = id1938out_result[getCycle()%2];
    const HWOffsetFix<64,0,UNSIGNED> &id2576in_b = id0out_numHists;

    id2576out_result[(getCycle()+1)%2] = (eq_fixed(id2576in_a,id2576in_b));
  }
  { // Node ID: 1940 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1941out_result;

  { // Node ID: 1941 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1941in_a = id1940out_io_output_force_disabled;

    id1941out_result = (not_fixed(id1941in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1942out_result;

  { // Node ID: 1942 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1942in_a = id2576out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1942in_b = id1941out_result;

    HWOffsetFix<1,0,UNSIGNED> id1942x_1;

    (id1942x_1) = (and_fixed(id1942in_a,id1942in_b));
    id1942out_result = (id1942x_1);
  }
  { // Node ID: 2564 (NodeConstantRawBits)
  }
  { // Node ID: 2565 (NodeConstantRawBits)
  }
  { // Node ID: 121 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (112l)))
  { // Node ID: 122 (NodePulse)
    const HWOffsetFix<1,0,UNSIGNED> &id122in_enable = id121out_value;

    if(((id122st_count)==(1l))) {
      (id122st_value) = (c_hw_fix_1_0_uns_bits_1);
    }
    if((id122in_enable.getValueAsBool())) {
      (id122st_count) = ((id122st_count)+(1l));
    }
    id122out_output = (id122st_value);
  }
  { // Node ID: 3522 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3522in_input = id122out_output;

    id3522out_output[(getCycle()+1)%2] = id3522in_input;
  }
  { // Node ID: 3521 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3521in_input = id3522out_output[getCycle()%2];

    id3521out_output[(getCycle()+1)%2] = id3521in_input;
  }
  { // Node ID: 3520 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3520in_input = id3521out_output[getCycle()%2];

    id3520out_output[(getCycle()+1)%2] = id3520in_input;
  }
  { // Node ID: 3966 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3966in_input = id3520out_output[getCycle()%2];

    id3966out_output[(getCycle()+6)%7] = id3966in_input;
  }
  { // Node ID: 4542 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4542in_input = id3966out_output[getCycle()%7];

    id4542out_output[(getCycle()+1)%2] = id4542in_input;
  }
  { // Node ID: 3497 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2582out_result;

  { // Node ID: 2582 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2582in_a = id3497out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2582in_b = id3523out_output[getCycle()%2];

    id2582out_result = (eq_fixed(id2582in_a,id2582in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1331out_o;

  { // Node ID: 1331 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1331in_i = id2582out_result;

    id1331out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1331in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1333out_result;

  { // Node ID: 1333 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1333in_a = id3550out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1333in_b = id1331out_o;

    id1333out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1333in_a,id1333in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1334out_result;

  { // Node ID: 1334 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1334in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1334in_option0 = id1333out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1334in_option1 = id1331out_o;

    HWOffsetFix<32,0,UNSIGNED> id1334x_1;

    switch((id1334in_sel.getValueAsLong())) {
      case 0l:
        id1334x_1 = id1334in_option0;
        break;
      case 1l:
        id1334x_1 = id1334in_option1;
        break;
      default:
        id1334x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1334out_result = (id1334x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1332out_output;

  { // Node ID: 1332 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1332in_input = id1334out_result;

    id1332out_output = id1332in_input;
  }
  { // Node ID: 3550 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3550in_input = id1332out_output;

    id3550out_output[(getCycle()+1)%2] = id3550in_input;
  }
  HWRawBits<32> id7out_result;

  { // Node ID: 7 (NodeSlice)
    const HWRawBits<224> &id7in_a = id6out_data;

    id7out_result = (slice<0,32>(id7in_a));
  }
  HWFloat<8,24> id8out_output;

  { // Node ID: 8 (NodeReinterpret)
    const HWRawBits<32> &id8in_input = id7out_result;

    id8out_output = (cast_bits2float<8,24>(id8in_input));
  }
  { // Node ID: 70 (NodeMul)
    const HWFloat<8,24> &id70in_a = id8out_output;
    const HWFloat<8,24> &id70in_b = id8out_output;

    id70out_result[(getCycle()+8)%9] = (mul_float(id70in_a,id70in_b));
  }
  HWRawBits<32> id9out_result;

  { // Node ID: 9 (NodeSlice)
    const HWRawBits<224> &id9in_a = id6out_data;

    id9out_result = (slice<32,32>(id9in_a));
  }
  HWFloat<8,24> id10out_output;

  { // Node ID: 10 (NodeReinterpret)
    const HWRawBits<32> &id10in_input = id9out_result;

    id10out_output = (cast_bits2float<8,24>(id10in_input));
  }
  { // Node ID: 71 (NodeMul)
    const HWFloat<8,24> &id71in_a = id10out_output;
    const HWFloat<8,24> &id71in_b = id10out_output;

    id71out_result[(getCycle()+8)%9] = (mul_float(id71in_a,id71in_b));
  }
  { // Node ID: 72 (NodeAdd)
    const HWFloat<8,24> &id72in_a = id70out_result[getCycle()%9];
    const HWFloat<8,24> &id72in_b = id71out_result[getCycle()%9];

    id72out_result[(getCycle()+11)%12] = (add_float(id72in_a,id72in_b));
  }
  { // Node ID: 73 (NodeSqrt)
    const HWFloat<8,24> &id73in_a = id72out_result[getCycle()%12];

    id73out_result[(getCycle()+28)%29] = (sqrt_float(id73in_a));
  }
  { // Node ID: 75 (NodeDiv)
    const HWFloat<8,24> &id75in_a = id73out_result[getCycle()%29];
    const HWFloat<8,24> &id75in_b = id3539out_output[getCycle()%48];

    id75out_result[(getCycle()+28)%29] = (div_float(id75in_a,id75in_b));
  }
  { // Node ID: 3496 (NodeConstantRawBits)
  }
  { // Node ID: 77 (NodeMul)
    const HWFloat<8,24> &id77in_a = id75out_result[getCycle()%29];
    const HWFloat<8,24> &id77in_b = id3496out_value;

    id77out_result[(getCycle()+8)%9] = (mul_float(id77in_a,id77in_b));
  }
  HWFloat<8,24> id78out_result;

  { // Node ID: 78 (NodeNeg)
    const HWFloat<8,24> &id78in_a = id77out_result[getCycle()%9];

    id78out_result = (neg_float(id78in_a));
  }
  HWRawBits<8> id79out_result;

  { // Node ID: 79 (NodeSlice)
    const HWFloat<8,24> &id79in_a = id78out_result;

    id79out_result = (slice<23,8>(id79in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id80out_output;

  { // Node ID: 80 (NodeReinterpret)
    const HWRawBits<8> &id80in_input = id79out_result;

    id80out_output = (cast_bits2fixed<8,0,UNSIGNED>(id80in_input));
  }
  { // Node ID: 3495 (NodeConstantRawBits)
  }
  { // Node ID: 82 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id82in_a = id80out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id82in_b = id3495out_value;

    id82out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id82in_a,id82in_b));
  }
  HWRawBits<1> id2577out_result;

  { // Node ID: 2577 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2577in_a = id82out_result[getCycle()%2];

    id2577out_result = (slice<8,1>(id2577in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id2578out_output;

  { // Node ID: 2578 (NodeReinterpret)
    const HWRawBits<1> &id2578in_input = id2577out_result;

    id2578out_output = (cast_bits2fixed<1,0,UNSIGNED>(id2578in_input));
  }
  { // Node ID: 3540 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3540in_input = id2578out_output;

    id3540out_output[(getCycle()+1)%2] = id3540in_input;
  }
  { // Node ID: 3494 (NodeConstantRawBits)
  }
  { // Node ID: 2579 (NodeEqInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2579in_a = id82out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2579in_b = id3494out_value;

    id2579out_result[(getCycle()+1)%2] = (eq_fixed(id2579in_a,id2579in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id102out_result;

  { // Node ID: 102 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id102in_a = id2579out_result[getCycle()%2];

    id102out_result = (not_fixed(id102in_a));
  }
  { // Node ID: 103 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_a = id3540out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id103in_b = id102out_result;

    HWOffsetFix<1,0,UNSIGNED> id103x_1;

    (id103x_1) = (and_fixed(id103in_a,id103in_b));
    id103out_result[(getCycle()+1)%2] = (id103x_1);
  }
  { // Node ID: 3547 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3547in_input = id103out_result[getCycle()%2];

    id3547out_output[(getCycle()+8)%9] = id3547in_input;
  }
  { // Node ID: 3545 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3545in_input = id2579out_result[getCycle()%2];

    id3545out_output[(getCycle()+9)%10] = id3545in_input;
  }
  { // Node ID: 3542 (NodeFIFO)
    const HWFloat<8,24> &id3542in_input = id78out_result;

    id3542out_output[(getCycle()+7)%8] = id3542in_input;
  }
  { // Node ID: 4543 (NodeFIFO)
    const HWFloat<8,24> &id4543in_input = id3542out_output[getCycle()%8];

    id4543out_output[(getCycle()+1)%2] = id4543in_input;
  }
  { // Node ID: 3493 (NodeConstantRawBits)
  }
  { // Node ID: 97 (NodeGt)
    const HWFloat<8,24> &id97in_a = id4543out_output[getCycle()%2];
    const HWFloat<8,24> &id97in_b = id3493out_value;

    id97out_result[(getCycle()+2)%3] = (gt_float(id97in_a,id97in_b));
  }
  HWRawBits<32> id2580out_output;

  { // Node ID: 2580 (NodeReinterpret)
    const HWFloat<8,24> &id2580in_input = id3542out_output[getCycle()%8];

    id2580out_output = (cast_float2bits(id2580in_input));
  }
  { // Node ID: 3492 (NodeConstantRawBits)
  }
  { // Node ID: 85 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id85in_a = id3492out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id85in_b = id82out_result[getCycle()%2];

    id85out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id85in_a,id85in_b));
  }
  { // Node ID: 3491 (NodeConstantRawBits)
  }
  { // Node ID: 2581 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2581in_a = id85out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2581in_b = id3491out_value;

    id2581out_result[(getCycle()+1)%2] = (gt_fixed(id2581in_a,id2581in_b));
  }
  { // Node ID: 3543 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3543in_input = id2581out_result[getCycle()%2];

    id3543out_output[(getCycle()+3)%4] = id3543in_input;
  }
  { // Node ID: 86 (NodeConstantRawBits)
  }
  HWOffsetFix<5,0,UNSIGNED> id89out_o;

  { // Node ID: 89 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id89in_i = id85out_result[getCycle()%2];

    id89out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id89in_i));
  }
  { // Node ID: 90 (NodeShift)
    const HWOffsetFix<32,0,UNSIGNED> &id90in_datain = id86out_value;
    const HWOffsetFix<5,0,UNSIGNED> &id90in_shift = id89out_o;

    id90out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id90in_datain,(id90in_shift.getValueAsLong())));
  }
  HWOffsetFix<32,0,UNSIGNED> id91out_output;

  { // Node ID: 91 (NodeReinterpret)
    const HWRawBits<32> &id91in_input = id90out_dataout[getCycle()%5];

    id91out_output = (cast_bits2fixed<32,0,UNSIGNED>(id91in_input));
  }
  { // Node ID: 92 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_sel = id3543out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id92in_option0 = id86out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id92in_option1 = id91out_output;

    HWOffsetFix<32,0,UNSIGNED> id92x_1;

    switch((id92in_sel.getValueAsLong())) {
      case 0l:
        id92x_1 = id92in_option0;
        break;
      case 1l:
        id92x_1 = id92in_option1;
        break;
      default:
        id92x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id92out_result[(getCycle()+1)%2] = (id92x_1);
  }
  HWRawBits<32> id93out_output;

  { // Node ID: 93 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id93in_input = id92out_result[getCycle()%2];

    id93out_output = (cast_fixed2bits(id93in_input));
  }
  { // Node ID: 94 (NodeAnd)
    const HWRawBits<32> &id94in_a = id2580out_output;
    const HWRawBits<32> &id94in_b = id93out_output;

    HWRawBits<32> id94x_1;

    (id94x_1) = (and_bits(id94in_a,id94in_b));
    id94out_result[(getCycle()+1)%2] = (id94x_1);
  }
  HWFloat<8,24> id95out_output;

  { // Node ID: 95 (NodeReinterpret)
    const HWRawBits<32> &id95in_input = id94out_result[getCycle()%2];

    id95out_output = (cast_bits2float<8,24>(id95in_input));
  }
  { // Node ID: 104 (NodeNeq)
    const HWFloat<8,24> &id104in_a = id95out_output;
    const HWFloat<8,24> &id104in_b = id4543out_output[getCycle()%2];

    id104out_result[(getCycle()+2)%3] = (neq_float(id104in_a,id104in_b));
  }
  { // Node ID: 105 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id105in_a = id97out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id105in_b = id104out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id105x_1;

    (id105x_1) = (and_fixed(id105in_a,id105in_b));
    id105out_result[(getCycle()+1)%2] = (id105x_1);
  }
  { // Node ID: 108 (NodeConstantRawBits)
  }
  { // Node ID: 107 (NodeConstantRawBits)
  }
  HWOffsetFix<2,0,UNSIGNED> id109out_result;

  { // Node ID: 109 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id109in_sel = id105out_result[getCycle()%2];
    const HWOffsetFix<2,0,UNSIGNED> &id109in_option0 = id108out_value;
    const HWOffsetFix<2,0,UNSIGNED> &id109in_option1 = id107out_value;

    HWOffsetFix<2,0,UNSIGNED> id109x_1;

    switch((id109in_sel.getValueAsLong())) {
      case 0l:
        id109x_1 = id109in_option0;
        break;
      case 1l:
        id109x_1 = id109in_option1;
        break;
      default:
        id109x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id109out_result = (id109x_1);
  }
  { // Node ID: 110 (NodeConstantRawBits)
  }
  HWOffsetFix<2,0,UNSIGNED> id111out_result;

  { // Node ID: 111 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_sel = id3545out_output[getCycle()%10];
    const HWOffsetFix<2,0,UNSIGNED> &id111in_option0 = id109out_result;
    const HWOffsetFix<2,0,UNSIGNED> &id111in_option1 = id110out_value;

    HWOffsetFix<2,0,UNSIGNED> id111x_1;

    switch((id111in_sel.getValueAsLong())) {
      case 0l:
        id111x_1 = id111in_option0;
        break;
      case 1l:
        id111x_1 = id111in_option1;
        break;
      default:
        id111x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id111out_result = (id111x_1);
  }
  { // Node ID: 3546 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3546in_input = id97out_result[getCycle()%3];

    id3546out_output[(getCycle()+1)%2] = id3546in_input;
  }
  HWOffsetFix<2,0,UNSIGNED> id106out_o;

  { // Node ID: 106 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id106in_i = id3546out_output[getCycle()%2];

    id106out_o = (cast_fixed2fixed<2,0,UNSIGNED,TONEAREVEN>(id106in_i));
  }
  HWOffsetFix<2,0,UNSIGNED> id112out_result;

  { // Node ID: 112 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_sel = id3547out_output[getCycle()%9];
    const HWOffsetFix<2,0,UNSIGNED> &id112in_option0 = id111out_result;
    const HWOffsetFix<2,0,UNSIGNED> &id112in_option1 = id106out_o;

    HWOffsetFix<2,0,UNSIGNED> id112x_1;

    switch((id112in_sel.getValueAsLong())) {
      case 0l:
        id112x_1 = id112in_option0;
        break;
      case 1l:
        id112x_1 = id112in_option1;
        break;
      default:
        id112x_1 = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id112out_result = (id112x_1);
  }
  { // Node ID: 3548 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id3548in_input = id112out_result;

    id3548out_output[(getCycle()+8)%9] = id3548in_input;
  }
  { // Node ID: 2566 (NodeConstantRawBits)
  }
  { // Node ID: 113 (NodeConstantRawBits)
  }
  { // Node ID: 3549 (NodeFIFO)
    const HWFloat<8,24> &id3549in_input = id95out_output;

    id3549out_output[(getCycle()+11)%12] = id3549in_input;
  }
  { // Node ID: 3490 (NodeConstantRawBits)
  }
  { // Node ID: 117 (NodeAdd)
    const HWFloat<8,24> &id117in_a = id95out_output;
    const HWFloat<8,24> &id117in_b = id3490out_value;

    id117out_result[(getCycle()+11)%12] = (add_float(id117in_a,id117in_b));
  }
  { // Node ID: 118 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id118in_sel = id3548out_output[getCycle()%9];
    const HWFloat<8,24> &id118in_option0 = id2566out_value;
    const HWFloat<8,24> &id118in_option1 = id113out_value;
    const HWFloat<8,24> &id118in_option2 = id3549out_output[getCycle()%12];
    const HWFloat<8,24> &id118in_option3 = id117out_result[getCycle()%12];

    HWFloat<8,24> id118x_1;

    switch((id118in_sel.getValueAsLong())) {
      case 0l:
        id118x_1 = id118in_option0;
        break;
      case 1l:
        id118x_1 = id118in_option1;
        break;
      case 2l:
        id118x_1 = id118in_option2;
        break;
      case 3l:
        id118x_1 = id118in_option3;
        break;
      default:
        id118x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id118out_result[(getCycle()+1)%2] = (id118x_1);
  }
  HWFloat<8,24> id119out_result;

  { // Node ID: 119 (NodeNeg)
    const HWFloat<8,24> &id119in_a = id118out_result[getCycle()%2];

    id119out_result = (neg_float(id119in_a));
  }
  { // Node ID: 120 (NodeCast)
    const HWFloat<8,24> &id120in_i = id119out_result;

    id120out_o[(getCycle()+7)%8] = (cast_float2fixed<32,0,UNSIGNED,TONEAREVEN>(id120in_i));
  }
  { // Node ID: 3525 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3525in_input = id120out_o[getCycle()%8];

    id3525out_output[(getCycle()+1)%2] = id3525in_input;
  }
  { // Node ID: 3524 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3524in_input = id3525out_output[getCycle()%2];

    id3524out_output[(getCycle()+1)%2] = id3524in_input;
  }
  { // Node ID: 3523 (NodeRegister)
    const HWOffsetFix<32,0,UNSIGNED> &id3523in_input = id3524out_output[getCycle()%2];

    id3523out_output[(getCycle()+1)%2] = id3523in_input;
  }
  { // Node ID: 3489 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2583out_result;

  { // Node ID: 2583 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2583in_a = id3489out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2583in_b = id3523out_output[getCycle()%2];

    id2583out_result = (eq_fixed(id2583in_a,id2583in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1319out_o;

  { // Node ID: 1319 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1319in_i = id2583out_result;

    id1319out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1319in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1321out_result;

  { // Node ID: 1321 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1321in_a = id3552out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1321in_b = id1319out_o;

    id1321out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1321in_a,id1321in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1322out_result;

  { // Node ID: 1322 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1322in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1322in_option0 = id1321out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1322in_option1 = id1319out_o;

    HWOffsetFix<32,0,UNSIGNED> id1322x_1;

    switch((id1322in_sel.getValueAsLong())) {
      case 0l:
        id1322x_1 = id1322in_option0;
        break;
      case 1l:
        id1322x_1 = id1322in_option1;
        break;
      default:
        id1322x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1322out_result = (id1322x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1320out_output;

  { // Node ID: 1320 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1320in_input = id1322out_result;

    id1320out_output = id1320in_input;
  }
  { // Node ID: 3552 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3552in_input = id1320out_output;

    id3552out_output[(getCycle()+1)%2] = id3552in_input;
  }
  { // Node ID: 3488 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2584out_result;

  { // Node ID: 2584 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2584in_a = id3488out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2584in_b = id3523out_output[getCycle()%2];

    id2584out_result = (eq_fixed(id2584in_a,id2584in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1307out_o;

  { // Node ID: 1307 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1307in_i = id2584out_result;

    id1307out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1307in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1309out_result;

  { // Node ID: 1309 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1309in_a = id3554out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1309in_b = id1307out_o;

    id1309out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1309in_a,id1309in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1310out_result;

  { // Node ID: 1310 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1310in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1310in_option0 = id1309out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1310in_option1 = id1307out_o;

    HWOffsetFix<32,0,UNSIGNED> id1310x_1;

    switch((id1310in_sel.getValueAsLong())) {
      case 0l:
        id1310x_1 = id1310in_option0;
        break;
      case 1l:
        id1310x_1 = id1310in_option1;
        break;
      default:
        id1310x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1310out_result = (id1310x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1308out_output;

  { // Node ID: 1308 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1308in_input = id1310out_result;

    id1308out_output = id1308in_input;
  }
  { // Node ID: 3554 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3554in_input = id1308out_output;

    id3554out_output[(getCycle()+1)%2] = id3554in_input;
  }
  { // Node ID: 3487 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2585out_result;

  { // Node ID: 2585 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2585in_a = id3487out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2585in_b = id3523out_output[getCycle()%2];

    id2585out_result = (eq_fixed(id2585in_a,id2585in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1295out_o;

  { // Node ID: 1295 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1295in_i = id2585out_result;

    id1295out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1295in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1297out_result;

  { // Node ID: 1297 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1297in_a = id3556out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1297in_b = id1295out_o;

    id1297out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1297in_a,id1297in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1298out_result;

  { // Node ID: 1298 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1298in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1298in_option0 = id1297out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1298in_option1 = id1295out_o;

    HWOffsetFix<32,0,UNSIGNED> id1298x_1;

    switch((id1298in_sel.getValueAsLong())) {
      case 0l:
        id1298x_1 = id1298in_option0;
        break;
      case 1l:
        id1298x_1 = id1298in_option1;
        break;
      default:
        id1298x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1298out_result = (id1298x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1296out_output;

  { // Node ID: 1296 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1296in_input = id1298out_result;

    id1296out_output = id1296in_input;
  }
  { // Node ID: 3556 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3556in_input = id1296out_output;

    id3556out_output[(getCycle()+1)%2] = id3556in_input;
  }
  { // Node ID: 3486 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2586out_result;

  { // Node ID: 2586 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2586in_a = id3486out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2586in_b = id3523out_output[getCycle()%2];

    id2586out_result = (eq_fixed(id2586in_a,id2586in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1283out_o;

  { // Node ID: 1283 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1283in_i = id2586out_result;

    id1283out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1283in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1285out_result;

  { // Node ID: 1285 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1285in_a = id3558out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1285in_b = id1283out_o;

    id1285out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1285in_a,id1285in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1286out_result;

  { // Node ID: 1286 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1286in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1286in_option0 = id1285out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1286in_option1 = id1283out_o;

    HWOffsetFix<32,0,UNSIGNED> id1286x_1;

    switch((id1286in_sel.getValueAsLong())) {
      case 0l:
        id1286x_1 = id1286in_option0;
        break;
      case 1l:
        id1286x_1 = id1286in_option1;
        break;
      default:
        id1286x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1286out_result = (id1286x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1284out_output;

  { // Node ID: 1284 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1284in_input = id1286out_result;

    id1284out_output = id1284in_input;
  }
  { // Node ID: 3558 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3558in_input = id1284out_output;

    id3558out_output[(getCycle()+1)%2] = id3558in_input;
  }
  { // Node ID: 3485 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2587out_result;

  { // Node ID: 2587 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2587in_a = id3485out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2587in_b = id3523out_output[getCycle()%2];

    id2587out_result = (eq_fixed(id2587in_a,id2587in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1271out_o;

  { // Node ID: 1271 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1271in_i = id2587out_result;

    id1271out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1271in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1273out_result;

  { // Node ID: 1273 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1273in_a = id3560out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1273in_b = id1271out_o;

    id1273out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1273in_a,id1273in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1274out_result;

  { // Node ID: 1274 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1274in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1274in_option0 = id1273out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1274in_option1 = id1271out_o;

    HWOffsetFix<32,0,UNSIGNED> id1274x_1;

    switch((id1274in_sel.getValueAsLong())) {
      case 0l:
        id1274x_1 = id1274in_option0;
        break;
      case 1l:
        id1274x_1 = id1274in_option1;
        break;
      default:
        id1274x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1274out_result = (id1274x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1272out_output;

  { // Node ID: 1272 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1272in_input = id1274out_result;

    id1272out_output = id1272in_input;
  }
  { // Node ID: 3560 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3560in_input = id1272out_output;

    id3560out_output[(getCycle()+1)%2] = id3560in_input;
  }
  { // Node ID: 3484 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2588out_result;

  { // Node ID: 2588 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2588in_a = id3484out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2588in_b = id3523out_output[getCycle()%2];

    id2588out_result = (eq_fixed(id2588in_a,id2588in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1259out_o;

  { // Node ID: 1259 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1259in_i = id2588out_result;

    id1259out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1259in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1261out_result;

  { // Node ID: 1261 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1261in_a = id3562out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1261in_b = id1259out_o;

    id1261out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1261in_a,id1261in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1262out_result;

  { // Node ID: 1262 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1262in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1262in_option0 = id1261out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1262in_option1 = id1259out_o;

    HWOffsetFix<32,0,UNSIGNED> id1262x_1;

    switch((id1262in_sel.getValueAsLong())) {
      case 0l:
        id1262x_1 = id1262in_option0;
        break;
      case 1l:
        id1262x_1 = id1262in_option1;
        break;
      default:
        id1262x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1262out_result = (id1262x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1260out_output;

  { // Node ID: 1260 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1260in_input = id1262out_result;

    id1260out_output = id1260in_input;
  }
  { // Node ID: 3562 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3562in_input = id1260out_output;

    id3562out_output[(getCycle()+1)%2] = id3562in_input;
  }
  { // Node ID: 3483 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2589out_result;

  { // Node ID: 2589 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2589in_a = id3483out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2589in_b = id3523out_output[getCycle()%2];

    id2589out_result = (eq_fixed(id2589in_a,id2589in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1247out_o;

  { // Node ID: 1247 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1247in_i = id2589out_result;

    id1247out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1247in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1249out_result;

  { // Node ID: 1249 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1249in_a = id3564out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1249in_b = id1247out_o;

    id1249out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1249in_a,id1249in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1250out_result;

  { // Node ID: 1250 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1250in_sel = id4542out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1250in_option0 = id1249out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1250in_option1 = id1247out_o;

    HWOffsetFix<32,0,UNSIGNED> id1250x_1;

    switch((id1250in_sel.getValueAsLong())) {
      case 0l:
        id1250x_1 = id1250in_option0;
        break;
      case 1l:
        id1250x_1 = id1250in_option1;
        break;
      default:
        id1250x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1250out_result = (id1250x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1248out_output;

  { // Node ID: 1248 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1248in_input = id1250out_result;

    id1248out_output = id1248in_input;
  }
  { // Node ID: 3564 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3564in_input = id1248out_output;

    id3564out_output[(getCycle()+1)%2] = id3564in_input;
  }
  { // Node ID: 3519 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3519in_input = id3520out_output[getCycle()%2];

    id3519out_output[(getCycle()+1)%2] = id3519in_input;
  }
  { // Node ID: 4035 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4035in_input = id3519out_output[getCycle()%2];

    id4035out_output[(getCycle()+5)%6] = id4035in_input;
  }
  { // Node ID: 4544 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4544in_input = id4035out_output[getCycle()%6];

    id4544out_output[(getCycle()+1)%2] = id4544in_input;
  }
  { // Node ID: 3482 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2590out_result;

  { // Node ID: 2590 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2590in_a = id3482out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2590in_b = id3523out_output[getCycle()%2];

    id2590out_result = (eq_fixed(id2590in_a,id2590in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1235out_o;

  { // Node ID: 1235 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1235in_i = id2590out_result;

    id1235out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1235in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1237out_result;

  { // Node ID: 1237 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1237in_a = id3566out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1237in_b = id1235out_o;

    id1237out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1237in_a,id1237in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1238out_result;

  { // Node ID: 1238 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1238in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1238in_option0 = id1237out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1238in_option1 = id1235out_o;

    HWOffsetFix<32,0,UNSIGNED> id1238x_1;

    switch((id1238in_sel.getValueAsLong())) {
      case 0l:
        id1238x_1 = id1238in_option0;
        break;
      case 1l:
        id1238x_1 = id1238in_option1;
        break;
      default:
        id1238x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1238out_result = (id1238x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1236out_output;

  { // Node ID: 1236 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1236in_input = id1238out_result;

    id1236out_output = id1236in_input;
  }
  { // Node ID: 3566 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3566in_input = id1236out_output;

    id3566out_output[(getCycle()+1)%2] = id3566in_input;
  }
  { // Node ID: 3481 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2591out_result;

  { // Node ID: 2591 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2591in_a = id3481out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2591in_b = id3523out_output[getCycle()%2];

    id2591out_result = (eq_fixed(id2591in_a,id2591in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1223out_o;

  { // Node ID: 1223 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1223in_i = id2591out_result;

    id1223out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1223in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1225out_result;

  { // Node ID: 1225 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1225in_a = id3568out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1225in_b = id1223out_o;

    id1225out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1225in_a,id1225in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1226out_result;

  { // Node ID: 1226 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1226in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1226in_option0 = id1225out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1226in_option1 = id1223out_o;

    HWOffsetFix<32,0,UNSIGNED> id1226x_1;

    switch((id1226in_sel.getValueAsLong())) {
      case 0l:
        id1226x_1 = id1226in_option0;
        break;
      case 1l:
        id1226x_1 = id1226in_option1;
        break;
      default:
        id1226x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1226out_result = (id1226x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1224out_output;

  { // Node ID: 1224 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1224in_input = id1226out_result;

    id1224out_output = id1224in_input;
  }
  { // Node ID: 3568 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3568in_input = id1224out_output;

    id3568out_output[(getCycle()+1)%2] = id3568in_input;
  }
  { // Node ID: 3480 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2592out_result;

  { // Node ID: 2592 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2592in_a = id3480out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2592in_b = id3523out_output[getCycle()%2];

    id2592out_result = (eq_fixed(id2592in_a,id2592in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1211out_o;

  { // Node ID: 1211 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1211in_i = id2592out_result;

    id1211out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1211in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1213out_result;

  { // Node ID: 1213 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1213in_a = id3570out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1213in_b = id1211out_o;

    id1213out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1213in_a,id1213in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1214out_result;

  { // Node ID: 1214 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1214in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1214in_option0 = id1213out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1214in_option1 = id1211out_o;

    HWOffsetFix<32,0,UNSIGNED> id1214x_1;

    switch((id1214in_sel.getValueAsLong())) {
      case 0l:
        id1214x_1 = id1214in_option0;
        break;
      case 1l:
        id1214x_1 = id1214in_option1;
        break;
      default:
        id1214x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1214out_result = (id1214x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1212out_output;

  { // Node ID: 1212 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1212in_input = id1214out_result;

    id1212out_output = id1212in_input;
  }
  { // Node ID: 3570 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3570in_input = id1212out_output;

    id3570out_output[(getCycle()+1)%2] = id3570in_input;
  }
  { // Node ID: 3479 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2593out_result;

  { // Node ID: 2593 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2593in_a = id3479out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2593in_b = id3523out_output[getCycle()%2];

    id2593out_result = (eq_fixed(id2593in_a,id2593in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1199out_o;

  { // Node ID: 1199 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1199in_i = id2593out_result;

    id1199out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1199in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1201out_result;

  { // Node ID: 1201 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1201in_a = id3572out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1201in_b = id1199out_o;

    id1201out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1201in_a,id1201in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1202out_result;

  { // Node ID: 1202 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1202in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1202in_option0 = id1201out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1202in_option1 = id1199out_o;

    HWOffsetFix<32,0,UNSIGNED> id1202x_1;

    switch((id1202in_sel.getValueAsLong())) {
      case 0l:
        id1202x_1 = id1202in_option0;
        break;
      case 1l:
        id1202x_1 = id1202in_option1;
        break;
      default:
        id1202x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1202out_result = (id1202x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1200out_output;

  { // Node ID: 1200 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1200in_input = id1202out_result;

    id1200out_output = id1200in_input;
  }
  { // Node ID: 3572 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3572in_input = id1200out_output;

    id3572out_output[(getCycle()+1)%2] = id3572in_input;
  }
  { // Node ID: 3478 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2594out_result;

  { // Node ID: 2594 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2594in_a = id3478out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2594in_b = id3523out_output[getCycle()%2];

    id2594out_result = (eq_fixed(id2594in_a,id2594in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1187out_o;

  { // Node ID: 1187 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1187in_i = id2594out_result;

    id1187out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1187in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1189out_result;

  { // Node ID: 1189 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1189in_a = id3574out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1189in_b = id1187out_o;

    id1189out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1189in_a,id1189in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1190out_result;

  { // Node ID: 1190 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1190in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1190in_option0 = id1189out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1190in_option1 = id1187out_o;

    HWOffsetFix<32,0,UNSIGNED> id1190x_1;

    switch((id1190in_sel.getValueAsLong())) {
      case 0l:
        id1190x_1 = id1190in_option0;
        break;
      case 1l:
        id1190x_1 = id1190in_option1;
        break;
      default:
        id1190x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1190out_result = (id1190x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1188out_output;

  { // Node ID: 1188 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1188in_input = id1190out_result;

    id1188out_output = id1188in_input;
  }
  { // Node ID: 3574 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3574in_input = id1188out_output;

    id3574out_output[(getCycle()+1)%2] = id3574in_input;
  }
  { // Node ID: 3477 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2595out_result;

  { // Node ID: 2595 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2595in_a = id3477out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2595in_b = id3523out_output[getCycle()%2];

    id2595out_result = (eq_fixed(id2595in_a,id2595in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1175out_o;

  { // Node ID: 1175 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1175in_i = id2595out_result;

    id1175out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1175in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1177out_result;

  { // Node ID: 1177 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1177in_a = id3576out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1177in_b = id1175out_o;

    id1177out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1177in_a,id1177in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1178out_result;

  { // Node ID: 1178 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1178in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1178in_option0 = id1177out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1178in_option1 = id1175out_o;

    HWOffsetFix<32,0,UNSIGNED> id1178x_1;

    switch((id1178in_sel.getValueAsLong())) {
      case 0l:
        id1178x_1 = id1178in_option0;
        break;
      case 1l:
        id1178x_1 = id1178in_option1;
        break;
      default:
        id1178x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1178out_result = (id1178x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1176out_output;

  { // Node ID: 1176 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1176in_input = id1178out_result;

    id1176out_output = id1176in_input;
  }
  { // Node ID: 3576 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3576in_input = id1176out_output;

    id3576out_output[(getCycle()+1)%2] = id3576in_input;
  }
  { // Node ID: 3476 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2596out_result;

  { // Node ID: 2596 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2596in_a = id3476out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2596in_b = id3523out_output[getCycle()%2];

    id2596out_result = (eq_fixed(id2596in_a,id2596in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1163out_o;

  { // Node ID: 1163 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1163in_i = id2596out_result;

    id1163out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1163in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1165out_result;

  { // Node ID: 1165 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1165in_a = id3578out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1165in_b = id1163out_o;

    id1165out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1165in_a,id1165in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1166out_result;

  { // Node ID: 1166 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1166in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1166in_option0 = id1165out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1166in_option1 = id1163out_o;

    HWOffsetFix<32,0,UNSIGNED> id1166x_1;

    switch((id1166in_sel.getValueAsLong())) {
      case 0l:
        id1166x_1 = id1166in_option0;
        break;
      case 1l:
        id1166x_1 = id1166in_option1;
        break;
      default:
        id1166x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1166out_result = (id1166x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1164out_output;

  { // Node ID: 1164 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1164in_input = id1166out_result;

    id1164out_output = id1164in_input;
  }
  { // Node ID: 3578 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3578in_input = id1164out_output;

    id3578out_output[(getCycle()+1)%2] = id3578in_input;
  }
  { // Node ID: 3475 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2597out_result;

  { // Node ID: 2597 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2597in_a = id3475out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2597in_b = id3523out_output[getCycle()%2];

    id2597out_result = (eq_fixed(id2597in_a,id2597in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1151out_o;

  { // Node ID: 1151 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1151in_i = id2597out_result;

    id1151out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1151in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1153out_result;

  { // Node ID: 1153 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1153in_a = id3580out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1153in_b = id1151out_o;

    id1153out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1153in_a,id1153in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1154out_result;

  { // Node ID: 1154 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1154in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1154in_option0 = id1153out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1154in_option1 = id1151out_o;

    HWOffsetFix<32,0,UNSIGNED> id1154x_1;

    switch((id1154in_sel.getValueAsLong())) {
      case 0l:
        id1154x_1 = id1154in_option0;
        break;
      case 1l:
        id1154x_1 = id1154in_option1;
        break;
      default:
        id1154x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1154out_result = (id1154x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1152out_output;

  { // Node ID: 1152 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1152in_input = id1154out_result;

    id1152out_output = id1152in_input;
  }
  { // Node ID: 3580 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3580in_input = id1152out_output;

    id3580out_output[(getCycle()+1)%2] = id3580in_input;
  }
  { // Node ID: 3474 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2598out_result;

  { // Node ID: 2598 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2598in_a = id3474out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2598in_b = id3523out_output[getCycle()%2];

    id2598out_result = (eq_fixed(id2598in_a,id2598in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1139out_o;

  { // Node ID: 1139 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1139in_i = id2598out_result;

    id1139out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1139in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1141out_result;

  { // Node ID: 1141 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1141in_a = id3582out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1141in_b = id1139out_o;

    id1141out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1141in_a,id1141in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1142out_result;

  { // Node ID: 1142 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1142in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1142in_option0 = id1141out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1142in_option1 = id1139out_o;

    HWOffsetFix<32,0,UNSIGNED> id1142x_1;

    switch((id1142in_sel.getValueAsLong())) {
      case 0l:
        id1142x_1 = id1142in_option0;
        break;
      case 1l:
        id1142x_1 = id1142in_option1;
        break;
      default:
        id1142x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1142out_result = (id1142x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1140out_output;

  { // Node ID: 1140 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1140in_input = id1142out_result;

    id1140out_output = id1140in_input;
  }
  { // Node ID: 3582 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3582in_input = id1140out_output;

    id3582out_output[(getCycle()+1)%2] = id3582in_input;
  }
  { // Node ID: 3473 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2599out_result;

  { // Node ID: 2599 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2599in_a = id3473out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2599in_b = id3523out_output[getCycle()%2];

    id2599out_result = (eq_fixed(id2599in_a,id2599in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1127out_o;

  { // Node ID: 1127 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1127in_i = id2599out_result;

    id1127out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1127in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1129out_result;

  { // Node ID: 1129 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1129in_a = id3584out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1129in_b = id1127out_o;

    id1129out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1129in_a,id1129in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1130out_result;

  { // Node ID: 1130 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1130in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1130in_option0 = id1129out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1130in_option1 = id1127out_o;

    HWOffsetFix<32,0,UNSIGNED> id1130x_1;

    switch((id1130in_sel.getValueAsLong())) {
      case 0l:
        id1130x_1 = id1130in_option0;
        break;
      case 1l:
        id1130x_1 = id1130in_option1;
        break;
      default:
        id1130x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1130out_result = (id1130x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1128out_output;

  { // Node ID: 1128 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1128in_input = id1130out_result;

    id1128out_output = id1128in_input;
  }
  { // Node ID: 3584 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3584in_input = id1128out_output;

    id3584out_output[(getCycle()+1)%2] = id3584in_input;
  }
  { // Node ID: 3472 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2600out_result;

  { // Node ID: 2600 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2600in_a = id3472out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2600in_b = id3523out_output[getCycle()%2];

    id2600out_result = (eq_fixed(id2600in_a,id2600in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1115out_o;

  { // Node ID: 1115 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1115in_i = id2600out_result;

    id1115out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1115in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1117out_result;

  { // Node ID: 1117 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1117in_a = id3586out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1117in_b = id1115out_o;

    id1117out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1117in_a,id1117in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1118out_result;

  { // Node ID: 1118 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1118in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1118in_option0 = id1117out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1118in_option1 = id1115out_o;

    HWOffsetFix<32,0,UNSIGNED> id1118x_1;

    switch((id1118in_sel.getValueAsLong())) {
      case 0l:
        id1118x_1 = id1118in_option0;
        break;
      case 1l:
        id1118x_1 = id1118in_option1;
        break;
      default:
        id1118x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1118out_result = (id1118x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1116out_output;

  { // Node ID: 1116 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1116in_input = id1118out_result;

    id1116out_output = id1116in_input;
  }
  { // Node ID: 3586 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3586in_input = id1116out_output;

    id3586out_output[(getCycle()+1)%2] = id3586in_input;
  }
  { // Node ID: 3471 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2601out_result;

  { // Node ID: 2601 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2601in_a = id3471out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2601in_b = id3523out_output[getCycle()%2];

    id2601out_result = (eq_fixed(id2601in_a,id2601in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1103out_o;

  { // Node ID: 1103 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1103in_i = id2601out_result;

    id1103out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1103in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1105out_result;

  { // Node ID: 1105 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1105in_a = id3588out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1105in_b = id1103out_o;

    id1105out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1105in_a,id1105in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1106out_result;

  { // Node ID: 1106 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1106in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1106in_option0 = id1105out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1106in_option1 = id1103out_o;

    HWOffsetFix<32,0,UNSIGNED> id1106x_1;

    switch((id1106in_sel.getValueAsLong())) {
      case 0l:
        id1106x_1 = id1106in_option0;
        break;
      case 1l:
        id1106x_1 = id1106in_option1;
        break;
      default:
        id1106x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1106out_result = (id1106x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1104out_output;

  { // Node ID: 1104 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1104in_input = id1106out_result;

    id1104out_output = id1104in_input;
  }
  { // Node ID: 3588 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3588in_input = id1104out_output;

    id3588out_output[(getCycle()+1)%2] = id3588in_input;
  }
  { // Node ID: 3470 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2602out_result;

  { // Node ID: 2602 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2602in_a = id3470out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2602in_b = id3523out_output[getCycle()%2];

    id2602out_result = (eq_fixed(id2602in_a,id2602in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1091out_o;

  { // Node ID: 1091 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1091in_i = id2602out_result;

    id1091out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1091in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1093out_result;

  { // Node ID: 1093 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1093in_a = id3590out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1093in_b = id1091out_o;

    id1093out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1093in_a,id1093in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1094out_result;

  { // Node ID: 1094 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1094in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1094in_option0 = id1093out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1094in_option1 = id1091out_o;

    HWOffsetFix<32,0,UNSIGNED> id1094x_1;

    switch((id1094in_sel.getValueAsLong())) {
      case 0l:
        id1094x_1 = id1094in_option0;
        break;
      case 1l:
        id1094x_1 = id1094in_option1;
        break;
      default:
        id1094x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1094out_result = (id1094x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1092out_output;

  { // Node ID: 1092 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1092in_input = id1094out_result;

    id1092out_output = id1092in_input;
  }
  { // Node ID: 3590 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3590in_input = id1092out_output;

    id3590out_output[(getCycle()+1)%2] = id3590in_input;
  }
  { // Node ID: 3469 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2603out_result;

  { // Node ID: 2603 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2603in_a = id3469out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2603in_b = id3523out_output[getCycle()%2];

    id2603out_result = (eq_fixed(id2603in_a,id2603in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1079out_o;

  { // Node ID: 1079 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1079in_i = id2603out_result;

    id1079out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1079in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1081out_result;

  { // Node ID: 1081 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1081in_a = id3592out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1081in_b = id1079out_o;

    id1081out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1081in_a,id1081in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1082out_result;

  { // Node ID: 1082 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1082in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1082in_option0 = id1081out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1082in_option1 = id1079out_o;

    HWOffsetFix<32,0,UNSIGNED> id1082x_1;

    switch((id1082in_sel.getValueAsLong())) {
      case 0l:
        id1082x_1 = id1082in_option0;
        break;
      case 1l:
        id1082x_1 = id1082in_option1;
        break;
      default:
        id1082x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1082out_result = (id1082x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1080out_output;

  { // Node ID: 1080 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1080in_input = id1082out_result;

    id1080out_output = id1080in_input;
  }
  { // Node ID: 3592 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3592in_input = id1080out_output;

    id3592out_output[(getCycle()+1)%2] = id3592in_input;
  }
  { // Node ID: 3468 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2604out_result;

  { // Node ID: 2604 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2604in_a = id3468out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2604in_b = id3523out_output[getCycle()%2];

    id2604out_result = (eq_fixed(id2604in_a,id2604in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1067out_o;

  { // Node ID: 1067 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1067in_i = id2604out_result;

    id1067out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1067in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1069out_result;

  { // Node ID: 1069 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1069in_a = id3594out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1069in_b = id1067out_o;

    id1069out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1069in_a,id1069in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1070out_result;

  { // Node ID: 1070 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1070in_sel = id4544out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1070in_option0 = id1069out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1070in_option1 = id1067out_o;

    HWOffsetFix<32,0,UNSIGNED> id1070x_1;

    switch((id1070in_sel.getValueAsLong())) {
      case 0l:
        id1070x_1 = id1070in_option0;
        break;
      case 1l:
        id1070x_1 = id1070in_option1;
        break;
      default:
        id1070x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1070out_result = (id1070x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1068out_output;

  { // Node ID: 1068 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1068in_input = id1070out_result;

    id1068out_output = id1068in_input;
  }
  { // Node ID: 3594 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3594in_input = id1068out_output;

    id3594out_output[(getCycle()+1)%2] = id3594in_input;
  }
  { // Node ID: 3518 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3518in_input = id3519out_output[getCycle()%2];

    id3518out_output[(getCycle()+1)%2] = id3518in_input;
  }
  { // Node ID: 3615 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3615in_input = id3518out_output[getCycle()%2];

    id3615out_output[(getCycle()+4)%5] = id3615in_input;
  }
  { // Node ID: 4545 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4545in_input = id3615out_output[getCycle()%5];

    id4545out_output[(getCycle()+1)%2] = id4545in_input;
  }
  { // Node ID: 3467 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2605out_result;

  { // Node ID: 2605 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2605in_a = id3467out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2605in_b = id3523out_output[getCycle()%2];

    id2605out_result = (eq_fixed(id2605in_a,id2605in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1055out_o;

  { // Node ID: 1055 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1055in_i = id2605out_result;

    id1055out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1055in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1057out_result;

  { // Node ID: 1057 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1057in_a = id3596out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1057in_b = id1055out_o;

    id1057out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1057in_a,id1057in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1058out_result;

  { // Node ID: 1058 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1058in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1058in_option0 = id1057out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1058in_option1 = id1055out_o;

    HWOffsetFix<32,0,UNSIGNED> id1058x_1;

    switch((id1058in_sel.getValueAsLong())) {
      case 0l:
        id1058x_1 = id1058in_option0;
        break;
      case 1l:
        id1058x_1 = id1058in_option1;
        break;
      default:
        id1058x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1058out_result = (id1058x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1056out_output;

  { // Node ID: 1056 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1056in_input = id1058out_result;

    id1056out_output = id1056in_input;
  }
  { // Node ID: 3596 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3596in_input = id1056out_output;

    id3596out_output[(getCycle()+1)%2] = id3596in_input;
  }
  { // Node ID: 3466 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2606out_result;

  { // Node ID: 2606 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2606in_a = id3466out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2606in_b = id3523out_output[getCycle()%2];

    id2606out_result = (eq_fixed(id2606in_a,id2606in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1043out_o;

  { // Node ID: 1043 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1043in_i = id2606out_result;

    id1043out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1043in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1045out_result;

  { // Node ID: 1045 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1045in_a = id3598out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1045in_b = id1043out_o;

    id1045out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1045in_a,id1045in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1046out_result;

  { // Node ID: 1046 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1046in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1046in_option0 = id1045out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1046in_option1 = id1043out_o;

    HWOffsetFix<32,0,UNSIGNED> id1046x_1;

    switch((id1046in_sel.getValueAsLong())) {
      case 0l:
        id1046x_1 = id1046in_option0;
        break;
      case 1l:
        id1046x_1 = id1046in_option1;
        break;
      default:
        id1046x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1046out_result = (id1046x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1044out_output;

  { // Node ID: 1044 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1044in_input = id1046out_result;

    id1044out_output = id1044in_input;
  }
  { // Node ID: 3598 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3598in_input = id1044out_output;

    id3598out_output[(getCycle()+1)%2] = id3598in_input;
  }
  { // Node ID: 3465 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2607out_result;

  { // Node ID: 2607 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2607in_a = id3465out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2607in_b = id3523out_output[getCycle()%2];

    id2607out_result = (eq_fixed(id2607in_a,id2607in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1031out_o;

  { // Node ID: 1031 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1031in_i = id2607out_result;

    id1031out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1031in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1033out_result;

  { // Node ID: 1033 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1033in_a = id3600out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1033in_b = id1031out_o;

    id1033out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1033in_a,id1033in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1034out_result;

  { // Node ID: 1034 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1034in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1034in_option0 = id1033out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1034in_option1 = id1031out_o;

    HWOffsetFix<32,0,UNSIGNED> id1034x_1;

    switch((id1034in_sel.getValueAsLong())) {
      case 0l:
        id1034x_1 = id1034in_option0;
        break;
      case 1l:
        id1034x_1 = id1034in_option1;
        break;
      default:
        id1034x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1034out_result = (id1034x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1032out_output;

  { // Node ID: 1032 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1032in_input = id1034out_result;

    id1032out_output = id1032in_input;
  }
  { // Node ID: 3600 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3600in_input = id1032out_output;

    id3600out_output[(getCycle()+1)%2] = id3600in_input;
  }
  { // Node ID: 3464 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2608out_result;

  { // Node ID: 2608 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2608in_a = id3464out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2608in_b = id3523out_output[getCycle()%2];

    id2608out_result = (eq_fixed(id2608in_a,id2608in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1019out_o;

  { // Node ID: 1019 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1019in_i = id2608out_result;

    id1019out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1019in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1021out_result;

  { // Node ID: 1021 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1021in_a = id3602out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1021in_b = id1019out_o;

    id1021out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1021in_a,id1021in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1022out_result;

  { // Node ID: 1022 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1022in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1022in_option0 = id1021out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1022in_option1 = id1019out_o;

    HWOffsetFix<32,0,UNSIGNED> id1022x_1;

    switch((id1022in_sel.getValueAsLong())) {
      case 0l:
        id1022x_1 = id1022in_option0;
        break;
      case 1l:
        id1022x_1 = id1022in_option1;
        break;
      default:
        id1022x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1022out_result = (id1022x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1020out_output;

  { // Node ID: 1020 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1020in_input = id1022out_result;

    id1020out_output = id1020in_input;
  }
  { // Node ID: 3602 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3602in_input = id1020out_output;

    id3602out_output[(getCycle()+1)%2] = id3602in_input;
  }
  { // Node ID: 3463 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2609out_result;

  { // Node ID: 2609 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2609in_a = id3463out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2609in_b = id3523out_output[getCycle()%2];

    id2609out_result = (eq_fixed(id2609in_a,id2609in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1007out_o;

  { // Node ID: 1007 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1007in_i = id2609out_result;

    id1007out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1007in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1009out_result;

  { // Node ID: 1009 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1009in_a = id3604out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1009in_b = id1007out_o;

    id1009out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1009in_a,id1009in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1010out_result;

  { // Node ID: 1010 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1010in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1010in_option0 = id1009out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1010in_option1 = id1007out_o;

    HWOffsetFix<32,0,UNSIGNED> id1010x_1;

    switch((id1010in_sel.getValueAsLong())) {
      case 0l:
        id1010x_1 = id1010in_option0;
        break;
      case 1l:
        id1010x_1 = id1010in_option1;
        break;
      default:
        id1010x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1010out_result = (id1010x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1008out_output;

  { // Node ID: 1008 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1008in_input = id1010out_result;

    id1008out_output = id1008in_input;
  }
  { // Node ID: 3604 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3604in_input = id1008out_output;

    id3604out_output[(getCycle()+1)%2] = id3604in_input;
  }
  { // Node ID: 3462 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2610out_result;

  { // Node ID: 2610 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2610in_a = id3462out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2610in_b = id3523out_output[getCycle()%2];

    id2610out_result = (eq_fixed(id2610in_a,id2610in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id995out_o;

  { // Node ID: 995 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id995in_i = id2610out_result;

    id995out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id995in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id997out_result;

  { // Node ID: 997 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id997in_a = id3606out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id997in_b = id995out_o;

    id997out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id997in_a,id997in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id998out_result;

  { // Node ID: 998 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id998in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id998in_option0 = id997out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id998in_option1 = id995out_o;

    HWOffsetFix<32,0,UNSIGNED> id998x_1;

    switch((id998in_sel.getValueAsLong())) {
      case 0l:
        id998x_1 = id998in_option0;
        break;
      case 1l:
        id998x_1 = id998in_option1;
        break;
      default:
        id998x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id998out_result = (id998x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id996out_output;

  { // Node ID: 996 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id996in_input = id998out_result;

    id996out_output = id996in_input;
  }
  { // Node ID: 3606 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3606in_input = id996out_output;

    id3606out_output[(getCycle()+1)%2] = id3606in_input;
  }
  { // Node ID: 3461 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2611out_result;

  { // Node ID: 2611 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2611in_a = id3461out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2611in_b = id3523out_output[getCycle()%2];

    id2611out_result = (eq_fixed(id2611in_a,id2611in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id983out_o;

  { // Node ID: 983 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id983in_i = id2611out_result;

    id983out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id983in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id985out_result;

  { // Node ID: 985 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id985in_a = id3608out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id985in_b = id983out_o;

    id985out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id985in_a,id985in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id986out_result;

  { // Node ID: 986 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id986in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id986in_option0 = id985out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id986in_option1 = id983out_o;

    HWOffsetFix<32,0,UNSIGNED> id986x_1;

    switch((id986in_sel.getValueAsLong())) {
      case 0l:
        id986x_1 = id986in_option0;
        break;
      case 1l:
        id986x_1 = id986in_option1;
        break;
      default:
        id986x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id986out_result = (id986x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id984out_output;

  { // Node ID: 984 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id984in_input = id986out_result;

    id984out_output = id984in_input;
  }
  { // Node ID: 3608 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3608in_input = id984out_output;

    id3608out_output[(getCycle()+1)%2] = id3608in_input;
  }
  { // Node ID: 3460 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2612out_result;

  { // Node ID: 2612 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2612in_a = id3460out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2612in_b = id3523out_output[getCycle()%2];

    id2612out_result = (eq_fixed(id2612in_a,id2612in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id971out_o;

  { // Node ID: 971 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id971in_i = id2612out_result;

    id971out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id971in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id973out_result;

  { // Node ID: 973 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id973in_a = id3610out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id973in_b = id971out_o;

    id973out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id973in_a,id973in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id974out_result;

  { // Node ID: 974 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id974in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id974in_option0 = id973out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id974in_option1 = id971out_o;

    HWOffsetFix<32,0,UNSIGNED> id974x_1;

    switch((id974in_sel.getValueAsLong())) {
      case 0l:
        id974x_1 = id974in_option0;
        break;
      case 1l:
        id974x_1 = id974in_option1;
        break;
      default:
        id974x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id974out_result = (id974x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id972out_output;

  { // Node ID: 972 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id972in_input = id974out_result;

    id972out_output = id972in_input;
  }
  { // Node ID: 3610 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3610in_input = id972out_output;

    id3610out_output[(getCycle()+1)%2] = id3610in_input;
  }
  { // Node ID: 3459 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2613out_result;

  { // Node ID: 2613 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2613in_a = id3459out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2613in_b = id3523out_output[getCycle()%2];

    id2613out_result = (eq_fixed(id2613in_a,id2613in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id959out_o;

  { // Node ID: 959 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id959in_i = id2613out_result;

    id959out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id959in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id961out_result;

  { // Node ID: 961 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id961in_a = id3612out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id961in_b = id959out_o;

    id961out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id961in_a,id961in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id962out_result;

  { // Node ID: 962 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id962in_sel = id4545out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id962in_option0 = id961out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id962in_option1 = id959out_o;

    HWOffsetFix<32,0,UNSIGNED> id962x_1;

    switch((id962in_sel.getValueAsLong())) {
      case 0l:
        id962x_1 = id962in_option0;
        break;
      case 1l:
        id962x_1 = id962in_option1;
        break;
      default:
        id962x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id962out_result = (id962x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id960out_output;

  { // Node ID: 960 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id960in_input = id962out_result;

    id960out_output = id960in_input;
  }
  { // Node ID: 3612 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3612in_input = id960out_output;

    id3612out_output[(getCycle()+1)%2] = id3612in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id948out_output;

  { // Node ID: 948 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id948in_input = id3614out_output[getCycle()%2];

    id948out_output = id948in_input;
  }
  { // Node ID: 3458 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2614out_result;

  { // Node ID: 2614 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2614in_a = id3458out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2614in_b = id3524out_output[getCycle()%2];

    id2614out_result = (eq_fixed(id2614in_a,id2614in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id947out_o;

  { // Node ID: 947 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id947in_i = id2614out_result;

    id947out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id947in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id949out_result;

  { // Node ID: 949 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id949in_a = id948out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id949in_b = id947out_o;

    id949out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id949in_a,id949in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id950out_result;

  { // Node ID: 950 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id950in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id950in_option0 = id949out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id950in_option1 = id947out_o;

    HWOffsetFix<32,0,UNSIGNED> id950x_1;

    switch((id950in_sel.getValueAsLong())) {
      case 0l:
        id950x_1 = id950in_option0;
        break;
      case 1l:
        id950x_1 = id950in_option1;
        break;
      default:
        id950x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id950out_result = (id950x_1);
  }
  { // Node ID: 3614 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3614in_input = id950out_result;

    id3614out_output[(getCycle()+1)%2] = id3614in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id936out_output;

  { // Node ID: 936 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id936in_input = id3616out_output[getCycle()%2];

    id936out_output = id936in_input;
  }
  { // Node ID: 3457 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2615out_result;

  { // Node ID: 2615 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2615in_a = id3457out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2615in_b = id3524out_output[getCycle()%2];

    id2615out_result = (eq_fixed(id2615in_a,id2615in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id935out_o;

  { // Node ID: 935 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id935in_i = id2615out_result;

    id935out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id935in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id937out_result;

  { // Node ID: 937 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id937in_a = id936out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id937in_b = id935out_o;

    id937out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id937in_a,id937in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id938out_result;

  { // Node ID: 938 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id938in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id938in_option0 = id937out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id938in_option1 = id935out_o;

    HWOffsetFix<32,0,UNSIGNED> id938x_1;

    switch((id938in_sel.getValueAsLong())) {
      case 0l:
        id938x_1 = id938in_option0;
        break;
      case 1l:
        id938x_1 = id938in_option1;
        break;
      default:
        id938x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id938out_result = (id938x_1);
  }
  { // Node ID: 3616 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3616in_input = id938out_result;

    id3616out_output[(getCycle()+1)%2] = id3616in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id924out_output;

  { // Node ID: 924 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id924in_input = id3618out_output[getCycle()%2];

    id924out_output = id924in_input;
  }
  { // Node ID: 3456 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2616out_result;

  { // Node ID: 2616 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2616in_a = id3456out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2616in_b = id3524out_output[getCycle()%2];

    id2616out_result = (eq_fixed(id2616in_a,id2616in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id923out_o;

  { // Node ID: 923 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id923in_i = id2616out_result;

    id923out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id923in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id925out_result;

  { // Node ID: 925 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id925in_a = id924out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id925in_b = id923out_o;

    id925out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id925in_a,id925in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id926out_result;

  { // Node ID: 926 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id926in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id926in_option0 = id925out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id926in_option1 = id923out_o;

    HWOffsetFix<32,0,UNSIGNED> id926x_1;

    switch((id926in_sel.getValueAsLong())) {
      case 0l:
        id926x_1 = id926in_option0;
        break;
      case 1l:
        id926x_1 = id926in_option1;
        break;
      default:
        id926x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id926out_result = (id926x_1);
  }
  { // Node ID: 3618 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3618in_input = id926out_result;

    id3618out_output[(getCycle()+1)%2] = id3618in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id912out_output;

  { // Node ID: 912 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id912in_input = id3620out_output[getCycle()%2];

    id912out_output = id912in_input;
  }
  { // Node ID: 3455 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2617out_result;

  { // Node ID: 2617 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2617in_a = id3455out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2617in_b = id3524out_output[getCycle()%2];

    id2617out_result = (eq_fixed(id2617in_a,id2617in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id911out_o;

  { // Node ID: 911 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id911in_i = id2617out_result;

    id911out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id911in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id913out_result;

  { // Node ID: 913 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id913in_a = id912out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id913in_b = id911out_o;

    id913out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id913in_a,id913in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id914out_result;

  { // Node ID: 914 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id914in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id914in_option0 = id913out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id914in_option1 = id911out_o;

    HWOffsetFix<32,0,UNSIGNED> id914x_1;

    switch((id914in_sel.getValueAsLong())) {
      case 0l:
        id914x_1 = id914in_option0;
        break;
      case 1l:
        id914x_1 = id914in_option1;
        break;
      default:
        id914x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id914out_result = (id914x_1);
  }
  { // Node ID: 3620 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3620in_input = id914out_result;

    id3620out_output[(getCycle()+1)%2] = id3620in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id900out_output;

  { // Node ID: 900 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id900in_input = id3622out_output[getCycle()%2];

    id900out_output = id900in_input;
  }
  { // Node ID: 3454 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2618out_result;

  { // Node ID: 2618 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2618in_a = id3454out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2618in_b = id3524out_output[getCycle()%2];

    id2618out_result = (eq_fixed(id2618in_a,id2618in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id899out_o;

  { // Node ID: 899 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id899in_i = id2618out_result;

    id899out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id899in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id901out_result;

  { // Node ID: 901 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id901in_a = id900out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id901in_b = id899out_o;

    id901out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id901in_a,id901in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id902out_result;

  { // Node ID: 902 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id902in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id902in_option0 = id901out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id902in_option1 = id899out_o;

    HWOffsetFix<32,0,UNSIGNED> id902x_1;

    switch((id902in_sel.getValueAsLong())) {
      case 0l:
        id902x_1 = id902in_option0;
        break;
      case 1l:
        id902x_1 = id902in_option1;
        break;
      default:
        id902x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id902out_result = (id902x_1);
  }
  { // Node ID: 3622 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3622in_input = id902out_result;

    id3622out_output[(getCycle()+1)%2] = id3622in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id888out_output;

  { // Node ID: 888 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id888in_input = id3624out_output[getCycle()%2];

    id888out_output = id888in_input;
  }
  { // Node ID: 3453 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2619out_result;

  { // Node ID: 2619 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2619in_a = id3453out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2619in_b = id3524out_output[getCycle()%2];

    id2619out_result = (eq_fixed(id2619in_a,id2619in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id887out_o;

  { // Node ID: 887 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id887in_i = id2619out_result;

    id887out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id887in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id889out_result;

  { // Node ID: 889 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id889in_a = id888out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id889in_b = id887out_o;

    id889out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id889in_a,id889in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id890out_result;

  { // Node ID: 890 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id890in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id890in_option0 = id889out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id890in_option1 = id887out_o;

    HWOffsetFix<32,0,UNSIGNED> id890x_1;

    switch((id890in_sel.getValueAsLong())) {
      case 0l:
        id890x_1 = id890in_option0;
        break;
      case 1l:
        id890x_1 = id890in_option1;
        break;
      default:
        id890x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id890out_result = (id890x_1);
  }
  { // Node ID: 3624 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3624in_input = id890out_result;

    id3624out_output[(getCycle()+1)%2] = id3624in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id876out_output;

  { // Node ID: 876 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id876in_input = id3626out_output[getCycle()%2];

    id876out_output = id876in_input;
  }
  { // Node ID: 3452 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2620out_result;

  { // Node ID: 2620 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2620in_a = id3452out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2620in_b = id3524out_output[getCycle()%2];

    id2620out_result = (eq_fixed(id2620in_a,id2620in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id875out_o;

  { // Node ID: 875 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id875in_i = id2620out_result;

    id875out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id875in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id877out_result;

  { // Node ID: 877 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id877in_a = id876out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id877in_b = id875out_o;

    id877out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id877in_a,id877in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id878out_result;

  { // Node ID: 878 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id878in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id878in_option0 = id877out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id878in_option1 = id875out_o;

    HWOffsetFix<32,0,UNSIGNED> id878x_1;

    switch((id878in_sel.getValueAsLong())) {
      case 0l:
        id878x_1 = id878in_option0;
        break;
      case 1l:
        id878x_1 = id878in_option1;
        break;
      default:
        id878x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id878out_result = (id878x_1);
  }
  { // Node ID: 3626 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3626in_input = id878out_result;

    id3626out_output[(getCycle()+1)%2] = id3626in_input;
  }
  { // Node ID: 3517 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3517in_input = id3518out_output[getCycle()%2];

    id3517out_output[(getCycle()+1)%2] = id3517in_input;
  }
  { // Node ID: 3629 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3629in_input = id3517out_output[getCycle()%2];

    id3629out_output[(getCycle()+3)%4] = id3629in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id864out_output;

  { // Node ID: 864 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id864in_input = id3628out_output[getCycle()%2];

    id864out_output = id864in_input;
  }
  { // Node ID: 3451 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2621out_result;

  { // Node ID: 2621 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2621in_a = id3451out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2621in_b = id3524out_output[getCycle()%2];

    id2621out_result = (eq_fixed(id2621in_a,id2621in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id863out_o;

  { // Node ID: 863 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id863in_i = id2621out_result;

    id863out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id863in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id865out_result;

  { // Node ID: 865 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id865in_a = id864out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id865in_b = id863out_o;

    id865out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id865in_a,id865in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id866out_result;

  { // Node ID: 866 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id866in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id866in_option0 = id865out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id866in_option1 = id863out_o;

    HWOffsetFix<32,0,UNSIGNED> id866x_1;

    switch((id866in_sel.getValueAsLong())) {
      case 0l:
        id866x_1 = id866in_option0;
        break;
      case 1l:
        id866x_1 = id866in_option1;
        break;
      default:
        id866x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id866out_result = (id866x_1);
  }
  { // Node ID: 3628 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3628in_input = id866out_result;

    id3628out_output[(getCycle()+1)%2] = id3628in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id852out_output;

  { // Node ID: 852 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id852in_input = id3630out_output[getCycle()%2];

    id852out_output = id852in_input;
  }
  { // Node ID: 3450 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2622out_result;

  { // Node ID: 2622 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2622in_a = id3450out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2622in_b = id3524out_output[getCycle()%2];

    id2622out_result = (eq_fixed(id2622in_a,id2622in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id851out_o;

  { // Node ID: 851 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id851in_i = id2622out_result;

    id851out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id851in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id853out_result;

  { // Node ID: 853 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id853in_a = id852out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id853in_b = id851out_o;

    id853out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id853in_a,id853in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id854out_result;

  { // Node ID: 854 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id854in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id854in_option0 = id853out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id854in_option1 = id851out_o;

    HWOffsetFix<32,0,UNSIGNED> id854x_1;

    switch((id854in_sel.getValueAsLong())) {
      case 0l:
        id854x_1 = id854in_option0;
        break;
      case 1l:
        id854x_1 = id854in_option1;
        break;
      default:
        id854x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id854out_result = (id854x_1);
  }
  { // Node ID: 3630 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3630in_input = id854out_result;

    id3630out_output[(getCycle()+1)%2] = id3630in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id840out_output;

  { // Node ID: 840 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id840in_input = id3632out_output[getCycle()%2];

    id840out_output = id840in_input;
  }
  { // Node ID: 3449 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2623out_result;

  { // Node ID: 2623 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2623in_a = id3449out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2623in_b = id3524out_output[getCycle()%2];

    id2623out_result = (eq_fixed(id2623in_a,id2623in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id839out_o;

  { // Node ID: 839 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id839in_i = id2623out_result;

    id839out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id839in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id841out_result;

  { // Node ID: 841 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id841in_a = id840out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id841in_b = id839out_o;

    id841out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id841in_a,id841in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id842out_result;

  { // Node ID: 842 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id842in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id842in_option0 = id841out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id842in_option1 = id839out_o;

    HWOffsetFix<32,0,UNSIGNED> id842x_1;

    switch((id842in_sel.getValueAsLong())) {
      case 0l:
        id842x_1 = id842in_option0;
        break;
      case 1l:
        id842x_1 = id842in_option1;
        break;
      default:
        id842x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id842out_result = (id842x_1);
  }
  { // Node ID: 3632 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3632in_input = id842out_result;

    id3632out_output[(getCycle()+1)%2] = id3632in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id828out_output;

  { // Node ID: 828 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id828in_input = id3634out_output[getCycle()%2];

    id828out_output = id828in_input;
  }
  { // Node ID: 3448 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2624out_result;

  { // Node ID: 2624 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2624in_a = id3448out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2624in_b = id3524out_output[getCycle()%2];

    id2624out_result = (eq_fixed(id2624in_a,id2624in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id827out_o;

  { // Node ID: 827 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id827in_i = id2624out_result;

    id827out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id827in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id829out_result;

  { // Node ID: 829 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id829in_a = id828out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id829in_b = id827out_o;

    id829out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id829in_a,id829in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id830out_result;

  { // Node ID: 830 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id830in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id830in_option0 = id829out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id830in_option1 = id827out_o;

    HWOffsetFix<32,0,UNSIGNED> id830x_1;

    switch((id830in_sel.getValueAsLong())) {
      case 0l:
        id830x_1 = id830in_option0;
        break;
      case 1l:
        id830x_1 = id830in_option1;
        break;
      default:
        id830x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id830out_result = (id830x_1);
  }
  { // Node ID: 3634 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3634in_input = id830out_result;

    id3634out_output[(getCycle()+1)%2] = id3634in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id816out_output;

  { // Node ID: 816 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id816in_input = id3636out_output[getCycle()%2];

    id816out_output = id816in_input;
  }
  { // Node ID: 3447 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2625out_result;

  { // Node ID: 2625 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2625in_a = id3447out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2625in_b = id3524out_output[getCycle()%2];

    id2625out_result = (eq_fixed(id2625in_a,id2625in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id815out_o;

  { // Node ID: 815 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id815in_i = id2625out_result;

    id815out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id815in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id817out_result;

  { // Node ID: 817 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id817in_a = id816out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id817in_b = id815out_o;

    id817out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id817in_a,id817in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id818out_result;

  { // Node ID: 818 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id818in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id818in_option0 = id817out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id818in_option1 = id815out_o;

    HWOffsetFix<32,0,UNSIGNED> id818x_1;

    switch((id818in_sel.getValueAsLong())) {
      case 0l:
        id818x_1 = id818in_option0;
        break;
      case 1l:
        id818x_1 = id818in_option1;
        break;
      default:
        id818x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id818out_result = (id818x_1);
  }
  { // Node ID: 3636 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3636in_input = id818out_result;

    id3636out_output[(getCycle()+1)%2] = id3636in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id804out_output;

  { // Node ID: 804 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id804in_input = id3638out_output[getCycle()%2];

    id804out_output = id804in_input;
  }
  { // Node ID: 3446 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2626out_result;

  { // Node ID: 2626 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2626in_a = id3446out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2626in_b = id3524out_output[getCycle()%2];

    id2626out_result = (eq_fixed(id2626in_a,id2626in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id803out_o;

  { // Node ID: 803 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id803in_i = id2626out_result;

    id803out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id803in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id805out_result;

  { // Node ID: 805 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id805in_a = id804out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id805in_b = id803out_o;

    id805out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id805in_a,id805in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id806out_result;

  { // Node ID: 806 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id806in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id806in_option0 = id805out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id806in_option1 = id803out_o;

    HWOffsetFix<32,0,UNSIGNED> id806x_1;

    switch((id806in_sel.getValueAsLong())) {
      case 0l:
        id806x_1 = id806in_option0;
        break;
      case 1l:
        id806x_1 = id806in_option1;
        break;
      default:
        id806x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id806out_result = (id806x_1);
  }
  { // Node ID: 3638 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3638in_input = id806out_result;

    id3638out_output[(getCycle()+1)%2] = id3638in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id792out_output;

  { // Node ID: 792 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id792in_input = id3640out_output[getCycle()%2];

    id792out_output = id792in_input;
  }
  { // Node ID: 3445 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2627out_result;

  { // Node ID: 2627 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2627in_a = id3445out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2627in_b = id3524out_output[getCycle()%2];

    id2627out_result = (eq_fixed(id2627in_a,id2627in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id791out_o;

  { // Node ID: 791 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id791in_i = id2627out_result;

    id791out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id791in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id793out_result;

  { // Node ID: 793 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id793in_a = id792out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id793in_b = id791out_o;

    id793out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id793in_a,id793in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id794out_result;

  { // Node ID: 794 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id794in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id794in_option0 = id793out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id794in_option1 = id791out_o;

    HWOffsetFix<32,0,UNSIGNED> id794x_1;

    switch((id794in_sel.getValueAsLong())) {
      case 0l:
        id794x_1 = id794in_option0;
        break;
      case 1l:
        id794x_1 = id794in_option1;
        break;
      default:
        id794x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id794out_result = (id794x_1);
  }
  { // Node ID: 3640 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3640in_input = id794out_result;

    id3640out_output[(getCycle()+1)%2] = id3640in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id780out_output;

  { // Node ID: 780 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id780in_input = id3642out_output[getCycle()%2];

    id780out_output = id780in_input;
  }
  { // Node ID: 3444 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2628out_result;

  { // Node ID: 2628 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2628in_a = id3444out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2628in_b = id3524out_output[getCycle()%2];

    id2628out_result = (eq_fixed(id2628in_a,id2628in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id779out_o;

  { // Node ID: 779 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id779in_i = id2628out_result;

    id779out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id779in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id781out_result;

  { // Node ID: 781 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id781in_a = id780out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id781in_b = id779out_o;

    id781out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id781in_a,id781in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id782out_result;

  { // Node ID: 782 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id782in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id782in_option0 = id781out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id782in_option1 = id779out_o;

    HWOffsetFix<32,0,UNSIGNED> id782x_1;

    switch((id782in_sel.getValueAsLong())) {
      case 0l:
        id782x_1 = id782in_option0;
        break;
      case 1l:
        id782x_1 = id782in_option1;
        break;
      default:
        id782x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id782out_result = (id782x_1);
  }
  { // Node ID: 3642 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3642in_input = id782out_result;

    id3642out_output[(getCycle()+1)%2] = id3642in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id768out_output;

  { // Node ID: 768 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id768in_input = id3644out_output[getCycle()%2];

    id768out_output = id768in_input;
  }
  { // Node ID: 3443 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2629out_result;

  { // Node ID: 2629 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2629in_a = id3443out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2629in_b = id3524out_output[getCycle()%2];

    id2629out_result = (eq_fixed(id2629in_a,id2629in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id767out_o;

  { // Node ID: 767 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id767in_i = id2629out_result;

    id767out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id767in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id769out_result;

  { // Node ID: 769 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id769in_a = id768out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id769in_b = id767out_o;

    id769out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id769in_a,id769in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id770out_result;

  { // Node ID: 770 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id770in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id770in_option0 = id769out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id770in_option1 = id767out_o;

    HWOffsetFix<32,0,UNSIGNED> id770x_1;

    switch((id770in_sel.getValueAsLong())) {
      case 0l:
        id770x_1 = id770in_option0;
        break;
      case 1l:
        id770x_1 = id770in_option1;
        break;
      default:
        id770x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id770out_result = (id770x_1);
  }
  { // Node ID: 3644 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3644in_input = id770out_result;

    id3644out_output[(getCycle()+1)%2] = id3644in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id756out_output;

  { // Node ID: 756 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id756in_input = id3646out_output[getCycle()%2];

    id756out_output = id756in_input;
  }
  { // Node ID: 3442 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2630out_result;

  { // Node ID: 2630 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2630in_a = id3442out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2630in_b = id3524out_output[getCycle()%2];

    id2630out_result = (eq_fixed(id2630in_a,id2630in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id755out_o;

  { // Node ID: 755 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id755in_i = id2630out_result;

    id755out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id755in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id757out_result;

  { // Node ID: 757 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id757in_a = id756out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id757in_b = id755out_o;

    id757out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id757in_a,id757in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id758out_result;

  { // Node ID: 758 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id758in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id758in_option0 = id757out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id758in_option1 = id755out_o;

    HWOffsetFix<32,0,UNSIGNED> id758x_1;

    switch((id758in_sel.getValueAsLong())) {
      case 0l:
        id758x_1 = id758in_option0;
        break;
      case 1l:
        id758x_1 = id758in_option1;
        break;
      default:
        id758x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id758out_result = (id758x_1);
  }
  { // Node ID: 3646 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3646in_input = id758out_result;

    id3646out_output[(getCycle()+1)%2] = id3646in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id744out_output;

  { // Node ID: 744 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id744in_input = id3648out_output[getCycle()%2];

    id744out_output = id744in_input;
  }
  { // Node ID: 3441 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2631out_result;

  { // Node ID: 2631 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2631in_a = id3441out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2631in_b = id3524out_output[getCycle()%2];

    id2631out_result = (eq_fixed(id2631in_a,id2631in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id743out_o;

  { // Node ID: 743 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id743in_i = id2631out_result;

    id743out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id743in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id745out_result;

  { // Node ID: 745 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id745in_a = id744out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id745in_b = id743out_o;

    id745out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id745in_a,id745in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id746out_result;

  { // Node ID: 746 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id746in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id746in_option0 = id745out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id746in_option1 = id743out_o;

    HWOffsetFix<32,0,UNSIGNED> id746x_1;

    switch((id746in_sel.getValueAsLong())) {
      case 0l:
        id746x_1 = id746in_option0;
        break;
      case 1l:
        id746x_1 = id746in_option1;
        break;
      default:
        id746x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id746out_result = (id746x_1);
  }
  { // Node ID: 3648 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3648in_input = id746out_result;

    id3648out_output[(getCycle()+1)%2] = id3648in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id732out_output;

  { // Node ID: 732 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id732in_input = id3650out_output[getCycle()%2];

    id732out_output = id732in_input;
  }
  { // Node ID: 3440 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2632out_result;

  { // Node ID: 2632 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2632in_a = id3440out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2632in_b = id3524out_output[getCycle()%2];

    id2632out_result = (eq_fixed(id2632in_a,id2632in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id731out_o;

  { // Node ID: 731 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id731in_i = id2632out_result;

    id731out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id731in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id733out_result;

  { // Node ID: 733 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id733in_a = id732out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id733in_b = id731out_o;

    id733out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id733in_a,id733in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id734out_result;

  { // Node ID: 734 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id734in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id734in_option0 = id733out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id734in_option1 = id731out_o;

    HWOffsetFix<32,0,UNSIGNED> id734x_1;

    switch((id734in_sel.getValueAsLong())) {
      case 0l:
        id734x_1 = id734in_option0;
        break;
      case 1l:
        id734x_1 = id734in_option1;
        break;
      default:
        id734x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id734out_result = (id734x_1);
  }
  { // Node ID: 3650 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3650in_input = id734out_result;

    id3650out_output[(getCycle()+1)%2] = id3650in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id720out_output;

  { // Node ID: 720 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id720in_input = id3652out_output[getCycle()%2];

    id720out_output = id720in_input;
  }
  { // Node ID: 3439 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2633out_result;

  { // Node ID: 2633 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2633in_a = id3439out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2633in_b = id3524out_output[getCycle()%2];

    id2633out_result = (eq_fixed(id2633in_a,id2633in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id719out_o;

  { // Node ID: 719 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id719in_i = id2633out_result;

    id719out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id719in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id721out_result;

  { // Node ID: 721 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id721in_a = id720out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id721in_b = id719out_o;

    id721out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id721in_a,id721in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id722out_result;

  { // Node ID: 722 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id722in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id722in_option0 = id721out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id722in_option1 = id719out_o;

    HWOffsetFix<32,0,UNSIGNED> id722x_1;

    switch((id722in_sel.getValueAsLong())) {
      case 0l:
        id722x_1 = id722in_option0;
        break;
      case 1l:
        id722x_1 = id722in_option1;
        break;
      default:
        id722x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id722out_result = (id722x_1);
  }
  { // Node ID: 3652 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3652in_input = id722out_result;

    id3652out_output[(getCycle()+1)%2] = id3652in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id708out_output;

  { // Node ID: 708 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id708in_input = id3654out_output[getCycle()%2];

    id708out_output = id708in_input;
  }
  { // Node ID: 3438 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2634out_result;

  { // Node ID: 2634 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2634in_a = id3438out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2634in_b = id3524out_output[getCycle()%2];

    id2634out_result = (eq_fixed(id2634in_a,id2634in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id707out_o;

  { // Node ID: 707 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id707in_i = id2634out_result;

    id707out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id707in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id709out_result;

  { // Node ID: 709 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id709in_a = id708out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id709in_b = id707out_o;

    id709out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id709in_a,id709in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id710out_result;

  { // Node ID: 710 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id710in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id710in_option0 = id709out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id710in_option1 = id707out_o;

    HWOffsetFix<32,0,UNSIGNED> id710x_1;

    switch((id710in_sel.getValueAsLong())) {
      case 0l:
        id710x_1 = id710in_option0;
        break;
      case 1l:
        id710x_1 = id710in_option1;
        break;
      default:
        id710x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id710out_result = (id710x_1);
  }
  { // Node ID: 3654 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3654in_input = id710out_result;

    id3654out_output[(getCycle()+1)%2] = id3654in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id696out_output;

  { // Node ID: 696 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id696in_input = id3656out_output[getCycle()%2];

    id696out_output = id696in_input;
  }
  { // Node ID: 3437 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2635out_result;

  { // Node ID: 2635 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2635in_a = id3437out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2635in_b = id3524out_output[getCycle()%2];

    id2635out_result = (eq_fixed(id2635in_a,id2635in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id695out_o;

  { // Node ID: 695 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id695in_i = id2635out_result;

    id695out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id695in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id697out_result;

  { // Node ID: 697 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id697in_a = id696out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id697in_b = id695out_o;

    id697out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id697in_a,id697in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id698out_result;

  { // Node ID: 698 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id698in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id698in_option0 = id697out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id698in_option1 = id695out_o;

    HWOffsetFix<32,0,UNSIGNED> id698x_1;

    switch((id698in_sel.getValueAsLong())) {
      case 0l:
        id698x_1 = id698in_option0;
        break;
      case 1l:
        id698x_1 = id698in_option1;
        break;
      default:
        id698x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id698out_result = (id698x_1);
  }
  { // Node ID: 3656 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3656in_input = id698out_result;

    id3656out_output[(getCycle()+1)%2] = id3656in_input;
  }
  { // Node ID: 3516 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3516in_input = id3517out_output[getCycle()%2];

    id3516out_output[(getCycle()+1)%2] = id3516in_input;
  }
  { // Node ID: 3659 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3659in_input = id3516out_output[getCycle()%2];

    id3659out_output[(getCycle()+2)%3] = id3659in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id684out_output;

  { // Node ID: 684 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id684in_input = id3658out_output[getCycle()%2];

    id684out_output = id684in_input;
  }
  { // Node ID: 3436 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2636out_result;

  { // Node ID: 2636 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2636in_a = id3436out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2636in_b = id3524out_output[getCycle()%2];

    id2636out_result = (eq_fixed(id2636in_a,id2636in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id683out_o;

  { // Node ID: 683 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id683in_i = id2636out_result;

    id683out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id683in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id685out_result;

  { // Node ID: 685 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id685in_a = id684out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id685in_b = id683out_o;

    id685out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id685in_a,id685in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id686out_result;

  { // Node ID: 686 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id686in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id686in_option0 = id685out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id686in_option1 = id683out_o;

    HWOffsetFix<32,0,UNSIGNED> id686x_1;

    switch((id686in_sel.getValueAsLong())) {
      case 0l:
        id686x_1 = id686in_option0;
        break;
      case 1l:
        id686x_1 = id686in_option1;
        break;
      default:
        id686x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id686out_result = (id686x_1);
  }
  { // Node ID: 3658 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3658in_input = id686out_result;

    id3658out_output[(getCycle()+1)%2] = id3658in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id672out_output;

  { // Node ID: 672 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id672in_input = id3660out_output[getCycle()%2];

    id672out_output = id672in_input;
  }
  { // Node ID: 3435 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2637out_result;

  { // Node ID: 2637 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2637in_a = id3435out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2637in_b = id3524out_output[getCycle()%2];

    id2637out_result = (eq_fixed(id2637in_a,id2637in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id671out_o;

  { // Node ID: 671 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id671in_i = id2637out_result;

    id671out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id671in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id673out_result;

  { // Node ID: 673 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id673in_a = id672out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id673in_b = id671out_o;

    id673out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id673in_a,id673in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id674out_result;

  { // Node ID: 674 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id674in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id674in_option0 = id673out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id674in_option1 = id671out_o;

    HWOffsetFix<32,0,UNSIGNED> id674x_1;

    switch((id674in_sel.getValueAsLong())) {
      case 0l:
        id674x_1 = id674in_option0;
        break;
      case 1l:
        id674x_1 = id674in_option1;
        break;
      default:
        id674x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id674out_result = (id674x_1);
  }
  { // Node ID: 3660 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3660in_input = id674out_result;

    id3660out_output[(getCycle()+1)%2] = id3660in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id660out_output;

  { // Node ID: 660 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id660in_input = id3662out_output[getCycle()%2];

    id660out_output = id660in_input;
  }
  { // Node ID: 3434 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2638out_result;

  { // Node ID: 2638 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2638in_a = id3434out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2638in_b = id3524out_output[getCycle()%2];

    id2638out_result = (eq_fixed(id2638in_a,id2638in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id659out_o;

  { // Node ID: 659 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id659in_i = id2638out_result;

    id659out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id659in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id661out_result;

  { // Node ID: 661 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id661in_a = id660out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id661in_b = id659out_o;

    id661out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id661in_a,id661in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id662out_result;

  { // Node ID: 662 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id662in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id662in_option0 = id661out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id662in_option1 = id659out_o;

    HWOffsetFix<32,0,UNSIGNED> id662x_1;

    switch((id662in_sel.getValueAsLong())) {
      case 0l:
        id662x_1 = id662in_option0;
        break;
      case 1l:
        id662x_1 = id662in_option1;
        break;
      default:
        id662x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id662out_result = (id662x_1);
  }
  { // Node ID: 3662 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3662in_input = id662out_result;

    id3662out_output[(getCycle()+1)%2] = id3662in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id648out_output;

  { // Node ID: 648 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id648in_input = id3664out_output[getCycle()%2];

    id648out_output = id648in_input;
  }
  { // Node ID: 3433 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2639out_result;

  { // Node ID: 2639 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2639in_a = id3433out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2639in_b = id3524out_output[getCycle()%2];

    id2639out_result = (eq_fixed(id2639in_a,id2639in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id647out_o;

  { // Node ID: 647 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id647in_i = id2639out_result;

    id647out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id647in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id649out_result;

  { // Node ID: 649 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id649in_a = id648out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id649in_b = id647out_o;

    id649out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id649in_a,id649in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id650out_result;

  { // Node ID: 650 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id650in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id650in_option0 = id649out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id650in_option1 = id647out_o;

    HWOffsetFix<32,0,UNSIGNED> id650x_1;

    switch((id650in_sel.getValueAsLong())) {
      case 0l:
        id650x_1 = id650in_option0;
        break;
      case 1l:
        id650x_1 = id650in_option1;
        break;
      default:
        id650x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id650out_result = (id650x_1);
  }
  { // Node ID: 3664 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3664in_input = id650out_result;

    id3664out_output[(getCycle()+1)%2] = id3664in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id636out_output;

  { // Node ID: 636 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id636in_input = id3666out_output[getCycle()%2];

    id636out_output = id636in_input;
  }
  { // Node ID: 3432 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2640out_result;

  { // Node ID: 2640 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2640in_a = id3432out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2640in_b = id3524out_output[getCycle()%2];

    id2640out_result = (eq_fixed(id2640in_a,id2640in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id635out_o;

  { // Node ID: 635 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id635in_i = id2640out_result;

    id635out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id635in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id637out_result;

  { // Node ID: 637 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id637in_a = id636out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id637in_b = id635out_o;

    id637out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id637in_a,id637in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id638out_result;

  { // Node ID: 638 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id638in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id638in_option0 = id637out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id638in_option1 = id635out_o;

    HWOffsetFix<32,0,UNSIGNED> id638x_1;

    switch((id638in_sel.getValueAsLong())) {
      case 0l:
        id638x_1 = id638in_option0;
        break;
      case 1l:
        id638x_1 = id638in_option1;
        break;
      default:
        id638x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id638out_result = (id638x_1);
  }
  { // Node ID: 3666 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3666in_input = id638out_result;

    id3666out_output[(getCycle()+1)%2] = id3666in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id624out_output;

  { // Node ID: 624 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id624in_input = id3668out_output[getCycle()%2];

    id624out_output = id624in_input;
  }
  { // Node ID: 3431 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2641out_result;

  { // Node ID: 2641 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2641in_a = id3431out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2641in_b = id3524out_output[getCycle()%2];

    id2641out_result = (eq_fixed(id2641in_a,id2641in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id623out_o;

  { // Node ID: 623 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id623in_i = id2641out_result;

    id623out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id623in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id625out_result;

  { // Node ID: 625 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id625in_a = id624out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id625in_b = id623out_o;

    id625out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id625in_a,id625in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id626out_result;

  { // Node ID: 626 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id626in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id626in_option0 = id625out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id626in_option1 = id623out_o;

    HWOffsetFix<32,0,UNSIGNED> id626x_1;

    switch((id626in_sel.getValueAsLong())) {
      case 0l:
        id626x_1 = id626in_option0;
        break;
      case 1l:
        id626x_1 = id626in_option1;
        break;
      default:
        id626x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id626out_result = (id626x_1);
  }
  { // Node ID: 3668 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3668in_input = id626out_result;

    id3668out_output[(getCycle()+1)%2] = id3668in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id612out_output;

  { // Node ID: 612 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id612in_input = id3670out_output[getCycle()%2];

    id612out_output = id612in_input;
  }
  { // Node ID: 3430 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2642out_result;

  { // Node ID: 2642 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2642in_a = id3430out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2642in_b = id3524out_output[getCycle()%2];

    id2642out_result = (eq_fixed(id2642in_a,id2642in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id611out_o;

  { // Node ID: 611 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id611in_i = id2642out_result;

    id611out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id611in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id613out_result;

  { // Node ID: 613 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id613in_a = id612out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id613in_b = id611out_o;

    id613out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id613in_a,id613in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id614out_result;

  { // Node ID: 614 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id614in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id614in_option0 = id613out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id614in_option1 = id611out_o;

    HWOffsetFix<32,0,UNSIGNED> id614x_1;

    switch((id614in_sel.getValueAsLong())) {
      case 0l:
        id614x_1 = id614in_option0;
        break;
      case 1l:
        id614x_1 = id614in_option1;
        break;
      default:
        id614x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id614out_result = (id614x_1);
  }
  { // Node ID: 3670 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3670in_input = id614out_result;

    id3670out_output[(getCycle()+1)%2] = id3670in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id600out_output;

  { // Node ID: 600 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id600in_input = id3672out_output[getCycle()%2];

    id600out_output = id600in_input;
  }
  { // Node ID: 3429 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2643out_result;

  { // Node ID: 2643 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2643in_a = id3429out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2643in_b = id3524out_output[getCycle()%2];

    id2643out_result = (eq_fixed(id2643in_a,id2643in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id599out_o;

  { // Node ID: 599 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id599in_i = id2643out_result;

    id599out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id599in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id601out_result;

  { // Node ID: 601 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id601in_a = id600out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id601in_b = id599out_o;

    id601out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id601in_a,id601in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id602out_result;

  { // Node ID: 602 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id602in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id602in_option0 = id601out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id602in_option1 = id599out_o;

    HWOffsetFix<32,0,UNSIGNED> id602x_1;

    switch((id602in_sel.getValueAsLong())) {
      case 0l:
        id602x_1 = id602in_option0;
        break;
      case 1l:
        id602x_1 = id602in_option1;
        break;
      default:
        id602x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id602out_result = (id602x_1);
  }
  { // Node ID: 3672 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3672in_input = id602out_result;

    id3672out_output[(getCycle()+1)%2] = id3672in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id588out_output;

  { // Node ID: 588 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id588in_input = id3674out_output[getCycle()%2];

    id588out_output = id588in_input;
  }
  { // Node ID: 3428 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2644out_result;

  { // Node ID: 2644 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2644in_a = id3428out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2644in_b = id3524out_output[getCycle()%2];

    id2644out_result = (eq_fixed(id2644in_a,id2644in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id587out_o;

  { // Node ID: 587 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id587in_i = id2644out_result;

    id587out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id587in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id589out_result;

  { // Node ID: 589 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id589in_a = id588out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id589in_b = id587out_o;

    id589out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id589in_a,id589in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id590out_result;

  { // Node ID: 590 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id590in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id590in_option0 = id589out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id590in_option1 = id587out_o;

    HWOffsetFix<32,0,UNSIGNED> id590x_1;

    switch((id590in_sel.getValueAsLong())) {
      case 0l:
        id590x_1 = id590in_option0;
        break;
      case 1l:
        id590x_1 = id590in_option1;
        break;
      default:
        id590x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id590out_result = (id590x_1);
  }
  { // Node ID: 3674 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3674in_input = id590out_result;

    id3674out_output[(getCycle()+1)%2] = id3674in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id576out_output;

  { // Node ID: 576 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id576in_input = id3676out_output[getCycle()%2];

    id576out_output = id576in_input;
  }
  { // Node ID: 3427 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2645out_result;

  { // Node ID: 2645 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2645in_a = id3427out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2645in_b = id3525out_output[getCycle()%2];

    id2645out_result = (eq_fixed(id2645in_a,id2645in_b));
  }
  { // Node ID: 3677 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3677in_input = id2645out_result;

    id3677out_output[(getCycle()+1)%2] = id3677in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id575out_o;

  { // Node ID: 575 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id575in_i = id3677out_output[getCycle()%2];

    id575out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id575in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id577out_result;

  { // Node ID: 577 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id577in_a = id576out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id577in_b = id575out_o;

    id577out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id577in_a,id577in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id578out_result;

  { // Node ID: 578 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id578in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id578in_option0 = id577out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id578in_option1 = id575out_o;

    HWOffsetFix<32,0,UNSIGNED> id578x_1;

    switch((id578in_sel.getValueAsLong())) {
      case 0l:
        id578x_1 = id578in_option0;
        break;
      case 1l:
        id578x_1 = id578in_option1;
        break;
      default:
        id578x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id578out_result = (id578x_1);
  }
  { // Node ID: 3676 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3676in_input = id578out_result;

    id3676out_output[(getCycle()+1)%2] = id3676in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id564out_output;

  { // Node ID: 564 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id564in_input = id3679out_output[getCycle()%2];

    id564out_output = id564in_input;
  }
  { // Node ID: 3426 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2646out_result;

  { // Node ID: 2646 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2646in_a = id3426out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2646in_b = id3525out_output[getCycle()%2];

    id2646out_result = (eq_fixed(id2646in_a,id2646in_b));
  }
  { // Node ID: 3680 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3680in_input = id2646out_result;

    id3680out_output[(getCycle()+1)%2] = id3680in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id563out_o;

  { // Node ID: 563 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id563in_i = id3680out_output[getCycle()%2];

    id563out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id563in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id565out_result;

  { // Node ID: 565 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id565in_a = id564out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id565in_b = id563out_o;

    id565out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id565in_a,id565in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id566out_result;

  { // Node ID: 566 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id566in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id566in_option0 = id565out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id566in_option1 = id563out_o;

    HWOffsetFix<32,0,UNSIGNED> id566x_1;

    switch((id566in_sel.getValueAsLong())) {
      case 0l:
        id566x_1 = id566in_option0;
        break;
      case 1l:
        id566x_1 = id566in_option1;
        break;
      default:
        id566x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id566out_result = (id566x_1);
  }
  { // Node ID: 3679 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3679in_input = id566out_result;

    id3679out_output[(getCycle()+1)%2] = id3679in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id552out_output;

  { // Node ID: 552 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id552in_input = id3682out_output[getCycle()%2];

    id552out_output = id552in_input;
  }
  { // Node ID: 3425 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2647out_result;

  { // Node ID: 2647 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2647in_a = id3425out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2647in_b = id3525out_output[getCycle()%2];

    id2647out_result = (eq_fixed(id2647in_a,id2647in_b));
  }
  { // Node ID: 3683 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3683in_input = id2647out_result;

    id3683out_output[(getCycle()+1)%2] = id3683in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id551out_o;

  { // Node ID: 551 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id551in_i = id3683out_output[getCycle()%2];

    id551out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id551in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id553out_result;

  { // Node ID: 553 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id553in_a = id552out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id553in_b = id551out_o;

    id553out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id553in_a,id553in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id554out_result;

  { // Node ID: 554 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id554in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id554in_option0 = id553out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id554in_option1 = id551out_o;

    HWOffsetFix<32,0,UNSIGNED> id554x_1;

    switch((id554in_sel.getValueAsLong())) {
      case 0l:
        id554x_1 = id554in_option0;
        break;
      case 1l:
        id554x_1 = id554in_option1;
        break;
      default:
        id554x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id554out_result = (id554x_1);
  }
  { // Node ID: 3682 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3682in_input = id554out_result;

    id3682out_output[(getCycle()+1)%2] = id3682in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id540out_output;

  { // Node ID: 540 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id540in_input = id3685out_output[getCycle()%2];

    id540out_output = id540in_input;
  }
  { // Node ID: 3424 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2648out_result;

  { // Node ID: 2648 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2648in_a = id3424out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2648in_b = id3525out_output[getCycle()%2];

    id2648out_result = (eq_fixed(id2648in_a,id2648in_b));
  }
  { // Node ID: 3686 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3686in_input = id2648out_result;

    id3686out_output[(getCycle()+1)%2] = id3686in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id539out_o;

  { // Node ID: 539 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id539in_i = id3686out_output[getCycle()%2];

    id539out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id539in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id541out_result;

  { // Node ID: 541 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id541in_a = id540out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id541in_b = id539out_o;

    id541out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id541in_a,id541in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id542out_result;

  { // Node ID: 542 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id542in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id542in_option0 = id541out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id542in_option1 = id539out_o;

    HWOffsetFix<32,0,UNSIGNED> id542x_1;

    switch((id542in_sel.getValueAsLong())) {
      case 0l:
        id542x_1 = id542in_option0;
        break;
      case 1l:
        id542x_1 = id542in_option1;
        break;
      default:
        id542x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id542out_result = (id542x_1);
  }
  { // Node ID: 3685 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3685in_input = id542out_result;

    id3685out_output[(getCycle()+1)%2] = id3685in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id528out_output;

  { // Node ID: 528 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id528in_input = id3688out_output[getCycle()%2];

    id528out_output = id528in_input;
  }
  { // Node ID: 3423 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2649out_result;

  { // Node ID: 2649 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2649in_a = id3423out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2649in_b = id3525out_output[getCycle()%2];

    id2649out_result = (eq_fixed(id2649in_a,id2649in_b));
  }
  { // Node ID: 3689 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3689in_input = id2649out_result;

    id3689out_output[(getCycle()+1)%2] = id3689in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id527out_o;

  { // Node ID: 527 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id527in_i = id3689out_output[getCycle()%2];

    id527out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id527in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id529out_result;

  { // Node ID: 529 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id529in_a = id528out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id529in_b = id527out_o;

    id529out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id529in_a,id529in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id530out_result;

  { // Node ID: 530 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id530in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id530in_option0 = id529out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id530in_option1 = id527out_o;

    HWOffsetFix<32,0,UNSIGNED> id530x_1;

    switch((id530in_sel.getValueAsLong())) {
      case 0l:
        id530x_1 = id530in_option0;
        break;
      case 1l:
        id530x_1 = id530in_option1;
        break;
      default:
        id530x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id530out_result = (id530x_1);
  }
  { // Node ID: 3688 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3688in_input = id530out_result;

    id3688out_output[(getCycle()+1)%2] = id3688in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id516out_output;

  { // Node ID: 516 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id516in_input = id3691out_output[getCycle()%2];

    id516out_output = id516in_input;
  }
  { // Node ID: 3422 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2650out_result;

  { // Node ID: 2650 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2650in_a = id3422out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2650in_b = id3525out_output[getCycle()%2];

    id2650out_result = (eq_fixed(id2650in_a,id2650in_b));
  }
  { // Node ID: 3692 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3692in_input = id2650out_result;

    id3692out_output[(getCycle()+1)%2] = id3692in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id515out_o;

  { // Node ID: 515 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id515in_i = id3692out_output[getCycle()%2];

    id515out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id515in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id517out_result;

  { // Node ID: 517 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id517in_a = id516out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id517in_b = id515out_o;

    id517out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id517in_a,id517in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id518out_result;

  { // Node ID: 518 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id518in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id518in_option0 = id517out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id518in_option1 = id515out_o;

    HWOffsetFix<32,0,UNSIGNED> id518x_1;

    switch((id518in_sel.getValueAsLong())) {
      case 0l:
        id518x_1 = id518in_option0;
        break;
      case 1l:
        id518x_1 = id518in_option1;
        break;
      default:
        id518x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id518out_result = (id518x_1);
  }
  { // Node ID: 3691 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3691in_input = id518out_result;

    id3691out_output[(getCycle()+1)%2] = id3691in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id504out_output;

  { // Node ID: 504 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id504in_input = id3694out_output[getCycle()%2];

    id504out_output = id504in_input;
  }
  { // Node ID: 3421 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2651out_result;

  { // Node ID: 2651 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2651in_a = id3421out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2651in_b = id3525out_output[getCycle()%2];

    id2651out_result = (eq_fixed(id2651in_a,id2651in_b));
  }
  { // Node ID: 3695 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3695in_input = id2651out_result;

    id3695out_output[(getCycle()+1)%2] = id3695in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id503out_o;

  { // Node ID: 503 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id503in_i = id3695out_output[getCycle()%2];

    id503out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id503in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id505out_result;

  { // Node ID: 505 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id505in_a = id504out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id505in_b = id503out_o;

    id505out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id505in_a,id505in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id506out_result;

  { // Node ID: 506 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id506in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id506in_option0 = id505out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id506in_option1 = id503out_o;

    HWOffsetFix<32,0,UNSIGNED> id506x_1;

    switch((id506in_sel.getValueAsLong())) {
      case 0l:
        id506x_1 = id506in_option0;
        break;
      case 1l:
        id506x_1 = id506in_option1;
        break;
      default:
        id506x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id506out_result = (id506x_1);
  }
  { // Node ID: 3694 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3694in_input = id506out_result;

    id3694out_output[(getCycle()+1)%2] = id3694in_input;
  }
  { // Node ID: 3515 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3515in_input = id3516out_output[getCycle()%2];

    id3515out_output[(getCycle()+1)%2] = id3515in_input;
  }
  { // Node ID: 3699 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3699in_input = id3515out_output[getCycle()%2];

    id3699out_output[(getCycle()+1)%2] = id3699in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id492out_output;

  { // Node ID: 492 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id492in_input = id3697out_output[getCycle()%2];

    id492out_output = id492in_input;
  }
  { // Node ID: 3420 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2652out_result;

  { // Node ID: 2652 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2652in_a = id3420out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2652in_b = id3525out_output[getCycle()%2];

    id2652out_result = (eq_fixed(id2652in_a,id2652in_b));
  }
  { // Node ID: 3698 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3698in_input = id2652out_result;

    id3698out_output[(getCycle()+1)%2] = id3698in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id491out_o;

  { // Node ID: 491 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id491in_i = id3698out_output[getCycle()%2];

    id491out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id491in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id493out_result;

  { // Node ID: 493 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id493in_a = id492out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id493in_b = id491out_o;

    id493out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id493in_a,id493in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id494out_result;

  { // Node ID: 494 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id494in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id494in_option0 = id493out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id494in_option1 = id491out_o;

    HWOffsetFix<32,0,UNSIGNED> id494x_1;

    switch((id494in_sel.getValueAsLong())) {
      case 0l:
        id494x_1 = id494in_option0;
        break;
      case 1l:
        id494x_1 = id494in_option1;
        break;
      default:
        id494x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id494out_result = (id494x_1);
  }
  { // Node ID: 3697 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3697in_input = id494out_result;

    id3697out_output[(getCycle()+1)%2] = id3697in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id480out_output;

  { // Node ID: 480 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id480in_input = id3700out_output[getCycle()%2];

    id480out_output = id480in_input;
  }
  { // Node ID: 3419 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2653out_result;

  { // Node ID: 2653 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2653in_a = id3419out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2653in_b = id3525out_output[getCycle()%2];

    id2653out_result = (eq_fixed(id2653in_a,id2653in_b));
  }
  { // Node ID: 3701 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3701in_input = id2653out_result;

    id3701out_output[(getCycle()+1)%2] = id3701in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id479out_o;

  { // Node ID: 479 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id479in_i = id3701out_output[getCycle()%2];

    id479out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id479in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id481out_result;

  { // Node ID: 481 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id481in_a = id480out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id481in_b = id479out_o;

    id481out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id481in_a,id481in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id482out_result;

  { // Node ID: 482 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id482in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id482in_option0 = id481out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id482in_option1 = id479out_o;

    HWOffsetFix<32,0,UNSIGNED> id482x_1;

    switch((id482in_sel.getValueAsLong())) {
      case 0l:
        id482x_1 = id482in_option0;
        break;
      case 1l:
        id482x_1 = id482in_option1;
        break;
      default:
        id482x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id482out_result = (id482x_1);
  }
  { // Node ID: 3700 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3700in_input = id482out_result;

    id3700out_output[(getCycle()+1)%2] = id3700in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id468out_output;

  { // Node ID: 468 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id468in_input = id3703out_output[getCycle()%2];

    id468out_output = id468in_input;
  }
  { // Node ID: 3418 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2654out_result;

  { // Node ID: 2654 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2654in_a = id3418out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2654in_b = id3525out_output[getCycle()%2];

    id2654out_result = (eq_fixed(id2654in_a,id2654in_b));
  }
  { // Node ID: 3704 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3704in_input = id2654out_result;

    id3704out_output[(getCycle()+1)%2] = id3704in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id467out_o;

  { // Node ID: 467 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id467in_i = id3704out_output[getCycle()%2];

    id467out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id467in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id469out_result;

  { // Node ID: 469 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id469in_a = id468out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id469in_b = id467out_o;

    id469out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id469in_a,id469in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id470out_result;

  { // Node ID: 470 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id470in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id470in_option0 = id469out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id470in_option1 = id467out_o;

    HWOffsetFix<32,0,UNSIGNED> id470x_1;

    switch((id470in_sel.getValueAsLong())) {
      case 0l:
        id470x_1 = id470in_option0;
        break;
      case 1l:
        id470x_1 = id470in_option1;
        break;
      default:
        id470x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id470out_result = (id470x_1);
  }
  { // Node ID: 3703 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3703in_input = id470out_result;

    id3703out_output[(getCycle()+1)%2] = id3703in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id456out_output;

  { // Node ID: 456 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id456in_input = id3706out_output[getCycle()%2];

    id456out_output = id456in_input;
  }
  { // Node ID: 3417 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2655out_result;

  { // Node ID: 2655 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2655in_a = id3417out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2655in_b = id3525out_output[getCycle()%2];

    id2655out_result = (eq_fixed(id2655in_a,id2655in_b));
  }
  { // Node ID: 3707 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3707in_input = id2655out_result;

    id3707out_output[(getCycle()+1)%2] = id3707in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id455out_o;

  { // Node ID: 455 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id455in_i = id3707out_output[getCycle()%2];

    id455out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id455in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id457out_result;

  { // Node ID: 457 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id457in_a = id456out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id457in_b = id455out_o;

    id457out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id457in_a,id457in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id458out_result;

  { // Node ID: 458 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id458in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id458in_option0 = id457out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id458in_option1 = id455out_o;

    HWOffsetFix<32,0,UNSIGNED> id458x_1;

    switch((id458in_sel.getValueAsLong())) {
      case 0l:
        id458x_1 = id458in_option0;
        break;
      case 1l:
        id458x_1 = id458in_option1;
        break;
      default:
        id458x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id458out_result = (id458x_1);
  }
  { // Node ID: 3706 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3706in_input = id458out_result;

    id3706out_output[(getCycle()+1)%2] = id3706in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id444out_output;

  { // Node ID: 444 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id444in_input = id3709out_output[getCycle()%2];

    id444out_output = id444in_input;
  }
  { // Node ID: 3416 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2656out_result;

  { // Node ID: 2656 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2656in_a = id3416out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2656in_b = id3525out_output[getCycle()%2];

    id2656out_result = (eq_fixed(id2656in_a,id2656in_b));
  }
  { // Node ID: 3710 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3710in_input = id2656out_result;

    id3710out_output[(getCycle()+1)%2] = id3710in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id443out_o;

  { // Node ID: 443 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id443in_i = id3710out_output[getCycle()%2];

    id443out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id443in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id445out_result;

  { // Node ID: 445 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id445in_a = id444out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id445in_b = id443out_o;

    id445out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id445in_a,id445in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id446out_result;

  { // Node ID: 446 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id446in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id446in_option0 = id445out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id446in_option1 = id443out_o;

    HWOffsetFix<32,0,UNSIGNED> id446x_1;

    switch((id446in_sel.getValueAsLong())) {
      case 0l:
        id446x_1 = id446in_option0;
        break;
      case 1l:
        id446x_1 = id446in_option1;
        break;
      default:
        id446x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id446out_result = (id446x_1);
  }
  { // Node ID: 3709 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3709in_input = id446out_result;

    id3709out_output[(getCycle()+1)%2] = id3709in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id432out_output;

  { // Node ID: 432 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id432in_input = id3712out_output[getCycle()%2];

    id432out_output = id432in_input;
  }
  { // Node ID: 3415 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2657out_result;

  { // Node ID: 2657 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2657in_a = id3415out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2657in_b = id3525out_output[getCycle()%2];

    id2657out_result = (eq_fixed(id2657in_a,id2657in_b));
  }
  { // Node ID: 3713 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3713in_input = id2657out_result;

    id3713out_output[(getCycle()+1)%2] = id3713in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id431out_o;

  { // Node ID: 431 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id431in_i = id3713out_output[getCycle()%2];

    id431out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id431in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id433out_result;

  { // Node ID: 433 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id433in_a = id432out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id433in_b = id431out_o;

    id433out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id433in_a,id433in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id434out_result;

  { // Node ID: 434 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id434in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id434in_option0 = id433out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id434in_option1 = id431out_o;

    HWOffsetFix<32,0,UNSIGNED> id434x_1;

    switch((id434in_sel.getValueAsLong())) {
      case 0l:
        id434x_1 = id434in_option0;
        break;
      case 1l:
        id434x_1 = id434in_option1;
        break;
      default:
        id434x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id434out_result = (id434x_1);
  }
  { // Node ID: 3712 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3712in_input = id434out_result;

    id3712out_output[(getCycle()+1)%2] = id3712in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id420out_output;

  { // Node ID: 420 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id420in_input = id3715out_output[getCycle()%2];

    id420out_output = id420in_input;
  }
  { // Node ID: 3414 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2658out_result;

  { // Node ID: 2658 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2658in_a = id3414out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2658in_b = id3525out_output[getCycle()%2];

    id2658out_result = (eq_fixed(id2658in_a,id2658in_b));
  }
  { // Node ID: 3716 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3716in_input = id2658out_result;

    id3716out_output[(getCycle()+1)%2] = id3716in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id419out_o;

  { // Node ID: 419 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id419in_i = id3716out_output[getCycle()%2];

    id419out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id419in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id421out_result;

  { // Node ID: 421 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id421in_a = id420out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id421in_b = id419out_o;

    id421out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id421in_a,id421in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id422out_result;

  { // Node ID: 422 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id422in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id422in_option0 = id421out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id422in_option1 = id419out_o;

    HWOffsetFix<32,0,UNSIGNED> id422x_1;

    switch((id422in_sel.getValueAsLong())) {
      case 0l:
        id422x_1 = id422in_option0;
        break;
      case 1l:
        id422x_1 = id422in_option1;
        break;
      default:
        id422x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id422out_result = (id422x_1);
  }
  { // Node ID: 3715 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3715in_input = id422out_result;

    id3715out_output[(getCycle()+1)%2] = id3715in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id408out_output;

  { // Node ID: 408 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id408in_input = id3718out_output[getCycle()%2];

    id408out_output = id408in_input;
  }
  { // Node ID: 3413 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2659out_result;

  { // Node ID: 2659 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2659in_a = id3413out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2659in_b = id3525out_output[getCycle()%2];

    id2659out_result = (eq_fixed(id2659in_a,id2659in_b));
  }
  { // Node ID: 3719 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3719in_input = id2659out_result;

    id3719out_output[(getCycle()+1)%2] = id3719in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id407out_o;

  { // Node ID: 407 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id407in_i = id3719out_output[getCycle()%2];

    id407out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id407in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id409out_result;

  { // Node ID: 409 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id409in_a = id408out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id409in_b = id407out_o;

    id409out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id409in_a,id409in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id410out_result;

  { // Node ID: 410 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id410in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id410in_option0 = id409out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id410in_option1 = id407out_o;

    HWOffsetFix<32,0,UNSIGNED> id410x_1;

    switch((id410in_sel.getValueAsLong())) {
      case 0l:
        id410x_1 = id410in_option0;
        break;
      case 1l:
        id410x_1 = id410in_option1;
        break;
      default:
        id410x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id410out_result = (id410x_1);
  }
  { // Node ID: 3718 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3718in_input = id410out_result;

    id3718out_output[(getCycle()+1)%2] = id3718in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id396out_output;

  { // Node ID: 396 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id396in_input = id3721out_output[getCycle()%2];

    id396out_output = id396in_input;
  }
  { // Node ID: 3412 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2660out_result;

  { // Node ID: 2660 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2660in_a = id3412out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2660in_b = id3525out_output[getCycle()%2];

    id2660out_result = (eq_fixed(id2660in_a,id2660in_b));
  }
  { // Node ID: 3722 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3722in_input = id2660out_result;

    id3722out_output[(getCycle()+1)%2] = id3722in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id395out_o;

  { // Node ID: 395 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id395in_i = id3722out_output[getCycle()%2];

    id395out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id395in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id397out_result;

  { // Node ID: 397 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id397in_a = id396out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id397in_b = id395out_o;

    id397out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id397in_a,id397in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id398out_result;

  { // Node ID: 398 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id398in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id398in_option0 = id397out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id398in_option1 = id395out_o;

    HWOffsetFix<32,0,UNSIGNED> id398x_1;

    switch((id398in_sel.getValueAsLong())) {
      case 0l:
        id398x_1 = id398in_option0;
        break;
      case 1l:
        id398x_1 = id398in_option1;
        break;
      default:
        id398x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id398out_result = (id398x_1);
  }
  { // Node ID: 3721 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3721in_input = id398out_result;

    id3721out_output[(getCycle()+1)%2] = id3721in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id384out_output;

  { // Node ID: 384 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id384in_input = id3724out_output[getCycle()%2];

    id384out_output = id384in_input;
  }
  { // Node ID: 3411 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2661out_result;

  { // Node ID: 2661 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2661in_a = id3411out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2661in_b = id3525out_output[getCycle()%2];

    id2661out_result = (eq_fixed(id2661in_a,id2661in_b));
  }
  { // Node ID: 3725 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3725in_input = id2661out_result;

    id3725out_output[(getCycle()+1)%2] = id3725in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id383out_o;

  { // Node ID: 383 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id383in_i = id3725out_output[getCycle()%2];

    id383out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id383in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id385out_result;

  { // Node ID: 385 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id385in_a = id384out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id385in_b = id383out_o;

    id385out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id385in_a,id385in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id386out_result;

  { // Node ID: 386 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id386in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id386in_option0 = id385out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id386in_option1 = id383out_o;

    HWOffsetFix<32,0,UNSIGNED> id386x_1;

    switch((id386in_sel.getValueAsLong())) {
      case 0l:
        id386x_1 = id386in_option0;
        break;
      case 1l:
        id386x_1 = id386in_option1;
        break;
      default:
        id386x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id386out_result = (id386x_1);
  }
  { // Node ID: 3724 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3724in_input = id386out_result;

    id3724out_output[(getCycle()+1)%2] = id3724in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id372out_output;

  { // Node ID: 372 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id372in_input = id3727out_output[getCycle()%2];

    id372out_output = id372in_input;
  }
  { // Node ID: 3410 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2662out_result;

  { // Node ID: 2662 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2662in_a = id3410out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2662in_b = id3525out_output[getCycle()%2];

    id2662out_result = (eq_fixed(id2662in_a,id2662in_b));
  }
  { // Node ID: 3728 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3728in_input = id2662out_result;

    id3728out_output[(getCycle()+1)%2] = id3728in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id371out_o;

  { // Node ID: 371 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id371in_i = id3728out_output[getCycle()%2];

    id371out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id371in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id373out_result;

  { // Node ID: 373 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id373in_a = id372out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id373in_b = id371out_o;

    id373out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id373in_a,id373in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id374out_result;

  { // Node ID: 374 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id374in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id374in_option0 = id373out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id374in_option1 = id371out_o;

    HWOffsetFix<32,0,UNSIGNED> id374x_1;

    switch((id374in_sel.getValueAsLong())) {
      case 0l:
        id374x_1 = id374in_option0;
        break;
      case 1l:
        id374x_1 = id374in_option1;
        break;
      default:
        id374x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id374out_result = (id374x_1);
  }
  { // Node ID: 3727 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3727in_input = id374out_result;

    id3727out_output[(getCycle()+1)%2] = id3727in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id360out_output;

  { // Node ID: 360 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id360in_input = id3730out_output[getCycle()%2];

    id360out_output = id360in_input;
  }
  { // Node ID: 3409 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2663out_result;

  { // Node ID: 2663 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2663in_a = id3409out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2663in_b = id3525out_output[getCycle()%2];

    id2663out_result = (eq_fixed(id2663in_a,id2663in_b));
  }
  { // Node ID: 3731 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3731in_input = id2663out_result;

    id3731out_output[(getCycle()+1)%2] = id3731in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id359out_o;

  { // Node ID: 359 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id359in_i = id3731out_output[getCycle()%2];

    id359out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id359in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id361out_result;

  { // Node ID: 361 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id361in_a = id360out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id361in_b = id359out_o;

    id361out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id361in_a,id361in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id362out_result;

  { // Node ID: 362 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id362in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id362in_option0 = id361out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id362in_option1 = id359out_o;

    HWOffsetFix<32,0,UNSIGNED> id362x_1;

    switch((id362in_sel.getValueAsLong())) {
      case 0l:
        id362x_1 = id362in_option0;
        break;
      case 1l:
        id362x_1 = id362in_option1;
        break;
      default:
        id362x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id362out_result = (id362x_1);
  }
  { // Node ID: 3730 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3730in_input = id362out_result;

    id3730out_output[(getCycle()+1)%2] = id3730in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id348out_output;

  { // Node ID: 348 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id348in_input = id3733out_output[getCycle()%2];

    id348out_output = id348in_input;
  }
  { // Node ID: 3408 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2664out_result;

  { // Node ID: 2664 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2664in_a = id3408out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2664in_b = id3525out_output[getCycle()%2];

    id2664out_result = (eq_fixed(id2664in_a,id2664in_b));
  }
  { // Node ID: 3734 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3734in_input = id2664out_result;

    id3734out_output[(getCycle()+1)%2] = id3734in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id347out_o;

  { // Node ID: 347 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id347in_i = id3734out_output[getCycle()%2];

    id347out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id347in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id349out_result;

  { // Node ID: 349 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id349in_a = id348out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id349in_b = id347out_o;

    id349out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id349in_a,id349in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id350out_result;

  { // Node ID: 350 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id350in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id350in_option0 = id349out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id350in_option1 = id347out_o;

    HWOffsetFix<32,0,UNSIGNED> id350x_1;

    switch((id350in_sel.getValueAsLong())) {
      case 0l:
        id350x_1 = id350in_option0;
        break;
      case 1l:
        id350x_1 = id350in_option1;
        break;
      default:
        id350x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id350out_result = (id350x_1);
  }
  { // Node ID: 3733 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3733in_input = id350out_result;

    id3733out_output[(getCycle()+1)%2] = id3733in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id336out_output;

  { // Node ID: 336 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id336in_input = id3736out_output[getCycle()%2];

    id336out_output = id336in_input;
  }
  { // Node ID: 3407 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2665out_result;

  { // Node ID: 2665 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2665in_a = id3407out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2665in_b = id3525out_output[getCycle()%2];

    id2665out_result = (eq_fixed(id2665in_a,id2665in_b));
  }
  { // Node ID: 3737 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3737in_input = id2665out_result;

    id3737out_output[(getCycle()+1)%2] = id3737in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id335out_o;

  { // Node ID: 335 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id335in_i = id3737out_output[getCycle()%2];

    id335out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id335in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id337out_result;

  { // Node ID: 337 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id337in_a = id336out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id337in_b = id335out_o;

    id337out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id337in_a,id337in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id338out_result;

  { // Node ID: 338 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id338in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id338in_option0 = id337out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id338in_option1 = id335out_o;

    HWOffsetFix<32,0,UNSIGNED> id338x_1;

    switch((id338in_sel.getValueAsLong())) {
      case 0l:
        id338x_1 = id338in_option0;
        break;
      case 1l:
        id338x_1 = id338in_option1;
        break;
      default:
        id338x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id338out_result = (id338x_1);
  }
  { // Node ID: 3736 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3736in_input = id338out_result;

    id3736out_output[(getCycle()+1)%2] = id3736in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id324out_output;

  { // Node ID: 324 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id324in_input = id3739out_output[getCycle()%2];

    id324out_output = id324in_input;
  }
  { // Node ID: 3406 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2666out_result;

  { // Node ID: 2666 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2666in_a = id3406out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2666in_b = id3525out_output[getCycle()%2];

    id2666out_result = (eq_fixed(id2666in_a,id2666in_b));
  }
  { // Node ID: 3740 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3740in_input = id2666out_result;

    id3740out_output[(getCycle()+1)%2] = id3740in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id323out_o;

  { // Node ID: 323 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id323in_i = id3740out_output[getCycle()%2];

    id323out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id323in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id325out_result;

  { // Node ID: 325 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id325in_a = id324out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id325in_b = id323out_o;

    id325out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id325in_a,id325in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id326out_result;

  { // Node ID: 326 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id326in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id326in_option0 = id325out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id326in_option1 = id323out_o;

    HWOffsetFix<32,0,UNSIGNED> id326x_1;

    switch((id326in_sel.getValueAsLong())) {
      case 0l:
        id326x_1 = id326in_option0;
        break;
      case 1l:
        id326x_1 = id326in_option1;
        break;
      default:
        id326x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id326out_result = (id326x_1);
  }
  { // Node ID: 3739 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3739in_input = id326out_result;

    id3739out_output[(getCycle()+1)%2] = id3739in_input;
  }
  { // Node ID: 3514 (NodeRegister)
    const HWOffsetFix<1,0,UNSIGNED> &id3514in_input = id3515out_output[getCycle()%2];

    id3514out_output[(getCycle()+1)%2] = id3514in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id312out_output;

  { // Node ID: 312 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id312in_input = id3742out_output[getCycle()%2];

    id312out_output = id312in_input;
  }
  { // Node ID: 3405 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2667out_result;

  { // Node ID: 2667 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2667in_a = id3405out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2667in_b = id3525out_output[getCycle()%2];

    id2667out_result = (eq_fixed(id2667in_a,id2667in_b));
  }
  { // Node ID: 3743 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3743in_input = id2667out_result;

    id3743out_output[(getCycle()+1)%2] = id3743in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id311out_o;

  { // Node ID: 311 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id311in_i = id3743out_output[getCycle()%2];

    id311out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id311in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id313out_result;

  { // Node ID: 313 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id313in_a = id312out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id313in_b = id311out_o;

    id313out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id313in_a,id313in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id314out_result;

  { // Node ID: 314 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id314in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id314in_option0 = id313out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id314in_option1 = id311out_o;

    HWOffsetFix<32,0,UNSIGNED> id314x_1;

    switch((id314in_sel.getValueAsLong())) {
      case 0l:
        id314x_1 = id314in_option0;
        break;
      case 1l:
        id314x_1 = id314in_option1;
        break;
      default:
        id314x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id314out_result = (id314x_1);
  }
  { // Node ID: 3742 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3742in_input = id314out_result;

    id3742out_output[(getCycle()+1)%2] = id3742in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id300out_output;

  { // Node ID: 300 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id300in_input = id3744out_output[getCycle()%2];

    id300out_output = id300in_input;
  }
  { // Node ID: 3404 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2668out_result;

  { // Node ID: 2668 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2668in_a = id3404out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2668in_b = id3525out_output[getCycle()%2];

    id2668out_result = (eq_fixed(id2668in_a,id2668in_b));
  }
  { // Node ID: 3745 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3745in_input = id2668out_result;

    id3745out_output[(getCycle()+1)%2] = id3745in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id299out_o;

  { // Node ID: 299 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id299in_i = id3745out_output[getCycle()%2];

    id299out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id299in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id301out_result;

  { // Node ID: 301 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id301in_a = id300out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id301in_b = id299out_o;

    id301out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id301in_a,id301in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id302out_result;

  { // Node ID: 302 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id302in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id302in_option0 = id301out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id302in_option1 = id299out_o;

    HWOffsetFix<32,0,UNSIGNED> id302x_1;

    switch((id302in_sel.getValueAsLong())) {
      case 0l:
        id302x_1 = id302in_option0;
        break;
      case 1l:
        id302x_1 = id302in_option1;
        break;
      default:
        id302x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id302out_result = (id302x_1);
  }
  { // Node ID: 3744 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3744in_input = id302out_result;

    id3744out_output[(getCycle()+1)%2] = id3744in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id288out_output;

  { // Node ID: 288 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id288in_input = id3746out_output[getCycle()%2];

    id288out_output = id288in_input;
  }
  { // Node ID: 3403 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2669out_result;

  { // Node ID: 2669 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2669in_a = id3403out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2669in_b = id3525out_output[getCycle()%2];

    id2669out_result = (eq_fixed(id2669in_a,id2669in_b));
  }
  { // Node ID: 3747 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3747in_input = id2669out_result;

    id3747out_output[(getCycle()+1)%2] = id3747in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id287out_o;

  { // Node ID: 287 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id287in_i = id3747out_output[getCycle()%2];

    id287out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id287in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id289out_result;

  { // Node ID: 289 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id289in_a = id288out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id289in_b = id287out_o;

    id289out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id289in_a,id289in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id290out_result;

  { // Node ID: 290 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id290in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id290in_option0 = id289out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id290in_option1 = id287out_o;

    HWOffsetFix<32,0,UNSIGNED> id290x_1;

    switch((id290in_sel.getValueAsLong())) {
      case 0l:
        id290x_1 = id290in_option0;
        break;
      case 1l:
        id290x_1 = id290in_option1;
        break;
      default:
        id290x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id290out_result = (id290x_1);
  }
  { // Node ID: 3746 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3746in_input = id290out_result;

    id3746out_output[(getCycle()+1)%2] = id3746in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id276out_output;

  { // Node ID: 276 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id276in_input = id3748out_output[getCycle()%2];

    id276out_output = id276in_input;
  }
  { // Node ID: 3402 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2670out_result;

  { // Node ID: 2670 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2670in_a = id3402out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2670in_b = id3525out_output[getCycle()%2];

    id2670out_result = (eq_fixed(id2670in_a,id2670in_b));
  }
  { // Node ID: 3749 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3749in_input = id2670out_result;

    id3749out_output[(getCycle()+1)%2] = id3749in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id275out_o;

  { // Node ID: 275 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id275in_i = id3749out_output[getCycle()%2];

    id275out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id275in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id277out_result;

  { // Node ID: 277 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id277in_a = id276out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id277in_b = id275out_o;

    id277out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id277in_a,id277in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id278out_result;

  { // Node ID: 278 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id278in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id278in_option0 = id277out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id278in_option1 = id275out_o;

    HWOffsetFix<32,0,UNSIGNED> id278x_1;

    switch((id278in_sel.getValueAsLong())) {
      case 0l:
        id278x_1 = id278in_option0;
        break;
      case 1l:
        id278x_1 = id278in_option1;
        break;
      default:
        id278x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id278out_result = (id278x_1);
  }
  { // Node ID: 3748 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3748in_input = id278out_result;

    id3748out_output[(getCycle()+1)%2] = id3748in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id264out_output;

  { // Node ID: 264 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id264in_input = id3750out_output[getCycle()%2];

    id264out_output = id264in_input;
  }
  { // Node ID: 3401 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2671out_result;

  { // Node ID: 2671 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2671in_a = id3401out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2671in_b = id3525out_output[getCycle()%2];

    id2671out_result = (eq_fixed(id2671in_a,id2671in_b));
  }
  { // Node ID: 3751 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3751in_input = id2671out_result;

    id3751out_output[(getCycle()+1)%2] = id3751in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id263out_o;

  { // Node ID: 263 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id263in_i = id3751out_output[getCycle()%2];

    id263out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id263in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id265out_result;

  { // Node ID: 265 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id265in_a = id264out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id265in_b = id263out_o;

    id265out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id265in_a,id265in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id266out_result;

  { // Node ID: 266 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id266in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id266in_option0 = id265out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id266in_option1 = id263out_o;

    HWOffsetFix<32,0,UNSIGNED> id266x_1;

    switch((id266in_sel.getValueAsLong())) {
      case 0l:
        id266x_1 = id266in_option0;
        break;
      case 1l:
        id266x_1 = id266in_option1;
        break;
      default:
        id266x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id266out_result = (id266x_1);
  }
  { // Node ID: 3750 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3750in_input = id266out_result;

    id3750out_output[(getCycle()+1)%2] = id3750in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id252out_output;

  { // Node ID: 252 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id252in_input = id3752out_output[getCycle()%2];

    id252out_output = id252in_input;
  }
  { // Node ID: 3400 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2672out_result;

  { // Node ID: 2672 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2672in_a = id3400out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2672in_b = id3525out_output[getCycle()%2];

    id2672out_result = (eq_fixed(id2672in_a,id2672in_b));
  }
  { // Node ID: 3753 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3753in_input = id2672out_result;

    id3753out_output[(getCycle()+1)%2] = id3753in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id251out_o;

  { // Node ID: 251 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id251in_i = id3753out_output[getCycle()%2];

    id251out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id251in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id253out_result;

  { // Node ID: 253 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id253in_a = id252out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id253in_b = id251out_o;

    id253out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id253in_a,id253in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id254out_result;

  { // Node ID: 254 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id254in_option0 = id253out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id254in_option1 = id251out_o;

    HWOffsetFix<32,0,UNSIGNED> id254x_1;

    switch((id254in_sel.getValueAsLong())) {
      case 0l:
        id254x_1 = id254in_option0;
        break;
      case 1l:
        id254x_1 = id254in_option1;
        break;
      default:
        id254x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id254out_result = (id254x_1);
  }
  { // Node ID: 3752 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3752in_input = id254out_result;

    id3752out_output[(getCycle()+1)%2] = id3752in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id240out_output;

  { // Node ID: 240 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id240in_input = id3754out_output[getCycle()%2];

    id240out_output = id240in_input;
  }
  { // Node ID: 3399 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2673out_result;

  { // Node ID: 2673 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2673in_a = id3399out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2673in_b = id3525out_output[getCycle()%2];

    id2673out_result = (eq_fixed(id2673in_a,id2673in_b));
  }
  { // Node ID: 3755 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3755in_input = id2673out_result;

    id3755out_output[(getCycle()+1)%2] = id3755in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id239out_o;

  { // Node ID: 239 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id239in_i = id3755out_output[getCycle()%2];

    id239out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id239in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id241out_result;

  { // Node ID: 241 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id241in_a = id240out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id241in_b = id239out_o;

    id241out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id241in_a,id241in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id242out_result;

  { // Node ID: 242 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id242in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id242in_option0 = id241out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id242in_option1 = id239out_o;

    HWOffsetFix<32,0,UNSIGNED> id242x_1;

    switch((id242in_sel.getValueAsLong())) {
      case 0l:
        id242x_1 = id242in_option0;
        break;
      case 1l:
        id242x_1 = id242in_option1;
        break;
      default:
        id242x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id242out_result = (id242x_1);
  }
  { // Node ID: 3754 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3754in_input = id242out_result;

    id3754out_output[(getCycle()+1)%2] = id3754in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id228out_output;

  { // Node ID: 228 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id228in_input = id3756out_output[getCycle()%2];

    id228out_output = id228in_input;
  }
  { // Node ID: 3398 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2674out_result;

  { // Node ID: 2674 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2674in_a = id3398out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2674in_b = id3525out_output[getCycle()%2];

    id2674out_result = (eq_fixed(id2674in_a,id2674in_b));
  }
  { // Node ID: 3757 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3757in_input = id2674out_result;

    id3757out_output[(getCycle()+1)%2] = id3757in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id227out_o;

  { // Node ID: 227 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id227in_i = id3757out_output[getCycle()%2];

    id227out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id227in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id229out_result;

  { // Node ID: 229 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id229in_a = id228out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id229in_b = id227out_o;

    id229out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id229in_a,id229in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id230out_result;

  { // Node ID: 230 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id230in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id230in_option0 = id229out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id230in_option1 = id227out_o;

    HWOffsetFix<32,0,UNSIGNED> id230x_1;

    switch((id230in_sel.getValueAsLong())) {
      case 0l:
        id230x_1 = id230in_option0;
        break;
      case 1l:
        id230x_1 = id230in_option1;
        break;
      default:
        id230x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id230out_result = (id230x_1);
  }
  { // Node ID: 3756 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3756in_input = id230out_result;

    id3756out_output[(getCycle()+1)%2] = id3756in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id216out_output;

  { // Node ID: 216 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id216in_input = id3758out_output[getCycle()%2];

    id216out_output = id216in_input;
  }
  { // Node ID: 3397 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2675out_result;

  { // Node ID: 2675 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2675in_a = id3397out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2675in_b = id3525out_output[getCycle()%2];

    id2675out_result = (eq_fixed(id2675in_a,id2675in_b));
  }
  { // Node ID: 3759 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3759in_input = id2675out_result;

    id3759out_output[(getCycle()+1)%2] = id3759in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id215out_o;

  { // Node ID: 215 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id215in_i = id3759out_output[getCycle()%2];

    id215out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id215in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id217out_result;

  { // Node ID: 217 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id217in_a = id216out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id217in_b = id215out_o;

    id217out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id217in_a,id217in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id218out_result;

  { // Node ID: 218 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id218in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id218in_option0 = id217out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id218in_option1 = id215out_o;

    HWOffsetFix<32,0,UNSIGNED> id218x_1;

    switch((id218in_sel.getValueAsLong())) {
      case 0l:
        id218x_1 = id218in_option0;
        break;
      case 1l:
        id218x_1 = id218in_option1;
        break;
      default:
        id218x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id218out_result = (id218x_1);
  }
  { // Node ID: 3758 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3758in_input = id218out_result;

    id3758out_output[(getCycle()+1)%2] = id3758in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id204out_output;

  { // Node ID: 204 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id204in_input = id3760out_output[getCycle()%2];

    id204out_output = id204in_input;
  }
  { // Node ID: 3396 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2676out_result;

  { // Node ID: 2676 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2676in_a = id3396out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2676in_b = id120out_o[getCycle()%8];

    id2676out_result = (eq_fixed(id2676in_a,id2676in_b));
  }
  { // Node ID: 3761 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3761in_input = id2676out_result;

    id3761out_output[(getCycle()+2)%3] = id3761in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id203out_o;

  { // Node ID: 203 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id203in_i = id3761out_output[getCycle()%3];

    id203out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id203in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id205out_result;

  { // Node ID: 205 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id205in_a = id204out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id205in_b = id203out_o;

    id205out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id205in_a,id205in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id206out_result;

  { // Node ID: 206 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id206in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id206in_option0 = id205out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id206in_option1 = id203out_o;

    HWOffsetFix<32,0,UNSIGNED> id206x_1;

    switch((id206in_sel.getValueAsLong())) {
      case 0l:
        id206x_1 = id206in_option0;
        break;
      case 1l:
        id206x_1 = id206in_option1;
        break;
      default:
        id206x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id206out_result = (id206x_1);
  }
  { // Node ID: 3760 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3760in_input = id206out_result;

    id3760out_output[(getCycle()+1)%2] = id3760in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id192out_output;

  { // Node ID: 192 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id192in_input = id3762out_output[getCycle()%2];

    id192out_output = id192in_input;
  }
  { // Node ID: 3395 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2677out_result;

  { // Node ID: 2677 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2677in_a = id3395out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2677in_b = id120out_o[getCycle()%8];

    id2677out_result = (eq_fixed(id2677in_a,id2677in_b));
  }
  { // Node ID: 3763 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3763in_input = id2677out_result;

    id3763out_output[(getCycle()+2)%3] = id3763in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id191out_o;

  { // Node ID: 191 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id191in_i = id3763out_output[getCycle()%3];

    id191out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id191in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id193out_result;

  { // Node ID: 193 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id193in_a = id192out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id193in_b = id191out_o;

    id193out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id193in_a,id193in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id194out_result;

  { // Node ID: 194 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id194in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id194in_option0 = id193out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id194in_option1 = id191out_o;

    HWOffsetFix<32,0,UNSIGNED> id194x_1;

    switch((id194in_sel.getValueAsLong())) {
      case 0l:
        id194x_1 = id194in_option0;
        break;
      case 1l:
        id194x_1 = id194in_option1;
        break;
      default:
        id194x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id194out_result = (id194x_1);
  }
  { // Node ID: 3762 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3762in_input = id194out_result;

    id3762out_output[(getCycle()+1)%2] = id3762in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id180out_output;

  { // Node ID: 180 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id180in_input = id3764out_output[getCycle()%2];

    id180out_output = id180in_input;
  }
  { // Node ID: 3394 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2678out_result;

  { // Node ID: 2678 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2678in_a = id3394out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2678in_b = id120out_o[getCycle()%8];

    id2678out_result = (eq_fixed(id2678in_a,id2678in_b));
  }
  { // Node ID: 3765 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3765in_input = id2678out_result;

    id3765out_output[(getCycle()+2)%3] = id3765in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id179out_o;

  { // Node ID: 179 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id179in_i = id3765out_output[getCycle()%3];

    id179out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id179in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id181out_result;

  { // Node ID: 181 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id181in_a = id180out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id181in_b = id179out_o;

    id181out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id181in_a,id181in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id182out_result;

  { // Node ID: 182 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id182in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id182in_option0 = id181out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id182in_option1 = id179out_o;

    HWOffsetFix<32,0,UNSIGNED> id182x_1;

    switch((id182in_sel.getValueAsLong())) {
      case 0l:
        id182x_1 = id182in_option0;
        break;
      case 1l:
        id182x_1 = id182in_option1;
        break;
      default:
        id182x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id182out_result = (id182x_1);
  }
  { // Node ID: 3764 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3764in_input = id182out_result;

    id3764out_output[(getCycle()+1)%2] = id3764in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id168out_output;

  { // Node ID: 168 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id168in_input = id3766out_output[getCycle()%2];

    id168out_output = id168in_input;
  }
  { // Node ID: 3393 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2679out_result;

  { // Node ID: 2679 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2679in_a = id3393out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2679in_b = id120out_o[getCycle()%8];

    id2679out_result = (eq_fixed(id2679in_a,id2679in_b));
  }
  { // Node ID: 3767 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3767in_input = id2679out_result;

    id3767out_output[(getCycle()+2)%3] = id3767in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id167out_o;

  { // Node ID: 167 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id167in_i = id3767out_output[getCycle()%3];

    id167out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id167in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id169out_result;

  { // Node ID: 169 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id169in_a = id168out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id169in_b = id167out_o;

    id169out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id169in_a,id169in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id170out_result;

  { // Node ID: 170 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id170in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id170in_option0 = id169out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id170in_option1 = id167out_o;

    HWOffsetFix<32,0,UNSIGNED> id170x_1;

    switch((id170in_sel.getValueAsLong())) {
      case 0l:
        id170x_1 = id170in_option0;
        break;
      case 1l:
        id170x_1 = id170in_option1;
        break;
      default:
        id170x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id170out_result = (id170x_1);
  }
  { // Node ID: 3766 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3766in_input = id170out_result;

    id3766out_output[(getCycle()+1)%2] = id3766in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id156out_output;

  { // Node ID: 156 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id156in_input = id3768out_output[getCycle()%2];

    id156out_output = id156in_input;
  }
  { // Node ID: 3392 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2680out_result;

  { // Node ID: 2680 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2680in_a = id3392out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2680in_b = id120out_o[getCycle()%8];

    id2680out_result = (eq_fixed(id2680in_a,id2680in_b));
  }
  { // Node ID: 3769 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3769in_input = id2680out_result;

    id3769out_output[(getCycle()+2)%3] = id3769in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id155out_o;

  { // Node ID: 155 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id155in_i = id3769out_output[getCycle()%3];

    id155out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id155in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id157out_result;

  { // Node ID: 157 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id157in_a = id156out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id157in_b = id155out_o;

    id157out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id157in_a,id157in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id158out_result;

  { // Node ID: 158 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id158in_option0 = id157out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id158in_option1 = id155out_o;

    HWOffsetFix<32,0,UNSIGNED> id158x_1;

    switch((id158in_sel.getValueAsLong())) {
      case 0l:
        id158x_1 = id158in_option0;
        break;
      case 1l:
        id158x_1 = id158in_option1;
        break;
      default:
        id158x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id158out_result = (id158x_1);
  }
  { // Node ID: 3768 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3768in_input = id158out_result;

    id3768out_output[(getCycle()+1)%2] = id3768in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id144out_output;

  { // Node ID: 144 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id144in_input = id3770out_output[getCycle()%2];

    id144out_output = id144in_input;
  }
  { // Node ID: 3391 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2681out_result;

  { // Node ID: 2681 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2681in_a = id3391out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2681in_b = id120out_o[getCycle()%8];

    id2681out_result = (eq_fixed(id2681in_a,id2681in_b));
  }
  { // Node ID: 3771 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3771in_input = id2681out_result;

    id3771out_output[(getCycle()+2)%3] = id3771in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id143out_o;

  { // Node ID: 143 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id143in_i = id3771out_output[getCycle()%3];

    id143out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id143in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id145out_result;

  { // Node ID: 145 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id145in_a = id144out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id145in_b = id143out_o;

    id145out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id145in_a,id145in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id146out_result;

  { // Node ID: 146 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id146in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id146in_option0 = id145out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id146in_option1 = id143out_o;

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
    id146out_result = (id146x_1);
  }
  { // Node ID: 3770 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3770in_input = id146out_result;

    id3770out_output[(getCycle()+1)%2] = id3770in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id132out_output;

  { // Node ID: 132 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id132in_input = id3772out_output[getCycle()%2];

    id132out_output = id132in_input;
  }
  { // Node ID: 3390 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2682out_result;

  { // Node ID: 2682 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2682in_a = id3390out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2682in_b = id120out_o[getCycle()%8];

    id2682out_result = (eq_fixed(id2682in_a,id2682in_b));
  }
  { // Node ID: 3773 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3773in_input = id2682out_result;

    id3773out_output[(getCycle()+2)%3] = id3773in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id131out_o;

  { // Node ID: 131 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id131in_i = id3773out_output[getCycle()%3];

    id131out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id131in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id133out_result;

  { // Node ID: 133 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id133in_a = id132out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id133in_b = id131out_o;

    id133out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id133in_a,id133in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id134out_result;

  { // Node ID: 134 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id134in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id134in_option0 = id133out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id134in_option1 = id131out_o;

    HWOffsetFix<32,0,UNSIGNED> id134x_1;

    switch((id134in_sel.getValueAsLong())) {
      case 0l:
        id134x_1 = id134in_option0;
        break;
      case 1l:
        id134x_1 = id134in_option1;
        break;
      default:
        id134x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id134out_result = (id134x_1);
  }
  { // Node ID: 3772 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3772in_input = id134out_result;

    id3772out_output[(getCycle()+1)%2] = id3772in_input;
  }
  { // Node ID: 3775 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3775in_input = id122out_output;

    id3775out_output[(getCycle()+10)%11] = id3775in_input;
  }
  { // Node ID: 3389 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2683out_result;

  { // Node ID: 2683 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2683in_a = id3389out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2683in_b = id3508out_output[getCycle()%2];

    id2683out_result = (eq_fixed(id2683in_a,id2683in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1931out_o;

  { // Node ID: 1931 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1931in_i = id2683out_result;

    id1931out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1931in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1933out_result;

  { // Node ID: 1933 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1933in_a = id3774out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1933in_b = id1931out_o;

    id1933out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1933in_a,id1933in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1934out_result;

  { // Node ID: 1934 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1934in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1934in_option0 = id1933out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1934in_option1 = id1931out_o;

    HWOffsetFix<32,0,UNSIGNED> id1934x_1;

    switch((id1934in_sel.getValueAsLong())) {
      case 0l:
        id1934x_1 = id1934in_option0;
        break;
      case 1l:
        id1934x_1 = id1934in_option1;
        break;
      default:
        id1934x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1934out_result = (id1934x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1932out_output;

  { // Node ID: 1932 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1932in_input = id1934out_result;

    id1932out_output = id1932in_input;
  }
  { // Node ID: 3774 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3774in_input = id1932out_output;

    id3774out_output[(getCycle()+1)%2] = id3774in_input;
  }
  { // Node ID: 3388 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2684out_result;

  { // Node ID: 2684 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2684in_a = id3388out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2684in_b = id3508out_output[getCycle()%2];

    id2684out_result = (eq_fixed(id2684in_a,id2684in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1925out_o;

  { // Node ID: 1925 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1925in_i = id2684out_result;

    id1925out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1925in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1927out_result;

  { // Node ID: 1927 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1927in_a = id3776out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1927in_b = id1925out_o;

    id1927out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1927in_a,id1927in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1928out_result;

  { // Node ID: 1928 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1928in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1928in_option0 = id1927out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1928in_option1 = id1925out_o;

    HWOffsetFix<32,0,UNSIGNED> id1928x_1;

    switch((id1928in_sel.getValueAsLong())) {
      case 0l:
        id1928x_1 = id1928in_option0;
        break;
      case 1l:
        id1928x_1 = id1928in_option1;
        break;
      default:
        id1928x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1928out_result = (id1928x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1926out_output;

  { // Node ID: 1926 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1926in_input = id1928out_result;

    id1926out_output = id1926in_input;
  }
  { // Node ID: 3776 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3776in_input = id1926out_output;

    id3776out_output[(getCycle()+1)%2] = id3776in_input;
  }
  { // Node ID: 3387 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2685out_result;

  { // Node ID: 2685 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2685in_a = id3387out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2685in_b = id3508out_output[getCycle()%2];

    id2685out_result = (eq_fixed(id2685in_a,id2685in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1919out_o;

  { // Node ID: 1919 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1919in_i = id2685out_result;

    id1919out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1919in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1921out_result;

  { // Node ID: 1921 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1921in_a = id3778out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1921in_b = id1919out_o;

    id1921out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1921in_a,id1921in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1922out_result;

  { // Node ID: 1922 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1922in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1922in_option0 = id1921out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1922in_option1 = id1919out_o;

    HWOffsetFix<32,0,UNSIGNED> id1922x_1;

    switch((id1922in_sel.getValueAsLong())) {
      case 0l:
        id1922x_1 = id1922in_option0;
        break;
      case 1l:
        id1922x_1 = id1922in_option1;
        break;
      default:
        id1922x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1922out_result = (id1922x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1920out_output;

  { // Node ID: 1920 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1920in_input = id1922out_result;

    id1920out_output = id1920in_input;
  }
  { // Node ID: 3778 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3778in_input = id1920out_output;

    id3778out_output[(getCycle()+1)%2] = id3778in_input;
  }
  { // Node ID: 3386 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2686out_result;

  { // Node ID: 2686 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2686in_a = id3386out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2686in_b = id3508out_output[getCycle()%2];

    id2686out_result = (eq_fixed(id2686in_a,id2686in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1913out_o;

  { // Node ID: 1913 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1913in_i = id2686out_result;

    id1913out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1913in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1915out_result;

  { // Node ID: 1915 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1915in_a = id3780out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1915in_b = id1913out_o;

    id1915out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1915in_a,id1915in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1916out_result;

  { // Node ID: 1916 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1916in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1916in_option0 = id1915out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1916in_option1 = id1913out_o;

    HWOffsetFix<32,0,UNSIGNED> id1916x_1;

    switch((id1916in_sel.getValueAsLong())) {
      case 0l:
        id1916x_1 = id1916in_option0;
        break;
      case 1l:
        id1916x_1 = id1916in_option1;
        break;
      default:
        id1916x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1916out_result = (id1916x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1914out_output;

  { // Node ID: 1914 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1914in_input = id1916out_result;

    id1914out_output = id1914in_input;
  }
  { // Node ID: 3780 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3780in_input = id1914out_output;

    id3780out_output[(getCycle()+1)%2] = id3780in_input;
  }
  { // Node ID: 3385 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2687out_result;

  { // Node ID: 2687 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2687in_a = id3385out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2687in_b = id3508out_output[getCycle()%2];

    id2687out_result = (eq_fixed(id2687in_a,id2687in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1907out_o;

  { // Node ID: 1907 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1907in_i = id2687out_result;

    id1907out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1907in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1909out_result;

  { // Node ID: 1909 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1909in_a = id3782out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1909in_b = id1907out_o;

    id1909out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1909in_a,id1909in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1910out_result;

  { // Node ID: 1910 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1910in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1910in_option0 = id1909out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1910in_option1 = id1907out_o;

    HWOffsetFix<32,0,UNSIGNED> id1910x_1;

    switch((id1910in_sel.getValueAsLong())) {
      case 0l:
        id1910x_1 = id1910in_option0;
        break;
      case 1l:
        id1910x_1 = id1910in_option1;
        break;
      default:
        id1910x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1910out_result = (id1910x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1908out_output;

  { // Node ID: 1908 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1908in_input = id1910out_result;

    id1908out_output = id1908in_input;
  }
  { // Node ID: 3782 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3782in_input = id1908out_output;

    id3782out_output[(getCycle()+1)%2] = id3782in_input;
  }
  { // Node ID: 3384 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2688out_result;

  { // Node ID: 2688 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2688in_a = id3384out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2688in_b = id3508out_output[getCycle()%2];

    id2688out_result = (eq_fixed(id2688in_a,id2688in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1901out_o;

  { // Node ID: 1901 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1901in_i = id2688out_result;

    id1901out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1901in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1903out_result;

  { // Node ID: 1903 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1903in_a = id3784out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1903in_b = id1901out_o;

    id1903out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1903in_a,id1903in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1904out_result;

  { // Node ID: 1904 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1904in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1904in_option0 = id1903out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1904in_option1 = id1901out_o;

    HWOffsetFix<32,0,UNSIGNED> id1904x_1;

    switch((id1904in_sel.getValueAsLong())) {
      case 0l:
        id1904x_1 = id1904in_option0;
        break;
      case 1l:
        id1904x_1 = id1904in_option1;
        break;
      default:
        id1904x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1904out_result = (id1904x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1902out_output;

  { // Node ID: 1902 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1902in_input = id1904out_result;

    id1902out_output = id1902in_input;
  }
  { // Node ID: 3784 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3784in_input = id1902out_output;

    id3784out_output[(getCycle()+1)%2] = id3784in_input;
  }
  { // Node ID: 3383 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2689out_result;

  { // Node ID: 2689 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2689in_a = id3383out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2689in_b = id3508out_output[getCycle()%2];

    id2689out_result = (eq_fixed(id2689in_a,id2689in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1895out_o;

  { // Node ID: 1895 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1895in_i = id2689out_result;

    id1895out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1895in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1897out_result;

  { // Node ID: 1897 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1897in_a = id3786out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1897in_b = id1895out_o;

    id1897out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1897in_a,id1897in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1898out_result;

  { // Node ID: 1898 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1898in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1898in_option0 = id1897out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1898in_option1 = id1895out_o;

    HWOffsetFix<32,0,UNSIGNED> id1898x_1;

    switch((id1898in_sel.getValueAsLong())) {
      case 0l:
        id1898x_1 = id1898in_option0;
        break;
      case 1l:
        id1898x_1 = id1898in_option1;
        break;
      default:
        id1898x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1898out_result = (id1898x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1896out_output;

  { // Node ID: 1896 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1896in_input = id1898out_result;

    id1896out_output = id1896in_input;
  }
  { // Node ID: 3786 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3786in_input = id1896out_output;

    id3786out_output[(getCycle()+1)%2] = id3786in_input;
  }
  { // Node ID: 3382 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2690out_result;

  { // Node ID: 2690 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2690in_a = id3382out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2690in_b = id3508out_output[getCycle()%2];

    id2690out_result = (eq_fixed(id2690in_a,id2690in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1889out_o;

  { // Node ID: 1889 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1889in_i = id2690out_result;

    id1889out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1889in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1891out_result;

  { // Node ID: 1891 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1891in_a = id3788out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1891in_b = id1889out_o;

    id1891out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1891in_a,id1891in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1892out_result;

  { // Node ID: 1892 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1892in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1892in_option0 = id1891out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1892in_option1 = id1889out_o;

    HWOffsetFix<32,0,UNSIGNED> id1892x_1;

    switch((id1892in_sel.getValueAsLong())) {
      case 0l:
        id1892x_1 = id1892in_option0;
        break;
      case 1l:
        id1892x_1 = id1892in_option1;
        break;
      default:
        id1892x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1892out_result = (id1892x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1890out_output;

  { // Node ID: 1890 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1890in_input = id1892out_result;

    id1890out_output = id1890in_input;
  }
  { // Node ID: 3788 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3788in_input = id1890out_output;

    id3788out_output[(getCycle()+1)%2] = id3788in_input;
  }
  { // Node ID: 3381 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2691out_result;

  { // Node ID: 2691 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2691in_a = id3381out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2691in_b = id3508out_output[getCycle()%2];

    id2691out_result = (eq_fixed(id2691in_a,id2691in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1883out_o;

  { // Node ID: 1883 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1883in_i = id2691out_result;

    id1883out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1883in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1885out_result;

  { // Node ID: 1885 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1885in_a = id3790out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1885in_b = id1883out_o;

    id1885out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1885in_a,id1885in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1886out_result;

  { // Node ID: 1886 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1886in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1886in_option0 = id1885out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1886in_option1 = id1883out_o;

    HWOffsetFix<32,0,UNSIGNED> id1886x_1;

    switch((id1886in_sel.getValueAsLong())) {
      case 0l:
        id1886x_1 = id1886in_option0;
        break;
      case 1l:
        id1886x_1 = id1886in_option1;
        break;
      default:
        id1886x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1886out_result = (id1886x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1884out_output;

  { // Node ID: 1884 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1884in_input = id1886out_result;

    id1884out_output = id1884in_input;
  }
  { // Node ID: 3790 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3790in_input = id1884out_output;

    id3790out_output[(getCycle()+1)%2] = id3790in_input;
  }
  { // Node ID: 3380 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2692out_result;

  { // Node ID: 2692 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2692in_a = id3380out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2692in_b = id3508out_output[getCycle()%2];

    id2692out_result = (eq_fixed(id2692in_a,id2692in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1877out_o;

  { // Node ID: 1877 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1877in_i = id2692out_result;

    id1877out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1877in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1879out_result;

  { // Node ID: 1879 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1879in_a = id3792out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1879in_b = id1877out_o;

    id1879out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1879in_a,id1879in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1880out_result;

  { // Node ID: 1880 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1880in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1880in_option0 = id1879out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1880in_option1 = id1877out_o;

    HWOffsetFix<32,0,UNSIGNED> id1880x_1;

    switch((id1880in_sel.getValueAsLong())) {
      case 0l:
        id1880x_1 = id1880in_option0;
        break;
      case 1l:
        id1880x_1 = id1880in_option1;
        break;
      default:
        id1880x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1880out_result = (id1880x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1878out_output;

  { // Node ID: 1878 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1878in_input = id1880out_result;

    id1878out_output = id1878in_input;
  }
  { // Node ID: 3792 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3792in_input = id1878out_output;

    id3792out_output[(getCycle()+1)%2] = id3792in_input;
  }
  { // Node ID: 3379 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2693out_result;

  { // Node ID: 2693 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2693in_a = id3379out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2693in_b = id3508out_output[getCycle()%2];

    id2693out_result = (eq_fixed(id2693in_a,id2693in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1871out_o;

  { // Node ID: 1871 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1871in_i = id2693out_result;

    id1871out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1871in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1873out_result;

  { // Node ID: 1873 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1873in_a = id3794out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1873in_b = id1871out_o;

    id1873out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1873in_a,id1873in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1874out_result;

  { // Node ID: 1874 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1874in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1874in_option0 = id1873out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1874in_option1 = id1871out_o;

    HWOffsetFix<32,0,UNSIGNED> id1874x_1;

    switch((id1874in_sel.getValueAsLong())) {
      case 0l:
        id1874x_1 = id1874in_option0;
        break;
      case 1l:
        id1874x_1 = id1874in_option1;
        break;
      default:
        id1874x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1874out_result = (id1874x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1872out_output;

  { // Node ID: 1872 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1872in_input = id1874out_result;

    id1872out_output = id1872in_input;
  }
  { // Node ID: 3794 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3794in_input = id1872out_output;

    id3794out_output[(getCycle()+1)%2] = id3794in_input;
  }
  { // Node ID: 3378 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2694out_result;

  { // Node ID: 2694 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2694in_a = id3378out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2694in_b = id3508out_output[getCycle()%2];

    id2694out_result = (eq_fixed(id2694in_a,id2694in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1865out_o;

  { // Node ID: 1865 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1865in_i = id2694out_result;

    id1865out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1865in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1867out_result;

  { // Node ID: 1867 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1867in_a = id3796out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1867in_b = id1865out_o;

    id1867out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1867in_a,id1867in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1868out_result;

  { // Node ID: 1868 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1868in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1868in_option0 = id1867out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1868in_option1 = id1865out_o;

    HWOffsetFix<32,0,UNSIGNED> id1868x_1;

    switch((id1868in_sel.getValueAsLong())) {
      case 0l:
        id1868x_1 = id1868in_option0;
        break;
      case 1l:
        id1868x_1 = id1868in_option1;
        break;
      default:
        id1868x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1868out_result = (id1868x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1866out_output;

  { // Node ID: 1866 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1866in_input = id1868out_result;

    id1866out_output = id1866in_input;
  }
  { // Node ID: 3796 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3796in_input = id1866out_output;

    id3796out_output[(getCycle()+1)%2] = id3796in_input;
  }
  { // Node ID: 3377 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2695out_result;

  { // Node ID: 2695 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2695in_a = id3377out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2695in_b = id3508out_output[getCycle()%2];

    id2695out_result = (eq_fixed(id2695in_a,id2695in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1859out_o;

  { // Node ID: 1859 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1859in_i = id2695out_result;

    id1859out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1859in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1861out_result;

  { // Node ID: 1861 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1861in_a = id3798out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1861in_b = id1859out_o;

    id1861out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1861in_a,id1861in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1862out_result;

  { // Node ID: 1862 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1862in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1862in_option0 = id1861out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1862in_option1 = id1859out_o;

    HWOffsetFix<32,0,UNSIGNED> id1862x_1;

    switch((id1862in_sel.getValueAsLong())) {
      case 0l:
        id1862x_1 = id1862in_option0;
        break;
      case 1l:
        id1862x_1 = id1862in_option1;
        break;
      default:
        id1862x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1862out_result = (id1862x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1860out_output;

  { // Node ID: 1860 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1860in_input = id1862out_result;

    id1860out_output = id1860in_input;
  }
  { // Node ID: 3798 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3798in_input = id1860out_output;

    id3798out_output[(getCycle()+1)%2] = id3798in_input;
  }
  { // Node ID: 3376 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2696out_result;

  { // Node ID: 2696 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2696in_a = id3376out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2696in_b = id3508out_output[getCycle()%2];

    id2696out_result = (eq_fixed(id2696in_a,id2696in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1853out_o;

  { // Node ID: 1853 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1853in_i = id2696out_result;

    id1853out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1853in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1855out_result;

  { // Node ID: 1855 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1855in_a = id3800out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1855in_b = id1853out_o;

    id1855out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1855in_a,id1855in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1856out_result;

  { // Node ID: 1856 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1856in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1856in_option0 = id1855out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1856in_option1 = id1853out_o;

    HWOffsetFix<32,0,UNSIGNED> id1856x_1;

    switch((id1856in_sel.getValueAsLong())) {
      case 0l:
        id1856x_1 = id1856in_option0;
        break;
      case 1l:
        id1856x_1 = id1856in_option1;
        break;
      default:
        id1856x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1856out_result = (id1856x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1854out_output;

  { // Node ID: 1854 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1854in_input = id1856out_result;

    id1854out_output = id1854in_input;
  }
  { // Node ID: 3800 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3800in_input = id1854out_output;

    id3800out_output[(getCycle()+1)%2] = id3800in_input;
  }
  { // Node ID: 3375 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2697out_result;

  { // Node ID: 2697 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2697in_a = id3375out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2697in_b = id3508out_output[getCycle()%2];

    id2697out_result = (eq_fixed(id2697in_a,id2697in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1847out_o;

  { // Node ID: 1847 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1847in_i = id2697out_result;

    id1847out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1847in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1849out_result;

  { // Node ID: 1849 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1849in_a = id3802out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1849in_b = id1847out_o;

    id1849out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1849in_a,id1849in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1850out_result;

  { // Node ID: 1850 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1850in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1850in_option0 = id1849out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1850in_option1 = id1847out_o;

    HWOffsetFix<32,0,UNSIGNED> id1850x_1;

    switch((id1850in_sel.getValueAsLong())) {
      case 0l:
        id1850x_1 = id1850in_option0;
        break;
      case 1l:
        id1850x_1 = id1850in_option1;
        break;
      default:
        id1850x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1850out_result = (id1850x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1848out_output;

  { // Node ID: 1848 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1848in_input = id1850out_result;

    id1848out_output = id1848in_input;
  }
  { // Node ID: 3802 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3802in_input = id1848out_output;

    id3802out_output[(getCycle()+1)%2] = id3802in_input;
  }
  { // Node ID: 3374 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2698out_result;

  { // Node ID: 2698 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2698in_a = id3374out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2698in_b = id3508out_output[getCycle()%2];

    id2698out_result = (eq_fixed(id2698in_a,id2698in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1841out_o;

  { // Node ID: 1841 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1841in_i = id2698out_result;

    id1841out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1841in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1843out_result;

  { // Node ID: 1843 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1843in_a = id3804out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1843in_b = id1841out_o;

    id1843out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1843in_a,id1843in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1844out_result;

  { // Node ID: 1844 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1844in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1844in_option0 = id1843out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1844in_option1 = id1841out_o;

    HWOffsetFix<32,0,UNSIGNED> id1844x_1;

    switch((id1844in_sel.getValueAsLong())) {
      case 0l:
        id1844x_1 = id1844in_option0;
        break;
      case 1l:
        id1844x_1 = id1844in_option1;
        break;
      default:
        id1844x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1844out_result = (id1844x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1842out_output;

  { // Node ID: 1842 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1842in_input = id1844out_result;

    id1842out_output = id1842in_input;
  }
  { // Node ID: 3804 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3804in_input = id1842out_output;

    id3804out_output[(getCycle()+1)%2] = id3804in_input;
  }
  { // Node ID: 3373 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2699out_result;

  { // Node ID: 2699 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2699in_a = id3373out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2699in_b = id3508out_output[getCycle()%2];

    id2699out_result = (eq_fixed(id2699in_a,id2699in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1835out_o;

  { // Node ID: 1835 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1835in_i = id2699out_result;

    id1835out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1835in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1837out_result;

  { // Node ID: 1837 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1837in_a = id3806out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1837in_b = id1835out_o;

    id1837out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1837in_a,id1837in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1838out_result;

  { // Node ID: 1838 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1838in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1838in_option0 = id1837out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1838in_option1 = id1835out_o;

    HWOffsetFix<32,0,UNSIGNED> id1838x_1;

    switch((id1838in_sel.getValueAsLong())) {
      case 0l:
        id1838x_1 = id1838in_option0;
        break;
      case 1l:
        id1838x_1 = id1838in_option1;
        break;
      default:
        id1838x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1838out_result = (id1838x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1836out_output;

  { // Node ID: 1836 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1836in_input = id1838out_result;

    id1836out_output = id1836in_input;
  }
  { // Node ID: 3806 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3806in_input = id1836out_output;

    id3806out_output[(getCycle()+1)%2] = id3806in_input;
  }
  { // Node ID: 3372 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2700out_result;

  { // Node ID: 2700 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2700in_a = id3372out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2700in_b = id3508out_output[getCycle()%2];

    id2700out_result = (eq_fixed(id2700in_a,id2700in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1829out_o;

  { // Node ID: 1829 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1829in_i = id2700out_result;

    id1829out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1829in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1831out_result;

  { // Node ID: 1831 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1831in_a = id3808out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1831in_b = id1829out_o;

    id1831out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1831in_a,id1831in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1832out_result;

  { // Node ID: 1832 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1832in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1832in_option0 = id1831out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1832in_option1 = id1829out_o;

    HWOffsetFix<32,0,UNSIGNED> id1832x_1;

    switch((id1832in_sel.getValueAsLong())) {
      case 0l:
        id1832x_1 = id1832in_option0;
        break;
      case 1l:
        id1832x_1 = id1832in_option1;
        break;
      default:
        id1832x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1832out_result = (id1832x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1830out_output;

  { // Node ID: 1830 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1830in_input = id1832out_result;

    id1830out_output = id1830in_input;
  }
  { // Node ID: 3808 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3808in_input = id1830out_output;

    id3808out_output[(getCycle()+1)%2] = id3808in_input;
  }
  { // Node ID: 3371 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2701out_result;

  { // Node ID: 2701 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2701in_a = id3371out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2701in_b = id3508out_output[getCycle()%2];

    id2701out_result = (eq_fixed(id2701in_a,id2701in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1823out_o;

  { // Node ID: 1823 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1823in_i = id2701out_result;

    id1823out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1823in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1825out_result;

  { // Node ID: 1825 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1825in_a = id3810out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1825in_b = id1823out_o;

    id1825out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1825in_a,id1825in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1826out_result;

  { // Node ID: 1826 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1826in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1826in_option0 = id1825out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1826in_option1 = id1823out_o;

    HWOffsetFix<32,0,UNSIGNED> id1826x_1;

    switch((id1826in_sel.getValueAsLong())) {
      case 0l:
        id1826x_1 = id1826in_option0;
        break;
      case 1l:
        id1826x_1 = id1826in_option1;
        break;
      default:
        id1826x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1826out_result = (id1826x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1824out_output;

  { // Node ID: 1824 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1824in_input = id1826out_result;

    id1824out_output = id1824in_input;
  }
  { // Node ID: 3810 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3810in_input = id1824out_output;

    id3810out_output[(getCycle()+1)%2] = id3810in_input;
  }
  { // Node ID: 3370 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2702out_result;

  { // Node ID: 2702 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2702in_a = id3370out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2702in_b = id3508out_output[getCycle()%2];

    id2702out_result = (eq_fixed(id2702in_a,id2702in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1817out_o;

  { // Node ID: 1817 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1817in_i = id2702out_result;

    id1817out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1817in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1819out_result;

  { // Node ID: 1819 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1819in_a = id3812out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1819in_b = id1817out_o;

    id1819out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1819in_a,id1819in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1820out_result;

  { // Node ID: 1820 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1820in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1820in_option0 = id1819out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1820in_option1 = id1817out_o;

    HWOffsetFix<32,0,UNSIGNED> id1820x_1;

    switch((id1820in_sel.getValueAsLong())) {
      case 0l:
        id1820x_1 = id1820in_option0;
        break;
      case 1l:
        id1820x_1 = id1820in_option1;
        break;
      default:
        id1820x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1820out_result = (id1820x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1818out_output;

  { // Node ID: 1818 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1818in_input = id1820out_result;

    id1818out_output = id1818in_input;
  }
  { // Node ID: 3812 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3812in_input = id1818out_output;

    id3812out_output[(getCycle()+1)%2] = id3812in_input;
  }
  { // Node ID: 3369 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2703out_result;

  { // Node ID: 2703 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2703in_a = id3369out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2703in_b = id3508out_output[getCycle()%2];

    id2703out_result = (eq_fixed(id2703in_a,id2703in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1811out_o;

  { // Node ID: 1811 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1811in_i = id2703out_result;

    id1811out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1811in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1813out_result;

  { // Node ID: 1813 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1813in_a = id3814out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1813in_b = id1811out_o;

    id1813out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1813in_a,id1813in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1814out_result;

  { // Node ID: 1814 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1814in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1814in_option0 = id1813out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1814in_option1 = id1811out_o;

    HWOffsetFix<32,0,UNSIGNED> id1814x_1;

    switch((id1814in_sel.getValueAsLong())) {
      case 0l:
        id1814x_1 = id1814in_option0;
        break;
      case 1l:
        id1814x_1 = id1814in_option1;
        break;
      default:
        id1814x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1814out_result = (id1814x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1812out_output;

  { // Node ID: 1812 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1812in_input = id1814out_result;

    id1812out_output = id1812in_input;
  }
  { // Node ID: 3814 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3814in_input = id1812out_output;

    id3814out_output[(getCycle()+1)%2] = id3814in_input;
  }
  { // Node ID: 3368 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2704out_result;

  { // Node ID: 2704 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2704in_a = id3368out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2704in_b = id3508out_output[getCycle()%2];

    id2704out_result = (eq_fixed(id2704in_a,id2704in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1805out_o;

  { // Node ID: 1805 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1805in_i = id2704out_result;

    id1805out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1805in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1807out_result;

  { // Node ID: 1807 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1807in_a = id3816out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1807in_b = id1805out_o;

    id1807out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1807in_a,id1807in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1808out_result;

  { // Node ID: 1808 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1808in_sel = id3775out_output[getCycle()%11];
    const HWOffsetFix<32,0,UNSIGNED> &id1808in_option0 = id1807out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1808in_option1 = id1805out_o;

    HWOffsetFix<32,0,UNSIGNED> id1808x_1;

    switch((id1808in_sel.getValueAsLong())) {
      case 0l:
        id1808x_1 = id1808in_option0;
        break;
      case 1l:
        id1808x_1 = id1808in_option1;
        break;
      default:
        id1808x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1808out_result = (id1808x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1806out_output;

  { // Node ID: 1806 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1806in_input = id1808out_result;

    id1806out_output = id1806in_input;
  }
  { // Node ID: 3816 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3816in_input = id1806out_output;

    id3816out_output[(getCycle()+1)%2] = id3816in_input;
  }
  { // Node ID: 3837 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3837in_input = id3522out_output[getCycle()%2];

    id3837out_output[(getCycle()+8)%9] = id3837in_input;
  }
  { // Node ID: 4541 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4541in_input = id3837out_output[getCycle()%9];

    id4541out_output[(getCycle()+1)%2] = id4541in_input;
  }
  { // Node ID: 3367 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2705out_result;

  { // Node ID: 2705 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2705in_a = id3367out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2705in_b = id3508out_output[getCycle()%2];

    id2705out_result = (eq_fixed(id2705in_a,id2705in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1799out_o;

  { // Node ID: 1799 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1799in_i = id2705out_result;

    id1799out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1799in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1801out_result;

  { // Node ID: 1801 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1801in_a = id3818out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1801in_b = id1799out_o;

    id1801out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1801in_a,id1801in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1802out_result;

  { // Node ID: 1802 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1802in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1802in_option0 = id1801out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1802in_option1 = id1799out_o;

    HWOffsetFix<32,0,UNSIGNED> id1802x_1;

    switch((id1802in_sel.getValueAsLong())) {
      case 0l:
        id1802x_1 = id1802in_option0;
        break;
      case 1l:
        id1802x_1 = id1802in_option1;
        break;
      default:
        id1802x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1802out_result = (id1802x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1800out_output;

  { // Node ID: 1800 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1800in_input = id1802out_result;

    id1800out_output = id1800in_input;
  }
  { // Node ID: 3818 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3818in_input = id1800out_output;

    id3818out_output[(getCycle()+1)%2] = id3818in_input;
  }
  { // Node ID: 3366 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2706out_result;

  { // Node ID: 2706 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2706in_a = id3366out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2706in_b = id3508out_output[getCycle()%2];

    id2706out_result = (eq_fixed(id2706in_a,id2706in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1793out_o;

  { // Node ID: 1793 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1793in_i = id2706out_result;

    id1793out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1793in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1795out_result;

  { // Node ID: 1795 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1795in_a = id3820out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1795in_b = id1793out_o;

    id1795out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1795in_a,id1795in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1796out_result;

  { // Node ID: 1796 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1796in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1796in_option0 = id1795out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1796in_option1 = id1793out_o;

    HWOffsetFix<32,0,UNSIGNED> id1796x_1;

    switch((id1796in_sel.getValueAsLong())) {
      case 0l:
        id1796x_1 = id1796in_option0;
        break;
      case 1l:
        id1796x_1 = id1796in_option1;
        break;
      default:
        id1796x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1796out_result = (id1796x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1794out_output;

  { // Node ID: 1794 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1794in_input = id1796out_result;

    id1794out_output = id1794in_input;
  }
  { // Node ID: 3820 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3820in_input = id1794out_output;

    id3820out_output[(getCycle()+1)%2] = id3820in_input;
  }
  { // Node ID: 3365 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2707out_result;

  { // Node ID: 2707 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2707in_a = id3365out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2707in_b = id3508out_output[getCycle()%2];

    id2707out_result = (eq_fixed(id2707in_a,id2707in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1787out_o;

  { // Node ID: 1787 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1787in_i = id2707out_result;

    id1787out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1787in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1789out_result;

  { // Node ID: 1789 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1789in_a = id3822out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1789in_b = id1787out_o;

    id1789out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1789in_a,id1789in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1790out_result;

  { // Node ID: 1790 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1790in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1790in_option0 = id1789out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1790in_option1 = id1787out_o;

    HWOffsetFix<32,0,UNSIGNED> id1790x_1;

    switch((id1790in_sel.getValueAsLong())) {
      case 0l:
        id1790x_1 = id1790in_option0;
        break;
      case 1l:
        id1790x_1 = id1790in_option1;
        break;
      default:
        id1790x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1790out_result = (id1790x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1788out_output;

  { // Node ID: 1788 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1788in_input = id1790out_result;

    id1788out_output = id1788in_input;
  }
  { // Node ID: 3822 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3822in_input = id1788out_output;

    id3822out_output[(getCycle()+1)%2] = id3822in_input;
  }
  { // Node ID: 3364 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2708out_result;

  { // Node ID: 2708 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2708in_a = id3364out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2708in_b = id3508out_output[getCycle()%2];

    id2708out_result = (eq_fixed(id2708in_a,id2708in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1781out_o;

  { // Node ID: 1781 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1781in_i = id2708out_result;

    id1781out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1781in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1783out_result;

  { // Node ID: 1783 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1783in_a = id3824out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1783in_b = id1781out_o;

    id1783out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1783in_a,id1783in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1784out_result;

  { // Node ID: 1784 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1784in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1784in_option0 = id1783out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1784in_option1 = id1781out_o;

    HWOffsetFix<32,0,UNSIGNED> id1784x_1;

    switch((id1784in_sel.getValueAsLong())) {
      case 0l:
        id1784x_1 = id1784in_option0;
        break;
      case 1l:
        id1784x_1 = id1784in_option1;
        break;
      default:
        id1784x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1784out_result = (id1784x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1782out_output;

  { // Node ID: 1782 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1782in_input = id1784out_result;

    id1782out_output = id1782in_input;
  }
  { // Node ID: 3824 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3824in_input = id1782out_output;

    id3824out_output[(getCycle()+1)%2] = id3824in_input;
  }
  { // Node ID: 3363 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2709out_result;

  { // Node ID: 2709 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2709in_a = id3363out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2709in_b = id3508out_output[getCycle()%2];

    id2709out_result = (eq_fixed(id2709in_a,id2709in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1775out_o;

  { // Node ID: 1775 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1775in_i = id2709out_result;

    id1775out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1775in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1777out_result;

  { // Node ID: 1777 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1777in_a = id3826out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1777in_b = id1775out_o;

    id1777out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1777in_a,id1777in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1778out_result;

  { // Node ID: 1778 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1778in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1778in_option0 = id1777out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1778in_option1 = id1775out_o;

    HWOffsetFix<32,0,UNSIGNED> id1778x_1;

    switch((id1778in_sel.getValueAsLong())) {
      case 0l:
        id1778x_1 = id1778in_option0;
        break;
      case 1l:
        id1778x_1 = id1778in_option1;
        break;
      default:
        id1778x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1778out_result = (id1778x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1776out_output;

  { // Node ID: 1776 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1776in_input = id1778out_result;

    id1776out_output = id1776in_input;
  }
  { // Node ID: 3826 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3826in_input = id1776out_output;

    id3826out_output[(getCycle()+1)%2] = id3826in_input;
  }
  { // Node ID: 3362 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2710out_result;

  { // Node ID: 2710 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2710in_a = id3362out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2710in_b = id3508out_output[getCycle()%2];

    id2710out_result = (eq_fixed(id2710in_a,id2710in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1769out_o;

  { // Node ID: 1769 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1769in_i = id2710out_result;

    id1769out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1769in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1771out_result;

  { // Node ID: 1771 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1771in_a = id3828out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1771in_b = id1769out_o;

    id1771out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1771in_a,id1771in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1772out_result;

  { // Node ID: 1772 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1772in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1772in_option0 = id1771out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1772in_option1 = id1769out_o;

    HWOffsetFix<32,0,UNSIGNED> id1772x_1;

    switch((id1772in_sel.getValueAsLong())) {
      case 0l:
        id1772x_1 = id1772in_option0;
        break;
      case 1l:
        id1772x_1 = id1772in_option1;
        break;
      default:
        id1772x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1772out_result = (id1772x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1770out_output;

  { // Node ID: 1770 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1770in_input = id1772out_result;

    id1770out_output = id1770in_input;
  }
  { // Node ID: 3828 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3828in_input = id1770out_output;

    id3828out_output[(getCycle()+1)%2] = id3828in_input;
  }
  { // Node ID: 3361 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2711out_result;

  { // Node ID: 2711 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2711in_a = id3361out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2711in_b = id3508out_output[getCycle()%2];

    id2711out_result = (eq_fixed(id2711in_a,id2711in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1763out_o;

  { // Node ID: 1763 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1763in_i = id2711out_result;

    id1763out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1763in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1765out_result;

  { // Node ID: 1765 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1765in_a = id3830out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1765in_b = id1763out_o;

    id1765out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1765in_a,id1765in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1766out_result;

  { // Node ID: 1766 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1766in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1766in_option0 = id1765out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1766in_option1 = id1763out_o;

    HWOffsetFix<32,0,UNSIGNED> id1766x_1;

    switch((id1766in_sel.getValueAsLong())) {
      case 0l:
        id1766x_1 = id1766in_option0;
        break;
      case 1l:
        id1766x_1 = id1766in_option1;
        break;
      default:
        id1766x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1766out_result = (id1766x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1764out_output;

  { // Node ID: 1764 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1764in_input = id1766out_result;

    id1764out_output = id1764in_input;
  }
  { // Node ID: 3830 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3830in_input = id1764out_output;

    id3830out_output[(getCycle()+1)%2] = id3830in_input;
  }
  { // Node ID: 3360 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2712out_result;

  { // Node ID: 2712 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2712in_a = id3360out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2712in_b = id3508out_output[getCycle()%2];

    id2712out_result = (eq_fixed(id2712in_a,id2712in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1757out_o;

  { // Node ID: 1757 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1757in_i = id2712out_result;

    id1757out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1757in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1759out_result;

  { // Node ID: 1759 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1759in_a = id3832out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1759in_b = id1757out_o;

    id1759out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1759in_a,id1759in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1760out_result;

  { // Node ID: 1760 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1760in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1760in_option0 = id1759out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1760in_option1 = id1757out_o;

    HWOffsetFix<32,0,UNSIGNED> id1760x_1;

    switch((id1760in_sel.getValueAsLong())) {
      case 0l:
        id1760x_1 = id1760in_option0;
        break;
      case 1l:
        id1760x_1 = id1760in_option1;
        break;
      default:
        id1760x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1760out_result = (id1760x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1758out_output;

  { // Node ID: 1758 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1758in_input = id1760out_result;

    id1758out_output = id1758in_input;
  }
  { // Node ID: 3832 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3832in_input = id1758out_output;

    id3832out_output[(getCycle()+1)%2] = id3832in_input;
  }
  { // Node ID: 3359 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2713out_result;

  { // Node ID: 2713 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2713in_a = id3359out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2713in_b = id3508out_output[getCycle()%2];

    id2713out_result = (eq_fixed(id2713in_a,id2713in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1751out_o;

  { // Node ID: 1751 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1751in_i = id2713out_result;

    id1751out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1751in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1753out_result;

  { // Node ID: 1753 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1753in_a = id3834out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1753in_b = id1751out_o;

    id1753out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1753in_a,id1753in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1754out_result;

  { // Node ID: 1754 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1754in_sel = id4541out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1754in_option0 = id1753out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1754in_option1 = id1751out_o;

    HWOffsetFix<32,0,UNSIGNED> id1754x_1;

    switch((id1754in_sel.getValueAsLong())) {
      case 0l:
        id1754x_1 = id1754in_option0;
        break;
      case 1l:
        id1754x_1 = id1754in_option1;
        break;
      default:
        id1754x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1754out_result = (id1754x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id1752out_output;

  { // Node ID: 1752 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1752in_input = id1754out_result;

    id1752out_output = id1752in_input;
  }
  { // Node ID: 3834 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3834in_input = id1752out_output;

    id3834out_output[(getCycle()+1)%2] = id3834in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1746out_output;

  { // Node ID: 1746 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1746in_input = id3836out_output[getCycle()%2];

    id1746out_output = id1746in_input;
  }
  { // Node ID: 3358 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2714out_result;

  { // Node ID: 2714 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2714in_a = id3358out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2714in_b = id3509out_output[getCycle()%2];

    id2714out_result = (eq_fixed(id2714in_a,id2714in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1745out_o;

  { // Node ID: 1745 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1745in_i = id2714out_result;

    id1745out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1745in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1747out_result;

  { // Node ID: 1747 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1747in_a = id1746out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1747in_b = id1745out_o;

    id1747out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1747in_a,id1747in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1748out_result;

  { // Node ID: 1748 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1748in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1748in_option0 = id1747out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1748in_option1 = id1745out_o;

    HWOffsetFix<32,0,UNSIGNED> id1748x_1;

    switch((id1748in_sel.getValueAsLong())) {
      case 0l:
        id1748x_1 = id1748in_option0;
        break;
      case 1l:
        id1748x_1 = id1748in_option1;
        break;
      default:
        id1748x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1748out_result = (id1748x_1);
  }
  { // Node ID: 3836 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3836in_input = id1748out_result;

    id3836out_output[(getCycle()+1)%2] = id3836in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1740out_output;

  { // Node ID: 1740 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1740in_input = id3838out_output[getCycle()%2];

    id1740out_output = id1740in_input;
  }
  { // Node ID: 3357 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2715out_result;

  { // Node ID: 2715 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2715in_a = id3357out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2715in_b = id3509out_output[getCycle()%2];

    id2715out_result = (eq_fixed(id2715in_a,id2715in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1739out_o;

  { // Node ID: 1739 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1739in_i = id2715out_result;

    id1739out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1739in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1741out_result;

  { // Node ID: 1741 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1741in_a = id1740out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1741in_b = id1739out_o;

    id1741out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1741in_a,id1741in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1742out_result;

  { // Node ID: 1742 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1742in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1742in_option0 = id1741out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1742in_option1 = id1739out_o;

    HWOffsetFix<32,0,UNSIGNED> id1742x_1;

    switch((id1742in_sel.getValueAsLong())) {
      case 0l:
        id1742x_1 = id1742in_option0;
        break;
      case 1l:
        id1742x_1 = id1742in_option1;
        break;
      default:
        id1742x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1742out_result = (id1742x_1);
  }
  { // Node ID: 3838 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3838in_input = id1742out_result;

    id3838out_output[(getCycle()+1)%2] = id3838in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1734out_output;

  { // Node ID: 1734 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1734in_input = id3840out_output[getCycle()%2];

    id1734out_output = id1734in_input;
  }
  { // Node ID: 3356 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2716out_result;

  { // Node ID: 2716 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2716in_a = id3356out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2716in_b = id3509out_output[getCycle()%2];

    id2716out_result = (eq_fixed(id2716in_a,id2716in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1733out_o;

  { // Node ID: 1733 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1733in_i = id2716out_result;

    id1733out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1733in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1735out_result;

  { // Node ID: 1735 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1735in_a = id1734out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1735in_b = id1733out_o;

    id1735out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1735in_a,id1735in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1736out_result;

  { // Node ID: 1736 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1736in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1736in_option0 = id1735out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1736in_option1 = id1733out_o;

    HWOffsetFix<32,0,UNSIGNED> id1736x_1;

    switch((id1736in_sel.getValueAsLong())) {
      case 0l:
        id1736x_1 = id1736in_option0;
        break;
      case 1l:
        id1736x_1 = id1736in_option1;
        break;
      default:
        id1736x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1736out_result = (id1736x_1);
  }
  { // Node ID: 3840 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3840in_input = id1736out_result;

    id3840out_output[(getCycle()+1)%2] = id3840in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1728out_output;

  { // Node ID: 1728 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1728in_input = id3842out_output[getCycle()%2];

    id1728out_output = id1728in_input;
  }
  { // Node ID: 3355 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2717out_result;

  { // Node ID: 2717 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2717in_a = id3355out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2717in_b = id3509out_output[getCycle()%2];

    id2717out_result = (eq_fixed(id2717in_a,id2717in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1727out_o;

  { // Node ID: 1727 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1727in_i = id2717out_result;

    id1727out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1727in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1729out_result;

  { // Node ID: 1729 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1729in_a = id1728out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1729in_b = id1727out_o;

    id1729out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1729in_a,id1729in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1730out_result;

  { // Node ID: 1730 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1730in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1730in_option0 = id1729out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1730in_option1 = id1727out_o;

    HWOffsetFix<32,0,UNSIGNED> id1730x_1;

    switch((id1730in_sel.getValueAsLong())) {
      case 0l:
        id1730x_1 = id1730in_option0;
        break;
      case 1l:
        id1730x_1 = id1730in_option1;
        break;
      default:
        id1730x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1730out_result = (id1730x_1);
  }
  { // Node ID: 3842 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3842in_input = id1730out_result;

    id3842out_output[(getCycle()+1)%2] = id3842in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1722out_output;

  { // Node ID: 1722 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1722in_input = id3844out_output[getCycle()%2];

    id1722out_output = id1722in_input;
  }
  { // Node ID: 3354 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2718out_result;

  { // Node ID: 2718 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2718in_a = id3354out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2718in_b = id3509out_output[getCycle()%2];

    id2718out_result = (eq_fixed(id2718in_a,id2718in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1721out_o;

  { // Node ID: 1721 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1721in_i = id2718out_result;

    id1721out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1721in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1723out_result;

  { // Node ID: 1723 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1723in_a = id1722out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1723in_b = id1721out_o;

    id1723out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1723in_a,id1723in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1724out_result;

  { // Node ID: 1724 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1724in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1724in_option0 = id1723out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1724in_option1 = id1721out_o;

    HWOffsetFix<32,0,UNSIGNED> id1724x_1;

    switch((id1724in_sel.getValueAsLong())) {
      case 0l:
        id1724x_1 = id1724in_option0;
        break;
      case 1l:
        id1724x_1 = id1724in_option1;
        break;
      default:
        id1724x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1724out_result = (id1724x_1);
  }
  { // Node ID: 3844 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3844in_input = id1724out_result;

    id3844out_output[(getCycle()+1)%2] = id3844in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1716out_output;

  { // Node ID: 1716 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1716in_input = id3846out_output[getCycle()%2];

    id1716out_output = id1716in_input;
  }
  { // Node ID: 3353 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2719out_result;

  { // Node ID: 2719 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2719in_a = id3353out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2719in_b = id3509out_output[getCycle()%2];

    id2719out_result = (eq_fixed(id2719in_a,id2719in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1715out_o;

  { // Node ID: 1715 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1715in_i = id2719out_result;

    id1715out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1715in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1717out_result;

  { // Node ID: 1717 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1717in_a = id1716out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1717in_b = id1715out_o;

    id1717out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1717in_a,id1717in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1718out_result;

  { // Node ID: 1718 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1718in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1718in_option0 = id1717out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1718in_option1 = id1715out_o;

    HWOffsetFix<32,0,UNSIGNED> id1718x_1;

    switch((id1718in_sel.getValueAsLong())) {
      case 0l:
        id1718x_1 = id1718in_option0;
        break;
      case 1l:
        id1718x_1 = id1718in_option1;
        break;
      default:
        id1718x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1718out_result = (id1718x_1);
  }
  { // Node ID: 3846 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3846in_input = id1718out_result;

    id3846out_output[(getCycle()+1)%2] = id3846in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1710out_output;

  { // Node ID: 1710 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1710in_input = id3848out_output[getCycle()%2];

    id1710out_output = id1710in_input;
  }
  { // Node ID: 3352 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2720out_result;

  { // Node ID: 2720 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2720in_a = id3352out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2720in_b = id3509out_output[getCycle()%2];

    id2720out_result = (eq_fixed(id2720in_a,id2720in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1709out_o;

  { // Node ID: 1709 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1709in_i = id2720out_result;

    id1709out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1709in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1711out_result;

  { // Node ID: 1711 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1711in_a = id1710out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1711in_b = id1709out_o;

    id1711out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1711in_a,id1711in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1712out_result;

  { // Node ID: 1712 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1712in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1712in_option0 = id1711out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1712in_option1 = id1709out_o;

    HWOffsetFix<32,0,UNSIGNED> id1712x_1;

    switch((id1712in_sel.getValueAsLong())) {
      case 0l:
        id1712x_1 = id1712in_option0;
        break;
      case 1l:
        id1712x_1 = id1712in_option1;
        break;
      default:
        id1712x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1712out_result = (id1712x_1);
  }
  { // Node ID: 3848 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3848in_input = id1712out_result;

    id3848out_output[(getCycle()+1)%2] = id3848in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1704out_output;

  { // Node ID: 1704 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1704in_input = id3850out_output[getCycle()%2];

    id1704out_output = id1704in_input;
  }
  { // Node ID: 3351 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2721out_result;

  { // Node ID: 2721 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2721in_a = id3351out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2721in_b = id3509out_output[getCycle()%2];

    id2721out_result = (eq_fixed(id2721in_a,id2721in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1703out_o;

  { // Node ID: 1703 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1703in_i = id2721out_result;

    id1703out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1703in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1705out_result;

  { // Node ID: 1705 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1705in_a = id1704out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1705in_b = id1703out_o;

    id1705out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1705in_a,id1705in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1706out_result;

  { // Node ID: 1706 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1706in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1706in_option0 = id1705out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1706in_option1 = id1703out_o;

    HWOffsetFix<32,0,UNSIGNED> id1706x_1;

    switch((id1706in_sel.getValueAsLong())) {
      case 0l:
        id1706x_1 = id1706in_option0;
        break;
      case 1l:
        id1706x_1 = id1706in_option1;
        break;
      default:
        id1706x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1706out_result = (id1706x_1);
  }
  { // Node ID: 3850 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3850in_input = id1706out_result;

    id3850out_output[(getCycle()+1)%2] = id3850in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1698out_output;

  { // Node ID: 1698 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1698in_input = id3852out_output[getCycle()%2];

    id1698out_output = id1698in_input;
  }
  { // Node ID: 3350 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2722out_result;

  { // Node ID: 2722 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2722in_a = id3350out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2722in_b = id3509out_output[getCycle()%2];

    id2722out_result = (eq_fixed(id2722in_a,id2722in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1697out_o;

  { // Node ID: 1697 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1697in_i = id2722out_result;

    id1697out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1697in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1699out_result;

  { // Node ID: 1699 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1699in_a = id1698out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1699in_b = id1697out_o;

    id1699out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1699in_a,id1699in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1700out_result;

  { // Node ID: 1700 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1700in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1700in_option0 = id1699out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1700in_option1 = id1697out_o;

    HWOffsetFix<32,0,UNSIGNED> id1700x_1;

    switch((id1700in_sel.getValueAsLong())) {
      case 0l:
        id1700x_1 = id1700in_option0;
        break;
      case 1l:
        id1700x_1 = id1700in_option1;
        break;
      default:
        id1700x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1700out_result = (id1700x_1);
  }
  { // Node ID: 3852 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3852in_input = id1700out_result;

    id3852out_output[(getCycle()+1)%2] = id3852in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1692out_output;

  { // Node ID: 1692 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1692in_input = id3854out_output[getCycle()%2];

    id1692out_output = id1692in_input;
  }
  { // Node ID: 3349 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2723out_result;

  { // Node ID: 2723 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2723in_a = id3349out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2723in_b = id3509out_output[getCycle()%2];

    id2723out_result = (eq_fixed(id2723in_a,id2723in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1691out_o;

  { // Node ID: 1691 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1691in_i = id2723out_result;

    id1691out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1691in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1693out_result;

  { // Node ID: 1693 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1693in_a = id1692out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1693in_b = id1691out_o;

    id1693out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1693in_a,id1693in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1694out_result;

  { // Node ID: 1694 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1694in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1694in_option0 = id1693out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1694in_option1 = id1691out_o;

    HWOffsetFix<32,0,UNSIGNED> id1694x_1;

    switch((id1694in_sel.getValueAsLong())) {
      case 0l:
        id1694x_1 = id1694in_option0;
        break;
      case 1l:
        id1694x_1 = id1694in_option1;
        break;
      default:
        id1694x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1694out_result = (id1694x_1);
  }
  { // Node ID: 3854 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3854in_input = id1694out_result;

    id3854out_output[(getCycle()+1)%2] = id3854in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1686out_output;

  { // Node ID: 1686 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1686in_input = id3856out_output[getCycle()%2];

    id1686out_output = id1686in_input;
  }
  { // Node ID: 3348 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2724out_result;

  { // Node ID: 2724 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2724in_a = id3348out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2724in_b = id3509out_output[getCycle()%2];

    id2724out_result = (eq_fixed(id2724in_a,id2724in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1685out_o;

  { // Node ID: 1685 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1685in_i = id2724out_result;

    id1685out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1685in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1687out_result;

  { // Node ID: 1687 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1687in_a = id1686out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1687in_b = id1685out_o;

    id1687out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1687in_a,id1687in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1688out_result;

  { // Node ID: 1688 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1688in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1688in_option0 = id1687out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1688in_option1 = id1685out_o;

    HWOffsetFix<32,0,UNSIGNED> id1688x_1;

    switch((id1688in_sel.getValueAsLong())) {
      case 0l:
        id1688x_1 = id1688in_option0;
        break;
      case 1l:
        id1688x_1 = id1688in_option1;
        break;
      default:
        id1688x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1688out_result = (id1688x_1);
  }
  { // Node ID: 3856 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3856in_input = id1688out_result;

    id3856out_output[(getCycle()+1)%2] = id3856in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1680out_output;

  { // Node ID: 1680 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1680in_input = id3858out_output[getCycle()%2];

    id1680out_output = id1680in_input;
  }
  { // Node ID: 3347 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2725out_result;

  { // Node ID: 2725 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2725in_a = id3347out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2725in_b = id3509out_output[getCycle()%2];

    id2725out_result = (eq_fixed(id2725in_a,id2725in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1679out_o;

  { // Node ID: 1679 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1679in_i = id2725out_result;

    id1679out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1679in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1681out_result;

  { // Node ID: 1681 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1681in_a = id1680out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1681in_b = id1679out_o;

    id1681out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1681in_a,id1681in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1682out_result;

  { // Node ID: 1682 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1682in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1682in_option0 = id1681out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1682in_option1 = id1679out_o;

    HWOffsetFix<32,0,UNSIGNED> id1682x_1;

    switch((id1682in_sel.getValueAsLong())) {
      case 0l:
        id1682x_1 = id1682in_option0;
        break;
      case 1l:
        id1682x_1 = id1682in_option1;
        break;
      default:
        id1682x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1682out_result = (id1682x_1);
  }
  { // Node ID: 3858 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3858in_input = id1682out_result;

    id3858out_output[(getCycle()+1)%2] = id3858in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1674out_output;

  { // Node ID: 1674 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1674in_input = id3860out_output[getCycle()%2];

    id1674out_output = id1674in_input;
  }
  { // Node ID: 3346 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2726out_result;

  { // Node ID: 2726 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2726in_a = id3346out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2726in_b = id3509out_output[getCycle()%2];

    id2726out_result = (eq_fixed(id2726in_a,id2726in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1673out_o;

  { // Node ID: 1673 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1673in_i = id2726out_result;

    id1673out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1673in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1675out_result;

  { // Node ID: 1675 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1675in_a = id1674out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1675in_b = id1673out_o;

    id1675out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1675in_a,id1675in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1676out_result;

  { // Node ID: 1676 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1676in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1676in_option0 = id1675out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1676in_option1 = id1673out_o;

    HWOffsetFix<32,0,UNSIGNED> id1676x_1;

    switch((id1676in_sel.getValueAsLong())) {
      case 0l:
        id1676x_1 = id1676in_option0;
        break;
      case 1l:
        id1676x_1 = id1676in_option1;
        break;
      default:
        id1676x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1676out_result = (id1676x_1);
  }
  { // Node ID: 3860 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3860in_input = id1676out_result;

    id3860out_output[(getCycle()+1)%2] = id3860in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1668out_output;

  { // Node ID: 1668 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1668in_input = id3862out_output[getCycle()%2];

    id1668out_output = id1668in_input;
  }
  { // Node ID: 3345 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2727out_result;

  { // Node ID: 2727 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2727in_a = id3345out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2727in_b = id3509out_output[getCycle()%2];

    id2727out_result = (eq_fixed(id2727in_a,id2727in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1667out_o;

  { // Node ID: 1667 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1667in_i = id2727out_result;

    id1667out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1667in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1669out_result;

  { // Node ID: 1669 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1669in_a = id1668out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1669in_b = id1667out_o;

    id1669out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1669in_a,id1669in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1670out_result;

  { // Node ID: 1670 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1670in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1670in_option0 = id1669out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1670in_option1 = id1667out_o;

    HWOffsetFix<32,0,UNSIGNED> id1670x_1;

    switch((id1670in_sel.getValueAsLong())) {
      case 0l:
        id1670x_1 = id1670in_option0;
        break;
      case 1l:
        id1670x_1 = id1670in_option1;
        break;
      default:
        id1670x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1670out_result = (id1670x_1);
  }
  { // Node ID: 3862 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3862in_input = id1670out_result;

    id3862out_output[(getCycle()+1)%2] = id3862in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1662out_output;

  { // Node ID: 1662 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1662in_input = id3864out_output[getCycle()%2];

    id1662out_output = id1662in_input;
  }
  { // Node ID: 3344 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2728out_result;

  { // Node ID: 2728 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2728in_a = id3344out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2728in_b = id3509out_output[getCycle()%2];

    id2728out_result = (eq_fixed(id2728in_a,id2728in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1661out_o;

  { // Node ID: 1661 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1661in_i = id2728out_result;

    id1661out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1661in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1663out_result;

  { // Node ID: 1663 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1663in_a = id1662out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1663in_b = id1661out_o;

    id1663out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1663in_a,id1663in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1664out_result;

  { // Node ID: 1664 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1664in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1664in_option0 = id1663out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1664in_option1 = id1661out_o;

    HWOffsetFix<32,0,UNSIGNED> id1664x_1;

    switch((id1664in_sel.getValueAsLong())) {
      case 0l:
        id1664x_1 = id1664in_option0;
        break;
      case 1l:
        id1664x_1 = id1664in_option1;
        break;
      default:
        id1664x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1664out_result = (id1664x_1);
  }
  { // Node ID: 3864 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3864in_input = id1664out_result;

    id3864out_output[(getCycle()+1)%2] = id3864in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1656out_output;

  { // Node ID: 1656 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1656in_input = id3866out_output[getCycle()%2];

    id1656out_output = id1656in_input;
  }
  { // Node ID: 3343 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2729out_result;

  { // Node ID: 2729 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2729in_a = id3343out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2729in_b = id3509out_output[getCycle()%2];

    id2729out_result = (eq_fixed(id2729in_a,id2729in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1655out_o;

  { // Node ID: 1655 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1655in_i = id2729out_result;

    id1655out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1655in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1657out_result;

  { // Node ID: 1657 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1657in_a = id1656out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1657in_b = id1655out_o;

    id1657out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1657in_a,id1657in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1658out_result;

  { // Node ID: 1658 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1658in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1658in_option0 = id1657out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1658in_option1 = id1655out_o;

    HWOffsetFix<32,0,UNSIGNED> id1658x_1;

    switch((id1658in_sel.getValueAsLong())) {
      case 0l:
        id1658x_1 = id1658in_option0;
        break;
      case 1l:
        id1658x_1 = id1658in_option1;
        break;
      default:
        id1658x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1658out_result = (id1658x_1);
  }
  { // Node ID: 3866 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3866in_input = id1658out_result;

    id3866out_output[(getCycle()+1)%2] = id3866in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1650out_output;

  { // Node ID: 1650 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1650in_input = id3868out_output[getCycle()%2];

    id1650out_output = id1650in_input;
  }
  { // Node ID: 3342 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2730out_result;

  { // Node ID: 2730 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2730in_a = id3342out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2730in_b = id3509out_output[getCycle()%2];

    id2730out_result = (eq_fixed(id2730in_a,id2730in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1649out_o;

  { // Node ID: 1649 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1649in_i = id2730out_result;

    id1649out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1649in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1651out_result;

  { // Node ID: 1651 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1651in_a = id1650out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1651in_b = id1649out_o;

    id1651out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1651in_a,id1651in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1652out_result;

  { // Node ID: 1652 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1652in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1652in_option0 = id1651out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1652in_option1 = id1649out_o;

    HWOffsetFix<32,0,UNSIGNED> id1652x_1;

    switch((id1652in_sel.getValueAsLong())) {
      case 0l:
        id1652x_1 = id1652in_option0;
        break;
      case 1l:
        id1652x_1 = id1652in_option1;
        break;
      default:
        id1652x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1652out_result = (id1652x_1);
  }
  { // Node ID: 3868 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3868in_input = id1652out_result;

    id3868out_output[(getCycle()+1)%2] = id3868in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1644out_output;

  { // Node ID: 1644 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1644in_input = id3870out_output[getCycle()%2];

    id1644out_output = id1644in_input;
  }
  { // Node ID: 3341 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2731out_result;

  { // Node ID: 2731 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2731in_a = id3341out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2731in_b = id3509out_output[getCycle()%2];

    id2731out_result = (eq_fixed(id2731in_a,id2731in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1643out_o;

  { // Node ID: 1643 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1643in_i = id2731out_result;

    id1643out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1643in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1645out_result;

  { // Node ID: 1645 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1645in_a = id1644out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1645in_b = id1643out_o;

    id1645out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1645in_a,id1645in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1646out_result;

  { // Node ID: 1646 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1646in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1646in_option0 = id1645out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1646in_option1 = id1643out_o;

    HWOffsetFix<32,0,UNSIGNED> id1646x_1;

    switch((id1646in_sel.getValueAsLong())) {
      case 0l:
        id1646x_1 = id1646in_option0;
        break;
      case 1l:
        id1646x_1 = id1646in_option1;
        break;
      default:
        id1646x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1646out_result = (id1646x_1);
  }
  { // Node ID: 3870 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3870in_input = id1646out_result;

    id3870out_output[(getCycle()+1)%2] = id3870in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1638out_output;

  { // Node ID: 1638 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1638in_input = id3872out_output[getCycle()%2];

    id1638out_output = id1638in_input;
  }
  { // Node ID: 3340 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2732out_result;

  { // Node ID: 2732 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2732in_a = id3340out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2732in_b = id3509out_output[getCycle()%2];

    id2732out_result = (eq_fixed(id2732in_a,id2732in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1637out_o;

  { // Node ID: 1637 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1637in_i = id2732out_result;

    id1637out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1637in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1639out_result;

  { // Node ID: 1639 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1639in_a = id1638out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1639in_b = id1637out_o;

    id1639out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1639in_a,id1639in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1640out_result;

  { // Node ID: 1640 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1640in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1640in_option0 = id1639out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1640in_option1 = id1637out_o;

    HWOffsetFix<32,0,UNSIGNED> id1640x_1;

    switch((id1640in_sel.getValueAsLong())) {
      case 0l:
        id1640x_1 = id1640in_option0;
        break;
      case 1l:
        id1640x_1 = id1640in_option1;
        break;
      default:
        id1640x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1640out_result = (id1640x_1);
  }
  { // Node ID: 3872 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3872in_input = id1640out_result;

    id3872out_output[(getCycle()+1)%2] = id3872in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1632out_output;

  { // Node ID: 1632 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1632in_input = id3874out_output[getCycle()%2];

    id1632out_output = id1632in_input;
  }
  { // Node ID: 3339 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2733out_result;

  { // Node ID: 2733 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2733in_a = id3339out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2733in_b = id3509out_output[getCycle()%2];

    id2733out_result = (eq_fixed(id2733in_a,id2733in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1631out_o;

  { // Node ID: 1631 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1631in_i = id2733out_result;

    id1631out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1631in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1633out_result;

  { // Node ID: 1633 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1633in_a = id1632out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1633in_b = id1631out_o;

    id1633out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1633in_a,id1633in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1634out_result;

  { // Node ID: 1634 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1634in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1634in_option0 = id1633out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1634in_option1 = id1631out_o;

    HWOffsetFix<32,0,UNSIGNED> id1634x_1;

    switch((id1634in_sel.getValueAsLong())) {
      case 0l:
        id1634x_1 = id1634in_option0;
        break;
      case 1l:
        id1634x_1 = id1634in_option1;
        break;
      default:
        id1634x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1634out_result = (id1634x_1);
  }
  { // Node ID: 3874 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3874in_input = id1634out_result;

    id3874out_output[(getCycle()+1)%2] = id3874in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1626out_output;

  { // Node ID: 1626 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1626in_input = id3876out_output[getCycle()%2];

    id1626out_output = id1626in_input;
  }
  { // Node ID: 3338 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2734out_result;

  { // Node ID: 2734 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2734in_a = id3338out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2734in_b = id3509out_output[getCycle()%2];

    id2734out_result = (eq_fixed(id2734in_a,id2734in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1625out_o;

  { // Node ID: 1625 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1625in_i = id2734out_result;

    id1625out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1625in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1627out_result;

  { // Node ID: 1627 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1627in_a = id1626out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1627in_b = id1625out_o;

    id1627out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1627in_a,id1627in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1628out_result;

  { // Node ID: 1628 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1628in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1628in_option0 = id1627out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1628in_option1 = id1625out_o;

    HWOffsetFix<32,0,UNSIGNED> id1628x_1;

    switch((id1628in_sel.getValueAsLong())) {
      case 0l:
        id1628x_1 = id1628in_option0;
        break;
      case 1l:
        id1628x_1 = id1628in_option1;
        break;
      default:
        id1628x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1628out_result = (id1628x_1);
  }
  { // Node ID: 3876 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3876in_input = id1628out_result;

    id3876out_output[(getCycle()+1)%2] = id3876in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1620out_output;

  { // Node ID: 1620 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1620in_input = id3878out_output[getCycle()%2];

    id1620out_output = id1620in_input;
  }
  { // Node ID: 3337 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2735out_result;

  { // Node ID: 2735 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2735in_a = id3337out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2735in_b = id3509out_output[getCycle()%2];

    id2735out_result = (eq_fixed(id2735in_a,id2735in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1619out_o;

  { // Node ID: 1619 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1619in_i = id2735out_result;

    id1619out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1619in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1621out_result;

  { // Node ID: 1621 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1621in_a = id1620out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1621in_b = id1619out_o;

    id1621out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1621in_a,id1621in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1622out_result;

  { // Node ID: 1622 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1622in_sel = id3837out_output[getCycle()%9];
    const HWOffsetFix<32,0,UNSIGNED> &id1622in_option0 = id1621out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1622in_option1 = id1619out_o;

    HWOffsetFix<32,0,UNSIGNED> id1622x_1;

    switch((id1622in_sel.getValueAsLong())) {
      case 0l:
        id1622x_1 = id1622in_option0;
        break;
      case 1l:
        id1622x_1 = id1622in_option1;
        break;
      default:
        id1622x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1622out_result = (id1622x_1);
  }
  { // Node ID: 3878 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3878in_input = id1622out_result;

    id3878out_output[(getCycle()+1)%2] = id3878in_input;
  }
  { // Node ID: 3881 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3881in_input = id3521out_output[getCycle()%2];

    id3881out_output[(getCycle()+7)%8] = id3881in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1614out_output;

  { // Node ID: 1614 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1614in_input = id3880out_output[getCycle()%2];

    id1614out_output = id1614in_input;
  }
  { // Node ID: 3336 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2736out_result;

  { // Node ID: 2736 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2736in_a = id3336out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2736in_b = id3509out_output[getCycle()%2];

    id2736out_result = (eq_fixed(id2736in_a,id2736in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1613out_o;

  { // Node ID: 1613 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1613in_i = id2736out_result;

    id1613out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1613in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1615out_result;

  { // Node ID: 1615 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1615in_a = id1614out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1615in_b = id1613out_o;

    id1615out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1615in_a,id1615in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1616out_result;

  { // Node ID: 1616 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1616in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1616in_option0 = id1615out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1616in_option1 = id1613out_o;

    HWOffsetFix<32,0,UNSIGNED> id1616x_1;

    switch((id1616in_sel.getValueAsLong())) {
      case 0l:
        id1616x_1 = id1616in_option0;
        break;
      case 1l:
        id1616x_1 = id1616in_option1;
        break;
      default:
        id1616x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1616out_result = (id1616x_1);
  }
  { // Node ID: 3880 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3880in_input = id1616out_result;

    id3880out_output[(getCycle()+1)%2] = id3880in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1608out_output;

  { // Node ID: 1608 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1608in_input = id3882out_output[getCycle()%2];

    id1608out_output = id1608in_input;
  }
  { // Node ID: 3335 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2737out_result;

  { // Node ID: 2737 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2737in_a = id3335out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2737in_b = id3509out_output[getCycle()%2];

    id2737out_result = (eq_fixed(id2737in_a,id2737in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1607out_o;

  { // Node ID: 1607 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1607in_i = id2737out_result;

    id1607out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1607in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1609out_result;

  { // Node ID: 1609 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1609in_a = id1608out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1609in_b = id1607out_o;

    id1609out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1609in_a,id1609in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1610out_result;

  { // Node ID: 1610 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1610in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1610in_option0 = id1609out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1610in_option1 = id1607out_o;

    HWOffsetFix<32,0,UNSIGNED> id1610x_1;

    switch((id1610in_sel.getValueAsLong())) {
      case 0l:
        id1610x_1 = id1610in_option0;
        break;
      case 1l:
        id1610x_1 = id1610in_option1;
        break;
      default:
        id1610x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1610out_result = (id1610x_1);
  }
  { // Node ID: 3882 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3882in_input = id1610out_result;

    id3882out_output[(getCycle()+1)%2] = id3882in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1602out_output;

  { // Node ID: 1602 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1602in_input = id3884out_output[getCycle()%2];

    id1602out_output = id1602in_input;
  }
  { // Node ID: 3334 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2738out_result;

  { // Node ID: 2738 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2738in_a = id3334out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2738in_b = id3509out_output[getCycle()%2];

    id2738out_result = (eq_fixed(id2738in_a,id2738in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1601out_o;

  { // Node ID: 1601 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1601in_i = id2738out_result;

    id1601out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1601in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1603out_result;

  { // Node ID: 1603 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1603in_a = id1602out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1603in_b = id1601out_o;

    id1603out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1603in_a,id1603in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1604out_result;

  { // Node ID: 1604 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1604in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1604in_option0 = id1603out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1604in_option1 = id1601out_o;

    HWOffsetFix<32,0,UNSIGNED> id1604x_1;

    switch((id1604in_sel.getValueAsLong())) {
      case 0l:
        id1604x_1 = id1604in_option0;
        break;
      case 1l:
        id1604x_1 = id1604in_option1;
        break;
      default:
        id1604x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1604out_result = (id1604x_1);
  }
  { // Node ID: 3884 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3884in_input = id1604out_result;

    id3884out_output[(getCycle()+1)%2] = id3884in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1596out_output;

  { // Node ID: 1596 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1596in_input = id3886out_output[getCycle()%2];

    id1596out_output = id1596in_input;
  }
  { // Node ID: 3333 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2739out_result;

  { // Node ID: 2739 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2739in_a = id3333out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2739in_b = id3509out_output[getCycle()%2];

    id2739out_result = (eq_fixed(id2739in_a,id2739in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1595out_o;

  { // Node ID: 1595 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1595in_i = id2739out_result;

    id1595out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1595in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1597out_result;

  { // Node ID: 1597 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1597in_a = id1596out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1597in_b = id1595out_o;

    id1597out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1597in_a,id1597in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1598out_result;

  { // Node ID: 1598 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1598in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1598in_option0 = id1597out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1598in_option1 = id1595out_o;

    HWOffsetFix<32,0,UNSIGNED> id1598x_1;

    switch((id1598in_sel.getValueAsLong())) {
      case 0l:
        id1598x_1 = id1598in_option0;
        break;
      case 1l:
        id1598x_1 = id1598in_option1;
        break;
      default:
        id1598x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1598out_result = (id1598x_1);
  }
  { // Node ID: 3886 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3886in_input = id1598out_result;

    id3886out_output[(getCycle()+1)%2] = id3886in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1590out_output;

  { // Node ID: 1590 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1590in_input = id3888out_output[getCycle()%2];

    id1590out_output = id1590in_input;
  }
  { // Node ID: 3332 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2740out_result;

  { // Node ID: 2740 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2740in_a = id3332out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2740in_b = id3509out_output[getCycle()%2];

    id2740out_result = (eq_fixed(id2740in_a,id2740in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1589out_o;

  { // Node ID: 1589 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1589in_i = id2740out_result;

    id1589out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1589in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1591out_result;

  { // Node ID: 1591 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1591in_a = id1590out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1591in_b = id1589out_o;

    id1591out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1591in_a,id1591in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1592out_result;

  { // Node ID: 1592 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1592in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1592in_option0 = id1591out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1592in_option1 = id1589out_o;

    HWOffsetFix<32,0,UNSIGNED> id1592x_1;

    switch((id1592in_sel.getValueAsLong())) {
      case 0l:
        id1592x_1 = id1592in_option0;
        break;
      case 1l:
        id1592x_1 = id1592in_option1;
        break;
      default:
        id1592x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1592out_result = (id1592x_1);
  }
  { // Node ID: 3888 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3888in_input = id1592out_result;

    id3888out_output[(getCycle()+1)%2] = id3888in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1584out_output;

  { // Node ID: 1584 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1584in_input = id3890out_output[getCycle()%2];

    id1584out_output = id1584in_input;
  }
  { // Node ID: 3331 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2741out_result;

  { // Node ID: 2741 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2741in_a = id3331out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2741in_b = id3509out_output[getCycle()%2];

    id2741out_result = (eq_fixed(id2741in_a,id2741in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1583out_o;

  { // Node ID: 1583 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1583in_i = id2741out_result;

    id1583out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1583in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1585out_result;

  { // Node ID: 1585 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1585in_a = id1584out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1585in_b = id1583out_o;

    id1585out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1585in_a,id1585in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1586out_result;

  { // Node ID: 1586 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1586in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1586in_option0 = id1585out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1586in_option1 = id1583out_o;

    HWOffsetFix<32,0,UNSIGNED> id1586x_1;

    switch((id1586in_sel.getValueAsLong())) {
      case 0l:
        id1586x_1 = id1586in_option0;
        break;
      case 1l:
        id1586x_1 = id1586in_option1;
        break;
      default:
        id1586x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1586out_result = (id1586x_1);
  }
  { // Node ID: 3890 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3890in_input = id1586out_result;

    id3890out_output[(getCycle()+1)%2] = id3890in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1578out_output;

  { // Node ID: 1578 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1578in_input = id3892out_output[getCycle()%2];

    id1578out_output = id1578in_input;
  }
  { // Node ID: 3330 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2742out_result;

  { // Node ID: 2742 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2742in_a = id3330out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2742in_b = id3509out_output[getCycle()%2];

    id2742out_result = (eq_fixed(id2742in_a,id2742in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1577out_o;

  { // Node ID: 1577 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1577in_i = id2742out_result;

    id1577out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1577in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1579out_result;

  { // Node ID: 1579 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1579in_a = id1578out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1579in_b = id1577out_o;

    id1579out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1579in_a,id1579in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1580out_result;

  { // Node ID: 1580 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1580in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1580in_option0 = id1579out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1580in_option1 = id1577out_o;

    HWOffsetFix<32,0,UNSIGNED> id1580x_1;

    switch((id1580in_sel.getValueAsLong())) {
      case 0l:
        id1580x_1 = id1580in_option0;
        break;
      case 1l:
        id1580x_1 = id1580in_option1;
        break;
      default:
        id1580x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1580out_result = (id1580x_1);
  }
  { // Node ID: 3892 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3892in_input = id1580out_result;

    id3892out_output[(getCycle()+1)%2] = id3892in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1572out_output;

  { // Node ID: 1572 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1572in_input = id3894out_output[getCycle()%2];

    id1572out_output = id1572in_input;
  }
  { // Node ID: 3329 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2743out_result;

  { // Node ID: 2743 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2743in_a = id3329out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2743in_b = id3509out_output[getCycle()%2];

    id2743out_result = (eq_fixed(id2743in_a,id2743in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1571out_o;

  { // Node ID: 1571 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1571in_i = id2743out_result;

    id1571out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1571in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1573out_result;

  { // Node ID: 1573 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1573in_a = id1572out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1573in_b = id1571out_o;

    id1573out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1573in_a,id1573in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1574out_result;

  { // Node ID: 1574 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1574in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1574in_option0 = id1573out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1574in_option1 = id1571out_o;

    HWOffsetFix<32,0,UNSIGNED> id1574x_1;

    switch((id1574in_sel.getValueAsLong())) {
      case 0l:
        id1574x_1 = id1574in_option0;
        break;
      case 1l:
        id1574x_1 = id1574in_option1;
        break;
      default:
        id1574x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1574out_result = (id1574x_1);
  }
  { // Node ID: 3894 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3894in_input = id1574out_result;

    id3894out_output[(getCycle()+1)%2] = id3894in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1566out_output;

  { // Node ID: 1566 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1566in_input = id3896out_output[getCycle()%2];

    id1566out_output = id1566in_input;
  }
  { // Node ID: 3328 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2744out_result;

  { // Node ID: 2744 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2744in_a = id3328out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2744in_b = id3509out_output[getCycle()%2];

    id2744out_result = (eq_fixed(id2744in_a,id2744in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1565out_o;

  { // Node ID: 1565 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1565in_i = id2744out_result;

    id1565out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1565in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1567out_result;

  { // Node ID: 1567 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1567in_a = id1566out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1567in_b = id1565out_o;

    id1567out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1567in_a,id1567in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1568out_result;

  { // Node ID: 1568 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1568in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1568in_option0 = id1567out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1568in_option1 = id1565out_o;

    HWOffsetFix<32,0,UNSIGNED> id1568x_1;

    switch((id1568in_sel.getValueAsLong())) {
      case 0l:
        id1568x_1 = id1568in_option0;
        break;
      case 1l:
        id1568x_1 = id1568in_option1;
        break;
      default:
        id1568x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1568out_result = (id1568x_1);
  }
  { // Node ID: 3896 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3896in_input = id1568out_result;

    id3896out_output[(getCycle()+1)%2] = id3896in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1560out_output;

  { // Node ID: 1560 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1560in_input = id3898out_output[getCycle()%2];

    id1560out_output = id1560in_input;
  }
  { // Node ID: 3327 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2745out_result;

  { // Node ID: 2745 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2745in_a = id3327out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2745in_b = id3510out_output[getCycle()%2];

    id2745out_result = (eq_fixed(id2745in_a,id2745in_b));
  }
  { // Node ID: 3899 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3899in_input = id2745out_result;

    id3899out_output[(getCycle()+1)%2] = id3899in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1559out_o;

  { // Node ID: 1559 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1559in_i = id3899out_output[getCycle()%2];

    id1559out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1559in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1561out_result;

  { // Node ID: 1561 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1561in_a = id1560out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1561in_b = id1559out_o;

    id1561out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1561in_a,id1561in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1562out_result;

  { // Node ID: 1562 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1562in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1562in_option0 = id1561out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1562in_option1 = id1559out_o;

    HWOffsetFix<32,0,UNSIGNED> id1562x_1;

    switch((id1562in_sel.getValueAsLong())) {
      case 0l:
        id1562x_1 = id1562in_option0;
        break;
      case 1l:
        id1562x_1 = id1562in_option1;
        break;
      default:
        id1562x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1562out_result = (id1562x_1);
  }
  { // Node ID: 3898 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3898in_input = id1562out_result;

    id3898out_output[(getCycle()+1)%2] = id3898in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1554out_output;

  { // Node ID: 1554 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1554in_input = id3901out_output[getCycle()%2];

    id1554out_output = id1554in_input;
  }
  { // Node ID: 3326 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2746out_result;

  { // Node ID: 2746 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2746in_a = id3326out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2746in_b = id3510out_output[getCycle()%2];

    id2746out_result = (eq_fixed(id2746in_a,id2746in_b));
  }
  { // Node ID: 3902 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3902in_input = id2746out_result;

    id3902out_output[(getCycle()+1)%2] = id3902in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1553out_o;

  { // Node ID: 1553 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1553in_i = id3902out_output[getCycle()%2];

    id1553out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1553in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1555out_result;

  { // Node ID: 1555 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1555in_a = id1554out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1555in_b = id1553out_o;

    id1555out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1555in_a,id1555in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1556out_result;

  { // Node ID: 1556 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1556in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1556in_option0 = id1555out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1556in_option1 = id1553out_o;

    HWOffsetFix<32,0,UNSIGNED> id1556x_1;

    switch((id1556in_sel.getValueAsLong())) {
      case 0l:
        id1556x_1 = id1556in_option0;
        break;
      case 1l:
        id1556x_1 = id1556in_option1;
        break;
      default:
        id1556x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1556out_result = (id1556x_1);
  }
  { // Node ID: 3901 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3901in_input = id1556out_result;

    id3901out_output[(getCycle()+1)%2] = id3901in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1548out_output;

  { // Node ID: 1548 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1548in_input = id3904out_output[getCycle()%2];

    id1548out_output = id1548in_input;
  }
  { // Node ID: 3325 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2747out_result;

  { // Node ID: 2747 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2747in_a = id3325out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2747in_b = id3510out_output[getCycle()%2];

    id2747out_result = (eq_fixed(id2747in_a,id2747in_b));
  }
  { // Node ID: 3905 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3905in_input = id2747out_result;

    id3905out_output[(getCycle()+1)%2] = id3905in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1547out_o;

  { // Node ID: 1547 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1547in_i = id3905out_output[getCycle()%2];

    id1547out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1547in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1549out_result;

  { // Node ID: 1549 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1549in_a = id1548out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1549in_b = id1547out_o;

    id1549out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1549in_a,id1549in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1550out_result;

  { // Node ID: 1550 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1550in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1550in_option0 = id1549out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1550in_option1 = id1547out_o;

    HWOffsetFix<32,0,UNSIGNED> id1550x_1;

    switch((id1550in_sel.getValueAsLong())) {
      case 0l:
        id1550x_1 = id1550in_option0;
        break;
      case 1l:
        id1550x_1 = id1550in_option1;
        break;
      default:
        id1550x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1550out_result = (id1550x_1);
  }
  { // Node ID: 3904 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3904in_input = id1550out_result;

    id3904out_output[(getCycle()+1)%2] = id3904in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1542out_output;

  { // Node ID: 1542 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1542in_input = id3907out_output[getCycle()%2];

    id1542out_output = id1542in_input;
  }
  { // Node ID: 3324 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2748out_result;

  { // Node ID: 2748 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2748in_a = id3324out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2748in_b = id3510out_output[getCycle()%2];

    id2748out_result = (eq_fixed(id2748in_a,id2748in_b));
  }
  { // Node ID: 3908 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3908in_input = id2748out_result;

    id3908out_output[(getCycle()+1)%2] = id3908in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1541out_o;

  { // Node ID: 1541 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1541in_i = id3908out_output[getCycle()%2];

    id1541out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1541in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1543out_result;

  { // Node ID: 1543 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1543in_a = id1542out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1543in_b = id1541out_o;

    id1543out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1543in_a,id1543in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1544out_result;

  { // Node ID: 1544 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1544in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1544in_option0 = id1543out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1544in_option1 = id1541out_o;

    HWOffsetFix<32,0,UNSIGNED> id1544x_1;

    switch((id1544in_sel.getValueAsLong())) {
      case 0l:
        id1544x_1 = id1544in_option0;
        break;
      case 1l:
        id1544x_1 = id1544in_option1;
        break;
      default:
        id1544x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1544out_result = (id1544x_1);
  }
  { // Node ID: 3907 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3907in_input = id1544out_result;

    id3907out_output[(getCycle()+1)%2] = id3907in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1536out_output;

  { // Node ID: 1536 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1536in_input = id3910out_output[getCycle()%2];

    id1536out_output = id1536in_input;
  }
  { // Node ID: 3323 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2749out_result;

  { // Node ID: 2749 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2749in_a = id3323out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2749in_b = id3510out_output[getCycle()%2];

    id2749out_result = (eq_fixed(id2749in_a,id2749in_b));
  }
  { // Node ID: 3911 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3911in_input = id2749out_result;

    id3911out_output[(getCycle()+1)%2] = id3911in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1535out_o;

  { // Node ID: 1535 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1535in_i = id3911out_output[getCycle()%2];

    id1535out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1535in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1537out_result;

  { // Node ID: 1537 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1537in_a = id1536out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1537in_b = id1535out_o;

    id1537out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1537in_a,id1537in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1538out_result;

  { // Node ID: 1538 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1538in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1538in_option0 = id1537out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1538in_option1 = id1535out_o;

    HWOffsetFix<32,0,UNSIGNED> id1538x_1;

    switch((id1538in_sel.getValueAsLong())) {
      case 0l:
        id1538x_1 = id1538in_option0;
        break;
      case 1l:
        id1538x_1 = id1538in_option1;
        break;
      default:
        id1538x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1538out_result = (id1538x_1);
  }
  { // Node ID: 3910 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3910in_input = id1538out_result;

    id3910out_output[(getCycle()+1)%2] = id3910in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1530out_output;

  { // Node ID: 1530 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1530in_input = id3913out_output[getCycle()%2];

    id1530out_output = id1530in_input;
  }
  { // Node ID: 3322 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2750out_result;

  { // Node ID: 2750 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2750in_a = id3322out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2750in_b = id3510out_output[getCycle()%2];

    id2750out_result = (eq_fixed(id2750in_a,id2750in_b));
  }
  { // Node ID: 3914 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3914in_input = id2750out_result;

    id3914out_output[(getCycle()+1)%2] = id3914in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1529out_o;

  { // Node ID: 1529 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1529in_i = id3914out_output[getCycle()%2];

    id1529out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1529in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1531out_result;

  { // Node ID: 1531 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1531in_a = id1530out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1531in_b = id1529out_o;

    id1531out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1531in_a,id1531in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1532out_result;

  { // Node ID: 1532 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1532in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1532in_option0 = id1531out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1532in_option1 = id1529out_o;

    HWOffsetFix<32,0,UNSIGNED> id1532x_1;

    switch((id1532in_sel.getValueAsLong())) {
      case 0l:
        id1532x_1 = id1532in_option0;
        break;
      case 1l:
        id1532x_1 = id1532in_option1;
        break;
      default:
        id1532x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1532out_result = (id1532x_1);
  }
  { // Node ID: 3913 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3913in_input = id1532out_result;

    id3913out_output[(getCycle()+1)%2] = id3913in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1524out_output;

  { // Node ID: 1524 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1524in_input = id3916out_output[getCycle()%2];

    id1524out_output = id1524in_input;
  }
  { // Node ID: 3321 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2751out_result;

  { // Node ID: 2751 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2751in_a = id3321out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2751in_b = id3510out_output[getCycle()%2];

    id2751out_result = (eq_fixed(id2751in_a,id2751in_b));
  }
  { // Node ID: 3917 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3917in_input = id2751out_result;

    id3917out_output[(getCycle()+1)%2] = id3917in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1523out_o;

  { // Node ID: 1523 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1523in_i = id3917out_output[getCycle()%2];

    id1523out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1523in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1525out_result;

  { // Node ID: 1525 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1525in_a = id1524out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1525in_b = id1523out_o;

    id1525out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1525in_a,id1525in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1526out_result;

  { // Node ID: 1526 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1526in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1526in_option0 = id1525out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1526in_option1 = id1523out_o;

    HWOffsetFix<32,0,UNSIGNED> id1526x_1;

    switch((id1526in_sel.getValueAsLong())) {
      case 0l:
        id1526x_1 = id1526in_option0;
        break;
      case 1l:
        id1526x_1 = id1526in_option1;
        break;
      default:
        id1526x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1526out_result = (id1526x_1);
  }
  { // Node ID: 3916 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3916in_input = id1526out_result;

    id3916out_output[(getCycle()+1)%2] = id3916in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1518out_output;

  { // Node ID: 1518 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1518in_input = id3919out_output[getCycle()%2];

    id1518out_output = id1518in_input;
  }
  { // Node ID: 3320 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2752out_result;

  { // Node ID: 2752 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2752in_a = id3320out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2752in_b = id3510out_output[getCycle()%2];

    id2752out_result = (eq_fixed(id2752in_a,id2752in_b));
  }
  { // Node ID: 3920 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3920in_input = id2752out_result;

    id3920out_output[(getCycle()+1)%2] = id3920in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1517out_o;

  { // Node ID: 1517 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1517in_i = id3920out_output[getCycle()%2];

    id1517out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1517in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1519out_result;

  { // Node ID: 1519 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1519in_a = id1518out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1519in_b = id1517out_o;

    id1519out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1519in_a,id1519in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1520out_result;

  { // Node ID: 1520 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1520in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1520in_option0 = id1519out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1520in_option1 = id1517out_o;

    HWOffsetFix<32,0,UNSIGNED> id1520x_1;

    switch((id1520in_sel.getValueAsLong())) {
      case 0l:
        id1520x_1 = id1520in_option0;
        break;
      case 1l:
        id1520x_1 = id1520in_option1;
        break;
      default:
        id1520x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1520out_result = (id1520x_1);
  }
  { // Node ID: 3919 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3919in_input = id1520out_result;

    id3919out_output[(getCycle()+1)%2] = id3919in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1512out_output;

  { // Node ID: 1512 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1512in_input = id3922out_output[getCycle()%2];

    id1512out_output = id1512in_input;
  }
  { // Node ID: 3319 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2753out_result;

  { // Node ID: 2753 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2753in_a = id3319out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2753in_b = id3510out_output[getCycle()%2];

    id2753out_result = (eq_fixed(id2753in_a,id2753in_b));
  }
  { // Node ID: 3923 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3923in_input = id2753out_result;

    id3923out_output[(getCycle()+1)%2] = id3923in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1511out_o;

  { // Node ID: 1511 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1511in_i = id3923out_output[getCycle()%2];

    id1511out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1511in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1513out_result;

  { // Node ID: 1513 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1513in_a = id1512out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1513in_b = id1511out_o;

    id1513out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1513in_a,id1513in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1514out_result;

  { // Node ID: 1514 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1514in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1514in_option0 = id1513out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1514in_option1 = id1511out_o;

    HWOffsetFix<32,0,UNSIGNED> id1514x_1;

    switch((id1514in_sel.getValueAsLong())) {
      case 0l:
        id1514x_1 = id1514in_option0;
        break;
      case 1l:
        id1514x_1 = id1514in_option1;
        break;
      default:
        id1514x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1514out_result = (id1514x_1);
  }
  { // Node ID: 3922 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3922in_input = id1514out_result;

    id3922out_output[(getCycle()+1)%2] = id3922in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1506out_output;

  { // Node ID: 1506 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1506in_input = id3925out_output[getCycle()%2];

    id1506out_output = id1506in_input;
  }
  { // Node ID: 3318 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2754out_result;

  { // Node ID: 2754 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2754in_a = id3318out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2754in_b = id3510out_output[getCycle()%2];

    id2754out_result = (eq_fixed(id2754in_a,id2754in_b));
  }
  { // Node ID: 3926 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3926in_input = id2754out_result;

    id3926out_output[(getCycle()+1)%2] = id3926in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1505out_o;

  { // Node ID: 1505 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1505in_i = id3926out_output[getCycle()%2];

    id1505out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1505in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1507out_result;

  { // Node ID: 1507 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1507in_a = id1506out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1507in_b = id1505out_o;

    id1507out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1507in_a,id1507in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1508out_result;

  { // Node ID: 1508 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1508in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1508in_option0 = id1507out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1508in_option1 = id1505out_o;

    HWOffsetFix<32,0,UNSIGNED> id1508x_1;

    switch((id1508in_sel.getValueAsLong())) {
      case 0l:
        id1508x_1 = id1508in_option0;
        break;
      case 1l:
        id1508x_1 = id1508in_option1;
        break;
      default:
        id1508x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1508out_result = (id1508x_1);
  }
  { // Node ID: 3925 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3925in_input = id1508out_result;

    id3925out_output[(getCycle()+1)%2] = id3925in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1500out_output;

  { // Node ID: 1500 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1500in_input = id3928out_output[getCycle()%2];

    id1500out_output = id1500in_input;
  }
  { // Node ID: 3317 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2755out_result;

  { // Node ID: 2755 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2755in_a = id3317out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2755in_b = id3510out_output[getCycle()%2];

    id2755out_result = (eq_fixed(id2755in_a,id2755in_b));
  }
  { // Node ID: 3929 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3929in_input = id2755out_result;

    id3929out_output[(getCycle()+1)%2] = id3929in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1499out_o;

  { // Node ID: 1499 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1499in_i = id3929out_output[getCycle()%2];

    id1499out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1499in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1501out_result;

  { // Node ID: 1501 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1501in_a = id1500out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1501in_b = id1499out_o;

    id1501out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1501in_a,id1501in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1502out_result;

  { // Node ID: 1502 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1502in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1502in_option0 = id1501out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1502in_option1 = id1499out_o;

    HWOffsetFix<32,0,UNSIGNED> id1502x_1;

    switch((id1502in_sel.getValueAsLong())) {
      case 0l:
        id1502x_1 = id1502in_option0;
        break;
      case 1l:
        id1502x_1 = id1502in_option1;
        break;
      default:
        id1502x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1502out_result = (id1502x_1);
  }
  { // Node ID: 3928 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3928in_input = id1502out_result;

    id3928out_output[(getCycle()+1)%2] = id3928in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1494out_output;

  { // Node ID: 1494 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1494in_input = id3931out_output[getCycle()%2];

    id1494out_output = id1494in_input;
  }
  { // Node ID: 3316 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2756out_result;

  { // Node ID: 2756 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2756in_a = id3316out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2756in_b = id3510out_output[getCycle()%2];

    id2756out_result = (eq_fixed(id2756in_a,id2756in_b));
  }
  { // Node ID: 3932 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3932in_input = id2756out_result;

    id3932out_output[(getCycle()+1)%2] = id3932in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1493out_o;

  { // Node ID: 1493 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1493in_i = id3932out_output[getCycle()%2];

    id1493out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1493in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1495out_result;

  { // Node ID: 1495 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1495in_a = id1494out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1495in_b = id1493out_o;

    id1495out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1495in_a,id1495in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1496out_result;

  { // Node ID: 1496 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1496in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1496in_option0 = id1495out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1496in_option1 = id1493out_o;

    HWOffsetFix<32,0,UNSIGNED> id1496x_1;

    switch((id1496in_sel.getValueAsLong())) {
      case 0l:
        id1496x_1 = id1496in_option0;
        break;
      case 1l:
        id1496x_1 = id1496in_option1;
        break;
      default:
        id1496x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1496out_result = (id1496x_1);
  }
  { // Node ID: 3931 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3931in_input = id1496out_result;

    id3931out_output[(getCycle()+1)%2] = id3931in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1488out_output;

  { // Node ID: 1488 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1488in_input = id3934out_output[getCycle()%2];

    id1488out_output = id1488in_input;
  }
  { // Node ID: 3315 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2757out_result;

  { // Node ID: 2757 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2757in_a = id3315out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2757in_b = id3510out_output[getCycle()%2];

    id2757out_result = (eq_fixed(id2757in_a,id2757in_b));
  }
  { // Node ID: 3935 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3935in_input = id2757out_result;

    id3935out_output[(getCycle()+1)%2] = id3935in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1487out_o;

  { // Node ID: 1487 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1487in_i = id3935out_output[getCycle()%2];

    id1487out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1487in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1489out_result;

  { // Node ID: 1489 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1489in_a = id1488out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1489in_b = id1487out_o;

    id1489out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1489in_a,id1489in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1490out_result;

  { // Node ID: 1490 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1490in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1490in_option0 = id1489out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1490in_option1 = id1487out_o;

    HWOffsetFix<32,0,UNSIGNED> id1490x_1;

    switch((id1490in_sel.getValueAsLong())) {
      case 0l:
        id1490x_1 = id1490in_option0;
        break;
      case 1l:
        id1490x_1 = id1490in_option1;
        break;
      default:
        id1490x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1490out_result = (id1490x_1);
  }
  { // Node ID: 3934 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3934in_input = id1490out_result;

    id3934out_output[(getCycle()+1)%2] = id3934in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1482out_output;

  { // Node ID: 1482 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1482in_input = id3937out_output[getCycle()%2];

    id1482out_output = id1482in_input;
  }
  { // Node ID: 3314 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2758out_result;

  { // Node ID: 2758 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2758in_a = id3314out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2758in_b = id3510out_output[getCycle()%2];

    id2758out_result = (eq_fixed(id2758in_a,id2758in_b));
  }
  { // Node ID: 3938 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3938in_input = id2758out_result;

    id3938out_output[(getCycle()+1)%2] = id3938in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1481out_o;

  { // Node ID: 1481 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1481in_i = id3938out_output[getCycle()%2];

    id1481out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1481in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1483out_result;

  { // Node ID: 1483 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1483in_a = id1482out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1483in_b = id1481out_o;

    id1483out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1483in_a,id1483in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1484out_result;

  { // Node ID: 1484 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1484in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1484in_option0 = id1483out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1484in_option1 = id1481out_o;

    HWOffsetFix<32,0,UNSIGNED> id1484x_1;

    switch((id1484in_sel.getValueAsLong())) {
      case 0l:
        id1484x_1 = id1484in_option0;
        break;
      case 1l:
        id1484x_1 = id1484in_option1;
        break;
      default:
        id1484x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1484out_result = (id1484x_1);
  }
  { // Node ID: 3937 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3937in_input = id1484out_result;

    id3937out_output[(getCycle()+1)%2] = id3937in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1476out_output;

  { // Node ID: 1476 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1476in_input = id3940out_output[getCycle()%2];

    id1476out_output = id1476in_input;
  }
  { // Node ID: 3313 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2759out_result;

  { // Node ID: 2759 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2759in_a = id3313out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2759in_b = id3510out_output[getCycle()%2];

    id2759out_result = (eq_fixed(id2759in_a,id2759in_b));
  }
  { // Node ID: 3941 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3941in_input = id2759out_result;

    id3941out_output[(getCycle()+1)%2] = id3941in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1475out_o;

  { // Node ID: 1475 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1475in_i = id3941out_output[getCycle()%2];

    id1475out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1475in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1477out_result;

  { // Node ID: 1477 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1477in_a = id1476out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1477in_b = id1475out_o;

    id1477out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1477in_a,id1477in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1478out_result;

  { // Node ID: 1478 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1478in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1478in_option0 = id1477out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1478in_option1 = id1475out_o;

    HWOffsetFix<32,0,UNSIGNED> id1478x_1;

    switch((id1478in_sel.getValueAsLong())) {
      case 0l:
        id1478x_1 = id1478in_option0;
        break;
      case 1l:
        id1478x_1 = id1478in_option1;
        break;
      default:
        id1478x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1478out_result = (id1478x_1);
  }
  { // Node ID: 3940 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3940in_input = id1478out_result;

    id3940out_output[(getCycle()+1)%2] = id3940in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1470out_output;

  { // Node ID: 1470 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1470in_input = id3943out_output[getCycle()%2];

    id1470out_output = id1470in_input;
  }
  { // Node ID: 3312 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2760out_result;

  { // Node ID: 2760 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2760in_a = id3312out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2760in_b = id3510out_output[getCycle()%2];

    id2760out_result = (eq_fixed(id2760in_a,id2760in_b));
  }
  { // Node ID: 3944 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3944in_input = id2760out_result;

    id3944out_output[(getCycle()+1)%2] = id3944in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1469out_o;

  { // Node ID: 1469 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1469in_i = id3944out_output[getCycle()%2];

    id1469out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1469in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1471out_result;

  { // Node ID: 1471 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1471in_a = id1470out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1471in_b = id1469out_o;

    id1471out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1471in_a,id1471in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1472out_result;

  { // Node ID: 1472 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1472in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1472in_option0 = id1471out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1472in_option1 = id1469out_o;

    HWOffsetFix<32,0,UNSIGNED> id1472x_1;

    switch((id1472in_sel.getValueAsLong())) {
      case 0l:
        id1472x_1 = id1472in_option0;
        break;
      case 1l:
        id1472x_1 = id1472in_option1;
        break;
      default:
        id1472x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1472out_result = (id1472x_1);
  }
  { // Node ID: 3943 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3943in_input = id1472out_result;

    id3943out_output[(getCycle()+1)%2] = id3943in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1464out_output;

  { // Node ID: 1464 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1464in_input = id3946out_output[getCycle()%2];

    id1464out_output = id1464in_input;
  }
  { // Node ID: 3311 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2761out_result;

  { // Node ID: 2761 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2761in_a = id3311out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2761in_b = id3510out_output[getCycle()%2];

    id2761out_result = (eq_fixed(id2761in_a,id2761in_b));
  }
  { // Node ID: 3947 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3947in_input = id2761out_result;

    id3947out_output[(getCycle()+1)%2] = id3947in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1463out_o;

  { // Node ID: 1463 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1463in_i = id3947out_output[getCycle()%2];

    id1463out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1463in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1465out_result;

  { // Node ID: 1465 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1465in_a = id1464out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1465in_b = id1463out_o;

    id1465out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1465in_a,id1465in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1466out_result;

  { // Node ID: 1466 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1466in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1466in_option0 = id1465out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1466in_option1 = id1463out_o;

    HWOffsetFix<32,0,UNSIGNED> id1466x_1;

    switch((id1466in_sel.getValueAsLong())) {
      case 0l:
        id1466x_1 = id1466in_option0;
        break;
      case 1l:
        id1466x_1 = id1466in_option1;
        break;
      default:
        id1466x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1466out_result = (id1466x_1);
  }
  { // Node ID: 3946 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3946in_input = id1466out_result;

    id3946out_output[(getCycle()+1)%2] = id3946in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1458out_output;

  { // Node ID: 1458 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1458in_input = id3949out_output[getCycle()%2];

    id1458out_output = id1458in_input;
  }
  { // Node ID: 3310 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2762out_result;

  { // Node ID: 2762 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2762in_a = id3310out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2762in_b = id3510out_output[getCycle()%2];

    id2762out_result = (eq_fixed(id2762in_a,id2762in_b));
  }
  { // Node ID: 3950 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3950in_input = id2762out_result;

    id3950out_output[(getCycle()+1)%2] = id3950in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1457out_o;

  { // Node ID: 1457 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1457in_i = id3950out_output[getCycle()%2];

    id1457out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1457in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1459out_result;

  { // Node ID: 1459 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1459in_a = id1458out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1459in_b = id1457out_o;

    id1459out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1459in_a,id1459in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1460out_result;

  { // Node ID: 1460 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1460in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1460in_option0 = id1459out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1460in_option1 = id1457out_o;

    HWOffsetFix<32,0,UNSIGNED> id1460x_1;

    switch((id1460in_sel.getValueAsLong())) {
      case 0l:
        id1460x_1 = id1460in_option0;
        break;
      case 1l:
        id1460x_1 = id1460in_option1;
        break;
      default:
        id1460x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1460out_result = (id1460x_1);
  }
  { // Node ID: 3949 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3949in_input = id1460out_result;

    id3949out_output[(getCycle()+1)%2] = id3949in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1452out_output;

  { // Node ID: 1452 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1452in_input = id3952out_output[getCycle()%2];

    id1452out_output = id1452in_input;
  }
  { // Node ID: 3309 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2763out_result;

  { // Node ID: 2763 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2763in_a = id3309out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2763in_b = id3510out_output[getCycle()%2];

    id2763out_result = (eq_fixed(id2763in_a,id2763in_b));
  }
  { // Node ID: 3953 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3953in_input = id2763out_result;

    id3953out_output[(getCycle()+1)%2] = id3953in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1451out_o;

  { // Node ID: 1451 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1451in_i = id3953out_output[getCycle()%2];

    id1451out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1451in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1453out_result;

  { // Node ID: 1453 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1453in_a = id1452out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1453in_b = id1451out_o;

    id1453out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1453in_a,id1453in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1454out_result;

  { // Node ID: 1454 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1454in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1454in_option0 = id1453out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1454in_option1 = id1451out_o;

    HWOffsetFix<32,0,UNSIGNED> id1454x_1;

    switch((id1454in_sel.getValueAsLong())) {
      case 0l:
        id1454x_1 = id1454in_option0;
        break;
      case 1l:
        id1454x_1 = id1454in_option1;
        break;
      default:
        id1454x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1454out_result = (id1454x_1);
  }
  { // Node ID: 3952 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3952in_input = id1454out_result;

    id3952out_output[(getCycle()+1)%2] = id3952in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1446out_output;

  { // Node ID: 1446 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1446in_input = id3955out_output[getCycle()%2];

    id1446out_output = id1446in_input;
  }
  { // Node ID: 3308 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2764out_result;

  { // Node ID: 2764 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2764in_a = id3308out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2764in_b = id3510out_output[getCycle()%2];

    id2764out_result = (eq_fixed(id2764in_a,id2764in_b));
  }
  { // Node ID: 3956 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3956in_input = id2764out_result;

    id3956out_output[(getCycle()+1)%2] = id3956in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1445out_o;

  { // Node ID: 1445 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1445in_i = id3956out_output[getCycle()%2];

    id1445out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1445in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1447out_result;

  { // Node ID: 1447 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1447in_a = id1446out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1447in_b = id1445out_o;

    id1447out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1447in_a,id1447in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1448out_result;

  { // Node ID: 1448 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1448in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1448in_option0 = id1447out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1448in_option1 = id1445out_o;

    HWOffsetFix<32,0,UNSIGNED> id1448x_1;

    switch((id1448in_sel.getValueAsLong())) {
      case 0l:
        id1448x_1 = id1448in_option0;
        break;
      case 1l:
        id1448x_1 = id1448in_option1;
        break;
      default:
        id1448x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1448out_result = (id1448x_1);
  }
  { // Node ID: 3955 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3955in_input = id1448out_result;

    id3955out_output[(getCycle()+1)%2] = id3955in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1440out_output;

  { // Node ID: 1440 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1440in_input = id3958out_output[getCycle()%2];

    id1440out_output = id1440in_input;
  }
  { // Node ID: 3307 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2765out_result;

  { // Node ID: 2765 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2765in_a = id3307out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2765in_b = id3510out_output[getCycle()%2];

    id2765out_result = (eq_fixed(id2765in_a,id2765in_b));
  }
  { // Node ID: 3959 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3959in_input = id2765out_result;

    id3959out_output[(getCycle()+1)%2] = id3959in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1439out_o;

  { // Node ID: 1439 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1439in_i = id3959out_output[getCycle()%2];

    id1439out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1439in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1441out_result;

  { // Node ID: 1441 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1441in_a = id1440out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1441in_b = id1439out_o;

    id1441out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1441in_a,id1441in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1442out_result;

  { // Node ID: 1442 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1442in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1442in_option0 = id1441out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1442in_option1 = id1439out_o;

    HWOffsetFix<32,0,UNSIGNED> id1442x_1;

    switch((id1442in_sel.getValueAsLong())) {
      case 0l:
        id1442x_1 = id1442in_option0;
        break;
      case 1l:
        id1442x_1 = id1442in_option1;
        break;
      default:
        id1442x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1442out_result = (id1442x_1);
  }
  { // Node ID: 3958 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3958in_input = id1442out_result;

    id3958out_output[(getCycle()+1)%2] = id3958in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1434out_output;

  { // Node ID: 1434 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1434in_input = id3961out_output[getCycle()%2];

    id1434out_output = id1434in_input;
  }
  { // Node ID: 3306 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2766out_result;

  { // Node ID: 2766 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2766in_a = id3306out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2766in_b = id3510out_output[getCycle()%2];

    id2766out_result = (eq_fixed(id2766in_a,id2766in_b));
  }
  { // Node ID: 3962 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3962in_input = id2766out_result;

    id3962out_output[(getCycle()+1)%2] = id3962in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1433out_o;

  { // Node ID: 1433 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1433in_i = id3962out_output[getCycle()%2];

    id1433out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1433in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1435out_result;

  { // Node ID: 1435 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1435in_a = id1434out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1435in_b = id1433out_o;

    id1435out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1435in_a,id1435in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1436out_result;

  { // Node ID: 1436 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1436in_sel = id3881out_output[getCycle()%8];
    const HWOffsetFix<32,0,UNSIGNED> &id1436in_option0 = id1435out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1436in_option1 = id1433out_o;

    HWOffsetFix<32,0,UNSIGNED> id1436x_1;

    switch((id1436in_sel.getValueAsLong())) {
      case 0l:
        id1436x_1 = id1436in_option0;
        break;
      case 1l:
        id1436x_1 = id1436in_option1;
        break;
      default:
        id1436x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1436out_result = (id1436x_1);
  }
  { // Node ID: 3961 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3961in_input = id1436out_result;

    id3961out_output[(getCycle()+1)%2] = id3961in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1428out_output;

  { // Node ID: 1428 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1428in_input = id3964out_output[getCycle()%2];

    id1428out_output = id1428in_input;
  }
  { // Node ID: 3305 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2767out_result;

  { // Node ID: 2767 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2767in_a = id3305out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2767in_b = id3510out_output[getCycle()%2];

    id2767out_result = (eq_fixed(id2767in_a,id2767in_b));
  }
  { // Node ID: 3965 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3965in_input = id2767out_result;

    id3965out_output[(getCycle()+1)%2] = id3965in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1427out_o;

  { // Node ID: 1427 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1427in_i = id3965out_output[getCycle()%2];

    id1427out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1427in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1429out_result;

  { // Node ID: 1429 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1429in_a = id1428out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1429in_b = id1427out_o;

    id1429out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1429in_a,id1429in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1430out_result;

  { // Node ID: 1430 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1430in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1430in_option0 = id1429out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1430in_option1 = id1427out_o;

    HWOffsetFix<32,0,UNSIGNED> id1430x_1;

    switch((id1430in_sel.getValueAsLong())) {
      case 0l:
        id1430x_1 = id1430in_option0;
        break;
      case 1l:
        id1430x_1 = id1430in_option1;
        break;
      default:
        id1430x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1430out_result = (id1430x_1);
  }
  { // Node ID: 3964 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3964in_input = id1430out_result;

    id3964out_output[(getCycle()+1)%2] = id3964in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1422out_output;

  { // Node ID: 1422 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1422in_input = id3967out_output[getCycle()%2];

    id1422out_output = id1422in_input;
  }
  { // Node ID: 3304 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2768out_result;

  { // Node ID: 2768 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2768in_a = id3304out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2768in_b = id3510out_output[getCycle()%2];

    id2768out_result = (eq_fixed(id2768in_a,id2768in_b));
  }
  { // Node ID: 3968 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3968in_input = id2768out_result;

    id3968out_output[(getCycle()+1)%2] = id3968in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1421out_o;

  { // Node ID: 1421 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1421in_i = id3968out_output[getCycle()%2];

    id1421out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1421in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1423out_result;

  { // Node ID: 1423 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1423in_a = id1422out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1423in_b = id1421out_o;

    id1423out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1423in_a,id1423in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1424out_result;

  { // Node ID: 1424 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1424in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1424in_option0 = id1423out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1424in_option1 = id1421out_o;

    HWOffsetFix<32,0,UNSIGNED> id1424x_1;

    switch((id1424in_sel.getValueAsLong())) {
      case 0l:
        id1424x_1 = id1424in_option0;
        break;
      case 1l:
        id1424x_1 = id1424in_option1;
        break;
      default:
        id1424x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1424out_result = (id1424x_1);
  }
  { // Node ID: 3967 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3967in_input = id1424out_result;

    id3967out_output[(getCycle()+1)%2] = id3967in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1416out_output;

  { // Node ID: 1416 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1416in_input = id3970out_output[getCycle()%2];

    id1416out_output = id1416in_input;
  }
  { // Node ID: 3303 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2769out_result;

  { // Node ID: 2769 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2769in_a = id3303out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2769in_b = id3510out_output[getCycle()%2];

    id2769out_result = (eq_fixed(id2769in_a,id2769in_b));
  }
  { // Node ID: 3971 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3971in_input = id2769out_result;

    id3971out_output[(getCycle()+1)%2] = id3971in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1415out_o;

  { // Node ID: 1415 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1415in_i = id3971out_output[getCycle()%2];

    id1415out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1415in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1417out_result;

  { // Node ID: 1417 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1417in_a = id1416out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1417in_b = id1415out_o;

    id1417out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1417in_a,id1417in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1418out_result;

  { // Node ID: 1418 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1418in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1418in_option0 = id1417out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1418in_option1 = id1415out_o;

    HWOffsetFix<32,0,UNSIGNED> id1418x_1;

    switch((id1418in_sel.getValueAsLong())) {
      case 0l:
        id1418x_1 = id1418in_option0;
        break;
      case 1l:
        id1418x_1 = id1418in_option1;
        break;
      default:
        id1418x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1418out_result = (id1418x_1);
  }
  { // Node ID: 3970 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3970in_input = id1418out_result;

    id3970out_output[(getCycle()+1)%2] = id3970in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1410out_output;

  { // Node ID: 1410 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1410in_input = id3973out_output[getCycle()%2];

    id1410out_output = id1410in_input;
  }
  { // Node ID: 3302 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2770out_result;

  { // Node ID: 2770 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2770in_a = id3302out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2770in_b = id3510out_output[getCycle()%2];

    id2770out_result = (eq_fixed(id2770in_a,id2770in_b));
  }
  { // Node ID: 3974 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3974in_input = id2770out_result;

    id3974out_output[(getCycle()+1)%2] = id3974in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1409out_o;

  { // Node ID: 1409 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1409in_i = id3974out_output[getCycle()%2];

    id1409out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1409in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1411out_result;

  { // Node ID: 1411 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1411in_a = id1410out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1411in_b = id1409out_o;

    id1411out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1411in_a,id1411in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1412out_result;

  { // Node ID: 1412 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1412in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1412in_option0 = id1411out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1412in_option1 = id1409out_o;

    HWOffsetFix<32,0,UNSIGNED> id1412x_1;

    switch((id1412in_sel.getValueAsLong())) {
      case 0l:
        id1412x_1 = id1412in_option0;
        break;
      case 1l:
        id1412x_1 = id1412in_option1;
        break;
      default:
        id1412x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1412out_result = (id1412x_1);
  }
  { // Node ID: 3973 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3973in_input = id1412out_result;

    id3973out_output[(getCycle()+1)%2] = id3973in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1404out_output;

  { // Node ID: 1404 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1404in_input = id3976out_output[getCycle()%2];

    id1404out_output = id1404in_input;
  }
  { // Node ID: 3301 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2771out_result;

  { // Node ID: 2771 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2771in_a = id3301out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2771in_b = id3510out_output[getCycle()%2];

    id2771out_result = (eq_fixed(id2771in_a,id2771in_b));
  }
  { // Node ID: 3977 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3977in_input = id2771out_result;

    id3977out_output[(getCycle()+1)%2] = id3977in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1403out_o;

  { // Node ID: 1403 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1403in_i = id3977out_output[getCycle()%2];

    id1403out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1403in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1405out_result;

  { // Node ID: 1405 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1405in_a = id1404out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1405in_b = id1403out_o;

    id1405out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1405in_a,id1405in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1406out_result;

  { // Node ID: 1406 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1406in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1406in_option0 = id1405out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1406in_option1 = id1403out_o;

    HWOffsetFix<32,0,UNSIGNED> id1406x_1;

    switch((id1406in_sel.getValueAsLong())) {
      case 0l:
        id1406x_1 = id1406in_option0;
        break;
      case 1l:
        id1406x_1 = id1406in_option1;
        break;
      default:
        id1406x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1406out_result = (id1406x_1);
  }
  { // Node ID: 3976 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3976in_input = id1406out_result;

    id3976out_output[(getCycle()+1)%2] = id3976in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1398out_output;

  { // Node ID: 1398 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1398in_input = id3979out_output[getCycle()%2];

    id1398out_output = id1398in_input;
  }
  { // Node ID: 3300 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2772out_result;

  { // Node ID: 2772 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2772in_a = id3300out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2772in_b = id3510out_output[getCycle()%2];

    id2772out_result = (eq_fixed(id2772in_a,id2772in_b));
  }
  { // Node ID: 3980 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3980in_input = id2772out_result;

    id3980out_output[(getCycle()+1)%2] = id3980in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1397out_o;

  { // Node ID: 1397 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1397in_i = id3980out_output[getCycle()%2];

    id1397out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1397in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1399out_result;

  { // Node ID: 1399 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1399in_a = id1398out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1399in_b = id1397out_o;

    id1399out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1399in_a,id1399in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1400out_result;

  { // Node ID: 1400 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1400in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1400in_option0 = id1399out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1400in_option1 = id1397out_o;

    HWOffsetFix<32,0,UNSIGNED> id1400x_1;

    switch((id1400in_sel.getValueAsLong())) {
      case 0l:
        id1400x_1 = id1400in_option0;
        break;
      case 1l:
        id1400x_1 = id1400in_option1;
        break;
      default:
        id1400x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1400out_result = (id1400x_1);
  }
  { // Node ID: 3979 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3979in_input = id1400out_result;

    id3979out_output[(getCycle()+1)%2] = id3979in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1392out_output;

  { // Node ID: 1392 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1392in_input = id3982out_output[getCycle()%2];

    id1392out_output = id1392in_input;
  }
  { // Node ID: 3299 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2773out_result;

  { // Node ID: 2773 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2773in_a = id3299out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2773in_b = id3510out_output[getCycle()%2];

    id2773out_result = (eq_fixed(id2773in_a,id2773in_b));
  }
  { // Node ID: 3983 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3983in_input = id2773out_result;

    id3983out_output[(getCycle()+1)%2] = id3983in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1391out_o;

  { // Node ID: 1391 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1391in_i = id3983out_output[getCycle()%2];

    id1391out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1391in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1393out_result;

  { // Node ID: 1393 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1393in_a = id1392out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1393in_b = id1391out_o;

    id1393out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1393in_a,id1393in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1394out_result;

  { // Node ID: 1394 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1394in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1394in_option0 = id1393out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1394in_option1 = id1391out_o;

    HWOffsetFix<32,0,UNSIGNED> id1394x_1;

    switch((id1394in_sel.getValueAsLong())) {
      case 0l:
        id1394x_1 = id1394in_option0;
        break;
      case 1l:
        id1394x_1 = id1394in_option1;
        break;
      default:
        id1394x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1394out_result = (id1394x_1);
  }
  { // Node ID: 3982 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3982in_input = id1394out_result;

    id3982out_output[(getCycle()+1)%2] = id3982in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1386out_output;

  { // Node ID: 1386 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1386in_input = id3985out_output[getCycle()%2];

    id1386out_output = id1386in_input;
  }
  { // Node ID: 3298 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2774out_result;

  { // Node ID: 2774 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2774in_a = id3298out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2774in_b = id3510out_output[getCycle()%2];

    id2774out_result = (eq_fixed(id2774in_a,id2774in_b));
  }
  { // Node ID: 3986 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3986in_input = id2774out_result;

    id3986out_output[(getCycle()+1)%2] = id3986in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1385out_o;

  { // Node ID: 1385 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1385in_i = id3986out_output[getCycle()%2];

    id1385out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1385in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1387out_result;

  { // Node ID: 1387 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1387in_a = id1386out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1387in_b = id1385out_o;

    id1387out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1387in_a,id1387in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1388out_result;

  { // Node ID: 1388 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1388in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1388in_option0 = id1387out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1388in_option1 = id1385out_o;

    HWOffsetFix<32,0,UNSIGNED> id1388x_1;

    switch((id1388in_sel.getValueAsLong())) {
      case 0l:
        id1388x_1 = id1388in_option0;
        break;
      case 1l:
        id1388x_1 = id1388in_option1;
        break;
      default:
        id1388x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1388out_result = (id1388x_1);
  }
  { // Node ID: 3985 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3985in_input = id1388out_result;

    id3985out_output[(getCycle()+1)%2] = id3985in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1380out_output;

  { // Node ID: 1380 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1380in_input = id3988out_output[getCycle()%2];

    id1380out_output = id1380in_input;
  }
  { // Node ID: 3297 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2775out_result;

  { // Node ID: 2775 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2775in_a = id3297out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2775in_b = id3510out_output[getCycle()%2];

    id2775out_result = (eq_fixed(id2775in_a,id2775in_b));
  }
  { // Node ID: 3989 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3989in_input = id2775out_result;

    id3989out_output[(getCycle()+1)%2] = id3989in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1379out_o;

  { // Node ID: 1379 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1379in_i = id3989out_output[getCycle()%2];

    id1379out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1379in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1381out_result;

  { // Node ID: 1381 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1381in_a = id1380out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1381in_b = id1379out_o;

    id1381out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1381in_a,id1381in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1382out_result;

  { // Node ID: 1382 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1382in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1382in_option0 = id1381out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1382in_option1 = id1379out_o;

    HWOffsetFix<32,0,UNSIGNED> id1382x_1;

    switch((id1382in_sel.getValueAsLong())) {
      case 0l:
        id1382x_1 = id1382in_option0;
        break;
      case 1l:
        id1382x_1 = id1382in_option1;
        break;
      default:
        id1382x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1382out_result = (id1382x_1);
  }
  { // Node ID: 3988 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3988in_input = id1382out_result;

    id3988out_output[(getCycle()+1)%2] = id3988in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1374out_output;

  { // Node ID: 1374 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1374in_input = id3991out_output[getCycle()%2];

    id1374out_output = id1374in_input;
  }
  { // Node ID: 3296 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2776out_result;

  { // Node ID: 2776 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2776in_a = id3296out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2776in_b = id3511out_output[getCycle()%2];

    id2776out_result = (eq_fixed(id2776in_a,id2776in_b));
  }
  { // Node ID: 3992 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3992in_input = id2776out_result;

    id3992out_output[(getCycle()+2)%3] = id3992in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1373out_o;

  { // Node ID: 1373 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1373in_i = id3992out_output[getCycle()%3];

    id1373out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1373in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1375out_result;

  { // Node ID: 1375 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1375in_a = id1374out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1375in_b = id1373out_o;

    id1375out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1375in_a,id1375in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1376out_result;

  { // Node ID: 1376 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1376in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1376in_option0 = id1375out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1376in_option1 = id1373out_o;

    HWOffsetFix<32,0,UNSIGNED> id1376x_1;

    switch((id1376in_sel.getValueAsLong())) {
      case 0l:
        id1376x_1 = id1376in_option0;
        break;
      case 1l:
        id1376x_1 = id1376in_option1;
        break;
      default:
        id1376x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1376out_result = (id1376x_1);
  }
  { // Node ID: 3991 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3991in_input = id1376out_result;

    id3991out_output[(getCycle()+1)%2] = id3991in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1368out_output;

  { // Node ID: 1368 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1368in_input = id3994out_output[getCycle()%2];

    id1368out_output = id1368in_input;
  }
  { // Node ID: 3295 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2777out_result;

  { // Node ID: 2777 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2777in_a = id3295out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2777in_b = id3511out_output[getCycle()%2];

    id2777out_result = (eq_fixed(id2777in_a,id2777in_b));
  }
  { // Node ID: 3995 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3995in_input = id2777out_result;

    id3995out_output[(getCycle()+2)%3] = id3995in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1367out_o;

  { // Node ID: 1367 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1367in_i = id3995out_output[getCycle()%3];

    id1367out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1367in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1369out_result;

  { // Node ID: 1369 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1369in_a = id1368out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1369in_b = id1367out_o;

    id1369out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1369in_a,id1369in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1370out_result;

  { // Node ID: 1370 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1370in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1370in_option0 = id1369out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1370in_option1 = id1367out_o;

    HWOffsetFix<32,0,UNSIGNED> id1370x_1;

    switch((id1370in_sel.getValueAsLong())) {
      case 0l:
        id1370x_1 = id1370in_option0;
        break;
      case 1l:
        id1370x_1 = id1370in_option1;
        break;
      default:
        id1370x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1370out_result = (id1370x_1);
  }
  { // Node ID: 3994 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3994in_input = id1370out_result;

    id3994out_output[(getCycle()+1)%2] = id3994in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1362out_output;

  { // Node ID: 1362 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1362in_input = id3997out_output[getCycle()%2];

    id1362out_output = id1362in_input;
  }
  { // Node ID: 3294 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2778out_result;

  { // Node ID: 2778 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2778in_a = id3294out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2778in_b = id3511out_output[getCycle()%2];

    id2778out_result = (eq_fixed(id2778in_a,id2778in_b));
  }
  { // Node ID: 3998 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id3998in_input = id2778out_result;

    id3998out_output[(getCycle()+2)%3] = id3998in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1361out_o;

  { // Node ID: 1361 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1361in_i = id3998out_output[getCycle()%3];

    id1361out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1361in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1363out_result;

  { // Node ID: 1363 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1363in_a = id1362out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1363in_b = id1361out_o;

    id1363out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1363in_a,id1363in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1364out_result;

  { // Node ID: 1364 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1364in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1364in_option0 = id1363out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1364in_option1 = id1361out_o;

    HWOffsetFix<32,0,UNSIGNED> id1364x_1;

    switch((id1364in_sel.getValueAsLong())) {
      case 0l:
        id1364x_1 = id1364in_option0;
        break;
      case 1l:
        id1364x_1 = id1364in_option1;
        break;
      default:
        id1364x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1364out_result = (id1364x_1);
  }
  { // Node ID: 3997 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id3997in_input = id1364out_result;

    id3997out_output[(getCycle()+1)%2] = id3997in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1356out_output;

  { // Node ID: 1356 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1356in_input = id4000out_output[getCycle()%2];

    id1356out_output = id1356in_input;
  }
  { // Node ID: 3293 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2779out_result;

  { // Node ID: 2779 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2779in_a = id3293out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2779in_b = id3511out_output[getCycle()%2];

    id2779out_result = (eq_fixed(id2779in_a,id2779in_b));
  }
  { // Node ID: 4001 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4001in_input = id2779out_result;

    id4001out_output[(getCycle()+2)%3] = id4001in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1355out_o;

  { // Node ID: 1355 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1355in_i = id4001out_output[getCycle()%3];

    id1355out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1355in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1357out_result;

  { // Node ID: 1357 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1357in_a = id1356out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1357in_b = id1355out_o;

    id1357out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1357in_a,id1357in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1358out_result;

  { // Node ID: 1358 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1358in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1358in_option0 = id1357out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1358in_option1 = id1355out_o;

    HWOffsetFix<32,0,UNSIGNED> id1358x_1;

    switch((id1358in_sel.getValueAsLong())) {
      case 0l:
        id1358x_1 = id1358in_option0;
        break;
      case 1l:
        id1358x_1 = id1358in_option1;
        break;
      default:
        id1358x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1358out_result = (id1358x_1);
  }
  { // Node ID: 4000 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4000in_input = id1358out_result;

    id4000out_output[(getCycle()+1)%2] = id4000in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1350out_output;

  { // Node ID: 1350 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1350in_input = id4003out_output[getCycle()%2];

    id1350out_output = id1350in_input;
  }
  { // Node ID: 3292 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2780out_result;

  { // Node ID: 2780 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2780in_a = id3292out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2780in_b = id3511out_output[getCycle()%2];

    id2780out_result = (eq_fixed(id2780in_a,id2780in_b));
  }
  { // Node ID: 4004 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4004in_input = id2780out_result;

    id4004out_output[(getCycle()+2)%3] = id4004in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1349out_o;

  { // Node ID: 1349 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1349in_i = id4004out_output[getCycle()%3];

    id1349out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1349in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1351out_result;

  { // Node ID: 1351 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1351in_a = id1350out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1351in_b = id1349out_o;

    id1351out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1351in_a,id1351in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1352out_result;

  { // Node ID: 1352 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1352in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1352in_option0 = id1351out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1352in_option1 = id1349out_o;

    HWOffsetFix<32,0,UNSIGNED> id1352x_1;

    switch((id1352in_sel.getValueAsLong())) {
      case 0l:
        id1352x_1 = id1352in_option0;
        break;
      case 1l:
        id1352x_1 = id1352in_option1;
        break;
      default:
        id1352x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1352out_result = (id1352x_1);
  }
  { // Node ID: 4003 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4003in_input = id1352out_result;

    id4003out_output[(getCycle()+1)%2] = id4003in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1344out_output;

  { // Node ID: 1344 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1344in_input = id4006out_output[getCycle()%2];

    id1344out_output = id1344in_input;
  }
  { // Node ID: 3291 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2781out_result;

  { // Node ID: 2781 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2781in_a = id3291out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2781in_b = id3511out_output[getCycle()%2];

    id2781out_result = (eq_fixed(id2781in_a,id2781in_b));
  }
  { // Node ID: 4007 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4007in_input = id2781out_result;

    id4007out_output[(getCycle()+2)%3] = id4007in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1343out_o;

  { // Node ID: 1343 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1343in_i = id4007out_output[getCycle()%3];

    id1343out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1343in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1345out_result;

  { // Node ID: 1345 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1345in_a = id1344out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1345in_b = id1343out_o;

    id1345out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1345in_a,id1345in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1346out_result;

  { // Node ID: 1346 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1346in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1346in_option0 = id1345out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1346in_option1 = id1343out_o;

    HWOffsetFix<32,0,UNSIGNED> id1346x_1;

    switch((id1346in_sel.getValueAsLong())) {
      case 0l:
        id1346x_1 = id1346in_option0;
        break;
      case 1l:
        id1346x_1 = id1346in_option1;
        break;
      default:
        id1346x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1346out_result = (id1346x_1);
  }
  { // Node ID: 4006 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4006in_input = id1346out_result;

    id4006out_output[(getCycle()+1)%2] = id4006in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1338out_output;

  { // Node ID: 1338 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1338in_input = id4009out_output[getCycle()%2];

    id1338out_output = id1338in_input;
  }
  { // Node ID: 3290 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2782out_result;

  { // Node ID: 2782 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2782in_a = id3290out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2782in_b = id3511out_output[getCycle()%2];

    id2782out_result = (eq_fixed(id2782in_a,id2782in_b));
  }
  { // Node ID: 4010 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4010in_input = id2782out_result;

    id4010out_output[(getCycle()+2)%3] = id4010in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1337out_o;

  { // Node ID: 1337 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1337in_i = id4010out_output[getCycle()%3];

    id1337out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1337in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1339out_result;

  { // Node ID: 1339 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1339in_a = id1338out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1339in_b = id1337out_o;

    id1339out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1339in_a,id1339in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1340out_result;

  { // Node ID: 1340 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1340in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1340in_option0 = id1339out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1340in_option1 = id1337out_o;

    HWOffsetFix<32,0,UNSIGNED> id1340x_1;

    switch((id1340in_sel.getValueAsLong())) {
      case 0l:
        id1340x_1 = id1340in_option0;
        break;
      case 1l:
        id1340x_1 = id1340in_option1;
        break;
      default:
        id1340x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1340out_result = (id1340x_1);
  }
  { // Node ID: 4009 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4009in_input = id1340out_result;

    id4009out_output[(getCycle()+1)%2] = id4009in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1326out_output;

  { // Node ID: 1326 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1326in_input = id4012out_output[getCycle()%2];

    id1326out_output = id1326in_input;
  }
  { // Node ID: 3289 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2783out_result;

  { // Node ID: 2783 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2783in_a = id3289out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2783in_b = id3511out_output[getCycle()%2];

    id2783out_result = (eq_fixed(id2783in_a,id2783in_b));
  }
  { // Node ID: 4013 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4013in_input = id2783out_result;

    id4013out_output[(getCycle()+2)%3] = id4013in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1325out_o;

  { // Node ID: 1325 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1325in_i = id4013out_output[getCycle()%3];

    id1325out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1325in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1327out_result;

  { // Node ID: 1327 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1327in_a = id1326out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1327in_b = id1325out_o;

    id1327out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1327in_a,id1327in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1328out_result;

  { // Node ID: 1328 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1328in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1328in_option0 = id1327out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1328in_option1 = id1325out_o;

    HWOffsetFix<32,0,UNSIGNED> id1328x_1;

    switch((id1328in_sel.getValueAsLong())) {
      case 0l:
        id1328x_1 = id1328in_option0;
        break;
      case 1l:
        id1328x_1 = id1328in_option1;
        break;
      default:
        id1328x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1328out_result = (id1328x_1);
  }
  { // Node ID: 4012 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4012in_input = id1328out_result;

    id4012out_output[(getCycle()+1)%2] = id4012in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1314out_output;

  { // Node ID: 1314 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1314in_input = id4015out_output[getCycle()%2];

    id1314out_output = id1314in_input;
  }
  { // Node ID: 3288 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2784out_result;

  { // Node ID: 2784 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2784in_a = id3288out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2784in_b = id3511out_output[getCycle()%2];

    id2784out_result = (eq_fixed(id2784in_a,id2784in_b));
  }
  { // Node ID: 4016 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4016in_input = id2784out_result;

    id4016out_output[(getCycle()+2)%3] = id4016in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1313out_o;

  { // Node ID: 1313 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1313in_i = id4016out_output[getCycle()%3];

    id1313out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1313in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1315out_result;

  { // Node ID: 1315 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1315in_a = id1314out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1315in_b = id1313out_o;

    id1315out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1315in_a,id1315in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1316out_result;

  { // Node ID: 1316 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1316in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1316in_option0 = id1315out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1316in_option1 = id1313out_o;

    HWOffsetFix<32,0,UNSIGNED> id1316x_1;

    switch((id1316in_sel.getValueAsLong())) {
      case 0l:
        id1316x_1 = id1316in_option0;
        break;
      case 1l:
        id1316x_1 = id1316in_option1;
        break;
      default:
        id1316x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1316out_result = (id1316x_1);
  }
  { // Node ID: 4015 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4015in_input = id1316out_result;

    id4015out_output[(getCycle()+1)%2] = id4015in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1302out_output;

  { // Node ID: 1302 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1302in_input = id4018out_output[getCycle()%2];

    id1302out_output = id1302in_input;
  }
  { // Node ID: 3287 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2785out_result;

  { // Node ID: 2785 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2785in_a = id3287out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2785in_b = id3511out_output[getCycle()%2];

    id2785out_result = (eq_fixed(id2785in_a,id2785in_b));
  }
  { // Node ID: 4019 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4019in_input = id2785out_result;

    id4019out_output[(getCycle()+2)%3] = id4019in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1301out_o;

  { // Node ID: 1301 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1301in_i = id4019out_output[getCycle()%3];

    id1301out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1301in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1303out_result;

  { // Node ID: 1303 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1303in_a = id1302out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1303in_b = id1301out_o;

    id1303out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1303in_a,id1303in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1304out_result;

  { // Node ID: 1304 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1304in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1304in_option0 = id1303out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1304in_option1 = id1301out_o;

    HWOffsetFix<32,0,UNSIGNED> id1304x_1;

    switch((id1304in_sel.getValueAsLong())) {
      case 0l:
        id1304x_1 = id1304in_option0;
        break;
      case 1l:
        id1304x_1 = id1304in_option1;
        break;
      default:
        id1304x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1304out_result = (id1304x_1);
  }
  { // Node ID: 4018 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4018in_input = id1304out_result;

    id4018out_output[(getCycle()+1)%2] = id4018in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1290out_output;

  { // Node ID: 1290 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1290in_input = id4021out_output[getCycle()%2];

    id1290out_output = id1290in_input;
  }
  { // Node ID: 3286 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2786out_result;

  { // Node ID: 2786 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2786in_a = id3286out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2786in_b = id3511out_output[getCycle()%2];

    id2786out_result = (eq_fixed(id2786in_a,id2786in_b));
  }
  { // Node ID: 4022 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4022in_input = id2786out_result;

    id4022out_output[(getCycle()+2)%3] = id4022in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1289out_o;

  { // Node ID: 1289 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1289in_i = id4022out_output[getCycle()%3];

    id1289out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1289in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1291out_result;

  { // Node ID: 1291 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1291in_a = id1290out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1291in_b = id1289out_o;

    id1291out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1291in_a,id1291in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1292out_result;

  { // Node ID: 1292 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1292in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1292in_option0 = id1291out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1292in_option1 = id1289out_o;

    HWOffsetFix<32,0,UNSIGNED> id1292x_1;

    switch((id1292in_sel.getValueAsLong())) {
      case 0l:
        id1292x_1 = id1292in_option0;
        break;
      case 1l:
        id1292x_1 = id1292in_option1;
        break;
      default:
        id1292x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1292out_result = (id1292x_1);
  }
  { // Node ID: 4021 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4021in_input = id1292out_result;

    id4021out_output[(getCycle()+1)%2] = id4021in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1278out_output;

  { // Node ID: 1278 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1278in_input = id4024out_output[getCycle()%2];

    id1278out_output = id1278in_input;
  }
  { // Node ID: 3285 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2787out_result;

  { // Node ID: 2787 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2787in_a = id3285out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2787in_b = id3511out_output[getCycle()%2];

    id2787out_result = (eq_fixed(id2787in_a,id2787in_b));
  }
  { // Node ID: 4025 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4025in_input = id2787out_result;

    id4025out_output[(getCycle()+2)%3] = id4025in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1277out_o;

  { // Node ID: 1277 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1277in_i = id4025out_output[getCycle()%3];

    id1277out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1277in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1279out_result;

  { // Node ID: 1279 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1279in_a = id1278out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1279in_b = id1277out_o;

    id1279out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1279in_a,id1279in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1280out_result;

  { // Node ID: 1280 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1280in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1280in_option0 = id1279out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1280in_option1 = id1277out_o;

    HWOffsetFix<32,0,UNSIGNED> id1280x_1;

    switch((id1280in_sel.getValueAsLong())) {
      case 0l:
        id1280x_1 = id1280in_option0;
        break;
      case 1l:
        id1280x_1 = id1280in_option1;
        break;
      default:
        id1280x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1280out_result = (id1280x_1);
  }
  { // Node ID: 4024 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4024in_input = id1280out_result;

    id4024out_output[(getCycle()+1)%2] = id4024in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1266out_output;

  { // Node ID: 1266 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1266in_input = id4027out_output[getCycle()%2];

    id1266out_output = id1266in_input;
  }
  { // Node ID: 3284 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2788out_result;

  { // Node ID: 2788 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2788in_a = id3284out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2788in_b = id3511out_output[getCycle()%2];

    id2788out_result = (eq_fixed(id2788in_a,id2788in_b));
  }
  { // Node ID: 4028 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4028in_input = id2788out_result;

    id4028out_output[(getCycle()+2)%3] = id4028in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1265out_o;

  { // Node ID: 1265 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1265in_i = id4028out_output[getCycle()%3];

    id1265out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1265in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1267out_result;

  { // Node ID: 1267 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1267in_a = id1266out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1267in_b = id1265out_o;

    id1267out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1267in_a,id1267in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1268out_result;

  { // Node ID: 1268 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1268in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1268in_option0 = id1267out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1268in_option1 = id1265out_o;

    HWOffsetFix<32,0,UNSIGNED> id1268x_1;

    switch((id1268in_sel.getValueAsLong())) {
      case 0l:
        id1268x_1 = id1268in_option0;
        break;
      case 1l:
        id1268x_1 = id1268in_option1;
        break;
      default:
        id1268x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1268out_result = (id1268x_1);
  }
  { // Node ID: 4027 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4027in_input = id1268out_result;

    id4027out_output[(getCycle()+1)%2] = id4027in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1254out_output;

  { // Node ID: 1254 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1254in_input = id4030out_output[getCycle()%2];

    id1254out_output = id1254in_input;
  }
  { // Node ID: 3283 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2789out_result;

  { // Node ID: 2789 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2789in_a = id3283out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2789in_b = id3511out_output[getCycle()%2];

    id2789out_result = (eq_fixed(id2789in_a,id2789in_b));
  }
  { // Node ID: 4031 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4031in_input = id2789out_result;

    id4031out_output[(getCycle()+2)%3] = id4031in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1253out_o;

  { // Node ID: 1253 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1253in_i = id4031out_output[getCycle()%3];

    id1253out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1253in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1255out_result;

  { // Node ID: 1255 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1255in_a = id1254out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1255in_b = id1253out_o;

    id1255out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1255in_a,id1255in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1256out_result;

  { // Node ID: 1256 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1256in_sel = id3966out_output[getCycle()%7];
    const HWOffsetFix<32,0,UNSIGNED> &id1256in_option0 = id1255out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1256in_option1 = id1253out_o;

    HWOffsetFix<32,0,UNSIGNED> id1256x_1;

    switch((id1256in_sel.getValueAsLong())) {
      case 0l:
        id1256x_1 = id1256in_option0;
        break;
      case 1l:
        id1256x_1 = id1256in_option1;
        break;
      default:
        id1256x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1256out_result = (id1256x_1);
  }
  { // Node ID: 4030 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4030in_input = id1256out_result;

    id4030out_output[(getCycle()+1)%2] = id4030in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1242out_output;

  { // Node ID: 1242 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1242in_input = id4033out_output[getCycle()%2];

    id1242out_output = id1242in_input;
  }
  { // Node ID: 3282 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2790out_result;

  { // Node ID: 2790 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2790in_a = id3282out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2790in_b = id3511out_output[getCycle()%2];

    id2790out_result = (eq_fixed(id2790in_a,id2790in_b));
  }
  { // Node ID: 4034 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4034in_input = id2790out_result;

    id4034out_output[(getCycle()+2)%3] = id4034in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1241out_o;

  { // Node ID: 1241 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1241in_i = id4034out_output[getCycle()%3];

    id1241out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1241in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1243out_result;

  { // Node ID: 1243 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1243in_a = id1242out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1243in_b = id1241out_o;

    id1243out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1243in_a,id1243in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1244out_result;

  { // Node ID: 1244 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1244in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1244in_option0 = id1243out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1244in_option1 = id1241out_o;

    HWOffsetFix<32,0,UNSIGNED> id1244x_1;

    switch((id1244in_sel.getValueAsLong())) {
      case 0l:
        id1244x_1 = id1244in_option0;
        break;
      case 1l:
        id1244x_1 = id1244in_option1;
        break;
      default:
        id1244x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1244out_result = (id1244x_1);
  }
  { // Node ID: 4033 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4033in_input = id1244out_result;

    id4033out_output[(getCycle()+1)%2] = id4033in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1230out_output;

  { // Node ID: 1230 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1230in_input = id4036out_output[getCycle()%2];

    id1230out_output = id1230in_input;
  }
  { // Node ID: 3281 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2791out_result;

  { // Node ID: 2791 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2791in_a = id3281out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2791in_b = id3511out_output[getCycle()%2];

    id2791out_result = (eq_fixed(id2791in_a,id2791in_b));
  }
  { // Node ID: 4037 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4037in_input = id2791out_result;

    id4037out_output[(getCycle()+2)%3] = id4037in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1229out_o;

  { // Node ID: 1229 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1229in_i = id4037out_output[getCycle()%3];

    id1229out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1229in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1231out_result;

  { // Node ID: 1231 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1231in_a = id1230out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1231in_b = id1229out_o;

    id1231out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1231in_a,id1231in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1232out_result;

  { // Node ID: 1232 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1232in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1232in_option0 = id1231out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1232in_option1 = id1229out_o;

    HWOffsetFix<32,0,UNSIGNED> id1232x_1;

    switch((id1232in_sel.getValueAsLong())) {
      case 0l:
        id1232x_1 = id1232in_option0;
        break;
      case 1l:
        id1232x_1 = id1232in_option1;
        break;
      default:
        id1232x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1232out_result = (id1232x_1);
  }
  { // Node ID: 4036 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4036in_input = id1232out_result;

    id4036out_output[(getCycle()+1)%2] = id4036in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1218out_output;

  { // Node ID: 1218 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1218in_input = id4039out_output[getCycle()%2];

    id1218out_output = id1218in_input;
  }
  { // Node ID: 3280 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2792out_result;

  { // Node ID: 2792 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2792in_a = id3280out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2792in_b = id3511out_output[getCycle()%2];

    id2792out_result = (eq_fixed(id2792in_a,id2792in_b));
  }
  { // Node ID: 4040 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4040in_input = id2792out_result;

    id4040out_output[(getCycle()+2)%3] = id4040in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1217out_o;

  { // Node ID: 1217 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1217in_i = id4040out_output[getCycle()%3];

    id1217out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1217in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1219out_result;

  { // Node ID: 1219 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1219in_a = id1218out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1219in_b = id1217out_o;

    id1219out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1219in_a,id1219in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1220out_result;

  { // Node ID: 1220 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1220in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1220in_option0 = id1219out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1220in_option1 = id1217out_o;

    HWOffsetFix<32,0,UNSIGNED> id1220x_1;

    switch((id1220in_sel.getValueAsLong())) {
      case 0l:
        id1220x_1 = id1220in_option0;
        break;
      case 1l:
        id1220x_1 = id1220in_option1;
        break;
      default:
        id1220x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1220out_result = (id1220x_1);
  }
  { // Node ID: 4039 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4039in_input = id1220out_result;

    id4039out_output[(getCycle()+1)%2] = id4039in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1206out_output;

  { // Node ID: 1206 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1206in_input = id4042out_output[getCycle()%2];

    id1206out_output = id1206in_input;
  }
  { // Node ID: 3279 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2793out_result;

  { // Node ID: 2793 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2793in_a = id3279out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2793in_b = id3511out_output[getCycle()%2];

    id2793out_result = (eq_fixed(id2793in_a,id2793in_b));
  }
  { // Node ID: 4043 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4043in_input = id2793out_result;

    id4043out_output[(getCycle()+2)%3] = id4043in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1205out_o;

  { // Node ID: 1205 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1205in_i = id4043out_output[getCycle()%3];

    id1205out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1205in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1207out_result;

  { // Node ID: 1207 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1207in_a = id1206out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1207in_b = id1205out_o;

    id1207out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1207in_a,id1207in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1208out_result;

  { // Node ID: 1208 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1208in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1208in_option0 = id1207out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1208in_option1 = id1205out_o;

    HWOffsetFix<32,0,UNSIGNED> id1208x_1;

    switch((id1208in_sel.getValueAsLong())) {
      case 0l:
        id1208x_1 = id1208in_option0;
        break;
      case 1l:
        id1208x_1 = id1208in_option1;
        break;
      default:
        id1208x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1208out_result = (id1208x_1);
  }
  { // Node ID: 4042 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4042in_input = id1208out_result;

    id4042out_output[(getCycle()+1)%2] = id4042in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1194out_output;

  { // Node ID: 1194 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1194in_input = id4045out_output[getCycle()%2];

    id1194out_output = id1194in_input;
  }
  { // Node ID: 3278 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2794out_result;

  { // Node ID: 2794 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2794in_a = id3278out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2794in_b = id3511out_output[getCycle()%2];

    id2794out_result = (eq_fixed(id2794in_a,id2794in_b));
  }
  { // Node ID: 4046 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4046in_input = id2794out_result;

    id4046out_output[(getCycle()+2)%3] = id4046in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1193out_o;

  { // Node ID: 1193 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1193in_i = id4046out_output[getCycle()%3];

    id1193out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1193in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1195out_result;

  { // Node ID: 1195 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1195in_a = id1194out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1195in_b = id1193out_o;

    id1195out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1195in_a,id1195in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1196out_result;

  { // Node ID: 1196 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1196in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1196in_option0 = id1195out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1196in_option1 = id1193out_o;

    HWOffsetFix<32,0,UNSIGNED> id1196x_1;

    switch((id1196in_sel.getValueAsLong())) {
      case 0l:
        id1196x_1 = id1196in_option0;
        break;
      case 1l:
        id1196x_1 = id1196in_option1;
        break;
      default:
        id1196x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1196out_result = (id1196x_1);
  }
  { // Node ID: 4045 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4045in_input = id1196out_result;

    id4045out_output[(getCycle()+1)%2] = id4045in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1182out_output;

  { // Node ID: 1182 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1182in_input = id4048out_output[getCycle()%2];

    id1182out_output = id1182in_input;
  }
  { // Node ID: 3277 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2795out_result;

  { // Node ID: 2795 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2795in_a = id3277out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2795in_b = id3511out_output[getCycle()%2];

    id2795out_result = (eq_fixed(id2795in_a,id2795in_b));
  }
  { // Node ID: 4049 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4049in_input = id2795out_result;

    id4049out_output[(getCycle()+2)%3] = id4049in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1181out_o;

  { // Node ID: 1181 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1181in_i = id4049out_output[getCycle()%3];

    id1181out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1181in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1183out_result;

  { // Node ID: 1183 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1183in_a = id1182out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1183in_b = id1181out_o;

    id1183out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1183in_a,id1183in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1184out_result;

  { // Node ID: 1184 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1184in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1184in_option0 = id1183out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1184in_option1 = id1181out_o;

    HWOffsetFix<32,0,UNSIGNED> id1184x_1;

    switch((id1184in_sel.getValueAsLong())) {
      case 0l:
        id1184x_1 = id1184in_option0;
        break;
      case 1l:
        id1184x_1 = id1184in_option1;
        break;
      default:
        id1184x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1184out_result = (id1184x_1);
  }
  { // Node ID: 4048 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4048in_input = id1184out_result;

    id4048out_output[(getCycle()+1)%2] = id4048in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1170out_output;

  { // Node ID: 1170 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1170in_input = id4051out_output[getCycle()%2];

    id1170out_output = id1170in_input;
  }
  { // Node ID: 3276 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2796out_result;

  { // Node ID: 2796 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2796in_a = id3276out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2796in_b = id3511out_output[getCycle()%2];

    id2796out_result = (eq_fixed(id2796in_a,id2796in_b));
  }
  { // Node ID: 4052 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4052in_input = id2796out_result;

    id4052out_output[(getCycle()+2)%3] = id4052in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1169out_o;

  { // Node ID: 1169 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1169in_i = id4052out_output[getCycle()%3];

    id1169out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1169in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1171out_result;

  { // Node ID: 1171 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1171in_a = id1170out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1171in_b = id1169out_o;

    id1171out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1171in_a,id1171in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1172out_result;

  { // Node ID: 1172 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1172in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1172in_option0 = id1171out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1172in_option1 = id1169out_o;

    HWOffsetFix<32,0,UNSIGNED> id1172x_1;

    switch((id1172in_sel.getValueAsLong())) {
      case 0l:
        id1172x_1 = id1172in_option0;
        break;
      case 1l:
        id1172x_1 = id1172in_option1;
        break;
      default:
        id1172x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1172out_result = (id1172x_1);
  }
  { // Node ID: 4051 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4051in_input = id1172out_result;

    id4051out_output[(getCycle()+1)%2] = id4051in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1158out_output;

  { // Node ID: 1158 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1158in_input = id4054out_output[getCycle()%2];

    id1158out_output = id1158in_input;
  }
  { // Node ID: 3275 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2797out_result;

  { // Node ID: 2797 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2797in_a = id3275out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2797in_b = id3511out_output[getCycle()%2];

    id2797out_result = (eq_fixed(id2797in_a,id2797in_b));
  }
  { // Node ID: 4055 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4055in_input = id2797out_result;

    id4055out_output[(getCycle()+2)%3] = id4055in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1157out_o;

  { // Node ID: 1157 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1157in_i = id4055out_output[getCycle()%3];

    id1157out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1157in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1159out_result;

  { // Node ID: 1159 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1159in_a = id1158out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1159in_b = id1157out_o;

    id1159out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1159in_a,id1159in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1160out_result;

  { // Node ID: 1160 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1160in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1160in_option0 = id1159out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1160in_option1 = id1157out_o;

    HWOffsetFix<32,0,UNSIGNED> id1160x_1;

    switch((id1160in_sel.getValueAsLong())) {
      case 0l:
        id1160x_1 = id1160in_option0;
        break;
      case 1l:
        id1160x_1 = id1160in_option1;
        break;
      default:
        id1160x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1160out_result = (id1160x_1);
  }
  { // Node ID: 4054 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4054in_input = id1160out_result;

    id4054out_output[(getCycle()+1)%2] = id4054in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1146out_output;

  { // Node ID: 1146 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1146in_input = id4057out_output[getCycle()%2];

    id1146out_output = id1146in_input;
  }
  { // Node ID: 3274 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2798out_result;

  { // Node ID: 2798 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2798in_a = id3274out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2798in_b = id3511out_output[getCycle()%2];

    id2798out_result = (eq_fixed(id2798in_a,id2798in_b));
  }
  { // Node ID: 4058 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4058in_input = id2798out_result;

    id4058out_output[(getCycle()+2)%3] = id4058in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1145out_o;

  { // Node ID: 1145 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1145in_i = id4058out_output[getCycle()%3];

    id1145out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1145in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1147out_result;

  { // Node ID: 1147 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1147in_a = id1146out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1147in_b = id1145out_o;

    id1147out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1147in_a,id1147in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1148out_result;

  { // Node ID: 1148 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1148in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1148in_option0 = id1147out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1148in_option1 = id1145out_o;

    HWOffsetFix<32,0,UNSIGNED> id1148x_1;

    switch((id1148in_sel.getValueAsLong())) {
      case 0l:
        id1148x_1 = id1148in_option0;
        break;
      case 1l:
        id1148x_1 = id1148in_option1;
        break;
      default:
        id1148x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1148out_result = (id1148x_1);
  }
  { // Node ID: 4057 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4057in_input = id1148out_result;

    id4057out_output[(getCycle()+1)%2] = id4057in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1134out_output;

  { // Node ID: 1134 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1134in_input = id4060out_output[getCycle()%2];

    id1134out_output = id1134in_input;
  }
  { // Node ID: 3273 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2799out_result;

  { // Node ID: 2799 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2799in_a = id3273out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2799in_b = id3511out_output[getCycle()%2];

    id2799out_result = (eq_fixed(id2799in_a,id2799in_b));
  }
  { // Node ID: 4061 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4061in_input = id2799out_result;

    id4061out_output[(getCycle()+2)%3] = id4061in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1133out_o;

  { // Node ID: 1133 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1133in_i = id4061out_output[getCycle()%3];

    id1133out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1133in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1135out_result;

  { // Node ID: 1135 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1135in_a = id1134out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1135in_b = id1133out_o;

    id1135out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1135in_a,id1135in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1136out_result;

  { // Node ID: 1136 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1136in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1136in_option0 = id1135out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1136in_option1 = id1133out_o;

    HWOffsetFix<32,0,UNSIGNED> id1136x_1;

    switch((id1136in_sel.getValueAsLong())) {
      case 0l:
        id1136x_1 = id1136in_option0;
        break;
      case 1l:
        id1136x_1 = id1136in_option1;
        break;
      default:
        id1136x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1136out_result = (id1136x_1);
  }
  { // Node ID: 4060 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4060in_input = id1136out_result;

    id4060out_output[(getCycle()+1)%2] = id4060in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1122out_output;

  { // Node ID: 1122 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1122in_input = id4063out_output[getCycle()%2];

    id1122out_output = id1122in_input;
  }
  { // Node ID: 3272 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2800out_result;

  { // Node ID: 2800 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2800in_a = id3272out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2800in_b = id3511out_output[getCycle()%2];

    id2800out_result = (eq_fixed(id2800in_a,id2800in_b));
  }
  { // Node ID: 4064 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4064in_input = id2800out_result;

    id4064out_output[(getCycle()+2)%3] = id4064in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1121out_o;

  { // Node ID: 1121 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1121in_i = id4064out_output[getCycle()%3];

    id1121out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1121in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1123out_result;

  { // Node ID: 1123 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1123in_a = id1122out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1123in_b = id1121out_o;

    id1123out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1123in_a,id1123in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1124out_result;

  { // Node ID: 1124 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1124in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1124in_option0 = id1123out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1124in_option1 = id1121out_o;

    HWOffsetFix<32,0,UNSIGNED> id1124x_1;

    switch((id1124in_sel.getValueAsLong())) {
      case 0l:
        id1124x_1 = id1124in_option0;
        break;
      case 1l:
        id1124x_1 = id1124in_option1;
        break;
      default:
        id1124x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1124out_result = (id1124x_1);
  }
  { // Node ID: 4063 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4063in_input = id1124out_result;

    id4063out_output[(getCycle()+1)%2] = id4063in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1110out_output;

  { // Node ID: 1110 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1110in_input = id4066out_output[getCycle()%2];

    id1110out_output = id1110in_input;
  }
  { // Node ID: 3271 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2801out_result;

  { // Node ID: 2801 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2801in_a = id3271out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2801in_b = id3511out_output[getCycle()%2];

    id2801out_result = (eq_fixed(id2801in_a,id2801in_b));
  }
  { // Node ID: 4067 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4067in_input = id2801out_result;

    id4067out_output[(getCycle()+2)%3] = id4067in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1109out_o;

  { // Node ID: 1109 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1109in_i = id4067out_output[getCycle()%3];

    id1109out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1109in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1111out_result;

  { // Node ID: 1111 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1111in_a = id1110out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1111in_b = id1109out_o;

    id1111out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1111in_a,id1111in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1112out_result;

  { // Node ID: 1112 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1112in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1112in_option0 = id1111out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1112in_option1 = id1109out_o;

    HWOffsetFix<32,0,UNSIGNED> id1112x_1;

    switch((id1112in_sel.getValueAsLong())) {
      case 0l:
        id1112x_1 = id1112in_option0;
        break;
      case 1l:
        id1112x_1 = id1112in_option1;
        break;
      default:
        id1112x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1112out_result = (id1112x_1);
  }
  { // Node ID: 4066 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4066in_input = id1112out_result;

    id4066out_output[(getCycle()+1)%2] = id4066in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1098out_output;

  { // Node ID: 1098 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1098in_input = id4069out_output[getCycle()%2];

    id1098out_output = id1098in_input;
  }
  { // Node ID: 3270 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2802out_result;

  { // Node ID: 2802 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2802in_a = id3270out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2802in_b = id3511out_output[getCycle()%2];

    id2802out_result = (eq_fixed(id2802in_a,id2802in_b));
  }
  { // Node ID: 4070 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4070in_input = id2802out_result;

    id4070out_output[(getCycle()+2)%3] = id4070in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1097out_o;

  { // Node ID: 1097 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1097in_i = id4070out_output[getCycle()%3];

    id1097out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1097in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1099out_result;

  { // Node ID: 1099 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1099in_a = id1098out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1099in_b = id1097out_o;

    id1099out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1099in_a,id1099in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1100out_result;

  { // Node ID: 1100 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1100in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1100in_option0 = id1099out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1100in_option1 = id1097out_o;

    HWOffsetFix<32,0,UNSIGNED> id1100x_1;

    switch((id1100in_sel.getValueAsLong())) {
      case 0l:
        id1100x_1 = id1100in_option0;
        break;
      case 1l:
        id1100x_1 = id1100in_option1;
        break;
      default:
        id1100x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1100out_result = (id1100x_1);
  }
  { // Node ID: 4069 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4069in_input = id1100out_result;

    id4069out_output[(getCycle()+1)%2] = id4069in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1086out_output;

  { // Node ID: 1086 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1086in_input = id4072out_output[getCycle()%2];

    id1086out_output = id1086in_input;
  }
  { // Node ID: 3269 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2803out_result;

  { // Node ID: 2803 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2803in_a = id3269out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2803in_b = id3511out_output[getCycle()%2];

    id2803out_result = (eq_fixed(id2803in_a,id2803in_b));
  }
  { // Node ID: 4073 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4073in_input = id2803out_result;

    id4073out_output[(getCycle()+2)%3] = id4073in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1085out_o;

  { // Node ID: 1085 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1085in_i = id4073out_output[getCycle()%3];

    id1085out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1085in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1087out_result;

  { // Node ID: 1087 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1087in_a = id1086out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1087in_b = id1085out_o;

    id1087out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1087in_a,id1087in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1088out_result;

  { // Node ID: 1088 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1088in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1088in_option0 = id1087out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1088in_option1 = id1085out_o;

    HWOffsetFix<32,0,UNSIGNED> id1088x_1;

    switch((id1088in_sel.getValueAsLong())) {
      case 0l:
        id1088x_1 = id1088in_option0;
        break;
      case 1l:
        id1088x_1 = id1088in_option1;
        break;
      default:
        id1088x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1088out_result = (id1088x_1);
  }
  { // Node ID: 4072 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4072in_input = id1088out_result;

    id4072out_output[(getCycle()+1)%2] = id4072in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1074out_output;

  { // Node ID: 1074 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1074in_input = id4075out_output[getCycle()%2];

    id1074out_output = id1074in_input;
  }
  { // Node ID: 3268 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2804out_result;

  { // Node ID: 2804 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2804in_a = id3268out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2804in_b = id3511out_output[getCycle()%2];

    id2804out_result = (eq_fixed(id2804in_a,id2804in_b));
  }
  { // Node ID: 4076 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4076in_input = id2804out_result;

    id4076out_output[(getCycle()+2)%3] = id4076in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1073out_o;

  { // Node ID: 1073 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1073in_i = id4076out_output[getCycle()%3];

    id1073out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1073in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1075out_result;

  { // Node ID: 1075 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1075in_a = id1074out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1075in_b = id1073out_o;

    id1075out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1075in_a,id1075in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1076out_result;

  { // Node ID: 1076 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1076in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1076in_option0 = id1075out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1076in_option1 = id1073out_o;

    HWOffsetFix<32,0,UNSIGNED> id1076x_1;

    switch((id1076in_sel.getValueAsLong())) {
      case 0l:
        id1076x_1 = id1076in_option0;
        break;
      case 1l:
        id1076x_1 = id1076in_option1;
        break;
      default:
        id1076x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1076out_result = (id1076x_1);
  }
  { // Node ID: 4075 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4075in_input = id1076out_result;

    id4075out_output[(getCycle()+1)%2] = id4075in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1062out_output;

  { // Node ID: 1062 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1062in_input = id4078out_output[getCycle()%2];

    id1062out_output = id1062in_input;
  }
  { // Node ID: 3267 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2805out_result;

  { // Node ID: 2805 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2805in_a = id3267out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2805in_b = id3511out_output[getCycle()%2];

    id2805out_result = (eq_fixed(id2805in_a,id2805in_b));
  }
  { // Node ID: 4079 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4079in_input = id2805out_result;

    id4079out_output[(getCycle()+2)%3] = id4079in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1061out_o;

  { // Node ID: 1061 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1061in_i = id4079out_output[getCycle()%3];

    id1061out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1061in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1063out_result;

  { // Node ID: 1063 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1063in_a = id1062out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1063in_b = id1061out_o;

    id1063out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1063in_a,id1063in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1064out_result;

  { // Node ID: 1064 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1064in_sel = id4035out_output[getCycle()%6];
    const HWOffsetFix<32,0,UNSIGNED> &id1064in_option0 = id1063out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1064in_option1 = id1061out_o;

    HWOffsetFix<32,0,UNSIGNED> id1064x_1;

    switch((id1064in_sel.getValueAsLong())) {
      case 0l:
        id1064x_1 = id1064in_option0;
        break;
      case 1l:
        id1064x_1 = id1064in_option1;
        break;
      default:
        id1064x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1064out_result = (id1064x_1);
  }
  { // Node ID: 4078 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4078in_input = id1064out_result;

    id4078out_output[(getCycle()+1)%2] = id4078in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1050out_output;

  { // Node ID: 1050 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1050in_input = id4081out_output[getCycle()%2];

    id1050out_output = id1050in_input;
  }
  { // Node ID: 3266 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2806out_result;

  { // Node ID: 2806 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2806in_a = id3266out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2806in_b = id3511out_output[getCycle()%2];

    id2806out_result = (eq_fixed(id2806in_a,id2806in_b));
  }
  { // Node ID: 4082 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4082in_input = id2806out_result;

    id4082out_output[(getCycle()+2)%3] = id4082in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1049out_o;

  { // Node ID: 1049 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1049in_i = id4082out_output[getCycle()%3];

    id1049out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1049in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1051out_result;

  { // Node ID: 1051 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1051in_a = id1050out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1051in_b = id1049out_o;

    id1051out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1051in_a,id1051in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1052out_result;

  { // Node ID: 1052 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1052in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id1052in_option0 = id1051out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1052in_option1 = id1049out_o;

    HWOffsetFix<32,0,UNSIGNED> id1052x_1;

    switch((id1052in_sel.getValueAsLong())) {
      case 0l:
        id1052x_1 = id1052in_option0;
        break;
      case 1l:
        id1052x_1 = id1052in_option1;
        break;
      default:
        id1052x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1052out_result = (id1052x_1);
  }
  { // Node ID: 4081 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4081in_input = id1052out_result;

    id4081out_output[(getCycle()+1)%2] = id4081in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1038out_output;

  { // Node ID: 1038 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1038in_input = id4084out_output[getCycle()%2];

    id1038out_output = id1038in_input;
  }
  { // Node ID: 3265 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2807out_result;

  { // Node ID: 2807 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2807in_a = id3265out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2807in_b = id3512out_output[getCycle()%2];

    id2807out_result = (eq_fixed(id2807in_a,id2807in_b));
  }
  { // Node ID: 4085 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4085in_input = id2807out_result;

    id4085out_output[(getCycle()+3)%4] = id4085in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1037out_o;

  { // Node ID: 1037 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1037in_i = id4085out_output[getCycle()%4];

    id1037out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1037in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1039out_result;

  { // Node ID: 1039 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1039in_a = id1038out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1039in_b = id1037out_o;

    id1039out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1039in_a,id1039in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1040out_result;

  { // Node ID: 1040 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1040in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id1040in_option0 = id1039out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1040in_option1 = id1037out_o;

    HWOffsetFix<32,0,UNSIGNED> id1040x_1;

    switch((id1040in_sel.getValueAsLong())) {
      case 0l:
        id1040x_1 = id1040in_option0;
        break;
      case 1l:
        id1040x_1 = id1040in_option1;
        break;
      default:
        id1040x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1040out_result = (id1040x_1);
  }
  { // Node ID: 4084 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4084in_input = id1040out_result;

    id4084out_output[(getCycle()+1)%2] = id4084in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1026out_output;

  { // Node ID: 1026 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1026in_input = id4087out_output[getCycle()%2];

    id1026out_output = id1026in_input;
  }
  { // Node ID: 3264 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2808out_result;

  { // Node ID: 2808 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2808in_a = id3264out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2808in_b = id3512out_output[getCycle()%2];

    id2808out_result = (eq_fixed(id2808in_a,id2808in_b));
  }
  { // Node ID: 4088 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4088in_input = id2808out_result;

    id4088out_output[(getCycle()+3)%4] = id4088in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1025out_o;

  { // Node ID: 1025 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1025in_i = id4088out_output[getCycle()%4];

    id1025out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1025in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1027out_result;

  { // Node ID: 1027 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1027in_a = id1026out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1027in_b = id1025out_o;

    id1027out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1027in_a,id1027in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1028out_result;

  { // Node ID: 1028 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1028in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id1028in_option0 = id1027out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1028in_option1 = id1025out_o;

    HWOffsetFix<32,0,UNSIGNED> id1028x_1;

    switch((id1028in_sel.getValueAsLong())) {
      case 0l:
        id1028x_1 = id1028in_option0;
        break;
      case 1l:
        id1028x_1 = id1028in_option1;
        break;
      default:
        id1028x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1028out_result = (id1028x_1);
  }
  { // Node ID: 4087 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4087in_input = id1028out_result;

    id4087out_output[(getCycle()+1)%2] = id4087in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1014out_output;

  { // Node ID: 1014 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1014in_input = id4090out_output[getCycle()%2];

    id1014out_output = id1014in_input;
  }
  { // Node ID: 3263 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2809out_result;

  { // Node ID: 2809 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2809in_a = id3263out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2809in_b = id3512out_output[getCycle()%2];

    id2809out_result = (eq_fixed(id2809in_a,id2809in_b));
  }
  { // Node ID: 4091 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4091in_input = id2809out_result;

    id4091out_output[(getCycle()+3)%4] = id4091in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1013out_o;

  { // Node ID: 1013 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1013in_i = id4091out_output[getCycle()%4];

    id1013out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1013in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1015out_result;

  { // Node ID: 1015 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1015in_a = id1014out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1015in_b = id1013out_o;

    id1015out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1015in_a,id1015in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1016out_result;

  { // Node ID: 1016 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1016in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id1016in_option0 = id1015out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1016in_option1 = id1013out_o;

    HWOffsetFix<32,0,UNSIGNED> id1016x_1;

    switch((id1016in_sel.getValueAsLong())) {
      case 0l:
        id1016x_1 = id1016in_option0;
        break;
      case 1l:
        id1016x_1 = id1016in_option1;
        break;
      default:
        id1016x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1016out_result = (id1016x_1);
  }
  { // Node ID: 4090 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4090in_input = id1016out_result;

    id4090out_output[(getCycle()+1)%2] = id4090in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1002out_output;

  { // Node ID: 1002 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id1002in_input = id4093out_output[getCycle()%2];

    id1002out_output = id1002in_input;
  }
  { // Node ID: 3262 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2810out_result;

  { // Node ID: 2810 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2810in_a = id3262out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2810in_b = id3512out_output[getCycle()%2];

    id2810out_result = (eq_fixed(id2810in_a,id2810in_b));
  }
  { // Node ID: 4094 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4094in_input = id2810out_result;

    id4094out_output[(getCycle()+3)%4] = id4094in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id1001out_o;

  { // Node ID: 1001 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id1001in_i = id4094out_output[getCycle()%4];

    id1001out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id1001in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id1003out_result;

  { // Node ID: 1003 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id1003in_a = id1002out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id1003in_b = id1001out_o;

    id1003out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id1003in_a,id1003in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id1004out_result;

  { // Node ID: 1004 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1004in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id1004in_option0 = id1003out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id1004in_option1 = id1001out_o;

    HWOffsetFix<32,0,UNSIGNED> id1004x_1;

    switch((id1004in_sel.getValueAsLong())) {
      case 0l:
        id1004x_1 = id1004in_option0;
        break;
      case 1l:
        id1004x_1 = id1004in_option1;
        break;
      default:
        id1004x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1004out_result = (id1004x_1);
  }
  { // Node ID: 4093 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4093in_input = id1004out_result;

    id4093out_output[(getCycle()+1)%2] = id4093in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id990out_output;

  { // Node ID: 990 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id990in_input = id4096out_output[getCycle()%2];

    id990out_output = id990in_input;
  }
  { // Node ID: 3261 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2811out_result;

  { // Node ID: 2811 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2811in_a = id3261out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2811in_b = id3512out_output[getCycle()%2];

    id2811out_result = (eq_fixed(id2811in_a,id2811in_b));
  }
  { // Node ID: 4097 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4097in_input = id2811out_result;

    id4097out_output[(getCycle()+3)%4] = id4097in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id989out_o;

  { // Node ID: 989 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id989in_i = id4097out_output[getCycle()%4];

    id989out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id989in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id991out_result;

  { // Node ID: 991 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id991in_a = id990out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id991in_b = id989out_o;

    id991out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id991in_a,id991in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id992out_result;

  { // Node ID: 992 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id992in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id992in_option0 = id991out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id992in_option1 = id989out_o;

    HWOffsetFix<32,0,UNSIGNED> id992x_1;

    switch((id992in_sel.getValueAsLong())) {
      case 0l:
        id992x_1 = id992in_option0;
        break;
      case 1l:
        id992x_1 = id992in_option1;
        break;
      default:
        id992x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id992out_result = (id992x_1);
  }
  { // Node ID: 4096 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4096in_input = id992out_result;

    id4096out_output[(getCycle()+1)%2] = id4096in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id978out_output;

  { // Node ID: 978 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id978in_input = id4099out_output[getCycle()%2];

    id978out_output = id978in_input;
  }
  { // Node ID: 3260 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2812out_result;

  { // Node ID: 2812 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2812in_a = id3260out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2812in_b = id3512out_output[getCycle()%2];

    id2812out_result = (eq_fixed(id2812in_a,id2812in_b));
  }
  { // Node ID: 4100 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4100in_input = id2812out_result;

    id4100out_output[(getCycle()+3)%4] = id4100in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id977out_o;

  { // Node ID: 977 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id977in_i = id4100out_output[getCycle()%4];

    id977out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id977in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id979out_result;

  { // Node ID: 979 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id979in_a = id978out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id979in_b = id977out_o;

    id979out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id979in_a,id979in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id980out_result;

  { // Node ID: 980 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id980in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id980in_option0 = id979out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id980in_option1 = id977out_o;

    HWOffsetFix<32,0,UNSIGNED> id980x_1;

    switch((id980in_sel.getValueAsLong())) {
      case 0l:
        id980x_1 = id980in_option0;
        break;
      case 1l:
        id980x_1 = id980in_option1;
        break;
      default:
        id980x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id980out_result = (id980x_1);
  }
  { // Node ID: 4099 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4099in_input = id980out_result;

    id4099out_output[(getCycle()+1)%2] = id4099in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id966out_output;

  { // Node ID: 966 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id966in_input = id4102out_output[getCycle()%2];

    id966out_output = id966in_input;
  }
  { // Node ID: 3259 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2813out_result;

  { // Node ID: 2813 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2813in_a = id3259out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2813in_b = id3512out_output[getCycle()%2];

    id2813out_result = (eq_fixed(id2813in_a,id2813in_b));
  }
  { // Node ID: 4103 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4103in_input = id2813out_result;

    id4103out_output[(getCycle()+3)%4] = id4103in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id965out_o;

  { // Node ID: 965 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id965in_i = id4103out_output[getCycle()%4];

    id965out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id965in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id967out_result;

  { // Node ID: 967 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id967in_a = id966out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id967in_b = id965out_o;

    id967out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id967in_a,id967in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id968out_result;

  { // Node ID: 968 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id968in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id968in_option0 = id967out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id968in_option1 = id965out_o;

    HWOffsetFix<32,0,UNSIGNED> id968x_1;

    switch((id968in_sel.getValueAsLong())) {
      case 0l:
        id968x_1 = id968in_option0;
        break;
      case 1l:
        id968x_1 = id968in_option1;
        break;
      default:
        id968x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id968out_result = (id968x_1);
  }
  { // Node ID: 4102 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4102in_input = id968out_result;

    id4102out_output[(getCycle()+1)%2] = id4102in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id954out_output;

  { // Node ID: 954 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id954in_input = id4105out_output[getCycle()%2];

    id954out_output = id954in_input;
  }
  { // Node ID: 3258 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2814out_result;

  { // Node ID: 2814 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2814in_a = id3258out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2814in_b = id3512out_output[getCycle()%2];

    id2814out_result = (eq_fixed(id2814in_a,id2814in_b));
  }
  { // Node ID: 4106 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4106in_input = id2814out_result;

    id4106out_output[(getCycle()+3)%4] = id4106in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id953out_o;

  { // Node ID: 953 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id953in_i = id4106out_output[getCycle()%4];

    id953out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id953in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id955out_result;

  { // Node ID: 955 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id955in_a = id954out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id955in_b = id953out_o;

    id955out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id955in_a,id955in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id956out_result;

  { // Node ID: 956 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id956in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id956in_option0 = id955out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id956in_option1 = id953out_o;

    HWOffsetFix<32,0,UNSIGNED> id956x_1;

    switch((id956in_sel.getValueAsLong())) {
      case 0l:
        id956x_1 = id956in_option0;
        break;
      case 1l:
        id956x_1 = id956in_option1;
        break;
      default:
        id956x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id956out_result = (id956x_1);
  }
  { // Node ID: 4105 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4105in_input = id956out_result;

    id4105out_output[(getCycle()+1)%2] = id4105in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id942out_output;

  { // Node ID: 942 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id942in_input = id4108out_output[getCycle()%2];

    id942out_output = id942in_input;
  }
  { // Node ID: 3257 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2815out_result;

  { // Node ID: 2815 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2815in_a = id3257out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2815in_b = id3512out_output[getCycle()%2];

    id2815out_result = (eq_fixed(id2815in_a,id2815in_b));
  }
  { // Node ID: 4109 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4109in_input = id2815out_result;

    id4109out_output[(getCycle()+3)%4] = id4109in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id941out_o;

  { // Node ID: 941 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id941in_i = id4109out_output[getCycle()%4];

    id941out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id941in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id943out_result;

  { // Node ID: 943 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id943in_a = id942out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id943in_b = id941out_o;

    id943out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id943in_a,id943in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id944out_result;

  { // Node ID: 944 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id944in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id944in_option0 = id943out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id944in_option1 = id941out_o;

    HWOffsetFix<32,0,UNSIGNED> id944x_1;

    switch((id944in_sel.getValueAsLong())) {
      case 0l:
        id944x_1 = id944in_option0;
        break;
      case 1l:
        id944x_1 = id944in_option1;
        break;
      default:
        id944x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id944out_result = (id944x_1);
  }
  { // Node ID: 4108 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4108in_input = id944out_result;

    id4108out_output[(getCycle()+1)%2] = id4108in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id930out_output;

  { // Node ID: 930 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id930in_input = id4111out_output[getCycle()%2];

    id930out_output = id930in_input;
  }
  { // Node ID: 3256 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2816out_result;

  { // Node ID: 2816 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2816in_a = id3256out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2816in_b = id3512out_output[getCycle()%2];

    id2816out_result = (eq_fixed(id2816in_a,id2816in_b));
  }
  { // Node ID: 4112 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4112in_input = id2816out_result;

    id4112out_output[(getCycle()+3)%4] = id4112in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id929out_o;

  { // Node ID: 929 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id929in_i = id4112out_output[getCycle()%4];

    id929out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id929in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id931out_result;

  { // Node ID: 931 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id931in_a = id930out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id931in_b = id929out_o;

    id931out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id931in_a,id931in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id932out_result;

  { // Node ID: 932 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id932in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id932in_option0 = id931out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id932in_option1 = id929out_o;

    HWOffsetFix<32,0,UNSIGNED> id932x_1;

    switch((id932in_sel.getValueAsLong())) {
      case 0l:
        id932x_1 = id932in_option0;
        break;
      case 1l:
        id932x_1 = id932in_option1;
        break;
      default:
        id932x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id932out_result = (id932x_1);
  }
  { // Node ID: 4111 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4111in_input = id932out_result;

    id4111out_output[(getCycle()+1)%2] = id4111in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id918out_output;

  { // Node ID: 918 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id918in_input = id4114out_output[getCycle()%2];

    id918out_output = id918in_input;
  }
  { // Node ID: 3255 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2817out_result;

  { // Node ID: 2817 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2817in_a = id3255out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2817in_b = id3512out_output[getCycle()%2];

    id2817out_result = (eq_fixed(id2817in_a,id2817in_b));
  }
  { // Node ID: 4115 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4115in_input = id2817out_result;

    id4115out_output[(getCycle()+3)%4] = id4115in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id917out_o;

  { // Node ID: 917 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id917in_i = id4115out_output[getCycle()%4];

    id917out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id917in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id919out_result;

  { // Node ID: 919 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id919in_a = id918out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id919in_b = id917out_o;

    id919out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id919in_a,id919in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id920out_result;

  { // Node ID: 920 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id920in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id920in_option0 = id919out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id920in_option1 = id917out_o;

    HWOffsetFix<32,0,UNSIGNED> id920x_1;

    switch((id920in_sel.getValueAsLong())) {
      case 0l:
        id920x_1 = id920in_option0;
        break;
      case 1l:
        id920x_1 = id920in_option1;
        break;
      default:
        id920x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id920out_result = (id920x_1);
  }
  { // Node ID: 4114 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4114in_input = id920out_result;

    id4114out_output[(getCycle()+1)%2] = id4114in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id906out_output;

  { // Node ID: 906 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id906in_input = id4117out_output[getCycle()%2];

    id906out_output = id906in_input;
  }
  { // Node ID: 3254 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2818out_result;

  { // Node ID: 2818 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2818in_a = id3254out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2818in_b = id3512out_output[getCycle()%2];

    id2818out_result = (eq_fixed(id2818in_a,id2818in_b));
  }
  { // Node ID: 4118 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4118in_input = id2818out_result;

    id4118out_output[(getCycle()+3)%4] = id4118in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id905out_o;

  { // Node ID: 905 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id905in_i = id4118out_output[getCycle()%4];

    id905out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id905in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id907out_result;

  { // Node ID: 907 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id907in_a = id906out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id907in_b = id905out_o;

    id907out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id907in_a,id907in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id908out_result;

  { // Node ID: 908 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id908in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id908in_option0 = id907out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id908in_option1 = id905out_o;

    HWOffsetFix<32,0,UNSIGNED> id908x_1;

    switch((id908in_sel.getValueAsLong())) {
      case 0l:
        id908x_1 = id908in_option0;
        break;
      case 1l:
        id908x_1 = id908in_option1;
        break;
      default:
        id908x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id908out_result = (id908x_1);
  }
  { // Node ID: 4117 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4117in_input = id908out_result;

    id4117out_output[(getCycle()+1)%2] = id4117in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id894out_output;

  { // Node ID: 894 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id894in_input = id4120out_output[getCycle()%2];

    id894out_output = id894in_input;
  }
  { // Node ID: 3253 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2819out_result;

  { // Node ID: 2819 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2819in_a = id3253out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2819in_b = id3512out_output[getCycle()%2];

    id2819out_result = (eq_fixed(id2819in_a,id2819in_b));
  }
  { // Node ID: 4121 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4121in_input = id2819out_result;

    id4121out_output[(getCycle()+3)%4] = id4121in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id893out_o;

  { // Node ID: 893 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id893in_i = id4121out_output[getCycle()%4];

    id893out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id893in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id895out_result;

  { // Node ID: 895 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id895in_a = id894out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id895in_b = id893out_o;

    id895out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id895in_a,id895in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id896out_result;

  { // Node ID: 896 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id896in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id896in_option0 = id895out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id896in_option1 = id893out_o;

    HWOffsetFix<32,0,UNSIGNED> id896x_1;

    switch((id896in_sel.getValueAsLong())) {
      case 0l:
        id896x_1 = id896in_option0;
        break;
      case 1l:
        id896x_1 = id896in_option1;
        break;
      default:
        id896x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id896out_result = (id896x_1);
  }
  { // Node ID: 4120 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4120in_input = id896out_result;

    id4120out_output[(getCycle()+1)%2] = id4120in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id882out_output;

  { // Node ID: 882 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id882in_input = id4123out_output[getCycle()%2];

    id882out_output = id882in_input;
  }
  { // Node ID: 3252 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2820out_result;

  { // Node ID: 2820 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2820in_a = id3252out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2820in_b = id3512out_output[getCycle()%2];

    id2820out_result = (eq_fixed(id2820in_a,id2820in_b));
  }
  { // Node ID: 4124 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4124in_input = id2820out_result;

    id4124out_output[(getCycle()+3)%4] = id4124in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id881out_o;

  { // Node ID: 881 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id881in_i = id4124out_output[getCycle()%4];

    id881out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id881in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id883out_result;

  { // Node ID: 883 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id883in_a = id882out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id883in_b = id881out_o;

    id883out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id883in_a,id883in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id884out_result;

  { // Node ID: 884 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id884in_sel = id3615out_output[getCycle()%5];
    const HWOffsetFix<32,0,UNSIGNED> &id884in_option0 = id883out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id884in_option1 = id881out_o;

    HWOffsetFix<32,0,UNSIGNED> id884x_1;

    switch((id884in_sel.getValueAsLong())) {
      case 0l:
        id884x_1 = id884in_option0;
        break;
      case 1l:
        id884x_1 = id884in_option1;
        break;
      default:
        id884x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id884out_result = (id884x_1);
  }
  { // Node ID: 4123 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4123in_input = id884out_result;

    id4123out_output[(getCycle()+1)%2] = id4123in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id870out_output;

  { // Node ID: 870 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id870in_input = id4126out_output[getCycle()%2];

    id870out_output = id870in_input;
  }
  { // Node ID: 3251 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2821out_result;

  { // Node ID: 2821 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2821in_a = id3251out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2821in_b = id3512out_output[getCycle()%2];

    id2821out_result = (eq_fixed(id2821in_a,id2821in_b));
  }
  { // Node ID: 4127 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4127in_input = id2821out_result;

    id4127out_output[(getCycle()+3)%4] = id4127in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id869out_o;

  { // Node ID: 869 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id869in_i = id4127out_output[getCycle()%4];

    id869out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id869in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id871out_result;

  { // Node ID: 871 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id871in_a = id870out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id871in_b = id869out_o;

    id871out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id871in_a,id871in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id872out_result;

  { // Node ID: 872 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id872in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id872in_option0 = id871out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id872in_option1 = id869out_o;

    HWOffsetFix<32,0,UNSIGNED> id872x_1;

    switch((id872in_sel.getValueAsLong())) {
      case 0l:
        id872x_1 = id872in_option0;
        break;
      case 1l:
        id872x_1 = id872in_option1;
        break;
      default:
        id872x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id872out_result = (id872x_1);
  }
  { // Node ID: 4126 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4126in_input = id872out_result;

    id4126out_output[(getCycle()+1)%2] = id4126in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id858out_output;

  { // Node ID: 858 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id858in_input = id4129out_output[getCycle()%2];

    id858out_output = id858in_input;
  }
  { // Node ID: 3250 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2822out_result;

  { // Node ID: 2822 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2822in_a = id3250out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2822in_b = id3512out_output[getCycle()%2];

    id2822out_result = (eq_fixed(id2822in_a,id2822in_b));
  }
  { // Node ID: 4130 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4130in_input = id2822out_result;

    id4130out_output[(getCycle()+3)%4] = id4130in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id857out_o;

  { // Node ID: 857 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id857in_i = id4130out_output[getCycle()%4];

    id857out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id857in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id859out_result;

  { // Node ID: 859 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id859in_a = id858out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id859in_b = id857out_o;

    id859out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id859in_a,id859in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id860out_result;

  { // Node ID: 860 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id860in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id860in_option0 = id859out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id860in_option1 = id857out_o;

    HWOffsetFix<32,0,UNSIGNED> id860x_1;

    switch((id860in_sel.getValueAsLong())) {
      case 0l:
        id860x_1 = id860in_option0;
        break;
      case 1l:
        id860x_1 = id860in_option1;
        break;
      default:
        id860x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id860out_result = (id860x_1);
  }
  { // Node ID: 4129 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4129in_input = id860out_result;

    id4129out_output[(getCycle()+1)%2] = id4129in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id846out_output;

  { // Node ID: 846 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id846in_input = id4132out_output[getCycle()%2];

    id846out_output = id846in_input;
  }
  { // Node ID: 3249 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2823out_result;

  { // Node ID: 2823 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2823in_a = id3249out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2823in_b = id3512out_output[getCycle()%2];

    id2823out_result = (eq_fixed(id2823in_a,id2823in_b));
  }
  { // Node ID: 4133 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4133in_input = id2823out_result;

    id4133out_output[(getCycle()+3)%4] = id4133in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id845out_o;

  { // Node ID: 845 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id845in_i = id4133out_output[getCycle()%4];

    id845out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id845in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id847out_result;

  { // Node ID: 847 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id847in_a = id846out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id847in_b = id845out_o;

    id847out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id847in_a,id847in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id848out_result;

  { // Node ID: 848 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id848in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id848in_option0 = id847out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id848in_option1 = id845out_o;

    HWOffsetFix<32,0,UNSIGNED> id848x_1;

    switch((id848in_sel.getValueAsLong())) {
      case 0l:
        id848x_1 = id848in_option0;
        break;
      case 1l:
        id848x_1 = id848in_option1;
        break;
      default:
        id848x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id848out_result = (id848x_1);
  }
  { // Node ID: 4132 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4132in_input = id848out_result;

    id4132out_output[(getCycle()+1)%2] = id4132in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id834out_output;

  { // Node ID: 834 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id834in_input = id4135out_output[getCycle()%2];

    id834out_output = id834in_input;
  }
  { // Node ID: 3248 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2824out_result;

  { // Node ID: 2824 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2824in_a = id3248out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2824in_b = id3512out_output[getCycle()%2];

    id2824out_result = (eq_fixed(id2824in_a,id2824in_b));
  }
  { // Node ID: 4136 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4136in_input = id2824out_result;

    id4136out_output[(getCycle()+3)%4] = id4136in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id833out_o;

  { // Node ID: 833 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id833in_i = id4136out_output[getCycle()%4];

    id833out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id833in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id835out_result;

  { // Node ID: 835 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id835in_a = id834out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id835in_b = id833out_o;

    id835out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id835in_a,id835in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id836out_result;

  { // Node ID: 836 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id836in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id836in_option0 = id835out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id836in_option1 = id833out_o;

    HWOffsetFix<32,0,UNSIGNED> id836x_1;

    switch((id836in_sel.getValueAsLong())) {
      case 0l:
        id836x_1 = id836in_option0;
        break;
      case 1l:
        id836x_1 = id836in_option1;
        break;
      default:
        id836x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id836out_result = (id836x_1);
  }
  { // Node ID: 4135 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4135in_input = id836out_result;

    id4135out_output[(getCycle()+1)%2] = id4135in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id822out_output;

  { // Node ID: 822 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id822in_input = id4138out_output[getCycle()%2];

    id822out_output = id822in_input;
  }
  { // Node ID: 3247 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2825out_result;

  { // Node ID: 2825 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2825in_a = id3247out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2825in_b = id3512out_output[getCycle()%2];

    id2825out_result = (eq_fixed(id2825in_a,id2825in_b));
  }
  { // Node ID: 4139 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4139in_input = id2825out_result;

    id4139out_output[(getCycle()+3)%4] = id4139in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id821out_o;

  { // Node ID: 821 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id821in_i = id4139out_output[getCycle()%4];

    id821out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id821in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id823out_result;

  { // Node ID: 823 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id823in_a = id822out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id823in_b = id821out_o;

    id823out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id823in_a,id823in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id824out_result;

  { // Node ID: 824 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id824in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id824in_option0 = id823out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id824in_option1 = id821out_o;

    HWOffsetFix<32,0,UNSIGNED> id824x_1;

    switch((id824in_sel.getValueAsLong())) {
      case 0l:
        id824x_1 = id824in_option0;
        break;
      case 1l:
        id824x_1 = id824in_option1;
        break;
      default:
        id824x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id824out_result = (id824x_1);
  }
  { // Node ID: 4138 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4138in_input = id824out_result;

    id4138out_output[(getCycle()+1)%2] = id4138in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id810out_output;

  { // Node ID: 810 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id810in_input = id4141out_output[getCycle()%2];

    id810out_output = id810in_input;
  }
  { // Node ID: 3246 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2826out_result;

  { // Node ID: 2826 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2826in_a = id3246out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2826in_b = id3512out_output[getCycle()%2];

    id2826out_result = (eq_fixed(id2826in_a,id2826in_b));
  }
  { // Node ID: 4142 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4142in_input = id2826out_result;

    id4142out_output[(getCycle()+3)%4] = id4142in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id809out_o;

  { // Node ID: 809 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id809in_i = id4142out_output[getCycle()%4];

    id809out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id809in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id811out_result;

  { // Node ID: 811 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id811in_a = id810out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id811in_b = id809out_o;

    id811out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id811in_a,id811in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id812out_result;

  { // Node ID: 812 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id812in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id812in_option0 = id811out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id812in_option1 = id809out_o;

    HWOffsetFix<32,0,UNSIGNED> id812x_1;

    switch((id812in_sel.getValueAsLong())) {
      case 0l:
        id812x_1 = id812in_option0;
        break;
      case 1l:
        id812x_1 = id812in_option1;
        break;
      default:
        id812x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id812out_result = (id812x_1);
  }
  { // Node ID: 4141 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4141in_input = id812out_result;

    id4141out_output[(getCycle()+1)%2] = id4141in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id798out_output;

  { // Node ID: 798 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id798in_input = id4144out_output[getCycle()%2];

    id798out_output = id798in_input;
  }
  { // Node ID: 3245 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2827out_result;

  { // Node ID: 2827 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2827in_a = id3245out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2827in_b = id3512out_output[getCycle()%2];

    id2827out_result = (eq_fixed(id2827in_a,id2827in_b));
  }
  { // Node ID: 4145 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4145in_input = id2827out_result;

    id4145out_output[(getCycle()+3)%4] = id4145in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id797out_o;

  { // Node ID: 797 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id797in_i = id4145out_output[getCycle()%4];

    id797out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id797in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id799out_result;

  { // Node ID: 799 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id799in_a = id798out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id799in_b = id797out_o;

    id799out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id799in_a,id799in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id800out_result;

  { // Node ID: 800 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id800in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id800in_option0 = id799out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id800in_option1 = id797out_o;

    HWOffsetFix<32,0,UNSIGNED> id800x_1;

    switch((id800in_sel.getValueAsLong())) {
      case 0l:
        id800x_1 = id800in_option0;
        break;
      case 1l:
        id800x_1 = id800in_option1;
        break;
      default:
        id800x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id800out_result = (id800x_1);
  }
  { // Node ID: 4144 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4144in_input = id800out_result;

    id4144out_output[(getCycle()+1)%2] = id4144in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id786out_output;

  { // Node ID: 786 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id786in_input = id4147out_output[getCycle()%2];

    id786out_output = id786in_input;
  }
  { // Node ID: 3244 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2828out_result;

  { // Node ID: 2828 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2828in_a = id3244out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2828in_b = id3512out_output[getCycle()%2];

    id2828out_result = (eq_fixed(id2828in_a,id2828in_b));
  }
  { // Node ID: 4148 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4148in_input = id2828out_result;

    id4148out_output[(getCycle()+3)%4] = id4148in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id785out_o;

  { // Node ID: 785 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id785in_i = id4148out_output[getCycle()%4];

    id785out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id785in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id787out_result;

  { // Node ID: 787 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id787in_a = id786out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id787in_b = id785out_o;

    id787out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id787in_a,id787in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id788out_result;

  { // Node ID: 788 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id788in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id788in_option0 = id787out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id788in_option1 = id785out_o;

    HWOffsetFix<32,0,UNSIGNED> id788x_1;

    switch((id788in_sel.getValueAsLong())) {
      case 0l:
        id788x_1 = id788in_option0;
        break;
      case 1l:
        id788x_1 = id788in_option1;
        break;
      default:
        id788x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id788out_result = (id788x_1);
  }
  { // Node ID: 4147 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4147in_input = id788out_result;

    id4147out_output[(getCycle()+1)%2] = id4147in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id774out_output;

  { // Node ID: 774 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id774in_input = id4150out_output[getCycle()%2];

    id774out_output = id774in_input;
  }
  { // Node ID: 3243 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2829out_result;

  { // Node ID: 2829 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2829in_a = id3243out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2829in_b = id3512out_output[getCycle()%2];

    id2829out_result = (eq_fixed(id2829in_a,id2829in_b));
  }
  { // Node ID: 4151 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4151in_input = id2829out_result;

    id4151out_output[(getCycle()+3)%4] = id4151in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id773out_o;

  { // Node ID: 773 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id773in_i = id4151out_output[getCycle()%4];

    id773out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id773in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id775out_result;

  { // Node ID: 775 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id775in_a = id774out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id775in_b = id773out_o;

    id775out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id775in_a,id775in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id776out_result;

  { // Node ID: 776 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id776in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id776in_option0 = id775out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id776in_option1 = id773out_o;

    HWOffsetFix<32,0,UNSIGNED> id776x_1;

    switch((id776in_sel.getValueAsLong())) {
      case 0l:
        id776x_1 = id776in_option0;
        break;
      case 1l:
        id776x_1 = id776in_option1;
        break;
      default:
        id776x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id776out_result = (id776x_1);
  }
  { // Node ID: 4150 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4150in_input = id776out_result;

    id4150out_output[(getCycle()+1)%2] = id4150in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id762out_output;

  { // Node ID: 762 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id762in_input = id4153out_output[getCycle()%2];

    id762out_output = id762in_input;
  }
  { // Node ID: 3242 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2830out_result;

  { // Node ID: 2830 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2830in_a = id3242out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2830in_b = id3512out_output[getCycle()%2];

    id2830out_result = (eq_fixed(id2830in_a,id2830in_b));
  }
  { // Node ID: 4154 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4154in_input = id2830out_result;

    id4154out_output[(getCycle()+3)%4] = id4154in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id761out_o;

  { // Node ID: 761 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id761in_i = id4154out_output[getCycle()%4];

    id761out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id761in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id763out_result;

  { // Node ID: 763 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id763in_a = id762out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id763in_b = id761out_o;

    id763out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id763in_a,id763in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id764out_result;

  { // Node ID: 764 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id764in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id764in_option0 = id763out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id764in_option1 = id761out_o;

    HWOffsetFix<32,0,UNSIGNED> id764x_1;

    switch((id764in_sel.getValueAsLong())) {
      case 0l:
        id764x_1 = id764in_option0;
        break;
      case 1l:
        id764x_1 = id764in_option1;
        break;
      default:
        id764x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id764out_result = (id764x_1);
  }
  { // Node ID: 4153 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4153in_input = id764out_result;

    id4153out_output[(getCycle()+1)%2] = id4153in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id750out_output;

  { // Node ID: 750 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id750in_input = id4156out_output[getCycle()%2];

    id750out_output = id750in_input;
  }
  { // Node ID: 3241 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2831out_result;

  { // Node ID: 2831 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2831in_a = id3241out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2831in_b = id3512out_output[getCycle()%2];

    id2831out_result = (eq_fixed(id2831in_a,id2831in_b));
  }
  { // Node ID: 4157 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4157in_input = id2831out_result;

    id4157out_output[(getCycle()+3)%4] = id4157in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id749out_o;

  { // Node ID: 749 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id749in_i = id4157out_output[getCycle()%4];

    id749out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id749in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id751out_result;

  { // Node ID: 751 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id751in_a = id750out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id751in_b = id749out_o;

    id751out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id751in_a,id751in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id752out_result;

  { // Node ID: 752 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id752in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id752in_option0 = id751out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id752in_option1 = id749out_o;

    HWOffsetFix<32,0,UNSIGNED> id752x_1;

    switch((id752in_sel.getValueAsLong())) {
      case 0l:
        id752x_1 = id752in_option0;
        break;
      case 1l:
        id752x_1 = id752in_option1;
        break;
      default:
        id752x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id752out_result = (id752x_1);
  }
  { // Node ID: 4156 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4156in_input = id752out_result;

    id4156out_output[(getCycle()+1)%2] = id4156in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id738out_output;

  { // Node ID: 738 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id738in_input = id4159out_output[getCycle()%2];

    id738out_output = id738in_input;
  }
  { // Node ID: 3240 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2832out_result;

  { // Node ID: 2832 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2832in_a = id3240out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2832in_b = id3512out_output[getCycle()%2];

    id2832out_result = (eq_fixed(id2832in_a,id2832in_b));
  }
  { // Node ID: 4160 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4160in_input = id2832out_result;

    id4160out_output[(getCycle()+3)%4] = id4160in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id737out_o;

  { // Node ID: 737 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id737in_i = id4160out_output[getCycle()%4];

    id737out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id737in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id739out_result;

  { // Node ID: 739 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id739in_a = id738out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id739in_b = id737out_o;

    id739out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id739in_a,id739in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id740out_result;

  { // Node ID: 740 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id740in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id740in_option0 = id739out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id740in_option1 = id737out_o;

    HWOffsetFix<32,0,UNSIGNED> id740x_1;

    switch((id740in_sel.getValueAsLong())) {
      case 0l:
        id740x_1 = id740in_option0;
        break;
      case 1l:
        id740x_1 = id740in_option1;
        break;
      default:
        id740x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id740out_result = (id740x_1);
  }
  { // Node ID: 4159 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4159in_input = id740out_result;

    id4159out_output[(getCycle()+1)%2] = id4159in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id726out_output;

  { // Node ID: 726 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id726in_input = id4162out_output[getCycle()%2];

    id726out_output = id726in_input;
  }
  { // Node ID: 3239 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2833out_result;

  { // Node ID: 2833 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2833in_a = id3239out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2833in_b = id3512out_output[getCycle()%2];

    id2833out_result = (eq_fixed(id2833in_a,id2833in_b));
  }
  { // Node ID: 4163 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4163in_input = id2833out_result;

    id4163out_output[(getCycle()+3)%4] = id4163in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id725out_o;

  { // Node ID: 725 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id725in_i = id4163out_output[getCycle()%4];

    id725out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id725in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id727out_result;

  { // Node ID: 727 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id727in_a = id726out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id727in_b = id725out_o;

    id727out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id727in_a,id727in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id728out_result;

  { // Node ID: 728 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id728in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id728in_option0 = id727out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id728in_option1 = id725out_o;

    HWOffsetFix<32,0,UNSIGNED> id728x_1;

    switch((id728in_sel.getValueAsLong())) {
      case 0l:
        id728x_1 = id728in_option0;
        break;
      case 1l:
        id728x_1 = id728in_option1;
        break;
      default:
        id728x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id728out_result = (id728x_1);
  }
  { // Node ID: 4162 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4162in_input = id728out_result;

    id4162out_output[(getCycle()+1)%2] = id4162in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id714out_output;

  { // Node ID: 714 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id714in_input = id4165out_output[getCycle()%2];

    id714out_output = id714in_input;
  }
  { // Node ID: 3238 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2834out_result;

  { // Node ID: 2834 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2834in_a = id3238out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2834in_b = id3512out_output[getCycle()%2];

    id2834out_result = (eq_fixed(id2834in_a,id2834in_b));
  }
  { // Node ID: 4166 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4166in_input = id2834out_result;

    id4166out_output[(getCycle()+3)%4] = id4166in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id713out_o;

  { // Node ID: 713 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id713in_i = id4166out_output[getCycle()%4];

    id713out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id713in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id715out_result;

  { // Node ID: 715 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id715in_a = id714out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id715in_b = id713out_o;

    id715out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id715in_a,id715in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id716out_result;

  { // Node ID: 716 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id716in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id716in_option0 = id715out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id716in_option1 = id713out_o;

    HWOffsetFix<32,0,UNSIGNED> id716x_1;

    switch((id716in_sel.getValueAsLong())) {
      case 0l:
        id716x_1 = id716in_option0;
        break;
      case 1l:
        id716x_1 = id716in_option1;
        break;
      default:
        id716x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id716out_result = (id716x_1);
  }
  { // Node ID: 4165 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4165in_input = id716out_result;

    id4165out_output[(getCycle()+1)%2] = id4165in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id702out_output;

  { // Node ID: 702 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id702in_input = id4168out_output[getCycle()%2];

    id702out_output = id702in_input;
  }
  { // Node ID: 3237 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2835out_result;

  { // Node ID: 2835 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2835in_a = id3237out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2835in_b = id3512out_output[getCycle()%2];

    id2835out_result = (eq_fixed(id2835in_a,id2835in_b));
  }
  { // Node ID: 4169 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4169in_input = id2835out_result;

    id4169out_output[(getCycle()+3)%4] = id4169in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id701out_o;

  { // Node ID: 701 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id701in_i = id4169out_output[getCycle()%4];

    id701out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id701in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id703out_result;

  { // Node ID: 703 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id703in_a = id702out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id703in_b = id701out_o;

    id703out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id703in_a,id703in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id704out_result;

  { // Node ID: 704 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id704in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id704in_option0 = id703out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id704in_option1 = id701out_o;

    HWOffsetFix<32,0,UNSIGNED> id704x_1;

    switch((id704in_sel.getValueAsLong())) {
      case 0l:
        id704x_1 = id704in_option0;
        break;
      case 1l:
        id704x_1 = id704in_option1;
        break;
      default:
        id704x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id704out_result = (id704x_1);
  }
  { // Node ID: 4168 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4168in_input = id704out_result;

    id4168out_output[(getCycle()+1)%2] = id4168in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id690out_output;

  { // Node ID: 690 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id690in_input = id4171out_output[getCycle()%2];

    id690out_output = id690in_input;
  }
  { // Node ID: 3236 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2836out_result;

  { // Node ID: 2836 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2836in_a = id3236out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2836in_b = id3512out_output[getCycle()%2];

    id2836out_result = (eq_fixed(id2836in_a,id2836in_b));
  }
  { // Node ID: 4172 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4172in_input = id2836out_result;

    id4172out_output[(getCycle()+3)%4] = id4172in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id689out_o;

  { // Node ID: 689 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id689in_i = id4172out_output[getCycle()%4];

    id689out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id689in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id691out_result;

  { // Node ID: 691 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id691in_a = id690out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id691in_b = id689out_o;

    id691out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id691in_a,id691in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id692out_result;

  { // Node ID: 692 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id692in_sel = id3629out_output[getCycle()%4];
    const HWOffsetFix<32,0,UNSIGNED> &id692in_option0 = id691out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id692in_option1 = id689out_o;

    HWOffsetFix<32,0,UNSIGNED> id692x_1;

    switch((id692in_sel.getValueAsLong())) {
      case 0l:
        id692x_1 = id692in_option0;
        break;
      case 1l:
        id692x_1 = id692in_option1;
        break;
      default:
        id692x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id692out_result = (id692x_1);
  }
  { // Node ID: 4171 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4171in_input = id692out_result;

    id4171out_output[(getCycle()+1)%2] = id4171in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id678out_output;

  { // Node ID: 678 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id678in_input = id4174out_output[getCycle()%2];

    id678out_output = id678in_input;
  }
  { // Node ID: 3235 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2837out_result;

  { // Node ID: 2837 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2837in_a = id3235out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2837in_b = id3512out_output[getCycle()%2];

    id2837out_result = (eq_fixed(id2837in_a,id2837in_b));
  }
  { // Node ID: 4175 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4175in_input = id2837out_result;

    id4175out_output[(getCycle()+3)%4] = id4175in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id677out_o;

  { // Node ID: 677 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id677in_i = id4175out_output[getCycle()%4];

    id677out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id677in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id679out_result;

  { // Node ID: 679 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id679in_a = id678out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id679in_b = id677out_o;

    id679out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id679in_a,id679in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id680out_result;

  { // Node ID: 680 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id680in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id680in_option0 = id679out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id680in_option1 = id677out_o;

    HWOffsetFix<32,0,UNSIGNED> id680x_1;

    switch((id680in_sel.getValueAsLong())) {
      case 0l:
        id680x_1 = id680in_option0;
        break;
      case 1l:
        id680x_1 = id680in_option1;
        break;
      default:
        id680x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id680out_result = (id680x_1);
  }
  { // Node ID: 4174 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4174in_input = id680out_result;

    id4174out_output[(getCycle()+1)%2] = id4174in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id666out_output;

  { // Node ID: 666 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id666in_input = id4177out_output[getCycle()%2];

    id666out_output = id666in_input;
  }
  { // Node ID: 3234 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2838out_result;

  { // Node ID: 2838 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2838in_a = id3234out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2838in_b = id3513out_output[getCycle()%2];

    id2838out_result = (eq_fixed(id2838in_a,id2838in_b));
  }
  { // Node ID: 4178 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4178in_input = id2838out_result;

    id4178out_output[(getCycle()+4)%5] = id4178in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id665out_o;

  { // Node ID: 665 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id665in_i = id4178out_output[getCycle()%5];

    id665out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id665in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id667out_result;

  { // Node ID: 667 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id667in_a = id666out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id667in_b = id665out_o;

    id667out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id667in_a,id667in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id668out_result;

  { // Node ID: 668 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id668in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id668in_option0 = id667out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id668in_option1 = id665out_o;

    HWOffsetFix<32,0,UNSIGNED> id668x_1;

    switch((id668in_sel.getValueAsLong())) {
      case 0l:
        id668x_1 = id668in_option0;
        break;
      case 1l:
        id668x_1 = id668in_option1;
        break;
      default:
        id668x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id668out_result = (id668x_1);
  }
  { // Node ID: 4177 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4177in_input = id668out_result;

    id4177out_output[(getCycle()+1)%2] = id4177in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id654out_output;

  { // Node ID: 654 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id654in_input = id4180out_output[getCycle()%2];

    id654out_output = id654in_input;
  }
  { // Node ID: 3233 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2839out_result;

  { // Node ID: 2839 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2839in_a = id3233out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2839in_b = id3513out_output[getCycle()%2];

    id2839out_result = (eq_fixed(id2839in_a,id2839in_b));
  }
  { // Node ID: 4181 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4181in_input = id2839out_result;

    id4181out_output[(getCycle()+4)%5] = id4181in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id653out_o;

  { // Node ID: 653 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id653in_i = id4181out_output[getCycle()%5];

    id653out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id653in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id655out_result;

  { // Node ID: 655 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id655in_a = id654out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id655in_b = id653out_o;

    id655out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id655in_a,id655in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id656out_result;

  { // Node ID: 656 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id656in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id656in_option0 = id655out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id656in_option1 = id653out_o;

    HWOffsetFix<32,0,UNSIGNED> id656x_1;

    switch((id656in_sel.getValueAsLong())) {
      case 0l:
        id656x_1 = id656in_option0;
        break;
      case 1l:
        id656x_1 = id656in_option1;
        break;
      default:
        id656x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id656out_result = (id656x_1);
  }
  { // Node ID: 4180 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4180in_input = id656out_result;

    id4180out_output[(getCycle()+1)%2] = id4180in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id642out_output;

  { // Node ID: 642 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id642in_input = id4183out_output[getCycle()%2];

    id642out_output = id642in_input;
  }
  { // Node ID: 3232 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2840out_result;

  { // Node ID: 2840 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2840in_a = id3232out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2840in_b = id3513out_output[getCycle()%2];

    id2840out_result = (eq_fixed(id2840in_a,id2840in_b));
  }
  { // Node ID: 4184 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4184in_input = id2840out_result;

    id4184out_output[(getCycle()+4)%5] = id4184in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id641out_o;

  { // Node ID: 641 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id641in_i = id4184out_output[getCycle()%5];

    id641out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id641in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id643out_result;

  { // Node ID: 643 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id643in_a = id642out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id643in_b = id641out_o;

    id643out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id643in_a,id643in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id644out_result;

  { // Node ID: 644 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id644in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id644in_option0 = id643out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id644in_option1 = id641out_o;

    HWOffsetFix<32,0,UNSIGNED> id644x_1;

    switch((id644in_sel.getValueAsLong())) {
      case 0l:
        id644x_1 = id644in_option0;
        break;
      case 1l:
        id644x_1 = id644in_option1;
        break;
      default:
        id644x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id644out_result = (id644x_1);
  }
  { // Node ID: 4183 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4183in_input = id644out_result;

    id4183out_output[(getCycle()+1)%2] = id4183in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id630out_output;

  { // Node ID: 630 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id630in_input = id4186out_output[getCycle()%2];

    id630out_output = id630in_input;
  }
  { // Node ID: 3231 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2841out_result;

  { // Node ID: 2841 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2841in_a = id3231out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2841in_b = id3513out_output[getCycle()%2];

    id2841out_result = (eq_fixed(id2841in_a,id2841in_b));
  }
  { // Node ID: 4187 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4187in_input = id2841out_result;

    id4187out_output[(getCycle()+4)%5] = id4187in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id629out_o;

  { // Node ID: 629 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id629in_i = id4187out_output[getCycle()%5];

    id629out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id629in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id631out_result;

  { // Node ID: 631 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id631in_a = id630out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id631in_b = id629out_o;

    id631out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id631in_a,id631in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id632out_result;

  { // Node ID: 632 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id632in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id632in_option0 = id631out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id632in_option1 = id629out_o;

    HWOffsetFix<32,0,UNSIGNED> id632x_1;

    switch((id632in_sel.getValueAsLong())) {
      case 0l:
        id632x_1 = id632in_option0;
        break;
      case 1l:
        id632x_1 = id632in_option1;
        break;
      default:
        id632x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id632out_result = (id632x_1);
  }
  { // Node ID: 4186 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4186in_input = id632out_result;

    id4186out_output[(getCycle()+1)%2] = id4186in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id618out_output;

  { // Node ID: 618 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id618in_input = id4189out_output[getCycle()%2];

    id618out_output = id618in_input;
  }
  { // Node ID: 3230 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2842out_result;

  { // Node ID: 2842 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2842in_a = id3230out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2842in_b = id3513out_output[getCycle()%2];

    id2842out_result = (eq_fixed(id2842in_a,id2842in_b));
  }
  { // Node ID: 4190 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4190in_input = id2842out_result;

    id4190out_output[(getCycle()+4)%5] = id4190in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id617out_o;

  { // Node ID: 617 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id617in_i = id4190out_output[getCycle()%5];

    id617out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id617in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id619out_result;

  { // Node ID: 619 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id619in_a = id618out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id619in_b = id617out_o;

    id619out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id619in_a,id619in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id620out_result;

  { // Node ID: 620 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id620in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id620in_option0 = id619out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id620in_option1 = id617out_o;

    HWOffsetFix<32,0,UNSIGNED> id620x_1;

    switch((id620in_sel.getValueAsLong())) {
      case 0l:
        id620x_1 = id620in_option0;
        break;
      case 1l:
        id620x_1 = id620in_option1;
        break;
      default:
        id620x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id620out_result = (id620x_1);
  }
  { // Node ID: 4189 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4189in_input = id620out_result;

    id4189out_output[(getCycle()+1)%2] = id4189in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id606out_output;

  { // Node ID: 606 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id606in_input = id4192out_output[getCycle()%2];

    id606out_output = id606in_input;
  }
  { // Node ID: 3229 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2843out_result;

  { // Node ID: 2843 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2843in_a = id3229out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2843in_b = id3513out_output[getCycle()%2];

    id2843out_result = (eq_fixed(id2843in_a,id2843in_b));
  }
  { // Node ID: 4193 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4193in_input = id2843out_result;

    id4193out_output[(getCycle()+4)%5] = id4193in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id605out_o;

  { // Node ID: 605 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id605in_i = id4193out_output[getCycle()%5];

    id605out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id605in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id607out_result;

  { // Node ID: 607 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id607in_a = id606out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id607in_b = id605out_o;

    id607out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id607in_a,id607in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id608out_result;

  { // Node ID: 608 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id608in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id608in_option0 = id607out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id608in_option1 = id605out_o;

    HWOffsetFix<32,0,UNSIGNED> id608x_1;

    switch((id608in_sel.getValueAsLong())) {
      case 0l:
        id608x_1 = id608in_option0;
        break;
      case 1l:
        id608x_1 = id608in_option1;
        break;
      default:
        id608x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id608out_result = (id608x_1);
  }
  { // Node ID: 4192 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4192in_input = id608out_result;

    id4192out_output[(getCycle()+1)%2] = id4192in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id594out_output;

  { // Node ID: 594 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id594in_input = id4195out_output[getCycle()%2];

    id594out_output = id594in_input;
  }
  { // Node ID: 3228 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2844out_result;

  { // Node ID: 2844 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2844in_a = id3228out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2844in_b = id3513out_output[getCycle()%2];

    id2844out_result = (eq_fixed(id2844in_a,id2844in_b));
  }
  { // Node ID: 4196 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4196in_input = id2844out_result;

    id4196out_output[(getCycle()+4)%5] = id4196in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id593out_o;

  { // Node ID: 593 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id593in_i = id4196out_output[getCycle()%5];

    id593out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id593in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id595out_result;

  { // Node ID: 595 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id595in_a = id594out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id595in_b = id593out_o;

    id595out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id595in_a,id595in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id596out_result;

  { // Node ID: 596 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id596in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id596in_option0 = id595out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id596in_option1 = id593out_o;

    HWOffsetFix<32,0,UNSIGNED> id596x_1;

    switch((id596in_sel.getValueAsLong())) {
      case 0l:
        id596x_1 = id596in_option0;
        break;
      case 1l:
        id596x_1 = id596in_option1;
        break;
      default:
        id596x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id596out_result = (id596x_1);
  }
  { // Node ID: 4195 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4195in_input = id596out_result;

    id4195out_output[(getCycle()+1)%2] = id4195in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id582out_output;

  { // Node ID: 582 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id582in_input = id4198out_output[getCycle()%2];

    id582out_output = id582in_input;
  }
  { // Node ID: 3227 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2845out_result;

  { // Node ID: 2845 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2845in_a = id3227out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2845in_b = id3513out_output[getCycle()%2];

    id2845out_result = (eq_fixed(id2845in_a,id2845in_b));
  }
  { // Node ID: 4199 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4199in_input = id2845out_result;

    id4199out_output[(getCycle()+4)%5] = id4199in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id581out_o;

  { // Node ID: 581 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id581in_i = id4199out_output[getCycle()%5];

    id581out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id581in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id583out_result;

  { // Node ID: 583 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id583in_a = id582out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id583in_b = id581out_o;

    id583out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id583in_a,id583in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id584out_result;

  { // Node ID: 584 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id584in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id584in_option0 = id583out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id584in_option1 = id581out_o;

    HWOffsetFix<32,0,UNSIGNED> id584x_1;

    switch((id584in_sel.getValueAsLong())) {
      case 0l:
        id584x_1 = id584in_option0;
        break;
      case 1l:
        id584x_1 = id584in_option1;
        break;
      default:
        id584x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id584out_result = (id584x_1);
  }
  { // Node ID: 4198 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4198in_input = id584out_result;

    id4198out_output[(getCycle()+1)%2] = id4198in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id570out_output;

  { // Node ID: 570 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id570in_input = id4201out_output[getCycle()%2];

    id570out_output = id570in_input;
  }
  { // Node ID: 3226 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2846out_result;

  { // Node ID: 2846 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2846in_a = id3226out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2846in_b = id3513out_output[getCycle()%2];

    id2846out_result = (eq_fixed(id2846in_a,id2846in_b));
  }
  { // Node ID: 4202 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4202in_input = id2846out_result;

    id4202out_output[(getCycle()+4)%5] = id4202in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id569out_o;

  { // Node ID: 569 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id569in_i = id4202out_output[getCycle()%5];

    id569out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id569in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id571out_result;

  { // Node ID: 571 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id571in_a = id570out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id571in_b = id569out_o;

    id571out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id571in_a,id571in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id572out_result;

  { // Node ID: 572 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id572in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id572in_option0 = id571out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id572in_option1 = id569out_o;

    HWOffsetFix<32,0,UNSIGNED> id572x_1;

    switch((id572in_sel.getValueAsLong())) {
      case 0l:
        id572x_1 = id572in_option0;
        break;
      case 1l:
        id572x_1 = id572in_option1;
        break;
      default:
        id572x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id572out_result = (id572x_1);
  }
  { // Node ID: 4201 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4201in_input = id572out_result;

    id4201out_output[(getCycle()+1)%2] = id4201in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id558out_output;

  { // Node ID: 558 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id558in_input = id4204out_output[getCycle()%2];

    id558out_output = id558in_input;
  }
  { // Node ID: 3225 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2847out_result;

  { // Node ID: 2847 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2847in_a = id3225out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2847in_b = id3513out_output[getCycle()%2];

    id2847out_result = (eq_fixed(id2847in_a,id2847in_b));
  }
  { // Node ID: 4205 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4205in_input = id2847out_result;

    id4205out_output[(getCycle()+4)%5] = id4205in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id557out_o;

  { // Node ID: 557 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id557in_i = id4205out_output[getCycle()%5];

    id557out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id557in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id559out_result;

  { // Node ID: 559 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id559in_a = id558out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id559in_b = id557out_o;

    id559out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id559in_a,id559in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id560out_result;

  { // Node ID: 560 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id560in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id560in_option0 = id559out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id560in_option1 = id557out_o;

    HWOffsetFix<32,0,UNSIGNED> id560x_1;

    switch((id560in_sel.getValueAsLong())) {
      case 0l:
        id560x_1 = id560in_option0;
        break;
      case 1l:
        id560x_1 = id560in_option1;
        break;
      default:
        id560x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id560out_result = (id560x_1);
  }
  { // Node ID: 4204 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4204in_input = id560out_result;

    id4204out_output[(getCycle()+1)%2] = id4204in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id546out_output;

  { // Node ID: 546 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id546in_input = id4207out_output[getCycle()%2];

    id546out_output = id546in_input;
  }
  { // Node ID: 3224 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2848out_result;

  { // Node ID: 2848 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2848in_a = id3224out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2848in_b = id3513out_output[getCycle()%2];

    id2848out_result = (eq_fixed(id2848in_a,id2848in_b));
  }
  { // Node ID: 4208 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4208in_input = id2848out_result;

    id4208out_output[(getCycle()+4)%5] = id4208in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id545out_o;

  { // Node ID: 545 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id545in_i = id4208out_output[getCycle()%5];

    id545out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id545in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id547out_result;

  { // Node ID: 547 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id547in_a = id546out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id547in_b = id545out_o;

    id547out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id547in_a,id547in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id548out_result;

  { // Node ID: 548 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id548in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id548in_option0 = id547out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id548in_option1 = id545out_o;

    HWOffsetFix<32,0,UNSIGNED> id548x_1;

    switch((id548in_sel.getValueAsLong())) {
      case 0l:
        id548x_1 = id548in_option0;
        break;
      case 1l:
        id548x_1 = id548in_option1;
        break;
      default:
        id548x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id548out_result = (id548x_1);
  }
  { // Node ID: 4207 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4207in_input = id548out_result;

    id4207out_output[(getCycle()+1)%2] = id4207in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id534out_output;

  { // Node ID: 534 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id534in_input = id4210out_output[getCycle()%2];

    id534out_output = id534in_input;
  }
  { // Node ID: 3223 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2849out_result;

  { // Node ID: 2849 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2849in_a = id3223out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2849in_b = id3513out_output[getCycle()%2];

    id2849out_result = (eq_fixed(id2849in_a,id2849in_b));
  }
  { // Node ID: 4211 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4211in_input = id2849out_result;

    id4211out_output[(getCycle()+4)%5] = id4211in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id533out_o;

  { // Node ID: 533 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id533in_i = id4211out_output[getCycle()%5];

    id533out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id533in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id535out_result;

  { // Node ID: 535 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id535in_a = id534out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id535in_b = id533out_o;

    id535out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id535in_a,id535in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id536out_result;

  { // Node ID: 536 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id536in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id536in_option0 = id535out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id536in_option1 = id533out_o;

    HWOffsetFix<32,0,UNSIGNED> id536x_1;

    switch((id536in_sel.getValueAsLong())) {
      case 0l:
        id536x_1 = id536in_option0;
        break;
      case 1l:
        id536x_1 = id536in_option1;
        break;
      default:
        id536x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id536out_result = (id536x_1);
  }
  { // Node ID: 4210 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4210in_input = id536out_result;

    id4210out_output[(getCycle()+1)%2] = id4210in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id522out_output;

  { // Node ID: 522 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id522in_input = id4213out_output[getCycle()%2];

    id522out_output = id522in_input;
  }
  { // Node ID: 3222 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2850out_result;

  { // Node ID: 2850 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2850in_a = id3222out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2850in_b = id3513out_output[getCycle()%2];

    id2850out_result = (eq_fixed(id2850in_a,id2850in_b));
  }
  { // Node ID: 4214 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4214in_input = id2850out_result;

    id4214out_output[(getCycle()+4)%5] = id4214in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id521out_o;

  { // Node ID: 521 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id521in_i = id4214out_output[getCycle()%5];

    id521out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id521in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id523out_result;

  { // Node ID: 523 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id523in_a = id522out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id523in_b = id521out_o;

    id523out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id523in_a,id523in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id524out_result;

  { // Node ID: 524 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id524in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id524in_option0 = id523out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id524in_option1 = id521out_o;

    HWOffsetFix<32,0,UNSIGNED> id524x_1;

    switch((id524in_sel.getValueAsLong())) {
      case 0l:
        id524x_1 = id524in_option0;
        break;
      case 1l:
        id524x_1 = id524in_option1;
        break;
      default:
        id524x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id524out_result = (id524x_1);
  }
  { // Node ID: 4213 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4213in_input = id524out_result;

    id4213out_output[(getCycle()+1)%2] = id4213in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id510out_output;

  { // Node ID: 510 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id510in_input = id4216out_output[getCycle()%2];

    id510out_output = id510in_input;
  }
  { // Node ID: 3221 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2851out_result;

  { // Node ID: 2851 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2851in_a = id3221out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2851in_b = id3513out_output[getCycle()%2];

    id2851out_result = (eq_fixed(id2851in_a,id2851in_b));
  }
  { // Node ID: 4217 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4217in_input = id2851out_result;

    id4217out_output[(getCycle()+4)%5] = id4217in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id509out_o;

  { // Node ID: 509 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id509in_i = id4217out_output[getCycle()%5];

    id509out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id509in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id511out_result;

  { // Node ID: 511 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id511in_a = id510out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id511in_b = id509out_o;

    id511out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id511in_a,id511in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id512out_result;

  { // Node ID: 512 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id512in_sel = id3659out_output[getCycle()%3];
    const HWOffsetFix<32,0,UNSIGNED> &id512in_option0 = id511out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id512in_option1 = id509out_o;

    HWOffsetFix<32,0,UNSIGNED> id512x_1;

    switch((id512in_sel.getValueAsLong())) {
      case 0l:
        id512x_1 = id512in_option0;
        break;
      case 1l:
        id512x_1 = id512in_option1;
        break;
      default:
        id512x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id512out_result = (id512x_1);
  }
  { // Node ID: 4216 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4216in_input = id512out_result;

    id4216out_output[(getCycle()+1)%2] = id4216in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id498out_output;

  { // Node ID: 498 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id498in_input = id4219out_output[getCycle()%2];

    id498out_output = id498in_input;
  }
  { // Node ID: 3220 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2852out_result;

  { // Node ID: 2852 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2852in_a = id3220out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2852in_b = id3513out_output[getCycle()%2];

    id2852out_result = (eq_fixed(id2852in_a,id2852in_b));
  }
  { // Node ID: 4220 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4220in_input = id2852out_result;

    id4220out_output[(getCycle()+4)%5] = id4220in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id497out_o;

  { // Node ID: 497 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id497in_i = id4220out_output[getCycle()%5];

    id497out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id497in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id499out_result;

  { // Node ID: 499 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id499in_a = id498out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id499in_b = id497out_o;

    id499out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id499in_a,id499in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id500out_result;

  { // Node ID: 500 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id500in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id500in_option0 = id499out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id500in_option1 = id497out_o;

    HWOffsetFix<32,0,UNSIGNED> id500x_1;

    switch((id500in_sel.getValueAsLong())) {
      case 0l:
        id500x_1 = id500in_option0;
        break;
      case 1l:
        id500x_1 = id500in_option1;
        break;
      default:
        id500x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id500out_result = (id500x_1);
  }
  { // Node ID: 4219 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4219in_input = id500out_result;

    id4219out_output[(getCycle()+1)%2] = id4219in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id486out_output;

  { // Node ID: 486 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id486in_input = id4222out_output[getCycle()%2];

    id486out_output = id486in_input;
  }
  { // Node ID: 3219 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2853out_result;

  { // Node ID: 2853 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2853in_a = id3219out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2853in_b = id3513out_output[getCycle()%2];

    id2853out_result = (eq_fixed(id2853in_a,id2853in_b));
  }
  { // Node ID: 4223 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4223in_input = id2853out_result;

    id4223out_output[(getCycle()+4)%5] = id4223in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id485out_o;

  { // Node ID: 485 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id485in_i = id4223out_output[getCycle()%5];

    id485out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id485in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id487out_result;

  { // Node ID: 487 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id487in_a = id486out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id487in_b = id485out_o;

    id487out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id487in_a,id487in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id488out_result;

  { // Node ID: 488 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id488in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id488in_option0 = id487out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id488in_option1 = id485out_o;

    HWOffsetFix<32,0,UNSIGNED> id488x_1;

    switch((id488in_sel.getValueAsLong())) {
      case 0l:
        id488x_1 = id488in_option0;
        break;
      case 1l:
        id488x_1 = id488in_option1;
        break;
      default:
        id488x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id488out_result = (id488x_1);
  }
  { // Node ID: 4222 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4222in_input = id488out_result;

    id4222out_output[(getCycle()+1)%2] = id4222in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id474out_output;

  { // Node ID: 474 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id474in_input = id4225out_output[getCycle()%2];

    id474out_output = id474in_input;
  }
  { // Node ID: 3218 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2854out_result;

  { // Node ID: 2854 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2854in_a = id3218out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2854in_b = id3513out_output[getCycle()%2];

    id2854out_result = (eq_fixed(id2854in_a,id2854in_b));
  }
  { // Node ID: 4226 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4226in_input = id2854out_result;

    id4226out_output[(getCycle()+4)%5] = id4226in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id473out_o;

  { // Node ID: 473 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id473in_i = id4226out_output[getCycle()%5];

    id473out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id473in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id475out_result;

  { // Node ID: 475 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id475in_a = id474out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id475in_b = id473out_o;

    id475out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id475in_a,id475in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id476out_result;

  { // Node ID: 476 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id476in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id476in_option0 = id475out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id476in_option1 = id473out_o;

    HWOffsetFix<32,0,UNSIGNED> id476x_1;

    switch((id476in_sel.getValueAsLong())) {
      case 0l:
        id476x_1 = id476in_option0;
        break;
      case 1l:
        id476x_1 = id476in_option1;
        break;
      default:
        id476x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id476out_result = (id476x_1);
  }
  { // Node ID: 4225 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4225in_input = id476out_result;

    id4225out_output[(getCycle()+1)%2] = id4225in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id462out_output;

  { // Node ID: 462 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id462in_input = id4228out_output[getCycle()%2];

    id462out_output = id462in_input;
  }
  { // Node ID: 3217 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2855out_result;

  { // Node ID: 2855 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2855in_a = id3217out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2855in_b = id3513out_output[getCycle()%2];

    id2855out_result = (eq_fixed(id2855in_a,id2855in_b));
  }
  { // Node ID: 4229 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4229in_input = id2855out_result;

    id4229out_output[(getCycle()+4)%5] = id4229in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id461out_o;

  { // Node ID: 461 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id461in_i = id4229out_output[getCycle()%5];

    id461out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id461in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id463out_result;

  { // Node ID: 463 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id463in_a = id462out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id463in_b = id461out_o;

    id463out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id463in_a,id463in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id464out_result;

  { // Node ID: 464 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id464in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id464in_option0 = id463out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id464in_option1 = id461out_o;

    HWOffsetFix<32,0,UNSIGNED> id464x_1;

    switch((id464in_sel.getValueAsLong())) {
      case 0l:
        id464x_1 = id464in_option0;
        break;
      case 1l:
        id464x_1 = id464in_option1;
        break;
      default:
        id464x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id464out_result = (id464x_1);
  }
  { // Node ID: 4228 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4228in_input = id464out_result;

    id4228out_output[(getCycle()+1)%2] = id4228in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id450out_output;

  { // Node ID: 450 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id450in_input = id4231out_output[getCycle()%2];

    id450out_output = id450in_input;
  }
  { // Node ID: 3216 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2856out_result;

  { // Node ID: 2856 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2856in_a = id3216out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2856in_b = id3513out_output[getCycle()%2];

    id2856out_result = (eq_fixed(id2856in_a,id2856in_b));
  }
  { // Node ID: 4232 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4232in_input = id2856out_result;

    id4232out_output[(getCycle()+4)%5] = id4232in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id449out_o;

  { // Node ID: 449 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id449in_i = id4232out_output[getCycle()%5];

    id449out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id449in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id451out_result;

  { // Node ID: 451 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id451in_a = id450out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id451in_b = id449out_o;

    id451out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id451in_a,id451in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id452out_result;

  { // Node ID: 452 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id452in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id452in_option0 = id451out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id452in_option1 = id449out_o;

    HWOffsetFix<32,0,UNSIGNED> id452x_1;

    switch((id452in_sel.getValueAsLong())) {
      case 0l:
        id452x_1 = id452in_option0;
        break;
      case 1l:
        id452x_1 = id452in_option1;
        break;
      default:
        id452x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id452out_result = (id452x_1);
  }
  { // Node ID: 4231 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4231in_input = id452out_result;

    id4231out_output[(getCycle()+1)%2] = id4231in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id438out_output;

  { // Node ID: 438 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id438in_input = id4234out_output[getCycle()%2];

    id438out_output = id438in_input;
  }
  { // Node ID: 3215 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2857out_result;

  { // Node ID: 2857 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2857in_a = id3215out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2857in_b = id3513out_output[getCycle()%2];

    id2857out_result = (eq_fixed(id2857in_a,id2857in_b));
  }
  { // Node ID: 4235 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4235in_input = id2857out_result;

    id4235out_output[(getCycle()+4)%5] = id4235in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id437out_o;

  { // Node ID: 437 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id437in_i = id4235out_output[getCycle()%5];

    id437out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id437in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id439out_result;

  { // Node ID: 439 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id439in_a = id438out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id439in_b = id437out_o;

    id439out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id439in_a,id439in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id440out_result;

  { // Node ID: 440 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id440in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id440in_option0 = id439out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id440in_option1 = id437out_o;

    HWOffsetFix<32,0,UNSIGNED> id440x_1;

    switch((id440in_sel.getValueAsLong())) {
      case 0l:
        id440x_1 = id440in_option0;
        break;
      case 1l:
        id440x_1 = id440in_option1;
        break;
      default:
        id440x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id440out_result = (id440x_1);
  }
  { // Node ID: 4234 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4234in_input = id440out_result;

    id4234out_output[(getCycle()+1)%2] = id4234in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id426out_output;

  { // Node ID: 426 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id426in_input = id4237out_output[getCycle()%2];

    id426out_output = id426in_input;
  }
  { // Node ID: 3214 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2858out_result;

  { // Node ID: 2858 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2858in_a = id3214out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2858in_b = id3513out_output[getCycle()%2];

    id2858out_result = (eq_fixed(id2858in_a,id2858in_b));
  }
  { // Node ID: 4238 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4238in_input = id2858out_result;

    id4238out_output[(getCycle()+4)%5] = id4238in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id425out_o;

  { // Node ID: 425 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id425in_i = id4238out_output[getCycle()%5];

    id425out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id425in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id427out_result;

  { // Node ID: 427 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id427in_a = id426out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id427in_b = id425out_o;

    id427out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id427in_a,id427in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id428out_result;

  { // Node ID: 428 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id428in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id428in_option0 = id427out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id428in_option1 = id425out_o;

    HWOffsetFix<32,0,UNSIGNED> id428x_1;

    switch((id428in_sel.getValueAsLong())) {
      case 0l:
        id428x_1 = id428in_option0;
        break;
      case 1l:
        id428x_1 = id428in_option1;
        break;
      default:
        id428x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id428out_result = (id428x_1);
  }
  { // Node ID: 4237 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4237in_input = id428out_result;

    id4237out_output[(getCycle()+1)%2] = id4237in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id414out_output;

  { // Node ID: 414 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id414in_input = id4240out_output[getCycle()%2];

    id414out_output = id414in_input;
  }
  { // Node ID: 3213 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2859out_result;

  { // Node ID: 2859 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2859in_a = id3213out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2859in_b = id3513out_output[getCycle()%2];

    id2859out_result = (eq_fixed(id2859in_a,id2859in_b));
  }
  { // Node ID: 4241 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4241in_input = id2859out_result;

    id4241out_output[(getCycle()+4)%5] = id4241in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id413out_o;

  { // Node ID: 413 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id413in_i = id4241out_output[getCycle()%5];

    id413out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id413in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id415out_result;

  { // Node ID: 415 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id415in_a = id414out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id415in_b = id413out_o;

    id415out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id415in_a,id415in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id416out_result;

  { // Node ID: 416 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id416in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id416in_option0 = id415out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id416in_option1 = id413out_o;

    HWOffsetFix<32,0,UNSIGNED> id416x_1;

    switch((id416in_sel.getValueAsLong())) {
      case 0l:
        id416x_1 = id416in_option0;
        break;
      case 1l:
        id416x_1 = id416in_option1;
        break;
      default:
        id416x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id416out_result = (id416x_1);
  }
  { // Node ID: 4240 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4240in_input = id416out_result;

    id4240out_output[(getCycle()+1)%2] = id4240in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id402out_output;

  { // Node ID: 402 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id402in_input = id4243out_output[getCycle()%2];

    id402out_output = id402in_input;
  }
  { // Node ID: 3212 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2860out_result;

  { // Node ID: 2860 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2860in_a = id3212out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2860in_b = id3513out_output[getCycle()%2];

    id2860out_result = (eq_fixed(id2860in_a,id2860in_b));
  }
  { // Node ID: 4244 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4244in_input = id2860out_result;

    id4244out_output[(getCycle()+4)%5] = id4244in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id401out_o;

  { // Node ID: 401 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id401in_i = id4244out_output[getCycle()%5];

    id401out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id401in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id403out_result;

  { // Node ID: 403 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id403in_a = id402out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id403in_b = id401out_o;

    id403out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id403in_a,id403in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id404out_result;

  { // Node ID: 404 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id404in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id404in_option0 = id403out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id404in_option1 = id401out_o;

    HWOffsetFix<32,0,UNSIGNED> id404x_1;

    switch((id404in_sel.getValueAsLong())) {
      case 0l:
        id404x_1 = id404in_option0;
        break;
      case 1l:
        id404x_1 = id404in_option1;
        break;
      default:
        id404x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id404out_result = (id404x_1);
  }
  { // Node ID: 4243 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4243in_input = id404out_result;

    id4243out_output[(getCycle()+1)%2] = id4243in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id390out_output;

  { // Node ID: 390 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id390in_input = id4246out_output[getCycle()%2];

    id390out_output = id390in_input;
  }
  { // Node ID: 3211 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2861out_result;

  { // Node ID: 2861 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2861in_a = id3211out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2861in_b = id3513out_output[getCycle()%2];

    id2861out_result = (eq_fixed(id2861in_a,id2861in_b));
  }
  { // Node ID: 4247 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4247in_input = id2861out_result;

    id4247out_output[(getCycle()+4)%5] = id4247in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id389out_o;

  { // Node ID: 389 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id389in_i = id4247out_output[getCycle()%5];

    id389out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id389in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id391out_result;

  { // Node ID: 391 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id391in_a = id390out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id391in_b = id389out_o;

    id391out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id391in_a,id391in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id392out_result;

  { // Node ID: 392 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id392in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id392in_option0 = id391out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id392in_option1 = id389out_o;

    HWOffsetFix<32,0,UNSIGNED> id392x_1;

    switch((id392in_sel.getValueAsLong())) {
      case 0l:
        id392x_1 = id392in_option0;
        break;
      case 1l:
        id392x_1 = id392in_option1;
        break;
      default:
        id392x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id392out_result = (id392x_1);
  }
  { // Node ID: 4246 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4246in_input = id392out_result;

    id4246out_output[(getCycle()+1)%2] = id4246in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id378out_output;

  { // Node ID: 378 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id378in_input = id4249out_output[getCycle()%2];

    id378out_output = id378in_input;
  }
  { // Node ID: 3210 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2862out_result;

  { // Node ID: 2862 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2862in_a = id3210out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2862in_b = id3513out_output[getCycle()%2];

    id2862out_result = (eq_fixed(id2862in_a,id2862in_b));
  }
  { // Node ID: 4250 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4250in_input = id2862out_result;

    id4250out_output[(getCycle()+4)%5] = id4250in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id377out_o;

  { // Node ID: 377 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id377in_i = id4250out_output[getCycle()%5];

    id377out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id377in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id379out_result;

  { // Node ID: 379 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id379in_a = id378out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id379in_b = id377out_o;

    id379out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id379in_a,id379in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id380out_result;

  { // Node ID: 380 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id380in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id380in_option0 = id379out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id380in_option1 = id377out_o;

    HWOffsetFix<32,0,UNSIGNED> id380x_1;

    switch((id380in_sel.getValueAsLong())) {
      case 0l:
        id380x_1 = id380in_option0;
        break;
      case 1l:
        id380x_1 = id380in_option1;
        break;
      default:
        id380x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id380out_result = (id380x_1);
  }
  { // Node ID: 4249 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4249in_input = id380out_result;

    id4249out_output[(getCycle()+1)%2] = id4249in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id366out_output;

  { // Node ID: 366 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id366in_input = id4252out_output[getCycle()%2];

    id366out_output = id366in_input;
  }
  { // Node ID: 3209 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2863out_result;

  { // Node ID: 2863 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2863in_a = id3209out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2863in_b = id3513out_output[getCycle()%2];

    id2863out_result = (eq_fixed(id2863in_a,id2863in_b));
  }
  { // Node ID: 4253 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4253in_input = id2863out_result;

    id4253out_output[(getCycle()+4)%5] = id4253in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id365out_o;

  { // Node ID: 365 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id365in_i = id4253out_output[getCycle()%5];

    id365out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id365in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id367out_result;

  { // Node ID: 367 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id367in_a = id366out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id367in_b = id365out_o;

    id367out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id367in_a,id367in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id368out_result;

  { // Node ID: 368 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id368in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id368in_option0 = id367out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id368in_option1 = id365out_o;

    HWOffsetFix<32,0,UNSIGNED> id368x_1;

    switch((id368in_sel.getValueAsLong())) {
      case 0l:
        id368x_1 = id368in_option0;
        break;
      case 1l:
        id368x_1 = id368in_option1;
        break;
      default:
        id368x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id368out_result = (id368x_1);
  }
  { // Node ID: 4252 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4252in_input = id368out_result;

    id4252out_output[(getCycle()+1)%2] = id4252in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id354out_output;

  { // Node ID: 354 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id354in_input = id4255out_output[getCycle()%2];

    id354out_output = id354in_input;
  }
  { // Node ID: 3208 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2864out_result;

  { // Node ID: 2864 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2864in_a = id3208out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2864in_b = id3513out_output[getCycle()%2];

    id2864out_result = (eq_fixed(id2864in_a,id2864in_b));
  }
  { // Node ID: 4256 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4256in_input = id2864out_result;

    id4256out_output[(getCycle()+4)%5] = id4256in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id353out_o;

  { // Node ID: 353 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id353in_i = id4256out_output[getCycle()%5];

    id353out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id353in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id355out_result;

  { // Node ID: 355 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id355in_a = id354out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id355in_b = id353out_o;

    id355out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id355in_a,id355in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id356out_result;

  { // Node ID: 356 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id356in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id356in_option0 = id355out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id356in_option1 = id353out_o;

    HWOffsetFix<32,0,UNSIGNED> id356x_1;

    switch((id356in_sel.getValueAsLong())) {
      case 0l:
        id356x_1 = id356in_option0;
        break;
      case 1l:
        id356x_1 = id356in_option1;
        break;
      default:
        id356x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id356out_result = (id356x_1);
  }
  { // Node ID: 4255 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4255in_input = id356out_result;

    id4255out_output[(getCycle()+1)%2] = id4255in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id342out_output;

  { // Node ID: 342 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id342in_input = id4258out_output[getCycle()%2];

    id342out_output = id342in_input;
  }
  { // Node ID: 3207 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2865out_result;

  { // Node ID: 2865 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2865in_a = id3207out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2865in_b = id3513out_output[getCycle()%2];

    id2865out_result = (eq_fixed(id2865in_a,id2865in_b));
  }
  { // Node ID: 4259 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4259in_input = id2865out_result;

    id4259out_output[(getCycle()+4)%5] = id4259in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id341out_o;

  { // Node ID: 341 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id341in_i = id4259out_output[getCycle()%5];

    id341out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id341in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id343out_result;

  { // Node ID: 343 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id343in_a = id342out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id343in_b = id341out_o;

    id343out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id343in_a,id343in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id344out_result;

  { // Node ID: 344 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id344in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id344in_option0 = id343out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id344in_option1 = id341out_o;

    HWOffsetFix<32,0,UNSIGNED> id344x_1;

    switch((id344in_sel.getValueAsLong())) {
      case 0l:
        id344x_1 = id344in_option0;
        break;
      case 1l:
        id344x_1 = id344in_option1;
        break;
      default:
        id344x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id344out_result = (id344x_1);
  }
  { // Node ID: 4258 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4258in_input = id344out_result;

    id4258out_output[(getCycle()+1)%2] = id4258in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id330out_output;

  { // Node ID: 330 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id330in_input = id4261out_output[getCycle()%2];

    id330out_output = id330in_input;
  }
  { // Node ID: 3206 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2866out_result;

  { // Node ID: 2866 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2866in_a = id3206out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2866in_b = id3513out_output[getCycle()%2];

    id2866out_result = (eq_fixed(id2866in_a,id2866in_b));
  }
  { // Node ID: 4262 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4262in_input = id2866out_result;

    id4262out_output[(getCycle()+4)%5] = id4262in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id329out_o;

  { // Node ID: 329 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id329in_i = id4262out_output[getCycle()%5];

    id329out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id329in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id331out_result;

  { // Node ID: 331 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id331in_a = id330out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id331in_b = id329out_o;

    id331out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id331in_a,id331in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id332out_result;

  { // Node ID: 332 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id332in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id332in_option0 = id331out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id332in_option1 = id329out_o;

    HWOffsetFix<32,0,UNSIGNED> id332x_1;

    switch((id332in_sel.getValueAsLong())) {
      case 0l:
        id332x_1 = id332in_option0;
        break;
      case 1l:
        id332x_1 = id332in_option1;
        break;
      default:
        id332x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id332out_result = (id332x_1);
  }
  { // Node ID: 4261 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4261in_input = id332out_result;

    id4261out_output[(getCycle()+1)%2] = id4261in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id318out_output;

  { // Node ID: 318 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id318in_input = id4264out_output[getCycle()%2];

    id318out_output = id318in_input;
  }
  { // Node ID: 3205 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2867out_result;

  { // Node ID: 2867 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2867in_a = id3205out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2867in_b = id3513out_output[getCycle()%2];

    id2867out_result = (eq_fixed(id2867in_a,id2867in_b));
  }
  { // Node ID: 4265 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4265in_input = id2867out_result;

    id4265out_output[(getCycle()+4)%5] = id4265in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id317out_o;

  { // Node ID: 317 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id317in_i = id4265out_output[getCycle()%5];

    id317out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id317in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id319out_result;

  { // Node ID: 319 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id319in_a = id318out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id319in_b = id317out_o;

    id319out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id319in_a,id319in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id320out_result;

  { // Node ID: 320 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id320in_sel = id3699out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id320in_option0 = id319out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id320in_option1 = id317out_o;

    HWOffsetFix<32,0,UNSIGNED> id320x_1;

    switch((id320in_sel.getValueAsLong())) {
      case 0l:
        id320x_1 = id320in_option0;
        break;
      case 1l:
        id320x_1 = id320in_option1;
        break;
      default:
        id320x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id320out_result = (id320x_1);
  }
  { // Node ID: 4264 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4264in_input = id320out_result;

    id4264out_output[(getCycle()+1)%2] = id4264in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id306out_output;

  { // Node ID: 306 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id306in_input = id4267out_output[getCycle()%2];

    id306out_output = id306in_input;
  }
  { // Node ID: 3204 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2868out_result;

  { // Node ID: 2868 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2868in_a = id3204out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2868in_b = id3513out_output[getCycle()%2];

    id2868out_result = (eq_fixed(id2868in_a,id2868in_b));
  }
  { // Node ID: 4268 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4268in_input = id2868out_result;

    id4268out_output[(getCycle()+4)%5] = id4268in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id305out_o;

  { // Node ID: 305 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id305in_i = id4268out_output[getCycle()%5];

    id305out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id305in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id307out_result;

  { // Node ID: 307 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id307in_a = id306out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id307in_b = id305out_o;

    id307out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id307in_a,id307in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id308out_result;

  { // Node ID: 308 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id308in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id308in_option0 = id307out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id308in_option1 = id305out_o;

    HWOffsetFix<32,0,UNSIGNED> id308x_1;

    switch((id308in_sel.getValueAsLong())) {
      case 0l:
        id308x_1 = id308in_option0;
        break;
      case 1l:
        id308x_1 = id308in_option1;
        break;
      default:
        id308x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id308out_result = (id308x_1);
  }
  { // Node ID: 4267 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4267in_input = id308out_result;

    id4267out_output[(getCycle()+1)%2] = id4267in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id294out_output;

  { // Node ID: 294 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id294in_input = id4269out_output[getCycle()%2];

    id294out_output = id294in_input;
  }
  { // Node ID: 3203 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2869out_result;

  { // Node ID: 2869 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2869in_a = id3203out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2869in_b = id69out_o[getCycle()%8];

    id2869out_result = (eq_fixed(id2869in_a,id2869in_b));
  }
  { // Node ID: 4270 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4270in_input = id2869out_result;

    id4270out_output[(getCycle()+5)%6] = id4270in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id293out_o;

  { // Node ID: 293 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id293in_i = id4270out_output[getCycle()%6];

    id293out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id293in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id295out_result;

  { // Node ID: 295 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id295in_a = id294out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id295in_b = id293out_o;

    id295out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id295in_a,id295in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id296out_result;

  { // Node ID: 296 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id296in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id296in_option0 = id295out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id296in_option1 = id293out_o;

    HWOffsetFix<32,0,UNSIGNED> id296x_1;

    switch((id296in_sel.getValueAsLong())) {
      case 0l:
        id296x_1 = id296in_option0;
        break;
      case 1l:
        id296x_1 = id296in_option1;
        break;
      default:
        id296x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id296out_result = (id296x_1);
  }
  { // Node ID: 4269 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4269in_input = id296out_result;

    id4269out_output[(getCycle()+1)%2] = id4269in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id282out_output;

  { // Node ID: 282 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id282in_input = id4271out_output[getCycle()%2];

    id282out_output = id282in_input;
  }
  { // Node ID: 3202 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2870out_result;

  { // Node ID: 2870 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2870in_a = id3202out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2870in_b = id69out_o[getCycle()%8];

    id2870out_result = (eq_fixed(id2870in_a,id2870in_b));
  }
  { // Node ID: 4272 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4272in_input = id2870out_result;

    id4272out_output[(getCycle()+5)%6] = id4272in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id281out_o;

  { // Node ID: 281 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id281in_i = id4272out_output[getCycle()%6];

    id281out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id281in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id283out_result;

  { // Node ID: 283 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id283in_a = id282out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id283in_b = id281out_o;

    id283out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id283in_a,id283in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id284out_result;

  { // Node ID: 284 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id284in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id284in_option0 = id283out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id284in_option1 = id281out_o;

    HWOffsetFix<32,0,UNSIGNED> id284x_1;

    switch((id284in_sel.getValueAsLong())) {
      case 0l:
        id284x_1 = id284in_option0;
        break;
      case 1l:
        id284x_1 = id284in_option1;
        break;
      default:
        id284x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id284out_result = (id284x_1);
  }
  { // Node ID: 4271 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4271in_input = id284out_result;

    id4271out_output[(getCycle()+1)%2] = id4271in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id270out_output;

  { // Node ID: 270 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id270in_input = id4273out_output[getCycle()%2];

    id270out_output = id270in_input;
  }
  { // Node ID: 3201 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2871out_result;

  { // Node ID: 2871 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2871in_a = id3201out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2871in_b = id69out_o[getCycle()%8];

    id2871out_result = (eq_fixed(id2871in_a,id2871in_b));
  }
  { // Node ID: 4274 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4274in_input = id2871out_result;

    id4274out_output[(getCycle()+5)%6] = id4274in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id269out_o;

  { // Node ID: 269 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id269in_i = id4274out_output[getCycle()%6];

    id269out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id269in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id271out_result;

  { // Node ID: 271 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id271in_a = id270out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id271in_b = id269out_o;

    id271out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id271in_a,id271in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id272out_result;

  { // Node ID: 272 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id272in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id272in_option0 = id271out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id272in_option1 = id269out_o;

    HWOffsetFix<32,0,UNSIGNED> id272x_1;

    switch((id272in_sel.getValueAsLong())) {
      case 0l:
        id272x_1 = id272in_option0;
        break;
      case 1l:
        id272x_1 = id272in_option1;
        break;
      default:
        id272x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id272out_result = (id272x_1);
  }
  { // Node ID: 4273 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4273in_input = id272out_result;

    id4273out_output[(getCycle()+1)%2] = id4273in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id258out_output;

  { // Node ID: 258 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id258in_input = id4275out_output[getCycle()%2];

    id258out_output = id258in_input;
  }
  { // Node ID: 3200 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2872out_result;

  { // Node ID: 2872 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2872in_a = id3200out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2872in_b = id69out_o[getCycle()%8];

    id2872out_result = (eq_fixed(id2872in_a,id2872in_b));
  }
  { // Node ID: 4276 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4276in_input = id2872out_result;

    id4276out_output[(getCycle()+5)%6] = id4276in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id257out_o;

  { // Node ID: 257 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id257in_i = id4276out_output[getCycle()%6];

    id257out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id257in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id259out_result;

  { // Node ID: 259 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id259in_a = id258out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id259in_b = id257out_o;

    id259out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id259in_a,id259in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id260out_result;

  { // Node ID: 260 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id260in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id260in_option0 = id259out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id260in_option1 = id257out_o;

    HWOffsetFix<32,0,UNSIGNED> id260x_1;

    switch((id260in_sel.getValueAsLong())) {
      case 0l:
        id260x_1 = id260in_option0;
        break;
      case 1l:
        id260x_1 = id260in_option1;
        break;
      default:
        id260x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id260out_result = (id260x_1);
  }
  { // Node ID: 4275 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4275in_input = id260out_result;

    id4275out_output[(getCycle()+1)%2] = id4275in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id246out_output;

  { // Node ID: 246 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id246in_input = id4277out_output[getCycle()%2];

    id246out_output = id246in_input;
  }
  { // Node ID: 3199 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2873out_result;

  { // Node ID: 2873 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2873in_a = id3199out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2873in_b = id69out_o[getCycle()%8];

    id2873out_result = (eq_fixed(id2873in_a,id2873in_b));
  }
  { // Node ID: 4278 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4278in_input = id2873out_result;

    id4278out_output[(getCycle()+5)%6] = id4278in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id245out_o;

  { // Node ID: 245 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id245in_i = id4278out_output[getCycle()%6];

    id245out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id245in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id247out_result;

  { // Node ID: 247 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id247in_a = id246out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id247in_b = id245out_o;

    id247out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id247in_a,id247in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id248out_result;

  { // Node ID: 248 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id248in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id248in_option0 = id247out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id248in_option1 = id245out_o;

    HWOffsetFix<32,0,UNSIGNED> id248x_1;

    switch((id248in_sel.getValueAsLong())) {
      case 0l:
        id248x_1 = id248in_option0;
        break;
      case 1l:
        id248x_1 = id248in_option1;
        break;
      default:
        id248x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id248out_result = (id248x_1);
  }
  { // Node ID: 4277 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4277in_input = id248out_result;

    id4277out_output[(getCycle()+1)%2] = id4277in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id234out_output;

  { // Node ID: 234 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id234in_input = id4279out_output[getCycle()%2];

    id234out_output = id234in_input;
  }
  { // Node ID: 3198 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2874out_result;

  { // Node ID: 2874 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2874in_a = id3198out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2874in_b = id69out_o[getCycle()%8];

    id2874out_result = (eq_fixed(id2874in_a,id2874in_b));
  }
  { // Node ID: 4280 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4280in_input = id2874out_result;

    id4280out_output[(getCycle()+5)%6] = id4280in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id233out_o;

  { // Node ID: 233 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id233in_i = id4280out_output[getCycle()%6];

    id233out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id233in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id235out_result;

  { // Node ID: 235 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id235in_a = id234out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id235in_b = id233out_o;

    id235out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id235in_a,id235in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id236out_result;

  { // Node ID: 236 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id236in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id236in_option0 = id235out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id236in_option1 = id233out_o;

    HWOffsetFix<32,0,UNSIGNED> id236x_1;

    switch((id236in_sel.getValueAsLong())) {
      case 0l:
        id236x_1 = id236in_option0;
        break;
      case 1l:
        id236x_1 = id236in_option1;
        break;
      default:
        id236x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id236out_result = (id236x_1);
  }
  { // Node ID: 4279 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4279in_input = id236out_result;

    id4279out_output[(getCycle()+1)%2] = id4279in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id222out_output;

  { // Node ID: 222 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id222in_input = id4281out_output[getCycle()%2];

    id222out_output = id222in_input;
  }
  { // Node ID: 3197 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2875out_result;

  { // Node ID: 2875 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2875in_a = id3197out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2875in_b = id69out_o[getCycle()%8];

    id2875out_result = (eq_fixed(id2875in_a,id2875in_b));
  }
  { // Node ID: 4282 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4282in_input = id2875out_result;

    id4282out_output[(getCycle()+5)%6] = id4282in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id221out_o;

  { // Node ID: 221 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id221in_i = id4282out_output[getCycle()%6];

    id221out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id221in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id223out_result;

  { // Node ID: 223 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id223in_a = id222out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id223in_b = id221out_o;

    id223out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id223in_a,id223in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id224out_result;

  { // Node ID: 224 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id224in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id224in_option0 = id223out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id224in_option1 = id221out_o;

    HWOffsetFix<32,0,UNSIGNED> id224x_1;

    switch((id224in_sel.getValueAsLong())) {
      case 0l:
        id224x_1 = id224in_option0;
        break;
      case 1l:
        id224x_1 = id224in_option1;
        break;
      default:
        id224x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id224out_result = (id224x_1);
  }
  { // Node ID: 4281 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4281in_input = id224out_result;

    id4281out_output[(getCycle()+1)%2] = id4281in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id210out_output;

  { // Node ID: 210 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id210in_input = id4283out_output[getCycle()%2];

    id210out_output = id210in_input;
  }
  { // Node ID: 3196 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2876out_result;

  { // Node ID: 2876 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2876in_a = id3196out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2876in_b = id69out_o[getCycle()%8];

    id2876out_result = (eq_fixed(id2876in_a,id2876in_b));
  }
  { // Node ID: 4284 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4284in_input = id2876out_result;

    id4284out_output[(getCycle()+5)%6] = id4284in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id209out_o;

  { // Node ID: 209 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id209in_i = id4284out_output[getCycle()%6];

    id209out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id209in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id211out_result;

  { // Node ID: 211 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id211in_a = id210out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id211in_b = id209out_o;

    id211out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id211in_a,id211in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id212out_result;

  { // Node ID: 212 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id212in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id212in_option0 = id211out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id212in_option1 = id209out_o;

    HWOffsetFix<32,0,UNSIGNED> id212x_1;

    switch((id212in_sel.getValueAsLong())) {
      case 0l:
        id212x_1 = id212in_option0;
        break;
      case 1l:
        id212x_1 = id212in_option1;
        break;
      default:
        id212x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id212out_result = (id212x_1);
  }
  { // Node ID: 4283 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4283in_input = id212out_result;

    id4283out_output[(getCycle()+1)%2] = id4283in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id198out_output;

  { // Node ID: 198 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id198in_input = id4285out_output[getCycle()%2];

    id198out_output = id198in_input;
  }
  { // Node ID: 3195 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2877out_result;

  { // Node ID: 2877 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2877in_a = id3195out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2877in_b = id69out_o[getCycle()%8];

    id2877out_result = (eq_fixed(id2877in_a,id2877in_b));
  }
  { // Node ID: 4286 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4286in_input = id2877out_result;

    id4286out_output[(getCycle()+5)%6] = id4286in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id197out_o;

  { // Node ID: 197 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id197in_i = id4286out_output[getCycle()%6];

    id197out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id197in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id199out_result;

  { // Node ID: 199 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id199in_a = id198out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id199in_b = id197out_o;

    id199out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id199in_a,id199in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id200out_result;

  { // Node ID: 200 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id200in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id200in_option0 = id199out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id200in_option1 = id197out_o;

    HWOffsetFix<32,0,UNSIGNED> id200x_1;

    switch((id200in_sel.getValueAsLong())) {
      case 0l:
        id200x_1 = id200in_option0;
        break;
      case 1l:
        id200x_1 = id200in_option1;
        break;
      default:
        id200x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id200out_result = (id200x_1);
  }
  { // Node ID: 4285 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4285in_input = id200out_result;

    id4285out_output[(getCycle()+1)%2] = id4285in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id186out_output;

  { // Node ID: 186 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id186in_input = id4287out_output[getCycle()%2];

    id186out_output = id186in_input;
  }
  { // Node ID: 3194 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2878out_result;

  { // Node ID: 2878 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2878in_a = id3194out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2878in_b = id69out_o[getCycle()%8];

    id2878out_result = (eq_fixed(id2878in_a,id2878in_b));
  }
  { // Node ID: 4288 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4288in_input = id2878out_result;

    id4288out_output[(getCycle()+5)%6] = id4288in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id185out_o;

  { // Node ID: 185 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id185in_i = id4288out_output[getCycle()%6];

    id185out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id185in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id187out_result;

  { // Node ID: 187 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id187in_a = id186out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id187in_b = id185out_o;

    id187out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id187in_a,id187in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id188out_result;

  { // Node ID: 188 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id188in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id188in_option0 = id187out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id188in_option1 = id185out_o;

    HWOffsetFix<32,0,UNSIGNED> id188x_1;

    switch((id188in_sel.getValueAsLong())) {
      case 0l:
        id188x_1 = id188in_option0;
        break;
      case 1l:
        id188x_1 = id188in_option1;
        break;
      default:
        id188x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id188out_result = (id188x_1);
  }
  { // Node ID: 4287 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4287in_input = id188out_result;

    id4287out_output[(getCycle()+1)%2] = id4287in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id174out_output;

  { // Node ID: 174 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id174in_input = id4289out_output[getCycle()%2];

    id174out_output = id174in_input;
  }
  { // Node ID: 3193 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2879out_result;

  { // Node ID: 2879 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2879in_a = id3193out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2879in_b = id69out_o[getCycle()%8];

    id2879out_result = (eq_fixed(id2879in_a,id2879in_b));
  }
  { // Node ID: 4290 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4290in_input = id2879out_result;

    id4290out_output[(getCycle()+5)%6] = id4290in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id173out_o;

  { // Node ID: 173 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id173in_i = id4290out_output[getCycle()%6];

    id173out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id173in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id175out_result;

  { // Node ID: 175 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id175in_a = id174out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id175in_b = id173out_o;

    id175out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id175in_a,id175in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id176out_result;

  { // Node ID: 176 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id176in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id176in_option0 = id175out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id176in_option1 = id173out_o;

    HWOffsetFix<32,0,UNSIGNED> id176x_1;

    switch((id176in_sel.getValueAsLong())) {
      case 0l:
        id176x_1 = id176in_option0;
        break;
      case 1l:
        id176x_1 = id176in_option1;
        break;
      default:
        id176x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id176out_result = (id176x_1);
  }
  { // Node ID: 4289 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4289in_input = id176out_result;

    id4289out_output[(getCycle()+1)%2] = id4289in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id162out_output;

  { // Node ID: 162 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id162in_input = id4291out_output[getCycle()%2];

    id162out_output = id162in_input;
  }
  { // Node ID: 3192 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2880out_result;

  { // Node ID: 2880 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2880in_a = id3192out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2880in_b = id69out_o[getCycle()%8];

    id2880out_result = (eq_fixed(id2880in_a,id2880in_b));
  }
  { // Node ID: 4292 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4292in_input = id2880out_result;

    id4292out_output[(getCycle()+5)%6] = id4292in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id161out_o;

  { // Node ID: 161 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id161in_i = id4292out_output[getCycle()%6];

    id161out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id161in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id163out_result;

  { // Node ID: 163 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id163in_a = id162out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id163in_b = id161out_o;

    id163out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id163in_a,id163in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id164out_result;

  { // Node ID: 164 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id164in_option0 = id163out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id164in_option1 = id161out_o;

    HWOffsetFix<32,0,UNSIGNED> id164x_1;

    switch((id164in_sel.getValueAsLong())) {
      case 0l:
        id164x_1 = id164in_option0;
        break;
      case 1l:
        id164x_1 = id164in_option1;
        break;
      default:
        id164x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id164out_result = (id164x_1);
  }
  { // Node ID: 4291 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4291in_input = id164out_result;

    id4291out_output[(getCycle()+1)%2] = id4291in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id150out_output;

  { // Node ID: 150 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id150in_input = id4293out_output[getCycle()%2];

    id150out_output = id150in_input;
  }
  { // Node ID: 3191 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2881out_result;

  { // Node ID: 2881 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2881in_a = id3191out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2881in_b = id69out_o[getCycle()%8];

    id2881out_result = (eq_fixed(id2881in_a,id2881in_b));
  }
  { // Node ID: 4294 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4294in_input = id2881out_result;

    id4294out_output[(getCycle()+5)%6] = id4294in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id149out_o;

  { // Node ID: 149 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id149in_i = id4294out_output[getCycle()%6];

    id149out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id149in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id151out_result;

  { // Node ID: 151 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id151in_a = id150out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id151in_b = id149out_o;

    id151out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id151in_a,id151in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id152out_result;

  { // Node ID: 152 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id152in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id152in_option0 = id151out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id152in_option1 = id149out_o;

    HWOffsetFix<32,0,UNSIGNED> id152x_1;

    switch((id152in_sel.getValueAsLong())) {
      case 0l:
        id152x_1 = id152in_option0;
        break;
      case 1l:
        id152x_1 = id152in_option1;
        break;
      default:
        id152x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id152out_result = (id152x_1);
  }
  { // Node ID: 4293 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4293in_input = id152out_result;

    id4293out_output[(getCycle()+1)%2] = id4293in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id138out_output;

  { // Node ID: 138 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id138in_input = id4295out_output[getCycle()%2];

    id138out_output = id138in_input;
  }
  { // Node ID: 3190 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2882out_result;

  { // Node ID: 2882 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2882in_a = id3190out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2882in_b = id69out_o[getCycle()%8];

    id2882out_result = (eq_fixed(id2882in_a,id2882in_b));
  }
  { // Node ID: 4296 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4296in_input = id2882out_result;

    id4296out_output[(getCycle()+5)%6] = id4296in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id137out_o;

  { // Node ID: 137 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id137in_i = id4296out_output[getCycle()%6];

    id137out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id137in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id139out_result;

  { // Node ID: 139 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id139in_a = id138out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id139in_b = id137out_o;

    id139out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id139in_a,id139in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id140out_result;

  { // Node ID: 140 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id140in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id140in_option0 = id139out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id140in_option1 = id137out_o;

    HWOffsetFix<32,0,UNSIGNED> id140x_1;

    switch((id140in_sel.getValueAsLong())) {
      case 0l:
        id140x_1 = id140in_option0;
        break;
      case 1l:
        id140x_1 = id140in_option1;
        break;
      default:
        id140x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id140out_result = (id140x_1);
  }
  { // Node ID: 4295 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4295in_input = id140out_result;

    id4295out_output[(getCycle()+1)%2] = id4295in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id126out_output;

  { // Node ID: 126 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id126in_input = id4297out_output[getCycle()%2];

    id126out_output = id126in_input;
  }
  { // Node ID: 3189 (NodeConstantRawBits)
  }
  HWOffsetFix<1,0,UNSIGNED> id2883out_result;

  { // Node ID: 2883 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id2883in_a = id3189out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id2883in_b = id69out_o[getCycle()%8];

    id2883out_result = (eq_fixed(id2883in_a,id2883in_b));
  }
  { // Node ID: 4298 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id4298in_input = id2883out_result;

    id4298out_output[(getCycle()+5)%6] = id4298in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id125out_o;

  { // Node ID: 125 (NodeCast)
    const HWOffsetFix<1,0,UNSIGNED> &id125in_i = id4298out_output[getCycle()%6];

    id125out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(id125in_i));
  }
  HWOffsetFix<32,0,UNSIGNED> id127out_result;

  { // Node ID: 127 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id127in_a = id126out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id127in_b = id125out_o;

    id127out_result = (add_fixed<32,0,UNSIGNED,TONEAREVEN>(id127in_a,id127in_b));
  }
  HWOffsetFix<32,0,UNSIGNED> id128out_result;

  { // Node ID: 128 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id128in_sel = id3514out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id128in_option0 = id127out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id128in_option1 = id125out_o;

    HWOffsetFix<32,0,UNSIGNED> id128x_1;

    switch((id128in_sel.getValueAsLong())) {
      case 0l:
        id128x_1 = id128in_option0;
        break;
      case 1l:
        id128x_1 = id128in_option1;
        break;
      default:
        id128x_1 = (HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id128out_result = (id128x_1);
  }
  { // Node ID: 4297 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id4297in_input = id128out_result;

    id4297out_output[(getCycle()+1)%2] = id4297in_input;
  }
  HWRawBits<9728> id3185out_result;

  { // Node ID: 3185 (NodeCat)
    const HWRawBits<32> &id3185in_in0 = id2564out_value;
    const HWRawBits<32> &id3185in_in1 = id2565out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in2 = id1334out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in3 = id1322out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in4 = id1310out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in5 = id1298out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in6 = id1286out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in7 = id1274out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in8 = id1262out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in9 = id1250out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in10 = id1238out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in11 = id1226out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in12 = id1214out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in13 = id1202out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in14 = id1190out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in15 = id1178out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in16 = id1166out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in17 = id1154out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in18 = id1142out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in19 = id1130out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in20 = id1118out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in21 = id1106out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in22 = id1094out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in23 = id1082out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in24 = id1070out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in25 = id1058out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in26 = id1046out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in27 = id1034out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in28 = id1022out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in29 = id1010out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in30 = id998out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in31 = id986out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in32 = id974out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in33 = id962out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in34 = id3614out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in35 = id3616out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in36 = id3618out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in37 = id3620out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in38 = id3622out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in39 = id3624out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in40 = id3626out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in41 = id3628out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in42 = id3630out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in43 = id3632out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in44 = id3634out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in45 = id3636out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in46 = id3638out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in47 = id3640out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in48 = id3642out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in49 = id3644out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in50 = id3646out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in51 = id3648out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in52 = id3650out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in53 = id3652out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in54 = id3654out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in55 = id3656out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in56 = id3658out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in57 = id3660out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in58 = id3662out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in59 = id3664out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in60 = id3666out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in61 = id3668out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in62 = id3670out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in63 = id3672out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in64 = id3674out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in65 = id3676out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in66 = id3679out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in67 = id3682out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in68 = id3685out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in69 = id3688out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in70 = id3691out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in71 = id3694out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in72 = id3697out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in73 = id3700out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in74 = id3703out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in75 = id3706out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in76 = id3709out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in77 = id3712out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in78 = id3715out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in79 = id3718out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in80 = id3721out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in81 = id3724out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in82 = id3727out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in83 = id3730out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in84 = id3733out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in85 = id3736out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in86 = id3739out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in87 = id3742out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in88 = id3744out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in89 = id3746out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in90 = id3748out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in91 = id3750out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in92 = id3752out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in93 = id3754out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in94 = id3756out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in95 = id3758out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in96 = id3760out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in97 = id3762out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in98 = id3764out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in99 = id3766out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in100 = id3768out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in101 = id3770out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in102 = id3772out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in103 = id1934out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in104 = id1928out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in105 = id1922out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in106 = id1916out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in107 = id1910out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in108 = id1904out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in109 = id1898out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in110 = id1892out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in111 = id1886out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in112 = id1880out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in113 = id1874out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in114 = id1868out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in115 = id1862out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in116 = id1856out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in117 = id1850out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in118 = id1844out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in119 = id1838out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in120 = id1832out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in121 = id1826out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in122 = id1820out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in123 = id1814out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in124 = id1808out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in125 = id1802out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in126 = id1796out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in127 = id1790out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in128 = id1784out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in129 = id1778out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in130 = id1772out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in131 = id1766out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in132 = id1760out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in133 = id1754out_result;
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in134 = id3836out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in135 = id3838out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in136 = id3840out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in137 = id3842out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in138 = id3844out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in139 = id3846out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in140 = id3848out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in141 = id3850out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in142 = id3852out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in143 = id3854out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in144 = id3856out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in145 = id3858out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in146 = id3860out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in147 = id3862out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in148 = id3864out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in149 = id3866out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in150 = id3868out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in151 = id3870out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in152 = id3872out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in153 = id3874out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in154 = id3876out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in155 = id3878out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in156 = id3880out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in157 = id3882out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in158 = id3884out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in159 = id3886out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in160 = id3888out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in161 = id3890out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in162 = id3892out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in163 = id3894out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in164 = id3896out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in165 = id3898out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in166 = id3901out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in167 = id3904out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in168 = id3907out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in169 = id3910out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in170 = id3913out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in171 = id3916out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in172 = id3919out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in173 = id3922out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in174 = id3925out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in175 = id3928out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in176 = id3931out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in177 = id3934out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in178 = id3937out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in179 = id3940out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in180 = id3943out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in181 = id3946out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in182 = id3949out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in183 = id3952out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in184 = id3955out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in185 = id3958out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in186 = id3961out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in187 = id3964out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in188 = id3967out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in189 = id3970out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in190 = id3973out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in191 = id3976out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in192 = id3979out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in193 = id3982out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in194 = id3985out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in195 = id3988out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in196 = id3991out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in197 = id3994out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in198 = id3997out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in199 = id4000out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in200 = id4003out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in201 = id4006out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in202 = id4009out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in203 = id4012out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in204 = id4015out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in205 = id4018out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in206 = id4021out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in207 = id4024out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in208 = id4027out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in209 = id4030out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in210 = id4033out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in211 = id4036out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in212 = id4039out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in213 = id4042out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in214 = id4045out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in215 = id4048out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in216 = id4051out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in217 = id4054out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in218 = id4057out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in219 = id4060out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in220 = id4063out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in221 = id4066out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in222 = id4069out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in223 = id4072out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in224 = id4075out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in225 = id4078out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in226 = id4081out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in227 = id4084out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in228 = id4087out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in229 = id4090out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in230 = id4093out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in231 = id4096out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in232 = id4099out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in233 = id4102out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in234 = id4105out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in235 = id4108out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in236 = id4111out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in237 = id4114out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in238 = id4117out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in239 = id4120out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in240 = id4123out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in241 = id4126out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in242 = id4129out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in243 = id4132out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in244 = id4135out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in245 = id4138out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in246 = id4141out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in247 = id4144out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in248 = id4147out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in249 = id4150out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in250 = id4153out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in251 = id4156out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in252 = id4159out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in253 = id4162out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in254 = id4165out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in255 = id4168out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in256 = id4171out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in257 = id4174out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in258 = id4177out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in259 = id4180out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in260 = id4183out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in261 = id4186out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in262 = id4189out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in263 = id4192out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in264 = id4195out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in265 = id4198out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in266 = id4201out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in267 = id4204out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in268 = id4207out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in269 = id4210out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in270 = id4213out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in271 = id4216out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in272 = id4219out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in273 = id4222out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in274 = id4225out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in275 = id4228out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in276 = id4231out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in277 = id4234out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in278 = id4237out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in279 = id4240out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in280 = id4243out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in281 = id4246out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in282 = id4249out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in283 = id4252out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in284 = id4255out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in285 = id4258out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in286 = id4261out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in287 = id4264out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in288 = id4267out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in289 = id4269out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in290 = id4271out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in291 = id4273out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in292 = id4275out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in293 = id4277out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in294 = id4279out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in295 = id4281out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in296 = id4283out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in297 = id4285out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in298 = id4287out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in299 = id4289out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in300 = id4291out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in301 = id4293out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in302 = id4295out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id3185in_in303 = id4297out_output[getCycle()%2];

    id3185out_result = (cat((cat((cat((cat((cat((cat((cat((cat((cat(id3185in_in0,id3185in_in1)),id3185in_in2)),(cat(id3185in_in3,id3185in_in4)))),(cat((cat((cat(id3185in_in5,id3185in_in6)),id3185in_in7)),(cat(id3185in_in8,id3185in_in9)))))),(cat((cat((cat((cat(id3185in_in10,id3185in_in11)),id3185in_in12)),(cat(id3185in_in13,id3185in_in14)))),(cat((cat(id3185in_in15,id3185in_in16)),(cat(id3185in_in17,id3185in_in18)))))))),(cat((cat((cat((cat((cat(id3185in_in19,id3185in_in20)),id3185in_in21)),(cat(id3185in_in22,id3185in_in23)))),(cat((cat((cat(id3185in_in24,id3185in_in25)),id3185in_in26)),(cat(id3185in_in27,id3185in_in28)))))),(cat((cat((cat((cat(id3185in_in29,id3185in_in30)),id3185in_in31)),(cat(id3185in_in32,id3185in_in33)))),(cat((cat(id3185in_in34,id3185in_in35)),(cat(id3185in_in36,id3185in_in37)))))))))),(cat((cat((cat((cat((cat((cat(id3185in_in38,id3185in_in39)),id3185in_in40)),(cat(id3185in_in41,id3185in_in42)))),(cat((cat((cat(id3185in_in43,id3185in_in44)),id3185in_in45)),(cat(id3185in_in46,id3185in_in47)))))),(cat((cat((cat((cat(id3185in_in48,id3185in_in49)),id3185in_in50)),(cat(id3185in_in51,id3185in_in52)))),(cat((cat(id3185in_in53,id3185in_in54)),(cat(id3185in_in55,id3185in_in56)))))))),(cat((cat((cat((cat((cat(id3185in_in57,id3185in_in58)),id3185in_in59)),(cat(id3185in_in60,id3185in_in61)))),(cat((cat((cat(id3185in_in62,id3185in_in63)),id3185in_in64)),(cat(id3185in_in65,id3185in_in66)))))),(cat((cat((cat((cat(id3185in_in67,id3185in_in68)),id3185in_in69)),(cat(id3185in_in70,id3185in_in71)))),(cat((cat(id3185in_in72,id3185in_in73)),(cat(id3185in_in74,id3185in_in75)))))))))))),(cat((cat((cat((cat((cat((cat((cat(id3185in_in76,id3185in_in77)),id3185in_in78)),(cat(id3185in_in79,id3185in_in80)))),(cat((cat((cat(id3185in_in81,id3185in_in82)),id3185in_in83)),(cat(id3185in_in84,id3185in_in85)))))),(cat((cat((cat((cat(id3185in_in86,id3185in_in87)),id3185in_in88)),(cat(id3185in_in89,id3185in_in90)))),(cat((cat(id3185in_in91,id3185in_in92)),(cat(id3185in_in93,id3185in_in94)))))))),(cat((cat((cat((cat((cat(id3185in_in95,id3185in_in96)),id3185in_in97)),(cat(id3185in_in98,id3185in_in99)))),(cat((cat((cat(id3185in_in100,id3185in_in101)),id3185in_in102)),(cat(id3185in_in103,id3185in_in104)))))),(cat((cat((cat((cat(id3185in_in105,id3185in_in106)),id3185in_in107)),(cat(id3185in_in108,id3185in_in109)))),(cat((cat(id3185in_in110,id3185in_in111)),(cat(id3185in_in112,id3185in_in113)))))))))),(cat((cat((cat((cat((cat((cat(id3185in_in114,id3185in_in115)),id3185in_in116)),(cat(id3185in_in117,id3185in_in118)))),(cat((cat((cat(id3185in_in119,id3185in_in120)),id3185in_in121)),(cat(id3185in_in122,id3185in_in123)))))),(cat((cat((cat((cat(id3185in_in124,id3185in_in125)),id3185in_in126)),(cat(id3185in_in127,id3185in_in128)))),(cat((cat(id3185in_in129,id3185in_in130)),(cat(id3185in_in131,id3185in_in132)))))))),(cat((cat((cat((cat((cat(id3185in_in133,id3185in_in134)),id3185in_in135)),(cat(id3185in_in136,id3185in_in137)))),(cat((cat((cat(id3185in_in138,id3185in_in139)),id3185in_in140)),(cat(id3185in_in141,id3185in_in142)))))),(cat((cat((cat((cat(id3185in_in143,id3185in_in144)),id3185in_in145)),(cat(id3185in_in146,id3185in_in147)))),(cat((cat(id3185in_in148,id3185in_in149)),(cat(id3185in_in150,id3185in_in151)))))))))))))),(cat((cat((cat((cat((cat((cat((cat((cat(id3185in_in152,id3185in_in153)),id3185in_in154)),(cat(id3185in_in155,id3185in_in156)))),(cat((cat((cat(id3185in_in157,id3185in_in158)),id3185in_in159)),(cat(id3185in_in160,id3185in_in161)))))),(cat((cat((cat((cat(id3185in_in162,id3185in_in163)),id3185in_in164)),(cat(id3185in_in165,id3185in_in166)))),(cat((cat(id3185in_in167,id3185in_in168)),(cat(id3185in_in169,id3185in_in170)))))))),(cat((cat((cat((cat((cat(id3185in_in171,id3185in_in172)),id3185in_in173)),(cat(id3185in_in174,id3185in_in175)))),(cat((cat((cat(id3185in_in176,id3185in_in177)),id3185in_in178)),(cat(id3185in_in179,id3185in_in180)))))),(cat((cat((cat((cat(id3185in_in181,id3185in_in182)),id3185in_in183)),(cat(id3185in_in184,id3185in_in185)))),(cat((cat(id3185in_in186,id3185in_in187)),(cat(id3185in_in188,id3185in_in189)))))))))),(cat((cat((cat((cat((cat((cat(id3185in_in190,id3185in_in191)),id3185in_in192)),(cat(id3185in_in193,id3185in_in194)))),(cat((cat((cat(id3185in_in195,id3185in_in196)),id3185in_in197)),(cat(id3185in_in198,id3185in_in199)))))),(cat((cat((cat((cat(id3185in_in200,id3185in_in201)),id3185in_in202)),(cat(id3185in_in203,id3185in_in204)))),(cat((cat(id3185in_in205,id3185in_in206)),(cat(id3185in_in207,id3185in_in208)))))))),(cat((cat((cat((cat((cat(id3185in_in209,id3185in_in210)),id3185in_in211)),(cat(id3185in_in212,id3185in_in213)))),(cat((cat((cat(id3185in_in214,id3185in_in215)),id3185in_in216)),(cat(id3185in_in217,id3185in_in218)))))),(cat((cat((cat((cat(id3185in_in219,id3185in_in220)),id3185in_in221)),(cat(id3185in_in222,id3185in_in223)))),(cat((cat(id3185in_in224,id3185in_in225)),(cat(id3185in_in226,id3185in_in227)))))))))))),(cat((cat((cat((cat((cat((cat((cat(id3185in_in228,id3185in_in229)),id3185in_in230)),(cat(id3185in_in231,id3185in_in232)))),(cat((cat((cat(id3185in_in233,id3185in_in234)),id3185in_in235)),(cat(id3185in_in236,id3185in_in237)))))),(cat((cat((cat((cat(id3185in_in238,id3185in_in239)),id3185in_in240)),(cat(id3185in_in241,id3185in_in242)))),(cat((cat(id3185in_in243,id3185in_in244)),(cat(id3185in_in245,id3185in_in246)))))))),(cat((cat((cat((cat((cat(id3185in_in247,id3185in_in248)),id3185in_in249)),(cat(id3185in_in250,id3185in_in251)))),(cat((cat((cat(id3185in_in252,id3185in_in253)),id3185in_in254)),(cat(id3185in_in255,id3185in_in256)))))),(cat((cat((cat((cat(id3185in_in257,id3185in_in258)),id3185in_in259)),(cat(id3185in_in260,id3185in_in261)))),(cat((cat(id3185in_in262,id3185in_in263)),(cat(id3185in_in264,id3185in_in265)))))))))),(cat((cat((cat((cat((cat((cat(id3185in_in266,id3185in_in267)),id3185in_in268)),(cat(id3185in_in269,id3185in_in270)))),(cat((cat((cat(id3185in_in271,id3185in_in272)),id3185in_in273)),(cat(id3185in_in274,id3185in_in275)))))),(cat((cat((cat((cat(id3185in_in276,id3185in_in277)),id3185in_in278)),(cat(id3185in_in279,id3185in_in280)))),(cat((cat(id3185in_in281,id3185in_in282)),(cat(id3185in_in283,id3185in_in284)))))))),(cat((cat((cat((cat((cat(id3185in_in285,id3185in_in286)),id3185in_in287)),(cat(id3185in_in288,id3185in_in289)))),(cat((cat((cat(id3185in_in290,id3185in_in291)),id3185in_in292)),(cat(id3185in_in293,id3185in_in294)))))),(cat((cat((cat((cat(id3185in_in295,id3185in_in296)),id3185in_in297)),(cat(id3185in_in298,id3185in_in299)))),(cat((cat(id3185in_in300,id3185in_in301)),(cat(id3185in_in302,id3185in_in303))))))))))))))));
  }
  if ( (getFillLevel() >= (122l)) && (getFlushLevel() < (122l)|| !isFlushingActive() ))
  { // Node ID: 1943 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1943in_output_control = id1942out_result;
    const HWRawBits<9728> &id1943in_data = id3185out_result;

    bool id1943x_1;

    (id1943x_1) = ((id1943in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(122l))&(isFlushingActive()))));
    if((id1943x_1)) {
      writeOutput(m_output, id1943in_data);
    }
  }
  { // Node ID: 2555 (NodeConstantRawBits)
  }
  { // Node ID: 3188 (NodeConstantRawBits)
  }
  { // Node ID: 2552 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 2553 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id2553in_enable = id3188out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id2553in_max = id2552out_value;

    HWOffsetFix<49,0,UNSIGNED> id2553x_1;
    HWOffsetFix<1,0,UNSIGNED> id2553x_2;
    HWOffsetFix<1,0,UNSIGNED> id2553x_3;
    HWOffsetFix<49,0,UNSIGNED> id2553x_4t_1e_1;

    id2553out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id2553st_count)));
    (id2553x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id2553st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id2553x_2) = (gte_fixed((id2553x_1),id2553in_max));
    (id2553x_3) = (and_fixed((id2553x_2),id2553in_enable));
    id2553out_wrap = (id2553x_3);
    if((id2553in_enable.getValueAsBool())) {
      if(((id2553x_3).getValueAsBool())) {
        (id2553st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id2553x_4t_1e_1) = (id2553x_1);
        (id2553st_count) = (id2553x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id2554out_output;

  { // Node ID: 2554 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id2554in_input = id2553out_count;

    id2554out_output = id2554in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 2556 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id2556in_load = id2555out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id2556in_data = id2554out_output;

    bool id2556x_1;

    (id2556x_1) = ((id2556in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id2556x_1)) {
      setMappedRegValue("current_run_cycle_count", id2556in_data);
    }
  }
  { // Node ID: 3187 (NodeConstantRawBits)
  }
  { // Node ID: 2558 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 2559 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id2559in_enable = id3187out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id2559in_max = id2558out_value;

    HWOffsetFix<49,0,UNSIGNED> id2559x_1;
    HWOffsetFix<1,0,UNSIGNED> id2559x_2;
    HWOffsetFix<1,0,UNSIGNED> id2559x_3;
    HWOffsetFix<49,0,UNSIGNED> id2559x_4t_1e_1;

    id2559out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id2559st_count)));
    (id2559x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id2559st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id2559x_2) = (gte_fixed((id2559x_1),id2559in_max));
    (id2559x_3) = (and_fixed((id2559x_2),id2559in_enable));
    id2559out_wrap = (id2559x_3);
    if((id2559in_enable.getValueAsBool())) {
      if(((id2559x_3).getValueAsBool())) {
        (id2559st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id2559x_4t_1e_1) = (id2559x_1);
        (id2559st_count) = (id2559x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 2561 (NodeInputMappedReg)
  }
  { // Node ID: 3186 (NodeEqInlined)
    const HWOffsetFix<48,0,UNSIGNED> &id3186in_a = id2559out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id3186in_b = id2561out_run_cycle_count;

    id3186out_result[(getCycle()+1)%2] = (eq_fixed(id3186in_a,id3186in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 2560 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id2560in_start = id3186out_result[getCycle()%2];

    if((id2560in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
