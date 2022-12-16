/*
 * Basic_IO_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Basic_IO".
 *
 * Model version              : 4.3
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 08:25:49 2022
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
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Basic_IO_B.motorcurrent), 0, 0, 12 }
  ,

  { (char_T *)(&Basic_IO_DW.HILInitialize_AIMinimums[0]), 0, 0, 38 },

  { (char_T *)(&Basic_IO_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Basic_IO_DW.HILRead_PWORK), 11, 0, 2 },

  { (char_T *)(&Basic_IO_DW.HILInitialize_DOStates), 6, 0, 12 },

  { (char_T *)(&Basic_IO_DW.HILInitialize_POSortedChans), 7, 0, 1 },

  { (char_T *)(&Basic_IO_DW.Integrator1_IWORK), 10, 0, 3 },

  { (char_T *)(&Basic_IO_DW.Unwrap224_FirstSample), 8, 0, 1 },

  { (char_T *)(&Basic_IO_DW.HILWrite_DigitalBuffer), 15, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Basic_IO_P.Throttle02to02_gain), 0, 0, 2 },

  { (char_T *)(&Basic_IO_P.HILRead_analog_channels[0]), 7, 0, 14 },

  { (char_T *)(&Basic_IO_P.HILInitialize_OOTerminate), 0, 0, 35 },

  { (char_T *)(&Basic_IO_P.HILInitialize_EIInitial), 6, 0, 6 },

  { (char_T *)(&Basic_IO_P.HILInitialize_AIChannels[0]), 7, 0, 48 },

  { (char_T *)(&Basic_IO_P.HILInitialize_Active), 8, 0, 37 },

  { (char_T *)(&Basic_IO_P.ManualSwitch_CurrentSetting), 3, 0, 8 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] Basic_IO_dt.h */
