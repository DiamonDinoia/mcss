#include "stdsimheader.h"

namespace maxcompilersim {

void loopKernel::execute0() {
  { // Node ID: 1359 (NodeConstantRawBits)
  }
  { // Node ID: 2456 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1360 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1360in_output_control = id1359out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1360in_data = id2456out_value;

    bool id1360x_1;

    (id1360x_1) = ((id1360in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1360x_1)) {
      writeOutput(m_internal_watch_llv_output, id1360in_data);
    }
  }
  { // Node ID: 3 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (104l)))
  { // Node ID: 4 (NodePulse)
    const HWOffsetFix<1,0,UNSIGNED> &id4in_enable = id3out_value;

    if(((id4st_count)==(90l))) {
      (id4st_value) = (c_hw_fix_1_0_uns_bits_1);
    }
    if((id4in_enable.getValueAsBool())) {
      (id4st_count) = ((id4st_count)+(1l));
    }
    id4out_output = (id4st_value);
  }
  { // Node ID: 2139 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2139in_input = id4out_output;

    id2139out_output[(getCycle()+3)%4] = id2139in_input;
  }
  { // Node ID: 2112 (NodeFIFO)
    const HWFloat<8,24> &id2112in_input = id1269out_result[getCycle()%2];

    id2112out_output[(getCycle()+36)%37] = id2112in_input;
  }
  { // Node ID: 25 (NodeConstantRawBits)
  }
  { // Node ID: 26 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_sel = id2422out_output[getCycle()%13];
    const HWFloat<8,24> &id26in_option0 = id2112out_output[getCycle()%37];
    const HWFloat<8,24> &id26in_option1 = id25out_value;

    HWFloat<8,24> id26x_1;

    switch((id26in_sel.getValueAsLong())) {
      case 0l:
        id26x_1 = id26in_option0;
        break;
      case 1l:
        id26x_1 = id26in_option1;
        break;
      default:
        id26x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id26out_result[(getCycle()+1)%2] = (id26x_1);
  }
  { // Node ID: 2023 (NodeConstantRawBits)
  }
  { // Node ID: 27 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id28out_result;

  { // Node ID: 28 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id28in_a = id27out_io_y_force_disabled;

    id28out_result = (not_fixed(id28in_a));
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 29 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_enable = id28out_result;

    (id29st_read_next_cycle) = ((id29in_enable.getValueAsBool())&(!(((getFlushLevel())>=(0l))&(isFlushingActive()))));
    queueReadRequest(m_y, id29st_read_next_cycle.getValueAsBool());
  }
  HWRawBits<32> id30out_result;

  { // Node ID: 30 (NodeSlice)
    const HWRawBits<96> &id30in_a = id29out_data;

    id30out_result = (slice<0,32>(id30in_a));
  }
  HWFloat<8,24> id31out_output;

  { // Node ID: 31 (NodeReinterpret)
    const HWRawBits<32> &id31in_input = id30out_result;

    id31out_output = (cast_bits2float<8,24>(id31in_input));
  }
  { // Node ID: 2022 (NodeConstantRawBits)
  }
  { // Node ID: 100 (NodeGte)
    const HWFloat<8,24> &id100in_a = id31out_output;
    const HWFloat<8,24> &id100in_b = id2022out_value;

    id100out_result[(getCycle()+2)%3] = (gte_float(id100in_a,id100in_b));
  }
  { // Node ID: 2136 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2136in_input = id100out_result[getCycle()%3];

    id2136out_output[(getCycle()+47)%48] = id2136in_input;
  }
  { // Node ID: 101 (NodeConstantRawBits)
  }
  { // Node ID: 2093 (NodeConstantRawBits)
  }
  { // Node ID: 2092 (NodeConstantRawBits)
  }
  { // Node ID: 40 (NodeConstantRawBits)
  }
  HWRawBits<31> id1380out_result;

  { // Node ID: 1380 (NodeSlice)
    const HWRawBits<96> &id1380in_a = id29out_data;

    id1380out_result = (slice<0,31>(id1380in_a));
  }
  { // Node ID: 2021 (NodeConstantRawBits)
  }
  { // Node ID: 1381 (NodeNeqInlined)
    const HWRawBits<31> &id1381in_a = id1380out_result;
    const HWRawBits<31> &id1381in_b = id2021out_value;

    id1381out_result[(getCycle()+1)%2] = (neq_bits(id1381in_a,id1381in_b));
  }
  HWRawBits<23> id1382out_result;

  { // Node ID: 1382 (NodeSlice)
    const HWRawBits<96> &id1382in_a = id29out_data;

    id1382out_result = (slice<0,23>(id1382in_a));
  }
  { // Node ID: 2113 (NodeFIFO)
    const HWRawBits<23> &id2113in_input = id1382out_result;

    id2113out_output[(getCycle()+1)%2] = id2113in_input;
  }
  HWRawBits<25> id1383out_result;

  { // Node ID: 1383 (NodeCat)
    const HWRawBits<1> &id1383in_in0 = id40out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1383in_in1 = id1381out_result[getCycle()%2];
    const HWRawBits<23> &id1383in_in2 = id2113out_output[getCycle()%2];

    id1383out_result = (cat((cat(id1383in_in0,id1383in_in1)),id1383in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id43out_output;

  { // Node ID: 43 (NodeReinterpret)
    const HWRawBits<25> &id43in_input = id1383out_result;

    id43out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id43in_input));
  }
  HWRawBits<1> id1379out_result;

  { // Node ID: 1379 (NodeSlice)
    const HWRawBits<96> &id1379in_a = id29out_data;

    id1379out_result = (slice<31,1>(id1379in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id45out_output;

  { // Node ID: 45 (NodeReinterpret)
    const HWRawBits<1> &id45in_input = id1379out_result;

    id45out_output = (cast_bits2fixed<1,0,UNSIGNED>(id45in_input));
  }
  { // Node ID: 2114 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2114in_input = id45out_output;

    id2114out_output[(getCycle()+1)%2] = id2114in_input;
  }
  { // Node ID: 2045 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2045in_a = id2092out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2045in_b = id43out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2045in_sub = id2114out_output[getCycle()%2];

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2045x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2045x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2045x_3;

    (id2045x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2045in_a,id2045in_b));
    (id2045x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2045in_a,id2045in_b));
    switch((id2045in_sub.getValueAsLong())) {
      case 0l:
        id2045x_3 = (id2045x_1);
        break;
      case 1l:
        id2045x_3 = (id2045x_2);
        break;
      default:
        id2045x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2045out_result[(getCycle()+1)%2] = (id2045x_3);
  }
  { // Node ID: 2020 (NodeConstantRawBits)
  }
  { // Node ID: 1384 (NodeGtInlined)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id1384in_a = id2045out_result[getCycle()%2];
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id1384in_b = id2020out_value;

    id1384out_result[(getCycle()+1)%2] = (gt_fixed(id1384in_a,id1384in_b));
  }
  { // Node ID: 2116 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2116in_input = id1384out_result[getCycle()%2];

    id2116out_output[(getCycle()+1)%2] = id2116in_input;
  }
  HWRawBits<8> id1385out_result;

  { // Node ID: 1385 (NodeSlice)
    const HWRawBits<96> &id1385in_a = id29out_data;

    id1385out_result = (slice<23,8>(id1385in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id49out_output;

  { // Node ID: 49 (NodeReinterpret)
    const HWRawBits<8> &id49in_input = id1385out_result;

    id49out_output = (cast_bits2fixed<8,0,UNSIGNED>(id49in_input));
  }
  { // Node ID: 2115 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id2115in_input = id49out_output;

    id2115out_output[(getCycle()+2)%3] = id2115in_input;
  }
  { // Node ID: 2019 (NodeConstantRawBits)
  }
  { // Node ID: 51 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id51in_a = id2115out_output[getCycle()%3];
    const HWOffsetFix<7,0,UNSIGNED> &id51in_b = id2019out_value;

    id51out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id51in_a,id51in_b));
  }
  { // Node ID: 2117 (NodeFIFO)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2117in_input = id51out_result[getCycle()%2];

    id2117out_output[(getCycle()+1)%2] = id2117in_input;
  }
  { // Node ID: 2018 (NodeConstantRawBits)
  }
  { // Node ID: 59 (NodeAdd)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id59in_a = id51out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id59in_b = id2018out_value;

    id59out_result[(getCycle()+1)%2] = (add_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id59in_a,id59in_b));
  }
  { // Node ID: 60 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id60in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id60in_option0 = id2117out_output[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id60in_option1 = id59out_result[getCycle()%2];

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id60x_1;

    switch((id60in_sel.getValueAsLong())) {
      case 0l:
        id60x_1 = id60in_option0;
        break;
      case 1l:
        id60x_1 = id60in_option1;
        break;
      default:
        id60x_1 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id60out_result[(getCycle()+1)%2] = (id60x_1);
  }
  HWRawBits<1> id1389out_result;

  { // Node ID: 1389 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1389in_a = id60out_result[getCycle()%2];

    id1389out_result = (slice<8,1>(id1389in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1390out_output;

  { // Node ID: 1390 (NodeReinterpret)
    const HWRawBits<1> &id1390in_input = id1389out_result;

    id1390out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1390in_input));
  }
  { // Node ID: 2047 (NodeCondAddSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2047in_a = id2093out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2047in_b = id60out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id2047in_sub = id1390out_output;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2047x_1;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2047x_2;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2047x_3;

    (id2047x_1) = (add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2047in_a,id2047in_b));
    (id2047x_2) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2047in_a,id2047in_b));
    switch((id2047in_sub.getValueAsLong())) {
      case 0l:
        id2047x_3 = (id2047x_1);
        break;
      case 1l:
        id2047x_3 = (id2047x_2);
        break;
      default:
        id2047x_3 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id2047out_result[(getCycle()+1)%2] = (id2047x_3);
  }
  HWRawBits<8> id65out_result;

  { // Node ID: 65 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id65in_a = id2047out_result[getCycle()%2];

    id65out_result = (slice<0,8>(id65in_a));
  }
  { // Node ID: 2118 (NodeFIFO)
    const HWRawBits<8> &id2118in_input = id65out_result;

    id2118out_output[(getCycle()+29)%30] = id2118in_input;
  }
  { // Node ID: 1310 (NodeROM)
    const HWRawBits<8> &id1310in_addr = id2118out_output[getCycle()%30];

    HWFloat<8,24> id1310x_1;

    switch(((long)((id1310in_addr.getValueAsLong())<(256l)))) {
      case 0l:
        id1310x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id1310x_1 = (id1310sta_rom_store[(id1310in_addr.getValueAsLong())]);
        break;
      default:
        id1310x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1310out_dout[(getCycle()+2)%3] = (id1310x_1);
  }
  HWRawBits<1> id2049out_result;

  { // Node ID: 2049 (NodeSlice)
    const HWFloat<8,24> &id2049in_a = id1310out_dout[getCycle()%3];

    id2049out_result = (slice<31,1>(id2049in_a));
  }
  HWRawBits<1> id1386out_result;

  { // Node ID: 1386 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1386in_a = id60out_result[getCycle()%2];

    id1386out_result = (slice<8,1>(id1386in_a));
  }
  HWRawBits<1> id1387out_result;

  { // Node ID: 1387 (NodeNot)
    const HWRawBits<1> &id1387in_a = id1386out_result;

    id1387out_result = (not_bits(id1387in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1388out_output;

  { // Node ID: 1388 (NodeReinterpret)
    const HWRawBits<1> &id1388in_input = id1387out_result;

    id1388out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1388in_input));
  }
  HWOffsetFix<1,0,UNSIGNED> id2050out_result;

  { // Node ID: 2050 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id2050in_a = id1388out_output;

    id2050out_result = (not_fixed(id2050in_a));
  }
  { // Node ID: 2119 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2119in_input = id2050out_result;

    id2119out_output[(getCycle()+32)%33] = id2119in_input;
  }
  HWRawBits<1> id2051out_result;

  { // Node ID: 2051 (NodeXor)
    const HWRawBits<1> &id2051in_a = id2049out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2051in_b = id2119out_output[getCycle()%33];

    HWRawBits<1> id2051x_1;

    (id2051x_1) = (xor_bits(id2051in_a,(cast_fixed2bits(id2051in_b))));
    id2051out_result = (id2051x_1);
  }
  HWRawBits<31> id2048out_result;

  { // Node ID: 2048 (NodeSlice)
    const HWFloat<8,24> &id2048in_a = id1310out_dout[getCycle()%3];

    id2048out_result = (slice<0,31>(id2048in_a));
  }
  HWRawBits<32> id2052out_result;

  { // Node ID: 2052 (NodeCat)
    const HWRawBits<1> &id2052in_in0 = id2051out_result;
    const HWRawBits<31> &id2052in_in1 = id2048out_result;

    id2052out_result = (cat(id2052in_in0,id2052in_in1));
  }
  HWFloat<8,24> id2053out_output;

  { // Node ID: 2053 (NodeReinterpret)
    const HWRawBits<32> &id2053in_input = id2052out_result;

    id2053out_output = (cast_bits2float<8,24>(id2053in_input));
  }
  HWRawBits<23> id54out_result;

  { // Node ID: 54 (NodeSlice)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id54in_a = id2045out_result[getCycle()%2];

    id54out_result = (slice<0,23>(id54in_a));
  }
  HWOffsetFix<23,-23,UNSIGNED> id56out_output;

  { // Node ID: 56 (NodeReinterpret)
    const HWRawBits<23> &id56in_input = id54out_result;

    id56out_output = (cast_bits2fixed<23,-23,UNSIGNED>(id56in_input));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id57out_o;

  { // Node ID: 57 (NodeCast)
    const HWOffsetFix<23,-23,UNSIGNED> &id57in_i = id56out_output;

    id57out_o = (cast_fixed2fixed<27,-23,TWOSCOMPLEMENT,TONEAREVEN>(id57in_i));
  }
  HWOffsetFix<25,-24,UNSIGNED> id70out_o;

  { // Node ID: 70 (NodeCast)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id70in_i = id57out_o;

    id70out_o = (cast_fixed2fixed<25,-24,UNSIGNED,TONEAREVEN>(id70in_i));
  }
  HWRawBits<7> id73out_result;

  { // Node ID: 73 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id73in_a = id70out_o;

    id73out_result = (slice<17,7>(id73in_a));
  }
  { // Node ID: 1292 (NodeROM)
    const HWRawBits<7> &id1292in_addr = id73out_result;

    HWRawBits<108> id1292x_1;

    switch(((long)((id1292in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1292x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
      case 1l:
        id1292x_1 = (id1292sta_rom_store[(id1292in_addr.getValueAsLong())]);
        break;
      default:
        id1292x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
    }
    id1292out_dout[(getCycle()+2)%3] = (id1292x_1);
  }
  HWRawBits<27> id1299out_result;

  { // Node ID: 1299 (NodeSlice)
    const HWRawBits<108> &id1299in_a = id1292out_dout[getCycle()%3];

    id1299out_result = (slice<81,27>(id1299in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1300out_output;

  { // Node ID: 1300 (NodeReinterpret)
    const HWRawBits<27> &id1300in_input = id1299out_result;

    id1300out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1300in_input));
  }
  HWRawBits<7> id76out_result;

  { // Node ID: 76 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id76in_a = id70out_o;

    id76out_result = (slice<17,7>(id76in_a));
  }
  { // Node ID: 1301 (NodeROM)
    const HWRawBits<7> &id1301in_addr = id76out_result;

    HWRawBits<108> id1301x_1;

    switch(((long)((id1301in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1301x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
      case 1l:
        id1301x_1 = (id1301sta_rom_store[(id1301in_addr.getValueAsLong())]);
        break;
      default:
        id1301x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
    }
    id1301out_dout[(getCycle()+2)%3] = (id1301x_1);
  }
  HWRawBits<27> id1308out_result;

  { // Node ID: 1308 (NodeSlice)
    const HWRawBits<108> &id1308in_a = id1301out_dout[getCycle()%3];

    id1308out_result = (slice<81,27>(id1308in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1309out_output;

  { // Node ID: 1309 (NodeReinterpret)
    const HWRawBits<27> &id1309in_input = id1308out_result;

    id1309out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1309in_input));
  }
  { // Node ID: 81 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id81in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id81in_option0 = id1300out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id81in_option1 = id1309out_output;

    HWOffsetFix<27,-23,TWOSCOMPLEMENT> id81x_1;

    switch((id81in_sel.getValueAsLong())) {
      case 0l:
        id81x_1 = id81in_option0;
        break;
      case 1l:
        id81x_1 = id81in_option1;
        break;
      default:
        id81x_1 = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
        break;
    }
    id81out_result[(getCycle()+1)%2] = (id81x_1);
  }
  { // Node ID: 2121 (NodeFIFO)
    const HWOffsetFix<25,-24,UNSIGNED> &id2121in_input = id70out_o;

    id2121out_output[(getCycle()+2)%3] = id2121in_input;
  }
  HWRawBits<17> id71out_result;

  { // Node ID: 71 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id71in_a = id2121out_output[getCycle()%3];

    id71out_result = (slice<0,17>(id71in_a));
  }
  HWOffsetFix<17,-17,UNSIGNED> id72out_output;

  { // Node ID: 72 (NodeReinterpret)
    const HWRawBits<17> &id72in_input = id71out_result;

    id72out_output = (cast_bits2fixed<17,-17,UNSIGNED>(id72in_input));
  }
  HWRawBits<17> id74out_result;

  { // Node ID: 74 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id74in_a = id2121out_output[getCycle()%3];

    id74out_result = (slice<0,17>(id74in_a));
  }
  HWOffsetFix<17,-17,UNSIGNED> id75out_output;

  { // Node ID: 75 (NodeReinterpret)
    const HWRawBits<17> &id75in_input = id74out_result;

    id75out_output = (cast_bits2fixed<17,-17,UNSIGNED>(id75in_input));
  }
  { // Node ID: 77 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id77in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id77in_option0 = id72out_output;
    const HWOffsetFix<17,-17,UNSIGNED> &id77in_option1 = id75out_output;

    HWOffsetFix<17,-17,UNSIGNED> id77x_1;

    switch((id77in_sel.getValueAsLong())) {
      case 0l:
        id77x_1 = id77in_option0;
        break;
      case 1l:
        id77x_1 = id77in_option1;
        break;
      default:
        id77x_1 = (HWOffsetFix<17,-17,UNSIGNED>(varint_u<17>(m_undefined_value.get_bits(17))));
        break;
    }
    id77out_result[(getCycle()+1)%2] = (id77x_1);
  }
  { // Node ID: 82 (NodeMul)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id82in_a = id81out_result[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id82in_b = id77out_result[getCycle()%2];

    id82out_result[(getCycle()+4)%5] = (mul_fixed<44,-40,TWOSCOMPLEMENT,TONEAREVEN>(id82in_a,id82in_b));
  }
  HWRawBits<27> id1297out_result;

  { // Node ID: 1297 (NodeSlice)
    const HWRawBits<108> &id1297in_a = id1292out_dout[getCycle()%3];

    id1297out_result = (slice<54,27>(id1297in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1298out_output;

  { // Node ID: 1298 (NodeReinterpret)
    const HWRawBits<27> &id1298in_input = id1297out_result;

    id1298out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1298in_input));
  }
  HWRawBits<27> id1306out_result;

  { // Node ID: 1306 (NodeSlice)
    const HWRawBits<108> &id1306in_a = id1301out_dout[getCycle()%3];

    id1306out_result = (slice<54,27>(id1306in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1307out_output;

  { // Node ID: 1307 (NodeReinterpret)
    const HWRawBits<27> &id1307in_input = id1306out_result;

    id1307out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1307in_input));
  }
  { // Node ID: 80 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id80in_option0 = id1298out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id80in_option1 = id1307out_output;

    HWOffsetFix<27,-23,TWOSCOMPLEMENT> id80x_1;

    switch((id80in_sel.getValueAsLong())) {
      case 0l:
        id80x_1 = id80in_option0;
        break;
      case 1l:
        id80x_1 = id80in_option1;
        break;
      default:
        id80x_1 = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
        break;
    }
    id80out_result[(getCycle()+1)%2] = (id80x_1);
  }
  { // Node ID: 2125 (NodeFIFO)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id2125in_input = id80out_result[getCycle()%2];

    id2125out_output[(getCycle()+4)%5] = id2125in_input;
  }
  { // Node ID: 83 (NodeAdd)
    const HWOffsetFix<44,-40,TWOSCOMPLEMENT> &id83in_a = id82out_result[getCycle()%5];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id83in_b = id2125out_output[getCycle()%5];

    id83out_result[(getCycle()+1)%2] = (add_fixed<45,-40,TWOSCOMPLEMENT,TONEAREVEN>(id83in_a,id83in_b));
  }
  { // Node ID: 84 (NodeCast)
    const HWOffsetFix<45,-40,TWOSCOMPLEMENT> &id84in_i = id83out_result[getCycle()%2];

    id84out_o[(getCycle()+1)%2] = (cast_fixed2fixed<25,-20,TWOSCOMPLEMENT,TONEAREVEN>(id84in_i));
  }
  { // Node ID: 2126 (NodeFIFO)
    const HWOffsetFix<17,-17,UNSIGNED> &id2126in_input = id77out_result[getCycle()%2];

    id2126out_output[(getCycle()+6)%7] = id2126in_input;
  }
  { // Node ID: 85 (NodeMul)
    const HWOffsetFix<25,-20,TWOSCOMPLEMENT> &id85in_a = id84out_o[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id85in_b = id2126out_output[getCycle()%7];

    id85out_result[(getCycle()+4)%5] = (mul_fixed<42,-37,TWOSCOMPLEMENT,TONEAREVEN>(id85in_a,id85in_b));
  }
  HWRawBits<27> id1295out_result;

  { // Node ID: 1295 (NodeSlice)
    const HWRawBits<108> &id1295in_a = id1292out_dout[getCycle()%3];

    id1295out_result = (slice<27,27>(id1295in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1296out_output;

  { // Node ID: 1296 (NodeReinterpret)
    const HWRawBits<27> &id1296in_input = id1295out_result;

    id1296out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1296in_input));
  }
  HWRawBits<27> id1304out_result;

  { // Node ID: 1304 (NodeSlice)
    const HWRawBits<108> &id1304in_a = id1301out_dout[getCycle()%3];

    id1304out_result = (slice<27,27>(id1304in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1305out_output;

  { // Node ID: 1305 (NodeReinterpret)
    const HWRawBits<27> &id1305in_input = id1304out_result;

    id1305out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1305in_input));
  }
  { // Node ID: 79 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id79in_option0 = id1296out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id79in_option1 = id1305out_output;

    HWOffsetFix<27,-23,TWOSCOMPLEMENT> id79x_1;

    switch((id79in_sel.getValueAsLong())) {
      case 0l:
        id79x_1 = id79in_option0;
        break;
      case 1l:
        id79x_1 = id79in_option1;
        break;
      default:
        id79x_1 = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
        break;
    }
    id79out_result[(getCycle()+1)%2] = (id79x_1);
  }
  { // Node ID: 2128 (NodeFIFO)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id2128in_input = id79out_result[getCycle()%2];

    id2128out_output[(getCycle()+10)%11] = id2128in_input;
  }
  { // Node ID: 86 (NodeAdd)
    const HWOffsetFix<42,-37,TWOSCOMPLEMENT> &id86in_a = id85out_result[getCycle()%5];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id86in_b = id2128out_output[getCycle()%11];

    id86out_result[(getCycle()+1)%2] = (add_fixed<43,-37,TWOSCOMPLEMENT,TONEAREVEN>(id86in_a,id86in_b));
  }
  { // Node ID: 87 (NodeCast)
    const HWOffsetFix<43,-37,TWOSCOMPLEMENT> &id87in_i = id86out_result[getCycle()%2];

    id87out_o[(getCycle()+1)%2] = (cast_fixed2fixed<25,-19,TWOSCOMPLEMENT,TONEAREVEN>(id87in_i));
  }
  { // Node ID: 2415 (NodeFIFO)
    const HWOffsetFix<17,-17,UNSIGNED> &id2415in_input = id2126out_output[getCycle()%7];

    id2415out_output[(getCycle()+6)%7] = id2415in_input;
  }
  { // Node ID: 88 (NodeMul)
    const HWOffsetFix<25,-19,TWOSCOMPLEMENT> &id88in_a = id87out_o[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id88in_b = id2415out_output[getCycle()%7];

    id88out_result[(getCycle()+4)%5] = (mul_fixed<42,-36,TWOSCOMPLEMENT,TONEAREVEN>(id88in_a,id88in_b));
  }
  HWRawBits<27> id1293out_result;

  { // Node ID: 1293 (NodeSlice)
    const HWRawBits<108> &id1293in_a = id1292out_dout[getCycle()%3];

    id1293out_result = (slice<0,27>(id1293in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1294out_output;

  { // Node ID: 1294 (NodeReinterpret)
    const HWRawBits<27> &id1294in_input = id1293out_result;

    id1294out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1294in_input));
  }
  HWRawBits<27> id1302out_result;

  { // Node ID: 1302 (NodeSlice)
    const HWRawBits<108> &id1302in_a = id1301out_dout[getCycle()%3];

    id1302out_result = (slice<0,27>(id1302in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1303out_output;

  { // Node ID: 1303 (NodeReinterpret)
    const HWRawBits<27> &id1303in_input = id1302out_result;

    id1303out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1303in_input));
  }
  { // Node ID: 78 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id78in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id78in_option0 = id1294out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id78in_option1 = id1303out_output;

    HWOffsetFix<27,-23,TWOSCOMPLEMENT> id78x_1;

    switch((id78in_sel.getValueAsLong())) {
      case 0l:
        id78x_1 = id78in_option0;
        break;
      case 1l:
        id78x_1 = id78in_option1;
        break;
      default:
        id78x_1 = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
        break;
    }
    id78out_result[(getCycle()+1)%2] = (id78x_1);
  }
  { // Node ID: 2131 (NodeFIFO)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id2131in_input = id78out_result[getCycle()%2];

    id2131out_output[(getCycle()+16)%17] = id2131in_input;
  }
  { // Node ID: 89 (NodeAdd)
    const HWOffsetFix<42,-36,TWOSCOMPLEMENT> &id89in_a = id88out_result[getCycle()%5];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id89in_b = id2131out_output[getCycle()%17];

    id89out_result[(getCycle()+1)%2] = (add_fixed<42,-36,TWOSCOMPLEMENT,TONEAREVEN>(id89in_a,id89in_b));
  }
  { // Node ID: 90 (NodeCast)
    const HWOffsetFix<42,-36,TWOSCOMPLEMENT> &id90in_i = id89out_result[getCycle()%2];

    id90out_o[(getCycle()+1)%2] = (cast_fixed2fixed<25,-19,TWOSCOMPLEMENT,TONEAREVEN>(id90in_i));
  }
  { // Node ID: 91 (NodeCast)
    const HWOffsetFix<25,-19,TWOSCOMPLEMENT> &id91in_i = id90out_o[getCycle()%2];

    id91out_o[(getCycle()+6)%7] = (cast_fixed2float<8,24>(id91in_i));
  }
  HWRawBits<25> id1391out_dataout;

  { // Node ID: 1391 (NodeShift)
    const HWOffsetFix<25,-24,UNSIGNED> &id1391in_datain = id2121out_output[getCycle()%3];

    id1391out_dataout = (shift_right_fixed(id1391in_datain,(1l)));
  }
  HWOffsetFix<25,-24,UNSIGNED> id94out_output;

  { // Node ID: 94 (NodeReinterpret)
    const HWRawBits<25> &id94in_input = id1391out_dataout;

    id94out_output = (cast_bits2fixed<25,-24,UNSIGNED>(id94in_input));
  }
  { // Node ID: 95 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id95in_sel = id2116out_output[getCycle()%2];
    const HWOffsetFix<25,-24,UNSIGNED> &id95in_option0 = id2121out_output[getCycle()%3];
    const HWOffsetFix<25,-24,UNSIGNED> &id95in_option1 = id94out_output;

    HWOffsetFix<25,-24,UNSIGNED> id95x_1;

    switch((id95in_sel.getValueAsLong())) {
      case 0l:
        id95x_1 = id95in_option0;
        break;
      case 1l:
        id95x_1 = id95in_option1;
        break;
      default:
        id95x_1 = (HWOffsetFix<25,-24,UNSIGNED>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id95out_result[(getCycle()+1)%2] = (id95x_1);
  }
  { // Node ID: 2135 (NodeFIFO)
    const HWOffsetFix<25,-24,UNSIGNED> &id2135in_input = id95out_result[getCycle()%2];

    id2135out_output[(getCycle()+18)%19] = id2135in_input;
  }
  { // Node ID: 96 (NodeCast)
    const HWOffsetFix<25,-24,UNSIGNED> &id96in_i = id2135out_output[getCycle()%19];

    id96out_o[(getCycle()+6)%7] = (cast_fixed2float<8,24>(id96in_i));
  }
  { // Node ID: 97 (NodeMul)
    const HWFloat<8,24> &id97in_a = id91out_o[getCycle()%7];
    const HWFloat<8,24> &id97in_b = id96out_o[getCycle()%7];

    id97out_result[(getCycle()+8)%9] = (mul_float(id97in_a,id97in_b));
  }
  { // Node ID: 98 (NodeAdd)
    const HWFloat<8,24> &id98in_a = id2053out_output;
    const HWFloat<8,24> &id98in_b = id97out_result[getCycle()%9];

    id98out_result[(getCycle()+12)%13] = (add_float(id98in_a,id98in_b));
  }
  { // Node ID: 102 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id102in_sel = id2136out_output[getCycle()%48];
    const HWFloat<8,24> &id102in_option0 = id101out_value;
    const HWFloat<8,24> &id102in_option1 = id98out_result[getCycle()%13];

    HWFloat<8,24> id102x_1;

    switch((id102in_sel.getValueAsLong())) {
      case 0l:
        id102x_1 = id102in_option0;
        break;
      case 1l:
        id102x_1 = id102in_option1;
        break;
      default:
        id102x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id102out_result[(getCycle()+1)%2] = (id102x_1);
  }
  { // Node ID: 104 (NodeMul)
    const HWFloat<8,24> &id104in_a = id2023out_value;
    const HWFloat<8,24> &id104in_b = id102out_result[getCycle()%2];

    id104out_result[(getCycle()+8)%9] = (mul_float(id104in_a,id104in_b));
  }
  { // Node ID: 2137 (NodeFIFO)
    const HWFloat<8,24> &id2137in_input = id104out_result[getCycle()%9];

    id2137out_output[(getCycle()+79)%80] = id2137in_input;
  }
  { // Node ID: 105 (NodeAdd)
    const HWFloat<8,24> &id105in_a = id26out_result[getCycle()%2];
    const HWFloat<8,24> &id105in_b = id2137out_output[getCycle()%80];

    id105out_result[(getCycle()+11)%12] = (add_float(id105in_a,id105in_b));
  }
  { // Node ID: 2407 (NodeFIFO)
    const HWFloat<8,24> &id2407in_input = id105out_result[getCycle()%12];

    id2407out_output[(getCycle()+35)%36] = id2407in_input;
  }
  { // Node ID: 2417 (NodeFIFO)
    const HWFloat<8,24> &id2417in_input = id2407out_output[getCycle()%36];

    id2417out_output[(getCycle()+2)%3] = id2417in_input;
  }
  { // Node ID: 2418 (NodeFIFO)
    const HWFloat<8,24> &id2418in_input = id2417out_output[getCycle()%3];

    id2418out_output[(getCycle()+5)%6] = id2418in_input;
  }
  HWFloat<8,24> id2103out_output;

  { // Node ID: 2103 (NodeStreamOffset)
    const HWFloat<8,24> &id2103in_input = id2418out_output[getCycle()%6];

    id2103out_output = id2103in_input;
  }
  { // Node ID: 1268 (NodeConstantRawBits)
  }
  { // Node ID: 1269 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1269in_sel = id4out_output;
    const HWFloat<8,24> &id1269in_option0 = id2103out_output;
    const HWFloat<8,24> &id1269in_option1 = id1268out_value;

    HWFloat<8,24> id1269x_1;

    switch((id1269in_sel.getValueAsLong())) {
      case 0l:
        id1269x_1 = id1269in_option0;
        break;
      case 1l:
        id1269x_1 = id1269in_option1;
        break;
      default:
        id1269x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1269out_result[(getCycle()+1)%2] = (id1269x_1);
  }
  { // Node ID: 2017 (NodeConstantRawBits)
  }
  { // Node ID: 9 (NodeGt)
    const HWFloat<8,24> &id9in_a = id1269out_result[getCycle()%2];
    const HWFloat<8,24> &id9in_b = id2017out_value;

    id9out_result[(getCycle()+2)%3] = (gt_float(id9in_a,id9in_b));
  }
  { // Node ID: 10 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_a = id9out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id10in_b = id2139out_output[getCycle()%4];

    HWOffsetFix<1,0,UNSIGNED> id10x_1;

    (id10x_1) = (or_fixed(id10in_a,id10in_b));
    id10out_result[(getCycle()+1)%2] = (id10x_1);
  }
  { // Node ID: 2358 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2358in_input = id10out_result[getCycle()%2];

    id2358out_output[(getCycle()+21)%22] = id2358in_input;
  }
  { // Node ID: 2422 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2422in_input = id2358out_output[getCycle()%22];

    id2422out_output[(getCycle()+12)%13] = id2422in_input;
  }
  { // Node ID: 2423 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2423in_input = id2422out_output[getCycle()%13];

    id2423out_output[(getCycle()+25)%26] = id2423in_input;
  }
  { // Node ID: 2424 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2424in_input = id2423out_output[getCycle()%26];

    id2424out_output[(getCycle()+20)%21] = id2424in_input;
  }
  { // Node ID: 11 (NodeConstantRawBits)
  }
  { // Node ID: 12 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id12in_sel = id2424out_output[getCycle()%21];
    const HWFloat<8,24> &id12in_option0 = id2141out_output[getCycle()%79];
    const HWFloat<8,24> &id12in_option1 = id11out_value;

    HWFloat<8,24> id12x_1;

    switch((id12in_sel.getValueAsLong())) {
      case 0l:
        id12x_1 = id12in_option0;
        break;
      case 1l:
        id12x_1 = id12in_option1;
        break;
      default:
        id12x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id12out_result[(getCycle()+1)%2] = (id12x_1);
  }
  { // Node ID: 2016 (NodeConstantRawBits)
  }
  { // Node ID: 107 (NodeGt)
    const HWFloat<8,24> &id107in_a = id105out_result[getCycle()%12];
    const HWFloat<8,24> &id107in_b = id2016out_value;

    id107out_result[(getCycle()+2)%3] = (gt_float(id107in_a,id107in_b));
  }
  { // Node ID: 2249 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2249in_input = id107out_result[getCycle()%3];

    id2249out_output[(getCycle()+20)%21] = id2249in_input;
  }
  { // Node ID: 2426 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2426in_input = id2249out_output[getCycle()%21];

    id2426out_output[(getCycle()+3)%4] = id2426in_input;
  }
  { // Node ID: 2427 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2427in_input = id2426out_output[getCycle()%4];

    id2427out_output[(getCycle()+1)%2] = id2427in_input;
  }
  { // Node ID: 2428 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2428in_input = id2427out_output[getCycle()%2];

    id2428out_output[(getCycle()+11)%12] = id2428in_input;
  }
  { // Node ID: 2429 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2429in_input = id2428out_output[getCycle()%12];

    id2429out_output[(getCycle()+5)%6] = id2429in_input;
  }
  { // Node ID: 2430 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2430in_input = id2429out_output[getCycle()%6];

    id2430out_output[(getCycle()+2)%3] = id2430in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1240out_result;

  { // Node ID: 1240 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1240in_a = id2430out_output[getCycle()%3];

    id1240out_result = (not_fixed(id1240in_a));
  }
  { // Node ID: 2450 (NodeFIFO)
    const HWFloat<8,24> &id2450in_input = id2449out_output[getCycle()%3];

    id2450out_output[(getCycle()+18)%19] = id2450in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1201out_result;

  { // Node ID: 1201 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1201in_a = id2429out_output[getCycle()%6];

    id1201out_result = (not_fixed(id1201in_a));
  }
  { // Node ID: 1191 (NodeMul)
    const HWFloat<8,24> &id1191in_a = id18out_result[getCycle()%2];
    const HWFloat<8,24> &id1191in_b = id18out_result[getCycle()%2];

    id1191out_result[(getCycle()+8)%9] = (mul_float(id1191in_a,id1191in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id1242out_result;

  { // Node ID: 1242 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1242in_a = id2430out_output[getCycle()%3];

    id1242out_result = (not_fixed(id1242in_a));
  }
  { // Node ID: 2360 (NodeFIFO)
    const HWFloat<8,24> &id2360in_input = id20out_result[getCycle()%2];

    id2360out_output[(getCycle()+21)%22] = id2360in_input;
  }
  { // Node ID: 2440 (NodeFIFO)
    const HWFloat<8,24> &id2440in_input = id2360out_output[getCycle()%22];

    id2440out_output[(getCycle()+8)%9] = id2440in_input;
  }
  { // Node ID: 2441 (NodeFIFO)
    const HWFloat<8,24> &id2441in_input = id2440out_output[getCycle()%9];

    id2441out_output[(getCycle()+39)%40] = id2441in_input;
  }
  { // Node ID: 2442 (NodeFIFO)
    const HWFloat<8,24> &id2442in_input = id2441out_output[getCycle()%40];

    id2442out_output[(getCycle()+2)%3] = id2442in_input;
  }
  { // Node ID: 2443 (NodeFIFO)
    const HWFloat<8,24> &id2443in_input = id2442out_output[getCycle()%3];

    id2443out_output[(getCycle()+18)%19] = id2443in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1211out_result;

  { // Node ID: 1211 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1211in_a = id2429out_output[getCycle()%6];

    id1211out_result = (not_fixed(id1211in_a));
  }
  { // Node ID: 1212 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1212in_a = id1211out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1212in_b = id2446out_output[getCycle()%19];

    HWOffsetFix<1,0,UNSIGNED> id1212x_1;

    (id1212x_1) = (and_fixed(id1212in_a,id1212in_b));
    id1212out_result[(getCycle()+1)%2] = (id1212x_1);
  }
  { // Node ID: 2015 (NodeConstantRawBits)
  }
  { // Node ID: 129 (NodeConstantRawBits)
  }
  { // Node ID: 130 (NodeConstantRawBits)
  }
  { // Node ID: 2014 (NodeConstantRawBits)
  }
  { // Node ID: 2013 (NodeConstantRawBits)
  }
  HWRawBits<32> id32out_result;

  { // Node ID: 32 (NodeSlice)
    const HWRawBits<96> &id32in_a = id29out_data;

    id32out_result = (slice<32,32>(id32in_a));
  }
  HWFloat<8,24> id33out_output;

  { // Node ID: 33 (NodeReinterpret)
    const HWRawBits<32> &id33in_input = id32out_result;

    id33out_output = (cast_bits2float<8,24>(id33in_input));
  }
  { // Node ID: 121 (NodeMul)
    const HWFloat<8,24> &id121in_a = id2013out_value;
    const HWFloat<8,24> &id121in_b = id33out_output;

    id121out_result[(getCycle()+8)%9] = (mul_float(id121in_a,id121in_b));
  }
  { // Node ID: 2147 (NodeFIFO)
    const HWFloat<8,24> &id2147in_input = id121out_result[getCycle()%9];

    id2147out_output[(getCycle()+14)%15] = id2147in_input;
  }
  { // Node ID: 2012 (NodeConstantRawBits)
  }
  { // Node ID: 123 (NodeSub)
    const HWFloat<8,24> &id123in_a = id2012out_value;
    const HWFloat<8,24> &id123in_b = id33out_output;

    id123out_result[(getCycle()+11)%12] = (sub_float(id123in_a,id123in_b));
  }
  { // Node ID: 2011 (NodeConstantRawBits)
  }
  { // Node ID: 125 (NodeAdd)
    const HWFloat<8,24> &id125in_a = id123out_result[getCycle()%12];
    const HWFloat<8,24> &id125in_b = id2011out_value;

    id125out_result[(getCycle()+11)%12] = (add_float(id125in_a,id125in_b));
  }
  { // Node ID: 126 (NodeDiv)
    const HWFloat<8,24> &id126in_a = id2147out_output[getCycle()%15];
    const HWFloat<8,24> &id126in_b = id125out_result[getCycle()%12];

    id126out_result[(getCycle()+28)%29] = (div_float(id126in_a,id126in_b));
  }
  { // Node ID: 128 (NodeSub)
    const HWFloat<8,24> &id128in_a = id2014out_value;
    const HWFloat<8,24> &id128in_b = id126out_result[getCycle()%29];

    id128out_result[(getCycle()+11)%12] = (sub_float(id128in_a,id128in_b));
  }
  { // Node ID: 131 (NodeGt)
    const HWFloat<8,24> &id131in_a = id130out_value;
    const HWFloat<8,24> &id131in_b = id128out_result[getCycle()%12];

    id131out_result[(getCycle()+2)%3] = (gt_float(id131in_a,id131in_b));
  }
  { // Node ID: 2148 (NodeFIFO)
    const HWFloat<8,24> &id2148in_input = id128out_result[getCycle()%12];

    id2148out_output[(getCycle()+2)%3] = id2148in_input;
  }
  { // Node ID: 132 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id132in_sel = id131out_result[getCycle()%3];
    const HWFloat<8,24> &id132in_option0 = id130out_value;
    const HWFloat<8,24> &id132in_option1 = id2148out_output[getCycle()%3];

    HWFloat<8,24> id132x_1;

    switch((id132in_sel.getValueAsLong())) {
      case 0l:
        id132x_1 = id132in_option0;
        break;
      case 1l:
        id132x_1 = id132in_option1;
        break;
      default:
        id132x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id132out_result[(getCycle()+1)%2] = (id132x_1);
  }
  { // Node ID: 133 (NodeGt)
    const HWFloat<8,24> &id133in_a = id129out_value;
    const HWFloat<8,24> &id133in_b = id132out_result[getCycle()%2];

    id133out_result[(getCycle()+2)%3] = (gt_float(id133in_a,id133in_b));
  }
  { // Node ID: 2149 (NodeFIFO)
    const HWFloat<8,24> &id2149in_input = id132out_result[getCycle()%2];

    id2149out_output[(getCycle()+2)%3] = id2149in_input;
  }
  { // Node ID: 134 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id134in_sel = id133out_result[getCycle()%3];
    const HWFloat<8,24> &id134in_option0 = id2149out_output[getCycle()%3];
    const HWFloat<8,24> &id134in_option1 = id129out_value;

    HWFloat<8,24> id134x_1;

    switch((id134in_sel.getValueAsLong())) {
      case 0l:
        id134x_1 = id134in_option0;
        break;
      case 1l:
        id134x_1 = id134in_option1;
        break;
      default:
        id134x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id134out_result[(getCycle()+1)%2] = (id134x_1);
  }
  { // Node ID: 136 (NodeSub)
    const HWFloat<8,24> &id136in_a = id2015out_value;
    const HWFloat<8,24> &id136in_b = id134out_result[getCycle()%2];

    id136out_result[(getCycle()+11)%12] = (sub_float(id136in_a,id136in_b));
  }
  { // Node ID: 2150 (NodeFIFO)
    const HWFloat<8,24> &id2150in_input = id136out_result[getCycle()%12];

    id2150out_output[(getCycle()+11)%12] = id2150in_input;
  }
  { // Node ID: 2010 (NodeConstantRawBits)
  }
  { // Node ID: 138 (NodeSub)
    const HWFloat<8,24> &id138in_a = id2010out_value;
    const HWFloat<8,24> &id138in_b = id136out_result[getCycle()%12];

    id138out_result[(getCycle()+11)%12] = (sub_float(id138in_a,id138in_b));
  }
  { // Node ID: 139 (NodeMul)
    const HWFloat<8,24> &id139in_a = id2150out_output[getCycle()%12];
    const HWFloat<8,24> &id139in_b = id138out_result[getCycle()%12];

    id139out_result[(getCycle()+8)%9] = (mul_float(id139in_a,id139in_b));
  }
  { // Node ID: 140 (NodeSqrt)
    const HWFloat<8,24> &id140in_a = id139out_result[getCycle()%9];

    id140out_result[(getCycle()+28)%29] = (sqrt_float(id140in_a));
  }
  { // Node ID: 2009 (NodeConstantRawBits)
  }
  HWRawBits<32> id34out_result;

  { // Node ID: 34 (NodeSlice)
    const HWRawBits<96> &id34in_a = id29out_data;

    id34out_result = (slice<64,32>(id34in_a));
  }
  HWFloat<8,24> id35out_output;

  { // Node ID: 35 (NodeReinterpret)
    const HWRawBits<32> &id35in_input = id34out_result;

    id35out_output = (cast_bits2float<8,24>(id35in_input));
  }
  { // Node ID: 2151 (NodeFIFO)
    const HWFloat<8,24> &id2151in_input = id35out_output;

    id2151out_output[(getCycle()+28)%29] = id2151in_input;
  }
  { // Node ID: 143 (NodeMul)
    const HWFloat<8,24> &id143in_a = id2009out_value;
    const HWFloat<8,24> &id143in_b = id2151out_output[getCycle()%29];

    id143out_result[(getCycle()+8)%9] = (mul_float(id143in_a,id143in_b));
  }
  { // Node ID: 2153 (NodeFIFO)
    const HWFloat<8,24> &id2153in_input = id143out_result[getCycle()%9];

    id2153out_output[(getCycle()+6)%7] = id2153in_input;
  }
  { // Node ID: 2434 (NodeFIFO)
    const HWFloat<8,24> &id2434in_input = id2153out_output[getCycle()%7];

    id2434out_output[(getCycle()+1)%2] = id2434in_input;
  }
  HWRawBits<31> id668out_result;

  { // Node ID: 668 (NodeSlice)
    const HWFloat<8,24> &id668in_a = id2434out_output[getCycle()%2];

    id668out_result = (slice<0,31>(id668in_a));
  }
  { // Node ID: 1177 (NodeConstantRawBits)
  }
  { // Node ID: 1393 (NodeEqInlined)
    const HWRawBits<31> &id1393in_a = id668out_result;
    const HWRawBits<31> &id1393in_b = id1177out_value;

    id1393out_result[(getCycle()+1)%2] = (eq_bits(id1393in_a,id1393in_b));
  }
  HWRawBits<8> id1734out_result;

  { // Node ID: 1734 (NodeSlice)
    const HWFloat<8,24> &id1734in_a = id2153out_output[getCycle()%7];

    id1734out_result = (slice<23,8>(id1734in_a));
  }
  { // Node ID: 1182 (NodeConstantRawBits)
  }
  { // Node ID: 1395 (NodeEqInlined)
    const HWRawBits<8> &id1395in_a = id1734out_result;
    const HWRawBits<8> &id1395in_b = id1182out_value;

    id1395out_result[(getCycle()+1)%2] = (eq_bits(id1395in_a,id1395in_b));
  }
  HWRawBits<23> id1735out_result;

  { // Node ID: 1735 (NodeSlice)
    const HWFloat<8,24> &id1735in_a = id2153out_output[getCycle()%7];

    id1735out_result = (slice<0,23>(id1735in_a));
  }
  { // Node ID: 2008 (NodeConstantRawBits)
  }
  { // Node ID: 1397 (NodeNeqInlined)
    const HWRawBits<23> &id1397in_a = id1735out_result;
    const HWRawBits<23> &id1397in_b = id2008out_value;

    id1397out_result[(getCycle()+1)%2] = (neq_bits(id1397in_a,id1397in_b));
  }
  { // Node ID: 1186 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1186in_a = id1395out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1186in_b = id1397out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1186x_1;

    (id1186x_1) = (and_fixed(id1186in_a,id1186in_b));
    id1186out_result[(getCycle()+1)%2] = (id1186x_1);
  }
  { // Node ID: 1187 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id1187in_a = id1393out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1187in_b = id1186out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1187x_1;

    (id1187x_1) = (or_fixed(id1187in_a,id1187in_b));
    id1187out_result[(getCycle()+1)%2] = (id1187x_1);
  }
  { // Node ID: 2247 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2247in_input = id1187out_result[getCycle()%2];

    id2247out_output[(getCycle()+79)%80] = id2247in_input;
  }
  { // Node ID: 672 (NodeConstantRawBits)
  }
  HWRawBits<23> id1736out_result;

  { // Node ID: 1736 (NodeSlice)
    const HWFloat<8,24> &id1736in_a = id2434out_output[getCycle()%2];

    id1736out_result = (slice<0,23>(id1736in_a));
  }
  HWRawBits<24> id673out_result;

  { // Node ID: 673 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id673in_in0 = id672out_value;
    const HWRawBits<23> &id673in_in1 = id1736out_result;

    id673out_result = (cat(id673in_in0,id673in_in1));
  }
  HWOffsetFix<24,0,UNSIGNED> id676out_output;

  { // Node ID: 676 (NodeReinterpret)
    const HWRawBits<24> &id676in_input = id673out_result;

    id676out_output = (cast_bits2fixed<24,0,UNSIGNED>(id676in_input));
  }
  HWRawBits<8> id1737out_result;

  { // Node ID: 1737 (NodeSlice)
    const HWFloat<8,24> &id1737in_a = id143out_result[getCycle()%9];

    id1737out_result = (slice<23,8>(id1737in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id678out_output;

  { // Node ID: 678 (NodeReinterpret)
    const HWRawBits<8> &id678in_input = id1737out_result;

    id678out_output = (cast_bits2fixed<8,0,UNSIGNED>(id678in_input));
  }
  { // Node ID: 2006 (NodeConstantRawBits)
  }
  { // Node ID: 2005 (NodeConstantRawBits)
  }
  { // Node ID: 2028 (NodeTriArith)
    const HWOffsetFix<8,0,UNSIGNED> &id2028in_a = id678out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2028in_b = id2006out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2028in_c = id2005out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id2028x_1;

    (id2028x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id2028in_a,id2028in_b)),id2028in_c));
    id2028out_result[(getCycle()+1)%2] = (id2028x_1);
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2029out_o;

  { // Node ID: 2029 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id2029in_i = id2028out_result[getCycle()%2];

    id2029out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id2029in_i));
  }
  HWRawBits<1> id1400out_result;

  { // Node ID: 1400 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1400in_a = id2029out_o;

    id1400out_result = (slice<8,1>(id1400in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1401out_output;

  { // Node ID: 1401 (NodeReinterpret)
    const HWRawBits<1> &id1401in_input = id1400out_result;

    id1401out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1401in_input));
  }
  { // Node ID: 2156 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2156in_input = id1401out_output;

    id2156out_output[(getCycle()+5)%6] = id2156in_input;
  }
  { // Node ID: 683 (NodeConstantRawBits)
  }
  { // Node ID: 2091 (NodeConstantRawBits)
  }
  HWRawBits<1> id1402out_result;

  { // Node ID: 1402 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1402in_a = id2029out_o;

    id1402out_result = (slice<8,1>(id1402in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1403out_output;

  { // Node ID: 1403 (NodeReinterpret)
    const HWRawBits<1> &id1403in_input = id1402out_result;

    id1403out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1403in_input));
  }
  { // Node ID: 2055 (NodeCondAddSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2055in_a = id2091out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2055in_b = id2029out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id2055in_sub = id1403out_output;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2055x_1;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2055x_2;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2055x_3;

    (id2055x_1) = (add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2055in_a,id2055in_b));
    (id2055x_2) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2055in_a,id2055in_b));
    switch((id2055in_sub.getValueAsLong())) {
      case 0l:
        id2055x_3 = (id2055x_1);
        break;
      case 1l:
        id2055x_3 = (id2055x_2);
        break;
      default:
        id2055x_3 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id2055out_result[(getCycle()+1)%2] = (id2055x_3);
  }
  HWRawBits<8> id690out_result;

  { // Node ID: 690 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id690in_a = id2055out_result[getCycle()%2];

    id690out_result = (slice<0,8>(id690in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id691out_output;

  { // Node ID: 691 (NodeReinterpret)
    const HWRawBits<8> &id691in_input = id690out_result;

    id691out_output = (cast_bits2fixed<8,0,UNSIGNED>(id691in_input));
  }
  { // Node ID: 693 (NodeShift)
    const HWRawBits<185> &id693in_datain = id683out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id693in_shift = id691out_output;

    id693out_dataout[(getCycle()+4)%5] = (shift_left_bits(id693in_datain,(id693in_shift.getValueAsLong())));
  }
  { // Node ID: 692 (NodeShift)
    const HWRawBits<185> &id692in_datain = id683out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id692in_shift = id691out_output;

    id692out_dataout[(getCycle()+4)%5] = (shift_right_bits(id692in_datain,(id692in_shift.getValueAsLong())));
  }
  { // Node ID: 694 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id694in_sel = id2156out_output[getCycle()%6];
    const HWRawBits<185> &id694in_option0 = id693out_dataout[getCycle()%5];
    const HWRawBits<185> &id694in_option1 = id692out_dataout[getCycle()%5];

    HWRawBits<185> id694x_1;

    switch((id694in_sel.getValueAsLong())) {
      case 0l:
        id694x_1 = id694in_option0;
        break;
      case 1l:
        id694x_1 = id694in_option1;
        break;
      default:
        id694x_1 = (HWRawBits<185>(varint_u<185>::init(3, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64), m_undefined_value.get_bits(57))));
        break;
    }
    id694out_result[(getCycle()+1)%2] = (id694x_1);
  }
  HWRawBits<81> id695out_result;

  { // Node ID: 695 (NodeSlice)
    const HWRawBits<185> &id695in_a = id694out_result[getCycle()%2];

    id695out_result = (slice<104,81>(id695in_a));
  }
  HWOffsetFix<81,0,UNSIGNED> id697out_output;

  { // Node ID: 697 (NodeReinterpret)
    const HWRawBits<81> &id697in_input = id695out_result;

    id697out_output = (cast_bits2fixed<81,0,UNSIGNED>(id697in_input));
  }
  { // Node ID: 698 (NodeMul)
    const HWOffsetFix<24,0,UNSIGNED> &id698in_a = id676out_output;
    const HWOffsetFix<81,0,UNSIGNED> &id698in_b = id697out_output;

    id698out_result[(getCycle()+1)%2] = (mul_fixed<81,0,UNSIGNED,TONEAREVEN>(id698in_a,id698in_b));
  }
  HWRawBits<79> id705out_result;

  { // Node ID: 705 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id705in_a = id698out_result[getCycle()%2];

    id705out_result = (slice<0,79>(id705in_a));
  }
  HWOffsetFix<79,-79,UNSIGNED> id706out_output;

  { // Node ID: 706 (NodeReinterpret)
    const HWRawBits<79> &id706in_input = id705out_result;

    id706out_output = (cast_bits2fixed<79,-79,UNSIGNED>(id706in_input));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id709out_o;

  { // Node ID: 709 (NodeCast)
    const HWOffsetFix<79,-79,UNSIGNED> &id709in_i = id706out_output;

    id709out_o = (cast_fixed2fixed<80,-79,TWOSCOMPLEMENT,TONEAREVEN>(id709in_i));
  }
  { // Node ID: 710 (NodeLeading1Detect)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id710in_input = id709out_o;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id710x_1;
    HWRawBits<80> id710x_2;
    HWRawBits<80> id710x_3;

    switch(((slice<79,1>(id710in_input)).getValueAsLong())) {
      case 0l:
        id710x_1 = id710in_input;
        break;
      case 1l:
        id710x_1 = (not_fixed(id710in_input));
        break;
      default:
        id710x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    {
      varint_u<80> raw_bits = (slice<0,80>((cat((id710x_1),(c_hw_fix_1_0_uns_bits))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id710x_2 = HWRawBits<80>(raw_bits);
    }
    {
      varint_u<80> raw_bits = (cast_fixed2bits((add_fixed<80,0,UNSIGNED,TRUNCATE>((cast_bits2fixed<80,0,UNSIGNED>((not_bits((id710x_2))))),(c_hw_fix_80_0_uns_1_0val))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id710x_3 = HWRawBits<80>(raw_bits);
    }
    id710out_output[(getCycle()+1)%2] = (cast_bits2fixed<80,0,UNSIGNED>((and_bits((id710x_3),(slice<0,80>((cat((id710x_1),(c_hw_fix_1_0_uns_bits)))))))));
  }
  { // Node ID: 711 (NodeOneHotDecode)
    const HWOffsetFix<80,0,UNSIGNED> &id711in_input = id710out_output[getCycle()%2];

    (id711st_one_hot_or) = (c_hw_fix_7_0_uns_bits_1);
    if(((slice<0,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_1)));
    }
    if(((slice<1,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_2)));
    }
    if(((slice<2,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_3)));
    }
    if(((slice<3,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_4)));
    }
    if(((slice<4,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_5)));
    }
    if(((slice<5,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_6)));
    }
    if(((slice<6,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_7)));
    }
    if(((slice<7,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_8)));
    }
    if(((slice<8,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_9)));
    }
    if(((slice<9,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_10)));
    }
    if(((slice<10,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_11)));
    }
    if(((slice<11,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_12)));
    }
    if(((slice<12,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_13)));
    }
    if(((slice<13,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_14)));
    }
    if(((slice<14,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_15)));
    }
    if(((slice<15,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_16)));
    }
    if(((slice<16,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_17)));
    }
    if(((slice<17,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_18)));
    }
    if(((slice<18,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_19)));
    }
    if(((slice<19,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_20)));
    }
    if(((slice<20,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_21)));
    }
    if(((slice<21,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_22)));
    }
    if(((slice<22,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_23)));
    }
    if(((slice<23,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_24)));
    }
    if(((slice<24,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_25)));
    }
    if(((slice<25,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_26)));
    }
    if(((slice<26,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_27)));
    }
    if(((slice<27,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_28)));
    }
    if(((slice<28,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_29)));
    }
    if(((slice<29,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_30)));
    }
    if(((slice<30,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_31)));
    }
    if(((slice<31,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_32)));
    }
    if(((slice<32,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_33)));
    }
    if(((slice<33,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_34)));
    }
    if(((slice<34,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_35)));
    }
    if(((slice<35,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_36)));
    }
    if(((slice<36,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_37)));
    }
    if(((slice<37,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_38)));
    }
    if(((slice<38,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_39)));
    }
    if(((slice<39,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_40)));
    }
    if(((slice<40,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_41)));
    }
    if(((slice<41,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_42)));
    }
    if(((slice<42,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_43)));
    }
    if(((slice<43,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_44)));
    }
    if(((slice<44,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_45)));
    }
    if(((slice<45,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_46)));
    }
    if(((slice<46,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_47)));
    }
    if(((slice<47,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_48)));
    }
    if(((slice<48,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_49)));
    }
    if(((slice<49,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_50)));
    }
    if(((slice<50,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_51)));
    }
    if(((slice<51,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_52)));
    }
    if(((slice<52,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_53)));
    }
    if(((slice<53,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_54)));
    }
    if(((slice<54,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_55)));
    }
    if(((slice<55,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_56)));
    }
    if(((slice<56,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_57)));
    }
    if(((slice<57,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_58)));
    }
    if(((slice<58,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_59)));
    }
    if(((slice<59,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_60)));
    }
    if(((slice<60,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_61)));
    }
    if(((slice<61,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_62)));
    }
    if(((slice<62,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_63)));
    }
    if(((slice<63,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_64)));
    }
    if(((slice<64,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_65)));
    }
    if(((slice<65,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_66)));
    }
    if(((slice<66,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_67)));
    }
    if(((slice<67,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_68)));
    }
    if(((slice<68,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_69)));
    }
    if(((slice<69,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_70)));
    }
    if(((slice<70,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_71)));
    }
    if(((slice<71,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_72)));
    }
    if(((slice<72,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_73)));
    }
    if(((slice<73,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_74)));
    }
    if(((slice<74,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_75)));
    }
    if(((slice<75,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_76)));
    }
    if(((slice<76,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_77)));
    }
    if(((slice<77,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_78)));
    }
    if(((slice<78,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_79)));
    }
    if(((slice<79,1>(id711in_input)).getValueAsBool())) {
      (id711st_one_hot_or) = (or_fixed((id711st_one_hot_or),(c_hw_fix_7_0_uns_bits_80)));
    }
    id711out_output[(getCycle()+1)%2] = (id711st_one_hot_or);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id712out_o;

  { // Node ID: 712 (NodeCast)
    const HWOffsetFix<7,0,UNSIGNED> &id712in_i = id711out_output[getCycle()%2];

    id712out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id712in_i));
  }
  { // Node ID: 2001 (NodeConstantRawBits)
  }
  { // Node ID: 2000 (NodeConstantRawBits)
  }
  { // Node ID: 2030 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2030in_a = id712out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2030in_b = id2001out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2030in_c = id2000out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id2030x_1;

    (id2030x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id2030in_a,id2030in_b)),id2030in_c));
    id2030out_result[(getCycle()+1)%2] = (id2030x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2031out_o;

  { // Node ID: 2031 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id2031in_i = id2030out_result[getCycle()%2];

    id2031out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id2031in_i));
  }
  { // Node ID: 2157 (NodeFIFO)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2157in_input = id2031out_o;

    id2157out_output[(getCycle()+4)%5] = id2157in_input;
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id729out_o;

  { // Node ID: 729 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id729in_i = id2157out_output[getCycle()%5];

    id729out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id729in_i));
  }
  { // Node ID: 1999 (NodeConstantRawBits)
  }
  { // Node ID: 731 (NodeAdd)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id731in_a = id729out_o;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id731in_b = id1999out_value;

    id731out_result[(getCycle()+1)%2] = (add_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id731in_a,id731in_b));
  }
  { // Node ID: 1998 (NodeConstantRawBits)
  }
  { // Node ID: 1406 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1406in_a = id731out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1406in_b = id1998out_value;

    id1406out_result[(getCycle()+1)%2] = (lt_fixed(id1406in_a,id1406in_b));
  }
  { // Node ID: 2162 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2162in_input = id1406out_result[getCycle()%2];

    id2162out_output[(getCycle()+1)%2] = id2162in_input;
  }
  { // Node ID: 1997 (NodeConstantRawBits)
  }
  { // Node ID: 1407 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1407in_a = id731out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1407in_b = id1997out_value;

    id1407out_result[(getCycle()+1)%2] = (gt_fixed(id1407in_a,id1407in_b));
  }
  { // Node ID: 1357 (NodeConstantRawBits)
  }
  HWOffsetFix<8,0,UNSIGNED> id734out_o;

  { // Node ID: 734 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id734in_i = id731out_result[getCycle()%2];

    id734out_o = (cast_fixed2fixed<8,0,UNSIGNED,TONEAREVEN>(id734in_i));
  }
  { // Node ID: 2161 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id2161in_input = id734out_o;

    id2161out_output[(getCycle()+1)%2] = id2161in_input;
  }
  { // Node ID: 1996 (NodeConstantRawBits)
  }
  { // Node ID: 1995 (NodeConstantRawBits)
  }
  { // Node ID: 2032 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2032in_a = id1996out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2032in_b = id712out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2032in_c = id1995out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id2032x_1;

    (id2032x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id2032in_a,id2032in_b)),id2032in_c));
    id2032out_result[(getCycle()+1)%2] = (id2032x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2033out_o;

  { // Node ID: 2033 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id2033in_i = id2032out_result[getCycle()%2];

    id2033out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id2033in_i));
  }
  { // Node ID: 1994 (NodeConstantRawBits)
  }
  { // Node ID: 1408 (NodeGtInlined)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1408in_a = id2033out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1408in_b = id1994out_value;

    id1408out_result[(getCycle()+1)%2] = (gt_fixed(id1408in_a,id1408in_b));
  }
  { // Node ID: 2159 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2159in_input = id1408out_result[getCycle()%2];

    id2159out_output[(getCycle()+3)%4] = id2159in_input;
  }
  { // Node ID: 2158 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2158in_input = id709out_o;

    id2158out_output[(getCycle()+3)%4] = id2158in_input;
  }
  { // Node ID: 2435 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2435in_input = id2158out_output[getCycle()%4];

    id2435out_output[(getCycle()+4)%5] = id2435in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id723out_o;

  { // Node ID: 723 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id723in_i = id2033out_o;

    id723out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAREVEN>(id723in_i));
  }
  { // Node ID: 724 (NodeShift)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id724in_datain = id2158out_output[getCycle()%4];
    const HWOffsetFix<7,0,UNSIGNED> &id724in_shift = id723out_o;

    id724out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id724in_datain,(id724in_shift.getValueAsLong())));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id725out_output;

  { // Node ID: 725 (NodeReinterpret)
    const HWRawBits<80> &id725in_input = id724out_dataout[getCycle()%5];

    id725out_output = (cast_bits2fixed<80,-79,TWOSCOMPLEMENT>(id725in_input));
  }
  { // Node ID: 726 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id726in_sel = id2159out_output[getCycle()%4];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id726in_option0 = id2435out_output[getCycle()%5];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id726in_option1 = id725out_output;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id726x_1;

    switch((id726in_sel.getValueAsLong())) {
      case 0l:
        id726x_1 = id726in_option0;
        break;
      case 1l:
        id726x_1 = id726in_option1;
        break;
      default:
        id726x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    id726out_result[(getCycle()+1)%2] = (id726x_1);
  }
  HWOffsetFix<80,-78,TWOSCOMPLEMENT> id728out_output;

  { // Node ID: 728 (NodeReinterpret)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id728in_input = id726out_result[getCycle()%2];

    id728out_output = (cast_bits2fixed<80,-78,TWOSCOMPLEMENT>((cast_fixed2bits(id728in_input))));
  }
  { // Node ID: 732 (NodeCast)
    const HWOffsetFix<80,-78,TWOSCOMPLEMENT> &id732in_i = id728out_output;

    id732out_o[(getCycle()+1)%2] = (cast_fixed2fixed<24,-23,UNSIGNED,TONEAREVEN>(id732in_i));
  }
  HWRawBits<23> id733out_result;

  { // Node ID: 733 (NodeSlice)
    const HWOffsetFix<24,-23,UNSIGNED> &id733in_a = id732out_o[getCycle()%2];

    id733out_result = (slice<0,23>(id733in_a));
  }
  HWRawBits<32> id1409out_result;

  { // Node ID: 1409 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id1409in_in0 = id1357out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1409in_in1 = id2161out_output[getCycle()%2];
    const HWRawBits<23> &id1409in_in2 = id733out_result;

    id1409out_result = (cat((cat(id1409in_in0,id1409in_in1)),id1409in_in2));
  }
  HWFloat<8,24> id738out_output;

  { // Node ID: 738 (NodeReinterpret)
    const HWRawBits<32> &id738in_input = id1409out_result;

    id738out_output = (cast_bits2float<8,24>(id738in_input));
  }
  { // Node ID: 741 (NodeConstantRawBits)
  }
  { // Node ID: 742 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id742in_sel = id1407out_result[getCycle()%2];
    const HWFloat<8,24> &id742in_option0 = id738out_output;
    const HWFloat<8,24> &id742in_option1 = id741out_value;

    HWFloat<8,24> id742x_1;

    switch((id742in_sel.getValueAsLong())) {
      case 0l:
        id742x_1 = id742in_option0;
        break;
      case 1l:
        id742x_1 = id742in_option1;
        break;
      default:
        id742x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id742out_result[(getCycle()+1)%2] = (id742x_1);
  }
  { // Node ID: 745 (NodeConstantRawBits)
  }
  { // Node ID: 746 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id746in_sel = id2162out_output[getCycle()%2];
    const HWFloat<8,24> &id746in_option0 = id742out_result[getCycle()%2];
    const HWFloat<8,24> &id746in_option1 = id745out_value;

    HWFloat<8,24> id746x_1;

    switch((id746in_sel.getValueAsLong())) {
      case 0l:
        id746x_1 = id746in_option0;
        break;
      case 1l:
        id746x_1 = id746in_option1;
        break;
      default:
        id746x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id746out_result[(getCycle()+1)%2] = (id746x_1);
  }
  { // Node ID: 2163 (NodeFIFO)
    const HWFloat<8,24> &id2163in_input = id746out_result[getCycle()%2];

    id2163out_output[(getCycle()+1)%2] = id2163in_input;
  }
  { // Node ID: 1993 (NodeConstantRawBits)
  }
  { // Node ID: 1169 (NodeLt)
    const HWFloat<8,24> &id1169in_a = id2163out_output[getCycle()%2];
    const HWFloat<8,24> &id1169in_b = id1993out_value;

    id1169out_result[(getCycle()+2)%3] = (lt_float(id1169in_a,id1169in_b));
  }
  { // Node ID: 1992 (NodeConstantRawBits)
  }
  { // Node ID: 1171 (NodeGte)
    const HWFloat<8,24> &id1171in_a = id2163out_output[getCycle()%2];
    const HWFloat<8,24> &id1171in_b = id1992out_value;

    id1171out_result[(getCycle()+2)%3] = (gte_float(id1171in_a,id1171in_b));
  }
  { // Node ID: 1172 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id1172in_a = id1169out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id1172in_b = id1171out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id1172x_1;

    (id1172x_1) = (or_fixed(id1172in_a,id1172in_b));
    id1172out_result[(getCycle()+1)%2] = (id1172x_1);
  }
  { // Node ID: 2245 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2245in_input = id1172out_result[getCycle()%2];

    id2245out_output[(getCycle()+64)%65] = id2245in_input;
  }
  { // Node ID: 2007 (NodeConstantRawBits)
  }
  { // Node ID: 666 (NodeLt)
    const HWFloat<8,24> &id666in_a = id2434out_output[getCycle()%2];
    const HWFloat<8,24> &id666in_b = id2007out_value;

    id666out_result[(getCycle()+2)%3] = (lt_float(id666in_a,id666in_b));
  }
  HWRawBits<2> id701out_result;

  { // Node ID: 701 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id701in_a = id698out_result[getCycle()%2];

    id701out_result = (slice<79,2>(id701in_a));
  }
  { // Node ID: 2166 (NodeFIFO)
    const HWRawBits<2> &id2166in_input = id701out_result;

    id2166out_output[(getCycle()+1)%2] = id2166in_input;
  }
  { // Node ID: 2004 (NodeConstantRawBits)
  }
  { // Node ID: 703 (NodeXor)
    const HWRawBits<2> &id703in_a = id701out_result;
    const HWRawBits<2> &id703in_b = id2004out_value;

    HWRawBits<2> id703x_1;

    (id703x_1) = (xor_bits(id703in_a,id703in_b));
    id703out_result[(getCycle()+1)%2] = (id703x_1);
  }
  { // Node ID: 704 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id704in_sel = id666out_result[getCycle()%3];
    const HWRawBits<2> &id704in_option0 = id2166out_output[getCycle()%2];
    const HWRawBits<2> &id704in_option1 = id703out_result[getCycle()%2];

    HWRawBits<2> id704x_1;

    switch((id704in_sel.getValueAsLong())) {
      case 0l:
        id704x_1 = id704in_option0;
        break;
      case 1l:
        id704x_1 = id704in_option1;
        break;
      default:
        id704x_1 = (HWRawBits<2>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id704out_result[(getCycle()+1)%2] = (id704x_1);
  }
  HWRawBits<1> id747out_result;

  { // Node ID: 747 (NodeSlice)
    const HWRawBits<2> &id747in_a = id704out_result[getCycle()%2];

    id747out_result = (slice<0,1>(id747in_a));
  }
  { // Node ID: 2177 (NodeFIFO)
    const HWRawBits<1> &id2177in_input = id747out_result;

    id2177out_output[(getCycle()+27)%28] = id2177in_input;
  }
  { // Node ID: 1991 (NodeConstantRawBits)
  }
  HWRawBits<8> id767out_result;

  { // Node ID: 767 (NodeSlice)
    const HWFloat<8,24> &id767in_a = id2163out_output[getCycle()%2];

    id767out_result = (slice<23,8>(id767in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id768out_output;

  { // Node ID: 768 (NodeReinterpret)
    const HWRawBits<8> &id768in_input = id767out_result;

    id768out_output = (cast_bits2fixed<8,0,UNSIGNED>(id768in_input));
  }
  { // Node ID: 1990 (NodeConstantRawBits)
  }
  { // Node ID: 2034 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2034in_a = id1991out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id2034in_b = id768out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2034in_c = id1990out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2034x_1;

    (id2034x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2034in_a,id2034in_b)),id2034in_c));
    id2034out_result[(getCycle()+1)%2] = (id2034x_1);
  }
  HWRawBits<1> id1410out_result;

  { // Node ID: 1410 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1410in_a = id2034out_result[getCycle()%2];

    id1410out_result = (slice<8,1>(id1410in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1411out_output;

  { // Node ID: 1411 (NodeReinterpret)
    const HWRawBits<1> &id1411in_input = id1410out_result;

    id1411out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1411in_input));
  }
  { // Node ID: 2170 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2170in_input = id1411out_output;

    id2170out_output[(getCycle()+4)%5] = id2170in_input;
  }
  { // Node ID: 765 (NodeConstantRawBits)
  }
  { // Node ID: 2090 (NodeConstantRawBits)
  }
  { // Node ID: 757 (NodeConstantRawBits)
  }
  HWRawBits<31> id754out_result;

  { // Node ID: 754 (NodeSlice)
    const HWFloat<8,24> &id754in_a = id746out_result[getCycle()%2];

    id754out_result = (slice<0,31>(id754in_a));
  }
  { // Node ID: 1989 (NodeConstantRawBits)
  }
  { // Node ID: 1412 (NodeNeqInlined)
    const HWRawBits<31> &id1412in_a = id754out_result;
    const HWRawBits<31> &id1412in_b = id1989out_value;

    id1412out_result[(getCycle()+1)%2] = (neq_bits(id1412in_a,id1412in_b));
  }
  HWRawBits<23> id753out_result;

  { // Node ID: 753 (NodeSlice)
    const HWFloat<8,24> &id753in_a = id2163out_output[getCycle()%2];

    id753out_result = (slice<0,23>(id753in_a));
  }
  HWRawBits<25> id1413out_result;

  { // Node ID: 1413 (NodeCat)
    const HWRawBits<1> &id1413in_in0 = id757out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1413in_in1 = id1412out_result[getCycle()%2];
    const HWRawBits<23> &id1413in_in2 = id753out_result;

    id1413out_result = (cat((cat(id1413in_in0,id1413in_in1)),id1413in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id760out_output;

  { // Node ID: 760 (NodeReinterpret)
    const HWRawBits<25> &id760in_input = id1413out_result;

    id760out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id760in_input));
  }
  HWRawBits<1> id761out_result;

  { // Node ID: 761 (NodeSlice)
    const HWFloat<8,24> &id761in_a = id2163out_output[getCycle()%2];

    id761out_result = (slice<31,1>(id761in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id762out_output;

  { // Node ID: 762 (NodeReinterpret)
    const HWRawBits<1> &id762in_input = id761out_result;

    id762out_output = (cast_bits2fixed<1,0,UNSIGNED>(id762in_input));
  }
  { // Node ID: 2057 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2057in_a = id2090out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2057in_b = id760out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2057in_sub = id762out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2057x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2057x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2057x_3;

    (id2057x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2057in_a,id2057in_b));
    (id2057x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2057in_a,id2057in_b));
    switch((id2057in_sub.getValueAsLong())) {
      case 0l:
        id2057x_3 = (id2057x_1);
        break;
      case 1l:
        id2057x_3 = (id2057x_2);
        break;
      default:
        id2057x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2057out_result[(getCycle()+1)%2] = (id2057x_3);
  }
  HWRawBits<30> id766out_result;

  { // Node ID: 766 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id766in_in0 = id765out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id766in_in1 = id2057out_result[getCycle()%2];

    id766out_result = (cat(id766in_in0,id766in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id775out_o;

  { // Node ID: 775 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id775in_i = id2034out_result[getCycle()%2];

    id775out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id775in_i));
  }
  { // Node ID: 776 (NodeShift)
    const HWRawBits<30> &id776in_datain = id766out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id776in_shift = id775out_o;

    id776out_dataout[(getCycle()+4)%5] = (shift_left_bits(id776in_datain,(id776in_shift.getValueAsLong())));
  }
  HWRawBits<7> id777out_result;

  { // Node ID: 777 (NodeSlice)
    const HWRawBits<30> &id777in_a = id776out_dataout[getCycle()%5];

    id777out_result = (slice<23,7>(id777in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id778out_output;

  { // Node ID: 778 (NodeReinterpret)
    const HWRawBits<7> &id778in_input = id777out_result;

    id778out_output = (cast_bits2fixed<7,0,UNSIGNED>(id778in_input));
  }
  { // Node ID: 779 (NodeConstantRawBits)
  }
  { // Node ID: 780 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id780in_sel = id2170out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id780in_option0 = id778out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id780in_option1 = id779out_value;

    HWOffsetFix<7,0,UNSIGNED> id780x_1;

    switch((id780in_sel.getValueAsLong())) {
      case 0l:
        id780x_1 = id780in_option0;
        break;
      case 1l:
        id780x_1 = id780in_option1;
        break;
      default:
        id780x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id780out_result[(getCycle()+1)%2] = (id780x_1);
  }
  { // Node ID: 2171 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2171in_input = id780out_result[getCycle()%2];

    id2171out_output[(getCycle()+9)%10] = id2171in_input;
  }
  { // Node ID: 1329 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1329in_addr = id2171out_output[getCycle()%10];

    HWRawBits<128> id1329x_1;

    switch(((long)((id1329in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1329x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1329x_1 = (id1329sta_rom_store[(id1329in_addr.getValueAsLong())]);
        break;
      default:
        id1329x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1329out_dout[(getCycle()+2)%3] = (id1329x_1);
  }
  HWRawBits<32> id1336out_result;

  { // Node ID: 1336 (NodeSlice)
    const HWRawBits<128> &id1336in_a = id1329out_dout[getCycle()%3];

    id1336out_result = (slice<96,32>(id1336in_a));
  }
  HWFloat<8,24> id1337out_output;

  { // Node ID: 1337 (NodeReinterpret)
    const HWRawBits<32> &id1337in_input = id1336out_result;

    id1337out_output = (cast_bits2float<8,24>(id1337in_input));
  }
  { // Node ID: 1988 (NodeConstantRawBits)
  }
  HWRawBits<8> id968out_result;

  { // Node ID: 968 (NodeSlice)
    const HWFloat<8,24> &id968in_a = id2163out_output[getCycle()%2];

    id968out_result = (slice<23,8>(id968in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id969out_output;

  { // Node ID: 969 (NodeReinterpret)
    const HWRawBits<8> &id969in_input = id968out_result;

    id969out_output = (cast_bits2fixed<8,0,UNSIGNED>(id969in_input));
  }
  { // Node ID: 1987 (NodeConstantRawBits)
  }
  { // Node ID: 2035 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2035in_a = id1988out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id2035in_b = id969out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2035in_c = id1987out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2035x_1;

    (id2035x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2035in_a,id2035in_b)),id2035in_c));
    id2035out_result[(getCycle()+1)%2] = (id2035x_1);
  }
  HWRawBits<1> id1414out_result;

  { // Node ID: 1414 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1414in_a = id2035out_result[getCycle()%2];

    id1414out_result = (slice<8,1>(id1414in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1415out_output;

  { // Node ID: 1415 (NodeReinterpret)
    const HWRawBits<1> &id1415in_input = id1414out_result;

    id1415out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1415in_input));
  }
  { // Node ID: 2175 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2175in_input = id1415out_output;

    id2175out_output[(getCycle()+4)%5] = id2175in_input;
  }
  { // Node ID: 966 (NodeConstantRawBits)
  }
  { // Node ID: 2089 (NodeConstantRawBits)
  }
  { // Node ID: 958 (NodeConstantRawBits)
  }
  HWRawBits<31> id955out_result;

  { // Node ID: 955 (NodeSlice)
    const HWFloat<8,24> &id955in_a = id746out_result[getCycle()%2];

    id955out_result = (slice<0,31>(id955in_a));
  }
  { // Node ID: 1986 (NodeConstantRawBits)
  }
  { // Node ID: 1416 (NodeNeqInlined)
    const HWRawBits<31> &id1416in_a = id955out_result;
    const HWRawBits<31> &id1416in_b = id1986out_value;

    id1416out_result[(getCycle()+1)%2] = (neq_bits(id1416in_a,id1416in_b));
  }
  HWRawBits<23> id954out_result;

  { // Node ID: 954 (NodeSlice)
    const HWFloat<8,24> &id954in_a = id2163out_output[getCycle()%2];

    id954out_result = (slice<0,23>(id954in_a));
  }
  HWRawBits<25> id1417out_result;

  { // Node ID: 1417 (NodeCat)
    const HWRawBits<1> &id1417in_in0 = id958out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1417in_in1 = id1416out_result[getCycle()%2];
    const HWRawBits<23> &id1417in_in2 = id954out_result;

    id1417out_result = (cat((cat(id1417in_in0,id1417in_in1)),id1417in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id961out_output;

  { // Node ID: 961 (NodeReinterpret)
    const HWRawBits<25> &id961in_input = id1417out_result;

    id961out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id961in_input));
  }
  HWRawBits<1> id962out_result;

  { // Node ID: 962 (NodeSlice)
    const HWFloat<8,24> &id962in_a = id2163out_output[getCycle()%2];

    id962out_result = (slice<31,1>(id962in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id963out_output;

  { // Node ID: 963 (NodeReinterpret)
    const HWRawBits<1> &id963in_input = id962out_result;

    id963out_output = (cast_bits2fixed<1,0,UNSIGNED>(id963in_input));
  }
  { // Node ID: 2059 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2059in_a = id2089out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2059in_b = id961out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2059in_sub = id963out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2059x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2059x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2059x_3;

    (id2059x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2059in_a,id2059in_b));
    (id2059x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2059in_a,id2059in_b));
    switch((id2059in_sub.getValueAsLong())) {
      case 0l:
        id2059x_3 = (id2059x_1);
        break;
      case 1l:
        id2059x_3 = (id2059x_2);
        break;
      default:
        id2059x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2059out_result[(getCycle()+1)%2] = (id2059x_3);
  }
  HWRawBits<30> id967out_result;

  { // Node ID: 967 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id967in_in0 = id966out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id967in_in1 = id2059out_result[getCycle()%2];

    id967out_result = (cat(id967in_in0,id967in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id976out_o;

  { // Node ID: 976 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id976in_i = id2035out_result[getCycle()%2];

    id976out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id976in_i));
  }
  { // Node ID: 977 (NodeShift)
    const HWRawBits<30> &id977in_datain = id967out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id977in_shift = id976out_o;

    id977out_dataout[(getCycle()+4)%5] = (shift_left_bits(id977in_datain,(id977in_shift.getValueAsLong())));
  }
  HWRawBits<7> id978out_result;

  { // Node ID: 978 (NodeSlice)
    const HWRawBits<30> &id978in_a = id977out_dataout[getCycle()%5];

    id978out_result = (slice<23,7>(id978in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id979out_output;

  { // Node ID: 979 (NodeReinterpret)
    const HWRawBits<7> &id979in_input = id978out_result;

    id979out_output = (cast_bits2fixed<7,0,UNSIGNED>(id979in_input));
  }
  { // Node ID: 980 (NodeConstantRawBits)
  }
  { // Node ID: 981 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id981in_sel = id2175out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id981in_option0 = id979out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id981in_option1 = id980out_value;

    HWOffsetFix<7,0,UNSIGNED> id981x_1;

    switch((id981in_sel.getValueAsLong())) {
      case 0l:
        id981x_1 = id981in_option0;
        break;
      case 1l:
        id981x_1 = id981in_option1;
        break;
      default:
        id981x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id981out_result[(getCycle()+1)%2] = (id981x_1);
  }
  { // Node ID: 2176 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2176in_input = id981out_result[getCycle()%2];

    id2176out_output[(getCycle()+9)%10] = id2176in_input;
  }
  { // Node ID: 1338 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1338in_addr = id2176out_output[getCycle()%10];

    HWRawBits<128> id1338x_1;

    switch(((long)((id1338in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1338x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1338x_1 = (id1338sta_rom_store[(id1338in_addr.getValueAsLong())]);
        break;
      default:
        id1338x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1338out_dout[(getCycle()+2)%3] = (id1338x_1);
  }
  HWRawBits<32> id1345out_result;

  { // Node ID: 1345 (NodeSlice)
    const HWRawBits<128> &id1345in_a = id1338out_dout[getCycle()%3];

    id1345out_result = (slice<96,32>(id1345in_a));
  }
  HWFloat<8,24> id1346out_output;

  { // Node ID: 1346 (NodeReinterpret)
    const HWRawBits<32> &id1346in_input = id1345out_result;

    id1346out_output = (cast_bits2float<8,24>(id1346in_input));
  }
  { // Node ID: 1159 (NodeMux)
    const HWRawBits<1> &id1159in_sel = id2177out_output[getCycle()%28];
    const HWFloat<8,24> &id1159in_option0 = id1337out_output;
    const HWFloat<8,24> &id1159in_option1 = id1346out_output;

    HWFloat<8,24> id1159x_1;

    switch((id1159in_sel.getValueAsLong())) {
      case 0l:
        id1159x_1 = id1159in_option0;
        break;
      case 1l:
        id1159x_1 = id1159in_option1;
        break;
      default:
        id1159x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1159out_result[(getCycle()+1)%2] = (id1159x_1);
  }
  { // Node ID: 2024 (NodePO2FPMult)
    const HWFloat<8,24> &id2024in_floatIn = id746out_result[getCycle()%2];

    id2024out_floatOut[(getCycle()+1)%2] = (mul_float(id2024in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2178 (NodeFIFO)
    const HWFloat<8,24> &id2178in_input = id2024out_floatOut[getCycle()%2];

    id2178out_output[(getCycle()+3)%4] = id2178in_input;
  }
  HWRawBits<1> id790out_result;

  { // Node ID: 790 (NodeSlice)
    const HWFloat<8,24> &id790in_a = id2178out_output[getCycle()%4];

    id790out_result = (slice<31,1>(id790in_a));
  }
  { // Node ID: 2207 (NodeFIFO)
    const HWRawBits<1> &id2207in_input = id790out_result;

    id2207out_output[(getCycle()+6)%7] = id2207in_input;
  }
  HWRawBits<8> id783out_result;

  { // Node ID: 783 (NodeSlice)
    const HWFloat<8,24> &id783in_a = id2024out_floatOut[getCycle()%2];

    id783out_result = (slice<23,8>(id783in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id784out_output;

  { // Node ID: 784 (NodeReinterpret)
    const HWRawBits<8> &id784in_input = id783out_result;

    id784out_output = (cast_bits2fixed<8,0,UNSIGNED>(id784in_input));
  }
  { // Node ID: 1984 (NodeConstantRawBits)
  }
  { // Node ID: 786 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id786in_a = id784out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id786in_b = id1984out_value;

    id786out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id786in_a,id786in_b));
  }
  { // Node ID: 1983 (NodeConstantRawBits)
  }
  { // Node ID: 1418 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1418in_a = id786out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1418in_b = id1983out_value;

    id1418out_result[(getCycle()+1)%2] = (gte_fixed(id1418in_a,id1418in_b));
  }
  { // Node ID: 1982 (NodeConstantRawBits)
  }
  { // Node ID: 1419 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1419in_a = id786out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1419in_b = id1982out_value;

    id1419out_result[(getCycle()+1)%2] = (lte_fixed(id1419in_a,id1419in_b));
  }
  { // Node ID: 795 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id795in_a = id1418out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id795in_b = id1419out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id795x_1;

    (id795x_1) = (or_fixed(id795in_a,id795in_b));
    id795out_result[(getCycle()+1)%2] = (id795x_1);
  }
  { // Node ID: 1981 (NodeConstantRawBits)
  }
  { // Node ID: 1420 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1420in_a = id786out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1420in_b = id1981out_value;

    id1420out_result[(getCycle()+1)%2] = (lte_fixed(id1420in_a,id1420in_b));
  }
  { // Node ID: 2179 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2179in_input = id1420out_result[getCycle()%2];

    id2179out_output[(getCycle()+1)%2] = id2179in_input;
  }
  HWRawBits<2> id947out_result;

  { // Node ID: 947 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id947in_in0 = id795out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id947in_in1 = id2179out_output[getCycle()%2];

    id947out_result = (cat(id947in_in0,id947in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id948out_output;

  { // Node ID: 948 (NodeReinterpret)
    const HWRawBits<2> &id948in_input = id947out_result;

    id948out_output = (cast_bits2fixed<2,0,UNSIGNED>(id948in_input));
  }
  { // Node ID: 2205 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2205in_input = id948out_output;

    id2205out_output[(getCycle()+5)%6] = id2205in_input;
  }
  { // Node ID: 1980 (NodeConstantRawBits)
  }
  { // Node ID: 1979 (NodeConstantRawBits)
  }
  { // Node ID: 806 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id806in_a = id1979out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id806in_b = id786out_result[getCycle()%2];

    id806out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id806in_a,id806in_b));
  }
  { // Node ID: 1421 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1421in_a = id1980out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1421in_b = id806out_result[getCycle()%2];

    id1421out_result[(getCycle()+1)%2] = (lt_fixed(id1421in_a,id1421in_b));
  }
  { // Node ID: 942 (NodeConstantRawBits)
  }
  HWRawBits<1> id1738out_result;

  { // Node ID: 1738 (NodeSlice)
    const HWFloat<8,24> &id1738in_a = id2178out_output[getCycle()%4];

    id1738out_result = (slice<22,1>(id1738in_a));
  }
  { // Node ID: 943 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id943in_sel = id1421out_result[getCycle()%2];
    const HWRawBits<1> &id943in_option0 = id942out_value;
    const HWRawBits<1> &id943in_option1 = id1738out_result;

    HWRawBits<1> id943x_1;

    switch((id943in_sel.getValueAsLong())) {
      case 0l:
        id943x_1 = id943in_option0;
        break;
      case 1l:
        id943x_1 = id943in_option1;
        break;
      default:
        id943x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id943out_result[(getCycle()+1)%2] = (id943x_1);
  }
  { // Node ID: 1978 (NodeConstantRawBits)
  }
  { // Node ID: 1423 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1423in_a = id1978out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1423in_b = id806out_result[getCycle()%2];

    id1423out_result[(getCycle()+1)%2] = (lt_fixed(id1423in_a,id1423in_b));
  }
  { // Node ID: 936 (NodeConstantRawBits)
  }
  HWRawBits<1> id1739out_result;

  { // Node ID: 1739 (NodeSlice)
    const HWFloat<8,24> &id1739in_a = id2178out_output[getCycle()%4];

    id1739out_result = (slice<21,1>(id1739in_a));
  }
  { // Node ID: 937 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id937in_sel = id1423out_result[getCycle()%2];
    const HWRawBits<1> &id937in_option0 = id936out_value;
    const HWRawBits<1> &id937in_option1 = id1739out_result;

    HWRawBits<1> id937x_1;

    switch((id937in_sel.getValueAsLong())) {
      case 0l:
        id937x_1 = id937in_option0;
        break;
      case 1l:
        id937x_1 = id937in_option1;
        break;
      default:
        id937x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id937out_result[(getCycle()+1)%2] = (id937x_1);
  }
  { // Node ID: 1977 (NodeConstantRawBits)
  }
  { // Node ID: 1425 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1425in_a = id1977out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1425in_b = id806out_result[getCycle()%2];

    id1425out_result[(getCycle()+1)%2] = (lt_fixed(id1425in_a,id1425in_b));
  }
  { // Node ID: 930 (NodeConstantRawBits)
  }
  HWRawBits<1> id1740out_result;

  { // Node ID: 1740 (NodeSlice)
    const HWFloat<8,24> &id1740in_a = id2178out_output[getCycle()%4];

    id1740out_result = (slice<20,1>(id1740in_a));
  }
  { // Node ID: 931 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id931in_sel = id1425out_result[getCycle()%2];
    const HWRawBits<1> &id931in_option0 = id930out_value;
    const HWRawBits<1> &id931in_option1 = id1740out_result;

    HWRawBits<1> id931x_1;

    switch((id931in_sel.getValueAsLong())) {
      case 0l:
        id931x_1 = id931in_option0;
        break;
      case 1l:
        id931x_1 = id931in_option1;
        break;
      default:
        id931x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id931out_result[(getCycle()+1)%2] = (id931x_1);
  }
  { // Node ID: 1976 (NodeConstantRawBits)
  }
  { // Node ID: 1427 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1427in_a = id1976out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1427in_b = id806out_result[getCycle()%2];

    id1427out_result[(getCycle()+1)%2] = (lt_fixed(id1427in_a,id1427in_b));
  }
  { // Node ID: 924 (NodeConstantRawBits)
  }
  HWRawBits<1> id1741out_result;

  { // Node ID: 1741 (NodeSlice)
    const HWFloat<8,24> &id1741in_a = id2178out_output[getCycle()%4];

    id1741out_result = (slice<19,1>(id1741in_a));
  }
  { // Node ID: 925 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id925in_sel = id1427out_result[getCycle()%2];
    const HWRawBits<1> &id925in_option0 = id924out_value;
    const HWRawBits<1> &id925in_option1 = id1741out_result;

    HWRawBits<1> id925x_1;

    switch((id925in_sel.getValueAsLong())) {
      case 0l:
        id925x_1 = id925in_option0;
        break;
      case 1l:
        id925x_1 = id925in_option1;
        break;
      default:
        id925x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id925out_result[(getCycle()+1)%2] = (id925x_1);
  }
  { // Node ID: 1975 (NodeConstantRawBits)
  }
  { // Node ID: 1429 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1429in_a = id1975out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1429in_b = id806out_result[getCycle()%2];

    id1429out_result[(getCycle()+1)%2] = (lt_fixed(id1429in_a,id1429in_b));
  }
  { // Node ID: 918 (NodeConstantRawBits)
  }
  HWRawBits<1> id1742out_result;

  { // Node ID: 1742 (NodeSlice)
    const HWFloat<8,24> &id1742in_a = id2178out_output[getCycle()%4];

    id1742out_result = (slice<18,1>(id1742in_a));
  }
  { // Node ID: 919 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id919in_sel = id1429out_result[getCycle()%2];
    const HWRawBits<1> &id919in_option0 = id918out_value;
    const HWRawBits<1> &id919in_option1 = id1742out_result;

    HWRawBits<1> id919x_1;

    switch((id919in_sel.getValueAsLong())) {
      case 0l:
        id919x_1 = id919in_option0;
        break;
      case 1l:
        id919x_1 = id919in_option1;
        break;
      default:
        id919x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id919out_result[(getCycle()+1)%2] = (id919x_1);
  }
  { // Node ID: 1974 (NodeConstantRawBits)
  }
  { // Node ID: 1431 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1431in_a = id1974out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1431in_b = id806out_result[getCycle()%2];

    id1431out_result[(getCycle()+1)%2] = (lt_fixed(id1431in_a,id1431in_b));
  }
  { // Node ID: 912 (NodeConstantRawBits)
  }
  HWRawBits<1> id1743out_result;

  { // Node ID: 1743 (NodeSlice)
    const HWFloat<8,24> &id1743in_a = id2178out_output[getCycle()%4];

    id1743out_result = (slice<17,1>(id1743in_a));
  }
  { // Node ID: 913 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id913in_sel = id1431out_result[getCycle()%2];
    const HWRawBits<1> &id913in_option0 = id912out_value;
    const HWRawBits<1> &id913in_option1 = id1743out_result;

    HWRawBits<1> id913x_1;

    switch((id913in_sel.getValueAsLong())) {
      case 0l:
        id913x_1 = id913in_option0;
        break;
      case 1l:
        id913x_1 = id913in_option1;
        break;
      default:
        id913x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id913out_result[(getCycle()+1)%2] = (id913x_1);
  }
  { // Node ID: 1973 (NodeConstantRawBits)
  }
  { // Node ID: 1433 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1433in_a = id1973out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1433in_b = id806out_result[getCycle()%2];

    id1433out_result[(getCycle()+1)%2] = (lt_fixed(id1433in_a,id1433in_b));
  }
  { // Node ID: 906 (NodeConstantRawBits)
  }
  HWRawBits<1> id1744out_result;

  { // Node ID: 1744 (NodeSlice)
    const HWFloat<8,24> &id1744in_a = id2178out_output[getCycle()%4];

    id1744out_result = (slice<16,1>(id1744in_a));
  }
  { // Node ID: 907 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id907in_sel = id1433out_result[getCycle()%2];
    const HWRawBits<1> &id907in_option0 = id906out_value;
    const HWRawBits<1> &id907in_option1 = id1744out_result;

    HWRawBits<1> id907x_1;

    switch((id907in_sel.getValueAsLong())) {
      case 0l:
        id907x_1 = id907in_option0;
        break;
      case 1l:
        id907x_1 = id907in_option1;
        break;
      default:
        id907x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id907out_result[(getCycle()+1)%2] = (id907x_1);
  }
  { // Node ID: 1972 (NodeConstantRawBits)
  }
  { // Node ID: 1435 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1435in_a = id1972out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1435in_b = id806out_result[getCycle()%2];

    id1435out_result[(getCycle()+1)%2] = (lt_fixed(id1435in_a,id1435in_b));
  }
  { // Node ID: 900 (NodeConstantRawBits)
  }
  HWRawBits<1> id1745out_result;

  { // Node ID: 1745 (NodeSlice)
    const HWFloat<8,24> &id1745in_a = id2178out_output[getCycle()%4];

    id1745out_result = (slice<15,1>(id1745in_a));
  }
  { // Node ID: 901 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id901in_sel = id1435out_result[getCycle()%2];
    const HWRawBits<1> &id901in_option0 = id900out_value;
    const HWRawBits<1> &id901in_option1 = id1745out_result;

    HWRawBits<1> id901x_1;

    switch((id901in_sel.getValueAsLong())) {
      case 0l:
        id901x_1 = id901in_option0;
        break;
      case 1l:
        id901x_1 = id901in_option1;
        break;
      default:
        id901x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id901out_result[(getCycle()+1)%2] = (id901x_1);
  }
  { // Node ID: 1971 (NodeConstantRawBits)
  }
  { // Node ID: 1437 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1437in_a = id1971out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1437in_b = id806out_result[getCycle()%2];

    id1437out_result[(getCycle()+1)%2] = (lt_fixed(id1437in_a,id1437in_b));
  }
  { // Node ID: 894 (NodeConstantRawBits)
  }
  HWRawBits<1> id1746out_result;

  { // Node ID: 1746 (NodeSlice)
    const HWFloat<8,24> &id1746in_a = id2178out_output[getCycle()%4];

    id1746out_result = (slice<14,1>(id1746in_a));
  }
  { // Node ID: 895 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id895in_sel = id1437out_result[getCycle()%2];
    const HWRawBits<1> &id895in_option0 = id894out_value;
    const HWRawBits<1> &id895in_option1 = id1746out_result;

    HWRawBits<1> id895x_1;

    switch((id895in_sel.getValueAsLong())) {
      case 0l:
        id895x_1 = id895in_option0;
        break;
      case 1l:
        id895x_1 = id895in_option1;
        break;
      default:
        id895x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id895out_result[(getCycle()+1)%2] = (id895x_1);
  }
  { // Node ID: 1970 (NodeConstantRawBits)
  }
  { // Node ID: 1439 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1439in_a = id1970out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1439in_b = id806out_result[getCycle()%2];

    id1439out_result[(getCycle()+1)%2] = (lt_fixed(id1439in_a,id1439in_b));
  }
  { // Node ID: 888 (NodeConstantRawBits)
  }
  HWRawBits<1> id1747out_result;

  { // Node ID: 1747 (NodeSlice)
    const HWFloat<8,24> &id1747in_a = id2178out_output[getCycle()%4];

    id1747out_result = (slice<13,1>(id1747in_a));
  }
  { // Node ID: 889 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id889in_sel = id1439out_result[getCycle()%2];
    const HWRawBits<1> &id889in_option0 = id888out_value;
    const HWRawBits<1> &id889in_option1 = id1747out_result;

    HWRawBits<1> id889x_1;

    switch((id889in_sel.getValueAsLong())) {
      case 0l:
        id889x_1 = id889in_option0;
        break;
      case 1l:
        id889x_1 = id889in_option1;
        break;
      default:
        id889x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id889out_result[(getCycle()+1)%2] = (id889x_1);
  }
  { // Node ID: 1969 (NodeConstantRawBits)
  }
  { // Node ID: 1441 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1441in_a = id1969out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1441in_b = id806out_result[getCycle()%2];

    id1441out_result[(getCycle()+1)%2] = (lt_fixed(id1441in_a,id1441in_b));
  }
  { // Node ID: 882 (NodeConstantRawBits)
  }
  HWRawBits<1> id1748out_result;

  { // Node ID: 1748 (NodeSlice)
    const HWFloat<8,24> &id1748in_a = id2178out_output[getCycle()%4];

    id1748out_result = (slice<12,1>(id1748in_a));
  }
  { // Node ID: 883 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id883in_sel = id1441out_result[getCycle()%2];
    const HWRawBits<1> &id883in_option0 = id882out_value;
    const HWRawBits<1> &id883in_option1 = id1748out_result;

    HWRawBits<1> id883x_1;

    switch((id883in_sel.getValueAsLong())) {
      case 0l:
        id883x_1 = id883in_option0;
        break;
      case 1l:
        id883x_1 = id883in_option1;
        break;
      default:
        id883x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id883out_result[(getCycle()+1)%2] = (id883x_1);
  }
  { // Node ID: 1968 (NodeConstantRawBits)
  }
  { // Node ID: 1443 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1443in_a = id1968out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1443in_b = id806out_result[getCycle()%2];

    id1443out_result[(getCycle()+1)%2] = (lt_fixed(id1443in_a,id1443in_b));
  }
  { // Node ID: 876 (NodeConstantRawBits)
  }
  HWRawBits<1> id1749out_result;

  { // Node ID: 1749 (NodeSlice)
    const HWFloat<8,24> &id1749in_a = id2178out_output[getCycle()%4];

    id1749out_result = (slice<11,1>(id1749in_a));
  }
  { // Node ID: 877 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id877in_sel = id1443out_result[getCycle()%2];
    const HWRawBits<1> &id877in_option0 = id876out_value;
    const HWRawBits<1> &id877in_option1 = id1749out_result;

    HWRawBits<1> id877x_1;

    switch((id877in_sel.getValueAsLong())) {
      case 0l:
        id877x_1 = id877in_option0;
        break;
      case 1l:
        id877x_1 = id877in_option1;
        break;
      default:
        id877x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id877out_result[(getCycle()+1)%2] = (id877x_1);
  }
  { // Node ID: 1967 (NodeConstantRawBits)
  }
  { // Node ID: 1445 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1445in_a = id1967out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1445in_b = id806out_result[getCycle()%2];

    id1445out_result[(getCycle()+1)%2] = (lt_fixed(id1445in_a,id1445in_b));
  }
  { // Node ID: 870 (NodeConstantRawBits)
  }
  HWRawBits<1> id1750out_result;

  { // Node ID: 1750 (NodeSlice)
    const HWFloat<8,24> &id1750in_a = id2178out_output[getCycle()%4];

    id1750out_result = (slice<10,1>(id1750in_a));
  }
  { // Node ID: 871 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id871in_sel = id1445out_result[getCycle()%2];
    const HWRawBits<1> &id871in_option0 = id870out_value;
    const HWRawBits<1> &id871in_option1 = id1750out_result;

    HWRawBits<1> id871x_1;

    switch((id871in_sel.getValueAsLong())) {
      case 0l:
        id871x_1 = id871in_option0;
        break;
      case 1l:
        id871x_1 = id871in_option1;
        break;
      default:
        id871x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id871out_result[(getCycle()+1)%2] = (id871x_1);
  }
  { // Node ID: 1966 (NodeConstantRawBits)
  }
  { // Node ID: 1447 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1447in_a = id1966out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1447in_b = id806out_result[getCycle()%2];

    id1447out_result[(getCycle()+1)%2] = (lt_fixed(id1447in_a,id1447in_b));
  }
  { // Node ID: 864 (NodeConstantRawBits)
  }
  HWRawBits<1> id1751out_result;

  { // Node ID: 1751 (NodeSlice)
    const HWFloat<8,24> &id1751in_a = id2178out_output[getCycle()%4];

    id1751out_result = (slice<9,1>(id1751in_a));
  }
  { // Node ID: 865 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id865in_sel = id1447out_result[getCycle()%2];
    const HWRawBits<1> &id865in_option0 = id864out_value;
    const HWRawBits<1> &id865in_option1 = id1751out_result;

    HWRawBits<1> id865x_1;

    switch((id865in_sel.getValueAsLong())) {
      case 0l:
        id865x_1 = id865in_option0;
        break;
      case 1l:
        id865x_1 = id865in_option1;
        break;
      default:
        id865x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id865out_result[(getCycle()+1)%2] = (id865x_1);
  }
  { // Node ID: 1965 (NodeConstantRawBits)
  }
  { // Node ID: 1449 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1449in_a = id1965out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1449in_b = id806out_result[getCycle()%2];

    id1449out_result[(getCycle()+1)%2] = (lt_fixed(id1449in_a,id1449in_b));
  }
  { // Node ID: 858 (NodeConstantRawBits)
  }
  HWRawBits<1> id1752out_result;

  { // Node ID: 1752 (NodeSlice)
    const HWFloat<8,24> &id1752in_a = id2178out_output[getCycle()%4];

    id1752out_result = (slice<8,1>(id1752in_a));
  }
  { // Node ID: 859 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id859in_sel = id1449out_result[getCycle()%2];
    const HWRawBits<1> &id859in_option0 = id858out_value;
    const HWRawBits<1> &id859in_option1 = id1752out_result;

    HWRawBits<1> id859x_1;

    switch((id859in_sel.getValueAsLong())) {
      case 0l:
        id859x_1 = id859in_option0;
        break;
      case 1l:
        id859x_1 = id859in_option1;
        break;
      default:
        id859x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id859out_result[(getCycle()+1)%2] = (id859x_1);
  }
  { // Node ID: 1964 (NodeConstantRawBits)
  }
  { // Node ID: 1451 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1451in_a = id1964out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1451in_b = id806out_result[getCycle()%2];

    id1451out_result[(getCycle()+1)%2] = (lt_fixed(id1451in_a,id1451in_b));
  }
  { // Node ID: 852 (NodeConstantRawBits)
  }
  HWRawBits<1> id1753out_result;

  { // Node ID: 1753 (NodeSlice)
    const HWFloat<8,24> &id1753in_a = id2178out_output[getCycle()%4];

    id1753out_result = (slice<7,1>(id1753in_a));
  }
  { // Node ID: 853 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id853in_sel = id1451out_result[getCycle()%2];
    const HWRawBits<1> &id853in_option0 = id852out_value;
    const HWRawBits<1> &id853in_option1 = id1753out_result;

    HWRawBits<1> id853x_1;

    switch((id853in_sel.getValueAsLong())) {
      case 0l:
        id853x_1 = id853in_option0;
        break;
      case 1l:
        id853x_1 = id853in_option1;
        break;
      default:
        id853x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id853out_result[(getCycle()+1)%2] = (id853x_1);
  }
  { // Node ID: 1963 (NodeConstantRawBits)
  }
  { // Node ID: 1453 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1453in_a = id1963out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1453in_b = id806out_result[getCycle()%2];

    id1453out_result[(getCycle()+1)%2] = (lt_fixed(id1453in_a,id1453in_b));
  }
  { // Node ID: 846 (NodeConstantRawBits)
  }
  HWRawBits<1> id1754out_result;

  { // Node ID: 1754 (NodeSlice)
    const HWFloat<8,24> &id1754in_a = id2178out_output[getCycle()%4];

    id1754out_result = (slice<6,1>(id1754in_a));
  }
  { // Node ID: 847 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id847in_sel = id1453out_result[getCycle()%2];
    const HWRawBits<1> &id847in_option0 = id846out_value;
    const HWRawBits<1> &id847in_option1 = id1754out_result;

    HWRawBits<1> id847x_1;

    switch((id847in_sel.getValueAsLong())) {
      case 0l:
        id847x_1 = id847in_option0;
        break;
      case 1l:
        id847x_1 = id847in_option1;
        break;
      default:
        id847x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id847out_result[(getCycle()+1)%2] = (id847x_1);
  }
  { // Node ID: 1962 (NodeConstantRawBits)
  }
  { // Node ID: 1455 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1455in_a = id1962out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1455in_b = id806out_result[getCycle()%2];

    id1455out_result[(getCycle()+1)%2] = (lt_fixed(id1455in_a,id1455in_b));
  }
  { // Node ID: 840 (NodeConstantRawBits)
  }
  HWRawBits<1> id1755out_result;

  { // Node ID: 1755 (NodeSlice)
    const HWFloat<8,24> &id1755in_a = id2178out_output[getCycle()%4];

    id1755out_result = (slice<5,1>(id1755in_a));
  }
  { // Node ID: 841 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id841in_sel = id1455out_result[getCycle()%2];
    const HWRawBits<1> &id841in_option0 = id840out_value;
    const HWRawBits<1> &id841in_option1 = id1755out_result;

    HWRawBits<1> id841x_1;

    switch((id841in_sel.getValueAsLong())) {
      case 0l:
        id841x_1 = id841in_option0;
        break;
      case 1l:
        id841x_1 = id841in_option1;
        break;
      default:
        id841x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id841out_result[(getCycle()+1)%2] = (id841x_1);
  }
  { // Node ID: 1961 (NodeConstantRawBits)
  }
  { // Node ID: 1457 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1457in_a = id1961out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1457in_b = id806out_result[getCycle()%2];

    id1457out_result[(getCycle()+1)%2] = (lt_fixed(id1457in_a,id1457in_b));
  }
  { // Node ID: 834 (NodeConstantRawBits)
  }
  HWRawBits<1> id1756out_result;

  { // Node ID: 1756 (NodeSlice)
    const HWFloat<8,24> &id1756in_a = id2178out_output[getCycle()%4];

    id1756out_result = (slice<4,1>(id1756in_a));
  }
  { // Node ID: 835 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id835in_sel = id1457out_result[getCycle()%2];
    const HWRawBits<1> &id835in_option0 = id834out_value;
    const HWRawBits<1> &id835in_option1 = id1756out_result;

    HWRawBits<1> id835x_1;

    switch((id835in_sel.getValueAsLong())) {
      case 0l:
        id835x_1 = id835in_option0;
        break;
      case 1l:
        id835x_1 = id835in_option1;
        break;
      default:
        id835x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id835out_result[(getCycle()+1)%2] = (id835x_1);
  }
  { // Node ID: 1960 (NodeConstantRawBits)
  }
  { // Node ID: 1459 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1459in_a = id1960out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1459in_b = id806out_result[getCycle()%2];

    id1459out_result[(getCycle()+1)%2] = (lt_fixed(id1459in_a,id1459in_b));
  }
  { // Node ID: 828 (NodeConstantRawBits)
  }
  HWRawBits<1> id1757out_result;

  { // Node ID: 1757 (NodeSlice)
    const HWFloat<8,24> &id1757in_a = id2178out_output[getCycle()%4];

    id1757out_result = (slice<3,1>(id1757in_a));
  }
  { // Node ID: 829 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id829in_sel = id1459out_result[getCycle()%2];
    const HWRawBits<1> &id829in_option0 = id828out_value;
    const HWRawBits<1> &id829in_option1 = id1757out_result;

    HWRawBits<1> id829x_1;

    switch((id829in_sel.getValueAsLong())) {
      case 0l:
        id829x_1 = id829in_option0;
        break;
      case 1l:
        id829x_1 = id829in_option1;
        break;
      default:
        id829x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id829out_result[(getCycle()+1)%2] = (id829x_1);
  }
  { // Node ID: 1959 (NodeConstantRawBits)
  }
  { // Node ID: 1461 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1461in_a = id1959out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1461in_b = id806out_result[getCycle()%2];

    id1461out_result[(getCycle()+1)%2] = (lt_fixed(id1461in_a,id1461in_b));
  }
  { // Node ID: 822 (NodeConstantRawBits)
  }
  HWRawBits<1> id1758out_result;

  { // Node ID: 1758 (NodeSlice)
    const HWFloat<8,24> &id1758in_a = id2178out_output[getCycle()%4];

    id1758out_result = (slice<2,1>(id1758in_a));
  }
  { // Node ID: 823 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id823in_sel = id1461out_result[getCycle()%2];
    const HWRawBits<1> &id823in_option0 = id822out_value;
    const HWRawBits<1> &id823in_option1 = id1758out_result;

    HWRawBits<1> id823x_1;

    switch((id823in_sel.getValueAsLong())) {
      case 0l:
        id823x_1 = id823in_option0;
        break;
      case 1l:
        id823x_1 = id823in_option1;
        break;
      default:
        id823x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id823out_result[(getCycle()+1)%2] = (id823x_1);
  }
  { // Node ID: 1958 (NodeConstantRawBits)
  }
  { // Node ID: 1463 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1463in_a = id1958out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1463in_b = id806out_result[getCycle()%2];

    id1463out_result[(getCycle()+1)%2] = (lt_fixed(id1463in_a,id1463in_b));
  }
  { // Node ID: 816 (NodeConstantRawBits)
  }
  HWRawBits<1> id1759out_result;

  { // Node ID: 1759 (NodeSlice)
    const HWFloat<8,24> &id1759in_a = id2178out_output[getCycle()%4];

    id1759out_result = (slice<1,1>(id1759in_a));
  }
  { // Node ID: 817 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id817in_sel = id1463out_result[getCycle()%2];
    const HWRawBits<1> &id817in_option0 = id816out_value;
    const HWRawBits<1> &id817in_option1 = id1759out_result;

    HWRawBits<1> id817x_1;

    switch((id817in_sel.getValueAsLong())) {
      case 0l:
        id817x_1 = id817in_option0;
        break;
      case 1l:
        id817x_1 = id817in_option1;
        break;
      default:
        id817x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id817out_result[(getCycle()+1)%2] = (id817x_1);
  }
  { // Node ID: 1957 (NodeConstantRawBits)
  }
  { // Node ID: 1465 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1465in_a = id1957out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1465in_b = id806out_result[getCycle()%2];

    id1465out_result[(getCycle()+1)%2] = (lt_fixed(id1465in_a,id1465in_b));
  }
  { // Node ID: 810 (NodeConstantRawBits)
  }
  HWRawBits<1> id1760out_result;

  { // Node ID: 1760 (NodeSlice)
    const HWFloat<8,24> &id1760in_a = id2178out_output[getCycle()%4];

    id1760out_result = (slice<0,1>(id1760in_a));
  }
  { // Node ID: 811 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id811in_sel = id1465out_result[getCycle()%2];
    const HWRawBits<1> &id811in_option0 = id810out_value;
    const HWRawBits<1> &id811in_option1 = id1760out_result;

    HWRawBits<1> id811x_1;

    switch((id811in_sel.getValueAsLong())) {
      case 0l:
        id811x_1 = id811in_option0;
        break;
      case 1l:
        id811x_1 = id811in_option1;
        break;
      default:
        id811x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id811out_result[(getCycle()+1)%2] = (id811x_1);
  }
  { // Node ID: 804 (NodeConstantRawBits)
  }
  HWRawBits<24> id1488out_result;

  { // Node ID: 1488 (NodeCat)
    const HWRawBits<1> &id1488in_in0 = id943out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in1 = id937out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in2 = id931out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in3 = id925out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in4 = id919out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in5 = id913out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in6 = id907out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in7 = id901out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in8 = id895out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in9 = id889out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in10 = id883out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in11 = id877out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in12 = id871out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in13 = id865out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in14 = id859out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in15 = id853out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in16 = id847out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in17 = id841out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in18 = id835out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in19 = id829out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in20 = id823out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in21 = id817out_result[getCycle()%2];
    const HWRawBits<1> &id1488in_in22 = id811out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1488in_in23 = id804out_value;

    id1488out_result = (cat((cat((cat((cat((cat(id1488in_in0,id1488in_in1)),id1488in_in2)),(cat((cat(id1488in_in3,id1488in_in4)),id1488in_in5)))),(cat((cat((cat(id1488in_in6,id1488in_in7)),id1488in_in8)),(cat((cat(id1488in_in9,id1488in_in10)),id1488in_in11)))))),(cat((cat((cat((cat(id1488in_in12,id1488in_in13)),id1488in_in14)),(cat((cat(id1488in_in15,id1488in_in16)),id1488in_in17)))),(cat((cat((cat(id1488in_in18,id1488in_in19)),id1488in_in20)),(cat((cat(id1488in_in21,id1488in_in22)),id1488in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id945out_o;

  { // Node ID: 945 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id945in_i = id786out_result[getCycle()%2];

    id945out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id945in_i));
  }
  { // Node ID: 2203 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2203in_input = id945out_o;

    id2203out_output[(getCycle()+3)%4] = id2203in_input;
  }
  { // Node ID: 946 (NodeShift)
    const HWRawBits<24> &id946in_datain = id1488out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id946in_shift = id2203out_output[getCycle()%4];

    id946out_dataout[(getCycle()+4)%5] = (shift_left_bits(id946in_datain,(id946in_shift.getValueAsLong())));
  }
  { // Node ID: 787 (NodeConstantRawBits)
  }
  HWRawBits<23> id788out_result;

  { // Node ID: 788 (NodeSlice)
    const HWFloat<8,24> &id788in_a = id2178out_output[getCycle()%4];

    id788out_result = (slice<0,23>(id788in_a));
  }
  HWRawBits<24> id789out_result;

  { // Node ID: 789 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id789in_in0 = id787out_value;
    const HWRawBits<23> &id789in_in1 = id788out_result;

    id789out_result = (cat(id789in_in0,id789in_in1));
  }
  { // Node ID: 799 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id799in_a = id786out_result[getCycle()%2];

    id799out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id799in_a));
  }
  { // Node ID: 1956 (NodeConstantRawBits)
  }
  { // Node ID: 801 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id801in_a = id799out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id801in_b = id1956out_value;

    id801out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id801in_a,id801in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id802out_o;

  { // Node ID: 802 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id802in_i = id801out_result[getCycle()%2];

    id802out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id802in_i));
  }
  { // Node ID: 803 (NodeShift)
    const HWRawBits<24> &id803in_datain = id789out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id803in_shift = id802out_o;

    id803out_dataout[(getCycle()+4)%5] = (shift_right_bits(id803in_datain,(id803in_shift.getValueAsLong())));
  }
  { // Node ID: 2206 (NodeFIFO)
    const HWRawBits<24> &id2206in_input = id803out_dataout[getCycle()%5];

    id2206out_output[(getCycle()+1)%2] = id2206in_input;
  }
  { // Node ID: 1955 (NodeConstantRawBits)
  }
  { // Node ID: 949 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id949in_sel = id2205out_output[getCycle()%6];
    const HWRawBits<24> &id949in_option0 = id946out_dataout[getCycle()%5];
    const HWRawBits<24> &id949in_option1 = id2206out_output[getCycle()%2];
    const HWRawBits<24> &id949in_option2 = id1955out_value;
    const HWRawBits<24> &id949in_option3 = id1955out_value;

    HWRawBits<24> id949x_1;

    switch((id949in_sel.getValueAsLong())) {
      case 0l:
        id949x_1 = id949in_option0;
        break;
      case 1l:
        id949x_1 = id949in_option1;
        break;
      case 2l:
        id949x_1 = id949in_option2;
        break;
      case 3l:
        id949x_1 = id949in_option3;
        break;
      default:
        id949x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id949out_result[(getCycle()+1)%2] = (id949x_1);
  }
  HWRawBits<24> id950out_result;

  { // Node ID: 950 (NodeNot)
    const HWRawBits<24> &id950in_a = id949out_result[getCycle()%2];

    id950out_result = (not_bits(id950in_a));
  }
  { // Node ID: 951 (NodeMux)
    const HWRawBits<1> &id951in_sel = id2207out_output[getCycle()%7];
    const HWRawBits<24> &id951in_option0 = id949out_result[getCycle()%2];
    const HWRawBits<24> &id951in_option1 = id950out_result;

    HWRawBits<24> id951x_1;

    switch((id951in_sel.getValueAsLong())) {
      case 0l:
        id951x_1 = id951in_option0;
        break;
      case 1l:
        id951x_1 = id951in_option1;
        break;
      default:
        id951x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id951out_result[(getCycle()+1)%2] = (id951x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id952out_output;

  { // Node ID: 952 (NodeReinterpret)
    const HWRawBits<24> &id952in_input = id951out_result[getCycle()%2];

    id952out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id952in_input));
  }
  { // Node ID: 953 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id953in_i = id952out_output;

    id953out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id953in_i));
  }
  { // Node ID: 2025 (NodePO2FPMult)
    const HWFloat<8,24> &id2025in_floatIn = id746out_result[getCycle()%2];

    id2025out_floatOut[(getCycle()+1)%2] = (mul_float(id2025in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2208 (NodeFIFO)
    const HWFloat<8,24> &id2208in_input = id2025out_floatOut[getCycle()%2];

    id2208out_output[(getCycle()+3)%4] = id2208in_input;
  }
  HWRawBits<1> id991out_result;

  { // Node ID: 991 (NodeSlice)
    const HWFloat<8,24> &id991in_a = id2208out_output[getCycle()%4];

    id991out_result = (slice<31,1>(id991in_a));
  }
  { // Node ID: 2237 (NodeFIFO)
    const HWRawBits<1> &id2237in_input = id991out_result;

    id2237out_output[(getCycle()+6)%7] = id2237in_input;
  }
  HWRawBits<8> id984out_result;

  { // Node ID: 984 (NodeSlice)
    const HWFloat<8,24> &id984in_a = id2025out_floatOut[getCycle()%2];

    id984out_result = (slice<23,8>(id984in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id985out_output;

  { // Node ID: 985 (NodeReinterpret)
    const HWRawBits<8> &id985in_input = id984out_result;

    id985out_output = (cast_bits2fixed<8,0,UNSIGNED>(id985in_input));
  }
  { // Node ID: 1953 (NodeConstantRawBits)
  }
  { // Node ID: 987 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id987in_a = id985out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id987in_b = id1953out_value;

    id987out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id987in_a,id987in_b));
  }
  { // Node ID: 1952 (NodeConstantRawBits)
  }
  { // Node ID: 1489 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1489in_a = id987out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1489in_b = id1952out_value;

    id1489out_result[(getCycle()+1)%2] = (gte_fixed(id1489in_a,id1489in_b));
  }
  { // Node ID: 1951 (NodeConstantRawBits)
  }
  { // Node ID: 1490 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1490in_a = id987out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1490in_b = id1951out_value;

    id1490out_result[(getCycle()+1)%2] = (lte_fixed(id1490in_a,id1490in_b));
  }
  { // Node ID: 996 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id996in_a = id1489out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id996in_b = id1490out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id996x_1;

    (id996x_1) = (or_fixed(id996in_a,id996in_b));
    id996out_result[(getCycle()+1)%2] = (id996x_1);
  }
  { // Node ID: 1950 (NodeConstantRawBits)
  }
  { // Node ID: 1491 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1491in_a = id987out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1491in_b = id1950out_value;

    id1491out_result[(getCycle()+1)%2] = (lte_fixed(id1491in_a,id1491in_b));
  }
  { // Node ID: 2209 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2209in_input = id1491out_result[getCycle()%2];

    id2209out_output[(getCycle()+1)%2] = id2209in_input;
  }
  HWRawBits<2> id1148out_result;

  { // Node ID: 1148 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id1148in_in0 = id996out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1148in_in1 = id2209out_output[getCycle()%2];

    id1148out_result = (cat(id1148in_in0,id1148in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id1149out_output;

  { // Node ID: 1149 (NodeReinterpret)
    const HWRawBits<2> &id1149in_input = id1148out_result;

    id1149out_output = (cast_bits2fixed<2,0,UNSIGNED>(id1149in_input));
  }
  { // Node ID: 2235 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2235in_input = id1149out_output;

    id2235out_output[(getCycle()+5)%6] = id2235in_input;
  }
  { // Node ID: 1949 (NodeConstantRawBits)
  }
  { // Node ID: 1948 (NodeConstantRawBits)
  }
  { // Node ID: 1007 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1007in_a = id1948out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1007in_b = id987out_result[getCycle()%2];

    id1007out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1007in_a,id1007in_b));
  }
  { // Node ID: 1492 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1492in_a = id1949out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1492in_b = id1007out_result[getCycle()%2];

    id1492out_result[(getCycle()+1)%2] = (lt_fixed(id1492in_a,id1492in_b));
  }
  { // Node ID: 1143 (NodeConstantRawBits)
  }
  HWRawBits<1> id1761out_result;

  { // Node ID: 1761 (NodeSlice)
    const HWFloat<8,24> &id1761in_a = id2208out_output[getCycle()%4];

    id1761out_result = (slice<22,1>(id1761in_a));
  }
  { // Node ID: 1144 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1144in_sel = id1492out_result[getCycle()%2];
    const HWRawBits<1> &id1144in_option0 = id1143out_value;
    const HWRawBits<1> &id1144in_option1 = id1761out_result;

    HWRawBits<1> id1144x_1;

    switch((id1144in_sel.getValueAsLong())) {
      case 0l:
        id1144x_1 = id1144in_option0;
        break;
      case 1l:
        id1144x_1 = id1144in_option1;
        break;
      default:
        id1144x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1144out_result[(getCycle()+1)%2] = (id1144x_1);
  }
  { // Node ID: 1947 (NodeConstantRawBits)
  }
  { // Node ID: 1494 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1494in_a = id1947out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1494in_b = id1007out_result[getCycle()%2];

    id1494out_result[(getCycle()+1)%2] = (lt_fixed(id1494in_a,id1494in_b));
  }
  { // Node ID: 1137 (NodeConstantRawBits)
  }
  HWRawBits<1> id1762out_result;

  { // Node ID: 1762 (NodeSlice)
    const HWFloat<8,24> &id1762in_a = id2208out_output[getCycle()%4];

    id1762out_result = (slice<21,1>(id1762in_a));
  }
  { // Node ID: 1138 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1138in_sel = id1494out_result[getCycle()%2];
    const HWRawBits<1> &id1138in_option0 = id1137out_value;
    const HWRawBits<1> &id1138in_option1 = id1762out_result;

    HWRawBits<1> id1138x_1;

    switch((id1138in_sel.getValueAsLong())) {
      case 0l:
        id1138x_1 = id1138in_option0;
        break;
      case 1l:
        id1138x_1 = id1138in_option1;
        break;
      default:
        id1138x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1138out_result[(getCycle()+1)%2] = (id1138x_1);
  }
  { // Node ID: 1946 (NodeConstantRawBits)
  }
  { // Node ID: 1496 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1496in_a = id1946out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1496in_b = id1007out_result[getCycle()%2];

    id1496out_result[(getCycle()+1)%2] = (lt_fixed(id1496in_a,id1496in_b));
  }
  { // Node ID: 1131 (NodeConstantRawBits)
  }
  HWRawBits<1> id1763out_result;

  { // Node ID: 1763 (NodeSlice)
    const HWFloat<8,24> &id1763in_a = id2208out_output[getCycle()%4];

    id1763out_result = (slice<20,1>(id1763in_a));
  }
  { // Node ID: 1132 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1132in_sel = id1496out_result[getCycle()%2];
    const HWRawBits<1> &id1132in_option0 = id1131out_value;
    const HWRawBits<1> &id1132in_option1 = id1763out_result;

    HWRawBits<1> id1132x_1;

    switch((id1132in_sel.getValueAsLong())) {
      case 0l:
        id1132x_1 = id1132in_option0;
        break;
      case 1l:
        id1132x_1 = id1132in_option1;
        break;
      default:
        id1132x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1132out_result[(getCycle()+1)%2] = (id1132x_1);
  }
  { // Node ID: 1945 (NodeConstantRawBits)
  }
  { // Node ID: 1498 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1498in_a = id1945out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1498in_b = id1007out_result[getCycle()%2];

    id1498out_result[(getCycle()+1)%2] = (lt_fixed(id1498in_a,id1498in_b));
  }
  { // Node ID: 1125 (NodeConstantRawBits)
  }
  HWRawBits<1> id1764out_result;

  { // Node ID: 1764 (NodeSlice)
    const HWFloat<8,24> &id1764in_a = id2208out_output[getCycle()%4];

    id1764out_result = (slice<19,1>(id1764in_a));
  }
  { // Node ID: 1126 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1126in_sel = id1498out_result[getCycle()%2];
    const HWRawBits<1> &id1126in_option0 = id1125out_value;
    const HWRawBits<1> &id1126in_option1 = id1764out_result;

    HWRawBits<1> id1126x_1;

    switch((id1126in_sel.getValueAsLong())) {
      case 0l:
        id1126x_1 = id1126in_option0;
        break;
      case 1l:
        id1126x_1 = id1126in_option1;
        break;
      default:
        id1126x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1126out_result[(getCycle()+1)%2] = (id1126x_1);
  }
  { // Node ID: 1944 (NodeConstantRawBits)
  }
  { // Node ID: 1500 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1500in_a = id1944out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1500in_b = id1007out_result[getCycle()%2];

    id1500out_result[(getCycle()+1)%2] = (lt_fixed(id1500in_a,id1500in_b));
  }
  { // Node ID: 1119 (NodeConstantRawBits)
  }
  HWRawBits<1> id1765out_result;

  { // Node ID: 1765 (NodeSlice)
    const HWFloat<8,24> &id1765in_a = id2208out_output[getCycle()%4];

    id1765out_result = (slice<18,1>(id1765in_a));
  }
  { // Node ID: 1120 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1120in_sel = id1500out_result[getCycle()%2];
    const HWRawBits<1> &id1120in_option0 = id1119out_value;
    const HWRawBits<1> &id1120in_option1 = id1765out_result;

    HWRawBits<1> id1120x_1;

    switch((id1120in_sel.getValueAsLong())) {
      case 0l:
        id1120x_1 = id1120in_option0;
        break;
      case 1l:
        id1120x_1 = id1120in_option1;
        break;
      default:
        id1120x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1120out_result[(getCycle()+1)%2] = (id1120x_1);
  }
  { // Node ID: 1943 (NodeConstantRawBits)
  }
  { // Node ID: 1502 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1502in_a = id1943out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1502in_b = id1007out_result[getCycle()%2];

    id1502out_result[(getCycle()+1)%2] = (lt_fixed(id1502in_a,id1502in_b));
  }
  { // Node ID: 1113 (NodeConstantRawBits)
  }
  HWRawBits<1> id1766out_result;

  { // Node ID: 1766 (NodeSlice)
    const HWFloat<8,24> &id1766in_a = id2208out_output[getCycle()%4];

    id1766out_result = (slice<17,1>(id1766in_a));
  }
  { // Node ID: 1114 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1114in_sel = id1502out_result[getCycle()%2];
    const HWRawBits<1> &id1114in_option0 = id1113out_value;
    const HWRawBits<1> &id1114in_option1 = id1766out_result;

    HWRawBits<1> id1114x_1;

    switch((id1114in_sel.getValueAsLong())) {
      case 0l:
        id1114x_1 = id1114in_option0;
        break;
      case 1l:
        id1114x_1 = id1114in_option1;
        break;
      default:
        id1114x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1114out_result[(getCycle()+1)%2] = (id1114x_1);
  }
  { // Node ID: 1942 (NodeConstantRawBits)
  }
  { // Node ID: 1504 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1504in_a = id1942out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1504in_b = id1007out_result[getCycle()%2];

    id1504out_result[(getCycle()+1)%2] = (lt_fixed(id1504in_a,id1504in_b));
  }
  { // Node ID: 1107 (NodeConstantRawBits)
  }
  HWRawBits<1> id1767out_result;

  { // Node ID: 1767 (NodeSlice)
    const HWFloat<8,24> &id1767in_a = id2208out_output[getCycle()%4];

    id1767out_result = (slice<16,1>(id1767in_a));
  }
  { // Node ID: 1108 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1108in_sel = id1504out_result[getCycle()%2];
    const HWRawBits<1> &id1108in_option0 = id1107out_value;
    const HWRawBits<1> &id1108in_option1 = id1767out_result;

    HWRawBits<1> id1108x_1;

    switch((id1108in_sel.getValueAsLong())) {
      case 0l:
        id1108x_1 = id1108in_option0;
        break;
      case 1l:
        id1108x_1 = id1108in_option1;
        break;
      default:
        id1108x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1108out_result[(getCycle()+1)%2] = (id1108x_1);
  }
  { // Node ID: 1941 (NodeConstantRawBits)
  }
  { // Node ID: 1506 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1506in_a = id1941out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1506in_b = id1007out_result[getCycle()%2];

    id1506out_result[(getCycle()+1)%2] = (lt_fixed(id1506in_a,id1506in_b));
  }
  { // Node ID: 1101 (NodeConstantRawBits)
  }
  HWRawBits<1> id1768out_result;

  { // Node ID: 1768 (NodeSlice)
    const HWFloat<8,24> &id1768in_a = id2208out_output[getCycle()%4];

    id1768out_result = (slice<15,1>(id1768in_a));
  }
  { // Node ID: 1102 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1102in_sel = id1506out_result[getCycle()%2];
    const HWRawBits<1> &id1102in_option0 = id1101out_value;
    const HWRawBits<1> &id1102in_option1 = id1768out_result;

    HWRawBits<1> id1102x_1;

    switch((id1102in_sel.getValueAsLong())) {
      case 0l:
        id1102x_1 = id1102in_option0;
        break;
      case 1l:
        id1102x_1 = id1102in_option1;
        break;
      default:
        id1102x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1102out_result[(getCycle()+1)%2] = (id1102x_1);
  }
  { // Node ID: 1940 (NodeConstantRawBits)
  }
  { // Node ID: 1508 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1508in_a = id1940out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1508in_b = id1007out_result[getCycle()%2];

    id1508out_result[(getCycle()+1)%2] = (lt_fixed(id1508in_a,id1508in_b));
  }
  { // Node ID: 1095 (NodeConstantRawBits)
  }
  HWRawBits<1> id1769out_result;

  { // Node ID: 1769 (NodeSlice)
    const HWFloat<8,24> &id1769in_a = id2208out_output[getCycle()%4];

    id1769out_result = (slice<14,1>(id1769in_a));
  }
  { // Node ID: 1096 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1096in_sel = id1508out_result[getCycle()%2];
    const HWRawBits<1> &id1096in_option0 = id1095out_value;
    const HWRawBits<1> &id1096in_option1 = id1769out_result;

    HWRawBits<1> id1096x_1;

    switch((id1096in_sel.getValueAsLong())) {
      case 0l:
        id1096x_1 = id1096in_option0;
        break;
      case 1l:
        id1096x_1 = id1096in_option1;
        break;
      default:
        id1096x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1096out_result[(getCycle()+1)%2] = (id1096x_1);
  }
  { // Node ID: 1939 (NodeConstantRawBits)
  }
  { // Node ID: 1510 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1510in_a = id1939out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1510in_b = id1007out_result[getCycle()%2];

    id1510out_result[(getCycle()+1)%2] = (lt_fixed(id1510in_a,id1510in_b));
  }
  { // Node ID: 1089 (NodeConstantRawBits)
  }
  HWRawBits<1> id1770out_result;

  { // Node ID: 1770 (NodeSlice)
    const HWFloat<8,24> &id1770in_a = id2208out_output[getCycle()%4];

    id1770out_result = (slice<13,1>(id1770in_a));
  }
  { // Node ID: 1090 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1090in_sel = id1510out_result[getCycle()%2];
    const HWRawBits<1> &id1090in_option0 = id1089out_value;
    const HWRawBits<1> &id1090in_option1 = id1770out_result;

    HWRawBits<1> id1090x_1;

    switch((id1090in_sel.getValueAsLong())) {
      case 0l:
        id1090x_1 = id1090in_option0;
        break;
      case 1l:
        id1090x_1 = id1090in_option1;
        break;
      default:
        id1090x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1090out_result[(getCycle()+1)%2] = (id1090x_1);
  }
  { // Node ID: 1938 (NodeConstantRawBits)
  }
  { // Node ID: 1512 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1512in_a = id1938out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1512in_b = id1007out_result[getCycle()%2];

    id1512out_result[(getCycle()+1)%2] = (lt_fixed(id1512in_a,id1512in_b));
  }
  { // Node ID: 1083 (NodeConstantRawBits)
  }
  HWRawBits<1> id1771out_result;

  { // Node ID: 1771 (NodeSlice)
    const HWFloat<8,24> &id1771in_a = id2208out_output[getCycle()%4];

    id1771out_result = (slice<12,1>(id1771in_a));
  }
  { // Node ID: 1084 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1084in_sel = id1512out_result[getCycle()%2];
    const HWRawBits<1> &id1084in_option0 = id1083out_value;
    const HWRawBits<1> &id1084in_option1 = id1771out_result;

    HWRawBits<1> id1084x_1;

    switch((id1084in_sel.getValueAsLong())) {
      case 0l:
        id1084x_1 = id1084in_option0;
        break;
      case 1l:
        id1084x_1 = id1084in_option1;
        break;
      default:
        id1084x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1084out_result[(getCycle()+1)%2] = (id1084x_1);
  }
  { // Node ID: 1937 (NodeConstantRawBits)
  }
  { // Node ID: 1514 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1514in_a = id1937out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1514in_b = id1007out_result[getCycle()%2];

    id1514out_result[(getCycle()+1)%2] = (lt_fixed(id1514in_a,id1514in_b));
  }
  { // Node ID: 1077 (NodeConstantRawBits)
  }
  HWRawBits<1> id1772out_result;

  { // Node ID: 1772 (NodeSlice)
    const HWFloat<8,24> &id1772in_a = id2208out_output[getCycle()%4];

    id1772out_result = (slice<11,1>(id1772in_a));
  }
  { // Node ID: 1078 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1078in_sel = id1514out_result[getCycle()%2];
    const HWRawBits<1> &id1078in_option0 = id1077out_value;
    const HWRawBits<1> &id1078in_option1 = id1772out_result;

    HWRawBits<1> id1078x_1;

    switch((id1078in_sel.getValueAsLong())) {
      case 0l:
        id1078x_1 = id1078in_option0;
        break;
      case 1l:
        id1078x_1 = id1078in_option1;
        break;
      default:
        id1078x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1078out_result[(getCycle()+1)%2] = (id1078x_1);
  }
  { // Node ID: 1936 (NodeConstantRawBits)
  }
  { // Node ID: 1516 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1516in_a = id1936out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1516in_b = id1007out_result[getCycle()%2];

    id1516out_result[(getCycle()+1)%2] = (lt_fixed(id1516in_a,id1516in_b));
  }
  { // Node ID: 1071 (NodeConstantRawBits)
  }
  HWRawBits<1> id1773out_result;

  { // Node ID: 1773 (NodeSlice)
    const HWFloat<8,24> &id1773in_a = id2208out_output[getCycle()%4];

    id1773out_result = (slice<10,1>(id1773in_a));
  }
  { // Node ID: 1072 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1072in_sel = id1516out_result[getCycle()%2];
    const HWRawBits<1> &id1072in_option0 = id1071out_value;
    const HWRawBits<1> &id1072in_option1 = id1773out_result;

    HWRawBits<1> id1072x_1;

    switch((id1072in_sel.getValueAsLong())) {
      case 0l:
        id1072x_1 = id1072in_option0;
        break;
      case 1l:
        id1072x_1 = id1072in_option1;
        break;
      default:
        id1072x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1072out_result[(getCycle()+1)%2] = (id1072x_1);
  }
  { // Node ID: 1935 (NodeConstantRawBits)
  }
  { // Node ID: 1518 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1518in_a = id1935out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1518in_b = id1007out_result[getCycle()%2];

    id1518out_result[(getCycle()+1)%2] = (lt_fixed(id1518in_a,id1518in_b));
  }
  { // Node ID: 1065 (NodeConstantRawBits)
  }
  HWRawBits<1> id1774out_result;

  { // Node ID: 1774 (NodeSlice)
    const HWFloat<8,24> &id1774in_a = id2208out_output[getCycle()%4];

    id1774out_result = (slice<9,1>(id1774in_a));
  }
  { // Node ID: 1066 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1066in_sel = id1518out_result[getCycle()%2];
    const HWRawBits<1> &id1066in_option0 = id1065out_value;
    const HWRawBits<1> &id1066in_option1 = id1774out_result;

    HWRawBits<1> id1066x_1;

    switch((id1066in_sel.getValueAsLong())) {
      case 0l:
        id1066x_1 = id1066in_option0;
        break;
      case 1l:
        id1066x_1 = id1066in_option1;
        break;
      default:
        id1066x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1066out_result[(getCycle()+1)%2] = (id1066x_1);
  }
  { // Node ID: 1934 (NodeConstantRawBits)
  }
  { // Node ID: 1520 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1520in_a = id1934out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1520in_b = id1007out_result[getCycle()%2];

    id1520out_result[(getCycle()+1)%2] = (lt_fixed(id1520in_a,id1520in_b));
  }
  { // Node ID: 1059 (NodeConstantRawBits)
  }
  HWRawBits<1> id1775out_result;

  { // Node ID: 1775 (NodeSlice)
    const HWFloat<8,24> &id1775in_a = id2208out_output[getCycle()%4];

    id1775out_result = (slice<8,1>(id1775in_a));
  }
  { // Node ID: 1060 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1060in_sel = id1520out_result[getCycle()%2];
    const HWRawBits<1> &id1060in_option0 = id1059out_value;
    const HWRawBits<1> &id1060in_option1 = id1775out_result;

    HWRawBits<1> id1060x_1;

    switch((id1060in_sel.getValueAsLong())) {
      case 0l:
        id1060x_1 = id1060in_option0;
        break;
      case 1l:
        id1060x_1 = id1060in_option1;
        break;
      default:
        id1060x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1060out_result[(getCycle()+1)%2] = (id1060x_1);
  }
  { // Node ID: 1933 (NodeConstantRawBits)
  }
  { // Node ID: 1522 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1522in_a = id1933out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1522in_b = id1007out_result[getCycle()%2];

    id1522out_result[(getCycle()+1)%2] = (lt_fixed(id1522in_a,id1522in_b));
  }
  { // Node ID: 1053 (NodeConstantRawBits)
  }
  HWRawBits<1> id1776out_result;

  { // Node ID: 1776 (NodeSlice)
    const HWFloat<8,24> &id1776in_a = id2208out_output[getCycle()%4];

    id1776out_result = (slice<7,1>(id1776in_a));
  }
  { // Node ID: 1054 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1054in_sel = id1522out_result[getCycle()%2];
    const HWRawBits<1> &id1054in_option0 = id1053out_value;
    const HWRawBits<1> &id1054in_option1 = id1776out_result;

    HWRawBits<1> id1054x_1;

    switch((id1054in_sel.getValueAsLong())) {
      case 0l:
        id1054x_1 = id1054in_option0;
        break;
      case 1l:
        id1054x_1 = id1054in_option1;
        break;
      default:
        id1054x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1054out_result[(getCycle()+1)%2] = (id1054x_1);
  }
  { // Node ID: 1932 (NodeConstantRawBits)
  }
  { // Node ID: 1524 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1524in_a = id1932out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1524in_b = id1007out_result[getCycle()%2];

    id1524out_result[(getCycle()+1)%2] = (lt_fixed(id1524in_a,id1524in_b));
  }
  { // Node ID: 1047 (NodeConstantRawBits)
  }
  HWRawBits<1> id1777out_result;

  { // Node ID: 1777 (NodeSlice)
    const HWFloat<8,24> &id1777in_a = id2208out_output[getCycle()%4];

    id1777out_result = (slice<6,1>(id1777in_a));
  }
  { // Node ID: 1048 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1048in_sel = id1524out_result[getCycle()%2];
    const HWRawBits<1> &id1048in_option0 = id1047out_value;
    const HWRawBits<1> &id1048in_option1 = id1777out_result;

    HWRawBits<1> id1048x_1;

    switch((id1048in_sel.getValueAsLong())) {
      case 0l:
        id1048x_1 = id1048in_option0;
        break;
      case 1l:
        id1048x_1 = id1048in_option1;
        break;
      default:
        id1048x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1048out_result[(getCycle()+1)%2] = (id1048x_1);
  }
  { // Node ID: 1931 (NodeConstantRawBits)
  }
  { // Node ID: 1526 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1526in_a = id1931out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1526in_b = id1007out_result[getCycle()%2];

    id1526out_result[(getCycle()+1)%2] = (lt_fixed(id1526in_a,id1526in_b));
  }
  { // Node ID: 1041 (NodeConstantRawBits)
  }
  HWRawBits<1> id1778out_result;

  { // Node ID: 1778 (NodeSlice)
    const HWFloat<8,24> &id1778in_a = id2208out_output[getCycle()%4];

    id1778out_result = (slice<5,1>(id1778in_a));
  }
  { // Node ID: 1042 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1042in_sel = id1526out_result[getCycle()%2];
    const HWRawBits<1> &id1042in_option0 = id1041out_value;
    const HWRawBits<1> &id1042in_option1 = id1778out_result;

    HWRawBits<1> id1042x_1;

    switch((id1042in_sel.getValueAsLong())) {
      case 0l:
        id1042x_1 = id1042in_option0;
        break;
      case 1l:
        id1042x_1 = id1042in_option1;
        break;
      default:
        id1042x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1042out_result[(getCycle()+1)%2] = (id1042x_1);
  }
  { // Node ID: 1930 (NodeConstantRawBits)
  }
  { // Node ID: 1528 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1528in_a = id1930out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1528in_b = id1007out_result[getCycle()%2];

    id1528out_result[(getCycle()+1)%2] = (lt_fixed(id1528in_a,id1528in_b));
  }
  { // Node ID: 1035 (NodeConstantRawBits)
  }
  HWRawBits<1> id1779out_result;

  { // Node ID: 1779 (NodeSlice)
    const HWFloat<8,24> &id1779in_a = id2208out_output[getCycle()%4];

    id1779out_result = (slice<4,1>(id1779in_a));
  }
  { // Node ID: 1036 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1036in_sel = id1528out_result[getCycle()%2];
    const HWRawBits<1> &id1036in_option0 = id1035out_value;
    const HWRawBits<1> &id1036in_option1 = id1779out_result;

    HWRawBits<1> id1036x_1;

    switch((id1036in_sel.getValueAsLong())) {
      case 0l:
        id1036x_1 = id1036in_option0;
        break;
      case 1l:
        id1036x_1 = id1036in_option1;
        break;
      default:
        id1036x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1036out_result[(getCycle()+1)%2] = (id1036x_1);
  }
  { // Node ID: 1929 (NodeConstantRawBits)
  }
  { // Node ID: 1530 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1530in_a = id1929out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1530in_b = id1007out_result[getCycle()%2];

    id1530out_result[(getCycle()+1)%2] = (lt_fixed(id1530in_a,id1530in_b));
  }
  { // Node ID: 1029 (NodeConstantRawBits)
  }
  HWRawBits<1> id1780out_result;

  { // Node ID: 1780 (NodeSlice)
    const HWFloat<8,24> &id1780in_a = id2208out_output[getCycle()%4];

    id1780out_result = (slice<3,1>(id1780in_a));
  }
  { // Node ID: 1030 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1030in_sel = id1530out_result[getCycle()%2];
    const HWRawBits<1> &id1030in_option0 = id1029out_value;
    const HWRawBits<1> &id1030in_option1 = id1780out_result;

    HWRawBits<1> id1030x_1;

    switch((id1030in_sel.getValueAsLong())) {
      case 0l:
        id1030x_1 = id1030in_option0;
        break;
      case 1l:
        id1030x_1 = id1030in_option1;
        break;
      default:
        id1030x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1030out_result[(getCycle()+1)%2] = (id1030x_1);
  }
  { // Node ID: 1928 (NodeConstantRawBits)
  }
  { // Node ID: 1532 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1532in_a = id1928out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1532in_b = id1007out_result[getCycle()%2];

    id1532out_result[(getCycle()+1)%2] = (lt_fixed(id1532in_a,id1532in_b));
  }
  { // Node ID: 1023 (NodeConstantRawBits)
  }
  HWRawBits<1> id1781out_result;

  { // Node ID: 1781 (NodeSlice)
    const HWFloat<8,24> &id1781in_a = id2208out_output[getCycle()%4];

    id1781out_result = (slice<2,1>(id1781in_a));
  }
  { // Node ID: 1024 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1024in_sel = id1532out_result[getCycle()%2];
    const HWRawBits<1> &id1024in_option0 = id1023out_value;
    const HWRawBits<1> &id1024in_option1 = id1781out_result;

    HWRawBits<1> id1024x_1;

    switch((id1024in_sel.getValueAsLong())) {
      case 0l:
        id1024x_1 = id1024in_option0;
        break;
      case 1l:
        id1024x_1 = id1024in_option1;
        break;
      default:
        id1024x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1024out_result[(getCycle()+1)%2] = (id1024x_1);
  }
  { // Node ID: 1927 (NodeConstantRawBits)
  }
  { // Node ID: 1534 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1534in_a = id1927out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1534in_b = id1007out_result[getCycle()%2];

    id1534out_result[(getCycle()+1)%2] = (lt_fixed(id1534in_a,id1534in_b));
  }
  { // Node ID: 1017 (NodeConstantRawBits)
  }
  HWRawBits<1> id1782out_result;

  { // Node ID: 1782 (NodeSlice)
    const HWFloat<8,24> &id1782in_a = id2208out_output[getCycle()%4];

    id1782out_result = (slice<1,1>(id1782in_a));
  }
  { // Node ID: 1018 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1018in_sel = id1534out_result[getCycle()%2];
    const HWRawBits<1> &id1018in_option0 = id1017out_value;
    const HWRawBits<1> &id1018in_option1 = id1782out_result;

    HWRawBits<1> id1018x_1;

    switch((id1018in_sel.getValueAsLong())) {
      case 0l:
        id1018x_1 = id1018in_option0;
        break;
      case 1l:
        id1018x_1 = id1018in_option1;
        break;
      default:
        id1018x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1018out_result[(getCycle()+1)%2] = (id1018x_1);
  }
  { // Node ID: 1926 (NodeConstantRawBits)
  }
  { // Node ID: 1536 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1536in_a = id1926out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1536in_b = id1007out_result[getCycle()%2];

    id1536out_result[(getCycle()+1)%2] = (lt_fixed(id1536in_a,id1536in_b));
  }
  { // Node ID: 1011 (NodeConstantRawBits)
  }
  HWRawBits<1> id1783out_result;

  { // Node ID: 1783 (NodeSlice)
    const HWFloat<8,24> &id1783in_a = id2208out_output[getCycle()%4];

    id1783out_result = (slice<0,1>(id1783in_a));
  }
  { // Node ID: 1012 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1012in_sel = id1536out_result[getCycle()%2];
    const HWRawBits<1> &id1012in_option0 = id1011out_value;
    const HWRawBits<1> &id1012in_option1 = id1783out_result;

    HWRawBits<1> id1012x_1;

    switch((id1012in_sel.getValueAsLong())) {
      case 0l:
        id1012x_1 = id1012in_option0;
        break;
      case 1l:
        id1012x_1 = id1012in_option1;
        break;
      default:
        id1012x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1012out_result[(getCycle()+1)%2] = (id1012x_1);
  }
  { // Node ID: 1005 (NodeConstantRawBits)
  }
  HWRawBits<24> id1559out_result;

  { // Node ID: 1559 (NodeCat)
    const HWRawBits<1> &id1559in_in0 = id1144out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in1 = id1138out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in2 = id1132out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in3 = id1126out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in4 = id1120out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in5 = id1114out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in6 = id1108out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in7 = id1102out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in8 = id1096out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in9 = id1090out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in10 = id1084out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in11 = id1078out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in12 = id1072out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in13 = id1066out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in14 = id1060out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in15 = id1054out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in16 = id1048out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in17 = id1042out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in18 = id1036out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in19 = id1030out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in20 = id1024out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in21 = id1018out_result[getCycle()%2];
    const HWRawBits<1> &id1559in_in22 = id1012out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1559in_in23 = id1005out_value;

    id1559out_result = (cat((cat((cat((cat((cat(id1559in_in0,id1559in_in1)),id1559in_in2)),(cat((cat(id1559in_in3,id1559in_in4)),id1559in_in5)))),(cat((cat((cat(id1559in_in6,id1559in_in7)),id1559in_in8)),(cat((cat(id1559in_in9,id1559in_in10)),id1559in_in11)))))),(cat((cat((cat((cat(id1559in_in12,id1559in_in13)),id1559in_in14)),(cat((cat(id1559in_in15,id1559in_in16)),id1559in_in17)))),(cat((cat((cat(id1559in_in18,id1559in_in19)),id1559in_in20)),(cat((cat(id1559in_in21,id1559in_in22)),id1559in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id1146out_o;

  { // Node ID: 1146 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1146in_i = id987out_result[getCycle()%2];

    id1146out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id1146in_i));
  }
  { // Node ID: 2233 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2233in_input = id1146out_o;

    id2233out_output[(getCycle()+3)%4] = id2233in_input;
  }
  { // Node ID: 1147 (NodeShift)
    const HWRawBits<24> &id1147in_datain = id1559out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id1147in_shift = id2233out_output[getCycle()%4];

    id1147out_dataout[(getCycle()+4)%5] = (shift_left_bits(id1147in_datain,(id1147in_shift.getValueAsLong())));
  }
  { // Node ID: 988 (NodeConstantRawBits)
  }
  HWRawBits<23> id989out_result;

  { // Node ID: 989 (NodeSlice)
    const HWFloat<8,24> &id989in_a = id2208out_output[getCycle()%4];

    id989out_result = (slice<0,23>(id989in_a));
  }
  HWRawBits<24> id990out_result;

  { // Node ID: 990 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id990in_in0 = id988out_value;
    const HWRawBits<23> &id990in_in1 = id989out_result;

    id990out_result = (cat(id990in_in0,id990in_in1));
  }
  { // Node ID: 1000 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1000in_a = id987out_result[getCycle()%2];

    id1000out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1000in_a));
  }
  { // Node ID: 1925 (NodeConstantRawBits)
  }
  { // Node ID: 1002 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1002in_a = id1000out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1002in_b = id1925out_value;

    id1002out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1002in_a,id1002in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id1003out_o;

  { // Node ID: 1003 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1003in_i = id1002out_result[getCycle()%2];

    id1003out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id1003in_i));
  }
  { // Node ID: 1004 (NodeShift)
    const HWRawBits<24> &id1004in_datain = id990out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id1004in_shift = id1003out_o;

    id1004out_dataout[(getCycle()+4)%5] = (shift_right_bits(id1004in_datain,(id1004in_shift.getValueAsLong())));
  }
  { // Node ID: 2236 (NodeFIFO)
    const HWRawBits<24> &id2236in_input = id1004out_dataout[getCycle()%5];

    id2236out_output[(getCycle()+1)%2] = id2236in_input;
  }
  { // Node ID: 1924 (NodeConstantRawBits)
  }
  { // Node ID: 1150 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id1150in_sel = id2235out_output[getCycle()%6];
    const HWRawBits<24> &id1150in_option0 = id1147out_dataout[getCycle()%5];
    const HWRawBits<24> &id1150in_option1 = id2236out_output[getCycle()%2];
    const HWRawBits<24> &id1150in_option2 = id1924out_value;
    const HWRawBits<24> &id1150in_option3 = id1924out_value;

    HWRawBits<24> id1150x_1;

    switch((id1150in_sel.getValueAsLong())) {
      case 0l:
        id1150x_1 = id1150in_option0;
        break;
      case 1l:
        id1150x_1 = id1150in_option1;
        break;
      case 2l:
        id1150x_1 = id1150in_option2;
        break;
      case 3l:
        id1150x_1 = id1150in_option3;
        break;
      default:
        id1150x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id1150out_result[(getCycle()+1)%2] = (id1150x_1);
  }
  HWRawBits<24> id1151out_result;

  { // Node ID: 1151 (NodeNot)
    const HWRawBits<24> &id1151in_a = id1150out_result[getCycle()%2];

    id1151out_result = (not_bits(id1151in_a));
  }
  { // Node ID: 1152 (NodeMux)
    const HWRawBits<1> &id1152in_sel = id2237out_output[getCycle()%7];
    const HWRawBits<24> &id1152in_option0 = id1150out_result[getCycle()%2];
    const HWRawBits<24> &id1152in_option1 = id1151out_result;

    HWRawBits<24> id1152x_1;

    switch((id1152in_sel.getValueAsLong())) {
      case 0l:
        id1152x_1 = id1152in_option0;
        break;
      case 1l:
        id1152x_1 = id1152in_option1;
        break;
      default:
        id1152x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id1152out_result[(getCycle()+1)%2] = (id1152x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id1153out_output;

  { // Node ID: 1153 (NodeReinterpret)
    const HWRawBits<24> &id1153in_input = id1152out_result[getCycle()%2];

    id1153out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id1153in_input));
  }
  { // Node ID: 1154 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id1154in_i = id1153out_output;

    id1154out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id1154in_i));
  }
  { // Node ID: 1155 (NodeMux)
    const HWRawBits<1> &id1155in_sel = id2177out_output[getCycle()%28];
    const HWFloat<8,24> &id1155in_option0 = id953out_o[getCycle()%8];
    const HWFloat<8,24> &id1155in_option1 = id1154out_o[getCycle()%8];

    HWFloat<8,24> id1155x_1;

    switch((id1155in_sel.getValueAsLong())) {
      case 0l:
        id1155x_1 = id1155in_option0;
        break;
      case 1l:
        id1155x_1 = id1155in_option1;
        break;
      default:
        id1155x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1155out_result[(getCycle()+1)%2] = (id1155x_1);
  }
  { // Node ID: 1161 (NodeMul)
    const HWFloat<8,24> &id1161in_a = id1159out_result[getCycle()%2];
    const HWFloat<8,24> &id1161in_b = id1155out_result[getCycle()%2];

    id1161out_result[(getCycle()+8)%9] = (mul_float(id1161in_a,id1161in_b));
  }
  { // Node ID: 1160 (NodeMul)
    const HWFloat<8,24> &id1160in_a = id1155out_result[getCycle()%2];
    const HWFloat<8,24> &id1160in_b = id1155out_result[getCycle()%2];

    id1160out_result[(getCycle()+8)%9] = (mul_float(id1160in_a,id1160in_b));
  }
  { // Node ID: 1162 (NodeMul)
    const HWFloat<8,24> &id1162in_a = id1161out_result[getCycle()%9];
    const HWFloat<8,24> &id1162in_b = id1160out_result[getCycle()%9];

    id1162out_result[(getCycle()+8)%9] = (mul_float(id1162in_a,id1162in_b));
  }
  HWRawBits<32> id1334out_result;

  { // Node ID: 1334 (NodeSlice)
    const HWRawBits<128> &id1334in_a = id1329out_dout[getCycle()%3];

    id1334out_result = (slice<64,32>(id1334in_a));
  }
  HWFloat<8,24> id1335out_output;

  { // Node ID: 1335 (NodeReinterpret)
    const HWRawBits<32> &id1335in_input = id1334out_result;

    id1335out_output = (cast_bits2float<8,24>(id1335in_input));
  }
  HWRawBits<32> id1343out_result;

  { // Node ID: 1343 (NodeSlice)
    const HWRawBits<128> &id1343in_a = id1338out_dout[getCycle()%3];

    id1343out_result = (slice<64,32>(id1343in_a));
  }
  HWFloat<8,24> id1344out_output;

  { // Node ID: 1344 (NodeReinterpret)
    const HWRawBits<32> &id1344in_input = id1343out_result;

    id1344out_output = (cast_bits2float<8,24>(id1344in_input));
  }
  { // Node ID: 1158 (NodeMux)
    const HWRawBits<1> &id1158in_sel = id2177out_output[getCycle()%28];
    const HWFloat<8,24> &id1158in_option0 = id1335out_output;
    const HWFloat<8,24> &id1158in_option1 = id1344out_output;

    HWFloat<8,24> id1158x_1;

    switch((id1158in_sel.getValueAsLong())) {
      case 0l:
        id1158x_1 = id1158in_option0;
        break;
      case 1l:
        id1158x_1 = id1158in_option1;
        break;
      default:
        id1158x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1158out_result[(getCycle()+1)%2] = (id1158x_1);
  }
  { // Node ID: 2240 (NodeFIFO)
    const HWFloat<8,24> &id2240in_input = id1158out_result[getCycle()%2];

    id2240out_output[(getCycle()+8)%9] = id2240in_input;
  }
  { // Node ID: 1163 (NodeMul)
    const HWFloat<8,24> &id1163in_a = id2240out_output[getCycle()%9];
    const HWFloat<8,24> &id1163in_b = id1160out_result[getCycle()%9];

    id1163out_result[(getCycle()+8)%9] = (mul_float(id1163in_a,id1163in_b));
  }
  { // Node ID: 1164 (NodeAdd)
    const HWFloat<8,24> &id1164in_a = id1162out_result[getCycle()%9];
    const HWFloat<8,24> &id1164in_b = id1163out_result[getCycle()%9];

    id1164out_result[(getCycle()+11)%12] = (add_float(id1164in_a,id1164in_b));
  }
  HWRawBits<32> id1332out_result;

  { // Node ID: 1332 (NodeSlice)
    const HWRawBits<128> &id1332in_a = id1329out_dout[getCycle()%3];

    id1332out_result = (slice<32,32>(id1332in_a));
  }
  HWFloat<8,24> id1333out_output;

  { // Node ID: 1333 (NodeReinterpret)
    const HWRawBits<32> &id1333in_input = id1332out_result;

    id1333out_output = (cast_bits2float<8,24>(id1333in_input));
  }
  HWRawBits<32> id1341out_result;

  { // Node ID: 1341 (NodeSlice)
    const HWRawBits<128> &id1341in_a = id1338out_dout[getCycle()%3];

    id1341out_result = (slice<32,32>(id1341in_a));
  }
  HWFloat<8,24> id1342out_output;

  { // Node ID: 1342 (NodeReinterpret)
    const HWRawBits<32> &id1342in_input = id1341out_result;

    id1342out_output = (cast_bits2float<8,24>(id1342in_input));
  }
  { // Node ID: 1157 (NodeMux)
    const HWRawBits<1> &id1157in_sel = id2177out_output[getCycle()%28];
    const HWFloat<8,24> &id1157in_option0 = id1333out_output;
    const HWFloat<8,24> &id1157in_option1 = id1342out_output;

    HWFloat<8,24> id1157x_1;

    switch((id1157in_sel.getValueAsLong())) {
      case 0l:
        id1157x_1 = id1157in_option0;
        break;
      case 1l:
        id1157x_1 = id1157in_option1;
        break;
      default:
        id1157x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1157out_result[(getCycle()+1)%2] = (id1157x_1);
  }
  { // Node ID: 1165 (NodeMul)
    const HWFloat<8,24> &id1165in_a = id1157out_result[getCycle()%2];
    const HWFloat<8,24> &id1165in_b = id1155out_result[getCycle()%2];

    id1165out_result[(getCycle()+8)%9] = (mul_float(id1165in_a,id1165in_b));
  }
  { // Node ID: 2242 (NodeFIFO)
    const HWFloat<8,24> &id2242in_input = id1165out_result[getCycle()%9];

    id2242out_output[(getCycle()+19)%20] = id2242in_input;
  }
  { // Node ID: 1166 (NodeAdd)
    const HWFloat<8,24> &id1166in_a = id1164out_result[getCycle()%12];
    const HWFloat<8,24> &id1166in_b = id2242out_output[getCycle()%20];

    id1166out_result[(getCycle()+11)%12] = (add_float(id1166in_a,id1166in_b));
  }
  HWRawBits<32> id1330out_result;

  { // Node ID: 1330 (NodeSlice)
    const HWRawBits<128> &id1330in_a = id1329out_dout[getCycle()%3];

    id1330out_result = (slice<0,32>(id1330in_a));
  }
  HWFloat<8,24> id1331out_output;

  { // Node ID: 1331 (NodeReinterpret)
    const HWRawBits<32> &id1331in_input = id1330out_result;

    id1331out_output = (cast_bits2float<8,24>(id1331in_input));
  }
  HWRawBits<32> id1339out_result;

  { // Node ID: 1339 (NodeSlice)
    const HWRawBits<128> &id1339in_a = id1338out_dout[getCycle()%3];

    id1339out_result = (slice<0,32>(id1339in_a));
  }
  HWFloat<8,24> id1340out_output;

  { // Node ID: 1340 (NodeReinterpret)
    const HWRawBits<32> &id1340in_input = id1339out_result;

    id1340out_output = (cast_bits2float<8,24>(id1340in_input));
  }
  { // Node ID: 1156 (NodeMux)
    const HWRawBits<1> &id1156in_sel = id2177out_output[getCycle()%28];
    const HWFloat<8,24> &id1156in_option0 = id1331out_output;
    const HWFloat<8,24> &id1156in_option1 = id1340out_output;

    HWFloat<8,24> id1156x_1;

    switch((id1156in_sel.getValueAsLong())) {
      case 0l:
        id1156x_1 = id1156in_option0;
        break;
      case 1l:
        id1156x_1 = id1156in_option1;
        break;
      default:
        id1156x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1156out_result[(getCycle()+1)%2] = (id1156x_1);
  }
  { // Node ID: 2244 (NodeFIFO)
    const HWFloat<8,24> &id2244in_input = id1156out_result[getCycle()%2];

    id2244out_output[(getCycle()+38)%39] = id2244in_input;
  }
  { // Node ID: 1167 (NodeAdd)
    const HWFloat<8,24> &id1167in_a = id1166out_result[getCycle()%12];
    const HWFloat<8,24> &id1167in_b = id2244out_output[getCycle()%39];

    id1167out_result[(getCycle()+11)%12] = (add_float(id1167in_a,id1167in_b));
  }
  { // Node ID: 1923 (NodeConstantRawBits)
  }
  { // Node ID: 1174 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1174in_sel = id2245out_output[getCycle()%65];
    const HWFloat<8,24> &id1174in_option0 = id1167out_result[getCycle()%12];
    const HWFloat<8,24> &id1174in_option1 = id1923out_value;

    HWFloat<8,24> id1174x_1;

    switch((id1174in_sel.getValueAsLong())) {
      case 0l:
        id1174x_1 = id1174in_option0;
        break;
      case 1l:
        id1174x_1 = id1174in_option1;
        break;
      default:
        id1174x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1174out_result[(getCycle()+1)%2] = (id1174x_1);
  }
  HWRawBits<1> id2061out_result;

  { // Node ID: 2061 (NodeSlice)
    const HWFloat<8,24> &id2061in_a = id1174out_result[getCycle()%2];

    id2061out_result = (slice<31,1>(id2061in_a));
  }
  { // Node ID: 2003 (NodeConstantRawBits)
  }
  { // Node ID: 1404 (NodeEqInlined)
    const HWRawBits<2> &id1404in_a = id704out_result[getCycle()%2];
    const HWRawBits<2> &id1404in_b = id2003out_value;

    id1404out_result[(getCycle()+1)%2] = (eq_bits(id1404in_a,id1404in_b));
  }
  { // Node ID: 2002 (NodeConstantRawBits)
  }
  { // Node ID: 1405 (NodeEqInlined)
    const HWRawBits<2> &id1405in_a = id704out_result[getCycle()%2];
    const HWRawBits<2> &id1405in_b = id2002out_value;

    id1405out_result[(getCycle()+1)%2] = (eq_bits(id1405in_a,id1405in_b));
  }
  { // Node ID: 752 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id752in_a = id1404out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id752in_b = id1405out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id752x_1;

    (id752x_1) = (or_fixed(id752in_a,id752in_b));
    id752out_result[(getCycle()+1)%2] = (id752x_1);
  }
  { // Node ID: 2246 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2246in_input = id752out_result[getCycle()%2];

    id2246out_output[(getCycle()+76)%77] = id2246in_input;
  }
  HWRawBits<1> id2062out_result;

  { // Node ID: 2062 (NodeXor)
    const HWRawBits<1> &id2062in_a = id2061out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2062in_b = id2246out_output[getCycle()%77];

    HWRawBits<1> id2062x_1;

    (id2062x_1) = (xor_bits(id2062in_a,(cast_fixed2bits(id2062in_b))));
    id2062out_result = (id2062x_1);
  }
  HWRawBits<31> id2060out_result;

  { // Node ID: 2060 (NodeSlice)
    const HWFloat<8,24> &id2060in_a = id1174out_result[getCycle()%2];

    id2060out_result = (slice<0,31>(id2060in_a));
  }
  HWRawBits<32> id2063out_result;

  { // Node ID: 2063 (NodeCat)
    const HWRawBits<1> &id2063in_in0 = id2062out_result;
    const HWRawBits<31> &id2063in_in1 = id2060out_result;

    id2063out_result = (cat(id2063in_in0,id2063in_in1));
  }
  HWFloat<8,24> id2064out_output;

  { // Node ID: 2064 (NodeReinterpret)
    const HWRawBits<32> &id2064in_input = id2063out_result;

    id2064out_output = (cast_bits2float<8,24>(id2064in_input));
  }
  { // Node ID: 1188 (NodeConstantRawBits)
  }
  { // Node ID: 1189 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1189in_sel = id2247out_output[getCycle()%80];
    const HWFloat<8,24> &id1189in_option0 = id2064out_output;
    const HWFloat<8,24> &id1189in_option1 = id1188out_value;

    HWFloat<8,24> id1189x_1;

    switch((id1189in_sel.getValueAsLong())) {
      case 0l:
        id1189x_1 = id1189in_option0;
        break;
      case 1l:
        id1189x_1 = id1189in_option1;
        break;
      default:
        id1189x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1189out_result[(getCycle()+1)%2] = (id1189x_1);
  }
  { // Node ID: 1190 (NodeMul)
    const HWFloat<8,24> &id1190in_a = id140out_result[getCycle()%29];
    const HWFloat<8,24> &id1190in_b = id1189out_result[getCycle()%2];

    id1190out_result[(getCycle()+8)%9] = (mul_float(id1190in_a,id1190in_b));
  }
  { // Node ID: 2364 (NodeFIFO)
    const HWFloat<8,24> &id2364in_input = id1190out_result[getCycle()%9];

    id2364out_output[(getCycle()+58)%59] = id2364in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1244out_result;

  { // Node ID: 1244 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1244in_a = id2427out_output[getCycle()%2];

    id1244out_result = (not_fixed(id1244in_a));
  }
  { // Node ID: 2347 (NodeFIFO)
    const HWFloat<8,24> &id2347in_input = id22out_result[getCycle()%2];

    id2347out_output[(getCycle()+27)%28] = id2347in_input;
  }
  { // Node ID: 2438 (NodeFIFO)
    const HWFloat<8,24> &id2438in_input = id2347out_output[getCycle()%28];

    id2438out_output[(getCycle()+18)%19] = id2438in_input;
  }
  { // Node ID: 2439 (NodeFIFO)
    const HWFloat<8,24> &id2439in_input = id2438out_output[getCycle()%19];

    id2439out_output[(getCycle()+4)%5] = id2439in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1221out_result;

  { // Node ID: 1221 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1221in_a = id2249out_output[getCycle()%21];

    id1221out_result = (not_fixed(id1221in_a));
  }
  { // Node ID: 1222 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1222in_a = id1221out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1222in_b = id2250out_output[getCycle()%21];

    HWOffsetFix<1,0,UNSIGNED> id1222x_1;

    (id1222x_1) = (and_fixed(id1222in_a,id1222in_b));
    id1222out_result[(getCycle()+1)%2] = (id1222x_1);
  }
  { // Node ID: 2348 (NodeFIFO)
    const HWFloat<8,24> &id2348in_input = id134out_result[getCycle()%2];

    id2348out_output[(getCycle()+85)%86] = id2348in_input;
  }
  { // Node ID: 2432 (NodeFIFO)
    const HWFloat<8,24> &id2432in_input = id2348out_output[getCycle()%86];

    id2432out_output[(getCycle()+19)%20] = id2432in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1196out_result;

  { // Node ID: 1196 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1196in_a = id107out_result[getCycle()%3];

    id1196out_result = (not_fixed(id1196in_a));
  }
  { // Node ID: 1197 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1197in_a = id1196out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1197in_b = id1195out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id1197x_1;

    (id1197x_1) = (and_fixed(id1197in_a,id1197in_b));
    id1197out_result[(getCycle()+1)%2] = (id1197x_1);
  }
  { // Node ID: 2444 (NodeFIFO)
    const HWFloat<8,24> &id2444in_input = id2367out_output[getCycle()%26];

    id2444out_output[(getCycle()+3)%4] = id2444in_input;
  }
  { // Node ID: 1198 (NodeSqrt)
    const HWFloat<8,24> &id1198in_a = id1193out_result[getCycle()%12];

    id1198out_result[(getCycle()+28)%29] = (sqrt_float(id1198in_a));
  }
  { // Node ID: 1200 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1200in_sel = id1197out_result[getCycle()%2];
    const HWFloat<8,24> &id1200in_option0 = id2444out_output[getCycle()%4];
    const HWFloat<8,24> &id1200in_option1 = id1198out_result[getCycle()%29];

    HWFloat<8,24> id1200x_1;

    switch((id1200in_sel.getValueAsLong())) {
      case 0l:
        id1200x_1 = id1200in_option0;
        break;
      case 1l:
        id1200x_1 = id1200in_option1;
        break;
      default:
        id1200x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1200out_result[(getCycle()+1)%2] = (id1200x_1);
  }
  HWFloat<8,24> id1223out_result;

  { // Node ID: 1223 (NodeNeg)
    const HWFloat<8,24> &id1223in_a = id1200out_result[getCycle()%2];

    id1223out_result = (neg_float(id1223in_a));
  }
  HWRawBits<31> id145out_result;

  { // Node ID: 145 (NodeSlice)
    const HWFloat<8,24> &id145in_a = id2434out_output[getCycle()%2];

    id145out_result = (slice<0,31>(id145in_a));
  }
  { // Node ID: 651 (NodeConstantRawBits)
  }
  { // Node ID: 1561 (NodeEqInlined)
    const HWRawBits<31> &id1561in_a = id145out_result;
    const HWRawBits<31> &id1561in_b = id651out_value;

    id1561out_result[(getCycle()+1)%2] = (eq_bits(id1561in_a,id1561in_b));
  }
  HWRawBits<8> id1784out_result;

  { // Node ID: 1784 (NodeSlice)
    const HWFloat<8,24> &id1784in_a = id2153out_output[getCycle()%7];

    id1784out_result = (slice<23,8>(id1784in_a));
  }
  { // Node ID: 656 (NodeConstantRawBits)
  }
  { // Node ID: 1563 (NodeEqInlined)
    const HWRawBits<8> &id1563in_a = id1784out_result;
    const HWRawBits<8> &id1563in_b = id656out_value;

    id1563out_result[(getCycle()+1)%2] = (eq_bits(id1563in_a,id1563in_b));
  }
  HWRawBits<23> id1785out_result;

  { // Node ID: 1785 (NodeSlice)
    const HWFloat<8,24> &id1785in_a = id2153out_output[getCycle()%7];

    id1785out_result = (slice<0,23>(id1785in_a));
  }
  { // Node ID: 1922 (NodeConstantRawBits)
  }
  { // Node ID: 1565 (NodeNeqInlined)
    const HWRawBits<23> &id1565in_a = id1785out_result;
    const HWRawBits<23> &id1565in_b = id1922out_value;

    id1565out_result[(getCycle()+1)%2] = (neq_bits(id1565in_a,id1565in_b));
  }
  { // Node ID: 660 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id660in_a = id1563out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id660in_b = id1565out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id660x_1;

    (id660x_1) = (and_fixed(id660in_a,id660in_b));
    id660out_result[(getCycle()+1)%2] = (id660x_1);
  }
  { // Node ID: 661 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id661in_a = id1561out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id661in_b = id660out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id661x_1;

    (id661x_1) = (or_fixed(id661in_a,id661in_b));
    id661out_result[(getCycle()+1)%2] = (id661x_1);
  }
  { // Node ID: 2345 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2345in_input = id661out_result[getCycle()%2];

    id2345out_output[(getCycle()+79)%80] = id2345in_input;
  }
  { // Node ID: 149 (NodeConstantRawBits)
  }
  HWRawBits<23> id1786out_result;

  { // Node ID: 1786 (NodeSlice)
    const HWFloat<8,24> &id1786in_a = id2434out_output[getCycle()%2];

    id1786out_result = (slice<0,23>(id1786in_a));
  }
  HWRawBits<24> id150out_result;

  { // Node ID: 150 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_in0 = id149out_value;
    const HWRawBits<23> &id150in_in1 = id1786out_result;

    id150out_result = (cat(id150in_in0,id150in_in1));
  }
  HWOffsetFix<24,0,UNSIGNED> id153out_output;

  { // Node ID: 153 (NodeReinterpret)
    const HWRawBits<24> &id153in_input = id150out_result;

    id153out_output = (cast_bits2fixed<24,0,UNSIGNED>(id153in_input));
  }
  HWRawBits<8> id1787out_result;

  { // Node ID: 1787 (NodeSlice)
    const HWFloat<8,24> &id1787in_a = id143out_result[getCycle()%9];

    id1787out_result = (slice<23,8>(id1787in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id155out_output;

  { // Node ID: 155 (NodeReinterpret)
    const HWRawBits<8> &id155in_input = id1787out_result;

    id155out_output = (cast_bits2fixed<8,0,UNSIGNED>(id155in_input));
  }
  { // Node ID: 1921 (NodeConstantRawBits)
  }
  { // Node ID: 1920 (NodeConstantRawBits)
  }
  { // Node ID: 2036 (NodeTriArith)
    const HWOffsetFix<8,0,UNSIGNED> &id2036in_a = id155out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2036in_b = id1921out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2036in_c = id1920out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id2036x_1;

    (id2036x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id2036in_a,id2036in_b)),id2036in_c));
    id2036out_result[(getCycle()+1)%2] = (id2036x_1);
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2037out_o;

  { // Node ID: 2037 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id2037in_i = id2036out_result[getCycle()%2];

    id2037out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id2037in_i));
  }
  HWRawBits<1> id1568out_result;

  { // Node ID: 1568 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1568in_a = id2037out_o;

    id1568out_result = (slice<8,1>(id1568in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1569out_output;

  { // Node ID: 1569 (NodeReinterpret)
    const HWRawBits<1> &id1569in_input = id1568out_result;

    id1569out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1569in_input));
  }
  { // Node ID: 2256 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2256in_input = id1569out_output;

    id2256out_output[(getCycle()+5)%6] = id2256in_input;
  }
  { // Node ID: 160 (NodeConstantRawBits)
  }
  { // Node ID: 2088 (NodeConstantRawBits)
  }
  HWRawBits<1> id1570out_result;

  { // Node ID: 1570 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1570in_a = id2037out_o;

    id1570out_result = (slice<8,1>(id1570in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1571out_output;

  { // Node ID: 1571 (NodeReinterpret)
    const HWRawBits<1> &id1571in_input = id1570out_result;

    id1571out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1571in_input));
  }
  { // Node ID: 2066 (NodeCondAddSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2066in_a = id2088out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2066in_b = id2037out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id2066in_sub = id1571out_output;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2066x_1;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2066x_2;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2066x_3;

    (id2066x_1) = (add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2066in_a,id2066in_b));
    (id2066x_2) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2066in_a,id2066in_b));
    switch((id2066in_sub.getValueAsLong())) {
      case 0l:
        id2066x_3 = (id2066x_1);
        break;
      case 1l:
        id2066x_3 = (id2066x_2);
        break;
      default:
        id2066x_3 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id2066out_result[(getCycle()+1)%2] = (id2066x_3);
  }
  HWRawBits<8> id167out_result;

  { // Node ID: 167 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id167in_a = id2066out_result[getCycle()%2];

    id167out_result = (slice<0,8>(id167in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id168out_output;

  { // Node ID: 168 (NodeReinterpret)
    const HWRawBits<8> &id168in_input = id167out_result;

    id168out_output = (cast_bits2fixed<8,0,UNSIGNED>(id168in_input));
  }
  { // Node ID: 170 (NodeShift)
    const HWRawBits<185> &id170in_datain = id160out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id170in_shift = id168out_output;

    id170out_dataout[(getCycle()+4)%5] = (shift_left_bits(id170in_datain,(id170in_shift.getValueAsLong())));
  }
  { // Node ID: 169 (NodeShift)
    const HWRawBits<185> &id169in_datain = id160out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id169in_shift = id168out_output;

    id169out_dataout[(getCycle()+4)%5] = (shift_right_bits(id169in_datain,(id169in_shift.getValueAsLong())));
  }
  { // Node ID: 171 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id171in_sel = id2256out_output[getCycle()%6];
    const HWRawBits<185> &id171in_option0 = id170out_dataout[getCycle()%5];
    const HWRawBits<185> &id171in_option1 = id169out_dataout[getCycle()%5];

    HWRawBits<185> id171x_1;

    switch((id171in_sel.getValueAsLong())) {
      case 0l:
        id171x_1 = id171in_option0;
        break;
      case 1l:
        id171x_1 = id171in_option1;
        break;
      default:
        id171x_1 = (HWRawBits<185>(varint_u<185>::init(3, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64), m_undefined_value.get_bits(57))));
        break;
    }
    id171out_result[(getCycle()+1)%2] = (id171x_1);
  }
  HWRawBits<81> id172out_result;

  { // Node ID: 172 (NodeSlice)
    const HWRawBits<185> &id172in_a = id171out_result[getCycle()%2];

    id172out_result = (slice<104,81>(id172in_a));
  }
  HWOffsetFix<81,0,UNSIGNED> id174out_output;

  { // Node ID: 174 (NodeReinterpret)
    const HWRawBits<81> &id174in_input = id172out_result;

    id174out_output = (cast_bits2fixed<81,0,UNSIGNED>(id174in_input));
  }
  { // Node ID: 175 (NodeMul)
    const HWOffsetFix<24,0,UNSIGNED> &id175in_a = id153out_output;
    const HWOffsetFix<81,0,UNSIGNED> &id175in_b = id174out_output;

    id175out_result[(getCycle()+1)%2] = (mul_fixed<81,0,UNSIGNED,TONEAREVEN>(id175in_a,id175in_b));
  }
  HWRawBits<79> id179out_result;

  { // Node ID: 179 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id179in_a = id175out_result[getCycle()%2];

    id179out_result = (slice<0,79>(id179in_a));
  }
  HWOffsetFix<79,-79,UNSIGNED> id180out_output;

  { // Node ID: 180 (NodeReinterpret)
    const HWRawBits<79> &id180in_input = id179out_result;

    id180out_output = (cast_bits2fixed<79,-79,UNSIGNED>(id180in_input));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id183out_o;

  { // Node ID: 183 (NodeCast)
    const HWOffsetFix<79,-79,UNSIGNED> &id183in_i = id180out_output;

    id183out_o = (cast_fixed2fixed<80,-79,TWOSCOMPLEMENT,TONEAREVEN>(id183in_i));
  }
  { // Node ID: 184 (NodeLeading1Detect)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id184in_input = id183out_o;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id184x_1;
    HWRawBits<80> id184x_2;
    HWRawBits<80> id184x_3;

    switch(((slice<79,1>(id184in_input)).getValueAsLong())) {
      case 0l:
        id184x_1 = id184in_input;
        break;
      case 1l:
        id184x_1 = (not_fixed(id184in_input));
        break;
      default:
        id184x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    {
      varint_u<80> raw_bits = (slice<0,80>((cat((id184x_1),(c_hw_fix_1_0_uns_bits))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id184x_2 = HWRawBits<80>(raw_bits);
    }
    {
      varint_u<80> raw_bits = (cast_fixed2bits((add_fixed<80,0,UNSIGNED,TRUNCATE>((cast_bits2fixed<80,0,UNSIGNED>((not_bits((id184x_2))))),(c_hw_fix_80_0_uns_1_0val))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id184x_3 = HWRawBits<80>(raw_bits);
    }
    id184out_output[(getCycle()+1)%2] = (cast_bits2fixed<80,0,UNSIGNED>((and_bits((id184x_3),(slice<0,80>((cat((id184x_1),(c_hw_fix_1_0_uns_bits)))))))));
  }
  { // Node ID: 185 (NodeOneHotDecode)
    const HWOffsetFix<80,0,UNSIGNED> &id185in_input = id184out_output[getCycle()%2];

    (id185st_one_hot_or) = (c_hw_fix_7_0_uns_bits_1);
    if(((slice<0,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_1)));
    }
    if(((slice<1,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_2)));
    }
    if(((slice<2,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_3)));
    }
    if(((slice<3,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_4)));
    }
    if(((slice<4,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_5)));
    }
    if(((slice<5,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_6)));
    }
    if(((slice<6,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_7)));
    }
    if(((slice<7,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_8)));
    }
    if(((slice<8,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_9)));
    }
    if(((slice<9,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_10)));
    }
    if(((slice<10,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_11)));
    }
    if(((slice<11,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_12)));
    }
    if(((slice<12,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_13)));
    }
    if(((slice<13,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_14)));
    }
    if(((slice<14,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_15)));
    }
    if(((slice<15,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_16)));
    }
    if(((slice<16,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_17)));
    }
    if(((slice<17,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_18)));
    }
    if(((slice<18,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_19)));
    }
    if(((slice<19,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_20)));
    }
    if(((slice<20,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_21)));
    }
    if(((slice<21,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_22)));
    }
    if(((slice<22,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_23)));
    }
    if(((slice<23,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_24)));
    }
    if(((slice<24,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_25)));
    }
    if(((slice<25,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_26)));
    }
    if(((slice<26,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_27)));
    }
    if(((slice<27,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_28)));
    }
    if(((slice<28,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_29)));
    }
    if(((slice<29,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_30)));
    }
    if(((slice<30,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_31)));
    }
    if(((slice<31,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_32)));
    }
    if(((slice<32,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_33)));
    }
    if(((slice<33,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_34)));
    }
    if(((slice<34,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_35)));
    }
    if(((slice<35,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_36)));
    }
    if(((slice<36,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_37)));
    }
    if(((slice<37,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_38)));
    }
    if(((slice<38,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_39)));
    }
    if(((slice<39,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_40)));
    }
    if(((slice<40,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_41)));
    }
    if(((slice<41,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_42)));
    }
    if(((slice<42,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_43)));
    }
    if(((slice<43,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_44)));
    }
    if(((slice<44,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_45)));
    }
    if(((slice<45,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_46)));
    }
    if(((slice<46,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_47)));
    }
    if(((slice<47,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_48)));
    }
    if(((slice<48,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_49)));
    }
    if(((slice<49,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_50)));
    }
    if(((slice<50,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_51)));
    }
    if(((slice<51,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_52)));
    }
    if(((slice<52,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_53)));
    }
    if(((slice<53,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_54)));
    }
    if(((slice<54,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_55)));
    }
    if(((slice<55,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_56)));
    }
    if(((slice<56,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_57)));
    }
    if(((slice<57,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_58)));
    }
    if(((slice<58,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_59)));
    }
    if(((slice<59,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_60)));
    }
    if(((slice<60,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_61)));
    }
    if(((slice<61,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_62)));
    }
    if(((slice<62,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_63)));
    }
    if(((slice<63,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_64)));
    }
    if(((slice<64,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_65)));
    }
    if(((slice<65,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_66)));
    }
    if(((slice<66,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_67)));
    }
    if(((slice<67,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_68)));
    }
    if(((slice<68,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_69)));
    }
    if(((slice<69,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_70)));
    }
    if(((slice<70,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_71)));
    }
    if(((slice<71,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_72)));
    }
    if(((slice<72,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_73)));
    }
    if(((slice<73,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_74)));
    }
    if(((slice<74,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_75)));
    }
    if(((slice<75,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_76)));
    }
    if(((slice<76,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_77)));
    }
    if(((slice<77,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_78)));
    }
    if(((slice<78,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_79)));
    }
    if(((slice<79,1>(id185in_input)).getValueAsBool())) {
      (id185st_one_hot_or) = (or_fixed((id185st_one_hot_or),(c_hw_fix_7_0_uns_bits_80)));
    }
    id185out_output[(getCycle()+1)%2] = (id185st_one_hot_or);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id186out_o;

  { // Node ID: 186 (NodeCast)
    const HWOffsetFix<7,0,UNSIGNED> &id186in_i = id185out_output[getCycle()%2];

    id186out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id186in_i));
  }
  { // Node ID: 1917 (NodeConstantRawBits)
  }
  { // Node ID: 1916 (NodeConstantRawBits)
  }
  { // Node ID: 2038 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2038in_a = id186out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2038in_b = id1917out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2038in_c = id1916out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id2038x_1;

    (id2038x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id2038in_a,id2038in_b)),id2038in_c));
    id2038out_result[(getCycle()+1)%2] = (id2038x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2039out_o;

  { // Node ID: 2039 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id2039in_i = id2038out_result[getCycle()%2];

    id2039out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id2039in_i));
  }
  { // Node ID: 2257 (NodeFIFO)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2257in_input = id2039out_o;

    id2257out_output[(getCycle()+4)%5] = id2257in_input;
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id203out_o;

  { // Node ID: 203 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id203in_i = id2257out_output[getCycle()%5];

    id203out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id203in_i));
  }
  { // Node ID: 1915 (NodeConstantRawBits)
  }
  { // Node ID: 205 (NodeAdd)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id205in_a = id203out_o;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id205in_b = id1915out_value;

    id205out_result[(getCycle()+1)%2] = (add_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id205in_a,id205in_b));
  }
  { // Node ID: 1914 (NodeConstantRawBits)
  }
  { // Node ID: 1574 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1574in_a = id205out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1574in_b = id1914out_value;

    id1574out_result[(getCycle()+1)%2] = (lt_fixed(id1574in_a,id1574in_b));
  }
  { // Node ID: 2262 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2262in_input = id1574out_result[getCycle()%2];

    id2262out_output[(getCycle()+1)%2] = id2262in_input;
  }
  { // Node ID: 1913 (NodeConstantRawBits)
  }
  { // Node ID: 1575 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1575in_a = id205out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1575in_b = id1913out_value;

    id1575out_result[(getCycle()+1)%2] = (gt_fixed(id1575in_a,id1575in_b));
  }
  { // Node ID: 1358 (NodeConstantRawBits)
  }
  HWOffsetFix<8,0,UNSIGNED> id208out_o;

  { // Node ID: 208 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id208in_i = id205out_result[getCycle()%2];

    id208out_o = (cast_fixed2fixed<8,0,UNSIGNED,TONEAREVEN>(id208in_i));
  }
  { // Node ID: 2261 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id2261in_input = id208out_o;

    id2261out_output[(getCycle()+1)%2] = id2261in_input;
  }
  { // Node ID: 1912 (NodeConstantRawBits)
  }
  { // Node ID: 1911 (NodeConstantRawBits)
  }
  { // Node ID: 2040 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2040in_a = id1912out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2040in_b = id186out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2040in_c = id1911out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id2040x_1;

    (id2040x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id2040in_a,id2040in_b)),id2040in_c));
    id2040out_result[(getCycle()+1)%2] = (id2040x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2041out_o;

  { // Node ID: 2041 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id2041in_i = id2040out_result[getCycle()%2];

    id2041out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id2041in_i));
  }
  { // Node ID: 1910 (NodeConstantRawBits)
  }
  { // Node ID: 1576 (NodeGtInlined)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1576in_a = id2041out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1576in_b = id1910out_value;

    id1576out_result[(getCycle()+1)%2] = (gt_fixed(id1576in_a,id1576in_b));
  }
  { // Node ID: 2259 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2259in_input = id1576out_result[getCycle()%2];

    id2259out_output[(getCycle()+3)%4] = id2259in_input;
  }
  { // Node ID: 2258 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2258in_input = id183out_o;

    id2258out_output[(getCycle()+3)%4] = id2258in_input;
  }
  { // Node ID: 2436 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2436in_input = id2258out_output[getCycle()%4];

    id2436out_output[(getCycle()+4)%5] = id2436in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id197out_o;

  { // Node ID: 197 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id197in_i = id2041out_o;

    id197out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAREVEN>(id197in_i));
  }
  { // Node ID: 198 (NodeShift)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id198in_datain = id2258out_output[getCycle()%4];
    const HWOffsetFix<7,0,UNSIGNED> &id198in_shift = id197out_o;

    id198out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id198in_datain,(id198in_shift.getValueAsLong())));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id199out_output;

  { // Node ID: 199 (NodeReinterpret)
    const HWRawBits<80> &id199in_input = id198out_dataout[getCycle()%5];

    id199out_output = (cast_bits2fixed<80,-79,TWOSCOMPLEMENT>(id199in_input));
  }
  { // Node ID: 200 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id200in_sel = id2259out_output[getCycle()%4];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id200in_option0 = id2436out_output[getCycle()%5];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id200in_option1 = id199out_output;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id200x_1;

    switch((id200in_sel.getValueAsLong())) {
      case 0l:
        id200x_1 = id200in_option0;
        break;
      case 1l:
        id200x_1 = id200in_option1;
        break;
      default:
        id200x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    id200out_result[(getCycle()+1)%2] = (id200x_1);
  }
  HWOffsetFix<80,-78,TWOSCOMPLEMENT> id202out_output;

  { // Node ID: 202 (NodeReinterpret)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id202in_input = id200out_result[getCycle()%2];

    id202out_output = (cast_bits2fixed<80,-78,TWOSCOMPLEMENT>((cast_fixed2bits(id202in_input))));
  }
  { // Node ID: 206 (NodeCast)
    const HWOffsetFix<80,-78,TWOSCOMPLEMENT> &id206in_i = id202out_output;

    id206out_o[(getCycle()+1)%2] = (cast_fixed2fixed<24,-23,UNSIGNED,TONEAREVEN>(id206in_i));
  }
  HWRawBits<23> id207out_result;

  { // Node ID: 207 (NodeSlice)
    const HWOffsetFix<24,-23,UNSIGNED> &id207in_a = id206out_o[getCycle()%2];

    id207out_result = (slice<0,23>(id207in_a));
  }
  HWRawBits<32> id1577out_result;

  { // Node ID: 1577 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id1577in_in0 = id1358out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1577in_in1 = id2261out_output[getCycle()%2];
    const HWRawBits<23> &id1577in_in2 = id207out_result;

    id1577out_result = (cat((cat(id1577in_in0,id1577in_in1)),id1577in_in2));
  }
  HWFloat<8,24> id212out_output;

  { // Node ID: 212 (NodeReinterpret)
    const HWRawBits<32> &id212in_input = id1577out_result;

    id212out_output = (cast_bits2float<8,24>(id212in_input));
  }
  { // Node ID: 215 (NodeConstantRawBits)
  }
  { // Node ID: 216 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id216in_sel = id1575out_result[getCycle()%2];
    const HWFloat<8,24> &id216in_option0 = id212out_output;
    const HWFloat<8,24> &id216in_option1 = id215out_value;

    HWFloat<8,24> id216x_1;

    switch((id216in_sel.getValueAsLong())) {
      case 0l:
        id216x_1 = id216in_option0;
        break;
      case 1l:
        id216x_1 = id216in_option1;
        break;
      default:
        id216x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id216out_result[(getCycle()+1)%2] = (id216x_1);
  }
  { // Node ID: 219 (NodeConstantRawBits)
  }
  { // Node ID: 220 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id220in_sel = id2262out_output[getCycle()%2];
    const HWFloat<8,24> &id220in_option0 = id216out_result[getCycle()%2];
    const HWFloat<8,24> &id220in_option1 = id219out_value;

    HWFloat<8,24> id220x_1;

    switch((id220in_sel.getValueAsLong())) {
      case 0l:
        id220x_1 = id220in_option0;
        break;
      case 1l:
        id220x_1 = id220in_option1;
        break;
      default:
        id220x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id220out_result[(getCycle()+1)%2] = (id220x_1);
  }
  { // Node ID: 2263 (NodeFIFO)
    const HWFloat<8,24> &id2263in_input = id220out_result[getCycle()%2];

    id2263out_output[(getCycle()+1)%2] = id2263in_input;
  }
  { // Node ID: 1909 (NodeConstantRawBits)
  }
  { // Node ID: 643 (NodeLt)
    const HWFloat<8,24> &id643in_a = id2263out_output[getCycle()%2];
    const HWFloat<8,24> &id643in_b = id1909out_value;

    id643out_result[(getCycle()+2)%3] = (lt_float(id643in_a,id643in_b));
  }
  { // Node ID: 1908 (NodeConstantRawBits)
  }
  { // Node ID: 645 (NodeGte)
    const HWFloat<8,24> &id645in_a = id2263out_output[getCycle()%2];
    const HWFloat<8,24> &id645in_b = id1908out_value;

    id645out_result[(getCycle()+2)%3] = (gte_float(id645in_a,id645in_b));
  }
  { // Node ID: 646 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id646in_a = id643out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id646in_b = id645out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id646x_1;

    (id646x_1) = (or_fixed(id646in_a,id646in_b));
    id646out_result[(getCycle()+1)%2] = (id646x_1);
  }
  { // Node ID: 2343 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2343in_input = id646out_result[getCycle()%2];

    id2343out_output[(getCycle()+64)%65] = id2343in_input;
  }
  HWRawBits<1> id1578out_result;

  { // Node ID: 1578 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id1578in_a = id175out_result[getCycle()%2];

    id1578out_result = (slice<79,1>(id1578in_a));
  }
  { // Node ID: 2275 (NodeFIFO)
    const HWRawBits<1> &id2275in_input = id1578out_result;

    id2275out_output[(getCycle()+29)%30] = id2275in_input;
  }
  { // Node ID: 1907 (NodeConstantRawBits)
  }
  HWRawBits<8> id241out_result;

  { // Node ID: 241 (NodeSlice)
    const HWFloat<8,24> &id241in_a = id2263out_output[getCycle()%2];

    id241out_result = (slice<23,8>(id241in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id242out_output;

  { // Node ID: 242 (NodeReinterpret)
    const HWRawBits<8> &id242in_input = id241out_result;

    id242out_output = (cast_bits2fixed<8,0,UNSIGNED>(id242in_input));
  }
  { // Node ID: 1906 (NodeConstantRawBits)
  }
  { // Node ID: 2042 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2042in_a = id1907out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id2042in_b = id242out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2042in_c = id1906out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2042x_1;

    (id2042x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2042in_a,id2042in_b)),id2042in_c));
    id2042out_result[(getCycle()+1)%2] = (id2042x_1);
  }
  HWRawBits<1> id1579out_result;

  { // Node ID: 1579 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1579in_a = id2042out_result[getCycle()%2];

    id1579out_result = (slice<8,1>(id1579in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1580out_output;

  { // Node ID: 1580 (NodeReinterpret)
    const HWRawBits<1> &id1580in_input = id1579out_result;

    id1580out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1580in_input));
  }
  { // Node ID: 2268 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2268in_input = id1580out_output;

    id2268out_output[(getCycle()+4)%5] = id2268in_input;
  }
  { // Node ID: 239 (NodeConstantRawBits)
  }
  { // Node ID: 2087 (NodeConstantRawBits)
  }
  { // Node ID: 231 (NodeConstantRawBits)
  }
  HWRawBits<31> id228out_result;

  { // Node ID: 228 (NodeSlice)
    const HWFloat<8,24> &id228in_a = id220out_result[getCycle()%2];

    id228out_result = (slice<0,31>(id228in_a));
  }
  { // Node ID: 1905 (NodeConstantRawBits)
  }
  { // Node ID: 1581 (NodeNeqInlined)
    const HWRawBits<31> &id1581in_a = id228out_result;
    const HWRawBits<31> &id1581in_b = id1905out_value;

    id1581out_result[(getCycle()+1)%2] = (neq_bits(id1581in_a,id1581in_b));
  }
  HWRawBits<23> id227out_result;

  { // Node ID: 227 (NodeSlice)
    const HWFloat<8,24> &id227in_a = id2263out_output[getCycle()%2];

    id227out_result = (slice<0,23>(id227in_a));
  }
  HWRawBits<25> id1582out_result;

  { // Node ID: 1582 (NodeCat)
    const HWRawBits<1> &id1582in_in0 = id231out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1582in_in1 = id1581out_result[getCycle()%2];
    const HWRawBits<23> &id1582in_in2 = id227out_result;

    id1582out_result = (cat((cat(id1582in_in0,id1582in_in1)),id1582in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id234out_output;

  { // Node ID: 234 (NodeReinterpret)
    const HWRawBits<25> &id234in_input = id1582out_result;

    id234out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id234in_input));
  }
  HWRawBits<1> id235out_result;

  { // Node ID: 235 (NodeSlice)
    const HWFloat<8,24> &id235in_a = id2263out_output[getCycle()%2];

    id235out_result = (slice<31,1>(id235in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id236out_output;

  { // Node ID: 236 (NodeReinterpret)
    const HWRawBits<1> &id236in_input = id235out_result;

    id236out_output = (cast_bits2fixed<1,0,UNSIGNED>(id236in_input));
  }
  { // Node ID: 2068 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2068in_a = id2087out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2068in_b = id234out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2068in_sub = id236out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2068x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2068x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2068x_3;

    (id2068x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2068in_a,id2068in_b));
    (id2068x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2068in_a,id2068in_b));
    switch((id2068in_sub.getValueAsLong())) {
      case 0l:
        id2068x_3 = (id2068x_1);
        break;
      case 1l:
        id2068x_3 = (id2068x_2);
        break;
      default:
        id2068x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2068out_result[(getCycle()+1)%2] = (id2068x_3);
  }
  HWRawBits<30> id240out_result;

  { // Node ID: 240 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id240in_in0 = id239out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id240in_in1 = id2068out_result[getCycle()%2];

    id240out_result = (cat(id240in_in0,id240in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id249out_o;

  { // Node ID: 249 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id249in_i = id2042out_result[getCycle()%2];

    id249out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id249in_i));
  }
  { // Node ID: 250 (NodeShift)
    const HWRawBits<30> &id250in_datain = id240out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id250in_shift = id249out_o;

    id250out_dataout[(getCycle()+4)%5] = (shift_left_bits(id250in_datain,(id250in_shift.getValueAsLong())));
  }
  HWRawBits<7> id251out_result;

  { // Node ID: 251 (NodeSlice)
    const HWRawBits<30> &id251in_a = id250out_dataout[getCycle()%5];

    id251out_result = (slice<23,7>(id251in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id252out_output;

  { // Node ID: 252 (NodeReinterpret)
    const HWRawBits<7> &id252in_input = id251out_result;

    id252out_output = (cast_bits2fixed<7,0,UNSIGNED>(id252in_input));
  }
  { // Node ID: 253 (NodeConstantRawBits)
  }
  { // Node ID: 254 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_sel = id2268out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id254in_option0 = id252out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id254in_option1 = id253out_value;

    HWOffsetFix<7,0,UNSIGNED> id254x_1;

    switch((id254in_sel.getValueAsLong())) {
      case 0l:
        id254x_1 = id254in_option0;
        break;
      case 1l:
        id254x_1 = id254in_option1;
        break;
      default:
        id254x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id254out_result[(getCycle()+1)%2] = (id254x_1);
  }
  { // Node ID: 2269 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2269in_input = id254out_result[getCycle()%2];

    id2269out_output[(getCycle()+9)%10] = id2269in_input;
  }
  { // Node ID: 1311 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1311in_addr = id2269out_output[getCycle()%10];

    HWRawBits<128> id1311x_1;

    switch(((long)((id1311in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1311x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1311x_1 = (id1311sta_rom_store[(id1311in_addr.getValueAsLong())]);
        break;
      default:
        id1311x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1311out_dout[(getCycle()+2)%3] = (id1311x_1);
  }
  HWRawBits<32> id1318out_result;

  { // Node ID: 1318 (NodeSlice)
    const HWRawBits<128> &id1318in_a = id1311out_dout[getCycle()%3];

    id1318out_result = (slice<96,32>(id1318in_a));
  }
  HWFloat<8,24> id1319out_output;

  { // Node ID: 1319 (NodeReinterpret)
    const HWRawBits<32> &id1319in_input = id1318out_result;

    id1319out_output = (cast_bits2float<8,24>(id1319in_input));
  }
  { // Node ID: 1904 (NodeConstantRawBits)
  }
  HWRawBits<8> id442out_result;

  { // Node ID: 442 (NodeSlice)
    const HWFloat<8,24> &id442in_a = id2263out_output[getCycle()%2];

    id442out_result = (slice<23,8>(id442in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id443out_output;

  { // Node ID: 443 (NodeReinterpret)
    const HWRawBits<8> &id443in_input = id442out_result;

    id443out_output = (cast_bits2fixed<8,0,UNSIGNED>(id443in_input));
  }
  { // Node ID: 1903 (NodeConstantRawBits)
  }
  { // Node ID: 2043 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2043in_a = id1904out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id2043in_b = id443out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2043in_c = id1903out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2043x_1;

    (id2043x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2043in_a,id2043in_b)),id2043in_c));
    id2043out_result[(getCycle()+1)%2] = (id2043x_1);
  }
  HWRawBits<1> id1583out_result;

  { // Node ID: 1583 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1583in_a = id2043out_result[getCycle()%2];

    id1583out_result = (slice<8,1>(id1583in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1584out_output;

  { // Node ID: 1584 (NodeReinterpret)
    const HWRawBits<1> &id1584in_input = id1583out_result;

    id1584out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1584in_input));
  }
  { // Node ID: 2273 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2273in_input = id1584out_output;

    id2273out_output[(getCycle()+4)%5] = id2273in_input;
  }
  { // Node ID: 440 (NodeConstantRawBits)
  }
  { // Node ID: 2086 (NodeConstantRawBits)
  }
  { // Node ID: 432 (NodeConstantRawBits)
  }
  HWRawBits<31> id429out_result;

  { // Node ID: 429 (NodeSlice)
    const HWFloat<8,24> &id429in_a = id220out_result[getCycle()%2];

    id429out_result = (slice<0,31>(id429in_a));
  }
  { // Node ID: 1902 (NodeConstantRawBits)
  }
  { // Node ID: 1585 (NodeNeqInlined)
    const HWRawBits<31> &id1585in_a = id429out_result;
    const HWRawBits<31> &id1585in_b = id1902out_value;

    id1585out_result[(getCycle()+1)%2] = (neq_bits(id1585in_a,id1585in_b));
  }
  HWRawBits<23> id428out_result;

  { // Node ID: 428 (NodeSlice)
    const HWFloat<8,24> &id428in_a = id2263out_output[getCycle()%2];

    id428out_result = (slice<0,23>(id428in_a));
  }
  HWRawBits<25> id1586out_result;

  { // Node ID: 1586 (NodeCat)
    const HWRawBits<1> &id1586in_in0 = id432out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1586in_in1 = id1585out_result[getCycle()%2];
    const HWRawBits<23> &id1586in_in2 = id428out_result;

    id1586out_result = (cat((cat(id1586in_in0,id1586in_in1)),id1586in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id435out_output;

  { // Node ID: 435 (NodeReinterpret)
    const HWRawBits<25> &id435in_input = id1586out_result;

    id435out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id435in_input));
  }
  HWRawBits<1> id436out_result;

  { // Node ID: 436 (NodeSlice)
    const HWFloat<8,24> &id436in_a = id2263out_output[getCycle()%2];

    id436out_result = (slice<31,1>(id436in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id437out_output;

  { // Node ID: 437 (NodeReinterpret)
    const HWRawBits<1> &id437in_input = id436out_result;

    id437out_output = (cast_bits2fixed<1,0,UNSIGNED>(id437in_input));
  }
  { // Node ID: 2070 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2070in_a = id2086out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2070in_b = id435out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2070in_sub = id437out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2070x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2070x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2070x_3;

    (id2070x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2070in_a,id2070in_b));
    (id2070x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2070in_a,id2070in_b));
    switch((id2070in_sub.getValueAsLong())) {
      case 0l:
        id2070x_3 = (id2070x_1);
        break;
      case 1l:
        id2070x_3 = (id2070x_2);
        break;
      default:
        id2070x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2070out_result[(getCycle()+1)%2] = (id2070x_3);
  }
  HWRawBits<30> id441out_result;

  { // Node ID: 441 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id441in_in0 = id440out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id441in_in1 = id2070out_result[getCycle()%2];

    id441out_result = (cat(id441in_in0,id441in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id450out_o;

  { // Node ID: 450 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id450in_i = id2043out_result[getCycle()%2];

    id450out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id450in_i));
  }
  { // Node ID: 451 (NodeShift)
    const HWRawBits<30> &id451in_datain = id441out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id451in_shift = id450out_o;

    id451out_dataout[(getCycle()+4)%5] = (shift_left_bits(id451in_datain,(id451in_shift.getValueAsLong())));
  }
  HWRawBits<7> id452out_result;

  { // Node ID: 452 (NodeSlice)
    const HWRawBits<30> &id452in_a = id451out_dataout[getCycle()%5];

    id452out_result = (slice<23,7>(id452in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id453out_output;

  { // Node ID: 453 (NodeReinterpret)
    const HWRawBits<7> &id453in_input = id452out_result;

    id453out_output = (cast_bits2fixed<7,0,UNSIGNED>(id453in_input));
  }
  { // Node ID: 454 (NodeConstantRawBits)
  }
  { // Node ID: 455 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id455in_sel = id2273out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id455in_option0 = id453out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id455in_option1 = id454out_value;

    HWOffsetFix<7,0,UNSIGNED> id455x_1;

    switch((id455in_sel.getValueAsLong())) {
      case 0l:
        id455x_1 = id455in_option0;
        break;
      case 1l:
        id455x_1 = id455in_option1;
        break;
      default:
        id455x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id455out_result[(getCycle()+1)%2] = (id455x_1);
  }
  { // Node ID: 2274 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2274in_input = id455out_result[getCycle()%2];

    id2274out_output[(getCycle()+9)%10] = id2274in_input;
  }
  { // Node ID: 1320 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1320in_addr = id2274out_output[getCycle()%10];

    HWRawBits<128> id1320x_1;

    switch(((long)((id1320in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1320x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1320x_1 = (id1320sta_rom_store[(id1320in_addr.getValueAsLong())]);
        break;
      default:
        id1320x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1320out_dout[(getCycle()+2)%3] = (id1320x_1);
  }
  HWRawBits<32> id1327out_result;

  { // Node ID: 1327 (NodeSlice)
    const HWRawBits<128> &id1327in_a = id1320out_dout[getCycle()%3];

    id1327out_result = (slice<96,32>(id1327in_a));
  }
  HWFloat<8,24> id1328out_output;

  { // Node ID: 1328 (NodeReinterpret)
    const HWRawBits<32> &id1328in_input = id1327out_result;

    id1328out_output = (cast_bits2float<8,24>(id1328in_input));
  }
  { // Node ID: 633 (NodeMux)
    const HWRawBits<1> &id633in_sel = id2275out_output[getCycle()%30];
    const HWFloat<8,24> &id633in_option0 = id1319out_output;
    const HWFloat<8,24> &id633in_option1 = id1328out_output;

    HWFloat<8,24> id633x_1;

    switch((id633in_sel.getValueAsLong())) {
      case 0l:
        id633x_1 = id633in_option0;
        break;
      case 1l:
        id633x_1 = id633in_option1;
        break;
      default:
        id633x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id633out_result[(getCycle()+1)%2] = (id633x_1);
  }
  { // Node ID: 2026 (NodePO2FPMult)
    const HWFloat<8,24> &id2026in_floatIn = id220out_result[getCycle()%2];

    id2026out_floatOut[(getCycle()+1)%2] = (mul_float(id2026in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2276 (NodeFIFO)
    const HWFloat<8,24> &id2276in_input = id2026out_floatOut[getCycle()%2];

    id2276out_output[(getCycle()+3)%4] = id2276in_input;
  }
  HWRawBits<1> id264out_result;

  { // Node ID: 264 (NodeSlice)
    const HWFloat<8,24> &id264in_a = id2276out_output[getCycle()%4];

    id264out_result = (slice<31,1>(id264in_a));
  }
  { // Node ID: 2305 (NodeFIFO)
    const HWRawBits<1> &id2305in_input = id264out_result;

    id2305out_output[(getCycle()+6)%7] = id2305in_input;
  }
  HWRawBits<8> id257out_result;

  { // Node ID: 257 (NodeSlice)
    const HWFloat<8,24> &id257in_a = id2026out_floatOut[getCycle()%2];

    id257out_result = (slice<23,8>(id257in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id258out_output;

  { // Node ID: 258 (NodeReinterpret)
    const HWRawBits<8> &id258in_input = id257out_result;

    id258out_output = (cast_bits2fixed<8,0,UNSIGNED>(id258in_input));
  }
  { // Node ID: 1900 (NodeConstantRawBits)
  }
  { // Node ID: 260 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id260in_a = id258out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id260in_b = id1900out_value;

    id260out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id260in_a,id260in_b));
  }
  { // Node ID: 1899 (NodeConstantRawBits)
  }
  { // Node ID: 1587 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1587in_a = id260out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1587in_b = id1899out_value;

    id1587out_result[(getCycle()+1)%2] = (gte_fixed(id1587in_a,id1587in_b));
  }
  { // Node ID: 1898 (NodeConstantRawBits)
  }
  { // Node ID: 1588 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1588in_a = id260out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1588in_b = id1898out_value;

    id1588out_result[(getCycle()+1)%2] = (lte_fixed(id1588in_a,id1588in_b));
  }
  { // Node ID: 269 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id269in_a = id1587out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id269in_b = id1588out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id269x_1;

    (id269x_1) = (or_fixed(id269in_a,id269in_b));
    id269out_result[(getCycle()+1)%2] = (id269x_1);
  }
  { // Node ID: 1897 (NodeConstantRawBits)
  }
  { // Node ID: 1589 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1589in_a = id260out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1589in_b = id1897out_value;

    id1589out_result[(getCycle()+1)%2] = (lte_fixed(id1589in_a,id1589in_b));
  }
  { // Node ID: 2277 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2277in_input = id1589out_result[getCycle()%2];

    id2277out_output[(getCycle()+1)%2] = id2277in_input;
  }
  HWRawBits<2> id421out_result;

  { // Node ID: 421 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id421in_in0 = id269out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id421in_in1 = id2277out_output[getCycle()%2];

    id421out_result = (cat(id421in_in0,id421in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id422out_output;

  { // Node ID: 422 (NodeReinterpret)
    const HWRawBits<2> &id422in_input = id421out_result;

    id422out_output = (cast_bits2fixed<2,0,UNSIGNED>(id422in_input));
  }
  { // Node ID: 2303 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2303in_input = id422out_output;

    id2303out_output[(getCycle()+5)%6] = id2303in_input;
  }
  { // Node ID: 1896 (NodeConstantRawBits)
  }
  { // Node ID: 1895 (NodeConstantRawBits)
  }
  { // Node ID: 280 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id280in_a = id1895out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id280in_b = id260out_result[getCycle()%2];

    id280out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id280in_a,id280in_b));
  }
  { // Node ID: 1590 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1590in_a = id1896out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1590in_b = id280out_result[getCycle()%2];

    id1590out_result[(getCycle()+1)%2] = (lt_fixed(id1590in_a,id1590in_b));
  }
  { // Node ID: 416 (NodeConstantRawBits)
  }
  HWRawBits<1> id1788out_result;

  { // Node ID: 1788 (NodeSlice)
    const HWFloat<8,24> &id1788in_a = id2276out_output[getCycle()%4];

    id1788out_result = (slice<22,1>(id1788in_a));
  }
  { // Node ID: 417 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id417in_sel = id1590out_result[getCycle()%2];
    const HWRawBits<1> &id417in_option0 = id416out_value;
    const HWRawBits<1> &id417in_option1 = id1788out_result;

    HWRawBits<1> id417x_1;

    switch((id417in_sel.getValueAsLong())) {
      case 0l:
        id417x_1 = id417in_option0;
        break;
      case 1l:
        id417x_1 = id417in_option1;
        break;
      default:
        id417x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id417out_result[(getCycle()+1)%2] = (id417x_1);
  }
  { // Node ID: 1894 (NodeConstantRawBits)
  }
  { // Node ID: 1592 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1592in_a = id1894out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1592in_b = id280out_result[getCycle()%2];

    id1592out_result[(getCycle()+1)%2] = (lt_fixed(id1592in_a,id1592in_b));
  }
  { // Node ID: 410 (NodeConstantRawBits)
  }
  HWRawBits<1> id1789out_result;

  { // Node ID: 1789 (NodeSlice)
    const HWFloat<8,24> &id1789in_a = id2276out_output[getCycle()%4];

    id1789out_result = (slice<21,1>(id1789in_a));
  }
  { // Node ID: 411 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id411in_sel = id1592out_result[getCycle()%2];
    const HWRawBits<1> &id411in_option0 = id410out_value;
    const HWRawBits<1> &id411in_option1 = id1789out_result;

    HWRawBits<1> id411x_1;

    switch((id411in_sel.getValueAsLong())) {
      case 0l:
        id411x_1 = id411in_option0;
        break;
      case 1l:
        id411x_1 = id411in_option1;
        break;
      default:
        id411x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id411out_result[(getCycle()+1)%2] = (id411x_1);
  }
  { // Node ID: 1893 (NodeConstantRawBits)
  }
  { // Node ID: 1594 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1594in_a = id1893out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1594in_b = id280out_result[getCycle()%2];

    id1594out_result[(getCycle()+1)%2] = (lt_fixed(id1594in_a,id1594in_b));
  }
  { // Node ID: 404 (NodeConstantRawBits)
  }
  HWRawBits<1> id1790out_result;

  { // Node ID: 1790 (NodeSlice)
    const HWFloat<8,24> &id1790in_a = id2276out_output[getCycle()%4];

    id1790out_result = (slice<20,1>(id1790in_a));
  }
  { // Node ID: 405 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id405in_sel = id1594out_result[getCycle()%2];
    const HWRawBits<1> &id405in_option0 = id404out_value;
    const HWRawBits<1> &id405in_option1 = id1790out_result;

    HWRawBits<1> id405x_1;

    switch((id405in_sel.getValueAsLong())) {
      case 0l:
        id405x_1 = id405in_option0;
        break;
      case 1l:
        id405x_1 = id405in_option1;
        break;
      default:
        id405x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id405out_result[(getCycle()+1)%2] = (id405x_1);
  }
  { // Node ID: 1892 (NodeConstantRawBits)
  }
  { // Node ID: 1596 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1596in_a = id1892out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1596in_b = id280out_result[getCycle()%2];

    id1596out_result[(getCycle()+1)%2] = (lt_fixed(id1596in_a,id1596in_b));
  }
  { // Node ID: 398 (NodeConstantRawBits)
  }
  HWRawBits<1> id1791out_result;

  { // Node ID: 1791 (NodeSlice)
    const HWFloat<8,24> &id1791in_a = id2276out_output[getCycle()%4];

    id1791out_result = (slice<19,1>(id1791in_a));
  }
  { // Node ID: 399 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id399in_sel = id1596out_result[getCycle()%2];
    const HWRawBits<1> &id399in_option0 = id398out_value;
    const HWRawBits<1> &id399in_option1 = id1791out_result;

    HWRawBits<1> id399x_1;

    switch((id399in_sel.getValueAsLong())) {
      case 0l:
        id399x_1 = id399in_option0;
        break;
      case 1l:
        id399x_1 = id399in_option1;
        break;
      default:
        id399x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id399out_result[(getCycle()+1)%2] = (id399x_1);
  }
  { // Node ID: 1891 (NodeConstantRawBits)
  }
  { // Node ID: 1598 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1598in_a = id1891out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1598in_b = id280out_result[getCycle()%2];

    id1598out_result[(getCycle()+1)%2] = (lt_fixed(id1598in_a,id1598in_b));
  }
  { // Node ID: 392 (NodeConstantRawBits)
  }
  HWRawBits<1> id1792out_result;

  { // Node ID: 1792 (NodeSlice)
    const HWFloat<8,24> &id1792in_a = id2276out_output[getCycle()%4];

    id1792out_result = (slice<18,1>(id1792in_a));
  }
  { // Node ID: 393 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id393in_sel = id1598out_result[getCycle()%2];
    const HWRawBits<1> &id393in_option0 = id392out_value;
    const HWRawBits<1> &id393in_option1 = id1792out_result;

    HWRawBits<1> id393x_1;

    switch((id393in_sel.getValueAsLong())) {
      case 0l:
        id393x_1 = id393in_option0;
        break;
      case 1l:
        id393x_1 = id393in_option1;
        break;
      default:
        id393x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id393out_result[(getCycle()+1)%2] = (id393x_1);
  }
  { // Node ID: 1890 (NodeConstantRawBits)
  }
  { // Node ID: 1600 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1600in_a = id1890out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1600in_b = id280out_result[getCycle()%2];

    id1600out_result[(getCycle()+1)%2] = (lt_fixed(id1600in_a,id1600in_b));
  }
  { // Node ID: 386 (NodeConstantRawBits)
  }
  HWRawBits<1> id1793out_result;

  { // Node ID: 1793 (NodeSlice)
    const HWFloat<8,24> &id1793in_a = id2276out_output[getCycle()%4];

    id1793out_result = (slice<17,1>(id1793in_a));
  }
  { // Node ID: 387 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id387in_sel = id1600out_result[getCycle()%2];
    const HWRawBits<1> &id387in_option0 = id386out_value;
    const HWRawBits<1> &id387in_option1 = id1793out_result;

    HWRawBits<1> id387x_1;

    switch((id387in_sel.getValueAsLong())) {
      case 0l:
        id387x_1 = id387in_option0;
        break;
      case 1l:
        id387x_1 = id387in_option1;
        break;
      default:
        id387x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id387out_result[(getCycle()+1)%2] = (id387x_1);
  }
  { // Node ID: 1889 (NodeConstantRawBits)
  }
  { // Node ID: 1602 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1602in_a = id1889out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1602in_b = id280out_result[getCycle()%2];

    id1602out_result[(getCycle()+1)%2] = (lt_fixed(id1602in_a,id1602in_b));
  }
  { // Node ID: 380 (NodeConstantRawBits)
  }
  HWRawBits<1> id1794out_result;

  { // Node ID: 1794 (NodeSlice)
    const HWFloat<8,24> &id1794in_a = id2276out_output[getCycle()%4];

    id1794out_result = (slice<16,1>(id1794in_a));
  }
  { // Node ID: 381 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id381in_sel = id1602out_result[getCycle()%2];
    const HWRawBits<1> &id381in_option0 = id380out_value;
    const HWRawBits<1> &id381in_option1 = id1794out_result;

    HWRawBits<1> id381x_1;

    switch((id381in_sel.getValueAsLong())) {
      case 0l:
        id381x_1 = id381in_option0;
        break;
      case 1l:
        id381x_1 = id381in_option1;
        break;
      default:
        id381x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id381out_result[(getCycle()+1)%2] = (id381x_1);
  }
  { // Node ID: 1888 (NodeConstantRawBits)
  }
  { // Node ID: 1604 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1604in_a = id1888out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1604in_b = id280out_result[getCycle()%2];

    id1604out_result[(getCycle()+1)%2] = (lt_fixed(id1604in_a,id1604in_b));
  }
  { // Node ID: 374 (NodeConstantRawBits)
  }
  HWRawBits<1> id1795out_result;

  { // Node ID: 1795 (NodeSlice)
    const HWFloat<8,24> &id1795in_a = id2276out_output[getCycle()%4];

    id1795out_result = (slice<15,1>(id1795in_a));
  }
  { // Node ID: 375 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id375in_sel = id1604out_result[getCycle()%2];
    const HWRawBits<1> &id375in_option0 = id374out_value;
    const HWRawBits<1> &id375in_option1 = id1795out_result;

    HWRawBits<1> id375x_1;

    switch((id375in_sel.getValueAsLong())) {
      case 0l:
        id375x_1 = id375in_option0;
        break;
      case 1l:
        id375x_1 = id375in_option1;
        break;
      default:
        id375x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id375out_result[(getCycle()+1)%2] = (id375x_1);
  }
  { // Node ID: 1887 (NodeConstantRawBits)
  }
  { // Node ID: 1606 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1606in_a = id1887out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1606in_b = id280out_result[getCycle()%2];

    id1606out_result[(getCycle()+1)%2] = (lt_fixed(id1606in_a,id1606in_b));
  }
  { // Node ID: 368 (NodeConstantRawBits)
  }
  HWRawBits<1> id1796out_result;

  { // Node ID: 1796 (NodeSlice)
    const HWFloat<8,24> &id1796in_a = id2276out_output[getCycle()%4];

    id1796out_result = (slice<14,1>(id1796in_a));
  }
  { // Node ID: 369 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id369in_sel = id1606out_result[getCycle()%2];
    const HWRawBits<1> &id369in_option0 = id368out_value;
    const HWRawBits<1> &id369in_option1 = id1796out_result;

    HWRawBits<1> id369x_1;

    switch((id369in_sel.getValueAsLong())) {
      case 0l:
        id369x_1 = id369in_option0;
        break;
      case 1l:
        id369x_1 = id369in_option1;
        break;
      default:
        id369x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id369out_result[(getCycle()+1)%2] = (id369x_1);
  }
  { // Node ID: 1886 (NodeConstantRawBits)
  }
  { // Node ID: 1608 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1608in_a = id1886out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1608in_b = id280out_result[getCycle()%2];

    id1608out_result[(getCycle()+1)%2] = (lt_fixed(id1608in_a,id1608in_b));
  }
  { // Node ID: 362 (NodeConstantRawBits)
  }
  HWRawBits<1> id1797out_result;

  { // Node ID: 1797 (NodeSlice)
    const HWFloat<8,24> &id1797in_a = id2276out_output[getCycle()%4];

    id1797out_result = (slice<13,1>(id1797in_a));
  }
  { // Node ID: 363 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id363in_sel = id1608out_result[getCycle()%2];
    const HWRawBits<1> &id363in_option0 = id362out_value;
    const HWRawBits<1> &id363in_option1 = id1797out_result;

    HWRawBits<1> id363x_1;

    switch((id363in_sel.getValueAsLong())) {
      case 0l:
        id363x_1 = id363in_option0;
        break;
      case 1l:
        id363x_1 = id363in_option1;
        break;
      default:
        id363x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id363out_result[(getCycle()+1)%2] = (id363x_1);
  }
  { // Node ID: 1885 (NodeConstantRawBits)
  }
  { // Node ID: 1610 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1610in_a = id1885out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1610in_b = id280out_result[getCycle()%2];

    id1610out_result[(getCycle()+1)%2] = (lt_fixed(id1610in_a,id1610in_b));
  }
  { // Node ID: 356 (NodeConstantRawBits)
  }
  HWRawBits<1> id1798out_result;

  { // Node ID: 1798 (NodeSlice)
    const HWFloat<8,24> &id1798in_a = id2276out_output[getCycle()%4];

    id1798out_result = (slice<12,1>(id1798in_a));
  }
  { // Node ID: 357 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id357in_sel = id1610out_result[getCycle()%2];
    const HWRawBits<1> &id357in_option0 = id356out_value;
    const HWRawBits<1> &id357in_option1 = id1798out_result;

    HWRawBits<1> id357x_1;

    switch((id357in_sel.getValueAsLong())) {
      case 0l:
        id357x_1 = id357in_option0;
        break;
      case 1l:
        id357x_1 = id357in_option1;
        break;
      default:
        id357x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id357out_result[(getCycle()+1)%2] = (id357x_1);
  }
  { // Node ID: 1884 (NodeConstantRawBits)
  }
  { // Node ID: 1612 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1612in_a = id1884out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1612in_b = id280out_result[getCycle()%2];

    id1612out_result[(getCycle()+1)%2] = (lt_fixed(id1612in_a,id1612in_b));
  }
  { // Node ID: 350 (NodeConstantRawBits)
  }
  HWRawBits<1> id1799out_result;

  { // Node ID: 1799 (NodeSlice)
    const HWFloat<8,24> &id1799in_a = id2276out_output[getCycle()%4];

    id1799out_result = (slice<11,1>(id1799in_a));
  }
  { // Node ID: 351 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id351in_sel = id1612out_result[getCycle()%2];
    const HWRawBits<1> &id351in_option0 = id350out_value;
    const HWRawBits<1> &id351in_option1 = id1799out_result;

    HWRawBits<1> id351x_1;

    switch((id351in_sel.getValueAsLong())) {
      case 0l:
        id351x_1 = id351in_option0;
        break;
      case 1l:
        id351x_1 = id351in_option1;
        break;
      default:
        id351x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id351out_result[(getCycle()+1)%2] = (id351x_1);
  }
  { // Node ID: 1883 (NodeConstantRawBits)
  }
  { // Node ID: 1614 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1614in_a = id1883out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1614in_b = id280out_result[getCycle()%2];

    id1614out_result[(getCycle()+1)%2] = (lt_fixed(id1614in_a,id1614in_b));
  }
  { // Node ID: 344 (NodeConstantRawBits)
  }
  HWRawBits<1> id1800out_result;

  { // Node ID: 1800 (NodeSlice)
    const HWFloat<8,24> &id1800in_a = id2276out_output[getCycle()%4];

    id1800out_result = (slice<10,1>(id1800in_a));
  }
  { // Node ID: 345 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id345in_sel = id1614out_result[getCycle()%2];
    const HWRawBits<1> &id345in_option0 = id344out_value;
    const HWRawBits<1> &id345in_option1 = id1800out_result;

    HWRawBits<1> id345x_1;

    switch((id345in_sel.getValueAsLong())) {
      case 0l:
        id345x_1 = id345in_option0;
        break;
      case 1l:
        id345x_1 = id345in_option1;
        break;
      default:
        id345x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id345out_result[(getCycle()+1)%2] = (id345x_1);
  }
  { // Node ID: 1882 (NodeConstantRawBits)
  }
  { // Node ID: 1616 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1616in_a = id1882out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1616in_b = id280out_result[getCycle()%2];

    id1616out_result[(getCycle()+1)%2] = (lt_fixed(id1616in_a,id1616in_b));
  }
  { // Node ID: 338 (NodeConstantRawBits)
  }
  HWRawBits<1> id1801out_result;

  { // Node ID: 1801 (NodeSlice)
    const HWFloat<8,24> &id1801in_a = id2276out_output[getCycle()%4];

    id1801out_result = (slice<9,1>(id1801in_a));
  }
  { // Node ID: 339 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id339in_sel = id1616out_result[getCycle()%2];
    const HWRawBits<1> &id339in_option0 = id338out_value;
    const HWRawBits<1> &id339in_option1 = id1801out_result;

    HWRawBits<1> id339x_1;

    switch((id339in_sel.getValueAsLong())) {
      case 0l:
        id339x_1 = id339in_option0;
        break;
      case 1l:
        id339x_1 = id339in_option1;
        break;
      default:
        id339x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id339out_result[(getCycle()+1)%2] = (id339x_1);
  }
  { // Node ID: 1881 (NodeConstantRawBits)
  }
  { // Node ID: 1618 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1618in_a = id1881out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1618in_b = id280out_result[getCycle()%2];

    id1618out_result[(getCycle()+1)%2] = (lt_fixed(id1618in_a,id1618in_b));
  }
  { // Node ID: 332 (NodeConstantRawBits)
  }
  HWRawBits<1> id1802out_result;

  { // Node ID: 1802 (NodeSlice)
    const HWFloat<8,24> &id1802in_a = id2276out_output[getCycle()%4];

    id1802out_result = (slice<8,1>(id1802in_a));
  }
  { // Node ID: 333 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id333in_sel = id1618out_result[getCycle()%2];
    const HWRawBits<1> &id333in_option0 = id332out_value;
    const HWRawBits<1> &id333in_option1 = id1802out_result;

    HWRawBits<1> id333x_1;

    switch((id333in_sel.getValueAsLong())) {
      case 0l:
        id333x_1 = id333in_option0;
        break;
      case 1l:
        id333x_1 = id333in_option1;
        break;
      default:
        id333x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id333out_result[(getCycle()+1)%2] = (id333x_1);
  }
  { // Node ID: 1880 (NodeConstantRawBits)
  }
  { // Node ID: 1620 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1620in_a = id1880out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1620in_b = id280out_result[getCycle()%2];

    id1620out_result[(getCycle()+1)%2] = (lt_fixed(id1620in_a,id1620in_b));
  }
  { // Node ID: 326 (NodeConstantRawBits)
  }
  HWRawBits<1> id1803out_result;

  { // Node ID: 1803 (NodeSlice)
    const HWFloat<8,24> &id1803in_a = id2276out_output[getCycle()%4];

    id1803out_result = (slice<7,1>(id1803in_a));
  }
  { // Node ID: 327 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id327in_sel = id1620out_result[getCycle()%2];
    const HWRawBits<1> &id327in_option0 = id326out_value;
    const HWRawBits<1> &id327in_option1 = id1803out_result;

    HWRawBits<1> id327x_1;

    switch((id327in_sel.getValueAsLong())) {
      case 0l:
        id327x_1 = id327in_option0;
        break;
      case 1l:
        id327x_1 = id327in_option1;
        break;
      default:
        id327x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id327out_result[(getCycle()+1)%2] = (id327x_1);
  }
  { // Node ID: 1879 (NodeConstantRawBits)
  }
  { // Node ID: 1622 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1622in_a = id1879out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1622in_b = id280out_result[getCycle()%2];

    id1622out_result[(getCycle()+1)%2] = (lt_fixed(id1622in_a,id1622in_b));
  }
  { // Node ID: 320 (NodeConstantRawBits)
  }
  HWRawBits<1> id1804out_result;

  { // Node ID: 1804 (NodeSlice)
    const HWFloat<8,24> &id1804in_a = id2276out_output[getCycle()%4];

    id1804out_result = (slice<6,1>(id1804in_a));
  }
  { // Node ID: 321 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id321in_sel = id1622out_result[getCycle()%2];
    const HWRawBits<1> &id321in_option0 = id320out_value;
    const HWRawBits<1> &id321in_option1 = id1804out_result;

    HWRawBits<1> id321x_1;

    switch((id321in_sel.getValueAsLong())) {
      case 0l:
        id321x_1 = id321in_option0;
        break;
      case 1l:
        id321x_1 = id321in_option1;
        break;
      default:
        id321x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id321out_result[(getCycle()+1)%2] = (id321x_1);
  }
  { // Node ID: 1878 (NodeConstantRawBits)
  }
  { // Node ID: 1624 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1624in_a = id1878out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1624in_b = id280out_result[getCycle()%2];

    id1624out_result[(getCycle()+1)%2] = (lt_fixed(id1624in_a,id1624in_b));
  }
  { // Node ID: 314 (NodeConstantRawBits)
  }
  HWRawBits<1> id1805out_result;

  { // Node ID: 1805 (NodeSlice)
    const HWFloat<8,24> &id1805in_a = id2276out_output[getCycle()%4];

    id1805out_result = (slice<5,1>(id1805in_a));
  }
  { // Node ID: 315 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id315in_sel = id1624out_result[getCycle()%2];
    const HWRawBits<1> &id315in_option0 = id314out_value;
    const HWRawBits<1> &id315in_option1 = id1805out_result;

    HWRawBits<1> id315x_1;

    switch((id315in_sel.getValueAsLong())) {
      case 0l:
        id315x_1 = id315in_option0;
        break;
      case 1l:
        id315x_1 = id315in_option1;
        break;
      default:
        id315x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id315out_result[(getCycle()+1)%2] = (id315x_1);
  }
  { // Node ID: 1877 (NodeConstantRawBits)
  }
  { // Node ID: 1626 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1626in_a = id1877out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1626in_b = id280out_result[getCycle()%2];

    id1626out_result[(getCycle()+1)%2] = (lt_fixed(id1626in_a,id1626in_b));
  }
  { // Node ID: 308 (NodeConstantRawBits)
  }
  HWRawBits<1> id1806out_result;

  { // Node ID: 1806 (NodeSlice)
    const HWFloat<8,24> &id1806in_a = id2276out_output[getCycle()%4];

    id1806out_result = (slice<4,1>(id1806in_a));
  }
  { // Node ID: 309 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id309in_sel = id1626out_result[getCycle()%2];
    const HWRawBits<1> &id309in_option0 = id308out_value;
    const HWRawBits<1> &id309in_option1 = id1806out_result;

    HWRawBits<1> id309x_1;

    switch((id309in_sel.getValueAsLong())) {
      case 0l:
        id309x_1 = id309in_option0;
        break;
      case 1l:
        id309x_1 = id309in_option1;
        break;
      default:
        id309x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id309out_result[(getCycle()+1)%2] = (id309x_1);
  }
  { // Node ID: 1876 (NodeConstantRawBits)
  }
  { // Node ID: 1628 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1628in_a = id1876out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1628in_b = id280out_result[getCycle()%2];

    id1628out_result[(getCycle()+1)%2] = (lt_fixed(id1628in_a,id1628in_b));
  }
  { // Node ID: 302 (NodeConstantRawBits)
  }
  HWRawBits<1> id1807out_result;

  { // Node ID: 1807 (NodeSlice)
    const HWFloat<8,24> &id1807in_a = id2276out_output[getCycle()%4];

    id1807out_result = (slice<3,1>(id1807in_a));
  }
  { // Node ID: 303 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id303in_sel = id1628out_result[getCycle()%2];
    const HWRawBits<1> &id303in_option0 = id302out_value;
    const HWRawBits<1> &id303in_option1 = id1807out_result;

    HWRawBits<1> id303x_1;

    switch((id303in_sel.getValueAsLong())) {
      case 0l:
        id303x_1 = id303in_option0;
        break;
      case 1l:
        id303x_1 = id303in_option1;
        break;
      default:
        id303x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id303out_result[(getCycle()+1)%2] = (id303x_1);
  }
  { // Node ID: 1875 (NodeConstantRawBits)
  }
  { // Node ID: 1630 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1630in_a = id1875out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1630in_b = id280out_result[getCycle()%2];

    id1630out_result[(getCycle()+1)%2] = (lt_fixed(id1630in_a,id1630in_b));
  }
  { // Node ID: 296 (NodeConstantRawBits)
  }
  HWRawBits<1> id1808out_result;

  { // Node ID: 1808 (NodeSlice)
    const HWFloat<8,24> &id1808in_a = id2276out_output[getCycle()%4];

    id1808out_result = (slice<2,1>(id1808in_a));
  }
  { // Node ID: 297 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id297in_sel = id1630out_result[getCycle()%2];
    const HWRawBits<1> &id297in_option0 = id296out_value;
    const HWRawBits<1> &id297in_option1 = id1808out_result;

    HWRawBits<1> id297x_1;

    switch((id297in_sel.getValueAsLong())) {
      case 0l:
        id297x_1 = id297in_option0;
        break;
      case 1l:
        id297x_1 = id297in_option1;
        break;
      default:
        id297x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id297out_result[(getCycle()+1)%2] = (id297x_1);
  }
  { // Node ID: 1874 (NodeConstantRawBits)
  }
  { // Node ID: 1632 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1632in_a = id1874out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1632in_b = id280out_result[getCycle()%2];

    id1632out_result[(getCycle()+1)%2] = (lt_fixed(id1632in_a,id1632in_b));
  }
  { // Node ID: 290 (NodeConstantRawBits)
  }
  HWRawBits<1> id1809out_result;

  { // Node ID: 1809 (NodeSlice)
    const HWFloat<8,24> &id1809in_a = id2276out_output[getCycle()%4];

    id1809out_result = (slice<1,1>(id1809in_a));
  }
  { // Node ID: 291 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id291in_sel = id1632out_result[getCycle()%2];
    const HWRawBits<1> &id291in_option0 = id290out_value;
    const HWRawBits<1> &id291in_option1 = id1809out_result;

    HWRawBits<1> id291x_1;

    switch((id291in_sel.getValueAsLong())) {
      case 0l:
        id291x_1 = id291in_option0;
        break;
      case 1l:
        id291x_1 = id291in_option1;
        break;
      default:
        id291x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id291out_result[(getCycle()+1)%2] = (id291x_1);
  }
  { // Node ID: 1873 (NodeConstantRawBits)
  }
  { // Node ID: 1634 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1634in_a = id1873out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1634in_b = id280out_result[getCycle()%2];

    id1634out_result[(getCycle()+1)%2] = (lt_fixed(id1634in_a,id1634in_b));
  }
  { // Node ID: 284 (NodeConstantRawBits)
  }
  HWRawBits<1> id1810out_result;

  { // Node ID: 1810 (NodeSlice)
    const HWFloat<8,24> &id1810in_a = id2276out_output[getCycle()%4];

    id1810out_result = (slice<0,1>(id1810in_a));
  }
  { // Node ID: 285 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id285in_sel = id1634out_result[getCycle()%2];
    const HWRawBits<1> &id285in_option0 = id284out_value;
    const HWRawBits<1> &id285in_option1 = id1810out_result;

    HWRawBits<1> id285x_1;

    switch((id285in_sel.getValueAsLong())) {
      case 0l:
        id285x_1 = id285in_option0;
        break;
      case 1l:
        id285x_1 = id285in_option1;
        break;
      default:
        id285x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id285out_result[(getCycle()+1)%2] = (id285x_1);
  }
  { // Node ID: 278 (NodeConstantRawBits)
  }
  HWRawBits<24> id1657out_result;

  { // Node ID: 1657 (NodeCat)
    const HWRawBits<1> &id1657in_in0 = id417out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in1 = id411out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in2 = id405out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in3 = id399out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in4 = id393out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in5 = id387out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in6 = id381out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in7 = id375out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in8 = id369out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in9 = id363out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in10 = id357out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in11 = id351out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in12 = id345out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in13 = id339out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in14 = id333out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in15 = id327out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in16 = id321out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in17 = id315out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in18 = id309out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in19 = id303out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in20 = id297out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in21 = id291out_result[getCycle()%2];
    const HWRawBits<1> &id1657in_in22 = id285out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1657in_in23 = id278out_value;

    id1657out_result = (cat((cat((cat((cat((cat(id1657in_in0,id1657in_in1)),id1657in_in2)),(cat((cat(id1657in_in3,id1657in_in4)),id1657in_in5)))),(cat((cat((cat(id1657in_in6,id1657in_in7)),id1657in_in8)),(cat((cat(id1657in_in9,id1657in_in10)),id1657in_in11)))))),(cat((cat((cat((cat(id1657in_in12,id1657in_in13)),id1657in_in14)),(cat((cat(id1657in_in15,id1657in_in16)),id1657in_in17)))),(cat((cat((cat(id1657in_in18,id1657in_in19)),id1657in_in20)),(cat((cat(id1657in_in21,id1657in_in22)),id1657in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id419out_o;

  { // Node ID: 419 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id419in_i = id260out_result[getCycle()%2];

    id419out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id419in_i));
  }
  { // Node ID: 2301 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2301in_input = id419out_o;

    id2301out_output[(getCycle()+3)%4] = id2301in_input;
  }
  { // Node ID: 420 (NodeShift)
    const HWRawBits<24> &id420in_datain = id1657out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id420in_shift = id2301out_output[getCycle()%4];

    id420out_dataout[(getCycle()+4)%5] = (shift_left_bits(id420in_datain,(id420in_shift.getValueAsLong())));
  }
  { // Node ID: 261 (NodeConstantRawBits)
  }
  HWRawBits<23> id262out_result;

  { // Node ID: 262 (NodeSlice)
    const HWFloat<8,24> &id262in_a = id2276out_output[getCycle()%4];

    id262out_result = (slice<0,23>(id262in_a));
  }
  HWRawBits<24> id263out_result;

  { // Node ID: 263 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id263in_in0 = id261out_value;
    const HWRawBits<23> &id263in_in1 = id262out_result;

    id263out_result = (cat(id263in_in0,id263in_in1));
  }
  { // Node ID: 273 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id273in_a = id260out_result[getCycle()%2];

    id273out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id273in_a));
  }
  { // Node ID: 1872 (NodeConstantRawBits)
  }
  { // Node ID: 275 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id275in_a = id273out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id275in_b = id1872out_value;

    id275out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id275in_a,id275in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id276out_o;

  { // Node ID: 276 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id276in_i = id275out_result[getCycle()%2];

    id276out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id276in_i));
  }
  { // Node ID: 277 (NodeShift)
    const HWRawBits<24> &id277in_datain = id263out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id277in_shift = id276out_o;

    id277out_dataout[(getCycle()+4)%5] = (shift_right_bits(id277in_datain,(id277in_shift.getValueAsLong())));
  }
  { // Node ID: 2304 (NodeFIFO)
    const HWRawBits<24> &id2304in_input = id277out_dataout[getCycle()%5];

    id2304out_output[(getCycle()+1)%2] = id2304in_input;
  }
  { // Node ID: 1871 (NodeConstantRawBits)
  }
  { // Node ID: 423 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id423in_sel = id2303out_output[getCycle()%6];
    const HWRawBits<24> &id423in_option0 = id420out_dataout[getCycle()%5];
    const HWRawBits<24> &id423in_option1 = id2304out_output[getCycle()%2];
    const HWRawBits<24> &id423in_option2 = id1871out_value;
    const HWRawBits<24> &id423in_option3 = id1871out_value;

    HWRawBits<24> id423x_1;

    switch((id423in_sel.getValueAsLong())) {
      case 0l:
        id423x_1 = id423in_option0;
        break;
      case 1l:
        id423x_1 = id423in_option1;
        break;
      case 2l:
        id423x_1 = id423in_option2;
        break;
      case 3l:
        id423x_1 = id423in_option3;
        break;
      default:
        id423x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id423out_result[(getCycle()+1)%2] = (id423x_1);
  }
  HWRawBits<24> id424out_result;

  { // Node ID: 424 (NodeNot)
    const HWRawBits<24> &id424in_a = id423out_result[getCycle()%2];

    id424out_result = (not_bits(id424in_a));
  }
  { // Node ID: 425 (NodeMux)
    const HWRawBits<1> &id425in_sel = id2305out_output[getCycle()%7];
    const HWRawBits<24> &id425in_option0 = id423out_result[getCycle()%2];
    const HWRawBits<24> &id425in_option1 = id424out_result;

    HWRawBits<24> id425x_1;

    switch((id425in_sel.getValueAsLong())) {
      case 0l:
        id425x_1 = id425in_option0;
        break;
      case 1l:
        id425x_1 = id425in_option1;
        break;
      default:
        id425x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id425out_result[(getCycle()+1)%2] = (id425x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id426out_output;

  { // Node ID: 426 (NodeReinterpret)
    const HWRawBits<24> &id426in_input = id425out_result[getCycle()%2];

    id426out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id426in_input));
  }
  { // Node ID: 427 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id427in_i = id426out_output;

    id427out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id427in_i));
  }
  { // Node ID: 2027 (NodePO2FPMult)
    const HWFloat<8,24> &id2027in_floatIn = id220out_result[getCycle()%2];

    id2027out_floatOut[(getCycle()+1)%2] = (mul_float(id2027in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2306 (NodeFIFO)
    const HWFloat<8,24> &id2306in_input = id2027out_floatOut[getCycle()%2];

    id2306out_output[(getCycle()+3)%4] = id2306in_input;
  }
  HWRawBits<1> id465out_result;

  { // Node ID: 465 (NodeSlice)
    const HWFloat<8,24> &id465in_a = id2306out_output[getCycle()%4];

    id465out_result = (slice<31,1>(id465in_a));
  }
  { // Node ID: 2335 (NodeFIFO)
    const HWRawBits<1> &id2335in_input = id465out_result;

    id2335out_output[(getCycle()+6)%7] = id2335in_input;
  }
  HWRawBits<8> id458out_result;

  { // Node ID: 458 (NodeSlice)
    const HWFloat<8,24> &id458in_a = id2027out_floatOut[getCycle()%2];

    id458out_result = (slice<23,8>(id458in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id459out_output;

  { // Node ID: 459 (NodeReinterpret)
    const HWRawBits<8> &id459in_input = id458out_result;

    id459out_output = (cast_bits2fixed<8,0,UNSIGNED>(id459in_input));
  }
  { // Node ID: 1869 (NodeConstantRawBits)
  }
  { // Node ID: 461 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id461in_a = id459out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id461in_b = id1869out_value;

    id461out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id461in_a,id461in_b));
  }
  { // Node ID: 1868 (NodeConstantRawBits)
  }
  { // Node ID: 1658 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1658in_a = id461out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1658in_b = id1868out_value;

    id1658out_result[(getCycle()+1)%2] = (gte_fixed(id1658in_a,id1658in_b));
  }
  { // Node ID: 1867 (NodeConstantRawBits)
  }
  { // Node ID: 1659 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1659in_a = id461out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1659in_b = id1867out_value;

    id1659out_result[(getCycle()+1)%2] = (lte_fixed(id1659in_a,id1659in_b));
  }
  { // Node ID: 470 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id470in_a = id1658out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id470in_b = id1659out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id470x_1;

    (id470x_1) = (or_fixed(id470in_a,id470in_b));
    id470out_result[(getCycle()+1)%2] = (id470x_1);
  }
  { // Node ID: 1866 (NodeConstantRawBits)
  }
  { // Node ID: 1660 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1660in_a = id461out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1660in_b = id1866out_value;

    id1660out_result[(getCycle()+1)%2] = (lte_fixed(id1660in_a,id1660in_b));
  }
  { // Node ID: 2307 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2307in_input = id1660out_result[getCycle()%2];

    id2307out_output[(getCycle()+1)%2] = id2307in_input;
  }
  HWRawBits<2> id622out_result;

  { // Node ID: 622 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id622in_in0 = id470out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id622in_in1 = id2307out_output[getCycle()%2];

    id622out_result = (cat(id622in_in0,id622in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id623out_output;

  { // Node ID: 623 (NodeReinterpret)
    const HWRawBits<2> &id623in_input = id622out_result;

    id623out_output = (cast_bits2fixed<2,0,UNSIGNED>(id623in_input));
  }
  { // Node ID: 2333 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2333in_input = id623out_output;

    id2333out_output[(getCycle()+5)%6] = id2333in_input;
  }
  { // Node ID: 1865 (NodeConstantRawBits)
  }
  { // Node ID: 1864 (NodeConstantRawBits)
  }
  { // Node ID: 481 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id481in_a = id1864out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id481in_b = id461out_result[getCycle()%2];

    id481out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id481in_a,id481in_b));
  }
  { // Node ID: 1661 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1661in_a = id1865out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1661in_b = id481out_result[getCycle()%2];

    id1661out_result[(getCycle()+1)%2] = (lt_fixed(id1661in_a,id1661in_b));
  }
  { // Node ID: 617 (NodeConstantRawBits)
  }
  HWRawBits<1> id1811out_result;

  { // Node ID: 1811 (NodeSlice)
    const HWFloat<8,24> &id1811in_a = id2306out_output[getCycle()%4];

    id1811out_result = (slice<22,1>(id1811in_a));
  }
  { // Node ID: 618 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id618in_sel = id1661out_result[getCycle()%2];
    const HWRawBits<1> &id618in_option0 = id617out_value;
    const HWRawBits<1> &id618in_option1 = id1811out_result;

    HWRawBits<1> id618x_1;

    switch((id618in_sel.getValueAsLong())) {
      case 0l:
        id618x_1 = id618in_option0;
        break;
      case 1l:
        id618x_1 = id618in_option1;
        break;
      default:
        id618x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id618out_result[(getCycle()+1)%2] = (id618x_1);
  }
  { // Node ID: 1863 (NodeConstantRawBits)
  }
  { // Node ID: 1663 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1663in_a = id1863out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1663in_b = id481out_result[getCycle()%2];

    id1663out_result[(getCycle()+1)%2] = (lt_fixed(id1663in_a,id1663in_b));
  }
  { // Node ID: 611 (NodeConstantRawBits)
  }
  HWRawBits<1> id1812out_result;

  { // Node ID: 1812 (NodeSlice)
    const HWFloat<8,24> &id1812in_a = id2306out_output[getCycle()%4];

    id1812out_result = (slice<21,1>(id1812in_a));
  }
  { // Node ID: 612 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id612in_sel = id1663out_result[getCycle()%2];
    const HWRawBits<1> &id612in_option0 = id611out_value;
    const HWRawBits<1> &id612in_option1 = id1812out_result;

    HWRawBits<1> id612x_1;

    switch((id612in_sel.getValueAsLong())) {
      case 0l:
        id612x_1 = id612in_option0;
        break;
      case 1l:
        id612x_1 = id612in_option1;
        break;
      default:
        id612x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id612out_result[(getCycle()+1)%2] = (id612x_1);
  }
  { // Node ID: 1862 (NodeConstantRawBits)
  }
  { // Node ID: 1665 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1665in_a = id1862out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1665in_b = id481out_result[getCycle()%2];

    id1665out_result[(getCycle()+1)%2] = (lt_fixed(id1665in_a,id1665in_b));
  }
  { // Node ID: 605 (NodeConstantRawBits)
  }
  HWRawBits<1> id1813out_result;

  { // Node ID: 1813 (NodeSlice)
    const HWFloat<8,24> &id1813in_a = id2306out_output[getCycle()%4];

    id1813out_result = (slice<20,1>(id1813in_a));
  }
  { // Node ID: 606 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id606in_sel = id1665out_result[getCycle()%2];
    const HWRawBits<1> &id606in_option0 = id605out_value;
    const HWRawBits<1> &id606in_option1 = id1813out_result;

    HWRawBits<1> id606x_1;

    switch((id606in_sel.getValueAsLong())) {
      case 0l:
        id606x_1 = id606in_option0;
        break;
      case 1l:
        id606x_1 = id606in_option1;
        break;
      default:
        id606x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id606out_result[(getCycle()+1)%2] = (id606x_1);
  }
  { // Node ID: 1861 (NodeConstantRawBits)
  }
  { // Node ID: 1667 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1667in_a = id1861out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1667in_b = id481out_result[getCycle()%2];

    id1667out_result[(getCycle()+1)%2] = (lt_fixed(id1667in_a,id1667in_b));
  }
  { // Node ID: 599 (NodeConstantRawBits)
  }
  HWRawBits<1> id1814out_result;

  { // Node ID: 1814 (NodeSlice)
    const HWFloat<8,24> &id1814in_a = id2306out_output[getCycle()%4];

    id1814out_result = (slice<19,1>(id1814in_a));
  }
  { // Node ID: 600 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id600in_sel = id1667out_result[getCycle()%2];
    const HWRawBits<1> &id600in_option0 = id599out_value;
    const HWRawBits<1> &id600in_option1 = id1814out_result;

    HWRawBits<1> id600x_1;

    switch((id600in_sel.getValueAsLong())) {
      case 0l:
        id600x_1 = id600in_option0;
        break;
      case 1l:
        id600x_1 = id600in_option1;
        break;
      default:
        id600x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id600out_result[(getCycle()+1)%2] = (id600x_1);
  }
  { // Node ID: 1860 (NodeConstantRawBits)
  }
  { // Node ID: 1669 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1669in_a = id1860out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1669in_b = id481out_result[getCycle()%2];

    id1669out_result[(getCycle()+1)%2] = (lt_fixed(id1669in_a,id1669in_b));
  }
  { // Node ID: 593 (NodeConstantRawBits)
  }
  HWRawBits<1> id1815out_result;

  { // Node ID: 1815 (NodeSlice)
    const HWFloat<8,24> &id1815in_a = id2306out_output[getCycle()%4];

    id1815out_result = (slice<18,1>(id1815in_a));
  }
  { // Node ID: 594 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id594in_sel = id1669out_result[getCycle()%2];
    const HWRawBits<1> &id594in_option0 = id593out_value;
    const HWRawBits<1> &id594in_option1 = id1815out_result;

    HWRawBits<1> id594x_1;

    switch((id594in_sel.getValueAsLong())) {
      case 0l:
        id594x_1 = id594in_option0;
        break;
      case 1l:
        id594x_1 = id594in_option1;
        break;
      default:
        id594x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id594out_result[(getCycle()+1)%2] = (id594x_1);
  }
  { // Node ID: 1859 (NodeConstantRawBits)
  }
  { // Node ID: 1671 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1671in_a = id1859out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1671in_b = id481out_result[getCycle()%2];

    id1671out_result[(getCycle()+1)%2] = (lt_fixed(id1671in_a,id1671in_b));
  }
  { // Node ID: 587 (NodeConstantRawBits)
  }
  HWRawBits<1> id1816out_result;

  { // Node ID: 1816 (NodeSlice)
    const HWFloat<8,24> &id1816in_a = id2306out_output[getCycle()%4];

    id1816out_result = (slice<17,1>(id1816in_a));
  }
  { // Node ID: 588 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id588in_sel = id1671out_result[getCycle()%2];
    const HWRawBits<1> &id588in_option0 = id587out_value;
    const HWRawBits<1> &id588in_option1 = id1816out_result;

    HWRawBits<1> id588x_1;

    switch((id588in_sel.getValueAsLong())) {
      case 0l:
        id588x_1 = id588in_option0;
        break;
      case 1l:
        id588x_1 = id588in_option1;
        break;
      default:
        id588x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id588out_result[(getCycle()+1)%2] = (id588x_1);
  }
  { // Node ID: 1858 (NodeConstantRawBits)
  }
  { // Node ID: 1673 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1673in_a = id1858out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1673in_b = id481out_result[getCycle()%2];

    id1673out_result[(getCycle()+1)%2] = (lt_fixed(id1673in_a,id1673in_b));
  }
  { // Node ID: 581 (NodeConstantRawBits)
  }
  HWRawBits<1> id1817out_result;

  { // Node ID: 1817 (NodeSlice)
    const HWFloat<8,24> &id1817in_a = id2306out_output[getCycle()%4];

    id1817out_result = (slice<16,1>(id1817in_a));
  }
  { // Node ID: 582 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id582in_sel = id1673out_result[getCycle()%2];
    const HWRawBits<1> &id582in_option0 = id581out_value;
    const HWRawBits<1> &id582in_option1 = id1817out_result;

    HWRawBits<1> id582x_1;

    switch((id582in_sel.getValueAsLong())) {
      case 0l:
        id582x_1 = id582in_option0;
        break;
      case 1l:
        id582x_1 = id582in_option1;
        break;
      default:
        id582x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id582out_result[(getCycle()+1)%2] = (id582x_1);
  }
  { // Node ID: 1857 (NodeConstantRawBits)
  }
  { // Node ID: 1675 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1675in_a = id1857out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1675in_b = id481out_result[getCycle()%2];

    id1675out_result[(getCycle()+1)%2] = (lt_fixed(id1675in_a,id1675in_b));
  }
  { // Node ID: 575 (NodeConstantRawBits)
  }
  HWRawBits<1> id1818out_result;

  { // Node ID: 1818 (NodeSlice)
    const HWFloat<8,24> &id1818in_a = id2306out_output[getCycle()%4];

    id1818out_result = (slice<15,1>(id1818in_a));
  }
  { // Node ID: 576 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id576in_sel = id1675out_result[getCycle()%2];
    const HWRawBits<1> &id576in_option0 = id575out_value;
    const HWRawBits<1> &id576in_option1 = id1818out_result;

    HWRawBits<1> id576x_1;

    switch((id576in_sel.getValueAsLong())) {
      case 0l:
        id576x_1 = id576in_option0;
        break;
      case 1l:
        id576x_1 = id576in_option1;
        break;
      default:
        id576x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id576out_result[(getCycle()+1)%2] = (id576x_1);
  }
  { // Node ID: 1856 (NodeConstantRawBits)
  }
  { // Node ID: 1677 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1677in_a = id1856out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1677in_b = id481out_result[getCycle()%2];

    id1677out_result[(getCycle()+1)%2] = (lt_fixed(id1677in_a,id1677in_b));
  }
  { // Node ID: 569 (NodeConstantRawBits)
  }
  HWRawBits<1> id1819out_result;

  { // Node ID: 1819 (NodeSlice)
    const HWFloat<8,24> &id1819in_a = id2306out_output[getCycle()%4];

    id1819out_result = (slice<14,1>(id1819in_a));
  }
  { // Node ID: 570 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id570in_sel = id1677out_result[getCycle()%2];
    const HWRawBits<1> &id570in_option0 = id569out_value;
    const HWRawBits<1> &id570in_option1 = id1819out_result;

    HWRawBits<1> id570x_1;

    switch((id570in_sel.getValueAsLong())) {
      case 0l:
        id570x_1 = id570in_option0;
        break;
      case 1l:
        id570x_1 = id570in_option1;
        break;
      default:
        id570x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id570out_result[(getCycle()+1)%2] = (id570x_1);
  }
  { // Node ID: 1855 (NodeConstantRawBits)
  }
  { // Node ID: 1679 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1679in_a = id1855out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1679in_b = id481out_result[getCycle()%2];

    id1679out_result[(getCycle()+1)%2] = (lt_fixed(id1679in_a,id1679in_b));
  }
  { // Node ID: 563 (NodeConstantRawBits)
  }
  HWRawBits<1> id1820out_result;

  { // Node ID: 1820 (NodeSlice)
    const HWFloat<8,24> &id1820in_a = id2306out_output[getCycle()%4];

    id1820out_result = (slice<13,1>(id1820in_a));
  }
  { // Node ID: 564 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id564in_sel = id1679out_result[getCycle()%2];
    const HWRawBits<1> &id564in_option0 = id563out_value;
    const HWRawBits<1> &id564in_option1 = id1820out_result;

    HWRawBits<1> id564x_1;

    switch((id564in_sel.getValueAsLong())) {
      case 0l:
        id564x_1 = id564in_option0;
        break;
      case 1l:
        id564x_1 = id564in_option1;
        break;
      default:
        id564x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id564out_result[(getCycle()+1)%2] = (id564x_1);
  }
  { // Node ID: 1854 (NodeConstantRawBits)
  }
  { // Node ID: 1681 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1681in_a = id1854out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1681in_b = id481out_result[getCycle()%2];

    id1681out_result[(getCycle()+1)%2] = (lt_fixed(id1681in_a,id1681in_b));
  }
  { // Node ID: 557 (NodeConstantRawBits)
  }
  HWRawBits<1> id1821out_result;

  { // Node ID: 1821 (NodeSlice)
    const HWFloat<8,24> &id1821in_a = id2306out_output[getCycle()%4];

    id1821out_result = (slice<12,1>(id1821in_a));
  }
  { // Node ID: 558 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id558in_sel = id1681out_result[getCycle()%2];
    const HWRawBits<1> &id558in_option0 = id557out_value;
    const HWRawBits<1> &id558in_option1 = id1821out_result;

    HWRawBits<1> id558x_1;

    switch((id558in_sel.getValueAsLong())) {
      case 0l:
        id558x_1 = id558in_option0;
        break;
      case 1l:
        id558x_1 = id558in_option1;
        break;
      default:
        id558x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id558out_result[(getCycle()+1)%2] = (id558x_1);
  }
  { // Node ID: 1853 (NodeConstantRawBits)
  }
  { // Node ID: 1683 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1683in_a = id1853out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1683in_b = id481out_result[getCycle()%2];

    id1683out_result[(getCycle()+1)%2] = (lt_fixed(id1683in_a,id1683in_b));
  }
  { // Node ID: 551 (NodeConstantRawBits)
  }
  HWRawBits<1> id1822out_result;

  { // Node ID: 1822 (NodeSlice)
    const HWFloat<8,24> &id1822in_a = id2306out_output[getCycle()%4];

    id1822out_result = (slice<11,1>(id1822in_a));
  }
  { // Node ID: 552 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id552in_sel = id1683out_result[getCycle()%2];
    const HWRawBits<1> &id552in_option0 = id551out_value;
    const HWRawBits<1> &id552in_option1 = id1822out_result;

    HWRawBits<1> id552x_1;

    switch((id552in_sel.getValueAsLong())) {
      case 0l:
        id552x_1 = id552in_option0;
        break;
      case 1l:
        id552x_1 = id552in_option1;
        break;
      default:
        id552x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id552out_result[(getCycle()+1)%2] = (id552x_1);
  }
  { // Node ID: 1852 (NodeConstantRawBits)
  }
  { // Node ID: 1685 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1685in_a = id1852out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1685in_b = id481out_result[getCycle()%2];

    id1685out_result[(getCycle()+1)%2] = (lt_fixed(id1685in_a,id1685in_b));
  }
  { // Node ID: 545 (NodeConstantRawBits)
  }
  HWRawBits<1> id1823out_result;

  { // Node ID: 1823 (NodeSlice)
    const HWFloat<8,24> &id1823in_a = id2306out_output[getCycle()%4];

    id1823out_result = (slice<10,1>(id1823in_a));
  }
  { // Node ID: 546 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id546in_sel = id1685out_result[getCycle()%2];
    const HWRawBits<1> &id546in_option0 = id545out_value;
    const HWRawBits<1> &id546in_option1 = id1823out_result;

    HWRawBits<1> id546x_1;

    switch((id546in_sel.getValueAsLong())) {
      case 0l:
        id546x_1 = id546in_option0;
        break;
      case 1l:
        id546x_1 = id546in_option1;
        break;
      default:
        id546x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id546out_result[(getCycle()+1)%2] = (id546x_1);
  }
  { // Node ID: 1851 (NodeConstantRawBits)
  }
  { // Node ID: 1687 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1687in_a = id1851out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1687in_b = id481out_result[getCycle()%2];

    id1687out_result[(getCycle()+1)%2] = (lt_fixed(id1687in_a,id1687in_b));
  }
  { // Node ID: 539 (NodeConstantRawBits)
  }
  HWRawBits<1> id1824out_result;

  { // Node ID: 1824 (NodeSlice)
    const HWFloat<8,24> &id1824in_a = id2306out_output[getCycle()%4];

    id1824out_result = (slice<9,1>(id1824in_a));
  }
  { // Node ID: 540 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id540in_sel = id1687out_result[getCycle()%2];
    const HWRawBits<1> &id540in_option0 = id539out_value;
    const HWRawBits<1> &id540in_option1 = id1824out_result;

    HWRawBits<1> id540x_1;

    switch((id540in_sel.getValueAsLong())) {
      case 0l:
        id540x_1 = id540in_option0;
        break;
      case 1l:
        id540x_1 = id540in_option1;
        break;
      default:
        id540x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id540out_result[(getCycle()+1)%2] = (id540x_1);
  }
  { // Node ID: 1850 (NodeConstantRawBits)
  }
  { // Node ID: 1689 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1689in_a = id1850out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1689in_b = id481out_result[getCycle()%2];

    id1689out_result[(getCycle()+1)%2] = (lt_fixed(id1689in_a,id1689in_b));
  }
  { // Node ID: 533 (NodeConstantRawBits)
  }
  HWRawBits<1> id1825out_result;

  { // Node ID: 1825 (NodeSlice)
    const HWFloat<8,24> &id1825in_a = id2306out_output[getCycle()%4];

    id1825out_result = (slice<8,1>(id1825in_a));
  }
  { // Node ID: 534 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id534in_sel = id1689out_result[getCycle()%2];
    const HWRawBits<1> &id534in_option0 = id533out_value;
    const HWRawBits<1> &id534in_option1 = id1825out_result;

    HWRawBits<1> id534x_1;

    switch((id534in_sel.getValueAsLong())) {
      case 0l:
        id534x_1 = id534in_option0;
        break;
      case 1l:
        id534x_1 = id534in_option1;
        break;
      default:
        id534x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id534out_result[(getCycle()+1)%2] = (id534x_1);
  }
  { // Node ID: 1849 (NodeConstantRawBits)
  }
  { // Node ID: 1691 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1691in_a = id1849out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1691in_b = id481out_result[getCycle()%2];

    id1691out_result[(getCycle()+1)%2] = (lt_fixed(id1691in_a,id1691in_b));
  }
  { // Node ID: 527 (NodeConstantRawBits)
  }
  HWRawBits<1> id1826out_result;

  { // Node ID: 1826 (NodeSlice)
    const HWFloat<8,24> &id1826in_a = id2306out_output[getCycle()%4];

    id1826out_result = (slice<7,1>(id1826in_a));
  }
  { // Node ID: 528 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id528in_sel = id1691out_result[getCycle()%2];
    const HWRawBits<1> &id528in_option0 = id527out_value;
    const HWRawBits<1> &id528in_option1 = id1826out_result;

    HWRawBits<1> id528x_1;

    switch((id528in_sel.getValueAsLong())) {
      case 0l:
        id528x_1 = id528in_option0;
        break;
      case 1l:
        id528x_1 = id528in_option1;
        break;
      default:
        id528x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id528out_result[(getCycle()+1)%2] = (id528x_1);
  }
  { // Node ID: 1848 (NodeConstantRawBits)
  }
  { // Node ID: 1693 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1693in_a = id1848out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1693in_b = id481out_result[getCycle()%2];

    id1693out_result[(getCycle()+1)%2] = (lt_fixed(id1693in_a,id1693in_b));
  }
  { // Node ID: 521 (NodeConstantRawBits)
  }
  HWRawBits<1> id1827out_result;

  { // Node ID: 1827 (NodeSlice)
    const HWFloat<8,24> &id1827in_a = id2306out_output[getCycle()%4];

    id1827out_result = (slice<6,1>(id1827in_a));
  }
  { // Node ID: 522 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id522in_sel = id1693out_result[getCycle()%2];
    const HWRawBits<1> &id522in_option0 = id521out_value;
    const HWRawBits<1> &id522in_option1 = id1827out_result;

    HWRawBits<1> id522x_1;

    switch((id522in_sel.getValueAsLong())) {
      case 0l:
        id522x_1 = id522in_option0;
        break;
      case 1l:
        id522x_1 = id522in_option1;
        break;
      default:
        id522x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id522out_result[(getCycle()+1)%2] = (id522x_1);
  }
  { // Node ID: 1847 (NodeConstantRawBits)
  }
  { // Node ID: 1695 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1695in_a = id1847out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1695in_b = id481out_result[getCycle()%2];

    id1695out_result[(getCycle()+1)%2] = (lt_fixed(id1695in_a,id1695in_b));
  }
  { // Node ID: 515 (NodeConstantRawBits)
  }
  HWRawBits<1> id1828out_result;

  { // Node ID: 1828 (NodeSlice)
    const HWFloat<8,24> &id1828in_a = id2306out_output[getCycle()%4];

    id1828out_result = (slice<5,1>(id1828in_a));
  }
  { // Node ID: 516 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id516in_sel = id1695out_result[getCycle()%2];
    const HWRawBits<1> &id516in_option0 = id515out_value;
    const HWRawBits<1> &id516in_option1 = id1828out_result;

    HWRawBits<1> id516x_1;

    switch((id516in_sel.getValueAsLong())) {
      case 0l:
        id516x_1 = id516in_option0;
        break;
      case 1l:
        id516x_1 = id516in_option1;
        break;
      default:
        id516x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id516out_result[(getCycle()+1)%2] = (id516x_1);
  }
  { // Node ID: 1846 (NodeConstantRawBits)
  }
  { // Node ID: 1697 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1697in_a = id1846out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1697in_b = id481out_result[getCycle()%2];

    id1697out_result[(getCycle()+1)%2] = (lt_fixed(id1697in_a,id1697in_b));
  }
  { // Node ID: 509 (NodeConstantRawBits)
  }
  HWRawBits<1> id1829out_result;

  { // Node ID: 1829 (NodeSlice)
    const HWFloat<8,24> &id1829in_a = id2306out_output[getCycle()%4];

    id1829out_result = (slice<4,1>(id1829in_a));
  }
  { // Node ID: 510 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id510in_sel = id1697out_result[getCycle()%2];
    const HWRawBits<1> &id510in_option0 = id509out_value;
    const HWRawBits<1> &id510in_option1 = id1829out_result;

    HWRawBits<1> id510x_1;

    switch((id510in_sel.getValueAsLong())) {
      case 0l:
        id510x_1 = id510in_option0;
        break;
      case 1l:
        id510x_1 = id510in_option1;
        break;
      default:
        id510x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id510out_result[(getCycle()+1)%2] = (id510x_1);
  }
  { // Node ID: 1845 (NodeConstantRawBits)
  }
  { // Node ID: 1699 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1699in_a = id1845out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1699in_b = id481out_result[getCycle()%2];

    id1699out_result[(getCycle()+1)%2] = (lt_fixed(id1699in_a,id1699in_b));
  }
  { // Node ID: 503 (NodeConstantRawBits)
  }
  HWRawBits<1> id1830out_result;

  { // Node ID: 1830 (NodeSlice)
    const HWFloat<8,24> &id1830in_a = id2306out_output[getCycle()%4];

    id1830out_result = (slice<3,1>(id1830in_a));
  }
  { // Node ID: 504 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id504in_sel = id1699out_result[getCycle()%2];
    const HWRawBits<1> &id504in_option0 = id503out_value;
    const HWRawBits<1> &id504in_option1 = id1830out_result;

    HWRawBits<1> id504x_1;

    switch((id504in_sel.getValueAsLong())) {
      case 0l:
        id504x_1 = id504in_option0;
        break;
      case 1l:
        id504x_1 = id504in_option1;
        break;
      default:
        id504x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id504out_result[(getCycle()+1)%2] = (id504x_1);
  }
  { // Node ID: 1844 (NodeConstantRawBits)
  }
  { // Node ID: 1701 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1701in_a = id1844out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1701in_b = id481out_result[getCycle()%2];

    id1701out_result[(getCycle()+1)%2] = (lt_fixed(id1701in_a,id1701in_b));
  }
  { // Node ID: 497 (NodeConstantRawBits)
  }
  HWRawBits<1> id1831out_result;

  { // Node ID: 1831 (NodeSlice)
    const HWFloat<8,24> &id1831in_a = id2306out_output[getCycle()%4];

    id1831out_result = (slice<2,1>(id1831in_a));
  }
  { // Node ID: 498 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id498in_sel = id1701out_result[getCycle()%2];
    const HWRawBits<1> &id498in_option0 = id497out_value;
    const HWRawBits<1> &id498in_option1 = id1831out_result;

    HWRawBits<1> id498x_1;

    switch((id498in_sel.getValueAsLong())) {
      case 0l:
        id498x_1 = id498in_option0;
        break;
      case 1l:
        id498x_1 = id498in_option1;
        break;
      default:
        id498x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id498out_result[(getCycle()+1)%2] = (id498x_1);
  }
  { // Node ID: 1843 (NodeConstantRawBits)
  }
  { // Node ID: 1703 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1703in_a = id1843out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1703in_b = id481out_result[getCycle()%2];

    id1703out_result[(getCycle()+1)%2] = (lt_fixed(id1703in_a,id1703in_b));
  }
  { // Node ID: 491 (NodeConstantRawBits)
  }
  HWRawBits<1> id1832out_result;

  { // Node ID: 1832 (NodeSlice)
    const HWFloat<8,24> &id1832in_a = id2306out_output[getCycle()%4];

    id1832out_result = (slice<1,1>(id1832in_a));
  }
  { // Node ID: 492 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id492in_sel = id1703out_result[getCycle()%2];
    const HWRawBits<1> &id492in_option0 = id491out_value;
    const HWRawBits<1> &id492in_option1 = id1832out_result;

    HWRawBits<1> id492x_1;

    switch((id492in_sel.getValueAsLong())) {
      case 0l:
        id492x_1 = id492in_option0;
        break;
      case 1l:
        id492x_1 = id492in_option1;
        break;
      default:
        id492x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id492out_result[(getCycle()+1)%2] = (id492x_1);
  }
  { // Node ID: 1842 (NodeConstantRawBits)
  }
  { // Node ID: 1705 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1705in_a = id1842out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1705in_b = id481out_result[getCycle()%2];

    id1705out_result[(getCycle()+1)%2] = (lt_fixed(id1705in_a,id1705in_b));
  }
  { // Node ID: 485 (NodeConstantRawBits)
  }
  HWRawBits<1> id1833out_result;

  { // Node ID: 1833 (NodeSlice)
    const HWFloat<8,24> &id1833in_a = id2306out_output[getCycle()%4];

    id1833out_result = (slice<0,1>(id1833in_a));
  }
  { // Node ID: 486 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id486in_sel = id1705out_result[getCycle()%2];
    const HWRawBits<1> &id486in_option0 = id485out_value;
    const HWRawBits<1> &id486in_option1 = id1833out_result;

    HWRawBits<1> id486x_1;

    switch((id486in_sel.getValueAsLong())) {
      case 0l:
        id486x_1 = id486in_option0;
        break;
      case 1l:
        id486x_1 = id486in_option1;
        break;
      default:
        id486x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id486out_result[(getCycle()+1)%2] = (id486x_1);
  }
  { // Node ID: 479 (NodeConstantRawBits)
  }
  HWRawBits<24> id1728out_result;

  { // Node ID: 1728 (NodeCat)
    const HWRawBits<1> &id1728in_in0 = id618out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in1 = id612out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in2 = id606out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in3 = id600out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in4 = id594out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in5 = id588out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in6 = id582out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in7 = id576out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in8 = id570out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in9 = id564out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in10 = id558out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in11 = id552out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in12 = id546out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in13 = id540out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in14 = id534out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in15 = id528out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in16 = id522out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in17 = id516out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in18 = id510out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in19 = id504out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in20 = id498out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in21 = id492out_result[getCycle()%2];
    const HWRawBits<1> &id1728in_in22 = id486out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1728in_in23 = id479out_value;

    id1728out_result = (cat((cat((cat((cat((cat(id1728in_in0,id1728in_in1)),id1728in_in2)),(cat((cat(id1728in_in3,id1728in_in4)),id1728in_in5)))),(cat((cat((cat(id1728in_in6,id1728in_in7)),id1728in_in8)),(cat((cat(id1728in_in9,id1728in_in10)),id1728in_in11)))))),(cat((cat((cat((cat(id1728in_in12,id1728in_in13)),id1728in_in14)),(cat((cat(id1728in_in15,id1728in_in16)),id1728in_in17)))),(cat((cat((cat(id1728in_in18,id1728in_in19)),id1728in_in20)),(cat((cat(id1728in_in21,id1728in_in22)),id1728in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id620out_o;

  { // Node ID: 620 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id620in_i = id461out_result[getCycle()%2];

    id620out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id620in_i));
  }
  { // Node ID: 2331 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2331in_input = id620out_o;

    id2331out_output[(getCycle()+3)%4] = id2331in_input;
  }
  { // Node ID: 621 (NodeShift)
    const HWRawBits<24> &id621in_datain = id1728out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id621in_shift = id2331out_output[getCycle()%4];

    id621out_dataout[(getCycle()+4)%5] = (shift_left_bits(id621in_datain,(id621in_shift.getValueAsLong())));
  }
  { // Node ID: 462 (NodeConstantRawBits)
  }
  HWRawBits<23> id463out_result;

  { // Node ID: 463 (NodeSlice)
    const HWFloat<8,24> &id463in_a = id2306out_output[getCycle()%4];

    id463out_result = (slice<0,23>(id463in_a));
  }
  HWRawBits<24> id464out_result;

  { // Node ID: 464 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id464in_in0 = id462out_value;
    const HWRawBits<23> &id464in_in1 = id463out_result;

    id464out_result = (cat(id464in_in0,id464in_in1));
  }
  { // Node ID: 474 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id474in_a = id461out_result[getCycle()%2];

    id474out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id474in_a));
  }
  { // Node ID: 1841 (NodeConstantRawBits)
  }
  { // Node ID: 476 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id476in_a = id474out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id476in_b = id1841out_value;

    id476out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id476in_a,id476in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id477out_o;

  { // Node ID: 477 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id477in_i = id476out_result[getCycle()%2];

    id477out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id477in_i));
  }
  { // Node ID: 478 (NodeShift)
    const HWRawBits<24> &id478in_datain = id464out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id478in_shift = id477out_o;

    id478out_dataout[(getCycle()+4)%5] = (shift_right_bits(id478in_datain,(id478in_shift.getValueAsLong())));
  }
  { // Node ID: 2334 (NodeFIFO)
    const HWRawBits<24> &id2334in_input = id478out_dataout[getCycle()%5];

    id2334out_output[(getCycle()+1)%2] = id2334in_input;
  }
  { // Node ID: 1840 (NodeConstantRawBits)
  }
  { // Node ID: 624 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id624in_sel = id2333out_output[getCycle()%6];
    const HWRawBits<24> &id624in_option0 = id621out_dataout[getCycle()%5];
    const HWRawBits<24> &id624in_option1 = id2334out_output[getCycle()%2];
    const HWRawBits<24> &id624in_option2 = id1840out_value;
    const HWRawBits<24> &id624in_option3 = id1840out_value;

    HWRawBits<24> id624x_1;

    switch((id624in_sel.getValueAsLong())) {
      case 0l:
        id624x_1 = id624in_option0;
        break;
      case 1l:
        id624x_1 = id624in_option1;
        break;
      case 2l:
        id624x_1 = id624in_option2;
        break;
      case 3l:
        id624x_1 = id624in_option3;
        break;
      default:
        id624x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id624out_result[(getCycle()+1)%2] = (id624x_1);
  }
  HWRawBits<24> id625out_result;

  { // Node ID: 625 (NodeNot)
    const HWRawBits<24> &id625in_a = id624out_result[getCycle()%2];

    id625out_result = (not_bits(id625in_a));
  }
  { // Node ID: 626 (NodeMux)
    const HWRawBits<1> &id626in_sel = id2335out_output[getCycle()%7];
    const HWRawBits<24> &id626in_option0 = id624out_result[getCycle()%2];
    const HWRawBits<24> &id626in_option1 = id625out_result;

    HWRawBits<24> id626x_1;

    switch((id626in_sel.getValueAsLong())) {
      case 0l:
        id626x_1 = id626in_option0;
        break;
      case 1l:
        id626x_1 = id626in_option1;
        break;
      default:
        id626x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id626out_result[(getCycle()+1)%2] = (id626x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id627out_output;

  { // Node ID: 627 (NodeReinterpret)
    const HWRawBits<24> &id627in_input = id626out_result[getCycle()%2];

    id627out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id627in_input));
  }
  { // Node ID: 628 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id628in_i = id627out_output;

    id628out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id628in_i));
  }
  { // Node ID: 629 (NodeMux)
    const HWRawBits<1> &id629in_sel = id2275out_output[getCycle()%30];
    const HWFloat<8,24> &id629in_option0 = id427out_o[getCycle()%8];
    const HWFloat<8,24> &id629in_option1 = id628out_o[getCycle()%8];

    HWFloat<8,24> id629x_1;

    switch((id629in_sel.getValueAsLong())) {
      case 0l:
        id629x_1 = id629in_option0;
        break;
      case 1l:
        id629x_1 = id629in_option1;
        break;
      default:
        id629x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id629out_result[(getCycle()+1)%2] = (id629x_1);
  }
  { // Node ID: 635 (NodeMul)
    const HWFloat<8,24> &id635in_a = id633out_result[getCycle()%2];
    const HWFloat<8,24> &id635in_b = id629out_result[getCycle()%2];

    id635out_result[(getCycle()+8)%9] = (mul_float(id635in_a,id635in_b));
  }
  { // Node ID: 634 (NodeMul)
    const HWFloat<8,24> &id634in_a = id629out_result[getCycle()%2];
    const HWFloat<8,24> &id634in_b = id629out_result[getCycle()%2];

    id634out_result[(getCycle()+8)%9] = (mul_float(id634in_a,id634in_b));
  }
  { // Node ID: 636 (NodeMul)
    const HWFloat<8,24> &id636in_a = id635out_result[getCycle()%9];
    const HWFloat<8,24> &id636in_b = id634out_result[getCycle()%9];

    id636out_result[(getCycle()+8)%9] = (mul_float(id636in_a,id636in_b));
  }
  HWRawBits<32> id1316out_result;

  { // Node ID: 1316 (NodeSlice)
    const HWRawBits<128> &id1316in_a = id1311out_dout[getCycle()%3];

    id1316out_result = (slice<64,32>(id1316in_a));
  }
  HWFloat<8,24> id1317out_output;

  { // Node ID: 1317 (NodeReinterpret)
    const HWRawBits<32> &id1317in_input = id1316out_result;

    id1317out_output = (cast_bits2float<8,24>(id1317in_input));
  }
  HWRawBits<32> id1325out_result;

  { // Node ID: 1325 (NodeSlice)
    const HWRawBits<128> &id1325in_a = id1320out_dout[getCycle()%3];

    id1325out_result = (slice<64,32>(id1325in_a));
  }
  HWFloat<8,24> id1326out_output;

  { // Node ID: 1326 (NodeReinterpret)
    const HWRawBits<32> &id1326in_input = id1325out_result;

    id1326out_output = (cast_bits2float<8,24>(id1326in_input));
  }
  { // Node ID: 632 (NodeMux)
    const HWRawBits<1> &id632in_sel = id2275out_output[getCycle()%30];
    const HWFloat<8,24> &id632in_option0 = id1317out_output;
    const HWFloat<8,24> &id632in_option1 = id1326out_output;

    HWFloat<8,24> id632x_1;

    switch((id632in_sel.getValueAsLong())) {
      case 0l:
        id632x_1 = id632in_option0;
        break;
      case 1l:
        id632x_1 = id632in_option1;
        break;
      default:
        id632x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id632out_result[(getCycle()+1)%2] = (id632x_1);
  }
  { // Node ID: 2338 (NodeFIFO)
    const HWFloat<8,24> &id2338in_input = id632out_result[getCycle()%2];

    id2338out_output[(getCycle()+8)%9] = id2338in_input;
  }
  { // Node ID: 637 (NodeMul)
    const HWFloat<8,24> &id637in_a = id2338out_output[getCycle()%9];
    const HWFloat<8,24> &id637in_b = id634out_result[getCycle()%9];

    id637out_result[(getCycle()+8)%9] = (mul_float(id637in_a,id637in_b));
  }
  { // Node ID: 638 (NodeAdd)
    const HWFloat<8,24> &id638in_a = id636out_result[getCycle()%9];
    const HWFloat<8,24> &id638in_b = id637out_result[getCycle()%9];

    id638out_result[(getCycle()+11)%12] = (add_float(id638in_a,id638in_b));
  }
  HWRawBits<32> id1314out_result;

  { // Node ID: 1314 (NodeSlice)
    const HWRawBits<128> &id1314in_a = id1311out_dout[getCycle()%3];

    id1314out_result = (slice<32,32>(id1314in_a));
  }
  HWFloat<8,24> id1315out_output;

  { // Node ID: 1315 (NodeReinterpret)
    const HWRawBits<32> &id1315in_input = id1314out_result;

    id1315out_output = (cast_bits2float<8,24>(id1315in_input));
  }
  HWRawBits<32> id1323out_result;

  { // Node ID: 1323 (NodeSlice)
    const HWRawBits<128> &id1323in_a = id1320out_dout[getCycle()%3];

    id1323out_result = (slice<32,32>(id1323in_a));
  }
  HWFloat<8,24> id1324out_output;

  { // Node ID: 1324 (NodeReinterpret)
    const HWRawBits<32> &id1324in_input = id1323out_result;

    id1324out_output = (cast_bits2float<8,24>(id1324in_input));
  }
  { // Node ID: 631 (NodeMux)
    const HWRawBits<1> &id631in_sel = id2275out_output[getCycle()%30];
    const HWFloat<8,24> &id631in_option0 = id1315out_output;
    const HWFloat<8,24> &id631in_option1 = id1324out_output;

    HWFloat<8,24> id631x_1;

    switch((id631in_sel.getValueAsLong())) {
      case 0l:
        id631x_1 = id631in_option0;
        break;
      case 1l:
        id631x_1 = id631in_option1;
        break;
      default:
        id631x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id631out_result[(getCycle()+1)%2] = (id631x_1);
  }
  { // Node ID: 639 (NodeMul)
    const HWFloat<8,24> &id639in_a = id631out_result[getCycle()%2];
    const HWFloat<8,24> &id639in_b = id629out_result[getCycle()%2];

    id639out_result[(getCycle()+8)%9] = (mul_float(id639in_a,id639in_b));
  }
  { // Node ID: 2340 (NodeFIFO)
    const HWFloat<8,24> &id2340in_input = id639out_result[getCycle()%9];

    id2340out_output[(getCycle()+19)%20] = id2340in_input;
  }
  { // Node ID: 640 (NodeAdd)
    const HWFloat<8,24> &id640in_a = id638out_result[getCycle()%12];
    const HWFloat<8,24> &id640in_b = id2340out_output[getCycle()%20];

    id640out_result[(getCycle()+11)%12] = (add_float(id640in_a,id640in_b));
  }
  HWRawBits<32> id1312out_result;

  { // Node ID: 1312 (NodeSlice)
    const HWRawBits<128> &id1312in_a = id1311out_dout[getCycle()%3];

    id1312out_result = (slice<0,32>(id1312in_a));
  }
  HWFloat<8,24> id1313out_output;

  { // Node ID: 1313 (NodeReinterpret)
    const HWRawBits<32> &id1313in_input = id1312out_result;

    id1313out_output = (cast_bits2float<8,24>(id1313in_input));
  }
  HWRawBits<32> id1321out_result;

  { // Node ID: 1321 (NodeSlice)
    const HWRawBits<128> &id1321in_a = id1320out_dout[getCycle()%3];

    id1321out_result = (slice<0,32>(id1321in_a));
  }
  HWFloat<8,24> id1322out_output;

  { // Node ID: 1322 (NodeReinterpret)
    const HWRawBits<32> &id1322in_input = id1321out_result;

    id1322out_output = (cast_bits2float<8,24>(id1322in_input));
  }
  { // Node ID: 630 (NodeMux)
    const HWRawBits<1> &id630in_sel = id2275out_output[getCycle()%30];
    const HWFloat<8,24> &id630in_option0 = id1313out_output;
    const HWFloat<8,24> &id630in_option1 = id1322out_output;

    HWFloat<8,24> id630x_1;

    switch((id630in_sel.getValueAsLong())) {
      case 0l:
        id630x_1 = id630in_option0;
        break;
      case 1l:
        id630x_1 = id630in_option1;
        break;
      default:
        id630x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id630out_result[(getCycle()+1)%2] = (id630x_1);
  }
  { // Node ID: 2342 (NodeFIFO)
    const HWFloat<8,24> &id2342in_input = id630out_result[getCycle()%2];

    id2342out_output[(getCycle()+38)%39] = id2342in_input;
  }
  { // Node ID: 641 (NodeAdd)
    const HWFloat<8,24> &id641in_a = id640out_result[getCycle()%12];
    const HWFloat<8,24> &id641in_b = id2342out_output[getCycle()%39];

    id641out_result[(getCycle()+11)%12] = (add_float(id641in_a,id641in_b));
  }
  { // Node ID: 1839 (NodeConstantRawBits)
  }
  { // Node ID: 648 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id648in_sel = id2343out_output[getCycle()%65];
    const HWFloat<8,24> &id648in_option0 = id641out_result[getCycle()%12];
    const HWFloat<8,24> &id648in_option1 = id1839out_value;

    HWFloat<8,24> id648x_1;

    switch((id648in_sel.getValueAsLong())) {
      case 0l:
        id648x_1 = id648in_option0;
        break;
      case 1l:
        id648x_1 = id648in_option1;
        break;
      default:
        id648x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id648out_result[(getCycle()+1)%2] = (id648x_1);
  }
  HWRawBits<1> id2072out_result;

  { // Node ID: 2072 (NodeSlice)
    const HWFloat<8,24> &id2072in_a = id648out_result[getCycle()%2];

    id2072out_result = (slice<31,1>(id2072in_a));
  }
  HWRawBits<2> id178out_result;

  { // Node ID: 178 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id178in_a = id175out_result[getCycle()%2];

    id178out_result = (slice<79,2>(id178in_a));
  }
  { // Node ID: 1919 (NodeConstantRawBits)
  }
  { // Node ID: 1572 (NodeEqInlined)
    const HWRawBits<2> &id1572in_a = id178out_result;
    const HWRawBits<2> &id1572in_b = id1919out_value;

    id1572out_result[(getCycle()+1)%2] = (eq_bits(id1572in_a,id1572in_b));
  }
  { // Node ID: 1918 (NodeConstantRawBits)
  }
  { // Node ID: 1573 (NodeEqInlined)
    const HWRawBits<2> &id1573in_a = id178out_result;
    const HWRawBits<2> &id1573in_b = id1918out_value;

    id1573out_result[(getCycle()+1)%2] = (eq_bits(id1573in_a,id1573in_b));
  }
  { // Node ID: 226 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id226in_a = id1572out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id226in_b = id1573out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id226x_1;

    (id226x_1) = (or_fixed(id226in_a,id226in_b));
    id226out_result[(getCycle()+1)%2] = (id226x_1);
  }
  { // Node ID: 2344 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2344in_input = id226out_result[getCycle()%2];

    id2344out_output[(getCycle()+78)%79] = id2344in_input;
  }
  HWRawBits<1> id2073out_result;

  { // Node ID: 2073 (NodeXor)
    const HWRawBits<1> &id2073in_a = id2072out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2073in_b = id2344out_output[getCycle()%79];

    HWRawBits<1> id2073x_1;

    (id2073x_1) = (xor_bits(id2073in_a,(cast_fixed2bits(id2073in_b))));
    id2073out_result = (id2073x_1);
  }
  HWRawBits<31> id2071out_result;

  { // Node ID: 2071 (NodeSlice)
    const HWFloat<8,24> &id2071in_a = id648out_result[getCycle()%2];

    id2071out_result = (slice<0,31>(id2071in_a));
  }
  HWRawBits<32> id2074out_result;

  { // Node ID: 2074 (NodeCat)
    const HWRawBits<1> &id2074in_in0 = id2073out_result;
    const HWRawBits<31> &id2074in_in1 = id2071out_result;

    id2074out_result = (cat(id2074in_in0,id2074in_in1));
  }
  HWFloat<8,24> id2075out_output;

  { // Node ID: 2075 (NodeReinterpret)
    const HWRawBits<32> &id2075in_input = id2074out_result;

    id2075out_output = (cast_bits2float<8,24>(id2075in_input));
  }
  { // Node ID: 662 (NodeConstantRawBits)
  }
  { // Node ID: 663 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id663in_sel = id2345out_output[getCycle()%80];
    const HWFloat<8,24> &id663in_option0 = id2075out_output;
    const HWFloat<8,24> &id663in_option1 = id662out_value;

    HWFloat<8,24> id663x_1;

    switch((id663in_sel.getValueAsLong())) {
      case 0l:
        id663x_1 = id663in_option0;
        break;
      case 1l:
        id663x_1 = id663in_option1;
        break;
      default:
        id663x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id663out_result[(getCycle()+1)%2] = (id663x_1);
  }
  { // Node ID: 664 (NodeMul)
    const HWFloat<8,24> &id664in_a = id140out_result[getCycle()%29];
    const HWFloat<8,24> &id664in_b = id663out_result[getCycle()%2];

    id664out_result[(getCycle()+8)%9] = (mul_float(id664in_a,id664in_b));
  }
  { // Node ID: 2346 (NodeFIFO)
    const HWFloat<8,24> &id2346in_input = id664out_result[getCycle()%9];

    id2346out_output[(getCycle()+19)%20] = id2346in_input;
  }
  { // Node ID: 1224 (NodeMul)
    const HWFloat<8,24> &id1224in_a = id1223out_result;
    const HWFloat<8,24> &id1224in_b = id2346out_output[getCycle()%20];

    id1224out_result[(getCycle()+8)%9] = (mul_float(id1224in_a,id1224in_b));
  }
  { // Node ID: 1225 (NodeMul)
    const HWFloat<8,24> &id1225in_a = id2347out_output[getCycle()%28];
    const HWFloat<8,24> &id1225in_b = id2348out_output[getCycle()%86];

    id1225out_result[(getCycle()+8)%9] = (mul_float(id1225in_a,id1225in_b));
  }
  { // Node ID: 1226 (NodeAdd)
    const HWFloat<8,24> &id1226in_a = id1224out_result[getCycle()%9];
    const HWFloat<8,24> &id1226in_b = id1225out_result[getCycle()%9];

    id1226out_result[(getCycle()+11)%12] = (add_float(id1226in_a,id1226in_b));
  }
  { // Node ID: 1227 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1227in_sel = id1222out_result[getCycle()%2];
    const HWFloat<8,24> &id1227in_option0 = id2432out_output[getCycle()%20];
    const HWFloat<8,24> &id1227in_option1 = id1226out_result[getCycle()%12];

    HWFloat<8,24> id1227x_1;

    switch((id1227in_sel.getValueAsLong())) {
      case 0l:
        id1227x_1 = id1227in_option0;
        break;
      case 1l:
        id1227x_1 = id1227in_option1;
        break;
      default:
        id1227x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1227out_result[(getCycle()+1)%2] = (id1227x_1);
  }
  HWRawBits<1> id2077out_result;

  { // Node ID: 2077 (NodeSlice)
    const HWFloat<8,24> &id2077in_a = id1227out_result[getCycle()%2];

    id2077out_result = (slice<31,1>(id2077in_a));
  }
  { // Node ID: 2353 (NodeFIFO)
    const HWRawBits<1> &id2353in_input = id2077out_result;

    id2353out_output[(getCycle()+2)%3] = id2353in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1236out_result;

  { // Node ID: 1236 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1236in_a = id2426out_output[getCycle()%4];

    id1236out_result = (not_fixed(id1236in_a));
  }
  { // Node ID: 1837 (NodeConstantRawBits)
  }
  { // Node ID: 1229 (NodeLt)
    const HWFloat<8,24> &id1229in_a = id2438out_output[getCycle()%19];
    const HWFloat<8,24> &id1229in_b = id1837out_value;

    id1229out_result[(getCycle()+2)%3] = (lt_float(id1229in_a,id1229in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id1230out_result;

  { // Node ID: 1230 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1230in_a = id2445out_output[getCycle()%3];

    id1230out_result = (not_fixed(id1230in_a));
  }
  { // Node ID: 1231 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1231in_a = id1229out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id1231in_b = id1230out_result;

    HWOffsetFix<1,0,UNSIGNED> id1231x_1;

    (id1231x_1) = (and_fixed(id1231in_a,id1231in_b));
    id1231out_result[(getCycle()+1)%2] = (id1231x_1);
  }
  { // Node ID: 1237 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1237in_a = id1236out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1237in_b = id1231out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1237x_1;

    (id1237x_1) = (and_fixed(id1237in_a,id1237in_b));
    id1237out_result[(getCycle()+1)%2] = (id1237x_1);
  }
  HWRawBits<1> id2078out_result;

  { // Node ID: 2078 (NodeXor)
    const HWRawBits<1> &id2078in_a = id2353out_output[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id2078in_b = id1237out_result[getCycle()%2];

    HWRawBits<1> id2078x_1;

    (id2078x_1) = (xor_bits(id2078in_a,(cast_fixed2bits(id2078in_b))));
    id2078out_result = (id2078x_1);
  }
  HWRawBits<31> id2076out_result;

  { // Node ID: 2076 (NodeSlice)
    const HWFloat<8,24> &id2076in_a = id1227out_result[getCycle()%2];

    id2076out_result = (slice<0,31>(id2076in_a));
  }
  { // Node ID: 2354 (NodeFIFO)
    const HWRawBits<31> &id2354in_input = id2076out_result;

    id2354out_output[(getCycle()+2)%3] = id2354in_input;
  }
  HWRawBits<32> id2079out_result;

  { // Node ID: 2079 (NodeCat)
    const HWRawBits<1> &id2079in_in0 = id2078out_result;
    const HWRawBits<31> &id2079in_in1 = id2354out_output[getCycle()%3];

    id2079out_result = (cat(id2079in_in0,id2079in_in1));
  }
  HWFloat<8,24> id2080out_output;

  { // Node ID: 2080 (NodeReinterpret)
    const HWRawBits<32> &id2080in_input = id2079out_result;

    id2080out_output = (cast_bits2float<8,24>(id2080in_input));
  }
  { // Node ID: 1245 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1245in_sel = id1244out_result;
    const HWFloat<8,24> &id1245in_option0 = id2439out_output[getCycle()%5];
    const HWFloat<8,24> &id1245in_option1 = id2080out_output;

    HWFloat<8,24> id1245x_1;

    switch((id1245in_sel.getValueAsLong())) {
      case 0l:
        id1245x_1 = id1245in_option0;
        break;
      case 1l:
        id1245x_1 = id1245in_option1;
        break;
      default:
        id1245x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1245out_result[(getCycle()+1)%2] = (id1245x_1);
  }
  { // Node ID: 2356 (NodeFIFO)
    const HWFloat<8,24> &id2356in_input = id1245out_result[getCycle()%2];

    id2356out_output[(getCycle()+18)%19] = id2356in_input;
  }
  HWFloat<8,24> id2104out_output;

  { // Node ID: 2104 (NodeStreamOffset)
    const HWFloat<8,24> &id2104in_input = id2356out_output[getCycle()%19];

    id2104out_output = id2104in_input;
  }
  { // Node ID: 1264 (NodeConstantRawBits)
  }
  { // Node ID: 1265 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1265in_sel = id2139out_output[getCycle()%4];
    const HWFloat<8,24> &id1265in_option0 = id2104out_output;
    const HWFloat<8,24> &id1265in_option1 = id1264out_value;

    HWFloat<8,24> id1265x_1;

    switch((id1265in_sel.getValueAsLong())) {
      case 0l:
        id1265x_1 = id1265in_option0;
        break;
      case 1l:
        id1265x_1 = id1265in_option1;
        break;
      default:
        id1265x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1265out_result[(getCycle()+1)%2] = (id1265x_1);
  }
  { // Node ID: 2359 (NodeFIFO)
    const HWFloat<8,24> &id2359in_input = id1265out_result[getCycle()%2];

    id2359out_output[(getCycle()+21)%22] = id2359in_input;
  }
  { // Node ID: 21 (NodeConstantRawBits)
  }
  { // Node ID: 22 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_sel = id2358out_output[getCycle()%22];
    const HWFloat<8,24> &id22in_option0 = id2359out_output[getCycle()%22];
    const HWFloat<8,24> &id22in_option1 = id21out_value;

    HWFloat<8,24> id22x_1;

    switch((id22in_sel.getValueAsLong())) {
      case 0l:
        id22x_1 = id22in_option0;
        break;
      case 1l:
        id22x_1 = id22in_option1;
        break;
      default:
        id22x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id22out_result[(getCycle()+1)%2] = (id22x_1);
  }
  { // Node ID: 1213 (NodeMul)
    const HWFloat<8,24> &id1213in_a = id2360out_output[getCycle()%22];
    const HWFloat<8,24> &id1213in_b = id22out_result[getCycle()%2];

    id1213out_result[(getCycle()+8)%9] = (mul_float(id1213in_a,id1213in_b));
  }
  { // Node ID: 1214 (NodeMul)
    const HWFloat<8,24> &id1214in_a = id1213out_result[getCycle()%9];
    const HWFloat<8,24> &id1214in_b = id664out_result[getCycle()%9];

    id1214out_result[(getCycle()+8)%9] = (mul_float(id1214in_a,id1214in_b));
  }
  { // Node ID: 1215 (NodeMul)
    const HWFloat<8,24> &id1215in_a = id2447out_output[getCycle()%9];
    const HWFloat<8,24> &id1215in_b = id1190out_result[getCycle()%9];

    id1215out_result[(getCycle()+8)%9] = (mul_float(id1215in_a,id1215in_b));
  }
  { // Node ID: 1216 (NodeSub)
    const HWFloat<8,24> &id1216in_a = id1214out_result[getCycle()%9];
    const HWFloat<8,24> &id1216in_b = id1215out_result[getCycle()%9];

    id1216out_result[(getCycle()+11)%12] = (sub_float(id1216in_a,id1216in_b));
  }
  { // Node ID: 1217 (NodeDiv)
    const HWFloat<8,24> &id1217in_a = id1216out_result[getCycle()%12];
    const HWFloat<8,24> &id1217in_b = id1200out_result[getCycle()%2];

    id1217out_result[(getCycle()+28)%29] = (div_float(id1217in_a,id1217in_b));
  }
  { // Node ID: 2433 (NodeFIFO)
    const HWFloat<8,24> &id2433in_input = id2432out_output[getCycle()%20];

    id2433out_output[(getCycle()+1)%2] = id2433in_input;
  }
  { // Node ID: 1218 (NodeMul)
    const HWFloat<8,24> &id1218in_a = id2441out_output[getCycle()%40];
    const HWFloat<8,24> &id1218in_b = id2433out_output[getCycle()%2];

    id1218out_result[(getCycle()+8)%9] = (mul_float(id1218in_a,id1218in_b));
  }
  { // Node ID: 1219 (NodeAdd)
    const HWFloat<8,24> &id1219in_a = id1217out_result[getCycle()%29];
    const HWFloat<8,24> &id1219in_b = id1218out_result[getCycle()%9];

    id1219out_result[(getCycle()+11)%12] = (add_float(id1219in_a,id1219in_b));
  }
  { // Node ID: 1220 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1220in_sel = id1212out_result[getCycle()%2];
    const HWFloat<8,24> &id1220in_option0 = id2364out_output[getCycle()%59];
    const HWFloat<8,24> &id1220in_option1 = id1219out_result[getCycle()%12];

    HWFloat<8,24> id1220x_1;

    switch((id1220in_sel.getValueAsLong())) {
      case 0l:
        id1220x_1 = id1220in_option0;
        break;
      case 1l:
        id1220x_1 = id1220in_option1;
        break;
      default:
        id1220x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1220out_result[(getCycle()+1)%2] = (id1220x_1);
  }
  { // Node ID: 1243 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1243in_sel = id1242out_result;
    const HWFloat<8,24> &id1243in_option0 = id2443out_output[getCycle()%19];
    const HWFloat<8,24> &id1243in_option1 = id1220out_result[getCycle()%2];

    HWFloat<8,24> id1243x_1;

    switch((id1243in_sel.getValueAsLong())) {
      case 0l:
        id1243x_1 = id1243in_option0;
        break;
      case 1l:
        id1243x_1 = id1243in_option1;
        break;
      default:
        id1243x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1243out_result[(getCycle()+1)%2] = (id1243x_1);
  }
  HWFloat<8,24> id2105out_output;

  { // Node ID: 2105 (NodeStreamOffset)
    const HWFloat<8,24> &id2105in_input = id1243out_result[getCycle()%2];

    id2105out_output = id2105in_input;
  }
  { // Node ID: 1262 (NodeConstantRawBits)
  }
  { // Node ID: 1263 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1263in_sel = id2139out_output[getCycle()%4];
    const HWFloat<8,24> &id1263in_option0 = id2105out_output;
    const HWFloat<8,24> &id1263in_option1 = id1262out_value;

    HWFloat<8,24> id1263x_1;

    switch((id1263in_sel.getValueAsLong())) {
      case 0l:
        id1263x_1 = id1263in_option0;
        break;
      case 1l:
        id1263x_1 = id1263in_option1;
        break;
      default:
        id1263x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1263out_result[(getCycle()+1)%2] = (id1263x_1);
  }
  { // Node ID: 19 (NodeConstantRawBits)
  }
  { // Node ID: 20 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_sel = id10out_result[getCycle()%2];
    const HWFloat<8,24> &id20in_option0 = id1263out_result[getCycle()%2];
    const HWFloat<8,24> &id20in_option1 = id19out_value;

    HWFloat<8,24> id20x_1;

    switch((id20in_sel.getValueAsLong())) {
      case 0l:
        id20x_1 = id20in_option0;
        break;
      case 1l:
        id20x_1 = id20in_option1;
        break;
      default:
        id20x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id20out_result[(getCycle()+1)%2] = (id20x_1);
  }
  { // Node ID: 1192 (NodeMul)
    const HWFloat<8,24> &id1192in_a = id20out_result[getCycle()%2];
    const HWFloat<8,24> &id1192in_b = id20out_result[getCycle()%2];

    id1192out_result[(getCycle()+8)%9] = (mul_float(id1192in_a,id1192in_b));
  }
  { // Node ID: 1193 (NodeAdd)
    const HWFloat<8,24> &id1193in_a = id1191out_result[getCycle()%9];
    const HWFloat<8,24> &id1193in_b = id1192out_result[getCycle()%9];

    id1193out_result[(getCycle()+11)%12] = (add_float(id1193in_a,id1193in_b));
  }
  { // Node ID: 2367 (NodeFIFO)
    const HWFloat<8,24> &id2367in_input = id1193out_result[getCycle()%12];

    id2367out_output[(getCycle()+25)%26] = id2367in_input;
  }
  { // Node ID: 1838 (NodeConstantRawBits)
  }
  { // Node ID: 1195 (NodeGt)
    const HWFloat<8,24> &id1195in_a = id2367out_output[getCycle()%26];
    const HWFloat<8,24> &id1195in_b = id1838out_value;

    id1195out_result[(getCycle()+2)%3] = (gt_float(id1195in_a,id1195in_b));
  }
  { // Node ID: 2250 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2250in_input = id1195out_result[getCycle()%3];

    id2250out_output[(getCycle()+20)%21] = id2250in_input;
  }
  { // Node ID: 2445 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2445in_input = id2250out_output[getCycle()%21];

    id2445out_output[(getCycle()+2)%3] = id2445in_input;
  }
  { // Node ID: 2446 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2446in_input = id2445out_output[getCycle()%3];

    id2446out_output[(getCycle()+18)%19] = id2446in_input;
  }
  { // Node ID: 1202 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1202in_a = id1201out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1202in_b = id2446out_output[getCycle()%19];

    HWOffsetFix<1,0,UNSIGNED> id1202x_1;

    (id1202x_1) = (and_fixed(id1202in_a,id1202in_b));
    id1202out_result[(getCycle()+1)%2] = (id1202x_1);
  }
  { // Node ID: 2437 (NodeFIFO)
    const HWFloat<8,24> &id2437in_input = id2346out_output[getCycle()%20];

    id2437out_output[(getCycle()+39)%40] = id2437in_input;
  }
  { // Node ID: 1203 (NodeMul)
    const HWFloat<8,24> &id1203in_a = id2369out_output[getCycle()%22];
    const HWFloat<8,24> &id1203in_b = id22out_result[getCycle()%2];

    id1203out_result[(getCycle()+8)%9] = (mul_float(id1203in_a,id1203in_b));
  }
  { // Node ID: 1204 (NodeMul)
    const HWFloat<8,24> &id1204in_a = id1203out_result[getCycle()%9];
    const HWFloat<8,24> &id1204in_b = id664out_result[getCycle()%9];

    id1204out_result[(getCycle()+8)%9] = (mul_float(id1204in_a,id1204in_b));
  }
  { // Node ID: 1205 (NodeMul)
    const HWFloat<8,24> &id1205in_a = id2440out_output[getCycle()%9];
    const HWFloat<8,24> &id1205in_b = id1190out_result[getCycle()%9];

    id1205out_result[(getCycle()+8)%9] = (mul_float(id1205in_a,id1205in_b));
  }
  { // Node ID: 1206 (NodeSub)
    const HWFloat<8,24> &id1206in_a = id1204out_result[getCycle()%9];
    const HWFloat<8,24> &id1206in_b = id1205out_result[getCycle()%9];

    id1206out_result[(getCycle()+11)%12] = (sub_float(id1206in_a,id1206in_b));
  }
  { // Node ID: 1207 (NodeDiv)
    const HWFloat<8,24> &id1207in_a = id1206out_result[getCycle()%12];
    const HWFloat<8,24> &id1207in_b = id1200out_result[getCycle()%2];

    id1207out_result[(getCycle()+28)%29] = (div_float(id1207in_a,id1207in_b));
  }
  { // Node ID: 1208 (NodeMul)
    const HWFloat<8,24> &id1208in_a = id2448out_output[getCycle()%40];
    const HWFloat<8,24> &id1208in_b = id2433out_output[getCycle()%2];

    id1208out_result[(getCycle()+8)%9] = (mul_float(id1208in_a,id1208in_b));
  }
  { // Node ID: 1209 (NodeAdd)
    const HWFloat<8,24> &id1209in_a = id1207out_result[getCycle()%29];
    const HWFloat<8,24> &id1209in_b = id1208out_result[getCycle()%9];

    id1209out_result[(getCycle()+11)%12] = (add_float(id1209in_a,id1209in_b));
  }
  { // Node ID: 1210 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1210in_sel = id1202out_result[getCycle()%2];
    const HWFloat<8,24> &id1210in_option0 = id2437out_output[getCycle()%40];
    const HWFloat<8,24> &id1210in_option1 = id1209out_result[getCycle()%12];

    HWFloat<8,24> id1210x_1;

    switch((id1210in_sel.getValueAsLong())) {
      case 0l:
        id1210x_1 = id1210in_option0;
        break;
      case 1l:
        id1210x_1 = id1210in_option1;
        break;
      default:
        id1210x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1210out_result[(getCycle()+1)%2] = (id1210x_1);
  }
  HWRawBits<1> id2082out_result;

  { // Node ID: 2082 (NodeSlice)
    const HWFloat<8,24> &id2082in_a = id1210out_result[getCycle()%2];

    id2082out_result = (slice<31,1>(id2082in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1232out_result;

  { // Node ID: 1232 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1232in_a = id2426out_output[getCycle()%4];

    id1232out_result = (not_fixed(id1232in_a));
  }
  { // Node ID: 1233 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1233in_a = id1232out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1233in_b = id1231out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1233x_1;

    (id1233x_1) = (and_fixed(id1233in_a,id1233in_b));
    id1233out_result[(getCycle()+1)%2] = (id1233x_1);
  }
  { // Node ID: 2375 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2375in_input = id1233out_result[getCycle()%2];

    id2375out_output[(getCycle()+18)%19] = id2375in_input;
  }
  HWRawBits<1> id2083out_result;

  { // Node ID: 2083 (NodeXor)
    const HWRawBits<1> &id2083in_a = id2082out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2083in_b = id2375out_output[getCycle()%19];

    HWRawBits<1> id2083x_1;

    (id2083x_1) = (xor_bits(id2083in_a,(cast_fixed2bits(id2083in_b))));
    id2083out_result = (id2083x_1);
  }
  HWRawBits<31> id2081out_result;

  { // Node ID: 2081 (NodeSlice)
    const HWFloat<8,24> &id2081in_a = id1210out_result[getCycle()%2];

    id2081out_result = (slice<0,31>(id2081in_a));
  }
  HWRawBits<32> id2084out_result;

  { // Node ID: 2084 (NodeCat)
    const HWRawBits<1> &id2084in_in0 = id2083out_result;
    const HWRawBits<31> &id2084in_in1 = id2081out_result;

    id2084out_result = (cat(id2084in_in0,id2084in_in1));
  }
  HWFloat<8,24> id2085out_output;

  { // Node ID: 2085 (NodeReinterpret)
    const HWRawBits<32> &id2085in_input = id2084out_result;

    id2085out_output = (cast_bits2float<8,24>(id2085in_input));
  }
  { // Node ID: 1241 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1241in_sel = id1240out_result;
    const HWFloat<8,24> &id1241in_option0 = id2450out_output[getCycle()%19];
    const HWFloat<8,24> &id1241in_option1 = id2085out_output;

    HWFloat<8,24> id1241x_1;

    switch((id1241in_sel.getValueAsLong())) {
      case 0l:
        id1241x_1 = id1241in_option0;
        break;
      case 1l:
        id1241x_1 = id1241in_option1;
        break;
      default:
        id1241x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1241out_result[(getCycle()+1)%2] = (id1241x_1);
  }
  HWFloat<8,24> id2106out_output;

  { // Node ID: 2106 (NodeStreamOffset)
    const HWFloat<8,24> &id2106in_input = id1241out_result[getCycle()%2];

    id2106out_output = id2106in_input;
  }
  { // Node ID: 1260 (NodeConstantRawBits)
  }
  { // Node ID: 1261 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1261in_sel = id2139out_output[getCycle()%4];
    const HWFloat<8,24> &id1261in_option0 = id2106out_output;
    const HWFloat<8,24> &id1261in_option1 = id1260out_value;

    HWFloat<8,24> id1261x_1;

    switch((id1261in_sel.getValueAsLong())) {
      case 0l:
        id1261x_1 = id1261in_option0;
        break;
      case 1l:
        id1261x_1 = id1261in_option1;
        break;
      default:
        id1261x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1261out_result[(getCycle()+1)%2] = (id1261x_1);
  }
  { // Node ID: 17 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_sel = id10out_result[getCycle()%2];
    const HWFloat<8,24> &id18in_option0 = id1261out_result[getCycle()%2];
    const HWFloat<8,24> &id18in_option1 = id17out_value;

    HWFloat<8,24> id18x_1;

    switch((id18in_sel.getValueAsLong())) {
      case 0l:
        id18x_1 = id18in_option0;
        break;
      case 1l:
        id18x_1 = id18in_option1;
        break;
      default:
        id18x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id18out_result[(getCycle()+1)%2] = (id18x_1);
  }
  { // Node ID: 2369 (NodeFIFO)
    const HWFloat<8,24> &id2369in_input = id18out_result[getCycle()%2];

    id2369out_output[(getCycle()+21)%22] = id2369in_input;
  }
  { // Node ID: 2447 (NodeFIFO)
    const HWFloat<8,24> &id2447in_input = id2369out_output[getCycle()%22];

    id2447out_output[(getCycle()+8)%9] = id2447in_input;
  }
  { // Node ID: 2448 (NodeFIFO)
    const HWFloat<8,24> &id2448in_input = id2447out_output[getCycle()%9];

    id2448out_output[(getCycle()+39)%40] = id2448in_input;
  }
  { // Node ID: 2449 (NodeFIFO)
    const HWFloat<8,24> &id2449in_input = id2448out_output[getCycle()%40];

    id2449out_output[(getCycle()+2)%3] = id2449in_input;
  }
  { // Node ID: 2416 (NodeFIFO)
    const HWFloat<8,24> &id2416in_input = id2137out_output[getCycle()%80];

    id2416out_output[(getCycle()+36)%37] = id2416in_input;
  }
  { // Node ID: 1836 (NodeConstantRawBits)
  }
  { // Node ID: 2414 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2414in_input = id2139out_output[getCycle()%4];

    id2414out_output[(getCycle()+58)%59] = id2414in_input;
  }
  { // Node ID: 2378 (NodeFIFO)
    const HWFloat<8,24> &id2378in_input = id24out_result[getCycle()%2];

    id2378out_output[(getCycle()+12)%13] = id2378in_input;
  }
  { // Node ID: 117 (NodeAdd)
    const HWFloat<8,24> &id117in_a = id2378out_output[getCycle()%13];
    const HWFloat<8,24> &id117in_b = id110out_result[getCycle()%2];

    id117out_result[(getCycle()+11)%12] = (add_float(id117in_a,id117in_b));
  }
  { // Node ID: 2405 (NodeFIFO)
    const HWFloat<8,24> &id2405in_input = id117out_result[getCycle()%12];

    id2405out_output[(getCycle()+8)%9] = id2405in_input;
  }
  { // Node ID: 2452 (NodeFIFO)
    const HWFloat<8,24> &id2452in_input = id2405out_output[getCycle()%9];

    id2452out_output[(getCycle()+58)%59] = id2452in_input;
  }
  HWFloat<8,24> id2107out_output;

  { // Node ID: 2107 (NodeStreamOffset)
    const HWFloat<8,24> &id2107in_input = id2452out_output[getCycle()%59];

    id2107out_output = id2107in_input;
  }
  { // Node ID: 1266 (NodeConstantRawBits)
  }
  { // Node ID: 1267 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1267in_sel = id2414out_output[getCycle()%59];
    const HWFloat<8,24> &id1267in_option0 = id2107out_output;
    const HWFloat<8,24> &id1267in_option1 = id1266out_value;

    HWFloat<8,24> id1267x_1;

    switch((id1267in_sel.getValueAsLong())) {
      case 0l:
        id1267x_1 = id1267in_option0;
        break;
      case 1l:
        id1267x_1 = id1267in_option1;
        break;
      default:
        id1267x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1267out_result[(getCycle()+1)%2] = (id1267x_1);
  }
  { // Node ID: 23 (NodeConstantRawBits)
  }
  { // Node ID: 24 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_sel = id2423out_output[getCycle()%26];
    const HWFloat<8,24> &id24in_option0 = id1267out_result[getCycle()%2];
    const HWFloat<8,24> &id24in_option1 = id23out_value;

    HWFloat<8,24> id24x_1;

    switch((id24in_sel.getValueAsLong())) {
      case 0l:
        id24x_1 = id24in_option0;
        break;
      case 1l:
        id24x_1 = id24in_option1;
        break;
      default:
        id24x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id24out_result[(getCycle()+1)%2] = (id24x_1);
  }
  { // Node ID: 109 (NodeSub)
    const HWFloat<8,24> &id109in_a = id1836out_value;
    const HWFloat<8,24> &id109in_b = id24out_result[getCycle()%2];

    id109out_result[(getCycle()+11)%12] = (sub_float(id109in_a,id109in_b));
  }
  { // Node ID: 110 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id110in_sel = id2426out_output[getCycle()%4];
    const HWFloat<8,24> &id110in_option0 = id2416out_output[getCycle()%37];
    const HWFloat<8,24> &id110in_option1 = id109out_result[getCycle()%12];

    HWFloat<8,24> id110x_1;

    switch((id110in_sel.getValueAsLong())) {
      case 0l:
        id110x_1 = id110in_option0;
        break;
      case 1l:
        id110x_1 = id110in_option1;
        break;
      default:
        id110x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id110out_result[(getCycle()+1)%2] = (id110x_1);
  }
  { // Node ID: 111 (NodeMul)
    const HWFloat<8,24> &id111in_a = id2449out_output[getCycle()%3];
    const HWFloat<8,24> &id111in_b = id110out_result[getCycle()%2];

    id111out_result[(getCycle()+8)%9] = (mul_float(id111in_a,id111in_b));
  }
  { // Node ID: 112 (NodeAdd)
    const HWFloat<8,24> &id112in_a = id12out_result[getCycle()%2];
    const HWFloat<8,24> &id112in_b = id111out_result[getCycle()%9];

    id112out_result[(getCycle()+11)%12] = (add_float(id112in_a,id112in_b));
  }
  HWFloat<8,24> id2108out_output;

  { // Node ID: 2108 (NodeStreamOffset)
    const HWFloat<8,24> &id2108in_input = id112out_result[getCycle()%12];

    id2108out_output = id2108in_input;
  }
  { // Node ID: 1254 (NodeConstantRawBits)
  }
  { // Node ID: 1255 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1255in_sel = id2139out_output[getCycle()%4];
    const HWFloat<8,24> &id1255in_option0 = id2108out_output;
    const HWFloat<8,24> &id1255in_option1 = id1254out_value;

    HWFloat<8,24> id1255x_1;

    switch((id1255in_sel.getValueAsLong())) {
      case 0l:
        id1255x_1 = id1255in_option0;
        break;
      case 1l:
        id1255x_1 = id1255in_option1;
        break;
      default:
        id1255x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1255out_result[(getCycle()+1)%2] = (id1255x_1);
  }
  { // Node ID: 2141 (NodeFIFO)
    const HWFloat<8,24> &id2141in_input = id1255out_result[getCycle()%2];

    id2141out_output[(getCycle()+78)%79] = id2141in_input;
  }
  { // Node ID: 2454 (NodeFIFO)
    const HWFloat<8,24> &id2454in_input = id2141out_output[getCycle()%79];

    id2454out_output[(getCycle()+12)%13] = id2454in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1361 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1361in_output_control = id1359out_value;
    const HWFloat<8,24> &id1361in_data = id2454out_output[getCycle()%13];

    bool id1361x_1;

    (id1361x_1) = ((id1361in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1361x_1)) {
      writeOutput(m_internal_watch_carriedposx_output, id1361in_data);
    }
  }
  { // Node ID: 15 (NodeConstantRawBits)
  }
  { // Node ID: 16 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_sel = id2424out_output[getCycle()%21];
    const HWFloat<8,24> &id16in_option0 = id2388out_output[getCycle()%79];
    const HWFloat<8,24> &id16in_option1 = id15out_value;

    HWFloat<8,24> id16x_1;

    switch((id16in_sel.getValueAsLong())) {
      case 0l:
        id16x_1 = id16in_option0;
        break;
      case 1l:
        id16x_1 = id16in_option1;
        break;
      default:
        id16x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id16out_result[(getCycle()+1)%2] = (id16x_1);
  }
  { // Node ID: 115 (NodeMul)
    const HWFloat<8,24> &id115in_a = id2439out_output[getCycle()%5];
    const HWFloat<8,24> &id115in_b = id110out_result[getCycle()%2];

    id115out_result[(getCycle()+8)%9] = (mul_float(id115in_a,id115in_b));
  }
  { // Node ID: 116 (NodeAdd)
    const HWFloat<8,24> &id116in_a = id16out_result[getCycle()%2];
    const HWFloat<8,24> &id116in_b = id115out_result[getCycle()%9];

    id116out_result[(getCycle()+11)%12] = (add_float(id116in_a,id116in_b));
  }
  HWFloat<8,24> id2109out_output;

  { // Node ID: 2109 (NodeStreamOffset)
    const HWFloat<8,24> &id2109in_input = id116out_result[getCycle()%12];

    id2109out_output = id2109in_input;
  }
  { // Node ID: 1258 (NodeConstantRawBits)
  }
  { // Node ID: 1259 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1259in_sel = id2139out_output[getCycle()%4];
    const HWFloat<8,24> &id1259in_option0 = id2109out_output;
    const HWFloat<8,24> &id1259in_option1 = id1258out_value;

    HWFloat<8,24> id1259x_1;

    switch((id1259in_sel.getValueAsLong())) {
      case 0l:
        id1259x_1 = id1259in_option0;
        break;
      case 1l:
        id1259x_1 = id1259in_option1;
        break;
      default:
        id1259x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1259out_result[(getCycle()+1)%2] = (id1259x_1);
  }
  { // Node ID: 2388 (NodeFIFO)
    const HWFloat<8,24> &id2388in_input = id1259out_result[getCycle()%2];

    id2388out_output[(getCycle()+78)%79] = id2388in_input;
  }
  { // Node ID: 2455 (NodeFIFO)
    const HWFloat<8,24> &id2455in_input = id2388out_output[getCycle()%79];

    id2455out_output[(getCycle()+12)%13] = id2455in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1362 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1362in_output_control = id1359out_value;
    const HWFloat<8,24> &id1362in_data = id2455out_output[getCycle()%13];

    bool id1362x_1;

    (id1362x_1) = ((id1362in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1362x_1)) {
      writeOutput(m_internal_watch_carriedposz_output, id1362in_data);
    }
  }
  { // Node ID: 2392 (NodeFIFO)
    const HWFloat<8,24> &id2392in_input = id1261out_result[getCycle()%2];

    id2392out_output[(getCycle()+90)%91] = id2392in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1363 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1363in_output_control = id1359out_value;
    const HWFloat<8,24> &id1363in_data = id2392out_output[getCycle()%91];

    bool id1363x_1;

    (id1363x_1) = ((id1363in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1363x_1)) {
      writeOutput(m_internal_watch_carrieddirx_output, id1363in_data);
    }
  }
  { // Node ID: 2421 (NodeFIFO)
    const HWFloat<8,24> &id2421in_input = id2112out_output[getCycle()%37];

    id2421out_output[(getCycle()+57)%58] = id2421in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1364 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1364in_output_control = id1359out_value;
    const HWFloat<8,24> &id1364in_data = id2421out_output[getCycle()%58];

    bool id1364x_1;

    (id1364x_1) = ((id1364in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1364x_1)) {
      writeOutput(m_internal_watch_carriedlength_output, id1364in_data);
    }
  }
  { // Node ID: 2394 (NodeFIFO)
    const HWFloat<8,24> &id2394in_input = id16out_result[getCycle()%2];

    id2394out_output[(getCycle()+11)%12] = id2394in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1365 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1365in_output_control = id1359out_value;
    const HWFloat<8,24> &id1365in_data = id2394out_output[getCycle()%12];

    bool id1365x_1;

    (id1365x_1) = ((id1365in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1365x_1)) {
      writeOutput(m_internal_watch_posz_output, id1365in_data);
    }
  }
  { // Node ID: 2451 (NodeFIFO)
    const HWFloat<8,24> &id2451in_input = id2450out_output[getCycle()%19];

    id2451out_output[(getCycle()+1)%2] = id2451in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1366 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1366in_output_control = id1359out_value;
    const HWFloat<8,24> &id1366in_data = id2451out_output[getCycle()%2];

    bool id1366x_1;

    (id1366x_1) = ((id1366in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1366x_1)) {
      writeOutput(m_internal_watch_dirx_output, id1366in_data);
    }
  }
  { // Node ID: 2453 (NodeFIFO)
    const HWFloat<8,24> &id2453in_input = id2378out_output[getCycle()%13];

    id2453out_output[(getCycle()+19)%20] = id2453in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1367 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1367in_output_control = id1359out_value;
    const HWFloat<8,24> &id1367in_data = id2453out_output[getCycle()%20];

    bool id1367x_1;

    (id1367x_1) = ((id1367in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1367x_1)) {
      writeOutput(m_internal_watch_tracklength_output, id1367in_data);
    }
  }
  { // Node ID: 2425 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2425in_input = id2424out_output[getCycle()%21];

    id2425out_output[(getCycle()+12)%13] = id2425in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1368 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1368in_output_control = id1359out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1368in_data = id2425out_output[getCycle()%13];

    bool id1368x_1;

    (id1368x_1) = ((id1368in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1368x_1)) {
      writeOutput(m_internal_watch_reset_output, id1368in_data);
    }
  }
  { // Node ID: 2431 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2431in_input = id2430out_output[getCycle()%3];

    id2431out_output[(getCycle()+1)%2] = id2431in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1369 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1369in_output_control = id1359out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1369in_data = id2431out_output[getCycle()%2];

    bool id1369x_1;

    (id1369x_1) = ((id1369in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1369x_1)) {
      writeOutput(m_internal_watch_pastlimit_output, id1369in_data);
    }
  }
  { // Node ID: 2409 (NodeFIFO)
    const HWFloat<8,24> &id2409in_input = id2103out_output;

    id2409out_output[(getCycle()+86)%87] = id2409in_input;
  }
  { // Node ID: 2420 (NodeFIFO)
    const HWFloat<8,24> &id2420in_input = id2409out_output[getCycle()%87];

    id2420out_output[(getCycle()+8)%9] = id2420in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1370 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1370in_output_control = id1359out_value;
    const HWFloat<8,24> &id1370in_data = id2420out_output[getCycle()%9];

    bool id1370x_1;

    (id1370x_1) = ((id1370in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1370x_1)) {
      writeOutput(m_internal_watch_lengthoffset_output, id1370in_data);
    }
  }
  { // Node ID: 2419 (NodeFIFO)
    const HWFloat<8,24> &id2419in_input = id2418out_output[getCycle()%6];

    id2419out_output[(getCycle()+3)%4] = id2419in_input;
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1371 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1371in_output_control = id1359out_value;
    const HWFloat<8,24> &id1371in_data = id2419out_output[getCycle()%4];

    bool id1371x_1;

    (id1371x_1) = ((id1371in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1371x_1)) {
      writeOutput(m_internal_watch_length_output, id1371in_data);
    }
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1372 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1372in_output_control = id1359out_value;
    const HWFloat<8,24> &id1372in_data = id112out_result[getCycle()%12];

    bool id1372x_1;

    (id1372x_1) = ((id1372in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1372x_1)) {
      writeOutput(m_internal_watch_track_0_output, id1372in_data);
    }
  }
  HWFloat<8,24> id2110out_output;

  { // Node ID: 2110 (NodeStreamOffset)
    const HWFloat<8,24> &id2110in_input = id114out_result[getCycle()%12];

    id2110out_output = id2110in_input;
  }
  { // Node ID: 1256 (NodeConstantRawBits)
  }
  { // Node ID: 1257 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1257in_sel = id2139out_output[getCycle()%4];
    const HWFloat<8,24> &id1257in_option0 = id2110out_output;
    const HWFloat<8,24> &id1257in_option1 = id1256out_value;

    HWFloat<8,24> id1257x_1;

    switch((id1257in_sel.getValueAsLong())) {
      case 0l:
        id1257x_1 = id1257in_option0;
        break;
      case 1l:
        id1257x_1 = id1257in_option1;
        break;
      default:
        id1257x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1257out_result[(getCycle()+1)%2] = (id1257x_1);
  }
  { // Node ID: 13 (NodeConstantRawBits)
  }
  { // Node ID: 14 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_sel = id10out_result[getCycle()%2];
    const HWFloat<8,24> &id14in_option0 = id1257out_result[getCycle()%2];
    const HWFloat<8,24> &id14in_option1 = id13out_value;

    HWFloat<8,24> id14x_1;

    switch((id14in_sel.getValueAsLong())) {
      case 0l:
        id14x_1 = id14in_option0;
        break;
      case 1l:
        id14x_1 = id14in_option1;
        break;
      default:
        id14x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id14out_result[(getCycle()+1)%2] = (id14x_1);
  }
  { // Node ID: 2403 (NodeFIFO)
    const HWFloat<8,24> &id2403in_input = id14out_result[getCycle()%2];

    id2403out_output[(getCycle()+78)%79] = id2403in_input;
  }
  { // Node ID: 113 (NodeMul)
    const HWFloat<8,24> &id113in_a = id2442out_output[getCycle()%3];
    const HWFloat<8,24> &id113in_b = id110out_result[getCycle()%2];

    id113out_result[(getCycle()+8)%9] = (mul_float(id113in_a,id113in_b));
  }
  { // Node ID: 114 (NodeAdd)
    const HWFloat<8,24> &id114in_a = id2403out_output[getCycle()%79];
    const HWFloat<8,24> &id114in_b = id113out_result[getCycle()%9];

    id114out_result[(getCycle()+11)%12] = (add_float(id114in_a,id114in_b));
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1373 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1373in_output_control = id1359out_value;
    const HWFloat<8,24> &id1373in_data = id114out_result[getCycle()%12];

    bool id1373x_1;

    (id1373x_1) = ((id1373in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1373x_1)) {
      writeOutput(m_internal_watch_track_1_output, id1373in_data);
    }
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1374 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1374in_output_control = id1359out_value;
    const HWFloat<8,24> &id1374in_data = id116out_result[getCycle()%12];

    bool id1374x_1;

    (id1374x_1) = ((id1374in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1374x_1)) {
      writeOutput(m_internal_watch_track_2_output, id1374in_data);
    }
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1375 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1375in_output_control = id1359out_value;
    const HWFloat<8,24> &id1375in_data = id1241out_result[getCycle()%2];

    bool id1375x_1;

    (id1375x_1) = ((id1375in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1375x_1)) {
      writeOutput(m_internal_watch_track_3_output, id1375in_data);
    }
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1376 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1376in_output_control = id1359out_value;
    const HWFloat<8,24> &id1376in_data = id1243out_result[getCycle()%2];

    bool id1376x_1;

    (id1376x_1) = ((id1376in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1376x_1)) {
      writeOutput(m_internal_watch_track_4_output, id1376in_data);
    }
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1377 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1377in_output_control = id1359out_value;
    const HWFloat<8,24> &id1377in_data = id2356out_output[getCycle()%19];

    bool id1377x_1;

    (id1377x_1) = ((id1377in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1377x_1)) {
      writeOutput(m_internal_watch_track_5_output, id1377in_data);
    }
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1378 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1378in_output_control = id1359out_value;
    const HWFloat<8,24> &id1378in_data = id2405out_output[getCycle()%9];

    bool id1378x_1;

    (id1378x_1) = ((id1378in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1378x_1)) {
      writeOutput(m_internal_watch_track_6_output, id1378in_data);
    }
  }
  if ( (getFillLevel() >= (0l)) && (getFlushLevel() < (0l)|| !isFlushingActive() ))
  { // Node ID: 2 (NodeWatch)
  }
  { // Node ID: 118 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (190l)) && (getFlushLevel() < (190l)|| !isFlushingActive() ))
  { // Node ID: 119 (NodePrintf)
    const HWOffsetFix<1,0,UNSIGNED> &id119in_condition = id118out_value;
    const HWFloat<8,24> &id119in_arg0 = id117out_result[getCycle()%12];
    const HWOffsetFix<1,0,UNSIGNED> &id119in_arg1 = id2428out_output[getCycle()%12];

    if((id119in_condition.getValueAsBool())) {
      const HWFloat<8,24> &_format_arg_0 = id119in_arg0;
      const HWOffsetFix<1,0,UNSIGNED> &_format_arg_1 = id119in_arg1;
      simPrintf("", 119, format_string_loopKernel_1("%f %i\n", _format_arg_0, _format_arg_1));
    }
  }
  { // Node ID: 1272 (NodeConstantRawBits)
  }
  { // Node ID: 1273 (NodeConstantRawBits)
  }
  { // Node ID: 2410 (NodeFIFO)
    const HWFloat<8,24> &id2410in_input = id2107out_output;

    id2410out_output[(getCycle()+25)%26] = id2410in_input;
  }
  { // Node ID: 1835 (NodeConstantRawBits)
  }
  { // Node ID: 1271 (NodeGt)
    const HWFloat<8,24> &id1271in_a = id2407out_output[getCycle()%36];
    const HWFloat<8,24> &id1271in_b = id1835out_value;

    id1271out_result[(getCycle()+2)%3] = (gt_float(id1271in_a,id1271in_b));
  }
  if ( (getFillLevel() >= (190l)) && (getFlushLevel() < (190l)|| !isFlushingActive() ))
  { // Node ID: 1274 (NodePrintf)
    const HWOffsetFix<1,0,UNSIGNED> &id1274in_condition = id1272out_value;
    const HWFloat<11,53> &id1274in_arg0 = id1273out_value;
    const HWFloat<8,24> &id1274in_arg1 = id117out_result[getCycle()%12];
    const HWFloat<8,24> &id1274in_arg2 = id2417out_output[getCycle()%3];
    const HWFloat<8,24> &id1274in_arg3 = id2409out_output[getCycle()%87];
    const HWFloat<8,24> &id1274in_arg4 = id2410out_output[getCycle()%26];
    const HWOffsetFix<1,0,UNSIGNED> &id1274in_arg5 = id1271out_result[getCycle()%3];

    if((id1274in_condition.getValueAsBool())) {
      const HWFloat<11,53> &_format_arg_0 = id1274in_arg0;
      const HWFloat<8,24> &_format_arg_1 = id1274in_arg1;
      const HWFloat<8,24> &_format_arg_2 = id1274in_arg2;
      const HWFloat<8,24> &_format_arg_3 = id1274in_arg3;
      const HWFloat<8,24> &_format_arg_4 = id1274in_arg4;
      const HWOffsetFix<1,0,UNSIGNED> &_format_arg_5 = id1274in_arg5;
      simPrintf("", 1274, format_string_loopKernel_2("%f %f %f %f %f %i\n", _format_arg_0, _format_arg_1, _format_arg_2, _format_arg_3, _format_arg_4, _format_arg_5));
    }
  }
  { // Node ID: 1275 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1276out_result;

  { // Node ID: 1276 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1276in_a = id1275out_io_z_force_disabled;

    id1276out_result = (not_fixed(id1276in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1277out_result;

  { // Node ID: 1277 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1277in_a = id2431out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1277in_b = id1276out_result;

    HWOffsetFix<1,0,UNSIGNED> id1277x_1;

    (id1277x_1) = (and_fixed(id1277in_a,id1277in_b));
    id1277out_result = (id1277x_1);
  }
  HWRawBits<224> id1733out_result;

  { // Node ID: 1733 (NodeCat)
    const HWFloat<8,24> &id1733in_in0 = id2405out_output[getCycle()%9];
    const HWFloat<8,24> &id1733in_in1 = id2356out_output[getCycle()%19];
    const HWFloat<8,24> &id1733in_in2 = id1243out_result[getCycle()%2];
    const HWFloat<8,24> &id1733in_in3 = id1241out_result[getCycle()%2];
    const HWFloat<8,24> &id1733in_in4 = id116out_result[getCycle()%12];
    const HWFloat<8,24> &id1733in_in5 = id114out_result[getCycle()%12];
    const HWFloat<8,24> &id1733in_in6 = id112out_result[getCycle()%12];

    id1733out_result = (cat((cat((cat(id1733in_in0,id1733in_in1)),(cat(id1733in_in2,id1733in_in3)))),(cat((cat(id1733in_in4,id1733in_in5)),id1733in_in6))));
  }
  if ( (getFillLevel() >= (198l)) && (getFlushLevel() < (198l)|| !isFlushingActive() ))
  { // Node ID: 1278 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1278in_output_control = id1277out_result;
    const HWRawBits<224> &id1278in_data = id1733out_result;

    bool id1278x_1;

    (id1278x_1) = ((id1278in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    if((id1278x_1)) {
      writeOutput(m_z, id1278in_data);
    }
  }
  { // Node ID: 1351 (NodeConstantRawBits)
  }
  { // Node ID: 1834 (NodeConstantRawBits)
  }
  { // Node ID: 1348 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 1349 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id1349in_enable = id1834out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id1349in_max = id1348out_value;

    HWOffsetFix<49,0,UNSIGNED> id1349x_1;
    HWOffsetFix<1,0,UNSIGNED> id1349x_2;
    HWOffsetFix<1,0,UNSIGNED> id1349x_3;
    HWOffsetFix<49,0,UNSIGNED> id1349x_4t_1e_1;

    id1349out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id1349st_count)));
    (id1349x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id1349st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id1349x_2) = (gte_fixed((id1349x_1),id1349in_max));
    (id1349x_3) = (and_fixed((id1349x_2),id1349in_enable));
    id1349out_wrap = (id1349x_3);
    if((id1349in_enable.getValueAsBool())) {
      if(((id1349x_3).getValueAsBool())) {
        (id1349st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id1349x_4t_1e_1) = (id1349x_1);
        (id1349st_count) = (id1349x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id1350out_output;

  { // Node ID: 1350 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id1350in_input = id1349out_count;

    id1350out_output = id1350in_input;
  }
  if ( (getFillLevel() >= (1l)) && (getFlushLevel() < (1l)|| !isFlushingActive() ))
  { // Node ID: 1352 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id1352in_load = id1351out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id1352in_data = id1350out_output;

    bool id1352x_1;

    (id1352x_1) = ((id1352in_load.getValueAsBool())&(!(((getFlushLevel())>=(1l))&(isFlushingActive()))));
    if((id1352x_1)) {
      setMappedRegValue("current_run_cycle_count", id1352in_data);
    }
  }
  { // Node ID: 0 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 1356 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id1356in_start = id0out_value;

    if((id1356in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
