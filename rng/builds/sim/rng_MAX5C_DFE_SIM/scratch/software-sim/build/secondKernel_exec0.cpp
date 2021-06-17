#include "stdsimheader.h"

namespace maxcompilersim {

void secondKernel::execute0() {
  { // Node ID: 32 (NodeConstantRawBits)
  }
  { // Node ID: 41 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)) && (getFlushLevel() < (0l)|| !isFlushingActive() ))
  { // Node ID: 33 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id33in_output_control = id32out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id33in_data = id41out_value;

    bool id33x_1;

    (id33x_1) = ((id33in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(0l))&(isFlushingActive()))));
    if((id33x_1)) {
      writeOutput(m_internal_watch_llv_output, id33in_data);
    }
  }
  { // Node ID: 36 (NodeConstantRawBits)
  }
  { // Node ID: 5 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 6 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id6in_enable = id36out_value;
    const HWOffsetFix<33,0,UNSIGNED> &id6in_max = id5out_value;

    HWOffsetFix<33,0,UNSIGNED> id6x_1;
    HWOffsetFix<1,0,UNSIGNED> id6x_2;
    HWOffsetFix<1,0,UNSIGNED> id6x_3;
    HWOffsetFix<33,0,UNSIGNED> id6x_4t_1e_1;

    id6out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id6st_count)));
    (id6x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id6st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id6x_2) = (gte_fixed((id6x_1),id6in_max));
    (id6x_3) = (and_fixed((id6x_2),id6in_enable));
    id6out_wrap = (id6x_3);
    if((id6in_enable.getValueAsBool())) {
      if(((id6x_3).getValueAsBool())) {
        (id6st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id6x_4t_1e_1) = (id6x_1);
        (id6st_count) = (id6x_4t_1e_1);
      }
    }
    else {
    }
  }
  if ( (getFillLevel() >= (0l)) && (getFlushLevel() < (0l)|| !isFlushingActive() ))
  { // Node ID: 34 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_output_control = id32out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id34in_data = id6out_count;

    bool id34x_1;

    (id34x_1) = ((id34in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(0l))&(isFlushingActive()))));
    if((id34x_1)) {
      writeOutput(m_internal_watch_countloopkernel_output, id34in_data);
    }
  }
  if ( (getFillLevel() >= (0l)) && (getFlushLevel() < (0l)|| !isFlushingActive() ))
  { // Node ID: 3 (NodeWatch)
  }
  { // Node ID: 10 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 11 (NodePulse)
    const HWOffsetFix<1,0,UNSIGNED> &id11in_enable = id10out_value;

    if(((id11st_count)==(1l))) {
      (id11st_value) = (c_hw_fix_1_0_uns_bits_1);
    }
    if((id11in_enable.getValueAsBool())) {
      (id11st_count) = ((id11st_count)+(1l));
    }
    id11out_output = (id11st_value);
  }
  HWFloat<8,24> id39out_output;

  { // Node ID: 39 (NodeStreamOffset)
    const HWFloat<8,24> &id39in_input = id15out_result[getCycle()%12];

    id39out_output = id39in_input;
  }
  { // Node ID: 12 (NodeConstantRawBits)
  }
  { // Node ID: 13 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_sel = id11out_output;
    const HWFloat<8,24> &id13in_option0 = id39out_output;
    const HWFloat<8,24> &id13in_option1 = id12out_value;

    HWFloat<8,24> id13x_1;

    switch((id13in_sel.getValueAsLong())) {
      case 0l:
        id13x_1 = id13in_option0;
        break;
      case 1l:
        id13x_1 = id13in_option1;
        break;
      default:
        id13x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id13out_result[(getCycle()+1)%2] = (id13x_1);
  }
  { // Node ID: 7 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id8out_result;

  { // Node ID: 8 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_a = id7out_io_y_force_disabled;

    id8out_result = (not_fixed(id8in_a));
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 9 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_enable = id8out_result;

    (id9st_read_next_cycle) = ((id9in_enable.getValueAsBool())&(!(((getFlushLevel())>=(0l))&(isFlushingActive()))));
    queueReadRequest(m_y, id9st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 15 (NodeAdd)
    const HWFloat<8,24> &id15in_a = id13out_result[getCycle()%2];
    const HWFloat<8,24> &id15in_b = id9out_data;

    id15out_result[(getCycle()+11)%12] = (add_float(id15in_a,id15in_b));
  }
  { // Node ID: 1 (NodeConstantRawBits)
  }
  { // Node ID: 17 (NodeGte)
    const HWFloat<8,24> &id17in_a = id15out_result[getCycle()%12];
    const HWFloat<8,24> &id17in_b = id1out_value;

    id17out_result[(getCycle()+2)%3] = (gte_float(id17in_a,id17in_b));
  }
  { // Node ID: 18 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id19out_result;

  { // Node ID: 19 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_a = id18out_io_z_force_disabled;

    id19out_result = (not_fixed(id19in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id20out_result;

  { // Node ID: 20 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_a = id17out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id20in_b = id19out_result;

    HWOffsetFix<1,0,UNSIGNED> id20x_1;

    (id20x_1) = (and_fixed(id20in_a,id20in_b));
    id20out_result = (id20x_1);
  }
  { // Node ID: 40 (NodeFIFO)
    const HWFloat<8,24> &id40in_input = id15out_result[getCycle()%12];

    id40out_output[(getCycle()+2)%3] = id40in_input;
  }
  if ( (getFillLevel() >= (18l)) && (getFlushLevel() < (18l)|| !isFlushingActive() ))
  { // Node ID: 21 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_output_control = id20out_result;
    const HWFloat<8,24> &id21in_data = id40out_output[getCycle()%3];

    bool id21x_1;

    (id21x_1) = ((id21in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(18l))&(isFlushingActive()))));
    if((id21x_1)) {
      writeOutput(m_z, id21in_data);
    }
  }
  { // Node ID: 26 (NodeConstantRawBits)
  }
  { // Node ID: 35 (NodeConstantRawBits)
  }
  { // Node ID: 23 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 24 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_enable = id35out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id24in_max = id23out_value;

    HWOffsetFix<49,0,UNSIGNED> id24x_1;
    HWOffsetFix<1,0,UNSIGNED> id24x_2;
    HWOffsetFix<1,0,UNSIGNED> id24x_3;
    HWOffsetFix<49,0,UNSIGNED> id24x_4t_1e_1;

    id24out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id24st_count)));
    (id24x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id24st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id24x_2) = (gte_fixed((id24x_1),id24in_max));
    (id24x_3) = (and_fixed((id24x_2),id24in_enable));
    id24out_wrap = (id24x_3);
    if((id24in_enable.getValueAsBool())) {
      if(((id24x_3).getValueAsBool())) {
        (id24st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id24x_4t_1e_1) = (id24x_1);
        (id24st_count) = (id24x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id25out_output;

  { // Node ID: 25 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id25in_input = id24out_count;

    id25out_output = id25in_input;
  }
  if ( (getFillLevel() >= (1l)) && (getFlushLevel() < (1l)|| !isFlushingActive() ))
  { // Node ID: 27 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id27in_load = id26out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id27in_data = id25out_output;

    bool id27x_1;

    (id27x_1) = ((id27in_load.getValueAsBool())&(!(((getFlushLevel())>=(1l))&(isFlushingActive()))));
    if((id27x_1)) {
      setMappedRegValue("current_run_cycle_count", id27in_data);
    }
  }
  { // Node ID: 0 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 31 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_start = id0out_value;

    if((id31in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
