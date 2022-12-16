/*
 * Manual_Drive.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Manual_Drive".
 *
 * Model version              : 1.212
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 17 10:36:28 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Manual_Drive.h"
#include "Manual_Drive_private.h"
#include "Manual_Drive_dt.h"

/* Block signals (default storage) */
B_Manual_Drive_T Manual_Drive_B;

/* Continuous states */
X_Manual_Drive_T Manual_Drive_X;

/* Block states (default storage) */
DW_Manual_Drive_T Manual_Drive_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Manual_Drive_T Manual_Drive_PrevZCX;

/* Real-time model */
static RT_MODEL_Manual_Drive_T Manual_Drive_M_;
RT_MODEL_Manual_Drive_T *const Manual_Drive_M = &Manual_Drive_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Manual_Drive_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  Manual_Drive_output();
  Manual_Drive_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Manual_Drive_output(void)
{
  /* local block i/o variables */
  real_T rtb_GameController_o5;
  real_T rtb_GameController_o6;
  real_T rtb_GameController_o7;
  real_T rtb_GameController_o8;
  real_T rtb_GameController_o10[4];
  real_T rtb_motorcurrent;
  real_T rtb_batteryvoltage;
  real_T rtb_Abs;
  real_T rtb_commandsaturation;
  real_T rtb_TmpSignalConversionAtHILWri[9];
  real_T rtb_Switch;
  boolean_T rtb_AND1;
  boolean_T rtb_Compare_e;
  if (rtmIsMajorTimeStep(Manual_Drive_M)) {
    /* set solver stop time */
    if (!(Manual_Drive_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Manual_Drive_M->solverInfo,
                            ((Manual_Drive_M->Timing.clockTickH0 + 1) *
        Manual_Drive_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Manual_Drive_M->solverInfo,
                            ((Manual_Drive_M->Timing.clockTick0 + 1) *
        Manual_Drive_M->Timing.stepSize0 + Manual_Drive_M->Timing.clockTickH0 *
        Manual_Drive_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Manual_Drive_M)) {
    Manual_Drive_M->Timing.t[0] = rtsiGetT(&Manual_Drive_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Manual_Drive_DW.TriggeredSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(Manual_Drive_M)) {
    /* S-Function (hil_read_block): '<S3>/HIL Read' */

    /* S-Function Block: Manual_Drive/basicQCarIO/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILRead_analog_channels, 2U,
        &Manual_Drive_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &Manual_Drive_DW.HILRead_AnalogBuffer[0],
        &Manual_Drive_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      } else {
        rtb_motorcurrent = Manual_Drive_DW.HILRead_AnalogBuffer[0];
        rtb_batteryvoltage = Manual_Drive_DW.HILRead_AnalogBuffer[1];
        Manual_Drive_B.encodercounts = Manual_Drive_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S3>/Unwrap 2^24' */
    /* S-Function Block: Manual_Drive/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = Manual_Drive_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Manual_Drive_DW.Unwrap224_FirstSample) {
        Manual_Drive_DW.Unwrap224_FirstSample = false;
        Manual_Drive_DW.Unwrap224_PreviousInput = Manual_Drive_B.encodercounts;
      }

      du = (real_T) Manual_Drive_B.encodercounts -
        Manual_Drive_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Manual_Drive_DW.Unwrap224_Revolutions =
          Manual_Drive_DW.Unwrap224_Revolutions - 1;
        dy = du - Manual_Drive_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Manual_Drive_DW.Unwrap224_Revolutions =
          Manual_Drive_DW.Unwrap224_Revolutions + 1;
        dy = du + Manual_Drive_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Manual_Drive_B.Unwrap224 = Manual_Drive_B.encodercounts +
        Manual_Drive_DW.Unwrap224_Revolutions * Manual_Drive_P.Unwrap224_Modulus;
      Manual_Drive_DW.Unwrap224_PreviousInput = Manual_Drive_B.encodercounts;
    }
  }

  /* Integrator: '<S10>/Integrator1' */
  if (Manual_Drive_DW.Integrator1_IWORK != 0) {
    Manual_Drive_X.Integrator1_CSTATE = Manual_Drive_B.Unwrap224;
  }

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Integrator: '<S10>/Integrator1'
   *  Integrator: '<S10>/Integrator2'
   *  Product: '<S10>/Product2'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   */
  Manual_Drive_B.Product = ((Manual_Drive_B.Unwrap224 -
    Manual_Drive_X.Integrator1_CSTATE) - Manual_Drive_X.Integrator2_CSTATE *
    Manual_Drive_P.Constant_Value_p * Manual_Drive_P.Constant1_Value_b) *
    Manual_Drive_P.Constant2_Value_n;

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Integrator: '<S10>/Integrator2'
   */
  Manual_Drive_B.Product1 = Manual_Drive_P.Constant2_Value_n *
    Manual_Drive_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(Manual_Drive_M)) {
    /* S-Function (game_controller_block): '<S6>/Game Controller' */

    /* S-Function Block: Manual_Drive/gamepadViaTarget/Game Controller (game_controller_block) */
    {
      if (Manual_Drive_P.GameController_Enabled) {
        t_game_controller_states state;
        t_boolean new_data;
        t_error result;
        result = game_controller_poll(Manual_Drive_DW.GameController_Controller,
          &state, &new_data);
        if (result < 0) {
          new_data = false;
        }

        Manual_Drive_B.GameController_o1 = new_data;

        {
          int_T i1;
          boolean_T *y1 = &Manual_Drive_B.GameController_o2[0];
          for (i1=0; i1 < 32; i1++) {
            y1[i1] = ((state.buttons & (1U << i1)) != 0);
          }
        }

        rtb_Abs = state.x;
        rtb_GameController_o5 = state.y;
        rtb_GameController_o6 = state.z;
        rtb_GameController_o7 = state.rx;
        rtb_GameController_o8 = state.ry;
        rtb_commandsaturation = state.rz;
        rtb_GameController_o10[0] = state.point_of_views[0];
        rtb_GameController_o10[1] = state.point_of_views[1];
        rtb_GameController_o10[2] = state.point_of_views[2];
        rtb_GameController_o10[3] = state.point_of_views[3];
      } else {
        Manual_Drive_B.GameController_o1 = false;

        {
          int_T i1;
          boolean_T *y1 = &Manual_Drive_B.GameController_o2[0];
          for (i1=0; i1 < 32; i1++) {
            y1[i1] = false;
          }
        }

        rtb_Abs = 0;
        rtb_GameController_o5 = 0;
        rtb_GameController_o6 = 0;
        rtb_GameController_o7 = 0;
        rtb_GameController_o8 = 0;
        rtb_commandsaturation = 0;
        rtb_GameController_o10[0] = -1;
        rtb_GameController_o10[1] = -1;
        rtb_GameController_o10[2] = -1;
        rtb_GameController_o10[3] = -1;
      }
    }

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_Compare_e = (rtb_commandsaturation != Manual_Drive_P.Constant_Value_f);

    /* Outputs for Triggered SubSystem: '<S6>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S15>/Trigger'
     */
    if (rtmIsMajorTimeStep(Manual_Drive_M)) {
      if (rtb_Compare_e && (Manual_Drive_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
                            1)) {
        /* SignalConversion generated from: '<S15>/Enabled' incorporates:
         *  Constant: '<S15>/Constant'
         */
        Manual_Drive_B.OutportBufferForEnabled = Manual_Drive_P.Constant_Value_d;
        Manual_Drive_DW.TriggeredSubsystem_SubsysRanBC = 4;
      }

      Manual_Drive_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Compare_e;
    }

    /* End of Outputs for SubSystem: '<S6>/Triggered Subsystem' */

    /* Switch: '<S6>/Switch' */
    if (!(Manual_Drive_B.OutportBufferForEnabled >
          Manual_Drive_P.Switch_Threshold)) {
      /* Saturate: '<S3>/command saturation' incorporates:
       *  Constant: '<S6>/Constant'
       */
      rtb_commandsaturation = Manual_Drive_P.Constant_Value;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     *  RelationalOperator: '<S11>/Compare'
     */
    if (Manual_Drive_B.GameController_o2[4] ==
        Manual_Drive_P.CompareToConstant1_const_o) {
      /* Switch: '<S5>/Switch1' incorporates:
       *  Constant: '<S12>/Constant'
       *  RelationalOperator: '<S12>/Compare'
       */
      if (Manual_Drive_B.GameController_o2[0] ==
          Manual_Drive_P.CompareToConstant2_const_a) {
        /* Saturate: '<S3>/command saturation' incorporates:
         *  Bias: '<S6>/Bias'
         *  Gain: '<S5>/Gain1'
         *  Gain: '<S6>/Gain3'
         */
        rtb_commandsaturation = (rtb_commandsaturation +
          Manual_Drive_P.Bias_Bias) * Manual_Drive_P.Gain3_Gain *
          Manual_Drive_P.Gain1_Gain;
      } else {
        /* Saturate: '<S3>/command saturation' incorporates:
         *  Bias: '<S6>/Bias'
         *  Gain: '<S6>/Gain3'
         */
        rtb_commandsaturation = (rtb_commandsaturation +
          Manual_Drive_P.Bias_Bias) * Manual_Drive_P.Gain3_Gain;
      }

      /* End of Switch: '<S5>/Switch1' */
    } else {
      /* Saturate: '<S3>/command saturation' incorporates:
       *  Constant: '<S5>/Constant2'
       */
      rtb_commandsaturation = Manual_Drive_P.Constant2_Value;
    }

    /* End of Switch: '<S5>/Switch' */

    /* Product: '<S5>/Product3' incorporates:
     *  Constant: '<Root>/True'
     */
    Manual_Drive_B.Product3 = Manual_Drive_P.True_Value * rtb_commandsaturation;

    /* Saturate: '<S3>/command saturation' incorporates:
     *  Gain: '<S3>/direction convention'
     *  Gain: '<S3>/scale output  to max range'
     */
    rtb_commandsaturation = Manual_Drive_P.directionconvention_Gain *
      Manual_Drive_B.Product3 * Manual_Drive_P.scaleoutputtomaxrange_Gain;

    /* Saturate: '<S3>/command saturation' */
    if (rtb_commandsaturation > Manual_Drive_P.commandsaturation_UpperSat) {
      /* Saturate: '<S3>/command saturation' */
      rtb_commandsaturation = Manual_Drive_P.commandsaturation_UpperSat;
    } else if (rtb_commandsaturation < Manual_Drive_P.commandsaturation_LowerSat)
    {
      /* Saturate: '<S3>/command saturation' */
      rtb_commandsaturation = Manual_Drive_P.commandsaturation_LowerSat;
    }

    /* End of Saturate: '<S3>/command saturation' */

    /* Abs: '<S7>/Abs' incorporates:
     *  Constant: '<Root>/True'
     *  Gain: '<S5>/ remapping to steering range '
     *  Gain: '<S6>/Gain4'
     *  Product: '<S5>/Product4'
     */
    rtb_Abs = Manual_Drive_P.Gain4_Gain * rtb_Abs * Manual_Drive_P.True_Value *
      Manual_Drive_P.remappingtosteeringrange_Gain;

    /* Product: '<S5>/Product1' */
    rtb_Switch = (real_T)Manual_Drive_B.GameController_o2[4] * rtb_Abs;

    /* Abs: '<S7>/Abs' incorporates:
     *  DiscretePulseGenerator: '<S7>/Pulsing Light'
     */
    rtb_Abs = (Manual_Drive_DW.clockTickCounter <
               Manual_Drive_P.PulsingLight_Duty) &&
      (Manual_Drive_DW.clockTickCounter >= 0) ? Manual_Drive_P.PulsingLight_Amp :
      0.0;

    /* DiscretePulseGenerator: '<S7>/Pulsing Light' */
    if (Manual_Drive_DW.clockTickCounter >= Manual_Drive_P.PulsingLight_Period -
        1.0) {
      Manual_Drive_DW.clockTickCounter = 0;
    } else {
      Manual_Drive_DW.clockTickCounter++;
    }

    /* Logic: '<S7>/AND3' incorporates:
     *  Constant: '<S19>/Constant'
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     *  RelationalOperator: '<S19>/Compare'
     */
    rtb_Compare_e = ((rtb_Switch > Manual_Drive_P.LeftSteeringLimit_const) &&
                     (rtb_Abs != 0.0));

    /* Logic: '<S7>/AND1' incorporates:
     *  Constant: '<S21>/Constant'
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     *  RelationalOperator: '<S21>/Compare'
     */
    rtb_AND1 = ((rtb_Switch < Manual_Drive_P.RightSteeringLimit_const) &&
                (rtb_Abs != 0.0));

    /* Abs: '<S7>/Abs' incorporates:
     *  Memory: '<S7>/Memory'
     */
    rtb_Abs = Manual_Drive_DW.Memory_PreviousInput;
    rtb_Abs = fabs(rtb_Abs);

    /* RelationalOperator: '<S18>/Compare' incorporates:
     *  Abs: '<S7>/Abs1'
     *  Constant: '<S18>/Constant'
     *  Sum: '<S7>/Subtract'
     */
    Manual_Drive_B.Compare = (fabs(Manual_Drive_B.Product3) - rtb_Abs <
      Manual_Drive_P.CompareToConstant3_const);

    /* S-Function (one_shot_block): '<S20>/one_shot_block' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    if (Manual_Drive_P.one_shot_block_trigger_type == 1.0 &&
        Manual_Drive_B.Compare - Manual_Drive_DW.one_shot_block_DSTATE[2] > 0 )
    {
      if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
          Manual_Drive_P.one_shot_block_redun_pulse == 1.0 ) {
      } else if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
                 Manual_Drive_P.one_shot_block_redun_pulse == 2.0 ) {
        Manual_Drive_DW.one_shot_block_DSTATE[1] = 0.0;
      } else {
        Manual_Drive_DW.one_shot_block_DSTATE[0] = 1.0;
      }
    } else if (Manual_Drive_P.one_shot_block_trigger_type == 2.0 &&
               Manual_Drive_B.Compare - Manual_Drive_DW.one_shot_block_DSTATE[2]
               < 0 ) {
      if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
          Manual_Drive_P.one_shot_block_redun_pulse == 1.0 ) {
      } else if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
                 Manual_Drive_P.one_shot_block_redun_pulse == 2.0 ) {
        Manual_Drive_DW.one_shot_block_DSTATE[1] = 0.0;
      } else {
        Manual_Drive_DW.one_shot_block_DSTATE[0] = 1.0;
      }
    } else if ((Manual_Drive_P.one_shot_block_trigger_type == 3.0 &&
                Manual_Drive_B.Compare - Manual_Drive_DW.one_shot_block_DSTATE[2]
                < 0 ) ||
               (Manual_Drive_P.one_shot_block_trigger_type == 3.0 &&
                Manual_Drive_B.Compare - Manual_Drive_DW.one_shot_block_DSTATE[2]
                > 0 ) ) {
      if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
          Manual_Drive_P.one_shot_block_redun_pulse == 1.0 ) {
      } else if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
                 Manual_Drive_P.one_shot_block_redun_pulse == 2.0 ) {
        Manual_Drive_DW.one_shot_block_DSTATE[1] = 0.0;
      } else {
        Manual_Drive_DW.one_shot_block_DSTATE[0] = 1.0;
      }
    }

    Manual_Drive_DW.one_shot_block_DSTATE[2] = Manual_Drive_B.Compare ;
    if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
        Manual_Drive_DW.one_shot_block_DSTATE[1] <
        Manual_Drive_P.Constant2_Value_j ) {
      Manual_Drive_DW.one_shot_block_DSTATE[1] += 1.0;
      Manual_Drive_B.one_shot_block = 1.0;
    } else if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 1.0 &&
               Manual_Drive_DW.one_shot_block_DSTATE[1] >=
               Manual_Drive_P.Constant2_Value_j ) {
      Manual_Drive_DW.one_shot_block_DSTATE[0] = 0.0;
      Manual_Drive_DW.one_shot_block_DSTATE[1] = 0.0;
      Manual_Drive_B.one_shot_block = 0.0;
    } else if (Manual_Drive_DW.one_shot_block_DSTATE[0] == 0.0 ) {
      Manual_Drive_DW.one_shot_block_DSTATE[1] = 0.0;
      Manual_Drive_B.one_shot_block = 0.0;
    }

    /* SignalConversion generated from: '<S3>/HIL Write' incorporates:
     *  Bias: '<S3>/Steering Bias'
     *  DataTypeConversion: '<S7>/Data Type Conversion1'
     *  Gain: '<S3>/Gain'
     */
    rtb_TmpSignalConversionAtHILWri[0] = Manual_Drive_P.Gain_Gain * rtb_Switch +
      Manual_Drive_P.SteeringBias_Bias;
    rtb_TmpSignalConversionAtHILWri[1] = rtb_Compare_e;
    rtb_TmpSignalConversionAtHILWri[2] = rtb_AND1;
    rtb_TmpSignalConversionAtHILWri[3] = rtb_Compare_e;
    rtb_TmpSignalConversionAtHILWri[4] = rtb_AND1;

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     */
    if (Manual_Drive_B.one_shot_block >= Manual_Drive_P.Switch_Threshold_f) {
      rtb_Switch = Manual_Drive_P.Constant1_Value;
    } else {
      rtb_Switch = Manual_Drive_P.Constant_Value_b;
    }

    /* End of Switch: '<S20>/Switch' */

    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S16>/Constant'
     *  Logic: '<S7>/AND2'
     *  RelationalOperator: '<S16>/Compare'
     */
    if ((rtb_Switch != 0.0) || (Manual_Drive_B.Product3 ==
         Manual_Drive_P.CompareToConstant1_const)) {
      /* SignalConversion generated from: '<S3>/HIL Write' incorporates:
       *  Constant: '<S7>/Steady Light'
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       */
      rtb_TmpSignalConversionAtHILWri[5] = Manual_Drive_P.SteadyLight_Value;
    } else {
      /* SignalConversion generated from: '<S3>/HIL Write' incorporates:
       *  Constant: '<S7>/Light Off'
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       */
      rtb_TmpSignalConversionAtHILWri[5] = Manual_Drive_P.LightOff_Value;
    }

    /* End of Switch: '<S7>/Switch2' */

    /* SignalConversion generated from: '<S3>/HIL Write' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S7>/Steady Light'
     *  DataTypeConversion: '<S7>/Data Type Conversion1'
     *  RelationalOperator: '<S17>/Compare'
     */
    rtb_TmpSignalConversionAtHILWri[6] = (Manual_Drive_B.Product3 <
      Manual_Drive_P.CompareToConstant2_const);
    rtb_TmpSignalConversionAtHILWri[7] = Manual_Drive_P.SteadyLight_Value;
    rtb_TmpSignalConversionAtHILWri[8] = Manual_Drive_P.SteadyLight_Value;

    /* S-Function (hil_write_block): '<S3>/HIL Write' incorporates:
     *  Constant: '<S3>/coast ON'
     */

    /* S-Function Block: Manual_Drive/basicQCarIO/HIL Write (hil_write_block) */
    {
      t_error result;
      Manual_Drive_DW.HILWrite_DigitalBuffer = (Manual_Drive_P.coastON_Value !=
        0);
      result = hil_write(Manual_Drive_DW.HILInitialize_Card,
                         NULL, 0U,
                         &Manual_Drive_P.HILWrite_pwm_channels, 1U,
                         &Manual_Drive_P.HILWrite_digital_channels, 1U,
                         Manual_Drive_P.HILWrite_other_channels, 9U,
                         NULL,
                         &rtb_commandsaturation,
                         &Manual_Drive_DW.HILWrite_DigitalBuffer,
                         &rtb_TmpSignalConversionAtHILWri[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      }
    }

    /* Product: '<S9>/Product' */
    Manual_Drive_B.Product_d = rtb_motorcurrent * rtb_batteryvoltage;

    /* Gain: '<S9>/Gain' incorporates:
     *  Constant: '<S9>/max voltage'
     *  Constant: '<S9>/min voltage'
     *  Product: '<S9>/Divide'
     *  Sum: '<S9>/Subtract'
     *  Sum: '<S9>/Subtract1'
     */
    Manual_Drive_B.Gain = (rtb_batteryvoltage - Manual_Drive_P.minvoltage_Value)
      / (Manual_Drive_P.maxvoltage_Value - Manual_Drive_P.minvoltage_Value) *
      Manual_Drive_P.Gain_Gain_i;
  }

  /* Gain: '<S4>/wheel radius' incorporates:
   *  Gain: '<S4>/counts to rotations'
   *  Gain: '<S4>/gear ratios'
   *  Gain: '<S4>/rot//s to rad//s'
   */
  Manual_Drive_B.wheelspeedms = Manual_Drive_P.countstorotations_Gain *
    Manual_Drive_B.Product1 * Manual_Drive_P.gearratios_Gain *
    Manual_Drive_P.rotstorads_Gain * Manual_Drive_P.wheelradius_Gain;
  if (rtmIsMajorTimeStep(Manual_Drive_M)) {
    /* S-Function (sample_time_block): '<S8>/Sample Time' */

    /* S-Function Block: Manual_Drive/monitorTiming /Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &Manual_Drive_DW.SampleTime_PreviousTime);
        Manual_Drive_B.actualsampletime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&Manual_Drive_DW.SampleTime_PreviousTime, &current_time, sizeof
               (t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    /* Constant: '<S8>/Constant' */
    Manual_Drive_B.reference = Manual_Drive_P.Constant_Value_b3;

    /* S-Function (computation_time_block): '<S8>/Computation Time' */

    /* S-Function Block: Manual_Drive/monitorTiming /Computation Time (computation_time_block) */
    {
      Manual_Drive_B.computationtime =
        Manual_Drive_DW.ComputationTime_ComputationTime.seconds +
        Manual_Drive_DW.ComputationTime_ComputationTime.nanoseconds * 1e-9;
    }
  }
}

/* Model update function */
void Manual_Drive_update(void)
{
  /* Update for Integrator: '<S10>/Integrator1' */
  Manual_Drive_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(Manual_Drive_M)) {
    /* Update for Memory: '<S7>/Memory' */
    Manual_Drive_DW.Memory_PreviousInput = Manual_Drive_B.Product3;
  }

  if (rtmIsMajorTimeStep(Manual_Drive_M)) {
    rt_ertODEUpdateContinuousStates(&Manual_Drive_M->solverInfo);
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
  if (!(++Manual_Drive_M->Timing.clockTick0)) {
    ++Manual_Drive_M->Timing.clockTickH0;
  }

  Manual_Drive_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Manual_Drive_M->solverInfo);

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
    if (!(++Manual_Drive_M->Timing.clockTick1)) {
      ++Manual_Drive_M->Timing.clockTickH1;
    }

    Manual_Drive_M->Timing.t[1] = Manual_Drive_M->Timing.clockTick1 *
      Manual_Drive_M->Timing.stepSize1 + Manual_Drive_M->Timing.clockTickH1 *
      Manual_Drive_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Manual_Drive_derivatives(void)
{
  XDot_Manual_Drive_T *_rtXdot;
  _rtXdot = ((XDot_Manual_Drive_T *) Manual_Drive_M->derivs);

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Manual_Drive_B.Product1;

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Manual_Drive_B.Product;
}

/* Model initialize function */
void Manual_Drive_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: Manual_Drive/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Manual_Drive_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Manual_Drive_DW.HILInitialize_Card,
      "gyro_fs=250;gyro_rate=64;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
      251);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Manual_Drive_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      return;
    }

    if ((Manual_Drive_P.HILInitialize_AIPStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Manual_Drive_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Manual_Drive_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Manual_Drive_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Manual_Drive_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILInitialize_AIChannels, 7U,
        &Manual_Drive_DW.HILInitialize_AIMinimums[0],
        &Manual_Drive_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Manual_Drive_DW.HILInitialize_Card,
      Manual_Drive_P.HILInitialize_DIChannels, 20U,
      &Manual_Drive_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      return;
    }

    if ((Manual_Drive_P.HILInitialize_DOStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Manual_Drive_DW.HILInitialize_Card,
        &Manual_Drive_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Manual_Drive_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_Drive_P.HILInitialize_EIPStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_EIPEnter && is_switching)) {
      Manual_Drive_DW.HILInitialize_QuadratureModes[0] =
        (Manual_Drive_P.HILInitialize_EIQuadrature[0]);
      Manual_Drive_DW.HILInitialize_QuadratureModes[1] =
        (Manual_Drive_P.HILInitialize_EIQuadrature[1]);
      Manual_Drive_DW.HILInitialize_QuadratureModes[2] =
        (Manual_Drive_P.HILInitialize_EIQuadrature[1]);
      Manual_Drive_DW.HILInitialize_QuadratureModes[3] =
        (Manual_Drive_P.HILInitialize_EIQuadrature[1]);
      Manual_Drive_DW.HILInitialize_QuadratureModes[4] =
        (Manual_Drive_P.HILInitialize_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (Manual_Drive_DW.HILInitialize_Card,
         Manual_Drive_P.HILInitialize_EIChannels, 5U, (t_encoder_quadrature_mode
          *) &Manual_Drive_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &Manual_Drive_DW.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] = Manual_Drive_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (Manual_Drive_DW.HILInitialize_Card,
         Manual_Drive_P.HILInitialize_EIChannels, 5U,
         &Manual_Drive_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_Drive_P.HILInitialize_EIStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Manual_Drive_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = Manual_Drive_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILInitialize_EIChannels, 5U,
        &Manual_Drive_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_Drive_P.HILInitialize_POPStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      Manual_Drive_DW.HILInitialize_POModeValues[0] =
        (Manual_Drive_P.HILInitialize_POModes[0]);

      {
        int_T i1;
        int32_T *dw_POModeValues = &Manual_Drive_DW.HILInitialize_POModeValues[1];
        for (i1=0; i1 < 7; i1++) {
          dw_POModeValues[i1] = (Manual_Drive_P.HILInitialize_POModes[1]);
        }
      }

      result = hil_set_pwm_mode(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Manual_Drive_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Manual_Drive_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &Manual_Drive_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Manual_Drive_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            Manual_Drive_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Manual_Drive_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Manual_Drive_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = (p_HILInitialize_POChannels[i1]);
            Manual_Drive_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = Manual_Drive_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Manual_Drive_DW.HILInitialize_Card,
          &Manual_Drive_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Manual_Drive_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Manual_Drive_DW.HILInitialize_Card,
          &Manual_Drive_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Manual_Drive_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Manual_Drive_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Manual_Drive_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Manual_Drive_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Manual_Drive_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Manual_Drive_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Manual_Drive_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &Manual_Drive_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Manual_Drive_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Manual_Drive_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_Drive_P.HILInitialize_POStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Manual_Drive_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Manual_Drive_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILInitialize_POChannels, 8U,
        &Manual_Drive_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    if (Manual_Drive_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Manual_Drive_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Manual_Drive_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Manual_Drive_DW.HILInitialize_Card,
         Manual_Drive_P.HILInitialize_POChannels, 8U,
         &Manual_Drive_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_Drive_P.HILInitialize_OOStart && !is_switching) ||
        (Manual_Drive_P.HILInitialize_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Manual_Drive_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Manual_Drive_P.HILInitialize_OOInitial;
        }
      }

      result = hil_write_other(Manual_Drive_DW.HILInitialize_Card,
        Manual_Drive_P.HILInitialize_OOChannels, 13U,
        &Manual_Drive_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S3>/Unwrap 2^24' */

  /* S-Function Block: Manual_Drive/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
  {
    Manual_Drive_DW.Unwrap224_FirstSample = true;
    Manual_Drive_DW.Unwrap224_Revolutions = 0;
  }

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: Manual_Drive/gamepadViaTarget/Game Controller (game_controller_block) */
  {
    if (Manual_Drive_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (Manual_Drive_P.GameController_ControllerNumber,
         Manual_Drive_P.GameController_BufferSize, deadzone, saturation,
         Manual_Drive_P.GameController_AutoCenter, 0, 1.0,
         &Manual_Drive_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      }
    }
  }

  /* Start for S-Function (sample_time_block): '<S8>/Sample Time' */

  /* S-Function Block: Manual_Drive/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Manual_Drive_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
      return;
    }
  }

  Manual_Drive_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  if (rtmIsFirstInitCond(Manual_Drive_M)) {
    Manual_Drive_X.Integrator1_CSTATE = 0.0;
  }

  Manual_Drive_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S10>/Integrator1' */

  /* InitializeConditions for Integrator: '<S10>/Integrator2' */
  Manual_Drive_X.Integrator2_CSTATE = Manual_Drive_P.Integrator2_IC;

  /* InitializeConditions for DiscretePulseGenerator: '<S7>/Pulsing Light' */
  Manual_Drive_DW.clockTickCounter = 0;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  Manual_Drive_DW.Memory_PreviousInput = Manual_Drive_P.Memory_InitialCondition;

  /* InitializeConditions for S-Function (one_shot_block): '<S20>/one_shot_block' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  {
    Manual_Drive_DW.one_shot_block_DSTATE[0] = 0.0;
    Manual_Drive_DW.one_shot_block_DSTATE[1] = 0.0;
    Manual_Drive_DW.one_shot_block_DSTATE[2] = 0.0;
  }

  /* SystemInitialize for Triggered SubSystem: '<S6>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S15>/Enabled' incorporates:
   *  Outport: '<S15>/Enabled'
   */
  Manual_Drive_B.OutportBufferForEnabled = Manual_Drive_P.Enabled_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/Triggered Subsystem' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Manual_Drive_M)) {
    rtmSetFirstInitCond(Manual_Drive_M, 0);
  }
}

/* Model terminate function */
void Manual_Drive_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: Manual_Drive/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Manual_Drive_DW.HILInitialize_Card);
    hil_monitor_stop_all(Manual_Drive_DW.HILInitialize_Card);
    is_switching = false;
    if ((Manual_Drive_P.HILInitialize_DOTerminate && !is_switching) ||
        (Manual_Drive_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Manual_Drive_P.HILInitialize_POTerminate && !is_switching) ||
        (Manual_Drive_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Manual_Drive_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Manual_Drive_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Manual_Drive_P.HILInitialize_OOTerminate && !is_switching) ||
        (Manual_Drive_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Manual_Drive_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Manual_Drive_P.HILInitialize_OOFinal;
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
      result = hil_write(Manual_Drive_DW.HILInitialize_Card
                         , NULL, 0
                         , Manual_Drive_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &Manual_Drive_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Manual_Drive_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Manual_Drive_DW.HILInitialize_POValues[0]
                         , (t_boolean *) &Manual_Drive_P.HILInitialize_DOFinal
                         , &Manual_Drive_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Manual_Drive_DW.HILInitialize_Card,
            Manual_Drive_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Manual_Drive_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Manual_Drive_DW.HILInitialize_Card,
            &Manual_Drive_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Manual_Drive_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Manual_Drive_DW.HILInitialize_Card,
            Manual_Drive_P.HILInitialize_OOChannels, num_final_other_outputs,
            &Manual_Drive_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Manual_Drive_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Manual_Drive_DW.HILInitialize_Card);
    hil_monitor_delete_all(Manual_Drive_DW.HILInitialize_Card);
    hil_close(Manual_Drive_DW.HILInitialize_Card);
    Manual_Drive_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: Manual_Drive/gamepadViaTarget/Game Controller (game_controller_block) */
  {
    if (Manual_Drive_P.GameController_Enabled) {
      game_controller_close(Manual_Drive_DW.GameController_Controller);
      Manual_Drive_DW.GameController_Controller = NULL;
    }
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
  Manual_Drive_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Manual_Drive_update();
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
  Manual_Drive_initialize();
}

void MdlTerminate(void)
{
  Manual_Drive_terminate();
}

/* Registration function */
RT_MODEL_Manual_Drive_T *Manual_Drive(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Manual_Drive_M, 0,
                sizeof(RT_MODEL_Manual_Drive_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Manual_Drive_M->solverInfo,
                          &Manual_Drive_M->Timing.simTimeStep);
    rtsiSetTPtr(&Manual_Drive_M->solverInfo, &rtmGetTPtr(Manual_Drive_M));
    rtsiSetStepSizePtr(&Manual_Drive_M->solverInfo,
                       &Manual_Drive_M->Timing.stepSize0);
    rtsiSetdXPtr(&Manual_Drive_M->solverInfo, &Manual_Drive_M->derivs);
    rtsiSetContStatesPtr(&Manual_Drive_M->solverInfo, (real_T **)
                         &Manual_Drive_M->contStates);
    rtsiSetNumContStatesPtr(&Manual_Drive_M->solverInfo,
      &Manual_Drive_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Manual_Drive_M->solverInfo,
      &Manual_Drive_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Manual_Drive_M->solverInfo,
      &Manual_Drive_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Manual_Drive_M->solverInfo,
      &Manual_Drive_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Manual_Drive_M->solverInfo, (&rtmGetErrorStatus
      (Manual_Drive_M)));
    rtsiSetRTModelPtr(&Manual_Drive_M->solverInfo, Manual_Drive_M);
  }

  rtsiSetSimTimeStep(&Manual_Drive_M->solverInfo, MAJOR_TIME_STEP);
  Manual_Drive_M->intgData.y = Manual_Drive_M->odeY;
  Manual_Drive_M->intgData.f[0] = Manual_Drive_M->odeF[0];
  Manual_Drive_M->intgData.f[1] = Manual_Drive_M->odeF[1];
  Manual_Drive_M->contStates = ((real_T *) &Manual_Drive_X);
  rtsiSetSolverData(&Manual_Drive_M->solverInfo, (void *)
                    &Manual_Drive_M->intgData);
  rtsiSetSolverName(&Manual_Drive_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Manual_Drive_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Manual_Drive_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Manual_Drive_M->Timing.sampleTimes =
      (&Manual_Drive_M->Timing.sampleTimesArray[0]);
    Manual_Drive_M->Timing.offsetTimes =
      (&Manual_Drive_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Manual_Drive_M->Timing.sampleTimes[0] = (0.0);
    Manual_Drive_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Manual_Drive_M->Timing.offsetTimes[0] = (0.0);
    Manual_Drive_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Manual_Drive_M, &Manual_Drive_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Manual_Drive_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Manual_Drive_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Manual_Drive_M, -1);
  Manual_Drive_M->Timing.stepSize0 = 0.002;
  Manual_Drive_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(Manual_Drive_M, 1);

  /* External mode info */
  Manual_Drive_M->Sizes.checksums[0] = (3049118402U);
  Manual_Drive_M->Sizes.checksums[1] = (3686269761U);
  Manual_Drive_M->Sizes.checksums[2] = (3026522845U);
  Manual_Drive_M->Sizes.checksums[3] = (2355600375U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    Manual_Drive_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Manual_Drive_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Manual_Drive_M->extModeInfo,
      &Manual_Drive_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Manual_Drive_M->extModeInfo,
                        Manual_Drive_M->Sizes.checksums);
    rteiSetTPtr(Manual_Drive_M->extModeInfo, rtmGetTPtr(Manual_Drive_M));
  }

  Manual_Drive_M->solverInfoPtr = (&Manual_Drive_M->solverInfo);
  Manual_Drive_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Manual_Drive_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Manual_Drive_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Manual_Drive_M->blockIO = ((void *) &Manual_Drive_B);
  (void) memset(((void *) &Manual_Drive_B), 0,
                sizeof(B_Manual_Drive_T));

  /* parameters */
  Manual_Drive_M->defaultParam = ((real_T *)&Manual_Drive_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Manual_Drive_X;
    Manual_Drive_M->contStates = (x);
    (void) memset((void *)&Manual_Drive_X, 0,
                  sizeof(X_Manual_Drive_T));
  }

  /* states (dwork) */
  Manual_Drive_M->dwork = ((void *) &Manual_Drive_DW);
  (void) memset((void *)&Manual_Drive_DW, 0,
                sizeof(DW_Manual_Drive_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Manual_Drive_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Manual_Drive_M->Sizes.numContStates = (2);/* Number of continuous states */
  Manual_Drive_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Manual_Drive_M->Sizes.numY = (0);    /* Number of model outputs */
  Manual_Drive_M->Sizes.numU = (0);    /* Number of model inputs */
  Manual_Drive_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Manual_Drive_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Manual_Drive_M->Sizes.numBlocks = (102);/* Number of blocks */
  Manual_Drive_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  Manual_Drive_M->Sizes.numBlockPrms = (182);/* Sum of parameter "widths" */
  return Manual_Drive_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
