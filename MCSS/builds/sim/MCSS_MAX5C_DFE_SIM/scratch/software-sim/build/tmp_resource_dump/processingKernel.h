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
  t_port_number m_internal_watch_tracklength_output;
  t_port_number m_internal_watch_lind_output;
  t_port_number m_internal_watch_longi_output;
  t_port_number m_output;
  HWOffsetFix<1,0,UNSIGNED> id2567out_value;

  HWOffsetFix<1,0,UNSIGNED> id4out_io_z_force_disabled;

  HWRawBits<224> id6out_data;

  HWOffsetFix<1,0,UNSIGNED> id6st_read_next_cycle;
  HWRawBits<224> id6st_last_read_value;

  HWFloat<8,24> id3539out_output[48];

  HWFloat<8,24> id4538out_output[67];

  HWFloat<8,24> id22out_result[29];

  HWFloat<8,24> id3527out_output[34];

  HWFloat<8,24> id3507out_value;

  HWFloat<8,24> id24out_result[12];

  HWFloat<8,24> id3506out_value;

  HWFloat<8,24> id26out_result[9];

  HWOffsetFix<7,0,UNSIGNED> id3505out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id31out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3528out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3504out_value;

  HWOffsetFix<1,0,UNSIGNED> id2573out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id52out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3535out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id3533out_output[10];

  HWFloat<8,24> id3530out_output[8];

  HWFloat<8,24> id4540out_output[2];

  HWFloat<8,24> id3503out_value;

  HWOffsetFix<1,0,UNSIGNED> id46out_result[3];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3502out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id34out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3501out_value;

  HWOffsetFix<1,0,UNSIGNED> id2575out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3531out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id35out_value;

  HWRawBits<32> id39out_dataout[5];

  HWOffsetFix<32,0,UNSIGNED> id41out_result[2];

  HWRawBits<32> id43out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id53out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id54out_result[2];

  HWOffsetFix<2,0,UNSIGNED> id57out_value;

  HWOffsetFix<2,0,UNSIGNED> id56out_value;

  HWOffsetFix<2,0,UNSIGNED> id59out_value;

  HWOffsetFix<1,0,UNSIGNED> id3534out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id3536out_output[9];

  HWFloat<8,24> id2563out_value;

  HWFloat<8,24> id62out_value;

  HWFloat<8,24> id3537out_output[12];

  HWFloat<8,24> id3500out_value;

  HWFloat<8,24> id66out_result[12];

  HWFloat<8,24> id67out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id69out_o[8];

  HWOffsetFix<32,0,UNSIGNED> id3513out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3512out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3511out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3510out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3509out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3508out_output[2];

  HWFloat<8,24> id4539out_output[53];

  HWOffsetFix<1,0,UNSIGNED> id3499out_value;

  HWOffsetFix<65,0,UNSIGNED> id2out_value;

  HWOffsetFix<64,0,UNSIGNED> id3out_count;
  HWOffsetFix<1,0,UNSIGNED> id3out_wrap;

  HWOffsetFix<65,0,UNSIGNED> id3st_count;

  HWOffsetFix<64,0,UNSIGNED> id3498out_value;

  HWOffsetFix<64,0,UNSIGNED> id1938out_result[2];

  HWOffsetFix<64,0,UNSIGNED> id0out_numHists;

  HWOffsetFix<1,0,UNSIGNED> id2576out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1940out_io_output_force_disabled;

  HWRawBits<32> id2564out_value;

  HWRawBits<32> id2565out_value;

  HWOffsetFix<1,0,UNSIGNED> id121out_value;

  HWOffsetFix<1,0,UNSIGNED> id122out_output;

  long id122st_count;
  HWOffsetFix<1,0,UNSIGNED> id122st_value;

  HWOffsetFix<1,0,UNSIGNED> id3522out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3521out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3520out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3966out_output[7];

  HWOffsetFix<1,0,UNSIGNED> id4542out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3497out_value;

  HWOffsetFix<32,0,UNSIGNED> id3550out_output[2];

  HWFloat<8,24> id70out_result[9];

  HWFloat<8,24> id71out_result[9];

  HWFloat<8,24> id72out_result[12];

  HWFloat<8,24> id73out_result[29];

  HWFloat<8,24> id75out_result[29];

  HWFloat<8,24> id3496out_value;

  HWFloat<8,24> id77out_result[9];

  HWOffsetFix<7,0,UNSIGNED> id3495out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id82out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3540out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3494out_value;

  HWOffsetFix<1,0,UNSIGNED> id2579out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id103out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3547out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id3545out_output[10];

  HWFloat<8,24> id3542out_output[8];

  HWFloat<8,24> id4543out_output[2];

  HWFloat<8,24> id3493out_value;

  HWOffsetFix<1,0,UNSIGNED> id97out_result[3];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3492out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id85out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id3491out_value;

  HWOffsetFix<1,0,UNSIGNED> id2581out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id3543out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id86out_value;

  HWRawBits<32> id90out_dataout[5];

  HWOffsetFix<32,0,UNSIGNED> id92out_result[2];

  HWRawBits<32> id94out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id104out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id105out_result[2];

  HWOffsetFix<2,0,UNSIGNED> id108out_value;

  HWOffsetFix<2,0,UNSIGNED> id107out_value;

  HWOffsetFix<2,0,UNSIGNED> id110out_value;

  HWOffsetFix<1,0,UNSIGNED> id3546out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id3548out_output[9];

  HWFloat<8,24> id2566out_value;

  HWFloat<8,24> id113out_value;

  HWFloat<8,24> id3549out_output[12];

  HWFloat<8,24> id3490out_value;

  HWFloat<8,24> id117out_result[12];

  HWFloat<8,24> id118out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id120out_o[8];

  HWOffsetFix<32,0,UNSIGNED> id3525out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3524out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3523out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3489out_value;

  HWOffsetFix<32,0,UNSIGNED> id3552out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3488out_value;

  HWOffsetFix<32,0,UNSIGNED> id3554out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3487out_value;

  HWOffsetFix<32,0,UNSIGNED> id3556out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3486out_value;

  HWOffsetFix<32,0,UNSIGNED> id3558out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3485out_value;

  HWOffsetFix<32,0,UNSIGNED> id3560out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3484out_value;

  HWOffsetFix<32,0,UNSIGNED> id3562out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3483out_value;

  HWOffsetFix<32,0,UNSIGNED> id3564out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3519out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id4035out_output[6];

  HWOffsetFix<1,0,UNSIGNED> id4544out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3482out_value;

  HWOffsetFix<32,0,UNSIGNED> id3566out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3481out_value;

  HWOffsetFix<32,0,UNSIGNED> id3568out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3480out_value;

  HWOffsetFix<32,0,UNSIGNED> id3570out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3479out_value;

  HWOffsetFix<32,0,UNSIGNED> id3572out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3478out_value;

  HWOffsetFix<32,0,UNSIGNED> id3574out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3477out_value;

  HWOffsetFix<32,0,UNSIGNED> id3576out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3476out_value;

  HWOffsetFix<32,0,UNSIGNED> id3578out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3475out_value;

  HWOffsetFix<32,0,UNSIGNED> id3580out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3474out_value;

  HWOffsetFix<32,0,UNSIGNED> id3582out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3473out_value;

  HWOffsetFix<32,0,UNSIGNED> id3584out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3472out_value;

  HWOffsetFix<32,0,UNSIGNED> id3586out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3471out_value;

  HWOffsetFix<32,0,UNSIGNED> id3588out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3470out_value;

  HWOffsetFix<32,0,UNSIGNED> id3590out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3469out_value;

  HWOffsetFix<32,0,UNSIGNED> id3592out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3468out_value;

  HWOffsetFix<32,0,UNSIGNED> id3594out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3518out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3615out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id4545out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3467out_value;

  HWOffsetFix<32,0,UNSIGNED> id3596out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3466out_value;

  HWOffsetFix<32,0,UNSIGNED> id3598out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3465out_value;

  HWOffsetFix<32,0,UNSIGNED> id3600out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3464out_value;

  HWOffsetFix<32,0,UNSIGNED> id3602out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3463out_value;

  HWOffsetFix<32,0,UNSIGNED> id3604out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3462out_value;

  HWOffsetFix<32,0,UNSIGNED> id3606out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3461out_value;

  HWOffsetFix<32,0,UNSIGNED> id3608out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3460out_value;

  HWOffsetFix<32,0,UNSIGNED> id3610out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3459out_value;

  HWOffsetFix<32,0,UNSIGNED> id3612out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3458out_value;

  HWOffsetFix<32,0,UNSIGNED> id3614out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3457out_value;

  HWOffsetFix<32,0,UNSIGNED> id3616out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3456out_value;

  HWOffsetFix<32,0,UNSIGNED> id3618out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3455out_value;

  HWOffsetFix<32,0,UNSIGNED> id3620out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3454out_value;

  HWOffsetFix<32,0,UNSIGNED> id3622out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3453out_value;

  HWOffsetFix<32,0,UNSIGNED> id3624out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3452out_value;

  HWOffsetFix<32,0,UNSIGNED> id3626out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3517out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3629out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id3451out_value;

  HWOffsetFix<32,0,UNSIGNED> id3628out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3450out_value;

  HWOffsetFix<32,0,UNSIGNED> id3630out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3449out_value;

  HWOffsetFix<32,0,UNSIGNED> id3632out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3448out_value;

  HWOffsetFix<32,0,UNSIGNED> id3634out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3447out_value;

  HWOffsetFix<32,0,UNSIGNED> id3636out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3446out_value;

  HWOffsetFix<32,0,UNSIGNED> id3638out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3445out_value;

  HWOffsetFix<32,0,UNSIGNED> id3640out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3444out_value;

  HWOffsetFix<32,0,UNSIGNED> id3642out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3443out_value;

  HWOffsetFix<32,0,UNSIGNED> id3644out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3442out_value;

  HWOffsetFix<32,0,UNSIGNED> id3646out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3441out_value;

  HWOffsetFix<32,0,UNSIGNED> id3648out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3440out_value;

  HWOffsetFix<32,0,UNSIGNED> id3650out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3439out_value;

  HWOffsetFix<32,0,UNSIGNED> id3652out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3438out_value;

  HWOffsetFix<32,0,UNSIGNED> id3654out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3437out_value;

  HWOffsetFix<32,0,UNSIGNED> id3656out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3516out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3659out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3436out_value;

  HWOffsetFix<32,0,UNSIGNED> id3658out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3435out_value;

  HWOffsetFix<32,0,UNSIGNED> id3660out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3434out_value;

  HWOffsetFix<32,0,UNSIGNED> id3662out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3433out_value;

  HWOffsetFix<32,0,UNSIGNED> id3664out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3432out_value;

  HWOffsetFix<32,0,UNSIGNED> id3666out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3431out_value;

  HWOffsetFix<32,0,UNSIGNED> id3668out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3430out_value;

  HWOffsetFix<32,0,UNSIGNED> id3670out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3429out_value;

  HWOffsetFix<32,0,UNSIGNED> id3672out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3428out_value;

  HWOffsetFix<32,0,UNSIGNED> id3674out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3427out_value;

  HWOffsetFix<1,0,UNSIGNED> id3677out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3676out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3426out_value;

  HWOffsetFix<1,0,UNSIGNED> id3680out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3679out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3425out_value;

  HWOffsetFix<1,0,UNSIGNED> id3683out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3682out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3424out_value;

  HWOffsetFix<1,0,UNSIGNED> id3686out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3685out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3423out_value;

  HWOffsetFix<1,0,UNSIGNED> id3689out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3688out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3422out_value;

  HWOffsetFix<1,0,UNSIGNED> id3692out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3691out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3421out_value;

  HWOffsetFix<1,0,UNSIGNED> id3695out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3694out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3515out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3699out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3420out_value;

  HWOffsetFix<1,0,UNSIGNED> id3698out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3697out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3419out_value;

  HWOffsetFix<1,0,UNSIGNED> id3701out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3700out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3418out_value;

  HWOffsetFix<1,0,UNSIGNED> id3704out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3703out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3417out_value;

  HWOffsetFix<1,0,UNSIGNED> id3707out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3706out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3416out_value;

  HWOffsetFix<1,0,UNSIGNED> id3710out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3709out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3415out_value;

  HWOffsetFix<1,0,UNSIGNED> id3713out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3712out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3414out_value;

  HWOffsetFix<1,0,UNSIGNED> id3716out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3715out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3413out_value;

  HWOffsetFix<1,0,UNSIGNED> id3719out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3718out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3412out_value;

  HWOffsetFix<1,0,UNSIGNED> id3722out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3721out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3411out_value;

  HWOffsetFix<1,0,UNSIGNED> id3725out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3724out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3410out_value;

  HWOffsetFix<1,0,UNSIGNED> id3728out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3727out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3409out_value;

  HWOffsetFix<1,0,UNSIGNED> id3731out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3730out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3408out_value;

  HWOffsetFix<1,0,UNSIGNED> id3734out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3733out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3407out_value;

  HWOffsetFix<1,0,UNSIGNED> id3737out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3736out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3406out_value;

  HWOffsetFix<1,0,UNSIGNED> id3740out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3739out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3514out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3405out_value;

  HWOffsetFix<1,0,UNSIGNED> id3743out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3742out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3404out_value;

  HWOffsetFix<1,0,UNSIGNED> id3745out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3744out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3403out_value;

  HWOffsetFix<1,0,UNSIGNED> id3747out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3746out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3402out_value;

  HWOffsetFix<1,0,UNSIGNED> id3749out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3748out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3401out_value;

  HWOffsetFix<1,0,UNSIGNED> id3751out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3750out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3400out_value;

  HWOffsetFix<1,0,UNSIGNED> id3753out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3752out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3399out_value;

  HWOffsetFix<1,0,UNSIGNED> id3755out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3754out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3398out_value;

  HWOffsetFix<1,0,UNSIGNED> id3757out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3756out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3397out_value;

  HWOffsetFix<1,0,UNSIGNED> id3759out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3758out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3396out_value;

  HWOffsetFix<1,0,UNSIGNED> id3761out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3760out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3395out_value;

  HWOffsetFix<1,0,UNSIGNED> id3763out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3762out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3394out_value;

  HWOffsetFix<1,0,UNSIGNED> id3765out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3764out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3393out_value;

  HWOffsetFix<1,0,UNSIGNED> id3767out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3766out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3392out_value;

  HWOffsetFix<1,0,UNSIGNED> id3769out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3768out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3391out_value;

  HWOffsetFix<1,0,UNSIGNED> id3771out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3770out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3390out_value;

  HWOffsetFix<1,0,UNSIGNED> id3773out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3772out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3775out_output[11];

  HWOffsetFix<32,0,UNSIGNED> id3389out_value;

  HWOffsetFix<32,0,UNSIGNED> id3774out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3388out_value;

  HWOffsetFix<32,0,UNSIGNED> id3776out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3387out_value;

  HWOffsetFix<32,0,UNSIGNED> id3778out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3386out_value;

  HWOffsetFix<32,0,UNSIGNED> id3780out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3385out_value;

  HWOffsetFix<32,0,UNSIGNED> id3782out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3384out_value;

  HWOffsetFix<32,0,UNSIGNED> id3784out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3383out_value;

  HWOffsetFix<32,0,UNSIGNED> id3786out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3382out_value;

  HWOffsetFix<32,0,UNSIGNED> id3788out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3381out_value;

  HWOffsetFix<32,0,UNSIGNED> id3790out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3380out_value;

  HWOffsetFix<32,0,UNSIGNED> id3792out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3379out_value;

  HWOffsetFix<32,0,UNSIGNED> id3794out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3378out_value;

  HWOffsetFix<32,0,UNSIGNED> id3796out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3377out_value;

  HWOffsetFix<32,0,UNSIGNED> id3798out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3376out_value;

  HWOffsetFix<32,0,UNSIGNED> id3800out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3375out_value;

  HWOffsetFix<32,0,UNSIGNED> id3802out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3374out_value;

  HWOffsetFix<32,0,UNSIGNED> id3804out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3373out_value;

  HWOffsetFix<32,0,UNSIGNED> id3806out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3372out_value;

  HWOffsetFix<32,0,UNSIGNED> id3808out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3371out_value;

  HWOffsetFix<32,0,UNSIGNED> id3810out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3370out_value;

  HWOffsetFix<32,0,UNSIGNED> id3812out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3369out_value;

  HWOffsetFix<32,0,UNSIGNED> id3814out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3368out_value;

  HWOffsetFix<32,0,UNSIGNED> id3816out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3837out_output[9];

  HWOffsetFix<1,0,UNSIGNED> id4541out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3367out_value;

  HWOffsetFix<32,0,UNSIGNED> id3818out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3366out_value;

  HWOffsetFix<32,0,UNSIGNED> id3820out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3365out_value;

  HWOffsetFix<32,0,UNSIGNED> id3822out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3364out_value;

  HWOffsetFix<32,0,UNSIGNED> id3824out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3363out_value;

  HWOffsetFix<32,0,UNSIGNED> id3826out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3362out_value;

  HWOffsetFix<32,0,UNSIGNED> id3828out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3361out_value;

  HWOffsetFix<32,0,UNSIGNED> id3830out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3360out_value;

  HWOffsetFix<32,0,UNSIGNED> id3832out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3359out_value;

  HWOffsetFix<32,0,UNSIGNED> id3834out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3358out_value;

  HWOffsetFix<32,0,UNSIGNED> id3836out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3357out_value;

  HWOffsetFix<32,0,UNSIGNED> id3838out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3356out_value;

  HWOffsetFix<32,0,UNSIGNED> id3840out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3355out_value;

  HWOffsetFix<32,0,UNSIGNED> id3842out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3354out_value;

  HWOffsetFix<32,0,UNSIGNED> id3844out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3353out_value;

  HWOffsetFix<32,0,UNSIGNED> id3846out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3352out_value;

  HWOffsetFix<32,0,UNSIGNED> id3848out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3351out_value;

  HWOffsetFix<32,0,UNSIGNED> id3850out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3350out_value;

  HWOffsetFix<32,0,UNSIGNED> id3852out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3349out_value;

  HWOffsetFix<32,0,UNSIGNED> id3854out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3348out_value;

  HWOffsetFix<32,0,UNSIGNED> id3856out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3347out_value;

  HWOffsetFix<32,0,UNSIGNED> id3858out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3346out_value;

  HWOffsetFix<32,0,UNSIGNED> id3860out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3345out_value;

  HWOffsetFix<32,0,UNSIGNED> id3862out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3344out_value;

  HWOffsetFix<32,0,UNSIGNED> id3864out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3343out_value;

  HWOffsetFix<32,0,UNSIGNED> id3866out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3342out_value;

  HWOffsetFix<32,0,UNSIGNED> id3868out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3341out_value;

  HWOffsetFix<32,0,UNSIGNED> id3870out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3340out_value;

  HWOffsetFix<32,0,UNSIGNED> id3872out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3339out_value;

  HWOffsetFix<32,0,UNSIGNED> id3874out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3338out_value;

  HWOffsetFix<32,0,UNSIGNED> id3876out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3337out_value;

  HWOffsetFix<32,0,UNSIGNED> id3878out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id3881out_output[8];

  HWOffsetFix<32,0,UNSIGNED> id3336out_value;

  HWOffsetFix<32,0,UNSIGNED> id3880out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3335out_value;

  HWOffsetFix<32,0,UNSIGNED> id3882out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3334out_value;

  HWOffsetFix<32,0,UNSIGNED> id3884out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3333out_value;

  HWOffsetFix<32,0,UNSIGNED> id3886out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3332out_value;

  HWOffsetFix<32,0,UNSIGNED> id3888out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3331out_value;

  HWOffsetFix<32,0,UNSIGNED> id3890out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3330out_value;

  HWOffsetFix<32,0,UNSIGNED> id3892out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3329out_value;

  HWOffsetFix<32,0,UNSIGNED> id3894out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3328out_value;

  HWOffsetFix<32,0,UNSIGNED> id3896out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3327out_value;

  HWOffsetFix<1,0,UNSIGNED> id3899out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3898out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3326out_value;

  HWOffsetFix<1,0,UNSIGNED> id3902out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3901out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3325out_value;

  HWOffsetFix<1,0,UNSIGNED> id3905out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3904out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3324out_value;

  HWOffsetFix<1,0,UNSIGNED> id3908out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3907out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3323out_value;

  HWOffsetFix<1,0,UNSIGNED> id3911out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3910out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3322out_value;

  HWOffsetFix<1,0,UNSIGNED> id3914out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3913out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3321out_value;

  HWOffsetFix<1,0,UNSIGNED> id3917out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3916out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3320out_value;

  HWOffsetFix<1,0,UNSIGNED> id3920out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3919out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3319out_value;

  HWOffsetFix<1,0,UNSIGNED> id3923out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3922out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3318out_value;

  HWOffsetFix<1,0,UNSIGNED> id3926out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3925out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3317out_value;

  HWOffsetFix<1,0,UNSIGNED> id3929out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3928out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3316out_value;

  HWOffsetFix<1,0,UNSIGNED> id3932out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3931out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3315out_value;

  HWOffsetFix<1,0,UNSIGNED> id3935out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3934out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3314out_value;

  HWOffsetFix<1,0,UNSIGNED> id3938out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3937out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3313out_value;

  HWOffsetFix<1,0,UNSIGNED> id3941out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3940out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3312out_value;

  HWOffsetFix<1,0,UNSIGNED> id3944out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3943out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3311out_value;

  HWOffsetFix<1,0,UNSIGNED> id3947out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3946out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3310out_value;

  HWOffsetFix<1,0,UNSIGNED> id3950out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3949out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3309out_value;

  HWOffsetFix<1,0,UNSIGNED> id3953out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3952out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3308out_value;

  HWOffsetFix<1,0,UNSIGNED> id3956out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3955out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3307out_value;

  HWOffsetFix<1,0,UNSIGNED> id3959out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3958out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3306out_value;

  HWOffsetFix<1,0,UNSIGNED> id3962out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3961out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3305out_value;

  HWOffsetFix<1,0,UNSIGNED> id3965out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3964out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3304out_value;

  HWOffsetFix<1,0,UNSIGNED> id3968out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3967out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3303out_value;

  HWOffsetFix<1,0,UNSIGNED> id3971out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3970out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3302out_value;

  HWOffsetFix<1,0,UNSIGNED> id3974out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3973out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3301out_value;

  HWOffsetFix<1,0,UNSIGNED> id3977out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3976out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3300out_value;

  HWOffsetFix<1,0,UNSIGNED> id3980out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3979out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3299out_value;

  HWOffsetFix<1,0,UNSIGNED> id3983out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3982out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3298out_value;

  HWOffsetFix<1,0,UNSIGNED> id3986out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3985out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3297out_value;

  HWOffsetFix<1,0,UNSIGNED> id3989out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3988out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3296out_value;

  HWOffsetFix<1,0,UNSIGNED> id3992out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3991out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3295out_value;

  HWOffsetFix<1,0,UNSIGNED> id3995out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3994out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3294out_value;

  HWOffsetFix<1,0,UNSIGNED> id3998out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id3997out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3293out_value;

  HWOffsetFix<1,0,UNSIGNED> id4001out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4000out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3292out_value;

  HWOffsetFix<1,0,UNSIGNED> id4004out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4003out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3291out_value;

  HWOffsetFix<1,0,UNSIGNED> id4007out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4006out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3290out_value;

  HWOffsetFix<1,0,UNSIGNED> id4010out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4009out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3289out_value;

  HWOffsetFix<1,0,UNSIGNED> id4013out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4012out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3288out_value;

  HWOffsetFix<1,0,UNSIGNED> id4016out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4015out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3287out_value;

  HWOffsetFix<1,0,UNSIGNED> id4019out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4018out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3286out_value;

  HWOffsetFix<1,0,UNSIGNED> id4022out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4021out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3285out_value;

  HWOffsetFix<1,0,UNSIGNED> id4025out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4024out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3284out_value;

  HWOffsetFix<1,0,UNSIGNED> id4028out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4027out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3283out_value;

  HWOffsetFix<1,0,UNSIGNED> id4031out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4030out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3282out_value;

  HWOffsetFix<1,0,UNSIGNED> id4034out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4033out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3281out_value;

  HWOffsetFix<1,0,UNSIGNED> id4037out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4036out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3280out_value;

  HWOffsetFix<1,0,UNSIGNED> id4040out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4039out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3279out_value;

  HWOffsetFix<1,0,UNSIGNED> id4043out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4042out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3278out_value;

  HWOffsetFix<1,0,UNSIGNED> id4046out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4045out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3277out_value;

  HWOffsetFix<1,0,UNSIGNED> id4049out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4048out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3276out_value;

  HWOffsetFix<1,0,UNSIGNED> id4052out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4051out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3275out_value;

  HWOffsetFix<1,0,UNSIGNED> id4055out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4054out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3274out_value;

  HWOffsetFix<1,0,UNSIGNED> id4058out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4057out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3273out_value;

  HWOffsetFix<1,0,UNSIGNED> id4061out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4060out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3272out_value;

  HWOffsetFix<1,0,UNSIGNED> id4064out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4063out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3271out_value;

  HWOffsetFix<1,0,UNSIGNED> id4067out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4066out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3270out_value;

  HWOffsetFix<1,0,UNSIGNED> id4070out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4069out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3269out_value;

  HWOffsetFix<1,0,UNSIGNED> id4073out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4072out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3268out_value;

  HWOffsetFix<1,0,UNSIGNED> id4076out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4075out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3267out_value;

  HWOffsetFix<1,0,UNSIGNED> id4079out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4078out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3266out_value;

  HWOffsetFix<1,0,UNSIGNED> id4082out_output[3];

  HWOffsetFix<32,0,UNSIGNED> id4081out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3265out_value;

  HWOffsetFix<1,0,UNSIGNED> id4085out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4084out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3264out_value;

  HWOffsetFix<1,0,UNSIGNED> id4088out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4087out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3263out_value;

  HWOffsetFix<1,0,UNSIGNED> id4091out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4090out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3262out_value;

  HWOffsetFix<1,0,UNSIGNED> id4094out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4093out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3261out_value;

  HWOffsetFix<1,0,UNSIGNED> id4097out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4096out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3260out_value;

  HWOffsetFix<1,0,UNSIGNED> id4100out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4099out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3259out_value;

  HWOffsetFix<1,0,UNSIGNED> id4103out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4102out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3258out_value;

  HWOffsetFix<1,0,UNSIGNED> id4106out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4105out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3257out_value;

  HWOffsetFix<1,0,UNSIGNED> id4109out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4108out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3256out_value;

  HWOffsetFix<1,0,UNSIGNED> id4112out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4111out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3255out_value;

  HWOffsetFix<1,0,UNSIGNED> id4115out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4114out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3254out_value;

  HWOffsetFix<1,0,UNSIGNED> id4118out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4117out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3253out_value;

  HWOffsetFix<1,0,UNSIGNED> id4121out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4120out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3252out_value;

  HWOffsetFix<1,0,UNSIGNED> id4124out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4123out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3251out_value;

  HWOffsetFix<1,0,UNSIGNED> id4127out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4126out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3250out_value;

  HWOffsetFix<1,0,UNSIGNED> id4130out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4129out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3249out_value;

  HWOffsetFix<1,0,UNSIGNED> id4133out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4132out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3248out_value;

  HWOffsetFix<1,0,UNSIGNED> id4136out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4135out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3247out_value;

  HWOffsetFix<1,0,UNSIGNED> id4139out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4138out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3246out_value;

  HWOffsetFix<1,0,UNSIGNED> id4142out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4141out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3245out_value;

  HWOffsetFix<1,0,UNSIGNED> id4145out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4144out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3244out_value;

  HWOffsetFix<1,0,UNSIGNED> id4148out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4147out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3243out_value;

  HWOffsetFix<1,0,UNSIGNED> id4151out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4150out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3242out_value;

  HWOffsetFix<1,0,UNSIGNED> id4154out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4153out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3241out_value;

  HWOffsetFix<1,0,UNSIGNED> id4157out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4156out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3240out_value;

  HWOffsetFix<1,0,UNSIGNED> id4160out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4159out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3239out_value;

  HWOffsetFix<1,0,UNSIGNED> id4163out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4162out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3238out_value;

  HWOffsetFix<1,0,UNSIGNED> id4166out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4165out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3237out_value;

  HWOffsetFix<1,0,UNSIGNED> id4169out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4168out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3236out_value;

  HWOffsetFix<1,0,UNSIGNED> id4172out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4171out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3235out_value;

  HWOffsetFix<1,0,UNSIGNED> id4175out_output[4];

  HWOffsetFix<32,0,UNSIGNED> id4174out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3234out_value;

  HWOffsetFix<1,0,UNSIGNED> id4178out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4177out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3233out_value;

  HWOffsetFix<1,0,UNSIGNED> id4181out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4180out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3232out_value;

  HWOffsetFix<1,0,UNSIGNED> id4184out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4183out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3231out_value;

  HWOffsetFix<1,0,UNSIGNED> id4187out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4186out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3230out_value;

  HWOffsetFix<1,0,UNSIGNED> id4190out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4189out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3229out_value;

  HWOffsetFix<1,0,UNSIGNED> id4193out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4192out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3228out_value;

  HWOffsetFix<1,0,UNSIGNED> id4196out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4195out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3227out_value;

  HWOffsetFix<1,0,UNSIGNED> id4199out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4198out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3226out_value;

  HWOffsetFix<1,0,UNSIGNED> id4202out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4201out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3225out_value;

  HWOffsetFix<1,0,UNSIGNED> id4205out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4204out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3224out_value;

  HWOffsetFix<1,0,UNSIGNED> id4208out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4207out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3223out_value;

  HWOffsetFix<1,0,UNSIGNED> id4211out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4210out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3222out_value;

  HWOffsetFix<1,0,UNSIGNED> id4214out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4213out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3221out_value;

  HWOffsetFix<1,0,UNSIGNED> id4217out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4216out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3220out_value;

  HWOffsetFix<1,0,UNSIGNED> id4220out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4219out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3219out_value;

  HWOffsetFix<1,0,UNSIGNED> id4223out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4222out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3218out_value;

  HWOffsetFix<1,0,UNSIGNED> id4226out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4225out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3217out_value;

  HWOffsetFix<1,0,UNSIGNED> id4229out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4228out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3216out_value;

  HWOffsetFix<1,0,UNSIGNED> id4232out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4231out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3215out_value;

  HWOffsetFix<1,0,UNSIGNED> id4235out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4234out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3214out_value;

  HWOffsetFix<1,0,UNSIGNED> id4238out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4237out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3213out_value;

  HWOffsetFix<1,0,UNSIGNED> id4241out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4240out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3212out_value;

  HWOffsetFix<1,0,UNSIGNED> id4244out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4243out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3211out_value;

  HWOffsetFix<1,0,UNSIGNED> id4247out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4246out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3210out_value;

  HWOffsetFix<1,0,UNSIGNED> id4250out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4249out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3209out_value;

  HWOffsetFix<1,0,UNSIGNED> id4253out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4252out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3208out_value;

  HWOffsetFix<1,0,UNSIGNED> id4256out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4255out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3207out_value;

  HWOffsetFix<1,0,UNSIGNED> id4259out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4258out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3206out_value;

  HWOffsetFix<1,0,UNSIGNED> id4262out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4261out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3205out_value;

  HWOffsetFix<1,0,UNSIGNED> id4265out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4264out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3204out_value;

  HWOffsetFix<1,0,UNSIGNED> id4268out_output[5];

  HWOffsetFix<32,0,UNSIGNED> id4267out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3203out_value;

  HWOffsetFix<1,0,UNSIGNED> id4270out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4269out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3202out_value;

  HWOffsetFix<1,0,UNSIGNED> id4272out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4271out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3201out_value;

  HWOffsetFix<1,0,UNSIGNED> id4274out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4273out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3200out_value;

  HWOffsetFix<1,0,UNSIGNED> id4276out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4275out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3199out_value;

  HWOffsetFix<1,0,UNSIGNED> id4278out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4277out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3198out_value;

  HWOffsetFix<1,0,UNSIGNED> id4280out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4279out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3197out_value;

  HWOffsetFix<1,0,UNSIGNED> id4282out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4281out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3196out_value;

  HWOffsetFix<1,0,UNSIGNED> id4284out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4283out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3195out_value;

  HWOffsetFix<1,0,UNSIGNED> id4286out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4285out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3194out_value;

  HWOffsetFix<1,0,UNSIGNED> id4288out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4287out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3193out_value;

  HWOffsetFix<1,0,UNSIGNED> id4290out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4289out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3192out_value;

  HWOffsetFix<1,0,UNSIGNED> id4292out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4291out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3191out_value;

  HWOffsetFix<1,0,UNSIGNED> id4294out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4293out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3190out_value;

  HWOffsetFix<1,0,UNSIGNED> id4296out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4295out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id3189out_value;

  HWOffsetFix<1,0,UNSIGNED> id4298out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id4297out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id2555out_value;

  HWOffsetFix<1,0,UNSIGNED> id3188out_value;

  HWOffsetFix<49,0,UNSIGNED> id2552out_value;

  HWOffsetFix<48,0,UNSIGNED> id2553out_count;
  HWOffsetFix<1,0,UNSIGNED> id2553out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id2553st_count;

  HWOffsetFix<1,0,UNSIGNED> id3187out_value;

  HWOffsetFix<49,0,UNSIGNED> id2558out_value;

  HWOffsetFix<48,0,UNSIGNED> id2559out_count;
  HWOffsetFix<1,0,UNSIGNED> id2559out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id2559st_count;

  HWOffsetFix<48,0,UNSIGNED> id2561out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id3186out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits_2;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_1;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits_1;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits_2;
  const HWOffsetFix<65,0,UNSIGNED> c_hw_fix_65_0_uns_bits;
  const HWOffsetFix<65,0,UNSIGNED> c_hw_fix_65_0_uns_bits_1;
  const HWOffsetFix<65,0,UNSIGNED> c_hw_fix_65_0_uns_bits_2;
  const HWOffsetFix<64,0,UNSIGNED> c_hw_fix_64_0_uns_bits;
  const HWRawBits<32> c_hw_bit_32_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
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
