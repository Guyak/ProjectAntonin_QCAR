/*
 * OG_LIDAR_Base.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OG_LIDAR_Base".
 *
 * Model version              : 5.8
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Oct 19 08:33:26 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OG_LIDAR_Base.h"
#include "OG_LIDAR_Base_private.h"
#include "OG_LIDAR_Base_dt.h"

/* Block signals (default storage) */
B_OG_LIDAR_Base_T OG_LIDAR_Base_B;

/* Continuous states */
X_OG_LIDAR_Base_T OG_LIDAR_Base_X;

/* Block states (default storage) */
DW_OG_LIDAR_Base_T OG_LIDAR_Base_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_OG_LIDAR_Base_T OG_LIDAR_Base_PrevZCX;

/* Real-time model */
static RT_MODEL_OG_LIDAR_Base_T OG_LIDAR_Base_M_;
RT_MODEL_OG_LIDAR_Base_T *const OG_LIDAR_Base_M = &OG_LIDAR_Base_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(OG_LIDAR_Base_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(OG_LIDAR_Base_M, 2);
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
  (OG_LIDAR_Base_M->Timing.TaskCounters.TID[2])++;
  if ((OG_LIDAR_Base_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.1s, 0.0s] */
    OG_LIDAR_Base_M->Timing.TaskCounters.TID[2] = 0;
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
  OG_LIDAR_Base_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void OG_LIDAR_Base_output0(void)       /* Sample time: [0.0s, 0.0s] */
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
  int8_T calc4[720];
  boolean_T Y1;
  boolean_T guard1 = false;
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    /* set solver stop time */
    if (!(OG_LIDAR_Base_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&OG_LIDAR_Base_M->solverInfo,
                            ((OG_LIDAR_Base_M->Timing.clockTickH0 + 1) *
        OG_LIDAR_Base_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&OG_LIDAR_Base_M->solverInfo,
                            ((OG_LIDAR_Base_M->Timing.clockTick0 + 1) *
        OG_LIDAR_Base_M->Timing.stepSize0 + OG_LIDAR_Base_M->Timing.clockTickH0 *
        OG_LIDAR_Base_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(OG_LIDAR_Base_M)) {
    OG_LIDAR_Base_M->Timing.t[0] = rtsiGetT(&OG_LIDAR_Base_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    /* S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

    /* S-Function Block: OG_LIDAR_Base/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
    {
      t_error result;
      result = rplidar_read(OG_LIDAR_Base_DW.RangingSensor_Sensor,
                            RANGING_MEASUREMENT_MODE_INTERPOLATED,
                            OG_LIDAR_Base_P.RangingSensor_MaxInterpolationD,
                            OG_LIDAR_Base_P.RangingSensor_MaxInterpolationA,
                            &OG_LIDAR_Base_DW.RangingSensor_Measurements[0], 720);
      if (result >= 0) {
        {
          int_T i1;
          real_T *y0 = &OG_LIDAR_Base_B.RangingSensor_o1[0];
          real_T *y1 = &OG_LIDAR_Base_B.RangingSensor_o2[0];
          real_T *y2 = &OG_LIDAR_Base_B.RangingSensor_o3[0];
          real_T *y3 = &OG_LIDAR_Base_B.RangingSensor_o4[0];
          t_ranging_measurement *dw_Measurements =
            &OG_LIDAR_Base_DW.RangingSensor_Measurements[0];
          for (i1=0; i1 < 720; i1++) {
            y0[i1] = dw_Measurements[i1].distance;
          }
        }
      } else if (result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      }
    }

    /* MATLAB Function: '<S4>/MATLAB Function' */
    for (i = 0; i < 180; i++) {
      OG_LIDAR_Base_B.correctedDistances[i] = OG_LIDAR_Base_B.RangingSensor_o1
        [179 - i];
    }

    for (i = 0; i < 540; i++) {
      OG_LIDAR_Base_B.correctedDistances[i + 180] =
        OG_LIDAR_Base_B.RangingSensor_o1[719 - i];
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function' */

    /* Constant: '<S4>/Constant1' */
    memcpy(&OG_LIDAR_Base_B.Constant1[0], &OG_LIDAR_Base_P.Constant1_Value[0],
           720U * sizeof(real_T));

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    for (i = 0; i < 720; i++) {
      Y1 = ((OG_LIDAR_Base_B.correctedDistances[i] <= 1.0) &&
            (OG_LIDAR_Base_B.correctedDistances[i] >= 0.1));
      calc1[i] = (int8_T)((OG_LIDAR_Base_B.Constant1[i] <= 0.52359877559829882) *
                          Y1);
      calc4[i] = (int8_T)((OG_LIDAR_Base_B.Constant1[i] >= 5.7595865315812871) *
                          Y1);
    }

    ex = calc1[0];
    for (k = 0; k < 719; k++) {
      i = calc1[k + 1];
      if (ex < i) {
        ex = i;
      }
    }

    guard1 = false;
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
          rtb_speed = OG_LIDAR_Base_P.Constant4_Value;
          OG_LIDAR_Base_B.steering = 0.5;
        } else {
          rtb_speed = OG_LIDAR_Base_P.Constant4_Value;
          OG_LIDAR_Base_B.steering = -0.5;
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      rtb_speed = OG_LIDAR_Base_P.Constant4_Value;
      OG_LIDAR_Base_B.steering = 0.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Saturate: '<S8>/command saturation' */
    if (rtb_speed > OG_LIDAR_Base_P.commandsaturation_UpperSat) {
      rtb_SteeringBias = OG_LIDAR_Base_P.commandsaturation_UpperSat;
    } else if (rtb_speed < OG_LIDAR_Base_P.commandsaturation_LowerSat) {
      rtb_SteeringBias = OG_LIDAR_Base_P.commandsaturation_LowerSat;
    } else {
      rtb_SteeringBias = rtb_speed;
    }

    /* End of Saturate: '<S8>/command saturation' */

    /* Product: '<S8>/Multiply1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    OG_LIDAR_Base_B.desired = rtb_SteeringBias *
      OG_LIDAR_Base_P.Constant_Value_i;

    /* Gain: '<S8>/Kff  (% // m//s)' */
    OG_LIDAR_Base_B.Kffms = OG_LIDAR_Base_P.Kffms_Gain * OG_LIDAR_Base_B.desired;
  }

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Integrator: '<S10>/Integrator2'
   */
  OG_LIDAR_Base_B.Product1 = OG_LIDAR_Base_P.Constant2_Value *
    OG_LIDAR_Base_X.Integrator2_CSTATE;

  /* Gain: '<S3>/wheel radius' incorporates:
   *  Gain: '<S3>/counts to rotations'
   *  Gain: '<S3>/gear ratios'
   *  Gain: '<S3>/rot//s to rad//s'
   */
  rtb_speed = OG_LIDAR_Base_P.countstorotations_Gain * OG_LIDAR_Base_B.Product1 *
    OG_LIDAR_Base_P.gearratios_Gain * OG_LIDAR_Base_P.rotstorads_Gain *
    OG_LIDAR_Base_P.wheelradius_Gain;

  /* Product: '<S8>/Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   */
  OG_LIDAR_Base_B.measured = rtb_speed * OG_LIDAR_Base_P.Constant_Value_i;

  /* Sum: '<S8>/Sum' */
  rtb_Sum_a = OG_LIDAR_Base_B.desired - OG_LIDAR_Base_B.measured;
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    /* RelationalOperator: '<S11>/Compare' incorporates:
     *  Constant: '<S11>/Constant'
     */
    OG_LIDAR_Base_B.Compare = (OG_LIDAR_Base_B.desired ==
      OG_LIDAR_Base_P.Constant_Value);
  }

  /* Integrator: '<S8>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    Y1 = (((OG_LIDAR_Base_PrevZCX.Integrator1_Reset_ZCE == 1) != (int32_T)
           OG_LIDAR_Base_B.Compare) &&
          (OG_LIDAR_Base_PrevZCX.Integrator1_Reset_ZCE != 3));
    OG_LIDAR_Base_PrevZCX.Integrator1_Reset_ZCE = OG_LIDAR_Base_B.Compare;

    /* evaluate zero-crossings */
    if (Y1) {
      OG_LIDAR_Base_X.Integrator1_CSTATE = OG_LIDAR_Base_P.Integrator1_IC;
    }
  }

  if (OG_LIDAR_Base_X.Integrator1_CSTATE >= OG_LIDAR_Base_P.Integrator1_UpperSat)
  {
    OG_LIDAR_Base_X.Integrator1_CSTATE = OG_LIDAR_Base_P.Integrator1_UpperSat;
  } else if (OG_LIDAR_Base_X.Integrator1_CSTATE <=
             OG_LIDAR_Base_P.Integrator1_LowerSat) {
    OG_LIDAR_Base_X.Integrator1_CSTATE = OG_LIDAR_Base_P.Integrator1_LowerSat;
  }

  /* Sum: '<S8>/Add1' incorporates:
   *  Gain: '<S8>/Kp (% // m//s)'
   *  Integrator: '<S8>/Integrator1'
   *  Sum: '<S8>/Add'
   */
  rtb_SteeringBias = (OG_LIDAR_Base_P.Kpms_Gain * rtb_Sum_a +
                      OG_LIDAR_Base_X.Integrator1_CSTATE) +
    OG_LIDAR_Base_B.Kffms;

  /* Saturate: '<S8>/Motor_command  sat' */
  if (rtb_SteeringBias > OG_LIDAR_Base_P.Motor_commandsat_UpperSat) {
    rtb_SteeringBias = OG_LIDAR_Base_P.Motor_commandsat_UpperSat;
  } else if (rtb_SteeringBias < OG_LIDAR_Base_P.Motor_commandsat_LowerSat) {
    rtb_SteeringBias = OG_LIDAR_Base_P.Motor_commandsat_LowerSat;
  }

  /* End of Saturate: '<S8>/Motor_command  sat' */

  /* Gain: '<Root>/direction convention' incorporates:
   *  Constant: '<Root>/Constant'
   *  Product: '<S8>/Multiply2'
   */
  rtb_SteeringBias = rtb_SteeringBias * OG_LIDAR_Base_P.Constant_Value_i *
    OG_LIDAR_Base_P.directionconvention_Gain;

  /* Saturate: '<Root>/command saturation' */
  if (rtb_SteeringBias > OG_LIDAR_Base_P.commandsaturation_UpperSat_l) {
    /* Saturate: '<Root>/command saturation' */
    OG_LIDAR_Base_B.commandsaturation =
      OG_LIDAR_Base_P.commandsaturation_UpperSat_l;
  } else if (rtb_SteeringBias < OG_LIDAR_Base_P.commandsaturation_LowerSat_l) {
    /* Saturate: '<Root>/command saturation' */
    OG_LIDAR_Base_B.commandsaturation =
      OG_LIDAR_Base_P.commandsaturation_LowerSat_l;
  } else {
    /* Saturate: '<Root>/command saturation' */
    OG_LIDAR_Base_B.commandsaturation = rtb_SteeringBias;
  }

  /* End of Saturate: '<Root>/command saturation' */
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    /* Bias: '<Root>/Steering Bias' */
    rtb_SteeringBias = OG_LIDAR_Base_B.steering +
      OG_LIDAR_Base_P.SteeringBias_Bias;

    /* S-Function (hil_write_block): '<Root>/HIL Write1' */

    /* S-Function Block: OG_LIDAR_Base/HIL Write1 (hil_write_block) */
    {
      t_error result;
      result = hil_write(OG_LIDAR_Base_DW.HILInitialize1_Card,
                         NULL, 0U,
                         &OG_LIDAR_Base_P.HILWrite1_pwm_channels, 1U,
                         NULL, 0U,
                         &OG_LIDAR_Base_P.HILWrite1_other_channels, 1U,
                         NULL,
                         &OG_LIDAR_Base_B.commandsaturation,
                         NULL,
                         &rtb_SteeringBias
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      }
    }
  }

  /* Integrator: '<S7>/Integrator' */
  OG_LIDAR_Base_B.Integrator = OG_LIDAR_Base_X.Integrator_CSTATE;

  /* Integrator: '<S7>/Integrator1' */
  OG_LIDAR_Base_B.Integrator1 = OG_LIDAR_Base_X.Integrator1_CSTATE_i;

  /* Integrator: '<S7>/Integrator2' */
  OG_LIDAR_Base_B.psi_headingrad = OG_LIDAR_Base_X.Integrator2_CSTATE_k;

  /* RateTransition: '<S6>/Rate Transition' */
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    /* RateTransition: '<S6>/Rate Transition' */
    OG_LIDAR_Base_B.RateTransition[0] = OG_LIDAR_Base_B.Integrator;
    OG_LIDAR_Base_B.RateTransition[1] = OG_LIDAR_Base_B.Integrator1;
    OG_LIDAR_Base_B.RateTransition[2] = OG_LIDAR_Base_B.psi_headingrad;
    OG_LIDAR_Base_B.RateTransition[3] = OG_LIDAR_Base_B.steering;

    /* S-Function (hil_read_block): '<Root>/HIL Read' */

    /* S-Function Block: OG_LIDAR_Base/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(OG_LIDAR_Base_DW.HILInitialize1_Card,
        NULL, 0U,
        &OG_LIDAR_Base_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        NULL,
        &OG_LIDAR_Base_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      } else {
        OG_LIDAR_Base_B.motorcounts = OG_LIDAR_Base_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S5>/Unwrap 2^24' */
    /* S-Function Block: OG_LIDAR_Base/filtering/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.033333333333333333;
      real_T half_range = OG_LIDAR_Base_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (OG_LIDAR_Base_DW.Unwrap224_FirstSample) {
        OG_LIDAR_Base_DW.Unwrap224_FirstSample = false;
        OG_LIDAR_Base_DW.Unwrap224_PreviousInput = OG_LIDAR_Base_B.motorcounts;
      }

      du = (real_T) OG_LIDAR_Base_B.motorcounts -
        OG_LIDAR_Base_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        OG_LIDAR_Base_DW.Unwrap224_Revolutions =
          OG_LIDAR_Base_DW.Unwrap224_Revolutions - 1;
        dy = du - OG_LIDAR_Base_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        OG_LIDAR_Base_DW.Unwrap224_Revolutions =
          OG_LIDAR_Base_DW.Unwrap224_Revolutions + 1;
        dy = du + OG_LIDAR_Base_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      OG_LIDAR_Base_B.Unwrap224 = OG_LIDAR_Base_B.motorcounts +
        OG_LIDAR_Base_DW.Unwrap224_Revolutions *
        OG_LIDAR_Base_P.Unwrap224_Modulus;
      OG_LIDAR_Base_DW.Unwrap224_PreviousInput = OG_LIDAR_Base_B.motorcounts;
    }
  }

  /* End of RateTransition: '<S6>/Rate Transition' */

  /* Integrator: '<S10>/Integrator1' */
  if (OG_LIDAR_Base_DW.Integrator1_IWORK != 0) {
    OG_LIDAR_Base_X.Integrator1_CSTATE_h = OG_LIDAR_Base_B.Unwrap224;
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
  OG_LIDAR_Base_B.Product = ((OG_LIDAR_Base_B.Unwrap224 -
    OG_LIDAR_Base_X.Integrator1_CSTATE_h) - OG_LIDAR_Base_X.Integrator2_CSTATE *
    OG_LIDAR_Base_P.Constant_Value_j * OG_LIDAR_Base_P.Constant3_Value) *
    OG_LIDAR_Base_P.Constant2_Value;

  /* Product: '<S7>/Product2' incorporates:
   *  Gain: '<S7>/1//L'
   */
  OG_LIDAR_Base_B.psidotrads = 1.0 / OG_LIDAR_Base_P.vehicle_length * rtb_speed *
    OG_LIDAR_Base_B.steering;

  /* Gain: '<S7>/Gain' */
  rtb_SteeringBias = OG_LIDAR_Base_P.vehicle_length / 2.0 *
    OG_LIDAR_Base_B.psidotrads;

  /* Trigonometry: '<S7>/Trigonometric Function1' */
  rtb_sinpsi = sin(OG_LIDAR_Base_B.psi_headingrad);

  /* Trigonometry: '<S7>/Trigonometric Function' */
  rtb_cospsi = cos(OG_LIDAR_Base_B.psi_headingrad);

  /* Sum: '<S7>/Sum' incorporates:
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   */
  OG_LIDAR_Base_B.v_Xms = rtb_speed * rtb_cospsi - rtb_SteeringBias * rtb_sinpsi;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product4'
   */
  OG_LIDAR_Base_B.v_Yms = rtb_speed * rtb_sinpsi + rtb_SteeringBias * rtb_cospsi;
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
  }

  /* Gain: '<S8>/Ki (% // m)  ' */
  OG_LIDAR_Base_B.Kim = OG_LIDAR_Base_P.Kim_Gain * rtb_Sum_a;
}

/* Model update function for TID0 */
void OG_LIDAR_Base_update0(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S10>/Integrator1' */
  OG_LIDAR_Base_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(OG_LIDAR_Base_M)) {
    rt_ertODEUpdateContinuousStates(&OG_LIDAR_Base_M->solverInfo);
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
  if (!(++OG_LIDAR_Base_M->Timing.clockTick0)) {
    ++OG_LIDAR_Base_M->Timing.clockTickH0;
  }

  OG_LIDAR_Base_M->Timing.t[0] = rtsiGetSolverStopTime
    (&OG_LIDAR_Base_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++OG_LIDAR_Base_M->Timing.clockTick1)) {
    ++OG_LIDAR_Base_M->Timing.clockTickH1;
  }

  OG_LIDAR_Base_M->Timing.t[1] = OG_LIDAR_Base_M->Timing.clockTick1 *
    OG_LIDAR_Base_M->Timing.stepSize1 + OG_LIDAR_Base_M->Timing.clockTickH1 *
    OG_LIDAR_Base_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void OG_LIDAR_Base_derivatives(void)
{
  XDot_OG_LIDAR_Base_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_OG_LIDAR_Base_T *) OG_LIDAR_Base_M->derivs);

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = OG_LIDAR_Base_B.Product;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  lsat = (OG_LIDAR_Base_X.Integrator1_CSTATE <=
          OG_LIDAR_Base_P.Integrator1_LowerSat);
  usat = (OG_LIDAR_Base_X.Integrator1_CSTATE >=
          OG_LIDAR_Base_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (OG_LIDAR_Base_B.Kim > 0.0)) || (usat &&
       (OG_LIDAR_Base_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE = OG_LIDAR_Base_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S8>/Integrator1' */

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = OG_LIDAR_Base_B.v_Xms;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_i = OG_LIDAR_Base_B.v_Yms;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_k = OG_LIDAR_Base_B.psidotrads;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h = OG_LIDAR_Base_B.Product1;
}

/* Model output function for TID2 */
void OG_LIDAR_Base_output2(void)       /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void OG_LIDAR_Base_update2(void)       /* Sample time: [0.1s, 0.0s] */
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
  if (!(++OG_LIDAR_Base_M->Timing.clockTick2)) {
    ++OG_LIDAR_Base_M->Timing.clockTickH2;
  }

  OG_LIDAR_Base_M->Timing.t[2] = OG_LIDAR_Base_M->Timing.clockTick2 *
    OG_LIDAR_Base_M->Timing.stepSize2 + OG_LIDAR_Base_M->Timing.clockTickH2 *
    OG_LIDAR_Base_M->Timing.stepSize2 * 4294967296.0;
}

/* Model wrapper function for compatibility with a static main program */
void OG_LIDAR_Base_output(int_T tid)
{
  switch (tid) {
   case 0 :
    OG_LIDAR_Base_output0();
    break;

   case 2 :
    OG_LIDAR_Base_output2();
    break;

   default :
    break;
  }
}

/* Model wrapper function for compatibility with a static main program */
void OG_LIDAR_Base_update(int_T tid)
{
  switch (tid) {
   case 0 :
    OG_LIDAR_Base_update0();
    break;

   case 2 :
    OG_LIDAR_Base_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void OG_LIDAR_Base_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: OG_LIDAR_Base/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &OG_LIDAR_Base_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(OG_LIDAR_Base_DW.HILInitialize1_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(OG_LIDAR_Base_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      return;
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_AIPStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &OG_LIDAR_Base_DW.HILInitialize1_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = OG_LIDAR_Base_P.HILInitialize1_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &OG_LIDAR_Base_DW.HILInitialize1_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = OG_LIDAR_Base_P.HILInitialize1_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(OG_LIDAR_Base_DW.HILInitialize1_Card,
        OG_LIDAR_Base_P.HILInitialize1_AIChannels, 7U,
        &OG_LIDAR_Base_DW.HILInitialize1_AIMinimums[0],
        &OG_LIDAR_Base_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(OG_LIDAR_Base_DW.HILInitialize1_Card,
      OG_LIDAR_Base_P.HILInitialize1_DIChannels, 19U,
      &OG_LIDAR_Base_P.HILInitialize1_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
      return;
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_DOStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_DOEnter && is_switching)) {
      result = hil_write_digital(OG_LIDAR_Base_DW.HILInitialize1_Card,
        &OG_LIDAR_Base_P.HILInitialize1_DOChannels, 1U, (t_boolean *)
        &OG_LIDAR_Base_P.HILInitialize1_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_EIPStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_EIPEnter && is_switching)) {
      OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes[0] =
        (OG_LIDAR_Base_P.HILInitialize1_EIQuadrature[0]);
      OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes[1] =
        (OG_LIDAR_Base_P.HILInitialize1_EIQuadrature[1]);
      OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes[2] =
        (OG_LIDAR_Base_P.HILInitialize1_EIQuadrature[1]);
      OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes[3] =
        (OG_LIDAR_Base_P.HILInitialize1_EIQuadrature[1]);
      OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes[4] =
        (OG_LIDAR_Base_P.HILInitialize1_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (OG_LIDAR_Base_DW.HILInitialize1_Card,
         OG_LIDAR_Base_P.HILInitialize1_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &OG_LIDAR_Base_DW.HILInitialize1_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] = OG_LIDAR_Base_P.HILInitialize1_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (OG_LIDAR_Base_DW.HILInitialize1_Card,
         OG_LIDAR_Base_P.HILInitialize1_EIChannels, 5U,
         &OG_LIDAR_Base_DW.HILInitialize1_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_EIStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &OG_LIDAR_Base_DW.HILInitialize1_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = OG_LIDAR_Base_P.HILInitialize1_EIInitial;
        }
      }

      result = hil_set_encoder_counts(OG_LIDAR_Base_DW.HILInitialize1_Card,
        OG_LIDAR_Base_P.HILInitialize1_EIChannels, 5U,
        &OG_LIDAR_Base_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_POPStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(OG_LIDAR_Base_DW.HILInitialize1_Card,
        &OG_LIDAR_Base_P.HILInitialize1_POChannels, 1U, (t_pwm_mode *)
        OG_LIDAR_Base_P.HILInitialize1_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }

      if ((OG_LIDAR_Base_P.HILInitialize1_POModes[0]) == PWM_DUTY_CYCLE_MODE ||
          (OG_LIDAR_Base_P.HILInitialize1_POModes[0]) == PWM_ONE_SHOT_MODE ||
          (OG_LIDAR_Base_P.HILInitialize1_POModes[0]) == PWM_TIME_MODE ||
          (OG_LIDAR_Base_P.HILInitialize1_POModes[0]) == PWM_RAW_MODE) {
        OG_LIDAR_Base_DW.HILInitialize1_POSortedChans =
          OG_LIDAR_Base_P.HILInitialize1_POChannels;
        OG_LIDAR_Base_DW.HILInitialize1_POSortedFreqs =
          OG_LIDAR_Base_P.HILInitialize1_POFrequency;
        num_duty_cycle_modes++;
      } else {
        OG_LIDAR_Base_DW.HILInitialize1_POSortedChans =
          OG_LIDAR_Base_P.HILInitialize1_POChannels;
        OG_LIDAR_Base_DW.HILInitialize1_POSortedFreqs =
          OG_LIDAR_Base_P.HILInitialize1_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(OG_LIDAR_Base_DW.HILInitialize1_Card,
          &OG_LIDAR_Base_DW.HILInitialize1_POSortedChans, num_duty_cycle_modes,
          &OG_LIDAR_Base_DW.HILInitialize1_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(OG_LIDAR_Base_DW.HILInitialize1_Card,
          &OG_LIDAR_Base_DW.HILInitialize1_POSortedChans, num_frequency_modes,
          &OG_LIDAR_Base_DW.HILInitialize1_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration(OG_LIDAR_Base_DW.HILInitialize1_Card,
        &OG_LIDAR_Base_P.HILInitialize1_POChannels, 1U,
        (t_pwm_configuration *) &OG_LIDAR_Base_P.HILInitialize1_POConfiguration,
        (t_pwm_alignment *) &OG_LIDAR_Base_P.HILInitialize1_POAlignment,
        (t_pwm_polarity *) &OG_LIDAR_Base_P.HILInitialize1_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_POStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_POEnter && is_switching)) {
      result = hil_write_pwm(OG_LIDAR_Base_DW.HILInitialize1_Card,
        &OG_LIDAR_Base_P.HILInitialize1_POChannels, 1U,
        &OG_LIDAR_Base_P.HILInitialize1_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    if (OG_LIDAR_Base_P.HILInitialize1_POReset) {
      result = hil_watchdog_set_pwm_expiration_state
        (OG_LIDAR_Base_DW.HILInitialize1_Card,
         &OG_LIDAR_Base_P.HILInitialize1_POChannels, 1U,
         &OG_LIDAR_Base_P.HILInitialize1_POWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_OOStart && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &OG_LIDAR_Base_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = OG_LIDAR_Base_P.HILInitialize1_OOInitial;
        }
      }

      result = hil_write_other(OG_LIDAR_Base_DW.HILInitialize1_Card,
        OG_LIDAR_Base_P.HILInitialize1_OOChannels, 13U,
        &OG_LIDAR_Base_DW.HILInitialize1_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: OG_LIDAR_Base/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    t_error result;
    result = rplidar_open("serial-cpu://localhost:2?baud='115200',word='8',parity='none',stop='1',flow='none',dsr='on'",
                          (t_ranging_distance)
                          (OG_LIDAR_Base_P.RangingSensor_Range - 1),
                          &OG_LIDAR_Base_DW.RangingSensor_Sensor);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
    }
  }

  /* Start for Constant: '<S4>/Constant1' */
  memcpy(&OG_LIDAR_Base_B.Constant1[0], &OG_LIDAR_Base_P.Constant1_Value[0],
         720U * sizeof(real_T));

  /* Start for S-Function (inverse_modulus_block): '<S5>/Unwrap 2^24' */

  /* S-Function Block: OG_LIDAR_Base/filtering/Unwrap 2^24 (inverse_modulus_block) */
  {
    OG_LIDAR_Base_DW.Unwrap224_FirstSample = true;
    OG_LIDAR_Base_DW.Unwrap224_Revolutions = 0;
  }

  OG_LIDAR_Base_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S10>/Integrator2' */
  OG_LIDAR_Base_X.Integrator2_CSTATE = OG_LIDAR_Base_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  OG_LIDAR_Base_X.Integrator1_CSTATE = OG_LIDAR_Base_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  OG_LIDAR_Base_X.Integrator_CSTATE = OG_LIDAR_Base_P.X_ic;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  OG_LIDAR_Base_X.Integrator1_CSTATE_i = OG_LIDAR_Base_P.Y_ic;

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  OG_LIDAR_Base_X.Integrator2_CSTATE_k = OG_LIDAR_Base_P.yaw_ic;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  if (rtmIsFirstInitCond(OG_LIDAR_Base_M)) {
    OG_LIDAR_Base_X.Integrator1_CSTATE_h = 0.0;
  }

  OG_LIDAR_Base_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S10>/Integrator1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(OG_LIDAR_Base_M)) {
    rtmSetFirstInitCond(OG_LIDAR_Base_M, 0);
  }
}

/* Model terminate function */
void OG_LIDAR_Base_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: OG_LIDAR_Base/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(OG_LIDAR_Base_DW.HILInitialize1_Card);
    hil_monitor_stop_all(OG_LIDAR_Base_DW.HILInitialize1_Card);
    is_switching = false;
    if ((OG_LIDAR_Base_P.HILInitialize1_DOTerminate && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_POTerminate && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_POExit && is_switching)) {
      num_final_pwm_outputs = 1U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((OG_LIDAR_Base_P.HILInitialize1_OOTerminate && !is_switching) ||
        (OG_LIDAR_Base_P.HILInitialize1_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &OG_LIDAR_Base_DW.HILInitialize1_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = OG_LIDAR_Base_P.HILInitialize1_OOFinal;
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
      result = hil_write(OG_LIDAR_Base_DW.HILInitialize1_Card
                         , NULL, 0
                         , &OG_LIDAR_Base_P.HILInitialize1_POChannels,
                         num_final_pwm_outputs
                         , &OG_LIDAR_Base_P.HILInitialize1_DOChannels,
                         num_final_digital_outputs
                         , OG_LIDAR_Base_P.HILInitialize1_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &OG_LIDAR_Base_P.HILInitialize1_POFinal
                         , (t_boolean *) &OG_LIDAR_Base_P.HILInitialize1_DOFinal
                         , &OG_LIDAR_Base_DW.HILInitialize1_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(OG_LIDAR_Base_DW.HILInitialize1_Card,
            &OG_LIDAR_Base_P.HILInitialize1_POChannels, num_final_pwm_outputs,
            &OG_LIDAR_Base_P.HILInitialize1_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(OG_LIDAR_Base_DW.HILInitialize1_Card,
            &OG_LIDAR_Base_P.HILInitialize1_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &OG_LIDAR_Base_P.HILInitialize1_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(OG_LIDAR_Base_DW.HILInitialize1_Card,
            OG_LIDAR_Base_P.HILInitialize1_OOChannels, num_final_other_outputs,
            &OG_LIDAR_Base_DW.HILInitialize1_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(OG_LIDAR_Base_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(OG_LIDAR_Base_DW.HILInitialize1_Card);
    hil_monitor_delete_all(OG_LIDAR_Base_DW.HILInitialize1_Card);
    hil_close(OG_LIDAR_Base_DW.HILInitialize1_Card);
    OG_LIDAR_Base_DW.HILInitialize1_Card = NULL;
  }

  /* Terminate for S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: OG_LIDAR_Base/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    rplidar_close(OG_LIDAR_Base_DW.RangingSensor_Sensor);
    OG_LIDAR_Base_DW.RangingSensor_Sensor = NULL;
    OG_LIDAR_Base_DW.RangingSensor_Sensor = NULL;
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
  OG_LIDAR_Base_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  OG_LIDAR_Base_update(tid);
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
  OG_LIDAR_Base_initialize();
}

void MdlTerminate(void)
{
  OG_LIDAR_Base_terminate();
}

/* Registration function */
RT_MODEL_OG_LIDAR_Base_T *OG_LIDAR_Base(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  OG_LIDAR_Base_P.RangingSensor_MaxInterpolationD = rtInf;

  /* initialize real-time model */
  (void) memset((void *)OG_LIDAR_Base_M, 0,
                sizeof(RT_MODEL_OG_LIDAR_Base_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&OG_LIDAR_Base_M->solverInfo,
                          &OG_LIDAR_Base_M->Timing.simTimeStep);
    rtsiSetTPtr(&OG_LIDAR_Base_M->solverInfo, &rtmGetTPtr(OG_LIDAR_Base_M));
    rtsiSetStepSizePtr(&OG_LIDAR_Base_M->solverInfo,
                       &OG_LIDAR_Base_M->Timing.stepSize0);
    rtsiSetdXPtr(&OG_LIDAR_Base_M->solverInfo, &OG_LIDAR_Base_M->derivs);
    rtsiSetContStatesPtr(&OG_LIDAR_Base_M->solverInfo, (real_T **)
                         &OG_LIDAR_Base_M->contStates);
    rtsiSetNumContStatesPtr(&OG_LIDAR_Base_M->solverInfo,
      &OG_LIDAR_Base_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&OG_LIDAR_Base_M->solverInfo,
      &OG_LIDAR_Base_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&OG_LIDAR_Base_M->solverInfo,
      &OG_LIDAR_Base_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&OG_LIDAR_Base_M->solverInfo,
      &OG_LIDAR_Base_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&OG_LIDAR_Base_M->solverInfo, (&rtmGetErrorStatus
      (OG_LIDAR_Base_M)));
    rtsiSetRTModelPtr(&OG_LIDAR_Base_M->solverInfo, OG_LIDAR_Base_M);
  }

  rtsiSetSimTimeStep(&OG_LIDAR_Base_M->solverInfo, MAJOR_TIME_STEP);
  OG_LIDAR_Base_M->intgData.f[0] = OG_LIDAR_Base_M->odeF[0];
  OG_LIDAR_Base_M->contStates = ((real_T *) &OG_LIDAR_Base_X);
  rtsiSetSolverData(&OG_LIDAR_Base_M->solverInfo, (void *)
                    &OG_LIDAR_Base_M->intgData);
  rtsiSetSolverName(&OG_LIDAR_Base_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = OG_LIDAR_Base_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    OG_LIDAR_Base_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    OG_LIDAR_Base_M->Timing.sampleTimes =
      (&OG_LIDAR_Base_M->Timing.sampleTimesArray[0]);
    OG_LIDAR_Base_M->Timing.offsetTimes =
      (&OG_LIDAR_Base_M->Timing.offsetTimesArray[0]);

    /* task periods */
    OG_LIDAR_Base_M->Timing.sampleTimes[0] = (0.0);
    OG_LIDAR_Base_M->Timing.sampleTimes[1] = (0.033333333333333333);
    OG_LIDAR_Base_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    OG_LIDAR_Base_M->Timing.offsetTimes[0] = (0.0);
    OG_LIDAR_Base_M->Timing.offsetTimes[1] = (0.0);
    OG_LIDAR_Base_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(OG_LIDAR_Base_M, &OG_LIDAR_Base_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = OG_LIDAR_Base_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = OG_LIDAR_Base_M->Timing.perTaskSampleHitsArray;
    OG_LIDAR_Base_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    OG_LIDAR_Base_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(OG_LIDAR_Base_M, -1);
  OG_LIDAR_Base_M->Timing.stepSize0 = 0.033333333333333333;
  OG_LIDAR_Base_M->Timing.stepSize1 = 0.033333333333333333;
  OG_LIDAR_Base_M->Timing.stepSize2 = 0.1;
  rtmSetFirstInitCond(OG_LIDAR_Base_M, 1);

  /* External mode info */
  OG_LIDAR_Base_M->Sizes.checksums[0] = (2397116534U);
  OG_LIDAR_Base_M->Sizes.checksums[1] = (2255181284U);
  OG_LIDAR_Base_M->Sizes.checksums[2] = (345482519U);
  OG_LIDAR_Base_M->Sizes.checksums[3] = (736530755U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    OG_LIDAR_Base_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(OG_LIDAR_Base_M->extModeInfo,
      &OG_LIDAR_Base_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(OG_LIDAR_Base_M->extModeInfo,
                        OG_LIDAR_Base_M->Sizes.checksums);
    rteiSetTPtr(OG_LIDAR_Base_M->extModeInfo, rtmGetTPtr(OG_LIDAR_Base_M));
  }

  OG_LIDAR_Base_M->solverInfoPtr = (&OG_LIDAR_Base_M->solverInfo);
  OG_LIDAR_Base_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&OG_LIDAR_Base_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&OG_LIDAR_Base_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  OG_LIDAR_Base_M->blockIO = ((void *) &OG_LIDAR_Base_B);
  (void) memset(((void *) &OG_LIDAR_Base_B), 0,
                sizeof(B_OG_LIDAR_Base_T));

  /* parameters */
  OG_LIDAR_Base_M->defaultParam = ((real_T *)&OG_LIDAR_Base_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &OG_LIDAR_Base_X;
    OG_LIDAR_Base_M->contStates = (x);
    (void) memset((void *)&OG_LIDAR_Base_X, 0,
                  sizeof(X_OG_LIDAR_Base_T));
  }

  /* states (dwork) */
  OG_LIDAR_Base_M->dwork = ((void *) &OG_LIDAR_Base_DW);
  (void) memset((void *)&OG_LIDAR_Base_DW, 0,
                sizeof(DW_OG_LIDAR_Base_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    OG_LIDAR_Base_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  OG_LIDAR_Base_M->Sizes.numContStates = (6);/* Number of continuous states */
  OG_LIDAR_Base_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  OG_LIDAR_Base_M->Sizes.numY = (0);   /* Number of model outputs */
  OG_LIDAR_Base_M->Sizes.numU = (0);   /* Number of model inputs */
  OG_LIDAR_Base_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  OG_LIDAR_Base_M->Sizes.numSampTimes = (3);/* Number of sample times */
  OG_LIDAR_Base_M->Sizes.numBlocks = (63);/* Number of blocks */
  OG_LIDAR_Base_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  OG_LIDAR_Base_M->Sizes.numBlockPrms = (936);/* Sum of parameter "widths" */
  return OG_LIDAR_Base_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
