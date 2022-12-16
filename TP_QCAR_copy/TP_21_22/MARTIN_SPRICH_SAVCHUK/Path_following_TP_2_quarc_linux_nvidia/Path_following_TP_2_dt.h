/*
 * Path_following_TP_2_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP_2".
 *
 * Model version              : 5.31
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 10:27:35 2022
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
  sizeof(t_card)
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
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Path_following_TP_2_B.Speed), 0, 0, 24 },

  { (char_T *)(&Path_following_TP_2_B.Compare), 8, 0, 1 }
  ,

  { (char_T *)(&Path_following_TP_2_DW.AnimationSFunction_DSTATE[0]), 0, 0, 58 },

  { (char_T *)(&Path_following_TP_2_DW.HILInitialize1_Card), 14, 0, 1 },

  { (char_T *)(&Path_following_TP_2_DW.HILWrite1_PWORK), 11, 0, 6 },

  { (char_T *)(&Path_following_TP_2_DW.HILInitialize1_DOStates), 6, 0, 37 },

  { (char_T *)(&Path_following_TP_2_DW.HILInitialize1_POSortedChans[0]), 7, 0, 8
  },

  { (char_T *)(&Path_following_TP_2_DW.Integrator1_IWORK), 10, 0, 1 },

  { (char_T *)(&Path_following_TP_2_DW.Unwrap224_FirstSample), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Path_following_TP_2_P.X_ic), 0, 0, 4 },

  { (char_T *)(&Path_following_TP_2_P.HILRead_encoder_channels[0]), 7, 0, 6 },

  { (char_T *)(&Path_following_TP_2_P.Constant_Value), 0, 0, 65 },

  { (char_T *)(&Path_following_TP_2_P.HILInitialize1_EIInitial), 6, 0, 6 },

  { (char_T *)(&Path_following_TP_2_P.HILInitialize1_AIChannels[0]), 7, 0, 56 },

  { (char_T *)(&Path_following_TP_2_P.HILInitialize1_Active), 8, 0, 37 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Path_following_TP_2_dt.h */
