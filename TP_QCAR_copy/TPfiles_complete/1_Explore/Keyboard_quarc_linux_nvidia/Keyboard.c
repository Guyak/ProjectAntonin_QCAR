/*
 * Keyboard.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Keyboard".
 *
 * Model version              : 4.18
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Oct 17 10:27:57 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Keyboard.h"
#include "Keyboard_private.h"
#include "Keyboard_dt.h"

/* Block signals (default storage) */
B_Keyboard_T Keyboard_B;

/* Continuous states */
X_Keyboard_T Keyboard_X;

/* Block states (default storage) */
DW_Keyboard_T Keyboard_DW;

/* Real-time model */
static RT_MODEL_Keyboard_T Keyboard_M_;
RT_MODEL_Keyboard_T *const Keyboard_M = &Keyboard_M_;
static t_error host_connect_Host0x2D1(t_host_remote_interface host, void
  * context)
{
  /* S-Function Block: Keyboard/Host Keyboard (host_keyboard_block) */
  {
    if (Keyboard_P.HostKeyboard_Enabled) {
      struct __attribute__ ((__packed__)) tag_keyboard_configuration {
        t_host_command_header header;
        char driver[9];
        t_boolean debug_flag;
        t_uint8 num_keys;
        t_uint8 virtual_keys[4];
      } keyboard_configuration = {
        { 0, HOST_COMMAND_LOAD },
        "keyboard",
        false,
        4
      };

      t_error result;
      keyboard_configuration.virtual_keys[0] =
        (Keyboard_P.HostKeyboard_ScanCodes[0]);
      keyboard_configuration.virtual_keys[1] =
        (Keyboard_P.HostKeyboard_ScanCodes[1]);
      keyboard_configuration.virtual_keys[2] =
        (Keyboard_P.HostKeyboard_ScanCodes[2]);
      keyboard_configuration.virtual_keys[3] =
        (Keyboard_P.HostKeyboard_ScanCodes[3]);
      keyboard_configuration.debug_flag = Keyboard_P.HostKeyboard_DebugMode;
      result = host_remote_interface_send(host, &keyboard_configuration, sizeof
        (keyboard_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
      }
    }
  }

  return 0;
}

static t_error host_disconnect_Host0x2D1(t_host_remote_interface host, void
  * context)
{
  return 0;
}

static t_error host_receive_Host0x2D1(t_host_remote_interface host, void
  * context, t_uint32 peripheral_identifier, const void * data, t_uint32
  data_length)
{
  switch (peripheral_identifier) {
   case 0:
    /* S-Function Block: Keyboard/Host Keyboard (host_keyboard_block) */
    {
      t_keyboard_state * state = (t_keyboard_state *) (data);
      if (data_length >= sizeof(t_keyboard_state)) {
        t_error result = qthread_section_lock(&Keyboard_DW.HostKeyboard_Lock);
        if (result == 0) {
          memory_copy(&Keyboard_DW.HostKeyboard_KeyboardState, sizeof
                      (*&Keyboard_DW.HostKeyboard_KeyboardState), state);
          Keyboard_DW.HostKeyboard_NewData = true;
          qthread_section_unlock(&Keyboard_DW.HostKeyboard_Lock);
        }
      } else {
        rtmSetErrorStatus(Keyboard_M,
                          "A Host Keyboad block has received an invalid packet from the host!");
      }
    }
    break;

   default:
    rtmSetErrorStatus(Keyboard_M, "Invalid peripheral identifier received!");
    break;
  }

  return 0;
}

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
  Keyboard_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  Keyboard_output();
  Keyboard_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Keyboard_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_HostKeyboard_o2[4];
  real_T rtb_TmpSignalConversionAtHILWri[9];
  real_T rtb_commandsaturation;
  if (rtmIsMajorTimeStep(Keyboard_M)) {
    /* set solver stop time */
    if (!(Keyboard_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Keyboard_M->solverInfo,
                            ((Keyboard_M->Timing.clockTickH0 + 1) *
        Keyboard_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Keyboard_M->solverInfo,
                            ((Keyboard_M->Timing.clockTick0 + 1) *
        Keyboard_M->Timing.stepSize0 + Keyboard_M->Timing.clockTickH0 *
        Keyboard_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Keyboard_M)) {
    Keyboard_M->Timing.t[0] = rtsiGetT(&Keyboard_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Keyboard_M)) {
    /* S-Function (hil_read_block): '<S1>/HIL Read' */

    /* S-Function Block: Keyboard/basicQCarIO/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(Keyboard_DW.HILInitialize_Card,
        Keyboard_P.HILRead_analog_channels, 2U,
        &Keyboard_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &Keyboard_DW.HILRead_AnalogBuffer[0],
        &Keyboard_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
      } else {
        Keyboard_B.motorcurrent = Keyboard_DW.HILRead_AnalogBuffer[0];
        Keyboard_B.batteryvoltage = Keyboard_DW.HILRead_AnalogBuffer[1];
        Keyboard_B.encodercounts = Keyboard_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S1>/Unwrap 2^24' */
    /* S-Function Block: Keyboard/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = Keyboard_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Keyboard_DW.Unwrap224_FirstSample) {
        Keyboard_DW.Unwrap224_FirstSample = false;
        Keyboard_DW.Unwrap224_PreviousInput = Keyboard_B.encodercounts;
      }

      du = (real_T) Keyboard_B.encodercounts -
        Keyboard_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Keyboard_DW.Unwrap224_Revolutions = Keyboard_DW.Unwrap224_Revolutions -
          1;
        dy = du - Keyboard_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Keyboard_DW.Unwrap224_Revolutions = Keyboard_DW.Unwrap224_Revolutions +
          1;
        dy = du + Keyboard_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Keyboard_B.Unwrap224 = Keyboard_B.encodercounts +
        Keyboard_DW.Unwrap224_Revolutions * Keyboard_P.Unwrap224_Modulus;
      Keyboard_DW.Unwrap224_PreviousInput = Keyboard_B.encodercounts;
    }
  }

  /* Integrator: '<S2>/Integrator1' */
  if (Keyboard_DW.Integrator1_IWORK != 0) {
    Keyboard_X.Integrator1_CSTATE = Keyboard_B.Unwrap224;
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S2>/Constant'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator2'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  Keyboard_B.Product = ((Keyboard_B.Unwrap224 - Keyboard_X.Integrator1_CSTATE) -
                        Keyboard_X.Integrator2_CSTATE *
                        Keyboard_P.Constant_Value * Keyboard_P.Constant1_Value) *
    Keyboard_P.Constant2_Value;

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Integrator: '<S2>/Integrator2'
   */
  Keyboard_B.Product1 = Keyboard_P.Constant2_Value *
    Keyboard_X.Integrator2_CSTATE;

  /* Integrator: '<S3>/Integrator1' */
  if (Keyboard_DW.Integrator1_IWORK_d != 0) {
    Keyboard_X.Integrator1_CSTATE_a = Keyboard_B.batteryvoltage;
  }

  /* Integrator: '<S3>/Integrator1' */
  Keyboard_B.Integrator1 = Keyboard_X.Integrator1_CSTATE_a;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S3>/Constant'
   *  Integrator: '<S3>/Integrator2'
   *  Product: '<S3>/Product2'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   */
  Keyboard_B.Product_h = ((Keyboard_B.batteryvoltage - Keyboard_B.Integrator1) -
    Keyboard_X.Integrator2_CSTATE_c * Keyboard_P.Constant_Value_b *
    Keyboard_P.Constant3_Value) * Keyboard_P.Constant4_Value;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Integrator: '<S3>/Integrator2'
   */
  Keyboard_B.Product1_e = Keyboard_P.Constant4_Value *
    Keyboard_X.Integrator2_CSTATE_c;

  /* Integrator: '<S4>/Integrator1' */
  if (Keyboard_DW.Integrator1_IWORK_c != 0) {
    Keyboard_X.Integrator1_CSTATE_e = Keyboard_B.motorcurrent;
  }

  /* Integrator: '<S4>/Integrator1' */
  Keyboard_B.Integrator1_o = Keyboard_X.Integrator1_CSTATE_e;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S4>/Constant'
   *  Integrator: '<S4>/Integrator2'
   *  Product: '<S4>/Product2'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S4>/Sum1'
   */
  Keyboard_B.Product_j = ((Keyboard_B.motorcurrent - Keyboard_B.Integrator1_o) -
    Keyboard_X.Integrator2_CSTATE_a * Keyboard_P.Constant_Value_bi *
    Keyboard_P.Constant5_Value) * Keyboard_P.Constant6_Value;

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Integrator: '<S4>/Integrator2'
   */
  Keyboard_B.Product1_m = Keyboard_P.Constant6_Value *
    Keyboard_X.Integrator2_CSTATE_a;
  if (rtmIsMajorTimeStep(Keyboard_M)) {
    /* S-Function (host_keyboard_block): '<Root>/Host Keyboard' */

    /* S-Function Block: Keyboard/Host Keyboard (host_keyboard_block) */
    {
      if (Keyboard_P.HostKeyboard_Enabled) {
        t_error result = qthread_section_lock(&Keyboard_DW.HostKeyboard_Lock);
        if (result == 0) {
          t_int offset;
          t_uint mask;
          offset = (Keyboard_P.HostKeyboard_ScanCodes[0]) >> 5;
          mask = 1U << ((Keyboard_P.HostKeyboard_ScanCodes[0]) & 31);
          rtb_HostKeyboard_o2[0] =
            ((Keyboard_DW.HostKeyboard_KeyboardState.keys[offset] & mask) != 0);
          offset = (Keyboard_P.HostKeyboard_ScanCodes[1]) >> 5;
          mask = 1U << ((Keyboard_P.HostKeyboard_ScanCodes[1]) & 31);
          rtb_HostKeyboard_o2[1] =
            ((Keyboard_DW.HostKeyboard_KeyboardState.keys[offset] & mask) != 0);
          offset = (Keyboard_P.HostKeyboard_ScanCodes[2]) >> 5;
          mask = 1U << ((Keyboard_P.HostKeyboard_ScanCodes[2]) & 31);
          rtb_HostKeyboard_o2[2] =
            ((Keyboard_DW.HostKeyboard_KeyboardState.keys[offset] & mask) != 0);
          offset = (Keyboard_P.HostKeyboard_ScanCodes[3]) >> 5;
          mask = 1U << ((Keyboard_P.HostKeyboard_ScanCodes[3]) & 31);
          rtb_HostKeyboard_o2[3] =
            ((Keyboard_DW.HostKeyboard_KeyboardState.keys[offset] & mask) != 0);
          Keyboard_DW.HostKeyboard_NewData = false;
          qthread_section_unlock(&Keyboard_DW.HostKeyboard_Lock);
        }
      } else {
        rtb_HostKeyboard_o2[0] = false;
        rtb_HostKeyboard_o2[1] = false;
        rtb_HostKeyboard_o2[2] = false;
        rtb_HostKeyboard_o2[3] = false;
      }
    }

    /* Gain: '<S1>/direction convention' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Gain: '<Root>/Gain'
     *  Gain: '<Root>/Gain1'
     *  Sum: '<Root>/Add1'
     */
    rtb_commandsaturation = (Keyboard_P.Gain_Gain * (real_T)rtb_HostKeyboard_o2
      [0] + Keyboard_P.Gain1_Gain * (real_T)rtb_HostKeyboard_o2[3]) *
      Keyboard_P.directionconvention_Gain;

    /* Saturate: '<S1>/command saturation' */
    if (rtb_commandsaturation > Keyboard_P.commandsaturation_UpperSat) {
      rtb_commandsaturation = Keyboard_P.commandsaturation_UpperSat;
    } else if (rtb_commandsaturation < Keyboard_P.commandsaturation_LowerSat) {
      rtb_commandsaturation = Keyboard_P.commandsaturation_LowerSat;
    }

    /* End of Saturate: '<S1>/command saturation' */

    /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
     *  Bias: '<S1>/Steering Bias'
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Gain: '<Root>/Gain2'
     *  Gain: '<Root>/Gain3'
     *  Gain: '<S1>/Gain'
     *  Sum: '<Root>/Add'
     */
    rtb_TmpSignalConversionAtHILWri[0] = (Keyboard_P.Gain2_Gain * (real_T)
      rtb_HostKeyboard_o2[1] + Keyboard_P.Gain3_Gain * (real_T)
      rtb_HostKeyboard_o2[2]) * Keyboard_P.Gain_Gain_b +
      Keyboard_P.SteeringBias_Bias;

    /* ManualSwitch: '<Root>/Manual Switch' */
    if (Keyboard_P.ManualSwitch_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[1] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[1] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* ManualSwitch: '<Root>/Manual Switch1' */
    if (Keyboard_P.ManualSwitch1_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[2] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[2] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */

    /* ManualSwitch: '<Root>/Manual Switch2' */
    if (Keyboard_P.ManualSwitch2_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[3] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[3] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* ManualSwitch: '<Root>/Manual Switch3' */
    if (Keyboard_P.ManualSwitch3_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[4] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[4] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */

    /* ManualSwitch: '<Root>/Manual Switch4' */
    if (Keyboard_P.ManualSwitch4_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[5] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[5] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch4' */

    /* ManualSwitch: '<Root>/Manual Switch5' */
    if (Keyboard_P.ManualSwitch5_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[6] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[6] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch5' */

    /* ManualSwitch: '<Root>/Manual Switch6' */
    if (Keyboard_P.ManualSwitch6_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[7] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[7] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch6' */

    /* ManualSwitch: '<Root>/Manual Switch7' */
    if (Keyboard_P.ManualSwitch7_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[8] = Keyboard_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S1>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[8] = Keyboard_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch7' */

    /* S-Function (hil_write_block): '<S1>/HIL Write' incorporates:
     *  Constant: '<S1>/coast ON'
     */

    /* S-Function Block: Keyboard/basicQCarIO/HIL Write (hil_write_block) */
    {
      t_error result;
      Keyboard_DW.HILWrite_DigitalBuffer = (Keyboard_P.coastON_Value != 0);
      result = hil_write(Keyboard_DW.HILInitialize_Card,
                         NULL, 0U,
                         &Keyboard_P.HILWrite_pwm_channels, 1U,
                         &Keyboard_P.HILWrite_digital_channels, 1U,
                         Keyboard_P.HILWrite_other_channels, 9U,
                         NULL,
                         &rtb_commandsaturation,
                         &Keyboard_DW.HILWrite_DigitalBuffer,
                         &rtb_TmpSignalConversionAtHILWri[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
      }
    }

    /* S-Function (host_initialize_block): '<Root>/Host Initialize' */

    /* S-Function Block: Keyboard/Host Initialize (host_initialize_block) */
    {
      t_host_status status;
      host_remote_interface_get_status
        (Keyboard_DW.HostInitialize_ConnectedHandle, &status);
      Keyboard_B.HostInitialize_o1 = status.connection_status;
      Keyboard_B.HostInitialize_o2 = status.error_status;
    }
  }
}

/* Model update function */
void Keyboard_update(void)
{
  /* Update for Integrator: '<S2>/Integrator1' */
  Keyboard_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S3>/Integrator1' */
  Keyboard_DW.Integrator1_IWORK_d = 0;

  /* Update for Integrator: '<S4>/Integrator1' */
  Keyboard_DW.Integrator1_IWORK_c = 0;
  if (rtmIsMajorTimeStep(Keyboard_M)) {
    rt_ertODEUpdateContinuousStates(&Keyboard_M->solverInfo);
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
  if (!(++Keyboard_M->Timing.clockTick0)) {
    ++Keyboard_M->Timing.clockTickH0;
  }

  Keyboard_M->Timing.t[0] = rtsiGetSolverStopTime(&Keyboard_M->solverInfo);

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
    if (!(++Keyboard_M->Timing.clockTick1)) {
      ++Keyboard_M->Timing.clockTickH1;
    }

    Keyboard_M->Timing.t[1] = Keyboard_M->Timing.clockTick1 *
      Keyboard_M->Timing.stepSize1 + Keyboard_M->Timing.clockTickH1 *
      Keyboard_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Keyboard_derivatives(void)
{
  XDot_Keyboard_T *_rtXdot;
  _rtXdot = ((XDot_Keyboard_T *) Keyboard_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Keyboard_B.Product1;

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Keyboard_B.Product;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_a = Keyboard_B.Product1_e;

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c = Keyboard_B.Product_h;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = Keyboard_B.Product1_m;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = Keyboard_B.Product_j;
}

/* Model initialize function */
void Keyboard_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: Keyboard/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Keyboard_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Keyboard_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Keyboard_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Keyboard_M, _rt_error_message);
      return;
    }

    if ((Keyboard_P.HILInitialize_AIPStart && !is_switching) ||
        (Keyboard_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Keyboard_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Keyboard_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Keyboard_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Keyboard_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Keyboard_DW.HILInitialize_Card,
        Keyboard_P.HILInitialize_AIChannels, 7U,
        &Keyboard_DW.HILInitialize_AIMinimums[0],
        &Keyboard_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Keyboard_DW.HILInitialize_Card,
      Keyboard_P.HILInitialize_DIChannels, 19U,
      &Keyboard_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Keyboard_M, _rt_error_message);
      return;
    }

    if ((Keyboard_P.HILInitialize_DOStart && !is_switching) ||
        (Keyboard_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Keyboard_DW.HILInitialize_Card,
        &Keyboard_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Keyboard_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    if ((Keyboard_P.HILInitialize_EIPStart && !is_switching) ||
        (Keyboard_P.HILInitialize_EIPEnter && is_switching)) {
      Keyboard_DW.HILInitialize_QuadratureModes[0] =
        (Keyboard_P.HILInitialize_EIQuadrature[0]);
      Keyboard_DW.HILInitialize_QuadratureModes[1] =
        (Keyboard_P.HILInitialize_EIQuadrature[1]);
      Keyboard_DW.HILInitialize_QuadratureModes[2] =
        (Keyboard_P.HILInitialize_EIQuadrature[1]);
      Keyboard_DW.HILInitialize_QuadratureModes[3] =
        (Keyboard_P.HILInitialize_EIQuadrature[1]);
      Keyboard_DW.HILInitialize_QuadratureModes[4] =
        (Keyboard_P.HILInitialize_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode(Keyboard_DW.HILInitialize_Card,
        Keyboard_P.HILInitialize_EIChannels, 5U, (t_encoder_quadrature_mode *)
        &Keyboard_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency = &Keyboard_DW.HILInitialize_FilterFrequency
          [0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] = Keyboard_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency(Keyboard_DW.HILInitialize_Card,
        Keyboard_P.HILInitialize_EIChannels, 5U,
        &Keyboard_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    if ((Keyboard_P.HILInitialize_EIStart && !is_switching) ||
        (Keyboard_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Keyboard_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = Keyboard_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Keyboard_DW.HILInitialize_Card,
        Keyboard_P.HILInitialize_EIChannels, 5U,
        &Keyboard_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    if ((Keyboard_P.HILInitialize_POPStart && !is_switching) ||
        (Keyboard_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(Keyboard_DW.HILInitialize_Card,
        &Keyboard_P.HILInitialize_POChannels, 1U, (t_pwm_mode *)
        Keyboard_P.HILInitialize_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }

      if ((Keyboard_P.HILInitialize_POModes[0]) == PWM_DUTY_CYCLE_MODE ||
          (Keyboard_P.HILInitialize_POModes[0]) == PWM_ONE_SHOT_MODE ||
          (Keyboard_P.HILInitialize_POModes[0]) == PWM_TIME_MODE ||
          (Keyboard_P.HILInitialize_POModes[0]) == PWM_RAW_MODE) {
        Keyboard_DW.HILInitialize_POSortedChans =
          Keyboard_P.HILInitialize_POChannels;
        Keyboard_DW.HILInitialize_POSortedFreqs =
          Keyboard_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        Keyboard_DW.HILInitialize_POSortedChans =
          Keyboard_P.HILInitialize_POChannels;
        Keyboard_DW.HILInitialize_POSortedFreqs =
          Keyboard_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Keyboard_DW.HILInitialize_Card,
          &Keyboard_DW.HILInitialize_POSortedChans, num_duty_cycle_modes,
          &Keyboard_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Keyboard_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Keyboard_DW.HILInitialize_Card,
          &Keyboard_DW.HILInitialize_POSortedChans, num_frequency_modes,
          &Keyboard_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Keyboard_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration(Keyboard_DW.HILInitialize_Card,
        &Keyboard_P.HILInitialize_POChannels, 1U,
        (t_pwm_configuration *) &Keyboard_P.HILInitialize_POConfiguration,
        (t_pwm_alignment *) &Keyboard_P.HILInitialize_POAlignment,
        (t_pwm_polarity *) &Keyboard_P.HILInitialize_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    if ((Keyboard_P.HILInitialize_POStart && !is_switching) ||
        (Keyboard_P.HILInitialize_POEnter && is_switching)) {
      result = hil_write_pwm(Keyboard_DW.HILInitialize_Card,
        &Keyboard_P.HILInitialize_POChannels, 1U,
        &Keyboard_P.HILInitialize_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    if (Keyboard_P.HILInitialize_POReset) {
      result = hil_watchdog_set_pwm_expiration_state
        (Keyboard_DW.HILInitialize_Card, &Keyboard_P.HILInitialize_POChannels,
         1U, &Keyboard_P.HILInitialize_POWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }

    if ((Keyboard_P.HILInitialize_OOStart && !is_switching) ||
        (Keyboard_P.HILInitialize_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Keyboard_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Keyboard_P.HILInitialize_OOInitial;
        }
      }

      result = hil_write_other(Keyboard_DW.HILInitialize_Card,
        Keyboard_P.HILInitialize_OOChannels, 13U,
        &Keyboard_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S1>/Unwrap 2^24' */

  /* S-Function Block: Keyboard/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
  {
    Keyboard_DW.Unwrap224_FirstSample = true;
    Keyboard_DW.Unwrap224_Revolutions = 0;
  }

  /* Start for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: Keyboard/Host Keyboard (host_keyboard_block) */
  {
    qthread_section_init(&Keyboard_DW.HostKeyboard_Lock, NULL);
  }

  /* S-Function Block: Keyboard/Host Initialize (host_initialize_block) */
  {
    t_error result;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    qthread_attr_t attributes;
    if (Keyboard_P.HostInitialize_ThreadPriority < min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (Keyboard_P.HostInitialize_ThreadPriority > max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        Keyboard_P.HostInitialize_ThreadPriority;
    }

    qthread_attr_init(&attributes);
    result = qthread_attr_setschedpolicy(&attributes, QSCHED_FIFO);
    if (result == 0) {
      result = qthread_attr_setschedparam(&attributes, &scheduling_parameters);
      if (result == 0) {
        result = qthread_attr_setinheritsched(&attributes,
          QTHREAD_EXPLICIT_SCHED);
        if (result < 0) {
          rtmSetErrorStatus(Keyboard_M,
                            "Unable to set scheduling inheritance for host thread");
        }
      } else {
        rtmSetErrorStatus(Keyboard_M,
                          "The specified thread priority for the host thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(Keyboard_M,
                        "Unable to set scheduling policy for host thread");
    }

    result = host_remote_interface_open((const char *)
      Keyboard_P.HostInitialize_URI, host_connect_Host0x2D1,
      host_receive_Host0x2D1, host_disconnect_Host0x2D1,
      Keyboard_P.HostInitialize_SendBufferSize,
      Keyboard_P.HostInitialize_ReceiveBufferSiz, &attributes, NULL,
      &Keyboard_DW.HostInitialize_ConnectedHandle);
    Keyboard_B.HostInitialize_o1 = HOST_STATE_NOT_LISTENING;
    Keyboard_B.HostInitialize_o2 = result;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Keyboard_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<S2>/Integrator1' incorporates:
   *  Integrator: '<S3>/Integrator1'
   */
  if (rtmIsFirstInitCond(Keyboard_M)) {
    Keyboard_X.Integrator1_CSTATE = 0.0;
    Keyboard_X.Integrator1_CSTATE_a = 0.0;
  }

  Keyboard_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S2>/Integrator1' */

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  Keyboard_X.Integrator2_CSTATE = Keyboard_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  Keyboard_DW.Integrator1_IWORK_d = 1;

  /* InitializeConditions for Integrator: '<S3>/Integrator2' */
  Keyboard_X.Integrator2_CSTATE_c = Keyboard_P.Integrator2_IC_o;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  if (rtmIsFirstInitCond(Keyboard_M)) {
    Keyboard_X.Integrator1_CSTATE_e = 0.0;
  }

  Keyboard_DW.Integrator1_IWORK_c = 1;

  /* End of InitializeConditions for Integrator: '<S4>/Integrator1' */

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  Keyboard_X.Integrator2_CSTATE_a = Keyboard_P.Integrator2_IC_n;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Keyboard_M)) {
    rtmSetFirstInitCond(Keyboard_M, 0);
  }
}

/* Model terminate function */
void Keyboard_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: Keyboard/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Keyboard_DW.HILInitialize_Card);
    hil_monitor_stop_all(Keyboard_DW.HILInitialize_Card);
    is_switching = false;
    if ((Keyboard_P.HILInitialize_DOTerminate && !is_switching) ||
        (Keyboard_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Keyboard_P.HILInitialize_POTerminate && !is_switching) ||
        (Keyboard_P.HILInitialize_POExit && is_switching)) {
      num_final_pwm_outputs = 1U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Keyboard_P.HILInitialize_OOTerminate && !is_switching) ||
        (Keyboard_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Keyboard_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Keyboard_P.HILInitialize_OOFinal;
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
      result = hil_write(Keyboard_DW.HILInitialize_Card
                         , NULL, 0
                         , &Keyboard_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &Keyboard_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Keyboard_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Keyboard_P.HILInitialize_POFinal
                         , (t_boolean *) &Keyboard_P.HILInitialize_DOFinal
                         , &Keyboard_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Keyboard_DW.HILInitialize_Card,
            &Keyboard_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Keyboard_P.HILInitialize_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Keyboard_DW.HILInitialize_Card,
            &Keyboard_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Keyboard_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Keyboard_DW.HILInitialize_Card,
            Keyboard_P.HILInitialize_OOChannels, num_final_other_outputs,
            &Keyboard_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Keyboard_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Keyboard_DW.HILInitialize_Card);
    hil_monitor_delete_all(Keyboard_DW.HILInitialize_Card);
    hil_close(Keyboard_DW.HILInitialize_Card);
    Keyboard_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (host_keyboard_block): '<Root>/Host Keyboard' */

  /* S-Function Block: Keyboard/Host Keyboard (host_keyboard_block) */
  {
    qthread_section_destroy(&Keyboard_DW.HostKeyboard_Lock);
  }

  /* Terminate for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: Keyboard/Host Initialize (host_initialize_block) */
  {
    host_remote_interface_close(Keyboard_DW.HostInitialize_ConnectedHandle);
    Keyboard_DW.HostInitialize_ConnectedHandle = NULL;
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
  Keyboard_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Keyboard_update();
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
  Keyboard_initialize();
}

void MdlTerminate(void)
{
  Keyboard_terminate();
}

/* Registration function */
RT_MODEL_Keyboard_T *Keyboard(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Keyboard_M, 0,
                sizeof(RT_MODEL_Keyboard_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Keyboard_M->solverInfo,
                          &Keyboard_M->Timing.simTimeStep);
    rtsiSetTPtr(&Keyboard_M->solverInfo, &rtmGetTPtr(Keyboard_M));
    rtsiSetStepSizePtr(&Keyboard_M->solverInfo, &Keyboard_M->Timing.stepSize0);
    rtsiSetdXPtr(&Keyboard_M->solverInfo, &Keyboard_M->derivs);
    rtsiSetContStatesPtr(&Keyboard_M->solverInfo, (real_T **)
                         &Keyboard_M->contStates);
    rtsiSetNumContStatesPtr(&Keyboard_M->solverInfo,
      &Keyboard_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Keyboard_M->solverInfo,
      &Keyboard_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Keyboard_M->solverInfo,
      &Keyboard_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Keyboard_M->solverInfo,
      &Keyboard_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Keyboard_M->solverInfo, (&rtmGetErrorStatus
      (Keyboard_M)));
    rtsiSetRTModelPtr(&Keyboard_M->solverInfo, Keyboard_M);
  }

  rtsiSetSimTimeStep(&Keyboard_M->solverInfo, MAJOR_TIME_STEP);
  Keyboard_M->intgData.y = Keyboard_M->odeY;
  Keyboard_M->intgData.f[0] = Keyboard_M->odeF[0];
  Keyboard_M->intgData.f[1] = Keyboard_M->odeF[1];
  Keyboard_M->contStates = ((real_T *) &Keyboard_X);
  rtsiSetSolverData(&Keyboard_M->solverInfo, (void *)&Keyboard_M->intgData);
  rtsiSetSolverName(&Keyboard_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Keyboard_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Keyboard_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Keyboard_M->Timing.sampleTimes = (&Keyboard_M->Timing.sampleTimesArray[0]);
    Keyboard_M->Timing.offsetTimes = (&Keyboard_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Keyboard_M->Timing.sampleTimes[0] = (0.0);
    Keyboard_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Keyboard_M->Timing.offsetTimes[0] = (0.0);
    Keyboard_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Keyboard_M, &Keyboard_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Keyboard_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Keyboard_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Keyboard_M, -1);
  Keyboard_M->Timing.stepSize0 = 0.002;
  Keyboard_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(Keyboard_M, 1);

  /* External mode info */
  Keyboard_M->Sizes.checksums[0] = (3658771018U);
  Keyboard_M->Sizes.checksums[1] = (4030026030U);
  Keyboard_M->Sizes.checksums[2] = (1248826225U);
  Keyboard_M->Sizes.checksums[3] = (3825146976U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Keyboard_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Keyboard_M->extModeInfo,
      &Keyboard_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Keyboard_M->extModeInfo, Keyboard_M->Sizes.checksums);
    rteiSetTPtr(Keyboard_M->extModeInfo, rtmGetTPtr(Keyboard_M));
  }

  Keyboard_M->solverInfoPtr = (&Keyboard_M->solverInfo);
  Keyboard_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Keyboard_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Keyboard_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Keyboard_M->blockIO = ((void *) &Keyboard_B);
  (void) memset(((void *) &Keyboard_B), 0,
                sizeof(B_Keyboard_T));

  /* parameters */
  Keyboard_M->defaultParam = ((real_T *)&Keyboard_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Keyboard_X;
    Keyboard_M->contStates = (x);
    (void) memset((void *)&Keyboard_X, 0,
                  sizeof(X_Keyboard_T));
  }

  /* states (dwork) */
  Keyboard_M->dwork = ((void *) &Keyboard_DW);
  (void) memset((void *)&Keyboard_DW, 0,
                sizeof(DW_Keyboard_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Keyboard_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Keyboard_M->Sizes.numContStates = (6);/* Number of continuous states */
  Keyboard_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Keyboard_M->Sizes.numY = (0);        /* Number of model outputs */
  Keyboard_M->Sizes.numU = (0);        /* Number of model inputs */
  Keyboard_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Keyboard_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Keyboard_M->Sizes.numBlocks = (63);  /* Number of blocks */
  Keyboard_M->Sizes.numBlockIO = (14); /* Number of block outputs */
  Keyboard_M->Sizes.numBlockPrms = (190);/* Sum of parameter "widths" */
  return Keyboard_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
