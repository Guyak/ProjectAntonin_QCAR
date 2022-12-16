/*
 * Path_following_TP_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP".
 *
 * Model version              : 5.4
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 17 17:11:43 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Path_following_TP.h"
#include "Path_following_TP_private.h"

/* Block parameters (default storage) */
P_Path_following_TP_T Path_following_TP_P = {
  /* Variable: X_ic
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Variable: Y_ic
   * Referenced by: '<S5>/Integrator1'
   */
  0.0,

  /* Variable: elipse
   * Referenced by: '<Root>/waypoint matrix'
   */
  { -0.0, 0.0024979173609871452, 0.0099667110793791869, 0.02233175543719701,
    0.039469502998557449, 0.061208719054813621, 0.087332192545160892,
    0.11757890635775581, 0.15164664532641731, 0.1891950158646678,
    0.22984884706593012, 0.27320193928721137, 0.3188211227616633,
    0.3662505856877063, 0.41501642854987958, 0.46463139916614854,
    0.51459976115064443, 0.56442224714776246, 0.61360104734654353,
    0.66164478343175182, 0.70807341827357118, 0.75242305229992879,
    0.79425055862767291, 0.83313801063991222, 0.86869685777062289,
    0.90057180777346679, 0.92844437668447366, 0.9520360710085306,
    0.97111117033432914, 0.98547908257479533, 0.99499624830022271,
    0.99956757513663974, 0.99914738789737656, 0.99914738789737656,
    0.99914738789737656, 0.99914738789737656, 0.99664947053638941,
    0.98918067681799737, 0.97681563246017955, 0.95967788489881911,
    0.93793866884256294, 0.91181519535221567, 0.88156848153962075,
    0.84750074257095931, 0.80995237203270876, 0.76929854083144644,
    0.72594544861016519, 0.68032626513571326, 0.63289680220967026,
    0.584130959347497, 0.53451598873122808, 0.48454762674673213,
    0.4347251407496141, 0.38554634055083303, 0.33750260446562474,
    0.29107396962380538, 0.24672433559744777, 0.20489682926970365,
    0.16600937725746434, 0.13045053012675367, 0.098575580123909767,
    0.0707030112129029, 0.047111316888845955, 0.028036217563047416,
    0.013668305322581231, 0.0041511395971538523, -0.00042018723926318113, 0.0,
    0.2, 0.0, -0.0, -0.049916708323414077, -0.099334665397530608,
    -0.1477601033306698, -0.19470917115432526, -0.2397127693021015,
    -0.28232123669751774, -0.32210884361884556, -0.3586780454497614,
    -0.39166345481374171, -0.42073549240394825, -0.44560368003071771,
    -0.4660195429836132, -0.48177909270859648, -0.49272486499423013,
    -0.49874749330202722, -0.49978680152075255, -0.49583240522623429,
    -0.48692381543909757, -0.47315004384370724, -0.45464871341284085,
    -0.43160468332443686, -0.40424820190979505, -0.37285260608836,
    -0.33773159027557531, -0.29923607205197822, -0.25775068591073208,
    -0.21368994011691489, -0.16749407507795233, -0.11962466460699099,
    -0.0705600040299336, -0.020790331216645246, 0.029187071713790043,
    0.0024979173609871452, 1.0024979173609871, 1.0024979173609871,
    1.0524146256844011, 1.1018325827585178, 1.1502580206916568,
    1.1972070885153123, 1.2422106866630886, 1.2848191540585048,
    1.3246067609798327, 1.3611759628107485, 1.3941613721747288,
    1.4232334097649355, 1.4481015973917049, 1.4685174603446003,
    1.4842770100695837, 1.4952227823552173, 1.5012454106630144,
    1.5022847188817396, 1.4983303225872215, 1.4894217328000847,
    1.4756479612046944, 1.4571466307738281, 1.4341026006854241,
    1.4067461192707822, 1.3753505234493471, 1.3402295076365625,
    1.3017339894129654, 1.2602486032717193, 1.2161878574779021,
    1.1699919924389395, 1.1221225819679781, 1.0730579213909208,
    1.0232882485776325, 0.973310845647197, 0.973310845647197,
    -0.026689154352802946 },

  /* Variable: vehicle_length
   * Referenced by:
   *   '<S5>/1//L'
   *   '<S5>/Gain'
   */
  0.256,

  /* Variable: yaw_ic
   * Referenced by: '<S5>/Integrator2'
   */
  -1.5707963267948966,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<Root>/HIL Read'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWrite1_other_channels
   * Referenced by: '<Root>/HIL Write1'
   */
  1000U,

  /* Mask Parameter: HILRead_other_channels
   * Referenced by: '<Root>/HIL Read'
   */
  { 3000U, 4000U },

  /* Mask Parameter: HILWrite1_pwm_channels
   * Referenced by: '<Root>/HIL Write1'
   */
  0U,

  /* Expression: 0.2
   * Referenced by: '<Root>/Pure Pursuit'
   */
  0.2,

  /* Expression: 1
   * Referenced by: '<Root>/Pure Pursuit'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Pure Pursuit'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
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

  /* Expression: 0.8
   * Referenced by: '<S6>/command saturation'
   */
  0.8,

  /* Expression: -0.8
   * Referenced by: '<S6>/command saturation'
   */
  -0.8,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Kff  (% // m//s)'
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
   * Referenced by: '<S3>/counts to rotations'
   */
  0.00034722222222222224,

  /* Expression: (13*19)/(70*37)
   * Referenced by: '<S3>/gear ratios'
   */
  0.095366795366795362,

  /* Expression: 2*pi
   * Referenced by: '<S3>/rot//s to rad//s'
   */
  6.2831853071795862,

  /* Expression: 0.0342
   * Referenced by: '<S3>/wheel radius'
   */
  0.0342,

  /* Expression: 0.87
   * Referenced by: '<S3>/Offset'
   */
  0.87,

  /* Expression: 0.3
   * Referenced by: '<S6>/Kp (% // m//s)'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Integrator1'
   */
  0.1,

  /* Expression: -0.1
   * Referenced by: '<S6>/Integrator1'
   */
  -0.1,

  /* Expression: 0.5
   * Referenced by: '<S6>/Motor_command  sat'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S6>/Motor_command  sat'
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

  /* Expression: 2
   * Referenced by: '<S1>/Constant6'
   */
  2.0,

  /* Expression: 0.256
   * Referenced by: '<S1>/Bicycle length'
   */
  0.256,

  /* Expression: 1
   * Referenced by: '<S1>/Sine Wave Function'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave Function'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Sine Wave Function'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave Function'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Lookahead distance'
   */
  0.1,

  /* Expression: 0.5
   * Referenced by: '<Root>/angle saturation1'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<Root>/angle saturation1'
   */
  -0.5,

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

  /* Expression: 1
   * Referenced by: '<S6>/Ki (% // m)  '
   */
  1.0,

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
