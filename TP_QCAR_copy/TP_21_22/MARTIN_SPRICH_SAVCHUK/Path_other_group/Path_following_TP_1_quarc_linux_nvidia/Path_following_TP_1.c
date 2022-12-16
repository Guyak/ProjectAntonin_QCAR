/*
 * Path_following_TP_1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP_1".
 *
 * Model version              : 5.21
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 21 15:01:59 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Path_following_TP_1.h"
#include "Path_following_TP_1_private.h"
#include "Path_following_TP_1_dt.h"

/* Block signals (default storage) */
B_Path_following_TP_1_T Path_following_TP_1_B;

/* Continuous states */
X_Path_following_TP_1_T Path_following_TP_1_X;

/* Block states (default storage) */
DW_Path_following_TP_1_T Path_following_TP_1_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Path_following_TP_1_T Path_following_TP_1_PrevZCX;

/* Real-time model */
static RT_MODEL_Path_following_TP_1_T Path_following_TP_1_M_;
RT_MODEL_Path_following_TP_1_T *const Path_following_TP_1_M =
  &Path_following_TP_1_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Path_following_TP_1_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Path_following_TP_1_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Path_following_TP_1_M->Timing.TaskCounters.TID[2])++;
  if ((Path_following_TP_1_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.1s, 0.0s] */
    Path_following_TP_1_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Path_following_TP_1_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Path_following_TP_1_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_steeringanglerad;
  real_T rtb_angularvelocityrads;
  real_T rtb_HILRead_o4;
  real_T rtb_L2psidot;
  real_T rtb_Sum_i;
  real_T rtb_cospsi;
  real_T rtb_sinpsi;
  boolean_T didZcEventOccur;
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    /* set solver stop time */
    if (!(Path_following_TP_1_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Path_following_TP_1_M->solverInfo,
                            ((Path_following_TP_1_M->Timing.clockTickH0 + 1) *
        Path_following_TP_1_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Path_following_TP_1_M->solverInfo,
                            ((Path_following_TP_1_M->Timing.clockTick0 + 1) *
        Path_following_TP_1_M->Timing.stepSize0 +
        Path_following_TP_1_M->Timing.clockTickH0 *
        Path_following_TP_1_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Path_following_TP_1_M)) {
    Path_following_TP_1_M->Timing.t[0] = rtsiGetT
      (&Path_following_TP_1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    /* Constant: '<S3>/Speed' */
    Path_following_TP_1_B.Speed = Path_following_TP_1_P.Speed_Value;

    /* Saturate: '<S7>/command saturation' */
    if (Path_following_TP_1_B.Speed >
        Path_following_TP_1_P.commandsaturation_UpperSat) {
      rtb_Sum_i = Path_following_TP_1_P.commandsaturation_UpperSat;
    } else if (Path_following_TP_1_B.Speed <
               Path_following_TP_1_P.commandsaturation_LowerSat) {
      rtb_Sum_i = Path_following_TP_1_P.commandsaturation_LowerSat;
    } else {
      rtb_Sum_i = Path_following_TP_1_B.Speed;
    }

    /* End of Saturate: '<S7>/command saturation' */

    /* Product: '<S7>/Multiply1' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    Path_following_TP_1_B.desired = rtb_Sum_i *
      Path_following_TP_1_P.Constant4_Value;

    /* Gain: '<S7>/Kff  (% // m//s)' */
    Path_following_TP_1_B.Kffms = Path_following_TP_1_P.Kffms_Gain *
      Path_following_TP_1_B.desired;
  }

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Integrator: '<S2>/Integrator2'
   */
  Path_following_TP_1_B.Product1 = Path_following_TP_1_P.Constant2_Value *
    Path_following_TP_1_X.Integrator2_CSTATE;

  /* Gain: '<S4>/Offset' incorporates:
   *  Gain: '<S4>/counts to rotations'
   *  Gain: '<S4>/gear ratios'
   *  Gain: '<S4>/rot//s to rad//s'
   *  Gain: '<S4>/wheel radius'
   */
  Path_following_TP_1_B.Offset = Path_following_TP_1_P.countstorotations_Gain *
    Path_following_TP_1_B.Product1 * Path_following_TP_1_P.gearratios_Gain *
    Path_following_TP_1_P.rotstorads_Gain *
    Path_following_TP_1_P.wheelradius_Gain * Path_following_TP_1_P.Offset_Gain;

  /* Product: '<S7>/Multiply' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  Path_following_TP_1_B.measured = Path_following_TP_1_B.Offset *
    Path_following_TP_1_P.Constant4_Value;

  /* Sum: '<S7>/Sum' */
  rtb_Sum_i = Path_following_TP_1_B.desired - Path_following_TP_1_B.measured;
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    /* RelationalOperator: '<S8>/Compare' incorporates:
     *  Constant: '<S8>/Constant'
     */
    Path_following_TP_1_B.Compare = (Path_following_TP_1_B.desired ==
      Path_following_TP_1_P.Constant_Value);
  }

  /* Integrator: '<S7>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    didZcEventOccur = (((Path_following_TP_1_PrevZCX.Integrator1_Reset_ZCE == 1)
                        != (int32_T)Path_following_TP_1_B.Compare) &&
                       (Path_following_TP_1_PrevZCX.Integrator1_Reset_ZCE != 3));
    Path_following_TP_1_PrevZCX.Integrator1_Reset_ZCE =
      Path_following_TP_1_B.Compare;

    /* evaluate zero-crossings */
    if (didZcEventOccur) {
      Path_following_TP_1_X.Integrator1_CSTATE =
        Path_following_TP_1_P.Integrator1_IC;
    }
  }

  if (Path_following_TP_1_X.Integrator1_CSTATE >=
      Path_following_TP_1_P.Integrator1_UpperSat) {
    Path_following_TP_1_X.Integrator1_CSTATE =
      Path_following_TP_1_P.Integrator1_UpperSat;
  } else if (Path_following_TP_1_X.Integrator1_CSTATE <=
             Path_following_TP_1_P.Integrator1_LowerSat) {
    Path_following_TP_1_X.Integrator1_CSTATE =
      Path_following_TP_1_P.Integrator1_LowerSat;
  }

  /* Sum: '<S7>/Add1' incorporates:
   *  Gain: '<S7>/Kp (% // m//s)'
   *  Integrator: '<S7>/Integrator1'
   *  Sum: '<S7>/Add'
   */
  rtb_L2psidot = (Path_following_TP_1_P.Kpms_Gain * rtb_Sum_i +
                  Path_following_TP_1_X.Integrator1_CSTATE) +
    Path_following_TP_1_B.Kffms;

  /* Saturate: '<S7>/Motor_command  sat' */
  if (rtb_L2psidot > Path_following_TP_1_P.Motor_commandsat_UpperSat) {
    rtb_L2psidot = Path_following_TP_1_P.Motor_commandsat_UpperSat;
  } else if (rtb_L2psidot < Path_following_TP_1_P.Motor_commandsat_LowerSat) {
    rtb_L2psidot = Path_following_TP_1_P.Motor_commandsat_LowerSat;
  }

  /* End of Saturate: '<S7>/Motor_command  sat' */

  /* Gain: '<Root>/direction convention' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Product: '<S7>/Multiply2'
   */
  rtb_L2psidot = rtb_L2psidot * Path_following_TP_1_P.Constant4_Value *
    Path_following_TP_1_P.directionconvention_Gain;

  /* Saturate: '<Root>/command saturation' */
  if (rtb_L2psidot > Path_following_TP_1_P.commandsaturation_UpperSat_e) {
    /* Saturate: '<Root>/command saturation' */
    Path_following_TP_1_B.commandsaturation =
      Path_following_TP_1_P.commandsaturation_UpperSat_e;
  } else if (rtb_L2psidot < Path_following_TP_1_P.commandsaturation_LowerSat_k)
  {
    /* Saturate: '<Root>/command saturation' */
    Path_following_TP_1_B.commandsaturation =
      Path_following_TP_1_P.commandsaturation_LowerSat_k;
  } else {
    /* Saturate: '<Root>/command saturation' */
    Path_following_TP_1_B.commandsaturation = rtb_L2psidot;
  }

  /* End of Saturate: '<Root>/command saturation' */
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    /* Product: '<S1>/Product' incorporates:
     *  Constant: '<S1>/Bicycle length'
     *  Constant: '<S1>/Constant6'
     */
    Path_following_TP_1_B.Product = Path_following_TP_1_P.Constant6_Value *
      Path_following_TP_1_P.Bicyclelength_Value;
  }

  /* SignalGenerator: '<S3>/Signal Generator' */
  Path_following_TP_1_B.SignalGenerator = sin(6.2831853071795862 *
    Path_following_TP_1_M->Timing.t[0] *
    Path_following_TP_1_P.SignalGenerator_Frequency) *
    Path_following_TP_1_P.SignalGenerator_Amplitude;

  /* Trigonometry: '<S1>/Atan' incorporates:
   *  Constant: '<S1>/Lookahead distance'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Product1'
   *  Sin: '<S1>/Sine Wave Function'
   */
  rtb_L2psidot = atan((sin(Path_following_TP_1_P.SineWaveFunction_Freq *
    Path_following_TP_1_B.SignalGenerator +
    Path_following_TP_1_P.SineWaveFunction_Phase) *
                       Path_following_TP_1_P.SineWaveFunction_Amp +
                       Path_following_TP_1_P.SineWaveFunction_Bias) *
                      Path_following_TP_1_B.Product /
                      Path_following_TP_1_P.Lookaheaddistance_Value);

  /* Saturate: '<Root>/angle saturation1' */
  if (rtb_L2psidot > Path_following_TP_1_P.anglesaturation1_UpperSat) {
    /* Saturate: '<Root>/angle saturation1' */
    Path_following_TP_1_B.anglesaturation1 =
      Path_following_TP_1_P.anglesaturation1_UpperSat;
  } else if (rtb_L2psidot < Path_following_TP_1_P.anglesaturation1_LowerSat) {
    /* Saturate: '<Root>/angle saturation1' */
    Path_following_TP_1_B.anglesaturation1 =
      Path_following_TP_1_P.anglesaturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/angle saturation1' */
    Path_following_TP_1_B.anglesaturation1 = rtb_L2psidot;
  }

  /* End of Saturate: '<Root>/angle saturation1' */
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    /* S-Function (hil_write_block): '<Root>/HIL Write1' */

    /* S-Function Block: Path_following_TP_1/HIL Write1 (hil_write_block) */
    {
      t_error result;
      result = hil_write(Path_following_TP_1_DW.HILInitialize1_Card,
                         NULL, 0U,
                         &Path_following_TP_1_P.HILWrite1_pwm_channels, 1U,
                         NULL, 0U,
                         &Path_following_TP_1_P.HILWrite1_other_channels, 1U,
                         NULL,
                         &Path_following_TP_1_B.commandsaturation,
                         NULL,
                         &Path_following_TP_1_B.anglesaturation1
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
      }
    }
  }

  /* Integrator: '<S6>/Integrator' */
  Path_following_TP_1_B.Integrator = Path_following_TP_1_X.Integrator_CSTATE;

  /* Integrator: '<S6>/Integrator1' */
  Path_following_TP_1_B.Integrator1 = Path_following_TP_1_X.Integrator1_CSTATE_o;

  /* Integrator: '<S6>/Integrator2' */
  Path_following_TP_1_B.psi_headingrad =
    Path_following_TP_1_X.Integrator2_CSTATE_o;

  /* RateTransition: '<S5>/Rate Transition' */
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    /* RateTransition: '<S5>/Rate Transition' */
    Path_following_TP_1_B.RateTransition[0] = Path_following_TP_1_B.Integrator;
    Path_following_TP_1_B.RateTransition[1] = Path_following_TP_1_B.Integrator1;
    Path_following_TP_1_B.RateTransition[2] =
      Path_following_TP_1_B.psi_headingrad;
    Path_following_TP_1_B.RateTransition[3] =
      Path_following_TP_1_B.anglesaturation1;

    /* S-Function (hil_read_block): '<Root>/HIL Read' */

    /* S-Function Block: Path_following_TP_1/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(Path_following_TP_1_DW.HILInitialize1_Card,
        NULL, 0U,
        Path_following_TP_1_P.HILRead_encoder_channels, 2U,
        NULL, 0U,
        Path_following_TP_1_P.HILRead_other_channels, 2U,
        NULL,
        &Path_following_TP_1_DW.HILRead_EncoderBuffer[0],
        NULL,
        &Path_following_TP_1_DW.HILRead_OtherBuffer[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
      } else {
        Path_following_TP_1_B.motorcounts =
          Path_following_TP_1_DW.HILRead_EncoderBuffer[0];
        rtb_steeringanglerad = Path_following_TP_1_DW.HILRead_EncoderBuffer[1];
        rtb_angularvelocityrads = Path_following_TP_1_DW.HILRead_OtherBuffer[0];
        rtb_HILRead_o4 = Path_following_TP_1_DW.HILRead_OtherBuffer[1];
      }
    }

    /* S-Function (inverse_modulus_block): '<Root>/Unwrap 2^24' */
    /* S-Function Block: Path_following_TP_1/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.033333333333333333;
      real_T half_range = Path_following_TP_1_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Path_following_TP_1_DW.Unwrap224_FirstSample) {
        Path_following_TP_1_DW.Unwrap224_FirstSample = false;
        Path_following_TP_1_DW.Unwrap224_PreviousInput =
          Path_following_TP_1_B.motorcounts;
      }

      du = (real_T) Path_following_TP_1_B.motorcounts -
        Path_following_TP_1_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Path_following_TP_1_DW.Unwrap224_Revolutions =
          Path_following_TP_1_DW.Unwrap224_Revolutions - 1;
        dy = du - Path_following_TP_1_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Path_following_TP_1_DW.Unwrap224_Revolutions =
          Path_following_TP_1_DW.Unwrap224_Revolutions + 1;
        dy = du + Path_following_TP_1_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Path_following_TP_1_B.Unwrap224 = Path_following_TP_1_B.motorcounts +
        Path_following_TP_1_DW.Unwrap224_Revolutions *
        Path_following_TP_1_P.Unwrap224_Modulus;
      Path_following_TP_1_DW.Unwrap224_PreviousInput =
        Path_following_TP_1_B.motorcounts;
    }
  }

  /* End of RateTransition: '<S5>/Rate Transition' */

  /* Integrator: '<S2>/Integrator1' */
  if (Path_following_TP_1_DW.Integrator1_IWORK != 0) {
    Path_following_TP_1_X.Integrator1_CSTATE_d = Path_following_TP_1_B.Unwrap224;
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S2>/Constant'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator2'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  Path_following_TP_1_B.Product_e = ((Path_following_TP_1_B.Unwrap224 -
    Path_following_TP_1_X.Integrator1_CSTATE_d) -
    Path_following_TP_1_X.Integrator2_CSTATE *
    Path_following_TP_1_P.Constant_Value_n *
    Path_following_TP_1_P.Constant3_Value) *
    Path_following_TP_1_P.Constant2_Value;
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
  }

  /* Product: '<S6>/Product2' incorporates:
   *  Gain: '<S6>/1//L'
   */
  Path_following_TP_1_B.psidotrads = 1.0 / Path_following_TP_1_P.vehicle_length *
    Path_following_TP_1_B.Offset * Path_following_TP_1_B.anglesaturation1;

  /* Gain: '<S6>/Gain' */
  rtb_L2psidot = Path_following_TP_1_P.vehicle_length / 2.0 *
    Path_following_TP_1_B.psidotrads;

  /* Trigonometry: '<S6>/Trigonometric Function1' */
  rtb_sinpsi = sin(Path_following_TP_1_B.psi_headingrad);

  /* Trigonometry: '<S6>/Trigonometric Function' */
  rtb_cospsi = cos(Path_following_TP_1_B.psi_headingrad);

  /* Sum: '<S6>/Sum' incorporates:
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product3'
   */
  Path_following_TP_1_B.v_Xms = Path_following_TP_1_B.Offset * rtb_cospsi -
    rtb_L2psidot * rtb_sinpsi;

  /* Sum: '<S6>/Sum1' incorporates:
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product4'
   */
  Path_following_TP_1_B.v_Yms = Path_following_TP_1_B.Offset * rtb_sinpsi +
    rtb_L2psidot * rtb_cospsi;
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
  }

  /* Gain: '<S7>/Ki (% // m)  ' */
  Path_following_TP_1_B.Kim = Path_following_TP_1_P.Kim_Gain * rtb_Sum_i;
}

/* Model update function for TID0 */
void Path_following_TP_1_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S2>/Integrator1' */
  Path_following_TP_1_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(Path_following_TP_1_M)) {
    rt_ertODEUpdateContinuousStates(&Path_following_TP_1_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Path_following_TP_1_M->Timing.clockTick0)) {
    ++Path_following_TP_1_M->Timing.clockTickH0;
  }

  Path_following_TP_1_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Path_following_TP_1_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Path_following_TP_1_M->Timing.clockTick1)) {
    ++Path_following_TP_1_M->Timing.clockTickH1;
  }

  Path_following_TP_1_M->Timing.t[1] = Path_following_TP_1_M->Timing.clockTick1 *
    Path_following_TP_1_M->Timing.stepSize1 +
    Path_following_TP_1_M->Timing.clockTickH1 *
    Path_following_TP_1_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Path_following_TP_1_derivatives(void)
{
  XDot_Path_following_TP_1_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Path_following_TP_1_T *) Path_following_TP_1_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Path_following_TP_1_B.Product_e;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  lsat = (Path_following_TP_1_X.Integrator1_CSTATE <=
          Path_following_TP_1_P.Integrator1_LowerSat);
  usat = (Path_following_TP_1_X.Integrator1_CSTATE >=
          Path_following_TP_1_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Path_following_TP_1_B.Kim > 0.0)) ||
      (usat && (Path_following_TP_1_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE = Path_following_TP_1_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S7>/Integrator1' */

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = Path_following_TP_1_B.v_Xms;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_o = Path_following_TP_1_B.v_Yms;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = Path_following_TP_1_B.psidotrads;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_d = Path_following_TP_1_B.Product1;
}

/* Model output function for TID2 */
void Path_following_TP_1_output2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void Path_following_TP_1_update2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Path_following_TP_1_M->Timing.clockTick2)) {
    ++Path_following_TP_1_M->Timing.clockTickH2;
  }

  Path_following_TP_1_M->Timing.t[2] = Path_following_TP_1_M->Timing.clockTick2 *
    Path_following_TP_1_M->Timing.stepSize2 +
    Path_following_TP_1_M->Timing.clockTickH2 *
    Path_following_TP_1_M->Timing.stepSize2 * 4294967296.0;
}

/* Model wrapper function for compatibility with a static main program */
void Path_following_TP_1_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Path_following_TP_1_output0();
    break;

   case 2 :
    Path_following_TP_1_output2();
    break;

   default :
    break;
  }
}

/* Model wrapper function for compatibility with a static main program */
void Path_following_TP_1_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Path_following_TP_1_update0();
    break;

   case 2 :
    Path_following_TP_1_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Path_following_TP_1_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: Path_following_TP_1/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Path_following_TP_1_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Path_following_TP_1_DW.HILInitialize1_Card,
       "gyro_fs=125;gyro_rate=47;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
       251);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Path_following_TP_1_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
      return;
    }

    if ((Path_following_TP_1_P.HILInitialize1_AIPStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &Path_following_TP_1_DW.HILInitialize1_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Path_following_TP_1_P.HILInitialize1_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &Path_following_TP_1_DW.HILInitialize1_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Path_following_TP_1_P.HILInitialize1_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Path_following_TP_1_DW.HILInitialize1_Card,
         Path_following_TP_1_P.HILInitialize1_AIChannels, 7U,
         &Path_following_TP_1_DW.HILInitialize1_AIMinimums[0],
         &Path_following_TP_1_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (Path_following_TP_1_DW.HILInitialize1_Card,
       Path_following_TP_1_P.HILInitialize1_DIChannels, 20U,
       &Path_following_TP_1_P.HILInitialize1_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
      return;
    }

    if ((Path_following_TP_1_P.HILInitialize1_DOStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_DOEnter && is_switching)) {
      result = hil_write_digital(Path_following_TP_1_DW.HILInitialize1_Card,
        &Path_following_TP_1_P.HILInitialize1_DOChannels, 1U, (t_boolean *)
        &Path_following_TP_1_P.HILInitialize1_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    if ((Path_following_TP_1_P.HILInitialize1_EIPStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_EIPEnter && is_switching)) {
      Path_following_TP_1_DW.HILInitialize1_QuadratureModes[0] =
        (Path_following_TP_1_P.HILInitialize1_EIQuadrature[0]);
      Path_following_TP_1_DW.HILInitialize1_QuadratureModes[1] =
        (Path_following_TP_1_P.HILInitialize1_EIQuadrature[1]);
      Path_following_TP_1_DW.HILInitialize1_QuadratureModes[2] =
        (Path_following_TP_1_P.HILInitialize1_EIQuadrature[1]);
      Path_following_TP_1_DW.HILInitialize1_QuadratureModes[3] =
        (Path_following_TP_1_P.HILInitialize1_EIQuadrature[1]);
      Path_following_TP_1_DW.HILInitialize1_QuadratureModes[4] =
        (Path_following_TP_1_P.HILInitialize1_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (Path_following_TP_1_DW.HILInitialize1_Card,
         Path_following_TP_1_P.HILInitialize1_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &Path_following_TP_1_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &Path_following_TP_1_DW.HILInitialize1_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] =
            Path_following_TP_1_P.HILInitialize1_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (Path_following_TP_1_DW.HILInitialize1_Card,
         Path_following_TP_1_P.HILInitialize1_EIChannels, 5U,
         &Path_following_TP_1_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    if ((Path_following_TP_1_P.HILInitialize1_EIStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Path_following_TP_1_DW.HILInitialize1_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] =
            Path_following_TP_1_P.HILInitialize1_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Path_following_TP_1_DW.HILInitialize1_Card,
        Path_following_TP_1_P.HILInitialize1_EIChannels, 5U,
        &Path_following_TP_1_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    if ((Path_following_TP_1_P.HILInitialize1_POPStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      Path_following_TP_1_DW.HILInitialize1_POModeValues[0] =
        (Path_following_TP_1_P.HILInitialize1_POModes[0]);

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Path_following_TP_1_DW.HILInitialize1_POModeValues[1];
        for (i1=0; i1 < 7; i1++) {
          dw_POModeValues[i1] = (Path_following_TP_1_P.HILInitialize1_POModes[1]);
        }
      }

      result = hil_set_pwm_mode(Path_following_TP_1_DW.HILInitialize1_Card,
        Path_following_TP_1_P.HILInitialize1_POChannels, 8U, (t_pwm_mode *)
        &Path_following_TP_1_DW.HILInitialize1_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize1_POChannels =
          Path_following_TP_1_P.HILInitialize1_POChannels;
        int32_T *dw_POModeValues =
          &Path_following_TP_1_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Path_following_TP_1_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize1_POChannels[i1]);
            Path_following_TP_1_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes]
              = Path_following_TP_1_P.HILInitialize1_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Path_following_TP_1_DW.HILInitialize1_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize1_POChannels[i1]);
            Path_following_TP_1_DW.HILInitialize1_POSortedFreqs[7U -
              num_frequency_modes] =
              Path_following_TP_1_P.HILInitialize1_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (Path_following_TP_1_DW.HILInitialize1_Card,
           &Path_following_TP_1_DW.HILInitialize1_POSortedChans[0],
           num_duty_cycle_modes,
           &Path_following_TP_1_DW.HILInitialize1_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (Path_following_TP_1_DW.HILInitialize1_Card,
           &Path_following_TP_1_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &Path_following_TP_1_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Path_following_TP_1_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Path_following_TP_1_P.HILInitialize1_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Path_following_TP_1_DW.HILInitialize1_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            Path_following_TP_1_P.HILInitialize1_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Path_following_TP_1_DW.HILInitialize1_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            Path_following_TP_1_P.HILInitialize1_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (Path_following_TP_1_DW.HILInitialize1_Card,
         Path_following_TP_1_P.HILInitialize1_POChannels, 8U,
         (t_pwm_configuration *)
         &Path_following_TP_1_DW.HILInitialize1_POModeValues[0],
         (t_pwm_alignment *)
         &Path_following_TP_1_DW.HILInitialize1_POAlignValues[0],
         (t_pwm_polarity *)
         &Path_following_TP_1_DW.HILInitialize1_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    if ((Path_following_TP_1_P.HILInitialize1_POStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Path_following_TP_1_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Path_following_TP_1_P.HILInitialize1_POInitial;
        }
      }

      result = hil_write_pwm(Path_following_TP_1_DW.HILInitialize1_Card,
        Path_following_TP_1_P.HILInitialize1_POChannels, 8U,
        &Path_following_TP_1_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    if (Path_following_TP_1_P.HILInitialize1_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Path_following_TP_1_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Path_following_TP_1_P.HILInitialize1_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Path_following_TP_1_DW.HILInitialize1_Card,
         Path_following_TP_1_P.HILInitialize1_POChannels, 8U,
         &Path_following_TP_1_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }

    if ((Path_following_TP_1_P.HILInitialize1_OOStart && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Path_following_TP_1_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Path_following_TP_1_P.HILInitialize1_OOInitial;
        }
      }

      result = hil_write_other(Path_following_TP_1_DW.HILInitialize1_Card,
        Path_following_TP_1_P.HILInitialize1_OOChannels, 13U,
        &Path_following_TP_1_DW.HILInitialize1_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Unwrap 2^24' */

  /* S-Function Block: Path_following_TP_1/Unwrap 2^24 (inverse_modulus_block) */
  {
    Path_following_TP_1_DW.Unwrap224_FirstSample = true;
    Path_following_TP_1_DW.Unwrap224_Revolutions = 0;
  }

  Path_following_TP_1_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  Path_following_TP_1_X.Integrator2_CSTATE =
    Path_following_TP_1_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  Path_following_TP_1_X.Integrator1_CSTATE =
    Path_following_TP_1_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Path_following_TP_1_X.Integrator_CSTATE = Path_following_TP_1_P.X_ic;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  Path_following_TP_1_X.Integrator1_CSTATE_o = Path_following_TP_1_P.Y_ic;

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  Path_following_TP_1_X.Integrator2_CSTATE_o = Path_following_TP_1_P.yaw_ic;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  if (rtmIsFirstInitCond(Path_following_TP_1_M)) {
    Path_following_TP_1_X.Integrator1_CSTATE_d = 0.0;
  }

  Path_following_TP_1_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S2>/Integrator1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Path_following_TP_1_M)) {
    rtmSetFirstInitCond(Path_following_TP_1_M, 0);
  }
}

/* Model terminate function */
void Path_following_TP_1_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: Path_following_TP_1/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Path_following_TP_1_DW.HILInitialize1_Card);
    hil_monitor_stop_all(Path_following_TP_1_DW.HILInitialize1_Card);
    is_switching = false;
    if ((Path_following_TP_1_P.HILInitialize1_DOTerminate && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Path_following_TP_1_P.HILInitialize1_POTerminate && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Path_following_TP_1_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Path_following_TP_1_P.HILInitialize1_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Path_following_TP_1_P.HILInitialize1_OOTerminate && !is_switching) ||
        (Path_following_TP_1_P.HILInitialize1_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Path_following_TP_1_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Path_following_TP_1_P.HILInitialize1_OOFinal;
        }
      }

      num_final_other_outputs = 13U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Path_following_TP_1_DW.HILInitialize1_Card
                         , NULL, 0
                         , Path_following_TP_1_P.HILInitialize1_POChannels,
                         num_final_pwm_outputs
                         , &Path_following_TP_1_P.HILInitialize1_DOChannels,
                         num_final_digital_outputs
                         , Path_following_TP_1_P.HILInitialize1_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Path_following_TP_1_DW.HILInitialize1_POValues[0]
                         , (t_boolean *)
                         &Path_following_TP_1_P.HILInitialize1_DOFinal
                         , &Path_following_TP_1_DW.HILInitialize1_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (Path_following_TP_1_DW.HILInitialize1_Card,
             Path_following_TP_1_P.HILInitialize1_POChannels,
             num_final_pwm_outputs,
             &Path_following_TP_1_DW.HILInitialize1_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Path_following_TP_1_DW.HILInitialize1_Card,
             &Path_following_TP_1_P.HILInitialize1_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &Path_following_TP_1_P.HILInitialize1_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (Path_following_TP_1_DW.HILInitialize1_Card,
             Path_following_TP_1_P.HILInitialize1_OOChannels,
             num_final_other_outputs,
             &Path_following_TP_1_DW.HILInitialize1_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Path_following_TP_1_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Path_following_TP_1_DW.HILInitialize1_Card);
    hil_monitor_delete_all(Path_following_TP_1_DW.HILInitialize1_Card);
    hil_close(Path_following_TP_1_DW.HILInitialize1_Card);
    Path_following_TP_1_DW.HILInitialize1_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Path_following_TP_1_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Path_following_TP_1_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Path_following_TP_1_initialize();
}

void MdlTerminate(void)
{
  Path_following_TP_1_terminate();
}

/* Registration function */
RT_MODEL_Path_following_TP_1_T *Path_following_TP_1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Path_following_TP_1_M, 0,
                sizeof(RT_MODEL_Path_following_TP_1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Path_following_TP_1_M->solverInfo,
                          &Path_following_TP_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Path_following_TP_1_M->solverInfo, &rtmGetTPtr
                (Path_following_TP_1_M));
    rtsiSetStepSizePtr(&Path_following_TP_1_M->solverInfo,
                       &Path_following_TP_1_M->Timing.stepSize0);
    rtsiSetdXPtr(&Path_following_TP_1_M->solverInfo,
                 &Path_following_TP_1_M->derivs);
    rtsiSetContStatesPtr(&Path_following_TP_1_M->solverInfo, (real_T **)
                         &Path_following_TP_1_M->contStates);
    rtsiSetNumContStatesPtr(&Path_following_TP_1_M->solverInfo,
      &Path_following_TP_1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Path_following_TP_1_M->solverInfo,
      &Path_following_TP_1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Path_following_TP_1_M->solverInfo,
      &Path_following_TP_1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Path_following_TP_1_M->solverInfo,
      &Path_following_TP_1_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Path_following_TP_1_M->solverInfo,
                          (&rtmGetErrorStatus(Path_following_TP_1_M)));
    rtsiSetRTModelPtr(&Path_following_TP_1_M->solverInfo, Path_following_TP_1_M);
  }

  rtsiSetSimTimeStep(&Path_following_TP_1_M->solverInfo, MAJOR_TIME_STEP);
  Path_following_TP_1_M->intgData.f[0] = Path_following_TP_1_M->odeF[0];
  Path_following_TP_1_M->contStates = ((real_T *) &Path_following_TP_1_X);
  rtsiSetSolverData(&Path_following_TP_1_M->solverInfo, (void *)
                    &Path_following_TP_1_M->intgData);
  rtsiSetSolverName(&Path_following_TP_1_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Path_following_TP_1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Path_following_TP_1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Path_following_TP_1_M->Timing.sampleTimes =
      (&Path_following_TP_1_M->Timing.sampleTimesArray[0]);
    Path_following_TP_1_M->Timing.offsetTimes =
      (&Path_following_TP_1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Path_following_TP_1_M->Timing.sampleTimes[0] = (0.0);
    Path_following_TP_1_M->Timing.sampleTimes[1] = (0.033333333333333333);
    Path_following_TP_1_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    Path_following_TP_1_M->Timing.offsetTimes[0] = (0.0);
    Path_following_TP_1_M->Timing.offsetTimes[1] = (0.0);
    Path_following_TP_1_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Path_following_TP_1_M, &Path_following_TP_1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Path_following_TP_1_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Path_following_TP_1_M->Timing.perTaskSampleHitsArray;
    Path_following_TP_1_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Path_following_TP_1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Path_following_TP_1_M, 24.0);
  Path_following_TP_1_M->Timing.stepSize0 = 0.033333333333333333;
  Path_following_TP_1_M->Timing.stepSize1 = 0.033333333333333333;
  Path_following_TP_1_M->Timing.stepSize2 = 0.1;
  rtmSetFirstInitCond(Path_following_TP_1_M, 1);

  /* External mode info */
  Path_following_TP_1_M->Sizes.checksums[0] = (789728585U);
  Path_following_TP_1_M->Sizes.checksums[1] = (4026775114U);
  Path_following_TP_1_M->Sizes.checksums[2] = (67514307U);
  Path_following_TP_1_M->Sizes.checksums[3] = (1828624872U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Path_following_TP_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Path_following_TP_1_M->extModeInfo,
      &Path_following_TP_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Path_following_TP_1_M->extModeInfo,
                        Path_following_TP_1_M->Sizes.checksums);
    rteiSetTPtr(Path_following_TP_1_M->extModeInfo, rtmGetTPtr
                (Path_following_TP_1_M));
  }

  Path_following_TP_1_M->solverInfoPtr = (&Path_following_TP_1_M->solverInfo);
  Path_following_TP_1_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Path_following_TP_1_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&Path_following_TP_1_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Path_following_TP_1_M->blockIO = ((void *) &Path_following_TP_1_B);
  (void) memset(((void *) &Path_following_TP_1_B), 0,
                sizeof(B_Path_following_TP_1_T));

  /* parameters */
  Path_following_TP_1_M->defaultParam = ((real_T *)&Path_following_TP_1_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Path_following_TP_1_X;
    Path_following_TP_1_M->contStates = (x);
    (void) memset((void *)&Path_following_TP_1_X, 0,
                  sizeof(X_Path_following_TP_1_T));
  }

  /* states (dwork) */
  Path_following_TP_1_M->dwork = ((void *) &Path_following_TP_1_DW);
  (void) memset((void *)&Path_following_TP_1_DW, 0,
                sizeof(DW_Path_following_TP_1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Path_following_TP_1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Path_following_TP_1_M->Sizes.numContStates = (6);/* Number of continuous states */
  Path_following_TP_1_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Path_following_TP_1_M->Sizes.numY = (0);/* Number of model outputs */
  Path_following_TP_1_M->Sizes.numU = (0);/* Number of model inputs */
  Path_following_TP_1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Path_following_TP_1_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Path_following_TP_1_M->Sizes.numBlocks = (68);/* Number of blocks */
  Path_following_TP_1_M->Sizes.numBlockIO = (22);/* Number of block outputs */
  Path_following_TP_1_M->Sizes.numBlockPrms = (159);/* Sum of parameter "widths" */
  return Path_following_TP_1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
