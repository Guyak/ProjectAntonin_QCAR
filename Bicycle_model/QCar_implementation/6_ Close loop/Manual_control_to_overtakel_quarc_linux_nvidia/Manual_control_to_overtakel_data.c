/*
 * Manual_control_to_overtakel_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Manual_control_to_overtakel".
 *
 * Model version              : 5.40
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 15:29:04 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Manual_control_to_overtakel.h"
#include "Manual_control_to_overtakel_private.h"

/* Block parameters (default storage) */
P_Manual_control_to_overtakel_T Manual_control_to_overtakel_P = {
  /* Variable: X_ic
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Variable: Y_ic
   * Referenced by: '<S7>/Integrator1'
   */
  0.0,

  /* Variable: vehicle_length
   * Referenced by:
   *   '<S7>/1//L'
   *   '<S7>/Gain'
   */
  0.256,

  /* Variable: x0
   * Referenced by: '<S1>/Integrator1'
   */
  { 8.0, 5.0, 1.5707963267948966 },

  /* Variable: xg
   * Referenced by: '<Root>/Goal position'
   */
  { 5.0, 5.0 },

  /* Variable: yaw_ic
   * Referenced by: '<S7>/Integrator2'
   */
  -1.5707963267948966,

  /* Mask Parameter: Bicycle_accel
   * Referenced by: '<S1>/acceleration limit'
   */
  1.0,

  /* Mask Parameter: Bicycle_alim
   * Referenced by: '<S1>/steering angle limit'
   */
  1.0,

  /* Mask Parameter: arewethereyet_const
   * Referenced by: '<S5>/Constant'
   */
  0.1,

  /* Mask Parameter: Bicycle_steer_rate
   * Referenced by: '<S1>/steering rate limit'
   */
  0.0,

  /* Mask Parameter: Bicycle_vlim
   * Referenced by: '<S1>/vel limit'
   */
  1.0,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<Root>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite1_other_channels
   * Referenced by: '<Root>/HIL Write1'
   */
  1000U,

  /* Mask Parameter: HILWrite1_pwm_channels
   * Referenced by: '<Root>/HIL Write1'
   */
  0U,

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize1'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: 0.5294117647058824
   * Referenced by: '<Root>/velocity gain Kv'
   */
  0.52941176470588236,

  /* Expression: 0.8
   * Referenced by: '<S8>/command saturation'
   */
  0.8,

  /* Expression: -0.8
   * Referenced by: '<S8>/command saturation'
   */
  -0.8,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Kff  (% // m//s)'
   */
  0.1,

  /* Expression: 25
   * Referenced by: '<Root>/Constant2'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator2'
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

  /* Expression: 0.87
   * Referenced by: '<S6>/Offset'
   */
  0.87,

  /* Expression: 0.6
   * Referenced by: '<S8>/Kp (% // m//s)'
   */
  0.6,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Integrator1'
   */
  0.1,

  /* Expression: -0.1
   * Referenced by: '<S8>/Integrator1'
   */
  -0.1,

  /* Expression: 0.5
   * Referenced by: '<S8>/Motor_command  sat'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S8>/Motor_command  sat'
   */
  -0.5,

  /* Expression: -1
   * Referenced by: '<Root>/direction convention'
   */
  -1.0,

  /* Expression: 0.20
   * Referenced by: '<Root>/command saturation'
   */
  0.2,

  /* Expression: -0.20
   * Referenced by: '<Root>/command saturation'
   */
  -0.2,

  /* Expression: 4
   * Referenced by: '<Root>/Gain'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S2>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<Root>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0.6
   * Referenced by: '<S8>/Ki (% // m)  '
   */
  0.6,

  /* Computed Parameter: HILInitialize1_EIInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POModes
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize1_POConfiguration
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POAlignment
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POPolarity
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_AIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize1_DIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U, 43U },

  /* Computed Parameter: HILInitialize1_DOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  40U,

  /* Computed Parameter: HILInitialize1_EIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize1_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize1_POChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize1_OOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: HILInitialize1_Active
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_EIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_EIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_EIStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_EIEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_OOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOFinal
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILWrite1_Active
   * Referenced by: '<Root>/HIL Write1'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<Root>/HIL Read'
   */
  true
};
