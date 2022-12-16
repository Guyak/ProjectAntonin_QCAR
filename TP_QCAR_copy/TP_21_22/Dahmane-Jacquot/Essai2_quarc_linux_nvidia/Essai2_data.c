/*
 * Essai2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Essai2".
 *
 * Model version              : 5.3
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 15:15:48 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Essai2.h"
#include "Essai2_private.h"

/* Block parameters (default storage) */
P_Essai2_T Essai2_P = {
  /* Variable: X_ic
   * Referenced by: '<S6>/Integrator'
   */
  0.0,

  /* Variable: Y_ic
   * Referenced by: '<S6>/Integrator1'
   */
  0.0,

  /* Variable: vehicle_length
   * Referenced by:
   *   '<S6>/1//L'
   *   '<S6>/Gain'
   */
  0.256,

  /* Variable: yaw_ic
   * Referenced by: '<S6>/Integrator2'
   */
  -1.5707963267948966,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  0.1,

  /* Mask Parameter: HILRead1_encoder_channels
   * Referenced by: '<Root>/HIL Read1'
   */
  { 0U, 1U },

  /* Mask Parameter: HILRead1_other_channels
   * Referenced by: '<Root>/HIL Read1'
   */
  { 3002U, 4000U },

  /* Mask Parameter: HILWrite2_other_channels
   * Referenced by: '<Root>/HIL Write2'
   */
  1000U,

  /* Mask Parameter: HILWrite2_pwm_channels
   * Referenced by: '<Root>/HIL Write2'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize2'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize2'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize2'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<Root>/HIL Initialize2'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize2'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0.0,

  /* Expression: 25
   * Referenced by: '<Root>/Constant1'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator2'
   */
  0.0,

  /* Expression: 1/720/4
   * Referenced by: '<S4>/counts to rotations'
   */
  0.00034722222222222224,

  /* Expression: (13*19)/(70*37)
   * Referenced by: '<S4>/gear ratios'
   */
  0.095366795366795362,

  /* Expression: 2*pi
   * Referenced by: '<S4>/rot//s to rad//s'
   */
  6.2831853071795862,

  /* Expression: 0.0342
   * Referenced by: '<S4>/wheel radius'
   */
  0.0342,

  /* Expression: 0.87
   * Referenced by: '<S4>/Offset'
   */
  0.87,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<Root>/Constant'
   */
  0.25,

  /* Expression: 0.07
   * Referenced by: '<Root>/Constant6'
   */
  0.07,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 0.20
   * Referenced by: '<Root>/command saturation1'
   */
  0.2,

  /* Expression: -0.20
   * Referenced by: '<Root>/command saturation1'
   */
  -0.2,

  /* Expression: 1
   * Referenced by: '<Root>/Constant5'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant7'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant8'
   */
  100.0,

  /* Expression: 2
   * Referenced by: '<S2>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<Root>/Unwrap 2^1'
   */
  1.6777215E+7,

  /* Expression: 2
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator2'
   */
  0.0,

  /* Computed Parameter: HILInitialize2_EIInitial
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0,

  /* Computed Parameter: HILInitialize2_POModes
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize2_POConfiguration
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0,

  /* Computed Parameter: HILInitialize2_POAlignment
   * Referenced by: '<Root>/HIL Initialize2'
   */
  0,

  /* Computed Parameter: HILInitialize2_POPolarity
   * Referenced by: '<Root>/HIL Initialize2'
   */
  1,

  /* Computed Parameter: HILInitialize2_AIChannels
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize2_DIChannels
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U, 43U },

  /* Computed Parameter: HILInitialize2_DOChannels
   * Referenced by: '<Root>/HIL Initialize2'
   */
  40U,

  /* Computed Parameter: HILInitialize2_EIChannels
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize2_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize2_POChannels
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize2_OOChannels
   * Referenced by: '<Root>/HIL Initialize2'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: HILInitialize2_Active
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_AOTerminate
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AOExit
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_DOTerminate
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_DOExit
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_POTerminate
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_POExit
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_CKPStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_CKPEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_CKStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_CKEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AIPStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AIPEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AOPStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AOPEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AOStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AOEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_AOReset
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_DOPStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_DOPEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_DOStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_DOEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_DOReset
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_EIPStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_EIPEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_EIStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_EIEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_POPStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_POPEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_POStart
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_POEnter
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_POReset
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_OOReset
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILInitialize2_DOFinal
   * Referenced by: '<Root>/HIL Initialize2'
   */
  true,

  /* Computed Parameter: HILInitialize2_DOInitial
   * Referenced by: '<Root>/HIL Initialize2'
   */
  false,

  /* Computed Parameter: HILRead1_Active
   * Referenced by: '<Root>/HIL Read1'
   */
  true,

  /* Computed Parameter: HILWrite2_Active
   * Referenced by: '<Root>/HIL Write2'
   */
  false
};
