/*
 * KeyboardAndLights.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "KeyboardAndLights".
 *
 * Model version              : 5.4
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Oct 18 10:01:57 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "KeyboardAndLights.h"
#include "KeyboardAndLights_private.h"
#include "KeyboardAndLights_dt.h"

/* Block signals (default storage) */
B_KeyboardAndLights_T KeyboardAndLights_B;

/* Continuous states */
X_KeyboardAndLights_T KeyboardAndLights_X;

/* Block states (default storage) */
DW_KeyboardAndLights_T KeyboardAndLights_DW;

/* Real-time model */
static RT_MODEL_KeyboardAndLights_T KeyboardAndLights_M_;
RT_MODEL_KeyboardAndLights_T *const KeyboardAndLights_M = &KeyboardAndLights_M_;
static t_error host_connect_Host0x2D1(t_host_remote_interface host, void
  * context)
{
  /* S-Function Block: KeyboardAndLights/Host Keyboard (host_keyboard_block) */
  {
    if (KeyboardAndLights_P.HostKeyboard_Enabled) {
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
        (KeyboardAndLights_P.HostKeyboard_ScanCodes[0]);
      keyboard_configuration.virtual_keys[1] =
        (KeyboardAndLights_P.HostKeyboard_ScanCodes[1]);
      keyboard_configuration.virtual_keys[2] =
        (KeyboardAndLights_P.HostKeyboard_ScanCodes[2]);
      keyboard_configuration.virtual_keys[3] =
        (KeyboardAndLights_P.HostKeyboard_ScanCodes[3]);
      keyboard_configuration.debug_flag =
        KeyboardAndLights_P.HostKeyboard_DebugMode;
      result = host_remote_interface_send(host, &keyboard_configuration, sizeof
        (keyboard_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
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
    /* S-Function Block: KeyboardAndLights/Host Keyboard (host_keyboard_block) */
    {
      t_keyboard_state * state = (t_keyboard_state *) (data);
      if (data_length >= sizeof(t_keyboard_state)) {
        t_error result = qthread_section_lock
          (&KeyboardAndLights_DW.HostKeyboard_Lock);
        if (result == 0) {
          memory_copy(&KeyboardAndLights_DW.HostKeyboard_KeyboardState, sizeof(*
            &KeyboardAndLights_DW.HostKeyboard_KeyboardState), state);
          KeyboardAndLights_DW.HostKeyboard_NewData = true;
          qthread_section_unlock(&KeyboardAndLights_DW.HostKeyboard_Lock);
        }
      } else {
        rtmSetErrorStatus(KeyboardAndLights_M,
                          "A Host Keyboad block has received an invalid packet from the host!");
      }
    }
    break;

   default:
    rtmSetErrorStatus(KeyboardAndLights_M,
                      "Invalid peripheral identifier received!");
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
  KeyboardAndLights_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  KeyboardAndLights_output();
  KeyboardAndLights_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void KeyboardAndLights_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_HostKeyboard_o2[4];
  real_T rtb_TmpSignalConversionAtHILWri[9];
  real_T rtb_SteeringBias;
  real_T rtb_commandsaturation;
  real_T rtb_frontleftheadlamp;
  int32_T rtb_DataTypeConversion3_idx_3;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_k;
  if (rtmIsMajorTimeStep(KeyboardAndLights_M)) {
    /* set solver stop time */
    if (!(KeyboardAndLights_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&KeyboardAndLights_M->solverInfo,
                            ((KeyboardAndLights_M->Timing.clockTickH0 + 1) *
        KeyboardAndLights_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&KeyboardAndLights_M->solverInfo,
                            ((KeyboardAndLights_M->Timing.clockTick0 + 1) *
        KeyboardAndLights_M->Timing.stepSize0 +
        KeyboardAndLights_M->Timing.clockTickH0 *
        KeyboardAndLights_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(KeyboardAndLights_M)) {
    KeyboardAndLights_M->Timing.t[0] = rtsiGetT(&KeyboardAndLights_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(KeyboardAndLights_M)) {
    /* S-Function (hil_read_block): '<S6>/HIL Read' */

    /* S-Function Block: KeyboardAndLights/basicQCarIO/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(KeyboardAndLights_DW.HILInitialize_Card,
        KeyboardAndLights_P.HILRead_analog_channels, 2U,
        &KeyboardAndLights_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &KeyboardAndLights_DW.HILRead_AnalogBuffer[0],
        &KeyboardAndLights_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
      } else {
        KeyboardAndLights_B.motorcurrent =
          KeyboardAndLights_DW.HILRead_AnalogBuffer[0];
        KeyboardAndLights_B.batteryvoltage =
          KeyboardAndLights_DW.HILRead_AnalogBuffer[1];
        KeyboardAndLights_B.encodercounts =
          KeyboardAndLights_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S6>/Unwrap 2^24' */
    /* S-Function Block: KeyboardAndLights/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = KeyboardAndLights_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (KeyboardAndLights_DW.Unwrap224_FirstSample) {
        KeyboardAndLights_DW.Unwrap224_FirstSample = false;
        KeyboardAndLights_DW.Unwrap224_PreviousInput =
          KeyboardAndLights_B.encodercounts;
      }

      du = (real_T) KeyboardAndLights_B.encodercounts -
        KeyboardAndLights_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        KeyboardAndLights_DW.Unwrap224_Revolutions =
          KeyboardAndLights_DW.Unwrap224_Revolutions - 1;
        dy = du - KeyboardAndLights_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        KeyboardAndLights_DW.Unwrap224_Revolutions =
          KeyboardAndLights_DW.Unwrap224_Revolutions + 1;
        dy = du + KeyboardAndLights_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      KeyboardAndLights_B.Unwrap224 = KeyboardAndLights_B.encodercounts +
        KeyboardAndLights_DW.Unwrap224_Revolutions *
        KeyboardAndLights_P.Unwrap224_Modulus;
      KeyboardAndLights_DW.Unwrap224_PreviousInput =
        KeyboardAndLights_B.encodercounts;
    }
  }

  /* Integrator: '<S7>/Integrator1' */
  if (KeyboardAndLights_DW.Integrator1_IWORK != 0) {
    KeyboardAndLights_X.Integrator1_CSTATE = KeyboardAndLights_B.Unwrap224;
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S7>/Constant'
   *  Integrator: '<S7>/Integrator1'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product2'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  KeyboardAndLights_B.Product = ((KeyboardAndLights_B.Unwrap224 -
    KeyboardAndLights_X.Integrator1_CSTATE) -
    KeyboardAndLights_X.Integrator2_CSTATE * KeyboardAndLights_P.Constant_Value *
    KeyboardAndLights_P.Constant1_Value) * KeyboardAndLights_P.Constant2_Value;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Integrator: '<S7>/Integrator2'
   */
  KeyboardAndLights_B.Product1 = KeyboardAndLights_P.Constant2_Value *
    KeyboardAndLights_X.Integrator2_CSTATE;

  /* Integrator: '<S8>/Integrator1' */
  if (KeyboardAndLights_DW.Integrator1_IWORK_d != 0) {
    KeyboardAndLights_X.Integrator1_CSTATE_a =
      KeyboardAndLights_B.batteryvoltage;
  }

  /* Integrator: '<S8>/Integrator1' */
  KeyboardAndLights_B.Integrator1 = KeyboardAndLights_X.Integrator1_CSTATE_a;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S8>/Constant'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S8>/Sum1'
   */
  KeyboardAndLights_B.Product_h = ((KeyboardAndLights_B.batteryvoltage -
    KeyboardAndLights_B.Integrator1) - KeyboardAndLights_X.Integrator2_CSTATE_c *
    KeyboardAndLights_P.Constant_Value_b * KeyboardAndLights_P.Constant3_Value) *
    KeyboardAndLights_P.Constant4_Value;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S6>/Constant4'
   *  Integrator: '<S8>/Integrator2'
   */
  KeyboardAndLights_B.Product1_e = KeyboardAndLights_P.Constant4_Value *
    KeyboardAndLights_X.Integrator2_CSTATE_c;

  /* Integrator: '<S9>/Integrator1' */
  if (KeyboardAndLights_DW.Integrator1_IWORK_c != 0) {
    KeyboardAndLights_X.Integrator1_CSTATE_e = KeyboardAndLights_B.motorcurrent;
  }

  /* Integrator: '<S9>/Integrator1' */
  KeyboardAndLights_B.Integrator1_o = KeyboardAndLights_X.Integrator1_CSTATE_e;

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S6>/Constant5'
   *  Constant: '<S6>/Constant6'
   *  Constant: '<S9>/Constant'
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Product2'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  KeyboardAndLights_B.Product_j = ((KeyboardAndLights_B.motorcurrent -
    KeyboardAndLights_B.Integrator1_o) -
    KeyboardAndLights_X.Integrator2_CSTATE_a *
    KeyboardAndLights_P.Constant_Value_bi * KeyboardAndLights_P.Constant5_Value)
    * KeyboardAndLights_P.Constant6_Value;

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S6>/Constant6'
   *  Integrator: '<S9>/Integrator2'
   */
  KeyboardAndLights_B.Product1_m = KeyboardAndLights_P.Constant6_Value *
    KeyboardAndLights_X.Integrator2_CSTATE_a;
  if (rtmIsMajorTimeStep(KeyboardAndLights_M)) {
    /* S-Function (host_keyboard_block): '<Root>/Host Keyboard' */

    /* S-Function Block: KeyboardAndLights/Host Keyboard (host_keyboard_block) */
    {
      if (KeyboardAndLights_P.HostKeyboard_Enabled) {
        t_error result = qthread_section_lock
          (&KeyboardAndLights_DW.HostKeyboard_Lock);
        if (result == 0) {
          t_int offset;
          t_uint mask;
          offset = (KeyboardAndLights_P.HostKeyboard_ScanCodes[0]) >> 5;
          mask = 1U << ((KeyboardAndLights_P.HostKeyboard_ScanCodes[0]) & 31);
          rtb_HostKeyboard_o2[0] =
            ((KeyboardAndLights_DW.HostKeyboard_KeyboardState.keys[offset] &
              mask) != 0);
          offset = (KeyboardAndLights_P.HostKeyboard_ScanCodes[1]) >> 5;
          mask = 1U << ((KeyboardAndLights_P.HostKeyboard_ScanCodes[1]) & 31);
          rtb_HostKeyboard_o2[1] =
            ((KeyboardAndLights_DW.HostKeyboard_KeyboardState.keys[offset] &
              mask) != 0);
          offset = (KeyboardAndLights_P.HostKeyboard_ScanCodes[2]) >> 5;
          mask = 1U << ((KeyboardAndLights_P.HostKeyboard_ScanCodes[2]) & 31);
          rtb_HostKeyboard_o2[2] =
            ((KeyboardAndLights_DW.HostKeyboard_KeyboardState.keys[offset] &
              mask) != 0);
          offset = (KeyboardAndLights_P.HostKeyboard_ScanCodes[3]) >> 5;
          mask = 1U << ((KeyboardAndLights_P.HostKeyboard_ScanCodes[3]) & 31);
          rtb_HostKeyboard_o2[3] =
            ((KeyboardAndLights_DW.HostKeyboard_KeyboardState.keys[offset] &
              mask) != 0);
          KeyboardAndLights_DW.HostKeyboard_NewData = false;
          qthread_section_unlock(&KeyboardAndLights_DW.HostKeyboard_Lock);
        }
      } else {
        rtb_HostKeyboard_o2[0] = false;
        rtb_HostKeyboard_o2[1] = false;
        rtb_HostKeyboard_o2[2] = false;
        rtb_HostKeyboard_o2[3] = false;
      }
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    rtb_DataTypeConversion3_idx_3 = rtb_HostKeyboard_o2[3];

    /* Gain: '<Root>/Gain1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     */
    rtb_commandsaturation = KeyboardAndLights_P.Gain1_Gain * (real_T)
      rtb_HostKeyboard_o2[3];

    /* Gain: '<S6>/direction convention' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     *  Gain: '<Root>/Gain'
     *  Sum: '<Root>/Add1'
     */
    rtb_commandsaturation = (KeyboardAndLights_P.Gain_Gain * (real_T)
      rtb_HostKeyboard_o2[0] + rtb_commandsaturation) *
      KeyboardAndLights_P.directionconvention_Gain;

    /* Saturate: '<S6>/command saturation' */
    if (rtb_commandsaturation > KeyboardAndLights_P.commandsaturation_UpperSat)
    {
      rtb_commandsaturation = KeyboardAndLights_P.commandsaturation_UpperSat;
    } else if (rtb_commandsaturation <
               KeyboardAndLights_P.commandsaturation_LowerSat) {
      rtb_commandsaturation = KeyboardAndLights_P.commandsaturation_LowerSat;
    }

    /* End of Saturate: '<S6>/command saturation' */

    /* Sum: '<Root>/Add' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     *  Gain: '<Root>/Gain2'
     *  Gain: '<Root>/Gain3'
     */
    rtb_frontleftheadlamp = KeyboardAndLights_P.Gain2_Gain * (real_T)
      rtb_HostKeyboard_o2[1] + KeyboardAndLights_P.Gain3_Gain * (real_T)
      rtb_HostKeyboard_o2[2];

    /* Bias: '<S6>/Steering Bias' incorporates:
     *  Gain: '<S6>/Gain'
     */
    rtb_SteeringBias = KeyboardAndLights_P.Gain_Gain_b * rtb_frontleftheadlamp +
      KeyboardAndLights_P.SteeringBias_Bias;

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_Compare = (rtb_frontleftheadlamp >
                   KeyboardAndLights_P.LeftSteeringLimit_const);

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    KeyboardAndLights_B.DataTypeConversion1 = rtb_Compare;

    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     */
    rtb_Compare_k = (rtb_frontleftheadlamp <
                     KeyboardAndLights_P.RightSteeringLimit_const);

    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    KeyboardAndLights_B.DataTypeConversion2 = rtb_Compare_k;

    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    KeyboardAndLights_B.DataTypeConversion5 = rtb_Compare;

    /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    KeyboardAndLights_B.DataTypeConversion4 = rtb_Compare_k;
  }

  /* SignalGenerator: '<S1>/Square Wave Generator' */
  rtb_frontleftheadlamp = KeyboardAndLights_P.SquareWaveGenerator_Frequency *
    KeyboardAndLights_M->Timing.t[0];
  if (rtb_frontleftheadlamp - floor(rtb_frontleftheadlamp) >= 0.5) {
    rtb_frontleftheadlamp = KeyboardAndLights_P.SquareWaveGenerator_Amplitude;
  } else {
    rtb_frontleftheadlamp = -KeyboardAndLights_P.SquareWaveGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<S1>/Square Wave Generator' */

  /* Switch: '<S1>/Switch' */
  if (rtb_frontleftheadlamp > KeyboardAndLights_P.Switch_Threshold) {
    /* Switch: '<S1>/Switch' */
    KeyboardAndLights_B.Switch[0] = KeyboardAndLights_B.DataTypeConversion1;
    KeyboardAndLights_B.Switch[1] = KeyboardAndLights_B.DataTypeConversion2;
    KeyboardAndLights_B.Switch[2] = KeyboardAndLights_B.DataTypeConversion5;
    KeyboardAndLights_B.Switch[3] = KeyboardAndLights_B.DataTypeConversion4;
  } else {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    KeyboardAndLights_B.Switch[0] = KeyboardAndLights_P.Constant1_Value_m;
    KeyboardAndLights_B.Switch[1] = KeyboardAndLights_P.Constant1_Value_m;
    KeyboardAndLights_B.Switch[2] = KeyboardAndLights_P.Constant1_Value_m;
    KeyboardAndLights_B.Switch[3] = KeyboardAndLights_P.Constant1_Value_m;
  }

  /* End of Switch: '<S1>/Switch' */
  if (rtmIsMajorTimeStep(KeyboardAndLights_M)) {
    /* SignalConversion generated from: '<S6>/HIL Write' */
    rtb_TmpSignalConversionAtHILWri[0] = rtb_SteeringBias;
    rtb_TmpSignalConversionAtHILWri[1] = KeyboardAndLights_B.Switch[0];
    rtb_TmpSignalConversionAtHILWri[2] = KeyboardAndLights_B.Switch[1];
    rtb_TmpSignalConversionAtHILWri[3] = KeyboardAndLights_B.Switch[2];
    rtb_TmpSignalConversionAtHILWri[4] = KeyboardAndLights_B.Switch[3];

    /* ManualSwitch: '<Root>/Manual Switch4' */
    if (KeyboardAndLights_P.ManualSwitch4_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S6>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[5] = KeyboardAndLights_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S6>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[5] = KeyboardAndLights_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch4' */

    /* SignalConversion generated from: '<S6>/HIL Write' */
    rtb_TmpSignalConversionAtHILWri[6] = rtb_DataTypeConversion3_idx_3;

    /* ManualSwitch: '<Root>/Manual Switch6' */
    if (KeyboardAndLights_P.ManualSwitch6_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S6>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[7] = KeyboardAndLights_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S6>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[7] = KeyboardAndLights_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch6' */

    /* ManualSwitch: '<Root>/Manual Switch7' */
    if (KeyboardAndLights_P.ManualSwitch7_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S6>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtb_TmpSignalConversionAtHILWri[8] = KeyboardAndLights_P.Constant2_Value_h;
    } else {
      /* SignalConversion generated from: '<S6>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      rtb_TmpSignalConversionAtHILWri[8] = KeyboardAndLights_P.Constant3_Value_k;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch7' */

    /* S-Function (hil_write_block): '<S6>/HIL Write' incorporates:
     *  Constant: '<S6>/coast ON'
     */

    /* S-Function Block: KeyboardAndLights/basicQCarIO/HIL Write (hil_write_block) */
    {
      t_error result;
      KeyboardAndLights_DW.HILWrite_DigitalBuffer =
        (KeyboardAndLights_P.coastON_Value != 0);
      result = hil_write(KeyboardAndLights_DW.HILInitialize_Card,
                         NULL, 0U,
                         &KeyboardAndLights_P.HILWrite_pwm_channels, 1U,
                         &KeyboardAndLights_P.HILWrite_digital_channels, 1U,
                         KeyboardAndLights_P.HILWrite_other_channels, 9U,
                         NULL,
                         &rtb_commandsaturation,
                         &KeyboardAndLights_DW.HILWrite_DigitalBuffer,
                         &rtb_TmpSignalConversionAtHILWri[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
      }
    }

    /* S-Function (host_initialize_block): '<Root>/Host Initialize' */

    /* S-Function Block: KeyboardAndLights/Host Initialize (host_initialize_block) */
    {
      t_host_status status;
      host_remote_interface_get_status
        (KeyboardAndLights_DW.HostInitialize_ConnectedHandle, &status);
      KeyboardAndLights_B.HostInitialize_o1 = status.connection_status;
      KeyboardAndLights_B.HostInitialize_o2 = status.error_status;
    }
  }
}

/* Model update function */
void KeyboardAndLights_update(void)
{
  /* Update for Integrator: '<S7>/Integrator1' */
  KeyboardAndLights_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S8>/Integrator1' */
  KeyboardAndLights_DW.Integrator1_IWORK_d = 0;

  /* Update for Integrator: '<S9>/Integrator1' */
  KeyboardAndLights_DW.Integrator1_IWORK_c = 0;
  if (rtmIsMajorTimeStep(KeyboardAndLights_M)) {
    rt_ertODEUpdateContinuousStates(&KeyboardAndLights_M->solverInfo);
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
  if (!(++KeyboardAndLights_M->Timing.clockTick0)) {
    ++KeyboardAndLights_M->Timing.clockTickH0;
  }

  KeyboardAndLights_M->Timing.t[0] = rtsiGetSolverStopTime
    (&KeyboardAndLights_M->solverInfo);

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
    if (!(++KeyboardAndLights_M->Timing.clockTick1)) {
      ++KeyboardAndLights_M->Timing.clockTickH1;
    }

    KeyboardAndLights_M->Timing.t[1] = KeyboardAndLights_M->Timing.clockTick1 *
      KeyboardAndLights_M->Timing.stepSize1 +
      KeyboardAndLights_M->Timing.clockTickH1 *
      KeyboardAndLights_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void KeyboardAndLights_derivatives(void)
{
  XDot_KeyboardAndLights_T *_rtXdot;
  _rtXdot = ((XDot_KeyboardAndLights_T *) KeyboardAndLights_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = KeyboardAndLights_B.Product1;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = KeyboardAndLights_B.Product;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_a = KeyboardAndLights_B.Product1_e;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c = KeyboardAndLights_B.Product_h;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = KeyboardAndLights_B.Product1_m;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = KeyboardAndLights_B.Product_j;
}

/* Model initialize function */
void KeyboardAndLights_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S6>/HIL Initialize' */

  /* S-Function Block: KeyboardAndLights/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &KeyboardAndLights_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(KeyboardAndLights_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
      return;
    }

    if ((KeyboardAndLights_P.HILInitialize_AIPStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &KeyboardAndLights_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = KeyboardAndLights_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &KeyboardAndLights_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = KeyboardAndLights_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (KeyboardAndLights_DW.HILInitialize_Card,
         KeyboardAndLights_P.HILInitialize_AIChannels, 7U,
         &KeyboardAndLights_DW.HILInitialize_AIMinimums[0],
         &KeyboardAndLights_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(KeyboardAndLights_DW.HILInitialize_Card,
      KeyboardAndLights_P.HILInitialize_DIChannels, 19U,
      &KeyboardAndLights_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
      return;
    }

    if ((KeyboardAndLights_P.HILInitialize_DOStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(KeyboardAndLights_DW.HILInitialize_Card,
        &KeyboardAndLights_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &KeyboardAndLights_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    if ((KeyboardAndLights_P.HILInitialize_EIPStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_EIPEnter && is_switching)) {
      KeyboardAndLights_DW.HILInitialize_QuadratureModes[0] =
        (KeyboardAndLights_P.HILInitialize_EIQuadrature[0]);
      KeyboardAndLights_DW.HILInitialize_QuadratureModes[1] =
        (KeyboardAndLights_P.HILInitialize_EIQuadrature[1]);
      KeyboardAndLights_DW.HILInitialize_QuadratureModes[2] =
        (KeyboardAndLights_P.HILInitialize_EIQuadrature[1]);
      KeyboardAndLights_DW.HILInitialize_QuadratureModes[3] =
        (KeyboardAndLights_P.HILInitialize_EIQuadrature[1]);
      KeyboardAndLights_DW.HILInitialize_QuadratureModes[4] =
        (KeyboardAndLights_P.HILInitialize_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (KeyboardAndLights_DW.HILInitialize_Card,
         KeyboardAndLights_P.HILInitialize_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &KeyboardAndLights_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &KeyboardAndLights_DW.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] = KeyboardAndLights_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (KeyboardAndLights_DW.HILInitialize_Card,
         KeyboardAndLights_P.HILInitialize_EIChannels, 5U,
         &KeyboardAndLights_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    if ((KeyboardAndLights_P.HILInitialize_EIStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &KeyboardAndLights_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = KeyboardAndLights_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(KeyboardAndLights_DW.HILInitialize_Card,
        KeyboardAndLights_P.HILInitialize_EIChannels, 5U,
        &KeyboardAndLights_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    if ((KeyboardAndLights_P.HILInitialize_POPStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(KeyboardAndLights_DW.HILInitialize_Card,
        &KeyboardAndLights_P.HILInitialize_POChannels, 1U, (t_pwm_mode *)
        KeyboardAndLights_P.HILInitialize_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }

      if ((KeyboardAndLights_P.HILInitialize_POModes[0]) == PWM_DUTY_CYCLE_MODE ||
          (KeyboardAndLights_P.HILInitialize_POModes[0]) == PWM_ONE_SHOT_MODE ||
          (KeyboardAndLights_P.HILInitialize_POModes[0]) == PWM_TIME_MODE ||
          (KeyboardAndLights_P.HILInitialize_POModes[0]) == PWM_RAW_MODE) {
        KeyboardAndLights_DW.HILInitialize_POSortedChans =
          KeyboardAndLights_P.HILInitialize_POChannels;
        KeyboardAndLights_DW.HILInitialize_POSortedFreqs =
          KeyboardAndLights_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        KeyboardAndLights_DW.HILInitialize_POSortedChans =
          KeyboardAndLights_P.HILInitialize_POChannels;
        KeyboardAndLights_DW.HILInitialize_POSortedFreqs =
          KeyboardAndLights_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(KeyboardAndLights_DW.HILInitialize_Card,
          &KeyboardAndLights_DW.HILInitialize_POSortedChans,
          num_duty_cycle_modes,
          &KeyboardAndLights_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(KeyboardAndLights_DW.HILInitialize_Card,
          &KeyboardAndLights_DW.HILInitialize_POSortedChans, num_frequency_modes,
          &KeyboardAndLights_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration(KeyboardAndLights_DW.HILInitialize_Card,
        &KeyboardAndLights_P.HILInitialize_POChannels, 1U,
        (t_pwm_configuration *)
        &KeyboardAndLights_P.HILInitialize_POConfiguration,
        (t_pwm_alignment *) &KeyboardAndLights_P.HILInitialize_POAlignment,
        (t_pwm_polarity *) &KeyboardAndLights_P.HILInitialize_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    if ((KeyboardAndLights_P.HILInitialize_POStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_POEnter && is_switching)) {
      result = hil_write_pwm(KeyboardAndLights_DW.HILInitialize_Card,
        &KeyboardAndLights_P.HILInitialize_POChannels, 1U,
        &KeyboardAndLights_P.HILInitialize_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    if (KeyboardAndLights_P.HILInitialize_POReset) {
      result = hil_watchdog_set_pwm_expiration_state
        (KeyboardAndLights_DW.HILInitialize_Card,
         &KeyboardAndLights_P.HILInitialize_POChannels, 1U,
         &KeyboardAndLights_P.HILInitialize_POWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }

    if ((KeyboardAndLights_P.HILInitialize_OOStart && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &KeyboardAndLights_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = KeyboardAndLights_P.HILInitialize_OOInitial;
        }
      }

      result = hil_write_other(KeyboardAndLights_DW.HILInitialize_Card,
        KeyboardAndLights_P.HILInitialize_OOChannels, 13U,
        &KeyboardAndLights_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S6>/Unwrap 2^24' */

  /* S-Function Block: KeyboardAndLights/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
  {
    KeyboardAndLights_DW.Unwrap224_FirstSample = true;
    KeyboardAndLights_DW.Unwrap224_Revolutions = 0;
  }

  /* Start for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: KeyboardAndLights/Host Keyboard (host_keyboard_block) */
  {
    qthread_section_init(&KeyboardAndLights_DW.HostKeyboard_Lock, NULL);
  }

  /* S-Function Block: KeyboardAndLights/Host Initialize (host_initialize_block) */
  {
    t_error result;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    qthread_attr_t attributes;
    if (KeyboardAndLights_P.HostInitialize_ThreadPriority < min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (KeyboardAndLights_P.HostInitialize_ThreadPriority > max_priority)
    {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        KeyboardAndLights_P.HostInitialize_ThreadPriority;
    }

    qthread_attr_init(&attributes);
    result = qthread_attr_setschedpolicy(&attributes, QSCHED_FIFO);
    if (result == 0) {
      result = qthread_attr_setschedparam(&attributes, &scheduling_parameters);
      if (result == 0) {
        result = qthread_attr_setinheritsched(&attributes,
          QTHREAD_EXPLICIT_SCHED);
        if (result < 0) {
          rtmSetErrorStatus(KeyboardAndLights_M,
                            "Unable to set scheduling inheritance for host thread");
        }
      } else {
        rtmSetErrorStatus(KeyboardAndLights_M,
                          "The specified thread priority for the host thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(KeyboardAndLights_M,
                        "Unable to set scheduling policy for host thread");
    }

    result = host_remote_interface_open((const char *)
      KeyboardAndLights_P.HostInitialize_URI, host_connect_Host0x2D1,
      host_receive_Host0x2D1, host_disconnect_Host0x2D1,
      KeyboardAndLights_P.HostInitialize_SendBufferSize,
      KeyboardAndLights_P.HostInitialize_ReceiveBufferSiz, &attributes, NULL,
      &KeyboardAndLights_DW.HostInitialize_ConnectedHandle);
    KeyboardAndLights_B.HostInitialize_o1 = HOST_STATE_NOT_LISTENING;
    KeyboardAndLights_B.HostInitialize_o2 = result;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<S7>/Integrator1' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  if (rtmIsFirstInitCond(KeyboardAndLights_M)) {
    KeyboardAndLights_X.Integrator1_CSTATE = 0.0;
    KeyboardAndLights_X.Integrator1_CSTATE_a = 0.0;
  }

  KeyboardAndLights_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S7>/Integrator1' */

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  KeyboardAndLights_X.Integrator2_CSTATE = KeyboardAndLights_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  KeyboardAndLights_DW.Integrator1_IWORK_d = 1;

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  KeyboardAndLights_X.Integrator2_CSTATE_c =
    KeyboardAndLights_P.Integrator2_IC_o;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  if (rtmIsFirstInitCond(KeyboardAndLights_M)) {
    KeyboardAndLights_X.Integrator1_CSTATE_e = 0.0;
  }

  KeyboardAndLights_DW.Integrator1_IWORK_c = 1;

  /* End of InitializeConditions for Integrator: '<S9>/Integrator1' */

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  KeyboardAndLights_X.Integrator2_CSTATE_a =
    KeyboardAndLights_P.Integrator2_IC_n;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(KeyboardAndLights_M)) {
    rtmSetFirstInitCond(KeyboardAndLights_M, 0);
  }
}

/* Model terminate function */
void KeyboardAndLights_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S6>/HIL Initialize' */

  /* S-Function Block: KeyboardAndLights/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(KeyboardAndLights_DW.HILInitialize_Card);
    hil_monitor_stop_all(KeyboardAndLights_DW.HILInitialize_Card);
    is_switching = false;
    if ((KeyboardAndLights_P.HILInitialize_DOTerminate && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((KeyboardAndLights_P.HILInitialize_POTerminate && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_POExit && is_switching)) {
      num_final_pwm_outputs = 1U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((KeyboardAndLights_P.HILInitialize_OOTerminate && !is_switching) ||
        (KeyboardAndLights_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &KeyboardAndLights_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = KeyboardAndLights_P.HILInitialize_OOFinal;
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
      result = hil_write(KeyboardAndLights_DW.HILInitialize_Card
                         , NULL, 0
                         , &KeyboardAndLights_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &KeyboardAndLights_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , KeyboardAndLights_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &KeyboardAndLights_P.HILInitialize_POFinal
                         , (t_boolean *)
                         &KeyboardAndLights_P.HILInitialize_DOFinal
                         , &KeyboardAndLights_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(KeyboardAndLights_DW.HILInitialize_Card,
            &KeyboardAndLights_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &KeyboardAndLights_P.HILInitialize_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (KeyboardAndLights_DW.HILInitialize_Card,
             &KeyboardAndLights_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &KeyboardAndLights_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(KeyboardAndLights_DW.HILInitialize_Card,
            KeyboardAndLights_P.HILInitialize_OOChannels,
            num_final_other_outputs,
            &KeyboardAndLights_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(KeyboardAndLights_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(KeyboardAndLights_DW.HILInitialize_Card);
    hil_monitor_delete_all(KeyboardAndLights_DW.HILInitialize_Card);
    hil_close(KeyboardAndLights_DW.HILInitialize_Card);
    KeyboardAndLights_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (host_keyboard_block): '<Root>/Host Keyboard' */

  /* S-Function Block: KeyboardAndLights/Host Keyboard (host_keyboard_block) */
  {
    qthread_section_destroy(&KeyboardAndLights_DW.HostKeyboard_Lock);
  }

  /* Terminate for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: KeyboardAndLights/Host Initialize (host_initialize_block) */
  {
    host_remote_interface_close
      (KeyboardAndLights_DW.HostInitialize_ConnectedHandle);
    KeyboardAndLights_DW.HostInitialize_ConnectedHandle = NULL;
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
  KeyboardAndLights_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  KeyboardAndLights_update();
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
  KeyboardAndLights_initialize();
}

void MdlTerminate(void)
{
  KeyboardAndLights_terminate();
}

/* Registration function */
RT_MODEL_KeyboardAndLights_T *KeyboardAndLights(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)KeyboardAndLights_M, 0,
                sizeof(RT_MODEL_KeyboardAndLights_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&KeyboardAndLights_M->solverInfo,
                          &KeyboardAndLights_M->Timing.simTimeStep);
    rtsiSetTPtr(&KeyboardAndLights_M->solverInfo, &rtmGetTPtr
                (KeyboardAndLights_M));
    rtsiSetStepSizePtr(&KeyboardAndLights_M->solverInfo,
                       &KeyboardAndLights_M->Timing.stepSize0);
    rtsiSetdXPtr(&KeyboardAndLights_M->solverInfo, &KeyboardAndLights_M->derivs);
    rtsiSetContStatesPtr(&KeyboardAndLights_M->solverInfo, (real_T **)
                         &KeyboardAndLights_M->contStates);
    rtsiSetNumContStatesPtr(&KeyboardAndLights_M->solverInfo,
      &KeyboardAndLights_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&KeyboardAndLights_M->solverInfo,
      &KeyboardAndLights_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&KeyboardAndLights_M->solverInfo,
      &KeyboardAndLights_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&KeyboardAndLights_M->solverInfo,
      &KeyboardAndLights_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&KeyboardAndLights_M->solverInfo, (&rtmGetErrorStatus
      (KeyboardAndLights_M)));
    rtsiSetRTModelPtr(&KeyboardAndLights_M->solverInfo, KeyboardAndLights_M);
  }

  rtsiSetSimTimeStep(&KeyboardAndLights_M->solverInfo, MAJOR_TIME_STEP);
  KeyboardAndLights_M->intgData.y = KeyboardAndLights_M->odeY;
  KeyboardAndLights_M->intgData.f[0] = KeyboardAndLights_M->odeF[0];
  KeyboardAndLights_M->intgData.f[1] = KeyboardAndLights_M->odeF[1];
  KeyboardAndLights_M->contStates = ((real_T *) &KeyboardAndLights_X);
  rtsiSetSolverData(&KeyboardAndLights_M->solverInfo, (void *)
                    &KeyboardAndLights_M->intgData);
  rtsiSetSolverName(&KeyboardAndLights_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = KeyboardAndLights_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    KeyboardAndLights_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    KeyboardAndLights_M->Timing.sampleTimes =
      (&KeyboardAndLights_M->Timing.sampleTimesArray[0]);
    KeyboardAndLights_M->Timing.offsetTimes =
      (&KeyboardAndLights_M->Timing.offsetTimesArray[0]);

    /* task periods */
    KeyboardAndLights_M->Timing.sampleTimes[0] = (0.0);
    KeyboardAndLights_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    KeyboardAndLights_M->Timing.offsetTimes[0] = (0.0);
    KeyboardAndLights_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(KeyboardAndLights_M, &KeyboardAndLights_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = KeyboardAndLights_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    KeyboardAndLights_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(KeyboardAndLights_M, -1);
  KeyboardAndLights_M->Timing.stepSize0 = 0.002;
  KeyboardAndLights_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(KeyboardAndLights_M, 1);

  /* External mode info */
  KeyboardAndLights_M->Sizes.checksums[0] = (3277035697U);
  KeyboardAndLights_M->Sizes.checksums[1] = (2835672248U);
  KeyboardAndLights_M->Sizes.checksums[2] = (2422911687U);
  KeyboardAndLights_M->Sizes.checksums[3] = (3455002146U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    KeyboardAndLights_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(KeyboardAndLights_M->extModeInfo,
      &KeyboardAndLights_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(KeyboardAndLights_M->extModeInfo,
                        KeyboardAndLights_M->Sizes.checksums);
    rteiSetTPtr(KeyboardAndLights_M->extModeInfo, rtmGetTPtr(KeyboardAndLights_M));
  }

  KeyboardAndLights_M->solverInfoPtr = (&KeyboardAndLights_M->solverInfo);
  KeyboardAndLights_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&KeyboardAndLights_M->solverInfo, 0.002);
  rtsiSetSolverMode(&KeyboardAndLights_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  KeyboardAndLights_M->blockIO = ((void *) &KeyboardAndLights_B);
  (void) memset(((void *) &KeyboardAndLights_B), 0,
                sizeof(B_KeyboardAndLights_T));

  /* parameters */
  KeyboardAndLights_M->defaultParam = ((real_T *)&KeyboardAndLights_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &KeyboardAndLights_X;
    KeyboardAndLights_M->contStates = (x);
    (void) memset((void *)&KeyboardAndLights_X, 0,
                  sizeof(X_KeyboardAndLights_T));
  }

  /* states (dwork) */
  KeyboardAndLights_M->dwork = ((void *) &KeyboardAndLights_DW);
  (void) memset((void *)&KeyboardAndLights_DW, 0,
                sizeof(DW_KeyboardAndLights_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    KeyboardAndLights_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  KeyboardAndLights_M->Sizes.numContStates = (6);/* Number of continuous states */
  KeyboardAndLights_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  KeyboardAndLights_M->Sizes.numY = (0);/* Number of model outputs */
  KeyboardAndLights_M->Sizes.numU = (0);/* Number of model inputs */
  KeyboardAndLights_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  KeyboardAndLights_M->Sizes.numSampTimes = (2);/* Number of sample times */
  KeyboardAndLights_M->Sizes.numBlocks = (69);/* Number of blocks */
  KeyboardAndLights_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  KeyboardAndLights_M->Sizes.numBlockPrms = (191);/* Sum of parameter "widths" */
  return KeyboardAndLights_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
