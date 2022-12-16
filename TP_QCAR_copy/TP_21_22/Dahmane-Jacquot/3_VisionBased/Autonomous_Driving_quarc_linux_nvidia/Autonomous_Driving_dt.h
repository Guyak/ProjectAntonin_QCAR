/*
 * Autonomous_Driving_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Autonomous_Driving".
 *
 * Model version              : 4.6
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 17:05:24 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_channel),
  sizeof(t_jpeg_compress),
  sizeof(t_video_capture),
  sizeof(t_video3d),
  sizeof(t_video3d_stream),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_image_rgb_to_hsv),
  sizeof(t_timeout),
  sizeof(t_card),
  sizeof(t_boolean)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_channel",
  "t_jpeg_compress",
  "t_video_capture",
  "t_video3d",
  "t_video3d_stream",
  "t_int64",
  "t_uint64",
  "t_image_rgb_to_hsv",
  "t_timeout",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Autonomous_Driving_B.Depth_o2), 20, 0, 1 },

  { (char_T *)(&Autonomous_Driving_B.motorcurrent), 0, 0, 57 },

  { (char_T *)(&Autonomous_Driving_B.Channel), 14, 0, 3 },

  { (char_T *)(&Autonomous_Driving_B.Depth_o1[0]), 1, 0, 230400 },

  { (char_T *)(&Autonomous_Driving_B.VideoCapture_o1[0]), 3, 0, 1443189 },

  { (char_T *)(&Autonomous_Driving_B.Compare), 8, 0, 6 }
  ,

  { (char_T *)(&Autonomous_Driving_DW.SampleTime_PreviousTime), 22, 0, 9 },

  { (char_T *)(&Autonomous_Driving_DW.one_shot_block_DSTATE[0]), 0, 0, 66 },

  { (char_T *)(&Autonomous_Driving_DW.ImageCompress_Compress), 15, 0, 3 },

  { (char_T *)(&Autonomous_Driving_DW.VideoCapture_VideoCapture), 16, 0, 1 },

  { (char_T *)(&Autonomous_Driving_DW.Video3DInitialize_Video3D), 17, 0, 2 },

  { (char_T *)(&Autonomous_Driving_DW.Depth_Stream), 18, 0, 1 },

  { (char_T *)(&Autonomous_Driving_DW.ImageTransform_AlgHandle), 21, 0, 1 },

  { (char_T *)(&Autonomous_Driving_DW.HILInitialize_Card), 23, 0, 1 },

  { (char_T *)(&Autonomous_Driving_DW.HILRead_PWORK), 11, 0, 18 },

  { (char_T *)(&Autonomous_Driving_DW.HILInitialize_DOStates), 6, 0, 40 },

  { (char_T *)(&Autonomous_Driving_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&Autonomous_Driving_DW.Integrator1_IWORK), 10, 0, 3 },

  { (char_T *)(&Autonomous_Driving_DW.obstacleDetection_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Autonomous_Driving_DW.ImageCompress_ScanLine[0]), 3, 0, 18264 },

  { (char_T *)(&Autonomous_Driving_DW.Unwrap224_FirstSample), 8, 0, 1 },

  { (char_T *)(&Autonomous_Driving_DW.HILWrite_DigitalBuffer), 24, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  22U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Autonomous_Driving_P.camera_rate), 0, 0, 16 },

  { (char_T *)(&Autonomous_Driving_P.HSVColorThresholding_b_comparis), 6, 0, 3 },

  { (char_T *)(&Autonomous_Driving_P.HILRead_analog_channels[0]), 7, 0, 15 },

  { (char_T *)(&Autonomous_Driving_P.Video3DInitialize_active), 8, 0, 1 },

  { (char_T *)(&Autonomous_Driving_P.distancem_Y0), 0, 0, 178 },

  { (char_T *)(&Autonomous_Driving_P.HILInitialize_EIInitial), 6, 0, 13 },

  { (char_T *)(&Autonomous_Driving_P.Gain_Gain_g), 1, 0, 1 },

  { (char_T *)(&Autonomous_Driving_P.HILInitialize_AIChannels[0]), 7, 0, 61 },

  { (char_T *)(&Autonomous_Driving_P.HILInitialize_Active), 8, 0, 59 },

  { (char_T *)(&Autonomous_Driving_P.imageDepthForDisplay_Y0), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  10U,
  rtPTransitions
};

/* [EOF] Autonomous_Driving_dt.h */
