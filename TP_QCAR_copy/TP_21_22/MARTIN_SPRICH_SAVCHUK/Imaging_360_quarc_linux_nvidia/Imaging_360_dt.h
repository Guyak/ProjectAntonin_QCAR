/*
 * Imaging_360_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Imaging_360".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 09:05:38 2022
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
  sizeof(t_video_capture),
  sizeof(t_channel),
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
  "t_video_capture",
  "t_channel",
  "t_timeout"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Imaging_360_B.actualsampletime), 0, 0, 3 },

  { (char_T *)(&Imaging_360_B.Channel), 15, 0, 1 },

  { (char_T *)(&Imaging_360_B.VideoCapture_o1[0]), 3, 0, 7372800 }
  ,

  { (char_T *)(&Imaging_360_DW.SampleTime_PreviousTime), 16, 0, 3 },

  { (char_T *)(&Imaging_360_DW.VideoCapture_VideoCapture), 14, 0, 4 },

  { (char_T *)(&Imaging_360_DW.Scope_PWORK.LoggedData), 11, 0, 2 },

  { (char_T *)(&Imaging_360_DW.stich_SubsysRanBC), 2, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Imaging_360_P.Constant_Value), 0, 0, 69 },

  { (char_T *)(&Imaging_360_P.VideoDisplay_UseHardware), 8, 0, 69 },

  { (char_T *)(&Imaging_360_P.u60view_Y0), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Imaging_360_dt.h */
