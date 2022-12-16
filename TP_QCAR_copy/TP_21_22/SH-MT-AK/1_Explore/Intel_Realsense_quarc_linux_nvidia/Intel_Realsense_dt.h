/*
 * Intel_Realsense_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Intel_Realsense".
 *
 * Model version              : 1.84
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 21 09:16:41 2022
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
  sizeof(t_video3d),
  sizeof(t_video3d_stream),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_colorization),
  sizeof(t_channel),
  sizeof(t_jpeg_compress)
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
  "t_video3d",
  "t_video3d_stream",
  "t_int64",
  "t_uint64",
  "t_colorization",
  "t_channel",
  "t_jpeg_compress"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Intel_Realsense_B.Depth_o2), 17, 0, 2 },

  { (char_T *)(&Intel_Realsense_B.Depth_o3), 0, 0, 2 },

  { (char_T *)(&Intel_Realsense_B.Channel), 19, 0, 2 },

  { (char_T *)(&Intel_Realsense_B.Depth_o1[0]), 1, 0, 921600 },

  { (char_T *)(&Intel_Realsense_B.RGB_o1[0]), 3, 0, 8294400 },

  { (char_T *)(&Intel_Realsense_B.Depth_o4), 8, 0, 2 }
  ,

  { (char_T *)(&Intel_Realsense_DW.Video3DInitialize_Video3D), 14, 0, 3 },

  { (char_T *)(&Intel_Realsense_DW.Depth_Stream), 15, 0, 2 },

  { (char_T *)(&Intel_Realsense_DW.ImageTransform_AlgHandle), 18, 0, 1 },

  { (char_T *)(&Intel_Realsense_DW.ImageCompress_Compress), 20, 0, 2 },

  { (char_T *)(&Intel_Realsense_DW.Channel_PWORK.Fifo), 11, 0, 2 },

  { (char_T *)(&Intel_Realsense_DW.ImageCompress_DIMS1), 6, 0, 2 },

  { (char_T *)(&Intel_Realsense_DW.enabledDisplay_SubsysRanBC), 2, 0, 2 },

  { (char_T *)(&Intel_Realsense_DW.ImageCompress_ScanLine[0]), 3, 0, 61440 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Intel_Realsense_P.ImageTransform_max_pixel), 1, 0, 2 },

  { (char_T *)(&Intel_Realsense_P.Depth_stream_index), 7, 0, 2 },

  { (char_T *)(&Intel_Realsense_P.Video3DInitialize_active), 8, 0, 1 },

  { (char_T *)(&Intel_Realsense_P.ImageTransform_FocalLen), 0, 0, 27 },

  { (char_T *)(&Intel_Realsense_P.ImageTransform_PrPoint[0]), 6, 0, 7 },

  { (char_T *)(&Intel_Realsense_P.ImageTransform_ColorTheme), 7, 0, 5 },

  { (char_T *)(&Intel_Realsense_P.VideoDisplay_UseHardware), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] Intel_Realsense_dt.h */
