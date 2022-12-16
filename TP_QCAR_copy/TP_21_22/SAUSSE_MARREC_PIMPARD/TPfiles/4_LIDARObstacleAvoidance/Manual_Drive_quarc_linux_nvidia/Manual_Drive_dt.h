/*
 * Manual_Drive_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Manual_Drive".
 *
 * Model version              : 1.212
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 17 10:36:28 2022
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
  sizeof(t_game_controller),
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
  "t_game_controller",
  "t_timeout",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Manual_Drive_B.encodercounts), 0, 0, 13 },

  { (char_T *)(&Manual_Drive_B.GameController_o1), 8, 0, 34 }
  ,

  { (char_T *)(&Manual_Drive_DW.SampleTime_PreviousTime), 15, 0, 3 },

  { (char_T *)(&Manual_Drive_DW.one_shot_block_DSTATE[0]), 0, 0, 56 },

  { (char_T *)(&Manual_Drive_DW.GameController_Controller), 14, 0, 1 },

  { (char_T *)(&Manual_Drive_DW.HILInitialize_Card), 16, 0, 1 },

  { (char_T *)(&Manual_Drive_DW.HILRead_PWORK), 11, 0, 4 },

  { (char_T *)(&Manual_Drive_DW.HILInitialize_DOStates), 6, 0, 37 },

  { (char_T *)(&Manual_Drive_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&Manual_Drive_DW.Integrator1_IWORK), 10, 0, 1 },

  { (char_T *)(&Manual_Drive_DW.TriggeredSubsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Manual_Drive_DW.Unwrap224_FirstSample), 8, 0, 1 },

  { (char_T *)(&Manual_Drive_DW.HILWrite_DigitalBuffer), 17, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Manual_Drive_P.LeftSteeringLimit_const), 0, 0, 5 },

  { (char_T *)(&Manual_Drive_P.HILRead_analog_channels[0]), 7, 0, 14 },

  { (char_T *)(&Manual_Drive_P.CompareToConstant2_const_a), 8, 0, 2 },

  { (char_T *)(&Manual_Drive_P.Gain1_Gain), 0, 0, 56 },

  { (char_T *)(&Manual_Drive_P.HILInitialize_EIInitial), 6, 0, 6 },

  { (char_T *)(&Manual_Drive_P.HILInitialize_AIChannels[0]), 7, 0, 56 },

  { (char_T *)(&Manual_Drive_P.GameController_BufferSize), 5, 0, 1 },

  { (char_T *)(&Manual_Drive_P.LightOff_Value), 8, 0, 41 },

  { (char_T *)(&Manual_Drive_P.GameController_ControllerNumber), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] Manual_Drive_dt.h */
