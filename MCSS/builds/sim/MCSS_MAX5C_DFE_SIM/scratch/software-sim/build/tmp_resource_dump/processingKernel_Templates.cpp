#include "stdsimheader.h"

using namespace maxcompilersim;

namespace maxcompilersim {
// Templated Types used in the kernel
template class HWRawBits<4864>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWRawBits<288>;
template class HWOffsetFix<9,0,TWOSCOMPLEMENT>;
template class HWRawBits<160>;
template class HWRawBits<320>;
template class HWRawBits<64>;
template class HWRawBits<2432>;
template class HWRawBits<1216>;
template class HWOffsetFix<1,0,UNSIGNED>;
template class HWRawBits<32>;
template class HWOffsetFix<2,0,UNSIGNED>;
template class HWRawBits<608>;
template class HWOffsetFix<7,0,UNSIGNED>;
template class HWOffsetFix<8,0,UNSIGNED>;
template class HWOffsetFix<5,0,UNSIGNED>;
template class HWOffsetFix<32,0,UNSIGNED>;
template class HWRawBits<96>;
template class HWRawBits<9728>;
template class HWFloat<8,24>;
template class HWRawBits<1>;
template class HWOffsetFix<64,0,UNSIGNED>;
template class HWRawBits<128>;
template class HWOffsetFix<65,0,UNSIGNED>;
template class HWRawBits<8>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWRawBits<2432> cat<>(const HWRawBits<1216> &a, const HWRawBits<1216> &b);
template HWOffsetFix<2,0,UNSIGNED> cast_fixed2fixed<2,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<1,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>gt_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWFloat<8,24>add_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWOffsetFix<5,0,UNSIGNED> cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWRawBits<64> cat<>(const HWRawBits<32> &a, const HWRawBits<32> &b);
template HWRawBits<9728> cat<>(const HWRawBits<4864> &a, const HWRawBits<4864> &b);
template HWRawBits<32> slice<0,32>(const HWRawBits<128> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>sub_fixed <9,0,TWOSCOMPLEMENT,TONEAREVEN,8,0,UNSIGNED,7,0,UNSIGNED, false>(const HWOffsetFix<8,0,UNSIGNED> &a, const HWOffsetFix<7,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<96> cat<>(const HWRawBits<64> &a, const HWOffsetFix<32,0,UNSIGNED> &b);
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<32,0,UNSIGNED> cast_float2fixed<32,0,UNSIGNED,TONEAREVEN>(const HWFloat<8,24> &a);
template HWRawBits<288> cat<>(const HWRawBits<160> &a, const HWRawBits<128> &b);
template HWOffsetFix<48,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name);
template HWRawBits<1> slice<8,1>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b );
template HWOffsetFix<65,0,UNSIGNED>add_fixed <65,0,UNSIGNED,TRUNCATE,65,0,UNSIGNED,65,0,UNSIGNED, false>(const HWOffsetFix<65,0,UNSIGNED> &a, const HWOffsetFix<65,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWRawBits<320> cat<>(const HWRawBits<160> &a, const HWRawBits<160> &b);
template HWOffsetFix<1,0,UNSIGNED>neq_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWRawBits<32>shift_left_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, long shift_by );
template HWRawBits<32>and_bits<>(const HWRawBits<32> &a,  const HWRawBits<32> &b );
template HWRawBits<1216> cat<>(const HWRawBits<608> &a, const HWRawBits<608> &b);
template HWRawBits<608> cat<>(const HWRawBits<320> &a, const HWRawBits<288> &b);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<64,0,UNSIGNED> &a, const HWOffsetFix<64,0,UNSIGNED> &b );
template HWFloat<8,24>div_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<65,0,UNSIGNED> &a, const HWOffsetFix<65,0,UNSIGNED> &b );
template HWOffsetFix<64,0,UNSIGNED> cast_fixed2fixed<64,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<65,0,UNSIGNED> &a);
template HWOffsetFix<32,0,UNSIGNED> cast_fixed2fixed<32,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<1,0,UNSIGNED> &a);
template HWOffsetFix<9,0,TWOSCOMPLEMENT>sub_fixed <9,0,TWOSCOMPLEMENT,TONEAREVEN,9,0,TWOSCOMPLEMENT,9,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>gt_fixed<>(const HWOffsetFix<9,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<9,0,TWOSCOMPLEMENT> &b );
template HWFloat<8,24> cast_bits2float<8,24>(const HWRawBits<32> &a);
template HWOffsetFix<1,0,UNSIGNED> cast_bits2fixed<1,0,UNSIGNED>(const HWRawBits<1> &a);
template HWRawBits<128> KernelManagerBlockSync::readInput< HWRawBits<128> >(const t_port_number port_number);
template HWOffsetFix<32,0,UNSIGNED>add_fixed <32,0,UNSIGNED,TONEAREVEN,32,0,UNSIGNED,32,0,UNSIGNED, false>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<48,0,UNSIGNED> &a, const HWOffsetFix<48,0,UNSIGNED> &b );
template HWRawBits<160> cat<>(const HWRawBits<96> &a, const HWRawBits<64> &b);
template void KernelManagerBlockSync::writeOutput< HWFloat<8,24> >(const t_port_number port_number, const HWFloat<8,24> &value);
template HWRawBits<8> slice<23,8>(const HWFloat<8,24> &a);
template HWOffsetFix<64,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<64,0,UNSIGNED> >(const std::string &name);
template void KernelManagerBlockSync::writeOutput< HWRawBits<9728> >(const t_port_number port_number, const HWRawBits<9728> &value);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);
template HWFloat<8,24>mul_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWRawBits<4864> cat<>(const HWRawBits<2432> &a, const HWRawBits<2432> &b);
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWRawBits<128> cat<>(const HWRawBits<64> &a, const HWRawBits<64> &b);
template HWFloat<8,24>sqrt_float<>(const HWFloat<8,24> &a );
template HWRawBits<32> slice<64,32>(const HWRawBits<128> &a);
template HWRawBits<32> cast_fixed2bits<>(const HWOffsetFix<32,0,UNSIGNED> &a);
template HWOffsetFix<64,0,UNSIGNED>add_fixed <64,0,UNSIGNED,TONEAREVEN,64,0,UNSIGNED,64,0,UNSIGNED, false>(const HWOffsetFix<64,0,UNSIGNED> &a, const HWOffsetFix<64,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWFloat<8,24>neg_float<>(const HWFloat<8,24> &a );
template HWOffsetFix<32,0,UNSIGNED> cast_bits2fixed<32,0,UNSIGNED>(const HWRawBits<32> &a);
template HWOffsetFix<49,0,UNSIGNED>add_fixed <49,0,UNSIGNED,TRUNCATE,49,0,UNSIGNED,49,0,UNSIGNED, false>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWRawBits<32> slice<96,32>(const HWRawBits<128> &a);
template HWRawBits<32> slice<32,32>(const HWRawBits<128> &a);
template HWOffsetFix<8,0,UNSIGNED> cast_bits2fixed<8,0,UNSIGNED>(const HWRawBits<8> &a);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b );
template HWRawBits<32> cast_float2bits<>(const HWFloat<8,24> &a);
template HWRawBits<64> cat<>(const HWOffsetFix<32,0,UNSIGNED> &a, const HWOffsetFix<32,0,UNSIGNED> &b);
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );


// Additional Code
std::string processingKernel::format_string_processingKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<64,0,UNSIGNED> &_format_arg_0, const HWFloat<8,24> &_format_arg_1, const HWFloat<8,24> &_format_arg_2, const HWFloat<8,24> &_format_arg_3, const HWFloat<8,24> &_format_arg_4)
{return ( bfmt(_format_arg_format_string)% _format_arg_0 % _format_arg_1 % _format_arg_2 % _format_arg_3 % _format_arg_4 ).str();}

} // End of maxcompilersim namespace
