/*
 * Imaging_360_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Imaging_360".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 09:04:21 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Imaging_360.h"
#include "Imaging_360_private.h"

/* Block parameters (default storage) */
P_Imaging_360_T Imaging_360_P = {
  /* Expression: qc_get_step_size
   * Referenced by: '<S5>/Constant'
   */
  0.033333333333333333,

  /* Expression: d_brightness
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_coloreffect
   * Referenced by: '<S3>/Video Capture'
   */
  0.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S3>/Video Capture'
   */
  0.0,

  /* Expression: d_gain
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_pan
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_tilt
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_roll
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_zoom
   * Referenced by: '<S3>/Video Capture'
   */
  0.0,

  /* Expression: d_exposure
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_iris
   * Referenced by: '<S3>/Video Capture'
   */
  50.0,

  /* Expression: d_focus
   * Referenced by: '<S3>/Video Capture'
   */
  0.0,

  /* Expression: d_brightness
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_coloreffect
   * Referenced by: '<S3>/Video Capture1'
   */
  0.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S3>/Video Capture1'
   */
  0.0,

  /* Expression: d_gain
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_pan
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_tilt
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_roll
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_zoom
   * Referenced by: '<S3>/Video Capture1'
   */
  0.0,

  /* Expression: d_exposure
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_iris
   * Referenced by: '<S3>/Video Capture1'
   */
  50.0,

  /* Expression: d_focus
   * Referenced by: '<S3>/Video Capture1'
   */
  0.0,

  /* Expression: d_brightness
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_coloreffect
   * Referenced by: '<S3>/Video Capture2'
   */
  0.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S3>/Video Capture2'
   */
  0.0,

  /* Expression: d_gain
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_pan
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_tilt
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_roll
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_zoom
   * Referenced by: '<S3>/Video Capture2'
   */
  0.0,

  /* Expression: d_exposure
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_iris
   * Referenced by: '<S3>/Video Capture2'
   */
  50.0,

  /* Expression: d_focus
   * Referenced by: '<S3>/Video Capture2'
   */
  0.0,

  /* Expression: d_brightness
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_coloreffect
   * Referenced by: '<S3>/Video Capture3'
   */
  0.0,

  /* Expression: d_whitebalance
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<S3>/Video Capture3'
   */
  0.0,

  /* Expression: d_gain
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_pan
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_tilt
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_roll
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_zoom
   * Referenced by: '<S3>/Video Capture3'
   */
  0.0,

  /* Expression: d_exposure
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_iris
   * Referenced by: '<S3>/Video Capture3'
   */
  50.0,

  /* Expression: d_focus
   * Referenced by: '<S3>/Video Capture3'
   */
  0.0,

  /* Computed Parameter: VideoDisplay_UseHardware
   * Referenced by: '<S4>/Video Display'
   */
  true,

  /* Computed Parameter: VideoCapture_OvBrightness
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvContrast
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvHue
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvSaturation
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvSharpness
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvGamma
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvColorEnable
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvWhiteBalance
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvBacklightCompens
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvGain
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvPan
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvTilt
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvRoll
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvZoom
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvExposure
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvIris
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture_OvFocus
   * Referenced by: '<S3>/Video Capture'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvBrightness
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvContrast
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvHue
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvSaturation
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvSharpness
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvGamma
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvColorEnable
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvWhiteBalance
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvBacklightCompen
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvGain
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvPan
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvTilt
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvRoll
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvZoom
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvExposure
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvIris
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture1_OvFocus
   * Referenced by: '<S3>/Video Capture1'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvBrightness
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvContrast
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvHue
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvSaturation
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvSharpness
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvGamma
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvColorEnable
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvWhiteBalance
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvBacklightCompen
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvGain
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvPan
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvTilt
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvRoll
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvZoom
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvExposure
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvIris
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture2_OvFocus
   * Referenced by: '<S3>/Video Capture2'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvBrightness
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvContrast
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvHue
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvSaturation
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvSharpness
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvGamma
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvColorEnable
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvWhiteBalance
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvBacklightCompen
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvGain
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvPan
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvTilt
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvRoll
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvZoom
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvExposure
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvIris
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: VideoCapture3_OvFocus
   * Referenced by: '<S3>/Video Capture3'
   */
  false,

  /* Computed Parameter: u60view_Y0
   * Referenced by: '<S6>/360 view'
   */
  0U
};
