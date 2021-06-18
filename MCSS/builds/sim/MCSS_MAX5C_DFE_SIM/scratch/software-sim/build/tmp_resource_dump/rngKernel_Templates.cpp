#include "stdsimheader.h"

using namespace maxcompilersim;

namespace maxcompilersim {
// Templated Types used in the kernel
template class HWRawBits<31>;
template class HWRawBits<32>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWFloat<8,24>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWRawBits<1>;
template class HWOffsetFix<11,0,UNSIGNED>;
template class HWOffsetFix<10,0,UNSIGNED>;
template class HWOffsetFix<32,0,UNSIGNED>;
template class HWRawBits<96>;
template class HWRawBits<64>;
template class HWOffsetFix<1,0,UNSIGNED>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWRawBits<1> slice<0,1>(const HWOffsetFix<32,0,UNSIGNED> &a);
template HWOffsetFix<32,0,UNSIGNED>xor_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b );
template HWRawBits<32>shift_right_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, long shift_by );
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<10,0,UNSIGNED> &a, const HWOffsetFix<10,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>gt_fixed<>(const HWOffsetFix<11,0,UNSIGNED> &a, const HWOffsetFix<11,0,UNSIGNED> &b );
template HWRawBits<31> slice<0,31>(const HWOffsetFix<32,0,UNSIGNED> &a);
template HWOffsetFix<11,0,UNSIGNED>add_fixed <11,0,UNSIGNED,TRUNCATE,11,0,UNSIGNED,11,0,UNSIGNED, false>(const HWOffsetFix<11,0,UNSIGNED> &a, const HWOffsetFix<11,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template void KernelManagerBlockSync::writeOutput< HWRawBits<96> >(const t_port_number port_number, const HWRawBits<96> &value);
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWFloat<8,24> cast_fixed2float<8,24>(const HWOffsetFix<32,0,UNSIGNED> &a);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);
template HWFloat<8,24>mul_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWOffsetFix<32,0,UNSIGNED>and_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b );
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWRawBits<32> cat<>(const HWRawBits<1> &a, const HWRawBits<31> &b);
template HWOffsetFix<32,0,UNSIGNED> cast_bits2fixed<32,0,UNSIGNED>(const HWRawBits<32> &a);
template HWOffsetFix<49,0,UNSIGNED>add_fixed <49,0,UNSIGNED,TRUNCATE,49,0,UNSIGNED,49,0,UNSIGNED, false>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<32>shift_left_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, long shift_by );
template HWOffsetFix<10,0,UNSIGNED> cast_fixed2fixed<10,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<11,0,UNSIGNED> &a);
template HWRawBits<64> cat<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b);
template HWRawBits<1> slice<31,1>(const HWOffsetFix<32,0,UNSIGNED> &a);
template HWRawBits<96> cat<>(const HWRawBits<64> &a, const HWFloat<8,24> &b);
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );


// Additional Code

} // End of maxcompilersim namespace
