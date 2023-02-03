/*
 * Lidar_Point_Cloud_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lidar_Point_Cloud".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Feb  1 11:22:53 2023
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lidar_Point_Cloud.h"
#include "Lidar_Point_Cloud_private.h"

/* Block parameters (default storage) */
P_Lidar_Point_Cloud_T Lidar_Point_Cloud_P = {
  /* Mask Parameter: BodyFramePolarPlot_maximum_rho
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  5.0,

  /* Mask Parameter: BodyFramePolarPlot_maximum_thet
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  360.0,

  /* Mask Parameter: BodyFramePolarPlot_minimum_rho
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.0,

  /* Mask Parameter: BodyFramePolarPlot_minimum_thet
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.0,

  /* Mask Parameter: BodyFramePolarPlot_direction
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Mask Parameter: BodyFramePolarPlot_update_rate
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Mask Parameter: BodyFramePolarPlot_zero_locatio
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  2,

  /* Expression: timing_budget
   * Referenced by: '<S4>/Ranging Sensor'
   */
  0.033,

  /* Expression: measurement_period
   * Referenced by: '<S4>/Ranging Sensor'
   */
  0.0001,

  /* Expression: max_interpolated_distance
   * Referenced by: '<S4>/Ranging Sensor'
   */
  0.0,

  /* Expression: max_interpolated_angle
   * Referenced by: '<S4>/Ranging Sensor'
   */
  5.0,

  /* Expression: -1
   * Referenced by: '<S4>/Change to  CCW rotation'
   */
  -1.0,

  /* Expression: pi/2
   * Referenced by: '<S4>/Change +x to front of QCar '
   */
  1.5707963267948966,

  /* Expression: line1_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line1_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.0, 0.447, 0.741 },

  /* Expression: marker1_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1.0,

  /* Expression: marker1_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.0, 0.447059, 0.741176 },

  /* Expression: marker1_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.0, 0.447059, 0.741176 },

  /* Expression: line2_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line2_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.85098, 0.32549, 0.0980392 },

  /* Expression: marker2_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker2_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.85098, 0.32549, 0.0980392 },

  /* Expression: marker2_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.85098, 0.32549, 0.0980392 },

  /* Expression: line3_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line3_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.929412, 0.694118, 0.12549 },

  /* Expression: marker3_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker3_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.929412, 0.694118, 0.12549 },

  /* Expression: marker3_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.929412, 0.694118, 0.12549 },

  /* Expression: line4_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line4_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.494118, 0.184314, 0.556863 },

  /* Expression: marker4_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker4_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.494118, 0.184314, 0.556863 },

  /* Expression: marker4_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.494118, 0.184314, 0.556863 },

  /* Expression: line5_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line5_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.466667, 0.67451, 0.188235 },

  /* Expression: marker5_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker5_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.466667, 0.67451, 0.188235 },

  /* Expression: marker5_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.466667, 0.67451, 0.188235 },

  /* Expression: 4
   * Referenced by: '<S6>/maximumDistance (m)'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/decay'
   */
  0.0,

  /* Expression: qc_get_step_size
   * Referenced by: '<S5>/Constant'
   */
  0.033333333333333333,

  /* Computed Parameter: BodyFramePolarPlot_L1Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  5,

  /* Computed Parameter: BodyFramePolarPlot_L1Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  4,

  /* Computed Parameter: BodyFramePolarPlot_L2Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L2Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: BodyFramePolarPlot_L3Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L3Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: BodyFramePolarPlot_L4Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L4Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: BodyFramePolarPlot_L5Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L5Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: RangingSensor_Range
   * Referenced by: '<S4>/Ranging Sensor'
   */
  3U,

  /* Computed Parameter: ImageCompress_Quality
   * Referenced by: '<S3>/Image Compress'
   */
  50U,

  /* Computed Parameter: RangingSensor_Active
   * Referenced by: '<S4>/Ranging Sensor'
   */
  true,

  /* Computed Parameter: VideoDisplay_UseHardware
   * Referenced by: '<S3>/Video Display'
   */
  true,

  /* Computed Parameter: BodyFramePolarPlot_Mode
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  2U
};
