#include "stdsimheader.h"

namespace maxcompilersim {

void loopKernel::execute0() {
  HWFloat<8,24> id2059out_output;

  { // Node ID: 2059 (NodeStreamOffset)
    const HWFloat<8,24> &id2059in_input = id106out_result[getCycle()%12];

    id2059out_output = id2059in_input;
  }
  { // Node ID: 2068 (NodeFIFO)
    const HWFloat<8,24> &id2068in_input = id2059out_output;

    id2068out_output[(getCycle()+75)%76] = id2068in_input;
  }
  { // Node ID: 1980 (NodeConstantRawBits)
  }
  { // Node ID: 7 (NodeGt)
    const HWFloat<8,24> &id7in_a = id2068out_output[getCycle()%76];
    const HWFloat<8,24> &id7in_b = id1980out_value;

    id7out_result[(getCycle()+2)%3] = (gt_float(id7in_a,id7in_b));
  }
  { // Node ID: 2 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (94l)))
  { // Node ID: 3 (NodePulse)
    const HWOffsetFix<1,0,UNSIGNED> &id3in_enable = id2out_value;

    if(((id3st_count)==(1l))) {
      (id3st_value) = (c_hw_fix_1_0_uns_bits_1);
    }
    if((id3in_enable.getValueAsBool())) {
      (id3st_count) = ((id3st_count)+(1l));
    }
    id3out_output = (id3st_value);
  }
  { // Node ID: 8 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_a = id7out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id8in_b = id3out_output;

    HWOffsetFix<1,0,UNSIGNED> id8x_1;

    (id8x_1) = (or_fixed(id8in_a,id8in_b));
    id8out_result[(getCycle()+1)%2] = (id8x_1);
  }
  { // Node ID: 2346 (NodeFIFO)
    const HWFloat<8,24> &id2346in_input = id2068out_output[getCycle()%76];

    id2346out_output[(getCycle()+3)%4] = id2346in_input;
  }
  { // Node ID: 23 (NodeConstantRawBits)
  }
  { // Node ID: 24 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_sel = id8out_result[getCycle()%2];
    const HWFloat<8,24> &id24in_option0 = id2346out_output[getCycle()%4];
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
  { // Node ID: 1979 (NodeConstantRawBits)
  }
  { // Node ID: 1978 (NodeConstantRawBits)
  }
  { // Node ID: 2373 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 5 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_enable = id1978out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id5in_max = id2373out_value;

    HWOffsetFix<33,0,UNSIGNED> id5x_1;
    HWOffsetFix<1,0,UNSIGNED> id5x_2;
    HWOffsetFix<1,0,UNSIGNED> id5x_3;
    HWOffsetFix<33,0,UNSIGNED> id5x_4t_1e_1;

    id5out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id5st_count)));
    (id5x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id5st_count),(c_hw_fix_33_0_uns_bits_1)));
    (id5x_2) = (gte_fixed((id5x_1),(cast_fixed2fixed<33,0,UNSIGNED,TRUNCATE>(id5in_max))));
    (id5x_3) = (and_fixed((id5x_2),id5in_enable));
    id5out_wrap = (id5x_3);
    if((id5in_enable.getValueAsBool())) {
      if(((id5x_3).getValueAsBool())) {
        (id5st_count) = (c_hw_fix_33_0_uns_bits);
      }
      else {
        (id5x_4t_1e_1) = (id5x_1);
        (id5st_count) = (id5x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 1977 (NodeConstantRawBits)
  }
  { // Node ID: 1335 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id1335in_a = id5out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id1335in_b = id1977out_value;

    id1335out_result[(getCycle()+1)%2] = (eq_fixed(id1335in_a,id1335in_b));
  }
  { // Node ID: 27 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id28out_result;

  { // Node ID: 28 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id28in_a = id27out_io_y_force_disabled;

    id28out_result = (not_fixed(id28in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id29out_result;

  { // Node ID: 29 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_a = id1335out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id29in_b = id28out_result;

    HWOffsetFix<1,0,UNSIGNED> id29x_1;

    (id29x_1) = (and_fixed(id29in_a,id29in_b));
    id29out_result = (id29x_1);
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 30 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id30in_enable = id29out_result;

    (id30st_read_next_cycle) = ((id30in_enable.getValueAsBool())&(!(((getFlushLevel())>=(1l))&(isFlushingActive()))));
    queueReadRequest(m_y, id30st_read_next_cycle.getValueAsBool());
  }
  HWRawBits<32> id31out_result;

  { // Node ID: 31 (NodeSlice)
    const HWRawBits<96> &id31in_a = id30out_data;

    id31out_result = (slice<0,32>(id31in_a));
  }
  HWFloat<8,24> id32out_output;

  { // Node ID: 32 (NodeReinterpret)
    const HWRawBits<32> &id32in_input = id31out_result;

    id32out_output = (cast_bits2float<8,24>(id32in_input));
  }
  { // Node ID: 1976 (NodeConstantRawBits)
  }
  { // Node ID: 101 (NodeGte)
    const HWFloat<8,24> &id101in_a = id32out_output;
    const HWFloat<8,24> &id101in_b = id1976out_value;

    id101out_result[(getCycle()+2)%3] = (gte_float(id101in_a,id101in_b));
  }
  { // Node ID: 2093 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2093in_input = id101out_result[getCycle()%3];

    id2093out_output[(getCycle()+47)%48] = id2093in_input;
  }
  { // Node ID: 102 (NodeConstantRawBits)
  }
  { // Node ID: 2050 (NodeConstantRawBits)
  }
  { // Node ID: 2049 (NodeConstantRawBits)
  }
  { // Node ID: 41 (NodeConstantRawBits)
  }
  HWRawBits<31> id1337out_result;

  { // Node ID: 1337 (NodeSlice)
    const HWRawBits<96> &id1337in_a = id30out_data;

    id1337out_result = (slice<0,31>(id1337in_a));
  }
  { // Node ID: 1975 (NodeConstantRawBits)
  }
  { // Node ID: 1338 (NodeNeqInlined)
    const HWRawBits<31> &id1338in_a = id1337out_result;
    const HWRawBits<31> &id1338in_b = id1975out_value;

    id1338out_result[(getCycle()+1)%2] = (neq_bits(id1338in_a,id1338in_b));
  }
  HWRawBits<23> id1339out_result;

  { // Node ID: 1339 (NodeSlice)
    const HWRawBits<96> &id1339in_a = id30out_data;

    id1339out_result = (slice<0,23>(id1339in_a));
  }
  { // Node ID: 2070 (NodeFIFO)
    const HWRawBits<23> &id2070in_input = id1339out_result;

    id2070out_output[(getCycle()+1)%2] = id2070in_input;
  }
  HWRawBits<25> id1340out_result;

  { // Node ID: 1340 (NodeCat)
    const HWRawBits<1> &id1340in_in0 = id41out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1340in_in1 = id1338out_result[getCycle()%2];
    const HWRawBits<23> &id1340in_in2 = id2070out_output[getCycle()%2];

    id1340out_result = (cat((cat(id1340in_in0,id1340in_in1)),id1340in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id44out_output;

  { // Node ID: 44 (NodeReinterpret)
    const HWRawBits<25> &id44in_input = id1340out_result;

    id44out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id44in_input));
  }
  HWRawBits<1> id1336out_result;

  { // Node ID: 1336 (NodeSlice)
    const HWRawBits<96> &id1336in_a = id30out_data;

    id1336out_result = (slice<31,1>(id1336in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id46out_output;

  { // Node ID: 46 (NodeReinterpret)
    const HWRawBits<1> &id46in_input = id1336out_result;

    id46out_output = (cast_bits2fixed<1,0,UNSIGNED>(id46in_input));
  }
  { // Node ID: 2071 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2071in_input = id46out_output;

    id2071out_output[(getCycle()+1)%2] = id2071in_input;
  }
  { // Node ID: 2002 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2002in_a = id2049out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2002in_b = id44out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2002in_sub = id2071out_output[getCycle()%2];

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2002x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2002x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2002x_3;

    (id2002x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2002in_a,id2002in_b));
    (id2002x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2002in_a,id2002in_b));
    switch((id2002in_sub.getValueAsLong())) {
      case 0l:
        id2002x_3 = (id2002x_1);
        break;
      case 1l:
        id2002x_3 = (id2002x_2);
        break;
      default:
        id2002x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2002out_result[(getCycle()+1)%2] = (id2002x_3);
  }
  { // Node ID: 1974 (NodeConstantRawBits)
  }
  { // Node ID: 1341 (NodeGtInlined)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id1341in_a = id2002out_result[getCycle()%2];
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id1341in_b = id1974out_value;

    id1341out_result[(getCycle()+1)%2] = (gt_fixed(id1341in_a,id1341in_b));
  }
  { // Node ID: 2073 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2073in_input = id1341out_result[getCycle()%2];

    id2073out_output[(getCycle()+1)%2] = id2073in_input;
  }
  HWRawBits<8> id1342out_result;

  { // Node ID: 1342 (NodeSlice)
    const HWRawBits<96> &id1342in_a = id30out_data;

    id1342out_result = (slice<23,8>(id1342in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id50out_output;

  { // Node ID: 50 (NodeReinterpret)
    const HWRawBits<8> &id50in_input = id1342out_result;

    id50out_output = (cast_bits2fixed<8,0,UNSIGNED>(id50in_input));
  }
  { // Node ID: 2072 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id2072in_input = id50out_output;

    id2072out_output[(getCycle()+2)%3] = id2072in_input;
  }
  { // Node ID: 1973 (NodeConstantRawBits)
  }
  { // Node ID: 52 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id52in_a = id2072out_output[getCycle()%3];
    const HWOffsetFix<7,0,UNSIGNED> &id52in_b = id1973out_value;

    id52out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id52in_a,id52in_b));
  }
  { // Node ID: 2074 (NodeFIFO)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2074in_input = id52out_result[getCycle()%2];

    id2074out_output[(getCycle()+1)%2] = id2074in_input;
  }
  { // Node ID: 1972 (NodeConstantRawBits)
  }
  { // Node ID: 60 (NodeAdd)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id60in_a = id52out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id60in_b = id1972out_value;

    id60out_result[(getCycle()+1)%2] = (add_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id60in_a,id60in_b));
  }
  { // Node ID: 61 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id61in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id61in_option0 = id2074out_output[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id61in_option1 = id60out_result[getCycle()%2];

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id61x_1;

    switch((id61in_sel.getValueAsLong())) {
      case 0l:
        id61x_1 = id61in_option0;
        break;
      case 1l:
        id61x_1 = id61in_option1;
        break;
      default:
        id61x_1 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id61out_result[(getCycle()+1)%2] = (id61x_1);
  }
  HWRawBits<1> id1346out_result;

  { // Node ID: 1346 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1346in_a = id61out_result[getCycle()%2];

    id1346out_result = (slice<8,1>(id1346in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1347out_output;

  { // Node ID: 1347 (NodeReinterpret)
    const HWRawBits<1> &id1347in_input = id1346out_result;

    id1347out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1347in_input));
  }
  { // Node ID: 2004 (NodeCondAddSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2004in_a = id2050out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2004in_b = id61out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id2004in_sub = id1347out_output;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2004x_1;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2004x_2;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2004x_3;

    (id2004x_1) = (add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2004in_a,id2004in_b));
    (id2004x_2) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2004in_a,id2004in_b));
    switch((id2004in_sub.getValueAsLong())) {
      case 0l:
        id2004x_3 = (id2004x_1);
        break;
      case 1l:
        id2004x_3 = (id2004x_2);
        break;
      default:
        id2004x_3 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id2004out_result[(getCycle()+1)%2] = (id2004x_3);
  }
  HWRawBits<8> id66out_result;

  { // Node ID: 66 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id66in_a = id2004out_result[getCycle()%2];

    id66out_result = (slice<0,8>(id66in_a));
  }
  { // Node ID: 2075 (NodeFIFO)
    const HWRawBits<8> &id2075in_input = id66out_result;

    id2075out_output[(getCycle()+29)%30] = id2075in_input;
  }
  { // Node ID: 1286 (NodeROM)
    const HWRawBits<8> &id1286in_addr = id2075out_output[getCycle()%30];

    HWFloat<8,24> id1286x_1;

    switch(((long)((id1286in_addr.getValueAsLong())<(256l)))) {
      case 0l:
        id1286x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id1286x_1 = (id1286sta_rom_store[(id1286in_addr.getValueAsLong())]);
        break;
      default:
        id1286x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1286out_dout[(getCycle()+2)%3] = (id1286x_1);
  }
  HWRawBits<1> id2006out_result;

  { // Node ID: 2006 (NodeSlice)
    const HWFloat<8,24> &id2006in_a = id1286out_dout[getCycle()%3];

    id2006out_result = (slice<31,1>(id2006in_a));
  }
  HWRawBits<1> id1343out_result;

  { // Node ID: 1343 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1343in_a = id61out_result[getCycle()%2];

    id1343out_result = (slice<8,1>(id1343in_a));
  }
  HWRawBits<1> id1344out_result;

  { // Node ID: 1344 (NodeNot)
    const HWRawBits<1> &id1344in_a = id1343out_result;

    id1344out_result = (not_bits(id1344in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1345out_output;

  { // Node ID: 1345 (NodeReinterpret)
    const HWRawBits<1> &id1345in_input = id1344out_result;

    id1345out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1345in_input));
  }
  HWOffsetFix<1,0,UNSIGNED> id2007out_result;

  { // Node ID: 2007 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id2007in_a = id1345out_output;

    id2007out_result = (not_fixed(id2007in_a));
  }
  { // Node ID: 2076 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2076in_input = id2007out_result;

    id2076out_output[(getCycle()+32)%33] = id2076in_input;
  }
  HWRawBits<1> id2008out_result;

  { // Node ID: 2008 (NodeXor)
    const HWRawBits<1> &id2008in_a = id2006out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2008in_b = id2076out_output[getCycle()%33];

    HWRawBits<1> id2008x_1;

    (id2008x_1) = (xor_bits(id2008in_a,(cast_fixed2bits(id2008in_b))));
    id2008out_result = (id2008x_1);
  }
  HWRawBits<31> id2005out_result;

  { // Node ID: 2005 (NodeSlice)
    const HWFloat<8,24> &id2005in_a = id1286out_dout[getCycle()%3];

    id2005out_result = (slice<0,31>(id2005in_a));
  }
  HWRawBits<32> id2009out_result;

  { // Node ID: 2009 (NodeCat)
    const HWRawBits<1> &id2009in_in0 = id2008out_result;
    const HWRawBits<31> &id2009in_in1 = id2005out_result;

    id2009out_result = (cat(id2009in_in0,id2009in_in1));
  }
  HWFloat<8,24> id2010out_output;

  { // Node ID: 2010 (NodeReinterpret)
    const HWRawBits<32> &id2010in_input = id2009out_result;

    id2010out_output = (cast_bits2float<8,24>(id2010in_input));
  }
  HWRawBits<23> id55out_result;

  { // Node ID: 55 (NodeSlice)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id55in_a = id2002out_result[getCycle()%2];

    id55out_result = (slice<0,23>(id55in_a));
  }
  HWOffsetFix<23,-23,UNSIGNED> id57out_output;

  { // Node ID: 57 (NodeReinterpret)
    const HWRawBits<23> &id57in_input = id55out_result;

    id57out_output = (cast_bits2fixed<23,-23,UNSIGNED>(id57in_input));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id58out_o;

  { // Node ID: 58 (NodeCast)
    const HWOffsetFix<23,-23,UNSIGNED> &id58in_i = id57out_output;

    id58out_o = (cast_fixed2fixed<27,-23,TWOSCOMPLEMENT,TONEAREVEN>(id58in_i));
  }
  HWOffsetFix<25,-24,UNSIGNED> id71out_o;

  { // Node ID: 71 (NodeCast)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id71in_i = id58out_o;

    id71out_o = (cast_fixed2fixed<25,-24,UNSIGNED,TONEAREVEN>(id71in_i));
  }
  HWRawBits<7> id74out_result;

  { // Node ID: 74 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id74in_a = id71out_o;

    id74out_result = (slice<17,7>(id74in_a));
  }
  { // Node ID: 1268 (NodeROM)
    const HWRawBits<7> &id1268in_addr = id74out_result;

    HWRawBits<108> id1268x_1;

    switch(((long)((id1268in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1268x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
      case 1l:
        id1268x_1 = (id1268sta_rom_store[(id1268in_addr.getValueAsLong())]);
        break;
      default:
        id1268x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
    }
    id1268out_dout[(getCycle()+2)%3] = (id1268x_1);
  }
  HWRawBits<27> id1275out_result;

  { // Node ID: 1275 (NodeSlice)
    const HWRawBits<108> &id1275in_a = id1268out_dout[getCycle()%3];

    id1275out_result = (slice<81,27>(id1275in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1276out_output;

  { // Node ID: 1276 (NodeReinterpret)
    const HWRawBits<27> &id1276in_input = id1275out_result;

    id1276out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1276in_input));
  }
  HWRawBits<7> id77out_result;

  { // Node ID: 77 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id77in_a = id71out_o;

    id77out_result = (slice<17,7>(id77in_a));
  }
  { // Node ID: 1277 (NodeROM)
    const HWRawBits<7> &id1277in_addr = id77out_result;

    HWRawBits<108> id1277x_1;

    switch(((long)((id1277in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1277x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
      case 1l:
        id1277x_1 = (id1277sta_rom_store[(id1277in_addr.getValueAsLong())]);
        break;
      default:
        id1277x_1 = (HWRawBits<108>(varint_u<108>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(44))));
        break;
    }
    id1277out_dout[(getCycle()+2)%3] = (id1277x_1);
  }
  HWRawBits<27> id1284out_result;

  { // Node ID: 1284 (NodeSlice)
    const HWRawBits<108> &id1284in_a = id1277out_dout[getCycle()%3];

    id1284out_result = (slice<81,27>(id1284in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1285out_output;

  { // Node ID: 1285 (NodeReinterpret)
    const HWRawBits<27> &id1285in_input = id1284out_result;

    id1285out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1285in_input));
  }
  { // Node ID: 82 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id82in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id82in_option0 = id1276out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id82in_option1 = id1285out_output;

    HWOffsetFix<27,-23,TWOSCOMPLEMENT> id82x_1;

    switch((id82in_sel.getValueAsLong())) {
      case 0l:
        id82x_1 = id82in_option0;
        break;
      case 1l:
        id82x_1 = id82in_option1;
        break;
      default:
        id82x_1 = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
        break;
    }
    id82out_result[(getCycle()+1)%2] = (id82x_1);
  }
  { // Node ID: 2078 (NodeFIFO)
    const HWOffsetFix<25,-24,UNSIGNED> &id2078in_input = id71out_o;

    id2078out_output[(getCycle()+2)%3] = id2078in_input;
  }
  HWRawBits<17> id72out_result;

  { // Node ID: 72 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id72in_a = id2078out_output[getCycle()%3];

    id72out_result = (slice<0,17>(id72in_a));
  }
  HWOffsetFix<17,-17,UNSIGNED> id73out_output;

  { // Node ID: 73 (NodeReinterpret)
    const HWRawBits<17> &id73in_input = id72out_result;

    id73out_output = (cast_bits2fixed<17,-17,UNSIGNED>(id73in_input));
  }
  HWRawBits<17> id75out_result;

  { // Node ID: 75 (NodeSlice)
    const HWOffsetFix<25,-24,UNSIGNED> &id75in_a = id2078out_output[getCycle()%3];

    id75out_result = (slice<0,17>(id75in_a));
  }
  HWOffsetFix<17,-17,UNSIGNED> id76out_output;

  { // Node ID: 76 (NodeReinterpret)
    const HWRawBits<17> &id76in_input = id75out_result;

    id76out_output = (cast_bits2fixed<17,-17,UNSIGNED>(id76in_input));
  }
  { // Node ID: 78 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id78in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id78in_option0 = id73out_output;
    const HWOffsetFix<17,-17,UNSIGNED> &id78in_option1 = id76out_output;

    HWOffsetFix<17,-17,UNSIGNED> id78x_1;

    switch((id78in_sel.getValueAsLong())) {
      case 0l:
        id78x_1 = id78in_option0;
        break;
      case 1l:
        id78x_1 = id78in_option1;
        break;
      default:
        id78x_1 = (HWOffsetFix<17,-17,UNSIGNED>(varint_u<17>(m_undefined_value.get_bits(17))));
        break;
    }
    id78out_result[(getCycle()+1)%2] = (id78x_1);
  }
  { // Node ID: 83 (NodeMul)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id83in_a = id82out_result[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id83in_b = id78out_result[getCycle()%2];

    id83out_result[(getCycle()+4)%5] = (mul_fixed<44,-40,TWOSCOMPLEMENT,TONEAREVEN>(id83in_a,id83in_b));
  }
  HWRawBits<27> id1273out_result;

  { // Node ID: 1273 (NodeSlice)
    const HWRawBits<108> &id1273in_a = id1268out_dout[getCycle()%3];

    id1273out_result = (slice<54,27>(id1273in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1274out_output;

  { // Node ID: 1274 (NodeReinterpret)
    const HWRawBits<27> &id1274in_input = id1273out_result;

    id1274out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1274in_input));
  }
  HWRawBits<27> id1282out_result;

  { // Node ID: 1282 (NodeSlice)
    const HWRawBits<108> &id1282in_a = id1277out_dout[getCycle()%3];

    id1282out_result = (slice<54,27>(id1282in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1283out_output;

  { // Node ID: 1283 (NodeReinterpret)
    const HWRawBits<27> &id1283in_input = id1282out_result;

    id1283out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1283in_input));
  }
  { // Node ID: 81 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id81in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id81in_option0 = id1274out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id81in_option1 = id1283out_output;

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
  { // Node ID: 2082 (NodeFIFO)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id2082in_input = id81out_result[getCycle()%2];

    id2082out_output[(getCycle()+4)%5] = id2082in_input;
  }
  { // Node ID: 84 (NodeAdd)
    const HWOffsetFix<44,-40,TWOSCOMPLEMENT> &id84in_a = id83out_result[getCycle()%5];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id84in_b = id2082out_output[getCycle()%5];

    id84out_result[(getCycle()+1)%2] = (add_fixed<45,-40,TWOSCOMPLEMENT,TONEAREVEN>(id84in_a,id84in_b));
  }
  { // Node ID: 85 (NodeCast)
    const HWOffsetFix<45,-40,TWOSCOMPLEMENT> &id85in_i = id84out_result[getCycle()%2];

    id85out_o[(getCycle()+1)%2] = (cast_fixed2fixed<25,-20,TWOSCOMPLEMENT,TONEAREVEN>(id85in_i));
  }
  { // Node ID: 2083 (NodeFIFO)
    const HWOffsetFix<17,-17,UNSIGNED> &id2083in_input = id78out_result[getCycle()%2];

    id2083out_output[(getCycle()+6)%7] = id2083in_input;
  }
  { // Node ID: 86 (NodeMul)
    const HWOffsetFix<25,-20,TWOSCOMPLEMENT> &id86in_a = id85out_o[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id86in_b = id2083out_output[getCycle()%7];

    id86out_result[(getCycle()+4)%5] = (mul_fixed<42,-37,TWOSCOMPLEMENT,TONEAREVEN>(id86in_a,id86in_b));
  }
  HWRawBits<27> id1271out_result;

  { // Node ID: 1271 (NodeSlice)
    const HWRawBits<108> &id1271in_a = id1268out_dout[getCycle()%3];

    id1271out_result = (slice<27,27>(id1271in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1272out_output;

  { // Node ID: 1272 (NodeReinterpret)
    const HWRawBits<27> &id1272in_input = id1271out_result;

    id1272out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1272in_input));
  }
  HWRawBits<27> id1280out_result;

  { // Node ID: 1280 (NodeSlice)
    const HWRawBits<108> &id1280in_a = id1277out_dout[getCycle()%3];

    id1280out_result = (slice<27,27>(id1280in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1281out_output;

  { // Node ID: 1281 (NodeReinterpret)
    const HWRawBits<27> &id1281in_input = id1280out_result;

    id1281out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1281in_input));
  }
  { // Node ID: 80 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id80in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id80in_option0 = id1272out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id80in_option1 = id1281out_output;

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
  { // Node ID: 2085 (NodeFIFO)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id2085in_input = id80out_result[getCycle()%2];

    id2085out_output[(getCycle()+10)%11] = id2085in_input;
  }
  { // Node ID: 87 (NodeAdd)
    const HWOffsetFix<42,-37,TWOSCOMPLEMENT> &id87in_a = id86out_result[getCycle()%5];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id87in_b = id2085out_output[getCycle()%11];

    id87out_result[(getCycle()+1)%2] = (add_fixed<43,-37,TWOSCOMPLEMENT,TONEAREVEN>(id87in_a,id87in_b));
  }
  { // Node ID: 88 (NodeCast)
    const HWOffsetFix<43,-37,TWOSCOMPLEMENT> &id88in_i = id87out_result[getCycle()%2];

    id88out_o[(getCycle()+1)%2] = (cast_fixed2fixed<25,-19,TWOSCOMPLEMENT,TONEAREVEN>(id88in_i));
  }
  { // Node ID: 2347 (NodeFIFO)
    const HWOffsetFix<17,-17,UNSIGNED> &id2347in_input = id2083out_output[getCycle()%7];

    id2347out_output[(getCycle()+6)%7] = id2347in_input;
  }
  { // Node ID: 89 (NodeMul)
    const HWOffsetFix<25,-19,TWOSCOMPLEMENT> &id89in_a = id88out_o[getCycle()%2];
    const HWOffsetFix<17,-17,UNSIGNED> &id89in_b = id2347out_output[getCycle()%7];

    id89out_result[(getCycle()+4)%5] = (mul_fixed<42,-36,TWOSCOMPLEMENT,TONEAREVEN>(id89in_a,id89in_b));
  }
  HWRawBits<27> id1269out_result;

  { // Node ID: 1269 (NodeSlice)
    const HWRawBits<108> &id1269in_a = id1268out_dout[getCycle()%3];

    id1269out_result = (slice<0,27>(id1269in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1270out_output;

  { // Node ID: 1270 (NodeReinterpret)
    const HWRawBits<27> &id1270in_input = id1269out_result;

    id1270out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1270in_input));
  }
  HWRawBits<27> id1278out_result;

  { // Node ID: 1278 (NodeSlice)
    const HWRawBits<108> &id1278in_a = id1277out_dout[getCycle()%3];

    id1278out_result = (slice<0,27>(id1278in_a));
  }
  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id1279out_output;

  { // Node ID: 1279 (NodeReinterpret)
    const HWRawBits<27> &id1279in_input = id1278out_result;

    id1279out_output = (cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(id1279in_input));
  }
  { // Node ID: 79 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id79in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id79in_option0 = id1270out_output;
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id79in_option1 = id1279out_output;

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
  { // Node ID: 2088 (NodeFIFO)
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id2088in_input = id79out_result[getCycle()%2];

    id2088out_output[(getCycle()+16)%17] = id2088in_input;
  }
  { // Node ID: 90 (NodeAdd)
    const HWOffsetFix<42,-36,TWOSCOMPLEMENT> &id90in_a = id89out_result[getCycle()%5];
    const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &id90in_b = id2088out_output[getCycle()%17];

    id90out_result[(getCycle()+1)%2] = (add_fixed<42,-36,TWOSCOMPLEMENT,TONEAREVEN>(id90in_a,id90in_b));
  }
  { // Node ID: 91 (NodeCast)
    const HWOffsetFix<42,-36,TWOSCOMPLEMENT> &id91in_i = id90out_result[getCycle()%2];

    id91out_o[(getCycle()+1)%2] = (cast_fixed2fixed<25,-19,TWOSCOMPLEMENT,TONEAREVEN>(id91in_i));
  }
  { // Node ID: 92 (NodeCast)
    const HWOffsetFix<25,-19,TWOSCOMPLEMENT> &id92in_i = id91out_o[getCycle()%2];

    id92out_o[(getCycle()+6)%7] = (cast_fixed2float<8,24>(id92in_i));
  }
  HWRawBits<25> id1348out_dataout;

  { // Node ID: 1348 (NodeShift)
    const HWOffsetFix<25,-24,UNSIGNED> &id1348in_datain = id2078out_output[getCycle()%3];

    id1348out_dataout = (shift_right_fixed(id1348in_datain,(1l)));
  }
  HWOffsetFix<25,-24,UNSIGNED> id95out_output;

  { // Node ID: 95 (NodeReinterpret)
    const HWRawBits<25> &id95in_input = id1348out_dataout;

    id95out_output = (cast_bits2fixed<25,-24,UNSIGNED>(id95in_input));
  }
  { // Node ID: 96 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id96in_sel = id2073out_output[getCycle()%2];
    const HWOffsetFix<25,-24,UNSIGNED> &id96in_option0 = id2078out_output[getCycle()%3];
    const HWOffsetFix<25,-24,UNSIGNED> &id96in_option1 = id95out_output;

    HWOffsetFix<25,-24,UNSIGNED> id96x_1;

    switch((id96in_sel.getValueAsLong())) {
      case 0l:
        id96x_1 = id96in_option0;
        break;
      case 1l:
        id96x_1 = id96in_option1;
        break;
      default:
        id96x_1 = (HWOffsetFix<25,-24,UNSIGNED>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id96out_result[(getCycle()+1)%2] = (id96x_1);
  }
  { // Node ID: 2092 (NodeFIFO)
    const HWOffsetFix<25,-24,UNSIGNED> &id2092in_input = id96out_result[getCycle()%2];

    id2092out_output[(getCycle()+18)%19] = id2092in_input;
  }
  { // Node ID: 97 (NodeCast)
    const HWOffsetFix<25,-24,UNSIGNED> &id97in_i = id2092out_output[getCycle()%19];

    id97out_o[(getCycle()+6)%7] = (cast_fixed2float<8,24>(id97in_i));
  }
  { // Node ID: 98 (NodeMul)
    const HWFloat<8,24> &id98in_a = id92out_o[getCycle()%7];
    const HWFloat<8,24> &id98in_b = id97out_o[getCycle()%7];

    id98out_result[(getCycle()+8)%9] = (mul_float(id98in_a,id98in_b));
  }
  { // Node ID: 99 (NodeAdd)
    const HWFloat<8,24> &id99in_a = id2010out_output;
    const HWFloat<8,24> &id99in_b = id98out_result[getCycle()%9];

    id99out_result[(getCycle()+12)%13] = (add_float(id99in_a,id99in_b));
  }
  { // Node ID: 103 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id103in_sel = id2093out_output[getCycle()%48];
    const HWFloat<8,24> &id103in_option0 = id102out_value;
    const HWFloat<8,24> &id103in_option1 = id99out_result[getCycle()%13];

    HWFloat<8,24> id103x_1;

    switch((id103in_sel.getValueAsLong())) {
      case 0l:
        id103x_1 = id103in_option0;
        break;
      case 1l:
        id103x_1 = id103in_option1;
        break;
      default:
        id103x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id103out_result[(getCycle()+1)%2] = (id103x_1);
  }
  { // Node ID: 2094 (NodeFIFO)
    const HWFloat<8,24> &id2094in_input = id103out_result[getCycle()%2];

    id2094out_output[(getCycle()+32)%33] = id2094in_input;
  }
  { // Node ID: 105 (NodeMul)
    const HWFloat<8,24> &id105in_a = id1979out_value;
    const HWFloat<8,24> &id105in_b = id2094out_output[getCycle()%33];

    id105out_result[(getCycle()+8)%9] = (mul_float(id105in_a,id105in_b));
  }
  { // Node ID: 106 (NodeAdd)
    const HWFloat<8,24> &id106in_a = id24out_result[getCycle()%2];
    const HWFloat<8,24> &id106in_b = id105out_result[getCycle()%9];

    id106out_result[(getCycle()+11)%12] = (add_float(id106in_a,id106in_b));
  }
  { // Node ID: 1971 (NodeConstantRawBits)
  }
  { // Node ID: 108 (NodeGt)
    const HWFloat<8,24> &id108in_a = id106out_result[getCycle()%12];
    const HWFloat<8,24> &id108in_b = id1971out_value;

    id108out_result[(getCycle()+2)%3] = (gt_float(id108in_a,id108in_b));
  }
  { // Node ID: 2095 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id2095in_input = id5out_count;

    id2095out_output[(getCycle()+1)%2] = id2095in_input;
  }
  { // Node ID: 1970 (NodeConstantRawBits)
  }
  { // Node ID: 1254 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id1254in_a = id2373out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id1254in_b = id1970out_value;

    id1254out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAREVEN>(id1254in_a,id1254in_b));
  }
  { // Node ID: 1349 (NodeEqInlined)
    const HWOffsetFix<32,0,UNSIGNED> &id1349in_a = id2095out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id1349in_b = id1254out_result[getCycle()%2];

    id1349out_result[(getCycle()+1)%2] = (eq_fixed(id1349in_a,id1349in_b));
  }
  { // Node ID: 2096 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2096in_input = id1349out_result[getCycle()%2];

    id2096out_output[(getCycle()+107)%108] = id2096in_input;
  }
  { // Node ID: 1256 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1256in_a = id108out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id1256in_b = id2096out_output[getCycle()%108];

    HWOffsetFix<1,0,UNSIGNED> id1256x_1;

    (id1256x_1) = (and_fixed(id1256in_a,id1256in_b));
    id1256out_result[(getCycle()+1)%2] = (id1256x_1);
  }
  { // Node ID: 1257 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1258out_result;

  { // Node ID: 1258 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1258in_a = id1257out_io_z_force_disabled;

    id1258out_result = (not_fixed(id1258in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1259out_result;

  { // Node ID: 1259 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1259in_a = id1256out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1259in_b = id1258out_result;

    HWOffsetFix<1,0,UNSIGNED> id1259x_1;

    (id1259x_1) = (and_fixed(id1259in_a,id1259in_b));
    id1259out_result = (id1259x_1);
  }
  { // Node ID: 2345 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2345in_input = id1259out_result;

    id2345out_output[(getCycle()+19)%20] = id2345in_input;
  }
  HWFloat<8,24> id2061out_output;

  { // Node ID: 2061 (NodeStreamOffset)
    const HWFloat<8,24> &id2061in_input = id2097out_output[getCycle()%9];

    id2061out_output = id2061in_input;
  }
  { // Node ID: 2098 (NodeFIFO)
    const HWFloat<8,24> &id2098in_input = id2061out_output;

    id2098out_output[(getCycle()+56)%57] = id2098in_input;
  }
  { // Node ID: 21 (NodeConstantRawBits)
  }
  { // Node ID: 22 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_sel = id8out_result[getCycle()%2];
    const HWFloat<8,24> &id22in_option0 = id2098out_output[getCycle()%57];
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
  { // Node ID: 2099 (NodeFIFO)
    const HWFloat<8,24> &id2099in_input = id22out_result[getCycle()%2];

    id2099out_output[(getCycle()+2)%3] = id2099in_input;
  }
  { // Node ID: 2353 (NodeFIFO)
    const HWFloat<8,24> &id2353in_input = id2099out_output[getCycle()%3];

    id2353out_output[(getCycle()+12)%13] = id2353in_input;
  }
  { // Node ID: 2100 (NodeFIFO)
    const HWFloat<8,24> &id2100in_input = id105out_result[getCycle()%9];

    id2100out_output[(getCycle()+13)%14] = id2100in_input;
  }
  { // Node ID: 1969 (NodeConstantRawBits)
  }
  { // Node ID: 110 (NodeSub)
    const HWFloat<8,24> &id110in_a = id1969out_value;
    const HWFloat<8,24> &id110in_b = id2099out_output[getCycle()%3];

    id110out_result[(getCycle()+11)%12] = (sub_float(id110in_a,id110in_b));
  }
  { // Node ID: 111 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id111in_sel = id108out_result[getCycle()%3];
    const HWFloat<8,24> &id111in_option0 = id2100out_output[getCycle()%14];
    const HWFloat<8,24> &id111in_option1 = id110out_result[getCycle()%12];

    HWFloat<8,24> id111x_1;

    switch((id111in_sel.getValueAsLong())) {
      case 0l:
        id111x_1 = id111in_option0;
        break;
      case 1l:
        id111x_1 = id111in_option1;
        break;
      default:
        id111x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id111out_result[(getCycle()+1)%2] = (id111x_1);
  }
  { // Node ID: 118 (NodeAdd)
    const HWFloat<8,24> &id118in_a = id2353out_output[getCycle()%13];
    const HWFloat<8,24> &id118in_b = id111out_result[getCycle()%2];

    id118out_result[(getCycle()+11)%12] = (add_float(id118in_a,id118in_b));
  }
  { // Node ID: 2097 (NodeFIFO)
    const HWFloat<8,24> &id2097in_input = id118out_result[getCycle()%12];

    id2097out_output[(getCycle()+8)%9] = id2097in_input;
  }
  HWFloat<8,24> id2062out_output;

  { // Node ID: 2062 (NodeStreamOffset)
    const HWFloat<8,24> &id2062in_input = id117out_result[getCycle()%12];

    id2062out_output = id2062in_input;
  }
  { // Node ID: 2102 (NodeFIFO)
    const HWFloat<8,24> &id2102in_input = id2062out_output;

    id2102out_output[(getCycle()+56)%57] = id2102in_input;
  }
  { // Node ID: 13 (NodeConstantRawBits)
  }
  { // Node ID: 14 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_sel = id8out_result[getCycle()%2];
    const HWFloat<8,24> &id14in_option0 = id2102out_output[getCycle()%57];
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
  { // Node ID: 2339 (NodeFIFO)
    const HWFloat<8,24> &id2339in_input = id14out_result[getCycle()%2];

    id2339out_output[(getCycle()+22)%23] = id2339in_input;
  }
  { // Node ID: 2312 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2312in_input = id108out_result[getCycle()%3];

    id2312out_output[(getCycle()+47)%48] = id2312in_input;
  }
  { // Node ID: 2348 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2348in_input = id2312out_output[getCycle()%48];

    id2348out_output[(getCycle()+20)%21] = id2348in_input;
  }
  { // Node ID: 2349 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2349in_input = id2348out_output[getCycle()%21];

    id2349out_output[(getCycle()+1)%2] = id2349in_input;
  }
  { // Node ID: 2350 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2350in_input = id2349out_output[getCycle()%2];

    id2350out_output[(getCycle()+1)%2] = id2350in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1243out_result;

  { // Node ID: 1243 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1243in_a = id2350out_output[getCycle()%2];

    id1243out_result = (not_fixed(id1243in_a));
  }
  { // Node ID: 2369 (NodeFIFO)
    const HWFloat<8,24> &id2369in_input = id2338out_output[getCycle()%15];

    id2369out_output[(getCycle()+21)%22] = id2369in_input;
  }
  { // Node ID: 2370 (NodeFIFO)
    const HWFloat<8,24> &id2370in_input = id2369out_output[getCycle()%22];

    id2370out_output[(getCycle()+27)%28] = id2370in_input;
  }
  { // Node ID: 2371 (NodeFIFO)
    const HWFloat<8,24> &id2371in_input = id2370out_output[getCycle()%28];

    id2371out_output[(getCycle()+16)%17] = id2371in_input;
  }
  { // Node ID: 2372 (NodeFIFO)
    const HWFloat<8,24> &id2372in_input = id2371out_output[getCycle()%17];

    id2372out_output[(getCycle()+4)%5] = id2372in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1220out_result;

  { // Node ID: 1220 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1220in_a = id2348out_output[getCycle()%21];

    id1220out_result = (not_fixed(id1220in_a));
  }
  { // Node ID: 2318 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2318in_input = id8out_result[getCycle()%2];

    id2318out_output[(getCycle()+14)%15] = id2318in_input;
  }
  { // Node ID: 2351 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2351in_input = id2350out_output[getCycle()%2];

    id2351out_output[(getCycle()+18)%19] = id2351in_input;
  }
  { // Node ID: 2352 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2352in_input = id2351out_output[getCycle()%19];

    id2352out_output[(getCycle()+2)%3] = id2352in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1239out_result;

  { // Node ID: 1239 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1239in_a = id2352out_output[getCycle()%3];

    id1239out_result = (not_fixed(id1239in_a));
  }
  { // Node ID: 2207 (NodeFIFO)
    const HWFloat<8,24> &id2207in_input = id16out_result[getCycle()%2];

    id2207out_output[(getCycle()+21)%22] = id2207in_input;
  }
  { // Node ID: 2364 (NodeFIFO)
    const HWFloat<8,24> &id2364in_input = id2207out_output[getCycle()%22];

    id2364out_output[(getCycle()+8)%9] = id2364in_input;
  }
  { // Node ID: 2365 (NodeFIFO)
    const HWFloat<8,24> &id2365in_input = id2364out_output[getCycle()%9];

    id2365out_output[(getCycle()+39)%40] = id2365in_input;
  }
  { // Node ID: 2366 (NodeFIFO)
    const HWFloat<8,24> &id2366in_input = id2365out_output[getCycle()%40];

    id2366out_output[(getCycle()+20)%21] = id2366in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1200out_result;

  { // Node ID: 1200 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1200in_a = id2351out_output[getCycle()%19];

    id1200out_result = (not_fixed(id1200in_a));
  }
  { // Node ID: 2368 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2368in_input = id2325out_output[getCycle()%21];

    id2368out_output[(getCycle()+20)%21] = id2368in_input;
  }
  { // Node ID: 1201 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1201in_a = id1200out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1201in_b = id2368out_output[getCycle()%21];

    HWOffsetFix<1,0,UNSIGNED> id1201x_1;

    (id1201x_1) = (and_fixed(id1201in_a,id1201in_b));
    id1201out_result[(getCycle()+1)%2] = (id1201x_1);
  }
  { // Node ID: 1967 (NodeConstantRawBits)
  }
  { // Node ID: 128 (NodeConstantRawBits)
  }
  { // Node ID: 129 (NodeConstantRawBits)
  }
  { // Node ID: 1966 (NodeConstantRawBits)
  }
  { // Node ID: 1965 (NodeConstantRawBits)
  }
  HWRawBits<32> id33out_result;

  { // Node ID: 33 (NodeSlice)
    const HWRawBits<96> &id33in_a = id30out_data;

    id33out_result = (slice<32,32>(id33in_a));
  }
  HWFloat<8,24> id34out_output;

  { // Node ID: 34 (NodeReinterpret)
    const HWRawBits<32> &id34in_input = id33out_result;

    id34out_output = (cast_bits2float<8,24>(id34in_input));
  }
  { // Node ID: 120 (NodeMul)
    const HWFloat<8,24> &id120in_a = id1965out_value;
    const HWFloat<8,24> &id120in_b = id34out_output;

    id120out_result[(getCycle()+8)%9] = (mul_float(id120in_a,id120in_b));
  }
  { // Node ID: 2108 (NodeFIFO)
    const HWFloat<8,24> &id2108in_input = id120out_result[getCycle()%9];

    id2108out_output[(getCycle()+14)%15] = id2108in_input;
  }
  { // Node ID: 1964 (NodeConstantRawBits)
  }
  { // Node ID: 122 (NodeSub)
    const HWFloat<8,24> &id122in_a = id1964out_value;
    const HWFloat<8,24> &id122in_b = id34out_output;

    id122out_result[(getCycle()+11)%12] = (sub_float(id122in_a,id122in_b));
  }
  { // Node ID: 1963 (NodeConstantRawBits)
  }
  { // Node ID: 124 (NodeAdd)
    const HWFloat<8,24> &id124in_a = id122out_result[getCycle()%12];
    const HWFloat<8,24> &id124in_b = id1963out_value;

    id124out_result[(getCycle()+11)%12] = (add_float(id124in_a,id124in_b));
  }
  { // Node ID: 125 (NodeDiv)
    const HWFloat<8,24> &id125in_a = id2108out_output[getCycle()%15];
    const HWFloat<8,24> &id125in_b = id124out_result[getCycle()%12];

    id125out_result[(getCycle()+28)%29] = (div_float(id125in_a,id125in_b));
  }
  { // Node ID: 127 (NodeSub)
    const HWFloat<8,24> &id127in_a = id1966out_value;
    const HWFloat<8,24> &id127in_b = id125out_result[getCycle()%29];

    id127out_result[(getCycle()+11)%12] = (sub_float(id127in_a,id127in_b));
  }
  { // Node ID: 130 (NodeGt)
    const HWFloat<8,24> &id130in_a = id129out_value;
    const HWFloat<8,24> &id130in_b = id127out_result[getCycle()%12];

    id130out_result[(getCycle()+2)%3] = (gt_float(id130in_a,id130in_b));
  }
  { // Node ID: 2109 (NodeFIFO)
    const HWFloat<8,24> &id2109in_input = id127out_result[getCycle()%12];

    id2109out_output[(getCycle()+2)%3] = id2109in_input;
  }
  { // Node ID: 131 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id131in_sel = id130out_result[getCycle()%3];
    const HWFloat<8,24> &id131in_option0 = id129out_value;
    const HWFloat<8,24> &id131in_option1 = id2109out_output[getCycle()%3];

    HWFloat<8,24> id131x_1;

    switch((id131in_sel.getValueAsLong())) {
      case 0l:
        id131x_1 = id131in_option0;
        break;
      case 1l:
        id131x_1 = id131in_option1;
        break;
      default:
        id131x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id131out_result[(getCycle()+1)%2] = (id131x_1);
  }
  { // Node ID: 132 (NodeGt)
    const HWFloat<8,24> &id132in_a = id128out_value;
    const HWFloat<8,24> &id132in_b = id131out_result[getCycle()%2];

    id132out_result[(getCycle()+2)%3] = (gt_float(id132in_a,id132in_b));
  }
  { // Node ID: 2110 (NodeFIFO)
    const HWFloat<8,24> &id2110in_input = id131out_result[getCycle()%2];

    id2110out_output[(getCycle()+2)%3] = id2110in_input;
  }
  { // Node ID: 133 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id133in_sel = id132out_result[getCycle()%3];
    const HWFloat<8,24> &id133in_option0 = id2110out_output[getCycle()%3];
    const HWFloat<8,24> &id133in_option1 = id128out_value;

    HWFloat<8,24> id133x_1;

    switch((id133in_sel.getValueAsLong())) {
      case 0l:
        id133x_1 = id133in_option0;
        break;
      case 1l:
        id133x_1 = id133in_option1;
        break;
      default:
        id133x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id133out_result[(getCycle()+1)%2] = (id133x_1);
  }
  { // Node ID: 135 (NodeSub)
    const HWFloat<8,24> &id135in_a = id1967out_value;
    const HWFloat<8,24> &id135in_b = id133out_result[getCycle()%2];

    id135out_result[(getCycle()+11)%12] = (sub_float(id135in_a,id135in_b));
  }
  { // Node ID: 2111 (NodeFIFO)
    const HWFloat<8,24> &id2111in_input = id135out_result[getCycle()%12];

    id2111out_output[(getCycle()+11)%12] = id2111in_input;
  }
  { // Node ID: 1962 (NodeConstantRawBits)
  }
  { // Node ID: 137 (NodeSub)
    const HWFloat<8,24> &id137in_a = id1962out_value;
    const HWFloat<8,24> &id137in_b = id135out_result[getCycle()%12];

    id137out_result[(getCycle()+11)%12] = (sub_float(id137in_a,id137in_b));
  }
  { // Node ID: 138 (NodeMul)
    const HWFloat<8,24> &id138in_a = id2111out_output[getCycle()%12];
    const HWFloat<8,24> &id138in_b = id137out_result[getCycle()%12];

    id138out_result[(getCycle()+8)%9] = (mul_float(id138in_a,id138in_b));
  }
  { // Node ID: 139 (NodeSqrt)
    const HWFloat<8,24> &id139in_a = id138out_result[getCycle()%9];

    id139out_result[(getCycle()+28)%29] = (sqrt_float(id139in_a));
  }
  { // Node ID: 1961 (NodeConstantRawBits)
  }
  HWRawBits<32> id35out_result;

  { // Node ID: 35 (NodeSlice)
    const HWRawBits<96> &id35in_a = id30out_data;

    id35out_result = (slice<64,32>(id35in_a));
  }
  HWFloat<8,24> id36out_output;

  { // Node ID: 36 (NodeReinterpret)
    const HWRawBits<32> &id36in_input = id35out_result;

    id36out_output = (cast_bits2float<8,24>(id36in_input));
  }
  { // Node ID: 142 (NodeMul)
    const HWFloat<8,24> &id142in_a = id1961out_value;
    const HWFloat<8,24> &id142in_b = id36out_output;

    id142out_result[(getCycle()+8)%9] = (mul_float(id142in_a,id142in_b));
  }
  { // Node ID: 2116 (NodeFIFO)
    const HWFloat<8,24> &id2116in_input = id142out_result[getCycle()%9];

    id2116out_output[(getCycle()+28)%29] = id2116in_input;
  }
  { // Node ID: 2356 (NodeFIFO)
    const HWFloat<8,24> &id2356in_input = id2116out_output[getCycle()%29];

    id2356out_output[(getCycle()+6)%7] = id2356in_input;
  }
  { // Node ID: 2357 (NodeFIFO)
    const HWFloat<8,24> &id2357in_input = id2356out_output[getCycle()%7];

    id2357out_output[(getCycle()+1)%2] = id2357in_input;
  }
  HWRawBits<31> id144out_result;

  { // Node ID: 144 (NodeSlice)
    const HWFloat<8,24> &id144in_a = id2357out_output[getCycle()%2];

    id144out_result = (slice<0,31>(id144in_a));
  }
  { // Node ID: 650 (NodeConstantRawBits)
  }
  { // Node ID: 1351 (NodeEqInlined)
    const HWRawBits<31> &id1351in_a = id144out_result;
    const HWRawBits<31> &id1351in_b = id650out_value;

    id1351out_result[(getCycle()+1)%2] = (eq_bits(id1351in_a,id1351in_b));
  }
  HWRawBits<8> id1689out_result;

  { // Node ID: 1689 (NodeSlice)
    const HWFloat<8,24> &id1689in_a = id2356out_output[getCycle()%7];

    id1689out_result = (slice<23,8>(id1689in_a));
  }
  { // Node ID: 655 (NodeConstantRawBits)
  }
  { // Node ID: 1353 (NodeEqInlined)
    const HWRawBits<8> &id1353in_a = id1689out_result;
    const HWRawBits<8> &id1353in_b = id655out_value;

    id1353out_result[(getCycle()+1)%2] = (eq_bits(id1353in_a,id1353in_b));
  }
  HWRawBits<23> id1690out_result;

  { // Node ID: 1690 (NodeSlice)
    const HWFloat<8,24> &id1690in_a = id2356out_output[getCycle()%7];

    id1690out_result = (slice<0,23>(id1690in_a));
  }
  { // Node ID: 1960 (NodeConstantRawBits)
  }
  { // Node ID: 1355 (NodeNeqInlined)
    const HWRawBits<23> &id1355in_a = id1690out_result;
    const HWRawBits<23> &id1355in_b = id1960out_value;

    id1355out_result[(getCycle()+1)%2] = (neq_bits(id1355in_a,id1355in_b));
  }
  { // Node ID: 659 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id659in_a = id1353out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id659in_b = id1355out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id659x_1;

    (id659x_1) = (and_fixed(id659in_a,id659in_b));
    id659out_result[(getCycle()+1)%2] = (id659x_1);
  }
  { // Node ID: 660 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id660in_a = id1351out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id660in_b = id659out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id660x_1;

    (id660x_1) = (or_fixed(id660in_a,id660in_b));
    id660out_result[(getCycle()+1)%2] = (id660x_1);
  }
  { // Node ID: 2206 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2206in_input = id660out_result[getCycle()%2];

    id2206out_output[(getCycle()+79)%80] = id2206in_input;
  }
  { // Node ID: 148 (NodeConstantRawBits)
  }
  HWRawBits<23> id1691out_result;

  { // Node ID: 1691 (NodeSlice)
    const HWFloat<8,24> &id1691in_a = id2357out_output[getCycle()%2];

    id1691out_result = (slice<0,23>(id1691in_a));
  }
  HWRawBits<24> id149out_result;

  { // Node ID: 149 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id149in_in0 = id148out_value;
    const HWRawBits<23> &id149in_in1 = id1691out_result;

    id149out_result = (cat(id149in_in0,id149in_in1));
  }
  HWOffsetFix<24,0,UNSIGNED> id152out_output;

  { // Node ID: 152 (NodeReinterpret)
    const HWRawBits<24> &id152in_input = id149out_result;

    id152out_output = (cast_bits2fixed<24,0,UNSIGNED>(id152in_input));
  }
  HWRawBits<8> id1692out_result;

  { // Node ID: 1692 (NodeSlice)
    const HWFloat<8,24> &id1692in_a = id2116out_output[getCycle()%29];

    id1692out_result = (slice<23,8>(id1692in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id154out_output;

  { // Node ID: 154 (NodeReinterpret)
    const HWRawBits<8> &id154in_input = id1692out_result;

    id154out_output = (cast_bits2fixed<8,0,UNSIGNED>(id154in_input));
  }
  { // Node ID: 1959 (NodeConstantRawBits)
  }
  { // Node ID: 1958 (NodeConstantRawBits)
  }
  { // Node ID: 1985 (NodeTriArith)
    const HWOffsetFix<8,0,UNSIGNED> &id1985in_a = id154out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id1985in_b = id1959out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1985in_c = id1958out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id1985x_1;

    (id1985x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id1985in_a,id1985in_b)),id1985in_c));
    id1985out_result[(getCycle()+1)%2] = (id1985x_1);
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1986out_o;

  { // Node ID: 1986 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id1986in_i = id1985out_result[getCycle()%2];

    id1986out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1986in_i));
  }
  HWRawBits<1> id1358out_result;

  { // Node ID: 1358 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1358in_a = id1986out_o;

    id1358out_result = (slice<8,1>(id1358in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1359out_output;

  { // Node ID: 1359 (NodeReinterpret)
    const HWRawBits<1> &id1359in_input = id1358out_result;

    id1359out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1359in_input));
  }
  { // Node ID: 2117 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2117in_input = id1359out_output;

    id2117out_output[(getCycle()+5)%6] = id2117in_input;
  }
  { // Node ID: 159 (NodeConstantRawBits)
  }
  { // Node ID: 2048 (NodeConstantRawBits)
  }
  HWRawBits<1> id1360out_result;

  { // Node ID: 1360 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1360in_a = id1986out_o;

    id1360out_result = (slice<8,1>(id1360in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1361out_output;

  { // Node ID: 1361 (NodeReinterpret)
    const HWRawBits<1> &id1361in_input = id1360out_result;

    id1361out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1361in_input));
  }
  { // Node ID: 2012 (NodeCondAddSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2012in_a = id2048out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2012in_b = id1986out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id2012in_sub = id1361out_output;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2012x_1;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2012x_2;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2012x_3;

    (id2012x_1) = (add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2012in_a,id2012in_b));
    (id2012x_2) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2012in_a,id2012in_b));
    switch((id2012in_sub.getValueAsLong())) {
      case 0l:
        id2012x_3 = (id2012x_1);
        break;
      case 1l:
        id2012x_3 = (id2012x_2);
        break;
      default:
        id2012x_3 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id2012out_result[(getCycle()+1)%2] = (id2012x_3);
  }
  HWRawBits<8> id166out_result;

  { // Node ID: 166 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id166in_a = id2012out_result[getCycle()%2];

    id166out_result = (slice<0,8>(id166in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id167out_output;

  { // Node ID: 167 (NodeReinterpret)
    const HWRawBits<8> &id167in_input = id166out_result;

    id167out_output = (cast_bits2fixed<8,0,UNSIGNED>(id167in_input));
  }
  { // Node ID: 169 (NodeShift)
    const HWRawBits<185> &id169in_datain = id159out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id169in_shift = id167out_output;

    id169out_dataout[(getCycle()+4)%5] = (shift_left_bits(id169in_datain,(id169in_shift.getValueAsLong())));
  }
  { // Node ID: 168 (NodeShift)
    const HWRawBits<185> &id168in_datain = id159out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id168in_shift = id167out_output;

    id168out_dataout[(getCycle()+4)%5] = (shift_right_bits(id168in_datain,(id168in_shift.getValueAsLong())));
  }
  { // Node ID: 170 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id170in_sel = id2117out_output[getCycle()%6];
    const HWRawBits<185> &id170in_option0 = id169out_dataout[getCycle()%5];
    const HWRawBits<185> &id170in_option1 = id168out_dataout[getCycle()%5];

    HWRawBits<185> id170x_1;

    switch((id170in_sel.getValueAsLong())) {
      case 0l:
        id170x_1 = id170in_option0;
        break;
      case 1l:
        id170x_1 = id170in_option1;
        break;
      default:
        id170x_1 = (HWRawBits<185>(varint_u<185>::init(3, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64), m_undefined_value.get_bits(57))));
        break;
    }
    id170out_result[(getCycle()+1)%2] = (id170x_1);
  }
  HWRawBits<81> id171out_result;

  { // Node ID: 171 (NodeSlice)
    const HWRawBits<185> &id171in_a = id170out_result[getCycle()%2];

    id171out_result = (slice<104,81>(id171in_a));
  }
  HWOffsetFix<81,0,UNSIGNED> id173out_output;

  { // Node ID: 173 (NodeReinterpret)
    const HWRawBits<81> &id173in_input = id171out_result;

    id173out_output = (cast_bits2fixed<81,0,UNSIGNED>(id173in_input));
  }
  { // Node ID: 174 (NodeMul)
    const HWOffsetFix<24,0,UNSIGNED> &id174in_a = id152out_output;
    const HWOffsetFix<81,0,UNSIGNED> &id174in_b = id173out_output;

    id174out_result[(getCycle()+1)%2] = (mul_fixed<81,0,UNSIGNED,TONEAREVEN>(id174in_a,id174in_b));
  }
  HWRawBits<79> id178out_result;

  { // Node ID: 178 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id178in_a = id174out_result[getCycle()%2];

    id178out_result = (slice<0,79>(id178in_a));
  }
  HWOffsetFix<79,-79,UNSIGNED> id179out_output;

  { // Node ID: 179 (NodeReinterpret)
    const HWRawBits<79> &id179in_input = id178out_result;

    id179out_output = (cast_bits2fixed<79,-79,UNSIGNED>(id179in_input));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id182out_o;

  { // Node ID: 182 (NodeCast)
    const HWOffsetFix<79,-79,UNSIGNED> &id182in_i = id179out_output;

    id182out_o = (cast_fixed2fixed<80,-79,TWOSCOMPLEMENT,TONEAREVEN>(id182in_i));
  }
  { // Node ID: 183 (NodeLeading1Detect)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id183in_input = id182out_o;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id183x_1;
    HWRawBits<80> id183x_2;
    HWRawBits<80> id183x_3;

    switch(((slice<79,1>(id183in_input)).getValueAsLong())) {
      case 0l:
        id183x_1 = id183in_input;
        break;
      case 1l:
        id183x_1 = (not_fixed(id183in_input));
        break;
      default:
        id183x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    {
      varint_u<80> raw_bits = (slice<0,80>((cat((id183x_1),(c_hw_fix_1_0_uns_bits))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id183x_2 = HWRawBits<80>(raw_bits);
    }
    {
      varint_u<80> raw_bits = (cast_fixed2bits((add_fixed<80,0,UNSIGNED,TRUNCATE>((cast_bits2fixed<80,0,UNSIGNED>((not_bits((id183x_2))))),(c_hw_fix_80_0_uns_1_0val))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id183x_3 = HWRawBits<80>(raw_bits);
    }
    id183out_output[(getCycle()+1)%2] = (cast_bits2fixed<80,0,UNSIGNED>((and_bits((id183x_3),(slice<0,80>((cat((id183x_1),(c_hw_fix_1_0_uns_bits)))))))));
  }
  { // Node ID: 184 (NodeOneHotDecode)
    const HWOffsetFix<80,0,UNSIGNED> &id184in_input = id183out_output[getCycle()%2];

    (id184st_one_hot_or) = (c_hw_fix_7_0_uns_bits_1);
    if(((slice<0,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_1)));
    }
    if(((slice<1,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_2)));
    }
    if(((slice<2,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_3)));
    }
    if(((slice<3,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_4)));
    }
    if(((slice<4,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_5)));
    }
    if(((slice<5,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_6)));
    }
    if(((slice<6,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_7)));
    }
    if(((slice<7,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_8)));
    }
    if(((slice<8,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_9)));
    }
    if(((slice<9,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_10)));
    }
    if(((slice<10,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_11)));
    }
    if(((slice<11,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_12)));
    }
    if(((slice<12,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_13)));
    }
    if(((slice<13,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_14)));
    }
    if(((slice<14,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_15)));
    }
    if(((slice<15,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_16)));
    }
    if(((slice<16,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_17)));
    }
    if(((slice<17,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_18)));
    }
    if(((slice<18,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_19)));
    }
    if(((slice<19,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_20)));
    }
    if(((slice<20,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_21)));
    }
    if(((slice<21,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_22)));
    }
    if(((slice<22,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_23)));
    }
    if(((slice<23,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_24)));
    }
    if(((slice<24,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_25)));
    }
    if(((slice<25,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_26)));
    }
    if(((slice<26,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_27)));
    }
    if(((slice<27,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_28)));
    }
    if(((slice<28,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_29)));
    }
    if(((slice<29,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_30)));
    }
    if(((slice<30,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_31)));
    }
    if(((slice<31,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_32)));
    }
    if(((slice<32,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_33)));
    }
    if(((slice<33,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_34)));
    }
    if(((slice<34,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_35)));
    }
    if(((slice<35,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_36)));
    }
    if(((slice<36,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_37)));
    }
    if(((slice<37,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_38)));
    }
    if(((slice<38,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_39)));
    }
    if(((slice<39,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_40)));
    }
    if(((slice<40,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_41)));
    }
    if(((slice<41,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_42)));
    }
    if(((slice<42,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_43)));
    }
    if(((slice<43,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_44)));
    }
    if(((slice<44,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_45)));
    }
    if(((slice<45,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_46)));
    }
    if(((slice<46,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_47)));
    }
    if(((slice<47,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_48)));
    }
    if(((slice<48,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_49)));
    }
    if(((slice<49,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_50)));
    }
    if(((slice<50,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_51)));
    }
    if(((slice<51,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_52)));
    }
    if(((slice<52,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_53)));
    }
    if(((slice<53,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_54)));
    }
    if(((slice<54,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_55)));
    }
    if(((slice<55,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_56)));
    }
    if(((slice<56,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_57)));
    }
    if(((slice<57,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_58)));
    }
    if(((slice<58,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_59)));
    }
    if(((slice<59,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_60)));
    }
    if(((slice<60,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_61)));
    }
    if(((slice<61,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_62)));
    }
    if(((slice<62,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_63)));
    }
    if(((slice<63,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_64)));
    }
    if(((slice<64,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_65)));
    }
    if(((slice<65,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_66)));
    }
    if(((slice<66,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_67)));
    }
    if(((slice<67,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_68)));
    }
    if(((slice<68,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_69)));
    }
    if(((slice<69,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_70)));
    }
    if(((slice<70,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_71)));
    }
    if(((slice<71,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_72)));
    }
    if(((slice<72,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_73)));
    }
    if(((slice<73,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_74)));
    }
    if(((slice<74,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_75)));
    }
    if(((slice<75,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_76)));
    }
    if(((slice<76,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_77)));
    }
    if(((slice<77,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_78)));
    }
    if(((slice<78,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_79)));
    }
    if(((slice<79,1>(id184in_input)).getValueAsBool())) {
      (id184st_one_hot_or) = (or_fixed((id184st_one_hot_or),(c_hw_fix_7_0_uns_bits_80)));
    }
    id184out_output[(getCycle()+1)%2] = (id184st_one_hot_or);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id185out_o;

  { // Node ID: 185 (NodeCast)
    const HWOffsetFix<7,0,UNSIGNED> &id185in_i = id184out_output[getCycle()%2];

    id185out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id185in_i));
  }
  { // Node ID: 1955 (NodeConstantRawBits)
  }
  { // Node ID: 1954 (NodeConstantRawBits)
  }
  { // Node ID: 1987 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1987in_a = id185out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1987in_b = id1955out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1987in_c = id1954out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id1987x_1;

    (id1987x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id1987in_a,id1987in_b)),id1987in_c));
    id1987out_result[(getCycle()+1)%2] = (id1987x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1988out_o;

  { // Node ID: 1988 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id1988in_i = id1987out_result[getCycle()%2];

    id1988out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id1988in_i));
  }
  { // Node ID: 2118 (NodeFIFO)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2118in_input = id1988out_o;

    id2118out_output[(getCycle()+4)%5] = id2118in_input;
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id202out_o;

  { // Node ID: 202 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id202in_i = id2118out_output[getCycle()%5];

    id202out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id202in_i));
  }
  { // Node ID: 1953 (NodeConstantRawBits)
  }
  { // Node ID: 204 (NodeAdd)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id204in_a = id202out_o;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id204in_b = id1953out_value;

    id204out_result[(getCycle()+1)%2] = (add_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id204in_a,id204in_b));
  }
  { // Node ID: 1952 (NodeConstantRawBits)
  }
  { // Node ID: 1364 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1364in_a = id204out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1364in_b = id1952out_value;

    id1364out_result[(getCycle()+1)%2] = (lt_fixed(id1364in_a,id1364in_b));
  }
  { // Node ID: 2123 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2123in_input = id1364out_result[getCycle()%2];

    id2123out_output[(getCycle()+1)%2] = id2123in_input;
  }
  { // Node ID: 1951 (NodeConstantRawBits)
  }
  { // Node ID: 1365 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1365in_a = id204out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1365in_b = id1951out_value;

    id1365out_result[(getCycle()+1)%2] = (gt_fixed(id1365in_a,id1365in_b));
  }
  { // Node ID: 1333 (NodeConstantRawBits)
  }
  HWOffsetFix<8,0,UNSIGNED> id207out_o;

  { // Node ID: 207 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id207in_i = id204out_result[getCycle()%2];

    id207out_o = (cast_fixed2fixed<8,0,UNSIGNED,TONEAREVEN>(id207in_i));
  }
  { // Node ID: 2122 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id2122in_input = id207out_o;

    id2122out_output[(getCycle()+1)%2] = id2122in_input;
  }
  { // Node ID: 1950 (NodeConstantRawBits)
  }
  { // Node ID: 1949 (NodeConstantRawBits)
  }
  { // Node ID: 1989 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1989in_a = id1950out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1989in_b = id185out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1989in_c = id1949out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id1989x_1;

    (id1989x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id1989in_a,id1989in_b)),id1989in_c));
    id1989out_result[(getCycle()+1)%2] = (id1989x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1990out_o;

  { // Node ID: 1990 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id1990in_i = id1989out_result[getCycle()%2];

    id1990out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id1990in_i));
  }
  { // Node ID: 1948 (NodeConstantRawBits)
  }
  { // Node ID: 1366 (NodeGtInlined)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1366in_a = id1990out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1366in_b = id1948out_value;

    id1366out_result[(getCycle()+1)%2] = (gt_fixed(id1366in_a,id1366in_b));
  }
  { // Node ID: 2120 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2120in_input = id1366out_result[getCycle()%2];

    id2120out_output[(getCycle()+3)%4] = id2120in_input;
  }
  { // Node ID: 2119 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2119in_input = id182out_o;

    id2119out_output[(getCycle()+3)%4] = id2119in_input;
  }
  { // Node ID: 2358 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2358in_input = id2119out_output[getCycle()%4];

    id2358out_output[(getCycle()+4)%5] = id2358in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id196out_o;

  { // Node ID: 196 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id196in_i = id1990out_o;

    id196out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAREVEN>(id196in_i));
  }
  { // Node ID: 197 (NodeShift)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id197in_datain = id2119out_output[getCycle()%4];
    const HWOffsetFix<7,0,UNSIGNED> &id197in_shift = id196out_o;

    id197out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id197in_datain,(id197in_shift.getValueAsLong())));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id198out_output;

  { // Node ID: 198 (NodeReinterpret)
    const HWRawBits<80> &id198in_input = id197out_dataout[getCycle()%5];

    id198out_output = (cast_bits2fixed<80,-79,TWOSCOMPLEMENT>(id198in_input));
  }
  { // Node ID: 199 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id199in_sel = id2120out_output[getCycle()%4];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id199in_option0 = id2358out_output[getCycle()%5];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id199in_option1 = id198out_output;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id199x_1;

    switch((id199in_sel.getValueAsLong())) {
      case 0l:
        id199x_1 = id199in_option0;
        break;
      case 1l:
        id199x_1 = id199in_option1;
        break;
      default:
        id199x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    id199out_result[(getCycle()+1)%2] = (id199x_1);
  }
  HWOffsetFix<80,-78,TWOSCOMPLEMENT> id201out_output;

  { // Node ID: 201 (NodeReinterpret)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id201in_input = id199out_result[getCycle()%2];

    id201out_output = (cast_bits2fixed<80,-78,TWOSCOMPLEMENT>((cast_fixed2bits(id201in_input))));
  }
  { // Node ID: 205 (NodeCast)
    const HWOffsetFix<80,-78,TWOSCOMPLEMENT> &id205in_i = id201out_output;

    id205out_o[(getCycle()+1)%2] = (cast_fixed2fixed<24,-23,UNSIGNED,TONEAREVEN>(id205in_i));
  }
  HWRawBits<23> id206out_result;

  { // Node ID: 206 (NodeSlice)
    const HWOffsetFix<24,-23,UNSIGNED> &id206in_a = id205out_o[getCycle()%2];

    id206out_result = (slice<0,23>(id206in_a));
  }
  HWRawBits<32> id1367out_result;

  { // Node ID: 1367 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id1367in_in0 = id1333out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1367in_in1 = id2122out_output[getCycle()%2];
    const HWRawBits<23> &id1367in_in2 = id206out_result;

    id1367out_result = (cat((cat(id1367in_in0,id1367in_in1)),id1367in_in2));
  }
  HWFloat<8,24> id211out_output;

  { // Node ID: 211 (NodeReinterpret)
    const HWRawBits<32> &id211in_input = id1367out_result;

    id211out_output = (cast_bits2float<8,24>(id211in_input));
  }
  { // Node ID: 214 (NodeConstantRawBits)
  }
  { // Node ID: 215 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id215in_sel = id1365out_result[getCycle()%2];
    const HWFloat<8,24> &id215in_option0 = id211out_output;
    const HWFloat<8,24> &id215in_option1 = id214out_value;

    HWFloat<8,24> id215x_1;

    switch((id215in_sel.getValueAsLong())) {
      case 0l:
        id215x_1 = id215in_option0;
        break;
      case 1l:
        id215x_1 = id215in_option1;
        break;
      default:
        id215x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id215out_result[(getCycle()+1)%2] = (id215x_1);
  }
  { // Node ID: 218 (NodeConstantRawBits)
  }
  { // Node ID: 219 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id219in_sel = id2123out_output[getCycle()%2];
    const HWFloat<8,24> &id219in_option0 = id215out_result[getCycle()%2];
    const HWFloat<8,24> &id219in_option1 = id218out_value;

    HWFloat<8,24> id219x_1;

    switch((id219in_sel.getValueAsLong())) {
      case 0l:
        id219x_1 = id219in_option0;
        break;
      case 1l:
        id219x_1 = id219in_option1;
        break;
      default:
        id219x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id219out_result[(getCycle()+1)%2] = (id219x_1);
  }
  { // Node ID: 2124 (NodeFIFO)
    const HWFloat<8,24> &id2124in_input = id219out_result[getCycle()%2];

    id2124out_output[(getCycle()+1)%2] = id2124in_input;
  }
  { // Node ID: 1947 (NodeConstantRawBits)
  }
  { // Node ID: 642 (NodeLt)
    const HWFloat<8,24> &id642in_a = id2124out_output[getCycle()%2];
    const HWFloat<8,24> &id642in_b = id1947out_value;

    id642out_result[(getCycle()+2)%3] = (lt_float(id642in_a,id642in_b));
  }
  { // Node ID: 1946 (NodeConstantRawBits)
  }
  { // Node ID: 644 (NodeGte)
    const HWFloat<8,24> &id644in_a = id2124out_output[getCycle()%2];
    const HWFloat<8,24> &id644in_b = id1946out_value;

    id644out_result[(getCycle()+2)%3] = (gte_float(id644in_a,id644in_b));
  }
  { // Node ID: 645 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id645in_a = id642out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id645in_b = id644out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id645x_1;

    (id645x_1) = (or_fixed(id645in_a,id645in_b));
    id645out_result[(getCycle()+1)%2] = (id645x_1);
  }
  { // Node ID: 2204 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2204in_input = id645out_result[getCycle()%2];

    id2204out_output[(getCycle()+64)%65] = id2204in_input;
  }
  HWRawBits<1> id1368out_result;

  { // Node ID: 1368 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id1368in_a = id174out_result[getCycle()%2];

    id1368out_result = (slice<79,1>(id1368in_a));
  }
  { // Node ID: 2136 (NodeFIFO)
    const HWRawBits<1> &id2136in_input = id1368out_result;

    id2136out_output[(getCycle()+29)%30] = id2136in_input;
  }
  { // Node ID: 1945 (NodeConstantRawBits)
  }
  HWRawBits<8> id240out_result;

  { // Node ID: 240 (NodeSlice)
    const HWFloat<8,24> &id240in_a = id2124out_output[getCycle()%2];

    id240out_result = (slice<23,8>(id240in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id241out_output;

  { // Node ID: 241 (NodeReinterpret)
    const HWRawBits<8> &id241in_input = id240out_result;

    id241out_output = (cast_bits2fixed<8,0,UNSIGNED>(id241in_input));
  }
  { // Node ID: 1944 (NodeConstantRawBits)
  }
  { // Node ID: 1991 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1991in_a = id1945out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1991in_b = id241out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id1991in_c = id1944out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id1991x_1;

    (id1991x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id1991in_a,id1991in_b)),id1991in_c));
    id1991out_result[(getCycle()+1)%2] = (id1991x_1);
  }
  HWRawBits<1> id1369out_result;

  { // Node ID: 1369 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1369in_a = id1991out_result[getCycle()%2];

    id1369out_result = (slice<8,1>(id1369in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1370out_output;

  { // Node ID: 1370 (NodeReinterpret)
    const HWRawBits<1> &id1370in_input = id1369out_result;

    id1370out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1370in_input));
  }
  { // Node ID: 2129 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2129in_input = id1370out_output;

    id2129out_output[(getCycle()+4)%5] = id2129in_input;
  }
  { // Node ID: 238 (NodeConstantRawBits)
  }
  { // Node ID: 2047 (NodeConstantRawBits)
  }
  { // Node ID: 230 (NodeConstantRawBits)
  }
  HWRawBits<31> id227out_result;

  { // Node ID: 227 (NodeSlice)
    const HWFloat<8,24> &id227in_a = id219out_result[getCycle()%2];

    id227out_result = (slice<0,31>(id227in_a));
  }
  { // Node ID: 1943 (NodeConstantRawBits)
  }
  { // Node ID: 1371 (NodeNeqInlined)
    const HWRawBits<31> &id1371in_a = id227out_result;
    const HWRawBits<31> &id1371in_b = id1943out_value;

    id1371out_result[(getCycle()+1)%2] = (neq_bits(id1371in_a,id1371in_b));
  }
  HWRawBits<23> id226out_result;

  { // Node ID: 226 (NodeSlice)
    const HWFloat<8,24> &id226in_a = id2124out_output[getCycle()%2];

    id226out_result = (slice<0,23>(id226in_a));
  }
  HWRawBits<25> id1372out_result;

  { // Node ID: 1372 (NodeCat)
    const HWRawBits<1> &id1372in_in0 = id230out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1372in_in1 = id1371out_result[getCycle()%2];
    const HWRawBits<23> &id1372in_in2 = id226out_result;

    id1372out_result = (cat((cat(id1372in_in0,id1372in_in1)),id1372in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id233out_output;

  { // Node ID: 233 (NodeReinterpret)
    const HWRawBits<25> &id233in_input = id1372out_result;

    id233out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id233in_input));
  }
  HWRawBits<1> id234out_result;

  { // Node ID: 234 (NodeSlice)
    const HWFloat<8,24> &id234in_a = id2124out_output[getCycle()%2];

    id234out_result = (slice<31,1>(id234in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id235out_output;

  { // Node ID: 235 (NodeReinterpret)
    const HWRawBits<1> &id235in_input = id234out_result;

    id235out_output = (cast_bits2fixed<1,0,UNSIGNED>(id235in_input));
  }
  { // Node ID: 2014 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2014in_a = id2047out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2014in_b = id233out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2014in_sub = id235out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2014x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2014x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2014x_3;

    (id2014x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2014in_a,id2014in_b));
    (id2014x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2014in_a,id2014in_b));
    switch((id2014in_sub.getValueAsLong())) {
      case 0l:
        id2014x_3 = (id2014x_1);
        break;
      case 1l:
        id2014x_3 = (id2014x_2);
        break;
      default:
        id2014x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2014out_result[(getCycle()+1)%2] = (id2014x_3);
  }
  HWRawBits<30> id239out_result;

  { // Node ID: 239 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id239in_in0 = id238out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id239in_in1 = id2014out_result[getCycle()%2];

    id239out_result = (cat(id239in_in0,id239in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id248out_o;

  { // Node ID: 248 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id248in_i = id1991out_result[getCycle()%2];

    id248out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id248in_i));
  }
  { // Node ID: 249 (NodeShift)
    const HWRawBits<30> &id249in_datain = id239out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id249in_shift = id248out_o;

    id249out_dataout[(getCycle()+4)%5] = (shift_left_bits(id249in_datain,(id249in_shift.getValueAsLong())));
  }
  HWRawBits<7> id250out_result;

  { // Node ID: 250 (NodeSlice)
    const HWRawBits<30> &id250in_a = id249out_dataout[getCycle()%5];

    id250out_result = (slice<23,7>(id250in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id251out_output;

  { // Node ID: 251 (NodeReinterpret)
    const HWRawBits<7> &id251in_input = id250out_result;

    id251out_output = (cast_bits2fixed<7,0,UNSIGNED>(id251in_input));
  }
  { // Node ID: 252 (NodeConstantRawBits)
  }
  { // Node ID: 253 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id253in_sel = id2129out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id253in_option0 = id251out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id253in_option1 = id252out_value;

    HWOffsetFix<7,0,UNSIGNED> id253x_1;

    switch((id253in_sel.getValueAsLong())) {
      case 0l:
        id253x_1 = id253in_option0;
        break;
      case 1l:
        id253x_1 = id253in_option1;
        break;
      default:
        id253x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id253out_result[(getCycle()+1)%2] = (id253x_1);
  }
  { // Node ID: 2130 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2130in_input = id253out_result[getCycle()%2];

    id2130out_output[(getCycle()+9)%10] = id2130in_input;
  }
  { // Node ID: 1287 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1287in_addr = id2130out_output[getCycle()%10];

    HWRawBits<128> id1287x_1;

    switch(((long)((id1287in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1287x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1287x_1 = (id1287sta_rom_store[(id1287in_addr.getValueAsLong())]);
        break;
      default:
        id1287x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1287out_dout[(getCycle()+2)%3] = (id1287x_1);
  }
  HWRawBits<32> id1294out_result;

  { // Node ID: 1294 (NodeSlice)
    const HWRawBits<128> &id1294in_a = id1287out_dout[getCycle()%3];

    id1294out_result = (slice<96,32>(id1294in_a));
  }
  HWFloat<8,24> id1295out_output;

  { // Node ID: 1295 (NodeReinterpret)
    const HWRawBits<32> &id1295in_input = id1294out_result;

    id1295out_output = (cast_bits2float<8,24>(id1295in_input));
  }
  { // Node ID: 1942 (NodeConstantRawBits)
  }
  HWRawBits<8> id441out_result;

  { // Node ID: 441 (NodeSlice)
    const HWFloat<8,24> &id441in_a = id2124out_output[getCycle()%2];

    id441out_result = (slice<23,8>(id441in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id442out_output;

  { // Node ID: 442 (NodeReinterpret)
    const HWRawBits<8> &id442in_input = id441out_result;

    id442out_output = (cast_bits2fixed<8,0,UNSIGNED>(id442in_input));
  }
  { // Node ID: 1941 (NodeConstantRawBits)
  }
  { // Node ID: 1992 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1992in_a = id1942out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1992in_b = id442out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id1992in_c = id1941out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id1992x_1;

    (id1992x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id1992in_a,id1992in_b)),id1992in_c));
    id1992out_result[(getCycle()+1)%2] = (id1992x_1);
  }
  HWRawBits<1> id1373out_result;

  { // Node ID: 1373 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1373in_a = id1992out_result[getCycle()%2];

    id1373out_result = (slice<8,1>(id1373in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1374out_output;

  { // Node ID: 1374 (NodeReinterpret)
    const HWRawBits<1> &id1374in_input = id1373out_result;

    id1374out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1374in_input));
  }
  { // Node ID: 2134 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2134in_input = id1374out_output;

    id2134out_output[(getCycle()+4)%5] = id2134in_input;
  }
  { // Node ID: 439 (NodeConstantRawBits)
  }
  { // Node ID: 2046 (NodeConstantRawBits)
  }
  { // Node ID: 431 (NodeConstantRawBits)
  }
  HWRawBits<31> id428out_result;

  { // Node ID: 428 (NodeSlice)
    const HWFloat<8,24> &id428in_a = id219out_result[getCycle()%2];

    id428out_result = (slice<0,31>(id428in_a));
  }
  { // Node ID: 1940 (NodeConstantRawBits)
  }
  { // Node ID: 1375 (NodeNeqInlined)
    const HWRawBits<31> &id1375in_a = id428out_result;
    const HWRawBits<31> &id1375in_b = id1940out_value;

    id1375out_result[(getCycle()+1)%2] = (neq_bits(id1375in_a,id1375in_b));
  }
  HWRawBits<23> id427out_result;

  { // Node ID: 427 (NodeSlice)
    const HWFloat<8,24> &id427in_a = id2124out_output[getCycle()%2];

    id427out_result = (slice<0,23>(id427in_a));
  }
  HWRawBits<25> id1376out_result;

  { // Node ID: 1376 (NodeCat)
    const HWRawBits<1> &id1376in_in0 = id431out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1376in_in1 = id1375out_result[getCycle()%2];
    const HWRawBits<23> &id1376in_in2 = id427out_result;

    id1376out_result = (cat((cat(id1376in_in0,id1376in_in1)),id1376in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id434out_output;

  { // Node ID: 434 (NodeReinterpret)
    const HWRawBits<25> &id434in_input = id1376out_result;

    id434out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id434in_input));
  }
  HWRawBits<1> id435out_result;

  { // Node ID: 435 (NodeSlice)
    const HWFloat<8,24> &id435in_a = id2124out_output[getCycle()%2];

    id435out_result = (slice<31,1>(id435in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id436out_output;

  { // Node ID: 436 (NodeReinterpret)
    const HWRawBits<1> &id436in_input = id435out_result;

    id436out_output = (cast_bits2fixed<1,0,UNSIGNED>(id436in_input));
  }
  { // Node ID: 2016 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2016in_a = id2046out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2016in_b = id434out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2016in_sub = id436out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2016x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2016x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2016x_3;

    (id2016x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2016in_a,id2016in_b));
    (id2016x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2016in_a,id2016in_b));
    switch((id2016in_sub.getValueAsLong())) {
      case 0l:
        id2016x_3 = (id2016x_1);
        break;
      case 1l:
        id2016x_3 = (id2016x_2);
        break;
      default:
        id2016x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2016out_result[(getCycle()+1)%2] = (id2016x_3);
  }
  HWRawBits<30> id440out_result;

  { // Node ID: 440 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id440in_in0 = id439out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id440in_in1 = id2016out_result[getCycle()%2];

    id440out_result = (cat(id440in_in0,id440in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id449out_o;

  { // Node ID: 449 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id449in_i = id1992out_result[getCycle()%2];

    id449out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id449in_i));
  }
  { // Node ID: 450 (NodeShift)
    const HWRawBits<30> &id450in_datain = id440out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id450in_shift = id449out_o;

    id450out_dataout[(getCycle()+4)%5] = (shift_left_bits(id450in_datain,(id450in_shift.getValueAsLong())));
  }
  HWRawBits<7> id451out_result;

  { // Node ID: 451 (NodeSlice)
    const HWRawBits<30> &id451in_a = id450out_dataout[getCycle()%5];

    id451out_result = (slice<23,7>(id451in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id452out_output;

  { // Node ID: 452 (NodeReinterpret)
    const HWRawBits<7> &id452in_input = id451out_result;

    id452out_output = (cast_bits2fixed<7,0,UNSIGNED>(id452in_input));
  }
  { // Node ID: 453 (NodeConstantRawBits)
  }
  { // Node ID: 454 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id454in_sel = id2134out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id454in_option0 = id452out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id454in_option1 = id453out_value;

    HWOffsetFix<7,0,UNSIGNED> id454x_1;

    switch((id454in_sel.getValueAsLong())) {
      case 0l:
        id454x_1 = id454in_option0;
        break;
      case 1l:
        id454x_1 = id454in_option1;
        break;
      default:
        id454x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id454out_result[(getCycle()+1)%2] = (id454x_1);
  }
  { // Node ID: 2135 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2135in_input = id454out_result[getCycle()%2];

    id2135out_output[(getCycle()+9)%10] = id2135in_input;
  }
  { // Node ID: 1296 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1296in_addr = id2135out_output[getCycle()%10];

    HWRawBits<128> id1296x_1;

    switch(((long)((id1296in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1296x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1296x_1 = (id1296sta_rom_store[(id1296in_addr.getValueAsLong())]);
        break;
      default:
        id1296x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1296out_dout[(getCycle()+2)%3] = (id1296x_1);
  }
  HWRawBits<32> id1303out_result;

  { // Node ID: 1303 (NodeSlice)
    const HWRawBits<128> &id1303in_a = id1296out_dout[getCycle()%3];

    id1303out_result = (slice<96,32>(id1303in_a));
  }
  HWFloat<8,24> id1304out_output;

  { // Node ID: 1304 (NodeReinterpret)
    const HWRawBits<32> &id1304in_input = id1303out_result;

    id1304out_output = (cast_bits2float<8,24>(id1304in_input));
  }
  { // Node ID: 632 (NodeMux)
    const HWRawBits<1> &id632in_sel = id2136out_output[getCycle()%30];
    const HWFloat<8,24> &id632in_option0 = id1295out_output;
    const HWFloat<8,24> &id632in_option1 = id1304out_output;

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
  { // Node ID: 1981 (NodePO2FPMult)
    const HWFloat<8,24> &id1981in_floatIn = id219out_result[getCycle()%2];

    id1981out_floatOut[(getCycle()+1)%2] = (mul_float(id1981in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2137 (NodeFIFO)
    const HWFloat<8,24> &id2137in_input = id1981out_floatOut[getCycle()%2];

    id2137out_output[(getCycle()+3)%4] = id2137in_input;
  }
  HWRawBits<1> id263out_result;

  { // Node ID: 263 (NodeSlice)
    const HWFloat<8,24> &id263in_a = id2137out_output[getCycle()%4];

    id263out_result = (slice<31,1>(id263in_a));
  }
  { // Node ID: 2166 (NodeFIFO)
    const HWRawBits<1> &id2166in_input = id263out_result;

    id2166out_output[(getCycle()+6)%7] = id2166in_input;
  }
  HWRawBits<8> id256out_result;

  { // Node ID: 256 (NodeSlice)
    const HWFloat<8,24> &id256in_a = id1981out_floatOut[getCycle()%2];

    id256out_result = (slice<23,8>(id256in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id257out_output;

  { // Node ID: 257 (NodeReinterpret)
    const HWRawBits<8> &id257in_input = id256out_result;

    id257out_output = (cast_bits2fixed<8,0,UNSIGNED>(id257in_input));
  }
  { // Node ID: 1938 (NodeConstantRawBits)
  }
  { // Node ID: 259 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id259in_a = id257out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id259in_b = id1938out_value;

    id259out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id259in_a,id259in_b));
  }
  { // Node ID: 1937 (NodeConstantRawBits)
  }
  { // Node ID: 1377 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1377in_a = id259out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1377in_b = id1937out_value;

    id1377out_result[(getCycle()+1)%2] = (gte_fixed(id1377in_a,id1377in_b));
  }
  { // Node ID: 1936 (NodeConstantRawBits)
  }
  { // Node ID: 1378 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1378in_a = id259out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1378in_b = id1936out_value;

    id1378out_result[(getCycle()+1)%2] = (lte_fixed(id1378in_a,id1378in_b));
  }
  { // Node ID: 268 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id268in_a = id1377out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id268in_b = id1378out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id268x_1;

    (id268x_1) = (or_fixed(id268in_a,id268in_b));
    id268out_result[(getCycle()+1)%2] = (id268x_1);
  }
  { // Node ID: 1935 (NodeConstantRawBits)
  }
  { // Node ID: 1379 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1379in_a = id259out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1379in_b = id1935out_value;

    id1379out_result[(getCycle()+1)%2] = (lte_fixed(id1379in_a,id1379in_b));
  }
  { // Node ID: 2138 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2138in_input = id1379out_result[getCycle()%2];

    id2138out_output[(getCycle()+1)%2] = id2138in_input;
  }
  HWRawBits<2> id420out_result;

  { // Node ID: 420 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id420in_in0 = id268out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id420in_in1 = id2138out_output[getCycle()%2];

    id420out_result = (cat(id420in_in0,id420in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id421out_output;

  { // Node ID: 421 (NodeReinterpret)
    const HWRawBits<2> &id421in_input = id420out_result;

    id421out_output = (cast_bits2fixed<2,0,UNSIGNED>(id421in_input));
  }
  { // Node ID: 2164 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2164in_input = id421out_output;

    id2164out_output[(getCycle()+5)%6] = id2164in_input;
  }
  { // Node ID: 1934 (NodeConstantRawBits)
  }
  { // Node ID: 1933 (NodeConstantRawBits)
  }
  { // Node ID: 279 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id279in_a = id1933out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id279in_b = id259out_result[getCycle()%2];

    id279out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id279in_a,id279in_b));
  }
  { // Node ID: 1380 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1380in_a = id1934out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1380in_b = id279out_result[getCycle()%2];

    id1380out_result[(getCycle()+1)%2] = (lt_fixed(id1380in_a,id1380in_b));
  }
  { // Node ID: 415 (NodeConstantRawBits)
  }
  HWRawBits<1> id1693out_result;

  { // Node ID: 1693 (NodeSlice)
    const HWFloat<8,24> &id1693in_a = id2137out_output[getCycle()%4];

    id1693out_result = (slice<22,1>(id1693in_a));
  }
  { // Node ID: 416 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id416in_sel = id1380out_result[getCycle()%2];
    const HWRawBits<1> &id416in_option0 = id415out_value;
    const HWRawBits<1> &id416in_option1 = id1693out_result;

    HWRawBits<1> id416x_1;

    switch((id416in_sel.getValueAsLong())) {
      case 0l:
        id416x_1 = id416in_option0;
        break;
      case 1l:
        id416x_1 = id416in_option1;
        break;
      default:
        id416x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id416out_result[(getCycle()+1)%2] = (id416x_1);
  }
  { // Node ID: 1932 (NodeConstantRawBits)
  }
  { // Node ID: 1382 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1382in_a = id1932out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1382in_b = id279out_result[getCycle()%2];

    id1382out_result[(getCycle()+1)%2] = (lt_fixed(id1382in_a,id1382in_b));
  }
  { // Node ID: 409 (NodeConstantRawBits)
  }
  HWRawBits<1> id1694out_result;

  { // Node ID: 1694 (NodeSlice)
    const HWFloat<8,24> &id1694in_a = id2137out_output[getCycle()%4];

    id1694out_result = (slice<21,1>(id1694in_a));
  }
  { // Node ID: 410 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id410in_sel = id1382out_result[getCycle()%2];
    const HWRawBits<1> &id410in_option0 = id409out_value;
    const HWRawBits<1> &id410in_option1 = id1694out_result;

    HWRawBits<1> id410x_1;

    switch((id410in_sel.getValueAsLong())) {
      case 0l:
        id410x_1 = id410in_option0;
        break;
      case 1l:
        id410x_1 = id410in_option1;
        break;
      default:
        id410x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id410out_result[(getCycle()+1)%2] = (id410x_1);
  }
  { // Node ID: 1931 (NodeConstantRawBits)
  }
  { // Node ID: 1384 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1384in_a = id1931out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1384in_b = id279out_result[getCycle()%2];

    id1384out_result[(getCycle()+1)%2] = (lt_fixed(id1384in_a,id1384in_b));
  }
  { // Node ID: 403 (NodeConstantRawBits)
  }
  HWRawBits<1> id1695out_result;

  { // Node ID: 1695 (NodeSlice)
    const HWFloat<8,24> &id1695in_a = id2137out_output[getCycle()%4];

    id1695out_result = (slice<20,1>(id1695in_a));
  }
  { // Node ID: 404 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id404in_sel = id1384out_result[getCycle()%2];
    const HWRawBits<1> &id404in_option0 = id403out_value;
    const HWRawBits<1> &id404in_option1 = id1695out_result;

    HWRawBits<1> id404x_1;

    switch((id404in_sel.getValueAsLong())) {
      case 0l:
        id404x_1 = id404in_option0;
        break;
      case 1l:
        id404x_1 = id404in_option1;
        break;
      default:
        id404x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id404out_result[(getCycle()+1)%2] = (id404x_1);
  }
  { // Node ID: 1930 (NodeConstantRawBits)
  }
  { // Node ID: 1386 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1386in_a = id1930out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1386in_b = id279out_result[getCycle()%2];

    id1386out_result[(getCycle()+1)%2] = (lt_fixed(id1386in_a,id1386in_b));
  }
  { // Node ID: 397 (NodeConstantRawBits)
  }
  HWRawBits<1> id1696out_result;

  { // Node ID: 1696 (NodeSlice)
    const HWFloat<8,24> &id1696in_a = id2137out_output[getCycle()%4];

    id1696out_result = (slice<19,1>(id1696in_a));
  }
  { // Node ID: 398 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id398in_sel = id1386out_result[getCycle()%2];
    const HWRawBits<1> &id398in_option0 = id397out_value;
    const HWRawBits<1> &id398in_option1 = id1696out_result;

    HWRawBits<1> id398x_1;

    switch((id398in_sel.getValueAsLong())) {
      case 0l:
        id398x_1 = id398in_option0;
        break;
      case 1l:
        id398x_1 = id398in_option1;
        break;
      default:
        id398x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id398out_result[(getCycle()+1)%2] = (id398x_1);
  }
  { // Node ID: 1929 (NodeConstantRawBits)
  }
  { // Node ID: 1388 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1388in_a = id1929out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1388in_b = id279out_result[getCycle()%2];

    id1388out_result[(getCycle()+1)%2] = (lt_fixed(id1388in_a,id1388in_b));
  }
  { // Node ID: 391 (NodeConstantRawBits)
  }
  HWRawBits<1> id1697out_result;

  { // Node ID: 1697 (NodeSlice)
    const HWFloat<8,24> &id1697in_a = id2137out_output[getCycle()%4];

    id1697out_result = (slice<18,1>(id1697in_a));
  }
  { // Node ID: 392 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id392in_sel = id1388out_result[getCycle()%2];
    const HWRawBits<1> &id392in_option0 = id391out_value;
    const HWRawBits<1> &id392in_option1 = id1697out_result;

    HWRawBits<1> id392x_1;

    switch((id392in_sel.getValueAsLong())) {
      case 0l:
        id392x_1 = id392in_option0;
        break;
      case 1l:
        id392x_1 = id392in_option1;
        break;
      default:
        id392x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id392out_result[(getCycle()+1)%2] = (id392x_1);
  }
  { // Node ID: 1928 (NodeConstantRawBits)
  }
  { // Node ID: 1390 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1390in_a = id1928out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1390in_b = id279out_result[getCycle()%2];

    id1390out_result[(getCycle()+1)%2] = (lt_fixed(id1390in_a,id1390in_b));
  }
  { // Node ID: 385 (NodeConstantRawBits)
  }
  HWRawBits<1> id1698out_result;

  { // Node ID: 1698 (NodeSlice)
    const HWFloat<8,24> &id1698in_a = id2137out_output[getCycle()%4];

    id1698out_result = (slice<17,1>(id1698in_a));
  }
  { // Node ID: 386 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id386in_sel = id1390out_result[getCycle()%2];
    const HWRawBits<1> &id386in_option0 = id385out_value;
    const HWRawBits<1> &id386in_option1 = id1698out_result;

    HWRawBits<1> id386x_1;

    switch((id386in_sel.getValueAsLong())) {
      case 0l:
        id386x_1 = id386in_option0;
        break;
      case 1l:
        id386x_1 = id386in_option1;
        break;
      default:
        id386x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id386out_result[(getCycle()+1)%2] = (id386x_1);
  }
  { // Node ID: 1927 (NodeConstantRawBits)
  }
  { // Node ID: 1392 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1392in_a = id1927out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1392in_b = id279out_result[getCycle()%2];

    id1392out_result[(getCycle()+1)%2] = (lt_fixed(id1392in_a,id1392in_b));
  }
  { // Node ID: 379 (NodeConstantRawBits)
  }
  HWRawBits<1> id1699out_result;

  { // Node ID: 1699 (NodeSlice)
    const HWFloat<8,24> &id1699in_a = id2137out_output[getCycle()%4];

    id1699out_result = (slice<16,1>(id1699in_a));
  }
  { // Node ID: 380 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id380in_sel = id1392out_result[getCycle()%2];
    const HWRawBits<1> &id380in_option0 = id379out_value;
    const HWRawBits<1> &id380in_option1 = id1699out_result;

    HWRawBits<1> id380x_1;

    switch((id380in_sel.getValueAsLong())) {
      case 0l:
        id380x_1 = id380in_option0;
        break;
      case 1l:
        id380x_1 = id380in_option1;
        break;
      default:
        id380x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id380out_result[(getCycle()+1)%2] = (id380x_1);
  }
  { // Node ID: 1926 (NodeConstantRawBits)
  }
  { // Node ID: 1394 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1394in_a = id1926out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1394in_b = id279out_result[getCycle()%2];

    id1394out_result[(getCycle()+1)%2] = (lt_fixed(id1394in_a,id1394in_b));
  }
  { // Node ID: 373 (NodeConstantRawBits)
  }
  HWRawBits<1> id1700out_result;

  { // Node ID: 1700 (NodeSlice)
    const HWFloat<8,24> &id1700in_a = id2137out_output[getCycle()%4];

    id1700out_result = (slice<15,1>(id1700in_a));
  }
  { // Node ID: 374 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id374in_sel = id1394out_result[getCycle()%2];
    const HWRawBits<1> &id374in_option0 = id373out_value;
    const HWRawBits<1> &id374in_option1 = id1700out_result;

    HWRawBits<1> id374x_1;

    switch((id374in_sel.getValueAsLong())) {
      case 0l:
        id374x_1 = id374in_option0;
        break;
      case 1l:
        id374x_1 = id374in_option1;
        break;
      default:
        id374x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id374out_result[(getCycle()+1)%2] = (id374x_1);
  }
  { // Node ID: 1925 (NodeConstantRawBits)
  }
  { // Node ID: 1396 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1396in_a = id1925out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1396in_b = id279out_result[getCycle()%2];

    id1396out_result[(getCycle()+1)%2] = (lt_fixed(id1396in_a,id1396in_b));
  }
  { // Node ID: 367 (NodeConstantRawBits)
  }
  HWRawBits<1> id1701out_result;

  { // Node ID: 1701 (NodeSlice)
    const HWFloat<8,24> &id1701in_a = id2137out_output[getCycle()%4];

    id1701out_result = (slice<14,1>(id1701in_a));
  }
  { // Node ID: 368 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id368in_sel = id1396out_result[getCycle()%2];
    const HWRawBits<1> &id368in_option0 = id367out_value;
    const HWRawBits<1> &id368in_option1 = id1701out_result;

    HWRawBits<1> id368x_1;

    switch((id368in_sel.getValueAsLong())) {
      case 0l:
        id368x_1 = id368in_option0;
        break;
      case 1l:
        id368x_1 = id368in_option1;
        break;
      default:
        id368x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id368out_result[(getCycle()+1)%2] = (id368x_1);
  }
  { // Node ID: 1924 (NodeConstantRawBits)
  }
  { // Node ID: 1398 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1398in_a = id1924out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1398in_b = id279out_result[getCycle()%2];

    id1398out_result[(getCycle()+1)%2] = (lt_fixed(id1398in_a,id1398in_b));
  }
  { // Node ID: 361 (NodeConstantRawBits)
  }
  HWRawBits<1> id1702out_result;

  { // Node ID: 1702 (NodeSlice)
    const HWFloat<8,24> &id1702in_a = id2137out_output[getCycle()%4];

    id1702out_result = (slice<13,1>(id1702in_a));
  }
  { // Node ID: 362 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id362in_sel = id1398out_result[getCycle()%2];
    const HWRawBits<1> &id362in_option0 = id361out_value;
    const HWRawBits<1> &id362in_option1 = id1702out_result;

    HWRawBits<1> id362x_1;

    switch((id362in_sel.getValueAsLong())) {
      case 0l:
        id362x_1 = id362in_option0;
        break;
      case 1l:
        id362x_1 = id362in_option1;
        break;
      default:
        id362x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id362out_result[(getCycle()+1)%2] = (id362x_1);
  }
  { // Node ID: 1923 (NodeConstantRawBits)
  }
  { // Node ID: 1400 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1400in_a = id1923out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1400in_b = id279out_result[getCycle()%2];

    id1400out_result[(getCycle()+1)%2] = (lt_fixed(id1400in_a,id1400in_b));
  }
  { // Node ID: 355 (NodeConstantRawBits)
  }
  HWRawBits<1> id1703out_result;

  { // Node ID: 1703 (NodeSlice)
    const HWFloat<8,24> &id1703in_a = id2137out_output[getCycle()%4];

    id1703out_result = (slice<12,1>(id1703in_a));
  }
  { // Node ID: 356 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id356in_sel = id1400out_result[getCycle()%2];
    const HWRawBits<1> &id356in_option0 = id355out_value;
    const HWRawBits<1> &id356in_option1 = id1703out_result;

    HWRawBits<1> id356x_1;

    switch((id356in_sel.getValueAsLong())) {
      case 0l:
        id356x_1 = id356in_option0;
        break;
      case 1l:
        id356x_1 = id356in_option1;
        break;
      default:
        id356x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id356out_result[(getCycle()+1)%2] = (id356x_1);
  }
  { // Node ID: 1922 (NodeConstantRawBits)
  }
  { // Node ID: 1402 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1402in_a = id1922out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1402in_b = id279out_result[getCycle()%2];

    id1402out_result[(getCycle()+1)%2] = (lt_fixed(id1402in_a,id1402in_b));
  }
  { // Node ID: 349 (NodeConstantRawBits)
  }
  HWRawBits<1> id1704out_result;

  { // Node ID: 1704 (NodeSlice)
    const HWFloat<8,24> &id1704in_a = id2137out_output[getCycle()%4];

    id1704out_result = (slice<11,1>(id1704in_a));
  }
  { // Node ID: 350 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id350in_sel = id1402out_result[getCycle()%2];
    const HWRawBits<1> &id350in_option0 = id349out_value;
    const HWRawBits<1> &id350in_option1 = id1704out_result;

    HWRawBits<1> id350x_1;

    switch((id350in_sel.getValueAsLong())) {
      case 0l:
        id350x_1 = id350in_option0;
        break;
      case 1l:
        id350x_1 = id350in_option1;
        break;
      default:
        id350x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id350out_result[(getCycle()+1)%2] = (id350x_1);
  }
  { // Node ID: 1921 (NodeConstantRawBits)
  }
  { // Node ID: 1404 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1404in_a = id1921out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1404in_b = id279out_result[getCycle()%2];

    id1404out_result[(getCycle()+1)%2] = (lt_fixed(id1404in_a,id1404in_b));
  }
  { // Node ID: 343 (NodeConstantRawBits)
  }
  HWRawBits<1> id1705out_result;

  { // Node ID: 1705 (NodeSlice)
    const HWFloat<8,24> &id1705in_a = id2137out_output[getCycle()%4];

    id1705out_result = (slice<10,1>(id1705in_a));
  }
  { // Node ID: 344 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id344in_sel = id1404out_result[getCycle()%2];
    const HWRawBits<1> &id344in_option0 = id343out_value;
    const HWRawBits<1> &id344in_option1 = id1705out_result;

    HWRawBits<1> id344x_1;

    switch((id344in_sel.getValueAsLong())) {
      case 0l:
        id344x_1 = id344in_option0;
        break;
      case 1l:
        id344x_1 = id344in_option1;
        break;
      default:
        id344x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id344out_result[(getCycle()+1)%2] = (id344x_1);
  }
  { // Node ID: 1920 (NodeConstantRawBits)
  }
  { // Node ID: 1406 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1406in_a = id1920out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1406in_b = id279out_result[getCycle()%2];

    id1406out_result[(getCycle()+1)%2] = (lt_fixed(id1406in_a,id1406in_b));
  }
  { // Node ID: 337 (NodeConstantRawBits)
  }
  HWRawBits<1> id1706out_result;

  { // Node ID: 1706 (NodeSlice)
    const HWFloat<8,24> &id1706in_a = id2137out_output[getCycle()%4];

    id1706out_result = (slice<9,1>(id1706in_a));
  }
  { // Node ID: 338 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id338in_sel = id1406out_result[getCycle()%2];
    const HWRawBits<1> &id338in_option0 = id337out_value;
    const HWRawBits<1> &id338in_option1 = id1706out_result;

    HWRawBits<1> id338x_1;

    switch((id338in_sel.getValueAsLong())) {
      case 0l:
        id338x_1 = id338in_option0;
        break;
      case 1l:
        id338x_1 = id338in_option1;
        break;
      default:
        id338x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id338out_result[(getCycle()+1)%2] = (id338x_1);
  }
  { // Node ID: 1919 (NodeConstantRawBits)
  }
  { // Node ID: 1408 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1408in_a = id1919out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1408in_b = id279out_result[getCycle()%2];

    id1408out_result[(getCycle()+1)%2] = (lt_fixed(id1408in_a,id1408in_b));
  }
  { // Node ID: 331 (NodeConstantRawBits)
  }
  HWRawBits<1> id1707out_result;

  { // Node ID: 1707 (NodeSlice)
    const HWFloat<8,24> &id1707in_a = id2137out_output[getCycle()%4];

    id1707out_result = (slice<8,1>(id1707in_a));
  }
  { // Node ID: 332 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id332in_sel = id1408out_result[getCycle()%2];
    const HWRawBits<1> &id332in_option0 = id331out_value;
    const HWRawBits<1> &id332in_option1 = id1707out_result;

    HWRawBits<1> id332x_1;

    switch((id332in_sel.getValueAsLong())) {
      case 0l:
        id332x_1 = id332in_option0;
        break;
      case 1l:
        id332x_1 = id332in_option1;
        break;
      default:
        id332x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id332out_result[(getCycle()+1)%2] = (id332x_1);
  }
  { // Node ID: 1918 (NodeConstantRawBits)
  }
  { // Node ID: 1410 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1410in_a = id1918out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1410in_b = id279out_result[getCycle()%2];

    id1410out_result[(getCycle()+1)%2] = (lt_fixed(id1410in_a,id1410in_b));
  }
  { // Node ID: 325 (NodeConstantRawBits)
  }
  HWRawBits<1> id1708out_result;

  { // Node ID: 1708 (NodeSlice)
    const HWFloat<8,24> &id1708in_a = id2137out_output[getCycle()%4];

    id1708out_result = (slice<7,1>(id1708in_a));
  }
  { // Node ID: 326 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id326in_sel = id1410out_result[getCycle()%2];
    const HWRawBits<1> &id326in_option0 = id325out_value;
    const HWRawBits<1> &id326in_option1 = id1708out_result;

    HWRawBits<1> id326x_1;

    switch((id326in_sel.getValueAsLong())) {
      case 0l:
        id326x_1 = id326in_option0;
        break;
      case 1l:
        id326x_1 = id326in_option1;
        break;
      default:
        id326x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id326out_result[(getCycle()+1)%2] = (id326x_1);
  }
  { // Node ID: 1917 (NodeConstantRawBits)
  }
  { // Node ID: 1412 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1412in_a = id1917out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1412in_b = id279out_result[getCycle()%2];

    id1412out_result[(getCycle()+1)%2] = (lt_fixed(id1412in_a,id1412in_b));
  }
  { // Node ID: 319 (NodeConstantRawBits)
  }
  HWRawBits<1> id1709out_result;

  { // Node ID: 1709 (NodeSlice)
    const HWFloat<8,24> &id1709in_a = id2137out_output[getCycle()%4];

    id1709out_result = (slice<6,1>(id1709in_a));
  }
  { // Node ID: 320 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id320in_sel = id1412out_result[getCycle()%2];
    const HWRawBits<1> &id320in_option0 = id319out_value;
    const HWRawBits<1> &id320in_option1 = id1709out_result;

    HWRawBits<1> id320x_1;

    switch((id320in_sel.getValueAsLong())) {
      case 0l:
        id320x_1 = id320in_option0;
        break;
      case 1l:
        id320x_1 = id320in_option1;
        break;
      default:
        id320x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id320out_result[(getCycle()+1)%2] = (id320x_1);
  }
  { // Node ID: 1916 (NodeConstantRawBits)
  }
  { // Node ID: 1414 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1414in_a = id1916out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1414in_b = id279out_result[getCycle()%2];

    id1414out_result[(getCycle()+1)%2] = (lt_fixed(id1414in_a,id1414in_b));
  }
  { // Node ID: 313 (NodeConstantRawBits)
  }
  HWRawBits<1> id1710out_result;

  { // Node ID: 1710 (NodeSlice)
    const HWFloat<8,24> &id1710in_a = id2137out_output[getCycle()%4];

    id1710out_result = (slice<5,1>(id1710in_a));
  }
  { // Node ID: 314 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id314in_sel = id1414out_result[getCycle()%2];
    const HWRawBits<1> &id314in_option0 = id313out_value;
    const HWRawBits<1> &id314in_option1 = id1710out_result;

    HWRawBits<1> id314x_1;

    switch((id314in_sel.getValueAsLong())) {
      case 0l:
        id314x_1 = id314in_option0;
        break;
      case 1l:
        id314x_1 = id314in_option1;
        break;
      default:
        id314x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id314out_result[(getCycle()+1)%2] = (id314x_1);
  }
  { // Node ID: 1915 (NodeConstantRawBits)
  }
  { // Node ID: 1416 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1416in_a = id1915out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1416in_b = id279out_result[getCycle()%2];

    id1416out_result[(getCycle()+1)%2] = (lt_fixed(id1416in_a,id1416in_b));
  }
  { // Node ID: 307 (NodeConstantRawBits)
  }
  HWRawBits<1> id1711out_result;

  { // Node ID: 1711 (NodeSlice)
    const HWFloat<8,24> &id1711in_a = id2137out_output[getCycle()%4];

    id1711out_result = (slice<4,1>(id1711in_a));
  }
  { // Node ID: 308 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id308in_sel = id1416out_result[getCycle()%2];
    const HWRawBits<1> &id308in_option0 = id307out_value;
    const HWRawBits<1> &id308in_option1 = id1711out_result;

    HWRawBits<1> id308x_1;

    switch((id308in_sel.getValueAsLong())) {
      case 0l:
        id308x_1 = id308in_option0;
        break;
      case 1l:
        id308x_1 = id308in_option1;
        break;
      default:
        id308x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id308out_result[(getCycle()+1)%2] = (id308x_1);
  }
  { // Node ID: 1914 (NodeConstantRawBits)
  }
  { // Node ID: 1418 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1418in_a = id1914out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1418in_b = id279out_result[getCycle()%2];

    id1418out_result[(getCycle()+1)%2] = (lt_fixed(id1418in_a,id1418in_b));
  }
  { // Node ID: 301 (NodeConstantRawBits)
  }
  HWRawBits<1> id1712out_result;

  { // Node ID: 1712 (NodeSlice)
    const HWFloat<8,24> &id1712in_a = id2137out_output[getCycle()%4];

    id1712out_result = (slice<3,1>(id1712in_a));
  }
  { // Node ID: 302 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id302in_sel = id1418out_result[getCycle()%2];
    const HWRawBits<1> &id302in_option0 = id301out_value;
    const HWRawBits<1> &id302in_option1 = id1712out_result;

    HWRawBits<1> id302x_1;

    switch((id302in_sel.getValueAsLong())) {
      case 0l:
        id302x_1 = id302in_option0;
        break;
      case 1l:
        id302x_1 = id302in_option1;
        break;
      default:
        id302x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id302out_result[(getCycle()+1)%2] = (id302x_1);
  }
  { // Node ID: 1913 (NodeConstantRawBits)
  }
  { // Node ID: 1420 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1420in_a = id1913out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1420in_b = id279out_result[getCycle()%2];

    id1420out_result[(getCycle()+1)%2] = (lt_fixed(id1420in_a,id1420in_b));
  }
  { // Node ID: 295 (NodeConstantRawBits)
  }
  HWRawBits<1> id1713out_result;

  { // Node ID: 1713 (NodeSlice)
    const HWFloat<8,24> &id1713in_a = id2137out_output[getCycle()%4];

    id1713out_result = (slice<2,1>(id1713in_a));
  }
  { // Node ID: 296 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id296in_sel = id1420out_result[getCycle()%2];
    const HWRawBits<1> &id296in_option0 = id295out_value;
    const HWRawBits<1> &id296in_option1 = id1713out_result;

    HWRawBits<1> id296x_1;

    switch((id296in_sel.getValueAsLong())) {
      case 0l:
        id296x_1 = id296in_option0;
        break;
      case 1l:
        id296x_1 = id296in_option1;
        break;
      default:
        id296x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id296out_result[(getCycle()+1)%2] = (id296x_1);
  }
  { // Node ID: 1912 (NodeConstantRawBits)
  }
  { // Node ID: 1422 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1422in_a = id1912out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1422in_b = id279out_result[getCycle()%2];

    id1422out_result[(getCycle()+1)%2] = (lt_fixed(id1422in_a,id1422in_b));
  }
  { // Node ID: 289 (NodeConstantRawBits)
  }
  HWRawBits<1> id1714out_result;

  { // Node ID: 1714 (NodeSlice)
    const HWFloat<8,24> &id1714in_a = id2137out_output[getCycle()%4];

    id1714out_result = (slice<1,1>(id1714in_a));
  }
  { // Node ID: 290 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id290in_sel = id1422out_result[getCycle()%2];
    const HWRawBits<1> &id290in_option0 = id289out_value;
    const HWRawBits<1> &id290in_option1 = id1714out_result;

    HWRawBits<1> id290x_1;

    switch((id290in_sel.getValueAsLong())) {
      case 0l:
        id290x_1 = id290in_option0;
        break;
      case 1l:
        id290x_1 = id290in_option1;
        break;
      default:
        id290x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id290out_result[(getCycle()+1)%2] = (id290x_1);
  }
  { // Node ID: 1911 (NodeConstantRawBits)
  }
  { // Node ID: 1424 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1424in_a = id1911out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1424in_b = id279out_result[getCycle()%2];

    id1424out_result[(getCycle()+1)%2] = (lt_fixed(id1424in_a,id1424in_b));
  }
  { // Node ID: 283 (NodeConstantRawBits)
  }
  HWRawBits<1> id1715out_result;

  { // Node ID: 1715 (NodeSlice)
    const HWFloat<8,24> &id1715in_a = id2137out_output[getCycle()%4];

    id1715out_result = (slice<0,1>(id1715in_a));
  }
  { // Node ID: 284 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id284in_sel = id1424out_result[getCycle()%2];
    const HWRawBits<1> &id284in_option0 = id283out_value;
    const HWRawBits<1> &id284in_option1 = id1715out_result;

    HWRawBits<1> id284x_1;

    switch((id284in_sel.getValueAsLong())) {
      case 0l:
        id284x_1 = id284in_option0;
        break;
      case 1l:
        id284x_1 = id284in_option1;
        break;
      default:
        id284x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id284out_result[(getCycle()+1)%2] = (id284x_1);
  }
  { // Node ID: 277 (NodeConstantRawBits)
  }
  HWRawBits<24> id1447out_result;

  { // Node ID: 1447 (NodeCat)
    const HWRawBits<1> &id1447in_in0 = id416out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in1 = id410out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in2 = id404out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in3 = id398out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in4 = id392out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in5 = id386out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in6 = id380out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in7 = id374out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in8 = id368out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in9 = id362out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in10 = id356out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in11 = id350out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in12 = id344out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in13 = id338out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in14 = id332out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in15 = id326out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in16 = id320out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in17 = id314out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in18 = id308out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in19 = id302out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in20 = id296out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in21 = id290out_result[getCycle()%2];
    const HWRawBits<1> &id1447in_in22 = id284out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1447in_in23 = id277out_value;

    id1447out_result = (cat((cat((cat((cat((cat(id1447in_in0,id1447in_in1)),id1447in_in2)),(cat((cat(id1447in_in3,id1447in_in4)),id1447in_in5)))),(cat((cat((cat(id1447in_in6,id1447in_in7)),id1447in_in8)),(cat((cat(id1447in_in9,id1447in_in10)),id1447in_in11)))))),(cat((cat((cat((cat(id1447in_in12,id1447in_in13)),id1447in_in14)),(cat((cat(id1447in_in15,id1447in_in16)),id1447in_in17)))),(cat((cat((cat(id1447in_in18,id1447in_in19)),id1447in_in20)),(cat((cat(id1447in_in21,id1447in_in22)),id1447in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id418out_o;

  { // Node ID: 418 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id418in_i = id259out_result[getCycle()%2];

    id418out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id418in_i));
  }
  { // Node ID: 2162 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2162in_input = id418out_o;

    id2162out_output[(getCycle()+3)%4] = id2162in_input;
  }
  { // Node ID: 419 (NodeShift)
    const HWRawBits<24> &id419in_datain = id1447out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id419in_shift = id2162out_output[getCycle()%4];

    id419out_dataout[(getCycle()+4)%5] = (shift_left_bits(id419in_datain,(id419in_shift.getValueAsLong())));
  }
  { // Node ID: 260 (NodeConstantRawBits)
  }
  HWRawBits<23> id261out_result;

  { // Node ID: 261 (NodeSlice)
    const HWFloat<8,24> &id261in_a = id2137out_output[getCycle()%4];

    id261out_result = (slice<0,23>(id261in_a));
  }
  HWRawBits<24> id262out_result;

  { // Node ID: 262 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id262in_in0 = id260out_value;
    const HWRawBits<23> &id262in_in1 = id261out_result;

    id262out_result = (cat(id262in_in0,id262in_in1));
  }
  { // Node ID: 272 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id272in_a = id259out_result[getCycle()%2];

    id272out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id272in_a));
  }
  { // Node ID: 1910 (NodeConstantRawBits)
  }
  { // Node ID: 274 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id274in_a = id272out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id274in_b = id1910out_value;

    id274out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id274in_a,id274in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id275out_o;

  { // Node ID: 275 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id275in_i = id274out_result[getCycle()%2];

    id275out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id275in_i));
  }
  { // Node ID: 276 (NodeShift)
    const HWRawBits<24> &id276in_datain = id262out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id276in_shift = id275out_o;

    id276out_dataout[(getCycle()+4)%5] = (shift_right_bits(id276in_datain,(id276in_shift.getValueAsLong())));
  }
  { // Node ID: 2165 (NodeFIFO)
    const HWRawBits<24> &id2165in_input = id276out_dataout[getCycle()%5];

    id2165out_output[(getCycle()+1)%2] = id2165in_input;
  }
  { // Node ID: 1909 (NodeConstantRawBits)
  }
  { // Node ID: 422 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id422in_sel = id2164out_output[getCycle()%6];
    const HWRawBits<24> &id422in_option0 = id419out_dataout[getCycle()%5];
    const HWRawBits<24> &id422in_option1 = id2165out_output[getCycle()%2];
    const HWRawBits<24> &id422in_option2 = id1909out_value;
    const HWRawBits<24> &id422in_option3 = id1909out_value;

    HWRawBits<24> id422x_1;

    switch((id422in_sel.getValueAsLong())) {
      case 0l:
        id422x_1 = id422in_option0;
        break;
      case 1l:
        id422x_1 = id422in_option1;
        break;
      case 2l:
        id422x_1 = id422in_option2;
        break;
      case 3l:
        id422x_1 = id422in_option3;
        break;
      default:
        id422x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id422out_result[(getCycle()+1)%2] = (id422x_1);
  }
  HWRawBits<24> id423out_result;

  { // Node ID: 423 (NodeNot)
    const HWRawBits<24> &id423in_a = id422out_result[getCycle()%2];

    id423out_result = (not_bits(id423in_a));
  }
  { // Node ID: 424 (NodeMux)
    const HWRawBits<1> &id424in_sel = id2166out_output[getCycle()%7];
    const HWRawBits<24> &id424in_option0 = id422out_result[getCycle()%2];
    const HWRawBits<24> &id424in_option1 = id423out_result;

    HWRawBits<24> id424x_1;

    switch((id424in_sel.getValueAsLong())) {
      case 0l:
        id424x_1 = id424in_option0;
        break;
      case 1l:
        id424x_1 = id424in_option1;
        break;
      default:
        id424x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id424out_result[(getCycle()+1)%2] = (id424x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id425out_output;

  { // Node ID: 425 (NodeReinterpret)
    const HWRawBits<24> &id425in_input = id424out_result[getCycle()%2];

    id425out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id425in_input));
  }
  { // Node ID: 426 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id426in_i = id425out_output;

    id426out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id426in_i));
  }
  { // Node ID: 1982 (NodePO2FPMult)
    const HWFloat<8,24> &id1982in_floatIn = id219out_result[getCycle()%2];

    id1982out_floatOut[(getCycle()+1)%2] = (mul_float(id1982in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2167 (NodeFIFO)
    const HWFloat<8,24> &id2167in_input = id1982out_floatOut[getCycle()%2];

    id2167out_output[(getCycle()+3)%4] = id2167in_input;
  }
  HWRawBits<1> id464out_result;

  { // Node ID: 464 (NodeSlice)
    const HWFloat<8,24> &id464in_a = id2167out_output[getCycle()%4];

    id464out_result = (slice<31,1>(id464in_a));
  }
  { // Node ID: 2196 (NodeFIFO)
    const HWRawBits<1> &id2196in_input = id464out_result;

    id2196out_output[(getCycle()+6)%7] = id2196in_input;
  }
  HWRawBits<8> id457out_result;

  { // Node ID: 457 (NodeSlice)
    const HWFloat<8,24> &id457in_a = id1982out_floatOut[getCycle()%2];

    id457out_result = (slice<23,8>(id457in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id458out_output;

  { // Node ID: 458 (NodeReinterpret)
    const HWRawBits<8> &id458in_input = id457out_result;

    id458out_output = (cast_bits2fixed<8,0,UNSIGNED>(id458in_input));
  }
  { // Node ID: 1907 (NodeConstantRawBits)
  }
  { // Node ID: 460 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id460in_a = id458out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id460in_b = id1907out_value;

    id460out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id460in_a,id460in_b));
  }
  { // Node ID: 1906 (NodeConstantRawBits)
  }
  { // Node ID: 1448 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1448in_a = id460out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1448in_b = id1906out_value;

    id1448out_result[(getCycle()+1)%2] = (gte_fixed(id1448in_a,id1448in_b));
  }
  { // Node ID: 1905 (NodeConstantRawBits)
  }
  { // Node ID: 1449 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1449in_a = id460out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1449in_b = id1905out_value;

    id1449out_result[(getCycle()+1)%2] = (lte_fixed(id1449in_a,id1449in_b));
  }
  { // Node ID: 469 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id469in_a = id1448out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id469in_b = id1449out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id469x_1;

    (id469x_1) = (or_fixed(id469in_a,id469in_b));
    id469out_result[(getCycle()+1)%2] = (id469x_1);
  }
  { // Node ID: 1904 (NodeConstantRawBits)
  }
  { // Node ID: 1450 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1450in_a = id460out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1450in_b = id1904out_value;

    id1450out_result[(getCycle()+1)%2] = (lte_fixed(id1450in_a,id1450in_b));
  }
  { // Node ID: 2168 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2168in_input = id1450out_result[getCycle()%2];

    id2168out_output[(getCycle()+1)%2] = id2168in_input;
  }
  HWRawBits<2> id621out_result;

  { // Node ID: 621 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id621in_in0 = id469out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id621in_in1 = id2168out_output[getCycle()%2];

    id621out_result = (cat(id621in_in0,id621in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id622out_output;

  { // Node ID: 622 (NodeReinterpret)
    const HWRawBits<2> &id622in_input = id621out_result;

    id622out_output = (cast_bits2fixed<2,0,UNSIGNED>(id622in_input));
  }
  { // Node ID: 2194 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2194in_input = id622out_output;

    id2194out_output[(getCycle()+5)%6] = id2194in_input;
  }
  { // Node ID: 1903 (NodeConstantRawBits)
  }
  { // Node ID: 1902 (NodeConstantRawBits)
  }
  { // Node ID: 480 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id480in_a = id1902out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id480in_b = id460out_result[getCycle()%2];

    id480out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id480in_a,id480in_b));
  }
  { // Node ID: 1451 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1451in_a = id1903out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1451in_b = id480out_result[getCycle()%2];

    id1451out_result[(getCycle()+1)%2] = (lt_fixed(id1451in_a,id1451in_b));
  }
  { // Node ID: 616 (NodeConstantRawBits)
  }
  HWRawBits<1> id1716out_result;

  { // Node ID: 1716 (NodeSlice)
    const HWFloat<8,24> &id1716in_a = id2167out_output[getCycle()%4];

    id1716out_result = (slice<22,1>(id1716in_a));
  }
  { // Node ID: 617 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id617in_sel = id1451out_result[getCycle()%2];
    const HWRawBits<1> &id617in_option0 = id616out_value;
    const HWRawBits<1> &id617in_option1 = id1716out_result;

    HWRawBits<1> id617x_1;

    switch((id617in_sel.getValueAsLong())) {
      case 0l:
        id617x_1 = id617in_option0;
        break;
      case 1l:
        id617x_1 = id617in_option1;
        break;
      default:
        id617x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id617out_result[(getCycle()+1)%2] = (id617x_1);
  }
  { // Node ID: 1901 (NodeConstantRawBits)
  }
  { // Node ID: 1453 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1453in_a = id1901out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1453in_b = id480out_result[getCycle()%2];

    id1453out_result[(getCycle()+1)%2] = (lt_fixed(id1453in_a,id1453in_b));
  }
  { // Node ID: 610 (NodeConstantRawBits)
  }
  HWRawBits<1> id1717out_result;

  { // Node ID: 1717 (NodeSlice)
    const HWFloat<8,24> &id1717in_a = id2167out_output[getCycle()%4];

    id1717out_result = (slice<21,1>(id1717in_a));
  }
  { // Node ID: 611 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id611in_sel = id1453out_result[getCycle()%2];
    const HWRawBits<1> &id611in_option0 = id610out_value;
    const HWRawBits<1> &id611in_option1 = id1717out_result;

    HWRawBits<1> id611x_1;

    switch((id611in_sel.getValueAsLong())) {
      case 0l:
        id611x_1 = id611in_option0;
        break;
      case 1l:
        id611x_1 = id611in_option1;
        break;
      default:
        id611x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id611out_result[(getCycle()+1)%2] = (id611x_1);
  }
  { // Node ID: 1900 (NodeConstantRawBits)
  }
  { // Node ID: 1455 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1455in_a = id1900out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1455in_b = id480out_result[getCycle()%2];

    id1455out_result[(getCycle()+1)%2] = (lt_fixed(id1455in_a,id1455in_b));
  }
  { // Node ID: 604 (NodeConstantRawBits)
  }
  HWRawBits<1> id1718out_result;

  { // Node ID: 1718 (NodeSlice)
    const HWFloat<8,24> &id1718in_a = id2167out_output[getCycle()%4];

    id1718out_result = (slice<20,1>(id1718in_a));
  }
  { // Node ID: 605 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id605in_sel = id1455out_result[getCycle()%2];
    const HWRawBits<1> &id605in_option0 = id604out_value;
    const HWRawBits<1> &id605in_option1 = id1718out_result;

    HWRawBits<1> id605x_1;

    switch((id605in_sel.getValueAsLong())) {
      case 0l:
        id605x_1 = id605in_option0;
        break;
      case 1l:
        id605x_1 = id605in_option1;
        break;
      default:
        id605x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id605out_result[(getCycle()+1)%2] = (id605x_1);
  }
  { // Node ID: 1899 (NodeConstantRawBits)
  }
  { // Node ID: 1457 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1457in_a = id1899out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1457in_b = id480out_result[getCycle()%2];

    id1457out_result[(getCycle()+1)%2] = (lt_fixed(id1457in_a,id1457in_b));
  }
  { // Node ID: 598 (NodeConstantRawBits)
  }
  HWRawBits<1> id1719out_result;

  { // Node ID: 1719 (NodeSlice)
    const HWFloat<8,24> &id1719in_a = id2167out_output[getCycle()%4];

    id1719out_result = (slice<19,1>(id1719in_a));
  }
  { // Node ID: 599 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id599in_sel = id1457out_result[getCycle()%2];
    const HWRawBits<1> &id599in_option0 = id598out_value;
    const HWRawBits<1> &id599in_option1 = id1719out_result;

    HWRawBits<1> id599x_1;

    switch((id599in_sel.getValueAsLong())) {
      case 0l:
        id599x_1 = id599in_option0;
        break;
      case 1l:
        id599x_1 = id599in_option1;
        break;
      default:
        id599x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id599out_result[(getCycle()+1)%2] = (id599x_1);
  }
  { // Node ID: 1898 (NodeConstantRawBits)
  }
  { // Node ID: 1459 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1459in_a = id1898out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1459in_b = id480out_result[getCycle()%2];

    id1459out_result[(getCycle()+1)%2] = (lt_fixed(id1459in_a,id1459in_b));
  }
  { // Node ID: 592 (NodeConstantRawBits)
  }
  HWRawBits<1> id1720out_result;

  { // Node ID: 1720 (NodeSlice)
    const HWFloat<8,24> &id1720in_a = id2167out_output[getCycle()%4];

    id1720out_result = (slice<18,1>(id1720in_a));
  }
  { // Node ID: 593 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id593in_sel = id1459out_result[getCycle()%2];
    const HWRawBits<1> &id593in_option0 = id592out_value;
    const HWRawBits<1> &id593in_option1 = id1720out_result;

    HWRawBits<1> id593x_1;

    switch((id593in_sel.getValueAsLong())) {
      case 0l:
        id593x_1 = id593in_option0;
        break;
      case 1l:
        id593x_1 = id593in_option1;
        break;
      default:
        id593x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id593out_result[(getCycle()+1)%2] = (id593x_1);
  }
  { // Node ID: 1897 (NodeConstantRawBits)
  }
  { // Node ID: 1461 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1461in_a = id1897out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1461in_b = id480out_result[getCycle()%2];

    id1461out_result[(getCycle()+1)%2] = (lt_fixed(id1461in_a,id1461in_b));
  }
  { // Node ID: 586 (NodeConstantRawBits)
  }
  HWRawBits<1> id1721out_result;

  { // Node ID: 1721 (NodeSlice)
    const HWFloat<8,24> &id1721in_a = id2167out_output[getCycle()%4];

    id1721out_result = (slice<17,1>(id1721in_a));
  }
  { // Node ID: 587 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id587in_sel = id1461out_result[getCycle()%2];
    const HWRawBits<1> &id587in_option0 = id586out_value;
    const HWRawBits<1> &id587in_option1 = id1721out_result;

    HWRawBits<1> id587x_1;

    switch((id587in_sel.getValueAsLong())) {
      case 0l:
        id587x_1 = id587in_option0;
        break;
      case 1l:
        id587x_1 = id587in_option1;
        break;
      default:
        id587x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id587out_result[(getCycle()+1)%2] = (id587x_1);
  }
  { // Node ID: 1896 (NodeConstantRawBits)
  }
  { // Node ID: 1463 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1463in_a = id1896out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1463in_b = id480out_result[getCycle()%2];

    id1463out_result[(getCycle()+1)%2] = (lt_fixed(id1463in_a,id1463in_b));
  }
  { // Node ID: 580 (NodeConstantRawBits)
  }
  HWRawBits<1> id1722out_result;

  { // Node ID: 1722 (NodeSlice)
    const HWFloat<8,24> &id1722in_a = id2167out_output[getCycle()%4];

    id1722out_result = (slice<16,1>(id1722in_a));
  }
  { // Node ID: 581 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id581in_sel = id1463out_result[getCycle()%2];
    const HWRawBits<1> &id581in_option0 = id580out_value;
    const HWRawBits<1> &id581in_option1 = id1722out_result;

    HWRawBits<1> id581x_1;

    switch((id581in_sel.getValueAsLong())) {
      case 0l:
        id581x_1 = id581in_option0;
        break;
      case 1l:
        id581x_1 = id581in_option1;
        break;
      default:
        id581x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id581out_result[(getCycle()+1)%2] = (id581x_1);
  }
  { // Node ID: 1895 (NodeConstantRawBits)
  }
  { // Node ID: 1465 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1465in_a = id1895out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1465in_b = id480out_result[getCycle()%2];

    id1465out_result[(getCycle()+1)%2] = (lt_fixed(id1465in_a,id1465in_b));
  }
  { // Node ID: 574 (NodeConstantRawBits)
  }
  HWRawBits<1> id1723out_result;

  { // Node ID: 1723 (NodeSlice)
    const HWFloat<8,24> &id1723in_a = id2167out_output[getCycle()%4];

    id1723out_result = (slice<15,1>(id1723in_a));
  }
  { // Node ID: 575 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id575in_sel = id1465out_result[getCycle()%2];
    const HWRawBits<1> &id575in_option0 = id574out_value;
    const HWRawBits<1> &id575in_option1 = id1723out_result;

    HWRawBits<1> id575x_1;

    switch((id575in_sel.getValueAsLong())) {
      case 0l:
        id575x_1 = id575in_option0;
        break;
      case 1l:
        id575x_1 = id575in_option1;
        break;
      default:
        id575x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id575out_result[(getCycle()+1)%2] = (id575x_1);
  }
  { // Node ID: 1894 (NodeConstantRawBits)
  }
  { // Node ID: 1467 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1467in_a = id1894out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1467in_b = id480out_result[getCycle()%2];

    id1467out_result[(getCycle()+1)%2] = (lt_fixed(id1467in_a,id1467in_b));
  }
  { // Node ID: 568 (NodeConstantRawBits)
  }
  HWRawBits<1> id1724out_result;

  { // Node ID: 1724 (NodeSlice)
    const HWFloat<8,24> &id1724in_a = id2167out_output[getCycle()%4];

    id1724out_result = (slice<14,1>(id1724in_a));
  }
  { // Node ID: 569 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id569in_sel = id1467out_result[getCycle()%2];
    const HWRawBits<1> &id569in_option0 = id568out_value;
    const HWRawBits<1> &id569in_option1 = id1724out_result;

    HWRawBits<1> id569x_1;

    switch((id569in_sel.getValueAsLong())) {
      case 0l:
        id569x_1 = id569in_option0;
        break;
      case 1l:
        id569x_1 = id569in_option1;
        break;
      default:
        id569x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id569out_result[(getCycle()+1)%2] = (id569x_1);
  }
  { // Node ID: 1893 (NodeConstantRawBits)
  }
  { // Node ID: 1469 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1469in_a = id1893out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1469in_b = id480out_result[getCycle()%2];

    id1469out_result[(getCycle()+1)%2] = (lt_fixed(id1469in_a,id1469in_b));
  }
  { // Node ID: 562 (NodeConstantRawBits)
  }
  HWRawBits<1> id1725out_result;

  { // Node ID: 1725 (NodeSlice)
    const HWFloat<8,24> &id1725in_a = id2167out_output[getCycle()%4];

    id1725out_result = (slice<13,1>(id1725in_a));
  }
  { // Node ID: 563 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id563in_sel = id1469out_result[getCycle()%2];
    const HWRawBits<1> &id563in_option0 = id562out_value;
    const HWRawBits<1> &id563in_option1 = id1725out_result;

    HWRawBits<1> id563x_1;

    switch((id563in_sel.getValueAsLong())) {
      case 0l:
        id563x_1 = id563in_option0;
        break;
      case 1l:
        id563x_1 = id563in_option1;
        break;
      default:
        id563x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id563out_result[(getCycle()+1)%2] = (id563x_1);
  }
  { // Node ID: 1892 (NodeConstantRawBits)
  }
  { // Node ID: 1471 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1471in_a = id1892out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1471in_b = id480out_result[getCycle()%2];

    id1471out_result[(getCycle()+1)%2] = (lt_fixed(id1471in_a,id1471in_b));
  }
  { // Node ID: 556 (NodeConstantRawBits)
  }
  HWRawBits<1> id1726out_result;

  { // Node ID: 1726 (NodeSlice)
    const HWFloat<8,24> &id1726in_a = id2167out_output[getCycle()%4];

    id1726out_result = (slice<12,1>(id1726in_a));
  }
  { // Node ID: 557 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id557in_sel = id1471out_result[getCycle()%2];
    const HWRawBits<1> &id557in_option0 = id556out_value;
    const HWRawBits<1> &id557in_option1 = id1726out_result;

    HWRawBits<1> id557x_1;

    switch((id557in_sel.getValueAsLong())) {
      case 0l:
        id557x_1 = id557in_option0;
        break;
      case 1l:
        id557x_1 = id557in_option1;
        break;
      default:
        id557x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id557out_result[(getCycle()+1)%2] = (id557x_1);
  }
  { // Node ID: 1891 (NodeConstantRawBits)
  }
  { // Node ID: 1473 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1473in_a = id1891out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1473in_b = id480out_result[getCycle()%2];

    id1473out_result[(getCycle()+1)%2] = (lt_fixed(id1473in_a,id1473in_b));
  }
  { // Node ID: 550 (NodeConstantRawBits)
  }
  HWRawBits<1> id1727out_result;

  { // Node ID: 1727 (NodeSlice)
    const HWFloat<8,24> &id1727in_a = id2167out_output[getCycle()%4];

    id1727out_result = (slice<11,1>(id1727in_a));
  }
  { // Node ID: 551 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id551in_sel = id1473out_result[getCycle()%2];
    const HWRawBits<1> &id551in_option0 = id550out_value;
    const HWRawBits<1> &id551in_option1 = id1727out_result;

    HWRawBits<1> id551x_1;

    switch((id551in_sel.getValueAsLong())) {
      case 0l:
        id551x_1 = id551in_option0;
        break;
      case 1l:
        id551x_1 = id551in_option1;
        break;
      default:
        id551x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id551out_result[(getCycle()+1)%2] = (id551x_1);
  }
  { // Node ID: 1890 (NodeConstantRawBits)
  }
  { // Node ID: 1475 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1475in_a = id1890out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1475in_b = id480out_result[getCycle()%2];

    id1475out_result[(getCycle()+1)%2] = (lt_fixed(id1475in_a,id1475in_b));
  }
  { // Node ID: 544 (NodeConstantRawBits)
  }
  HWRawBits<1> id1728out_result;

  { // Node ID: 1728 (NodeSlice)
    const HWFloat<8,24> &id1728in_a = id2167out_output[getCycle()%4];

    id1728out_result = (slice<10,1>(id1728in_a));
  }
  { // Node ID: 545 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id545in_sel = id1475out_result[getCycle()%2];
    const HWRawBits<1> &id545in_option0 = id544out_value;
    const HWRawBits<1> &id545in_option1 = id1728out_result;

    HWRawBits<1> id545x_1;

    switch((id545in_sel.getValueAsLong())) {
      case 0l:
        id545x_1 = id545in_option0;
        break;
      case 1l:
        id545x_1 = id545in_option1;
        break;
      default:
        id545x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id545out_result[(getCycle()+1)%2] = (id545x_1);
  }
  { // Node ID: 1889 (NodeConstantRawBits)
  }
  { // Node ID: 1477 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1477in_a = id1889out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1477in_b = id480out_result[getCycle()%2];

    id1477out_result[(getCycle()+1)%2] = (lt_fixed(id1477in_a,id1477in_b));
  }
  { // Node ID: 538 (NodeConstantRawBits)
  }
  HWRawBits<1> id1729out_result;

  { // Node ID: 1729 (NodeSlice)
    const HWFloat<8,24> &id1729in_a = id2167out_output[getCycle()%4];

    id1729out_result = (slice<9,1>(id1729in_a));
  }
  { // Node ID: 539 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id539in_sel = id1477out_result[getCycle()%2];
    const HWRawBits<1> &id539in_option0 = id538out_value;
    const HWRawBits<1> &id539in_option1 = id1729out_result;

    HWRawBits<1> id539x_1;

    switch((id539in_sel.getValueAsLong())) {
      case 0l:
        id539x_1 = id539in_option0;
        break;
      case 1l:
        id539x_1 = id539in_option1;
        break;
      default:
        id539x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id539out_result[(getCycle()+1)%2] = (id539x_1);
  }
  { // Node ID: 1888 (NodeConstantRawBits)
  }
  { // Node ID: 1479 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1479in_a = id1888out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1479in_b = id480out_result[getCycle()%2];

    id1479out_result[(getCycle()+1)%2] = (lt_fixed(id1479in_a,id1479in_b));
  }
  { // Node ID: 532 (NodeConstantRawBits)
  }
  HWRawBits<1> id1730out_result;

  { // Node ID: 1730 (NodeSlice)
    const HWFloat<8,24> &id1730in_a = id2167out_output[getCycle()%4];

    id1730out_result = (slice<8,1>(id1730in_a));
  }
  { // Node ID: 533 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id533in_sel = id1479out_result[getCycle()%2];
    const HWRawBits<1> &id533in_option0 = id532out_value;
    const HWRawBits<1> &id533in_option1 = id1730out_result;

    HWRawBits<1> id533x_1;

    switch((id533in_sel.getValueAsLong())) {
      case 0l:
        id533x_1 = id533in_option0;
        break;
      case 1l:
        id533x_1 = id533in_option1;
        break;
      default:
        id533x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id533out_result[(getCycle()+1)%2] = (id533x_1);
  }
  { // Node ID: 1887 (NodeConstantRawBits)
  }
  { // Node ID: 1481 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1481in_a = id1887out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1481in_b = id480out_result[getCycle()%2];

    id1481out_result[(getCycle()+1)%2] = (lt_fixed(id1481in_a,id1481in_b));
  }
  { // Node ID: 526 (NodeConstantRawBits)
  }
  HWRawBits<1> id1731out_result;

  { // Node ID: 1731 (NodeSlice)
    const HWFloat<8,24> &id1731in_a = id2167out_output[getCycle()%4];

    id1731out_result = (slice<7,1>(id1731in_a));
  }
  { // Node ID: 527 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id527in_sel = id1481out_result[getCycle()%2];
    const HWRawBits<1> &id527in_option0 = id526out_value;
    const HWRawBits<1> &id527in_option1 = id1731out_result;

    HWRawBits<1> id527x_1;

    switch((id527in_sel.getValueAsLong())) {
      case 0l:
        id527x_1 = id527in_option0;
        break;
      case 1l:
        id527x_1 = id527in_option1;
        break;
      default:
        id527x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id527out_result[(getCycle()+1)%2] = (id527x_1);
  }
  { // Node ID: 1886 (NodeConstantRawBits)
  }
  { // Node ID: 1483 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1483in_a = id1886out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1483in_b = id480out_result[getCycle()%2];

    id1483out_result[(getCycle()+1)%2] = (lt_fixed(id1483in_a,id1483in_b));
  }
  { // Node ID: 520 (NodeConstantRawBits)
  }
  HWRawBits<1> id1732out_result;

  { // Node ID: 1732 (NodeSlice)
    const HWFloat<8,24> &id1732in_a = id2167out_output[getCycle()%4];

    id1732out_result = (slice<6,1>(id1732in_a));
  }
  { // Node ID: 521 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id521in_sel = id1483out_result[getCycle()%2];
    const HWRawBits<1> &id521in_option0 = id520out_value;
    const HWRawBits<1> &id521in_option1 = id1732out_result;

    HWRawBits<1> id521x_1;

    switch((id521in_sel.getValueAsLong())) {
      case 0l:
        id521x_1 = id521in_option0;
        break;
      case 1l:
        id521x_1 = id521in_option1;
        break;
      default:
        id521x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id521out_result[(getCycle()+1)%2] = (id521x_1);
  }
  { // Node ID: 1885 (NodeConstantRawBits)
  }
  { // Node ID: 1485 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1485in_a = id1885out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1485in_b = id480out_result[getCycle()%2];

    id1485out_result[(getCycle()+1)%2] = (lt_fixed(id1485in_a,id1485in_b));
  }
  { // Node ID: 514 (NodeConstantRawBits)
  }
  HWRawBits<1> id1733out_result;

  { // Node ID: 1733 (NodeSlice)
    const HWFloat<8,24> &id1733in_a = id2167out_output[getCycle()%4];

    id1733out_result = (slice<5,1>(id1733in_a));
  }
  { // Node ID: 515 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id515in_sel = id1485out_result[getCycle()%2];
    const HWRawBits<1> &id515in_option0 = id514out_value;
    const HWRawBits<1> &id515in_option1 = id1733out_result;

    HWRawBits<1> id515x_1;

    switch((id515in_sel.getValueAsLong())) {
      case 0l:
        id515x_1 = id515in_option0;
        break;
      case 1l:
        id515x_1 = id515in_option1;
        break;
      default:
        id515x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id515out_result[(getCycle()+1)%2] = (id515x_1);
  }
  { // Node ID: 1884 (NodeConstantRawBits)
  }
  { // Node ID: 1487 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1487in_a = id1884out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1487in_b = id480out_result[getCycle()%2];

    id1487out_result[(getCycle()+1)%2] = (lt_fixed(id1487in_a,id1487in_b));
  }
  { // Node ID: 508 (NodeConstantRawBits)
  }
  HWRawBits<1> id1734out_result;

  { // Node ID: 1734 (NodeSlice)
    const HWFloat<8,24> &id1734in_a = id2167out_output[getCycle()%4];

    id1734out_result = (slice<4,1>(id1734in_a));
  }
  { // Node ID: 509 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id509in_sel = id1487out_result[getCycle()%2];
    const HWRawBits<1> &id509in_option0 = id508out_value;
    const HWRawBits<1> &id509in_option1 = id1734out_result;

    HWRawBits<1> id509x_1;

    switch((id509in_sel.getValueAsLong())) {
      case 0l:
        id509x_1 = id509in_option0;
        break;
      case 1l:
        id509x_1 = id509in_option1;
        break;
      default:
        id509x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id509out_result[(getCycle()+1)%2] = (id509x_1);
  }
  { // Node ID: 1883 (NodeConstantRawBits)
  }
  { // Node ID: 1489 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1489in_a = id1883out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1489in_b = id480out_result[getCycle()%2];

    id1489out_result[(getCycle()+1)%2] = (lt_fixed(id1489in_a,id1489in_b));
  }
  { // Node ID: 502 (NodeConstantRawBits)
  }
  HWRawBits<1> id1735out_result;

  { // Node ID: 1735 (NodeSlice)
    const HWFloat<8,24> &id1735in_a = id2167out_output[getCycle()%4];

    id1735out_result = (slice<3,1>(id1735in_a));
  }
  { // Node ID: 503 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id503in_sel = id1489out_result[getCycle()%2];
    const HWRawBits<1> &id503in_option0 = id502out_value;
    const HWRawBits<1> &id503in_option1 = id1735out_result;

    HWRawBits<1> id503x_1;

    switch((id503in_sel.getValueAsLong())) {
      case 0l:
        id503x_1 = id503in_option0;
        break;
      case 1l:
        id503x_1 = id503in_option1;
        break;
      default:
        id503x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id503out_result[(getCycle()+1)%2] = (id503x_1);
  }
  { // Node ID: 1882 (NodeConstantRawBits)
  }
  { // Node ID: 1491 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1491in_a = id1882out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1491in_b = id480out_result[getCycle()%2];

    id1491out_result[(getCycle()+1)%2] = (lt_fixed(id1491in_a,id1491in_b));
  }
  { // Node ID: 496 (NodeConstantRawBits)
  }
  HWRawBits<1> id1736out_result;

  { // Node ID: 1736 (NodeSlice)
    const HWFloat<8,24> &id1736in_a = id2167out_output[getCycle()%4];

    id1736out_result = (slice<2,1>(id1736in_a));
  }
  { // Node ID: 497 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id497in_sel = id1491out_result[getCycle()%2];
    const HWRawBits<1> &id497in_option0 = id496out_value;
    const HWRawBits<1> &id497in_option1 = id1736out_result;

    HWRawBits<1> id497x_1;

    switch((id497in_sel.getValueAsLong())) {
      case 0l:
        id497x_1 = id497in_option0;
        break;
      case 1l:
        id497x_1 = id497in_option1;
        break;
      default:
        id497x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id497out_result[(getCycle()+1)%2] = (id497x_1);
  }
  { // Node ID: 1881 (NodeConstantRawBits)
  }
  { // Node ID: 1493 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1493in_a = id1881out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1493in_b = id480out_result[getCycle()%2];

    id1493out_result[(getCycle()+1)%2] = (lt_fixed(id1493in_a,id1493in_b));
  }
  { // Node ID: 490 (NodeConstantRawBits)
  }
  HWRawBits<1> id1737out_result;

  { // Node ID: 1737 (NodeSlice)
    const HWFloat<8,24> &id1737in_a = id2167out_output[getCycle()%4];

    id1737out_result = (slice<1,1>(id1737in_a));
  }
  { // Node ID: 491 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id491in_sel = id1493out_result[getCycle()%2];
    const HWRawBits<1> &id491in_option0 = id490out_value;
    const HWRawBits<1> &id491in_option1 = id1737out_result;

    HWRawBits<1> id491x_1;

    switch((id491in_sel.getValueAsLong())) {
      case 0l:
        id491x_1 = id491in_option0;
        break;
      case 1l:
        id491x_1 = id491in_option1;
        break;
      default:
        id491x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id491out_result[(getCycle()+1)%2] = (id491x_1);
  }
  { // Node ID: 1880 (NodeConstantRawBits)
  }
  { // Node ID: 1495 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1495in_a = id1880out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1495in_b = id480out_result[getCycle()%2];

    id1495out_result[(getCycle()+1)%2] = (lt_fixed(id1495in_a,id1495in_b));
  }
  { // Node ID: 484 (NodeConstantRawBits)
  }
  HWRawBits<1> id1738out_result;

  { // Node ID: 1738 (NodeSlice)
    const HWFloat<8,24> &id1738in_a = id2167out_output[getCycle()%4];

    id1738out_result = (slice<0,1>(id1738in_a));
  }
  { // Node ID: 485 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id485in_sel = id1495out_result[getCycle()%2];
    const HWRawBits<1> &id485in_option0 = id484out_value;
    const HWRawBits<1> &id485in_option1 = id1738out_result;

    HWRawBits<1> id485x_1;

    switch((id485in_sel.getValueAsLong())) {
      case 0l:
        id485x_1 = id485in_option0;
        break;
      case 1l:
        id485x_1 = id485in_option1;
        break;
      default:
        id485x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id485out_result[(getCycle()+1)%2] = (id485x_1);
  }
  { // Node ID: 478 (NodeConstantRawBits)
  }
  HWRawBits<24> id1518out_result;

  { // Node ID: 1518 (NodeCat)
    const HWRawBits<1> &id1518in_in0 = id617out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in1 = id611out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in2 = id605out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in3 = id599out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in4 = id593out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in5 = id587out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in6 = id581out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in7 = id575out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in8 = id569out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in9 = id563out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in10 = id557out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in11 = id551out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in12 = id545out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in13 = id539out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in14 = id533out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in15 = id527out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in16 = id521out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in17 = id515out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in18 = id509out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in19 = id503out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in20 = id497out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in21 = id491out_result[getCycle()%2];
    const HWRawBits<1> &id1518in_in22 = id485out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1518in_in23 = id478out_value;

    id1518out_result = (cat((cat((cat((cat((cat(id1518in_in0,id1518in_in1)),id1518in_in2)),(cat((cat(id1518in_in3,id1518in_in4)),id1518in_in5)))),(cat((cat((cat(id1518in_in6,id1518in_in7)),id1518in_in8)),(cat((cat(id1518in_in9,id1518in_in10)),id1518in_in11)))))),(cat((cat((cat((cat(id1518in_in12,id1518in_in13)),id1518in_in14)),(cat((cat(id1518in_in15,id1518in_in16)),id1518in_in17)))),(cat((cat((cat(id1518in_in18,id1518in_in19)),id1518in_in20)),(cat((cat(id1518in_in21,id1518in_in22)),id1518in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id619out_o;

  { // Node ID: 619 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id619in_i = id460out_result[getCycle()%2];

    id619out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id619in_i));
  }
  { // Node ID: 2192 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2192in_input = id619out_o;

    id2192out_output[(getCycle()+3)%4] = id2192in_input;
  }
  { // Node ID: 620 (NodeShift)
    const HWRawBits<24> &id620in_datain = id1518out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id620in_shift = id2192out_output[getCycle()%4];

    id620out_dataout[(getCycle()+4)%5] = (shift_left_bits(id620in_datain,(id620in_shift.getValueAsLong())));
  }
  { // Node ID: 461 (NodeConstantRawBits)
  }
  HWRawBits<23> id462out_result;

  { // Node ID: 462 (NodeSlice)
    const HWFloat<8,24> &id462in_a = id2167out_output[getCycle()%4];

    id462out_result = (slice<0,23>(id462in_a));
  }
  HWRawBits<24> id463out_result;

  { // Node ID: 463 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id463in_in0 = id461out_value;
    const HWRawBits<23> &id463in_in1 = id462out_result;

    id463out_result = (cat(id463in_in0,id463in_in1));
  }
  { // Node ID: 473 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id473in_a = id460out_result[getCycle()%2];

    id473out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id473in_a));
  }
  { // Node ID: 1879 (NodeConstantRawBits)
  }
  { // Node ID: 475 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id475in_a = id473out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id475in_b = id1879out_value;

    id475out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id475in_a,id475in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id476out_o;

  { // Node ID: 476 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id476in_i = id475out_result[getCycle()%2];

    id476out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id476in_i));
  }
  { // Node ID: 477 (NodeShift)
    const HWRawBits<24> &id477in_datain = id463out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id477in_shift = id476out_o;

    id477out_dataout[(getCycle()+4)%5] = (shift_right_bits(id477in_datain,(id477in_shift.getValueAsLong())));
  }
  { // Node ID: 2195 (NodeFIFO)
    const HWRawBits<24> &id2195in_input = id477out_dataout[getCycle()%5];

    id2195out_output[(getCycle()+1)%2] = id2195in_input;
  }
  { // Node ID: 1878 (NodeConstantRawBits)
  }
  { // Node ID: 623 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id623in_sel = id2194out_output[getCycle()%6];
    const HWRawBits<24> &id623in_option0 = id620out_dataout[getCycle()%5];
    const HWRawBits<24> &id623in_option1 = id2195out_output[getCycle()%2];
    const HWRawBits<24> &id623in_option2 = id1878out_value;
    const HWRawBits<24> &id623in_option3 = id1878out_value;

    HWRawBits<24> id623x_1;

    switch((id623in_sel.getValueAsLong())) {
      case 0l:
        id623x_1 = id623in_option0;
        break;
      case 1l:
        id623x_1 = id623in_option1;
        break;
      case 2l:
        id623x_1 = id623in_option2;
        break;
      case 3l:
        id623x_1 = id623in_option3;
        break;
      default:
        id623x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id623out_result[(getCycle()+1)%2] = (id623x_1);
  }
  HWRawBits<24> id624out_result;

  { // Node ID: 624 (NodeNot)
    const HWRawBits<24> &id624in_a = id623out_result[getCycle()%2];

    id624out_result = (not_bits(id624in_a));
  }
  { // Node ID: 625 (NodeMux)
    const HWRawBits<1> &id625in_sel = id2196out_output[getCycle()%7];
    const HWRawBits<24> &id625in_option0 = id623out_result[getCycle()%2];
    const HWRawBits<24> &id625in_option1 = id624out_result;

    HWRawBits<24> id625x_1;

    switch((id625in_sel.getValueAsLong())) {
      case 0l:
        id625x_1 = id625in_option0;
        break;
      case 1l:
        id625x_1 = id625in_option1;
        break;
      default:
        id625x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id625out_result[(getCycle()+1)%2] = (id625x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id626out_output;

  { // Node ID: 626 (NodeReinterpret)
    const HWRawBits<24> &id626in_input = id625out_result[getCycle()%2];

    id626out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id626in_input));
  }
  { // Node ID: 627 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id627in_i = id626out_output;

    id627out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id627in_i));
  }
  { // Node ID: 628 (NodeMux)
    const HWRawBits<1> &id628in_sel = id2136out_output[getCycle()%30];
    const HWFloat<8,24> &id628in_option0 = id426out_o[getCycle()%8];
    const HWFloat<8,24> &id628in_option1 = id627out_o[getCycle()%8];

    HWFloat<8,24> id628x_1;

    switch((id628in_sel.getValueAsLong())) {
      case 0l:
        id628x_1 = id628in_option0;
        break;
      case 1l:
        id628x_1 = id628in_option1;
        break;
      default:
        id628x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id628out_result[(getCycle()+1)%2] = (id628x_1);
  }
  { // Node ID: 634 (NodeMul)
    const HWFloat<8,24> &id634in_a = id632out_result[getCycle()%2];
    const HWFloat<8,24> &id634in_b = id628out_result[getCycle()%2];

    id634out_result[(getCycle()+8)%9] = (mul_float(id634in_a,id634in_b));
  }
  { // Node ID: 633 (NodeMul)
    const HWFloat<8,24> &id633in_a = id628out_result[getCycle()%2];
    const HWFloat<8,24> &id633in_b = id628out_result[getCycle()%2];

    id633out_result[(getCycle()+8)%9] = (mul_float(id633in_a,id633in_b));
  }
  { // Node ID: 635 (NodeMul)
    const HWFloat<8,24> &id635in_a = id634out_result[getCycle()%9];
    const HWFloat<8,24> &id635in_b = id633out_result[getCycle()%9];

    id635out_result[(getCycle()+8)%9] = (mul_float(id635in_a,id635in_b));
  }
  HWRawBits<32> id1292out_result;

  { // Node ID: 1292 (NodeSlice)
    const HWRawBits<128> &id1292in_a = id1287out_dout[getCycle()%3];

    id1292out_result = (slice<64,32>(id1292in_a));
  }
  HWFloat<8,24> id1293out_output;

  { // Node ID: 1293 (NodeReinterpret)
    const HWRawBits<32> &id1293in_input = id1292out_result;

    id1293out_output = (cast_bits2float<8,24>(id1293in_input));
  }
  HWRawBits<32> id1301out_result;

  { // Node ID: 1301 (NodeSlice)
    const HWRawBits<128> &id1301in_a = id1296out_dout[getCycle()%3];

    id1301out_result = (slice<64,32>(id1301in_a));
  }
  HWFloat<8,24> id1302out_output;

  { // Node ID: 1302 (NodeReinterpret)
    const HWRawBits<32> &id1302in_input = id1301out_result;

    id1302out_output = (cast_bits2float<8,24>(id1302in_input));
  }
  { // Node ID: 631 (NodeMux)
    const HWRawBits<1> &id631in_sel = id2136out_output[getCycle()%30];
    const HWFloat<8,24> &id631in_option0 = id1293out_output;
    const HWFloat<8,24> &id631in_option1 = id1302out_output;

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
  { // Node ID: 2199 (NodeFIFO)
    const HWFloat<8,24> &id2199in_input = id631out_result[getCycle()%2];

    id2199out_output[(getCycle()+8)%9] = id2199in_input;
  }
  { // Node ID: 636 (NodeMul)
    const HWFloat<8,24> &id636in_a = id2199out_output[getCycle()%9];
    const HWFloat<8,24> &id636in_b = id633out_result[getCycle()%9];

    id636out_result[(getCycle()+8)%9] = (mul_float(id636in_a,id636in_b));
  }
  { // Node ID: 637 (NodeAdd)
    const HWFloat<8,24> &id637in_a = id635out_result[getCycle()%9];
    const HWFloat<8,24> &id637in_b = id636out_result[getCycle()%9];

    id637out_result[(getCycle()+11)%12] = (add_float(id637in_a,id637in_b));
  }
  HWRawBits<32> id1290out_result;

  { // Node ID: 1290 (NodeSlice)
    const HWRawBits<128> &id1290in_a = id1287out_dout[getCycle()%3];

    id1290out_result = (slice<32,32>(id1290in_a));
  }
  HWFloat<8,24> id1291out_output;

  { // Node ID: 1291 (NodeReinterpret)
    const HWRawBits<32> &id1291in_input = id1290out_result;

    id1291out_output = (cast_bits2float<8,24>(id1291in_input));
  }
  HWRawBits<32> id1299out_result;

  { // Node ID: 1299 (NodeSlice)
    const HWRawBits<128> &id1299in_a = id1296out_dout[getCycle()%3];

    id1299out_result = (slice<32,32>(id1299in_a));
  }
  HWFloat<8,24> id1300out_output;

  { // Node ID: 1300 (NodeReinterpret)
    const HWRawBits<32> &id1300in_input = id1299out_result;

    id1300out_output = (cast_bits2float<8,24>(id1300in_input));
  }
  { // Node ID: 630 (NodeMux)
    const HWRawBits<1> &id630in_sel = id2136out_output[getCycle()%30];
    const HWFloat<8,24> &id630in_option0 = id1291out_output;
    const HWFloat<8,24> &id630in_option1 = id1300out_output;

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
  { // Node ID: 638 (NodeMul)
    const HWFloat<8,24> &id638in_a = id630out_result[getCycle()%2];
    const HWFloat<8,24> &id638in_b = id628out_result[getCycle()%2];

    id638out_result[(getCycle()+8)%9] = (mul_float(id638in_a,id638in_b));
  }
  { // Node ID: 2201 (NodeFIFO)
    const HWFloat<8,24> &id2201in_input = id638out_result[getCycle()%9];

    id2201out_output[(getCycle()+19)%20] = id2201in_input;
  }
  { // Node ID: 639 (NodeAdd)
    const HWFloat<8,24> &id639in_a = id637out_result[getCycle()%12];
    const HWFloat<8,24> &id639in_b = id2201out_output[getCycle()%20];

    id639out_result[(getCycle()+11)%12] = (add_float(id639in_a,id639in_b));
  }
  HWRawBits<32> id1288out_result;

  { // Node ID: 1288 (NodeSlice)
    const HWRawBits<128> &id1288in_a = id1287out_dout[getCycle()%3];

    id1288out_result = (slice<0,32>(id1288in_a));
  }
  HWFloat<8,24> id1289out_output;

  { // Node ID: 1289 (NodeReinterpret)
    const HWRawBits<32> &id1289in_input = id1288out_result;

    id1289out_output = (cast_bits2float<8,24>(id1289in_input));
  }
  HWRawBits<32> id1297out_result;

  { // Node ID: 1297 (NodeSlice)
    const HWRawBits<128> &id1297in_a = id1296out_dout[getCycle()%3];

    id1297out_result = (slice<0,32>(id1297in_a));
  }
  HWFloat<8,24> id1298out_output;

  { // Node ID: 1298 (NodeReinterpret)
    const HWRawBits<32> &id1298in_input = id1297out_result;

    id1298out_output = (cast_bits2float<8,24>(id1298in_input));
  }
  { // Node ID: 629 (NodeMux)
    const HWRawBits<1> &id629in_sel = id2136out_output[getCycle()%30];
    const HWFloat<8,24> &id629in_option0 = id1289out_output;
    const HWFloat<8,24> &id629in_option1 = id1298out_output;

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
  { // Node ID: 2203 (NodeFIFO)
    const HWFloat<8,24> &id2203in_input = id629out_result[getCycle()%2];

    id2203out_output[(getCycle()+38)%39] = id2203in_input;
  }
  { // Node ID: 640 (NodeAdd)
    const HWFloat<8,24> &id640in_a = id639out_result[getCycle()%12];
    const HWFloat<8,24> &id640in_b = id2203out_output[getCycle()%39];

    id640out_result[(getCycle()+11)%12] = (add_float(id640in_a,id640in_b));
  }
  { // Node ID: 1877 (NodeConstantRawBits)
  }
  { // Node ID: 647 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id647in_sel = id2204out_output[getCycle()%65];
    const HWFloat<8,24> &id647in_option0 = id640out_result[getCycle()%12];
    const HWFloat<8,24> &id647in_option1 = id1877out_value;

    HWFloat<8,24> id647x_1;

    switch((id647in_sel.getValueAsLong())) {
      case 0l:
        id647x_1 = id647in_option0;
        break;
      case 1l:
        id647x_1 = id647in_option1;
        break;
      default:
        id647x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id647out_result[(getCycle()+1)%2] = (id647x_1);
  }
  HWRawBits<1> id2018out_result;

  { // Node ID: 2018 (NodeSlice)
    const HWFloat<8,24> &id2018in_a = id647out_result[getCycle()%2];

    id2018out_result = (slice<31,1>(id2018in_a));
  }
  HWRawBits<2> id177out_result;

  { // Node ID: 177 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id177in_a = id174out_result[getCycle()%2];

    id177out_result = (slice<79,2>(id177in_a));
  }
  { // Node ID: 1957 (NodeConstantRawBits)
  }
  { // Node ID: 1362 (NodeEqInlined)
    const HWRawBits<2> &id1362in_a = id177out_result;
    const HWRawBits<2> &id1362in_b = id1957out_value;

    id1362out_result[(getCycle()+1)%2] = (eq_bits(id1362in_a,id1362in_b));
  }
  { // Node ID: 1956 (NodeConstantRawBits)
  }
  { // Node ID: 1363 (NodeEqInlined)
    const HWRawBits<2> &id1363in_a = id177out_result;
    const HWRawBits<2> &id1363in_b = id1956out_value;

    id1363out_result[(getCycle()+1)%2] = (eq_bits(id1363in_a,id1363in_b));
  }
  { // Node ID: 225 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id225in_a = id1362out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id225in_b = id1363out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id225x_1;

    (id225x_1) = (or_fixed(id225in_a,id225in_b));
    id225out_result[(getCycle()+1)%2] = (id225x_1);
  }
  { // Node ID: 2205 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2205in_input = id225out_result[getCycle()%2];

    id2205out_output[(getCycle()+78)%79] = id2205in_input;
  }
  HWRawBits<1> id2019out_result;

  { // Node ID: 2019 (NodeXor)
    const HWRawBits<1> &id2019in_a = id2018out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2019in_b = id2205out_output[getCycle()%79];

    HWRawBits<1> id2019x_1;

    (id2019x_1) = (xor_bits(id2019in_a,(cast_fixed2bits(id2019in_b))));
    id2019out_result = (id2019x_1);
  }
  HWRawBits<31> id2017out_result;

  { // Node ID: 2017 (NodeSlice)
    const HWFloat<8,24> &id2017in_a = id647out_result[getCycle()%2];

    id2017out_result = (slice<0,31>(id2017in_a));
  }
  HWRawBits<32> id2020out_result;

  { // Node ID: 2020 (NodeCat)
    const HWRawBits<1> &id2020in_in0 = id2019out_result;
    const HWRawBits<31> &id2020in_in1 = id2017out_result;

    id2020out_result = (cat(id2020in_in0,id2020in_in1));
  }
  HWFloat<8,24> id2021out_output;

  { // Node ID: 2021 (NodeReinterpret)
    const HWRawBits<32> &id2021in_input = id2020out_result;

    id2021out_output = (cast_bits2float<8,24>(id2021in_input));
  }
  { // Node ID: 661 (NodeConstantRawBits)
  }
  { // Node ID: 662 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id662in_sel = id2206out_output[getCycle()%80];
    const HWFloat<8,24> &id662in_option0 = id2021out_output;
    const HWFloat<8,24> &id662in_option1 = id661out_value;

    HWFloat<8,24> id662x_1;

    switch((id662in_sel.getValueAsLong())) {
      case 0l:
        id662x_1 = id662in_option0;
        break;
      case 1l:
        id662x_1 = id662in_option1;
        break;
      default:
        id662x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id662out_result[(getCycle()+1)%2] = (id662x_1);
  }
  { // Node ID: 663 (NodeMul)
    const HWFloat<8,24> &id663in_a = id139out_result[getCycle()%29];
    const HWFloat<8,24> &id663in_b = id662out_result[getCycle()%2];

    id663out_result[(getCycle()+8)%9] = (mul_float(id663in_a,id663in_b));
  }
  { // Node ID: 2331 (NodeFIFO)
    const HWFloat<8,24> &id2331in_input = id663out_result[getCycle()%9];

    id2331out_output[(getCycle()+19)%20] = id2331in_input;
  }
  { // Node ID: 2359 (NodeFIFO)
    const HWFloat<8,24> &id2359in_input = id2331out_output[getCycle()%20];

    id2359out_output[(getCycle()+39)%40] = id2359in_input;
  }
  { // Node ID: 1202 (NodeMul)
    const HWFloat<8,24> &id1202in_a = id2207out_output[getCycle()%22];
    const HWFloat<8,24> &id1202in_b = id2369out_output[getCycle()%22];

    id1202out_result[(getCycle()+8)%9] = (mul_float(id1202in_a,id1202in_b));
  }
  { // Node ID: 1203 (NodeMul)
    const HWFloat<8,24> &id1203in_a = id1202out_result[getCycle()%9];
    const HWFloat<8,24> &id1203in_b = id663out_result[getCycle()%9];

    id1203out_result[(getCycle()+8)%9] = (mul_float(id1203in_a,id1203in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id1241out_result;

  { // Node ID: 1241 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1241in_a = id2352out_output[getCycle()%3];

    id1241out_result = (not_fixed(id1241in_a));
  }
  { // Node ID: 2362 (NodeFIFO)
    const HWFloat<8,24> &id2362in_input = id2361out_output[getCycle()%9];

    id2362out_output[(getCycle()+39)%40] = id2362in_input;
  }
  { // Node ID: 2363 (NodeFIFO)
    const HWFloat<8,24> &id2363in_input = id2362out_output[getCycle()%40];

    id2363out_output[(getCycle()+20)%21] = id2363in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id1210out_result;

  { // Node ID: 1210 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1210in_a = id2351out_output[getCycle()%19];

    id1210out_result = (not_fixed(id1210in_a));
  }
  { // Node ID: 1211 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1211in_a = id1210out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1211in_b = id2368out_output[getCycle()%21];

    HWOffsetFix<1,0,UNSIGNED> id1211x_1;

    (id1211x_1) = (and_fixed(id1211in_a,id1211in_b));
    id1211out_result[(getCycle()+1)%2] = (id1211x_1);
  }
  HWRawBits<31> id667out_result;

  { // Node ID: 667 (NodeSlice)
    const HWFloat<8,24> &id667in_a = id2357out_output[getCycle()%2];

    id667out_result = (slice<0,31>(id667in_a));
  }
  { // Node ID: 1176 (NodeConstantRawBits)
  }
  { // Node ID: 1520 (NodeEqInlined)
    const HWRawBits<31> &id1520in_a = id667out_result;
    const HWRawBits<31> &id1520in_b = id1176out_value;

    id1520out_result[(getCycle()+1)%2] = (eq_bits(id1520in_a,id1520in_b));
  }
  HWRawBits<8> id1739out_result;

  { // Node ID: 1739 (NodeSlice)
    const HWFloat<8,24> &id1739in_a = id2356out_output[getCycle()%7];

    id1739out_result = (slice<23,8>(id1739in_a));
  }
  { // Node ID: 1181 (NodeConstantRawBits)
  }
  { // Node ID: 1522 (NodeEqInlined)
    const HWRawBits<8> &id1522in_a = id1739out_result;
    const HWRawBits<8> &id1522in_b = id1181out_value;

    id1522out_result[(getCycle()+1)%2] = (eq_bits(id1522in_a,id1522in_b));
  }
  HWRawBits<23> id1740out_result;

  { // Node ID: 1740 (NodeSlice)
    const HWFloat<8,24> &id1740in_a = id2356out_output[getCycle()%7];

    id1740out_result = (slice<0,23>(id1740in_a));
  }
  { // Node ID: 1876 (NodeConstantRawBits)
  }
  { // Node ID: 1524 (NodeNeqInlined)
    const HWRawBits<23> &id1524in_a = id1740out_result;
    const HWRawBits<23> &id1524in_b = id1876out_value;

    id1524out_result[(getCycle()+1)%2] = (neq_bits(id1524in_a,id1524in_b));
  }
  { // Node ID: 1185 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1185in_a = id1522out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1185in_b = id1524out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1185x_1;

    (id1185x_1) = (and_fixed(id1185in_a,id1185in_b));
    id1185out_result[(getCycle()+1)%2] = (id1185x_1);
  }
  { // Node ID: 1186 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id1186in_a = id1520out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1186in_b = id1185out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1186x_1;

    (id1186x_1) = (or_fixed(id1186in_a,id1186in_b));
    id1186out_result[(getCycle()+1)%2] = (id1186x_1);
  }
  { // Node ID: 2308 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2308in_input = id1186out_result[getCycle()%2];

    id2308out_output[(getCycle()+79)%80] = id2308in_input;
  }
  { // Node ID: 671 (NodeConstantRawBits)
  }
  HWRawBits<23> id1741out_result;

  { // Node ID: 1741 (NodeSlice)
    const HWFloat<8,24> &id1741in_a = id2357out_output[getCycle()%2];

    id1741out_result = (slice<0,23>(id1741in_a));
  }
  HWRawBits<24> id672out_result;

  { // Node ID: 672 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id672in_in0 = id671out_value;
    const HWRawBits<23> &id672in_in1 = id1741out_result;

    id672out_result = (cat(id672in_in0,id672in_in1));
  }
  HWOffsetFix<24,0,UNSIGNED> id675out_output;

  { // Node ID: 675 (NodeReinterpret)
    const HWRawBits<24> &id675in_input = id672out_result;

    id675out_output = (cast_bits2fixed<24,0,UNSIGNED>(id675in_input));
  }
  HWRawBits<8> id1742out_result;

  { // Node ID: 1742 (NodeSlice)
    const HWFloat<8,24> &id1742in_a = id2116out_output[getCycle()%29];

    id1742out_result = (slice<23,8>(id1742in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id677out_output;

  { // Node ID: 677 (NodeReinterpret)
    const HWRawBits<8> &id677in_input = id1742out_result;

    id677out_output = (cast_bits2fixed<8,0,UNSIGNED>(id677in_input));
  }
  { // Node ID: 1874 (NodeConstantRawBits)
  }
  { // Node ID: 1873 (NodeConstantRawBits)
  }
  { // Node ID: 1993 (NodeTriArith)
    const HWOffsetFix<8,0,UNSIGNED> &id1993in_a = id677out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id1993in_b = id1874out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1993in_c = id1873out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id1993x_1;

    (id1993x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id1993in_a,id1993in_b)),id1993in_c));
    id1993out_result[(getCycle()+1)%2] = (id1993x_1);
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1994out_o;

  { // Node ID: 1994 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id1994in_i = id1993out_result[getCycle()%2];

    id1994out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1994in_i));
  }
  HWRawBits<1> id1527out_result;

  { // Node ID: 1527 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1527in_a = id1994out_o;

    id1527out_result = (slice<8,1>(id1527in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1528out_output;

  { // Node ID: 1528 (NodeReinterpret)
    const HWRawBits<1> &id1528in_input = id1527out_result;

    id1528out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1528in_input));
  }
  { // Node ID: 2217 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2217in_input = id1528out_output;

    id2217out_output[(getCycle()+5)%6] = id2217in_input;
  }
  { // Node ID: 682 (NodeConstantRawBits)
  }
  { // Node ID: 2045 (NodeConstantRawBits)
  }
  HWRawBits<1> id1529out_result;

  { // Node ID: 1529 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1529in_a = id1994out_o;

    id1529out_result = (slice<8,1>(id1529in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1530out_output;

  { // Node ID: 1530 (NodeReinterpret)
    const HWRawBits<1> &id1530in_input = id1529out_result;

    id1530out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1530in_input));
  }
  { // Node ID: 2023 (NodeCondAddSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2023in_a = id2045out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2023in_b = id1994out_o;
    const HWOffsetFix<1,0,UNSIGNED> &id2023in_sub = id1530out_output;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2023x_1;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2023x_2;
    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2023x_3;

    (id2023x_1) = (add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2023in_a,id2023in_b));
    (id2023x_2) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2023in_a,id2023in_b));
    switch((id2023in_sub.getValueAsLong())) {
      case 0l:
        id2023x_3 = (id2023x_1);
        break;
      case 1l:
        id2023x_3 = (id2023x_2);
        break;
      default:
        id2023x_3 = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
        break;
    }
    id2023out_result[(getCycle()+1)%2] = (id2023x_3);
  }
  HWRawBits<8> id689out_result;

  { // Node ID: 689 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id689in_a = id2023out_result[getCycle()%2];

    id689out_result = (slice<0,8>(id689in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id690out_output;

  { // Node ID: 690 (NodeReinterpret)
    const HWRawBits<8> &id690in_input = id689out_result;

    id690out_output = (cast_bits2fixed<8,0,UNSIGNED>(id690in_input));
  }
  { // Node ID: 692 (NodeShift)
    const HWRawBits<185> &id692in_datain = id682out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id692in_shift = id690out_output;

    id692out_dataout[(getCycle()+4)%5] = (shift_left_bits(id692in_datain,(id692in_shift.getValueAsLong())));
  }
  { // Node ID: 691 (NodeShift)
    const HWRawBits<185> &id691in_datain = id682out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id691in_shift = id690out_output;

    id691out_dataout[(getCycle()+4)%5] = (shift_right_bits(id691in_datain,(id691in_shift.getValueAsLong())));
  }
  { // Node ID: 693 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id693in_sel = id2217out_output[getCycle()%6];
    const HWRawBits<185> &id693in_option0 = id692out_dataout[getCycle()%5];
    const HWRawBits<185> &id693in_option1 = id691out_dataout[getCycle()%5];

    HWRawBits<185> id693x_1;

    switch((id693in_sel.getValueAsLong())) {
      case 0l:
        id693x_1 = id693in_option0;
        break;
      case 1l:
        id693x_1 = id693in_option1;
        break;
      default:
        id693x_1 = (HWRawBits<185>(varint_u<185>::init(3, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64), m_undefined_value.get_bits(57))));
        break;
    }
    id693out_result[(getCycle()+1)%2] = (id693x_1);
  }
  HWRawBits<81> id694out_result;

  { // Node ID: 694 (NodeSlice)
    const HWRawBits<185> &id694in_a = id693out_result[getCycle()%2];

    id694out_result = (slice<104,81>(id694in_a));
  }
  HWOffsetFix<81,0,UNSIGNED> id696out_output;

  { // Node ID: 696 (NodeReinterpret)
    const HWRawBits<81> &id696in_input = id694out_result;

    id696out_output = (cast_bits2fixed<81,0,UNSIGNED>(id696in_input));
  }
  { // Node ID: 697 (NodeMul)
    const HWOffsetFix<24,0,UNSIGNED> &id697in_a = id675out_output;
    const HWOffsetFix<81,0,UNSIGNED> &id697in_b = id696out_output;

    id697out_result[(getCycle()+1)%2] = (mul_fixed<81,0,UNSIGNED,TONEAREVEN>(id697in_a,id697in_b));
  }
  HWRawBits<79> id704out_result;

  { // Node ID: 704 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id704in_a = id697out_result[getCycle()%2];

    id704out_result = (slice<0,79>(id704in_a));
  }
  HWOffsetFix<79,-79,UNSIGNED> id705out_output;

  { // Node ID: 705 (NodeReinterpret)
    const HWRawBits<79> &id705in_input = id704out_result;

    id705out_output = (cast_bits2fixed<79,-79,UNSIGNED>(id705in_input));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id708out_o;

  { // Node ID: 708 (NodeCast)
    const HWOffsetFix<79,-79,UNSIGNED> &id708in_i = id705out_output;

    id708out_o = (cast_fixed2fixed<80,-79,TWOSCOMPLEMENT,TONEAREVEN>(id708in_i));
  }
  { // Node ID: 709 (NodeLeading1Detect)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id709in_input = id708out_o;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id709x_1;
    HWRawBits<80> id709x_2;
    HWRawBits<80> id709x_3;

    switch(((slice<79,1>(id709in_input)).getValueAsLong())) {
      case 0l:
        id709x_1 = id709in_input;
        break;
      case 1l:
        id709x_1 = (not_fixed(id709in_input));
        break;
      default:
        id709x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    {
      varint_u<80> raw_bits = (slice<0,80>((cat((id709x_1),(c_hw_fix_1_0_uns_bits))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id709x_2 = HWRawBits<80>(raw_bits);
    }
    {
      varint_u<80> raw_bits = (cast_fixed2bits((add_fixed<80,0,UNSIGNED,TRUNCATE>((cast_bits2fixed<80,0,UNSIGNED>((not_bits((id709x_2))))),(c_hw_fix_80_0_uns_1_0val))))).getBitString();
      for (int i=0; i<40; i++) {
        int partner_bit = (80-1) - i;
        bool low_val = raw_bits[i];
        bool high_val = raw_bits[partner_bit];
        raw_bits[i] = high_val;
        raw_bits[partner_bit] = low_val;
      }
      id709x_3 = HWRawBits<80>(raw_bits);
    }
    id709out_output[(getCycle()+1)%2] = (cast_bits2fixed<80,0,UNSIGNED>((and_bits((id709x_3),(slice<0,80>((cat((id709x_1),(c_hw_fix_1_0_uns_bits)))))))));
  }
  { // Node ID: 710 (NodeOneHotDecode)
    const HWOffsetFix<80,0,UNSIGNED> &id710in_input = id709out_output[getCycle()%2];

    (id710st_one_hot_or) = (c_hw_fix_7_0_uns_bits_1);
    if(((slice<0,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_1)));
    }
    if(((slice<1,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_2)));
    }
    if(((slice<2,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_3)));
    }
    if(((slice<3,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_4)));
    }
    if(((slice<4,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_5)));
    }
    if(((slice<5,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_6)));
    }
    if(((slice<6,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_7)));
    }
    if(((slice<7,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_8)));
    }
    if(((slice<8,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_9)));
    }
    if(((slice<9,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_10)));
    }
    if(((slice<10,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_11)));
    }
    if(((slice<11,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_12)));
    }
    if(((slice<12,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_13)));
    }
    if(((slice<13,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_14)));
    }
    if(((slice<14,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_15)));
    }
    if(((slice<15,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_16)));
    }
    if(((slice<16,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_17)));
    }
    if(((slice<17,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_18)));
    }
    if(((slice<18,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_19)));
    }
    if(((slice<19,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_20)));
    }
    if(((slice<20,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_21)));
    }
    if(((slice<21,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_22)));
    }
    if(((slice<22,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_23)));
    }
    if(((slice<23,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_24)));
    }
    if(((slice<24,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_25)));
    }
    if(((slice<25,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_26)));
    }
    if(((slice<26,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_27)));
    }
    if(((slice<27,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_28)));
    }
    if(((slice<28,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_29)));
    }
    if(((slice<29,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_30)));
    }
    if(((slice<30,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_31)));
    }
    if(((slice<31,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_32)));
    }
    if(((slice<32,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_33)));
    }
    if(((slice<33,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_34)));
    }
    if(((slice<34,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_35)));
    }
    if(((slice<35,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_36)));
    }
    if(((slice<36,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_37)));
    }
    if(((slice<37,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_38)));
    }
    if(((slice<38,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_39)));
    }
    if(((slice<39,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_40)));
    }
    if(((slice<40,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_41)));
    }
    if(((slice<41,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_42)));
    }
    if(((slice<42,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_43)));
    }
    if(((slice<43,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_44)));
    }
    if(((slice<44,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_45)));
    }
    if(((slice<45,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_46)));
    }
    if(((slice<46,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_47)));
    }
    if(((slice<47,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_48)));
    }
    if(((slice<48,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_49)));
    }
    if(((slice<49,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_50)));
    }
    if(((slice<50,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_51)));
    }
    if(((slice<51,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_52)));
    }
    if(((slice<52,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_53)));
    }
    if(((slice<53,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_54)));
    }
    if(((slice<54,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_55)));
    }
    if(((slice<55,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_56)));
    }
    if(((slice<56,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_57)));
    }
    if(((slice<57,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_58)));
    }
    if(((slice<58,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_59)));
    }
    if(((slice<59,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_60)));
    }
    if(((slice<60,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_61)));
    }
    if(((slice<61,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_62)));
    }
    if(((slice<62,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_63)));
    }
    if(((slice<63,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_64)));
    }
    if(((slice<64,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_65)));
    }
    if(((slice<65,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_66)));
    }
    if(((slice<66,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_67)));
    }
    if(((slice<67,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_68)));
    }
    if(((slice<68,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_69)));
    }
    if(((slice<69,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_70)));
    }
    if(((slice<70,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_71)));
    }
    if(((slice<71,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_72)));
    }
    if(((slice<72,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_73)));
    }
    if(((slice<73,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_74)));
    }
    if(((slice<74,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_75)));
    }
    if(((slice<75,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_76)));
    }
    if(((slice<76,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_77)));
    }
    if(((slice<77,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_78)));
    }
    if(((slice<78,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_79)));
    }
    if(((slice<79,1>(id710in_input)).getValueAsBool())) {
      (id710st_one_hot_or) = (or_fixed((id710st_one_hot_or),(c_hw_fix_7_0_uns_bits_80)));
    }
    id710out_output[(getCycle()+1)%2] = (id710st_one_hot_or);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id711out_o;

  { // Node ID: 711 (NodeCast)
    const HWOffsetFix<7,0,UNSIGNED> &id711in_i = id710out_output[getCycle()%2];

    id711out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id711in_i));
  }
  { // Node ID: 1869 (NodeConstantRawBits)
  }
  { // Node ID: 1868 (NodeConstantRawBits)
  }
  { // Node ID: 1995 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1995in_a = id711out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1995in_b = id1869out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1995in_c = id1868out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id1995x_1;

    (id1995x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id1995in_a,id1995in_b)),id1995in_c));
    id1995out_result[(getCycle()+1)%2] = (id1995x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1996out_o;

  { // Node ID: 1996 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id1996in_i = id1995out_result[getCycle()%2];

    id1996out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id1996in_i));
  }
  { // Node ID: 2218 (NodeFIFO)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id2218in_input = id1996out_o;

    id2218out_output[(getCycle()+4)%5] = id2218in_input;
  }
  HWOffsetFix<9,0,TWOSCOMPLEMENT> id728out_o;

  { // Node ID: 728 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id728in_i = id2218out_output[getCycle()%5];

    id728out_o = (cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id728in_i));
  }
  { // Node ID: 1867 (NodeConstantRawBits)
  }
  { // Node ID: 730 (NodeAdd)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id730in_a = id728out_o;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id730in_b = id1867out_value;

    id730out_result[(getCycle()+1)%2] = (add_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id730in_a,id730in_b));
  }
  { // Node ID: 1866 (NodeConstantRawBits)
  }
  { // Node ID: 1533 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1533in_a = id730out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1533in_b = id1866out_value;

    id1533out_result[(getCycle()+1)%2] = (lt_fixed(id1533in_a,id1533in_b));
  }
  { // Node ID: 2223 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2223in_input = id1533out_result[getCycle()%2];

    id2223out_output[(getCycle()+1)%2] = id2223in_input;
  }
  { // Node ID: 1865 (NodeConstantRawBits)
  }
  { // Node ID: 1534 (NodeGtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1534in_a = id730out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1534in_b = id1865out_value;

    id1534out_result[(getCycle()+1)%2] = (gt_fixed(id1534in_a,id1534in_b));
  }
  { // Node ID: 1334 (NodeConstantRawBits)
  }
  HWOffsetFix<8,0,UNSIGNED> id733out_o;

  { // Node ID: 733 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id733in_i = id730out_result[getCycle()%2];

    id733out_o = (cast_fixed2fixed<8,0,UNSIGNED,TONEAREVEN>(id733in_i));
  }
  { // Node ID: 2222 (NodeFIFO)
    const HWOffsetFix<8,0,UNSIGNED> &id2222in_input = id733out_o;

    id2222out_output[(getCycle()+1)%2] = id2222in_input;
  }
  { // Node ID: 1864 (NodeConstantRawBits)
  }
  { // Node ID: 1863 (NodeConstantRawBits)
  }
  { // Node ID: 1997 (NodeTriArith)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1997in_a = id1864out_value;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1997in_b = id711out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1997in_c = id1863out_value;

    HWOffsetFix<10,0,TWOSCOMPLEMENT> id1997x_1;

    (id1997x_1) = (sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>((sub_fixed<10,0,TWOSCOMPLEMENT,TONEAREVEN>(id1997in_a,id1997in_b)),id1997in_c));
    id1997out_result[(getCycle()+1)%2] = (id1997x_1);
  }
  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1998out_o;

  { // Node ID: 1998 (NodeCast)
    const HWOffsetFix<10,0,TWOSCOMPLEMENT> &id1998in_i = id1997out_result[getCycle()%2];

    id1998out_o = (cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(id1998in_i));
  }
  { // Node ID: 1862 (NodeConstantRawBits)
  }
  { // Node ID: 1535 (NodeGtInlined)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1535in_a = id1998out_o;
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id1535in_b = id1862out_value;

    id1535out_result[(getCycle()+1)%2] = (gt_fixed(id1535in_a,id1535in_b));
  }
  { // Node ID: 2220 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2220in_input = id1535out_result[getCycle()%2];

    id2220out_output[(getCycle()+3)%4] = id2220in_input;
  }
  { // Node ID: 2219 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2219in_input = id708out_o;

    id2219out_output[(getCycle()+3)%4] = id2219in_input;
  }
  { // Node ID: 2360 (NodeFIFO)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id2360in_input = id2219out_output[getCycle()%4];

    id2360out_output[(getCycle()+4)%5] = id2360in_input;
  }
  HWOffsetFix<7,0,UNSIGNED> id722out_o;

  { // Node ID: 722 (NodeCast)
    const HWOffsetFix<8,0,TWOSCOMPLEMENT> &id722in_i = id1998out_o;

    id722out_o = (cast_fixed2fixed<7,0,UNSIGNED,TONEAREVEN>(id722in_i));
  }
  { // Node ID: 723 (NodeShift)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id723in_datain = id2219out_output[getCycle()%4];
    const HWOffsetFix<7,0,UNSIGNED> &id723in_shift = id722out_o;

    id723out_dataout[(getCycle()+4)%5] = (shift_left_fixed(id723in_datain,(id723in_shift.getValueAsLong())));
  }
  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id724out_output;

  { // Node ID: 724 (NodeReinterpret)
    const HWRawBits<80> &id724in_input = id723out_dataout[getCycle()%5];

    id724out_output = (cast_bits2fixed<80,-79,TWOSCOMPLEMENT>(id724in_input));
  }
  { // Node ID: 725 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id725in_sel = id2220out_output[getCycle()%4];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id725in_option0 = id2360out_output[getCycle()%5];
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id725in_option1 = id724out_output;

    HWOffsetFix<80,-79,TWOSCOMPLEMENT> id725x_1;

    switch((id725in_sel.getValueAsLong())) {
      case 0l:
        id725x_1 = id725in_option0;
        break;
      case 1l:
        id725x_1 = id725in_option1;
        break;
      default:
        id725x_1 = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
        break;
    }
    id725out_result[(getCycle()+1)%2] = (id725x_1);
  }
  HWOffsetFix<80,-78,TWOSCOMPLEMENT> id727out_output;

  { // Node ID: 727 (NodeReinterpret)
    const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &id727in_input = id725out_result[getCycle()%2];

    id727out_output = (cast_bits2fixed<80,-78,TWOSCOMPLEMENT>((cast_fixed2bits(id727in_input))));
  }
  { // Node ID: 731 (NodeCast)
    const HWOffsetFix<80,-78,TWOSCOMPLEMENT> &id731in_i = id727out_output;

    id731out_o[(getCycle()+1)%2] = (cast_fixed2fixed<24,-23,UNSIGNED,TONEAREVEN>(id731in_i));
  }
  HWRawBits<23> id732out_result;

  { // Node ID: 732 (NodeSlice)
    const HWOffsetFix<24,-23,UNSIGNED> &id732in_a = id731out_o[getCycle()%2];

    id732out_result = (slice<0,23>(id732in_a));
  }
  HWRawBits<32> id1536out_result;

  { // Node ID: 1536 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id1536in_in0 = id1334out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1536in_in1 = id2222out_output[getCycle()%2];
    const HWRawBits<23> &id1536in_in2 = id732out_result;

    id1536out_result = (cat((cat(id1536in_in0,id1536in_in1)),id1536in_in2));
  }
  HWFloat<8,24> id737out_output;

  { // Node ID: 737 (NodeReinterpret)
    const HWRawBits<32> &id737in_input = id1536out_result;

    id737out_output = (cast_bits2float<8,24>(id737in_input));
  }
  { // Node ID: 740 (NodeConstantRawBits)
  }
  { // Node ID: 741 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id741in_sel = id1534out_result[getCycle()%2];
    const HWFloat<8,24> &id741in_option0 = id737out_output;
    const HWFloat<8,24> &id741in_option1 = id740out_value;

    HWFloat<8,24> id741x_1;

    switch((id741in_sel.getValueAsLong())) {
      case 0l:
        id741x_1 = id741in_option0;
        break;
      case 1l:
        id741x_1 = id741in_option1;
        break;
      default:
        id741x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id741out_result[(getCycle()+1)%2] = (id741x_1);
  }
  { // Node ID: 744 (NodeConstantRawBits)
  }
  { // Node ID: 745 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id745in_sel = id2223out_output[getCycle()%2];
    const HWFloat<8,24> &id745in_option0 = id741out_result[getCycle()%2];
    const HWFloat<8,24> &id745in_option1 = id744out_value;

    HWFloat<8,24> id745x_1;

    switch((id745in_sel.getValueAsLong())) {
      case 0l:
        id745x_1 = id745in_option0;
        break;
      case 1l:
        id745x_1 = id745in_option1;
        break;
      default:
        id745x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id745out_result[(getCycle()+1)%2] = (id745x_1);
  }
  { // Node ID: 2224 (NodeFIFO)
    const HWFloat<8,24> &id2224in_input = id745out_result[getCycle()%2];

    id2224out_output[(getCycle()+1)%2] = id2224in_input;
  }
  { // Node ID: 1861 (NodeConstantRawBits)
  }
  { // Node ID: 1168 (NodeLt)
    const HWFloat<8,24> &id1168in_a = id2224out_output[getCycle()%2];
    const HWFloat<8,24> &id1168in_b = id1861out_value;

    id1168out_result[(getCycle()+2)%3] = (lt_float(id1168in_a,id1168in_b));
  }
  { // Node ID: 1860 (NodeConstantRawBits)
  }
  { // Node ID: 1170 (NodeGte)
    const HWFloat<8,24> &id1170in_a = id2224out_output[getCycle()%2];
    const HWFloat<8,24> &id1170in_b = id1860out_value;

    id1170out_result[(getCycle()+2)%3] = (gte_float(id1170in_a,id1170in_b));
  }
  { // Node ID: 1171 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id1171in_a = id1168out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id1171in_b = id1170out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id1171x_1;

    (id1171x_1) = (or_fixed(id1171in_a,id1171in_b));
    id1171out_result[(getCycle()+1)%2] = (id1171x_1);
  }
  { // Node ID: 2306 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2306in_input = id1171out_result[getCycle()%2];

    id2306out_output[(getCycle()+64)%65] = id2306in_input;
  }
  { // Node ID: 1875 (NodeConstantRawBits)
  }
  { // Node ID: 665 (NodeLt)
    const HWFloat<8,24> &id665in_a = id2357out_output[getCycle()%2];
    const HWFloat<8,24> &id665in_b = id1875out_value;

    id665out_result[(getCycle()+2)%3] = (lt_float(id665in_a,id665in_b));
  }
  HWRawBits<2> id700out_result;

  { // Node ID: 700 (NodeSlice)
    const HWOffsetFix<81,0,UNSIGNED> &id700in_a = id697out_result[getCycle()%2];

    id700out_result = (slice<79,2>(id700in_a));
  }
  { // Node ID: 2227 (NodeFIFO)
    const HWRawBits<2> &id2227in_input = id700out_result;

    id2227out_output[(getCycle()+1)%2] = id2227in_input;
  }
  { // Node ID: 1872 (NodeConstantRawBits)
  }
  { // Node ID: 702 (NodeXor)
    const HWRawBits<2> &id702in_a = id700out_result;
    const HWRawBits<2> &id702in_b = id1872out_value;

    HWRawBits<2> id702x_1;

    (id702x_1) = (xor_bits(id702in_a,id702in_b));
    id702out_result[(getCycle()+1)%2] = (id702x_1);
  }
  { // Node ID: 703 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id703in_sel = id665out_result[getCycle()%3];
    const HWRawBits<2> &id703in_option0 = id2227out_output[getCycle()%2];
    const HWRawBits<2> &id703in_option1 = id702out_result[getCycle()%2];

    HWRawBits<2> id703x_1;

    switch((id703in_sel.getValueAsLong())) {
      case 0l:
        id703x_1 = id703in_option0;
        break;
      case 1l:
        id703x_1 = id703in_option1;
        break;
      default:
        id703x_1 = (HWRawBits<2>(varint_u<2>(m_undefined_value.get_bits(2))));
        break;
    }
    id703out_result[(getCycle()+1)%2] = (id703x_1);
  }
  HWRawBits<1> id746out_result;

  { // Node ID: 746 (NodeSlice)
    const HWRawBits<2> &id746in_a = id703out_result[getCycle()%2];

    id746out_result = (slice<0,1>(id746in_a));
  }
  { // Node ID: 2238 (NodeFIFO)
    const HWRawBits<1> &id2238in_input = id746out_result;

    id2238out_output[(getCycle()+27)%28] = id2238in_input;
  }
  { // Node ID: 1859 (NodeConstantRawBits)
  }
  HWRawBits<8> id766out_result;

  { // Node ID: 766 (NodeSlice)
    const HWFloat<8,24> &id766in_a = id2224out_output[getCycle()%2];

    id766out_result = (slice<23,8>(id766in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id767out_output;

  { // Node ID: 767 (NodeReinterpret)
    const HWRawBits<8> &id767in_input = id766out_result;

    id767out_output = (cast_bits2fixed<8,0,UNSIGNED>(id767in_input));
  }
  { // Node ID: 1858 (NodeConstantRawBits)
  }
  { // Node ID: 1999 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1999in_a = id1859out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id1999in_b = id767out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id1999in_c = id1858out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id1999x_1;

    (id1999x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id1999in_a,id1999in_b)),id1999in_c));
    id1999out_result[(getCycle()+1)%2] = (id1999x_1);
  }
  HWRawBits<1> id1537out_result;

  { // Node ID: 1537 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1537in_a = id1999out_result[getCycle()%2];

    id1537out_result = (slice<8,1>(id1537in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1538out_output;

  { // Node ID: 1538 (NodeReinterpret)
    const HWRawBits<1> &id1538in_input = id1537out_result;

    id1538out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1538in_input));
  }
  { // Node ID: 2231 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2231in_input = id1538out_output;

    id2231out_output[(getCycle()+4)%5] = id2231in_input;
  }
  { // Node ID: 764 (NodeConstantRawBits)
  }
  { // Node ID: 2044 (NodeConstantRawBits)
  }
  { // Node ID: 756 (NodeConstantRawBits)
  }
  HWRawBits<31> id753out_result;

  { // Node ID: 753 (NodeSlice)
    const HWFloat<8,24> &id753in_a = id745out_result[getCycle()%2];

    id753out_result = (slice<0,31>(id753in_a));
  }
  { // Node ID: 1857 (NodeConstantRawBits)
  }
  { // Node ID: 1539 (NodeNeqInlined)
    const HWRawBits<31> &id1539in_a = id753out_result;
    const HWRawBits<31> &id1539in_b = id1857out_value;

    id1539out_result[(getCycle()+1)%2] = (neq_bits(id1539in_a,id1539in_b));
  }
  HWRawBits<23> id752out_result;

  { // Node ID: 752 (NodeSlice)
    const HWFloat<8,24> &id752in_a = id2224out_output[getCycle()%2];

    id752out_result = (slice<0,23>(id752in_a));
  }
  HWRawBits<25> id1540out_result;

  { // Node ID: 1540 (NodeCat)
    const HWRawBits<1> &id1540in_in0 = id756out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1540in_in1 = id1539out_result[getCycle()%2];
    const HWRawBits<23> &id1540in_in2 = id752out_result;

    id1540out_result = (cat((cat(id1540in_in0,id1540in_in1)),id1540in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id759out_output;

  { // Node ID: 759 (NodeReinterpret)
    const HWRawBits<25> &id759in_input = id1540out_result;

    id759out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id759in_input));
  }
  HWRawBits<1> id760out_result;

  { // Node ID: 760 (NodeSlice)
    const HWFloat<8,24> &id760in_a = id2224out_output[getCycle()%2];

    id760out_result = (slice<31,1>(id760in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id761out_output;

  { // Node ID: 761 (NodeReinterpret)
    const HWRawBits<1> &id761in_input = id760out_result;

    id761out_output = (cast_bits2fixed<1,0,UNSIGNED>(id761in_input));
  }
  { // Node ID: 2025 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2025in_a = id2044out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2025in_b = id759out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2025in_sub = id761out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2025x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2025x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2025x_3;

    (id2025x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2025in_a,id2025in_b));
    (id2025x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2025in_a,id2025in_b));
    switch((id2025in_sub.getValueAsLong())) {
      case 0l:
        id2025x_3 = (id2025x_1);
        break;
      case 1l:
        id2025x_3 = (id2025x_2);
        break;
      default:
        id2025x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2025out_result[(getCycle()+1)%2] = (id2025x_3);
  }
  HWRawBits<30> id765out_result;

  { // Node ID: 765 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id765in_in0 = id764out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id765in_in1 = id2025out_result[getCycle()%2];

    id765out_result = (cat(id765in_in0,id765in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id774out_o;

  { // Node ID: 774 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id774in_i = id1999out_result[getCycle()%2];

    id774out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id774in_i));
  }
  { // Node ID: 775 (NodeShift)
    const HWRawBits<30> &id775in_datain = id765out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id775in_shift = id774out_o;

    id775out_dataout[(getCycle()+4)%5] = (shift_left_bits(id775in_datain,(id775in_shift.getValueAsLong())));
  }
  HWRawBits<7> id776out_result;

  { // Node ID: 776 (NodeSlice)
    const HWRawBits<30> &id776in_a = id775out_dataout[getCycle()%5];

    id776out_result = (slice<23,7>(id776in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id777out_output;

  { // Node ID: 777 (NodeReinterpret)
    const HWRawBits<7> &id777in_input = id776out_result;

    id777out_output = (cast_bits2fixed<7,0,UNSIGNED>(id777in_input));
  }
  { // Node ID: 778 (NodeConstantRawBits)
  }
  { // Node ID: 779 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id779in_sel = id2231out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id779in_option0 = id777out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id779in_option1 = id778out_value;

    HWOffsetFix<7,0,UNSIGNED> id779x_1;

    switch((id779in_sel.getValueAsLong())) {
      case 0l:
        id779x_1 = id779in_option0;
        break;
      case 1l:
        id779x_1 = id779in_option1;
        break;
      default:
        id779x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id779out_result[(getCycle()+1)%2] = (id779x_1);
  }
  { // Node ID: 2232 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2232in_input = id779out_result[getCycle()%2];

    id2232out_output[(getCycle()+9)%10] = id2232in_input;
  }
  { // Node ID: 1305 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1305in_addr = id2232out_output[getCycle()%10];

    HWRawBits<128> id1305x_1;

    switch(((long)((id1305in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1305x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1305x_1 = (id1305sta_rom_store[(id1305in_addr.getValueAsLong())]);
        break;
      default:
        id1305x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1305out_dout[(getCycle()+2)%3] = (id1305x_1);
  }
  HWRawBits<32> id1312out_result;

  { // Node ID: 1312 (NodeSlice)
    const HWRawBits<128> &id1312in_a = id1305out_dout[getCycle()%3];

    id1312out_result = (slice<96,32>(id1312in_a));
  }
  HWFloat<8,24> id1313out_output;

  { // Node ID: 1313 (NodeReinterpret)
    const HWRawBits<32> &id1313in_input = id1312out_result;

    id1313out_output = (cast_bits2float<8,24>(id1313in_input));
  }
  { // Node ID: 1856 (NodeConstantRawBits)
  }
  HWRawBits<8> id967out_result;

  { // Node ID: 967 (NodeSlice)
    const HWFloat<8,24> &id967in_a = id2224out_output[getCycle()%2];

    id967out_result = (slice<23,8>(id967in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id968out_output;

  { // Node ID: 968 (NodeReinterpret)
    const HWRawBits<8> &id968in_input = id967out_result;

    id968out_output = (cast_bits2fixed<8,0,UNSIGNED>(id968in_input));
  }
  { // Node ID: 1855 (NodeConstantRawBits)
  }
  { // Node ID: 2000 (NodeTriArith)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id2000in_a = id1856out_value;
    const HWOffsetFix<8,0,UNSIGNED> &id2000in_b = id968out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id2000in_c = id1855out_value;

    HWOffsetFix<9,0,TWOSCOMPLEMENT> id2000x_1;

    (id2000x_1) = (sub_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<9,0,TWOSCOMPLEMENT,TRUNCATE>(id2000in_a,id2000in_b)),id2000in_c));
    id2000out_result[(getCycle()+1)%2] = (id2000x_1);
  }
  HWRawBits<1> id1541out_result;

  { // Node ID: 1541 (NodeSlice)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1541in_a = id2000out_result[getCycle()%2];

    id1541out_result = (slice<8,1>(id1541in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1542out_output;

  { // Node ID: 1542 (NodeReinterpret)
    const HWRawBits<1> &id1542in_input = id1541out_result;

    id1542out_output = (cast_bits2fixed<1,0,UNSIGNED>(id1542in_input));
  }
  { // Node ID: 2236 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2236in_input = id1542out_output;

    id2236out_output[(getCycle()+4)%5] = id2236in_input;
  }
  { // Node ID: 965 (NodeConstantRawBits)
  }
  { // Node ID: 2043 (NodeConstantRawBits)
  }
  { // Node ID: 957 (NodeConstantRawBits)
  }
  HWRawBits<31> id954out_result;

  { // Node ID: 954 (NodeSlice)
    const HWFloat<8,24> &id954in_a = id745out_result[getCycle()%2];

    id954out_result = (slice<0,31>(id954in_a));
  }
  { // Node ID: 1854 (NodeConstantRawBits)
  }
  { // Node ID: 1543 (NodeNeqInlined)
    const HWRawBits<31> &id1543in_a = id954out_result;
    const HWRawBits<31> &id1543in_b = id1854out_value;

    id1543out_result[(getCycle()+1)%2] = (neq_bits(id1543in_a,id1543in_b));
  }
  HWRawBits<23> id953out_result;

  { // Node ID: 953 (NodeSlice)
    const HWFloat<8,24> &id953in_a = id2224out_output[getCycle()%2];

    id953out_result = (slice<0,23>(id953in_a));
  }
  HWRawBits<25> id1544out_result;

  { // Node ID: 1544 (NodeCat)
    const HWRawBits<1> &id1544in_in0 = id957out_value;
    const HWOffsetFix<1,0,UNSIGNED> &id1544in_in1 = id1543out_result[getCycle()%2];
    const HWRawBits<23> &id1544in_in2 = id953out_result;

    id1544out_result = (cat((cat(id1544in_in0,id1544in_in1)),id1544in_in2));
  }
  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id960out_output;

  { // Node ID: 960 (NodeReinterpret)
    const HWRawBits<25> &id960in_input = id1544out_result;

    id960out_output = (cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(id960in_input));
  }
  HWRawBits<1> id961out_result;

  { // Node ID: 961 (NodeSlice)
    const HWFloat<8,24> &id961in_a = id2224out_output[getCycle()%2];

    id961out_result = (slice<31,1>(id961in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id962out_output;

  { // Node ID: 962 (NodeReinterpret)
    const HWRawBits<1> &id962in_input = id961out_result;

    id962out_output = (cast_bits2fixed<1,0,UNSIGNED>(id962in_input));
  }
  { // Node ID: 2027 (NodeCondAddSub)
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2027in_a = id2043out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id2027in_b = id960out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id2027in_sub = id962out_output;

    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2027x_1;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2027x_2;
    HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2027x_3;

    (id2027x_1) = (add_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2027in_a,id2027in_b));
    (id2027x_2) = (sub_fixed<25,-23,TWOSCOMPLEMENT,TRUNCATE>(id2027in_a,id2027in_b));
    switch((id2027in_sub.getValueAsLong())) {
      case 0l:
        id2027x_3 = (id2027x_1);
        break;
      case 1l:
        id2027x_3 = (id2027x_2);
        break;
      default:
        id2027x_3 = (HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(m_undefined_value.get_bits(25))));
        break;
    }
    id2027out_result[(getCycle()+1)%2] = (id2027x_3);
  }
  HWRawBits<30> id966out_result;

  { // Node ID: 966 (NodeCat)
    const HWOffsetFix<5,0,UNSIGNED> &id966in_in0 = id965out_value;
    const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &id966in_in1 = id2027out_result[getCycle()%2];

    id966out_result = (cat(id966in_in0,id966in_in1));
  }
  HWOffsetFix<5,0,UNSIGNED> id975out_o;

  { // Node ID: 975 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id975in_i = id2000out_result[getCycle()%2];

    id975out_o = (cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(id975in_i));
  }
  { // Node ID: 976 (NodeShift)
    const HWRawBits<30> &id976in_datain = id966out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id976in_shift = id975out_o;

    id976out_dataout[(getCycle()+4)%5] = (shift_left_bits(id976in_datain,(id976in_shift.getValueAsLong())));
  }
  HWRawBits<7> id977out_result;

  { // Node ID: 977 (NodeSlice)
    const HWRawBits<30> &id977in_a = id976out_dataout[getCycle()%5];

    id977out_result = (slice<23,7>(id977in_a));
  }
  HWOffsetFix<7,0,UNSIGNED> id978out_output;

  { // Node ID: 978 (NodeReinterpret)
    const HWRawBits<7> &id978in_input = id977out_result;

    id978out_output = (cast_bits2fixed<7,0,UNSIGNED>(id978in_input));
  }
  { // Node ID: 979 (NodeConstantRawBits)
  }
  { // Node ID: 980 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id980in_sel = id2236out_output[getCycle()%5];
    const HWOffsetFix<7,0,UNSIGNED> &id980in_option0 = id978out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id980in_option1 = id979out_value;

    HWOffsetFix<7,0,UNSIGNED> id980x_1;

    switch((id980in_sel.getValueAsLong())) {
      case 0l:
        id980x_1 = id980in_option0;
        break;
      case 1l:
        id980x_1 = id980in_option1;
        break;
      default:
        id980x_1 = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
        break;
    }
    id980out_result[(getCycle()+1)%2] = (id980x_1);
  }
  { // Node ID: 2237 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id2237in_input = id980out_result[getCycle()%2];

    id2237out_output[(getCycle()+9)%10] = id2237in_input;
  }
  { // Node ID: 1314 (NodeROM)
    const HWOffsetFix<7,0,UNSIGNED> &id1314in_addr = id2237out_output[getCycle()%10];

    HWRawBits<128> id1314x_1;

    switch(((long)((id1314in_addr.getValueAsLong())<(128l)))) {
      case 0l:
        id1314x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
      case 1l:
        id1314x_1 = (id1314sta_rom_store[(id1314in_addr.getValueAsLong())]);
        break;
      default:
        id1314x_1 = (HWRawBits<128>(varint_u<128>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(64))));
        break;
    }
    id1314out_dout[(getCycle()+2)%3] = (id1314x_1);
  }
  HWRawBits<32> id1321out_result;

  { // Node ID: 1321 (NodeSlice)
    const HWRawBits<128> &id1321in_a = id1314out_dout[getCycle()%3];

    id1321out_result = (slice<96,32>(id1321in_a));
  }
  HWFloat<8,24> id1322out_output;

  { // Node ID: 1322 (NodeReinterpret)
    const HWRawBits<32> &id1322in_input = id1321out_result;

    id1322out_output = (cast_bits2float<8,24>(id1322in_input));
  }
  { // Node ID: 1158 (NodeMux)
    const HWRawBits<1> &id1158in_sel = id2238out_output[getCycle()%28];
    const HWFloat<8,24> &id1158in_option0 = id1313out_output;
    const HWFloat<8,24> &id1158in_option1 = id1322out_output;

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
  { // Node ID: 1983 (NodePO2FPMult)
    const HWFloat<8,24> &id1983in_floatIn = id745out_result[getCycle()%2];

    id1983out_floatOut[(getCycle()+1)%2] = (mul_float(id1983in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2239 (NodeFIFO)
    const HWFloat<8,24> &id2239in_input = id1983out_floatOut[getCycle()%2];

    id2239out_output[(getCycle()+3)%4] = id2239in_input;
  }
  HWRawBits<1> id789out_result;

  { // Node ID: 789 (NodeSlice)
    const HWFloat<8,24> &id789in_a = id2239out_output[getCycle()%4];

    id789out_result = (slice<31,1>(id789in_a));
  }
  { // Node ID: 2268 (NodeFIFO)
    const HWRawBits<1> &id2268in_input = id789out_result;

    id2268out_output[(getCycle()+6)%7] = id2268in_input;
  }
  HWRawBits<8> id782out_result;

  { // Node ID: 782 (NodeSlice)
    const HWFloat<8,24> &id782in_a = id1983out_floatOut[getCycle()%2];

    id782out_result = (slice<23,8>(id782in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id783out_output;

  { // Node ID: 783 (NodeReinterpret)
    const HWRawBits<8> &id783in_input = id782out_result;

    id783out_output = (cast_bits2fixed<8,0,UNSIGNED>(id783in_input));
  }
  { // Node ID: 1852 (NodeConstantRawBits)
  }
  { // Node ID: 785 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id785in_a = id783out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id785in_b = id1852out_value;

    id785out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id785in_a,id785in_b));
  }
  { // Node ID: 1851 (NodeConstantRawBits)
  }
  { // Node ID: 1545 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1545in_a = id785out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1545in_b = id1851out_value;

    id1545out_result[(getCycle()+1)%2] = (gte_fixed(id1545in_a,id1545in_b));
  }
  { // Node ID: 1850 (NodeConstantRawBits)
  }
  { // Node ID: 1546 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1546in_a = id785out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1546in_b = id1850out_value;

    id1546out_result[(getCycle()+1)%2] = (lte_fixed(id1546in_a,id1546in_b));
  }
  { // Node ID: 794 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id794in_a = id1545out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id794in_b = id1546out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id794x_1;

    (id794x_1) = (or_fixed(id794in_a,id794in_b));
    id794out_result[(getCycle()+1)%2] = (id794x_1);
  }
  { // Node ID: 1849 (NodeConstantRawBits)
  }
  { // Node ID: 1547 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1547in_a = id785out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1547in_b = id1849out_value;

    id1547out_result[(getCycle()+1)%2] = (lte_fixed(id1547in_a,id1547in_b));
  }
  { // Node ID: 2240 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2240in_input = id1547out_result[getCycle()%2];

    id2240out_output[(getCycle()+1)%2] = id2240in_input;
  }
  HWRawBits<2> id946out_result;

  { // Node ID: 946 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id946in_in0 = id794out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id946in_in1 = id2240out_output[getCycle()%2];

    id946out_result = (cat(id946in_in0,id946in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id947out_output;

  { // Node ID: 947 (NodeReinterpret)
    const HWRawBits<2> &id947in_input = id946out_result;

    id947out_output = (cast_bits2fixed<2,0,UNSIGNED>(id947in_input));
  }
  { // Node ID: 2266 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2266in_input = id947out_output;

    id2266out_output[(getCycle()+5)%6] = id2266in_input;
  }
  { // Node ID: 1848 (NodeConstantRawBits)
  }
  { // Node ID: 1847 (NodeConstantRawBits)
  }
  { // Node ID: 805 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id805in_a = id1847out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id805in_b = id785out_result[getCycle()%2];

    id805out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id805in_a,id805in_b));
  }
  { // Node ID: 1548 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1548in_a = id1848out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1548in_b = id805out_result[getCycle()%2];

    id1548out_result[(getCycle()+1)%2] = (lt_fixed(id1548in_a,id1548in_b));
  }
  { // Node ID: 941 (NodeConstantRawBits)
  }
  HWRawBits<1> id1743out_result;

  { // Node ID: 1743 (NodeSlice)
    const HWFloat<8,24> &id1743in_a = id2239out_output[getCycle()%4];

    id1743out_result = (slice<22,1>(id1743in_a));
  }
  { // Node ID: 942 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id942in_sel = id1548out_result[getCycle()%2];
    const HWRawBits<1> &id942in_option0 = id941out_value;
    const HWRawBits<1> &id942in_option1 = id1743out_result;

    HWRawBits<1> id942x_1;

    switch((id942in_sel.getValueAsLong())) {
      case 0l:
        id942x_1 = id942in_option0;
        break;
      case 1l:
        id942x_1 = id942in_option1;
        break;
      default:
        id942x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id942out_result[(getCycle()+1)%2] = (id942x_1);
  }
  { // Node ID: 1846 (NodeConstantRawBits)
  }
  { // Node ID: 1550 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1550in_a = id1846out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1550in_b = id805out_result[getCycle()%2];

    id1550out_result[(getCycle()+1)%2] = (lt_fixed(id1550in_a,id1550in_b));
  }
  { // Node ID: 935 (NodeConstantRawBits)
  }
  HWRawBits<1> id1744out_result;

  { // Node ID: 1744 (NodeSlice)
    const HWFloat<8,24> &id1744in_a = id2239out_output[getCycle()%4];

    id1744out_result = (slice<21,1>(id1744in_a));
  }
  { // Node ID: 936 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id936in_sel = id1550out_result[getCycle()%2];
    const HWRawBits<1> &id936in_option0 = id935out_value;
    const HWRawBits<1> &id936in_option1 = id1744out_result;

    HWRawBits<1> id936x_1;

    switch((id936in_sel.getValueAsLong())) {
      case 0l:
        id936x_1 = id936in_option0;
        break;
      case 1l:
        id936x_1 = id936in_option1;
        break;
      default:
        id936x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id936out_result[(getCycle()+1)%2] = (id936x_1);
  }
  { // Node ID: 1845 (NodeConstantRawBits)
  }
  { // Node ID: 1552 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1552in_a = id1845out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1552in_b = id805out_result[getCycle()%2];

    id1552out_result[(getCycle()+1)%2] = (lt_fixed(id1552in_a,id1552in_b));
  }
  { // Node ID: 929 (NodeConstantRawBits)
  }
  HWRawBits<1> id1745out_result;

  { // Node ID: 1745 (NodeSlice)
    const HWFloat<8,24> &id1745in_a = id2239out_output[getCycle()%4];

    id1745out_result = (slice<20,1>(id1745in_a));
  }
  { // Node ID: 930 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id930in_sel = id1552out_result[getCycle()%2];
    const HWRawBits<1> &id930in_option0 = id929out_value;
    const HWRawBits<1> &id930in_option1 = id1745out_result;

    HWRawBits<1> id930x_1;

    switch((id930in_sel.getValueAsLong())) {
      case 0l:
        id930x_1 = id930in_option0;
        break;
      case 1l:
        id930x_1 = id930in_option1;
        break;
      default:
        id930x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id930out_result[(getCycle()+1)%2] = (id930x_1);
  }
  { // Node ID: 1844 (NodeConstantRawBits)
  }
  { // Node ID: 1554 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1554in_a = id1844out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1554in_b = id805out_result[getCycle()%2];

    id1554out_result[(getCycle()+1)%2] = (lt_fixed(id1554in_a,id1554in_b));
  }
  { // Node ID: 923 (NodeConstantRawBits)
  }
  HWRawBits<1> id1746out_result;

  { // Node ID: 1746 (NodeSlice)
    const HWFloat<8,24> &id1746in_a = id2239out_output[getCycle()%4];

    id1746out_result = (slice<19,1>(id1746in_a));
  }
  { // Node ID: 924 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id924in_sel = id1554out_result[getCycle()%2];
    const HWRawBits<1> &id924in_option0 = id923out_value;
    const HWRawBits<1> &id924in_option1 = id1746out_result;

    HWRawBits<1> id924x_1;

    switch((id924in_sel.getValueAsLong())) {
      case 0l:
        id924x_1 = id924in_option0;
        break;
      case 1l:
        id924x_1 = id924in_option1;
        break;
      default:
        id924x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id924out_result[(getCycle()+1)%2] = (id924x_1);
  }
  { // Node ID: 1843 (NodeConstantRawBits)
  }
  { // Node ID: 1556 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1556in_a = id1843out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1556in_b = id805out_result[getCycle()%2];

    id1556out_result[(getCycle()+1)%2] = (lt_fixed(id1556in_a,id1556in_b));
  }
  { // Node ID: 917 (NodeConstantRawBits)
  }
  HWRawBits<1> id1747out_result;

  { // Node ID: 1747 (NodeSlice)
    const HWFloat<8,24> &id1747in_a = id2239out_output[getCycle()%4];

    id1747out_result = (slice<18,1>(id1747in_a));
  }
  { // Node ID: 918 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id918in_sel = id1556out_result[getCycle()%2];
    const HWRawBits<1> &id918in_option0 = id917out_value;
    const HWRawBits<1> &id918in_option1 = id1747out_result;

    HWRawBits<1> id918x_1;

    switch((id918in_sel.getValueAsLong())) {
      case 0l:
        id918x_1 = id918in_option0;
        break;
      case 1l:
        id918x_1 = id918in_option1;
        break;
      default:
        id918x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id918out_result[(getCycle()+1)%2] = (id918x_1);
  }
  { // Node ID: 1842 (NodeConstantRawBits)
  }
  { // Node ID: 1558 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1558in_a = id1842out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1558in_b = id805out_result[getCycle()%2];

    id1558out_result[(getCycle()+1)%2] = (lt_fixed(id1558in_a,id1558in_b));
  }
  { // Node ID: 911 (NodeConstantRawBits)
  }
  HWRawBits<1> id1748out_result;

  { // Node ID: 1748 (NodeSlice)
    const HWFloat<8,24> &id1748in_a = id2239out_output[getCycle()%4];

    id1748out_result = (slice<17,1>(id1748in_a));
  }
  { // Node ID: 912 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id912in_sel = id1558out_result[getCycle()%2];
    const HWRawBits<1> &id912in_option0 = id911out_value;
    const HWRawBits<1> &id912in_option1 = id1748out_result;

    HWRawBits<1> id912x_1;

    switch((id912in_sel.getValueAsLong())) {
      case 0l:
        id912x_1 = id912in_option0;
        break;
      case 1l:
        id912x_1 = id912in_option1;
        break;
      default:
        id912x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id912out_result[(getCycle()+1)%2] = (id912x_1);
  }
  { // Node ID: 1841 (NodeConstantRawBits)
  }
  { // Node ID: 1560 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1560in_a = id1841out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1560in_b = id805out_result[getCycle()%2];

    id1560out_result[(getCycle()+1)%2] = (lt_fixed(id1560in_a,id1560in_b));
  }
  { // Node ID: 905 (NodeConstantRawBits)
  }
  HWRawBits<1> id1749out_result;

  { // Node ID: 1749 (NodeSlice)
    const HWFloat<8,24> &id1749in_a = id2239out_output[getCycle()%4];

    id1749out_result = (slice<16,1>(id1749in_a));
  }
  { // Node ID: 906 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id906in_sel = id1560out_result[getCycle()%2];
    const HWRawBits<1> &id906in_option0 = id905out_value;
    const HWRawBits<1> &id906in_option1 = id1749out_result;

    HWRawBits<1> id906x_1;

    switch((id906in_sel.getValueAsLong())) {
      case 0l:
        id906x_1 = id906in_option0;
        break;
      case 1l:
        id906x_1 = id906in_option1;
        break;
      default:
        id906x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id906out_result[(getCycle()+1)%2] = (id906x_1);
  }
  { // Node ID: 1840 (NodeConstantRawBits)
  }
  { // Node ID: 1562 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1562in_a = id1840out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1562in_b = id805out_result[getCycle()%2];

    id1562out_result[(getCycle()+1)%2] = (lt_fixed(id1562in_a,id1562in_b));
  }
  { // Node ID: 899 (NodeConstantRawBits)
  }
  HWRawBits<1> id1750out_result;

  { // Node ID: 1750 (NodeSlice)
    const HWFloat<8,24> &id1750in_a = id2239out_output[getCycle()%4];

    id1750out_result = (slice<15,1>(id1750in_a));
  }
  { // Node ID: 900 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id900in_sel = id1562out_result[getCycle()%2];
    const HWRawBits<1> &id900in_option0 = id899out_value;
    const HWRawBits<1> &id900in_option1 = id1750out_result;

    HWRawBits<1> id900x_1;

    switch((id900in_sel.getValueAsLong())) {
      case 0l:
        id900x_1 = id900in_option0;
        break;
      case 1l:
        id900x_1 = id900in_option1;
        break;
      default:
        id900x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id900out_result[(getCycle()+1)%2] = (id900x_1);
  }
  { // Node ID: 1839 (NodeConstantRawBits)
  }
  { // Node ID: 1564 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1564in_a = id1839out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1564in_b = id805out_result[getCycle()%2];

    id1564out_result[(getCycle()+1)%2] = (lt_fixed(id1564in_a,id1564in_b));
  }
  { // Node ID: 893 (NodeConstantRawBits)
  }
  HWRawBits<1> id1751out_result;

  { // Node ID: 1751 (NodeSlice)
    const HWFloat<8,24> &id1751in_a = id2239out_output[getCycle()%4];

    id1751out_result = (slice<14,1>(id1751in_a));
  }
  { // Node ID: 894 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id894in_sel = id1564out_result[getCycle()%2];
    const HWRawBits<1> &id894in_option0 = id893out_value;
    const HWRawBits<1> &id894in_option1 = id1751out_result;

    HWRawBits<1> id894x_1;

    switch((id894in_sel.getValueAsLong())) {
      case 0l:
        id894x_1 = id894in_option0;
        break;
      case 1l:
        id894x_1 = id894in_option1;
        break;
      default:
        id894x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id894out_result[(getCycle()+1)%2] = (id894x_1);
  }
  { // Node ID: 1838 (NodeConstantRawBits)
  }
  { // Node ID: 1566 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1566in_a = id1838out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1566in_b = id805out_result[getCycle()%2];

    id1566out_result[(getCycle()+1)%2] = (lt_fixed(id1566in_a,id1566in_b));
  }
  { // Node ID: 887 (NodeConstantRawBits)
  }
  HWRawBits<1> id1752out_result;

  { // Node ID: 1752 (NodeSlice)
    const HWFloat<8,24> &id1752in_a = id2239out_output[getCycle()%4];

    id1752out_result = (slice<13,1>(id1752in_a));
  }
  { // Node ID: 888 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id888in_sel = id1566out_result[getCycle()%2];
    const HWRawBits<1> &id888in_option0 = id887out_value;
    const HWRawBits<1> &id888in_option1 = id1752out_result;

    HWRawBits<1> id888x_1;

    switch((id888in_sel.getValueAsLong())) {
      case 0l:
        id888x_1 = id888in_option0;
        break;
      case 1l:
        id888x_1 = id888in_option1;
        break;
      default:
        id888x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id888out_result[(getCycle()+1)%2] = (id888x_1);
  }
  { // Node ID: 1837 (NodeConstantRawBits)
  }
  { // Node ID: 1568 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1568in_a = id1837out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1568in_b = id805out_result[getCycle()%2];

    id1568out_result[(getCycle()+1)%2] = (lt_fixed(id1568in_a,id1568in_b));
  }
  { // Node ID: 881 (NodeConstantRawBits)
  }
  HWRawBits<1> id1753out_result;

  { // Node ID: 1753 (NodeSlice)
    const HWFloat<8,24> &id1753in_a = id2239out_output[getCycle()%4];

    id1753out_result = (slice<12,1>(id1753in_a));
  }
  { // Node ID: 882 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id882in_sel = id1568out_result[getCycle()%2];
    const HWRawBits<1> &id882in_option0 = id881out_value;
    const HWRawBits<1> &id882in_option1 = id1753out_result;

    HWRawBits<1> id882x_1;

    switch((id882in_sel.getValueAsLong())) {
      case 0l:
        id882x_1 = id882in_option0;
        break;
      case 1l:
        id882x_1 = id882in_option1;
        break;
      default:
        id882x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id882out_result[(getCycle()+1)%2] = (id882x_1);
  }
  { // Node ID: 1836 (NodeConstantRawBits)
  }
  { // Node ID: 1570 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1570in_a = id1836out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1570in_b = id805out_result[getCycle()%2];

    id1570out_result[(getCycle()+1)%2] = (lt_fixed(id1570in_a,id1570in_b));
  }
  { // Node ID: 875 (NodeConstantRawBits)
  }
  HWRawBits<1> id1754out_result;

  { // Node ID: 1754 (NodeSlice)
    const HWFloat<8,24> &id1754in_a = id2239out_output[getCycle()%4];

    id1754out_result = (slice<11,1>(id1754in_a));
  }
  { // Node ID: 876 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id876in_sel = id1570out_result[getCycle()%2];
    const HWRawBits<1> &id876in_option0 = id875out_value;
    const HWRawBits<1> &id876in_option1 = id1754out_result;

    HWRawBits<1> id876x_1;

    switch((id876in_sel.getValueAsLong())) {
      case 0l:
        id876x_1 = id876in_option0;
        break;
      case 1l:
        id876x_1 = id876in_option1;
        break;
      default:
        id876x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id876out_result[(getCycle()+1)%2] = (id876x_1);
  }
  { // Node ID: 1835 (NodeConstantRawBits)
  }
  { // Node ID: 1572 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1572in_a = id1835out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1572in_b = id805out_result[getCycle()%2];

    id1572out_result[(getCycle()+1)%2] = (lt_fixed(id1572in_a,id1572in_b));
  }
  { // Node ID: 869 (NodeConstantRawBits)
  }
  HWRawBits<1> id1755out_result;

  { // Node ID: 1755 (NodeSlice)
    const HWFloat<8,24> &id1755in_a = id2239out_output[getCycle()%4];

    id1755out_result = (slice<10,1>(id1755in_a));
  }
  { // Node ID: 870 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id870in_sel = id1572out_result[getCycle()%2];
    const HWRawBits<1> &id870in_option0 = id869out_value;
    const HWRawBits<1> &id870in_option1 = id1755out_result;

    HWRawBits<1> id870x_1;

    switch((id870in_sel.getValueAsLong())) {
      case 0l:
        id870x_1 = id870in_option0;
        break;
      case 1l:
        id870x_1 = id870in_option1;
        break;
      default:
        id870x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id870out_result[(getCycle()+1)%2] = (id870x_1);
  }
  { // Node ID: 1834 (NodeConstantRawBits)
  }
  { // Node ID: 1574 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1574in_a = id1834out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1574in_b = id805out_result[getCycle()%2];

    id1574out_result[(getCycle()+1)%2] = (lt_fixed(id1574in_a,id1574in_b));
  }
  { // Node ID: 863 (NodeConstantRawBits)
  }
  HWRawBits<1> id1756out_result;

  { // Node ID: 1756 (NodeSlice)
    const HWFloat<8,24> &id1756in_a = id2239out_output[getCycle()%4];

    id1756out_result = (slice<9,1>(id1756in_a));
  }
  { // Node ID: 864 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id864in_sel = id1574out_result[getCycle()%2];
    const HWRawBits<1> &id864in_option0 = id863out_value;
    const HWRawBits<1> &id864in_option1 = id1756out_result;

    HWRawBits<1> id864x_1;

    switch((id864in_sel.getValueAsLong())) {
      case 0l:
        id864x_1 = id864in_option0;
        break;
      case 1l:
        id864x_1 = id864in_option1;
        break;
      default:
        id864x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id864out_result[(getCycle()+1)%2] = (id864x_1);
  }
  { // Node ID: 1833 (NodeConstantRawBits)
  }
  { // Node ID: 1576 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1576in_a = id1833out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1576in_b = id805out_result[getCycle()%2];

    id1576out_result[(getCycle()+1)%2] = (lt_fixed(id1576in_a,id1576in_b));
  }
  { // Node ID: 857 (NodeConstantRawBits)
  }
  HWRawBits<1> id1757out_result;

  { // Node ID: 1757 (NodeSlice)
    const HWFloat<8,24> &id1757in_a = id2239out_output[getCycle()%4];

    id1757out_result = (slice<8,1>(id1757in_a));
  }
  { // Node ID: 858 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id858in_sel = id1576out_result[getCycle()%2];
    const HWRawBits<1> &id858in_option0 = id857out_value;
    const HWRawBits<1> &id858in_option1 = id1757out_result;

    HWRawBits<1> id858x_1;

    switch((id858in_sel.getValueAsLong())) {
      case 0l:
        id858x_1 = id858in_option0;
        break;
      case 1l:
        id858x_1 = id858in_option1;
        break;
      default:
        id858x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id858out_result[(getCycle()+1)%2] = (id858x_1);
  }
  { // Node ID: 1832 (NodeConstantRawBits)
  }
  { // Node ID: 1578 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1578in_a = id1832out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1578in_b = id805out_result[getCycle()%2];

    id1578out_result[(getCycle()+1)%2] = (lt_fixed(id1578in_a,id1578in_b));
  }
  { // Node ID: 851 (NodeConstantRawBits)
  }
  HWRawBits<1> id1758out_result;

  { // Node ID: 1758 (NodeSlice)
    const HWFloat<8,24> &id1758in_a = id2239out_output[getCycle()%4];

    id1758out_result = (slice<7,1>(id1758in_a));
  }
  { // Node ID: 852 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id852in_sel = id1578out_result[getCycle()%2];
    const HWRawBits<1> &id852in_option0 = id851out_value;
    const HWRawBits<1> &id852in_option1 = id1758out_result;

    HWRawBits<1> id852x_1;

    switch((id852in_sel.getValueAsLong())) {
      case 0l:
        id852x_1 = id852in_option0;
        break;
      case 1l:
        id852x_1 = id852in_option1;
        break;
      default:
        id852x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id852out_result[(getCycle()+1)%2] = (id852x_1);
  }
  { // Node ID: 1831 (NodeConstantRawBits)
  }
  { // Node ID: 1580 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1580in_a = id1831out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1580in_b = id805out_result[getCycle()%2];

    id1580out_result[(getCycle()+1)%2] = (lt_fixed(id1580in_a,id1580in_b));
  }
  { // Node ID: 845 (NodeConstantRawBits)
  }
  HWRawBits<1> id1759out_result;

  { // Node ID: 1759 (NodeSlice)
    const HWFloat<8,24> &id1759in_a = id2239out_output[getCycle()%4];

    id1759out_result = (slice<6,1>(id1759in_a));
  }
  { // Node ID: 846 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id846in_sel = id1580out_result[getCycle()%2];
    const HWRawBits<1> &id846in_option0 = id845out_value;
    const HWRawBits<1> &id846in_option1 = id1759out_result;

    HWRawBits<1> id846x_1;

    switch((id846in_sel.getValueAsLong())) {
      case 0l:
        id846x_1 = id846in_option0;
        break;
      case 1l:
        id846x_1 = id846in_option1;
        break;
      default:
        id846x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id846out_result[(getCycle()+1)%2] = (id846x_1);
  }
  { // Node ID: 1830 (NodeConstantRawBits)
  }
  { // Node ID: 1582 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1582in_a = id1830out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1582in_b = id805out_result[getCycle()%2];

    id1582out_result[(getCycle()+1)%2] = (lt_fixed(id1582in_a,id1582in_b));
  }
  { // Node ID: 839 (NodeConstantRawBits)
  }
  HWRawBits<1> id1760out_result;

  { // Node ID: 1760 (NodeSlice)
    const HWFloat<8,24> &id1760in_a = id2239out_output[getCycle()%4];

    id1760out_result = (slice<5,1>(id1760in_a));
  }
  { // Node ID: 840 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id840in_sel = id1582out_result[getCycle()%2];
    const HWRawBits<1> &id840in_option0 = id839out_value;
    const HWRawBits<1> &id840in_option1 = id1760out_result;

    HWRawBits<1> id840x_1;

    switch((id840in_sel.getValueAsLong())) {
      case 0l:
        id840x_1 = id840in_option0;
        break;
      case 1l:
        id840x_1 = id840in_option1;
        break;
      default:
        id840x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id840out_result[(getCycle()+1)%2] = (id840x_1);
  }
  { // Node ID: 1829 (NodeConstantRawBits)
  }
  { // Node ID: 1584 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1584in_a = id1829out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1584in_b = id805out_result[getCycle()%2];

    id1584out_result[(getCycle()+1)%2] = (lt_fixed(id1584in_a,id1584in_b));
  }
  { // Node ID: 833 (NodeConstantRawBits)
  }
  HWRawBits<1> id1761out_result;

  { // Node ID: 1761 (NodeSlice)
    const HWFloat<8,24> &id1761in_a = id2239out_output[getCycle()%4];

    id1761out_result = (slice<4,1>(id1761in_a));
  }
  { // Node ID: 834 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id834in_sel = id1584out_result[getCycle()%2];
    const HWRawBits<1> &id834in_option0 = id833out_value;
    const HWRawBits<1> &id834in_option1 = id1761out_result;

    HWRawBits<1> id834x_1;

    switch((id834in_sel.getValueAsLong())) {
      case 0l:
        id834x_1 = id834in_option0;
        break;
      case 1l:
        id834x_1 = id834in_option1;
        break;
      default:
        id834x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id834out_result[(getCycle()+1)%2] = (id834x_1);
  }
  { // Node ID: 1828 (NodeConstantRawBits)
  }
  { // Node ID: 1586 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1586in_a = id1828out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1586in_b = id805out_result[getCycle()%2];

    id1586out_result[(getCycle()+1)%2] = (lt_fixed(id1586in_a,id1586in_b));
  }
  { // Node ID: 827 (NodeConstantRawBits)
  }
  HWRawBits<1> id1762out_result;

  { // Node ID: 1762 (NodeSlice)
    const HWFloat<8,24> &id1762in_a = id2239out_output[getCycle()%4];

    id1762out_result = (slice<3,1>(id1762in_a));
  }
  { // Node ID: 828 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id828in_sel = id1586out_result[getCycle()%2];
    const HWRawBits<1> &id828in_option0 = id827out_value;
    const HWRawBits<1> &id828in_option1 = id1762out_result;

    HWRawBits<1> id828x_1;

    switch((id828in_sel.getValueAsLong())) {
      case 0l:
        id828x_1 = id828in_option0;
        break;
      case 1l:
        id828x_1 = id828in_option1;
        break;
      default:
        id828x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id828out_result[(getCycle()+1)%2] = (id828x_1);
  }
  { // Node ID: 1827 (NodeConstantRawBits)
  }
  { // Node ID: 1588 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1588in_a = id1827out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1588in_b = id805out_result[getCycle()%2];

    id1588out_result[(getCycle()+1)%2] = (lt_fixed(id1588in_a,id1588in_b));
  }
  { // Node ID: 821 (NodeConstantRawBits)
  }
  HWRawBits<1> id1763out_result;

  { // Node ID: 1763 (NodeSlice)
    const HWFloat<8,24> &id1763in_a = id2239out_output[getCycle()%4];

    id1763out_result = (slice<2,1>(id1763in_a));
  }
  { // Node ID: 822 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id822in_sel = id1588out_result[getCycle()%2];
    const HWRawBits<1> &id822in_option0 = id821out_value;
    const HWRawBits<1> &id822in_option1 = id1763out_result;

    HWRawBits<1> id822x_1;

    switch((id822in_sel.getValueAsLong())) {
      case 0l:
        id822x_1 = id822in_option0;
        break;
      case 1l:
        id822x_1 = id822in_option1;
        break;
      default:
        id822x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id822out_result[(getCycle()+1)%2] = (id822x_1);
  }
  { // Node ID: 1826 (NodeConstantRawBits)
  }
  { // Node ID: 1590 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1590in_a = id1826out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1590in_b = id805out_result[getCycle()%2];

    id1590out_result[(getCycle()+1)%2] = (lt_fixed(id1590in_a,id1590in_b));
  }
  { // Node ID: 815 (NodeConstantRawBits)
  }
  HWRawBits<1> id1764out_result;

  { // Node ID: 1764 (NodeSlice)
    const HWFloat<8,24> &id1764in_a = id2239out_output[getCycle()%4];

    id1764out_result = (slice<1,1>(id1764in_a));
  }
  { // Node ID: 816 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id816in_sel = id1590out_result[getCycle()%2];
    const HWRawBits<1> &id816in_option0 = id815out_value;
    const HWRawBits<1> &id816in_option1 = id1764out_result;

    HWRawBits<1> id816x_1;

    switch((id816in_sel.getValueAsLong())) {
      case 0l:
        id816x_1 = id816in_option0;
        break;
      case 1l:
        id816x_1 = id816in_option1;
        break;
      default:
        id816x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id816out_result[(getCycle()+1)%2] = (id816x_1);
  }
  { // Node ID: 1825 (NodeConstantRawBits)
  }
  { // Node ID: 1592 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1592in_a = id1825out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1592in_b = id805out_result[getCycle()%2];

    id1592out_result[(getCycle()+1)%2] = (lt_fixed(id1592in_a,id1592in_b));
  }
  { // Node ID: 809 (NodeConstantRawBits)
  }
  HWRawBits<1> id1765out_result;

  { // Node ID: 1765 (NodeSlice)
    const HWFloat<8,24> &id1765in_a = id2239out_output[getCycle()%4];

    id1765out_result = (slice<0,1>(id1765in_a));
  }
  { // Node ID: 810 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id810in_sel = id1592out_result[getCycle()%2];
    const HWRawBits<1> &id810in_option0 = id809out_value;
    const HWRawBits<1> &id810in_option1 = id1765out_result;

    HWRawBits<1> id810x_1;

    switch((id810in_sel.getValueAsLong())) {
      case 0l:
        id810x_1 = id810in_option0;
        break;
      case 1l:
        id810x_1 = id810in_option1;
        break;
      default:
        id810x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id810out_result[(getCycle()+1)%2] = (id810x_1);
  }
  { // Node ID: 803 (NodeConstantRawBits)
  }
  HWRawBits<24> id1615out_result;

  { // Node ID: 1615 (NodeCat)
    const HWRawBits<1> &id1615in_in0 = id942out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in1 = id936out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in2 = id930out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in3 = id924out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in4 = id918out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in5 = id912out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in6 = id906out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in7 = id900out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in8 = id894out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in9 = id888out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in10 = id882out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in11 = id876out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in12 = id870out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in13 = id864out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in14 = id858out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in15 = id852out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in16 = id846out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in17 = id840out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in18 = id834out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in19 = id828out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in20 = id822out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in21 = id816out_result[getCycle()%2];
    const HWRawBits<1> &id1615in_in22 = id810out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1615in_in23 = id803out_value;

    id1615out_result = (cat((cat((cat((cat((cat(id1615in_in0,id1615in_in1)),id1615in_in2)),(cat((cat(id1615in_in3,id1615in_in4)),id1615in_in5)))),(cat((cat((cat(id1615in_in6,id1615in_in7)),id1615in_in8)),(cat((cat(id1615in_in9,id1615in_in10)),id1615in_in11)))))),(cat((cat((cat((cat(id1615in_in12,id1615in_in13)),id1615in_in14)),(cat((cat(id1615in_in15,id1615in_in16)),id1615in_in17)))),(cat((cat((cat(id1615in_in18,id1615in_in19)),id1615in_in20)),(cat((cat(id1615in_in21,id1615in_in22)),id1615in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id944out_o;

  { // Node ID: 944 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id944in_i = id785out_result[getCycle()%2];

    id944out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id944in_i));
  }
  { // Node ID: 2264 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2264in_input = id944out_o;

    id2264out_output[(getCycle()+3)%4] = id2264in_input;
  }
  { // Node ID: 945 (NodeShift)
    const HWRawBits<24> &id945in_datain = id1615out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id945in_shift = id2264out_output[getCycle()%4];

    id945out_dataout[(getCycle()+4)%5] = (shift_left_bits(id945in_datain,(id945in_shift.getValueAsLong())));
  }
  { // Node ID: 786 (NodeConstantRawBits)
  }
  HWRawBits<23> id787out_result;

  { // Node ID: 787 (NodeSlice)
    const HWFloat<8,24> &id787in_a = id2239out_output[getCycle()%4];

    id787out_result = (slice<0,23>(id787in_a));
  }
  HWRawBits<24> id788out_result;

  { // Node ID: 788 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id788in_in0 = id786out_value;
    const HWRawBits<23> &id788in_in1 = id787out_result;

    id788out_result = (cat(id788in_in0,id788in_in1));
  }
  { // Node ID: 798 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id798in_a = id785out_result[getCycle()%2];

    id798out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id798in_a));
  }
  { // Node ID: 1824 (NodeConstantRawBits)
  }
  { // Node ID: 800 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id800in_a = id798out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id800in_b = id1824out_value;

    id800out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id800in_a,id800in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id801out_o;

  { // Node ID: 801 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id801in_i = id800out_result[getCycle()%2];

    id801out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id801in_i));
  }
  { // Node ID: 802 (NodeShift)
    const HWRawBits<24> &id802in_datain = id788out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id802in_shift = id801out_o;

    id802out_dataout[(getCycle()+4)%5] = (shift_right_bits(id802in_datain,(id802in_shift.getValueAsLong())));
  }
  { // Node ID: 2267 (NodeFIFO)
    const HWRawBits<24> &id2267in_input = id802out_dataout[getCycle()%5];

    id2267out_output[(getCycle()+1)%2] = id2267in_input;
  }
  { // Node ID: 1823 (NodeConstantRawBits)
  }
  { // Node ID: 948 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id948in_sel = id2266out_output[getCycle()%6];
    const HWRawBits<24> &id948in_option0 = id945out_dataout[getCycle()%5];
    const HWRawBits<24> &id948in_option1 = id2267out_output[getCycle()%2];
    const HWRawBits<24> &id948in_option2 = id1823out_value;
    const HWRawBits<24> &id948in_option3 = id1823out_value;

    HWRawBits<24> id948x_1;

    switch((id948in_sel.getValueAsLong())) {
      case 0l:
        id948x_1 = id948in_option0;
        break;
      case 1l:
        id948x_1 = id948in_option1;
        break;
      case 2l:
        id948x_1 = id948in_option2;
        break;
      case 3l:
        id948x_1 = id948in_option3;
        break;
      default:
        id948x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id948out_result[(getCycle()+1)%2] = (id948x_1);
  }
  HWRawBits<24> id949out_result;

  { // Node ID: 949 (NodeNot)
    const HWRawBits<24> &id949in_a = id948out_result[getCycle()%2];

    id949out_result = (not_bits(id949in_a));
  }
  { // Node ID: 950 (NodeMux)
    const HWRawBits<1> &id950in_sel = id2268out_output[getCycle()%7];
    const HWRawBits<24> &id950in_option0 = id948out_result[getCycle()%2];
    const HWRawBits<24> &id950in_option1 = id949out_result;

    HWRawBits<24> id950x_1;

    switch((id950in_sel.getValueAsLong())) {
      case 0l:
        id950x_1 = id950in_option0;
        break;
      case 1l:
        id950x_1 = id950in_option1;
        break;
      default:
        id950x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id950out_result[(getCycle()+1)%2] = (id950x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id951out_output;

  { // Node ID: 951 (NodeReinterpret)
    const HWRawBits<24> &id951in_input = id950out_result[getCycle()%2];

    id951out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id951in_input));
  }
  { // Node ID: 952 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id952in_i = id951out_output;

    id952out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id952in_i));
  }
  { // Node ID: 1984 (NodePO2FPMult)
    const HWFloat<8,24> &id1984in_floatIn = id745out_result[getCycle()%2];

    id1984out_floatOut[(getCycle()+1)%2] = (mul_float(id1984in_floatIn,(c_hw_flt_8_24_128_0val)));
  }
  { // Node ID: 2269 (NodeFIFO)
    const HWFloat<8,24> &id2269in_input = id1984out_floatOut[getCycle()%2];

    id2269out_output[(getCycle()+3)%4] = id2269in_input;
  }
  HWRawBits<1> id990out_result;

  { // Node ID: 990 (NodeSlice)
    const HWFloat<8,24> &id990in_a = id2269out_output[getCycle()%4];

    id990out_result = (slice<31,1>(id990in_a));
  }
  { // Node ID: 2298 (NodeFIFO)
    const HWRawBits<1> &id2298in_input = id990out_result;

    id2298out_output[(getCycle()+6)%7] = id2298in_input;
  }
  HWRawBits<8> id983out_result;

  { // Node ID: 983 (NodeSlice)
    const HWFloat<8,24> &id983in_a = id1984out_floatOut[getCycle()%2];

    id983out_result = (slice<23,8>(id983in_a));
  }
  HWOffsetFix<8,0,UNSIGNED> id984out_output;

  { // Node ID: 984 (NodeReinterpret)
    const HWRawBits<8> &id984in_input = id983out_result;

    id984out_output = (cast_bits2fixed<8,0,UNSIGNED>(id984in_input));
  }
  { // Node ID: 1821 (NodeConstantRawBits)
  }
  { // Node ID: 986 (NodeSub)
    const HWOffsetFix<8,0,UNSIGNED> &id986in_a = id984out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id986in_b = id1821out_value;

    id986out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id986in_a,id986in_b));
  }
  { // Node ID: 1820 (NodeConstantRawBits)
  }
  { // Node ID: 1616 (NodeGteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1616in_a = id986out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1616in_b = id1820out_value;

    id1616out_result[(getCycle()+1)%2] = (gte_fixed(id1616in_a,id1616in_b));
  }
  { // Node ID: 1819 (NodeConstantRawBits)
  }
  { // Node ID: 1617 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1617in_a = id986out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1617in_b = id1819out_value;

    id1617out_result[(getCycle()+1)%2] = (lte_fixed(id1617in_a,id1617in_b));
  }
  { // Node ID: 995 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id995in_a = id1616out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id995in_b = id1617out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id995x_1;

    (id995x_1) = (or_fixed(id995in_a,id995in_b));
    id995out_result[(getCycle()+1)%2] = (id995x_1);
  }
  { // Node ID: 1818 (NodeConstantRawBits)
  }
  { // Node ID: 1618 (NodeLteInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1618in_a = id986out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1618in_b = id1818out_value;

    id1618out_result[(getCycle()+1)%2] = (lte_fixed(id1618in_a,id1618in_b));
  }
  { // Node ID: 2270 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2270in_input = id1618out_result[getCycle()%2];

    id2270out_output[(getCycle()+1)%2] = id2270in_input;
  }
  HWRawBits<2> id1147out_result;

  { // Node ID: 1147 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id1147in_in0 = id995out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1147in_in1 = id2270out_output[getCycle()%2];

    id1147out_result = (cat(id1147in_in0,id1147in_in1));
  }
  HWOffsetFix<2,0,UNSIGNED> id1148out_output;

  { // Node ID: 1148 (NodeReinterpret)
    const HWRawBits<2> &id1148in_input = id1147out_result;

    id1148out_output = (cast_bits2fixed<2,0,UNSIGNED>(id1148in_input));
  }
  { // Node ID: 2296 (NodeFIFO)
    const HWOffsetFix<2,0,UNSIGNED> &id2296in_input = id1148out_output;

    id2296out_output[(getCycle()+5)%6] = id2296in_input;
  }
  { // Node ID: 1817 (NodeConstantRawBits)
  }
  { // Node ID: 1816 (NodeConstantRawBits)
  }
  { // Node ID: 1006 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1006in_a = id1816out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1006in_b = id986out_result[getCycle()%2];

    id1006out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1006in_a,id1006in_b));
  }
  { // Node ID: 1619 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1619in_a = id1817out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1619in_b = id1006out_result[getCycle()%2];

    id1619out_result[(getCycle()+1)%2] = (lt_fixed(id1619in_a,id1619in_b));
  }
  { // Node ID: 1142 (NodeConstantRawBits)
  }
  HWRawBits<1> id1766out_result;

  { // Node ID: 1766 (NodeSlice)
    const HWFloat<8,24> &id1766in_a = id2269out_output[getCycle()%4];

    id1766out_result = (slice<22,1>(id1766in_a));
  }
  { // Node ID: 1143 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1143in_sel = id1619out_result[getCycle()%2];
    const HWRawBits<1> &id1143in_option0 = id1142out_value;
    const HWRawBits<1> &id1143in_option1 = id1766out_result;

    HWRawBits<1> id1143x_1;

    switch((id1143in_sel.getValueAsLong())) {
      case 0l:
        id1143x_1 = id1143in_option0;
        break;
      case 1l:
        id1143x_1 = id1143in_option1;
        break;
      default:
        id1143x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1143out_result[(getCycle()+1)%2] = (id1143x_1);
  }
  { // Node ID: 1815 (NodeConstantRawBits)
  }
  { // Node ID: 1621 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1621in_a = id1815out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1621in_b = id1006out_result[getCycle()%2];

    id1621out_result[(getCycle()+1)%2] = (lt_fixed(id1621in_a,id1621in_b));
  }
  { // Node ID: 1136 (NodeConstantRawBits)
  }
  HWRawBits<1> id1767out_result;

  { // Node ID: 1767 (NodeSlice)
    const HWFloat<8,24> &id1767in_a = id2269out_output[getCycle()%4];

    id1767out_result = (slice<21,1>(id1767in_a));
  }
  { // Node ID: 1137 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1137in_sel = id1621out_result[getCycle()%2];
    const HWRawBits<1> &id1137in_option0 = id1136out_value;
    const HWRawBits<1> &id1137in_option1 = id1767out_result;

    HWRawBits<1> id1137x_1;

    switch((id1137in_sel.getValueAsLong())) {
      case 0l:
        id1137x_1 = id1137in_option0;
        break;
      case 1l:
        id1137x_1 = id1137in_option1;
        break;
      default:
        id1137x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1137out_result[(getCycle()+1)%2] = (id1137x_1);
  }
  { // Node ID: 1814 (NodeConstantRawBits)
  }
  { // Node ID: 1623 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1623in_a = id1814out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1623in_b = id1006out_result[getCycle()%2];

    id1623out_result[(getCycle()+1)%2] = (lt_fixed(id1623in_a,id1623in_b));
  }
  { // Node ID: 1130 (NodeConstantRawBits)
  }
  HWRawBits<1> id1768out_result;

  { // Node ID: 1768 (NodeSlice)
    const HWFloat<8,24> &id1768in_a = id2269out_output[getCycle()%4];

    id1768out_result = (slice<20,1>(id1768in_a));
  }
  { // Node ID: 1131 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1131in_sel = id1623out_result[getCycle()%2];
    const HWRawBits<1> &id1131in_option0 = id1130out_value;
    const HWRawBits<1> &id1131in_option1 = id1768out_result;

    HWRawBits<1> id1131x_1;

    switch((id1131in_sel.getValueAsLong())) {
      case 0l:
        id1131x_1 = id1131in_option0;
        break;
      case 1l:
        id1131x_1 = id1131in_option1;
        break;
      default:
        id1131x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1131out_result[(getCycle()+1)%2] = (id1131x_1);
  }
  { // Node ID: 1813 (NodeConstantRawBits)
  }
  { // Node ID: 1625 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1625in_a = id1813out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1625in_b = id1006out_result[getCycle()%2];

    id1625out_result[(getCycle()+1)%2] = (lt_fixed(id1625in_a,id1625in_b));
  }
  { // Node ID: 1124 (NodeConstantRawBits)
  }
  HWRawBits<1> id1769out_result;

  { // Node ID: 1769 (NodeSlice)
    const HWFloat<8,24> &id1769in_a = id2269out_output[getCycle()%4];

    id1769out_result = (slice<19,1>(id1769in_a));
  }
  { // Node ID: 1125 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1125in_sel = id1625out_result[getCycle()%2];
    const HWRawBits<1> &id1125in_option0 = id1124out_value;
    const HWRawBits<1> &id1125in_option1 = id1769out_result;

    HWRawBits<1> id1125x_1;

    switch((id1125in_sel.getValueAsLong())) {
      case 0l:
        id1125x_1 = id1125in_option0;
        break;
      case 1l:
        id1125x_1 = id1125in_option1;
        break;
      default:
        id1125x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1125out_result[(getCycle()+1)%2] = (id1125x_1);
  }
  { // Node ID: 1812 (NodeConstantRawBits)
  }
  { // Node ID: 1627 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1627in_a = id1812out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1627in_b = id1006out_result[getCycle()%2];

    id1627out_result[(getCycle()+1)%2] = (lt_fixed(id1627in_a,id1627in_b));
  }
  { // Node ID: 1118 (NodeConstantRawBits)
  }
  HWRawBits<1> id1770out_result;

  { // Node ID: 1770 (NodeSlice)
    const HWFloat<8,24> &id1770in_a = id2269out_output[getCycle()%4];

    id1770out_result = (slice<18,1>(id1770in_a));
  }
  { // Node ID: 1119 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1119in_sel = id1627out_result[getCycle()%2];
    const HWRawBits<1> &id1119in_option0 = id1118out_value;
    const HWRawBits<1> &id1119in_option1 = id1770out_result;

    HWRawBits<1> id1119x_1;

    switch((id1119in_sel.getValueAsLong())) {
      case 0l:
        id1119x_1 = id1119in_option0;
        break;
      case 1l:
        id1119x_1 = id1119in_option1;
        break;
      default:
        id1119x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1119out_result[(getCycle()+1)%2] = (id1119x_1);
  }
  { // Node ID: 1811 (NodeConstantRawBits)
  }
  { // Node ID: 1629 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1629in_a = id1811out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1629in_b = id1006out_result[getCycle()%2];

    id1629out_result[(getCycle()+1)%2] = (lt_fixed(id1629in_a,id1629in_b));
  }
  { // Node ID: 1112 (NodeConstantRawBits)
  }
  HWRawBits<1> id1771out_result;

  { // Node ID: 1771 (NodeSlice)
    const HWFloat<8,24> &id1771in_a = id2269out_output[getCycle()%4];

    id1771out_result = (slice<17,1>(id1771in_a));
  }
  { // Node ID: 1113 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1113in_sel = id1629out_result[getCycle()%2];
    const HWRawBits<1> &id1113in_option0 = id1112out_value;
    const HWRawBits<1> &id1113in_option1 = id1771out_result;

    HWRawBits<1> id1113x_1;

    switch((id1113in_sel.getValueAsLong())) {
      case 0l:
        id1113x_1 = id1113in_option0;
        break;
      case 1l:
        id1113x_1 = id1113in_option1;
        break;
      default:
        id1113x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1113out_result[(getCycle()+1)%2] = (id1113x_1);
  }
  { // Node ID: 1810 (NodeConstantRawBits)
  }
  { // Node ID: 1631 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1631in_a = id1810out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1631in_b = id1006out_result[getCycle()%2];

    id1631out_result[(getCycle()+1)%2] = (lt_fixed(id1631in_a,id1631in_b));
  }
  { // Node ID: 1106 (NodeConstantRawBits)
  }
  HWRawBits<1> id1772out_result;

  { // Node ID: 1772 (NodeSlice)
    const HWFloat<8,24> &id1772in_a = id2269out_output[getCycle()%4];

    id1772out_result = (slice<16,1>(id1772in_a));
  }
  { // Node ID: 1107 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1107in_sel = id1631out_result[getCycle()%2];
    const HWRawBits<1> &id1107in_option0 = id1106out_value;
    const HWRawBits<1> &id1107in_option1 = id1772out_result;

    HWRawBits<1> id1107x_1;

    switch((id1107in_sel.getValueAsLong())) {
      case 0l:
        id1107x_1 = id1107in_option0;
        break;
      case 1l:
        id1107x_1 = id1107in_option1;
        break;
      default:
        id1107x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1107out_result[(getCycle()+1)%2] = (id1107x_1);
  }
  { // Node ID: 1809 (NodeConstantRawBits)
  }
  { // Node ID: 1633 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1633in_a = id1809out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1633in_b = id1006out_result[getCycle()%2];

    id1633out_result[(getCycle()+1)%2] = (lt_fixed(id1633in_a,id1633in_b));
  }
  { // Node ID: 1100 (NodeConstantRawBits)
  }
  HWRawBits<1> id1773out_result;

  { // Node ID: 1773 (NodeSlice)
    const HWFloat<8,24> &id1773in_a = id2269out_output[getCycle()%4];

    id1773out_result = (slice<15,1>(id1773in_a));
  }
  { // Node ID: 1101 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1101in_sel = id1633out_result[getCycle()%2];
    const HWRawBits<1> &id1101in_option0 = id1100out_value;
    const HWRawBits<1> &id1101in_option1 = id1773out_result;

    HWRawBits<1> id1101x_1;

    switch((id1101in_sel.getValueAsLong())) {
      case 0l:
        id1101x_1 = id1101in_option0;
        break;
      case 1l:
        id1101x_1 = id1101in_option1;
        break;
      default:
        id1101x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1101out_result[(getCycle()+1)%2] = (id1101x_1);
  }
  { // Node ID: 1808 (NodeConstantRawBits)
  }
  { // Node ID: 1635 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1635in_a = id1808out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1635in_b = id1006out_result[getCycle()%2];

    id1635out_result[(getCycle()+1)%2] = (lt_fixed(id1635in_a,id1635in_b));
  }
  { // Node ID: 1094 (NodeConstantRawBits)
  }
  HWRawBits<1> id1774out_result;

  { // Node ID: 1774 (NodeSlice)
    const HWFloat<8,24> &id1774in_a = id2269out_output[getCycle()%4];

    id1774out_result = (slice<14,1>(id1774in_a));
  }
  { // Node ID: 1095 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1095in_sel = id1635out_result[getCycle()%2];
    const HWRawBits<1> &id1095in_option0 = id1094out_value;
    const HWRawBits<1> &id1095in_option1 = id1774out_result;

    HWRawBits<1> id1095x_1;

    switch((id1095in_sel.getValueAsLong())) {
      case 0l:
        id1095x_1 = id1095in_option0;
        break;
      case 1l:
        id1095x_1 = id1095in_option1;
        break;
      default:
        id1095x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1095out_result[(getCycle()+1)%2] = (id1095x_1);
  }
  { // Node ID: 1807 (NodeConstantRawBits)
  }
  { // Node ID: 1637 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1637in_a = id1807out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1637in_b = id1006out_result[getCycle()%2];

    id1637out_result[(getCycle()+1)%2] = (lt_fixed(id1637in_a,id1637in_b));
  }
  { // Node ID: 1088 (NodeConstantRawBits)
  }
  HWRawBits<1> id1775out_result;

  { // Node ID: 1775 (NodeSlice)
    const HWFloat<8,24> &id1775in_a = id2269out_output[getCycle()%4];

    id1775out_result = (slice<13,1>(id1775in_a));
  }
  { // Node ID: 1089 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1089in_sel = id1637out_result[getCycle()%2];
    const HWRawBits<1> &id1089in_option0 = id1088out_value;
    const HWRawBits<1> &id1089in_option1 = id1775out_result;

    HWRawBits<1> id1089x_1;

    switch((id1089in_sel.getValueAsLong())) {
      case 0l:
        id1089x_1 = id1089in_option0;
        break;
      case 1l:
        id1089x_1 = id1089in_option1;
        break;
      default:
        id1089x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1089out_result[(getCycle()+1)%2] = (id1089x_1);
  }
  { // Node ID: 1806 (NodeConstantRawBits)
  }
  { // Node ID: 1639 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1639in_a = id1806out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1639in_b = id1006out_result[getCycle()%2];

    id1639out_result[(getCycle()+1)%2] = (lt_fixed(id1639in_a,id1639in_b));
  }
  { // Node ID: 1082 (NodeConstantRawBits)
  }
  HWRawBits<1> id1776out_result;

  { // Node ID: 1776 (NodeSlice)
    const HWFloat<8,24> &id1776in_a = id2269out_output[getCycle()%4];

    id1776out_result = (slice<12,1>(id1776in_a));
  }
  { // Node ID: 1083 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1083in_sel = id1639out_result[getCycle()%2];
    const HWRawBits<1> &id1083in_option0 = id1082out_value;
    const HWRawBits<1> &id1083in_option1 = id1776out_result;

    HWRawBits<1> id1083x_1;

    switch((id1083in_sel.getValueAsLong())) {
      case 0l:
        id1083x_1 = id1083in_option0;
        break;
      case 1l:
        id1083x_1 = id1083in_option1;
        break;
      default:
        id1083x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1083out_result[(getCycle()+1)%2] = (id1083x_1);
  }
  { // Node ID: 1805 (NodeConstantRawBits)
  }
  { // Node ID: 1641 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1641in_a = id1805out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1641in_b = id1006out_result[getCycle()%2];

    id1641out_result[(getCycle()+1)%2] = (lt_fixed(id1641in_a,id1641in_b));
  }
  { // Node ID: 1076 (NodeConstantRawBits)
  }
  HWRawBits<1> id1777out_result;

  { // Node ID: 1777 (NodeSlice)
    const HWFloat<8,24> &id1777in_a = id2269out_output[getCycle()%4];

    id1777out_result = (slice<11,1>(id1777in_a));
  }
  { // Node ID: 1077 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1077in_sel = id1641out_result[getCycle()%2];
    const HWRawBits<1> &id1077in_option0 = id1076out_value;
    const HWRawBits<1> &id1077in_option1 = id1777out_result;

    HWRawBits<1> id1077x_1;

    switch((id1077in_sel.getValueAsLong())) {
      case 0l:
        id1077x_1 = id1077in_option0;
        break;
      case 1l:
        id1077x_1 = id1077in_option1;
        break;
      default:
        id1077x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1077out_result[(getCycle()+1)%2] = (id1077x_1);
  }
  { // Node ID: 1804 (NodeConstantRawBits)
  }
  { // Node ID: 1643 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1643in_a = id1804out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1643in_b = id1006out_result[getCycle()%2];

    id1643out_result[(getCycle()+1)%2] = (lt_fixed(id1643in_a,id1643in_b));
  }
  { // Node ID: 1070 (NodeConstantRawBits)
  }
  HWRawBits<1> id1778out_result;

  { // Node ID: 1778 (NodeSlice)
    const HWFloat<8,24> &id1778in_a = id2269out_output[getCycle()%4];

    id1778out_result = (slice<10,1>(id1778in_a));
  }
  { // Node ID: 1071 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1071in_sel = id1643out_result[getCycle()%2];
    const HWRawBits<1> &id1071in_option0 = id1070out_value;
    const HWRawBits<1> &id1071in_option1 = id1778out_result;

    HWRawBits<1> id1071x_1;

    switch((id1071in_sel.getValueAsLong())) {
      case 0l:
        id1071x_1 = id1071in_option0;
        break;
      case 1l:
        id1071x_1 = id1071in_option1;
        break;
      default:
        id1071x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1071out_result[(getCycle()+1)%2] = (id1071x_1);
  }
  { // Node ID: 1803 (NodeConstantRawBits)
  }
  { // Node ID: 1645 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1645in_a = id1803out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1645in_b = id1006out_result[getCycle()%2];

    id1645out_result[(getCycle()+1)%2] = (lt_fixed(id1645in_a,id1645in_b));
  }
  { // Node ID: 1064 (NodeConstantRawBits)
  }
  HWRawBits<1> id1779out_result;

  { // Node ID: 1779 (NodeSlice)
    const HWFloat<8,24> &id1779in_a = id2269out_output[getCycle()%4];

    id1779out_result = (slice<9,1>(id1779in_a));
  }
  { // Node ID: 1065 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1065in_sel = id1645out_result[getCycle()%2];
    const HWRawBits<1> &id1065in_option0 = id1064out_value;
    const HWRawBits<1> &id1065in_option1 = id1779out_result;

    HWRawBits<1> id1065x_1;

    switch((id1065in_sel.getValueAsLong())) {
      case 0l:
        id1065x_1 = id1065in_option0;
        break;
      case 1l:
        id1065x_1 = id1065in_option1;
        break;
      default:
        id1065x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1065out_result[(getCycle()+1)%2] = (id1065x_1);
  }
  { // Node ID: 1802 (NodeConstantRawBits)
  }
  { // Node ID: 1647 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1647in_a = id1802out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1647in_b = id1006out_result[getCycle()%2];

    id1647out_result[(getCycle()+1)%2] = (lt_fixed(id1647in_a,id1647in_b));
  }
  { // Node ID: 1058 (NodeConstantRawBits)
  }
  HWRawBits<1> id1780out_result;

  { // Node ID: 1780 (NodeSlice)
    const HWFloat<8,24> &id1780in_a = id2269out_output[getCycle()%4];

    id1780out_result = (slice<8,1>(id1780in_a));
  }
  { // Node ID: 1059 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1059in_sel = id1647out_result[getCycle()%2];
    const HWRawBits<1> &id1059in_option0 = id1058out_value;
    const HWRawBits<1> &id1059in_option1 = id1780out_result;

    HWRawBits<1> id1059x_1;

    switch((id1059in_sel.getValueAsLong())) {
      case 0l:
        id1059x_1 = id1059in_option0;
        break;
      case 1l:
        id1059x_1 = id1059in_option1;
        break;
      default:
        id1059x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1059out_result[(getCycle()+1)%2] = (id1059x_1);
  }
  { // Node ID: 1801 (NodeConstantRawBits)
  }
  { // Node ID: 1649 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1649in_a = id1801out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1649in_b = id1006out_result[getCycle()%2];

    id1649out_result[(getCycle()+1)%2] = (lt_fixed(id1649in_a,id1649in_b));
  }
  { // Node ID: 1052 (NodeConstantRawBits)
  }
  HWRawBits<1> id1781out_result;

  { // Node ID: 1781 (NodeSlice)
    const HWFloat<8,24> &id1781in_a = id2269out_output[getCycle()%4];

    id1781out_result = (slice<7,1>(id1781in_a));
  }
  { // Node ID: 1053 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1053in_sel = id1649out_result[getCycle()%2];
    const HWRawBits<1> &id1053in_option0 = id1052out_value;
    const HWRawBits<1> &id1053in_option1 = id1781out_result;

    HWRawBits<1> id1053x_1;

    switch((id1053in_sel.getValueAsLong())) {
      case 0l:
        id1053x_1 = id1053in_option0;
        break;
      case 1l:
        id1053x_1 = id1053in_option1;
        break;
      default:
        id1053x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1053out_result[(getCycle()+1)%2] = (id1053x_1);
  }
  { // Node ID: 1800 (NodeConstantRawBits)
  }
  { // Node ID: 1651 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1651in_a = id1800out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1651in_b = id1006out_result[getCycle()%2];

    id1651out_result[(getCycle()+1)%2] = (lt_fixed(id1651in_a,id1651in_b));
  }
  { // Node ID: 1046 (NodeConstantRawBits)
  }
  HWRawBits<1> id1782out_result;

  { // Node ID: 1782 (NodeSlice)
    const HWFloat<8,24> &id1782in_a = id2269out_output[getCycle()%4];

    id1782out_result = (slice<6,1>(id1782in_a));
  }
  { // Node ID: 1047 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1047in_sel = id1651out_result[getCycle()%2];
    const HWRawBits<1> &id1047in_option0 = id1046out_value;
    const HWRawBits<1> &id1047in_option1 = id1782out_result;

    HWRawBits<1> id1047x_1;

    switch((id1047in_sel.getValueAsLong())) {
      case 0l:
        id1047x_1 = id1047in_option0;
        break;
      case 1l:
        id1047x_1 = id1047in_option1;
        break;
      default:
        id1047x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1047out_result[(getCycle()+1)%2] = (id1047x_1);
  }
  { // Node ID: 1799 (NodeConstantRawBits)
  }
  { // Node ID: 1653 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1653in_a = id1799out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1653in_b = id1006out_result[getCycle()%2];

    id1653out_result[(getCycle()+1)%2] = (lt_fixed(id1653in_a,id1653in_b));
  }
  { // Node ID: 1040 (NodeConstantRawBits)
  }
  HWRawBits<1> id1783out_result;

  { // Node ID: 1783 (NodeSlice)
    const HWFloat<8,24> &id1783in_a = id2269out_output[getCycle()%4];

    id1783out_result = (slice<5,1>(id1783in_a));
  }
  { // Node ID: 1041 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1041in_sel = id1653out_result[getCycle()%2];
    const HWRawBits<1> &id1041in_option0 = id1040out_value;
    const HWRawBits<1> &id1041in_option1 = id1783out_result;

    HWRawBits<1> id1041x_1;

    switch((id1041in_sel.getValueAsLong())) {
      case 0l:
        id1041x_1 = id1041in_option0;
        break;
      case 1l:
        id1041x_1 = id1041in_option1;
        break;
      default:
        id1041x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1041out_result[(getCycle()+1)%2] = (id1041x_1);
  }
  { // Node ID: 1798 (NodeConstantRawBits)
  }
  { // Node ID: 1655 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1655in_a = id1798out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1655in_b = id1006out_result[getCycle()%2];

    id1655out_result[(getCycle()+1)%2] = (lt_fixed(id1655in_a,id1655in_b));
  }
  { // Node ID: 1034 (NodeConstantRawBits)
  }
  HWRawBits<1> id1784out_result;

  { // Node ID: 1784 (NodeSlice)
    const HWFloat<8,24> &id1784in_a = id2269out_output[getCycle()%4];

    id1784out_result = (slice<4,1>(id1784in_a));
  }
  { // Node ID: 1035 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1035in_sel = id1655out_result[getCycle()%2];
    const HWRawBits<1> &id1035in_option0 = id1034out_value;
    const HWRawBits<1> &id1035in_option1 = id1784out_result;

    HWRawBits<1> id1035x_1;

    switch((id1035in_sel.getValueAsLong())) {
      case 0l:
        id1035x_1 = id1035in_option0;
        break;
      case 1l:
        id1035x_1 = id1035in_option1;
        break;
      default:
        id1035x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1035out_result[(getCycle()+1)%2] = (id1035x_1);
  }
  { // Node ID: 1797 (NodeConstantRawBits)
  }
  { // Node ID: 1657 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1657in_a = id1797out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1657in_b = id1006out_result[getCycle()%2];

    id1657out_result[(getCycle()+1)%2] = (lt_fixed(id1657in_a,id1657in_b));
  }
  { // Node ID: 1028 (NodeConstantRawBits)
  }
  HWRawBits<1> id1785out_result;

  { // Node ID: 1785 (NodeSlice)
    const HWFloat<8,24> &id1785in_a = id2269out_output[getCycle()%4];

    id1785out_result = (slice<3,1>(id1785in_a));
  }
  { // Node ID: 1029 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1029in_sel = id1657out_result[getCycle()%2];
    const HWRawBits<1> &id1029in_option0 = id1028out_value;
    const HWRawBits<1> &id1029in_option1 = id1785out_result;

    HWRawBits<1> id1029x_1;

    switch((id1029in_sel.getValueAsLong())) {
      case 0l:
        id1029x_1 = id1029in_option0;
        break;
      case 1l:
        id1029x_1 = id1029in_option1;
        break;
      default:
        id1029x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1029out_result[(getCycle()+1)%2] = (id1029x_1);
  }
  { // Node ID: 1796 (NodeConstantRawBits)
  }
  { // Node ID: 1659 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1659in_a = id1796out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1659in_b = id1006out_result[getCycle()%2];

    id1659out_result[(getCycle()+1)%2] = (lt_fixed(id1659in_a,id1659in_b));
  }
  { // Node ID: 1022 (NodeConstantRawBits)
  }
  HWRawBits<1> id1786out_result;

  { // Node ID: 1786 (NodeSlice)
    const HWFloat<8,24> &id1786in_a = id2269out_output[getCycle()%4];

    id1786out_result = (slice<2,1>(id1786in_a));
  }
  { // Node ID: 1023 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1023in_sel = id1659out_result[getCycle()%2];
    const HWRawBits<1> &id1023in_option0 = id1022out_value;
    const HWRawBits<1> &id1023in_option1 = id1786out_result;

    HWRawBits<1> id1023x_1;

    switch((id1023in_sel.getValueAsLong())) {
      case 0l:
        id1023x_1 = id1023in_option0;
        break;
      case 1l:
        id1023x_1 = id1023in_option1;
        break;
      default:
        id1023x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1023out_result[(getCycle()+1)%2] = (id1023x_1);
  }
  { // Node ID: 1795 (NodeConstantRawBits)
  }
  { // Node ID: 1661 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1661in_a = id1795out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1661in_b = id1006out_result[getCycle()%2];

    id1661out_result[(getCycle()+1)%2] = (lt_fixed(id1661in_a,id1661in_b));
  }
  { // Node ID: 1016 (NodeConstantRawBits)
  }
  HWRawBits<1> id1787out_result;

  { // Node ID: 1787 (NodeSlice)
    const HWFloat<8,24> &id1787in_a = id2269out_output[getCycle()%4];

    id1787out_result = (slice<1,1>(id1787in_a));
  }
  { // Node ID: 1017 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1017in_sel = id1661out_result[getCycle()%2];
    const HWRawBits<1> &id1017in_option0 = id1016out_value;
    const HWRawBits<1> &id1017in_option1 = id1787out_result;

    HWRawBits<1> id1017x_1;

    switch((id1017in_sel.getValueAsLong())) {
      case 0l:
        id1017x_1 = id1017in_option0;
        break;
      case 1l:
        id1017x_1 = id1017in_option1;
        break;
      default:
        id1017x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1017out_result[(getCycle()+1)%2] = (id1017x_1);
  }
  { // Node ID: 1794 (NodeConstantRawBits)
  }
  { // Node ID: 1663 (NodeLtInlined)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1663in_a = id1794out_value;
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1663in_b = id1006out_result[getCycle()%2];

    id1663out_result[(getCycle()+1)%2] = (lt_fixed(id1663in_a,id1663in_b));
  }
  { // Node ID: 1010 (NodeConstantRawBits)
  }
  HWRawBits<1> id1788out_result;

  { // Node ID: 1788 (NodeSlice)
    const HWFloat<8,24> &id1788in_a = id2269out_output[getCycle()%4];

    id1788out_result = (slice<0,1>(id1788in_a));
  }
  { // Node ID: 1011 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1011in_sel = id1663out_result[getCycle()%2];
    const HWRawBits<1> &id1011in_option0 = id1010out_value;
    const HWRawBits<1> &id1011in_option1 = id1788out_result;

    HWRawBits<1> id1011x_1;

    switch((id1011in_sel.getValueAsLong())) {
      case 0l:
        id1011x_1 = id1011in_option0;
        break;
      case 1l:
        id1011x_1 = id1011in_option1;
        break;
      default:
        id1011x_1 = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
        break;
    }
    id1011out_result[(getCycle()+1)%2] = (id1011x_1);
  }
  { // Node ID: 1004 (NodeConstantRawBits)
  }
  HWRawBits<24> id1686out_result;

  { // Node ID: 1686 (NodeCat)
    const HWRawBits<1> &id1686in_in0 = id1143out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in1 = id1137out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in2 = id1131out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in3 = id1125out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in4 = id1119out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in5 = id1113out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in6 = id1107out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in7 = id1101out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in8 = id1095out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in9 = id1089out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in10 = id1083out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in11 = id1077out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in12 = id1071out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in13 = id1065out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in14 = id1059out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in15 = id1053out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in16 = id1047out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in17 = id1041out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in18 = id1035out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in19 = id1029out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in20 = id1023out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in21 = id1017out_result[getCycle()%2];
    const HWRawBits<1> &id1686in_in22 = id1011out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id1686in_in23 = id1004out_value;

    id1686out_result = (cat((cat((cat((cat((cat(id1686in_in0,id1686in_in1)),id1686in_in2)),(cat((cat(id1686in_in3,id1686in_in4)),id1686in_in5)))),(cat((cat((cat(id1686in_in6,id1686in_in7)),id1686in_in8)),(cat((cat(id1686in_in9,id1686in_in10)),id1686in_in11)))))),(cat((cat((cat((cat(id1686in_in12,id1686in_in13)),id1686in_in14)),(cat((cat(id1686in_in15,id1686in_in16)),id1686in_in17)))),(cat((cat((cat(id1686in_in18,id1686in_in19)),id1686in_in20)),(cat((cat(id1686in_in21,id1686in_in22)),id1686in_in23))))))));
  }
  HWOffsetFix<5,0,UNSIGNED> id1145out_o;

  { // Node ID: 1145 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1145in_i = id986out_result[getCycle()%2];

    id1145out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id1145in_i));
  }
  { // Node ID: 2294 (NodeFIFO)
    const HWOffsetFix<5,0,UNSIGNED> &id2294in_input = id1145out_o;

    id2294out_output[(getCycle()+3)%4] = id2294in_input;
  }
  { // Node ID: 1146 (NodeShift)
    const HWRawBits<24> &id1146in_datain = id1686out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id1146in_shift = id2294out_output[getCycle()%4];

    id1146out_dataout[(getCycle()+4)%5] = (shift_left_bits(id1146in_datain,(id1146in_shift.getValueAsLong())));
  }
  { // Node ID: 987 (NodeConstantRawBits)
  }
  HWRawBits<23> id988out_result;

  { // Node ID: 988 (NodeSlice)
    const HWFloat<8,24> &id988in_a = id2269out_output[getCycle()%4];

    id988out_result = (slice<0,23>(id988in_a));
  }
  HWRawBits<24> id989out_result;

  { // Node ID: 989 (NodeCat)
    const HWOffsetFix<1,0,UNSIGNED> &id989in_in0 = id987out_value;
    const HWRawBits<23> &id989in_in1 = id988out_result;

    id989out_result = (cat(id989in_in0,id989in_in1));
  }
  { // Node ID: 999 (NodeNeg)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id999in_a = id986out_result[getCycle()%2];

    id999out_result[(getCycle()+1)%2] = (neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id999in_a));
  }
  { // Node ID: 1793 (NodeConstantRawBits)
  }
  { // Node ID: 1001 (NodeSub)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1001in_a = id999out_result[getCycle()%2];
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1001in_b = id1793out_value;

    id1001out_result[(getCycle()+1)%2] = (sub_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(id1001in_a,id1001in_b));
  }
  HWOffsetFix<5,0,UNSIGNED> id1002out_o;

  { // Node ID: 1002 (NodeCast)
    const HWOffsetFix<9,0,TWOSCOMPLEMENT> &id1002in_i = id1001out_result[getCycle()%2];

    id1002out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id1002in_i));
  }
  { // Node ID: 1003 (NodeShift)
    const HWRawBits<24> &id1003in_datain = id989out_result;
    const HWOffsetFix<5,0,UNSIGNED> &id1003in_shift = id1002out_o;

    id1003out_dataout[(getCycle()+4)%5] = (shift_right_bits(id1003in_datain,(id1003in_shift.getValueAsLong())));
  }
  { // Node ID: 2297 (NodeFIFO)
    const HWRawBits<24> &id2297in_input = id1003out_dataout[getCycle()%5];

    id2297out_output[(getCycle()+1)%2] = id2297in_input;
  }
  { // Node ID: 1792 (NodeConstantRawBits)
  }
  { // Node ID: 1149 (NodeMux)
    const HWOffsetFix<2,0,UNSIGNED> &id1149in_sel = id2296out_output[getCycle()%6];
    const HWRawBits<24> &id1149in_option0 = id1146out_dataout[getCycle()%5];
    const HWRawBits<24> &id1149in_option1 = id2297out_output[getCycle()%2];
    const HWRawBits<24> &id1149in_option2 = id1792out_value;
    const HWRawBits<24> &id1149in_option3 = id1792out_value;

    HWRawBits<24> id1149x_1;

    switch((id1149in_sel.getValueAsLong())) {
      case 0l:
        id1149x_1 = id1149in_option0;
        break;
      case 1l:
        id1149x_1 = id1149in_option1;
        break;
      case 2l:
        id1149x_1 = id1149in_option2;
        break;
      case 3l:
        id1149x_1 = id1149in_option3;
        break;
      default:
        id1149x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id1149out_result[(getCycle()+1)%2] = (id1149x_1);
  }
  HWRawBits<24> id1150out_result;

  { // Node ID: 1150 (NodeNot)
    const HWRawBits<24> &id1150in_a = id1149out_result[getCycle()%2];

    id1150out_result = (not_bits(id1150in_a));
  }
  { // Node ID: 1151 (NodeMux)
    const HWRawBits<1> &id1151in_sel = id2298out_output[getCycle()%7];
    const HWRawBits<24> &id1151in_option0 = id1149out_result[getCycle()%2];
    const HWRawBits<24> &id1151in_option1 = id1150out_result;

    HWRawBits<24> id1151x_1;

    switch((id1151in_sel.getValueAsLong())) {
      case 0l:
        id1151x_1 = id1151in_option0;
        break;
      case 1l:
        id1151x_1 = id1151in_option1;
        break;
      default:
        id1151x_1 = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
        break;
    }
    id1151out_result[(getCycle()+1)%2] = (id1151x_1);
  }
  HWOffsetFix<24,-24,UNSIGNED> id1152out_output;

  { // Node ID: 1152 (NodeReinterpret)
    const HWRawBits<24> &id1152in_input = id1151out_result[getCycle()%2];

    id1152out_output = (cast_bits2fixed<24,-24,UNSIGNED>(id1152in_input));
  }
  { // Node ID: 1153 (NodeCast)
    const HWOffsetFix<24,-24,UNSIGNED> &id1153in_i = id1152out_output;

    id1153out_o[(getCycle()+7)%8] = (cast_fixed2float<8,24>(id1153in_i));
  }
  { // Node ID: 1154 (NodeMux)
    const HWRawBits<1> &id1154in_sel = id2238out_output[getCycle()%28];
    const HWFloat<8,24> &id1154in_option0 = id952out_o[getCycle()%8];
    const HWFloat<8,24> &id1154in_option1 = id1153out_o[getCycle()%8];

    HWFloat<8,24> id1154x_1;

    switch((id1154in_sel.getValueAsLong())) {
      case 0l:
        id1154x_1 = id1154in_option0;
        break;
      case 1l:
        id1154x_1 = id1154in_option1;
        break;
      default:
        id1154x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1154out_result[(getCycle()+1)%2] = (id1154x_1);
  }
  { // Node ID: 1160 (NodeMul)
    const HWFloat<8,24> &id1160in_a = id1158out_result[getCycle()%2];
    const HWFloat<8,24> &id1160in_b = id1154out_result[getCycle()%2];

    id1160out_result[(getCycle()+8)%9] = (mul_float(id1160in_a,id1160in_b));
  }
  { // Node ID: 1159 (NodeMul)
    const HWFloat<8,24> &id1159in_a = id1154out_result[getCycle()%2];
    const HWFloat<8,24> &id1159in_b = id1154out_result[getCycle()%2];

    id1159out_result[(getCycle()+8)%9] = (mul_float(id1159in_a,id1159in_b));
  }
  { // Node ID: 1161 (NodeMul)
    const HWFloat<8,24> &id1161in_a = id1160out_result[getCycle()%9];
    const HWFloat<8,24> &id1161in_b = id1159out_result[getCycle()%9];

    id1161out_result[(getCycle()+8)%9] = (mul_float(id1161in_a,id1161in_b));
  }
  HWRawBits<32> id1310out_result;

  { // Node ID: 1310 (NodeSlice)
    const HWRawBits<128> &id1310in_a = id1305out_dout[getCycle()%3];

    id1310out_result = (slice<64,32>(id1310in_a));
  }
  HWFloat<8,24> id1311out_output;

  { // Node ID: 1311 (NodeReinterpret)
    const HWRawBits<32> &id1311in_input = id1310out_result;

    id1311out_output = (cast_bits2float<8,24>(id1311in_input));
  }
  HWRawBits<32> id1319out_result;

  { // Node ID: 1319 (NodeSlice)
    const HWRawBits<128> &id1319in_a = id1314out_dout[getCycle()%3];

    id1319out_result = (slice<64,32>(id1319in_a));
  }
  HWFloat<8,24> id1320out_output;

  { // Node ID: 1320 (NodeReinterpret)
    const HWRawBits<32> &id1320in_input = id1319out_result;

    id1320out_output = (cast_bits2float<8,24>(id1320in_input));
  }
  { // Node ID: 1157 (NodeMux)
    const HWRawBits<1> &id1157in_sel = id2238out_output[getCycle()%28];
    const HWFloat<8,24> &id1157in_option0 = id1311out_output;
    const HWFloat<8,24> &id1157in_option1 = id1320out_output;

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
  { // Node ID: 2301 (NodeFIFO)
    const HWFloat<8,24> &id2301in_input = id1157out_result[getCycle()%2];

    id2301out_output[(getCycle()+8)%9] = id2301in_input;
  }
  { // Node ID: 1162 (NodeMul)
    const HWFloat<8,24> &id1162in_a = id2301out_output[getCycle()%9];
    const HWFloat<8,24> &id1162in_b = id1159out_result[getCycle()%9];

    id1162out_result[(getCycle()+8)%9] = (mul_float(id1162in_a,id1162in_b));
  }
  { // Node ID: 1163 (NodeAdd)
    const HWFloat<8,24> &id1163in_a = id1161out_result[getCycle()%9];
    const HWFloat<8,24> &id1163in_b = id1162out_result[getCycle()%9];

    id1163out_result[(getCycle()+11)%12] = (add_float(id1163in_a,id1163in_b));
  }
  HWRawBits<32> id1308out_result;

  { // Node ID: 1308 (NodeSlice)
    const HWRawBits<128> &id1308in_a = id1305out_dout[getCycle()%3];

    id1308out_result = (slice<32,32>(id1308in_a));
  }
  HWFloat<8,24> id1309out_output;

  { // Node ID: 1309 (NodeReinterpret)
    const HWRawBits<32> &id1309in_input = id1308out_result;

    id1309out_output = (cast_bits2float<8,24>(id1309in_input));
  }
  HWRawBits<32> id1317out_result;

  { // Node ID: 1317 (NodeSlice)
    const HWRawBits<128> &id1317in_a = id1314out_dout[getCycle()%3];

    id1317out_result = (slice<32,32>(id1317in_a));
  }
  HWFloat<8,24> id1318out_output;

  { // Node ID: 1318 (NodeReinterpret)
    const HWRawBits<32> &id1318in_input = id1317out_result;

    id1318out_output = (cast_bits2float<8,24>(id1318in_input));
  }
  { // Node ID: 1156 (NodeMux)
    const HWRawBits<1> &id1156in_sel = id2238out_output[getCycle()%28];
    const HWFloat<8,24> &id1156in_option0 = id1309out_output;
    const HWFloat<8,24> &id1156in_option1 = id1318out_output;

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
  { // Node ID: 1164 (NodeMul)
    const HWFloat<8,24> &id1164in_a = id1156out_result[getCycle()%2];
    const HWFloat<8,24> &id1164in_b = id1154out_result[getCycle()%2];

    id1164out_result[(getCycle()+8)%9] = (mul_float(id1164in_a,id1164in_b));
  }
  { // Node ID: 2303 (NodeFIFO)
    const HWFloat<8,24> &id2303in_input = id1164out_result[getCycle()%9];

    id2303out_output[(getCycle()+19)%20] = id2303in_input;
  }
  { // Node ID: 1165 (NodeAdd)
    const HWFloat<8,24> &id1165in_a = id1163out_result[getCycle()%12];
    const HWFloat<8,24> &id1165in_b = id2303out_output[getCycle()%20];

    id1165out_result[(getCycle()+11)%12] = (add_float(id1165in_a,id1165in_b));
  }
  HWRawBits<32> id1306out_result;

  { // Node ID: 1306 (NodeSlice)
    const HWRawBits<128> &id1306in_a = id1305out_dout[getCycle()%3];

    id1306out_result = (slice<0,32>(id1306in_a));
  }
  HWFloat<8,24> id1307out_output;

  { // Node ID: 1307 (NodeReinterpret)
    const HWRawBits<32> &id1307in_input = id1306out_result;

    id1307out_output = (cast_bits2float<8,24>(id1307in_input));
  }
  HWRawBits<32> id1315out_result;

  { // Node ID: 1315 (NodeSlice)
    const HWRawBits<128> &id1315in_a = id1314out_dout[getCycle()%3];

    id1315out_result = (slice<0,32>(id1315in_a));
  }
  HWFloat<8,24> id1316out_output;

  { // Node ID: 1316 (NodeReinterpret)
    const HWRawBits<32> &id1316in_input = id1315out_result;

    id1316out_output = (cast_bits2float<8,24>(id1316in_input));
  }
  { // Node ID: 1155 (NodeMux)
    const HWRawBits<1> &id1155in_sel = id2238out_output[getCycle()%28];
    const HWFloat<8,24> &id1155in_option0 = id1307out_output;
    const HWFloat<8,24> &id1155in_option1 = id1316out_output;

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
  { // Node ID: 2305 (NodeFIFO)
    const HWFloat<8,24> &id2305in_input = id1155out_result[getCycle()%2];

    id2305out_output[(getCycle()+38)%39] = id2305in_input;
  }
  { // Node ID: 1166 (NodeAdd)
    const HWFloat<8,24> &id1166in_a = id1165out_result[getCycle()%12];
    const HWFloat<8,24> &id1166in_b = id2305out_output[getCycle()%39];

    id1166out_result[(getCycle()+11)%12] = (add_float(id1166in_a,id1166in_b));
  }
  { // Node ID: 1791 (NodeConstantRawBits)
  }
  { // Node ID: 1173 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1173in_sel = id2306out_output[getCycle()%65];
    const HWFloat<8,24> &id1173in_option0 = id1166out_result[getCycle()%12];
    const HWFloat<8,24> &id1173in_option1 = id1791out_value;

    HWFloat<8,24> id1173x_1;

    switch((id1173in_sel.getValueAsLong())) {
      case 0l:
        id1173x_1 = id1173in_option0;
        break;
      case 1l:
        id1173x_1 = id1173in_option1;
        break;
      default:
        id1173x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1173out_result[(getCycle()+1)%2] = (id1173x_1);
  }
  HWRawBits<1> id2029out_result;

  { // Node ID: 2029 (NodeSlice)
    const HWFloat<8,24> &id2029in_a = id1173out_result[getCycle()%2];

    id2029out_result = (slice<31,1>(id2029in_a));
  }
  { // Node ID: 1871 (NodeConstantRawBits)
  }
  { // Node ID: 1531 (NodeEqInlined)
    const HWRawBits<2> &id1531in_a = id703out_result[getCycle()%2];
    const HWRawBits<2> &id1531in_b = id1871out_value;

    id1531out_result[(getCycle()+1)%2] = (eq_bits(id1531in_a,id1531in_b));
  }
  { // Node ID: 1870 (NodeConstantRawBits)
  }
  { // Node ID: 1532 (NodeEqInlined)
    const HWRawBits<2> &id1532in_a = id703out_result[getCycle()%2];
    const HWRawBits<2> &id1532in_b = id1870out_value;

    id1532out_result[(getCycle()+1)%2] = (eq_bits(id1532in_a,id1532in_b));
  }
  { // Node ID: 751 (NodeOr)
    const HWOffsetFix<1,0,UNSIGNED> &id751in_a = id1531out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id751in_b = id1532out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id751x_1;

    (id751x_1) = (or_fixed(id751in_a,id751in_b));
    id751out_result[(getCycle()+1)%2] = (id751x_1);
  }
  { // Node ID: 2307 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2307in_input = id751out_result[getCycle()%2];

    id2307out_output[(getCycle()+76)%77] = id2307in_input;
  }
  HWRawBits<1> id2030out_result;

  { // Node ID: 2030 (NodeXor)
    const HWRawBits<1> &id2030in_a = id2029out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2030in_b = id2307out_output[getCycle()%77];

    HWRawBits<1> id2030x_1;

    (id2030x_1) = (xor_bits(id2030in_a,(cast_fixed2bits(id2030in_b))));
    id2030out_result = (id2030x_1);
  }
  HWRawBits<31> id2028out_result;

  { // Node ID: 2028 (NodeSlice)
    const HWFloat<8,24> &id2028in_a = id1173out_result[getCycle()%2];

    id2028out_result = (slice<0,31>(id2028in_a));
  }
  HWRawBits<32> id2031out_result;

  { // Node ID: 2031 (NodeCat)
    const HWRawBits<1> &id2031in_in0 = id2030out_result;
    const HWRawBits<31> &id2031in_in1 = id2028out_result;

    id2031out_result = (cat(id2031in_in0,id2031in_in1));
  }
  HWFloat<8,24> id2032out_output;

  { // Node ID: 2032 (NodeReinterpret)
    const HWRawBits<32> &id2032in_input = id2031out_result;

    id2032out_output = (cast_bits2float<8,24>(id2032in_input));
  }
  { // Node ID: 1187 (NodeConstantRawBits)
  }
  { // Node ID: 1188 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1188in_sel = id2308out_output[getCycle()%80];
    const HWFloat<8,24> &id1188in_option0 = id2032out_output;
    const HWFloat<8,24> &id1188in_option1 = id1187out_value;

    HWFloat<8,24> id1188x_1;

    switch((id1188in_sel.getValueAsLong())) {
      case 0l:
        id1188x_1 = id1188in_option0;
        break;
      case 1l:
        id1188x_1 = id1188in_option1;
        break;
      default:
        id1188x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1188out_result[(getCycle()+1)%2] = (id1188x_1);
  }
  { // Node ID: 1189 (NodeMul)
    const HWFloat<8,24> &id1189in_a = id139out_result[getCycle()%29];
    const HWFloat<8,24> &id1189in_b = id1188out_result[getCycle()%2];

    id1189out_result[(getCycle()+8)%9] = (mul_float(id1189in_a,id1189in_b));
  }
  { // Node ID: 2316 (NodeFIFO)
    const HWFloat<8,24> &id2316in_input = id1189out_result[getCycle()%9];

    id2316out_output[(getCycle()+58)%59] = id2316in_input;
  }
  { // Node ID: 1212 (NodeMul)
    const HWFloat<8,24> &id1212in_a = id2309out_output[getCycle()%22];
    const HWFloat<8,24> &id1212in_b = id2369out_output[getCycle()%22];

    id1212out_result[(getCycle()+8)%9] = (mul_float(id1212in_a,id1212in_b));
  }
  { // Node ID: 1213 (NodeMul)
    const HWFloat<8,24> &id1213in_a = id1212out_result[getCycle()%9];
    const HWFloat<8,24> &id1213in_b = id663out_result[getCycle()%9];

    id1213out_result[(getCycle()+8)%9] = (mul_float(id1213in_a,id1213in_b));
  }
  { // Node ID: 1214 (NodeMul)
    const HWFloat<8,24> &id1214in_a = id2364out_output[getCycle()%9];
    const HWFloat<8,24> &id1214in_b = id1189out_result[getCycle()%9];

    id1214out_result[(getCycle()+8)%9] = (mul_float(id1214in_a,id1214in_b));
  }
  { // Node ID: 1215 (NodeAdd)
    const HWFloat<8,24> &id1215in_a = id1213out_result[getCycle()%9];
    const HWFloat<8,24> &id1215in_b = id1214out_result[getCycle()%9];

    id1215out_result[(getCycle()+11)%12] = (add_float(id1215in_a,id1215in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id1195out_result;

  { // Node ID: 1195 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1195in_a = id2312out_output[getCycle()%48];

    id1195out_result = (not_fixed(id1195in_a));
  }
  { // Node ID: 1196 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1196in_a = id1195out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1196in_b = id1194out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id1196x_1;

    (id1196x_1) = (and_fixed(id1196in_a,id1196in_b));
    id1196out_result[(getCycle()+1)%2] = (id1196x_1);
  }
  { // Node ID: 2367 (NodeFIFO)
    const HWFloat<8,24> &id2367in_input = id2329out_output[getCycle()%26];

    id2367out_output[(getCycle()+3)%4] = id2367in_input;
  }
  { // Node ID: 1197 (NodeSqrt)
    const HWFloat<8,24> &id1197in_a = id1192out_result[getCycle()%12];

    id1197out_result[(getCycle()+28)%29] = (sqrt_float(id1197in_a));
  }
  { // Node ID: 1199 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1199in_sel = id1196out_result[getCycle()%2];
    const HWFloat<8,24> &id1199in_option0 = id2367out_output[getCycle()%4];
    const HWFloat<8,24> &id1199in_option1 = id1197out_result[getCycle()%29];

    HWFloat<8,24> id1199x_1;

    switch((id1199in_sel.getValueAsLong())) {
      case 0l:
        id1199x_1 = id1199in_option0;
        break;
      case 1l:
        id1199x_1 = id1199in_option1;
        break;
      default:
        id1199x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1199out_result[(getCycle()+1)%2] = (id1199x_1);
  }
  { // Node ID: 1216 (NodeDiv)
    const HWFloat<8,24> &id1216in_a = id1215out_result[getCycle()%12];
    const HWFloat<8,24> &id1216in_b = id1199out_result[getCycle()%2];

    id1216out_result[(getCycle()+28)%29] = (div_float(id1216in_a,id1216in_b));
  }
  { // Node ID: 2333 (NodeFIFO)
    const HWFloat<8,24> &id2333in_input = id133out_result[getCycle()%2];

    id2333out_output[(getCycle()+85)%86] = id2333in_input;
  }
  { // Node ID: 2354 (NodeFIFO)
    const HWFloat<8,24> &id2354in_input = id2333out_output[getCycle()%86];

    id2354out_output[(getCycle()+19)%20] = id2354in_input;
  }
  { // Node ID: 2355 (NodeFIFO)
    const HWFloat<8,24> &id2355in_input = id2354out_output[getCycle()%20];

    id2355out_output[(getCycle()+1)%2] = id2355in_input;
  }
  { // Node ID: 1217 (NodeMul)
    const HWFloat<8,24> &id1217in_a = id2362out_output[getCycle()%40];
    const HWFloat<8,24> &id1217in_b = id2355out_output[getCycle()%2];

    id1217out_result[(getCycle()+8)%9] = (mul_float(id1217in_a,id1217in_b));
  }
  { // Node ID: 1218 (NodeAdd)
    const HWFloat<8,24> &id1218in_a = id1216out_result[getCycle()%29];
    const HWFloat<8,24> &id1218in_b = id1217out_result[getCycle()%9];

    id1218out_result[(getCycle()+11)%12] = (add_float(id1218in_a,id1218in_b));
  }
  { // Node ID: 1219 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1219in_sel = id1211out_result[getCycle()%2];
    const HWFloat<8,24> &id1219in_option0 = id2316out_output[getCycle()%59];
    const HWFloat<8,24> &id1219in_option1 = id1218out_result[getCycle()%12];

    HWFloat<8,24> id1219x_1;

    switch((id1219in_sel.getValueAsLong())) {
      case 0l:
        id1219x_1 = id1219in_option0;
        break;
      case 1l:
        id1219x_1 = id1219in_option1;
        break;
      default:
        id1219x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1219out_result[(getCycle()+1)%2] = (id1219x_1);
  }
  { // Node ID: 1242 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1242in_sel = id1241out_result;
    const HWFloat<8,24> &id1242in_option0 = id2363out_output[getCycle()%21];
    const HWFloat<8,24> &id1242in_option1 = id1219out_result[getCycle()%2];

    HWFloat<8,24> id1242x_1;

    switch((id1242in_sel.getValueAsLong())) {
      case 0l:
        id1242x_1 = id1242in_option0;
        break;
      case 1l:
        id1242x_1 = id1242in_option1;
        break;
      default:
        id1242x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1242out_result[(getCycle()+1)%2] = (id1242x_1);
  }
  HWFloat<8,24> id2063out_output;

  { // Node ID: 2063 (NodeStreamOffset)
    const HWFloat<8,24> &id2063in_input = id1242out_result[getCycle()%2];

    id2063out_output = id2063in_input;
  }
  { // Node ID: 17 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_sel = id2318out_output[getCycle()%15];
    const HWFloat<8,24> &id18in_option0 = id2063out_output;
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
  { // Node ID: 2309 (NodeFIFO)
    const HWFloat<8,24> &id2309in_input = id18out_result[getCycle()%2];

    id2309out_output[(getCycle()+21)%22] = id2309in_input;
  }
  { // Node ID: 2361 (NodeFIFO)
    const HWFloat<8,24> &id2361in_input = id2309out_output[getCycle()%22];

    id2361out_output[(getCycle()+8)%9] = id2361in_input;
  }
  { // Node ID: 1204 (NodeMul)
    const HWFloat<8,24> &id1204in_a = id2361out_output[getCycle()%9];
    const HWFloat<8,24> &id1204in_b = id1189out_result[getCycle()%9];

    id1204out_result[(getCycle()+8)%9] = (mul_float(id1204in_a,id1204in_b));
  }
  { // Node ID: 1205 (NodeSub)
    const HWFloat<8,24> &id1205in_a = id1203out_result[getCycle()%9];
    const HWFloat<8,24> &id1205in_b = id1204out_result[getCycle()%9];

    id1205out_result[(getCycle()+11)%12] = (sub_float(id1205in_a,id1205in_b));
  }
  { // Node ID: 1206 (NodeDiv)
    const HWFloat<8,24> &id1206in_a = id1205out_result[getCycle()%12];
    const HWFloat<8,24> &id1206in_b = id1199out_result[getCycle()%2];

    id1206out_result[(getCycle()+28)%29] = (div_float(id1206in_a,id1206in_b));
  }
  { // Node ID: 1207 (NodeMul)
    const HWFloat<8,24> &id1207in_a = id2365out_output[getCycle()%40];
    const HWFloat<8,24> &id1207in_b = id2355out_output[getCycle()%2];

    id1207out_result[(getCycle()+8)%9] = (mul_float(id1207in_a,id1207in_b));
  }
  { // Node ID: 1208 (NodeAdd)
    const HWFloat<8,24> &id1208in_a = id1206out_result[getCycle()%29];
    const HWFloat<8,24> &id1208in_b = id1207out_result[getCycle()%9];

    id1208out_result[(getCycle()+11)%12] = (add_float(id1208in_a,id1208in_b));
  }
  { // Node ID: 1209 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1209in_sel = id1201out_result[getCycle()%2];
    const HWFloat<8,24> &id1209in_option0 = id2359out_output[getCycle()%40];
    const HWFloat<8,24> &id1209in_option1 = id1208out_result[getCycle()%12];

    HWFloat<8,24> id1209x_1;

    switch((id1209in_sel.getValueAsLong())) {
      case 0l:
        id1209x_1 = id1209in_option0;
        break;
      case 1l:
        id1209x_1 = id1209in_option1;
        break;
      default:
        id1209x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1209out_result[(getCycle()+1)%2] = (id1209x_1);
  }
  HWRawBits<1> id2034out_result;

  { // Node ID: 2034 (NodeSlice)
    const HWFloat<8,24> &id2034in_a = id1209out_result[getCycle()%2];

    id2034out_result = (slice<31,1>(id2034in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1231out_result;

  { // Node ID: 1231 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1231in_a = id2349out_output[getCycle()%2];

    id1231out_result = (not_fixed(id1231in_a));
  }
  { // Node ID: 1968 (NodeConstantRawBits)
  }
  { // Node ID: 1228 (NodeLt)
    const HWFloat<8,24> &id1228in_a = id2371out_output[getCycle()%17];
    const HWFloat<8,24> &id1228in_b = id1968out_value;

    id1228out_result[(getCycle()+2)%3] = (lt_float(id1228in_a,id1228in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id1229out_result;

  { // Node ID: 1229 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1229in_a = id2325out_output[getCycle()%21];

    id1229out_result = (not_fixed(id1229in_a));
  }
  { // Node ID: 1230 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1230in_a = id1228out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id1230in_b = id1229out_result;

    HWOffsetFix<1,0,UNSIGNED> id1230x_1;

    (id1230x_1) = (and_fixed(id1230in_a,id1230in_b));
    id1230out_result[(getCycle()+1)%2] = (id1230x_1);
  }
  { // Node ID: 1232 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1232in_a = id1231out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1232in_b = id1230out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1232x_1;

    (id1232x_1) = (and_fixed(id1232in_a,id1232in_b));
    id1232out_result[(getCycle()+1)%2] = (id1232x_1);
  }
  { // Node ID: 2326 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2326in_input = id1232out_result[getCycle()%2];

    id2326out_output[(getCycle()+20)%21] = id2326in_input;
  }
  HWRawBits<1> id2035out_result;

  { // Node ID: 2035 (NodeXor)
    const HWRawBits<1> &id2035in_a = id2034out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2035in_b = id2326out_output[getCycle()%21];

    HWRawBits<1> id2035x_1;

    (id2035x_1) = (xor_bits(id2035in_a,(cast_fixed2bits(id2035in_b))));
    id2035out_result = (id2035x_1);
  }
  HWRawBits<31> id2033out_result;

  { // Node ID: 2033 (NodeSlice)
    const HWFloat<8,24> &id2033in_a = id1209out_result[getCycle()%2];

    id2033out_result = (slice<0,31>(id2033in_a));
  }
  HWRawBits<32> id2036out_result;

  { // Node ID: 2036 (NodeCat)
    const HWRawBits<1> &id2036in_in0 = id2035out_result;
    const HWRawBits<31> &id2036in_in1 = id2033out_result;

    id2036out_result = (cat(id2036in_in0,id2036in_in1));
  }
  HWFloat<8,24> id2037out_output;

  { // Node ID: 2037 (NodeReinterpret)
    const HWRawBits<32> &id2037in_input = id2036out_result;

    id2037out_output = (cast_bits2float<8,24>(id2037in_input));
  }
  { // Node ID: 1240 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1240in_sel = id1239out_result;
    const HWFloat<8,24> &id1240in_option0 = id2366out_output[getCycle()%21];
    const HWFloat<8,24> &id1240in_option1 = id2037out_output;

    HWFloat<8,24> id1240x_1;

    switch((id1240in_sel.getValueAsLong())) {
      case 0l:
        id1240x_1 = id1240in_option0;
        break;
      case 1l:
        id1240x_1 = id1240in_option1;
        break;
      default:
        id1240x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1240out_result[(getCycle()+1)%2] = (id1240x_1);
  }
  HWFloat<8,24> id2064out_output;

  { // Node ID: 2064 (NodeStreamOffset)
    const HWFloat<8,24> &id2064in_input = id1240out_result[getCycle()%2];

    id2064out_output = id2064in_input;
  }
  { // Node ID: 15 (NodeConstantRawBits)
  }
  { // Node ID: 16 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_sel = id2318out_output[getCycle()%15];
    const HWFloat<8,24> &id16in_option0 = id2064out_output;
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
  { // Node ID: 1190 (NodeMul)
    const HWFloat<8,24> &id1190in_a = id16out_result[getCycle()%2];
    const HWFloat<8,24> &id1190in_b = id16out_result[getCycle()%2];

    id1190out_result[(getCycle()+8)%9] = (mul_float(id1190in_a,id1190in_b));
  }
  { // Node ID: 1191 (NodeMul)
    const HWFloat<8,24> &id1191in_a = id18out_result[getCycle()%2];
    const HWFloat<8,24> &id1191in_b = id18out_result[getCycle()%2];

    id1191out_result[(getCycle()+8)%9] = (mul_float(id1191in_a,id1191in_b));
  }
  { // Node ID: 1192 (NodeAdd)
    const HWFloat<8,24> &id1192in_a = id1190out_result[getCycle()%9];
    const HWFloat<8,24> &id1192in_b = id1191out_result[getCycle()%9];

    id1192out_result[(getCycle()+11)%12] = (add_float(id1192in_a,id1192in_b));
  }
  { // Node ID: 2329 (NodeFIFO)
    const HWFloat<8,24> &id2329in_input = id1192out_result[getCycle()%12];

    id2329out_output[(getCycle()+25)%26] = id2329in_input;
  }
  { // Node ID: 1790 (NodeConstantRawBits)
  }
  { // Node ID: 1194 (NodeGt)
    const HWFloat<8,24> &id1194in_a = id2329out_output[getCycle()%26];
    const HWFloat<8,24> &id1194in_b = id1790out_value;

    id1194out_result[(getCycle()+2)%3] = (gt_float(id1194in_a,id1194in_b));
  }
  { // Node ID: 2325 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id2325in_input = id1194out_result[getCycle()%3];

    id2325out_output[(getCycle()+20)%21] = id2325in_input;
  }
  { // Node ID: 1221 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1221in_a = id1220out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1221in_b = id2325out_output[getCycle()%21];

    HWOffsetFix<1,0,UNSIGNED> id1221x_1;

    (id1221x_1) = (and_fixed(id1221in_a,id1221in_b));
    id1221out_result[(getCycle()+1)%2] = (id1221x_1);
  }
  HWFloat<8,24> id1222out_result;

  { // Node ID: 1222 (NodeNeg)
    const HWFloat<8,24> &id1222in_a = id1199out_result[getCycle()%2];

    id1222out_result = (neg_float(id1222in_a));
  }
  { // Node ID: 1223 (NodeMul)
    const HWFloat<8,24> &id1223in_a = id1222out_result;
    const HWFloat<8,24> &id1223in_b = id2331out_output[getCycle()%20];

    id1223out_result[(getCycle()+8)%9] = (mul_float(id1223in_a,id1223in_b));
  }
  { // Node ID: 1224 (NodeMul)
    const HWFloat<8,24> &id1224in_a = id2370out_output[getCycle()%28];
    const HWFloat<8,24> &id1224in_b = id2333out_output[getCycle()%86];

    id1224out_result[(getCycle()+8)%9] = (mul_float(id1224in_a,id1224in_b));
  }
  { // Node ID: 1225 (NodeAdd)
    const HWFloat<8,24> &id1225in_a = id1223out_result[getCycle()%9];
    const HWFloat<8,24> &id1225in_b = id1224out_result[getCycle()%9];

    id1225out_result[(getCycle()+11)%12] = (add_float(id1225in_a,id1225in_b));
  }
  { // Node ID: 1226 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1226in_sel = id1221out_result[getCycle()%2];
    const HWFloat<8,24> &id1226in_option0 = id2354out_output[getCycle()%20];
    const HWFloat<8,24> &id1226in_option1 = id1225out_result[getCycle()%12];

    HWFloat<8,24> id1226x_1;

    switch((id1226in_sel.getValueAsLong())) {
      case 0l:
        id1226x_1 = id1226in_option0;
        break;
      case 1l:
        id1226x_1 = id1226in_option1;
        break;
      default:
        id1226x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1226out_result[(getCycle()+1)%2] = (id1226x_1);
  }
  HWRawBits<1> id2039out_result;

  { // Node ID: 2039 (NodeSlice)
    const HWFloat<8,24> &id2039in_a = id1226out_result[getCycle()%2];

    id2039out_result = (slice<31,1>(id2039in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id1235out_result;

  { // Node ID: 1235 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1235in_a = id2349out_output[getCycle()%2];

    id1235out_result = (not_fixed(id1235in_a));
  }
  { // Node ID: 1236 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id1236in_a = id1235out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id1236in_b = id1230out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id1236x_1;

    (id1236x_1) = (and_fixed(id1236in_a,id1236in_b));
    id1236out_result[(getCycle()+1)%2] = (id1236x_1);
  }
  HWRawBits<1> id2040out_result;

  { // Node ID: 2040 (NodeXor)
    const HWRawBits<1> &id2040in_a = id2039out_result;
    const HWOffsetFix<1,0,UNSIGNED> &id2040in_b = id1236out_result[getCycle()%2];

    HWRawBits<1> id2040x_1;

    (id2040x_1) = (xor_bits(id2040in_a,(cast_fixed2bits(id2040in_b))));
    id2040out_result = (id2040x_1);
  }
  HWRawBits<31> id2038out_result;

  { // Node ID: 2038 (NodeSlice)
    const HWFloat<8,24> &id2038in_a = id1226out_result[getCycle()%2];

    id2038out_result = (slice<0,31>(id2038in_a));
  }
  HWRawBits<32> id2041out_result;

  { // Node ID: 2041 (NodeCat)
    const HWRawBits<1> &id2041in_in0 = id2040out_result;
    const HWRawBits<31> &id2041in_in1 = id2038out_result;

    id2041out_result = (cat(id2041in_in0,id2041in_in1));
  }
  HWFloat<8,24> id2042out_output;

  { // Node ID: 2042 (NodeReinterpret)
    const HWRawBits<32> &id2042in_input = id2041out_result;

    id2042out_output = (cast_bits2float<8,24>(id2042in_input));
  }
  { // Node ID: 1244 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id1244in_sel = id1243out_result;
    const HWFloat<8,24> &id1244in_option0 = id2372out_output[getCycle()%5];
    const HWFloat<8,24> &id1244in_option1 = id2042out_output;

    HWFloat<8,24> id1244x_1;

    switch((id1244in_sel.getValueAsLong())) {
      case 0l:
        id1244x_1 = id1244in_option0;
        break;
      case 1l:
        id1244x_1 = id1244in_option1;
        break;
      default:
        id1244x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id1244out_result[(getCycle()+1)%2] = (id1244x_1);
  }
  HWFloat<8,24> id2065out_output;

  { // Node ID: 2065 (NodeStreamOffset)
    const HWFloat<8,24> &id2065in_input = id1244out_result[getCycle()%2];

    id2065out_output = id2065in_input;
  }
  { // Node ID: 2337 (NodeFIFO)
    const HWFloat<8,24> &id2337in_input = id2065out_output;

    id2337out_output[(getCycle()+6)%7] = id2337in_input;
  }
  { // Node ID: 19 (NodeConstantRawBits)
  }
  { // Node ID: 20 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_sel = id8out_result[getCycle()%2];
    const HWFloat<8,24> &id20in_option0 = id2337out_output[getCycle()%7];
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
  { // Node ID: 2338 (NodeFIFO)
    const HWFloat<8,24> &id2338in_input = id20out_result[getCycle()%2];

    id2338out_output[(getCycle()+14)%15] = id2338in_input;
  }
  { // Node ID: 116 (NodeMul)
    const HWFloat<8,24> &id116in_a = id2338out_output[getCycle()%15];
    const HWFloat<8,24> &id116in_b = id111out_result[getCycle()%2];

    id116out_result[(getCycle()+8)%9] = (mul_float(id116in_a,id116in_b));
  }
  { // Node ID: 117 (NodeAdd)
    const HWFloat<8,24> &id117in_a = id2339out_output[getCycle()%23];
    const HWFloat<8,24> &id117in_b = id116out_result[getCycle()%9];

    id117out_result[(getCycle()+11)%12] = (add_float(id117in_a,id117in_b));
  }
  HWFloat<8,24> id2066out_output;

  { // Node ID: 2066 (NodeStreamOffset)
    const HWFloat<8,24> &id2066in_input = id115out_result[getCycle()%12];

    id2066out_output = id2066in_input;
  }
  { // Node ID: 2340 (NodeFIFO)
    const HWFloat<8,24> &id2340in_input = id2066out_output;

    id2340out_output[(getCycle()+56)%57] = id2340in_input;
  }
  { // Node ID: 11 (NodeConstantRawBits)
  }
  { // Node ID: 12 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id12in_sel = id8out_result[getCycle()%2];
    const HWFloat<8,24> &id12in_option0 = id2340out_output[getCycle()%57];
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
  { // Node ID: 2341 (NodeFIFO)
    const HWFloat<8,24> &id2341in_input = id12out_result[getCycle()%2];

    id2341out_output[(getCycle()+22)%23] = id2341in_input;
  }
  { // Node ID: 114 (NodeMul)
    const HWFloat<8,24> &id114in_a = id18out_result[getCycle()%2];
    const HWFloat<8,24> &id114in_b = id111out_result[getCycle()%2];

    id114out_result[(getCycle()+8)%9] = (mul_float(id114in_a,id114in_b));
  }
  { // Node ID: 115 (NodeAdd)
    const HWFloat<8,24> &id115in_a = id2341out_output[getCycle()%23];
    const HWFloat<8,24> &id115in_b = id114out_result[getCycle()%9];

    id115out_result[(getCycle()+11)%12] = (add_float(id115in_a,id115in_b));
  }
  HWFloat<8,24> id2067out_output;

  { // Node ID: 2067 (NodeStreamOffset)
    const HWFloat<8,24> &id2067in_input = id113out_result[getCycle()%12];

    id2067out_output = id2067in_input;
  }
  { // Node ID: 2342 (NodeFIFO)
    const HWFloat<8,24> &id2342in_input = id2067out_output;

    id2342out_output[(getCycle()+56)%57] = id2342in_input;
  }
  { // Node ID: 9 (NodeConstantRawBits)
  }
  { // Node ID: 10 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_sel = id8out_result[getCycle()%2];
    const HWFloat<8,24> &id10in_option0 = id2342out_output[getCycle()%57];
    const HWFloat<8,24> &id10in_option1 = id9out_value;

    HWFloat<8,24> id10x_1;

    switch((id10in_sel.getValueAsLong())) {
      case 0l:
        id10x_1 = id10in_option0;
        break;
      case 1l:
        id10x_1 = id10in_option1;
        break;
      default:
        id10x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id10out_result[(getCycle()+1)%2] = (id10x_1);
  }
  { // Node ID: 2343 (NodeFIFO)
    const HWFloat<8,24> &id2343in_input = id10out_result[getCycle()%2];

    id2343out_output[(getCycle()+22)%23] = id2343in_input;
  }
  { // Node ID: 112 (NodeMul)
    const HWFloat<8,24> &id112in_a = id16out_result[getCycle()%2];
    const HWFloat<8,24> &id112in_b = id111out_result[getCycle()%2];

    id112out_result[(getCycle()+8)%9] = (mul_float(id112in_a,id112in_b));
  }
  { // Node ID: 113 (NodeAdd)
    const HWFloat<8,24> &id113in_a = id2343out_output[getCycle()%23];
    const HWFloat<8,24> &id113in_b = id112out_result[getCycle()%9];

    id113out_result[(getCycle()+11)%12] = (add_float(id113in_a,id113in_b));
  }
  HWRawBits<128> id1688out_result;

  { // Node ID: 1688 (NodeCat)
    const HWFloat<8,24> &id1688in_in0 = id2097out_output[getCycle()%9];
    const HWFloat<8,24> &id1688in_in1 = id117out_result[getCycle()%12];
    const HWFloat<8,24> &id1688in_in2 = id115out_result[getCycle()%12];
    const HWFloat<8,24> &id1688in_in3 = id113out_result[getCycle()%12];

    id1688out_result = (cat((cat(id1688in_in0,id1688in_in1)),(cat(id1688in_in2,id1688in_in3))));
  }
  if ( (getFillLevel() >= (129l)) && (getFlushLevel() < (129l)|| !isFlushingActive() ))
  { // Node ID: 1260 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id1260in_output_control = id2345out_output[getCycle()%20];
    const HWRawBits<128> &id1260in_data = id1688out_result;

    bool id1260x_1;

    (id1260x_1) = ((id1260in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(129l))&(isFlushingActive()))));
    if((id1260x_1)) {
      writeOutput(m_z, id1260in_data);
    }
  }
  { // Node ID: 1327 (NodeConstantRawBits)
  }
  { // Node ID: 1789 (NodeConstantRawBits)
  }
  { // Node ID: 1324 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 1325 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id1325in_enable = id1789out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id1325in_max = id1324out_value;

    HWOffsetFix<49,0,UNSIGNED> id1325x_1;
    HWOffsetFix<1,0,UNSIGNED> id1325x_2;
    HWOffsetFix<1,0,UNSIGNED> id1325x_3;
    HWOffsetFix<49,0,UNSIGNED> id1325x_4t_1e_1;

    id1325out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id1325st_count)));
    (id1325x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id1325st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id1325x_2) = (gte_fixed((id1325x_1),id1325in_max));
    (id1325x_3) = (and_fixed((id1325x_2),id1325in_enable));
    id1325out_wrap = (id1325x_3);
    if((id1325in_enable.getValueAsBool())) {
      if(((id1325x_3).getValueAsBool())) {
        (id1325st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id1325x_4t_1e_1) = (id1325x_1);
        (id1325st_count) = (id1325x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id1326out_output;

  { // Node ID: 1326 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id1326in_input = id1325out_count;

    id1326out_output = id1326in_input;
  }
  if ( (getFillLevel() >= (1l)) && (getFlushLevel() < (1l)|| !isFlushingActive() ))
  { // Node ID: 1328 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id1328in_load = id1327out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id1328in_data = id1326out_output;

    bool id1328x_1;

    (id1328x_1) = ((id1328in_load.getValueAsBool())&(!(((getFlushLevel())>=(1l))&(isFlushingActive()))));
    if((id1328x_1)) {
      setMappedRegValue("current_run_cycle_count", id1328in_data);
    }
  }
  { // Node ID: 0 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 1332 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id1332in_start = id0out_value;

    if((id1332in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
