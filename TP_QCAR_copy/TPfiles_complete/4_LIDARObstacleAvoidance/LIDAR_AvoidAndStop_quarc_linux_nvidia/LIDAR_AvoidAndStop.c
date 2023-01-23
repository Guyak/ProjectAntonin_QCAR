/*
 * LIDAR_AvoidAndStop.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LIDAR_AvoidAndStop".
 *
 * Model version              : 5.7
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Oct 19 08:27:58 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LIDAR_AvoidAndStop.h"
#include "LIDAR_AvoidAndStop_private.h"
#include "LIDAR_AvoidAndStop_dt.h"

/* Block signals (default storage) */
B_LIDAR_AvoidAndStop_T LIDAR_AvoidAndStop_B;

/* Continuous states */
X_LIDAR_AvoidAndStop_T LIDAR_AvoidAndStop_X;

/* Block states (default storage) */
DW_LIDAR_AvoidAndStop_T LIDAR_AvoidAndStop_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_LIDAR_AvoidAndStop_T LIDAR_AvoidAndStop_PrevZCX;

/* Real-time model */
static RT_MODEL_LIDAR_AvoidAndStop_T LIDAR_AvoidAndStop_M_;
RT_MODEL_LIDAR_AvoidAndStop_T *const LIDAR_AvoidAndStop_M =
  &LIDAR_AvoidAndStop_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(LIDAR_AvoidAndStop_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(LIDAR_AvoidAndStop_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (LIDAR_AvoidAndStop_M->Timing.TaskCounters.TID[2])++;
  if ((LIDAR_AvoidAndStop_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.1s, 0.0s] */
    LIDAR_AvoidAndStop_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  LIDAR_AvoidAndStop_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void LIDAR_AvoidAndStop_output0(void)  /* Sample time: [0.0s, 0.0s] */
{
  real_T rtb_SteeringBias;
  real_T rtb_Sum_a;
  real_T rtb_cospsi;
  real_T rtb_sinpsi;
  real_T rtb_speed;
  int32_T ex;
  int32_T i;
  int32_T k;
  int8_T calc1[720];
  int8_T calc2[720];
  int8_T calc3[720];
  int8_T calc4[720];
  int8_T calc2_tmp;
  int8_T calc3_0;
  int8_T calc4_0;
  boolean_T X1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    /* set solver stop time */
    if (!(LIDAR_AvoidAndStop_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LIDAR_AvoidAndStop_M->solverInfo,
                            ((LIDAR_AvoidAndStop_M->Timing.clockTickH0 + 1) *
        LIDAR_AvoidAndStop_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LIDAR_AvoidAndStop_M->solverInfo,
                            ((LIDAR_AvoidAndStop_M->Timing.clockTick0 + 1) *
        LIDAR_AvoidAndStop_M->Timing.stepSize0 +
        LIDAR_AvoidAndStop_M->Timing.clockTickH0 *
        LIDAR_AvoidAndStop_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LIDAR_AvoidAndStop_M)) {
    LIDAR_AvoidAndStop_M->Timing.t[0] = rtsiGetT
      (&LIDAR_AvoidAndStop_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    /* S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

    /* S-Function Block: LIDAR_AvoidAndStop/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
    {
      t_error result;
      result = rplidar_read(LIDAR_AvoidAndStop_DW.RangingSensor_Sensor,
                            RANGING_MEASUREMENT_MODE_INTERPOLATED,
                            LIDAR_AvoidAndStop_P.RangingSensor_MaxInterpolationD,
                            LIDAR_AvoidAndStop_P.RangingSensor_MaxInterpolationA,
                            &LIDAR_AvoidAndStop_DW.RangingSensor_Measurements[0],
                            720);
      if (result >= 0) {
        {
          int_T i1;
          real_T *y0 = &LIDAR_AvoidAndStop_B.RangingSensor_o1[0];
          real_T *y1 = &LIDAR_AvoidAndStop_B.RangingSensor_o2[0];
          real_T *y2 = &LIDAR_AvoidAndStop_B.RangingSensor_o3[0];
          real_T *y3 = &LIDAR_AvoidAndStop_B.RangingSensor_o4[0];
          t_ranging_measurement *dw_Measurements =
            &LIDAR_AvoidAndStop_DW.RangingSensor_Measurements[0];
          for (i1=0; i1 < 720; i1++) {
            y0[i1] = dw_Measurements[i1].distance;
          }
        }
      } else if (result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      }
    }

    /* MATLAB Function: '<S4>/MATLAB Function' */
    for (i = 0; i < 180; i++) {
      LIDAR_AvoidAndStop_B.correctedDistances[i] =
        LIDAR_AvoidAndStop_B.RangingSensor_o1[179 - i];
    }

    for (i = 0; i < 540; i++) {
      LIDAR_AvoidAndStop_B.correctedDistances[i + 180] =
        LIDAR_AvoidAndStop_B.RangingSensor_o1[719 - i];
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function' */

    /* Constant: '<S4>/Constant1' */
    memcpy(&LIDAR_AvoidAndStop_B.Constant1[0],
           &LIDAR_AvoidAndStop_P.Constant1_Value[0], 720U * sizeof(real_T));

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    for (i = 0; i < 720; i++) {
      X1 = (LIDAR_AvoidAndStop_B.Constant1[i] <= 0.52359877559829882);
      calc4_0 = (int8_T)((LIDAR_AvoidAndStop_B.correctedDistances[i] <= 1.0) &&
                         (LIDAR_AvoidAndStop_B.correctedDistances[i] >= 0.2));
      calc1[i] = (int8_T)(X1 * calc4_0);
      calc3_0 = (int8_T)(LIDAR_AvoidAndStop_B.Constant1[i] >= 5.7595865315812871);
      calc2_tmp = (int8_T)((LIDAR_AvoidAndStop_B.correctedDistances[i] <= 0.2) &&
                           (LIDAR_AvoidAndStop_B.correctedDistances[i] >= 0.05));
      calc2[i] = (int8_T)(X1 * calc2_tmp);
      calc4[i] = (int8_T)(calc3_0 * calc4_0);
      calc3[i] = (int8_T)(calc3_0 * calc2_tmp);
    }

    ex = calc2[0];
    for (k = 0; k < 719; k++) {
      i = calc2[k + 1];
      if (ex < i) {
        ex = i;
      }
    }

    guard1 = false;
    guard2 = false;
    if (ex == 1) {
      ex = calc3[0];
      for (k = 0; k < 719; k++) {
        i = calc3[k + 1];
        if (ex < i) {
          ex = i;
        }
      }

      if (ex == 1) {
        rtb_speed = 0.0;
        LIDAR_AvoidAndStop_B.steering = 0.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      ex = calc1[0];
      for (k = 0; k < 719; k++) {
        i = calc1[k + 1];
        if (ex < i) {
          ex = i;
        }
      }

      if (ex == 1) {
        ex = calc4[0];
        for (k = 0; k < 719; k++) {
          i = calc4[k + 1];
          if (ex < i) {
            ex = i;
          }
        }

        if (ex == 1) {
          rtb_speed = calc1[0];
          rtb_Sum_a = calc4[0];
          for (ex = 0; ex < 719; ex++) {
            rtb_speed += (real_T)calc1[ex + 1];
            rtb_Sum_a += (real_T)calc4[ex + 1];
          }

          if (rtb_speed > rtb_Sum_a) {
            rtb_speed = LIDAR_AvoidAndStop_P.Constant4_Value;
            LIDAR_AvoidAndStop_B.steering = 0.5;
          } else {
            rtb_speed = LIDAR_AvoidAndStop_P.Constant4_Value;
            LIDAR_AvoidAndStop_B.steering = -0.5;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      rtb_speed = LIDAR_AvoidAndStop_P.Constant4_Value;
      LIDAR_AvoidAndStop_B.steering = 0.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Saturate: '<S8>/command saturation' */
    if (rtb_speed > LIDAR_AvoidAndStop_P.commandsaturation_UpperSat) {
      rtb_SteeringBias = LIDAR_AvoidAndStop_P.commandsaturation_UpperSat;
    } else if (rtb_speed < LIDAR_AvoidAndStop_P.commandsaturation_LowerSat) {
      rtb_SteeringBias = LIDAR_AvoidAndStop_P.commandsaturation_LowerSat;
    } else {
      rtb_SteeringBias = rtb_speed;
    }

    /* End of Saturate: '<S8>/command saturation' */

    /* Product: '<S8>/Multiply1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    LIDAR_AvoidAndStop_B.desired = rtb_SteeringBias *
      LIDAR_AvoidAndStop_P.Constant_Value_i;

    /* Gain: '<S8>/Kff  (% // m//s)' */
    LIDAR_AvoidAndStop_B.Kffms = LIDAR_AvoidAndStop_P.Kffms_Gain *
      LIDAR_AvoidAndStop_B.desired;
  }

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Integrator: '<S10>/Integrator2'
   */
  LIDAR_AvoidAndStop_B.Product1 = LIDAR_AvoidAndStop_P.Constant2_Value *
    LIDAR_AvoidAndStop_X.Integrator2_CSTATE;

  /* Gain: '<S3>/wheel radius' incorporates:
   *  Gain: '<S3>/counts to rotations'
   *  Gain: '<S3>/gear ratios'
   *  Gain: '<S3>/rot//s to rad//s'
   */
  rtb_speed = LIDAR_AvoidAndStop_P.countstorotations_Gain *
    LIDAR_AvoidAndStop_B.Product1 * LIDAR_AvoidAndStop_P.gearratios_Gain *
    LIDAR_AvoidAndStop_P.rotstorads_Gain * LIDAR_AvoidAndStop_P.wheelradius_Gain;

  /* Product: '<S8>/Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   */
  LIDAR_AvoidAndStop_B.measured = rtb_speed *
    LIDAR_AvoidAndStop_P.Constant_Value_i;

  /* Sum: '<S8>/Sum' */
  rtb_Sum_a = LIDAR_AvoidAndStop_B.desired - LIDAR_AvoidAndStop_B.measured;
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    /* RelationalOperator: '<S11>/Compare' incorporates:
     *  Constant: '<S11>/Constant'
     */
    LIDAR_AvoidAndStop_B.Compare = (LIDAR_AvoidAndStop_B.desired ==
      LIDAR_AvoidAndStop_P.Constant_Value);
  }

  /* Integrator: '<S8>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    X1 = (((LIDAR_AvoidAndStop_PrevZCX.Integrator1_Reset_ZCE == 1) != (int32_T)
           LIDAR_AvoidAndStop_B.Compare) &&
          (LIDAR_AvoidAndStop_PrevZCX.Integrator1_Reset_ZCE != 3));
    LIDAR_AvoidAndStop_PrevZCX.Integrator1_Reset_ZCE =
      LIDAR_AvoidAndStop_B.Compare;

    /* evaluate zero-crossings */
    if (X1) {
      LIDAR_AvoidAndStop_X.Integrator1_CSTATE =
        LIDAR_AvoidAndStop_P.Integrator1_IC;
    }
  }

  if (LIDAR_AvoidAndStop_X.Integrator1_CSTATE >=
      LIDAR_AvoidAndStop_P.Integrator1_UpperSat) {
    LIDAR_AvoidAndStop_X.Integrator1_CSTATE =
      LIDAR_AvoidAndStop_P.Integrator1_UpperSat;
  } else if (LIDAR_AvoidAndStop_X.Integrator1_CSTATE <=
             LIDAR_AvoidAndStop_P.Integrator1_LowerSat) {
    LIDAR_AvoidAndStop_X.Integrator1_CSTATE =
      LIDAR_AvoidAndStop_P.Integrator1_LowerSat;
  }

  /* Sum: '<S8>/Add1' incorporates:
   *  Gain: '<S8>/Kp (% // m//s)'
   *  Integrator: '<S8>/Integrator1'
   *  Sum: '<S8>/Add'
   */
  rtb_SteeringBias = (LIDAR_AvoidAndStop_P.Kpms_Gain * rtb_Sum_a +
                      LIDAR_AvoidAndStop_X.Integrator1_CSTATE) +
    LIDAR_AvoidAndStop_B.Kffms;

  /* Saturate: '<S8>/Motor_command  sat' */
  if (rtb_SteeringBias > LIDAR_AvoidAndStop_P.Motor_commandsat_UpperSat) {
    rtb_SteeringBias = LIDAR_AvoidAndStop_P.Motor_commandsat_UpperSat;
  } else if (rtb_SteeringBias < LIDAR_AvoidAndStop_P.Motor_commandsat_LowerSat)
  {
    rtb_SteeringBias = LIDAR_AvoidAndStop_P.Motor_commandsat_LowerSat;
  }

  /* End of Saturate: '<S8>/Motor_command  sat' */

  /* Gain: '<Root>/direction convention' incorporates:
   *  Constant: '<Root>/Constant'
   *  Product: '<S8>/Multiply2'
   */
  rtb_SteeringBias = rtb_SteeringBias * LIDAR_AvoidAndStop_P.Constant_Value_i *
    LIDAR_AvoidAndStop_P.directionconvention_Gain;

  /* Saturate: '<Root>/command saturation' */
  if (rtb_SteeringBias > LIDAR_AvoidAndStop_P.commandsaturation_UpperSat_l) {
    /* Saturate: '<Root>/command saturation' */
    LIDAR_AvoidAndStop_B.commandsaturation =
      LIDAR_AvoidAndStop_P.commandsaturation_UpperSat_l;
  } else if (rtb_SteeringBias <
             LIDAR_AvoidAndStop_P.commandsaturation_LowerSat_l) {
    /* Saturate: '<Root>/command saturation' */
    LIDAR_AvoidAndStop_B.commandsaturation =
      LIDAR_AvoidAndStop_P.commandsaturation_LowerSat_l;
  } else {
    /* Saturate: '<Root>/command saturation' */
    LIDAR_AvoidAndStop_B.commandsaturation = rtb_SteeringBias;
  }

  /* End of Saturate: '<Root>/command saturation' */
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    /* Bias: '<Root>/Steering Bias' */
    rtb_SteeringBias = LIDAR_AvoidAndStop_B.steering +
      LIDAR_AvoidAndStop_P.SteeringBias_Bias;

    /* S-Function (hil_write_block): '<Root>/HIL Write1' */

    /* S-Function Block: LIDAR_AvoidAndStop/HIL Write1 (hil_write_block) */
    {
      t_error result;
      result = hil_write(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
                         NULL, 0U,
                         &LIDAR_AvoidAndStop_P.HILWrite1_pwm_channels, 1U,
                         NULL, 0U,
                         &LIDAR_AvoidAndStop_P.HILWrite1_other_channels, 1U,
                         NULL,
                         &LIDAR_AvoidAndStop_B.commandsaturation,
                         NULL,
                         &rtb_SteeringBias
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      }
    }
  }

  /* Integrator: '<S7>/Integrator' */
  LIDAR_AvoidAndStop_B.Integrator = LIDAR_AvoidAndStop_X.Integrator_CSTATE;

  /* Integrator: '<S7>/Integrator1' */
  LIDAR_AvoidAndStop_B.Integrator1 = LIDAR_AvoidAndStop_X.Integrator1_CSTATE_i;

  /* Integrator: '<S7>/Integrator2' */
  LIDAR_AvoidAndStop_B.psi_headingrad =
    LIDAR_AvoidAndStop_X.Integrator2_CSTATE_k;

  /* RateTransition: '<S6>/Rate Transition' */
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    /* RateTransition: '<S6>/Rate Transition' */
    LIDAR_AvoidAndStop_B.RateTransition[0] = LIDAR_AvoidAndStop_B.Integrator;
    LIDAR_AvoidAndStop_B.RateTransition[1] = LIDAR_AvoidAndStop_B.Integrator1;
    LIDAR_AvoidAndStop_B.RateTransition[2] = LIDAR_AvoidAndStop_B.psi_headingrad;
    LIDAR_AvoidAndStop_B.RateTransition[3] = LIDAR_AvoidAndStop_B.steering;

    /* S-Function (hil_read_block): '<Root>/HIL Read' */

    /* S-Function Block: LIDAR_AvoidAndStop/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
        NULL, 0U,
        &LIDAR_AvoidAndStop_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        NULL,
        &LIDAR_AvoidAndStop_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      } else {
        LIDAR_AvoidAndStop_B.motorcounts =
          LIDAR_AvoidAndStop_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S5>/Unwrap 2^24' */
    /* S-Function Block: LIDAR_AvoidAndStop/filtering/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.033333333333333333;
      real_T half_range = LIDAR_AvoidAndStop_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (LIDAR_AvoidAndStop_DW.Unwrap224_FirstSample) {
        LIDAR_AvoidAndStop_DW.Unwrap224_FirstSample = false;
        LIDAR_AvoidAndStop_DW.Unwrap224_PreviousInput =
          LIDAR_AvoidAndStop_B.motorcounts;
      }

      du = (real_T) LIDAR_AvoidAndStop_B.motorcounts -
        LIDAR_AvoidAndStop_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        LIDAR_AvoidAndStop_DW.Unwrap224_Revolutions =
          LIDAR_AvoidAndStop_DW.Unwrap224_Revolutions - 1;
        dy = du - LIDAR_AvoidAndStop_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        LIDAR_AvoidAndStop_DW.Unwrap224_Revolutions =
          LIDAR_AvoidAndStop_DW.Unwrap224_Revolutions + 1;
        dy = du + LIDAR_AvoidAndStop_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      LIDAR_AvoidAndStop_B.Unwrap224 = LIDAR_AvoidAndStop_B.motorcounts +
        LIDAR_AvoidAndStop_DW.Unwrap224_Revolutions *
        LIDAR_AvoidAndStop_P.Unwrap224_Modulus;
      LIDAR_AvoidAndStop_DW.Unwrap224_PreviousInput =
        LIDAR_AvoidAndStop_B.motorcounts;
    }
  }

  /* End of RateTransition: '<S6>/Rate Transition' */

  /* Integrator: '<S10>/Integrator1' */
  if (LIDAR_AvoidAndStop_DW.Integrator1_IWORK != 0) {
    LIDAR_AvoidAndStop_X.Integrator1_CSTATE_h = LIDAR_AvoidAndStop_B.Unwrap224;
  }

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant3'
   *  Integrator: '<S10>/Integrator1'
   *  Integrator: '<S10>/Integrator2'
   *  Product: '<S10>/Product2'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   */
  LIDAR_AvoidAndStop_B.Product = ((LIDAR_AvoidAndStop_B.Unwrap224 -
    LIDAR_AvoidAndStop_X.Integrator1_CSTATE_h) -
    LIDAR_AvoidAndStop_X.Integrator2_CSTATE *
    LIDAR_AvoidAndStop_P.Constant_Value_j * LIDAR_AvoidAndStop_P.Constant3_Value)
    * LIDAR_AvoidAndStop_P.Constant2_Value;

  /* Product: '<S7>/Product2' incorporates:
   *  Gain: '<S7>/1//L'
   */
  LIDAR_AvoidAndStop_B.psidotrads = 1.0 / LIDAR_AvoidAndStop_P.vehicle_length *
    rtb_speed * LIDAR_AvoidAndStop_B.steering;

  /* Gain: '<S7>/Gain' */
  rtb_SteeringBias = LIDAR_AvoidAndStop_P.vehicle_length / 2.0 *
    LIDAR_AvoidAndStop_B.psidotrads;

  /* Trigonometry: '<S7>/Trigonometric Function1' */
  rtb_sinpsi = sin(LIDAR_AvoidAndStop_B.psi_headingrad);

  /* Trigonometry: '<S7>/Trigonometric Function' */
  rtb_cospsi = cos(LIDAR_AvoidAndStop_B.psi_headingrad);

  /* Sum: '<S7>/Sum' incorporates:
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   */
  LIDAR_AvoidAndStop_B.v_Xms = rtb_speed * rtb_cospsi - rtb_SteeringBias *
    rtb_sinpsi;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product4'
   */
  LIDAR_AvoidAndStop_B.v_Yms = rtb_speed * rtb_sinpsi + rtb_SteeringBias *
    rtb_cospsi;
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
  }

  /* Gain: '<S8>/Ki (% // m)  ' */
  LIDAR_AvoidAndStop_B.Kim = LIDAR_AvoidAndStop_P.Kim_Gain * rtb_Sum_a;
}

/* Model update function for TID0 */
void LIDAR_AvoidAndStop_update0(void)  /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S10>/Integrator1' */
  LIDAR_AvoidAndStop_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(LIDAR_AvoidAndStop_M)) {
    rt_ertODEUpdateContinuousStates(&LIDAR_AvoidAndStop_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LIDAR_AvoidAndStop_M->Timing.clockTick0)) {
    ++LIDAR_AvoidAndStop_M->Timing.clockTickH0;
  }

  LIDAR_AvoidAndStop_M->Timing.t[0] = rtsiGetSolverStopTime
    (&LIDAR_AvoidAndStop_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LIDAR_AvoidAndStop_M->Timing.clockTick1)) {
    ++LIDAR_AvoidAndStop_M->Timing.clockTickH1;
  }

  LIDAR_AvoidAndStop_M->Timing.t[1] = LIDAR_AvoidAndStop_M->Timing.clockTick1 *
    LIDAR_AvoidAndStop_M->Timing.stepSize1 +
    LIDAR_AvoidAndStop_M->Timing.clockTickH1 *
    LIDAR_AvoidAndStop_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void LIDAR_AvoidAndStop_derivatives(void)
{
  XDot_LIDAR_AvoidAndStop_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_LIDAR_AvoidAndStop_T *) LIDAR_AvoidAndStop_M->derivs);

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = LIDAR_AvoidAndStop_B.Product;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  lsat = (LIDAR_AvoidAndStop_X.Integrator1_CSTATE <=
          LIDAR_AvoidAndStop_P.Integrator1_LowerSat);
  usat = (LIDAR_AvoidAndStop_X.Integrator1_CSTATE >=
          LIDAR_AvoidAndStop_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (LIDAR_AvoidAndStop_B.Kim > 0.0)) ||
      (usat && (LIDAR_AvoidAndStop_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE = LIDAR_AvoidAndStop_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S8>/Integrator1' */

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = LIDAR_AvoidAndStop_B.v_Xms;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_i = LIDAR_AvoidAndStop_B.v_Yms;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_k = LIDAR_AvoidAndStop_B.psidotrads;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h = LIDAR_AvoidAndStop_B.Product1;
}

/* Model output function for TID2 */
void LIDAR_AvoidAndStop_output2(void)  /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void LIDAR_AvoidAndStop_update2(void)  /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LIDAR_AvoidAndStop_M->Timing.clockTick2)) {
    ++LIDAR_AvoidAndStop_M->Timing.clockTickH2;
  }

  LIDAR_AvoidAndStop_M->Timing.t[2] = LIDAR_AvoidAndStop_M->Timing.clockTick2 *
    LIDAR_AvoidAndStop_M->Timing.stepSize2 +
    LIDAR_AvoidAndStop_M->Timing.clockTickH2 *
    LIDAR_AvoidAndStop_M->Timing.stepSize2 * 4294967296.0;
}

/* Model wrapper function for compatibility with a static main program */
void LIDAR_AvoidAndStop_output(int_T tid)
{
  switch (tid) {
   case 0 :
    LIDAR_AvoidAndStop_output0();
    break;

   case 2 :
    LIDAR_AvoidAndStop_output2();
    break;

   default :
    break;
  }
}

/* Model wrapper function for compatibility with a static main program */
void LIDAR_AvoidAndStop_update(int_T tid)
{
  switch (tid) {
   case 0 :
    LIDAR_AvoidAndStop_update0();
    break;

   case 2 :
    LIDAR_AvoidAndStop_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void LIDAR_AvoidAndStop_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: LIDAR_AvoidAndStop/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      return;
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_AIPStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &LIDAR_AvoidAndStop_DW.HILInitialize1_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = LIDAR_AvoidAndStop_P.HILInitialize1_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &LIDAR_AvoidAndStop_DW.HILInitialize1_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = LIDAR_AvoidAndStop_P.HILInitialize1_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
         LIDAR_AvoidAndStop_P.HILInitialize1_AIChannels, 7U,
         &LIDAR_AvoidAndStop_DW.HILInitialize1_AIMinimums[0],
         &LIDAR_AvoidAndStop_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
       LIDAR_AvoidAndStop_P.HILInitialize1_DIChannels, 19U,
       &LIDAR_AvoidAndStop_P.HILInitialize1_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
      return;
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_DOStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_DOEnter && is_switching)) {
      result = hil_write_digital(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
        &LIDAR_AvoidAndStop_P.HILInitialize1_DOChannels, 1U, (t_boolean *)
        &LIDAR_AvoidAndStop_P.HILInitialize1_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_EIPStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIPEnter && is_switching)) {
      LIDAR_AvoidAndStop_DW.HILInitialize1_QuadratureModes[0] =
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIQuadrature[0]);
      LIDAR_AvoidAndStop_DW.HILInitialize1_QuadratureModes[1] =
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIQuadrature[1]);
      LIDAR_AvoidAndStop_DW.HILInitialize1_QuadratureModes[2] =
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIQuadrature[1]);
      LIDAR_AvoidAndStop_DW.HILInitialize1_QuadratureModes[3] =
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIQuadrature[1]);
      LIDAR_AvoidAndStop_DW.HILInitialize1_QuadratureModes[4] =
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
         LIDAR_AvoidAndStop_P.HILInitialize1_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &LIDAR_AvoidAndStop_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &LIDAR_AvoidAndStop_DW.HILInitialize1_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] =
            LIDAR_AvoidAndStop_P.HILInitialize1_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
         LIDAR_AvoidAndStop_P.HILInitialize1_EIChannels, 5U,
         &LIDAR_AvoidAndStop_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_EIStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &LIDAR_AvoidAndStop_DW.HILInitialize1_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = LIDAR_AvoidAndStop_P.HILInitialize1_EIInitial;
        }
      }

      result = hil_set_encoder_counts(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
        LIDAR_AvoidAndStop_P.HILInitialize1_EIChannels, 5U,
        &LIDAR_AvoidAndStop_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_POPStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
        &LIDAR_AvoidAndStop_P.HILInitialize1_POChannels, 1U, (t_pwm_mode *)
        LIDAR_AvoidAndStop_P.HILInitialize1_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }

      if ((LIDAR_AvoidAndStop_P.HILInitialize1_POModes[0]) ==
          PWM_DUTY_CYCLE_MODE || (LIDAR_AvoidAndStop_P.HILInitialize1_POModes[0])
          == PWM_ONE_SHOT_MODE || (LIDAR_AvoidAndStop_P.HILInitialize1_POModes[0])
          == PWM_TIME_MODE || (LIDAR_AvoidAndStop_P.HILInitialize1_POModes[0]) ==
          PWM_RAW_MODE) {
        LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedChans =
          LIDAR_AvoidAndStop_P.HILInitialize1_POChannels;
        LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedFreqs =
          LIDAR_AvoidAndStop_P.HILInitialize1_POFrequency;
        num_duty_cycle_modes++;
      } else {
        LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedChans =
          LIDAR_AvoidAndStop_P.HILInitialize1_POChannels;
        LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedFreqs =
          LIDAR_AvoidAndStop_P.HILInitialize1_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
          &LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedChans,
          num_duty_cycle_modes,
          &LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
           &LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedChans,
           num_frequency_modes,
           &LIDAR_AvoidAndStop_DW.HILInitialize1_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration
        (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
         &LIDAR_AvoidAndStop_P.HILInitialize1_POChannels, 1U,
         (t_pwm_configuration *)
         &LIDAR_AvoidAndStop_P.HILInitialize1_POConfiguration,
         (t_pwm_alignment *) &LIDAR_AvoidAndStop_P.HILInitialize1_POAlignment,
         (t_pwm_polarity *) &LIDAR_AvoidAndStop_P.HILInitialize1_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_POStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_POEnter && is_switching)) {
      result = hil_write_pwm(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
        &LIDAR_AvoidAndStop_P.HILInitialize1_POChannels, 1U,
        &LIDAR_AvoidAndStop_P.HILInitialize1_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    if (LIDAR_AvoidAndStop_P.HILInitialize1_POReset) {
      result = hil_watchdog_set_pwm_expiration_state
        (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
         &LIDAR_AvoidAndStop_P.HILInitialize1_POChannels, 1U,
         &LIDAR_AvoidAndStop_P.HILInitialize1_POWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_OOStart && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &LIDAR_AvoidAndStop_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = LIDAR_AvoidAndStop_P.HILInitialize1_OOInitial;
        }
      }

      result = hil_write_other(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
        LIDAR_AvoidAndStop_P.HILInitialize1_OOChannels, 13U,
        &LIDAR_AvoidAndStop_DW.HILInitialize1_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: LIDAR_AvoidAndStop/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    t_error result;
    result = rplidar_open("serial-cpu://localhost:2?baud='115200',word='8',parity='none',stop='1',flow='none',dsr='on'",
                          (t_ranging_distance)
                          (LIDAR_AvoidAndStop_P.RangingSensor_Range - 1),
                          &LIDAR_AvoidAndStop_DW.RangingSensor_Sensor);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
    }
  }

  /* Start for Constant: '<S4>/Constant1' */
  memcpy(&LIDAR_AvoidAndStop_B.Constant1[0],
         &LIDAR_AvoidAndStop_P.Constant1_Value[0], 720U * sizeof(real_T));

  /* Start for S-Function (inverse_modulus_block): '<S5>/Unwrap 2^24' */

  /* S-Function Block: LIDAR_AvoidAndStop/filtering/Unwrap 2^24 (inverse_modulus_block) */
  {
    LIDAR_AvoidAndStop_DW.Unwrap224_FirstSample = true;
    LIDAR_AvoidAndStop_DW.Unwrap224_Revolutions = 0;
  }

  LIDAR_AvoidAndStop_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S10>/Integrator2' */
  LIDAR_AvoidAndStop_X.Integrator2_CSTATE = LIDAR_AvoidAndStop_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  LIDAR_AvoidAndStop_X.Integrator1_CSTATE = LIDAR_AvoidAndStop_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  LIDAR_AvoidAndStop_X.Integrator_CSTATE = LIDAR_AvoidAndStop_P.X_ic;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  LIDAR_AvoidAndStop_X.Integrator1_CSTATE_i = LIDAR_AvoidAndStop_P.Y_ic;

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  LIDAR_AvoidAndStop_X.Integrator2_CSTATE_k = LIDAR_AvoidAndStop_P.yaw_ic;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  if (rtmIsFirstInitCond(LIDAR_AvoidAndStop_M)) {
    LIDAR_AvoidAndStop_X.Integrator1_CSTATE_h = 0.0;
  }

  LIDAR_AvoidAndStop_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S10>/Integrator1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(LIDAR_AvoidAndStop_M)) {
    rtmSetFirstInitCond(LIDAR_AvoidAndStop_M, 0);
  }
}

/* Model terminate function */
void LIDAR_AvoidAndStop_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: LIDAR_AvoidAndStop/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    hil_monitor_stop_all(LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    is_switching = false;
    if ((LIDAR_AvoidAndStop_P.HILInitialize1_DOTerminate && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_POTerminate && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_POExit && is_switching)) {
      num_final_pwm_outputs = 1U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((LIDAR_AvoidAndStop_P.HILInitialize1_OOTerminate && !is_switching) ||
        (LIDAR_AvoidAndStop_P.HILInitialize1_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &LIDAR_AvoidAndStop_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = LIDAR_AvoidAndStop_P.HILInitialize1_OOFinal;
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
      result = hil_write(LIDAR_AvoidAndStop_DW.HILInitialize1_Card
                         , NULL, 0
                         , &LIDAR_AvoidAndStop_P.HILInitialize1_POChannels,
                         num_final_pwm_outputs
                         , &LIDAR_AvoidAndStop_P.HILInitialize1_DOChannels,
                         num_final_digital_outputs
                         , LIDAR_AvoidAndStop_P.HILInitialize1_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &LIDAR_AvoidAndStop_P.HILInitialize1_POFinal
                         , (t_boolean *)
                         &LIDAR_AvoidAndStop_P.HILInitialize1_DOFinal
                         , &LIDAR_AvoidAndStop_DW.HILInitialize1_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
            &LIDAR_AvoidAndStop_P.HILInitialize1_POChannels,
            num_final_pwm_outputs, &LIDAR_AvoidAndStop_P.HILInitialize1_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
             &LIDAR_AvoidAndStop_P.HILInitialize1_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &LIDAR_AvoidAndStop_P.HILInitialize1_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (LIDAR_AvoidAndStop_DW.HILInitialize1_Card,
             LIDAR_AvoidAndStop_P.HILInitialize1_OOChannels,
             num_final_other_outputs,
             &LIDAR_AvoidAndStop_DW.HILInitialize1_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(LIDAR_AvoidAndStop_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    hil_monitor_delete_all(LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    hil_close(LIDAR_AvoidAndStop_DW.HILInitialize1_Card);
    LIDAR_AvoidAndStop_DW.HILInitialize1_Card = NULL;
  }

  /* Terminate for S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: LIDAR_AvoidAndStop/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    rplidar_close(LIDAR_AvoidAndStop_DW.RangingSensor_Sensor);
    LIDAR_AvoidAndStop_DW.RangingSensor_Sensor = NULL;
    LIDAR_AvoidAndStop_DW.RangingSensor_Sensor = NULL;
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
  if (tid == 1)
    tid = 0;
  LIDAR_AvoidAndStop_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  LIDAR_AvoidAndStop_update(tid);
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
  LIDAR_AvoidAndStop_initialize();
}

void MdlTerminate(void)
{
  LIDAR_AvoidAndStop_terminate();
}

/* Registration function */
RT_MODEL_LIDAR_AvoidAndStop_T *LIDAR_AvoidAndStop(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  LIDAR_AvoidAndStop_P.RangingSensor_MaxInterpolationD = rtInf;

  /* initialize real-time model */
  (void) memset((void *)LIDAR_AvoidAndStop_M, 0,
                sizeof(RT_MODEL_LIDAR_AvoidAndStop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LIDAR_AvoidAndStop_M->solverInfo,
                          &LIDAR_AvoidAndStop_M->Timing.simTimeStep);
    rtsiSetTPtr(&LIDAR_AvoidAndStop_M->solverInfo, &rtmGetTPtr
                (LIDAR_AvoidAndStop_M));
    rtsiSetStepSizePtr(&LIDAR_AvoidAndStop_M->solverInfo,
                       &LIDAR_AvoidAndStop_M->Timing.stepSize0);
    rtsiSetdXPtr(&LIDAR_AvoidAndStop_M->solverInfo,
                 &LIDAR_AvoidAndStop_M->derivs);
    rtsiSetContStatesPtr(&LIDAR_AvoidAndStop_M->solverInfo, (real_T **)
                         &LIDAR_AvoidAndStop_M->contStates);
    rtsiSetNumContStatesPtr(&LIDAR_AvoidAndStop_M->solverInfo,
      &LIDAR_AvoidAndStop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&LIDAR_AvoidAndStop_M->solverInfo,
      &LIDAR_AvoidAndStop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&LIDAR_AvoidAndStop_M->solverInfo,
      &LIDAR_AvoidAndStop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&LIDAR_AvoidAndStop_M->solverInfo,
      &LIDAR_AvoidAndStop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&LIDAR_AvoidAndStop_M->solverInfo, (&rtmGetErrorStatus
      (LIDAR_AvoidAndStop_M)));
    rtsiSetRTModelPtr(&LIDAR_AvoidAndStop_M->solverInfo, LIDAR_AvoidAndStop_M);
  }

  rtsiSetSimTimeStep(&LIDAR_AvoidAndStop_M->solverInfo, MAJOR_TIME_STEP);
  LIDAR_AvoidAndStop_M->intgData.f[0] = LIDAR_AvoidAndStop_M->odeF[0];
  LIDAR_AvoidAndStop_M->contStates = ((real_T *) &LIDAR_AvoidAndStop_X);
  rtsiSetSolverData(&LIDAR_AvoidAndStop_M->solverInfo, (void *)
                    &LIDAR_AvoidAndStop_M->intgData);
  rtsiSetSolverName(&LIDAR_AvoidAndStop_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = LIDAR_AvoidAndStop_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    LIDAR_AvoidAndStop_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    LIDAR_AvoidAndStop_M->Timing.sampleTimes =
      (&LIDAR_AvoidAndStop_M->Timing.sampleTimesArray[0]);
    LIDAR_AvoidAndStop_M->Timing.offsetTimes =
      (&LIDAR_AvoidAndStop_M->Timing.offsetTimesArray[0]);

    /* task periods */
    LIDAR_AvoidAndStop_M->Timing.sampleTimes[0] = (0.0);
    LIDAR_AvoidAndStop_M->Timing.sampleTimes[1] = (0.033333333333333333);
    LIDAR_AvoidAndStop_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    LIDAR_AvoidAndStop_M->Timing.offsetTimes[0] = (0.0);
    LIDAR_AvoidAndStop_M->Timing.offsetTimes[1] = (0.0);
    LIDAR_AvoidAndStop_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(LIDAR_AvoidAndStop_M, &LIDAR_AvoidAndStop_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = LIDAR_AvoidAndStop_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      LIDAR_AvoidAndStop_M->Timing.perTaskSampleHitsArray;
    LIDAR_AvoidAndStop_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    LIDAR_AvoidAndStop_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(LIDAR_AvoidAndStop_M, -1);
  LIDAR_AvoidAndStop_M->Timing.stepSize0 = 0.033333333333333333;
  LIDAR_AvoidAndStop_M->Timing.stepSize1 = 0.033333333333333333;
  LIDAR_AvoidAndStop_M->Timing.stepSize2 = 0.1;
  rtmSetFirstInitCond(LIDAR_AvoidAndStop_M, 1);

  /* External mode info */
  LIDAR_AvoidAndStop_M->Sizes.checksums[0] = (3954270668U);
  LIDAR_AvoidAndStop_M->Sizes.checksums[1] = (764802388U);
  LIDAR_AvoidAndStop_M->Sizes.checksums[2] = (2860914891U);
  LIDAR_AvoidAndStop_M->Sizes.checksums[3] = (3456049891U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    LIDAR_AvoidAndStop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LIDAR_AvoidAndStop_M->extModeInfo,
      &LIDAR_AvoidAndStop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LIDAR_AvoidAndStop_M->extModeInfo,
                        LIDAR_AvoidAndStop_M->Sizes.checksums);
    rteiSetTPtr(LIDAR_AvoidAndStop_M->extModeInfo, rtmGetTPtr
                (LIDAR_AvoidAndStop_M));
  }

  LIDAR_AvoidAndStop_M->solverInfoPtr = (&LIDAR_AvoidAndStop_M->solverInfo);
  LIDAR_AvoidAndStop_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&LIDAR_AvoidAndStop_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&LIDAR_AvoidAndStop_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  LIDAR_AvoidAndStop_M->blockIO = ((void *) &LIDAR_AvoidAndStop_B);
  (void) memset(((void *) &LIDAR_AvoidAndStop_B), 0,
                sizeof(B_LIDAR_AvoidAndStop_T));

  /* parameters */
  LIDAR_AvoidAndStop_M->defaultParam = ((real_T *)&LIDAR_AvoidAndStop_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &LIDAR_AvoidAndStop_X;
    LIDAR_AvoidAndStop_M->contStates = (x);
    (void) memset((void *)&LIDAR_AvoidAndStop_X, 0,
                  sizeof(X_LIDAR_AvoidAndStop_T));
  }

  /* states (dwork) */
  LIDAR_AvoidAndStop_M->dwork = ((void *) &LIDAR_AvoidAndStop_DW);
  (void) memset((void *)&LIDAR_AvoidAndStop_DW, 0,
                sizeof(DW_LIDAR_AvoidAndStop_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LIDAR_AvoidAndStop_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  LIDAR_AvoidAndStop_M->Sizes.numContStates = (6);/* Number of continuous states */
  LIDAR_AvoidAndStop_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  LIDAR_AvoidAndStop_M->Sizes.numY = (0);/* Number of model outputs */
  LIDAR_AvoidAndStop_M->Sizes.numU = (0);/* Number of model inputs */
  LIDAR_AvoidAndStop_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  LIDAR_AvoidAndStop_M->Sizes.numSampTimes = (3);/* Number of sample times */
  LIDAR_AvoidAndStop_M->Sizes.numBlocks = (63);/* Number of blocks */
  LIDAR_AvoidAndStop_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  LIDAR_AvoidAndStop_M->Sizes.numBlockPrms = (936);/* Sum of parameter "widths" */
  return LIDAR_AvoidAndStop_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
