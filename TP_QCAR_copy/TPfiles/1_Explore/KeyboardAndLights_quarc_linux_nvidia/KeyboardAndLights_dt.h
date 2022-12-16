/*
 * KeyboardAndLights_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "KeyboardAndLights".
 *
 * Model version              : 5.5
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Oct 19 10:14:16 2022
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
  sizeof(t_host_remote_interface),
  sizeof(qthread_section_t),
  sizeof(t_keyboard_state),
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
  "t_host_remote_interface",
  "qthread_section_t",
  "t_keyboard_state",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&KeyboardAndLights_B.motorcurrent), 0, 0, 20 },

  { (char_T *)(&KeyboardAndLights_B.HostInitialize_o2), 6, 0, 1 },

  { (char_T *)(&KeyboardAndLights_B.HostInitialize_o1), 3, 0, 1 }
  ,

  { (char_T *)(&KeyboardAndLights_DW.HostKeyboard_Lock), 15, 0, 1 },

  { (char_T *)(&KeyboardAndLights_DW.HostKeyboard_KeyboardState), 16, 0, 1 },

  { (char_T *)(&KeyboardAndLights_DW.HILInitialize_AIMinimums[0]), 0, 0, 38 },

  { (char_T *)(&KeyboardAndLights_DW.HostInitialize_ConnectedHandle), 14, 0, 1 },

  { (char_T *)(&KeyboardAndLights_DW.HILInitialize_Card), 17, 0, 1 },

  { (char_T *)(&KeyboardAndLights_DW.HILRead_PWORK), 11, 0, 4 },

  { (char_T *)(&KeyboardAndLights_DW.HILInitialize_DOStates), 6, 0, 12 },

  { (char_T *)(&KeyboardAndLights_DW.HILInitialize_POSortedChans), 7, 0, 1 },

  { (char_T *)(&KeyboardAndLights_DW.Integrator1_IWORK), 10, 0, 3 },

  { (char_T *)(&KeyboardAndLights_DW.Unwrap224_FirstSample), 8, 0, 2 },

  { (char_T *)(&KeyboardAndLights_DW.HILWrite_DigitalBuffer), 18, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&KeyboardAndLights_P.LeftSteeringLimit_const), 0, 0, 2 },

  { (char_T *)(&KeyboardAndLights_P.HILRead_analog_channels[0]), 7, 0, 14 },

  { (char_T *)(&KeyboardAndLights_P.HILInitialize_OOTerminate), 0, 0, 42 },

  { (char_T *)(&KeyboardAndLights_P.HILInitialize_EIInitial), 6, 0, 9 },

  { (char_T *)(&KeyboardAndLights_P.HILInitialize_AIChannels[0]), 7, 0, 48 },

  { (char_T *)(&KeyboardAndLights_P.HILInitialize_Active), 8, 0, 42 },

  { (char_T *)(&KeyboardAndLights_P.HostKeyboard_ScanCodes[0]), 3, 0, 34 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] KeyboardAndLights_dt.h */
