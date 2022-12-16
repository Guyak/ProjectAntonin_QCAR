/*
 * Path_following_TP_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP".
 *
 * Model version              : 5.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 15:34:41 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Path_following_TP_types_h_
#define RTW_HEADER_Path_following_TP_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Path_following_TP_T
#define typedef_cell_wrap_Path_following_TP_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Path_following_TP_T;

#endif                               /* typedef_cell_wrap_Path_following_TP_T */

#ifndef struct_tag_Y63vLFkQX5kZWBH5MzBSDF
#define struct_tag_Y63vLFkQX5kZWBH5MzBSDF

struct tag_Y63vLFkQX5kZWBH5MzBSDF
{
  int32_T isInitialized;
  cell_wrap_Path_following_TP_T inputVarSize[2];
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[560];
};

#endif                                 /* struct_tag_Y63vLFkQX5kZWBH5MzBSDF */

#ifndef typedef_nav_slalgs_internal_PurePursu_T
#define typedef_nav_slalgs_internal_PurePursu_T

typedef struct tag_Y63vLFkQX5kZWBH5MzBSDF nav_slalgs_internal_PurePursu_T;

#endif                             /* typedef_nav_slalgs_internal_PurePursu_T */

/* Parameters (default storage) */
typedef struct P_Path_following_TP_T_ P_Path_following_TP_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Path_following_TP_T RT_MODEL_Path_following_TP_T;

#endif                               /* RTW_HEADER_Path_following_TP_types_h_ */
