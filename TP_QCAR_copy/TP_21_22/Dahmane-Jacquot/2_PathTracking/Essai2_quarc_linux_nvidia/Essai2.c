/*
 * Essai2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Essai2".
 *
 * Model version              : 5.4
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 15:26:28 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Essai2.h"
#include "Essai2_private.h"
#include "Essai2_dt.h"

/* Block signals (default storage) */
B_Essai2_T Essai2_B;

/* Continuous states */
X_Essai2_T Essai2_X;

/* Block states (default storage) */
DW_Essai2_T Essai2_DW;

/* Real-time model */
static RT_MODEL_Essai2_T Essai2_M_;
RT_MODEL_Essai2_T *const Essai2_M = &Essai2_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Essai2_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Essai2_M, 2);
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
  (Essai2_M->Timing.TaskCounters.TID[2])++;
  if ((Essai2_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.1s, 0.0s] */
    Essai2_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Essai2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Essai2_output0(void)              /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_steeringanglerad;
  real_T rtb_HILRead1_o4;
  real_T rtb_commandsaturation1;
  real_T rtb_cospsi;
  real_T rtb_sinpsi;
  if (rtmIsMajorTimeStep(Essai2_M)) {
    /* set solver stop time */
    if (!(Essai2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Essai2_M->solverInfo,
                            ((Essai2_M->Timing.clockTickH0 + 1) *
        Essai2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Essai2_M->solverInfo, ((Essai2_M->Timing.clockTick0
        + 1) * Essai2_M->Timing.stepSize0 + Essai2_M->Timing.clockTickH0 *
        Essai2_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Essai2_M)) {
    Essai2_M->Timing.t[0] = rtsiGetT(&Essai2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Essai2_M)) {
    /* Constant: '<Root>/Constant' */
    Essai2_B.Constant = Essai2_P.Constant_Value;
  }

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Integrator: '<S2>/Integrator2'
   */
  Essai2_B.Product1 = Essai2_P.Constant1_Value * Essai2_X.Integrator2_CSTATE;

  /* Gain: '<S4>/Offset' incorporates:
   *  Gain: '<S4>/counts to rotations'
   *  Gain: '<S4>/gear ratios'
   *  Gain: '<S4>/rot//s to rad//s'
   *  Gain: '<S4>/wheel radius'
   */
  Essai2_B.Offset = Essai2_P.countstorotations_Gain * Essai2_B.Product1 *
    Essai2_P.gearratios_Gain * Essai2_P.rotstorads_Gain *
    Essai2_P.wheelradius_Gain * Essai2_P.Offset_Gain;

  /* Integrator: '<Root>/Integrator' */
  Essai2_B.headingpositiongyroscope = Essai2_X.Integrator_CSTATE;

  /* Sum: '<Root>/Sum' */
  Essai2_B.Sum = Essai2_B.Constant - Essai2_B.headingpositiongyroscope;

  /* Gain: '<S43>/Proportional Gain' */
  Essai2_B.ProportionalGain = Essai2_P.PIDController_P * Essai2_B.Sum;
  if (rtmIsMajorTimeStep(Essai2_M)) {
    /* S-Function (hil_read_block): '<Root>/HIL Read1' */

    /* S-Function Block: Essai2/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read(Essai2_DW.HILInitialize2_Card,
        NULL, 0U,
        Essai2_P.HILRead1_encoder_channels, 2U,
        NULL, 0U,
        Essai2_P.HILRead1_other_channels, 2U,
        NULL,
        &Essai2_DW.HILRead1_EncoderBuffer[0],
        NULL,
        &Essai2_DW.HILRead1_OtherBuffer[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
      } else {
        Essai2_B.motorcounts = Essai2_DW.HILRead1_EncoderBuffer[0];
        rtb_steeringanglerad = Essai2_DW.HILRead1_EncoderBuffer[1];
        Essai2_B.HILRead1_o3 = Essai2_DW.HILRead1_OtherBuffer[0];
        rtb_HILRead1_o4 = Essai2_DW.HILRead1_OtherBuffer[1];
      }
    }

    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    rtb_commandsaturation1 = Essai2_P.Gain_Gain * Essai2_P.Constant6_Value;

    /* Saturate: '<Root>/command saturation1' */
    if (rtb_commandsaturation1 > Essai2_P.commandsaturation1_UpperSat) {
      rtb_commandsaturation1 = Essai2_P.commandsaturation1_UpperSat;
    } else if (rtb_commandsaturation1 < Essai2_P.commandsaturation1_LowerSat) {
      rtb_commandsaturation1 = Essai2_P.commandsaturation1_LowerSat;
    }

    /* End of Saturate: '<Root>/command saturation1' */

    /* S-Function (hil_write_block): '<Root>/HIL Write2' */

    /* S-Function Block: Essai2/HIL Write2 (hil_write_block) */
    {
      t_error result;
      result = hil_write(Essai2_DW.HILInitialize2_Card,
                         NULL, 0U,
                         &Essai2_P.HILWrite2_pwm_channels, 1U,
                         NULL, 0U,
                         &Essai2_P.HILWrite2_other_channels, 1U,
                         NULL,
                         &rtb_commandsaturation1,
                         NULL,
                         &Essai2_B.ProportionalGain
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
      }
    }
  }

  /* Integrator: '<S6>/Integrator' */
  Essai2_B.Integrator = Essai2_X.Integrator_CSTATE_f;

  /* Integrator: '<S6>/Integrator1' */
  Essai2_B.Integrator1 = Essai2_X.Integrator1_CSTATE;

  /* Integrator: '<S6>/Integrator2' */
  Essai2_B.psi_headingrad = Essai2_X.Integrator2_CSTATE_p;

  /* RateTransition: '<S5>/Rate Transition' */
  if (rtmIsMajorTimeStep(Essai2_M)) {
    /* RateTransition: '<S5>/Rate Transition' */
    Essai2_B.RateTransition[0] = Essai2_B.Integrator;
    Essai2_B.RateTransition[1] = Essai2_B.Integrator1;
    Essai2_B.RateTransition[2] = Essai2_B.psi_headingrad;
    Essai2_B.RateTransition[3] = Essai2_B.ProportionalGain;

    /* S-Function (inverse_modulus_block): '<Root>/Unwrap 2^1' */
    /* S-Function Block: Essai2/Unwrap 2^1 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.033333333333333333;
      real_T half_range = Essai2_P.Unwrap21_Modulus / 2.0;
      real_T du, dy;
      if (Essai2_DW.Unwrap21_FirstSample) {
        Essai2_DW.Unwrap21_FirstSample = false;
        Essai2_DW.Unwrap21_PreviousInput = Essai2_B.motorcounts;
      }

      du = (real_T) Essai2_B.motorcounts - Essai2_DW.Unwrap21_PreviousInput;
      if (du > half_range) {
        Essai2_DW.Unwrap21_Revolutions = Essai2_DW.Unwrap21_Revolutions - 1;
        dy = du - Essai2_P.Unwrap21_Modulus;
      } else if (du < -half_range) {
        Essai2_DW.Unwrap21_Revolutions = Essai2_DW.Unwrap21_Revolutions + 1;
        dy = du + Essai2_P.Unwrap21_Modulus;
      } else {
        dy = du;
      }

      Essai2_B.Unwrap21 = Essai2_B.motorcounts + Essai2_DW.Unwrap21_Revolutions *
        Essai2_P.Unwrap21_Modulus;
      Essai2_DW.Unwrap21_PreviousInput = Essai2_B.motorcounts;
    }
  }

  /* End of RateTransition: '<S5>/Rate Transition' */

  /* Integrator: '<S2>/Integrator1' */
  if (Essai2_DW.Integrator1_IWORK != 0) {
    Essai2_X.Integrator1_CSTATE_g = Essai2_B.Unwrap21;
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<S2>/Constant'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator2'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  Essai2_B.Product = ((Essai2_B.Unwrap21 - Essai2_X.Integrator1_CSTATE_g) -
                      Essai2_X.Integrator2_CSTATE * Essai2_P.Constant_Value_a *
                      Essai2_P.Constant5_Value) * Essai2_P.Constant1_Value;

  /* Integrator: '<S3>/Integrator1' */
  if (Essai2_DW.Integrator1_IWORK_m != 0) {
    Essai2_X.Integrator1_CSTATE_h = Essai2_B.HILRead1_o3;
  }

  /* Integrator: '<S3>/Integrator1' */
  Essai2_B.Integrator1_l = Essai2_X.Integrator1_CSTATE_h;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   *  Constant: '<S3>/Constant'
   *  Integrator: '<S3>/Integrator2'
   *  Product: '<S3>/Product2'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   */
  Essai2_B.Product_b = ((Essai2_B.HILRead1_o3 - Essai2_B.Integrator1_l) -
                        Essai2_X.Integrator2_CSTATE_g *
                        Essai2_P.Constant_Value_n * Essai2_P.Constant7_Value) *
    Essai2_P.Constant8_Value;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Integrator: '<S3>/Integrator2'
   */
  Essai2_B.Product1_f = Essai2_P.Constant8_Value * Essai2_X.Integrator2_CSTATE_g;

  /* Product: '<S6>/Product2' incorporates:
   *  Gain: '<S6>/1//L'
   */
  Essai2_B.psidotrads = 1.0 / Essai2_P.vehicle_length * Essai2_B.Offset *
    Essai2_B.ProportionalGain;

  /* Gain: '<S6>/Gain' */
  rtb_commandsaturation1 = Essai2_P.vehicle_length / 2.0 * Essai2_B.psidotrads;

  /* Trigonometry: '<S6>/Trigonometric Function1' */
  rtb_sinpsi = sin(Essai2_B.psi_headingrad);

  /* Trigonometry: '<S6>/Trigonometric Function' */
  rtb_cospsi = cos(Essai2_B.psi_headingrad);

  /* Sum: '<S6>/Sum' incorporates:
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product3'
   */
  Essai2_B.v_Xms = Essai2_B.Offset * rtb_cospsi - rtb_commandsaturation1 *
    rtb_sinpsi;

  /* Sum: '<S6>/Sum1' incorporates:
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product4'
   */
  Essai2_B.v_Yms = Essai2_B.Offset * rtb_sinpsi + rtb_commandsaturation1 *
    rtb_cospsi;
}

/* Model update function for TID0 */
void Essai2_update0(void)              /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S2>/Integrator1' */
  Essai2_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S3>/Integrator1' */
  Essai2_DW.Integrator1_IWORK_m = 0;
  if (rtmIsMajorTimeStep(Essai2_M)) {
    rt_ertODEUpdateContinuousStates(&Essai2_M->solverInfo);
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
  if (!(++Essai2_M->Timing.clockTick0)) {
    ++Essai2_M->Timing.clockTickH0;
  }

  Essai2_M->Timing.t[0] = rtsiGetSolverStopTime(&Essai2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Essai2_M->Timing.clockTick1)) {
    ++Essai2_M->Timing.clockTickH1;
  }

  Essai2_M->Timing.t[1] = Essai2_M->Timing.clockTick1 *
    Essai2_M->Timing.stepSize1 + Essai2_M->Timing.clockTickH1 *
    Essai2_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Essai2_derivatives(void)
{
  XDot_Essai2_T *_rtXdot;
  _rtXdot = ((XDot_Essai2_T *) Essai2_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Essai2_B.Product;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Essai2_B.Integrator1_l;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = Essai2_B.v_Xms;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Essai2_B.v_Yms;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_p = Essai2_B.psidotrads;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g = Essai2_B.Product1;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h = Essai2_B.Product1_f;

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_g = Essai2_B.Product_b;
}

/* Model output function for TID2 */
void Essai2_output2(void)              /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void Essai2_update2(void)              /* Sample time: [0.1s, 0.0s] */
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
  if (!(++Essai2_M->Timing.clockTick2)) {
    ++Essai2_M->Timing.clockTickH2;
  }

  Essai2_M->Timing.t[2] = Essai2_M->Timing.clockTick2 *
    Essai2_M->Timing.stepSize2 + Essai2_M->Timing.clockTickH2 *
    Essai2_M->Timing.stepSize2 * 4294967296.0;
}

/* Model wrapper function for compatibility with a static main program */
void Essai2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Essai2_output0();
    break;

   case 2 :
    Essai2_output2();
    break;

   default :
    break;
  }
}

/* Model wrapper function for compatibility with a static main program */
void Essai2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Essai2_update0();
    break;

   case 2 :
    Essai2_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Essai2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize2' */

  /* S-Function Block: Essai2/HIL Initialize2 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Essai2_DW.HILInitialize2_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Essai2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Essai2_DW.HILInitialize2_Card,
      "gyro_fs=125;gyro_rate=47;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
      251);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Essai2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Essai2_DW.HILInitialize2_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Essai2_M, _rt_error_message);
      return;
    }

    if ((Essai2_P.HILInitialize2_AIPStart && !is_switching) ||
        (Essai2_P.HILInitialize2_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Essai2_DW.HILInitialize2_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Essai2_P.HILInitialize2_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Essai2_DW.HILInitialize2_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Essai2_P.HILInitialize2_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_AIChannels, 7U,
        &Essai2_DW.HILInitialize2_AIMinimums[0],
        &Essai2_DW.HILInitialize2_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Essai2_DW.HILInitialize2_Card,
      Essai2_P.HILInitialize2_DIChannels, 20U,
      &Essai2_P.HILInitialize2_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Essai2_M, _rt_error_message);
      return;
    }

    if ((Essai2_P.HILInitialize2_DOStart && !is_switching) ||
        (Essai2_P.HILInitialize2_DOEnter && is_switching)) {
      result = hil_write_digital(Essai2_DW.HILInitialize2_Card,
        &Essai2_P.HILInitialize2_DOChannels, 1U, (t_boolean *)
        &Essai2_P.HILInitialize2_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    if ((Essai2_P.HILInitialize2_EIPStart && !is_switching) ||
        (Essai2_P.HILInitialize2_EIPEnter && is_switching)) {
      Essai2_DW.HILInitialize2_QuadratureModes[0] =
        (Essai2_P.HILInitialize2_EIQuadrature[0]);
      Essai2_DW.HILInitialize2_QuadratureModes[1] =
        (Essai2_P.HILInitialize2_EIQuadrature[1]);
      Essai2_DW.HILInitialize2_QuadratureModes[2] =
        (Essai2_P.HILInitialize2_EIQuadrature[1]);
      Essai2_DW.HILInitialize2_QuadratureModes[3] =
        (Essai2_P.HILInitialize2_EIQuadrature[1]);
      Essai2_DW.HILInitialize2_QuadratureModes[4] =
        (Essai2_P.HILInitialize2_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_EIChannels, 5U, (t_encoder_quadrature_mode *)
        &Essai2_DW.HILInitialize2_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency = &Essai2_DW.HILInitialize2_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] = Essai2_P.HILInitialize2_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_EIChannels, 5U,
        &Essai2_DW.HILInitialize2_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    if ((Essai2_P.HILInitialize2_EIStart && !is_switching) ||
        (Essai2_P.HILInitialize2_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &Essai2_DW.HILInitialize2_InitialEICounts
          [0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = Essai2_P.HILInitialize2_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_EIChannels, 5U,
        &Essai2_DW.HILInitialize2_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    if ((Essai2_P.HILInitialize2_POPStart && !is_switching) ||
        (Essai2_P.HILInitialize2_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      Essai2_DW.HILInitialize2_POModeValues[0] =
        (Essai2_P.HILInitialize2_POModes[0]);

      {
        int_T i1;
        int32_T *dw_POModeValues = &Essai2_DW.HILInitialize2_POModeValues[1];
        for (i1=0; i1 < 7; i1++) {
          dw_POModeValues[i1] = (Essai2_P.HILInitialize2_POModes[1]);
        }
      }

      result = hil_set_pwm_mode(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_POChannels, 8U, (t_pwm_mode *)
        &Essai2_DW.HILInitialize2_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize2_POChannels =
          Essai2_P.HILInitialize2_POChannels;
        int32_T *dw_POModeValues = &Essai2_DW.HILInitialize2_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Essai2_DW.HILInitialize2_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize2_POChannels[i1]);
            Essai2_DW.HILInitialize2_POSortedFreqs[num_duty_cycle_modes] =
              Essai2_P.HILInitialize2_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Essai2_DW.HILInitialize2_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize2_POChannels[i1]);
            Essai2_DW.HILInitialize2_POSortedFreqs[7U - num_frequency_modes] =
              Essai2_P.HILInitialize2_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Essai2_DW.HILInitialize2_Card,
          &Essai2_DW.HILInitialize2_POSortedChans[0], num_duty_cycle_modes,
          &Essai2_DW.HILInitialize2_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Essai2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Essai2_DW.HILInitialize2_Card,
          &Essai2_DW.HILInitialize2_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Essai2_DW.HILInitialize2_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Essai2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Essai2_DW.HILInitialize2_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Essai2_P.HILInitialize2_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &Essai2_DW.HILInitialize2_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Essai2_P.HILInitialize2_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &Essai2_DW.HILInitialize2_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Essai2_P.HILInitialize2_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_POChannels, 8U,
        (t_pwm_configuration *) &Essai2_DW.HILInitialize2_POModeValues[0],
        (t_pwm_alignment *) &Essai2_DW.HILInitialize2_POAlignValues[0],
        (t_pwm_polarity *) &Essai2_DW.HILInitialize2_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    if ((Essai2_P.HILInitialize2_POStart && !is_switching) ||
        (Essai2_P.HILInitialize2_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Essai2_DW.HILInitialize2_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Essai2_P.HILInitialize2_POInitial;
        }
      }

      result = hil_write_pwm(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_POChannels, 8U,
        &Essai2_DW.HILInitialize2_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    if (Essai2_P.HILInitialize2_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Essai2_DW.HILInitialize2_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Essai2_P.HILInitialize2_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Essai2_DW.HILInitialize2_Card, Essai2_P.HILInitialize2_POChannels, 8U,
         &Essai2_DW.HILInitialize2_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }

    if ((Essai2_P.HILInitialize2_OOStart && !is_switching) ||
        (Essai2_P.HILInitialize2_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Essai2_DW.HILInitialize2_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Essai2_P.HILInitialize2_OOInitial;
        }
      }

      result = hil_write_other(Essai2_DW.HILInitialize2_Card,
        Essai2_P.HILInitialize2_OOChannels, 13U,
        &Essai2_DW.HILInitialize2_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Essai2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Unwrap 2^1' */

  /* S-Function Block: Essai2/Unwrap 2^1 (inverse_modulus_block) */
  {
    Essai2_DW.Unwrap21_FirstSample = true;
    Essai2_DW.Unwrap21_Revolutions = 0;
  }

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  Essai2_X.Integrator2_CSTATE = Essai2_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Essai2_X.Integrator_CSTATE = Essai2_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Essai2_X.Integrator_CSTATE_f = Essai2_P.X_ic;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  Essai2_X.Integrator1_CSTATE = Essai2_P.Y_ic;

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  Essai2_X.Integrator2_CSTATE_p = Essai2_P.yaw_ic;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' incorporates:
   *  Integrator: '<S3>/Integrator1'
   */
  if (rtmIsFirstInitCond(Essai2_M)) {
    Essai2_X.Integrator1_CSTATE_g = 0.0;
    Essai2_X.Integrator1_CSTATE_h = 0.0;
  }

  Essai2_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S2>/Integrator1' */

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  Essai2_DW.Integrator1_IWORK_m = 1;

  /* InitializeConditions for Integrator: '<S3>/Integrator2' */
  Essai2_X.Integrator2_CSTATE_g = Essai2_P.Integrator2_IC_f;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Essai2_M)) {
    rtmSetFirstInitCond(Essai2_M, 0);
  }
}

/* Model terminate function */
void Essai2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize2' */

  /* S-Function Block: Essai2/HIL Initialize2 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Essai2_DW.HILInitialize2_Card);
    hil_monitor_stop_all(Essai2_DW.HILInitialize2_Card);
    is_switching = false;
    if ((Essai2_P.HILInitialize2_DOTerminate && !is_switching) ||
        (Essai2_P.HILInitialize2_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Essai2_P.HILInitialize2_POTerminate && !is_switching) ||
        (Essai2_P.HILInitialize2_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Essai2_DW.HILInitialize2_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Essai2_P.HILInitialize2_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Essai2_P.HILInitialize2_OOTerminate && !is_switching) ||
        (Essai2_P.HILInitialize2_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Essai2_DW.HILInitialize2_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Essai2_P.HILInitialize2_OOFinal;
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
      result = hil_write(Essai2_DW.HILInitialize2_Card
                         , NULL, 0
                         , Essai2_P.HILInitialize2_POChannels,
                         num_final_pwm_outputs
                         , &Essai2_P.HILInitialize2_DOChannels,
                         num_final_digital_outputs
                         , Essai2_P.HILInitialize2_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Essai2_DW.HILInitialize2_POValues[0]
                         , (t_boolean *) &Essai2_P.HILInitialize2_DOFinal
                         , &Essai2_DW.HILInitialize2_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Essai2_DW.HILInitialize2_Card,
            Essai2_P.HILInitialize2_POChannels, num_final_pwm_outputs,
            &Essai2_DW.HILInitialize2_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Essai2_DW.HILInitialize2_Card,
            &Essai2_P.HILInitialize2_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Essai2_P.HILInitialize2_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Essai2_DW.HILInitialize2_Card,
            Essai2_P.HILInitialize2_OOChannels, num_final_other_outputs,
            &Essai2_DW.HILInitialize2_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Essai2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Essai2_DW.HILInitialize2_Card);
    hil_monitor_delete_all(Essai2_DW.HILInitialize2_Card);
    hil_close(Essai2_DW.HILInitialize2_Card);
    Essai2_DW.HILInitialize2_Card = NULL;
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
  Essai2_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Essai2_update(tid);
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
  Essai2_initialize();
}

void MdlTerminate(void)
{
  Essai2_terminate();
}

/* Registration function */
RT_MODEL_Essai2_T *Essai2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Essai2_M, 0,
                sizeof(RT_MODEL_Essai2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Essai2_M->solverInfo, &Essai2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Essai2_M->solverInfo, &rtmGetTPtr(Essai2_M));
    rtsiSetStepSizePtr(&Essai2_M->solverInfo, &Essai2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Essai2_M->solverInfo, &Essai2_M->derivs);
    rtsiSetContStatesPtr(&Essai2_M->solverInfo, (real_T **)
                         &Essai2_M->contStates);
    rtsiSetNumContStatesPtr(&Essai2_M->solverInfo,
      &Essai2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Essai2_M->solverInfo,
      &Essai2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Essai2_M->solverInfo,
      &Essai2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Essai2_M->solverInfo,
      &Essai2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Essai2_M->solverInfo, (&rtmGetErrorStatus(Essai2_M)));
    rtsiSetRTModelPtr(&Essai2_M->solverInfo, Essai2_M);
  }

  rtsiSetSimTimeStep(&Essai2_M->solverInfo, MAJOR_TIME_STEP);
  Essai2_M->intgData.f[0] = Essai2_M->odeF[0];
  Essai2_M->contStates = ((real_T *) &Essai2_X);
  rtsiSetSolverData(&Essai2_M->solverInfo, (void *)&Essai2_M->intgData);
  rtsiSetSolverName(&Essai2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Essai2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Essai2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Essai2_M->Timing.sampleTimes = (&Essai2_M->Timing.sampleTimesArray[0]);
    Essai2_M->Timing.offsetTimes = (&Essai2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Essai2_M->Timing.sampleTimes[0] = (0.0);
    Essai2_M->Timing.sampleTimes[1] = (0.033333333333333333);
    Essai2_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    Essai2_M->Timing.offsetTimes[0] = (0.0);
    Essai2_M->Timing.offsetTimes[1] = (0.0);
    Essai2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Essai2_M, &Essai2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Essai2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Essai2_M->Timing.perTaskSampleHitsArray;
    Essai2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Essai2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Essai2_M, -1);
  Essai2_M->Timing.stepSize0 = 0.033333333333333333;
  Essai2_M->Timing.stepSize1 = 0.033333333333333333;
  Essai2_M->Timing.stepSize2 = 0.1;
  rtmSetFirstInitCond(Essai2_M, 1);

  /* External mode info */
  Essai2_M->Sizes.checksums[0] = (1809551046U);
  Essai2_M->Sizes.checksums[1] = (1287788468U);
  Essai2_M->Sizes.checksums[2] = (268289483U);
  Essai2_M->Sizes.checksums[3] = (3368718399U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Essai2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Essai2_M->extModeInfo,
      &Essai2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Essai2_M->extModeInfo, Essai2_M->Sizes.checksums);
    rteiSetTPtr(Essai2_M->extModeInfo, rtmGetTPtr(Essai2_M));
  }

  Essai2_M->solverInfoPtr = (&Essai2_M->solverInfo);
  Essai2_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Essai2_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&Essai2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Essai2_M->blockIO = ((void *) &Essai2_B);
  (void) memset(((void *) &Essai2_B), 0,
                sizeof(B_Essai2_T));

  /* parameters */
  Essai2_M->defaultParam = ((real_T *)&Essai2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Essai2_X;
    Essai2_M->contStates = (x);
    (void) memset((void *)&Essai2_X, 0,
                  sizeof(X_Essai2_T));
  }

  /* states (dwork) */
  Essai2_M->dwork = ((void *) &Essai2_DW);
  (void) memset((void *)&Essai2_DW, 0,
                sizeof(DW_Essai2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Essai2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Essai2_M->Sizes.numContStates = (8); /* Number of continuous states */
  Essai2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Essai2_M->Sizes.numY = (0);          /* Number of model outputs */
  Essai2_M->Sizes.numU = (0);          /* Number of model inputs */
  Essai2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Essai2_M->Sizes.numSampTimes = (3);  /* Number of sample times */
  Essai2_M->Sizes.numBlocks = (61);    /* Number of blocks */
  Essai2_M->Sizes.numBlockIO = (20);   /* Number of block outputs */
  Essai2_M->Sizes.numBlockPrms = (143);/* Sum of parameter "widths" */
  return Essai2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
