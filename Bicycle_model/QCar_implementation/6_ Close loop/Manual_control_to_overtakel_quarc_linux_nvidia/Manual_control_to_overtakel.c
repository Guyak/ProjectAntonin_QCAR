/*
 * Manual_control_to_overtakel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Manual_control_to_overtakel".
 *
 * Model version              : 5.40
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 15:29:04 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Manual_control_to_overtakel.h"
#include "Manual_control_to_overtakel_private.h"
#include "Manual_control_to_overtakel_dt.h"

/* Block signals (default storage) */
B_Manual_control_to_overtakel_T Manual_control_to_overtakel_B;

/* Continuous states */
X_Manual_control_to_overtakel_T Manual_control_to_overtakel_X;

/* Block states (default storage) */
DW_Manual_control_to_overtakel_T Manual_control_to_overtakel_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Manual_control_to_overtakel_T Manual_control_to_overtakel_PrevZCX;

/* Real-time model */
static RT_MODEL_Manual_control_to_overtakel_T Manual_control_to_overtakel_M_;
RT_MODEL_Manual_control_to_overtakel_T *const Manual_control_to_overtakel_M =
  &Manual_control_to_overtakel_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Manual_control_to_overtakel_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void Manual_control_to_overtakel_output(void)
{
  real_T rtb_Product;
  real_T rtb_Sum1_j_idx_0;
  real_T rtb_Sum1_j_idx_1;
  real_T rtb_d;
  real_T u0;
  boolean_T rEQ0;
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    /* set solver stop time */
    if (!(Manual_control_to_overtakel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Manual_control_to_overtakel_M->solverInfo,
                            ((Manual_control_to_overtakel_M->Timing.clockTickH0
        + 1) * Manual_control_to_overtakel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Manual_control_to_overtakel_M->solverInfo,
                            ((Manual_control_to_overtakel_M->Timing.clockTick0 +
        1) * Manual_control_to_overtakel_M->Timing.stepSize0 +
        Manual_control_to_overtakel_M->Timing.clockTickH0 *
        Manual_control_to_overtakel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Manual_control_to_overtakel_M)) {
    Manual_control_to_overtakel_M->Timing.t[0] = rtsiGetT
      (&Manual_control_to_overtakel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
  }

  /* Integrator: '<S1>/Integrator1' */
  Manual_control_to_overtakel_B.Integrator1[0] =
    Manual_control_to_overtakel_X.Integrator1_CSTATE[0];
  Manual_control_to_overtakel_B.Integrator1[1] =
    Manual_control_to_overtakel_X.Integrator1_CSTATE[1];
  Manual_control_to_overtakel_B.Integrator1[2] =
    Manual_control_to_overtakel_X.Integrator1_CSTATE[2];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Goal position'
   */
  rtb_Sum1_j_idx_0 = Manual_control_to_overtakel_P.xg[0] -
    Manual_control_to_overtakel_B.Integrator1[0];
  rtb_Sum1_j_idx_1 = Manual_control_to_overtakel_P.xg[1] -
    Manual_control_to_overtakel_B.Integrator1[1];

  /* Fcn: '<Root>/distance to goal' */
  rtb_d = rt_powd_snf(rtb_Sum1_j_idx_0, 2.0) + rt_powd_snf(rtb_Sum1_j_idx_1, 2.0);
  if (rtb_d < 0.0) {
    rtb_d = -sqrt(-rtb_d);
  } else {
    rtb_d = sqrt(rtb_d);
  }

  /* Gain: '<Root>/velocity gain Kv' incorporates:
   *  Fcn: '<Root>/distance to goal'
   */
  Manual_control_to_overtakel_B.speedcommand =
    Manual_control_to_overtakel_P.velocitygainKv_Gain * rtb_d;

  /* Saturate: '<S8>/command saturation' */
  if (Manual_control_to_overtakel_B.speedcommand >
      Manual_control_to_overtakel_P.commandsaturation_UpperSat) {
    rtb_Product = Manual_control_to_overtakel_P.commandsaturation_UpperSat;
  } else if (Manual_control_to_overtakel_B.speedcommand <
             Manual_control_to_overtakel_P.commandsaturation_LowerSat) {
    rtb_Product = Manual_control_to_overtakel_P.commandsaturation_LowerSat;
  } else {
    rtb_Product = Manual_control_to_overtakel_B.speedcommand;
  }

  /* End of Saturate: '<S8>/command saturation' */

  /* Product: '<S8>/Multiply1' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  Manual_control_to_overtakel_B.desired = rtb_Product *
    Manual_control_to_overtakel_P.Constant4_Value;

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Integrator: '<S2>/Integrator2'
   */
  Manual_control_to_overtakel_B.Product1 =
    Manual_control_to_overtakel_P.Constant2_Value *
    Manual_control_to_overtakel_X.Integrator2_CSTATE;

  /* Gain: '<S6>/Offset' incorporates:
   *  Gain: '<S6>/counts to rotations'
   *  Gain: '<S6>/gear ratios'
   *  Gain: '<S6>/rot//s to rad//s'
   *  Gain: '<S6>/wheel radius'
   */
  Manual_control_to_overtakel_B.Offset =
    Manual_control_to_overtakel_P.countstorotations_Gain *
    Manual_control_to_overtakel_B.Product1 *
    Manual_control_to_overtakel_P.gearratios_Gain *
    Manual_control_to_overtakel_P.rotstorads_Gain *
    Manual_control_to_overtakel_P.wheelradius_Gain *
    Manual_control_to_overtakel_P.Offset_Gain;

  /* Product: '<S8>/Multiply' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  Manual_control_to_overtakel_B.measured = Manual_control_to_overtakel_B.Offset *
    Manual_control_to_overtakel_P.Constant4_Value;

  /* Sum: '<S8>/Sum' */
  rtb_Product = Manual_control_to_overtakel_B.desired -
    Manual_control_to_overtakel_B.measured;

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  Manual_control_to_overtakel_B.Compare = (Manual_control_to_overtakel_B.desired
    == Manual_control_to_overtakel_P.Constant_Value);

  /* Integrator: '<S8>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    rEQ0 = (((Manual_control_to_overtakel_PrevZCX.Integrator1_Reset_ZCE == 1) !=
             (int32_T)Manual_control_to_overtakel_B.Compare) &&
            (Manual_control_to_overtakel_PrevZCX.Integrator1_Reset_ZCE != 3));
    Manual_control_to_overtakel_PrevZCX.Integrator1_Reset_ZCE =
      Manual_control_to_overtakel_B.Compare;

    /* evaluate zero-crossings */
    if (rEQ0) {
      Manual_control_to_overtakel_X.Integrator1_CSTATE_f =
        Manual_control_to_overtakel_P.Integrator1_IC;
    }
  }

  if (Manual_control_to_overtakel_X.Integrator1_CSTATE_f >=
      Manual_control_to_overtakel_P.Integrator1_UpperSat) {
    Manual_control_to_overtakel_X.Integrator1_CSTATE_f =
      Manual_control_to_overtakel_P.Integrator1_UpperSat;
  } else if (Manual_control_to_overtakel_X.Integrator1_CSTATE_f <=
             Manual_control_to_overtakel_P.Integrator1_LowerSat) {
    Manual_control_to_overtakel_X.Integrator1_CSTATE_f =
      Manual_control_to_overtakel_P.Integrator1_LowerSat;
  }

  /* Sum: '<S8>/Add1' incorporates:
   *  Gain: '<S8>/Kff  (% // m//s)'
   *  Gain: '<S8>/Kp (% // m//s)'
   *  Integrator: '<S8>/Integrator1'
   *  Sum: '<S8>/Add'
   */
  u0 = (Manual_control_to_overtakel_P.Kpms_Gain * rtb_Product +
        Manual_control_to_overtakel_X.Integrator1_CSTATE_f) +
    Manual_control_to_overtakel_P.Kffms_Gain *
    Manual_control_to_overtakel_B.desired;

  /* Saturate: '<S8>/Motor_command  sat' */
  if (u0 > Manual_control_to_overtakel_P.Motor_commandsat_UpperSat) {
    u0 = Manual_control_to_overtakel_P.Motor_commandsat_UpperSat;
  } else if (u0 < Manual_control_to_overtakel_P.Motor_commandsat_LowerSat) {
    u0 = Manual_control_to_overtakel_P.Motor_commandsat_LowerSat;
  }

  /* End of Saturate: '<S8>/Motor_command  sat' */

  /* Gain: '<Root>/direction convention' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Product: '<S8>/Multiply2'
   */
  u0 = u0 * Manual_control_to_overtakel_P.Constant4_Value *
    Manual_control_to_overtakel_P.directionconvention_Gain;

  /* Saturate: '<Root>/command saturation' */
  if (u0 > Manual_control_to_overtakel_P.commandsaturation_UpperSat_e) {
    /* Saturate: '<Root>/command saturation' */
    Manual_control_to_overtakel_B.commandsaturation =
      Manual_control_to_overtakel_P.commandsaturation_UpperSat_e;
  } else if (u0 < Manual_control_to_overtakel_P.commandsaturation_LowerSat_k) {
    /* Saturate: '<Root>/command saturation' */
    Manual_control_to_overtakel_B.commandsaturation =
      Manual_control_to_overtakel_P.commandsaturation_LowerSat_k;
  } else {
    /* Saturate: '<Root>/command saturation' */
    Manual_control_to_overtakel_B.commandsaturation = u0;
  }

  /* End of Saturate: '<Root>/command saturation' */
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    /* S-Function (hil_write_block): '<Root>/HIL Write1' */

    /* S-Function Block: Manual_control_to_overtakel/HIL Write1 (hil_write_block) */
    {
      t_error result;
      result = hil_write(Manual_control_to_overtakel_DW.HILInitialize1_Card,
                         NULL, 0U,
                         &Manual_control_to_overtakel_P.HILWrite1_pwm_channels,
                         1U,
                         NULL, 0U,
                         &Manual_control_to_overtakel_P.HILWrite1_other_channels,
                         1U,
                         NULL,
                         &Manual_control_to_overtakel_B.commandsaturation,
                         NULL,
                         &Manual_control_to_overtakel_B.Integrator1[2]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
      }
    }
  }

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Fcn: '<Root>/distance to goal'
   */
  Manual_control_to_overtakel_B.Compare_c = (rtb_d <
    Manual_control_to_overtakel_P.arewethereyet_const);
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    /* Stop: '<Root>/Stop Simulation' */
    if (Manual_control_to_overtakel_B.Compare_c) {
      rtmSetStopRequested(Manual_control_to_overtakel_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Fcn: '<Root>/heading angle to goal'
   */
  rtb_d = rt_atan2d_snf(rtb_Sum1_j_idx_1, rtb_Sum1_j_idx_0) -
    Manual_control_to_overtakel_B.Integrator1[2];
  if (rtIsNaN(rtb_d + 3.1415926535897931) || rtIsInf(rtb_d + 3.1415926535897931))
  {
    rtb_Sum1_j_idx_0 = (rtNaN);
  } else if (rtb_d + 3.1415926535897931 == 0.0) {
    rtb_Sum1_j_idx_0 = 0.0;
  } else {
    rtb_Sum1_j_idx_0 = fmod(rtb_d + 3.1415926535897931, 6.2831853071795862);
    rEQ0 = (rtb_Sum1_j_idx_0 == 0.0);
    if (!rEQ0) {
      rtb_Sum1_j_idx_1 = fabs((rtb_d + 3.1415926535897931) / 6.2831853071795862);
      rEQ0 = !(fabs(rtb_Sum1_j_idx_1 - floor(rtb_Sum1_j_idx_1 + 0.5)) >
               2.2204460492503131E-16 * rtb_Sum1_j_idx_1);
    }

    if (rEQ0) {
      rtb_Sum1_j_idx_0 = 0.0;
    } else if (rtb_d + 3.1415926535897931 < 0.0) {
      rtb_Sum1_j_idx_0 += 6.2831853071795862;
    }
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function'
   */
  rtb_Sum1_j_idx_0 = (rtb_Sum1_j_idx_0 - 3.1415926535897931) *
    Manual_control_to_overtakel_P.Gain_Gain;

  /* Saturate: '<S1>/steering angle limit' */
  if (rtb_Sum1_j_idx_0 > Manual_control_to_overtakel_P.Bicycle_alim) {
    /* Saturate: '<S1>/steering angle limit' */
    rtb_Sum1_j_idx_0 = Manual_control_to_overtakel_P.Bicycle_alim;
  } else if (rtb_Sum1_j_idx_0 < -Manual_control_to_overtakel_P.Bicycle_alim) {
    /* Saturate: '<S1>/steering angle limit' */
    rtb_Sum1_j_idx_0 = -Manual_control_to_overtakel_P.Bicycle_alim;
  }

  /* End of Saturate: '<S1>/steering angle limit' */

  /* RateLimiter: '<S1>/steering rate limit' */
  if (Manual_control_to_overtakel_DW.LastMajorTime == (rtInf)) {
    /* RateLimiter: '<S1>/steering rate limit' */
    Manual_control_to_overtakel_B.steeringratelimit = rtb_Sum1_j_idx_0;
  } else {
    rtb_Sum1_j_idx_1 = Manual_control_to_overtakel_M->Timing.t[0] -
      Manual_control_to_overtakel_DW.LastMajorTime;
    u0 = rtb_Sum1_j_idx_1 * Manual_control_to_overtakel_P.Bicycle_steer_rate;
    rtb_d = rtb_Sum1_j_idx_0 - Manual_control_to_overtakel_DW.PrevY;
    if (rtb_d > u0) {
      /* RateLimiter: '<S1>/steering rate limit' */
      Manual_control_to_overtakel_B.steeringratelimit =
        Manual_control_to_overtakel_DW.PrevY + u0;
    } else {
      rtb_Sum1_j_idx_1 *= -Manual_control_to_overtakel_P.Bicycle_steer_rate;
      if (rtb_d < rtb_Sum1_j_idx_1) {
        /* RateLimiter: '<S1>/steering rate limit' */
        Manual_control_to_overtakel_B.steeringratelimit =
          Manual_control_to_overtakel_DW.PrevY + rtb_Sum1_j_idx_1;
      } else {
        /* RateLimiter: '<S1>/steering rate limit' */
        Manual_control_to_overtakel_B.steeringratelimit = rtb_Sum1_j_idx_0;
      }
    }
  }

  /* End of RateLimiter: '<S1>/steering rate limit' */

  /* Saturate: '<S1>/vel limit' */
  if (Manual_control_to_overtakel_B.speedcommand >
      Manual_control_to_overtakel_P.Bicycle_vlim) {
    /* Saturate: '<S1>/vel limit' */
    rtb_Sum1_j_idx_0 = Manual_control_to_overtakel_P.Bicycle_vlim;
  } else if (Manual_control_to_overtakel_B.speedcommand <
             -Manual_control_to_overtakel_P.Bicycle_vlim) {
    /* Saturate: '<S1>/vel limit' */
    rtb_Sum1_j_idx_0 = -Manual_control_to_overtakel_P.Bicycle_vlim;
  } else {
    /* Saturate: '<S1>/vel limit' */
    rtb_Sum1_j_idx_0 = Manual_control_to_overtakel_B.speedcommand;
  }

  /* End of Saturate: '<S1>/vel limit' */

  /* RateLimiter: '<S1>/acceleration limit' */
  if (Manual_control_to_overtakel_DW.LastMajorTime_j == (rtInf)) {
    /* RateLimiter: '<S1>/acceleration limit' */
    Manual_control_to_overtakel_B.accelerationlimit = rtb_Sum1_j_idx_0;
  } else {
    rtb_Sum1_j_idx_1 = Manual_control_to_overtakel_M->Timing.t[0] -
      Manual_control_to_overtakel_DW.LastMajorTime_j;
    u0 = rtb_Sum1_j_idx_1 * Manual_control_to_overtakel_P.Bicycle_accel;
    rtb_d = rtb_Sum1_j_idx_0 - Manual_control_to_overtakel_DW.PrevY_l;
    if (rtb_d > u0) {
      /* RateLimiter: '<S1>/acceleration limit' */
      Manual_control_to_overtakel_B.accelerationlimit =
        Manual_control_to_overtakel_DW.PrevY_l + u0;
    } else {
      rtb_Sum1_j_idx_1 *= -Manual_control_to_overtakel_P.Bicycle_accel;
      if (rtb_d < rtb_Sum1_j_idx_1) {
        /* RateLimiter: '<S1>/acceleration limit' */
        Manual_control_to_overtakel_B.accelerationlimit =
          Manual_control_to_overtakel_DW.PrevY_l + rtb_Sum1_j_idx_1;
      } else {
        /* RateLimiter: '<S1>/acceleration limit' */
        Manual_control_to_overtakel_B.accelerationlimit = rtb_Sum1_j_idx_0;
      }
    }
  }

  /* End of RateLimiter: '<S1>/acceleration limit' */

  /* Product: '<S1>/Product' incorporates:
   *  Fcn: '<S1>/Fcn'
   *  Trigonometry: '<S1>/Trigonometric Function'
   *  Trigonometry: '<S1>/Trigonometric Function2'
   */
  Manual_control_to_overtakel_B.Product[0] = cos
    (Manual_control_to_overtakel_B.Integrator1[2]) *
    Manual_control_to_overtakel_B.accelerationlimit;
  Manual_control_to_overtakel_B.Product[1] = sin
    (Manual_control_to_overtakel_B.Integrator1[2]) *
    Manual_control_to_overtakel_B.accelerationlimit;
  Manual_control_to_overtakel_B.Product[2] = tan
    (Manual_control_to_overtakel_B.steeringratelimit) *
    Manual_control_to_overtakel_B.accelerationlimit;
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    /* S-Function (hil_read_block): '<Root>/HIL Read' */

    /* S-Function Block: Manual_control_to_overtakel/HIL Read (hil_read_block) */
    {
      t_error result = hil_read
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         NULL, 0U,
         &Manual_control_to_overtakel_P.HILRead_encoder_channels, 1U,
         NULL, 0U,
         NULL, 0U,
         NULL,
         &Manual_control_to_overtakel_DW.HILRead_EncoderBuffer,
         NULL,
         NULL
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
      } else {
        Manual_control_to_overtakel_B.motorcounts =
          Manual_control_to_overtakel_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<Root>/Unwrap 2^24' */
    /* S-Function Block: Manual_control_to_overtakel/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.033333333333333333;
      real_T half_range = Manual_control_to_overtakel_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Manual_control_to_overtakel_DW.Unwrap224_FirstSample) {
        Manual_control_to_overtakel_DW.Unwrap224_FirstSample = false;
        Manual_control_to_overtakel_DW.Unwrap224_PreviousInput =
          Manual_control_to_overtakel_B.motorcounts;
      }

      du = (real_T) Manual_control_to_overtakel_B.motorcounts -
        Manual_control_to_overtakel_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Manual_control_to_overtakel_DW.Unwrap224_Revolutions =
          Manual_control_to_overtakel_DW.Unwrap224_Revolutions - 1;
        dy = du - Manual_control_to_overtakel_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Manual_control_to_overtakel_DW.Unwrap224_Revolutions =
          Manual_control_to_overtakel_DW.Unwrap224_Revolutions + 1;
        dy = du + Manual_control_to_overtakel_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Manual_control_to_overtakel_B.Unwrap224 =
        Manual_control_to_overtakel_B.motorcounts +
        Manual_control_to_overtakel_DW.Unwrap224_Revolutions *
        Manual_control_to_overtakel_P.Unwrap224_Modulus;
      Manual_control_to_overtakel_DW.Unwrap224_PreviousInput =
        Manual_control_to_overtakel_B.motorcounts;
    }
  }

  /* Integrator: '<S2>/Integrator1' */
  if (Manual_control_to_overtakel_DW.Integrator1_IWORK != 0) {
    Manual_control_to_overtakel_X.Integrator1_CSTATE_d =
      Manual_control_to_overtakel_B.Unwrap224;
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S2>/Constant'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator2'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  Manual_control_to_overtakel_B.Product_e =
    ((Manual_control_to_overtakel_B.Unwrap224 -
      Manual_control_to_overtakel_X.Integrator1_CSTATE_d) -
     Manual_control_to_overtakel_X.Integrator2_CSTATE *
     Manual_control_to_overtakel_P.Constant_Value_n *
     Manual_control_to_overtakel_P.Constant3_Value) *
    Manual_control_to_overtakel_P.Constant2_Value;
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    /* Product: '<S7>/Product2' incorporates:
     *  Gain: '<S7>/1//L'
     */
    Manual_control_to_overtakel_B.psidotrads = 1.0 /
      Manual_control_to_overtakel_P.vehicle_length * 0.0 * 0.0;

    /* Gain: '<S7>/Gain' */
    Manual_control_to_overtakel_B.L2psidot =
      Manual_control_to_overtakel_P.vehicle_length / 2.0 *
      Manual_control_to_overtakel_B.psidotrads;
  }

  /* Gain: '<S8>/Ki (% // m)  ' */
  Manual_control_to_overtakel_B.Kim = Manual_control_to_overtakel_P.Kim_Gain *
    rtb_Product;

  /* Trigonometry: '<S7>/Trigonometric Function1' incorporates:
   *  Integrator: '<S7>/Integrator2'
   */
  rtb_Product = sin(Manual_control_to_overtakel_X.Integrator2_CSTATE_o);

  /* Trigonometry: '<S7>/Trigonometric Function' incorporates:
   *  Integrator: '<S7>/Integrator2'
   */
  rtb_d = cos(Manual_control_to_overtakel_X.Integrator2_CSTATE_o);

  /* Sum: '<S7>/Sum' incorporates:
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   */
  Manual_control_to_overtakel_B.v_Xms = 0.0 * rtb_d -
    Manual_control_to_overtakel_B.L2psidot * rtb_Product;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product4'
   */
  Manual_control_to_overtakel_B.v_Yms = 0.0 * rtb_Product +
    Manual_control_to_overtakel_B.L2psidot * rtb_d;
}

/* Model update function */
void Manual_control_to_overtakel_update(void)
{
  real_T LastMajorTime_tmp;

  /* Update for RateLimiter: '<S1>/steering rate limit' incorporates:
   *  RateLimiter: '<S1>/acceleration limit'
   */
  Manual_control_to_overtakel_DW.PrevY =
    Manual_control_to_overtakel_B.steeringratelimit;
  LastMajorTime_tmp = Manual_control_to_overtakel_M->Timing.t[0];
  Manual_control_to_overtakel_DW.LastMajorTime = LastMajorTime_tmp;

  /* Update for RateLimiter: '<S1>/acceleration limit' */
  Manual_control_to_overtakel_DW.PrevY_l =
    Manual_control_to_overtakel_B.accelerationlimit;
  Manual_control_to_overtakel_DW.LastMajorTime_j = LastMajorTime_tmp;

  /* Update for Integrator: '<S2>/Integrator1' */
  Manual_control_to_overtakel_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(Manual_control_to_overtakel_M)) {
    rt_ertODEUpdateContinuousStates(&Manual_control_to_overtakel_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Manual_control_to_overtakel_M->Timing.clockTick0)) {
    ++Manual_control_to_overtakel_M->Timing.clockTickH0;
  }

  Manual_control_to_overtakel_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Manual_control_to_overtakel_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.033333333333333333s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Manual_control_to_overtakel_M->Timing.clockTick1)) {
      ++Manual_control_to_overtakel_M->Timing.clockTickH1;
    }

    Manual_control_to_overtakel_M->Timing.t[1] =
      Manual_control_to_overtakel_M->Timing.clockTick1 *
      Manual_control_to_overtakel_M->Timing.stepSize1 +
      Manual_control_to_overtakel_M->Timing.clockTickH1 *
      Manual_control_to_overtakel_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Manual_control_to_overtakel_derivatives(void)
{
  XDot_Manual_control_to_overtakel_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Manual_control_to_overtakel_T *)
             Manual_control_to_overtakel_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = Manual_control_to_overtakel_B.Product[0];
  _rtXdot->Integrator1_CSTATE[1] = Manual_control_to_overtakel_B.Product[1];
  _rtXdot->Integrator1_CSTATE[2] = Manual_control_to_overtakel_B.Product[2];

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Manual_control_to_overtakel_B.Product_e;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  lsat = (Manual_control_to_overtakel_X.Integrator1_CSTATE_f <=
          Manual_control_to_overtakel_P.Integrator1_LowerSat);
  usat = (Manual_control_to_overtakel_X.Integrator1_CSTATE_f >=
          Manual_control_to_overtakel_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Manual_control_to_overtakel_B.Kim > 0.0))
      || (usat && (Manual_control_to_overtakel_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE_f = Manual_control_to_overtakel_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_f = 0.0;
  }

  /* End of Derivatives for Integrator: '<S8>/Integrator1' */

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_d = Manual_control_to_overtakel_B.Product1;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = Manual_control_to_overtakel_B.v_Xms;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_o = Manual_control_to_overtakel_B.v_Yms;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = Manual_control_to_overtakel_B.psidotrads;
}

/* Model initialize function */
void Manual_control_to_overtakel_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: Manual_control_to_overtakel/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0",
                      &Manual_control_to_overtakel_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Manual_control_to_overtakel_DW.HILInitialize1_Card,
       "gyro_fs=125;gyro_rate=47;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
       251);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (Manual_control_to_overtakel_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
      return;
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_AIPStart && !is_switching)
        || (Manual_control_to_overtakel_P.HILInitialize1_AIPEnter &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &Manual_control_to_overtakel_DW.HILInitialize1_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Manual_control_to_overtakel_P.HILInitialize1_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &Manual_control_to_overtakel_DW.HILInitialize1_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_AIChannels, 7U,
         &Manual_control_to_overtakel_DW.HILInitialize1_AIMinimums[0],
         &Manual_control_to_overtakel_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (Manual_control_to_overtakel_DW.HILInitialize1_Card,
       Manual_control_to_overtakel_P.HILInitialize1_DIChannels, 20U,
       &Manual_control_to_overtakel_P.HILInitialize1_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
      return;
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_DOStart && !is_switching) ||
        (Manual_control_to_overtakel_P.HILInitialize1_DOEnter && is_switching))
    {
      result = hil_write_digital
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         &Manual_control_to_overtakel_P.HILInitialize1_DOChannels, 1U,
         (t_boolean *) &Manual_control_to_overtakel_P.HILInitialize1_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_EIPStart && !is_switching)
        || (Manual_control_to_overtakel_P.HILInitialize1_EIPEnter &&
            is_switching)) {
      Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes[0] =
        (Manual_control_to_overtakel_P.HILInitialize1_EIQuadrature[0]);
      Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes[1] =
        (Manual_control_to_overtakel_P.HILInitialize1_EIQuadrature[1]);
      Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes[2] =
        (Manual_control_to_overtakel_P.HILInitialize1_EIQuadrature[1]);
      Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes[3] =
        (Manual_control_to_overtakel_P.HILInitialize1_EIQuadrature[1]);
      Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes[4] =
        (Manual_control_to_overtakel_P.HILInitialize1_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &Manual_control_to_overtakel_DW.HILInitialize1_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_EIChannels, 5U,
         &Manual_control_to_overtakel_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_EIStart && !is_switching) ||
        (Manual_control_to_overtakel_P.HILInitialize1_EIEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Manual_control_to_overtakel_DW.HILInitialize1_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_EIInitial;
        }
      }

      result = hil_set_encoder_counts
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_EIChannels, 5U,
         &Manual_control_to_overtakel_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_POPStart && !is_switching)
        || (Manual_control_to_overtakel_P.HILInitialize1_POPEnter &&
            is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      Manual_control_to_overtakel_DW.HILInitialize1_POModeValues[0] =
        (Manual_control_to_overtakel_P.HILInitialize1_POModes[0]);

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POModeValues[1];
        for (i1=0; i1 < 7; i1++) {
          dw_POModeValues[i1] =
            (Manual_control_to_overtakel_P.HILInitialize1_POModes[1]);
        }
      }

      result = hil_set_pwm_mode
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_POChannels, 8U,
         (t_pwm_mode *)
         &Manual_control_to_overtakel_DW.HILInitialize1_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize1_POChannels =
          Manual_control_to_overtakel_P.HILInitialize1_POChannels;
        int32_T *dw_POModeValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Manual_control_to_overtakel_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize1_POChannels[i1]);
            Manual_control_to_overtakel_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes]
              = Manual_control_to_overtakel_P.HILInitialize1_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Manual_control_to_overtakel_DW.HILInitialize1_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize1_POChannels[i1]);
            Manual_control_to_overtakel_DW.HILInitialize1_POSortedFreqs[7U -
              num_frequency_modes] =
              Manual_control_to_overtakel_P.HILInitialize1_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (Manual_control_to_overtakel_DW.HILInitialize1_Card,
           &Manual_control_to_overtakel_DW.HILInitialize1_POSortedChans[0],
           num_duty_cycle_modes,
           &Manual_control_to_overtakel_DW.HILInitialize1_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (Manual_control_to_overtakel_DW.HILInitialize1_Card,
           &Manual_control_to_overtakel_DW.HILInitialize1_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &Manual_control_to_overtakel_DW.HILInitialize1_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Manual_control_to_overtakel_DW.HILInitialize1_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_POChannels, 8U,
         (t_pwm_configuration *)
         &Manual_control_to_overtakel_DW.HILInitialize1_POModeValues[0],
         (t_pwm_alignment *)
         &Manual_control_to_overtakel_DW.HILInitialize1_POAlignValues[0],
         (t_pwm_polarity *)
         &Manual_control_to_overtakel_DW.HILInitialize1_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_POStart && !is_switching) ||
        (Manual_control_to_overtakel_P.HILInitialize1_POEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_POInitial;
        }
      }

      result = hil_write_pwm(Manual_control_to_overtakel_DW.HILInitialize1_Card,
        Manual_control_to_overtakel_P.HILInitialize1_POChannels, 8U,
        &Manual_control_to_overtakel_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    if (Manual_control_to_overtakel_P.HILInitialize1_POReset) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_POChannels, 8U,
         &Manual_control_to_overtakel_DW.HILInitialize1_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_OOStart && !is_switching) ||
        (Manual_control_to_overtakel_P.HILInitialize1_OOEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_OOValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] =
            Manual_control_to_overtakel_P.HILInitialize1_OOInitial;
        }
      }

      result = hil_write_other
        (Manual_control_to_overtakel_DW.HILInitialize1_Card,
         Manual_control_to_overtakel_P.HILInitialize1_OOChannels, 13U,
         &Manual_control_to_overtakel_DW.HILInitialize1_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Unwrap 2^24' */

  /* S-Function Block: Manual_control_to_overtakel/Unwrap 2^24 (inverse_modulus_block) */
  {
    Manual_control_to_overtakel_DW.Unwrap224_FirstSample = true;
    Manual_control_to_overtakel_DW.Unwrap224_Revolutions = 0;
  }

  Manual_control_to_overtakel_PrevZCX.Integrator1_Reset_ZCE =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Manual_control_to_overtakel_X.Integrator1_CSTATE[0] =
    Manual_control_to_overtakel_P.x0[0];
  Manual_control_to_overtakel_X.Integrator1_CSTATE[1] =
    Manual_control_to_overtakel_P.x0[1];
  Manual_control_to_overtakel_X.Integrator1_CSTATE[2] =
    Manual_control_to_overtakel_P.x0[2];

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  Manual_control_to_overtakel_X.Integrator2_CSTATE =
    Manual_control_to_overtakel_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  Manual_control_to_overtakel_X.Integrator1_CSTATE_f =
    Manual_control_to_overtakel_P.Integrator1_IC;

  /* InitializeConditions for RateLimiter: '<S1>/steering rate limit' */
  Manual_control_to_overtakel_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for RateLimiter: '<S1>/acceleration limit' */
  Manual_control_to_overtakel_DW.LastMajorTime_j = (rtInf);

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  if (rtmIsFirstInitCond(Manual_control_to_overtakel_M)) {
    Manual_control_to_overtakel_X.Integrator1_CSTATE_d = 0.0;
  }

  Manual_control_to_overtakel_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S2>/Integrator1' */

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  Manual_control_to_overtakel_X.Integrator_CSTATE =
    Manual_control_to_overtakel_P.X_ic;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  Manual_control_to_overtakel_X.Integrator1_CSTATE_o =
    Manual_control_to_overtakel_P.Y_ic;

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  Manual_control_to_overtakel_X.Integrator2_CSTATE_o =
    Manual_control_to_overtakel_P.yaw_ic;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Manual_control_to_overtakel_M)) {
    rtmSetFirstInitCond(Manual_control_to_overtakel_M, 0);
  }
}

/* Model terminate function */
void Manual_control_to_overtakel_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: Manual_control_to_overtakel/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Manual_control_to_overtakel_DW.HILInitialize1_Card);
    hil_monitor_stop_all(Manual_control_to_overtakel_DW.HILInitialize1_Card);
    is_switching = false;
    if ((Manual_control_to_overtakel_P.HILInitialize1_DOTerminate &&
         !is_switching) || (Manual_control_to_overtakel_P.HILInitialize1_DOExit &&
         is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_POTerminate &&
         !is_switching) || (Manual_control_to_overtakel_P.HILInitialize1_POExit &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Manual_control_to_overtakel_P.HILInitialize1_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Manual_control_to_overtakel_P.HILInitialize1_OOTerminate &&
         !is_switching) || (Manual_control_to_overtakel_P.HILInitialize1_OOExit &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues =
          &Manual_control_to_overtakel_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Manual_control_to_overtakel_P.HILInitialize1_OOFinal;
        }
      }

      num_final_other_outputs = 13U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Manual_control_to_overtakel_DW.HILInitialize1_Card
                         , NULL, 0
                         ,
                         Manual_control_to_overtakel_P.HILInitialize1_POChannels,
                         num_final_pwm_outputs
                         ,
                         &Manual_control_to_overtakel_P.HILInitialize1_DOChannels,
                         num_final_digital_outputs
                         ,
                         Manual_control_to_overtakel_P.HILInitialize1_OOChannels,
                         num_final_other_outputs
                         , NULL
                         ,
                         &Manual_control_to_overtakel_DW.HILInitialize1_POValues[
                         0]
                         , (t_boolean *)
                         &Manual_control_to_overtakel_P.HILInitialize1_DOFinal
                         ,
                         &Manual_control_to_overtakel_DW.HILInitialize1_OOValues[
                         0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (Manual_control_to_overtakel_DW.HILInitialize1_Card,
             Manual_control_to_overtakel_P.HILInitialize1_POChannels,
             num_final_pwm_outputs,
             &Manual_control_to_overtakel_DW.HILInitialize1_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Manual_control_to_overtakel_DW.HILInitialize1_Card,
             &Manual_control_to_overtakel_P.HILInitialize1_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &Manual_control_to_overtakel_P.HILInitialize1_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (Manual_control_to_overtakel_DW.HILInitialize1_Card,
             Manual_control_to_overtakel_P.HILInitialize1_OOChannels,
             num_final_other_outputs,
             &Manual_control_to_overtakel_DW.HILInitialize1_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Manual_control_to_overtakel_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Manual_control_to_overtakel_DW.HILInitialize1_Card);
    hil_monitor_delete_all(Manual_control_to_overtakel_DW.HILInitialize1_Card);
    hil_close(Manual_control_to_overtakel_DW.HILInitialize1_Card);
    Manual_control_to_overtakel_DW.HILInitialize1_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Manual_control_to_overtakel_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Manual_control_to_overtakel_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Manual_control_to_overtakel_initialize();
}

void MdlTerminate(void)
{
  Manual_control_to_overtakel_terminate();
}

/* Registration function */
RT_MODEL_Manual_control_to_overtakel_T *Manual_control_to_overtakel(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Manual_control_to_overtakel_P.Bicycle_steer_rate = rtInf;

  /* initialize real-time model */
  (void) memset((void *)Manual_control_to_overtakel_M, 0,
                sizeof(RT_MODEL_Manual_control_to_overtakel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Manual_control_to_overtakel_M->solverInfo,
                          &Manual_control_to_overtakel_M->Timing.simTimeStep);
    rtsiSetTPtr(&Manual_control_to_overtakel_M->solverInfo, &rtmGetTPtr
                (Manual_control_to_overtakel_M));
    rtsiSetStepSizePtr(&Manual_control_to_overtakel_M->solverInfo,
                       &Manual_control_to_overtakel_M->Timing.stepSize0);
    rtsiSetdXPtr(&Manual_control_to_overtakel_M->solverInfo,
                 &Manual_control_to_overtakel_M->derivs);
    rtsiSetContStatesPtr(&Manual_control_to_overtakel_M->solverInfo, (real_T **)
                         &Manual_control_to_overtakel_M->contStates);
    rtsiSetNumContStatesPtr(&Manual_control_to_overtakel_M->solverInfo,
      &Manual_control_to_overtakel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Manual_control_to_overtakel_M->solverInfo,
      &Manual_control_to_overtakel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Manual_control_to_overtakel_M->solverInfo,
       &Manual_control_to_overtakel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Manual_control_to_overtakel_M->solverInfo,
      &Manual_control_to_overtakel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Manual_control_to_overtakel_M->solverInfo,
                          (&rtmGetErrorStatus(Manual_control_to_overtakel_M)));
    rtsiSetRTModelPtr(&Manual_control_to_overtakel_M->solverInfo,
                      Manual_control_to_overtakel_M);
  }

  rtsiSetSimTimeStep(&Manual_control_to_overtakel_M->solverInfo, MAJOR_TIME_STEP);
  Manual_control_to_overtakel_M->intgData.f[0] =
    Manual_control_to_overtakel_M->odeF[0];
  Manual_control_to_overtakel_M->contStates = ((real_T *)
    &Manual_control_to_overtakel_X);
  rtsiSetSolverData(&Manual_control_to_overtakel_M->solverInfo, (void *)
                    &Manual_control_to_overtakel_M->intgData);
  rtsiSetSolverName(&Manual_control_to_overtakel_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Manual_control_to_overtakel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Manual_control_to_overtakel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Manual_control_to_overtakel_M->Timing.sampleTimes =
      (&Manual_control_to_overtakel_M->Timing.sampleTimesArray[0]);
    Manual_control_to_overtakel_M->Timing.offsetTimes =
      (&Manual_control_to_overtakel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Manual_control_to_overtakel_M->Timing.sampleTimes[0] = (0.0);
    Manual_control_to_overtakel_M->Timing.sampleTimes[1] = (0.033333333333333333);

    /* task offsets */
    Manual_control_to_overtakel_M->Timing.offsetTimes[0] = (0.0);
    Manual_control_to_overtakel_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Manual_control_to_overtakel_M,
             &Manual_control_to_overtakel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Manual_control_to_overtakel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Manual_control_to_overtakel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Manual_control_to_overtakel_M, 11.0);
  Manual_control_to_overtakel_M->Timing.stepSize0 = 0.033333333333333333;
  Manual_control_to_overtakel_M->Timing.stepSize1 = 0.033333333333333333;
  rtmSetFirstInitCond(Manual_control_to_overtakel_M, 1);

  /* External mode info */
  Manual_control_to_overtakel_M->Sizes.checksums[0] = (2623534310U);
  Manual_control_to_overtakel_M->Sizes.checksums[1] = (3944745123U);
  Manual_control_to_overtakel_M->Sizes.checksums[2] = (2538963905U);
  Manual_control_to_overtakel_M->Sizes.checksums[3] = (3241768099U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Manual_control_to_overtakel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Manual_control_to_overtakel_M->extModeInfo,
      &Manual_control_to_overtakel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Manual_control_to_overtakel_M->extModeInfo,
                        Manual_control_to_overtakel_M->Sizes.checksums);
    rteiSetTPtr(Manual_control_to_overtakel_M->extModeInfo, rtmGetTPtr
                (Manual_control_to_overtakel_M));
  }

  Manual_control_to_overtakel_M->solverInfoPtr =
    (&Manual_control_to_overtakel_M->solverInfo);
  Manual_control_to_overtakel_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Manual_control_to_overtakel_M->solverInfo,
                       0.033333333333333333);
  rtsiSetSolverMode(&Manual_control_to_overtakel_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Manual_control_to_overtakel_M->blockIO = ((void *)
    &Manual_control_to_overtakel_B);
  (void) memset(((void *) &Manual_control_to_overtakel_B), 0,
                sizeof(B_Manual_control_to_overtakel_T));

  /* parameters */
  Manual_control_to_overtakel_M->defaultParam = ((real_T *)
    &Manual_control_to_overtakel_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Manual_control_to_overtakel_X;
    Manual_control_to_overtakel_M->contStates = (x);
    (void) memset((void *)&Manual_control_to_overtakel_X, 0,
                  sizeof(X_Manual_control_to_overtakel_T));
  }

  /* states (dwork) */
  Manual_control_to_overtakel_M->dwork = ((void *)
    &Manual_control_to_overtakel_DW);
  (void) memset((void *)&Manual_control_to_overtakel_DW, 0,
                sizeof(DW_Manual_control_to_overtakel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Manual_control_to_overtakel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Manual_control_to_overtakel_M->Sizes.numContStates = (9);/* Number of continuous states */
  Manual_control_to_overtakel_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Manual_control_to_overtakel_M->Sizes.numY = (0);/* Number of model outputs */
  Manual_control_to_overtakel_M->Sizes.numU = (0);/* Number of model inputs */
  Manual_control_to_overtakel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Manual_control_to_overtakel_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Manual_control_to_overtakel_M->Sizes.numBlocks = (78);/* Number of blocks */
  Manual_control_to_overtakel_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  Manual_control_to_overtakel_M->Sizes.numBlockPrms = (156);/* Sum of parameter "widths" */
  return Manual_control_to_overtakel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
