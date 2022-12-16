/*
 * Manual_Drive_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Manual_Drive".
 *
 * Model version              : 1.212
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 17 10:33:52 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Manual_Drive.h"
#include "Manual_Drive_private.h"

/* Block parameters (default storage) */
P_Manual_Drive_T Manual_Drive_P = {
  /* Mask Parameter: LeftSteeringLimit_const
   * Referenced by: '<S19>/Constant'
   */
  0.3,

  /* Mask Parameter: RightSteeringLimit_const
   * Referenced by: '<S21>/Constant'
   */
  -0.3,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S18>/Constant'
   */
  -0.002,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S16>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Mask Parameter: HILRead_analog_channels
   * Referenced by: '<S3>/HIL Read'
   */
  { 5U, 6U },

  /* Mask Parameter: HILWrite_digital_channels
   * Referenced by: '<S3>/HIL Write'
   */
  40U,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<S3>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S3>/HIL Write'
   */
  { 1000U, 11008U, 11009U, 11010U, 11011U, 11000U, 11001U, 11002U, 11003U },

  /* Mask Parameter: HILWrite_pwm_channels
   * Referenced by: '<S3>/HIL Write'
   */
  0U,

  /* Mask Parameter: CompareToConstant2_const_a
   * Referenced by: '<S12>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant1_const_o
   * Referenced by: '<S11>/Constant'
   */
  true,

  /* Expression: -1
   * Referenced by: '<S5>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant2'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S6>/Constant'
   */
  -1.0,

  /* Expression: [0]
   * Referenced by: '<S15>/Enabled'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S3>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S3>/HIL Initialize'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<S3>/HIL Initialize'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<S3>/HIL Initialize'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<S3>/HIL Initialize'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant1'
   */
  1.0,

  /* Expression: 25
   * Referenced by: '<S3>/Constant2'
   */
  25.0,

  /* Expression: 2
   * Referenced by: '<S10>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<S3>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/True'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S6>/Switch'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S6>/Bias'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S6>/Gain3'
   */
  0.5,

  /* Expression: -1
   * Referenced by: '<S3>/direction convention'
   */
  -1.0,

  /* Expression: 0.2
   * Referenced by: '<S3>/scale output  to max range'
   */
  0.2,

  /* Expression: 0.20
   * Referenced by: '<S3>/command saturation'
   */
  0.2,

  /* Expression: -0.20
   * Referenced by: '<S3>/command saturation'
   */
  -0.2,

  /* Expression: 0
   * Referenced by: '<S3>/coast ON'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S6>/Gain4'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S5>/ remapping to steering range '
   */
  0.5,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Steering Bias'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Pulsing Light'
   */
  1.0,

  /* Expression: 0.5/qc_get_step_size
   * Referenced by: '<S7>/Pulsing Light'
   */
  250.0,

  /* Expression: 0.5/2/qc_get_step_size
   * Referenced by: '<S7>/Pulsing Light'
   */
  125.0,

  /* Expression: 0
   * Referenced by: '<S7>/Pulsing Light'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S7>/Constant2'
   */
  5.0,

  /* Expression: i_trigger_type
   * Referenced by: '<S20>/one_shot_block'
   */
  2.0,

  /* Expression: i_redun_pulse
   * Referenced by: '<S20>/one_shot_block'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S20>/Switch'
   */
  0.5,

  /* Expression: 10.5
   * Referenced by: '<S9>/min voltage'
   */
  10.5,

  /* Expression: 12.6
   * Referenced by: '<S9>/max voltage'
   */
  12.6,

  /* Expression: 100
   * Referenced by: '<S9>/Gain'
   */
  100.0,

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

  /* Expression: qc_get_step_size
   * Referenced by: '<S8>/Constant'
   */
  0.002,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S3>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S3>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U, 43U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  40U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S6>/Game Controller'
   */
  12U,

  /* Computed Parameter: LightOff_Value
   * Referenced by: '<S7>/Light Off'
   */
  false,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S3>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S3>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<S3>/HIL Read'
   */
  true,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S6>/Game Controller'
   */
  false,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S6>/Game Controller'
   */
  true,

  /* Computed Parameter: SteadyLight_Value
   * Referenced by: '<S7>/Steady Light'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S3>/HIL Write'
   */
  false,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S6>/Game Controller'
   */
  1U
};
