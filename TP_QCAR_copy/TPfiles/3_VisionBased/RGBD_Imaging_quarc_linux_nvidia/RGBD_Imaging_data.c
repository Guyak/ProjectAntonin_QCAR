/*
 * RGBD_Imaging_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RGBD_Imaging".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Oct 17 16:16:41 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RGBD_Imaging.h"
#include "RGBD_Imaging_private.h"

/* Block parameters (default storage) */
P_RGBD_Imaging_T RGBD_Imaging_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S12>/Constant'
   */
  -1.0,

  /* Mask Parameter: HSVColorThresholding_b_comparis
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  1,

  /* Mask Parameter: ImageFindObjects_connectivity
   * Referenced by: '<S5>/Image Find Objects'
   */
  2,

  /* Mask Parameter: HSVColorThresholding_g_comparis
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  1,

  /* Mask Parameter: HSVColorThresholding_r_comparis
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  9,

  /* Mask Parameter: ImageFindObjects_sort_order
   * Referenced by: '<S5>/Image Find Objects'
   */
  4,

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S9>/Constant'
   */
  1U,

  /* Mask Parameter: ImageFindObjects_max_pixels
   * Referenced by: '<S5>/Image Find Objects'
   */
  4294967295U,

  /* Mask Parameter: ImageFindObjects_min_pixels
   * Referenced by: '<S5>/Image Find Objects'
   */
  100U,

  /* Mask Parameter: Depth_stream_index
   * Referenced by: '<S3>/Depth'
   */
  0U,

  /* Mask Parameter: RGB_stream_index
   * Referenced by: '<S3>/RGB'
   */
  0U,

  /* Mask Parameter: Video3DInitialize_active
   * Referenced by: '<S3>/Video3D Initialize'
   */
  true,

  /* Mask Parameter: ImageFindObjects_exclude_at_edg
   * Referenced by: '<S5>/Image Find Objects'
   */
  true,

  /* Mask Parameter: ImageFindObjects_largest
   * Referenced by: '<S5>/Image Find Objects'
   */
  true,

  /* Expression: 720/2
   * Referenced by: '<S4>/Constant'
   */
  360.0,

  /* Expression: 42.5/57
   * Referenced by: '<S4>/Adjust for V-FOV'
   */
  0.74561403508771928,

  /* Expression: 69.4/86
   * Referenced by: '<S4>/Adjust for H-FOV'
   */
  0.80697674418604659,

  /* Expression: 1280/2
   * Referenced by: '<S4>/Constant1'
   */
  640.0,

  /* Expression: 255
   * Referenced by: '<S11>/Constant1'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant'
   */
  0.0,

  /* Computed Parameter: blobLocationpx2_Y0
   * Referenced by: '<S5>/blobLocation (px) [2]'
   */
  0.0,

  /* Expression: min_pixel
   * Referenced by: '<S11>/Image Transform'
   */
  0.0,

  /* Expression: max_pixel
   * Referenced by: '<S11>/Image Transform'
   */
  4000.0,

  /* Expression: focal_length
   * Referenced by: '<S11>/Image Transform'
   */
  308.0,

  /* Expression: extrapolated
   * Referenced by: '<S11>/Image Transform'
   */
  0.0,

  /* Expression: angle
   * Referenced by: '<S11>/Image Transform'
   */
  0.0,

  /* Expression: radial_coeffs
   * Referenced by: '<S11>/Image Transform'
   */
  { -0.3129, 0.0907 },

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S11>/Hue Threshold'
   */
  20.0,

  /* Expression: 255/360
   * Referenced by: '<S11>/Gain'
   */
  0.70833333333333337,

  /* Expression: [100, 100]
   * Referenced by: '<S5>/Constant1'
   */
  { 100.0, 100.0 },

  /* Expression: [255, 255]
   * Referenced by: '<S5>/Constant2'
   */
  { 255.0, 255.0 },

  /* Expression: r_min
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  30.0,

  /* Expression: r_max
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  70.0,

  /* Expression: g_min
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  60.0,

  /* Expression: g_max
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  100.0,

  /* Expression: b_min
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  40.0,

  /* Expression: b_max
   * Referenced by: '<S11>/HSV Color Thresholding'
   */
  80.0,

  /* Expression: [720/2, 1280/2]
   * Referenced by: '<S5>/Constant3'
   */
  { 360.0, 640.0 },

  /* Expression: d_brightness
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_gain
   * Referenced by: '<S3>/Depth'
   */
  50.0,

  /* Expression: d_exposure
   * Referenced by: '<S3>/Depth'
   */
  30.0,

  /* Expression: emitter
   * Referenced by: '<S3>/Depth'
   */
  1.0,

  /* Expression: d_brightness
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_gain
   * Referenced by: '<S3>/RGB'
   */
  50.0,

  /* Expression: d_exposure
   * Referenced by: '<S3>/RGB'
   */
  30.0,

  /* Expression: emitter
   * Referenced by: '<S3>/RGB'
   */
  1.0,

  /* Expression: qc_get_step_size
   * Referenced by: '<S6>/Constant'
   */
  0.033333333333333333,

  /* Computed Parameter: ImageTransform_PrPoint
   * Referenced by: '<S11>/Image Transform'
   */
  { 262, 334 },

  /* Computed Parameter: ImageTransform_Interpolation
   * Referenced by: '<S11>/Image Transform'
   */
  1,

  /* Computed Parameter: ImageTransform_Origin
   * Referenced by: '<S11>/Image Transform'
   */
  { 240, 320 },

  /* Computed Parameter: ImageTransform_OOrigin
   * Referenced by: '<S11>/Image Transform'
   */
  { 240, 320 },

  /* Computed Parameter: distanceToSignm_Y0
   * Referenced by: '<S4>/distanceToSign (m)'
   */
  0.0F,

  /* Computed Parameter: ImageCompress_Quality
   * Referenced by: '<S7>/Image Compress'
   */
  50U,

  /* Computed Parameter: ImageTransform_ColorTheme
   * Referenced by: '<S11>/Image Transform'
   */
  1U,

  /* Computed Parameter: ImageCompress_Quality_o
   * Referenced by: '<S8>/Image Compress'
   */
  50U,

  /* Computed Parameter: ImageCompress_Quality_f
   * Referenced by: '<S10>/Image Compress'
   */
  50U,

  /* Computed Parameter: Depth_Preset
   * Referenced by: '<S3>/Depth'
   */
  21U,

  /* Computed Parameter: RGB_Preset
   * Referenced by: '<S3>/RGB'
   */
  21U,

  /* Computed Parameter: VideoDisplay_UseHardware
   * Referenced by: '<S7>/Video Display'
   */
  true,

  /* Computed Parameter: blobFound_Y0
   * Referenced by: '<S5>/blobFound?'
   */
  false,

  /* Computed Parameter: VideoDisplay_UseHardware_g
   * Referenced by: '<S8>/Video Display'
   */
  true,

  /* Computed Parameter: VideoDisplay_UseHardware_d
   * Referenced by: '<S10>/Video Display'
   */
  true
};
