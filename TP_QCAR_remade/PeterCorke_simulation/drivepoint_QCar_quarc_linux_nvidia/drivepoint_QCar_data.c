/*
 * drivepoint_QCar_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "drivepoint_QCar".
 *
 * Model version              : 4.14
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 23 17:44:10 2023
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "drivepoint_QCar.h"
#include "drivepoint_QCar_private.h"

/* Block parameters (default storage) */
P_drivepoint_QCar_T drivepoint_QCar_P = {
  /* Variable: x0
   * Referenced by: '<S1>/Integrator'
   */
  { 0.0, 0.0, -3.1415926535897931 },

  /* Variable: xg
   * Referenced by: '<Root>/Goal position'
   */
  { 1.0, 1.0 },

  /* Mask Parameter: arewethereyet_const
   * Referenced by: '<S5>/Constant'
   */
  0.1,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<Root>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<Root>/HIL Write'
   */
  1000U,

  /* Mask Parameter: HILRead_other_channels
   * Referenced by: '<Root>/HIL Read'
   */
  3002U,

  /* Mask Parameter: HILWrite_pwm_channels
   * Referenced by: '<Root>/HIL Write'
   */
  0U,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/velocity gain Kv'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S7>/command saturation'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S7>/command saturation'
   */
  -0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S7>/Kff  (% // m//s)'
   */
  0.1,

  /* Expression: 25
   * Referenced by: '<Root>/Constant2'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator2'
   */
  0.0,

  /* Expression: 1/720/4
   * Referenced by: '<S6>/counts to rotations'
   */
  0.00034722222222222224,

  /* Expression: (13*19)/(70*37)
   * Referenced by: '<S6>/gear ratios'
   */
  0.095366795366795362,

  /* Expression: 2*pi
   * Referenced by: '<S6>/rot//s to rad//s'
   */
  6.2831853071795862,

  /* Expression: 0.0342
   * Referenced by: '<S6>/wheel radius'
   */
  0.0342,

  /* Expression: 1
   * Referenced by: '<S6>/Offset'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<S7>/Kp (% // m//s)'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S7>/Integrator1'
   */
  0.1,

  /* Expression: -0.1
   * Referenced by: '<S7>/Integrator1'
   */
  -0.1,

  /* Expression: 0.5
   * Referenced by: '<S7>/Motor_command  sat'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S7>/Motor_command  sat'
   */
  -0.5,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/heading gain Kh'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Saturation'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<Root>/Saturation'
   */
  -0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/steering limit'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S1>/steering limit'
   */
  -0.5,

  /* Expression: 0.425
   * Referenced by: '<S8>/vehicle length'
   */
  0.425,

  /* Expression: 0.2
   * Referenced by: '<S1>/velocity limit'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<S1>/velocity limit'
   */
  -0.2,

  /* Expression: 0.5
   * Referenced by: '<S1>/acceleration limit'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S1>/acceleration limit'
   */
  -0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<Root>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0.6
   * Referenced by: '<S7>/Ki (% // m)  '
   */
  0.6,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U, 43U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  40U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<Root>/HIL Write'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<Root>/HIL Read'
   */
  true
};
