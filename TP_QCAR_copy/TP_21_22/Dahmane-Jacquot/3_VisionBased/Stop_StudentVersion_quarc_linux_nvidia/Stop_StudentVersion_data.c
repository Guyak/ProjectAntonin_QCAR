/*
 * Stop_StudentVersion_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Stop_StudentVersion".
 *
 * Model version              : 5.1
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 17:31:11 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Stop_StudentVersion.h"
#include "Stop_StudentVersion_private.h"

/* Block parameters (default storage) */
P_Stop_StudentVersion_T Stop_StudentVersion_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S17>/Constant'
   */
  -1.0,

  /* Mask Parameter: HSVColorThresholding_b_comparis
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  1,

  /* Mask Parameter: ImageFindObjects_connectivity
   * Referenced by: '<S8>/Image Find Objects'
   */
  2,

  /* Mask Parameter: HSVColorThresholding_g_comparis
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  1,

  /* Mask Parameter: HSVColorThresholding_r_comparis
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  9,

  /* Mask Parameter: ImageFindObjects_sort_order
   * Referenced by: '<S8>/Image Find Objects'
   */
  4,

  /* Mask Parameter: HILRead_analog_channels
   * Referenced by: '<S3>/HIL Read'
   */
  { 5U, 6U },

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S14>/Constant'
   */
  1U,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<S3>/HIL Read'
   */
  0U,

  /* Mask Parameter: ImageFindObjects_max_pixels
   * Referenced by: '<S8>/Image Find Objects'
   */
  4294967295U,

  /* Mask Parameter: ImageFindObjects_min_pixels
   * Referenced by: '<S8>/Image Find Objects'
   */
  100U,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S3>/HIL Write'
   */
  1000U,

  /* Mask Parameter: HILWrite_pwm_channels
   * Referenced by: '<S3>/HIL Write'
   */
  0U,

  /* Mask Parameter: Depth_stream_index
   * Referenced by: '<S6>/Depth'
   */
  0U,

  /* Mask Parameter: RGB_stream_index
   * Referenced by: '<S6>/RGB'
   */
  0U,

  /* Mask Parameter: Video3DInitialize_active
   * Referenced by: '<S6>/Video3D Initialize'
   */
  true,

  /* Mask Parameter: ImageFindObjects_exclude_at_edg
   * Referenced by: '<S8>/Image Find Objects'
   */
  true,

  /* Mask Parameter: ImageFindObjects_largest
   * Referenced by: '<S8>/Image Find Objects'
   */
  true,

  /* Expression: 720/2
   * Referenced by: '<S7>/Constant'
   */
  360.0,

  /* Expression: 42.5/57
   * Referenced by: '<S7>/Adjust for V-FOV'
   */
  0.74561403508771928,

  /* Expression: 69.4/86
   * Referenced by: '<S7>/Adjust for H-FOV'
   */
  0.80697674418604659,

  /* Expression: 1280/2
   * Referenced by: '<S7>/Constant1'
   */
  640.0,

  /* Expression: 255
   * Referenced by: '<S16>/Constant1'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S16>/Constant'
   */
  0.0,

  /* Computed Parameter: blobLocationpx2_Y0
   * Referenced by: '<S8>/blobLocation (px) [2]'
   */
  0.0,

  /* Expression: min_pixel
   * Referenced by: '<S16>/Image Transform'
   */
  0.0,

  /* Expression: max_pixel
   * Referenced by: '<S16>/Image Transform'
   */
  4000.0,

  /* Expression: focal_length
   * Referenced by: '<S16>/Image Transform'
   */
  308.0,

  /* Expression: extrapolated
   * Referenced by: '<S16>/Image Transform'
   */
  0.0,

  /* Expression: angle
   * Referenced by: '<S16>/Image Transform'
   */
  0.0,

  /* Expression: radial_coeffs
   * Referenced by: '<S16>/Image Transform'
   */
  { -0.3129, 0.0907 },

  /* Expression: 0
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S16>/Hue Threshold'
   */
  20.0,

  /* Expression: 255/360
   * Referenced by: '<S16>/Gain'
   */
  0.70833333333333337,

  /* Expression: [100, 100]
   * Referenced by: '<S8>/Constant1'
   */
  { 100.0, 100.0 },

  /* Expression: [255, 255]
   * Referenced by: '<S8>/Constant2'
   */
  { 255.0, 255.0 },

  /* Expression: r_min
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  30.0,

  /* Expression: r_max
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  70.0,

  /* Expression: g_min
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  60.0,

  /* Expression: g_max
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  100.0,

  /* Expression: b_min
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  40.0,

  /* Expression: b_max
   * Referenced by: '<S16>/HSV Color Thresholding'
   */
  80.0,

  /* Expression: [720/2, 1280/2]
   * Referenced by: '<S8>/Constant3'
   */
  { 360.0, 640.0 },

  /* Expression: 0
   * Referenced by: '<S18>/Constant'
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
   * Referenced by: '<S11>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<S3>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0
   * Referenced by: '<S11>/Integrator2'
   */
  0.0,

  /* Expression: d_brightness
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_gain
   * Referenced by: '<S6>/Depth'
   */
  50.0,

  /* Expression: d_exposure
   * Referenced by: '<S6>/Depth'
   */
  30.0,

  /* Expression: emitter
   * Referenced by: '<S6>/Depth'
   */
  1.0,

  /* Expression: d_brightness
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_gain
   * Referenced by: '<S6>/RGB'
   */
  50.0,

  /* Expression: d_exposure
   * Referenced by: '<S6>/RGB'
   */
  30.0,

  /* Expression: emitter
   * Referenced by: '<S6>/RGB'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/m//s'
   */
  0.2,

  /* Expression: 5
   * Referenced by: '<S10>/command saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S10>/command saturation'
   */
  -5.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S10>/Kff  (% // m//s)'
   */
  0.1,

  /* Expression: 1/720/4
   * Referenced by: '<S5>/counts to rotations'
   */
  0.00034722222222222224,

  /* Expression: (13*19)/(70*37)
   * Referenced by: '<S5>/gear ratios'
   */
  0.095366795366795362,

  /* Expression: 2*pi
   * Referenced by: '<S5>/rot//s to rad//s'
   */
  6.2831853071795862,

  /* Expression: 0.0342
   * Referenced by: '<S5>/wheel radius'
   */
  0.0342,

  /* Expression: 0.3
   * Referenced by: '<S10>/Kp (% // m//s)'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator1'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<S10>/Integrator1'
   */
  0.4,

  /* Expression: -0.4
   * Referenced by: '<S10>/Integrator1'
   */
  -0.4,

  /* Expression: -1
   * Referenced by: '<S3>/direction convention'
   */
  -1.0,

  /* Expression: 0.25
   * Referenced by: '<S3>/command saturation'
   */
  0.25,

  /* Expression: -0.25
   * Referenced by: '<S3>/command saturation'
   */
  -0.25,

  /* Expression: 0.0
   * Referenced by: '<S3>/Steering'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S3>/Gain'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Steering Bias'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Ki (% // m)  '
   */
  1.0,

  /* Expression: qc_get_step_size
   * Referenced by: '<S9>/Constant'
   */
  0.033333333333333333,

  /* Computed Parameter: ImageTransform_PrPoint
   * Referenced by: '<S16>/Image Transform'
   */
  { 262, 334 },

  /* Computed Parameter: ImageTransform_Interpolation
   * Referenced by: '<S16>/Image Transform'
   */
  1,

  /* Computed Parameter: ImageTransform_Origin
   * Referenced by: '<S16>/Image Transform'
   */
  { 240, 320 },

  /* Computed Parameter: ImageTransform_OOrigin
   * Referenced by: '<S16>/Image Transform'
   */
  { 240, 320 },

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

  /* Computed Parameter: distanceToSignm_Y0
   * Referenced by: '<S7>/distanceToSign (m)'
   */
  0.0F,

  /* Computed Parameter: ImageCompress_Quality
   * Referenced by: '<S12>/Image Compress'
   */
  50U,

  /* Computed Parameter: ImageTransform_ColorTheme
   * Referenced by: '<S16>/Image Transform'
   */
  1U,

  /* Computed Parameter: ImageCompress_Quality_o
   * Referenced by: '<S13>/Image Compress'
   */
  50U,

  /* Computed Parameter: ImageCompress_Quality_f
   * Referenced by: '<S15>/Image Compress'
   */
  50U,

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

  /* Computed Parameter: Depth_Preset
   * Referenced by: '<S6>/Depth'
   */
  21U,

  /* Computed Parameter: RGB_Preset
   * Referenced by: '<S6>/RGB'
   */
  21U,

  /* Computed Parameter: VideoDisplay_UseHardware
   * Referenced by: '<S12>/Video Display'
   */
  true,

  /* Computed Parameter: blobFound_Y0
   * Referenced by: '<S8>/blobFound?'
   */
  false,

  /* Computed Parameter: VideoDisplay_UseHardware_g
   * Referenced by: '<S13>/Video Display'
   */
  true,

  /* Computed Parameter: VideoDisplay_UseHardware_d
   * Referenced by: '<S15>/Video Display'
   */
  true,

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

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S3>/HIL Write'
   */
  false
};
