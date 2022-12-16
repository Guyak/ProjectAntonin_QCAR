/*
 * Path_following_TP_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP".
 *
 * Model version              : 5.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Oct 17 16:07:58 2022
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

  /* Variable: p4
   * Referenced by: '<Root>/waypoint matrix'
   */
  { 0.0, 0.0, 0.041884839766713922, 0.08375130745839926, 0.12558103905862675,
    0.167355686664631, 0.20905692653530691, 0.25066646712860852,
    0.29216605712482324, 0.33353749343220457, 0.3747626291714492,
    0.41582338163551863, 0.45670174022131149, 0.49737977432970959,
    0.53783964123053141, 0.57806359388894324, 0.61803398874989479,
    0.65773329347716647, 0.69714409464363036, 0.73624910536935584,
    0.775031172904206, 0.81347328615160031, 0.85155858313014532,
    0.889270358369855, 0.92659207023972345, 0.96350734820343065,
    0.99999999999999989, 1.0360540187462604, 1.0716535899579933,
    1.1067830984866882, 1.1414271353688634, 1.1755705045849463,
    1.2091982297247497, 1.2422955605566208, 1.2748479794973793,
    1.3068412079802108, 1.3382612127177163, 1.3690942118573772,
    1.3993266810267309, 1.4289453592656067, 1.4579372548428231,
    1.4862896509547885, 1.513990111303513, 1.5410264855515785,
    1.5673869146516795, 1.5930598360483925, 1.6180339887498949,
    1.6422984182674081, 1.6658424814201989, 1.6886558510040302,
    1.7107285203210134, 1.7320508075688772, 1.7526133600877272,
    1.7724071584624295, 1.7914235204788258, 1.8096541049320392,
    1.8270909152852017, 1.843726303177001, 1.8595529717765027,
    1.8745639789837831, 1.888752740474962, 1.9021130325903071,
    1.9146389950641345, 1.9263251335953164, 1.9371663222572622,
    1.9471578057463206, 1.9562952014676112, 1.9645745014573772,
    1.9719920741410097, 1.9785446659259767, 1.9842294026289558,
    1.9890437907365466, 1.9929857184990087, 1.9960534568565431,
    1.9982456601977168, 1.999561366949691, 2.0, 1.999561366949691,
    1.9982456601977168, 1.9960534568565431, 1.9929857184990087,
    1.9890437907365468, 1.9842294026289558, 1.9785446659259767, 1.97199207414101,
    1.9645745014573774, 1.9562952014676114, 1.9471578057463206,
    1.9371663222572622, 1.9263251335953162, 1.9146389950641345,
    1.9021130325903073, 1.8887527404749622, 1.8745639789837831,
    1.8595529717765029, 1.8437263031770013, 1.827090915285202,
    1.8096541049320389, 1.7914235204788256, 1.7724071584624292,
    1.7526133600877274, 1.7320508075688774, 1.710728520321013,
    1.6886558510040304, 1.6658424814201991, 1.6422984182674081,
    1.6180339887498949, 1.5930598360483927, 1.5673869146516797,
    1.5410264855515785, 1.5139901113035128, 1.4862896509547889,
    1.4579372548428229, 1.4289453592656067, 1.3993266810267306,
    1.3690942118573777, 1.3382612127177167, 1.3068412079802105,
    1.2748479794973797, 1.242295560556621, 1.2091982297247499,
    1.1755705045849465, 1.1414271353688634, 1.1067830984866882,
    1.0716535899579933, 1.0360540187462604, 1.0000000000000007,
    0.96350734820343042, 0.92659207023972323, 0.88927035836985469,
    0.85155858313014576, 0.81347328615160086, 0.77503117290420553,
    0.73624910536935628, 0.6971440946436307, 0.6577332934771668,
    0.618033988749895, 0.57806359388894335, 0.53783964123053152,
    0.49737977432970965, 0.45670174022131149, 0.41582338163551946,
    0.37476262917144915, 0.33353749343220435, 0.292166057124823,
    0.25066646712860907, 0.20905692653530747, 0.16735568666463058,
    0.12558103905862716, 0.083751307458399621, 0.04188483976671422,
    2.4492935982947064E-16, -0.041884839766712846, -0.083751307458398247,
    -0.1255810390586258, -0.16735568666463008, -0.20905692653530611,
    -0.25066646712860768, -0.29216605712482252, -0.3335374934322039,
    -0.37476262917144776, -0.41582338163551813, -0.45670174022131188,
    -0.49737977432970915, -0.5378396412305293, -0.578063593888942,
    -0.61803398874989457, -0.65773329347716625, -0.69714409464362947,
    -0.73624910536935417, -0.77503117290420509, -0.81347328615159964,
    -0.85155858313014532, -0.88927035836985424, -0.92659207023972212,
    -0.9635073482034292, -0.99999999999999944, -1.0360540187462608,
    -1.071653589957992, -1.1067830984866864, -1.1414271353688623,
    -1.1755705045849461, -1.2091982297247494, -1.24229556055662,
    -1.2748479794973779, -1.30684120798021, -1.3382612127177158,
    -1.3690942118573775, -1.3993266810267302, -1.4289453592656056,
    -1.457937254842822, -1.486289650954788, -1.5139901113035124,
    -1.5410264855515776, -1.5673869146516783, -1.5930598360483919,
    -1.6180339887498947, -1.6422984182674085, -1.6658424814201989,
    -1.6886558510040297, -1.7107285203210123, -1.732050807568877,
    -1.7526133600877272, -1.772407158462429, -1.7914235204788249,
    -1.8096541049320387, -1.8270909152852011, -1.8437263031770008,
    -1.8595529717765023, -1.8745639789837822, -1.8887527404749618,
    -1.9021130325903071, -1.9146389950641347, -1.9263251335953162,
    -1.9371663222572619, -1.9471578057463201, -1.9562952014676112,
    -1.9645745014573774, -1.9719920741410097, -1.9785446659259764,
    -1.9842294026289555, -1.9890437907365466, -1.9929857184990085,
    -1.9960534568565431, -1.9982456601977168, -1.999561366949691, -2.0,
    -1.999561366949691, -1.9982456601977168, -1.9960534568565431,
    -1.9929857184990087, -1.9890437907365468, -1.9842294026289558,
    -1.9785446659259767, -1.9719920741410097, -1.9645745014573774,
    -1.9562952014676116, -1.9471578057463206, -1.9371663222572626,
    -1.9263251335953164, -1.9146389950641349, -1.9021130325903073,
    -1.888752740474962, -1.8745639789837831, -1.8595529717765031,
    -1.8437263031770019, -1.8270909152852022, -1.8096541049320392,
    -1.791423520478826, -1.7724071584624295, -1.7526133600877276,
    -1.7320508075688781, -1.7107285203210136, -1.688655851004031,
    -1.6658424814201993, -1.6422984182674087, -1.6180339887498951,
    -1.5930598360483923, -1.5673869146516808, -1.5410264855515792,
    -1.5139901113035141, -1.4862896509547892, -1.4579372548428231,
    -1.4289453592656074, -1.3993266810267309, -1.3690942118573779,
    -1.3382612127177176, -1.3068412079802114, -1.2748479794973806,
    -1.2422955605566213, -1.2091982297247508, -1.1755705045849467,
    -1.141427135368863, -1.10678309848669, -1.0716535899579942,
    -1.0360540187462621, -1.0000000000000009, -0.96350734820343065,
    -0.92659207023972434, -0.88927035836985491, -0.851558583130146,
    -0.81347328615160186, -0.77503117290420653, -0.73624910536935739,
    -0.697144094643631, -0.6577332934771678, -0.61803398874989524,
    -0.57806359388894268, -0.53783964123053341, -0.4973797743297107,
    -0.45670174022131343, -0.41582338163551974, -0.37476262917144937,
    -0.33353749343220546, -0.29216605712482324, -0.25066646712860929,
    -0.20905692653530861, -0.16735568666463169, -0.1255810390586283,
    -0.083751307458399857, -0.041884839766715351, -4.8985871965894128E-16, 0.0,
    0.0, -0.08375130745839926, -0.167355686664631, -0.25066646712860852,
    -0.33353749343220457, -0.41582338163551863, -0.49737977432970959,
    -0.57806359388894324, -0.65773329347716647, -0.73624910536935584,
    -0.81347328615160031, -0.889270358369855, -0.96350734820343065,
    -1.0360540187462604, -1.1067830984866882, -1.1755705045849463,
    -1.2422955605566208, -1.3068412079802108, -1.3690942118573772,
    -1.4289453592656067, -1.4862896509547885, -1.5410264855515785,
    -1.5930598360483925, -1.6422984182674081, -1.6886558510040302,
    -1.7320508075688772, -1.7724071584624295, -1.8096541049320392,
    -1.843726303177001, -1.8745639789837831, -1.9021130325903071,
    -1.9263251335953164, -1.9471578057463206, -1.9645745014573772,
    -1.9785446659259767, -1.9890437907365466, -1.9960534568565431,
    -1.999561366949691, -1.999561366949691, -1.9960534568565431,
    -1.9890437907365468, -1.9785446659259767, -1.9645745014573774,
    -1.9471578057463206, -1.9263251335953162, -1.9021130325903073,
    -1.8745639789837831, -1.8437263031770013, -1.8096541049320389,
    -1.7724071584624292, -1.7320508075688774, -1.6886558510040304,
    -1.6422984182674081, -1.5930598360483927, -1.5410264855515785,
    -1.4862896509547889, -1.4289453592656067, -1.3690942118573777,
    -1.3068412079802105, -1.242295560556621, -1.1755705045849465,
    -1.1067830984866882, -1.0360540187462604, -0.96350734820343042,
    -0.88927035836985469, -0.81347328615160086, -0.73624910536935628,
    -0.6577332934771668, -0.57806359388894335, -0.49737977432970965,
    -0.41582338163551946, -0.33353749343220435, -0.25066646712860907,
    -0.16735568666463058, -0.083751307458399621, -2.4492935982947064E-16,
    0.083751307458399135, 0.16735568666463096, 0.25066646712860857,
    0.3335374934322039, 0.41582338163551813, 0.49737977432970915,
    0.57806359388894368, 0.65773329347716625, 0.73624910536935584,
    0.81347328615159964, 0.88927035836985424, 0.96350734820343076,
    1.0360540187462608, 1.1067830984866878, 1.1755705045849461, 1.24229556055662,
    1.3068412079802108, 1.3690942118573775, 1.4289453592656063,
    1.486289650954788, 1.5410264855515787, 1.593059836048393, 1.6422984182674085,
    1.6886558510040297, 1.732050807568877, 1.77240715846243, 1.8096541049320387,
    1.8437263031770008, 1.8745639789837829, 1.9021130325903071,
    1.9263251335953162, 1.9471578057463206, 1.9645745014573774,
    1.9785446659259767, 1.9890437907365466, 1.9960534568565431,
    1.999561366949691, 1.999561366949691, 1.9960534568565431, 1.9890437907365468,
    1.9785446659259764, 1.9645745014573774, 1.9471578057463206,
    1.9263251335953164, 1.9021130325903073, 1.8745639789837831,
    1.843726303177001, 1.8096541049320392, 1.7724071584624295,
    1.7320508075688781, 1.68865585100403, 1.6422984182674079, 1.5930598360483923,
    1.5410264855515792, 1.4862896509547892, 1.4289453592656061,
    1.3690942118573779, 1.3068412079802114, 1.2422955605566213,
    1.1755705045849467, 1.1067830984866884, 1.0360540187462606,
    0.96350734820343065, 0.88927035836985491, 0.81347328615160186,
    0.73624910536935573, 0.65773329347716614, 0.57806359388894268,
    0.4973797743297107, 0.41582338163551974, 0.33353749343220374,
    0.25066646712860929, 0.16735568666463169, 0.083751307458399857,
    4.8985871965894128E-16, -0.083751307458397109, -0.16735568666462897,
    -0.25066646712860657, -0.33353749343220274, -0.415823381635517,
    -0.49737977432970804, -0.5780635938889418, -0.65773329347716525,
    -0.73624910536935317, -0.81347328615159942, -0.88927035836985568,
    -0.96350734820342976, -1.0360540187462568, -1.1067830984866862,
    -1.1755705045849458, -1.2422955605566204, -1.3068412079802094,
    -1.3690942118573746, -1.4289453592656054, -1.4862896509547874,
    -1.5410264855515785, -1.5930598360483916, -1.6422984182674063,
    -1.6886558510040286, -1.7320508075688767, -1.7724071584624297,
    -1.8096541049320378, -1.8437263031769993, -1.8745639789837822,
    -1.9021130325903071, -1.9263251335953162, -1.9471578057463201,
    -1.9645745014573766, -1.9785446659259764, -1.9890437907365466,
    -1.9960534568565431, -1.999561366949691, -1.999561366949691,
    -1.9960534568565433, -1.9890437907365468, -1.9785446659259769,
    -1.9645745014573779, -1.9471578057463215, -1.9263251335953171,
    -1.9021130325903073, -1.8745639789837825, -1.8437263031770013,
    -1.80965410493204, -1.7724071584624312, -1.7320508075688783,
    -1.6886558510040302, -1.642298418267409, -1.5930598360483945,
    -1.5410264855515794, -1.4862896509547905, -1.4289453592656076,
    -1.3690942118573795, -1.3068412079802143, -1.2422955605566228,
    -1.1755705045849467, -1.1067830984866871, -1.0360540187462608,
    -0.96350734820343242, -0.88927035836985835, -0.81347328615160208,
    -0.736249105369356, -0.657733293477168, -0.57806359388894635,
    -0.497379774329711, -0.41582338163552168, -0.33353749343220573,
    -0.25066646712861135, -0.16735568666463194, -0.083751307458401883,
    -7.3478807948841188E-16, 0.083751307458400412, 0.16735568666463049,
    0.25066646712860635, 0.33353749343220079, 0.4158233816355168,
    0.49737977432970953, 0.57806359388894157, 0.65773329347716669,
    0.73624910536935451, 0.81347328615159753, 0.8892703583698538,
    0.963507348203428, 1.0360540187462595, 1.106783098486686, 1.1755705045849456,
    1.2422955605566215, 1.3068412079802105, 1.3690942118573757,
    1.4289453592656041, 1.4862896509547872, 1.5410264855515783,
    1.5930598360483914, 1.6422984182674081, 1.6886558510040293,
    1.7320508075688756, 1.7724071584624288, 1.8096541049320378,
    1.8437263031770006, 1.874563978983782, 1.9021130325903068,
    1.9263251335953167, 1.9471578057463197, 1.964574501457377, 1.978544665925976,
    1.9890437907365464, 1.9960534568565431, 1.999561366949691, 1.999561366949691,
    1.9960534568565431, 1.989043790736547, 1.9785446659259769,
    1.9645745014573779, 1.9471578057463208, 1.9263251335953171,
    1.9021130325903075, 1.8745639789837827, 1.8437263031770026, 1.80965410493204,
    1.7724071584624312, 1.7320508075688783, 1.6886558510040304,
    1.6422984182674092, 1.5930598360483925, 1.5410264855515796,
    1.4862896509547907, 1.4289453592656076, 1.3690942118573797,
    1.3068412079802116, 1.242295560556623, 1.1755705045849469,
    1.1067830984866873, 1.0360540187462641, 0.96350734820343265,
    0.88927035836985857, 0.81347328615160241, 0.73624910536935617,
    0.65773329347716825, 0.57806359388894324, 0.4973797743297112,
    0.41582338163552196, 0.33353749343220596, 0.25066646712861157,
    0.16735568666463219, 0.083751307458402133, 9.7971743931788257E-16 },

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
