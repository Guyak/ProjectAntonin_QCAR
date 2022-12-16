/*
 * Path_following_TP_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP".
 *
 * Model version              : 5.3
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 16:14:43 2022
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

  /* Variable: circuit
   * Referenced by: '<Root>/waypoint matrix'
   */
  { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.000432424863360259,
    0.0050037516997772924, 0.014520917425204727, 0.028888829665670968,
    0.047963928991469396, 0.07155562331552634, 0.099428192226533152,
    0.13130314222937728, 0.166861989360088, 0.20574944137232709,
    0.24757694770007121, 0.29192658172642882, 0.3383552165682483,
    0.38639895265345647, 0.43557775285223765, 0.48540023884935557,
    0.5353686008338514, 0.58498357145012037, 0.6337494143122937,
    0.6811788772383367, 0.72679806071278863, 0.77015115293406988,
    0.8108049841353322, 0.84835335467358264, 0.88242109364224419,
    0.91266780745483911, 0.93879128094518638, 0.96053049700144255,
    0.977668244562803, 0.99003328892062081, 0.99750208263901285, 1.0, 1.0,
    0.99750208263901285, 0.99003328892062081, 0.977668244562803,
    0.96053049700144255, 0.93879128094518638, 0.91266780745483911,
    0.88242109364224419, 0.84835335467358264, 0.8108049841353322,
    0.77015115293406988, 0.72679806071278863, 0.6811788772383367,
    0.6337494143122937, 0.58498357145012037, 0.5353686008338514,
    0.48540023884935557, 0.43557775285223765, 0.38639895265345647,
    0.3383552165682483, 0.29192658172642882, 0.24757694770007121,
    0.20574944137232709, 0.166861989360088, 0.13130314222937728,
    0.099428192226533152, 0.07155562331552634, 0.047963928991469396,
    0.028888829665670968, 0.014520917425204727, 0.0050037516997772924,
    0.000432424863360259, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    0.000432424863360259, 0.0050037516997772924, 0.014520917425204727,
    0.028888829665670968, 0.047963928991469396, 0.07155562331552634,
    0.099428192226533152, 0.13130314222937728, 0.166861989360088,
    0.20574944137232709, 0.24757694770007121, 0.29192658172642882,
    0.3383552165682483, 0.38639895265345647, 0.43557775285223765,
    0.48540023884935557, 0.5353686008338514, 0.58498357145012037,
    0.6337494143122937, 0.6811788772383367, 0.72679806071278863,
    0.77015115293406988, 0.8108049841353322, 0.84835335467358264,
    0.88242109364224419, 0.91266780745483911, 0.93879128094518638,
    0.96053049700144255, 0.977668244562803, 0.99003328892062081,
    0.99750208263901285, 1.0, 1.0, 0.99750208263901285, 0.99003328892062081,
    0.977668244562803, 0.96053049700144255, 0.93879128094518638,
    0.91266780745483911, 0.88242109364224419, 0.84835335467358264,
    0.8108049841353322, 0.77015115293406988, 0.72679806071278863,
    0.6811788772383367, 0.6337494143122937, 0.58498357145012037,
    0.5353686008338514, 0.48540023884935557, 0.43557775285223765,
    0.38639895265345647, 0.3383552165682483, 0.29192658172642882,
    0.24757694770007121, 0.20574944137232709, 0.166861989360088,
    0.13130314222937728, 0.099428192226533152, 0.07155562331552634,
    0.047963928991469396, 0.028888829665670968, 0.014520917425204727,
    0.0050037516997772924, 0.000432424863360259, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.000432424863360259, 0.0050037516997772924, 0.014520917425204727,
    0.028888829665670968, 0.047963928991469396, 0.07155562331552634,
    0.099428192226533152, 0.13130314222937728, 0.166861989360088,
    0.20574944137232709, 0.24757694770007121, 0.29192658172642882,
    0.3383552165682483, 0.38639895265345647, 0.43557775285223765,
    0.48540023884935557, 0.5353686008338514, 0.58498357145012037,
    0.6337494143122937, 0.6811788772383367, 0.72679806071278863,
    0.77015115293406988, 0.8108049841353322, 0.84835335467358264,
    0.88242109364224419, 0.91266780745483911, 0.93879128094518638,
    0.96053049700144255, 0.977668244562803, 0.99003328892062081,
    0.99750208263901285, 1.0, 1.0, 0.99750208263901285, 0.99003328892062081,
    0.977668244562803, 0.96053049700144255, 0.93879128094518638,
    0.91266780745483911, 0.88242109364224419, 0.84835335467358264,
    0.8108049841353322, 0.77015115293406988, 0.72679806071278863,
    0.6811788772383367, 0.6337494143122937, 0.58498357145012037,
    0.5353686008338514, 0.48540023884935557, 0.43557775285223765,
    0.38639895265345647, 0.3383552165682483, 0.29192658172642882,
    0.24757694770007121, 0.20574944137232709, 0.166861989360088,
    0.13130314222937728, 0.099428192226533152, 0.07155562331552634,
    0.047963928991469396, 0.028888829665670968, 0.014520917425204727,
    0.0050037516997772924, 0.000432424863360259, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.000432424863360259, 0.0050037516997772924, 0.014520917425204727,
    0.028888829665670968, 0.047963928991469396, 0.07155562331552634,
    0.099428192226533152, 0.13130314222937728, 0.166861989360088,
    0.20574944137232709, 0.24757694770007121, 0.29192658172642882,
    0.3383552165682483, 0.38639895265345647, 0.43557775285223765,
    0.48540023884935557, 0.5353686008338514, 0.58498357145012037,
    0.6337494143122937, 0.6811788772383367, 0.72679806071278863,
    0.77015115293406988, 0.8108049841353322, 0.84835335467358264,
    0.88242109364224419, 0.91266780745483911, 0.93879128094518638,
    0.96053049700144255, 0.977668244562803, 0.99003328892062081,
    0.99750208263901285, 1.0, 1.0, 0.99750208263901285, 0.99003328892062081,
    0.977668244562803, 0.96053049700144255, 0.93879128094518638,
    0.91266780745483911, 0.88242109364224419, 0.84835335467358264,
    0.8108049841353322, 0.77015115293406988, 0.72679806071278863,
    0.6811788772383367, 0.6337494143122937, 0.58498357145012037,
    0.5353686008338514, 0.48540023884935557, 0.43557775285223765,
    0.38639895265345647, 0.3383552165682483, 0.29192658172642882,
    0.24757694770007121, 0.20574944137232709, 0.166861989360088,
    0.13130314222937728, 0.099428192226533152, 0.07155562331552634,
    0.047963928991469396, 0.028888829665670968, 0.014520917425204727,
    0.0050037516997772924, 0.000432424863360259, 0.0, -0.3, -0.6, -1.0, -1.0,
    -0.6, -0.3, 0.0, -1.0207903312166453, -1.0705600040299337,
    -1.1196246646069912, -1.1674940750779526, -1.213689940116915,
    -1.2577506859107321, -1.2992360720519782, -1.3377315902755755,
    -1.3728526060883601, -1.404248201909795, -1.4316046833244369,
    -1.454648713412841, -1.4731500438437073, -1.4869238154390976,
    -1.4958324052262344, -1.4997868015207525, -1.4987474933020273,
    -1.4927248649942302, -1.4817790927085965, -1.4660195429836131,
    -1.4456036800307177, -1.4207354924039484, -1.3916634548137417,
    -1.3586780454497613, -1.3221088436188455, -1.2823212366975176,
    -1.2397127693021015, -1.1947091711543252, -1.1477601033306697,
    -1.0993346653975307, -1.049916708323414, -1.0, 0.0, 0.049916708323414077,
    0.099334665397530608, 0.1477601033306698, 0.19470917115432526,
    0.2397127693021015, 0.28232123669751774, 0.32210884361884556,
    0.3586780454497614, 0.39166345481374171, 0.42073549240394825,
    0.44560368003071771, 0.4660195429836132, 0.48177909270859648,
    0.49272486499423013, 0.49874749330202722, 0.49978680152075255,
    0.49583240522623429, 0.48692381543909757, 0.47315004384370724,
    0.45464871341284085, 0.43160468332443686, 0.40424820190979505,
    0.37285260608836013, 0.33773159027557548, 0.29923607205197822,
    0.25775068591073208, 0.21368994011691489, 0.16749407507795255,
    0.11962466460699121, 0.0705600040299336, 0.020790331216645246, 0.0, -0.3,
    -0.6, -1.0, -1.0, -0.6, -0.3, 0.0, -1.0207903312166453, -1.0705600040299337,
    -1.1196246646069912, -1.1674940750779526, -1.213689940116915,
    -1.2577506859107321, -1.2992360720519782, -1.3377315902755755,
    -1.3728526060883601, -1.404248201909795, -1.4316046833244369,
    -1.454648713412841, -1.4731500438437073, -1.4869238154390976,
    -1.4958324052262344, -1.4997868015207525, -1.4987474933020273,
    -1.4927248649942302, -1.4817790927085965, -1.4660195429836131,
    -1.4456036800307177, -1.4207354924039484, -1.3916634548137417,
    -1.3586780454497613, -1.3221088436188455, -1.2823212366975176,
    -1.2397127693021015, -1.1947091711543252, -1.1477601033306697,
    -1.0993346653975307, -1.049916708323414, -1.0, 0.0, 0.049916708323414077,
    0.099334665397530608, 0.1477601033306698, 0.19470917115432526,
    0.2397127693021015, 0.28232123669751774, 0.32210884361884556,
    0.3586780454497614, 0.39166345481374171, 0.42073549240394825,
    0.44560368003071771, 0.4660195429836132, 0.48177909270859648,
    0.49272486499423013, 0.49874749330202722, 0.49978680152075255,
    0.49583240522623429, 0.48692381543909757, 0.47315004384370724,
    0.45464871341284085, 0.43160468332443686, 0.40424820190979505,
    0.37285260608836013, 0.33773159027557548, 0.29923607205197822,
    0.25775068591073208, 0.21368994011691489, 0.16749407507795255,
    0.11962466460699121, 0.0705600040299336, 0.020790331216645246, 0.0, -0.3,
    -0.6, -1.0, -1.0, -0.6, -0.3, 0.0, -1.0207903312166453, -1.0705600040299337,
    -1.1196246646069912, -1.1674940750779526, -1.213689940116915,
    -1.2577506859107321, -1.2992360720519782, -1.3377315902755755,
    -1.3728526060883601, -1.404248201909795, -1.4316046833244369,
    -1.454648713412841, -1.4731500438437073, -1.4869238154390976,
    -1.4958324052262344, -1.4997868015207525, -1.4987474933020273,
    -1.4927248649942302, -1.4817790927085965, -1.4660195429836131,
    -1.4456036800307177, -1.4207354924039484, -1.3916634548137417,
    -1.3586780454497613, -1.3221088436188455, -1.2823212366975176,
    -1.2397127693021015, -1.1947091711543252, -1.1477601033306697,
    -1.0993346653975307, -1.049916708323414, -1.0, 0.0, 0.049916708323414077,
    0.099334665397530608, 0.1477601033306698, 0.19470917115432526,
    0.2397127693021015, 0.28232123669751774, 0.32210884361884556,
    0.3586780454497614, 0.39166345481374171, 0.42073549240394825,
    0.44560368003071771, 0.4660195429836132, 0.48177909270859648,
    0.49272486499423013, 0.49874749330202722, 0.49978680152075255,
    0.49583240522623429, 0.48692381543909757, 0.47315004384370724,
    0.45464871341284085, 0.43160468332443686, 0.40424820190979505,
    0.37285260608836013, 0.33773159027557548, 0.29923607205197822,
    0.25775068591073208, 0.21368994011691489, 0.16749407507795255,
    0.11962466460699121, 0.0705600040299336, 0.020790331216645246, 0.0, -0.3,
    -0.6, -1.0, -1.0, -0.6, -0.3, 0.0, -1.0207903312166453, -1.0705600040299337,
    -1.1196246646069912, -1.1674940750779526, -1.213689940116915,
    -1.2577506859107321, -1.2992360720519782, -1.3377315902755755,
    -1.3728526060883601, -1.404248201909795, -1.4316046833244369,
    -1.454648713412841, -1.4731500438437073, -1.4869238154390976,
    -1.4958324052262344, -1.4997868015207525, -1.4987474933020273,
    -1.4927248649942302, -1.4817790927085965, -1.4660195429836131,
    -1.4456036800307177, -1.4207354924039484, -1.3916634548137417,
    -1.3586780454497613, -1.3221088436188455, -1.2823212366975176,
    -1.2397127693021015, -1.1947091711543252, -1.1477601033306697,
    -1.0993346653975307, -1.049916708323414, -1.0, 0.0, 0.049916708323414077,
    0.099334665397530608, 0.1477601033306698, 0.19470917115432526,
    0.2397127693021015, 0.28232123669751774, 0.32210884361884556,
    0.3586780454497614, 0.39166345481374171, 0.42073549240394825,
    0.44560368003071771, 0.4660195429836132, 0.48177909270859648,
    0.49272486499423013, 0.49874749330202722, 0.49978680152075255,
    0.49583240522623429, 0.48692381543909757, 0.47315004384370724,
    0.45464871341284085, 0.43160468332443686, 0.40424820190979505,
    0.37285260608836013, 0.33773159027557548, 0.29923607205197822,
    0.25775068591073208, 0.21368994011691489, 0.16749407507795255,
    0.11962466460699121, 0.0705600040299336, 0.020790331216645246 },

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

  /* Expression: 0.3
   * Referenced by: '<Root>/Pure Pursuit'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<Root>/Pure Pursuit'
   */
  1.0,

  /* Expression: 0.20
   * Referenced by: '<Root>/Pure Pursuit'
   */
  0.2,

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

  /* Expression: 0.20
   * Referenced by: '<S1>/Lookahead distance'
   */
  0.2,

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
