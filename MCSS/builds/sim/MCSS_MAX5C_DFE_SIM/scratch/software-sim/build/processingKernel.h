#ifndef PROCESSINGKERNEL_H_
#define PROCESSINGKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class processingKernel : public KernelManagerBlockSync {
public:
  processingKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void ramInitialise();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_z;
  t_port_number m_internal_watch_track2_output;
  t_port_number m_output;
  HWOffsetFix<1,0,UNSIGNED> id2520out_value;

  HWOffsetFix<1,0,UNSIGNED> id4out_io_z_force_disabled;

  HWRawBits<128> id6out_data;

  HWOffsetFix<1,0,UNSIGNED> id6st_read_next_cycle;
  HWRawBits<128> id6st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id22out_value;

  HWOffsetFix<1,0,UNSIGNED> id3447out_value;

  HWOffsetFix<65,0,UNSIGNED> id2out_value;

  HWOffsetFix<64,0,UNSIGNED> id3out_count;
  HWOffsetFix<1,0,UNSIGNED> id3out_wrap;

  HWOffsetFix<65,0,UNSIGNED> id3st_count;

  std::string format_string_processingKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<64,0,UNSIGNED> &_format_arg_0, const HWFloat<8,24> &_format_arg_1, const HWFloat<8,24> &_format_arg_2, const HWFloat<8,24> &_format_arg_3, const HWFloat<8,24> &_format_arg_4);
  HWOffsetFix<64,0,UNSIGNED> id3446out_value;

  HWOffsetFix<64,0,UNSIGNED> id1892out_result[2];

  HWOffsetFix<64,0,UNSIGNED> id0out_numHists;

  HWOffsetFix<1,0,UNSIGNED> id2522out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1894out_io_output_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id4478out_output[112];

  HWRawBits<32> id2517out_value;

  HWRawBits<32> id2518out_value;

  HWOffsetFix<1,0,UNSIGNED> id75out_value;

  HWOffsetFix<1,0,UNSIGNED> id76out_output;

  long id76st_count;
  HWOffsetFix<1,0,UNSIGNED> id76st_value;

  HWOffsetFix<1,0,UNSIGNED> id3456out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3455out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3454out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3893out_output[7];

  HWOffsetFix<1,0,UNSIGNED> id4480out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3445out_value;

  HWOffsetFix<32,0,UNSIGNED> id3477out_output[2];

  HWFloat<8,24> id24out_result[9];

  HWFloat<8,24> id25out_result[9];

  HWFloat<8,24> id26out_result[12];

  HWFloat<8,24> id27out_result[29];

  HWFloat<8,24> id3466out_output[48];

  HWFloat<8,24> id29out_result[29];

  HWFloat<8,24> id3444out_value;

  HWFloat<8,24> id31out_result[9];

  HWOffsetFix<7,0,UNSIGNED> id3443out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id36out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3467out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3442out_value;

  HWOffsetFix<1,0,UNSIGNED> id2525out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id57out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3474out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id3472out_output[10];

  HWFloat<8,24> id3469out_output[8];

  HWFloat<8,24> id4481out_output[2];

  HWFloat<8,24> id3441out_value;

  HWOffsetFix<1,0,UNSIGNED> id51out_result[3];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3440out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id39out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3439out_value;

  HWOffsetFix<1,0,UNSIGNED> id2527out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3470out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id40out_value;

  HWRawBits<32> id44out_dataout[5];

  HWOffsetFix<32,0,UNSIGNED> id46out_result[2];

  HWRawBits<32> id48out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id58out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id59out_result[2];

  HWOffsetFix<2,0,UNSIGNED> id62out_value;

  HWOffsetFix<2,0,UNSIGNED> id61out_value;

  HWOffsetFix<2,0,UNSIGNED> id64out_value;

  HWOffsetFix<1,0,UNSIGNED> id3473out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id3475out_output[9];

  HWFloat<8,24> id2519out_value;

  HWFloat<8,24> id67out_value;

  HWFloat<8,24> id3476out_output[12];

  HWFloat<8,24> id3438out_value;

  HWFloat<8,24> id71out_result[12];

  HWFloat<8,24> id72out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id74out_o[8];

  HWOffsetFix<32,0,UNSIGNED> id3459out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3458out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3457out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3437out_value;

  HWOffsetFix<32,0,UNSIGNED> id3479out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3436out_value;

  HWOffsetFix<32,0,UNSIGNED> id3481out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3435out_value;

  HWOffsetFix<32,0,UNSIGNED> id3483out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3434out_value;

  HWOffsetFix<32,0,UNSIGNED> id3485out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3433out_value;

  HWOffsetFix<32,0,UNSIGNED> id3487out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3432out_value;

  HWOffsetFix<32,0,UNSIGNED> id3489out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3431out_value;

  HWOffsetFix<32,0,UNSIGNED> id3491out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3453out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3962out_output[6];

  HWOffsetFix<1,0,UNSIGNED> id4482out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3430out_value;

  HWOffsetFix<32,0,UNSIGNED> id3493out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3429out_value;

  HWOffsetFix<32,0,UNSIGNED> id3495out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3428out_value;

  HWOffsetFix<32,0,UNSIGNED> id3497out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3427out_value;

  HWOffsetFix<32,0,UNSIGNED> id3499out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3426out_value;

  HWOffsetFix<32,0,UNSIGNED> id3501out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3425out_value;

  HWOffsetFix<32,0,UNSIGNED> id3503out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3424out_value;

  HWOffsetFix<32,0,UNSIGNED> id3505out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3423out_value;

  HWOffsetFix<32,0,UNSIGNED> id3507out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3422out_value;

  HWOffsetFix<32,0,UNSIGNED> id3509out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3421out_value;

  HWOffsetFix<32,0,UNSIGNED> id3511out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3420out_value;

  HWOffsetFix<32,0,UNSIGNED> id3513out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3419out_value;

  HWOffsetFix<32,0,UNSIGNED> id3515out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3418out_value;

  HWOffsetFix<32,0,UNSIGNED> id3517out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3417out_value;

  HWOffsetFix<32,0,UNSIGNED> id3519out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3416out_value;

  HWOffsetFix<32,0,UNSIGNED> id3521out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3452out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3542out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id4483out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3415out_value;

  HWOffsetFix<32,0,UNSIGNED> id3523out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3414out_value;

  HWOffsetFix<32,0,UNSIGNED> id3525out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3413out_value;

  HWOffsetFix<32,0,UNSIGNED> id3527out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3412out_value;

  HWOffsetFix<32,0,UNSIGNED> id3529out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3411out_value;

  HWOffsetFix<32,0,UNSIGNED> id3531out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3410out_value;

  HWOffsetFix<32,0,UNSIGNED> id3533out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3409out_value;

  HWOffsetFix<32,0,UNSIGNED> id3535out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3408out_value;

  HWOffsetFix<32,0,UNSIGNED> id3537out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3407out_value;

  HWOffsetFix<32,0,UNSIGNED> id3539out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3406out_value;

  HWOffsetFix<32,0,UNSIGNED> id3541out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3405out_value;

  HWOffsetFix<32,0,UNSIGNED> id3543out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3404out_value;

  HWOffsetFix<32,0,UNSIGNED> id3545out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3403out_value;

  HWOffsetFix<32,0,UNSIGNED> id3547out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3402out_value;

  HWOffsetFix<32,0,UNSIGNED> id3549out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3401out_value;

  HWOffsetFix<32,0,UNSIGNED> id3551out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3400out_value;

  HWOffsetFix<32,0,UNSIGNED> id3553out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3451out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3556out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id3399out_value;

  HWOffsetFix<32,0,UNSIGNED> id3555out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3398out_value;

  HWOffsetFix<32,0,UNSIGNED> id3557out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3397out_value;

  HWOffsetFix<32,0,UNSIGNED> id3559out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3396out_value;

  HWOffsetFix<32,0,UNSIGNED> id3561out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3395out_value;

  HWOffsetFix<32,0,UNSIGNED> id3563out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3394out_value;

  HWOffsetFix<32,0,UNSIGNED> id3565out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3393out_value;

  HWOffsetFix<32,0,UNSIGNED> id3567out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3392out_value;

  HWOffsetFix<32,0,UNSIGNED> id3569out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3391out_value;

  HWOffsetFix<32,0,UNSIGNED> id3571out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3390out_value;

  HWOffsetFix<32,0,UNSIGNED> id3573out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3389out_value;

  HWOffsetFix<32,0,UNSIGNED> id3575out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3388out_value;

  HWOffsetFix<32,0,UNSIGNED> id3577out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3387out_value;

  HWOffsetFix<32,0,UNSIGNED> id3579out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3386out_value;

  HWOffsetFix<32,0,UNSIGNED> id3581out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3385out_value;

  HWOffsetFix<32,0,UNSIGNED> id3583out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3450out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3586out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3384out_value;

  HWOffsetFix<32,0,UNSIGNED> id3585out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3383out_value;

  HWOffsetFix<32,0,UNSIGNED> id3587out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3382out_value;

  HWOffsetFix<32,0,UNSIGNED> id3589out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3381out_value;

  HWOffsetFix<32,0,UNSIGNED> id3591out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3380out_value;

  HWOffsetFix<32,0,UNSIGNED> id3593out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3379out_value;

  HWOffsetFix<32,0,UNSIGNED> id3595out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3378out_value;

  HWOffsetFix<32,0,UNSIGNED> id3597out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3377out_value;

  HWOffsetFix<32,0,UNSIGNED> id3599out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3376out_value;

  HWOffsetFix<32,0,UNSIGNED> id3601out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3375out_value;

  HWOffsetFix<1,0,UNSIGNED> id3604out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3603out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3374out_value;

  HWOffsetFix<1,0,UNSIGNED> id3607out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3606out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3373out_value;

  HWOffsetFix<1,0,UNSIGNED> id3610out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3609out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3372out_value;

  HWOffsetFix<1,0,UNSIGNED> id3613out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3612out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3371out_value;

  HWOffsetFix<1,0,UNSIGNED> id3616out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3615out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3370out_value;

  HWOffsetFix<1,0,UNSIGNED> id3619out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3618out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3369out_value;

  HWOffsetFix<1,0,UNSIGNED> id3622out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3621out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3449out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3626out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3368out_value;

  HWOffsetFix<1,0,UNSIGNED> id3625out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3624out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3367out_value;

  HWOffsetFix<1,0,UNSIGNED> id3628out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3627out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3366out_value;

  HWOffsetFix<1,0,UNSIGNED> id3631out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3630out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3365out_value;

  HWOffsetFix<1,0,UNSIGNED> id3634out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3633out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3364out_value;

  HWOffsetFix<1,0,UNSIGNED> id3637out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3636out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3363out_value;

  HWOffsetFix<1,0,UNSIGNED> id3640out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3639out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3362out_value;

  HWOffsetFix<1,0,UNSIGNED> id3643out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3642out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3361out_value;

  HWOffsetFix<1,0,UNSIGNED> id3646out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3645out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3360out_value;

  HWOffsetFix<1,0,UNSIGNED> id3649out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3648out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3359out_value;

  HWOffsetFix<1,0,UNSIGNED> id3652out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3651out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3358out_value;

  HWOffsetFix<1,0,UNSIGNED> id3655out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3654out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3357out_value;

  HWOffsetFix<1,0,UNSIGNED> id3658out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3657out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3356out_value;

  HWOffsetFix<1,0,UNSIGNED> id3661out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3660out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3355out_value;

  HWOffsetFix<1,0,UNSIGNED> id3664out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3663out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3354out_value;

  HWOffsetFix<1,0,UNSIGNED> id3667out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3666out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3448out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3353out_value;

  HWOffsetFix<1,0,UNSIGNED> id3670out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3669out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3352out_value;

  HWOffsetFix<1,0,UNSIGNED> id3672out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3671out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3351out_value;

  HWOffsetFix<1,0,UNSIGNED> id3674out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3673out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3350out_value;

  HWOffsetFix<1,0,UNSIGNED> id3676out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3675out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3349out_value;

  HWOffsetFix<1,0,UNSIGNED> id3678out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3677out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3348out_value;

  HWOffsetFix<1,0,UNSIGNED> id3680out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3679out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3347out_value;

  HWOffsetFix<1,0,UNSIGNED> id3682out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3681out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3346out_value;

  HWOffsetFix<1,0,UNSIGNED> id3684out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3683out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3345out_value;

  HWOffsetFix<1,0,UNSIGNED> id3686out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3685out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3344out_value;

  HWOffsetFix<1,0,UNSIGNED> id3688out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3687out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3343out_value;

  HWOffsetFix<1,0,UNSIGNED> id3690out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3689out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3342out_value;

  HWOffsetFix<1,0,UNSIGNED> id3692out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3691out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3341out_value;

  HWOffsetFix<1,0,UNSIGNED> id3694out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3693out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3340out_value;

  HWOffsetFix<1,0,UNSIGNED> id3696out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3695out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3339out_value;

  HWOffsetFix<1,0,UNSIGNED> id3698out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3697out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3338out_value;

  HWOffsetFix<1,0,UNSIGNED> id3700out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3699out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3703out_output[11];

  HWOffsetFix<32,0,UNSIGNED> id3337out_value;

  HWOffsetFix<32,0,UNSIGNED> id3702out_output[2];

  HWFloat<8,24> id15out_result[29];

  HWFloat<8,24> id3336out_value;

  HWFloat<8,24> id18out_result[12];

  HWFloat<8,24> id3335out_value;

  HWFloat<8,24> id20out_result[9];

  HWOffsetFix<32,0,UNSIGNED> id21out_o[8];

  HWOffsetFix<32,0,UNSIGNED> id3701out_output[54];

  HWOffsetFix<32,0,UNSIGNED> id3465out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3464out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3463out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3462out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3461out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3460out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3334out_value;

  HWOffsetFix<32,0,UNSIGNED> id3704out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3333out_value;

  HWOffsetFix<32,0,UNSIGNED> id3706out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3332out_value;

  HWOffsetFix<32,0,UNSIGNED> id3708out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3331out_value;

  HWOffsetFix<32,0,UNSIGNED> id3710out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3330out_value;

  HWOffsetFix<32,0,UNSIGNED> id3712out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3329out_value;

  HWOffsetFix<32,0,UNSIGNED> id3714out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3328out_value;

  HWOffsetFix<32,0,UNSIGNED> id3716out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3327out_value;

  HWOffsetFix<32,0,UNSIGNED> id3718out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3326out_value;

  HWOffsetFix<32,0,UNSIGNED> id3720out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3325out_value;

  HWOffsetFix<32,0,UNSIGNED> id3722out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3324out_value;

  HWOffsetFix<32,0,UNSIGNED> id3724out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3323out_value;

  HWOffsetFix<32,0,UNSIGNED> id3726out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3322out_value;

  HWOffsetFix<32,0,UNSIGNED> id3728out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3321out_value;

  HWOffsetFix<32,0,UNSIGNED> id3730out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3320out_value;

  HWOffsetFix<32,0,UNSIGNED> id3732out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3319out_value;

  HWOffsetFix<32,0,UNSIGNED> id3734out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3318out_value;

  HWOffsetFix<32,0,UNSIGNED> id3736out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3317out_value;

  HWOffsetFix<32,0,UNSIGNED> id3738out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3316out_value;

  HWOffsetFix<32,0,UNSIGNED> id3740out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3315out_value;

  HWOffsetFix<32,0,UNSIGNED> id3742out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3314out_value;

  HWOffsetFix<32,0,UNSIGNED> id3744out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3767out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id4479out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3313out_value;

  HWOffsetFix<32,0,UNSIGNED> id3746out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3312out_value;

  HWOffsetFix<32,0,UNSIGNED> id3748out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3311out_value;

  HWOffsetFix<32,0,UNSIGNED> id3750out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3310out_value;

  HWOffsetFix<32,0,UNSIGNED> id3752out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3309out_value;

  HWOffsetFix<32,0,UNSIGNED> id3754out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3308out_value;

  HWOffsetFix<32,0,UNSIGNED> id3756out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3307out_value;

  HWOffsetFix<32,0,UNSIGNED> id3758out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3306out_value;

  HWOffsetFix<32,0,UNSIGNED> id3760out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3305out_value;

  HWOffsetFix<32,0,UNSIGNED> id3762out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3304out_value;

  HWOffsetFix<32,0,UNSIGNED> id3764out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3303out_value;

  HWOffsetFix<32,0,UNSIGNED> id3766out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3302out_value;

  HWOffsetFix<32,0,UNSIGNED> id3768out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3301out_value;

  HWOffsetFix<32,0,UNSIGNED> id3770out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3300out_value;

  HWOffsetFix<32,0,UNSIGNED> id3772out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3299out_value;

  HWOffsetFix<32,0,UNSIGNED> id3774out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3298out_value;

  HWOffsetFix<32,0,UNSIGNED> id3776out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3297out_value;

  HWOffsetFix<32,0,UNSIGNED> id3778out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3296out_value;

  HWOffsetFix<32,0,UNSIGNED> id3780out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3295out_value;

  HWOffsetFix<32,0,UNSIGNED> id3782out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3294out_value;

  HWOffsetFix<32,0,UNSIGNED> id3784out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3293out_value;

  HWOffsetFix<32,0,UNSIGNED> id3786out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3292out_value;

  HWOffsetFix<32,0,UNSIGNED> id3788out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3291out_value;

  HWOffsetFix<32,0,UNSIGNED> id3790out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3290out_value;

  HWOffsetFix<32,0,UNSIGNED> id3792out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3289out_value;

  HWOffsetFix<32,0,UNSIGNED> id3794out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3288out_value;

  HWOffsetFix<32,0,UNSIGNED> id3796out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3287out_value;

  HWOffsetFix<32,0,UNSIGNED> id3798out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3286out_value;

  HWOffsetFix<32,0,UNSIGNED> id3800out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3285out_value;

  HWOffsetFix<32,0,UNSIGNED> id3802out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3284out_value;

  HWOffsetFix<32,0,UNSIGNED> id3804out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3283out_value;

  HWOffsetFix<32,0,UNSIGNED> id3806out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3809out_output[8];

  HWOffsetFix<32,0,UNSIGNED> id3282out_value;

  HWOffsetFix<32,0,UNSIGNED> id3808out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3281out_value;

  HWOffsetFix<32,0,UNSIGNED> id3810out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3280out_value;

  HWOffsetFix<32,0,UNSIGNED> id3812out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3279out_value;

  HWOffsetFix<32,0,UNSIGNED> id3814out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3278out_value;

  HWOffsetFix<32,0,UNSIGNED> id3816out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3277out_value;

  HWOffsetFix<32,0,UNSIGNED> id3818out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3276out_value;

  HWOffsetFix<32,0,UNSIGNED> id3820out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3275out_value;

  HWOffsetFix<32,0,UNSIGNED> id3822out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3274out_value;

  HWOffsetFix<32,0,UNSIGNED> id3824out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3273out_value;

  HWOffsetFix<32,0,UNSIGNED> id3826out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3272out_value;

  HWOffsetFix<1,0,UNSIGNED> id3829out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3828out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3271out_value;

  HWOffsetFix<1,0,UNSIGNED> id3832out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3831out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3270out_value;

  HWOffsetFix<1,0,UNSIGNED> id3835out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3834out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3269out_value;

  HWOffsetFix<1,0,UNSIGNED> id3838out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3837out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3268out_value;

  HWOffsetFix<1,0,UNSIGNED> id3841out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3840out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3267out_value;

  HWOffsetFix<1,0,UNSIGNED> id3844out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3843out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3266out_value;

  HWOffsetFix<1,0,UNSIGNED> id3847out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3846out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3265out_value;

  HWOffsetFix<1,0,UNSIGNED> id3850out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3849out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3264out_value;

  HWOffsetFix<1,0,UNSIGNED> id3853out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3852out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3263out_value;

  HWOffsetFix<1,0,UNSIGNED> id3856out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3855out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3262out_value;

  HWOffsetFix<1,0,UNSIGNED> id3859out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3858out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3261out_value;

  HWOffsetFix<1,0,UNSIGNED> id3862out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3861out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3260out_value;

  HWOffsetFix<1,0,UNSIGNED> id3865out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3864out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3259out_value;

  HWOffsetFix<1,0,UNSIGNED> id3868out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3867out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3258out_value;

  HWOffsetFix<1,0,UNSIGNED> id3871out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3870out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3257out_value;

  HWOffsetFix<1,0,UNSIGNED> id3874out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3873out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3256out_value;

  HWOffsetFix<1,0,UNSIGNED> id3877out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3876out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3255out_value;

  HWOffsetFix<1,0,UNSIGNED> id3880out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3879out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3254out_value;

  HWOffsetFix<1,0,UNSIGNED> id3883out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3882out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3253out_value;

  HWOffsetFix<1,0,UNSIGNED> id3886out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3885out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3252out_value;

  HWOffsetFix<1,0,UNSIGNED> id3889out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3888out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3251out_value;

  HWOffsetFix<1,0,UNSIGNED> id3892out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3891out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3250out_value;

  HWOffsetFix<1,0,UNSIGNED> id3895out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3894out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3249out_value;

  HWOffsetFix<1,0,UNSIGNED> id3898out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3897out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3248out_value;

  HWOffsetFix<1,0,UNSIGNED> id3901out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3900out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3247out_value;

  HWOffsetFix<1,0,UNSIGNED> id3904out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3903out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3246out_value;

  HWOffsetFix<1,0,UNSIGNED> id3907out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3906out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3245out_value;

  HWOffsetFix<1,0,UNSIGNED> id3910out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3909out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3244out_value;

  HWOffsetFix<1,0,UNSIGNED> id3913out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3912out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3243out_value;

  HWOffsetFix<1,0,UNSIGNED> id3916out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3915out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3242out_value;

  HWOffsetFix<1,0,UNSIGNED> id3919out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3918out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3241out_value;

  HWOffsetFix<1,0,UNSIGNED> id3922out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3921out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3240out_value;

  HWOffsetFix<1,0,UNSIGNED> id3925out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3924out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3239out_value;

  HWOffsetFix<1,0,UNSIGNED> id3928out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3927out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3238out_value;

  HWOffsetFix<1,0,UNSIGNED> id3931out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3930out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3237out_value;

  HWOffsetFix<1,0,UNSIGNED> id3934out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3933out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3236out_value;

  HWOffsetFix<1,0,UNSIGNED> id3937out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3936out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3235out_value;

  HWOffsetFix<1,0,UNSIGNED> id3940out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3939out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3234out_value;

  HWOffsetFix<1,0,UNSIGNED> id3943out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3942out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3233out_value;

  HWOffsetFix<1,0,UNSIGNED> id3946out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3945out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3232out_value;

  HWOffsetFix<1,0,UNSIGNED> id3949out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3948out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3231out_value;

  HWOffsetFix<1,0,UNSIGNED> id3952out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3951out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3230out_value;

  HWOffsetFix<1,0,UNSIGNED> id3955out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3954out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3229out_value;

  HWOffsetFix<1,0,UNSIGNED> id3958out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3957out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3228out_value;

  HWOffsetFix<1,0,UNSIGNED> id3961out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3960out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3227out_value;

  HWOffsetFix<1,0,UNSIGNED> id3964out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3963out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3226out_value;

  HWOffsetFix<1,0,UNSIGNED> id3967out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3966out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3225out_value;

  HWOffsetFix<1,0,UNSIGNED> id3970out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3969out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3224out_value;

  HWOffsetFix<1,0,UNSIGNED> id3973out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3972out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3223out_value;

  HWOffsetFix<1,0,UNSIGNED> id3976out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3975out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3222out_value;

  HWOffsetFix<1,0,UNSIGNED> id3979out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3978out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3221out_value;

  HWOffsetFix<1,0,UNSIGNED> id3982out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3981out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3220out_value;

  HWOffsetFix<1,0,UNSIGNED> id3985out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3984out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3219out_value;

  HWOffsetFix<1,0,UNSIGNED> id3988out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3987out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3218out_value;

  HWOffsetFix<1,0,UNSIGNED> id3991out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3990out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3217out_value;

  HWOffsetFix<1,0,UNSIGNED> id3994out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3993out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3216out_value;

  HWOffsetFix<1,0,UNSIGNED> id3997out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3996out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3215out_value;

  HWOffsetFix<1,0,UNSIGNED> id4000out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3999out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3214out_value;

  HWOffsetFix<1,0,UNSIGNED> id4003out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4002out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3213out_value;

  HWOffsetFix<1,0,UNSIGNED> id4006out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4005out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3212out_value;

  HWOffsetFix<1,0,UNSIGNED> id4009out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4008out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3211out_value;

  HWOffsetFix<1,0,UNSIGNED> id4012out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4011out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3210out_value;

  HWOffsetFix<1,0,UNSIGNED> id4015out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4014out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3209out_value;

  HWOffsetFix<1,0,UNSIGNED> id4018out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4017out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3208out_value;

  HWOffsetFix<1,0,UNSIGNED> id4021out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4020out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3207out_value;

  HWOffsetFix<1,0,UNSIGNED> id4024out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4023out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3206out_value;

  HWOffsetFix<1,0,UNSIGNED> id4027out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4026out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3205out_value;

  HWOffsetFix<1,0,UNSIGNED> id4030out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4029out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3204out_value;

  HWOffsetFix<1,0,UNSIGNED> id4033out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4032out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3203out_value;

  HWOffsetFix<1,0,UNSIGNED> id4036out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4035out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3202out_value;

  HWOffsetFix<1,0,UNSIGNED> id4039out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4038out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3201out_value;

  HWOffsetFix<1,0,UNSIGNED> id4042out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4041out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3200out_value;

  HWOffsetFix<1,0,UNSIGNED> id4045out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4044out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3199out_value;

  HWOffsetFix<1,0,UNSIGNED> id4048out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4047out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3198out_value;

  HWOffsetFix<1,0,UNSIGNED> id4051out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4050out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3197out_value;

  HWOffsetFix<1,0,UNSIGNED> id4054out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4053out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3196out_value;

  HWOffsetFix<1,0,UNSIGNED> id4057out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4056out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3195out_value;

  HWOffsetFix<1,0,UNSIGNED> id4060out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4059out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3194out_value;

  HWOffsetFix<1,0,UNSIGNED> id4063out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4062out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3193out_value;

  HWOffsetFix<1,0,UNSIGNED> id4066out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4065out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3192out_value;

  HWOffsetFix<1,0,UNSIGNED> id4069out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4068out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3191out_value;

  HWOffsetFix<1,0,UNSIGNED> id4072out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4071out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3190out_value;

  HWOffsetFix<1,0,UNSIGNED> id4075out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4074out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3189out_value;

  HWOffsetFix<1,0,UNSIGNED> id4078out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4077out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3188out_value;

  HWOffsetFix<1,0,UNSIGNED> id4081out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4080out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3187out_value;

  HWOffsetFix<1,0,UNSIGNED> id4084out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4083out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3186out_value;

  HWOffsetFix<1,0,UNSIGNED> id4087out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4086out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3185out_value;

  HWOffsetFix<1,0,UNSIGNED> id4090out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4089out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3184out_value;

  HWOffsetFix<1,0,UNSIGNED> id4093out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4092out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3183out_value;

  HWOffsetFix<1,0,UNSIGNED> id4096out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4095out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3182out_value;

  HWOffsetFix<1,0,UNSIGNED> id4099out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4098out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3181out_value;

  HWOffsetFix<1,0,UNSIGNED> id4102out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4101out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3180out_value;

  HWOffsetFix<1,0,UNSIGNED> id4105out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4104out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3179out_value;

  HWOffsetFix<1,0,UNSIGNED> id4108out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4107out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3178out_value;

  HWOffsetFix<1,0,UNSIGNED> id4111out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4110out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3177out_value;

  HWOffsetFix<1,0,UNSIGNED> id4114out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4113out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3176out_value;

  HWOffsetFix<1,0,UNSIGNED> id4117out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4116out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3175out_value;

  HWOffsetFix<1,0,UNSIGNED> id4120out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4119out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3174out_value;

  HWOffsetFix<1,0,UNSIGNED> id4123out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4122out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3173out_value;

  HWOffsetFix<1,0,UNSIGNED> id4126out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4125out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3172out_value;

  HWOffsetFix<1,0,UNSIGNED> id4129out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4128out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3171out_value;

  HWOffsetFix<1,0,UNSIGNED> id4132out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4131out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3170out_value;

  HWOffsetFix<1,0,UNSIGNED> id4135out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4134out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3169out_value;

  HWOffsetFix<1,0,UNSIGNED> id4138out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4137out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3168out_value;

  HWOffsetFix<1,0,UNSIGNED> id4141out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4140out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3167out_value;

  HWOffsetFix<1,0,UNSIGNED> id4144out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4143out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3166out_value;

  HWOffsetFix<1,0,UNSIGNED> id4147out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4146out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3165out_value;

  HWOffsetFix<1,0,UNSIGNED> id4150out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4149out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3164out_value;

  HWOffsetFix<1,0,UNSIGNED> id4153out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4152out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3163out_value;

  HWOffsetFix<1,0,UNSIGNED> id4156out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4155out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3162out_value;

  HWOffsetFix<1,0,UNSIGNED> id4159out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4158out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3161out_value;

  HWOffsetFix<1,0,UNSIGNED> id4162out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4161out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3160out_value;

  HWOffsetFix<1,0,UNSIGNED> id4165out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4164out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3159out_value;

  HWOffsetFix<1,0,UNSIGNED> id4168out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4167out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3158out_value;

  HWOffsetFix<1,0,UNSIGNED> id4171out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4170out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3157out_value;

  HWOffsetFix<1,0,UNSIGNED> id4174out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4173out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3156out_value;

  HWOffsetFix<1,0,UNSIGNED> id4177out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4176out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3155out_value;

  HWOffsetFix<1,0,UNSIGNED> id4180out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4179out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3154out_value;

  HWOffsetFix<1,0,UNSIGNED> id4183out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4182out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3153out_value;

  HWOffsetFix<1,0,UNSIGNED> id4186out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4185out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3152out_value;

  HWOffsetFix<1,0,UNSIGNED> id4189out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4188out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3151out_value;

  HWOffsetFix<1,0,UNSIGNED> id4192out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4191out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3150out_value;

  HWOffsetFix<1,0,UNSIGNED> id4195out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4194out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3149out_value;

  HWOffsetFix<1,0,UNSIGNED> id4197out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4196out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3148out_value;

  HWOffsetFix<1,0,UNSIGNED> id4200out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4198out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3147out_value;

  HWOffsetFix<1,0,UNSIGNED> id4203out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4201out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3146out_value;

  HWOffsetFix<1,0,UNSIGNED> id4206out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4204out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3145out_value;

  HWOffsetFix<1,0,UNSIGNED> id4209out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4207out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3144out_value;

  HWOffsetFix<1,0,UNSIGNED> id4212out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4210out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3143out_value;

  HWOffsetFix<1,0,UNSIGNED> id4215out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4213out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3142out_value;

  HWOffsetFix<1,0,UNSIGNED> id4218out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4216out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3141out_value;

  HWOffsetFix<1,0,UNSIGNED> id4221out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4219out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3140out_value;

  HWOffsetFix<1,0,UNSIGNED> id4224out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4222out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3139out_value;

  HWOffsetFix<1,0,UNSIGNED> id4227out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4225out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3138out_value;

  HWOffsetFix<1,0,UNSIGNED> id4230out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4228out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3137out_value;

  HWOffsetFix<1,0,UNSIGNED> id4233out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4231out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3136out_value;

  HWOffsetFix<1,0,UNSIGNED> id4236out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4234out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3135out_value;

  HWOffsetFix<1,0,UNSIGNED> id4239out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4237out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id2509out_value;

  HWOffsetFix<1,0,UNSIGNED> id3134out_value;

  HWOffsetFix<49,0,UNSIGNED> id2506out_value;

  HWOffsetFix<48,0,UNSIGNED> id2507out_count;
  HWOffsetFix<1,0,UNSIGNED> id2507out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id2507st_count;

  HWOffsetFix<1,0,UNSIGNED> id3133out_value;

  HWOffsetFix<49,0,UNSIGNED> id2512out_value;

  HWOffsetFix<48,0,UNSIGNED> id2513out_count;
  HWOffsetFix<1,0,UNSIGNED> id2513out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id2513st_count;

  HWOffsetFix<48,0,UNSIGNED> id2515out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id3132out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<65,0,UNSIGNED> c_hw_fix_65_0_uns_bits;
  const HWOffsetFix<65,0,UNSIGNED> c_hw_fix_65_0_uns_bits_1;
  const HWOffsetFix<65,0,UNSIGNED> c_hw_fix_65_0_uns_bits_2;
  const HWOffsetFix<64,0,UNSIGNED> c_hw_fix_64_0_uns_bits;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_1;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits_1;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits_2;
  const HWFloat<8,24> c_hw_flt_8_24_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_3;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_4;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_5;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_6;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_7;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_8;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_9;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_10;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_11;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_12;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_13;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_14;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_15;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_16;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_17;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_18;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_19;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_20;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_21;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_22;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_23;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_24;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_25;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_26;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_27;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_28;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_29;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_30;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_31;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_32;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_33;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_34;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_35;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_36;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_37;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_38;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_39;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_40;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_41;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_42;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_43;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_44;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_45;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_46;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_47;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_48;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_49;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_50;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_51;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_52;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_53;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_54;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_55;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_56;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_57;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_58;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_59;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_60;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_61;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_62;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_63;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_64;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_65;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_66;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_67;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_68;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_69;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_70;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_71;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_72;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_73;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_74;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_75;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_76;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_77;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_78;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_79;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_80;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_81;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_82;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_83;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_84;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_85;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_86;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_87;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_88;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_89;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_90;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_91;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_92;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_93;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_94;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_95;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_96;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_97;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_98;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_99;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_100;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_101;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_102;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_103;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_104;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_105;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_106;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_107;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_108;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_109;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_110;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_111;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_112;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_113;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_114;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_115;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_116;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_117;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_118;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_119;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_120;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_121;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_122;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_123;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_124;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_125;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_126;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_127;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_128;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_129;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_130;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_131;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_132;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_133;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_134;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_135;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_136;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_137;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_138;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_139;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_140;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_141;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_142;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_143;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_144;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_145;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_146;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_147;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_148;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_149;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_150;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_151;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_152;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_153;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_154;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_155;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_156;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_157;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_158;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_159;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_160;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_161;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_162;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_163;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_164;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_165;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_166;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_167;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_168;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_169;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_170;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_171;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_172;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_173;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_174;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_175;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_176;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_177;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_178;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_179;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_180;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_181;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_182;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_183;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_184;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_185;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_186;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_187;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_188;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_189;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_190;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_191;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_192;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_193;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_194;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_195;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_196;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_197;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_198;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_199;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_200;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_201;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* PROCESSINGKERNEL_H_ */
