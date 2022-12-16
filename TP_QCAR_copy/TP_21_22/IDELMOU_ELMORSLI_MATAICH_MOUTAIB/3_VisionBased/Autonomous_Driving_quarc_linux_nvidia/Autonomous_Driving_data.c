/*
 * Autonomous_Driving_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Autonomous_Driving".
 *
 * Model version              : 5.1
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 17:08:15 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Autonomous_Driving.h"
#include "Autonomous_Driving_private.h"

/* Block parameters (default storage) */
P_Autonomous_Driving_T Autonomous_Driving_P = {
  /* Variable: camera_rate
   * Referenced by: '<S15>/Constant'
   */
  0.0083333333333333332,

  /* Variable: depth_rate
   * Referenced by: '<S16>/Constant'
   */
  0.01,

  /* Mask Parameter: LeftSteeringLimit_const
   * Referenced by: '<S33>/Constant'
   */
  0.3,

  /* Mask Parameter: RightSteeringLimit_const
   * Referenced by: '<S35>/Constant'
   */
  -0.3,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S32>/Constant'
   */
  -0.002,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S30>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S31>/Constant'
   */
  0.0,

  /* Mask Parameter: SpeedSelector1_gain
   * Referenced by: '<S52>/Slider Gain'
   */
  1.0,

  /* Mask Parameter: ColorSelectingMean0_gain
   * Referenced by: '<S49>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: ColorSelectingWindow1_gain
   * Referenced by: '<S50>/Slider Gain'
   */
  1.0,

  /* Mask Parameter: ColorMixingMean0_gain
   * Referenced by: '<S47>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: ColorMixingWindow1_gain
   * Referenced by: '<S48>/Slider Gain'
   */
  1.0,

  /* Mask Parameter: BrightnessMean0_gain
   * Referenced by: '<S45>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: BrightnessWindow1_gain
   * Referenced by: '<S46>/Slider Gain'
   */
  1.0,

  /* Mask Parameter: DistaneToLane0_gain
   * Referenced by: '<S51>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: StoppingDistanceOffset0_gain
   * Referenced by: '<S53>/Slider Gain'
   */
  1.0,

  /* Mask Parameter: HSVColorThresholding_b_comparis
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  1,

  /* Mask Parameter: HSVColorThresholding_g_comparis
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  1,

  /* Mask Parameter: HSVColorThresholding_r_comparis
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  9,

  /* Mask Parameter: HILRead_analog_channels
   * Referenced by: '<S8>/HIL Read'
   */
  { 5U, 6U },

  /* Mask Parameter: HILWrite_digital_channels
   * Referenced by: '<S8>/HIL Write'
   */
  40U,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<S8>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S8>/HIL Write'
   */
  { 1000U, 11008U, 11009U, 11010U, 11011U, 11000U, 11001U, 11002U, 11003U },

  /* Mask Parameter: HILWrite_pwm_channels
   * Referenced by: '<S8>/HIL Write'
   */
  0U,

  /* Mask Parameter: Depth_stream_index
   * Referenced by: '<S11>/Depth'
   */
  0U,

  /* Mask Parameter: Video3DInitialize_active
   * Referenced by: '<S11>/Video3D Initialize'
   */
  true,

  /* Computed Parameter: distancem_Y0
   * Referenced by: '<S17>/distance (m)'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<S17>/Constant'
   */
  0.05,

  /* Expression: 2
   * Referenced by: '<S17>/Constant1'
   */
  2.0,

  /* Expression: Inf
   * Referenced by: '<S17>/Constant2'
   */
  0.0,

  /* Expression: [255 0 0]
   * Referenced by: '<S17>/Constant3'
   */
  { 255.0, 0.0, 0.0 },

  /* Expression: 3
   * Referenced by: '<S17>/scale'
   */
  3.0,

  /* Expression: 50
   * Referenced by: '<S19>/b_n'
   */
  50.0,

  /* Expression: 8
   * Referenced by: '<S20>/Constant'
   */
  8.0,

  /* Expression: 1
   * Referenced by: '<S20>/Saturation'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S20>/Saturation'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S21>/Constant10'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Constant8'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Constant3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Saturation1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S21>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/Constant'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S8>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S8>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S8>/HIL Initialize'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<S8>/HIL Initialize'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<S8>/HIL Initialize'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<S8>/HIL Initialize'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant1'
   */
  1.0,

  /* Expression: 25
   * Referenced by: '<S8>/Constant2'
   */
  25.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant3'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S8>/Constant4'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant5'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S8>/Constant6'
   */
  100.0,

  /* Expression: 2
   * Referenced by: '<S26>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<S8>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0
   * Referenced by: '<S26>/Integrator2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S27>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S27>/Integrator2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S28>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S28>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition1'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<S7>/Constant'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S7>/Constant2'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S21>/Speed Max (m//s)'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S21>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Rate Limiter'
   */
  1.0,

  /* Expression: -Inf
   * Referenced by: '<S21>/Rate Limiter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S21>/Rate Limiter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S20>/Switch'
   */
  0.5,

  /* Expression: 5
   * Referenced by: '<S18>/command saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S18>/command saturation'
   */
  -5.0,

  /* Expression: 0.1
   * Referenced by: '<S18>/Kff  (% // m//s)'
   */
  0.1,

  /* Expression: 1/720/4
   * Referenced by: '<S9>/counts to rotations'
   */
  0.00034722222222222224,

  /* Expression: (13*19)/(70*37)
   * Referenced by: '<S9>/gear ratios'
   */
  0.095366795366795362,

  /* Expression: 2*pi
   * Referenced by: '<S9>/rot//s to rad//s'
   */
  6.2831853071795862,

  /* Expression: 0.0342
   * Referenced by: '<S9>/wheel radius'
   */
  0.0342,

  /* Expression: 0.3
   * Referenced by: '<S18>/Kp (% // m//s)'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S18>/Integrator1'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<S18>/Integrator1'
   */
  0.4,

  /* Expression: -0.4
   * Referenced by: '<S18>/Integrator1'
   */
  -0.4,

  /* Expression: -1
   * Referenced by: '<S8>/direction convention'
   */
  -1.0,

  /* Expression: 0.25
   * Referenced by: '<S8>/command saturation'
   */
  0.25,

  /* Expression: -0.25
   * Referenced by: '<S8>/command saturation'
   */
  -0.25,

  /* Expression: 0
   * Referenced by: '<S8>/coast ON'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S8>/Gain'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<S8>/Steering Bias'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Pulsing Light'
   */
  1.0,

  /* Expression: 0.5/qc_get_step_size
   * Referenced by: '<S13>/Pulsing Light'
   */
  300.0,

  /* Expression: 0.5/2/qc_get_step_size
   * Referenced by: '<S13>/Pulsing Light'
   */
  150.0,

  /* Expression: 0
   * Referenced by: '<S13>/Pulsing Light'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Memory'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S13>/Constant2'
   */
  5.0,

  /* Expression: i_trigger_type
   * Referenced by: '<S34>/one_shot_block'
   */
  2.0,

  /* Expression: i_redun_pulse
   * Referenced by: '<S34>/one_shot_block'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S34>/Switch'
   */
  0.5,

  /* Expression: 80
   * Referenced by: '<Root>/Gain'
   */
  80.0,

  /* Expression: 220
   * Referenced by: '<Root>/Bias1'
   */
  220.0,

  /* Expression: 300
   * Referenced by: '<Root>/Saturation'
   */
  300.0,

  /* Expression: 220
   * Referenced by: '<Root>/Saturation'
   */
  220.0,

  /* Expression: 1
   * Referenced by: '<S18>/Ki (% // m)  '
   */
  1.0,

  /* Expression: qc_get_step_size
   * Referenced by: '<S14>/Constant'
   */
  0.0016666666666666668,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition3'
   */
  0.0,

  /* Expression: d_brightness
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_coloreffect
   * Referenced by: '<S10>/Video Capture'
   */
  0.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S10>/Video Capture'
   */
  0.0,

  /* Expression: d_gain
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_pan
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_tilt
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_roll
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_zoom
   * Referenced by: '<S10>/Video Capture'
   */
  0.0,

  /* Expression: d_exposure
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_iris
   * Referenced by: '<S10>/Video Capture'
   */
  50.0,

  /* Expression: d_focus
   * Referenced by: '<S10>/Video Capture'
   */
  0.0,

  /* Expression: min_pixel
   * Referenced by: '<S12>/Image Transform'
   */
  0.0,

  /* Expression: max_pixel
   * Referenced by: '<S12>/Image Transform'
   */
  4000.0,

  /* Expression: focal_length
   * Referenced by: '<S12>/Image Transform'
   */
  308.0,

  /* Expression: extrapolated
   * Referenced by: '<S12>/Image Transform'
   */
  0.0,

  /* Expression: angle
   * Referenced by: '<S12>/Image Transform'
   */
  0.0,

  /* Expression: radial_coeffs
   * Referenced by: '<S12>/Image Transform'
   */
  { -0.3129, 0.0907 },

  /* Expression: 35
   * Referenced by: '<S21>/Hue Min'
   */
  35.0,

  /* Expression: 60
   * Referenced by: '<S21>/Hue Max'
   */
  60.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain'
   */
  0.5,

  /* Expression: 0.4
   * Referenced by: '<S29>/20%'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S21>/Constant'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain1'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S21>/Constant7'
   */
  1.0,

  /* Expression: 255/360
   * Referenced by: '<S29>/Gain6'
   */
  0.70833333333333337,

  /* Expression: 0
   * Referenced by: '<S21>/Sat Min'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S21>/Sat Max'
   */
  255.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain2'
   */
  0.5,

  /* Expression: 0.4
   * Referenced by: '<S29>/20%1'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S21>/Constant1'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain3'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S21>/Constant6'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Val Min'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S21>/Val Max'
   */
  255.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain4'
   */
  0.5,

  /* Expression: 0.4
   * Referenced by: '<S29>/20%2'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<S21>/Constant2'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain5'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S21>/Constant5'
   */
  1.0,

  /* Expression: [255 255 255]
   * Referenced by: '<S29>/Saturation'
   */
  { 255.0, 255.0, 255.0 },

  /* Expression: [0 0 0]
   * Referenced by: '<S29>/Saturation'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 255/360
   * Referenced by: '<S29>/Gain7'
   */
  0.70833333333333337,

  /* Expression: [255 255 255]
   * Referenced by: '<S29>/Saturation1'
   */
  { 255.0, 255.0, 255.0 },

  /* Expression: [0 0 0]
   * Referenced by: '<S29>/Saturation1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: r_min
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  30.0,

  /* Expression: r_max
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  70.0,

  /* Expression: g_min
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  60.0,

  /* Expression: g_max
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  100.0,

  /* Expression: b_min
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  40.0,

  /* Expression: b_max
   * Referenced by: '<S12>/HSV Color Thresholding'
   */
  80.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant4'
   */
  1.0,

  /* Expression: 0.33
   * Referenced by: '<S19>/Gain'
   */
  0.33,

  /* Expression: 1
   * Referenced by: '<S19>/Bias'
   */
  1.0,

  /* Expression: 0.75
   * Referenced by: '<S19>/Constant3'
   */
  0.75,

  /* Expression: 0.5
   * Referenced by: '<S19>/m_n'
   */
  0.5,

  /* Expression: 50
   * Referenced by: '<S21>/b_n'
   */
  50.0,

  /* Expression: 0.5
   * Referenced by: '<S19>/Steering Saturation1'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S19>/Steering Saturation1'
   */
  -0.5,

  /* Expression: d_brightness
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_gain
   * Referenced by: '<S11>/Depth'
   */
  50.0,

  /* Expression: d_exposure
   * Referenced by: '<S11>/Depth'
   */
  30.0,

  /* Expression: emitter
   * Referenced by: '<S11>/Depth'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<S21>/Stopping Distance (m)'
   */
  0.01,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S8>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S8>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S8>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S8>/HIL Initialize'
   */
  1,

  /* Computed Parameter: ImageTransform_PrPoint
   * Referenced by: '<S12>/Image Transform'
   */
  { 334, 262 },

  /* Computed Parameter: ImageTransform_Interpolation
   * Referenced by: '<S12>/Image Transform'
   */
  1,

  /* Computed Parameter: ImageTransform_Origin
   * Referenced by: '<S12>/Image Transform'
   */
  { 320, 240 },

  /* Computed Parameter: ImageTransform_OOrigin
   * Referenced by: '<S12>/Image Transform'
   */
  { 320, 240 },

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S17>/Gain'
   */
  63.75F,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U, 43U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S8>/HIL Initialize'
   */
  40U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<S8>/HIL Initialize'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: ImageTransform_ColorTheme
   * Referenced by: '<S12>/Image Transform'
   */
  1U,

  /* Computed Parameter: ImageCompress_Quality
   * Referenced by: '<S23>/Image Compress'
   */
  50U,

  /* Computed Parameter: ImageCompress_Quality_p
   * Referenced by: '<S24>/Image Compress'
   */
  50U,

  /* Computed Parameter: Depth_Preset
   * Referenced by: '<S11>/Depth'
   */
  21U,

  /* Computed Parameter: ImageCompress_Quality_k
   * Referenced by: '<S22>/Image Compress'
   */
  50U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S8>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S8>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<S8>/HIL Read'
   */
  true,

  /* Computed Parameter: SteadyLight_Value
   * Referenced by: '<S13>/Steady Light'
   */
  true,

  /* Computed Parameter: LightOff_Value
   * Referenced by: '<S13>/Light Off'
   */
  false,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S8>/HIL Write'
   */
  false,

  /* Computed Parameter: VideoCapture_OvBrightness
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvContrast
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvHue
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvSaturation
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvSharpness
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvGamma
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvColorEnable
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvWhiteBalance
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvBacklightCompens
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvGain
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvPan
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvTilt
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvRoll
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvZoom
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvExposure
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvIris
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvFocus
   * Referenced by: '<S10>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoDisplay_UseHardware
   * Referenced by: '<S23>/Video Display'
   */
  true,

  /* Computed Parameter: VideoDisplay_UseHardware_b
   * Referenced by: '<S24>/Video Display'
   */
  true,

  /* Computed Parameter: VideoDisplay_UseHardware_c
   * Referenced by: '<S22>/Video Display'
   */
  true,

  /* Computed Parameter: imageDepthForDisplay_Y0
   * Referenced by: '<S17>/imageDepthForDisplay'
   */
  0U,

  /* Computed Parameter: uArm0Disarm1_CurrentSetting
   * Referenced by: '<S21>/1 - Arm, 0 - Disarm1'
   */
  1U,

  /* Computed Parameter: uRight0Left_CurrentSetting
   * Referenced by: '<S21>/1 - Right, 0 - Left'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S19>/Manual Switch'
   */
  0U
};
