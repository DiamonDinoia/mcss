#include "stdsimheader.h"
#include "loopKernel.h"

namespace maxcompilersim {

loopKernel::loopKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 256, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_8_0_uns_bits((HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(0x5bl))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_flt_8_24_bits((HWFloat<8,24>(varint_u<32>(0x00000000l))))
, c_hw_flt_8_24_bits_1((HWFloat<8,24>(varint_u<32>(0xb7f29d06l))))
, c_hw_flt_8_24_bits_2((HWFloat<8,24>(varint_u<32>(0x7fc00000l))))
, c_hw_fix_9_0_sgn_bits((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x000l))))
, c_hw_fix_25_n23_sgn_bits((HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(0x0000000l))))
, c_hw_bit_1_bits((HWRawBits<1>(varint_u<1>(0x0l))))
, c_hw_bit_31_bits((HWRawBits<31>(varint_u<31>(0x00000000l))))
, c_hw_fix_25_n23_sgn_bits_1((HWOffsetFix<25,-23,TWOSCOMPLEMENT>(varint_u<25>(0x0c00000l))))
, c_hw_fix_7_0_uns_bits((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x7fl))))
, c_hw_fix_9_0_sgn_bits_1((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x001l))))
, c_hw_flt_8_24_bits_3((HWFloat<8,24>(varint_u<32>(0x3a7dfc62l))))
, c_hw_flt_8_24_bits_4((HWFloat<8,24>(varint_u<32>(0x3f800000l))))
, c_hw_flt_8_24_bits_5((HWFloat<8,24>(varint_u<32>(0xbf800000l))))
, c_hw_flt_8_24_bits_6((HWFloat<8,24>(varint_u<32>(0x3b2d79edl))))
, c_hw_flt_8_24_bits_7((HWFloat<8,24>(varint_u<32>(0x3aad79edl))))
, c_hw_flt_8_24_bits_8((HWFloat<8,24>(varint_u<32>(0x40000000l))))
, c_hw_flt_8_24_bits_9((HWFloat<8,24>(varint_u<32>(0x40c90fdbl))))
, c_hw_bit_31_bits_1((HWRawBits<31>(varint_u<31>(0x7f800000l))))
, c_hw_bit_8_bits((HWRawBits<8>(varint_u<8>(0xffl))))
, c_hw_bit_23_bits((HWRawBits<23>(varint_u<23>(0x000000l))))
, c_hw_fix_9_0_sgn_bits_2((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x018l))))
, c_hw_bit_185_bits((HWRawBits<185>(varint_u<185>::init(3, 0xc0db6295993c4390l, 0x29fc2757d1f534ddl, 0x0a2f9836e4e4415l))))
, c_hw_fix_80_0_uns_1_0val((HWOffsetFix<80,0,UNSIGNED>(varint_u<80>::init(2, 0x0000000000000001l, 0x0000l))))
, c_hw_fix_7_0_uns_bits_1((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x00l))))
, c_hw_fix_7_0_uns_bits_2((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x01l))))
, c_hw_fix_7_0_uns_bits_3((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x02l))))
, c_hw_fix_7_0_uns_bits_4((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x03l))))
, c_hw_fix_7_0_uns_bits_5((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x04l))))
, c_hw_fix_7_0_uns_bits_6((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x05l))))
, c_hw_fix_7_0_uns_bits_7((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x06l))))
, c_hw_fix_7_0_uns_bits_8((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x07l))))
, c_hw_fix_7_0_uns_bits_9((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x08l))))
, c_hw_fix_7_0_uns_bits_10((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x09l))))
, c_hw_fix_7_0_uns_bits_11((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x0al))))
, c_hw_fix_7_0_uns_bits_12((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x0bl))))
, c_hw_fix_7_0_uns_bits_13((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x0cl))))
, c_hw_fix_7_0_uns_bits_14((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x0dl))))
, c_hw_fix_7_0_uns_bits_15((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x0el))))
, c_hw_fix_7_0_uns_bits_16((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x0fl))))
, c_hw_fix_7_0_uns_bits_17((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x10l))))
, c_hw_fix_7_0_uns_bits_18((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x11l))))
, c_hw_fix_7_0_uns_bits_19((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x12l))))
, c_hw_fix_7_0_uns_bits_20((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x13l))))
, c_hw_fix_7_0_uns_bits_21((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x14l))))
, c_hw_fix_7_0_uns_bits_22((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x15l))))
, c_hw_fix_7_0_uns_bits_23((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x16l))))
, c_hw_fix_7_0_uns_bits_24((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x17l))))
, c_hw_fix_7_0_uns_bits_25((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x18l))))
, c_hw_fix_7_0_uns_bits_26((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x19l))))
, c_hw_fix_7_0_uns_bits_27((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x1al))))
, c_hw_fix_7_0_uns_bits_28((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x1bl))))
, c_hw_fix_7_0_uns_bits_29((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x1cl))))
, c_hw_fix_7_0_uns_bits_30((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x1dl))))
, c_hw_fix_7_0_uns_bits_31((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x1el))))
, c_hw_fix_7_0_uns_bits_32((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x1fl))))
, c_hw_fix_7_0_uns_bits_33((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x20l))))
, c_hw_fix_7_0_uns_bits_34((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x21l))))
, c_hw_fix_7_0_uns_bits_35((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x22l))))
, c_hw_fix_7_0_uns_bits_36((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x23l))))
, c_hw_fix_7_0_uns_bits_37((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x24l))))
, c_hw_fix_7_0_uns_bits_38((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x25l))))
, c_hw_fix_7_0_uns_bits_39((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x26l))))
, c_hw_fix_7_0_uns_bits_40((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x27l))))
, c_hw_fix_7_0_uns_bits_41((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x28l))))
, c_hw_fix_7_0_uns_bits_42((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x29l))))
, c_hw_fix_7_0_uns_bits_43((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x2al))))
, c_hw_fix_7_0_uns_bits_44((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x2bl))))
, c_hw_fix_7_0_uns_bits_45((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x2cl))))
, c_hw_fix_7_0_uns_bits_46((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x2dl))))
, c_hw_fix_7_0_uns_bits_47((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x2el))))
, c_hw_fix_7_0_uns_bits_48((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x2fl))))
, c_hw_fix_7_0_uns_bits_49((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x30l))))
, c_hw_fix_7_0_uns_bits_50((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x31l))))
, c_hw_fix_7_0_uns_bits_51((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x32l))))
, c_hw_fix_7_0_uns_bits_52((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x33l))))
, c_hw_fix_7_0_uns_bits_53((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x34l))))
, c_hw_fix_7_0_uns_bits_54((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x35l))))
, c_hw_fix_7_0_uns_bits_55((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x36l))))
, c_hw_fix_7_0_uns_bits_56((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x37l))))
, c_hw_fix_7_0_uns_bits_57((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x38l))))
, c_hw_fix_7_0_uns_bits_58((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x39l))))
, c_hw_fix_7_0_uns_bits_59((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x3al))))
, c_hw_fix_7_0_uns_bits_60((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x3bl))))
, c_hw_fix_7_0_uns_bits_61((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x3cl))))
, c_hw_fix_7_0_uns_bits_62((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x3dl))))
, c_hw_fix_7_0_uns_bits_63((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x3el))))
, c_hw_fix_7_0_uns_bits_64((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x3fl))))
, c_hw_fix_7_0_uns_bits_65((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x40l))))
, c_hw_fix_7_0_uns_bits_66((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x41l))))
, c_hw_fix_7_0_uns_bits_67((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x42l))))
, c_hw_fix_7_0_uns_bits_68((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x43l))))
, c_hw_fix_7_0_uns_bits_69((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x44l))))
, c_hw_fix_7_0_uns_bits_70((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x45l))))
, c_hw_fix_7_0_uns_bits_71((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x46l))))
, c_hw_fix_7_0_uns_bits_72((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x47l))))
, c_hw_fix_7_0_uns_bits_73((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x48l))))
, c_hw_fix_7_0_uns_bits_74((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x49l))))
, c_hw_fix_7_0_uns_bits_75((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x4al))))
, c_hw_fix_7_0_uns_bits_76((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x4bl))))
, c_hw_fix_7_0_uns_bits_77((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x4cl))))
, c_hw_fix_7_0_uns_bits_78((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x4dl))))
, c_hw_fix_7_0_uns_bits_79((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x4el))))
, c_hw_fix_7_0_uns_bits_80((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x4fl))))
, c_hw_fix_8_0_sgn_bits((HWOffsetFix<8,0,TWOSCOMPLEMENT>(varint_u<8>(0x4fl))))
, c_hw_fix_8_0_sgn_bits_1((HWOffsetFix<8,0,TWOSCOMPLEMENT>(varint_u<8>(0x01l))))
, c_hw_fix_9_0_sgn_bits_3((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x07fl))))
, c_hw_fix_9_0_sgn_bits_4((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x182l))))
, c_hw_fix_8_0_sgn_bits_2((HWOffsetFix<8,0,TWOSCOMPLEMENT>(varint_u<8>(0x50l))))
, c_hw_fix_8_0_sgn_bits_3((HWOffsetFix<8,0,TWOSCOMPLEMENT>(varint_u<8>(0x00l))))
, c_hw_flt_8_24_bits_10((HWFloat<8,24>(varint_u<32>(0x7f800000l))))
, c_hw_flt_8_24_bits_11((HWFloat<8,24>(varint_u<32>(0xff800000l))))
, c_hw_bit_2_bits((HWRawBits<2>(varint_u<2>(0x2l))))
, c_hw_fix_9_0_sgn_bits_5((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x007l))))
, c_hw_fix_5_0_uns_bits((HWOffsetFix<5,0,UNSIGNED>(varint_u<5>(0x00l))))
, c_hw_flt_8_24_128_0val((HWFloat<8,24>(varint_u<32>(0x43000000l))))
, c_hw_fix_9_0_sgn_bits_6((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x017l))))
, c_hw_fix_9_0_sgn_bits_7((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x1e8l))))
, c_hw_fix_9_0_sgn_bits_8((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x1ffl))))
, c_hw_fix_9_0_sgn_bits_9((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x016l))))
, c_hw_fix_9_0_sgn_bits_10((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x015l))))
, c_hw_fix_9_0_sgn_bits_11((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x014l))))
, c_hw_fix_9_0_sgn_bits_12((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x013l))))
, c_hw_fix_9_0_sgn_bits_13((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x012l))))
, c_hw_fix_9_0_sgn_bits_14((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x011l))))
, c_hw_fix_9_0_sgn_bits_15((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x010l))))
, c_hw_fix_9_0_sgn_bits_16((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x00fl))))
, c_hw_fix_9_0_sgn_bits_17((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x00el))))
, c_hw_fix_9_0_sgn_bits_18((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x00dl))))
, c_hw_fix_9_0_sgn_bits_19((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x00cl))))
, c_hw_fix_9_0_sgn_bits_20((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x00bl))))
, c_hw_fix_9_0_sgn_bits_21((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x00al))))
, c_hw_fix_9_0_sgn_bits_22((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x009l))))
, c_hw_fix_9_0_sgn_bits_23((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x008l))))
, c_hw_fix_9_0_sgn_bits_24((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x006l))))
, c_hw_fix_9_0_sgn_bits_25((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x005l))))
, c_hw_fix_9_0_sgn_bits_26((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x004l))))
, c_hw_fix_9_0_sgn_bits_27((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x003l))))
, c_hw_fix_9_0_sgn_bits_28((HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(0x002l))))
, c_hw_bit_24_bits((HWRawBits<24>(varint_u<24>(0x000000l))))
, c_hw_bit_2_bits_1((HWRawBits<2>(varint_u<2>(0x3l))))
, c_hw_bit_2_bits_2((HWRawBits<2>(varint_u<2>(0x1l))))
, c_hw_flt_11_53_bits((HWFloat<11,53>(varint_u<64>(0x3f4fbf8c3e6e7f51l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
{
  { // Node ID: 1359 (NodeConstantRawBits)
    id1359out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 2456 (NodeConstantRawBits)
    id2456out_value = (c_hw_fix_8_0_uns_bits);
  }
  { // Node ID: 1360 (NodeOutput)
    m_internal_watch_llv_output = registerOutput("internal_watch_llv_output",1 );
  }
  { // Node ID: 3 (NodeConstantRawBits)
    id3out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 25 (NodeConstantRawBits)
    id25out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 2023 (NodeConstantRawBits)
    id2023out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 27 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 29 (NodeInput)
     m_y =  registerInput("y",0,5);
  }
  { // Node ID: 2022 (NodeConstantRawBits)
    id2022out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 101 (NodeConstantRawBits)
    id101out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 2093 (NodeConstantRawBits)
    id2093out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 2092 (NodeConstantRawBits)
    id2092out_value = (c_hw_fix_25_n23_sgn_bits);
  }
  { // Node ID: 40 (NodeConstantRawBits)
    id40out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 2021 (NodeConstantRawBits)
    id2021out_value = (c_hw_bit_31_bits);
  }
  { // Node ID: 2020 (NodeConstantRawBits)
    id2020out_value = (c_hw_fix_25_n23_sgn_bits_1);
  }
  { // Node ID: 2019 (NodeConstantRawBits)
    id2019out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 2018 (NodeConstantRawBits)
    id2018out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 1310 (NodeROM)
    uint64_t data[] = {
      0x0,
      0x3f317218,
      0x3fb17218,
      0x40051592,
      0x40317218,
      0x405dce9e,
      0x40851592,
      0x409b43d5,
      0x40b17218,
      0x40c7a05b,
      0x40ddce9e,
      0x40f3fce1,
      0x41051592,
      0x41102cb3,
      0x411b43d5,
      0x41265af6,
      0x41317218,
      0x413c8939,
      0x4147a05b,
      0x4152b77c,
      0x415dce9e,
      0x4168e5bf,
      0x4173fce1,
      0x417f1402,
      0x41851592,
      0x418aa123,
      0x41902cb3,
      0x4195b844,
      0x419b43d5,
      0x41a0cf66,
      0x41a65af6,
      0x41abe687,
      0x41b17218,
      0x41b6fda9,
      0x41bc8939,
      0x41c214ca,
      0x41c7a05b,
      0x41cd2bec,
      0x41d2b77c,
      0x41d8430d,
      0x41ddce9e,
      0x41e35a2f,
      0x41e8e5bf,
      0x41ee7150,
      0x41f3fce1,
      0x41f98872,
      0x41ff1402,
      0x42024fca,
      0x42051592,
      0x4207db5a,
      0x420aa123,
      0x420d66eb,
      0x42102cb3,
      0x4212f27c,
      0x4215b844,
      0x42187e0d,
      0x421b43d5,
      0x421e099d,
      0x4220cf66,
      0x4223952e,
      0x42265af6,
      0x422920bf,
      0x422be687,
      0x422eac50,
      0x42317218,
      0x423437e0,
      0x4236fda9,
      0x4239c371,
      0x423c8939,
      0x423f4f02,
      0x424214ca,
      0x4244da93,
      0x4247a05b,
      0x424a6623,
      0x424d2bec,
      0x424ff1b4,
      0x4252b77c,
      0x42557d45,
      0x4258430d,
      0x425b08d6,
      0x425dce9e,
      0x42609466,
      0x42635a2f,
      0x42661ff7,
      0x4268e5bf,
      0x426bab88,
      0x426e7150,
      0x42713719,
      0x4273fce1,
      0x4276c2a9,
      0x42798872,
      0x427c4e3a,
      0x427f1402,
      0x4280ece5,
      0x42824fca,
      0x4283b2ae,
      0x42851592,
      0x42867876,
      0x4287db5a,
      0x42893e3f,
      0x428aa123,
      0x428c0407,
      0x428d66eb,
      0x428ec9cf,
      0x42902cb3,
      0x42918f98,
      0x4292f27c,
      0x42945560,
      0x4295b844,
      0x42971b28,
      0x42987e0d,
      0x4299e0f1,
      0x429b43d5,
      0x429ca6b9,
      0x429e099d,
      0x429f6c82,
      0x42a0cf66,
      0x42a2324a,
      0x42a3952e,
      0x42a4f812,
      0x42a65af6,
      0x42a7bddb,
      0x42a920bf,
      0x42aa83a3,
      0x42abe687,
      0x42ad496b,
      0x42aeac50,
      0x42b00f34,
      0x42b17218,
      0x42b2d4fc,
      0x42b437e0,
      0x42b59ac5,
      0x42b6fda9,
      0x42b8608d,
      0x42b9c371,
      0x42bb2655,
      0x42bc8939,
      0x42bdec1e,
      0x42bf4f02,
      0x42c0b1e6,
      0x42c214ca,
      0x42c377ae,
      0x42c4da93,
      0x42c63d77,
      0x42c7a05b,
      0x42c9033f,
      0x42ca6623,
      0x42cbc908,
      0x42cd2bec,
      0x42ce8ed0,
      0x42cff1b4,
      0x42d15498,
      0x42d2b77c,
      0x42d41a61,
      0x42d57d45,
      0x42d6e029,
      0x42d8430d,
      0x42d9a5f1,
      0x42db08d6,
      0x42dc6bba,
      0x42ddce9e,
      0x42df3182,
      0x42e09466,
      0x42e1f74b,
      0x42e35a2f,
      0x42e4bd13,
      0x42e61ff7,
      0x42e782db,
      0x42e8e5bf,
      0x42ea48a4,
      0x42ebab88,
      0x42ed0e6c,
      0x42ee7150,
      0x42efd434,
      0x42f13719,
      0x42f299fd,
      0x42f3fce1,
      0x42f55fc5,
      0x42f6c2a9,
      0x42f8258e,
      0x42f98872,
      0x42faeb56,
      0x42fc4e3a,
      0x42fdb11e,
      0x42ff1402,
      0x43003b73,
      0x4300ece5,
      0x43019e58,
      0x43024fca,
      0x4303013c,
      0x4303b2ae,
      0x43046420,
      0x43051592,
      0x4305c704,
      0x43067876,
      0x430729e8,
      0x4307db5a,
      0x43088ccc,
      0x43093e3f,
      0x4309efb1,
      0x430aa123,
      0x430b5295,
      0x430c0407,
      0x430cb579,
      0x430d66eb,
      0x430e185d,
      0x430ec9cf,
      0x430f7b41,
      0x43102cb3,
      0x4310de26,
      0x43118f98,
      0x4312410a,
      0x4312f27c,
      0x4313a3ee,
      0x43145560,
      0x431506d2,
      0x4315b844,
      0x431669b6,
      0x43171b28,
      0x4317cc9b,
      0x43187e0d,
      0x43192f7f,
      0x4319e0f1,
      0x431a9263,
      0x431b43d5,
      0x431bf547,
      0x431ca6b9,
      0x431d582b,
      0x431e099d,
      0x431ebb0f,
      0x431f6c82,
      0x43201df4,
      0x4320cf66,
      0x432180d8,
      0x4322324a,
      0x4322e3bc,
      0x4323952e,
      0x432446a0,
      0x4324f812,
      0x4325a984,
      0x43265af6,
      0x43270c69,
      0x4327bddb,
      0x43286f4d,
      0x432920bf,
      0x4329d231,
      0x432a83a3,
      0x432b3515,
      0x432be687,
      0x432c97f9,
      0x432d496b,
      0x432dfadd,
      0x432eac50,
      0x432f5dc2,
      0x43300f34,
      0x4330c0a6,
    };
    setRom< HWFloat<8,24> > (data, id1310sta_rom_store, 32, 256); 
  }
  { // Node ID: 1292 (NodeROM)
    uint64_t data[] = {
      0x2afffc0000800000,
      0xffffffe0000,
      0x2a3ffc0a907f80aa,
      0xffffffe0000,
      0x297ffc14f87f02a3,
      0xffffffe0000,
      0x28bffc1f307e85e5,
      0xffffffe0000,
      0x27fffc29387e0a6c,
      0xffffffe0000,
      0x277ffc33187d9031,
      0xffffffe0000,
      0x26bffc3cc87d1730,
      0xffffffe0000,
      0x25fffc46507c9f62,
      0xffffffe0000,
      0x257ffc4fb87c28c3,
      0xffffffe0000,
      0x24bffc58f07bb34e,
      0xffffffe0000,
      0x243ffc62007b3efd,
      0xffffffe0000,
      0x23bffc6af07acbcd,
      0xffffffe0000,
      0x22fffc73b87a59b8,
      0xffffffe0000,
      0x227ffc7c6079e8ba,
      0xffffffe0000,
      0x21fffc84e07978cf,
      0xffffffe0000,
      0x217ffc8d407909f1,
      0xffffffe0000,
      0x20fffc9580789c1e,
      0xffffffe0000,
      0x207ffc9da0782f50,
      0xffffffe0000,
      0x1ffffca59877c383,
      0xffffffe0000,
      0x1f7ffcad787758b5,
      0xffffffe0000,
      0x1efffcb53876eee0,
      0xffffffe0000,
      0x1e7ffcbcd8768601,
      0xffffffe0000,
      0x1dfffcc458761e14,
      0xffffffe0000,
      0x1d7ffccbc075b716,
      0xffffffe0000,
      0x1d3ffcd308755102,
      0xffffffe0000,
      0x1cbffcda3874ebd7,
      0xffffffe0000,
      0x1c3ffce14874878f,
      0xffffffe0000,
      0x1bfffce840742428,
      0xffffffe0000,
      0x1b7ffcef2073c19e,
      0xffffffe0000,
      0x1b3ffcf5e8735fef,
      0xffffffe0000,
      0x1abffcfc9072ff17,
      0xffffffe0000,
      0x1a3ffd0328729f12,
      0x0,
      0x19fffd09a0723fdf,
      0x0,
      0x19bffd100871e17a,
      0x0,
      0x193ffd16507183e0,
      0x0,
      0x18fffd1c8871270e,
      0x0,
      0x187ffd22a870cb02,
      0x0,
      0x183ffd28b8706fb8,
      0x0,
      0x17fffd2eb070152e,
      0x0,
      0x177ffd34906fbb62,
      0x0,
      0x173ffd3a586f6251,
      0x0,
      0x16fffd40106f09f8,
      0x0,
      0x16bffd45b86eb255,
      0x0,
      0x167ffd4b486e5b66,
      0x0,
      0x15fffd50c86e0527,
      0x0,
      0x15bffd56386daf97,
      0x0,
      0x157ffd5b906d5ab4,
      0x0,
      0x153ffd60d86d067b,
      0x0,
      0x14fffd66106cb2e9,
      0x0,
      0x14bffd6b386c5ffe,
      0x0,
      0x147ffd70486c0db6,
      0x0,
      0x143ffd75506bbc10,
      0x0,
      0x13fffd7a406b6b09,
      0x0,
      0x13bffd7f286b1a9f,
      0x0,
      0x137ffd83f86acad1,
      0x0,
      0x133ffd88c06a7b9d,
      0x0,
      0x12fffd8d706a2d00,
      0x0,
      0x12bffd921869def9,
      0x0,
      0x127ffd96b0699185,
      0x0,
      0x123ffd9b386944a4,
      0x0,
      0x11fffd9fb868f853,
      0x0,
      0x11bffda42068ac91,
      0x0,
      0x11bffda88068615b,
      0x0,
      0x117ffdacd06816b1,
      0x0,
      0x113ffdb11867cc90,
      0x0,
      0x10fffdb5506782f6,
      0x0,
      0x10bffdb9786739e3,
      0x0,
      0x10bffdbd9866f155,
      0x0,
      0x107ffdc1b066a949,
      0x0,
      0x103ffdc5b06661bf,
      0x0,
      0xffffdc9b0661ab5,
      0x0,
      0xffffdcd9865d42a,
      0x0,
      0xfbffdd180658e1c,
      0x0,
      0xf7ffdd558654889,
      0x0,
      0xf3ffdd920650370,
      0x0,
      0xf3ffddce064bed1,
      0x0,
      0xefffde098647aa8,
      0x0,
      0xebffde4486436f6,
      0x0,
      0xebffde7e863f3b9,
      0x0,
      0xe7ffdeb7863b0ef,
      0x0,
      0xe3ffdef08636e98,
      0x0,
      0xe3ffdf288632cb1,
      0x0,
      0xdfffdf60062eb3a,
      0x0,
      0xdfffdf97062aa31,
      0x0,
      0xdbffdfcd8626996,
      0x0,
      0xd7ffe0038622967,
      0x0,
      0xd7ffe038861e9a3,
      0x0,
      0xd3ffe06d061aa48,
      0x0,
      0xd3ffe0a10616b57,
      0x0,
      0xcfffe0d48612ccc,
      0x0,
      0xcfffe107860eea8,
      0x0,
      0xcbffe13a060b0ea,
      0x0,
      0xcbffe16c0607390,
      0x0,
      0xc7ffe19d0603699,
      0x0,
      0xc7ffe1ce05ffa04,
      0x0,
      0xc3ffe1fe85fbdd0,
      0x0,
      0xc3ffe22e05f81fd,
      0x0,
      0xbfffe25d85f4688,
      0x0,
      0xbfffe28c85f0b72,
      0x0,
      0xbbffe2ba85ed0b9,
      0x0,
      0xbbffe2e885e965d,
      0x0,
      0xb7ffe31605e5c5b,
      0x0,
      0xb7ffe34305e22b4,
      0x0,
      0xb3ffe36f85de967,
      0x0,
      0xb3ffe39b85db072,
      0x0,
      0xafffe3c785d77d5,
      0x0,
      0xafffe3f285d3f8f,
      0x0,
      0xafffe41d85d079f,
      0x0,
      0xabffe44785cd004,
      0x0,
      0xabffe47185c98bd,
      0x0,
      0xa7ffe49b05c61ca,
      0x0,
      0xa7ffe4c485c2b2a,
      0x0,
      0xa7ffe4ed05bf4db,
      0x0,
      0xa3ffe51585bbede,
      0x0,
      0xa3ffe53d85b8930,
      0x0,
      0x9fffe56505b53d3,
      0x0,
      0x9fffe58c05b1ec4,
      0x0,
      0x9fffe5b305aea03,
      0x0,
      0x9bffe5d985ab58f,
      0x0,
      0x9bffe5ff85a8169,
      0x0,
      0x9bffe62585a4d8d,
      0x0,
      0x97ffe64a85a19fd,
      0x0,
      0x97ffe66f859e6b8,
      0x0,
      0x97ffe694859b3bc,
      0x0,
      0x93ffe6b90598109,
      0x0,
      0x93ffe6dd0594e9f,
      0x0,
      0x93ffe7008591c7d,
      0x0,
      0x8fffe724058eaa1,
      0x0,
    };
    setRom< HWRawBits<108> > (data, id1292sta_rom_store, 108, 128); 
  }
  { // Node ID: 1301 (NodeROM)
    uint64_t data[] = {
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0x0,
      0xbdc0000000000000,
      0x2571bf19049,
      0x96c027bebf6cb4ef,
      0xabfffa,
      0xd6c0266c6f719777,
      0xa1fffa,
      0x13002529af7650af,
      0x99fffb,
      0x4bc023f5877ae27c,
      0x8ffffb,
      0x810022cf1f7f4ea2,
      0x87fffb,
      0xb38021b5b78396cd,
      0x7ffffb,
      0xe30020a87f87bc90,
      0x79fffb,
      0xfc01fa6d78bc166,
      0x71fffc,
      0x3a001eb00f8fa6b7,
      0x6bfffc,
      0x62401dc397936dd6,
      0x67fffc,
      0x88001ce0df971803,
      0x61fffc,
      0xac001c075f9aa66e,
      0x5bfffc,
      0xce001b36979e1a36,
      0x57fffc,
      0xee401a6e1fa1746b,
      0x53fffc,
      0xcc019ad7fa4b610,
      0x4ffffd,
      0x2a0018f457a7e019,
      0x4bfffd,
      0x4580184247aaf36f,
      0x47fffd,
      0x5fc01796efadf0f0,
      0x43fffd,
      0x78c016f1ffb0d96e,
      0x41fffd,
      0x908016532fb3adb0,
      0x3dfffd,
      0xa74015ba27b66e76,
      0x3bfffd,
      0xbcc01526afb91c74,
      0x37fffd,
      0xd180149877bbb858,
      0x35fffd,
      0xe500140f47be42c6,
      0x33fffd,
      0xf800138ae7c0bc5c,
      0x31fffd,
      0x9c0130b1fc325b0,
      0x2ffffe,
      0x1b00128fb7c57f51,
      0x2dfffe,
      0x2b4012187fc7c9c9,
      0x2bfffe,
      0x3b0011a547ca059a,
      0x29fffe,
      0x4a001135e7cc3342,
      0x27fffe,
      0x584010ca2fce5339,
      0x25fffe,
      0x66001061f7d065f1,
      0x25fffe,
      0x73400ffd1fd26bd9,
      0x23fffe,
      0x7fc00f9b87d4655a,
      0x21fffe,
      0x8c000f3cffd652da,
      0x1ffffe,
      0x97800ee16fd834b8,
      0x1ffffe,
      0xa2c00e88bfda0b53,
      0x1dfffe,
      0xad800e32bfdbd703,
      0x1dfffe,
      0xb7c00ddf67dd981d,
      0x1bfffe,
      0xc1c00d8e97df4ef6,
      0x1bfffe,
      0xcb400d402fe0fbdb,
      0x19fffe,
      0xd4400cf417e29f18,
      0x19fffe,
      0xdd000caa47e438f7,
      0x17fffe,
      0xe5800c6297e5c9bf,
      0x17fffe,
      0xedc00c1cffe751b3,
      0x15fffe,
      0xf5800bd967e8d113,
      0x15fffe,
      0xfd000b97bfea4820,
      0x15fffe,
      0x4800b57efebb715,
      0x13ffff,
      0xb800b19e7ed1e2d,
      0x13ffff,
      0x12400add9fee7da0,
      0x13ffff,
      0x18c00aa2f7efd5a4,
      0x11ffff,
      0x1f000a69eff1266e,
      0x11ffff,
      0x25000a3277f2702f,
      0x11ffff,
      0x2b0009fc77f3b31a,
      0x11ffff,
      0x30c009c7eff4ef5c,
      0xfffff,
      0x36400994c7f62523,
      0xfffff,
      0x3b800962fff7549b,
      0xfffff,
      0x408009327ff87dee,
      0xfffff,
      0x458009033ff9a146,
      0xdffff,
      0x4a4008d537fabeca,
      0xdffff,
      0x4f0008a85ffbd69f,
      0xdffff,
      0x5380087caffce8ec,
      0xdffff,
      0x57c008520ffdf5d5,
      0xdffff,
      0x5c00082887fefd7b,
      0xbffff,
    };
    setRom< HWRawBits<108> > (data, id1301sta_rom_store, 108, 128); 
  }
  { // Node ID: 1268 (NodeConstantRawBits)
    id1268out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 2017 (NodeConstantRawBits)
    id2017out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 11 (NodeConstantRawBits)
    id11out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 2016 (NodeConstantRawBits)
    id2016out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 2015 (NodeConstantRawBits)
    id2015out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 129 (NodeConstantRawBits)
    id129out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 130 (NodeConstantRawBits)
    id130out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 2014 (NodeConstantRawBits)
    id2014out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 2013 (NodeConstantRawBits)
    id2013out_value = (c_hw_flt_8_24_bits_6);
  }
  { // Node ID: 2012 (NodeConstantRawBits)
    id2012out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 2011 (NodeConstantRawBits)
    id2011out_value = (c_hw_flt_8_24_bits_7);
  }
  { // Node ID: 2010 (NodeConstantRawBits)
    id2010out_value = (c_hw_flt_8_24_bits_8);
  }
  { // Node ID: 2009 (NodeConstantRawBits)
    id2009out_value = (c_hw_flt_8_24_bits_9);
  }
  { // Node ID: 1177 (NodeConstantRawBits)
    id1177out_value = (c_hw_bit_31_bits_1);
  }
  { // Node ID: 1182 (NodeConstantRawBits)
    id1182out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 2008 (NodeConstantRawBits)
    id2008out_value = (c_hw_bit_23_bits);
  }
  { // Node ID: 672 (NodeConstantRawBits)
    id672out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 2006 (NodeConstantRawBits)
    id2006out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 2005 (NodeConstantRawBits)
    id2005out_value = (c_hw_fix_9_0_sgn_bits_2);
  }
  { // Node ID: 683 (NodeConstantRawBits)
    id683out_value = (c_hw_bit_185_bits);
  }
  { // Node ID: 2091 (NodeConstantRawBits)
    id2091out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 2001 (NodeConstantRawBits)
    id2001out_value = (c_hw_fix_8_0_sgn_bits);
  }
  { // Node ID: 2000 (NodeConstantRawBits)
    id2000out_value = (c_hw_fix_8_0_sgn_bits_1);
  }
  { // Node ID: 1999 (NodeConstantRawBits)
    id1999out_value = (c_hw_fix_9_0_sgn_bits_3);
  }
  { // Node ID: 1998 (NodeConstantRawBits)
    id1998out_value = (c_hw_fix_9_0_sgn_bits_4);
  }
  { // Node ID: 1997 (NodeConstantRawBits)
    id1997out_value = (c_hw_fix_9_0_sgn_bits_3);
  }
  { // Node ID: 1357 (NodeConstantRawBits)
    id1357out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 1996 (NodeConstantRawBits)
    id1996out_value = (c_hw_fix_8_0_sgn_bits_2);
  }
  { // Node ID: 1995 (NodeConstantRawBits)
    id1995out_value = (c_hw_fix_8_0_sgn_bits_1);
  }
  { // Node ID: 1994 (NodeConstantRawBits)
    id1994out_value = (c_hw_fix_8_0_sgn_bits_3);
  }
  { // Node ID: 741 (NodeConstantRawBits)
    id741out_value = (c_hw_flt_8_24_bits_10);
  }
  { // Node ID: 745 (NodeConstantRawBits)
    id745out_value = (c_hw_flt_8_24_bits_11);
  }
  { // Node ID: 1993 (NodeConstantRawBits)
    id1993out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1992 (NodeConstantRawBits)
    id1992out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 2007 (NodeConstantRawBits)
    id2007out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 2004 (NodeConstantRawBits)
    id2004out_value = (c_hw_bit_2_bits);
  }
  { // Node ID: 1991 (NodeConstantRawBits)
    id1991out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 1990 (NodeConstantRawBits)
    id1990out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 765 (NodeConstantRawBits)
    id765out_value = (c_hw_fix_5_0_uns_bits);
  }
  { // Node ID: 2090 (NodeConstantRawBits)
    id2090out_value = (c_hw_fix_25_n23_sgn_bits);
  }
  { // Node ID: 757 (NodeConstantRawBits)
    id757out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1989 (NodeConstantRawBits)
    id1989out_value = (c_hw_bit_31_bits);
  }
  { // Node ID: 779 (NodeConstantRawBits)
    id779out_value = (c_hw_fix_7_0_uns_bits_1);
  }
  { // Node ID: 1329 (NodeROM)
    uint64_t data[] = {
      0x3c490fdb00000000,
      0xb4a55cf2aca33598,
      0x3c490bfa3c490e90,
      0xb4a55692b5780c60,
      0x3c49005a3cc90ab0,
      0xb4a549d2b5f80770,
      0x3c48ecfa3d16c32c,
      0xb4a536b3b639ff8f,
      0x3c48d1db3d48fb30,
      0xb4a51d36b677f43b,
      0x3c48aefd3d7b2b74,
      0xb4a4fd5ab69aefac,
      0x3c4884643d96a905,
      0xb4a4d723b6b9df41,
      0x3c48520f3dafb680,
      0xb4a4aa90b6d8c7ac,
      0x3c4818013dc8bd36,
      0xb4a477a4b6f7a7bc,
      0x3c47d63c3de1bc2e,
      0xb4a43e61b70b3f1f,
      0x3c478cc33dfab273,
      0xb4a3fec9b71aa503,
      0x3c473b993e09cf86,
      0xb4a3b8dfb72a04f0,
      0x3c46e2c03e164083,
      0xb4a36ca5b7395e4f,
      0x3c46823c3e22abb6,
      0xb4a31a1db748b088,
      0x3c461a113e2f10a2,
      0xb4a2c14cb757fb05,
      0x3c45aa433e3b6ecf,
      0xb4a26235b7673d2e,
      0x3c4532d63e47c5c2,
      0xb4a1fcdbb776766d,
      0x3c44b3cf3e541501,
      0xb4a19142b782d316,
      0x3c442d333e605c13,
      0xb4a11f6fb78a65ea,
      0x3c439f063e6c9a7f,
      0xb4a0a766b791f368,
      0x3c43094f3e78cfcc,
      0xb4a0292bb7997b46,
      0x3c426c123e827dc0,
      0xb49fa4c3b7a0fd39,
      0x3c41c7573e888e93,
      0xb49f1a33b7a878f7,
      0x3c411b243e8e9a22,
      0xb49e8982b7afee36,
      0x3c40677e3e94a031,
      0xb49df2b4b7b75cad,
      0x3c3fac6e3e9aa086,
      0xb49d55ceb7bec412,
      0x3c3ee9fa3ea09ae5,
      0xb49cb2d8b7c6241d,
      0x3c3e202a3ea68f12,
      0xb49c09d8b7cd7c84,
      0x3c3d4f053eac7cd4,
      0xb49b5ad3b7d4ccff,
      0x3c3c76943eb263ef,
      0xb49aa5d2b7dc1545,
      0x3c3b96df3eb8442a,
      0xb499eadab7e35510,
      0x3c3aafee3ebe1d4a,
      0xb49929f2b7ea8c17,
      0x3c39c1cb3ec3ef15,
      0xb4986324b7f1ba13,
      0x3c38cc7e3ec9b953,
      0xb4979675b7f8debd,
      0x3c37d0123ecf7bca,
      0xb496c3eeb7fff9cf,
      0x3c36cc903ed53641,
      0xb495eb97b8038582,
      0x3c35c2013edae880,
      0xb4950d79b8070909,
      0x3c34b0713ee0924f,
      0xb494299bb80a875d,
      0x3c3397e93ee63375,
      0xb4934007b80e0058,
      0x3c3278753eebcbbb,
      0xb49250c6b81173db,
      0x3c31521f3ef15aea,
      0xb4915be1b814e1c2,
      0x3c3024f43ef6e0cb,
      0xb4906161b81849eb,
      0x3c2ef0fe3efc5d27,
      0xb48f6150b81bac36,
      0x3c2db6493f00e7e4,
      0xb48e5bb8b81f0880,
      0x3c2c74e23f039c3d,
      0xb48d50a4b8225ea8,
      0x3c2b2cd53f064b82,
      0xb48c401cb825ae8e,
      0x3c29de2e3f08f59b,
      0xb48b2a2cb828f811,
      0x3c2888fb3f0b9a6b,
      0xb48a0edfb82c3b10,
      0x3c272d483f0e39da,
      0xb488ee3fb82f776c,
      0x3c25cb243f10d3cd,
      0xb487c858b832ad03,
      0x3c24629b3f13682a,
      0xb4869d35b835dbb7,
      0x3c22f3bc3f15f6d9,
      0xb4856ce1b8390369,
      0x3c217e953f187fc0,
      0xb4843768b83c23f8,
      0x3c2003333f1b02c6,
      0xb482fcd6b83f3d47,
      0x3c1e81a73f1d7fd1,
      0xb481bd38b8424f36,
      0x3c1cf9fe3f1ff6cb,
      0xb4807899b84559a7,
      0x3c1b6c483f226799,
      0xb47e5e0cb8485c7c,
      0x3c19d8943f24d225,
      0xb47bc118b84b5799,
      0x3c183ef13f273656,
      0xb4791a6fb84e4ade,
      0x3c169f703f299415,
      0xb4766a2cb851362f,
      0x3c14fa213f2beb4a,
      0xb473b068b854196f,
      0x3c134f133f2e3bde,
      0xb470ed40b856f482,
      0x3c119e573f3085bb,
      0xb46e20ceb859c74c,
      0x3c0fe7fe3f32c8c9,
      0xb46b4b2db85c91b0,
      0x3c0e2c193f3504f3,
      0xb4686c7ab85f5394,
      0x3c0c6ab83f373a23,
      0xb46584d2b8620cdb,
      0x3c0aa3ee3f396842,
      0xb4629450b864bd6b,
      0x3c08d7cc3f3b8f3b,
      0xb45f9b12b867652a,
      0x3c0706623f3daef9,
      0xb45c9935b86a03fd,
      0x3c052fc53f3fc767,
      0xb4598ed7b86c99ca,
      0x3c0354043f41d870,
      0xb4567c16b86f2678,
      0x3c0173343f43e200,
      0xb4536110b871a9ee,
      0x3bff1acc3f45e403,
      0xb4503de3b8742413,
      0x3bfb455a3f47de65,
      0xb44d12b0b87694ce,
      0x3bf766393f49d112,
      0xb449df94b878fc08,
      0x3bf37d8d3f4bbbf8,
      0xb446a4b0b87b59a8,
      0x3bef8b7f3f4d9f02,
      0xb4436224b87dad98,
      0x3beb90343f4f7a1f,
      0xb440180fb87ff7bf,
      0x3be78bd53f514d3d,
      0xb43cc692b8811c05,
      0x3be37e883f531849,
      0xb4396dcfb882372f,
      0x3bdf68763f54db31,
      0xb4360de5b8834d55,
      0x3bdb49c73f5695e5,
      0xb432a6f6b8845e6a,
      0x3bd722a43f584853,
      0xb42f3924b8856a65,
      0x3bd2f3353f59f26a,
      0xb42bc491b886713c,
      0x3bcebba53f5b941a,
      0xb428495fb88772e3,
      0x3bca7c1c3f5d2d53,
      0xb424c7afb8886f52,
      0x3bc634c53f5ebe05,
      0xb4213fa6b889667e,
      0x3bc1e5c93f604621,
      0xb41db165b88a585e,
      0x3bbd8f543f61c598,
      0xb41a1d0fb88b44e9,
      0x3bb931903f633c5a,
      0xb41682c9b88c2c15,
      0x3bb4cca83f64aa59,
      0xb412e2b5b88d0dda,
      0x3bb060c83f660f88,
      0xb40f3cf7b88dea2e,
      0x3babee1b3f676bd8,
      0xb40b91b4b88ec10a,
      0x3ba774ce3f68bf3c,
      0xb407e10fb88f9265,
      0x3ba2f50b3f6a09a7,
      0xb4042b2db8905e37,
      0x3b9e6f003f6b4b0c,
      0xb4007033b8912479,
      0x3b99e2da3f6c835e,
      0xb3f9608ab891e522,
      0x3b9550c53f6db293,
      0xb3f1d711b892a02a,
      0x3b90b8ee3f6ed89e,
      0xb3ea4446b893558c,
      0x3b8c1b833f6ff573,
      0xb3e2a872b8940540,
      0x3b8778b13f710908,
      0xb3db03e1b894af3f,
      0x3b82d0a63f721352,
      0xb3d356deb8955382,
      0x3b7c471f3f731447,
      0xb3cba1b6b895f203,
      0x3b72e3393f740bdd,
      0xb3c3e4b4b8968abd,
      0x3b6975f63f74fa0b,
      0xb3bc2025b8971da9,
      0x3b5fffb33f75dec6,
      0xb3b45455b897aac1,
      0x3b5680cd3f76ba07,
      0xb3ac8191b8983201,
      0x3b4cf9a23f778bc5,
      0xb3a4a826b898b363,
      0x3b436a903f7853f8,
      0xb39cc863b8992ee1,
      0x3b39d3f53f791298,
      0xb394e294b899a478,
      0x3b3036303f79c79d,
      0xb38cf708b89a1422,
      0x3b2691a03f7a7302,
      0xb385060cb89a7ddb,
      0x3b1ce6a43f7b14be,
      0xb37a1fe0b89ae1a0,
      0x3b13359c3f7baccd,
      0xb36a2a03b89b3f6c,
      0x3b097ee73f7c3b28,
      0xb35a2b1eb89b973c,
      0x3aff85c93f7cbfc9,
      0xb34a23d1b89be90d,
      0x3aec03eb3f7d3aac,
      0xb33a14b8b89c34da,
      0x3ad878f33f7dabcc,
      0xb329fe73b89c7aa2,
      0x3ac4e5a33f7e1324,
      0xb319e1a0b89cba62,
      0x3ab14abb3f7e70b0,
      0xb309bedeb89cf417,
      0x3a9da8fe3f7ec46d,
      0xb2f32d9ab89d27be,
      0x3a8a012d3f7f0e58,
      0xb2d2d418b89d5557,
      0x3a6ca8123f7f4e6d,
      0xb2b27275b89d7cdf,
      0x3a4544ac3f7f84ab,
      0xb29209f1b89d9e54,
      0x3a1dd9ab3f7fb10f,
      0xb2633797b89db9b6,
      0x39ecd1273f7fd397,
      0xb2225289b89dcf03,
      0x399de5d73f7fec43,
      0xb1c2ce73b89dde3b,
      0x391de8e33f7ffb11,
      0xb101e0a3b89de75d,
    };
    setRom< HWRawBits<128> > (data, id1329sta_rom_store, 128, 128); 
  }
  { // Node ID: 1988 (NodeConstantRawBits)
    id1988out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 1987 (NodeConstantRawBits)
    id1987out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 966 (NodeConstantRawBits)
    id966out_value = (c_hw_fix_5_0_uns_bits);
  }
  { // Node ID: 2089 (NodeConstantRawBits)
    id2089out_value = (c_hw_fix_25_n23_sgn_bits);
  }
  { // Node ID: 958 (NodeConstantRawBits)
    id958out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1986 (NodeConstantRawBits)
    id1986out_value = (c_hw_bit_31_bits);
  }
  { // Node ID: 980 (NodeConstantRawBits)
    id980out_value = (c_hw_fix_7_0_uns_bits_1);
  }
  { // Node ID: 1338 (NodeROM)
    uint64_t data[] = {
      0x3f800000,
      0x3101e0a3b89dea68,
      0xb91de8e33f7ffb11,
      0x31c2ce73b89de75d,
      0xb99de5d73f7fec43,
      0x32225289b89dde3b,
      0xb9ecd1273f7fd397,
      0x32633797b89dcf03,
      0xba1dd9ab3f7fb10f,
      0x329209f1b89db9b6,
      0xba4544ac3f7f84ab,
      0x32b27275b89d9e54,
      0xba6ca8123f7f4e6d,
      0x32d2d418b89d7cdf,
      0xba8a012d3f7f0e58,
      0x32f32d9ab89d5557,
      0xba9da8fe3f7ec46d,
      0x3309bedeb89d27be,
      0xbab14abb3f7e70b0,
      0x3319e1a0b89cf416,
      0xbac4e5a33f7e1324,
      0x3329fe73b89cba62,
      0xbad878f33f7dabcc,
      0x333a14b8b89c7aa2,
      0xbaec03eb3f7d3aac,
      0x334a23d1b89c34da,
      0xbaff85c93f7cbfc9,
      0x335a2b1eb89be90c,
      0xbb097ee73f7c3b28,
      0x336a2a03b89b973c,
      0xbb13359c3f7baccd,
      0x337a1fe0b89b3f6c,
      0xbb1ce6a43f7b14be,
      0x3385060cb89ae1a0,
      0xbb2691a03f7a7302,
      0x338cf708b89a7ddb,
      0xbb3036303f79c79d,
      0x3394e294b89a1421,
      0xbb39d3f53f791298,
      0x339cc863b899a477,
      0xbb436a903f7853f8,
      0x33a4a826b8992ee1,
      0xbb4cf9a23f778bc5,
      0x33ac8191b898b362,
      0xbb5680cd3f76ba07,
      0x33b45455b8983201,
      0xbb5fffb33f75dec6,
      0x33bc2025b897aac1,
      0xbb6975f63f74fa0b,
      0x33c3e4b4b8971da9,
      0xbb72e3393f740bdd,
      0x33cba1b6b8968abd,
      0xbb7c471f3f731447,
      0x33d356deb895f203,
      0xbb82d0a63f721352,
      0x33db03e1b8955381,
      0xbb8778b13f710908,
      0x33e2a872b894af3e,
      0xbb8c1b833f6ff573,
      0x33ea4446b894053f,
      0xbb90b8ee3f6ed89e,
      0x33f1d711b893558c,
      0xbb9550c53f6db293,
      0x33f9608ab892a02a,
      0xbb99e2da3f6c835e,
      0x34007033b891e521,
      0xbb9e6f003f6b4b0c,
      0x34042b2db8912478,
      0xbba2f50b3f6a09a7,
      0x3407e10fb8905e37,
      0xbba774ce3f68bf3c,
      0x340b91b4b88f9265,
      0xbbabee1b3f676bd8,
      0x340f3cf7b88ec10a,
      0xbbb060c83f660f88,
      0x3412e2b5b88dea2e,
      0xbbb4cca83f64aa59,
      0x341682c9b88d0dd9,
      0xbbb931903f633c5a,
      0x341a1d0fb88c2c14,
      0xbbbd8f543f61c598,
      0x341db165b88b44e8,
      0xbbc1e5c93f604621,
      0x34213fa6b88a585d,
      0xbbc634c53f5ebe05,
      0x3424c7afb889667d,
      0xbbca7c1c3f5d2d53,
      0x3428495fb8886f51,
      0xbbcebba53f5b941a,
      0x342bc491b88772e2,
      0xbbd2f3353f59f26a,
      0x342f3924b886713b,
      0xbbd722a43f584853,
      0x3432a6f6b8856a65,
      0xbbdb49c73f5695e5,
      0x34360de5b8845e69,
      0xbbdf68763f54db31,
      0x34396dcfb8834d54,
      0xbbe37e883f531849,
      0x343cc692b882372e,
      0xbbe78bd53f514d3d,
      0x3440180fb8811c04,
      0xbbeb90343f4f7a1f,
      0x34436224b87ff7be,
      0xbbef8b7f3f4d9f02,
      0x3446a4b0b87dad96,
      0xbbf37d8d3f4bbbf8,
      0x3449df94b87b59a6,
      0xbbf766393f49d112,
      0x344d12b0b878fc06,
      0xbbfb455a3f47de65,
      0x34503de3b87694cc,
      0xbbff1acc3f45e403,
      0x34536110b8742411,
      0xbc0173343f43e200,
      0x34567c16b871a9ec,
      0xbc0354043f41d870,
      0x34598ed7b86f2676,
      0xbc052fc53f3fc767,
      0x345c9935b86c99c8,
      0xbc0706623f3daef9,
      0x345f9b12b86a03fb,
      0xbc08d7cc3f3b8f3b,
      0x34629450b8676528,
      0xbc0aa3ee3f396842,
      0x346584d2b864bd69,
      0xbc0c6ab83f373a23,
      0x34686c7ab8620cd9,
      0xbc0e2c193f3504f3,
      0x346b4b2db85f5392,
      0xbc0fe7fe3f32c8c9,
      0x346e20ceb85c91ae,
      0xbc119e573f3085bb,
      0x3470ed40b859c74a,
      0xbc134f133f2e3bde,
      0x3473b068b856f481,
      0xbc14fa213f2beb4a,
      0x34766a2cb854196d,
      0xbc169f703f299415,
      0x34791a6fb851362d,
      0xbc183ef13f273656,
      0x347bc118b84e4adc,
      0xbc19d8943f24d225,
      0x347e5e0cb84b5797,
      0xbc1b6c483f226799,
      0x34807899b8485c7a,
      0xbc1cf9fe3f1ff6cb,
      0x3481bd38b84559a5,
      0xbc1e81a73f1d7fd1,
      0x3482fcd6b8424f34,
      0xbc2003333f1b02c6,
      0x34843768b83f3d45,
      0xbc217e953f187fc0,
      0x34856ce1b83c23f6,
      0xbc22f3bc3f15f6d9,
      0x34869d35b8390367,
      0xbc24629b3f13682a,
      0x3487c858b835dbb5,
      0xbc25cb243f10d3cd,
      0x3488ee3fb832ad01,
      0xbc272d483f0e39da,
      0x348a0edfb82f776a,
      0xbc2888fb3f0b9a6b,
      0x348b2a2cb82c3b0e,
      0xbc29de2e3f08f59b,
      0x348c401cb828f80f,
      0xbc2b2cd53f064b82,
      0x348d50a4b825ae8c,
      0xbc2c74e23f039c3d,
      0x348e5bb8b8225ea6,
      0xbc2db6493f00e7e4,
      0x348f6150b81f087e,
      0xbc2ef0fe3efc5d27,
      0x34906161b81bac34,
      0xbc3024f43ef6e0cb,
      0x34915be1b81849e9,
      0xbc31521f3ef15aea,
      0x349250c6b814e1c0,
      0xbc3278753eebcbbb,
      0x34934007b81173d9,
      0xbc3397e93ee63375,
      0x3494299bb80e0056,
      0xbc34b0713ee0924f,
      0x34950d79b80a875a,
      0xbc35c2013edae880,
      0x3495eb97b8070907,
      0xbc36cc903ed53641,
      0x3496c3eeb803857f,
      0xbc37d0123ecf7bca,
      0x34979675b7fff9cb,
      0xbc38cc7e3ec9b953,
      0x34986324b7f8deb9,
      0xbc39c1cb3ec3ef15,
      0x349929f2b7f1ba0e,
      0xbc3aafee3ebe1d4a,
      0x3499eadab7ea8c12,
      0xbc3b96df3eb8442a,
      0x349aa5d2b7e3550b,
      0xbc3c76943eb263ef,
      0x349b5ad3b7dc1541,
      0xbc3d4f053eac7cd4,
      0x349c09d8b7d4ccfa,
      0xbc3e202a3ea68f12,
      0x349cb2d8b7cd7c7f,
      0xbc3ee9fa3ea09ae5,
      0x349d55ceb7c62418,
      0xbc3fac6e3e9aa086,
      0x349df2b4b7bec40d,
      0xbc40677e3e94a031,
      0x349e8982b7b75ca8,
      0xbc411b243e8e9a22,
      0x349f1a33b7afee31,
      0xbc41c7573e888e93,
      0x349fa4c3b7a878f2,
      0xbc426c123e827dc0,
      0x34a0292bb7a0fd34,
      0xbc43094f3e78cfcc,
      0x34a0a766b7997b41,
      0xbc439f063e6c9a7f,
      0x34a11f6fb791f363,
      0xbc442d333e605c13,
      0x34a19142b78a65e5,
      0xbc44b3cf3e541501,
      0x34a1fcdbb782d311,
      0xbc4532d63e47c5c2,
      0x34a26235b7767663,
      0xbc45aa433e3b6ecf,
      0x34a2c14cb7673d24,
      0xbc461a113e2f10a2,
      0x34a31a1db757fafb,
      0xbc46823c3e22abb6,
      0x34a36ca4b748b07e,
      0xbc46e2c03e164083,
      0x34a3b8dfb7395e44,
      0xbc473b993e09cf86,
      0x34a3fec9b72a04e5,
      0xbc478cc33dfab273,
      0x34a43e61b71aa4f8,
      0xbc47d63c3de1bc2e,
      0x34a477a4b70b3f15,
      0xbc4818013dc8bd36,
      0x34a4aa90b6f7a7a7,
      0xbc48520f3dafb680,
      0x34a4d723b6d8c798,
      0xbc4884643d96a905,
      0x34a4fd5ab6b9df2d,
      0xbc48aefd3d7b2b74,
      0x34a51d36b69aef98,
      0xbc48d1db3d48fb30,
      0x34a536b3b677f413,
      0xbc48ecfa3d16c32c,
      0x34a549d2b639ff67,
      0xbc49005a3cc90ab0,
      0x34a55692b5f8071e,
      0xbc490bfa3c490e90,
      0x34a55cf2b5780bbd,
    };
    setRom< HWRawBits<128> > (data, id1338sta_rom_store, 128, 128); 
  }
  { // Node ID: 1984 (NodeConstantRawBits)
    id1984out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 1983 (NodeConstantRawBits)
    id1983out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 1982 (NodeConstantRawBits)
    id1982out_value = (c_hw_fix_9_0_sgn_bits_7);
  }
  { // Node ID: 1981 (NodeConstantRawBits)
    id1981out_value = (c_hw_fix_9_0_sgn_bits_8);
  }
  { // Node ID: 1980 (NodeConstantRawBits)
    id1980out_value = (c_hw_fix_9_0_sgn_bits_9);
  }
  { // Node ID: 1979 (NodeConstantRawBits)
    id1979out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 942 (NodeConstantRawBits)
    id942out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1978 (NodeConstantRawBits)
    id1978out_value = (c_hw_fix_9_0_sgn_bits_10);
  }
  { // Node ID: 936 (NodeConstantRawBits)
    id936out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1977 (NodeConstantRawBits)
    id1977out_value = (c_hw_fix_9_0_sgn_bits_11);
  }
  { // Node ID: 930 (NodeConstantRawBits)
    id930out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1976 (NodeConstantRawBits)
    id1976out_value = (c_hw_fix_9_0_sgn_bits_12);
  }
  { // Node ID: 924 (NodeConstantRawBits)
    id924out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1975 (NodeConstantRawBits)
    id1975out_value = (c_hw_fix_9_0_sgn_bits_13);
  }
  { // Node ID: 918 (NodeConstantRawBits)
    id918out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1974 (NodeConstantRawBits)
    id1974out_value = (c_hw_fix_9_0_sgn_bits_14);
  }
  { // Node ID: 912 (NodeConstantRawBits)
    id912out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1973 (NodeConstantRawBits)
    id1973out_value = (c_hw_fix_9_0_sgn_bits_15);
  }
  { // Node ID: 906 (NodeConstantRawBits)
    id906out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1972 (NodeConstantRawBits)
    id1972out_value = (c_hw_fix_9_0_sgn_bits_16);
  }
  { // Node ID: 900 (NodeConstantRawBits)
    id900out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1971 (NodeConstantRawBits)
    id1971out_value = (c_hw_fix_9_0_sgn_bits_17);
  }
  { // Node ID: 894 (NodeConstantRawBits)
    id894out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1970 (NodeConstantRawBits)
    id1970out_value = (c_hw_fix_9_0_sgn_bits_18);
  }
  { // Node ID: 888 (NodeConstantRawBits)
    id888out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1969 (NodeConstantRawBits)
    id1969out_value = (c_hw_fix_9_0_sgn_bits_19);
  }
  { // Node ID: 882 (NodeConstantRawBits)
    id882out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1968 (NodeConstantRawBits)
    id1968out_value = (c_hw_fix_9_0_sgn_bits_20);
  }
  { // Node ID: 876 (NodeConstantRawBits)
    id876out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1967 (NodeConstantRawBits)
    id1967out_value = (c_hw_fix_9_0_sgn_bits_21);
  }
  { // Node ID: 870 (NodeConstantRawBits)
    id870out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1966 (NodeConstantRawBits)
    id1966out_value = (c_hw_fix_9_0_sgn_bits_22);
  }
  { // Node ID: 864 (NodeConstantRawBits)
    id864out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1965 (NodeConstantRawBits)
    id1965out_value = (c_hw_fix_9_0_sgn_bits_23);
  }
  { // Node ID: 858 (NodeConstantRawBits)
    id858out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1964 (NodeConstantRawBits)
    id1964out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 852 (NodeConstantRawBits)
    id852out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1963 (NodeConstantRawBits)
    id1963out_value = (c_hw_fix_9_0_sgn_bits_24);
  }
  { // Node ID: 846 (NodeConstantRawBits)
    id846out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1962 (NodeConstantRawBits)
    id1962out_value = (c_hw_fix_9_0_sgn_bits_25);
  }
  { // Node ID: 840 (NodeConstantRawBits)
    id840out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1961 (NodeConstantRawBits)
    id1961out_value = (c_hw_fix_9_0_sgn_bits_26);
  }
  { // Node ID: 834 (NodeConstantRawBits)
    id834out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1960 (NodeConstantRawBits)
    id1960out_value = (c_hw_fix_9_0_sgn_bits_27);
  }
  { // Node ID: 828 (NodeConstantRawBits)
    id828out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1959 (NodeConstantRawBits)
    id1959out_value = (c_hw_fix_9_0_sgn_bits_28);
  }
  { // Node ID: 822 (NodeConstantRawBits)
    id822out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1958 (NodeConstantRawBits)
    id1958out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 816 (NodeConstantRawBits)
    id816out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1957 (NodeConstantRawBits)
    id1957out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 810 (NodeConstantRawBits)
    id810out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 804 (NodeConstantRawBits)
    id804out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 787 (NodeConstantRawBits)
    id787out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1956 (NodeConstantRawBits)
    id1956out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 1955 (NodeConstantRawBits)
    id1955out_value = (c_hw_bit_24_bits);
  }
  { // Node ID: 1953 (NodeConstantRawBits)
    id1953out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 1952 (NodeConstantRawBits)
    id1952out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 1951 (NodeConstantRawBits)
    id1951out_value = (c_hw_fix_9_0_sgn_bits_7);
  }
  { // Node ID: 1950 (NodeConstantRawBits)
    id1950out_value = (c_hw_fix_9_0_sgn_bits_8);
  }
  { // Node ID: 1949 (NodeConstantRawBits)
    id1949out_value = (c_hw_fix_9_0_sgn_bits_9);
  }
  { // Node ID: 1948 (NodeConstantRawBits)
    id1948out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 1143 (NodeConstantRawBits)
    id1143out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1947 (NodeConstantRawBits)
    id1947out_value = (c_hw_fix_9_0_sgn_bits_10);
  }
  { // Node ID: 1137 (NodeConstantRawBits)
    id1137out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1946 (NodeConstantRawBits)
    id1946out_value = (c_hw_fix_9_0_sgn_bits_11);
  }
  { // Node ID: 1131 (NodeConstantRawBits)
    id1131out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1945 (NodeConstantRawBits)
    id1945out_value = (c_hw_fix_9_0_sgn_bits_12);
  }
  { // Node ID: 1125 (NodeConstantRawBits)
    id1125out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1944 (NodeConstantRawBits)
    id1944out_value = (c_hw_fix_9_0_sgn_bits_13);
  }
  { // Node ID: 1119 (NodeConstantRawBits)
    id1119out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1943 (NodeConstantRawBits)
    id1943out_value = (c_hw_fix_9_0_sgn_bits_14);
  }
  { // Node ID: 1113 (NodeConstantRawBits)
    id1113out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1942 (NodeConstantRawBits)
    id1942out_value = (c_hw_fix_9_0_sgn_bits_15);
  }
  { // Node ID: 1107 (NodeConstantRawBits)
    id1107out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1941 (NodeConstantRawBits)
    id1941out_value = (c_hw_fix_9_0_sgn_bits_16);
  }
  { // Node ID: 1101 (NodeConstantRawBits)
    id1101out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1940 (NodeConstantRawBits)
    id1940out_value = (c_hw_fix_9_0_sgn_bits_17);
  }
  { // Node ID: 1095 (NodeConstantRawBits)
    id1095out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1939 (NodeConstantRawBits)
    id1939out_value = (c_hw_fix_9_0_sgn_bits_18);
  }
  { // Node ID: 1089 (NodeConstantRawBits)
    id1089out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1938 (NodeConstantRawBits)
    id1938out_value = (c_hw_fix_9_0_sgn_bits_19);
  }
  { // Node ID: 1083 (NodeConstantRawBits)
    id1083out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1937 (NodeConstantRawBits)
    id1937out_value = (c_hw_fix_9_0_sgn_bits_20);
  }
  { // Node ID: 1077 (NodeConstantRawBits)
    id1077out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1936 (NodeConstantRawBits)
    id1936out_value = (c_hw_fix_9_0_sgn_bits_21);
  }
  { // Node ID: 1071 (NodeConstantRawBits)
    id1071out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1935 (NodeConstantRawBits)
    id1935out_value = (c_hw_fix_9_0_sgn_bits_22);
  }
  { // Node ID: 1065 (NodeConstantRawBits)
    id1065out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1934 (NodeConstantRawBits)
    id1934out_value = (c_hw_fix_9_0_sgn_bits_23);
  }
  { // Node ID: 1059 (NodeConstantRawBits)
    id1059out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1933 (NodeConstantRawBits)
    id1933out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 1053 (NodeConstantRawBits)
    id1053out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1932 (NodeConstantRawBits)
    id1932out_value = (c_hw_fix_9_0_sgn_bits_24);
  }
  { // Node ID: 1047 (NodeConstantRawBits)
    id1047out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1931 (NodeConstantRawBits)
    id1931out_value = (c_hw_fix_9_0_sgn_bits_25);
  }
  { // Node ID: 1041 (NodeConstantRawBits)
    id1041out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1930 (NodeConstantRawBits)
    id1930out_value = (c_hw_fix_9_0_sgn_bits_26);
  }
  { // Node ID: 1035 (NodeConstantRawBits)
    id1035out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1929 (NodeConstantRawBits)
    id1929out_value = (c_hw_fix_9_0_sgn_bits_27);
  }
  { // Node ID: 1029 (NodeConstantRawBits)
    id1029out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1928 (NodeConstantRawBits)
    id1928out_value = (c_hw_fix_9_0_sgn_bits_28);
  }
  { // Node ID: 1023 (NodeConstantRawBits)
    id1023out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1927 (NodeConstantRawBits)
    id1927out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 1017 (NodeConstantRawBits)
    id1017out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1926 (NodeConstantRawBits)
    id1926out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 1011 (NodeConstantRawBits)
    id1011out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1005 (NodeConstantRawBits)
    id1005out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 988 (NodeConstantRawBits)
    id988out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1925 (NodeConstantRawBits)
    id1925out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 1924 (NodeConstantRawBits)
    id1924out_value = (c_hw_bit_24_bits);
  }
  { // Node ID: 1923 (NodeConstantRawBits)
    id1923out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 2003 (NodeConstantRawBits)
    id2003out_value = (c_hw_bit_2_bits);
  }
  { // Node ID: 2002 (NodeConstantRawBits)
    id2002out_value = (c_hw_bit_2_bits_1);
  }
  { // Node ID: 1188 (NodeConstantRawBits)
    id1188out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 651 (NodeConstantRawBits)
    id651out_value = (c_hw_bit_31_bits_1);
  }
  { // Node ID: 656 (NodeConstantRawBits)
    id656out_value = (c_hw_bit_8_bits);
  }
  { // Node ID: 1922 (NodeConstantRawBits)
    id1922out_value = (c_hw_bit_23_bits);
  }
  { // Node ID: 149 (NodeConstantRawBits)
    id149out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1921 (NodeConstantRawBits)
    id1921out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 1920 (NodeConstantRawBits)
    id1920out_value = (c_hw_fix_9_0_sgn_bits_2);
  }
  { // Node ID: 160 (NodeConstantRawBits)
    id160out_value = (c_hw_bit_185_bits);
  }
  { // Node ID: 2088 (NodeConstantRawBits)
    id2088out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 1917 (NodeConstantRawBits)
    id1917out_value = (c_hw_fix_8_0_sgn_bits);
  }
  { // Node ID: 1916 (NodeConstantRawBits)
    id1916out_value = (c_hw_fix_8_0_sgn_bits_1);
  }
  { // Node ID: 1915 (NodeConstantRawBits)
    id1915out_value = (c_hw_fix_9_0_sgn_bits_3);
  }
  { // Node ID: 1914 (NodeConstantRawBits)
    id1914out_value = (c_hw_fix_9_0_sgn_bits_4);
  }
  { // Node ID: 1913 (NodeConstantRawBits)
    id1913out_value = (c_hw_fix_9_0_sgn_bits_3);
  }
  { // Node ID: 1358 (NodeConstantRawBits)
    id1358out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 1912 (NodeConstantRawBits)
    id1912out_value = (c_hw_fix_8_0_sgn_bits_2);
  }
  { // Node ID: 1911 (NodeConstantRawBits)
    id1911out_value = (c_hw_fix_8_0_sgn_bits_1);
  }
  { // Node ID: 1910 (NodeConstantRawBits)
    id1910out_value = (c_hw_fix_8_0_sgn_bits_3);
  }
  { // Node ID: 215 (NodeConstantRawBits)
    id215out_value = (c_hw_flt_8_24_bits_10);
  }
  { // Node ID: 219 (NodeConstantRawBits)
    id219out_value = (c_hw_flt_8_24_bits_11);
  }
  { // Node ID: 1909 (NodeConstantRawBits)
    id1909out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1908 (NodeConstantRawBits)
    id1908out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 1907 (NodeConstantRawBits)
    id1907out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 1906 (NodeConstantRawBits)
    id1906out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 239 (NodeConstantRawBits)
    id239out_value = (c_hw_fix_5_0_uns_bits);
  }
  { // Node ID: 2087 (NodeConstantRawBits)
    id2087out_value = (c_hw_fix_25_n23_sgn_bits);
  }
  { // Node ID: 231 (NodeConstantRawBits)
    id231out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1905 (NodeConstantRawBits)
    id1905out_value = (c_hw_bit_31_bits);
  }
  { // Node ID: 253 (NodeConstantRawBits)
    id253out_value = (c_hw_fix_7_0_uns_bits_1);
  }
  { // Node ID: 1311 (NodeROM)
    uint64_t data[] = {
      0x3f800000,
      0x3101e0a3b89dea68,
      0xb91de8e33f7ffb11,
      0x31c2ce73b89de75d,
      0xb99de5d73f7fec43,
      0x32225289b89dde3b,
      0xb9ecd1273f7fd397,
      0x32633797b89dcf03,
      0xba1dd9ab3f7fb10f,
      0x329209f1b89db9b6,
      0xba4544ac3f7f84ab,
      0x32b27275b89d9e54,
      0xba6ca8123f7f4e6d,
      0x32d2d418b89d7cdf,
      0xba8a012d3f7f0e58,
      0x32f32d9ab89d5557,
      0xba9da8fe3f7ec46d,
      0x3309bedeb89d27be,
      0xbab14abb3f7e70b0,
      0x3319e1a0b89cf416,
      0xbac4e5a33f7e1324,
      0x3329fe73b89cba62,
      0xbad878f33f7dabcc,
      0x333a14b8b89c7aa2,
      0xbaec03eb3f7d3aac,
      0x334a23d1b89c34da,
      0xbaff85c93f7cbfc9,
      0x335a2b1eb89be90c,
      0xbb097ee73f7c3b28,
      0x336a2a03b89b973c,
      0xbb13359c3f7baccd,
      0x337a1fe0b89b3f6c,
      0xbb1ce6a43f7b14be,
      0x3385060cb89ae1a0,
      0xbb2691a03f7a7302,
      0x338cf708b89a7ddb,
      0xbb3036303f79c79d,
      0x3394e294b89a1421,
      0xbb39d3f53f791298,
      0x339cc863b899a477,
      0xbb436a903f7853f8,
      0x33a4a826b8992ee1,
      0xbb4cf9a23f778bc5,
      0x33ac8191b898b362,
      0xbb5680cd3f76ba07,
      0x33b45455b8983201,
      0xbb5fffb33f75dec6,
      0x33bc2025b897aac1,
      0xbb6975f63f74fa0b,
      0x33c3e4b4b8971da9,
      0xbb72e3393f740bdd,
      0x33cba1b6b8968abd,
      0xbb7c471f3f731447,
      0x33d356deb895f203,
      0xbb82d0a63f721352,
      0x33db03e1b8955381,
      0xbb8778b13f710908,
      0x33e2a872b894af3e,
      0xbb8c1b833f6ff573,
      0x33ea4446b894053f,
      0xbb90b8ee3f6ed89e,
      0x33f1d711b893558c,
      0xbb9550c53f6db293,
      0x33f9608ab892a02a,
      0xbb99e2da3f6c835e,
      0x34007033b891e521,
      0xbb9e6f003f6b4b0c,
      0x34042b2db8912478,
      0xbba2f50b3f6a09a7,
      0x3407e10fb8905e37,
      0xbba774ce3f68bf3c,
      0x340b91b4b88f9265,
      0xbbabee1b3f676bd8,
      0x340f3cf7b88ec10a,
      0xbbb060c83f660f88,
      0x3412e2b5b88dea2e,
      0xbbb4cca83f64aa59,
      0x341682c9b88d0dd9,
      0xbbb931903f633c5a,
      0x341a1d0fb88c2c14,
      0xbbbd8f543f61c598,
      0x341db165b88b44e8,
      0xbbc1e5c93f604621,
      0x34213fa6b88a585d,
      0xbbc634c53f5ebe05,
      0x3424c7afb889667d,
      0xbbca7c1c3f5d2d53,
      0x3428495fb8886f51,
      0xbbcebba53f5b941a,
      0x342bc491b88772e2,
      0xbbd2f3353f59f26a,
      0x342f3924b886713b,
      0xbbd722a43f584853,
      0x3432a6f6b8856a65,
      0xbbdb49c73f5695e5,
      0x34360de5b8845e69,
      0xbbdf68763f54db31,
      0x34396dcfb8834d54,
      0xbbe37e883f531849,
      0x343cc692b882372e,
      0xbbe78bd53f514d3d,
      0x3440180fb8811c04,
      0xbbeb90343f4f7a1f,
      0x34436224b87ff7be,
      0xbbef8b7f3f4d9f02,
      0x3446a4b0b87dad96,
      0xbbf37d8d3f4bbbf8,
      0x3449df94b87b59a6,
      0xbbf766393f49d112,
      0x344d12b0b878fc06,
      0xbbfb455a3f47de65,
      0x34503de3b87694cc,
      0xbbff1acc3f45e403,
      0x34536110b8742411,
      0xbc0173343f43e200,
      0x34567c16b871a9ec,
      0xbc0354043f41d870,
      0x34598ed7b86f2676,
      0xbc052fc53f3fc767,
      0x345c9935b86c99c8,
      0xbc0706623f3daef9,
      0x345f9b12b86a03fb,
      0xbc08d7cc3f3b8f3b,
      0x34629450b8676528,
      0xbc0aa3ee3f396842,
      0x346584d2b864bd69,
      0xbc0c6ab83f373a23,
      0x34686c7ab8620cd9,
      0xbc0e2c193f3504f3,
      0x346b4b2db85f5392,
      0xbc0fe7fe3f32c8c9,
      0x346e20ceb85c91ae,
      0xbc119e573f3085bb,
      0x3470ed40b859c74a,
      0xbc134f133f2e3bde,
      0x3473b068b856f481,
      0xbc14fa213f2beb4a,
      0x34766a2cb854196d,
      0xbc169f703f299415,
      0x34791a6fb851362d,
      0xbc183ef13f273656,
      0x347bc118b84e4adc,
      0xbc19d8943f24d225,
      0x347e5e0cb84b5797,
      0xbc1b6c483f226799,
      0x34807899b8485c7a,
      0xbc1cf9fe3f1ff6cb,
      0x3481bd38b84559a5,
      0xbc1e81a73f1d7fd1,
      0x3482fcd6b8424f34,
      0xbc2003333f1b02c6,
      0x34843768b83f3d45,
      0xbc217e953f187fc0,
      0x34856ce1b83c23f6,
      0xbc22f3bc3f15f6d9,
      0x34869d35b8390367,
      0xbc24629b3f13682a,
      0x3487c858b835dbb5,
      0xbc25cb243f10d3cd,
      0x3488ee3fb832ad01,
      0xbc272d483f0e39da,
      0x348a0edfb82f776a,
      0xbc2888fb3f0b9a6b,
      0x348b2a2cb82c3b0e,
      0xbc29de2e3f08f59b,
      0x348c401cb828f80f,
      0xbc2b2cd53f064b82,
      0x348d50a4b825ae8c,
      0xbc2c74e23f039c3d,
      0x348e5bb8b8225ea6,
      0xbc2db6493f00e7e4,
      0x348f6150b81f087e,
      0xbc2ef0fe3efc5d27,
      0x34906161b81bac34,
      0xbc3024f43ef6e0cb,
      0x34915be1b81849e9,
      0xbc31521f3ef15aea,
      0x349250c6b814e1c0,
      0xbc3278753eebcbbb,
      0x34934007b81173d9,
      0xbc3397e93ee63375,
      0x3494299bb80e0056,
      0xbc34b0713ee0924f,
      0x34950d79b80a875a,
      0xbc35c2013edae880,
      0x3495eb97b8070907,
      0xbc36cc903ed53641,
      0x3496c3eeb803857f,
      0xbc37d0123ecf7bca,
      0x34979675b7fff9cb,
      0xbc38cc7e3ec9b953,
      0x34986324b7f8deb9,
      0xbc39c1cb3ec3ef15,
      0x349929f2b7f1ba0e,
      0xbc3aafee3ebe1d4a,
      0x3499eadab7ea8c12,
      0xbc3b96df3eb8442a,
      0x349aa5d2b7e3550b,
      0xbc3c76943eb263ef,
      0x349b5ad3b7dc1541,
      0xbc3d4f053eac7cd4,
      0x349c09d8b7d4ccfa,
      0xbc3e202a3ea68f12,
      0x349cb2d8b7cd7c7f,
      0xbc3ee9fa3ea09ae5,
      0x349d55ceb7c62418,
      0xbc3fac6e3e9aa086,
      0x349df2b4b7bec40d,
      0xbc40677e3e94a031,
      0x349e8982b7b75ca8,
      0xbc411b243e8e9a22,
      0x349f1a33b7afee31,
      0xbc41c7573e888e93,
      0x349fa4c3b7a878f2,
      0xbc426c123e827dc0,
      0x34a0292bb7a0fd34,
      0xbc43094f3e78cfcc,
      0x34a0a766b7997b41,
      0xbc439f063e6c9a7f,
      0x34a11f6fb791f363,
      0xbc442d333e605c13,
      0x34a19142b78a65e5,
      0xbc44b3cf3e541501,
      0x34a1fcdbb782d311,
      0xbc4532d63e47c5c2,
      0x34a26235b7767663,
      0xbc45aa433e3b6ecf,
      0x34a2c14cb7673d24,
      0xbc461a113e2f10a2,
      0x34a31a1db757fafb,
      0xbc46823c3e22abb6,
      0x34a36ca4b748b07e,
      0xbc46e2c03e164083,
      0x34a3b8dfb7395e44,
      0xbc473b993e09cf86,
      0x34a3fec9b72a04e5,
      0xbc478cc33dfab273,
      0x34a43e61b71aa4f8,
      0xbc47d63c3de1bc2e,
      0x34a477a4b70b3f15,
      0xbc4818013dc8bd36,
      0x34a4aa90b6f7a7a7,
      0xbc48520f3dafb680,
      0x34a4d723b6d8c798,
      0xbc4884643d96a905,
      0x34a4fd5ab6b9df2d,
      0xbc48aefd3d7b2b74,
      0x34a51d36b69aef98,
      0xbc48d1db3d48fb30,
      0x34a536b3b677f413,
      0xbc48ecfa3d16c32c,
      0x34a549d2b639ff67,
      0xbc49005a3cc90ab0,
      0x34a55692b5f8071e,
      0xbc490bfa3c490e90,
      0x34a55cf2b5780bbd,
    };
    setRom< HWRawBits<128> > (data, id1311sta_rom_store, 128, 128); 
  }
  { // Node ID: 1904 (NodeConstantRawBits)
    id1904out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 1903 (NodeConstantRawBits)
    id1903out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 440 (NodeConstantRawBits)
    id440out_value = (c_hw_fix_5_0_uns_bits);
  }
  { // Node ID: 2086 (NodeConstantRawBits)
    id2086out_value = (c_hw_fix_25_n23_sgn_bits);
  }
  { // Node ID: 432 (NodeConstantRawBits)
    id432out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1902 (NodeConstantRawBits)
    id1902out_value = (c_hw_bit_31_bits);
  }
  { // Node ID: 454 (NodeConstantRawBits)
    id454out_value = (c_hw_fix_7_0_uns_bits_1);
  }
  { // Node ID: 1320 (NodeROM)
    uint64_t data[] = {
      0x3c490fdb00000000,
      0xb4a55cf2aca33598,
      0x3c490bfa3c490e90,
      0xb4a55692b5780c60,
      0x3c49005a3cc90ab0,
      0xb4a549d2b5f80770,
      0x3c48ecfa3d16c32c,
      0xb4a536b3b639ff8f,
      0x3c48d1db3d48fb30,
      0xb4a51d36b677f43b,
      0x3c48aefd3d7b2b74,
      0xb4a4fd5ab69aefac,
      0x3c4884643d96a905,
      0xb4a4d723b6b9df41,
      0x3c48520f3dafb680,
      0xb4a4aa90b6d8c7ac,
      0x3c4818013dc8bd36,
      0xb4a477a4b6f7a7bc,
      0x3c47d63c3de1bc2e,
      0xb4a43e61b70b3f1f,
      0x3c478cc33dfab273,
      0xb4a3fec9b71aa503,
      0x3c473b993e09cf86,
      0xb4a3b8dfb72a04f0,
      0x3c46e2c03e164083,
      0xb4a36ca5b7395e4f,
      0x3c46823c3e22abb6,
      0xb4a31a1db748b088,
      0x3c461a113e2f10a2,
      0xb4a2c14cb757fb05,
      0x3c45aa433e3b6ecf,
      0xb4a26235b7673d2e,
      0x3c4532d63e47c5c2,
      0xb4a1fcdbb776766d,
      0x3c44b3cf3e541501,
      0xb4a19142b782d316,
      0x3c442d333e605c13,
      0xb4a11f6fb78a65ea,
      0x3c439f063e6c9a7f,
      0xb4a0a766b791f368,
      0x3c43094f3e78cfcc,
      0xb4a0292bb7997b46,
      0x3c426c123e827dc0,
      0xb49fa4c3b7a0fd39,
      0x3c41c7573e888e93,
      0xb49f1a33b7a878f7,
      0x3c411b243e8e9a22,
      0xb49e8982b7afee36,
      0x3c40677e3e94a031,
      0xb49df2b4b7b75cad,
      0x3c3fac6e3e9aa086,
      0xb49d55ceb7bec412,
      0x3c3ee9fa3ea09ae5,
      0xb49cb2d8b7c6241d,
      0x3c3e202a3ea68f12,
      0xb49c09d8b7cd7c84,
      0x3c3d4f053eac7cd4,
      0xb49b5ad3b7d4ccff,
      0x3c3c76943eb263ef,
      0xb49aa5d2b7dc1545,
      0x3c3b96df3eb8442a,
      0xb499eadab7e35510,
      0x3c3aafee3ebe1d4a,
      0xb49929f2b7ea8c17,
      0x3c39c1cb3ec3ef15,
      0xb4986324b7f1ba13,
      0x3c38cc7e3ec9b953,
      0xb4979675b7f8debd,
      0x3c37d0123ecf7bca,
      0xb496c3eeb7fff9cf,
      0x3c36cc903ed53641,
      0xb495eb97b8038582,
      0x3c35c2013edae880,
      0xb4950d79b8070909,
      0x3c34b0713ee0924f,
      0xb494299bb80a875d,
      0x3c3397e93ee63375,
      0xb4934007b80e0058,
      0x3c3278753eebcbbb,
      0xb49250c6b81173db,
      0x3c31521f3ef15aea,
      0xb4915be1b814e1c2,
      0x3c3024f43ef6e0cb,
      0xb4906161b81849eb,
      0x3c2ef0fe3efc5d27,
      0xb48f6150b81bac36,
      0x3c2db6493f00e7e4,
      0xb48e5bb8b81f0880,
      0x3c2c74e23f039c3d,
      0xb48d50a4b8225ea8,
      0x3c2b2cd53f064b82,
      0xb48c401cb825ae8e,
      0x3c29de2e3f08f59b,
      0xb48b2a2cb828f811,
      0x3c2888fb3f0b9a6b,
      0xb48a0edfb82c3b10,
      0x3c272d483f0e39da,
      0xb488ee3fb82f776c,
      0x3c25cb243f10d3cd,
      0xb487c858b832ad03,
      0x3c24629b3f13682a,
      0xb4869d35b835dbb7,
      0x3c22f3bc3f15f6d9,
      0xb4856ce1b8390369,
      0x3c217e953f187fc0,
      0xb4843768b83c23f8,
      0x3c2003333f1b02c6,
      0xb482fcd6b83f3d47,
      0x3c1e81a73f1d7fd1,
      0xb481bd38b8424f36,
      0x3c1cf9fe3f1ff6cb,
      0xb4807899b84559a7,
      0x3c1b6c483f226799,
      0xb47e5e0cb8485c7c,
      0x3c19d8943f24d225,
      0xb47bc118b84b5799,
      0x3c183ef13f273656,
      0xb4791a6fb84e4ade,
      0x3c169f703f299415,
      0xb4766a2cb851362f,
      0x3c14fa213f2beb4a,
      0xb473b068b854196f,
      0x3c134f133f2e3bde,
      0xb470ed40b856f482,
      0x3c119e573f3085bb,
      0xb46e20ceb859c74c,
      0x3c0fe7fe3f32c8c9,
      0xb46b4b2db85c91b0,
      0x3c0e2c193f3504f3,
      0xb4686c7ab85f5394,
      0x3c0c6ab83f373a23,
      0xb46584d2b8620cdb,
      0x3c0aa3ee3f396842,
      0xb4629450b864bd6b,
      0x3c08d7cc3f3b8f3b,
      0xb45f9b12b867652a,
      0x3c0706623f3daef9,
      0xb45c9935b86a03fd,
      0x3c052fc53f3fc767,
      0xb4598ed7b86c99ca,
      0x3c0354043f41d870,
      0xb4567c16b86f2678,
      0x3c0173343f43e200,
      0xb4536110b871a9ee,
      0x3bff1acc3f45e403,
      0xb4503de3b8742413,
      0x3bfb455a3f47de65,
      0xb44d12b0b87694ce,
      0x3bf766393f49d112,
      0xb449df94b878fc08,
      0x3bf37d8d3f4bbbf8,
      0xb446a4b0b87b59a8,
      0x3bef8b7f3f4d9f02,
      0xb4436224b87dad98,
      0x3beb90343f4f7a1f,
      0xb440180fb87ff7bf,
      0x3be78bd53f514d3d,
      0xb43cc692b8811c05,
      0x3be37e883f531849,
      0xb4396dcfb882372f,
      0x3bdf68763f54db31,
      0xb4360de5b8834d55,
      0x3bdb49c73f5695e5,
      0xb432a6f6b8845e6a,
      0x3bd722a43f584853,
      0xb42f3924b8856a65,
      0x3bd2f3353f59f26a,
      0xb42bc491b886713c,
      0x3bcebba53f5b941a,
      0xb428495fb88772e3,
      0x3bca7c1c3f5d2d53,
      0xb424c7afb8886f52,
      0x3bc634c53f5ebe05,
      0xb4213fa6b889667e,
      0x3bc1e5c93f604621,
      0xb41db165b88a585e,
      0x3bbd8f543f61c598,
      0xb41a1d0fb88b44e9,
      0x3bb931903f633c5a,
      0xb41682c9b88c2c15,
      0x3bb4cca83f64aa59,
      0xb412e2b5b88d0dda,
      0x3bb060c83f660f88,
      0xb40f3cf7b88dea2e,
      0x3babee1b3f676bd8,
      0xb40b91b4b88ec10a,
      0x3ba774ce3f68bf3c,
      0xb407e10fb88f9265,
      0x3ba2f50b3f6a09a7,
      0xb4042b2db8905e37,
      0x3b9e6f003f6b4b0c,
      0xb4007033b8912479,
      0x3b99e2da3f6c835e,
      0xb3f9608ab891e522,
      0x3b9550c53f6db293,
      0xb3f1d711b892a02a,
      0x3b90b8ee3f6ed89e,
      0xb3ea4446b893558c,
      0x3b8c1b833f6ff573,
      0xb3e2a872b8940540,
      0x3b8778b13f710908,
      0xb3db03e1b894af3f,
      0x3b82d0a63f721352,
      0xb3d356deb8955382,
      0x3b7c471f3f731447,
      0xb3cba1b6b895f203,
      0x3b72e3393f740bdd,
      0xb3c3e4b4b8968abd,
      0x3b6975f63f74fa0b,
      0xb3bc2025b8971da9,
      0x3b5fffb33f75dec6,
      0xb3b45455b897aac1,
      0x3b5680cd3f76ba07,
      0xb3ac8191b8983201,
      0x3b4cf9a23f778bc5,
      0xb3a4a826b898b363,
      0x3b436a903f7853f8,
      0xb39cc863b8992ee1,
      0x3b39d3f53f791298,
      0xb394e294b899a478,
      0x3b3036303f79c79d,
      0xb38cf708b89a1422,
      0x3b2691a03f7a7302,
      0xb385060cb89a7ddb,
      0x3b1ce6a43f7b14be,
      0xb37a1fe0b89ae1a0,
      0x3b13359c3f7baccd,
      0xb36a2a03b89b3f6c,
      0x3b097ee73f7c3b28,
      0xb35a2b1eb89b973c,
      0x3aff85c93f7cbfc9,
      0xb34a23d1b89be90d,
      0x3aec03eb3f7d3aac,
      0xb33a14b8b89c34da,
      0x3ad878f33f7dabcc,
      0xb329fe73b89c7aa2,
      0x3ac4e5a33f7e1324,
      0xb319e1a0b89cba62,
      0x3ab14abb3f7e70b0,
      0xb309bedeb89cf417,
      0x3a9da8fe3f7ec46d,
      0xb2f32d9ab89d27be,
      0x3a8a012d3f7f0e58,
      0xb2d2d418b89d5557,
      0x3a6ca8123f7f4e6d,
      0xb2b27275b89d7cdf,
      0x3a4544ac3f7f84ab,
      0xb29209f1b89d9e54,
      0x3a1dd9ab3f7fb10f,
      0xb2633797b89db9b6,
      0x39ecd1273f7fd397,
      0xb2225289b89dcf03,
      0x399de5d73f7fec43,
      0xb1c2ce73b89dde3b,
      0x391de8e33f7ffb11,
      0xb101e0a3b89de75d,
    };
    setRom< HWRawBits<128> > (data, id1320sta_rom_store, 128, 128); 
  }
  { // Node ID: 1900 (NodeConstantRawBits)
    id1900out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 1899 (NodeConstantRawBits)
    id1899out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 1898 (NodeConstantRawBits)
    id1898out_value = (c_hw_fix_9_0_sgn_bits_7);
  }
  { // Node ID: 1897 (NodeConstantRawBits)
    id1897out_value = (c_hw_fix_9_0_sgn_bits_8);
  }
  { // Node ID: 1896 (NodeConstantRawBits)
    id1896out_value = (c_hw_fix_9_0_sgn_bits_9);
  }
  { // Node ID: 1895 (NodeConstantRawBits)
    id1895out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 416 (NodeConstantRawBits)
    id416out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1894 (NodeConstantRawBits)
    id1894out_value = (c_hw_fix_9_0_sgn_bits_10);
  }
  { // Node ID: 410 (NodeConstantRawBits)
    id410out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1893 (NodeConstantRawBits)
    id1893out_value = (c_hw_fix_9_0_sgn_bits_11);
  }
  { // Node ID: 404 (NodeConstantRawBits)
    id404out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1892 (NodeConstantRawBits)
    id1892out_value = (c_hw_fix_9_0_sgn_bits_12);
  }
  { // Node ID: 398 (NodeConstantRawBits)
    id398out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1891 (NodeConstantRawBits)
    id1891out_value = (c_hw_fix_9_0_sgn_bits_13);
  }
  { // Node ID: 392 (NodeConstantRawBits)
    id392out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1890 (NodeConstantRawBits)
    id1890out_value = (c_hw_fix_9_0_sgn_bits_14);
  }
  { // Node ID: 386 (NodeConstantRawBits)
    id386out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1889 (NodeConstantRawBits)
    id1889out_value = (c_hw_fix_9_0_sgn_bits_15);
  }
  { // Node ID: 380 (NodeConstantRawBits)
    id380out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1888 (NodeConstantRawBits)
    id1888out_value = (c_hw_fix_9_0_sgn_bits_16);
  }
  { // Node ID: 374 (NodeConstantRawBits)
    id374out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1887 (NodeConstantRawBits)
    id1887out_value = (c_hw_fix_9_0_sgn_bits_17);
  }
  { // Node ID: 368 (NodeConstantRawBits)
    id368out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1886 (NodeConstantRawBits)
    id1886out_value = (c_hw_fix_9_0_sgn_bits_18);
  }
  { // Node ID: 362 (NodeConstantRawBits)
    id362out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1885 (NodeConstantRawBits)
    id1885out_value = (c_hw_fix_9_0_sgn_bits_19);
  }
  { // Node ID: 356 (NodeConstantRawBits)
    id356out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1884 (NodeConstantRawBits)
    id1884out_value = (c_hw_fix_9_0_sgn_bits_20);
  }
  { // Node ID: 350 (NodeConstantRawBits)
    id350out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1883 (NodeConstantRawBits)
    id1883out_value = (c_hw_fix_9_0_sgn_bits_21);
  }
  { // Node ID: 344 (NodeConstantRawBits)
    id344out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1882 (NodeConstantRawBits)
    id1882out_value = (c_hw_fix_9_0_sgn_bits_22);
  }
  { // Node ID: 338 (NodeConstantRawBits)
    id338out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1881 (NodeConstantRawBits)
    id1881out_value = (c_hw_fix_9_0_sgn_bits_23);
  }
  { // Node ID: 332 (NodeConstantRawBits)
    id332out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1880 (NodeConstantRawBits)
    id1880out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 326 (NodeConstantRawBits)
    id326out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1879 (NodeConstantRawBits)
    id1879out_value = (c_hw_fix_9_0_sgn_bits_24);
  }
  { // Node ID: 320 (NodeConstantRawBits)
    id320out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1878 (NodeConstantRawBits)
    id1878out_value = (c_hw_fix_9_0_sgn_bits_25);
  }
  { // Node ID: 314 (NodeConstantRawBits)
    id314out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1877 (NodeConstantRawBits)
    id1877out_value = (c_hw_fix_9_0_sgn_bits_26);
  }
  { // Node ID: 308 (NodeConstantRawBits)
    id308out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1876 (NodeConstantRawBits)
    id1876out_value = (c_hw_fix_9_0_sgn_bits_27);
  }
  { // Node ID: 302 (NodeConstantRawBits)
    id302out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1875 (NodeConstantRawBits)
    id1875out_value = (c_hw_fix_9_0_sgn_bits_28);
  }
  { // Node ID: 296 (NodeConstantRawBits)
    id296out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1874 (NodeConstantRawBits)
    id1874out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 290 (NodeConstantRawBits)
    id290out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1873 (NodeConstantRawBits)
    id1873out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 284 (NodeConstantRawBits)
    id284out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 278 (NodeConstantRawBits)
    id278out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 261 (NodeConstantRawBits)
    id261out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1872 (NodeConstantRawBits)
    id1872out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 1871 (NodeConstantRawBits)
    id1871out_value = (c_hw_bit_24_bits);
  }
  { // Node ID: 1869 (NodeConstantRawBits)
    id1869out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 1868 (NodeConstantRawBits)
    id1868out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 1867 (NodeConstantRawBits)
    id1867out_value = (c_hw_fix_9_0_sgn_bits_7);
  }
  { // Node ID: 1866 (NodeConstantRawBits)
    id1866out_value = (c_hw_fix_9_0_sgn_bits_8);
  }
  { // Node ID: 1865 (NodeConstantRawBits)
    id1865out_value = (c_hw_fix_9_0_sgn_bits_9);
  }
  { // Node ID: 1864 (NodeConstantRawBits)
    id1864out_value = (c_hw_fix_9_0_sgn_bits_6);
  }
  { // Node ID: 617 (NodeConstantRawBits)
    id617out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1863 (NodeConstantRawBits)
    id1863out_value = (c_hw_fix_9_0_sgn_bits_10);
  }
  { // Node ID: 611 (NodeConstantRawBits)
    id611out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1862 (NodeConstantRawBits)
    id1862out_value = (c_hw_fix_9_0_sgn_bits_11);
  }
  { // Node ID: 605 (NodeConstantRawBits)
    id605out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1861 (NodeConstantRawBits)
    id1861out_value = (c_hw_fix_9_0_sgn_bits_12);
  }
  { // Node ID: 599 (NodeConstantRawBits)
    id599out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1860 (NodeConstantRawBits)
    id1860out_value = (c_hw_fix_9_0_sgn_bits_13);
  }
  { // Node ID: 593 (NodeConstantRawBits)
    id593out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1859 (NodeConstantRawBits)
    id1859out_value = (c_hw_fix_9_0_sgn_bits_14);
  }
  { // Node ID: 587 (NodeConstantRawBits)
    id587out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1858 (NodeConstantRawBits)
    id1858out_value = (c_hw_fix_9_0_sgn_bits_15);
  }
  { // Node ID: 581 (NodeConstantRawBits)
    id581out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1857 (NodeConstantRawBits)
    id1857out_value = (c_hw_fix_9_0_sgn_bits_16);
  }
  { // Node ID: 575 (NodeConstantRawBits)
    id575out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1856 (NodeConstantRawBits)
    id1856out_value = (c_hw_fix_9_0_sgn_bits_17);
  }
  { // Node ID: 569 (NodeConstantRawBits)
    id569out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1855 (NodeConstantRawBits)
    id1855out_value = (c_hw_fix_9_0_sgn_bits_18);
  }
  { // Node ID: 563 (NodeConstantRawBits)
    id563out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1854 (NodeConstantRawBits)
    id1854out_value = (c_hw_fix_9_0_sgn_bits_19);
  }
  { // Node ID: 557 (NodeConstantRawBits)
    id557out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1853 (NodeConstantRawBits)
    id1853out_value = (c_hw_fix_9_0_sgn_bits_20);
  }
  { // Node ID: 551 (NodeConstantRawBits)
    id551out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1852 (NodeConstantRawBits)
    id1852out_value = (c_hw_fix_9_0_sgn_bits_21);
  }
  { // Node ID: 545 (NodeConstantRawBits)
    id545out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1851 (NodeConstantRawBits)
    id1851out_value = (c_hw_fix_9_0_sgn_bits_22);
  }
  { // Node ID: 539 (NodeConstantRawBits)
    id539out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1850 (NodeConstantRawBits)
    id1850out_value = (c_hw_fix_9_0_sgn_bits_23);
  }
  { // Node ID: 533 (NodeConstantRawBits)
    id533out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1849 (NodeConstantRawBits)
    id1849out_value = (c_hw_fix_9_0_sgn_bits_5);
  }
  { // Node ID: 527 (NodeConstantRawBits)
    id527out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1848 (NodeConstantRawBits)
    id1848out_value = (c_hw_fix_9_0_sgn_bits_24);
  }
  { // Node ID: 521 (NodeConstantRawBits)
    id521out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1847 (NodeConstantRawBits)
    id1847out_value = (c_hw_fix_9_0_sgn_bits_25);
  }
  { // Node ID: 515 (NodeConstantRawBits)
    id515out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1846 (NodeConstantRawBits)
    id1846out_value = (c_hw_fix_9_0_sgn_bits_26);
  }
  { // Node ID: 509 (NodeConstantRawBits)
    id509out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1845 (NodeConstantRawBits)
    id1845out_value = (c_hw_fix_9_0_sgn_bits_27);
  }
  { // Node ID: 503 (NodeConstantRawBits)
    id503out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1844 (NodeConstantRawBits)
    id1844out_value = (c_hw_fix_9_0_sgn_bits_28);
  }
  { // Node ID: 497 (NodeConstantRawBits)
    id497out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1843 (NodeConstantRawBits)
    id1843out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 491 (NodeConstantRawBits)
    id491out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 1842 (NodeConstantRawBits)
    id1842out_value = (c_hw_fix_9_0_sgn_bits);
  }
  { // Node ID: 485 (NodeConstantRawBits)
    id485out_value = (c_hw_bit_1_bits);
  }
  { // Node ID: 479 (NodeConstantRawBits)
    id479out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 462 (NodeConstantRawBits)
    id462out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1841 (NodeConstantRawBits)
    id1841out_value = (c_hw_fix_9_0_sgn_bits_1);
  }
  { // Node ID: 1840 (NodeConstantRawBits)
    id1840out_value = (c_hw_bit_24_bits);
  }
  { // Node ID: 1839 (NodeConstantRawBits)
    id1839out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 1919 (NodeConstantRawBits)
    id1919out_value = (c_hw_bit_2_bits_2);
  }
  { // Node ID: 1918 (NodeConstantRawBits)
    id1918out_value = (c_hw_bit_2_bits);
  }
  { // Node ID: 662 (NodeConstantRawBits)
    id662out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 1837 (NodeConstantRawBits)
    id1837out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1264 (NodeConstantRawBits)
    id1264out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 21 (NodeConstantRawBits)
    id21out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 1262 (NodeConstantRawBits)
    id1262out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 19 (NodeConstantRawBits)
    id19out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1838 (NodeConstantRawBits)
    id1838out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1260 (NodeConstantRawBits)
    id1260out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 17 (NodeConstantRawBits)
    id17out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1836 (NodeConstantRawBits)
    id1836out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 1266 (NodeConstantRawBits)
    id1266out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 23 (NodeConstantRawBits)
    id23out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1254 (NodeConstantRawBits)
    id1254out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1361 (NodeOutput)
    m_internal_watch_carriedposx_output = registerOutput("internal_watch_carriedposx_output",2 );
  }
  { // Node ID: 15 (NodeConstantRawBits)
    id15out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1258 (NodeConstantRawBits)
    id1258out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1362 (NodeOutput)
    m_internal_watch_carriedposz_output = registerOutput("internal_watch_carriedposz_output",3 );
  }
  { // Node ID: 1363 (NodeOutput)
    m_internal_watch_carrieddirx_output = registerOutput("internal_watch_carrieddirx_output",4 );
  }
  { // Node ID: 1364 (NodeOutput)
    m_internal_watch_carriedlength_output = registerOutput("internal_watch_carriedlength_output",5 );
  }
  { // Node ID: 1365 (NodeOutput)
    m_internal_watch_posz_output = registerOutput("internal_watch_posz_output",6 );
  }
  { // Node ID: 1366 (NodeOutput)
    m_internal_watch_dirx_output = registerOutput("internal_watch_dirx_output",7 );
  }
  { // Node ID: 1367 (NodeOutput)
    m_internal_watch_tracklength_output = registerOutput("internal_watch_tracklength_output",8 );
  }
  { // Node ID: 1368 (NodeOutput)
    m_internal_watch_reset_output = registerOutput("internal_watch_reset_output",9 );
  }
  { // Node ID: 1369 (NodeOutput)
    m_internal_watch_pastlimit_output = registerOutput("internal_watch_pastlimit_output",10 );
  }
  { // Node ID: 1370 (NodeOutput)
    m_internal_watch_lengthoffset_output = registerOutput("internal_watch_lengthoffset_output",11 );
  }
  { // Node ID: 1371 (NodeOutput)
    m_internal_watch_length_output = registerOutput("internal_watch_length_output",12 );
  }
  { // Node ID: 1372 (NodeOutput)
    m_internal_watch_track_0_output = registerOutput("internal_watch_track_0_output",13 );
  }
  { // Node ID: 1256 (NodeConstantRawBits)
    id1256out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 13 (NodeConstantRawBits)
    id13out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 1373 (NodeOutput)
    m_internal_watch_track_1_output = registerOutput("internal_watch_track_1_output",14 );
  }
  { // Node ID: 1374 (NodeOutput)
    m_internal_watch_track_2_output = registerOutput("internal_watch_track_2_output",15 );
  }
  { // Node ID: 1375 (NodeOutput)
    m_internal_watch_track_3_output = registerOutput("internal_watch_track_3_output",16 );
  }
  { // Node ID: 1376 (NodeOutput)
    m_internal_watch_track_4_output = registerOutput("internal_watch_track_4_output",17 );
  }
  { // Node ID: 1377 (NodeOutput)
    m_internal_watch_track_5_output = registerOutput("internal_watch_track_5_output",18 );
  }
  { // Node ID: 1378 (NodeOutput)
    m_internal_watch_track_6_output = registerOutput("internal_watch_track_6_output",19 );
  }
  { // Node ID: 118 (NodeConstantRawBits)
    id118out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1272 (NodeConstantRawBits)
    id1272out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1273 (NodeConstantRawBits)
    id1273out_value = (c_hw_flt_11_53_bits);
  }
  { // Node ID: 1835 (NodeConstantRawBits)
    id1835out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 1275 (NodeInputMappedReg)
    registerMappedRegister("io_z_force_disabled", Data(1));
  }
  { // Node ID: 1278 (NodeOutput)
    m_z = registerOutput("z",0 );
  }
  { // Node ID: 1351 (NodeConstantRawBits)
    id1351out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1834 (NodeConstantRawBits)
    id1834out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1348 (NodeConstantRawBits)
    id1348out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 1352 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 0 (NodeConstantRawBits)
    id0out_value = (c_hw_fix_1_0_uns_bits_1);
  }
}

void loopKernel::ramInitialise() {
}

void loopKernel::resetComputation() {
  resetComputationAfterFlush();
}

void loopKernel::resetComputationAfterFlush() {
  { // Node ID: 4 (NodePulse)

    (id4st_count) = (0l);
    (id4st_value) = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 2139 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2139out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2112 (NodeFIFO)

    for(int i=0; i<37; i++)
    {
      id2112out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 27 (NodeInputMappedReg)
    id27out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 29 (NodeInput)

    (id29st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id29st_last_read_value) = (HWRawBits<96>(varint_u<96>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(32))));
  }
  { // Node ID: 2136 (NodeFIFO)

    for(int i=0; i<48; i++)
    {
      id2136out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2113 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2113out_output[i] = (HWRawBits<23>(varint_u<23>(m_undefined_value.get_bits(23))));
    }
  }
  { // Node ID: 2114 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2114out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2116 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2116out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2115 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2115out_output[i] = (HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(m_undefined_value.get_bits(8))));
    }
  }
  { // Node ID: 2117 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2117out_output[i] = (HWOffsetFix<9,0,TWOSCOMPLEMENT>(varint_u<9>(m_undefined_value.get_bits(9))));
    }
  }
  { // Node ID: 2118 (NodeFIFO)

    for(int i=0; i<30; i++)
    {
      id2118out_output[i] = (HWRawBits<8>(varint_u<8>(m_undefined_value.get_bits(8))));
    }
  }
  { // Node ID: 2119 (NodeFIFO)

    for(int i=0; i<33; i++)
    {
      id2119out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2121 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2121out_output[i] = (HWOffsetFix<25,-24,UNSIGNED>(varint_u<25>(m_undefined_value.get_bits(25))));
    }
  }
  { // Node ID: 2125 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2125out_output[i] = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
    }
  }
  { // Node ID: 2126 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2126out_output[i] = (HWOffsetFix<17,-17,UNSIGNED>(varint_u<17>(m_undefined_value.get_bits(17))));
    }
  }
  { // Node ID: 2128 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id2128out_output[i] = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
    }
  }
  { // Node ID: 2415 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2415out_output[i] = (HWOffsetFix<17,-17,UNSIGNED>(varint_u<17>(m_undefined_value.get_bits(17))));
    }
  }
  { // Node ID: 2131 (NodeFIFO)

    for(int i=0; i<17; i++)
    {
      id2131out_output[i] = (HWOffsetFix<27,-23,TWOSCOMPLEMENT>(varint_u<27>(m_undefined_value.get_bits(27))));
    }
  }
  { // Node ID: 2135 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2135out_output[i] = (HWOffsetFix<25,-24,UNSIGNED>(varint_u<25>(m_undefined_value.get_bits(25))));
    }
  }
  { // Node ID: 2137 (NodeFIFO)

    for(int i=0; i<80; i++)
    {
      id2137out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2407 (NodeFIFO)

    for(int i=0; i<36; i++)
    {
      id2407out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2417 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2417out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2418 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2418out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2358 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id2358out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2422 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id2422out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2423 (NodeFIFO)

    for(int i=0; i<26; i++)
    {
      id2423out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2424 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id2424out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2249 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id2249out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2426 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2426out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2427 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2427out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2428 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id2428out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2429 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2429out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2430 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2430out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2450 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2450out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2360 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id2360out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2440 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id2440out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2441 (NodeFIFO)

    for(int i=0; i<40; i++)
    {
      id2441out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2442 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2442out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2443 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2443out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2147 (NodeFIFO)

    for(int i=0; i<15; i++)
    {
      id2147out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2148 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2148out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2149 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2149out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2150 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id2150out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2151 (NodeFIFO)

    for(int i=0; i<29; i++)
    {
      id2151out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2153 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2153out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2434 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2434out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2247 (NodeFIFO)

    for(int i=0; i<80; i++)
    {
      id2247out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2156 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2156out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2157 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2157out_output[i] = (HWOffsetFix<8,0,TWOSCOMPLEMENT>(varint_u<8>(m_undefined_value.get_bits(8))));
    }
  }
  { // Node ID: 2162 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2162out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2161 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2161out_output[i] = (HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(m_undefined_value.get_bits(8))));
    }
  }
  { // Node ID: 2159 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2159out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2158 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2158out_output[i] = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
    }
  }
  { // Node ID: 2435 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2435out_output[i] = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
    }
  }
  { // Node ID: 2163 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2163out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2245 (NodeFIFO)

    for(int i=0; i<65; i++)
    {
      id2245out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2166 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2166out_output[i] = (HWRawBits<2>(varint_u<2>(m_undefined_value.get_bits(2))));
    }
  }
  { // Node ID: 2177 (NodeFIFO)

    for(int i=0; i<28; i++)
    {
      id2177out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2170 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2170out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2171 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id2171out_output[i] = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
    }
  }
  { // Node ID: 2175 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2175out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2176 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id2176out_output[i] = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
    }
  }
  { // Node ID: 2178 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2178out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2207 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2207out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2179 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2179out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2205 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2205out_output[i] = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
    }
  }
  { // Node ID: 2203 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2203out_output[i] = (HWOffsetFix<5,0,UNSIGNED>(varint_u<5>(m_undefined_value.get_bits(5))));
    }
  }
  { // Node ID: 2206 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2206out_output[i] = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
    }
  }
  { // Node ID: 2208 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2208out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2237 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2237out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2209 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2209out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2235 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2235out_output[i] = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
    }
  }
  { // Node ID: 2233 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2233out_output[i] = (HWOffsetFix<5,0,UNSIGNED>(varint_u<5>(m_undefined_value.get_bits(5))));
    }
  }
  { // Node ID: 2236 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2236out_output[i] = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
    }
  }
  { // Node ID: 2240 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id2240out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2242 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id2242out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2244 (NodeFIFO)

    for(int i=0; i<39; i++)
    {
      id2244out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2246 (NodeFIFO)

    for(int i=0; i<77; i++)
    {
      id2246out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2364 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id2364out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2347 (NodeFIFO)

    for(int i=0; i<28; i++)
    {
      id2347out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2438 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2438out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2439 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2439out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2348 (NodeFIFO)

    for(int i=0; i<86; i++)
    {
      id2348out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2432 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id2432out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2444 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2444out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2345 (NodeFIFO)

    for(int i=0; i<80; i++)
    {
      id2345out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2256 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2256out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2257 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2257out_output[i] = (HWOffsetFix<8,0,TWOSCOMPLEMENT>(varint_u<8>(m_undefined_value.get_bits(8))));
    }
  }
  { // Node ID: 2262 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2262out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2261 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2261out_output[i] = (HWOffsetFix<8,0,UNSIGNED>(varint_u<8>(m_undefined_value.get_bits(8))));
    }
  }
  { // Node ID: 2259 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2259out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2258 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2258out_output[i] = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
    }
  }
  { // Node ID: 2436 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2436out_output[i] = (HWOffsetFix<80,-79,TWOSCOMPLEMENT>(varint_u<80>::init(2, m_undefined_value.get_bits(64), m_undefined_value.get_bits(16))));
    }
  }
  { // Node ID: 2263 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2263out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2343 (NodeFIFO)

    for(int i=0; i<65; i++)
    {
      id2343out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2275 (NodeFIFO)

    for(int i=0; i<30; i++)
    {
      id2275out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2268 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2268out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2269 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id2269out_output[i] = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
    }
  }
  { // Node ID: 2273 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id2273out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2274 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id2274out_output[i] = (HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(m_undefined_value.get_bits(7))));
    }
  }
  { // Node ID: 2276 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2276out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2305 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2305out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2277 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2277out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2303 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2303out_output[i] = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
    }
  }
  { // Node ID: 2301 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2301out_output[i] = (HWOffsetFix<5,0,UNSIGNED>(varint_u<5>(m_undefined_value.get_bits(5))));
    }
  }
  { // Node ID: 2304 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2304out_output[i] = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
    }
  }
  { // Node ID: 2306 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2306out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2335 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id2335out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2307 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2307out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2333 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id2333out_output[i] = (HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(m_undefined_value.get_bits(2))));
    }
  }
  { // Node ID: 2331 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2331out_output[i] = (HWOffsetFix<5,0,UNSIGNED>(varint_u<5>(m_undefined_value.get_bits(5))));
    }
  }
  { // Node ID: 2334 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2334out_output[i] = (HWRawBits<24>(varint_u<24>(m_undefined_value.get_bits(24))));
    }
  }
  { // Node ID: 2338 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id2338out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2340 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id2340out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2342 (NodeFIFO)

    for(int i=0; i<39; i++)
    {
      id2342out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2344 (NodeFIFO)

    for(int i=0; i<79; i++)
    {
      id2344out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2346 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id2346out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2353 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2353out_output[i] = (HWRawBits<1>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2354 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2354out_output[i] = (HWRawBits<31>(varint_u<31>(m_undefined_value.get_bits(31))));
    }
  }
  { // Node ID: 2356 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2356out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2359 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id2359out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2433 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2433out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2367 (NodeFIFO)

    for(int i=0; i<26; i++)
    {
      id2367out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2250 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id2250out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2445 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2445out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2446 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2446out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2437 (NodeFIFO)

    for(int i=0; i<40; i++)
    {
      id2437out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2375 (NodeFIFO)

    for(int i=0; i<19; i++)
    {
      id2375out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2369 (NodeFIFO)

    for(int i=0; i<22; i++)
    {
      id2369out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2447 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id2447out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2448 (NodeFIFO)

    for(int i=0; i<40; i++)
    {
      id2448out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2449 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id2449out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2416 (NodeFIFO)

    for(int i=0; i<37; i++)
    {
      id2416out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2414 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id2414out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2378 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id2378out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2405 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id2405out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2452 (NodeFIFO)

    for(int i=0; i<59; i++)
    {
      id2452out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2141 (NodeFIFO)

    for(int i=0; i<79; i++)
    {
      id2141out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2454 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id2454out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2388 (NodeFIFO)

    for(int i=0; i<79; i++)
    {
      id2388out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2455 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id2455out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2392 (NodeFIFO)

    for(int i=0; i<91; i++)
    {
      id2392out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2421 (NodeFIFO)

    for(int i=0; i<58; i++)
    {
      id2421out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2394 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id2394out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2451 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2451out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2453 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id2453out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2425 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id2425out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2431 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id2431out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 2409 (NodeFIFO)

    for(int i=0; i<87; i++)
    {
      id2409out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2420 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id2420out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2419 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id2419out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2403 (NodeFIFO)

    for(int i=0; i<79; i++)
    {
      id2403out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 2410 (NodeFIFO)

    for(int i=0; i<26; i++)
    {
      id2410out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 1275 (NodeInputMappedReg)
    id1275out_io_z_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_z_force_disabled");
  }
  { // Node ID: 1349 (NodeCounter)

    (id1349st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
}

void loopKernel::updateState() {
  { // Node ID: 27 (NodeInputMappedReg)
    id27out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 1275 (NodeInputMappedReg)
    id1275out_io_z_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_z_force_disabled");
  }
}

void loopKernel::preExecute() {
  { // Node ID: 29 (NodeInput)
    if(((needsToReadInput(m_y))&(((getFlushLevel())<((0l)+(5)))|(!(isFlushingActive()))))) {
      (id29st_last_read_value) = (readInput<HWRawBits<96> >(m_y));
    }
    id29out_data = (id29st_last_read_value);
  }
}

void loopKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "loopKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int loopKernel::getFlushLevelStart() {
  return ((0l)+(0l));
}

}
