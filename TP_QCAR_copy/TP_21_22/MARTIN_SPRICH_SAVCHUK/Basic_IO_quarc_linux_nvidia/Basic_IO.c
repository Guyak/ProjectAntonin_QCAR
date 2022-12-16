/*
 * Basic_IO.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Basic_IO".
 *
 * Model version              : 4.3
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 08:28:56 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Basic_IO.h"
#include "Basic_IO_private.h"
#include "Basic_IO_dt.h"

/* Block signals (default storage) */
B_Basic_IO_T Basic_IO_B;

/* Continuous states */
X_Basic_IO_T Basic_IO_X;

/* Block states (default storage) */
DW_Basic_IO_T Basic_IO_DW;

/* Real-time model */
static RT_MODEL_Basic_IO_T Basic_IO_M_;
RT_MODEL_Basic_IO_T *const Basic_IO_M = &Basic_IO_M_;

/*
 * This function updates continuous states using the ODE2 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE2_IntgData *id = (ODE2_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T temp;
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Basic_IO_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  Basic_IO_output();
  Basic_IO_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Basic_IO_output(void)
{
  real_T rtb_TmpSignalConversionAtHILWri[9];
  real_T rtb_commandsaturation;
  if (rtmIsMajorTimeStep(Basic_IO_M)) {
    /* set solver stop time */
    if (!(Basic_IO_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Basic_IO_M->solverInfo,
                            ((Basic_IO_M->Timing.clockTickH0 + 1) *
        Basic_IO_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Basic_IO_M->solverInfo,
                            ((Basic_IO_M->Timing.clockTick0 + 1) *
        Basic_IO_M->Timing.stepSize0 + Basic_IO_M->Timing.clockTickH0 *
        Basic_IO_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Basic_IO_M)) {
    Basic_IO_M->Timing.t[0] = rtsiGetT(&Basic_IO_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Basic_IO_M)) {
    /* S-Function (hil_read_block): '<S5>/HIL Read' */

    /* S-Function Block: Basic_IO/basicQCarIO/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(Basic_IO_DW.HILInitialize_Card,
        Basic_IO_P.HILRead_analog_channels, 2U,
        &Basic_IO_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &Basic_IO_DW.HILRead_AnalogBuffer[0],
        &Basic_IO_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
      } else {
        Basic_IO_B.motorcurrent = Basic_IO_DW.HILRead_AnalogBuffer[0];
        Basic_IO_B.batteryvoltage = Basic_IO_DW.HILRead_AnalogBuffer[1];
        Basic_IO_B.encodercounts = Basic_IO_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S5>/Unwrap 2^24' */
    /* S-Function Block: Basic_IO/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = Basic_IO_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Basic_IO_DW.Unwrap224_FirstSample) {
        Basic_IO_DW.Unwrap224_FirstSample = false;
        Basic_IO_DW.Unwrap224_PreviousInput = Basic_IO_B.encodercounts;
      }

      du = (real_T) Basic_IO_B.encodercounts -
        Basic_IO_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Basic_IO_DW.Unwrap224_Revolutions = Basic_IO_DW.Unwrap224_Revolutions -
          1;
        dy = du - Basic_IO_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Basic_IO_DW.Unwrap224_Revolutions = Basic_IO_DW.Unwrap224_Revolutions +
          1;
        dy = du + Basic_IO_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Basic_IO_B.Unwrap224 = Basic_IO_B.encodercounts +
        Basic_IO_DW.Unwrap224_Revolutions * Basic_IO_P.Unwrap224_Modulus;
      Basic_IO_DW.Unwrap224_PreviousInput = Basic_IO_B.encodercounts;
    }
  }

  /* Integrator: '<S6>/Integrator1' */
  if (Basic_IO_DW.Integrator1_IWORK != 0) {
    Basic_IO_X.Integrator1_CSTATE = Basic_IO_B.Unwrap224;
  }

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S6>/Constant'
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S6>/Integrator2'
   *  Product: '<S6>/Product2'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   */
  Basic_IO_B.Product = ((Basic_IO_B.Unwrap224 - Basic_IO_X.Integrator1_CSTATE) -
                        Basic_IO_X.Integrator2_CSTATE *
                        Basic_IO_P.Constant_Value * Basic_IO_P.Constant1_Value) *
    Basic_IO_P.Constant2_Value;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Integrator: '<S6>/Integrator2'
   */
  Basic_IO_B.Product1 = Basic_IO_P.Constant2_Value *
    Basic_IO_X.Integrator2_CSTATE;

  /* Integrator: '<S7>/Integrator1' */
  if (Basic_IO_DW.Integrator1_IWORK_d != 0) {
    Basic_IO_X.Integrator1_CSTATE_a = Basic_IO_B.batteryvoltage;
  }

  /* Integrator: '<S7>/Integrator1' */
  Basic_IO_B.Integrator1 = Basic_IO_X.Integrator1_CSTATE_a;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S7>/Constant'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product2'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  Basic_IO_B.Product_h = ((Basic_IO_B.batteryvoltage - Basic_IO_B.Integrator1) -
    Basic_IO_X.Integrator2_CSTATE_c * Basic_IO_P.Constant_Value_b *
    Basic_IO_P.Constant3_Value) * Basic_IO_P.Constant4_Value;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S5>/Constant4'
   *  Integrator: '<S7>/Integrator2'
   */
  Basic_IO_B.Product1_e = Basic_IO_P.Constant4_Value *
    Basic_IO_X.Integrator2_CSTATE_c;

  /* Integrator: '<S8>/Integrator1' */
  if (Basic_IO_DW.Integrator1_IWORK_c != 0) {
    Basic_IO_X.Integrator1_CSTATE_e = Basic_IO_B.motorcurrent;
  }

  /* Integrator: '<S8>/Integrator1' */
  Basic_IO_B.Integrator1_o = Basic_IO_X.Integrator1_CSTATE_e;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S5>/Constant6'
   *  Constant: '<S8>/Constant'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S8>/Sum1'
   */
  Basic_IO_B.Product_j = ((Basic_IO_B.motorcurrent - Basic_IO_B.Integrator1_o) -
    Basic_IO_X.Integrator2_CSTATE_a * Basic_IO_P.Constant_Value_bi *
    Basic_IO_P.Constant5_Value) * Basic_IO_P.Constant6_Value;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Integrator: '<S8>/Integrator2'
   */
  Basic_IO_B.Product1_m = Basic_IO_P.Constant6_Value *
    Basic_IO_X.Integrator2_CSTATE_a;
  if (rtmIsMajorTimeStep(Basic_IO_M)) {
    /* Gain: '<S5>/direction convention' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Gain: '<S4>/Slider Gain'
     */
    rtb_commandsaturation = Basic_IO_P.Throttle02to02_gain *
      Basic_IO_P.Constant1_Value_k * Basic_IO_P.directionconvention_Gain;

    /* Saturate: '<S5>/command saturation' */
    if (rtb_commandsaturation > Basic_IO_P.commandsaturation_UpperSat) {
      rtb_commandsaturation = Basic_IO_P.commandsaturation_UpperSat;
    } else if (rtb_commandsaturation < Basic_IO_P.commandsaturation_LowerSat) {
      rtb_commandsaturation = Basic_IO_P.commandsaturation_LowerSat;
    }

    /* End of Saturate: '<S5>/command saturation' */

    /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
     *  Bias: '<S5>/Steering Bias'
     *  Constant: '<Root>/Constant1'
     *  Gain: '<S3>/Slider Gain'
     *  Gain: '<S5>/Gain'
     */
    rtb_TmpSignalConversionAtHILWri[0] = Basic_IO_P.Steeringrad05to05_gain *
      Basic_IO_P.Constant1_Value_k * Basic_IO_P.Gain_Gain +
      Basic_IO_P.SteeringBias_Bias;

    /* ManualSwitch: '<Root>/Manual Switch' */
    if (Basic_IO_P.ManualSwitch_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[1] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[1] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* ManualSwitch: '<Root>/Manual Switch1' */
    if (Basic_IO_P.ManualSwitch1_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[2] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[2] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */

    /* ManualSwitch: '<Root>/Manual Switch2' */
    if (Basic_IO_P.ManualSwitch2_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[3] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[3] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* ManualSwitch: '<Root>/Manual Switch3' */
    if (Basic_IO_P.ManualSwitch3_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[4] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[4] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */

    /* ManualSwitch: '<Root>/Manual Switch4' */
    if (Basic_IO_P.ManualSwitch4_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[5] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[5] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch4' */

    /* ManualSwitch: '<Root>/Manual Switch5' */
    if (Basic_IO_P.ManualSwitch5_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[6] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[6] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch5' */

    /* ManualSwitch: '<Root>/Manual Switch6' */
    if (Basic_IO_P.ManualSwitch6_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[7] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[7] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch6' */

    /* ManualSwitch: '<Root>/Manual Switch7' */
    if (Basic_IO_P.ManualSwitch7_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[8] = Basic_IO_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S5>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[8] = Basic_IO_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch7' */

    /* S-Function (hil_write_block): '<S5>/HIL Write' incorporates:
     *  Constant: '<S5>/coast ON'
     */

    /* S-Function Block: Basic_IO/basicQCarIO/HIL Write (hil_write_block) */
    {
      t_error result;
      Basic_IO_DW.HILWrite_DigitalBuffer = (Basic_IO_P.coastON_Value != 0);
      result = hil_write(Basic_IO_DW.HILInitialize_Card,
                         NULL, 0U,
                         &Basic_IO_P.HILWrite_pwm_channels, 1U,
                         &Basic_IO_P.HILWrite_digital_channels, 1U,
                         Basic_IO_P.HILWrite_other_channels, 9U,
                         NULL,
                         &rtb_commandsaturation,
                         &Basic_IO_DW.HILWrite_DigitalBuffer,
                         &rtb_TmpSignalConversionAtHILWri[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void Basic_IO_update(void)
{
  /* Update for Integrator: '<S6>/Integrator1' */
  Basic_IO_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S7>/Integrator1' */
  Basic_IO_DW.Integrator1_IWORK_d = 0;

  /* Update for Integrator: '<S8>/Integrator1' */
  Basic_IO_DW.Integrator1_IWORK_c = 0;
  if (rtmIsMajorTimeStep(Basic_IO_M)) {
    rt_ertODEUpdateContinuousStates(&Basic_IO_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Basic_IO_M->Timing.clockTick0)) {
    ++Basic_IO_M->Timing.clockTickH0;
  }

  Basic_IO_M->Timing.t[0] = rtsiGetSolverStopTime(&Basic_IO_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Basic_IO_M->Timing.clockTick1)) {
      ++Basic_IO_M->Timing.clockTickH1;
    }

    Basic_IO_M->Timing.t[1] = Basic_IO_M->Timing.clockTick1 *
      Basic_IO_M->Timing.stepSize1 + Basic_IO_M->Timing.clockTickH1 *
      Basic_IO_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Basic_IO_derivatives(void)
{
  XDot_Basic_IO_T *_rtXdot;
  _rtXdot = ((XDot_Basic_IO_T *) Basic_IO_M->derivs);

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Basic_IO_B.Product1;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Basic_IO_B.Product;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_a = Basic_IO_B.Product1_e;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c = Basic_IO_B.Product_h;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = Basic_IO_B.Product1_m;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = Basic_IO_B.Product_j;
}

/* Model initialize function */
void Basic_IO_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: Basic_IO/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Basic_IO_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Basic_IO_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
      return;
    }

    if ((Basic_IO_P.HILInitialize_AIPStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Basic_IO_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Basic_IO_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Basic_IO_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Basic_IO_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Basic_IO_DW.HILInitialize_Card,
        Basic_IO_P.HILInitialize_AIChannels, 7U,
        &Basic_IO_DW.HILInitialize_AIMinimums[0],
        &Basic_IO_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Basic_IO_DW.HILInitialize_Card,
      Basic_IO_P.HILInitialize_DIChannels, 19U,
      &Basic_IO_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
      return;
    }

    if ((Basic_IO_P.HILInitialize_DOStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Basic_IO_DW.HILInitialize_Card,
        &Basic_IO_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Basic_IO_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    if ((Basic_IO_P.HILInitialize_EIPStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_EIPEnter && is_switching)) {
      Basic_IO_DW.HILInitialize_QuadratureModes[0] =
        (Basic_IO_P.HILInitialize_EIQuadrature[0]);
      Basic_IO_DW.HILInitialize_QuadratureModes[1] =
        (Basic_IO_P.HILInitialize_EIQuadrature[1]);
      Basic_IO_DW.HILInitialize_QuadratureModes[2] =
        (Basic_IO_P.HILInitialize_EIQuadrature[1]);
      Basic_IO_DW.HILInitialize_QuadratureModes[3] =
        (Basic_IO_P.HILInitialize_EIQuadrature[1]);
      Basic_IO_DW.HILInitialize_QuadratureModes[4] =
        (Basic_IO_P.HILInitialize_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode(Basic_IO_DW.HILInitialize_Card,
        Basic_IO_P.HILInitialize_EIChannels, 5U, (t_encoder_quadrature_mode *)
        &Basic_IO_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency = &Basic_IO_DW.HILInitialize_FilterFrequency
          [0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] = Basic_IO_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency(Basic_IO_DW.HILInitialize_Card,
        Basic_IO_P.HILInitialize_EIChannels, 5U,
        &Basic_IO_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    if ((Basic_IO_P.HILInitialize_EIStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Basic_IO_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = Basic_IO_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Basic_IO_DW.HILInitialize_Card,
        Basic_IO_P.HILInitialize_EIChannels, 5U,
        &Basic_IO_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    if ((Basic_IO_P.HILInitialize_POPStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(Basic_IO_DW.HILInitialize_Card,
        &Basic_IO_P.HILInitialize_POChannels, 1U, (t_pwm_mode *)
        Basic_IO_P.HILInitialize_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }

      if ((Basic_IO_P.HILInitialize_POModes[0]) == PWM_DUTY_CYCLE_MODE ||
          (Basic_IO_P.HILInitialize_POModes[0]) == PWM_ONE_SHOT_MODE ||
          (Basic_IO_P.HILInitialize_POModes[0]) == PWM_TIME_MODE ||
          (Basic_IO_P.HILInitialize_POModes[0]) == PWM_RAW_MODE) {
        Basic_IO_DW.HILInitialize_POSortedChans =
          Basic_IO_P.HILInitialize_POChannels;
        Basic_IO_DW.HILInitialize_POSortedFreqs =
          Basic_IO_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        Basic_IO_DW.HILInitialize_POSortedChans =
          Basic_IO_P.HILInitialize_POChannels;
        Basic_IO_DW.HILInitialize_POSortedFreqs =
          Basic_IO_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Basic_IO_DW.HILInitialize_Card,
          &Basic_IO_DW.HILInitialize_POSortedChans, num_duty_cycle_modes,
          &Basic_IO_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Basic_IO_DW.HILInitialize_Card,
          &Basic_IO_DW.HILInitialize_POSortedChans, num_frequency_modes,
          &Basic_IO_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration(Basic_IO_DW.HILInitialize_Card,
        &Basic_IO_P.HILInitialize_POChannels, 1U,
        (t_pwm_configuration *) &Basic_IO_P.HILInitialize_POConfiguration,
        (t_pwm_alignment *) &Basic_IO_P.HILInitialize_POAlignment,
        (t_pwm_polarity *) &Basic_IO_P.HILInitialize_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    if ((Basic_IO_P.HILInitialize_POStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_POEnter && is_switching)) {
      result = hil_write_pwm(Basic_IO_DW.HILInitialize_Card,
        &Basic_IO_P.HILInitialize_POChannels, 1U,
        &Basic_IO_P.HILInitialize_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    if (Basic_IO_P.HILInitialize_POReset) {
      result = hil_watchdog_set_pwm_expiration_state
        (Basic_IO_DW.HILInitialize_Card, &Basic_IO_P.HILInitialize_POChannels,
         1U, &Basic_IO_P.HILInitialize_POWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }

    if ((Basic_IO_P.HILInitialize_OOStart && !is_switching) ||
        (Basic_IO_P.HILInitialize_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Basic_IO_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Basic_IO_P.HILInitialize_OOInitial;
        }
      }

      result = hil_write_other(Basic_IO_DW.HILInitialize_Card,
        Basic_IO_P.HILInitialize_OOChannels, 13U,
        &Basic_IO_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S5>/Unwrap 2^24' */

  /* S-Function Block: Basic_IO/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
  {
    Basic_IO_DW.Unwrap224_FirstSample = true;
    Basic_IO_DW.Unwrap224_Revolutions = 0;
  }

  /* InitializeConditions for Integrator: '<S6>/Integrator1' incorporates:
   *  Integrator: '<S7>/Integrator1'
   */
  if (rtmIsFirstInitCond(Basic_IO_M)) {
    Basic_IO_X.Integrator1_CSTATE = 0.0;
    Basic_IO_X.Integrator1_CSTATE_a = 0.0;
  }

  Basic_IO_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S6>/Integrator1' */

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  Basic_IO_X.Integrator2_CSTATE = Basic_IO_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  Basic_IO_DW.Integrator1_IWORK_d = 1;

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  Basic_IO_X.Integrator2_CSTATE_c = Basic_IO_P.Integrator2_IC_o;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  if (rtmIsFirstInitCond(Basic_IO_M)) {
    Basic_IO_X.Integrator1_CSTATE_e = 0.0;
  }

  Basic_IO_DW.Integrator1_IWORK_c = 1;

  /* End of InitializeConditions for Integrator: '<S8>/Integrator1' */

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  Basic_IO_X.Integrator2_CSTATE_a = Basic_IO_P.Integrator2_IC_n;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Basic_IO_M)) {
    rtmSetFirstInitCond(Basic_IO_M, 0);
  }
}

/* Model terminate function */
void Basic_IO_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: Basic_IO/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Basic_IO_DW.HILInitialize_Card);
    hil_monitor_stop_all(Basic_IO_DW.HILInitialize_Card);
    is_switching = false;
    if ((Basic_IO_P.HILInitialize_DOTerminate && !is_switching) ||
        (Basic_IO_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Basic_IO_P.HILInitialize_POTerminate && !is_switching) ||
        (Basic_IO_P.HILInitialize_POExit && is_switching)) {
      num_final_pwm_outputs = 1U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Basic_IO_P.HILInitialize_OOTerminate && !is_switching) ||
        (Basic_IO_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Basic_IO_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Basic_IO_P.HILInitialize_OOFinal;
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
      result = hil_write(Basic_IO_DW.HILInitialize_Card
                         , NULL, 0
                         , &Basic_IO_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &Basic_IO_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Basic_IO_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Basic_IO_P.HILInitialize_POFinal
                         , (t_boolean *) &Basic_IO_P.HILInitialize_DOFinal
                         , &Basic_IO_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Basic_IO_DW.HILInitialize_Card,
            &Basic_IO_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Basic_IO_P.HILInitialize_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Basic_IO_DW.HILInitialize_Card,
            &Basic_IO_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Basic_IO_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Basic_IO_DW.HILInitialize_Card,
            Basic_IO_P.HILInitialize_OOChannels, num_final_other_outputs,
            &Basic_IO_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Basic_IO_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Basic_IO_DW.HILInitialize_Card);
    hil_monitor_delete_all(Basic_IO_DW.HILInitialize_Card);
    hil_close(Basic_IO_DW.HILInitialize_Card);
    Basic_IO_DW.HILInitialize_Card = NULL;
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
  Basic_IO_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Basic_IO_update();
  UNUSED_PARAMETER(tid);
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
  Basic_IO_initialize();
}

void MdlTerminate(void)
{
  Basic_IO_terminate();
}

/* Registration function */
RT_MODEL_Basic_IO_T *Basic_IO(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Basic_IO_M, 0,
                sizeof(RT_MODEL_Basic_IO_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Basic_IO_M->solverInfo,
                          &Basic_IO_M->Timing.simTimeStep);
    rtsiSetTPtr(&Basic_IO_M->solverInfo, &rtmGetTPtr(Basic_IO_M));
    rtsiSetStepSizePtr(&Basic_IO_M->solverInfo, &Basic_IO_M->Timing.stepSize0);
    rtsiSetdXPtr(&Basic_IO_M->solverInfo, &Basic_IO_M->derivs);
    rtsiSetContStatesPtr(&Basic_IO_M->solverInfo, (real_T **)
                         &Basic_IO_M->contStates);
    rtsiSetNumContStatesPtr(&Basic_IO_M->solverInfo,
      &Basic_IO_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Basic_IO_M->solverInfo,
      &Basic_IO_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Basic_IO_M->solverInfo,
      &Basic_IO_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Basic_IO_M->solverInfo,
      &Basic_IO_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Basic_IO_M->solverInfo, (&rtmGetErrorStatus
      (Basic_IO_M)));
    rtsiSetRTModelPtr(&Basic_IO_M->solverInfo, Basic_IO_M);
  }

  rtsiSetSimTimeStep(&Basic_IO_M->solverInfo, MAJOR_TIME_STEP);
  Basic_IO_M->intgData.y = Basic_IO_M->odeY;
  Basic_IO_M->intgData.f[0] = Basic_IO_M->odeF[0];
  Basic_IO_M->intgData.f[1] = Basic_IO_M->odeF[1];
  Basic_IO_M->contStates = ((real_T *) &Basic_IO_X);
  rtsiSetSolverData(&Basic_IO_M->solverInfo, (void *)&Basic_IO_M->intgData);
  rtsiSetSolverName(&Basic_IO_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Basic_IO_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Basic_IO_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Basic_IO_M->Timing.sampleTimes = (&Basic_IO_M->Timing.sampleTimesArray[0]);
    Basic_IO_M->Timing.offsetTimes = (&Basic_IO_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Basic_IO_M->Timing.sampleTimes[0] = (0.0);
    Basic_IO_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Basic_IO_M->Timing.offsetTimes[0] = (0.0);
    Basic_IO_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Basic_IO_M, &Basic_IO_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Basic_IO_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Basic_IO_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Basic_IO_M, -1);
  Basic_IO_M->Timing.stepSize0 = 0.002;
  Basic_IO_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(Basic_IO_M, 1);

  /* External mode info */
  Basic_IO_M->Sizes.checksums[0] = (3740935406U);
  Basic_IO_M->Sizes.checksums[1] = (211609550U);
  Basic_IO_M->Sizes.checksums[2] = (2334164827U);
  Basic_IO_M->Sizes.checksums[3] = (594665250U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Basic_IO_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Basic_IO_M->extModeInfo,
      &Basic_IO_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Basic_IO_M->extModeInfo, Basic_IO_M->Sizes.checksums);
    rteiSetTPtr(Basic_IO_M->extModeInfo, rtmGetTPtr(Basic_IO_M));
  }

  Basic_IO_M->solverInfoPtr = (&Basic_IO_M->solverInfo);
  Basic_IO_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Basic_IO_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Basic_IO_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Basic_IO_M->blockIO = ((void *) &Basic_IO_B);
  (void) memset(((void *) &Basic_IO_B), 0,
                sizeof(B_Basic_IO_T));

  /* parameters */
  Basic_IO_M->defaultParam = ((real_T *)&Basic_IO_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Basic_IO_X;
    Basic_IO_M->contStates = (x);
    (void) memset((void *)&Basic_IO_X, 0,
                  sizeof(X_Basic_IO_T));
  }

  /* states (dwork) */
  Basic_IO_M->dwork = ((void *) &Basic_IO_DW);
  (void) memset((void *)&Basic_IO_DW, 0,
                sizeof(DW_Basic_IO_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Basic_IO_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Basic_IO_M->Sizes.numContStates = (6);/* Number of continuous states */
  Basic_IO_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Basic_IO_M->Sizes.numY = (0);        /* Number of model outputs */
  Basic_IO_M->Sizes.numU = (0);        /* Number of model inputs */
  Basic_IO_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Basic_IO_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Basic_IO_M->Sizes.numBlocks = (56);  /* Number of blocks */
  Basic_IO_M->Sizes.numBlockIO = (12); /* Number of block outputs */
  Basic_IO_M->Sizes.numBlockPrms = (150);/* Sum of parameter "widths" */
  return Basic_IO_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
