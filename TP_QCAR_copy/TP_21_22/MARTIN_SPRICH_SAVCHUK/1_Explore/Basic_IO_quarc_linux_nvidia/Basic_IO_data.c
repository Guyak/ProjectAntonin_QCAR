/*
 * Basic_IO_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Basic_IO".
 *
 * Model version              : 5.1
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 10 09:27:03 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Basic_IO.h"
#include "Basic_IO_private.h"

/* Block parameters (default storage) */
P_Basic_IO_T Basic_IO_P = {
  /* Mask Parameter: Throttle02to02_gain
   * Referenced by: '<S4>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: Steeringrad05to05_gain
   * Referenced by: '<S3>/Slider Gain'
   */
  0.01,

  /* Mask Parameter: HILRead_analog_channels
   * Referenced by: '<S5>/HIL Read'
   */
  { 5U, 6U },

  /* Mask Parameter: HILWrite_digital_channels
   * Referenced by: '<S5>/HIL Write'
   */
  40U,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<S5>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S5>/HIL Write'
   */
  { 1000U, 11008U, 11009U, 11010U, 11011U, 11000U, 11001U, 11002U, 11003U },

  /* Mask Parameter: HILWrite_pwm_channels
   * Referenced by: '<S5>/HIL Write'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S5>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S5>/HIL Initialize'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<S5>/HIL Initialize'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<S5>/HIL Initialize'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<S5>/HIL Initialize'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant1'
   */
  1.0,

  /* Expression: 25
   * Referenced by: '<S5>/Constant2'
   */
  25.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant3'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S5>/Constant4'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant5'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S5>/Constant6'
   */
  100.0,

  /* Expression: 2
   * Referenced by: '<S6>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<S5>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S7>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S8>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S5>/direction convention'
   */
  -1.0,

  /* Expression: 0.20
   * Referenced by: '<S5>/command saturation'
   */
  0.2,

  /* Expression: -0.20
   * Referenced by: '<S5>/command saturation'
   */
  -0.2,

  /* Expression: 0
   * Referenced by: '<S5>/coast ON'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S5>/Gain'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Steering Bias'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S5>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S5>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  40U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<S5>/HIL Initialize'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S5>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S5>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<S5>/HIL Read'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S5>/HIL Write'
   */
  false,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  1U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<Root>/Manual Switch4'
   */
  1U,

  /* Computed Parameter: ManualSwitch5_CurrentSetting
   * Referenced by: '<Root>/Manual Switch5'
   */
  0U,

  /* Computed Parameter: ManualSwitch6_CurrentSetting
   * Referenced by: '<Root>/Manual Switch6'
   */
  0U,

  /* Computed Parameter: ManualSwitch7_CurrentSetting
   * Referenced by: '<Root>/Manual Switch7'
   */
  0U
};
