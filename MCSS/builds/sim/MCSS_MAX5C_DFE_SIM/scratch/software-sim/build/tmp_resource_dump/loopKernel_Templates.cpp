#include "stdsimheader.h"

using namespace maxcompilersim;

namespace maxcompilersim {
// Templated Types used in the kernel
template class HWOffsetFix<42,-37,TWOSCOMPLEMENT>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWOffsetFix<8,0,TWOSCOMPLEMENT>;
template class HWRawBits<80>;
template class HWRawBits<27>;
template class HWOffsetFix<80,-79,TWOSCOMPLEMENT>;
template class HWRawBits<25>;
template class HWOffsetFix<24,0,UNSIGNED>;
template class HWRawBits<23>;
template class HWOffsetFix<10,0,TWOSCOMPLEMENT>;
template class HWOffsetFix<80,-78,TWOSCOMPLEMENT>;
template class HWOffsetFix<44,-40,TWOSCOMPLEMENT>;
template class HWOffsetFix<43,-37,TWOSCOMPLEMENT>;
template class HWOffsetFix<1,0,UNSIGNED>;
template class HWOffsetFix<27,-23,TWOSCOMPLEMENT>;
template class HWRawBits<31>;
template class HWRawBits<79>;
template class HWOffsetFix<32,0,UNSIGNED>;
template class HWRawBits<96>;
template class HWRawBits<12>;
template class HWOffsetFix<33,0,UNSIGNED>;
template class HWOffsetFix<25,-19,TWOSCOMPLEMENT>;
template class HWRawBits<2>;
template class HWOffsetFix<81,0,UNSIGNED>;
template class HWRawBits<185>;
template class HWOffsetFix<80,0,UNSIGNED>;
template class HWRawBits<128>;
template class HWRawBits<6>;
template class HWRawBits<8>;
template class HWOffsetFix<45,-40,TWOSCOMPLEMENT>;
template class HWOffsetFix<24,-24,UNSIGNED>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWOffsetFix<9,0,TWOSCOMPLEMENT>;
template class HWRawBits<81>;
template class HWRawBits<24>;
template class HWRawBits<64>;
template class HWOffsetFix<17,-17,UNSIGNED>;
template class HWRawBits<32>;
template class HWOffsetFix<25,-23,TWOSCOMPLEMENT>;
template class HWOffsetFix<2,0,UNSIGNED>;
template class HWRawBits<30>;
template class HWOffsetFix<7,0,UNSIGNED>;
template class HWOffsetFix<8,0,UNSIGNED>;
template class HWOffsetFix<5,0,UNSIGNED>;
template class HWRawBits<17>;
template class HWOffsetFix<42,-36,TWOSCOMPLEMENT>;
template class HWRawBits<3>;
template class HWOffsetFix<24,-23,UNSIGNED>;
template class HWFloat<8,24>;
template class HWOffsetFix<25,-24,UNSIGNED>;
template class HWRawBits<1>;
template class HWOffsetFix<79,-79,UNSIGNED>;
template class HWRawBits<108>;
template class HWOffsetFix<23,-23,UNSIGNED>;
template class HWOffsetFix<25,-20,TWOSCOMPLEMENT>;
template class HWRawBits<7>;
template class HWRawBits<9>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWRawBits<1> slice<65,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<25,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>add_fixed <9,0,TWOSCOMPLEMENT,TONEAREVEN,9,0,TWOSCOMPLEMENT,9,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWRawBits<2> cat<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b);
template HWRawBits<80>and_bits<>(const HWRawBits<80> &a,  const HWRawBits<80> &b );
template HWOffsetFix<8,0,TWOSCOMPLEMENT> cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<10,0,TWOSCOMPLEMENT> &a);
template HWOffsetFix<1,0,UNSIGNED>gt_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b );
template HWRawBits<1> slice<79,1>(const HWOffsetFix<81,0,UNSIGNED> &a);
template HWRawBits<1> slice<57,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>eq_bits<>(const HWRawBits<8> &a,  const HWRawBits<8> &b );
template HWOffsetFix<9,0,TWOSCOMPLEMENT>sub_fixed <9,0,TWOSCOMPLEMENT,TONEAREVEN,8,0,UNSIGNED,7,0,UNSIGNED, false>(const HWOffsetFix<8,0,UNSIGNED> &a, const HWOffsetFix<7,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<0,1>(const HWRawBits<2> &a);
template HWRawBits<1> slice<18,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<49,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<8,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<10,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<50,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<17> slice<0,17>(const HWOffsetFix<25,-24,UNSIGNED> &a);
template HWRawBits<27> slice<54,27>(const HWRawBits<108> &a);
template HWRawBits<1> slice<41,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<25,-20,TWOSCOMPLEMENT> cast_fixed2fixed<25,-20,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<45,-40,TWOSCOMPLEMENT> &a);
template HWOffsetFix<43,-37,TWOSCOMPLEMENT>add_fixed <43,-37,TWOSCOMPLEMENT,TONEAREVEN,42,-37,TWOSCOMPLEMENT,27,-23,TWOSCOMPLEMENT, false>(const HWOffsetFix<42,-37,TWOSCOMPLEMENT> &a, const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<25,-24,UNSIGNED> cast_fixed2fixed<25,-24,UNSIGNED,TONEAREVEN>(const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWRawBits<1> slice<42,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<80,0,UNSIGNED> cast_bits2fixed<80,0,UNSIGNED>(const HWRawBits<80> &a);
template HWRawBits<1> slice<17,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<30> cat<>(const HWOffsetFix<5,0,UNSIGNED> &a, const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &b);
template HWRawBits<1> slice<13,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<73,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<34,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<25,-19,TWOSCOMPLEMENT> cast_fixed2fixed<25,-19,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<43,-37,TWOSCOMPLEMENT> &a);
template HWRawBits<1> slice<33,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<25,-24,UNSIGNED> cast_bits2fixed<25,-24,UNSIGNED>(const HWRawBits<25> &a);
template HWRawBits<2> slice<79,2>(const HWOffsetFix<81,0,UNSIGNED> &a);
template HWOffsetFix<45,-40,TWOSCOMPLEMENT>add_fixed <45,-40,TWOSCOMPLEMENT,TONEAREVEN,44,-40,TWOSCOMPLEMENT,27,-23,TWOSCOMPLEMENT, false>(const HWOffsetFix<44,-40,TWOSCOMPLEMENT> &a, const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<79,-79,UNSIGNED> cast_bits2fixed<79,-79,UNSIGNED>(const HWRawBits<79> &a);
template HWRawBits<25> cat<>(const HWRawBits<2> &a, const HWRawBits<23> &b);
template HWRawBits<1> slice<9,1>(const HWFloat<8,24> &a);
template HWRawBits<32> slice<0,32>(const HWRawBits<96> &a);
template HWRawBits<80> cast_fixed2bits<>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<81,0,UNSIGNED> cast_bits2fixed<81,0,UNSIGNED>(const HWRawBits<81> &a);
template HWRawBits<1> slice<4,1>(const HWFloat<8,24> &a);
template HWOffsetFix<1,0,UNSIGNED>lt_fixed<>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b );
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);
template HWOffsetFix<32,0,UNSIGNED>sub_fixed <32,0,UNSIGNED,TONEAREVEN,32,0,UNSIGNED,32,0,UNSIGNED, false>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<79,1>(const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &a);
template HWRawBits<3> cat<>(const HWRawBits<2> &a, const HWRawBits<1> &b);
template HWFloat<8,24> cast_fixed2float<8,24>(const HWOffsetFix<25,-19,TWOSCOMPLEMENT> &a);
template HWRawBits<128> cat<>(const HWRawBits<64> &a, const HWRawBits<64> &b);
template HWOffsetFix<81,0,UNSIGNED>mul_fixed <81,0,UNSIGNED,TONEAREVEN,24,0,UNSIGNED,81,0,UNSIGNED, false>(const HWOffsetFix<24,0,UNSIGNED> &a, const HWOffsetFix<81,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<17,-17,UNSIGNED> cast_bits2fixed<17,-17,UNSIGNED>(const HWRawBits<17> &a);
template HWOffsetFix<49,0,UNSIGNED>add_fixed <49,0,UNSIGNED,TRUNCATE,49,0,UNSIGNED,49,0,UNSIGNED, false>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<32> slice<96,32>(const HWRawBits<128> &a);
template HWRawBits<32> slice<32,32>(const HWRawBits<128> &a);
template HWOffsetFix<23,-23,UNSIGNED> cast_bits2fixed<23,-23,UNSIGNED>(const HWRawBits<23> &a);
template HWRawBits<23> slice<0,23>(const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &a);
template HWRawBits<23> slice<0,23>(const HWFloat<8,24> &a);
template HWOffsetFix<10,0,TWOSCOMPLEMENT>sub_fixed <10,0,TWOSCOMPLEMENT,TONEAREVEN,10,0,TWOSCOMPLEMENT,9,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<10,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>eq_bits<>(const HWRawBits<2> &a,  const HWRawBits<2> &b );
template HWRawBits<23> slice<0,23>(const HWRawBits<96> &a);
template HWRawBits<1> slice<0,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<2,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<64> cat<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b);
template HWRawBits<1> slice<35,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<55,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<15,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<80,-79,TWOSCOMPLEMENT> cast_bits2fixed<80,-79,TWOSCOMPLEMENT>(const HWRawBits<80> &a);
template HWRawBits<1> slice<2,1>(const HWFloat<8,24> &a);
template HWRawBits<27> slice<0,27>(const HWRawBits<108> &a);
template HWOffsetFix<1,0,UNSIGNED>or_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );
template HWFloat<8,24> cast_fixed2float<8,24>(const HWOffsetFix<25,-24,UNSIGNED> &a);
template HWRawBits<1> slice<75,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<21,1>(const HWFloat<8,24> &a);
template HWOffsetFix<7,0,UNSIGNED> cast_fixed2fixed<7,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<8,0,TWOSCOMPLEMENT> &a);
template HWRawBits<80>not_bits<>(const HWRawBits<80> &a );
template HWRawBits<1> slice<6,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<11,1>(const HWFloat<8,24> &a);
template HWRawBits<32> slice<0,32>(const HWRawBits<128> &a);
template HWRawBits<2> cat<>(const HWRawBits<1> &a, const HWOffsetFix<1,0,UNSIGNED> &b);
template HWRawBits<1> slice<59,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<79,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWRawBits<1> slice<8,1>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWRawBits<1> slice<20,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<10,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<40,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<8> slice<23,8>(const HWRawBits<96> &a);
template HWRawBits<30>shift_left_bits<>(const HWRawBits<30> &a, long shift_by );
template HWOffsetFix<44,-40,TWOSCOMPLEMENT>mul_fixed <44,-40,TWOSCOMPLEMENT,TONEAREVEN,27,-23,TWOSCOMPLEMENT,17,-17,UNSIGNED, false>(const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &a, const HWOffsetFix<17,-17,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<60,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<31,1>(const HWRawBits<96> &a);
template HWRawBits<24> cat<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWRawBits<23> &b);
template HWRawBits<1> slice<19,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<39,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWRawBits<1>xor_bits<>(const HWRawBits<1> &a,  const HWRawBits<1> &b );
template HWRawBits<1> slice<31,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template void KernelManagerBlockSync::writeOutput< HWRawBits<128> >(const t_port_number port_number, const HWRawBits<128> &value);
template HWRawBits<80> cast_fixed2bits<>(const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &a);
template HWRawBits<1> slice<11,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<18,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>sub_fixed <9,0,TWOSCOMPLEMENT,TRUNCATE,9,0,TWOSCOMPLEMENT,7,0,UNSIGNED, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<7,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<3,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<51,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<71,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<44,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<31,1>(const HWFloat<8,24> &a);
template HWRawBits<185>shift_left_bits<>(const HWRawBits<185> &a, long shift_by );
template HWRawBits<1> slice<22,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<24,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<6> cat<>(const HWRawBits<3> &a, const HWRawBits<3> &b);
template HWRawBits<1> slice<64,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<54,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<3,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<31> slice<0,31>(const HWFloat<8,24> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>sub_fixed <9,0,TWOSCOMPLEMENT,TONEAREVEN,9,0,TWOSCOMPLEMENT,9,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED> cast_bits2fixed<1,0,UNSIGNED>(const HWRawBits<1> &a);
template HWRawBits<1> slice<74,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<24>shift_right_bits<>(const HWRawBits<24> &a, long shift_by );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b );
template HWRawBits<1> slice<38,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<7,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<68,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>neq_bits<>(const HWRawBits<23> &a,  const HWRawBits<23> &b );
template HWRawBits<1> slice<48,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> cast_fixed2bits<>(const HWOffsetFix<1,0,UNSIGNED> &a);
template HWRawBits<1> slice<58,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<10,0,TWOSCOMPLEMENT>sub_fixed <10,0,TWOSCOMPLEMENT,TONEAREVEN,10,0,TWOSCOMPLEMENT,8,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<10,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<8,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<42,-36,TWOSCOMPLEMENT>add_fixed <42,-36,TWOSCOMPLEMENT,TONEAREVEN,42,-36,TWOSCOMPLEMENT,27,-23,TWOSCOMPLEMENT, false>(const HWOffsetFix<42,-36,TWOSCOMPLEMENT> &a, const HWOffsetFix<27,-23,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<80,-79,TWOSCOMPLEMENT> cast_fixed2fixed<80,-79,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<79,-79,UNSIGNED> &a);
template HWRawBits<1> slice<78,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<8,0,TWOSCOMPLEMENT> cast_fixed2fixed<8,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<7,0,UNSIGNED> &a);
template HWRawBits<1> slice<1,1>(const HWFloat<8,24> &a);
template HWRawBits<8> slice<23,8>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<20,1>(const HWFloat<8,24> &a);
template HWRawBits<7> slice<23,7>(const HWRawBits<30> &a);
template HWRawBits<31> slice<0,31>(const HWRawBits<96> &a);
template HWFloat<8,24>mul_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWRawBits<81> cat<>(const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &a, const HWOffsetFix<1,0,UNSIGNED> &b);
template HWRawBits<2>xor_bits<>(const HWRawBits<2> &a,  const HWRawBits<2> &b );
template HWRawBits<32> cat<>(const HWRawBits<1> &a, const HWRawBits<31> &b);
template HWFloat<8,24>neg_float<>(const HWFloat<8,24> &a );
template HWOffsetFix<8,0,UNSIGNED> cast_bits2fixed<8,0,UNSIGNED>(const HWRawBits<8> &a);
template HWOffsetFix<27,-23,TWOSCOMPLEMENT> cast_fixed2fixed<27,-23,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<23,-23,UNSIGNED> &a);
template HWRawBits<25>shift_right_fixed<>(const HWOffsetFix<25,-24,UNSIGNED> &a, long shift_by );
template HWOffsetFix<7,0,UNSIGNED>or_fixed<>(const HWOffsetFix<7,0,UNSIGNED> &a, const HWOffsetFix<7,0,UNSIGNED> &b );
template HWOffsetFix<27,-23,TWOSCOMPLEMENT> cast_bits2fixed<27,-23,TWOSCOMPLEMENT>(const HWRawBits<27> &a);
template HWOffsetFix<1,0,UNSIGNED>gt_fixed<>(const HWOffsetFix<8,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<8,0,TWOSCOMPLEMENT> &b );
template HWRawBits<1> slice<45,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT> cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<8,0,TWOSCOMPLEMENT> &a);
template HWRawBits<1> slice<4,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<25,-23,TWOSCOMPLEMENT>add_fixed <25,-23,TWOSCOMPLEMENT,TRUNCATE,25,-23,TWOSCOMPLEMENT,25,-23,TWOSCOMPLEMENT, false>(const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &a, const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<37,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWRawBits<1> slice<5,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<77,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>neg_fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a );
template HWRawBits<27> slice<81,27>(const HWRawBits<108> &a);
template HWRawBits<32> slice<64,32>(const HWRawBits<96> &a);
template HWRawBits<1> slice<69,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<30,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<70,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<29,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<32,0,UNSIGNED> cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<33,0,UNSIGNED> &a);
template HWRawBits<1> slice<21,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<19,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<0,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<28,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<32> slice<32,32>(const HWRawBits<96> &a);
template HWOffsetFix<10,0,TWOSCOMPLEMENT>sub_fixed <10,0,TWOSCOMPLEMENT,TONEAREVEN,8,0,UNSIGNED,7,0,UNSIGNED, false>(const HWOffsetFix<8,0,UNSIGNED> &a, const HWOffsetFix<7,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<13,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<22,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<61,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<14,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<53,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<62,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>lt_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWFloat<8,24>div_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWRawBits<1> slice<12,1>(const HWFloat<8,24> &a);
template HWOffsetFix<24,0,UNSIGNED> cast_bits2fixed<24,0,UNSIGNED>(const HWRawBits<24> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>sub_fixed <9,0,TWOSCOMPLEMENT,TRUNCATE,9,0,TWOSCOMPLEMENT,9,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<17,1>(const HWFloat<8,24> &a);
template HWOffsetFix<1,0,UNSIGNED>gt_fixed<>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b );
template HWFloat<8,24> cast_fixed2float<8,24>(const HWOffsetFix<24,-24,UNSIGNED> &a);
template HWOffsetFix<25,-23,TWOSCOMPLEMENT> cast_bits2fixed<25,-23,TWOSCOMPLEMENT>(const HWRawBits<25> &a);
template HWOffsetFix<25,-19,TWOSCOMPLEMENT> cast_fixed2fixed<25,-19,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<42,-36,TWOSCOMPLEMENT> &a);
template HWOffsetFix<24,-23,UNSIGNED> cast_fixed2fixed<24,-23,UNSIGNED,TONEAREVEN>(const HWOffsetFix<80,-78,TWOSCOMPLEMENT> &a);
template HWOffsetFix<33,0,UNSIGNED> cast_fixed2fixed<33,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<32,0,UNSIGNED> &a);
template HWRawBits<12> cat<>(const HWRawBits<6> &a, const HWRawBits<6> &b);
template HWRawBits<3> cat<>(const HWRawBits<2> &a, const HWOffsetFix<1,0,UNSIGNED> &b);
template HWRawBits<27> slice<27,27>(const HWRawBits<108> &a);
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b );
template HWRawBits<185>shift_right_bits<>(const HWRawBits<185> &a, long shift_by );
template HWOffsetFix<80,0,UNSIGNED>add_fixed <80,0,UNSIGNED,TRUNCATE,80,0,UNSIGNED,80,0,UNSIGNED, false>(const HWOffsetFix<80,0,UNSIGNED> &a, const HWOffsetFix<80,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<7,0,UNSIGNED> cast_bits2fixed<7,0,UNSIGNED>(const HWRawBits<7> &a);
template HWOffsetFix<2,0,UNSIGNED> cast_bits2fixed<2,0,UNSIGNED>(const HWRawBits<2> &a);
template HWRawBits<1> slice<16,1>(const HWFloat<8,24> &a);
template HWRawBits<7> slice<17,7>(const HWOffsetFix<25,-24,UNSIGNED> &a);
template HWRawBits<2> cat<>(const HWRawBits<1> &a, const HWRawBits<1> &b);
template HWFloat<8,24>add_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<10,0,TWOSCOMPLEMENT>sub_fixed <10,0,TWOSCOMPLEMENT,TONEAREVEN,8,0,TWOSCOMPLEMENT,8,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<8,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<8,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<27,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<47,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<5,0,UNSIGNED> cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWRawBits<79> slice<0,79>(const HWOffsetFix<81,0,UNSIGNED> &a);
template HWRawBits<1> slice<67,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<9,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<8,1>(const HWFloat<8,24> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>add_fixed <9,0,TWOSCOMPLEMENT,TRUNCATE,9,0,TWOSCOMPLEMENT,9,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>lte_fixed<>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b );
template HWOffsetFix<9,0,TWOSCOMPLEMENT>add_fixed <9,0,TWOSCOMPLEMENT,TRUNCATE,9,0,TWOSCOMPLEMENT,8,0,UNSIGNED, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<8,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<23,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<72,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<12,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<63,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<9> cat<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<8,0,UNSIGNED> &b);
template HWRawBits<1> slice<32,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<43,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<8,0,UNSIGNED> cast_fixed2fixed<8,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWRawBits<24> cat<>(const HWRawBits<12> &a, const HWRawBits<12> &b);
template HWRawBits<1> slice<52,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<33,0,UNSIGNED>add_fixed <33,0,UNSIGNED,TRUNCATE,33,0,UNSIGNED,33,0,UNSIGNED, false>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<80,-78,TWOSCOMPLEMENT> cast_bits2fixed<80,-78,TWOSCOMPLEMENT>(const HWRawBits<80> &a);
template HWOffsetFix<42,-37,TWOSCOMPLEMENT>mul_fixed <42,-37,TWOSCOMPLEMENT,TONEAREVEN,25,-20,TWOSCOMPLEMENT,17,-17,UNSIGNED, false>(const HWOffsetFix<25,-20,TWOSCOMPLEMENT> &a, const HWOffsetFix<17,-17,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<80,-79,TWOSCOMPLEMENT>not_fixed<>(const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &a );
template HWRawBits<1> slice<16,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>neq_bits<>(const HWRawBits<31> &a,  const HWRawBits<31> &b );
template HWRawBits<1> slice<26,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<6,1>(const HWFloat<8,24> &a);
template HWRawBits<1> slice<5,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<76,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<66,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWFloat<8,24>sub_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWRawBits<1> slice<36,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<1> slice<46,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWOffsetFix<5,0,UNSIGNED> cast_fixed2fixed<5,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWFloat<8,24> cast_bits2float<8,24>(const HWRawBits<32> &a);
template HWRawBits<80> slice<0,80>(const HWRawBits<81> &a);
template HWOffsetFix<1,0,UNSIGNED>gt_fixed<>(const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &a, const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &b );
template HWRawBits<1> slice<56,1>(const HWOffsetFix<80,0,UNSIGNED> &a);
template HWRawBits<23> slice<0,23>(const HWOffsetFix<24,-23,UNSIGNED> &a);
template HWRawBits<24>not_bits<>(const HWRawBits<24> &a );
template HWOffsetFix<1,0,UNSIGNED>eq_bits<>(const HWRawBits<31> &a,  const HWRawBits<31> &b );
template HWOffsetFix<24,-24,UNSIGNED> cast_bits2fixed<24,-24,UNSIGNED>(const HWRawBits<24> &a);
template HWRawBits<1> slice<15,1>(const HWFloat<8,24> &a);
template HWRawBits<80>shift_left_fixed<>(const HWOffsetFix<80,-79,TWOSCOMPLEMENT> &a, long shift_by );
template HWRawBits<24>shift_left_bits<>(const HWRawBits<24> &a, long shift_by );
template HWOffsetFix<25,-23,TWOSCOMPLEMENT>sub_fixed <25,-23,TWOSCOMPLEMENT,TRUNCATE,25,-23,TWOSCOMPLEMENT,25,-23,TWOSCOMPLEMENT, false>(const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &a, const HWOffsetFix<25,-23,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWRawBits<1>not_bits<>(const HWRawBits<1> &a );
template HWRawBits<96> KernelManagerBlockSync::readInput< HWRawBits<96> >(const t_port_number port_number);
template HWOffsetFix<42,-36,TWOSCOMPLEMENT>mul_fixed <42,-36,TWOSCOMPLEMENT,TONEAREVEN,25,-19,TWOSCOMPLEMENT,17,-17,UNSIGNED, false>(const HWOffsetFix<25,-19,TWOSCOMPLEMENT> &a, const HWOffsetFix<17,-17,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<1> slice<14,1>(const HWFloat<8,24> &a);
template HWRawBits<32> cat<>(const HWRawBits<9> &a, const HWRawBits<23> &b);
template HWFloat<8,24>sqrt_float<>(const HWFloat<8,24> &a );
template HWRawBits<32> slice<64,32>(const HWRawBits<128> &a);
template HWRawBits<81> slice<104,81>(const HWRawBits<185> &a);
template HWRawBits<1> slice<7,1>(const HWFloat<8,24> &a);
template HWRawBits<8> slice<0,8>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );
template HWOffsetFix<9,0,TWOSCOMPLEMENT> cast_fixed2fixed<9,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<10,0,TWOSCOMPLEMENT> &a);
template HWRawBits<1> slice<1,1>(const HWOffsetFix<80,0,UNSIGNED> &a);


// Additional Code

} // End of maxcompilersim namespace
