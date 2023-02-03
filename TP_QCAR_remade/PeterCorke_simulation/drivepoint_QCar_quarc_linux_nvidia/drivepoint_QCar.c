/*
 * drivepoint_QCar.c
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

#include "drivepoint_QCar.h"
#include "drivepoint_QCar_private.h"
#include "drivepoint_QCar_dt.h"

/* Block signals (default storage) */
B_drivepoint_QCar_T drivepoint_QCar_B;

/* Continuous states */
X_drivepoint_QCar_T drivepoint_QCar_X;

/* Block states (default storage) */
DW_drivepoint_QCar_T drivepoint_QCar_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_drivepoint_QCar_T drivepoint_QCar_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_drivepoint_QCar_T drivepoint_QCar_Y;

/* Real-time model */
static RT_MODEL_drivepoint_QCar_T drivepoint_QCar_M_;
RT_MODEL_drivepoint_QCar_T *const drivepoint_QCar_M = &drivepoint_QCar_M_;

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 7;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    drivepoint_QCar_output();
    rtsiSetdX(si,p);
    drivepoint_QCar_derivatives();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  drivepoint_QCar_derivatives();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (p = W, i = 0; i < nx; i++, p += (nx+1)) {
      *p += 1.0;
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      drivepoint_QCar_output();
      drivepoint_QCar_derivatives();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - (ytmp-yn) */
      for (i = 0; i < nx; i++) {
        Delta[i] -= xtmp[i];
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        drivepoint_QCar_output();
        drivepoint_QCar_derivatives();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (i = 0; i < nx; i++) {
            Delta[i] -= xtmp[i];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
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
void drivepoint_QCar_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILRead_o2;
  b_dsp_FIRFilter_0_drivepoint__T *obj_0;
  b_dspcodegen_FIRFilter_drivep_T *obj;
  real_T pLastY;
  real_T q;
  real_T rtb_gamma;
  real_T thetaWrap;
  int32_T n;
  boolean_T rEQ0;
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
    /* set solver stop time */
    if (!(drivepoint_QCar_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&drivepoint_QCar_M->solverInfo,
                            ((drivepoint_QCar_M->Timing.clockTickH0 + 1) *
        drivepoint_QCar_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&drivepoint_QCar_M->solverInfo,
                            ((drivepoint_QCar_M->Timing.clockTick0 + 1) *
        drivepoint_QCar_M->Timing.stepSize0 +
        drivepoint_QCar_M->Timing.clockTickH0 *
        drivepoint_QCar_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(drivepoint_QCar_M)) {
    drivepoint_QCar_M->Timing.t[0] = rtsiGetT(&drivepoint_QCar_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
  }

  /* Integrator: '<Root>/Integrator' */
  drivepoint_QCar_B.currentheading = drivepoint_QCar_X.Integrator_CSTATE;

  /* Outport: '<Root>/theta' */
  drivepoint_QCar_Y.theta = drivepoint_QCar_B.currentheading;

  /* Integrator: '<S1>/Integrator' */
  drivepoint_QCar_B.positions[0] = drivepoint_QCar_X.Integrator_CSTATE_l[0];
  drivepoint_QCar_B.positions[1] = drivepoint_QCar_X.Integrator_CSTATE_l[1];
  drivepoint_QCar_B.positions[2] = drivepoint_QCar_X.Integrator_CSTATE_l[2];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Goal position'
   */
  drivepoint_QCar_B.Sum[0] = drivepoint_QCar_P.xg[0] -
    drivepoint_QCar_B.positions[0];
  drivepoint_QCar_B.Sum[1] = drivepoint_QCar_P.xg[1] -
    drivepoint_QCar_B.positions[1];

  /* Fcn: '<Root>/distance to goal' */
  pLastY = rt_powd_snf(drivepoint_QCar_B.Sum[0], 2.0) + rt_powd_snf
    (drivepoint_QCar_B.Sum[1], 2.0);
  if (pLastY < 0.0) {
    pLastY = -sqrt(-pLastY);
  } else {
    pLastY = sqrt(pLastY);
  }

  /* Gain: '<Root>/velocity gain Kv' incorporates:
   *  Fcn: '<Root>/distance to goal'
   */
  drivepoint_QCar_B.speedcommand = drivepoint_QCar_P.velocitygainKv_Gain *
    pLastY;

  /* Saturate: '<S7>/command saturation' */
  if (drivepoint_QCar_B.speedcommand >
      drivepoint_QCar_P.commandsaturation_UpperSat) {
    /* Saturate: '<S7>/command saturation' */
    drivepoint_QCar_B.desired = drivepoint_QCar_P.commandsaturation_UpperSat;
  } else if (drivepoint_QCar_B.speedcommand <
             drivepoint_QCar_P.commandsaturation_LowerSat) {
    /* Saturate: '<S7>/command saturation' */
    drivepoint_QCar_B.desired = drivepoint_QCar_P.commandsaturation_LowerSat;
  } else {
    /* Saturate: '<S7>/command saturation' */
    drivepoint_QCar_B.desired = drivepoint_QCar_B.speedcommand;
  }

  /* End of Saturate: '<S7>/command saturation' */

  /* Product: '<S7>/Multiply1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  drivepoint_QCar_B.desired_o = drivepoint_QCar_B.desired *
    drivepoint_QCar_P.Constant_Value_f;

  /* Integrator: '<S3>/Integrator2' */
  drivepoint_QCar_B.Integrator2 = drivepoint_QCar_X.Integrator2_CSTATE;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  drivepoint_QCar_B.Product1 = drivepoint_QCar_P.Constant2_Value *
    drivepoint_QCar_B.Integrator2;

  /* Gain: '<S6>/counts to rotations' */
  drivepoint_QCar_B.motorspeedrots = drivepoint_QCar_P.countstorotations_Gain *
    drivepoint_QCar_B.Product1;

  /* Gain: '<S6>/gear ratios' */
  drivepoint_QCar_B.shaftspeedrotss = drivepoint_QCar_P.gearratios_Gain *
    drivepoint_QCar_B.motorspeedrots;

  /* Gain: '<S6>/rot//s to rad//s' */
  drivepoint_QCar_B.wheelspeedrads = drivepoint_QCar_P.rotstorads_Gain *
    drivepoint_QCar_B.shaftspeedrotss;

  /* Gain: '<S6>/wheel radius' */
  drivepoint_QCar_B.wheelspeedms = drivepoint_QCar_P.wheelradius_Gain *
    drivepoint_QCar_B.wheelspeedrads;

  /* Gain: '<S6>/Offset' */
  drivepoint_QCar_B.Offset = drivepoint_QCar_P.Offset_Gain *
    drivepoint_QCar_B.wheelspeedms;

  /* Product: '<S7>/Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   */
  drivepoint_QCar_B.measured = drivepoint_QCar_B.Offset *
    drivepoint_QCar_P.Constant_Value_f;

  /* Sum: '<S7>/Sum' */
  drivepoint_QCar_B.Sum_n = drivepoint_QCar_B.desired_o -
    drivepoint_QCar_B.measured;

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  drivepoint_QCar_B.Compare = (drivepoint_QCar_B.desired_o ==
    drivepoint_QCar_P.Constant_Value);

  /* Integrator: '<S7>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
    rEQ0 = (((drivepoint_QCar_PrevZCX.Integrator1_Reset_ZCE == 1) != (int32_T)
             drivepoint_QCar_B.Compare) &&
            (drivepoint_QCar_PrevZCX.Integrator1_Reset_ZCE != 3));
    drivepoint_QCar_PrevZCX.Integrator1_Reset_ZCE = drivepoint_QCar_B.Compare;

    /* evaluate zero-crossings */
    if (rEQ0) {
      drivepoint_QCar_X.Integrator1_CSTATE = drivepoint_QCar_P.Integrator1_IC;
    }
  }

  if (drivepoint_QCar_X.Integrator1_CSTATE >=
      drivepoint_QCar_P.Integrator1_UpperSat) {
    drivepoint_QCar_X.Integrator1_CSTATE =
      drivepoint_QCar_P.Integrator1_UpperSat;
  } else if (drivepoint_QCar_X.Integrator1_CSTATE <=
             drivepoint_QCar_P.Integrator1_LowerSat) {
    drivepoint_QCar_X.Integrator1_CSTATE =
      drivepoint_QCar_P.Integrator1_LowerSat;
  }

  /* Integrator: '<S7>/Integrator1' */
  drivepoint_QCar_B.Integrator1 = drivepoint_QCar_X.Integrator1_CSTATE;

  /* Sum: '<S7>/Add1' incorporates:
   *  Gain: '<S7>/Kff  (% // m//s)'
   *  Gain: '<S7>/Kp (% // m//s)'
   *  Sum: '<S7>/Add'
   */
  rtb_gamma = (drivepoint_QCar_P.Kpms_Gain * drivepoint_QCar_B.Sum_n +
               drivepoint_QCar_B.Integrator1) + drivepoint_QCar_P.Kffms_Gain *
    drivepoint_QCar_B.desired_o;

  /* Saturate: '<S7>/Motor_command  sat' */
  if (rtb_gamma > drivepoint_QCar_P.Motor_commandsat_UpperSat) {
    rtb_gamma = drivepoint_QCar_P.Motor_commandsat_UpperSat;
  } else if (rtb_gamma < drivepoint_QCar_P.Motor_commandsat_LowerSat) {
    rtb_gamma = drivepoint_QCar_P.Motor_commandsat_LowerSat;
  }

  /* End of Saturate: '<S7>/Motor_command  sat' */

  /* Gain: '<Root>/Gain1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Product: '<S7>/Multiply2'
   */
  drivepoint_QCar_B.Gain1 = rtb_gamma * drivepoint_QCar_P.Constant_Value_f *
    drivepoint_QCar_P.Gain1_Gain;

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Fcn: '<Root>/heading angle to goal'
   */
  /* MATLAB Function 'MATLAB Function2': '<S2>:1' */
  /* '<S2>:1:3' */
  rtb_gamma = rt_atan2d_snf(drivepoint_QCar_B.Sum[1], drivepoint_QCar_B.Sum[0])
    - drivepoint_QCar_B.positions[2];
  if (fabs(rtb_gamma) > 3.1415926535897931) {
    if (rtIsNaN(rtb_gamma + 3.1415926535897931) || rtIsInf(rtb_gamma +
         3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (rtb_gamma + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      thetaWrap = fmod(rtb_gamma + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        q = fabs((rtb_gamma + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (rtb_gamma + 3.1415926535897931 < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (rtb_gamma + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    rtb_gamma = thetaWrap - 3.1415926535897931;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* Gain: '<Root>/heading gain Kh' */
  drivepoint_QCar_B.steeringwheelangle = drivepoint_QCar_P.headinggainKh_Gain *
    rtb_gamma;

  /* Saturate: '<Root>/Saturation' */
  if (drivepoint_QCar_B.steeringwheelangle >
      drivepoint_QCar_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    drivepoint_QCar_B.Saturation = drivepoint_QCar_P.Saturation_UpperSat;
  } else if (drivepoint_QCar_B.steeringwheelangle <
             drivepoint_QCar_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    drivepoint_QCar_B.Saturation = drivepoint_QCar_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    drivepoint_QCar_B.Saturation = drivepoint_QCar_B.steeringwheelangle;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
    /* S-Function (hil_write_block): '<Root>/HIL Write' */

    /* S-Function Block: drivepoint_QCar/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(drivepoint_QCar_DW.HILInitialize_Card,
                         NULL, 0U,
                         &drivepoint_QCar_P.HILWrite_pwm_channels, 1U,
                         NULL, 0U,
                         &drivepoint_QCar_P.HILWrite_other_channels, 1U,
                         NULL,
                         &drivepoint_QCar_B.Gain1,
                         NULL,
                         &drivepoint_QCar_B.Saturation
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
      }
    }
  }

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Fcn: '<Root>/distance to goal'
   */
  drivepoint_QCar_B.Compare_m = (pLastY < drivepoint_QCar_P.arewethereyet_const);
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
    /* Stop: '<Root>/Stop Simulation' */
    if (drivepoint_QCar_B.Compare_m) {
      rtmSetStopRequested(drivepoint_QCar_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */
  }

  /* Saturate: '<S1>/steering limit' */
  if (drivepoint_QCar_B.steeringwheelangle >
      drivepoint_QCar_P.steeringlimit_UpperSat) {
    /* Saturate: '<S1>/steering limit' */
    drivepoint_QCar_B.steeringlimit = drivepoint_QCar_P.steeringlimit_UpperSat;
  } else if (drivepoint_QCar_B.steeringwheelangle <
             drivepoint_QCar_P.steeringlimit_LowerSat) {
    /* Saturate: '<S1>/steering limit' */
    drivepoint_QCar_B.steeringlimit = drivepoint_QCar_P.steeringlimit_LowerSat;
  } else {
    /* Saturate: '<S1>/steering limit' */
    drivepoint_QCar_B.steeringlimit = drivepoint_QCar_B.steeringwheelangle;
  }

  /* End of Saturate: '<S1>/steering limit' */

  /* Product: '<S8>/Divide' incorporates:
   *  Constant: '<S8>/vehicle length'
   *  Trigonometry: '<S8>/Tan'
   */
  drivepoint_QCar_B.Divide = tan(drivepoint_QCar_B.steeringlimit) /
    drivepoint_QCar_P.vehiclelength_Value;

  /* Saturate: '<S1>/velocity limit' */
  if (drivepoint_QCar_B.Offset > drivepoint_QCar_P.velocitylimit_UpperSat) {
    /* Saturate: '<S1>/velocity limit' */
    drivepoint_QCar_B.velocitylimit = drivepoint_QCar_P.velocitylimit_UpperSat;
  } else if (drivepoint_QCar_B.Offset < drivepoint_QCar_P.velocitylimit_LowerSat)
  {
    /* Saturate: '<S1>/velocity limit' */
    drivepoint_QCar_B.velocitylimit = drivepoint_QCar_P.velocitylimit_LowerSat;
  } else {
    /* Saturate: '<S1>/velocity limit' */
    drivepoint_QCar_B.velocitylimit = drivepoint_QCar_B.Offset;
  }

  /* End of Saturate: '<S1>/velocity limit' */

  /* RateLimiter: '<S1>/acceleration limit' */
  pLastY = drivepoint_QCar_M->Timing.t[0];
  if ((drivepoint_QCar_DW.LastMajorTimeA >= pLastY) &&
      (drivepoint_QCar_DW.LastMajorTimeB >= pLastY)) {
    /* RateLimiter: '<S1>/acceleration limit' */
    drivepoint_QCar_B.accelerationlimit = drivepoint_QCar_B.velocitylimit;
  } else {
    if (((drivepoint_QCar_DW.LastMajorTimeA < drivepoint_QCar_DW.LastMajorTimeB)
         && (drivepoint_QCar_DW.LastMajorTimeB < pLastY)) ||
        ((drivepoint_QCar_DW.LastMajorTimeA >= drivepoint_QCar_DW.LastMajorTimeB)
         && (drivepoint_QCar_DW.LastMajorTimeA >= pLastY))) {
      thetaWrap = pLastY - drivepoint_QCar_DW.LastMajorTimeB;
      pLastY = drivepoint_QCar_DW.PrevYB;
    } else {
      thetaWrap = pLastY - drivepoint_QCar_DW.LastMajorTimeA;
      pLastY = drivepoint_QCar_DW.PrevYA;
    }

    q = thetaWrap * drivepoint_QCar_P.accelerationlimit_RisingLim;
    rtb_gamma = drivepoint_QCar_B.velocitylimit - pLastY;
    if (rtb_gamma > q) {
      /* RateLimiter: '<S1>/acceleration limit' */
      drivepoint_QCar_B.accelerationlimit = pLastY + q;
    } else {
      thetaWrap *= drivepoint_QCar_P.accelerationlimit_FallingLim;
      if (rtb_gamma < thetaWrap) {
        /* RateLimiter: '<S1>/acceleration limit' */
        drivepoint_QCar_B.accelerationlimit = pLastY + thetaWrap;
      } else {
        /* RateLimiter: '<S1>/acceleration limit' */
        drivepoint_QCar_B.accelerationlimit = drivepoint_QCar_B.velocitylimit;
      }
    }
  }

  /* End of RateLimiter: '<S1>/acceleration limit' */

  /* Product: '<S1>/Product' incorporates:
   *  Trigonometry: '<S1>/Cos'
   *  Trigonometry: '<S1>/Sin'
   */
  drivepoint_QCar_B.Product[0] = cos(drivepoint_QCar_B.positions[2]) *
    drivepoint_QCar_B.accelerationlimit;
  drivepoint_QCar_B.Product[1] = sin(drivepoint_QCar_B.positions[2]) *
    drivepoint_QCar_B.accelerationlimit;
  drivepoint_QCar_B.Product[2] = drivepoint_QCar_B.Divide *
    drivepoint_QCar_B.accelerationlimit;
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
    /* S-Function (hil_read_block): '<Root>/HIL Read' */

    /* S-Function Block: drivepoint_QCar/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(drivepoint_QCar_DW.HILInitialize_Card,
        NULL, 0U,
        &drivepoint_QCar_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        &drivepoint_QCar_P.HILRead_other_channels, 1U,
        NULL,
        &drivepoint_QCar_DW.HILRead_EncoderBuffer,
        NULL,
        &drivepoint_QCar_DW.HILRead_OtherBuffer
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
      } else {
        drivepoint_QCar_B.motorcounts = drivepoint_QCar_DW.HILRead_EncoderBuffer;
        rtb_HILRead_o2 = drivepoint_QCar_DW.HILRead_OtherBuffer;
      }
    }

    /* MATLABSystem: '<Root>/Lowpass Filter' */
    obj = drivepoint_QCar_DW.obj.FilterObj;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->isSetupComplete = true;

      /* System object Initialization function: dsp.FIRFilter */
      for (n = 0; n < 457; n++) {
        obj->cSFunObject.W0_states[n] = obj->cSFunObject.P0_InitialStates;
      }
    }

    obj_0 = &obj->cSFunObject;

    /* System object Outputs function: dsp.FIRFilter */
    rtb_gamma = rtb_HILRead_o2;
    pLastY = 0.0;

    /* load input sample */
    for (n = 0; n < 457; n++) {
      /* shift state */
      thetaWrap = rtb_gamma;
      rtb_gamma = obj_0->W0_states[n];
      obj_0->W0_states[n] = thetaWrap;

      /* compute one tap */
      thetaWrap *= obj_0->P1_Coefficients[n];
      pLastY += thetaWrap;
    }

    /* compute last tap */
    thetaWrap = obj->cSFunObject.P1_Coefficients[n] * rtb_gamma;

    /* MATLABSystem: '<Root>/Lowpass Filter' */
    /* store output sample */
    drivepoint_QCar_B.theta_dotrads = pLastY + thetaWrap;

    /* S-Function (inverse_modulus_block): '<Root>/Unwrap 2^24' */
    /* S-Function Block: drivepoint_QCar/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = drivepoint_QCar_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (drivepoint_QCar_DW.Unwrap224_FirstSample) {
        drivepoint_QCar_DW.Unwrap224_FirstSample = false;
        drivepoint_QCar_DW.Unwrap224_PreviousInput =
          drivepoint_QCar_B.motorcounts;
      }

      du = (real_T) drivepoint_QCar_B.motorcounts -
        drivepoint_QCar_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        drivepoint_QCar_DW.Unwrap224_Revolutions =
          drivepoint_QCar_DW.Unwrap224_Revolutions - 1;
        dy = du - drivepoint_QCar_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        drivepoint_QCar_DW.Unwrap224_Revolutions =
          drivepoint_QCar_DW.Unwrap224_Revolutions + 1;
        dy = du + drivepoint_QCar_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      drivepoint_QCar_B.Unwrap224 = drivepoint_QCar_B.motorcounts +
        drivepoint_QCar_DW.Unwrap224_Revolutions *
        drivepoint_QCar_P.Unwrap224_Modulus;
      drivepoint_QCar_DW.Unwrap224_PreviousInput = drivepoint_QCar_B.motorcounts;
    }
  }

  /* Integrator: '<S3>/Integrator1' */
  if (drivepoint_QCar_DW.Integrator1_IWORK != 0) {
    drivepoint_QCar_X.Integrator1_CSTATE_e = drivepoint_QCar_B.Unwrap224;
  }

  /* Integrator: '<S3>/Integrator1' */
  drivepoint_QCar_B.Integrator1_j = drivepoint_QCar_X.Integrator1_CSTATE_e;

  /* Sum: '<S3>/Sum1' */
  drivepoint_QCar_B.Sum1 = drivepoint_QCar_B.Unwrap224 -
    drivepoint_QCar_B.Integrator1_j;

  /* Product: '<S3>/Product2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S3>/Constant'
   */
  drivepoint_QCar_B.Product2 = drivepoint_QCar_B.Integrator2 *
    drivepoint_QCar_P.Constant_Value_e * drivepoint_QCar_P.Constant3_Value;

  /* Sum: '<S3>/Sum' */
  drivepoint_QCar_B.Sum_e = drivepoint_QCar_B.Sum1 - drivepoint_QCar_B.Product2;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  drivepoint_QCar_B.Product_b = drivepoint_QCar_P.Constant2_Value *
    drivepoint_QCar_B.Sum_e;
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
  }

  /* Gain: '<S7>/Ki (% // m)  ' */
  drivepoint_QCar_B.Kim = drivepoint_QCar_P.Kim_Gain * drivepoint_QCar_B.Sum_n;
}

/* Model update function */
void drivepoint_QCar_update(void)
{
  /* Update for RateLimiter: '<S1>/acceleration limit' */
  if (drivepoint_QCar_DW.LastMajorTimeA == (rtInf)) {
    drivepoint_QCar_DW.LastMajorTimeA = drivepoint_QCar_M->Timing.t[0];
    drivepoint_QCar_DW.PrevYA = drivepoint_QCar_B.accelerationlimit;
  } else if (drivepoint_QCar_DW.LastMajorTimeB == (rtInf)) {
    drivepoint_QCar_DW.LastMajorTimeB = drivepoint_QCar_M->Timing.t[0];
    drivepoint_QCar_DW.PrevYB = drivepoint_QCar_B.accelerationlimit;
  } else if (drivepoint_QCar_DW.LastMajorTimeA <
             drivepoint_QCar_DW.LastMajorTimeB) {
    drivepoint_QCar_DW.LastMajorTimeA = drivepoint_QCar_M->Timing.t[0];
    drivepoint_QCar_DW.PrevYA = drivepoint_QCar_B.accelerationlimit;
  } else {
    drivepoint_QCar_DW.LastMajorTimeB = drivepoint_QCar_M->Timing.t[0];
    drivepoint_QCar_DW.PrevYB = drivepoint_QCar_B.accelerationlimit;
  }

  /* End of Update for RateLimiter: '<S1>/acceleration limit' */

  /* Update for Integrator: '<S3>/Integrator1' */
  drivepoint_QCar_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(drivepoint_QCar_M)) {
    rt_ertODEUpdateContinuousStates(&drivepoint_QCar_M->solverInfo);
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
  if (!(++drivepoint_QCar_M->Timing.clockTick0)) {
    ++drivepoint_QCar_M->Timing.clockTickH0;
  }

  drivepoint_QCar_M->Timing.t[0] = rtsiGetSolverStopTime
    (&drivepoint_QCar_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++drivepoint_QCar_M->Timing.clockTick1)) {
      ++drivepoint_QCar_M->Timing.clockTickH1;
    }

    drivepoint_QCar_M->Timing.t[1] = drivepoint_QCar_M->Timing.clockTick1 *
      drivepoint_QCar_M->Timing.stepSize1 +
      drivepoint_QCar_M->Timing.clockTickH1 *
      drivepoint_QCar_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void drivepoint_QCar_derivatives(void)
{
  XDot_drivepoint_QCar_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_drivepoint_QCar_T *) drivepoint_QCar_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = drivepoint_QCar_B.theta_dotrads;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[0] = drivepoint_QCar_B.Product[0];
  _rtXdot->Integrator_CSTATE_l[1] = drivepoint_QCar_B.Product[1];
  _rtXdot->Integrator_CSTATE_l[2] = drivepoint_QCar_B.Product[2];

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = drivepoint_QCar_B.Product_b;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  lsat = (drivepoint_QCar_X.Integrator1_CSTATE <=
          drivepoint_QCar_P.Integrator1_LowerSat);
  usat = (drivepoint_QCar_X.Integrator1_CSTATE >=
          drivepoint_QCar_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (drivepoint_QCar_B.Kim > 0.0)) || (usat &&
       (drivepoint_QCar_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE = drivepoint_QCar_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S7>/Integrator1' */

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = drivepoint_QCar_B.Product1;
}

/* Model initialize function */
void drivepoint_QCar_initialize(void)
{
  {
    b_dspcodegen_FIRFilter_drivep_T *iobj_0;
    int32_T i;
    static const real_T tmp[458] = { 5.6767778271866516E-5,
      1.5795816232593139E-5, 1.7947540861151679E-5, 2.0260874194992456E-5,
      2.2739020488131543E-5, 2.5385728845885136E-5, 2.8207726984584141E-5,
      3.1202978526585671E-5, 3.437744745554658E-5, 3.7731241746168895E-5,
      4.1266227979697194E-5, 4.498145402769874E-5, 4.887839286743438E-5,
      5.2956254246761535E-5, 5.7214303343971881E-5, 6.1649433006808312E-5,
      6.6258903044584032E-5, 7.1038491716511035E-5, 7.598366176848507E-5,
      8.1088023577758283E-5, 8.6344905367853562E-5, 9.1746660711168813E-5,
      9.7285364241223081E-5, 0.00010295143782818293, 0.00010873402878706212,
      0.00011462064266438507, 0.00012059807486813235, 0.00012665207866046694,
      0.00013276751787639124, 0.00013892783145253441, 0.00014511530919185411,
      0.00015131101775082962, 0.00015749495882783288, 0.00016364586283160789,
      0.00016974124601889726, 0.000175757620655289, 0.00018167064726000209,
      0.00018745512239541989, 0.00019308447130551325, 0.00019853075546223968,
      0.00020376474010966116, 0.00020875680273691963, 0.00021347680147375473,
      0.00021789406614495019, 0.00022197624012000391, 0.00022568985647915653,
      0.00022900046335732723, 0.00023187420109533583, 0.00023427677071234941,
      0.00023617355970067616, 0.00023752801552727001, 0.00023830380105764755,
      0.00023846449130310576, 0.00023797562916387987, 0.0002368014477743279,
      0.00023490649079537261, 0.00023225334089643524, 0.00022880814947703811,
      0.00022453646965557317, 0.00021940724994144853, 0.00021338340530728151,
      0.00020643401298153785, 0.00019852378123413881, 0.00018963988212175795,
      0.000179724458518688, 0.0001687760125197001, 0.00015675948555891723,
      0.0001436439873885048, 0.00012941267085404674, 0.00011405635998179952,
      9.7536399475715374E-5, 7.9849051074803946E-5, 6.0980849567570254E-5,
      4.09232815403084E-5, 1.9663684154742737E-5, -2.8019217615462844E-6,
      -2.6474712200137892E-5, -5.1350588682011877E-5, -7.7426282343867633E-5,
      -0.00010469523679752043, -0.00013314793953006897, -0.000162768454945227,
      -0.00019353738839137703, -0.00022543180247259066, -0.00025842685064345083,
      -0.00029249322153853037, -0.0003275969002230937, -0.00036369812880990895,
      -0.00040075311959138096, -0.00043871410825289378, -0.0004775299541017313,
      -0.00051714506786268834, -0.00055749948194660311, -0.0005985284762121953,
      -0.00064016314932518548, -0.00068233032889953812, -0.00072495285493750128,
      -0.00076794940565669213, -0.00081123449550744918, -0.000854718104730997,
      -0.000898305302514217, -0.00094189611584824908, -0.00098538581197874365,
      -0.0010286658354898472, -0.0010716244381189705, -0.0011141472869809054,
      -0.0011561170824518239, -0.0011974136554612747, -0.001237913380560225,
      -0.0012774894635837249, -0.0013160110068272338, -0.0013533433272491574,
      -0.0013893474926047729, -0.0014238823192146298, -0.0014568049451663821,
      -0.0014879730918176894, -0.0015172441146064559, -0.0015444761904559864,
      -0.0015695257026329542, -0.0015922475982409492, -0.0016124909803227287,
      -0.0016301016574467144, -0.0016449223491324335, -0.0016568039473378266,
      -0.001665605215723748, -0.0016711966322400813, -0.0016734389811926525,
      -0.0016721839885763569, -0.0016672520346337682, -0.0016584921420413859,
      -0.0016458316690858581, -0.0016292065374362342, -0.0016082336044851697,
      -0.0015830547847863353, -0.0015533986824448824, -0.0015191942856493516,
      -0.001480321714734497, -0.0014366747516213465, -0.0013881463058498266,
      -0.0013346429364187052, -0.0012760724367214585, -0.0012123510241319134,
      -0.00114339915299231, -0.001069147200095676, -0.00098953138177162612,
      -0.00090449614434139612, -0.00081399193287174125, -0.0007179784404777866,
      -0.00061642339091594258, -0.00050930387184473574, -0.00039660454360111887,
      -0.00027831906613305293, -0.00015444978951794773, -2.5009136950533529E-5,
      0.00010998128759248985, 0.00025049024876638772, 0.00039647733434542537,
      0.000547892004859089, 0.00070467381552230318, 0.0008667522547157031,
      0.0010340473362282887, 0.0012064692614217184, 0.0013839182042043709,
      0.0015662839425239477, 0.0017534462254432362, 0.0019452752778846673,
      0.0021416320277640568, 0.0023423679159138271, 0.0025473244308335105,
      0.0027563334126815527, 0.0029692174766648063, 0.0031857908977416674,
      0.0034058592789826111, 0.003629219584039927, 0.0038556595994972682,
      0.0040849591778385451, 0.0043168905099427932, 0.0045512192444363241,
      0.0047877033383530365, 0.0050260939097900312, 0.0052661348051891424,
      0.0055075650412774579, 0.0057501178134741933, 0.005993521875884646,
      0.0062374992776029065, 0.0064817687140088613, 0.0067260442189588836,
      0.0069700391489500293, 0.0072134610329785652, 0.0074560162941989631,
      0.0076974052181521353, 0.0079373338780740939, 0.0081755016961620464,
      0.0084116155283035579, 0.0086453510715087, 0.0088764633941317214,
      0.0091045858166609317, 0.00932947119170265, 0.0095508239532603109,
      0.009768331126818023, 0.00998170512146345, 0.01019068419732715,
      0.010394978661914429, 0.010594309500177833, 0.010788401912287988,
      0.010976997573503348, 0.011159841635139072, 0.011336684594774141,
      0.011507278421377061, 0.011671384862653294, 0.011828775524625107,
      0.011979234128597992, 0.012122551816643054, 0.012258527623562759,
      0.01238696776693559, 0.012507689212506383, 0.012620520085780296,
      0.012725301170642304, 0.012821884672799546, 0.012910134590497779,
      0.012989925684588328, 0.013061143950197361, 0.013123686319966686,
      0.013177461836123134, 0.013222392215965335, 0.013258412833756951,
      0.013285472509235959, 0.013303533316260822, 0.013312570020168075,
      0.013312570020168075, 0.013303533316260822, 0.013285472509235959,
      0.013258412833756951, 0.013222392215965335, 0.013177461836123134,
      0.013123686319966686, 0.013061143950197361, 0.012989925684588328,
      0.012910134590497779, 0.012821884672799546, 0.012725301170642304,
      0.012620520085780296, 0.012507689212506383, 0.01238696776693559,
      0.012258527623562759, 0.012122551816643054, 0.011979234128597992,
      0.011828775524625107, 0.011671384862653294, 0.011507278421377061,
      0.011336684594774141, 0.011159841635139072, 0.010976997573503348,
      0.010788401912287988, 0.010594309500177833, 0.010394978661914429,
      0.01019068419732715, 0.00998170512146345, 0.009768331126818023,
      0.0095508239532603109, 0.00932947119170265, 0.0091045858166609317,
      0.0088764633941317214, 0.0086453510715087, 0.0084116155283035579,
      0.0081755016961620464, 0.0079373338780740939, 0.0076974052181521353,
      0.0074560162941989631, 0.0072134610329785652, 0.0069700391489500293,
      0.0067260442189588836, 0.0064817687140088613, 0.0062374992776029065,
      0.005993521875884646, 0.0057501178134741933, 0.0055075650412774579,
      0.0052661348051891424, 0.0050260939097900312, 0.0047877033383530365,
      0.0045512192444363241, 0.0043168905099427932, 0.0040849591778385451,
      0.0038556595994972682, 0.003629219584039927, 0.0034058592789826111,
      0.0031857908977416674, 0.0029692174766648063, 0.0027563334126815527,
      0.0025473244308335105, 0.0023423679159138271, 0.0021416320277640568,
      0.0019452752778846673, 0.0017534462254432362, 0.0015662839425239477,
      0.0013839182042043709, 0.0012064692614217184, 0.0010340473362282887,
      0.0008667522547157031, 0.00070467381552230318, 0.000547892004859089,
      0.00039647733434542537, 0.00025049024876638772, 0.00010998128759248985,
      -2.5009136950533529E-5, -0.00015444978951794773, -0.00027831906613305293,
      -0.00039660454360111887, -0.00050930387184473574, -0.00061642339091594258,
      -0.0007179784404777866, -0.00081399193287174125, -0.00090449614434139612,
      -0.00098953138177162612, -0.001069147200095676, -0.00114339915299231,
      -0.0012123510241319134, -0.0012760724367214585, -0.0013346429364187052,
      -0.0013881463058498266, -0.0014366747516213465, -0.001480321714734497,
      -0.0015191942856493516, -0.0015533986824448824, -0.0015830547847863353,
      -0.0016082336044851697, -0.0016292065374362342, -0.0016458316690858581,
      -0.0016584921420413859, -0.0016672520346337682, -0.0016721839885763569,
      -0.0016734389811926525, -0.0016711966322400813, -0.001665605215723748,
      -0.0016568039473378266, -0.0016449223491324335, -0.0016301016574467144,
      -0.0016124909803227287, -0.0015922475982409492, -0.0015695257026329542,
      -0.0015444761904559864, -0.0015172441146064559, -0.0014879730918176894,
      -0.0014568049451663821, -0.0014238823192146298, -0.0013893474926047729,
      -0.0013533433272491574, -0.0013160110068272338, -0.0012774894635837249,
      -0.001237913380560225, -0.0011974136554612747, -0.0011561170824518239,
      -0.0011141472869809054, -0.0010716244381189705, -0.0010286658354898472,
      -0.00098538581197874365, -0.00094189611584824908, -0.000898305302514217,
      -0.000854718104730997, -0.00081123449550744918, -0.00076794940565669213,
      -0.00072495285493750128, -0.00068233032889953812, -0.00064016314932518548,
      -0.0005985284762121953, -0.00055749948194660311, -0.00051714506786268834,
      -0.0004775299541017313, -0.00043871410825289378, -0.00040075311959138096,
      -0.00036369812880990895, -0.0003275969002230937, -0.00029249322153853037,
      -0.00025842685064345083, -0.00022543180247259066, -0.00019353738839137703,
      -0.000162768454945227, -0.00013314793953006897, -0.00010469523679752043,
      -7.7426282343867633E-5, -5.1350588682011877E-5, -2.6474712200137892E-5,
      -2.8019217615462844E-6, 1.9663684154742737E-5, 4.09232815403084E-5,
      6.0980849567570254E-5, 7.9849051074803946E-5, 9.7536399475715374E-5,
      0.00011405635998179952, 0.00012941267085404674, 0.0001436439873885048,
      0.00015675948555891723, 0.0001687760125197001, 0.000179724458518688,
      0.00018963988212175795, 0.00019852378123413881, 0.00020643401298153785,
      0.00021338340530728151, 0.00021940724994144853, 0.00022453646965557317,
      0.00022880814947703811, 0.00023225334089643524, 0.00023490649079537261,
      0.0002368014477743279, 0.00023797562916387987, 0.00023846449130310576,
      0.00023830380105764755, 0.00023752801552727001, 0.00023617355970067616,
      0.00023427677071234941, 0.00023187420109533583, 0.00022900046335732723,
      0.00022568985647915653, 0.00022197624012000391, 0.00021789406614495019,
      0.00021347680147375473, 0.00020875680273691963, 0.00020376474010966116,
      0.00019853075546223968, 0.00019308447130551325, 0.00018745512239541989,
      0.00018167064726000209, 0.000175757620655289, 0.00016974124601889726,
      0.00016364586283160789, 0.00015749495882783288, 0.00015131101775082962,
      0.00014511530919185411, 0.00013892783145253441, 0.00013276751787639124,
      0.00012665207866046694, 0.00012059807486813235, 0.00011462064266438507,
      0.00010873402878706212, 0.00010295143782818293, 9.7285364241223081E-5,
      9.1746660711168813E-5, 8.6344905367853562E-5, 8.1088023577758283E-5,
      7.598366176848507E-5, 7.1038491716511035E-5, 6.6258903044584032E-5,
      6.1649433006808312E-5, 5.7214303343971881E-5, 5.2956254246761535E-5,
      4.887839286743438E-5, 4.498145402769874E-5, 4.1266227979697194E-5,
      3.7731241746168895E-5, 3.437744745554658E-5, 3.1202978526585671E-5,
      2.8207726984584141E-5, 2.5385728845885136E-5, 2.2739020488131543E-5,
      2.0260874194992456E-5, 1.7947540861151679E-5, 1.5795816232593139E-5,
      5.6767778271866516E-5 };

    /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

    /* S-Function Block: drivepoint_QCar/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("qcar", "0", &drivepoint_QCar_DW.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
        return;
      }

      is_switching = false;
      result = hil_set_card_specific_options
        (drivepoint_QCar_DW.HILInitialize_Card,
         "gyro_fs=250;gyro_rate=64;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
         251);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
        return;
      }

      result = hil_watchdog_clear(drivepoint_QCar_DW.HILInitialize_Card);
      if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
        return;
      }

      if ((drivepoint_QCar_P.HILInitialize_AIPStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_AIPEnter && is_switching)) {
        {
          int_T i1;
          real_T *dw_AIMinimums = &drivepoint_QCar_DW.HILInitialize_AIMinimums[0];
          for (i1=0; i1 < 7; i1++) {
            dw_AIMinimums[i1] = drivepoint_QCar_P.HILInitialize_AILow;
          }
        }

        {
          int_T i1;
          real_T *dw_AIMaximums = &drivepoint_QCar_DW.HILInitialize_AIMaximums[0];
          for (i1=0; i1 < 7; i1++) {
            dw_AIMaximums[i1] = drivepoint_QCar_P.HILInitialize_AIHigh;
          }
        }

        result = hil_set_analog_input_ranges
          (drivepoint_QCar_DW.HILInitialize_Card,
           drivepoint_QCar_P.HILInitialize_AIChannels, 7U,
           &drivepoint_QCar_DW.HILInitialize_AIMinimums[0],
           &drivepoint_QCar_DW.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_digital_directions(drivepoint_QCar_DW.HILInitialize_Card,
        drivepoint_QCar_P.HILInitialize_DIChannels, 20U,
        &drivepoint_QCar_P.HILInitialize_DOChannels, 1U);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
        return;
      }

      if ((drivepoint_QCar_P.HILInitialize_DOStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_DOEnter && is_switching)) {
        result = hil_write_digital(drivepoint_QCar_DW.HILInitialize_Card,
          &drivepoint_QCar_P.HILInitialize_DOChannels, 1U, (t_boolean *)
          &drivepoint_QCar_P.HILInitialize_DOInitial);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      if ((drivepoint_QCar_P.HILInitialize_EIPStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_EIPEnter && is_switching)) {
        drivepoint_QCar_DW.HILInitialize_QuadratureModes[0] =
          (drivepoint_QCar_P.HILInitialize_EIQuadrature[0]);
        drivepoint_QCar_DW.HILInitialize_QuadratureModes[1] =
          (drivepoint_QCar_P.HILInitialize_EIQuadrature[1]);
        drivepoint_QCar_DW.HILInitialize_QuadratureModes[2] =
          (drivepoint_QCar_P.HILInitialize_EIQuadrature[1]);
        drivepoint_QCar_DW.HILInitialize_QuadratureModes[3] =
          (drivepoint_QCar_P.HILInitialize_EIQuadrature[1]);
        drivepoint_QCar_DW.HILInitialize_QuadratureModes[4] =
          (drivepoint_QCar_P.HILInitialize_EIQuadrature[1]);
        result = hil_set_encoder_quadrature_mode
          (drivepoint_QCar_DW.HILInitialize_Card,
           drivepoint_QCar_P.HILInitialize_EIChannels, 5U,
           (t_encoder_quadrature_mode *)
           &drivepoint_QCar_DW.HILInitialize_QuadratureModes[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }

        {
          int_T i1;
          real_T *dw_FilterFrequency =
            &drivepoint_QCar_DW.HILInitialize_FilterFrequency[0];
          for (i1=0; i1 < 5; i1++) {
            dw_FilterFrequency[i1] = drivepoint_QCar_P.HILInitialize_EIFrequency;
          }
        }

        result = hil_set_encoder_filter_frequency
          (drivepoint_QCar_DW.HILInitialize_Card,
           drivepoint_QCar_P.HILInitialize_EIChannels, 5U,
           &drivepoint_QCar_DW.HILInitialize_FilterFrequency[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      if ((drivepoint_QCar_P.HILInitialize_EIStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_EIEnter && is_switching)) {
        {
          int_T i1;
          int32_T *dw_InitialEICounts =
            &drivepoint_QCar_DW.HILInitialize_InitialEICounts[0];
          for (i1=0; i1 < 5; i1++) {
            dw_InitialEICounts[i1] = drivepoint_QCar_P.HILInitialize_EIInitial;
          }
        }

        result = hil_set_encoder_counts(drivepoint_QCar_DW.HILInitialize_Card,
          drivepoint_QCar_P.HILInitialize_EIChannels, 5U,
          &drivepoint_QCar_DW.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      if ((drivepoint_QCar_P.HILInitialize_POPStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_POPEnter && is_switching)) {
        uint32_T num_duty_cycle_modes = 0;
        uint32_T num_frequency_modes = 0;
        drivepoint_QCar_DW.HILInitialize_POModeValues[0] =
          (drivepoint_QCar_P.HILInitialize_POModes[0]);

        {
          int_T i1;
          int32_T *dw_POModeValues =
            &drivepoint_QCar_DW.HILInitialize_POModeValues[1];
          for (i1=0; i1 < 7; i1++) {
            dw_POModeValues[i1] = (drivepoint_QCar_P.HILInitialize_POModes[1]);
          }
        }

        result = hil_set_pwm_mode(drivepoint_QCar_DW.HILInitialize_Card,
          drivepoint_QCar_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
          &drivepoint_QCar_DW.HILInitialize_POModeValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }

        {
          int_T i1;
          const uint32_T *p_HILInitialize_POChannels =
            drivepoint_QCar_P.HILInitialize_POChannels;
          int32_T *dw_POModeValues =
            &drivepoint_QCar_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 8; i1++) {
            if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1]
                == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
                dw_POModeValues[i1] == PWM_RAW_MODE) {
              drivepoint_QCar_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
                = (p_HILInitialize_POChannels[i1]);
              drivepoint_QCar_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
                = drivepoint_QCar_P.HILInitialize_POFrequency;
              num_duty_cycle_modes++;
            } else {
              drivepoint_QCar_DW.HILInitialize_POSortedChans[7U -
                num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
              drivepoint_QCar_DW.HILInitialize_POSortedFreqs[7U -
                num_frequency_modes] =
                drivepoint_QCar_P.HILInitialize_POFrequency;
              num_frequency_modes++;
            }
          }
        }

        if (num_duty_cycle_modes > 0) {
          result = hil_set_pwm_frequency(drivepoint_QCar_DW.HILInitialize_Card,
            &drivepoint_QCar_DW.HILInitialize_POSortedChans[0],
            num_duty_cycle_modes,
            &drivepoint_QCar_DW.HILInitialize_POSortedFreqs[0]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
            return;
          }
        }

        if (num_frequency_modes > 0) {
          result = hil_set_pwm_duty_cycle(drivepoint_QCar_DW.HILInitialize_Card,
            &drivepoint_QCar_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
            num_frequency_modes,
            &drivepoint_QCar_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
            return;
          }
        }

        {
          int_T i1;
          int32_T *dw_POModeValues =
            &drivepoint_QCar_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POModeValues[i1] =
              drivepoint_QCar_P.HILInitialize_POConfiguration;
          }
        }

        {
          int_T i1;
          int32_T *dw_POAlignValues =
            &drivepoint_QCar_DW.HILInitialize_POAlignValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POAlignValues[i1] = drivepoint_QCar_P.HILInitialize_POAlignment;
          }
        }

        {
          int_T i1;
          int32_T *dw_POPolarityVals =
            &drivepoint_QCar_DW.HILInitialize_POPolarityVals[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POPolarityVals[i1] = drivepoint_QCar_P.HILInitialize_POPolarity;
          }
        }

        result = hil_set_pwm_configuration(drivepoint_QCar_DW.HILInitialize_Card,
          drivepoint_QCar_P.HILInitialize_POChannels, 8U,
          (t_pwm_configuration *)
          &drivepoint_QCar_DW.HILInitialize_POModeValues[0],
          (t_pwm_alignment *) &drivepoint_QCar_DW.HILInitialize_POAlignValues[0],
          (t_pwm_polarity *) &drivepoint_QCar_DW.HILInitialize_POPolarityVals[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      if ((drivepoint_QCar_P.HILInitialize_POStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_POEnter && is_switching)) {
        {
          int_T i1;
          real_T *dw_POValues = &drivepoint_QCar_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POValues[i1] = drivepoint_QCar_P.HILInitialize_POInitial;
          }
        }

        result = hil_write_pwm(drivepoint_QCar_DW.HILInitialize_Card,
          drivepoint_QCar_P.HILInitialize_POChannels, 8U,
          &drivepoint_QCar_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      if (drivepoint_QCar_P.HILInitialize_POReset) {
        {
          int_T i1;
          real_T *dw_POValues = &drivepoint_QCar_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 8; i1++) {
            dw_POValues[i1] = drivepoint_QCar_P.HILInitialize_POWatchdog;
          }
        }

        result = hil_watchdog_set_pwm_expiration_state
          (drivepoint_QCar_DW.HILInitialize_Card,
           drivepoint_QCar_P.HILInitialize_POChannels, 8U,
           &drivepoint_QCar_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }

      if ((drivepoint_QCar_P.HILInitialize_OOStart && !is_switching) ||
          (drivepoint_QCar_P.HILInitialize_OOEnter && is_switching)) {
        {
          int_T i1;
          real_T *dw_OOValues = &drivepoint_QCar_DW.HILInitialize_OOValues[0];
          for (i1=0; i1 < 13; i1++) {
            dw_OOValues[i1] = drivepoint_QCar_P.HILInitialize_OOInitial;
          }
        }

        result = hil_write_other(drivepoint_QCar_DW.HILInitialize_Card,
          drivepoint_QCar_P.HILInitialize_OOChannels, 13U,
          &drivepoint_QCar_DW.HILInitialize_OOValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
          return;
        }
      }
    }

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    drivepoint_QCar_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    drivepoint_QCar_DW.obj.matlabCodegenIsDeleted = true;
    drivepoint_QCar_DW.obj.isInitialized = 0;
    drivepoint_QCar_DW.obj.NumChannels = -1;
    drivepoint_QCar_DW.obj.matlabCodegenIsDeleted = false;
    drivepoint_QCar_DW.objisempty = true;
    drivepoint_QCar_DW.obj.isSetupComplete = false;
    drivepoint_QCar_DW.obj.isInitialized = 1;
    iobj_0 = &drivepoint_QCar_DW.obj._pobj0;
    iobj_0->isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 458; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    drivepoint_QCar_DW.obj.FilterObj = iobj_0;
    drivepoint_QCar_DW.obj.NumChannels = 1;
    drivepoint_QCar_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter' */

    /* Start for S-Function (inverse_modulus_block): '<Root>/Unwrap 2^24' */

    /* S-Function Block: drivepoint_QCar/Unwrap 2^24 (inverse_modulus_block) */
    {
      drivepoint_QCar_DW.Unwrap224_FirstSample = true;
      drivepoint_QCar_DW.Unwrap224_Revolutions = 0;
    }
  }

  drivepoint_QCar_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    b_dspcodegen_FIRFilter_drivep_T *obj;
    int32_T i;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    drivepoint_QCar_X.Integrator_CSTATE = drivepoint_QCar_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    drivepoint_QCar_X.Integrator_CSTATE_l[0] = drivepoint_QCar_P.x0[0];
    drivepoint_QCar_X.Integrator_CSTATE_l[1] = drivepoint_QCar_P.x0[1];
    drivepoint_QCar_X.Integrator_CSTATE_l[2] = drivepoint_QCar_P.x0[2];

    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    drivepoint_QCar_X.Integrator2_CSTATE = drivepoint_QCar_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S7>/Integrator1' */
    drivepoint_QCar_X.Integrator1_CSTATE = drivepoint_QCar_P.Integrator1_IC;

    /* InitializeConditions for RateLimiter: '<S1>/acceleration limit' */
    drivepoint_QCar_DW.LastMajorTimeA = (rtInf);
    drivepoint_QCar_DW.LastMajorTimeB = (rtInf);

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    if (rtmIsFirstInitCond(drivepoint_QCar_M)) {
      drivepoint_QCar_X.Integrator1_CSTATE_e = 0.0;
    }

    drivepoint_QCar_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S3>/Integrator1' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    obj = drivepoint_QCar_DW.obj.FilterObj;
    if (obj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 457; i++) {
        obj->cSFunObject.W0_states[i] = obj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(drivepoint_QCar_M)) {
      rtmSetFirstInitCond(drivepoint_QCar_M, 0);
    }
  }
}

/* Model terminate function */
void drivepoint_QCar_terminate(void)
{
  b_dspcodegen_FIRFilter_drivep_T *obj;

  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: drivepoint_QCar/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(drivepoint_QCar_DW.HILInitialize_Card);
    hil_monitor_stop_all(drivepoint_QCar_DW.HILInitialize_Card);
    is_switching = false;
    if ((drivepoint_QCar_P.HILInitialize_DOTerminate && !is_switching) ||
        (drivepoint_QCar_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((drivepoint_QCar_P.HILInitialize_POTerminate && !is_switching) ||
        (drivepoint_QCar_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &drivepoint_QCar_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = drivepoint_QCar_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((drivepoint_QCar_P.HILInitialize_OOTerminate && !is_switching) ||
        (drivepoint_QCar_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &drivepoint_QCar_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = drivepoint_QCar_P.HILInitialize_OOFinal;
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
      result = hil_write(drivepoint_QCar_DW.HILInitialize_Card
                         , NULL, 0
                         , drivepoint_QCar_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &drivepoint_QCar_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , drivepoint_QCar_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &drivepoint_QCar_DW.HILInitialize_POValues[0]
                         , (t_boolean *)
                         &drivepoint_QCar_P.HILInitialize_DOFinal
                         , &drivepoint_QCar_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(drivepoint_QCar_DW.HILInitialize_Card,
            drivepoint_QCar_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &drivepoint_QCar_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(drivepoint_QCar_DW.HILInitialize_Card,
            &drivepoint_QCar_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &drivepoint_QCar_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(drivepoint_QCar_DW.HILInitialize_Card,
            drivepoint_QCar_P.HILInitialize_OOChannels, num_final_other_outputs,
            &drivepoint_QCar_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(drivepoint_QCar_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(drivepoint_QCar_DW.HILInitialize_Card);
    hil_monitor_delete_all(drivepoint_QCar_DW.HILInitialize_Card);
    hil_close(drivepoint_QCar_DW.HILInitialize_Card);
    drivepoint_QCar_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  if (!drivepoint_QCar_DW.obj.matlabCodegenIsDeleted) {
    drivepoint_QCar_DW.obj.matlabCodegenIsDeleted = true;
    if ((drivepoint_QCar_DW.obj.isInitialized == 1) &&
        drivepoint_QCar_DW.obj.isSetupComplete) {
      obj = drivepoint_QCar_DW.obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      drivepoint_QCar_DW.obj.NumChannels = -1;
    }
  }

  obj = &drivepoint_QCar_DW.obj._pobj0;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
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
  drivepoint_QCar_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  drivepoint_QCar_update();
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
  drivepoint_QCar_initialize();
}

void MdlTerminate(void)
{
  drivepoint_QCar_terminate();
}

/* Registration function */
RT_MODEL_drivepoint_QCar_T *drivepoint_QCar(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)drivepoint_QCar_M, 0,
                sizeof(RT_MODEL_drivepoint_QCar_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&drivepoint_QCar_M->solverInfo,
                          &drivepoint_QCar_M->Timing.simTimeStep);
    rtsiSetTPtr(&drivepoint_QCar_M->solverInfo, &rtmGetTPtr(drivepoint_QCar_M));
    rtsiSetStepSizePtr(&drivepoint_QCar_M->solverInfo,
                       &drivepoint_QCar_M->Timing.stepSize0);
    rtsiSetdXPtr(&drivepoint_QCar_M->solverInfo, &drivepoint_QCar_M->derivs);
    rtsiSetContStatesPtr(&drivepoint_QCar_M->solverInfo, (real_T **)
                         &drivepoint_QCar_M->contStates);
    rtsiSetNumContStatesPtr(&drivepoint_QCar_M->solverInfo,
      &drivepoint_QCar_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&drivepoint_QCar_M->solverInfo,
      &drivepoint_QCar_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&drivepoint_QCar_M->solverInfo,
      &drivepoint_QCar_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&drivepoint_QCar_M->solverInfo,
      &drivepoint_QCar_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&drivepoint_QCar_M->solverInfo, (&rtmGetErrorStatus
      (drivepoint_QCar_M)));
    rtsiSetRTModelPtr(&drivepoint_QCar_M->solverInfo, drivepoint_QCar_M);
  }

  rtsiSetSimTimeStep(&drivepoint_QCar_M->solverInfo, MAJOR_TIME_STEP);
  drivepoint_QCar_M->intgData.x0 = drivepoint_QCar_M->odeX0;
  drivepoint_QCar_M->intgData.f0 = drivepoint_QCar_M->odeF0;
  drivepoint_QCar_M->intgData.x1start = drivepoint_QCar_M->odeX1START;
  drivepoint_QCar_M->intgData.f1 = drivepoint_QCar_M->odeF1;
  drivepoint_QCar_M->intgData.Delta = drivepoint_QCar_M->odeDELTA;
  drivepoint_QCar_M->intgData.E = drivepoint_QCar_M->odeE;
  drivepoint_QCar_M->intgData.fac = drivepoint_QCar_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = drivepoint_QCar_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(drivepoint_QCar_M->odeFAC)/sizeof(real_T)); i
         ++) {
      f[i] = 1.5e-8;
    }
  }

  drivepoint_QCar_M->intgData.DFDX = drivepoint_QCar_M->odeDFDX;
  drivepoint_QCar_M->intgData.W = drivepoint_QCar_M->odeW;
  drivepoint_QCar_M->intgData.pivots = drivepoint_QCar_M->odePIVOTS;
  drivepoint_QCar_M->intgData.xtmp = drivepoint_QCar_M->odeXTMP;
  drivepoint_QCar_M->intgData.ztmp = drivepoint_QCar_M->odeZTMP;
  drivepoint_QCar_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&drivepoint_QCar_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&drivepoint_QCar_M->solverInfo, 1);
  drivepoint_QCar_M->contStates = ((real_T *) &drivepoint_QCar_X);
  rtsiSetSolverData(&drivepoint_QCar_M->solverInfo, (void *)
                    &drivepoint_QCar_M->intgData);
  rtsiSetSolverName(&drivepoint_QCar_M->solverInfo,"ode14x");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = drivepoint_QCar_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    drivepoint_QCar_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    drivepoint_QCar_M->Timing.sampleTimes =
      (&drivepoint_QCar_M->Timing.sampleTimesArray[0]);
    drivepoint_QCar_M->Timing.offsetTimes =
      (&drivepoint_QCar_M->Timing.offsetTimesArray[0]);

    /* task periods */
    drivepoint_QCar_M->Timing.sampleTimes[0] = (0.0);
    drivepoint_QCar_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    drivepoint_QCar_M->Timing.offsetTimes[0] = (0.0);
    drivepoint_QCar_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(drivepoint_QCar_M, &drivepoint_QCar_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = drivepoint_QCar_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    drivepoint_QCar_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(drivepoint_QCar_M, -1);
  drivepoint_QCar_M->Timing.stepSize0 = 0.002;
  drivepoint_QCar_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(drivepoint_QCar_M, 1);

  /* External mode info */
  drivepoint_QCar_M->Sizes.checksums[0] = (1887622831U);
  drivepoint_QCar_M->Sizes.checksums[1] = (1808056908U);
  drivepoint_QCar_M->Sizes.checksums[2] = (704291663U);
  drivepoint_QCar_M->Sizes.checksums[3] = (2045435848U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    drivepoint_QCar_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(drivepoint_QCar_M->extModeInfo,
      &drivepoint_QCar_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(drivepoint_QCar_M->extModeInfo,
                        drivepoint_QCar_M->Sizes.checksums);
    rteiSetTPtr(drivepoint_QCar_M->extModeInfo, rtmGetTPtr(drivepoint_QCar_M));
  }

  drivepoint_QCar_M->solverInfoPtr = (&drivepoint_QCar_M->solverInfo);
  drivepoint_QCar_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&drivepoint_QCar_M->solverInfo, 0.002);
  rtsiSetSolverMode(&drivepoint_QCar_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  drivepoint_QCar_M->blockIO = ((void *) &drivepoint_QCar_B);
  (void) memset(((void *) &drivepoint_QCar_B), 0,
                sizeof(B_drivepoint_QCar_T));

  /* parameters */
  drivepoint_QCar_M->defaultParam = ((real_T *)&drivepoint_QCar_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &drivepoint_QCar_X;
    drivepoint_QCar_M->contStates = (x);
    (void) memset((void *)&drivepoint_QCar_X, 0,
                  sizeof(X_drivepoint_QCar_T));
  }

  /* states (dwork) */
  drivepoint_QCar_M->dwork = ((void *) &drivepoint_QCar_DW);
  (void) memset((void *)&drivepoint_QCar_DW, 0,
                sizeof(DW_drivepoint_QCar_T));

  /* external outputs */
  drivepoint_QCar_M->outputs = (&drivepoint_QCar_Y);
  drivepoint_QCar_Y.theta = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    drivepoint_QCar_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  drivepoint_QCar_M->Sizes.numContStates = (7);/* Number of continuous states */
  drivepoint_QCar_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  drivepoint_QCar_M->Sizes.numY = (1); /* Number of model outputs */
  drivepoint_QCar_M->Sizes.numU = (0); /* Number of model inputs */
  drivepoint_QCar_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  drivepoint_QCar_M->Sizes.numSampTimes = (2);/* Number of sample times */
  drivepoint_QCar_M->Sizes.numBlocks = (71);/* Number of blocks */
  drivepoint_QCar_M->Sizes.numBlockIO = (36);/* Number of block outputs */
  drivepoint_QCar_M->Sizes.numBlockPrms = (157);/* Sum of parameter "widths" */
  return drivepoint_QCar_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
