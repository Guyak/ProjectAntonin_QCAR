/*
 * drivepoint_QCar_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "drivepoint_QCar".
 *
 * Model version              : 4.14
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 23 17:44:10 2023
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_drivepoint_QCar_types_h_
#define RTW_HEADER_drivepoint_QCar_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef struct_tag_p3Sml37nZ8W6ZoAywbOWsF
#define struct_tag_p3Sml37nZ8W6ZoAywbOWsF

struct tag_p3Sml37nZ8W6ZoAywbOWsF
{
  int32_T S0_isInitialized;
  real_T W0_states[457];
  real_T P0_InitialStates;
  real_T P1_Coefficients[458];
};

#endif                                 /* struct_tag_p3Sml37nZ8W6ZoAywbOWsF */

#ifndef typedef_b_dsp_FIRFilter_0_drivepoint__T
#define typedef_b_dsp_FIRFilter_0_drivepoint__T

typedef struct tag_p3Sml37nZ8W6ZoAywbOWsF b_dsp_FIRFilter_0_drivepoint__T;

#endif                             /* typedef_b_dsp_FIRFilter_0_drivepoint__T */

#ifndef struct_tag_AT4hEU7rn0P31kSdlDAZ4D
#define struct_tag_AT4hEU7rn0P31kSdlDAZ4D

struct tag_AT4hEU7rn0P31kSdlDAZ4D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_drivepoint__T cSFunObject;
};

#endif                                 /* struct_tag_AT4hEU7rn0P31kSdlDAZ4D */

#ifndef typedef_b_dspcodegen_FIRFilter_drivep_T
#define typedef_b_dspcodegen_FIRFilter_drivep_T

typedef struct tag_AT4hEU7rn0P31kSdlDAZ4D b_dspcodegen_FIRFilter_drivep_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_drivep_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_drivepoint_QCar_T
#define typedef_cell_wrap_drivepoint_QCar_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_drivepoint_QCar_T;

#endif                                 /* typedef_cell_wrap_drivepoint_QCar_T */

#ifndef struct_tag_e5LiOJGwAL1nfpMJSwFzgE
#define struct_tag_e5LiOJGwAL1nfpMJSwFzgE

struct tag_e5LiOJGwAL1nfpMJSwFzgE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_drivepoint_QCar_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_drivep_T *FilterObj;
  b_dspcodegen_FIRFilter_drivep_T _pobj0;
};

#endif                                 /* struct_tag_e5LiOJGwAL1nfpMJSwFzgE */

#ifndef typedef_dsp_LowpassFilter_drivepoint__T
#define typedef_dsp_LowpassFilter_drivepoint__T

typedef struct tag_e5LiOJGwAL1nfpMJSwFzgE dsp_LowpassFilter_drivepoint__T;

#endif                             /* typedef_dsp_LowpassFilter_drivepoint__T */

/* Parameters (default storage) */
typedef struct P_drivepoint_QCar_T_ P_drivepoint_QCar_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_drivepoint_QCar_T RT_MODEL_drivepoint_QCar_T;

#endif                                 /* RTW_HEADER_drivepoint_QCar_types_h_ */
