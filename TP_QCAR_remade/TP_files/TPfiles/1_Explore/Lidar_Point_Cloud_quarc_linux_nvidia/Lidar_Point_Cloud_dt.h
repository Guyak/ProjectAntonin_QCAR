/*
 * Lidar_Point_Cloud_dt.h
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
  sizeof(t_ranging_sensor),
  sizeof(t_ranging_measurement),
  sizeof(t_timeout)
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
  "t_ranging_sensor",
  "t_ranging_measurement",
  "t_timeout"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Lidar_Point_Cloud_B.RangingSensor_o1[0]), 0, 0, 3600 },

  { (char_T *)(&Lidar_Point_Cloud_B.actualsampletime), 0, 0, 3 },

  { (char_T *)(&Lidar_Point_Cloud_B.Channel), 14, 0, 1 },

  { (char_T *)(&Lidar_Point_Cloud_B.ImageCompress[0]), 3, 0, 160000 }
  ,

  { (char_T *)(&Lidar_Point_Cloud_DW.RangingSensor_Measurements[0]), 17, 0, 720
  },

  { (char_T *)(&Lidar_Point_Cloud_DW.SampleTime_PreviousTime), 18, 0, 3 },

  { (char_T *)(&Lidar_Point_Cloud_DW.BodyFramePolarPlot_XBuffer[0]), 0, 0,
    161440 },

  { (char_T *)(&Lidar_Point_Cloud_DW.ImageCompress_Compress), 15, 0, 1 },

  { (char_T *)(&Lidar_Point_Cloud_DW.RangingSensor_Sensor), 16, 0, 1 },

  { (char_T *)(&Lidar_Point_Cloud_DW.Channel_PWORK.Fifo), 11, 0, 2 },

  { (char_T *)(&Lidar_Point_Cloud_DW.ImageCompress_DIMS1), 6, 0, 3 },

  { (char_T *)(&Lidar_Point_Cloud_DW.BodyFramePolarPlot_IWORK[0]), 10, 0, 2 },

  { (char_T *)(&Lidar_Point_Cloud_DW.ImageCompress_ScanLine[0]), 3, 0, 3200 },

  { (char_T *)(&Lidar_Point_Cloud_DW.BodyFramePolarPlot_IsFull), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Lidar_Point_Cloud_P.BodyFramePolarPlot_maximum_rho), 0, 0, 4 },

  { (char_T *)(&Lidar_Point_Cloud_P.BodyFramePolarPlot_direction), 6, 0, 3 },

  { (char_T *)(&Lidar_Point_Cloud_P.RangingSensor_Budget), 0, 0, 65 },

  { (char_T *)(&Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Style), 6, 0, 10 },

  { (char_T *)(&Lidar_Point_Cloud_P.RangingSensor_Range), 7, 0, 2 },

  { (char_T *)(&Lidar_Point_Cloud_P.RangingSensor_Active), 8, 0, 2 },

  { (char_T *)(&Lidar_Point_Cloud_P.BodyFramePolarPlot_Mode), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] Lidar_Point_Cloud_dt.h */
