/*
 * Intel_Realsense_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Intel_Realsense".
 *
 * Model version              : 1.84
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 09:09:53 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Intel_Realsense.h"
#include "Intel_Realsense_private.h"

/* Block parameters (default storage) */
P_Intel_Realsense_T Intel_Realsense_P = {
  /* Mask Parameter: ImageTransform_max_pixel
   * Referenced by: '<S4>/Image Transform'
   */
  50.0F,

  /* Mask Parameter: ImageTransform_min_pixel
   * Referenced by: '<S4>/Image Transform'
   */
  0.0F,

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

  /* Expression: focal_length
   * Referenced by: '<S4>/Image Transform'
   */
  308.0,

  /* Expression: extrapolated
   * Referenced by: '<S4>/Image Transform'
   */
  0.0,

  /* Expression: angle
   * Referenced by: '<S4>/Image Transform'
   */
  0.0,

  /* Expression: radial_coeffs
   * Referenced by: '<S4>/Image Transform'
   */
  { -0.3129, 0.0907 },

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

  /* Computed Parameter: ImageTransform_PrPoint
   * Referenced by: '<S4>/Image Transform'
   */
  { 334, 262 },

  /* Computed Parameter: ImageTransform_Interpolation
   * Referenced by: '<S4>/Image Transform'
   */
  1,

  /* Computed Parameter: ImageTransform_Origin
   * Referenced by: '<S4>/Image Transform'
   */
  { 320, 240 },

  /* Computed Parameter: ImageTransform_OOrigin
   * Referenced by: '<S4>/Image Transform'
   */
  { 320, 240 },

  /* Computed Parameter: ImageTransform_ColorTheme
   * Referenced by: '<S4>/Image Transform'
   */
  1U,

  /* Computed Parameter: ImageCompress_Quality
   * Referenced by: '<S6>/Image Compress'
   */
  50U,

  /* Computed Parameter: ImageCompress_Quality_n
   * Referenced by: '<S7>/Image Compress'
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
   * Referenced by: '<S6>/Video Display'
   */
  true,

  /* Computed Parameter: VideoDisplay_UseHardware_k
   * Referenced by: '<S7>/Video Display'
   */
  true
};
