/*
 * Autonomous_Driving.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Autonomous_Driving".
 *
 * Model version              : 5.1
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 17:08:15 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Autonomous_Driving.h"
#include "Autonomous_Driving_private.h"
#include "Autonomous_Driving_dt.h"
#define Autonomous_Driving_period      (0.0016666666666666668)

/* Block signals (default storage) */
B_Autonomous_Driving_T Autonomous_Driving_B;

/* Continuous states */
X_Autonomous_Driving_T Autonomous_Driving_X;

/* Block states (default storage) */
DW_Autonomous_Driving_T Autonomous_Driving_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Autonomous_Driving_T Autonomous_Driving_PrevZCX;

/* Real-time model */
static RT_MODEL_Autonomous_Driving_T Autonomous_Driving_M_;
RT_MODEL_Autonomous_Driving_T *const Autonomous_Driving_M =
  &Autonomous_Driving_M_;

/* Forward declaration for local functions */
static void Autonomous_Drivi_emxInit_real_T(emxArray_real_T_Autonomous_Dr_T
  **pEmxArray, int32_T numDimensions);
static void Autono_emxEnsureCapacity_real_T(emxArray_real_T_Autonomous_Dr_T
  *emxArray, int32_T oldNumel);
static void Autonomous_Driv_eml_float_colon(real_T a,
  emxArray_real_T_Autonomous_Dr_T *y);
static void Autonomous_Drivi_emxFree_real_T(emxArray_real_T_Autonomous_Dr_T
  **pEmxArray);
static void Autonomous_Driv_emxInit_real_T1(emxArray_real_T_Autonomous_Dr_T
  **pEmxArray, int32_T numDimensions);
static void Autonomous_Driv_emxInit_int32_T(emxArray_int32_T_Autonomous_D_T
  **pEmxArray, int32_T numDimensions);
static void Auton_emxEnsureCapacity_int32_T(emxArray_int32_T_Autonomous_D_T
  *emxArray, int32_T oldNumel);
static void Autonomous_Driving_eml_find(const boolean_T x_data[], const int32_T
  x_size[2], emxArray_int32_T_Autonomous_D_T *i, emxArray_int32_T_Autonomous_D_T
  *j);
static void Auton_emxEnsureCapacity_real_T1(emxArray_real_T_Autonomous_Dr_T
  *emxArray, int32_T oldNumel);
static void Autonomous_Driv_emxFree_int32_T(emxArray_int32_T_Autonomous_D_T
  **pEmxArray);
static real_T Autonomous_Driving_xnrm2(int32_T n, const
  emxArray_real_T_Autonomous_Dr_T *x, int32_T ix0);
static void Autonomous_Driving_xswap(int32_T n, emxArray_real_T_Autonomous_Dr_T *
  x, int32_T ix0, int32_T iy0);
static void Autonomous_Driving_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T
  tau, emxArray_real_T_Autonomous_Dr_T *C, int32_T ic0, int32_T ldc, real_T
  work[2]);
static void Autonomous_Driving_qrpf(emxArray_real_T_Autonomous_Dr_T *A, int32_T
  m, real_T tau_data[], int32_T jpvt[2]);
static void Autonomous_Driving_xgeqp3(emxArray_real_T_Autonomous_Dr_T *A, real_T
  tau_data[], int32_T *tau_size, int32_T jpvt[2]);
static void Autonomous_Driving_qrsolve(const emxArray_real_T_Autonomous_Dr_T *A,
  const emxArray_real_T_Autonomous_Dr_T *B, real_T Y[2], int32_T *rankA);
static void Autonomous_Driving_polyfit(const emxArray_real_T_Autonomous_Dr_T *x,
  const emxArray_real_T_Autonomous_Dr_T *y, real_T p[2]);
static void Autonomous_Driving_linspace(real_T d1, real_T d2, real_T n,
  emxArray_real_T_Autonomous_Dr_T *y);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Autonomous_Driving_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Autonomous_Driving_M, 2);
  rtmSampleHitPtr[3] = rtmStepTask(Autonomous_Driving_M, 3);
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (Autonomous_Driving_M->Timing.TaskCounters.TID[1] == 0) {
    Autonomous_Driving_M->Timing.RateInteraction.TID1_2 =
      (Autonomous_Driving_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Autonomous_Driving_M->Timing.perTaskSampleHits[6] =
      Autonomous_Driving_M->Timing.RateInteraction.TID1_2;
    Autonomous_Driving_M->Timing.RateInteraction.TID1_3 =
      (Autonomous_Driving_M->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Autonomous_Driving_M->Timing.perTaskSampleHits[7] =
      Autonomous_Driving_M->Timing.RateInteraction.TID1_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Autonomous_Driving_M->Timing.TaskCounters.TID[2])++;
  if ((Autonomous_Driving_M->Timing.TaskCounters.TID[2]) > 4) {
                               /* Sample time: [0.0083333333333333332s, 0.0s] */
    Autonomous_Driving_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Autonomous_Driving_M->Timing.TaskCounters.TID[3])++;
  if ((Autonomous_Driving_M->Timing.TaskCounters.TID[3]) > 5) {/* Sample time: [0.01s, 0.0s] */
    Autonomous_Driving_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * This function updates continuous states using the ODE2 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE2_IntgData *id = (ODE2_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T temp;
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Autonomous_Driving_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  Autonomous_Driving_output0();
  Autonomous_Driving_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
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

static void Autonomous_Drivi_emxInit_real_T(emxArray_real_T_Autonomous_Dr_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_Autonomous_Dr_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Autonomous_Dr_T *)malloc(sizeof
    (emxArray_real_T_Autonomous_Dr_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Autono_emxEnsureCapacity_real_T(emxArray_real_T_Autonomous_Dr_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S19>/Combine images' */
static void Autonomous_Driv_eml_float_colon(real_T a,
  emxArray_real_T_Autonomous_Dr_T *y)
{
  real_T apnd;
  real_T ndbl;
  int32_T k;
  int32_T n;
  int32_T nm1d2;
  ndbl = floor((137.0 - a) + 0.5);
  apnd = a + ndbl;
  if (fabs(apnd - 137.0) < 4.4408920985006262E-16 * fmax(fabs(a), 137.0)) {
    ndbl++;
    apnd = 137.0;
  } else if (apnd - 137.0 > 0.0) {
    apnd = (ndbl - 1.0) + a;
  } else {
    ndbl++;
  }

  if (ndbl >= 0.0) {
    n = (int32_T)ndbl - 1;
  } else {
    n = -1;
  }

  nm1d2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n + 1;
  Autono_emxEnsureCapacity_real_T(y, nm1d2);
  if (n + 1 > 0) {
    y->data[0] = a;
    if (n + 1 > 1) {
      y->data[n] = apnd;
      nm1d2 = n / 2;
      for (k = 1; k - 1 <= nm1d2 - 2; k++) {
        y->data[k] = a + (real_T)k;
        y->data[n - k] = apnd - (real_T)k;
      }

      if (nm1d2 << 1 == n) {
        y->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        y->data[nm1d2] = a + (real_T)nm1d2;
        y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }
}

static void Autonomous_Drivi_emxFree_real_T(emxArray_real_T_Autonomous_Dr_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Autonomous_Dr_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Autonomous_Dr_T *)NULL;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void Autonomous_Driv_emxInit_real_T1(emxArray_real_T_Autonomous_Dr_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_Autonomous_Dr_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Autonomous_Dr_T *)malloc(sizeof
    (emxArray_real_T_Autonomous_Dr_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Autonomous_Driv_emxInit_int32_T(emxArray_int32_T_Autonomous_D_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T_Autonomous_D_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_Autonomous_D_T *)malloc(sizeof
    (emxArray_int32_T_Autonomous_D_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Auton_emxEnsureCapacity_int32_T(emxArray_int32_T_Autonomous_D_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_eml_find(const boolean_T x_data[], const int32_T
  x_size[2], emxArray_int32_T_Autonomous_D_T *i, emxArray_int32_T_Autonomous_D_T
  *j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  int32_T nx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  nx = x_size[0] * 273;
  if (nx == 0) {
    i->size[0] = 0;
    j->size[0] = 0;
  } else {
    idx = 0;
    ii = i->size[0];
    i->size[0] = nx;
    Auton_emxEnsureCapacity_int32_T(i, ii);
    ii = j->size[0];
    j->size[0] = nx;
    Auton_emxEnsureCapacity_int32_T(j, ii);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 273)) {
      guard1 = false;
      if (x_data[(ii + x_size[0] * (jj - 1)) - 1]) {
        idx++;
        i->data[idx - 1] = ii;
        j->data[idx - 1] = jj;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
        if (ii > x_size[0]) {
          ii = 1;
          jj++;
        }
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        i->size[0] = 0;
        j->size[0] = 0;
      }
    } else if (1 > idx) {
      i->size[0] = 0;
      j->size[0] = 0;
    } else {
      ii = i->size[0];
      i->size[0] = idx;
      Auton_emxEnsureCapacity_int32_T(i, ii);
      ii = j->size[0];
      j->size[0] = idx;
      Auton_emxEnsureCapacity_int32_T(j, ii);
    }
  }
}

static void Auton_emxEnsureCapacity_real_T1(emxArray_real_T_Autonomous_Dr_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void Autonomous_Driv_emxFree_int32_T(emxArray_int32_T_Autonomous_D_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_Autonomous_D_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_Autonomous_D_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static real_T Autonomous_Driving_xnrm2(int32_T n, const
  emxArray_real_T_Autonomous_Dr_T *x, int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x->data[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x->data[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_xswap(int32_T n, emxArray_real_T_Autonomous_Dr_T *
  x, int32_T ix0, int32_T iy0)
{
  real_T temp;
  int32_T ix;
  int32_T iy;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < n; k++) {
    temp = x->data[ix];
    x->data[ix] = x->data[iy];
    x->data[iy] = temp;
    ix++;
    iy++;
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T
  tau, emxArray_real_T_Autonomous_Dr_T *C, int32_T ic0, int32_T ldc, real_T
  work[2])
{
  real_T c;
  int32_T b_ix;
  int32_T exitg1;
  int32_T ia;
  int32_T ijA;
  int32_T ix;
  int32_T jA;
  int32_T jy;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      jA = ic0;
      do {
        exitg1 = 0;
        if (jA <= (ic0 + lastv) - 1) {
          if (C->data[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc = 0;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    if (lastc != 0) {
      work[0] = 0.0;
      jA = 0;
      jy = ic0;
      while (((ldc > 0) && (jy <= ic0)) || ((ldc < 0) && (jy >= ic0))) {
        ix = iv0;
        c = 0.0;
        b_ix = (jy + lastv) - 1;
        for (ia = jy; ia <= b_ix; ia++) {
          c += C->data[ia - 1] * C->data[ix - 1];
          ix++;
        }

        work[jA] += c;
        jA++;
        jy += ldc;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0 - 1;
      jy = 0;
      for (ix = 0; ix < lastc; ix++) {
        if (work[jy] != 0.0) {
          c = work[jy] * -tau;
          b_ix = iv0;
          ia = lastv + jA;
          for (ijA = jA; ijA < ia; ijA++) {
            C->data[ijA] += C->data[b_ix - 1] * c;
            b_ix++;
          }
        }

        jy++;
        jA += ldc;
      }
    }
  }
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_qrpf(emxArray_real_T_Autonomous_Dr_T *A, int32_T
  m, real_T tau_data[], int32_T jpvt[2])
{
  real_T vn1[2];
  real_T vn2[2];
  real_T work[2];
  real_T b_atmp;
  real_T beta1;
  int32_T c_k;
  int32_T ii;
  int32_T itemp;
  int32_T j;
  int32_T ma;
  int32_T minmn;
  int32_T mmi;
  int32_T pvt;
  ma = A->size[0];
  if (m < 2) {
    minmn = m;
  } else {
    minmn = 2;
  }

  work[0] = 0.0;
  b_atmp = Autonomous_Driving_xnrm2(m, A, 1);
  vn2[0] = b_atmp;
  vn1[0] = b_atmp;
  work[1] = 0.0;
  b_atmp = Autonomous_Driving_xnrm2(m, A, A->size[0] + 1);
  vn2[1] = b_atmp;
  vn1[1] = b_atmp;
  for (j = 0; j < minmn; j++) {
    ii = j * ma + j;
    mmi = m - j;
    pvt = 0;
    if ((2 - j > 1) && (fabs(vn1[1]) > fabs(vn1[j]))) {
      pvt = 1;
    }

    pvt += j;
    if (pvt + 1 != j + 1) {
      Autonomous_Driving_xswap(m, A, pvt * ma + 1, j * ma + 1);
      itemp = jpvt[pvt];
      jpvt[pvt] = jpvt[j];
      jpvt[j] = itemp;
      vn1[pvt] = vn1[j];
      vn2[pvt] = vn2[j];
    }

    if (j + 1 < m) {
      b_atmp = A->data[ii];
      tau_data[j] = 0.0;
      if (mmi > 0) {
        beta1 = Autonomous_Driving_xnrm2(mmi - 1, A, ii + 2);
        if (beta1 != 0.0) {
          beta1 = rt_hypotd_snf(A->data[ii], beta1);
          if (A->data[ii] >= 0.0) {
            beta1 = -beta1;
          }

          if (fabs(beta1) < 1.0020841800044864E-292) {
            itemp = -1;
            pvt = ii + mmi;
            do {
              itemp++;
              for (c_k = ii + 1; c_k < pvt; c_k++) {
                A->data[c_k] *= 9.9792015476736E+291;
              }

              beta1 *= 9.9792015476736E+291;
              b_atmp *= 9.9792015476736E+291;
            } while (!(fabs(beta1) >= 1.0020841800044864E-292));

            beta1 = rt_hypotd_snf(b_atmp, Autonomous_Driving_xnrm2(mmi - 1, A,
              ii + 2));
            if (b_atmp >= 0.0) {
              beta1 = -beta1;
            }

            tau_data[j] = (beta1 - b_atmp) / beta1;
            b_atmp = 1.0 / (b_atmp - beta1);
            for (c_k = ii + 1; c_k < pvt; c_k++) {
              A->data[c_k] *= b_atmp;
            }

            for (pvt = 0; pvt <= itemp; pvt++) {
              beta1 *= 1.0020841800044864E-292;
            }

            b_atmp = beta1;
          } else {
            tau_data[j] = (beta1 - A->data[ii]) / beta1;
            b_atmp = 1.0 / (A->data[ii] - beta1);
            itemp = ii + mmi;
            for (pvt = ii + 1; pvt < itemp; pvt++) {
              A->data[pvt] *= b_atmp;
            }

            b_atmp = beta1;
          }
        }
      }

      A->data[ii] = b_atmp;
    } else {
      tau_data[j] = 0.0;
    }

    if (j + 1 < 2) {
      b_atmp = A->data[ii];
      A->data[ii] = 1.0;
      Autonomous_Driving_xzlarf(mmi, 1 - j, ii + 1, tau_data[0], A, (ii + ma) +
        1, ma, work);
      A->data[ii] = b_atmp;
    }

    for (ii = j + 2; ii < 3; ii++) {
      pvt = j + ma;
      if (vn1[1] != 0.0) {
        b_atmp = fabs(A->data[pvt]) / vn1[1];
        b_atmp = 1.0 - b_atmp * b_atmp;
        if (b_atmp < 0.0) {
          b_atmp = 0.0;
        }

        beta1 = vn1[1] / vn2[1];
        beta1 = beta1 * beta1 * b_atmp;
        if (beta1 <= 1.4901161193847656E-8) {
          if (j + 1 < m) {
            vn1[1] = Autonomous_Driving_xnrm2(mmi - 1, A, pvt + 2);
            vn2[1] = vn1[1];
          } else {
            vn1[1] = 0.0;
            vn2[1] = 0.0;
          }
        } else {
          vn1[1] *= sqrt(b_atmp);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_xgeqp3(emxArray_real_T_Autonomous_Dr_T *A, real_T
  tau_data[], int32_T *tau_size, int32_T jpvt[2])
{
  emxArray_real_T_Autonomous_Dr_T *b_A;
  int32_T A_0;
  int32_T b_A_0;
  int32_T minmana;
  boolean_T guard1 = false;
  Autonomous_Drivi_emxInit_real_T(&b_A, 2);
  A_0 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 2;
  Autono_emxEnsureCapacity_real_T(b_A, A_0);
  minmana = A->size[0] << 1;
  for (A_0 = 0; A_0 < minmana; A_0++) {
    b_A->data[A_0] = A->data[A_0];
  }

  if (A->size[0] < 2) {
    minmana = A->size[0];
  } else {
    minmana = 2;
  }

  *tau_size = minmana;
  if (0 <= minmana - 1) {
    memset(&tau_data[0], 0, minmana * sizeof(real_T));
  }

  guard1 = false;
  if (A->size[0] == 0) {
    guard1 = true;
  } else {
    if (A->size[0] < 2) {
      A_0 = A->size[0];
    } else {
      A_0 = 2;
    }

    if (A_0 < 1) {
      guard1 = true;
    } else {
      jpvt[0] = 1;
      jpvt[1] = 2;
      A_0 = b_A->size[0] * b_A->size[1];
      b_A->size[0] = A->size[0];
      b_A->size[1] = 2;
      Autono_emxEnsureCapacity_real_T(b_A, A_0);
      minmana = A->size[0] << 1;
      for (A_0 = 0; A_0 < minmana; A_0++) {
        b_A->data[A_0] = A->data[A_0];
      }

      Autonomous_Driving_qrpf(b_A, A->size[0], tau_data, jpvt);
    }
  }

  if (guard1) {
    jpvt[0] = 1;
    jpvt[1] = 2;
  }

  A_0 = A->size[0] * A->size[1];
  A->size[0] = b_A->size[0];
  A->size[1] = 2;
  Autono_emxEnsureCapacity_real_T(A, A_0);
  minmana = b_A->size[0];
  for (A_0 = 0; A_0 < 2; A_0++) {
    for (b_A_0 = 0; b_A_0 < minmana; b_A_0++) {
      A->data[b_A_0 + A->size[0] * A_0] = b_A->data[b_A_0 + b_A->size[0] * A_0];
    }
  }

  Autonomous_Drivi_emxFree_real_T(&b_A);
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_qrsolve(const emxArray_real_T_Autonomous_Dr_T *A,
  const emxArray_real_T_Autonomous_Dr_T *B, real_T Y[2], int32_T *rankA)
{
  emxArray_real_T_Autonomous_Dr_T *b_A;
  emxArray_real_T_Autonomous_Dr_T *b_B;
  real_T tau_data[2];
  real_T tol;
  int32_T jpvt[2];
  int32_T b_j;
  int32_T b_mn;
  int32_T d_i;
  int32_T maxmn;
  int32_T minmn;
  Autonomous_Drivi_emxInit_real_T(&b_A, 2);
  b_mn = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 2;
  Autono_emxEnsureCapacity_real_T(b_A, b_mn);
  maxmn = A->size[0] << 1;
  for (b_mn = 0; b_mn < maxmn; b_mn++) {
    b_A->data[b_mn] = A->data[b_mn];
  }

  Autonomous_Driving_xgeqp3(b_A, tau_data, &b_mn, jpvt);
  *rankA = 0;
  if (b_A->size[0] < 2) {
    minmn = b_A->size[0];
    maxmn = 2;
  } else {
    minmn = 2;
    maxmn = b_A->size[0];
  }

  if (minmn > 0) {
    tol = 2.2204460492503131E-15 * (real_T)maxmn * fabs(b_A->data[0]);
    while ((*rankA < minmn) && (!(fabs(b_A->data[*rankA + b_A->size[0] * *rankA])
             <= tol))) {
      (*rankA)++;
    }
  }

  minmn = -1;
  if (b_A->size[0] < 2) {
    maxmn = b_A->size[0];
  } else {
    maxmn = 2;
  }

  if (maxmn > 0) {
    for (b_mn = 0; b_mn < maxmn; b_mn++) {
      if (b_A->data[b_mn + b_A->size[0] * b_mn] != 0.0) {
        minmn++;
      }
    }
  }

  Autonomous_Driv_emxInit_real_T1(&b_B, 1);
  Y[0] = 0.0;
  Y[1] = 0.0;
  b_mn = b_B->size[0];
  b_B->size[0] = B->size[0];
  Auton_emxEnsureCapacity_real_T1(b_B, b_mn);
  maxmn = B->size[0];
  for (b_mn = 0; b_mn < maxmn; b_mn++) {
    b_B->data[b_mn] = B->data[b_mn];
  }

  maxmn = b_A->size[0];
  if (b_A->size[0] < 2) {
    b_mn = b_A->size[0] - 1;
  } else {
    b_mn = 1;
  }

  for (b_j = 0; b_j <= b_mn; b_j++) {
    if (tau_data[b_j] != 0.0) {
      tol = b_B->data[b_j];
      for (d_i = b_j + 1; d_i < maxmn; d_i++) {
        tol += b_A->data[d_i + b_A->size[0] * b_j] * b_B->data[d_i];
      }

      tol *= tau_data[b_j];
      if (tol != 0.0) {
        b_B->data[b_j] -= tol;
        for (d_i = b_j + 1; d_i < maxmn; d_i++) {
          b_B->data[d_i] -= b_A->data[d_i + b_A->size[0] * b_j] * tol;
        }
      }
    }
  }

  for (maxmn = 0; maxmn <= minmn; maxmn++) {
    Y[jpvt[maxmn] - 1] = b_B->data[maxmn];
  }

  Autonomous_Drivi_emxFree_real_T(&b_B);
  while (minmn + 1 > 0) {
    Y[jpvt[minmn] - 1] /= b_A->data[minmn + b_A->size[0] * minmn];
    for (maxmn = 0; maxmn < minmn; maxmn++) {
      Y[jpvt[0] - 1] -= Y[jpvt[minmn] - 1] * b_A->data[b_A->size[0] * minmn];
    }

    minmn--;
  }

  Autonomous_Drivi_emxFree_real_T(&b_A);
}

/* Function for MATLAB Function: '<S19>/Find slope and intercept' */
static void Autonomous_Driving_polyfit(const emxArray_real_T_Autonomous_Dr_T *x,
  const emxArray_real_T_Autonomous_Dr_T *y, real_T p[2])
{
  emxArray_real_T_Autonomous_Dr_T *V;
  int32_T k;
  int32_T n;
  Autonomous_Drivi_emxInit_real_T(&V, 2);
  n = x->size[0] - 1;
  k = V->size[0] * V->size[1];
  V->size[0] = x->size[0];
  V->size[1] = 2;
  Autono_emxEnsureCapacity_real_T(V, k);
  if (x->size[0] != 0) {
    for (k = 0; k <= n; k++) {
      V->data[k + V->size[0]] = 1.0;
    }

    for (k = 0; k <= n; k++) {
      V->data[k] = x->data[k];
    }
  }

  Autonomous_Driving_qrsolve(V, y, p, &n);
  Autonomous_Drivi_emxFree_real_T(&V);
}

/* Function for MATLAB Function: '<S17>/Draw Lines Module' */
static void Autonomous_Driving_linspace(real_T d1, real_T d2, real_T n,
  emxArray_real_T_Autonomous_Dr_T *y)
{
  real_T delta1;
  real_T delta2;
  int32_T b_n;
  int32_T c_k;
  if (!(n >= 0.0)) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    delta2 = floor(n);
    b_n = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)delta2;
    Autono_emxEnsureCapacity_real_T(y, b_n);
    if ((int32_T)delta2 >= 1) {
      y->data[(int32_T)delta2 - 1] = d2;
      if (y->size[1] >= 2) {
        y->data[0] = d1;
        if (y->size[1] >= 3) {
          if ((d1 == -d2) && ((int32_T)delta2 > 2)) {
            delta1 = d2 / ((real_T)(int32_T)delta2 - 1.0);
            for (c_k = 2; c_k < (int32_T)delta2; c_k++) {
              y->data[c_k - 1] = (real_T)(((c_k << 1) - (int32_T)delta2) - 1) *
                delta1;
            }

            if (((int32_T)delta2 & 1) == 1) {
              y->data[(int32_T)delta2 >> 1] = 0.0;
            }
          } else if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) >
                       8.9884656743115785E+307) || (fabs(d2) >
                       8.9884656743115785E+307))) {
            delta1 = d1 / ((real_T)y->size[1] - 1.0);
            delta2 = d2 / ((real_T)y->size[1] - 1.0);
            b_n = y->size[1];
            for (c_k = 0; c_k <= b_n - 3; c_k++) {
              y->data[c_k + 1] = (((real_T)c_k + 1.0) * delta2 + d1) - ((real_T)
                c_k + 1.0) * delta1;
            }
          } else {
            delta1 = (d2 - d1) / ((real_T)y->size[1] - 1.0);
            b_n = y->size[1];
            for (c_k = 0; c_k <= b_n - 3; c_k++) {
              y->data[c_k + 1] = ((real_T)c_k + 1.0) * delta1 + d1;
            }
          }
        }
      }
    }
  }
}

/* Model output function for TID0 */
void Autonomous_Driving_output0(void)  /* Sample time: [0.0s, 0.0s] */
{
  real_T rtb_TmpSignalConversionAtHILWri[9];
  real_T rtb_Saturation_e;
  real_T rtb_SteeringBias;
  real_T rtb_Sum_a;
  boolean_T didZcEventOccur;
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* set solver stop time */
    if (!(Autonomous_Driving_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Autonomous_Driving_M->solverInfo,
                            ((Autonomous_Driving_M->Timing.clockTickH0 + 1) *
        Autonomous_Driving_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Autonomous_Driving_M->solverInfo,
                            ((Autonomous_Driving_M->Timing.clockTick0 + 1) *
        Autonomous_Driving_M->Timing.stepSize0 +
        Autonomous_Driving_M->Timing.clockTickH0 *
        Autonomous_Driving_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Autonomous_Driving_M)) {
    Autonomous_Driving_M->Timing.t[0] = rtsiGetT
      (&Autonomous_Driving_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* S-Function (hil_read_block): '<S8>/HIL Read' */

    /* S-Function Block: Autonomous_Driving/basicQCarIO/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(Autonomous_Driving_DW.HILInitialize_Card,
        Autonomous_Driving_P.HILRead_analog_channels, 2U,
        &Autonomous_Driving_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &Autonomous_Driving_DW.HILRead_AnalogBuffer[0],
        &Autonomous_Driving_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      } else {
        Autonomous_Driving_B.motorcurrent =
          Autonomous_Driving_DW.HILRead_AnalogBuffer[0];
        Autonomous_Driving_B.batteryvoltage =
          Autonomous_Driving_DW.HILRead_AnalogBuffer[1];
        Autonomous_Driving_B.encodercounts =
          Autonomous_Driving_DW.HILRead_EncoderBuffer;
      }
    }
  }

  /* Integrator: '<S28>/Integrator1' */
  if (Autonomous_Driving_DW.Integrator1_IWORK != 0) {
    Autonomous_Driving_X.Integrator1_CSTATE = Autonomous_Driving_B.motorcurrent;
  }

  /* Integrator: '<S28>/Integrator1' */
  Autonomous_Driving_B.Integrator1 = Autonomous_Driving_X.Integrator1_CSTATE;

  /* Integrator: '<S27>/Integrator1' */
  if (Autonomous_Driving_DW.Integrator1_IWORK_p != 0) {
    Autonomous_Driving_X.Integrator1_CSTATE_p =
      Autonomous_Driving_B.batteryvoltage;
  }

  /* Integrator: '<S27>/Integrator1' */
  Autonomous_Driving_B.Integrator1_p = Autonomous_Driving_X.Integrator1_CSTATE_p;
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* S-Function (inverse_modulus_block): '<S8>/Unwrap 2^24' */
    /* S-Function Block: Autonomous_Driving/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.0016666666666666668;
      real_T half_range = Autonomous_Driving_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Autonomous_Driving_DW.Unwrap224_FirstSample) {
        Autonomous_Driving_DW.Unwrap224_FirstSample = false;
        Autonomous_Driving_DW.Unwrap224_PreviousInput =
          Autonomous_Driving_B.encodercounts;
      }

      du = (real_T) Autonomous_Driving_B.encodercounts -
        Autonomous_Driving_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Autonomous_Driving_DW.Unwrap224_Revolutions =
          Autonomous_Driving_DW.Unwrap224_Revolutions - 1;
        dy = du - Autonomous_Driving_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Autonomous_Driving_DW.Unwrap224_Revolutions =
          Autonomous_Driving_DW.Unwrap224_Revolutions + 1;
        dy = du + Autonomous_Driving_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Autonomous_Driving_B.Unwrap224 = Autonomous_Driving_B.encodercounts +
        Autonomous_Driving_DW.Unwrap224_Revolutions *
        Autonomous_Driving_P.Unwrap224_Modulus;
      Autonomous_Driving_DW.Unwrap224_PreviousInput =
        Autonomous_Driving_B.encodercounts;
    }
  }

  /* Integrator: '<S26>/Integrator1' */
  if (Autonomous_Driving_DW.Integrator1_IWORK_o != 0) {
    Autonomous_Driving_X.Integrator1_CSTATE_n = Autonomous_Driving_B.Unwrap224;
  }

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Integrator: '<S26>/Integrator1'
   *  Integrator: '<S26>/Integrator2'
   *  Product: '<S26>/Product2'
   *  Sum: '<S26>/Sum'
   *  Sum: '<S26>/Sum1'
   */
  Autonomous_Driving_B.Product = ((Autonomous_Driving_B.Unwrap224 -
    Autonomous_Driving_X.Integrator1_CSTATE_n) -
    Autonomous_Driving_X.Integrator2_CSTATE *
    Autonomous_Driving_P.Constant_Value_k *
    Autonomous_Driving_P.Constant1_Value_l) *
    Autonomous_Driving_P.Constant2_Value_i;

  /* Product: '<S26>/Product1' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Integrator: '<S26>/Integrator2'
   */
  Autonomous_Driving_B.Product1 = Autonomous_Driving_P.Constant2_Value_i *
    Autonomous_Driving_X.Integrator2_CSTATE;

  /* Product: '<S27>/Product' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Integrator: '<S27>/Integrator2'
   *  Product: '<S27>/Product2'
   *  Sum: '<S27>/Sum'
   *  Sum: '<S27>/Sum1'
   */
  Autonomous_Driving_B.Product_g = ((Autonomous_Driving_B.batteryvoltage -
    Autonomous_Driving_B.Integrator1_p) -
    Autonomous_Driving_X.Integrator2_CSTATE_k *
    Autonomous_Driving_P.Constant_Value_h *
    Autonomous_Driving_P.Constant3_Value_j) *
    Autonomous_Driving_P.Constant4_Value_n;

  /* Product: '<S27>/Product1' incorporates:
   *  Constant: '<S8>/Constant4'
   *  Integrator: '<S27>/Integrator2'
   */
  Autonomous_Driving_B.Product1_c = Autonomous_Driving_P.Constant4_Value_n *
    Autonomous_Driving_X.Integrator2_CSTATE_k;

  /* Product: '<S28>/Product' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S8>/Constant5'
   *  Constant: '<S8>/Constant6'
   *  Integrator: '<S28>/Integrator2'
   *  Product: '<S28>/Product2'
   *  Sum: '<S28>/Sum'
   *  Sum: '<S28>/Sum1'
   */
  Autonomous_Driving_B.Product_e = ((Autonomous_Driving_B.motorcurrent -
    Autonomous_Driving_B.Integrator1) -
    Autonomous_Driving_X.Integrator2_CSTATE_o *
    Autonomous_Driving_P.Constant_Value_e * Autonomous_Driving_P.Constant5_Value)
    * Autonomous_Driving_P.Constant6_Value;

  /* Product: '<S28>/Product1' incorporates:
   *  Constant: '<S8>/Constant6'
   *  Integrator: '<S28>/Integrator2'
   */
  Autonomous_Driving_B.Product1_a = Autonomous_Driving_P.Constant6_Value *
    Autonomous_Driving_X.Integrator2_CSTATE_o;

  /* RateTransition: '<Root>/Rate Transition1' */
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    if (Autonomous_Driving_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition: '<Root>/Rate Transition1' */
      Autonomous_Driving_B.RateTransition1 =
        Autonomous_Driving_DW.RateTransition1_Buffer0;
    }

    /* ManualSwitch: '<S21>/1 - Arm, 0 - Disarm1' */
    if (Autonomous_Driving_P.uArm0Disarm1_CurrentSetting == 1) {
      /* ManualSwitch: '<S21>/1 - Arm, 0 - Disarm1' incorporates:
       *  Constant: '<S21>/Constant10'
       */
      Autonomous_Driving_B.uArm0Disarm1 = Autonomous_Driving_P.Constant10_Value;
    } else {
      /* ManualSwitch: '<S21>/1 - Arm, 0 - Disarm1' incorporates:
       *  Constant: '<S21>/Constant8'
       */
      Autonomous_Driving_B.uArm0Disarm1 = Autonomous_Driving_P.Constant8_Value;
    }

    /* End of ManualSwitch: '<S21>/1 - Arm, 0 - Disarm1' */

    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S21>/Constant9'
     */
    if (Autonomous_Driving_B.uArm0Disarm1 >
        Autonomous_Driving_P.Switch_Threshold) {
      /* Gain: '<S52>/Slider Gain' incorporates:
       *  Constant: '<S21>/Speed Max (m//s)'
       */
      rtb_Saturation_e = Autonomous_Driving_P.SpeedSelector1_gain *
        Autonomous_Driving_P.SpeedMaxms_Value;

      /* Saturate: '<S21>/Saturation1' */
      if (rtb_Saturation_e > Autonomous_Driving_P.Saturation1_UpperSat) {
        rtb_Saturation_e = Autonomous_Driving_P.Saturation1_UpperSat;
      } else if (rtb_Saturation_e < Autonomous_Driving_P.Saturation1_LowerSat) {
        rtb_Saturation_e = Autonomous_Driving_P.Saturation1_LowerSat;
      }

      /* End of Saturate: '<S21>/Saturation1' */
    } else {
      rtb_Saturation_e = Autonomous_Driving_P.Constant9_Value;
    }

    /* End of Switch: '<S21>/Switch' */

    /* RateLimiter: '<S21>/Rate Limiter' */
    rtb_Sum_a = rtb_Saturation_e - Autonomous_Driving_DW.PrevY;
    if (rtb_Sum_a > Autonomous_Driving_P.RateLimiter_RisingLim *
        Autonomous_Driving_period) {
      rtb_Saturation_e = Autonomous_Driving_P.RateLimiter_RisingLim *
        Autonomous_Driving_period + Autonomous_Driving_DW.PrevY;
    } else if (rtb_Sum_a < Autonomous_Driving_P.RateLimiter_FallingLim *
               Autonomous_Driving_period) {
      rtb_Saturation_e = Autonomous_Driving_P.RateLimiter_FallingLim *
        Autonomous_Driving_period + Autonomous_Driving_DW.PrevY;
    }

    Autonomous_Driving_DW.PrevY = rtb_Saturation_e;

    /* End of RateLimiter: '<S21>/Rate Limiter' */

    /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant2'
     */
    Autonomous_Driving_B.speed_cmd = rtb_Saturation_e;
    if (Autonomous_Driving_B.RateTransition1 <
        Autonomous_Driving_P.Constant_Value_p) {
      Autonomous_Driving_B.speed_cmd = 0.0;
    } else if (Autonomous_Driving_B.RateTransition1 <
               Autonomous_Driving_P.Constant2_Value_f) {
      rtb_Sum_a = rtb_Saturation_e / (Autonomous_Driving_P.Constant2_Value_f -
        Autonomous_Driving_P.Constant_Value_p);
      Autonomous_Driving_B.speed_cmd = rtb_Sum_a *
        Autonomous_Driving_B.RateTransition1 - rtb_Sum_a *
        Autonomous_Driving_P.Constant_Value_p;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function' */

    /* RateTransition: '<Root>/Rate Transition' */
    if (Autonomous_Driving_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<Root>/Rate Transition' */
      Autonomous_Driving_B.RateTransition =
        Autonomous_Driving_DW.RateTransition_Buffer0;
    }

    /* End of RateTransition: '<Root>/Rate Transition' */

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    if (Autonomous_Driving_P.Constant1_Value_f >
        Autonomous_Driving_P.Switch_Threshold_h) {
      /* Trigonometry: '<S20>/Cos' */
      rtb_Saturation_e = cos(Autonomous_Driving_B.RateTransition);

      /* Math: '<S20>/Square' incorporates:
       *  Constant: '<S20>/Constant'
       */
      if ((rtb_Saturation_e < 0.0) && (Autonomous_Driving_P.Constant_Value_j >
           floor(Autonomous_Driving_P.Constant_Value_j))) {
        rtb_Saturation_e = -rt_powd_snf(-rtb_Saturation_e,
          Autonomous_Driving_P.Constant_Value_j);
      } else {
        rtb_Saturation_e = rt_powd_snf(rtb_Saturation_e,
          Autonomous_Driving_P.Constant_Value_j);
      }

      /* End of Math: '<S20>/Square' */

      /* Saturate: '<S20>/Saturation' */
      if (rtb_Saturation_e > Autonomous_Driving_P.Saturation_UpperSat) {
        rtb_Saturation_e = Autonomous_Driving_P.Saturation_UpperSat;
      } else if (rtb_Saturation_e < Autonomous_Driving_P.Saturation_LowerSat) {
        rtb_Saturation_e = Autonomous_Driving_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<S20>/Saturation' */

      /* Switch: '<S20>/Switch' incorporates:
       *  Product: '<S20>/Product'
       */
      Autonomous_Driving_B.DesiredSpeedms = Autonomous_Driving_B.speed_cmd *
        rtb_Saturation_e;
    } else {
      /* Switch: '<S20>/Switch' */
      Autonomous_Driving_B.DesiredSpeedms = Autonomous_Driving_B.speed_cmd;
    }

    /* End of Switch: '<S20>/Switch' */

    /* Saturate: '<S18>/command saturation' */
    if (Autonomous_Driving_B.DesiredSpeedms >
        Autonomous_Driving_P.commandsaturation_UpperSat) {
      rtb_Saturation_e = Autonomous_Driving_P.commandsaturation_UpperSat;
    } else if (Autonomous_Driving_B.DesiredSpeedms <
               Autonomous_Driving_P.commandsaturation_LowerSat) {
      rtb_Saturation_e = Autonomous_Driving_P.commandsaturation_LowerSat;
    } else {
      rtb_Saturation_e = Autonomous_Driving_B.DesiredSpeedms;
    }

    /* End of Saturate: '<S18>/command saturation' */

    /* Product: '<S18>/Multiply1' */
    Autonomous_Driving_B.desired = rtb_Saturation_e *
      Autonomous_Driving_B.uArm0Disarm1;

    /* Gain: '<S18>/Kff  (% // m//s)' */
    Autonomous_Driving_B.Kffms = Autonomous_Driving_P.Kffms_Gain *
      Autonomous_Driving_B.desired;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* Product: '<S18>/Multiply' incorporates:
   *  Gain: '<S9>/counts to rotations'
   *  Gain: '<S9>/gear ratios'
   *  Gain: '<S9>/rot//s to rad//s'
   *  Gain: '<S9>/wheel radius'
   */
  Autonomous_Driving_B.measured = Autonomous_Driving_P.countstorotations_Gain *
    Autonomous_Driving_B.Product1 * Autonomous_Driving_P.gearratios_Gain *
    Autonomous_Driving_P.rotstorads_Gain * Autonomous_Driving_P.wheelradius_Gain
    * Autonomous_Driving_B.uArm0Disarm1;

  /* Sum: '<S18>/Sum' */
  rtb_Sum_a = Autonomous_Driving_B.desired - Autonomous_Driving_B.measured;
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<S39>/Constant'
     */
    Autonomous_Driving_B.Compare = (Autonomous_Driving_B.desired ==
      Autonomous_Driving_P.Constant_Value_i);
  }

  /* Integrator: '<S18>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    didZcEventOccur = (((Autonomous_Driving_PrevZCX.Integrator1_Reset_ZCE ==
                         POS_ZCSIG) != (int32_T)Autonomous_Driving_B.Compare) &&
                       (Autonomous_Driving_PrevZCX.Integrator1_Reset_ZCE !=
                        UNINITIALIZED_ZCSIG));
    Autonomous_Driving_PrevZCX.Integrator1_Reset_ZCE =
      Autonomous_Driving_B.Compare;

    /* evaluate zero-crossings */
    if (didZcEventOccur) {
      Autonomous_Driving_X.Integrator1_CSTATE_b =
        Autonomous_Driving_P.Integrator1_IC;
    }
  }

  if (Autonomous_Driving_X.Integrator1_CSTATE_b >=
      Autonomous_Driving_P.Integrator1_UpperSat) {
    Autonomous_Driving_X.Integrator1_CSTATE_b =
      Autonomous_Driving_P.Integrator1_UpperSat;
  } else if (Autonomous_Driving_X.Integrator1_CSTATE_b <=
             Autonomous_Driving_P.Integrator1_LowerSat) {
    Autonomous_Driving_X.Integrator1_CSTATE_b =
      Autonomous_Driving_P.Integrator1_LowerSat;
  }

  /* Product: '<S18>/Multiply2' incorporates:
   *  Gain: '<S18>/Kp (% // m//s)'
   *  Integrator: '<S18>/Integrator1'
   *  Sum: '<S18>/Add'
   *  Sum: '<S18>/Add1'
   */
  Autonomous_Driving_B.pwmdutycycle = ((Autonomous_Driving_P.Kpms_Gain *
    rtb_Sum_a + Autonomous_Driving_X.Integrator1_CSTATE_b) +
    Autonomous_Driving_B.Kffms) * Autonomous_Driving_B.uArm0Disarm1;

  /* Gain: '<S8>/direction convention' */
  rtb_Saturation_e = Autonomous_Driving_P.directionconvention_Gain *
    Autonomous_Driving_B.pwmdutycycle;

  /* Saturate: '<S8>/command saturation' */
  if (rtb_Saturation_e > Autonomous_Driving_P.commandsaturation_UpperSat_i) {
    /* Saturate: '<S8>/command saturation' */
    Autonomous_Driving_B.commandsaturation =
      Autonomous_Driving_P.commandsaturation_UpperSat_i;
  } else if (rtb_Saturation_e <
             Autonomous_Driving_P.commandsaturation_LowerSat_a) {
    /* Saturate: '<S8>/command saturation' */
    Autonomous_Driving_B.commandsaturation =
      Autonomous_Driving_P.commandsaturation_LowerSat_a;
  } else {
    /* Saturate: '<S8>/command saturation' */
    Autonomous_Driving_B.commandsaturation = rtb_Saturation_e;
  }

  /* End of Saturate: '<S8>/command saturation' */
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* Bias: '<S8>/Steering Bias' incorporates:
     *  Gain: '<S8>/Gain'
     */
    rtb_SteeringBias = Autonomous_Driving_P.Gain_Gain *
      Autonomous_Driving_B.RateTransition +
      Autonomous_Driving_P.SteeringBias_Bias;

    /* DiscretePulseGenerator: '<S13>/Pulsing Light' */
    rtb_Saturation_e = (Autonomous_Driving_DW.clockTickCounter <
                        Autonomous_Driving_P.PulsingLight_Duty) &&
      (Autonomous_Driving_DW.clockTickCounter >= 0) ?
      Autonomous_Driving_P.PulsingLight_Amp : 0.0;
    if (Autonomous_Driving_DW.clockTickCounter >=
        Autonomous_Driving_P.PulsingLight_Period - 1.0) {
      Autonomous_Driving_DW.clockTickCounter = 0;
    } else {
      Autonomous_Driving_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S13>/Pulsing Light' */

    /* Logic: '<S13>/AND3' incorporates:
     *  Constant: '<S33>/Constant'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  RelationalOperator: '<S33>/Compare'
     */
    Autonomous_Driving_B.AND3 = ((Autonomous_Driving_B.RateTransition >
      Autonomous_Driving_P.LeftSteeringLimit_const) && (rtb_Saturation_e != 0.0));

    /* Logic: '<S13>/AND1' incorporates:
     *  Constant: '<S35>/Constant'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  RelationalOperator: '<S35>/Compare'
     */
    Autonomous_Driving_B.AND1 = ((Autonomous_Driving_B.RateTransition <
      Autonomous_Driving_P.RightSteeringLimit_const) && (rtb_Saturation_e != 0.0));

    /* Abs: '<S13>/Abs' incorporates:
     *  Memory: '<S13>/Memory'
     */
    Autonomous_Driving_B.Abs = fabs(Autonomous_Driving_DW.Memory_PreviousInput);
  }

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Abs: '<S13>/Abs1'
   *  Constant: '<S32>/Constant'
   *  Sum: '<S13>/Subtract'
   */
  Autonomous_Driving_B.Compare_d = (fabs(Autonomous_Driving_B.pwmdutycycle) -
    Autonomous_Driving_B.Abs < Autonomous_Driving_P.CompareToConstant3_const);

  /* S-Function (one_shot_block): '<S34>/one_shot_block' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  if (Autonomous_Driving_P.one_shot_block_trigger_type == 1.0 &&
      Autonomous_Driving_B.Compare_d -
      Autonomous_Driving_DW.one_shot_block_DSTATE[2] > 0 ) {
    if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
        Autonomous_Driving_P.one_shot_block_redun_pulse == 1.0 ) {
    } else if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
               Autonomous_Driving_P.one_shot_block_redun_pulse == 2.0 ) {
      Autonomous_Driving_DW.one_shot_block_DSTATE[1] = 0.0;
    } else {
      Autonomous_Driving_DW.one_shot_block_DSTATE[0] = 1.0;
    }
  } else if (Autonomous_Driving_P.one_shot_block_trigger_type == 2.0 &&
             Autonomous_Driving_B.Compare_d -
             Autonomous_Driving_DW.one_shot_block_DSTATE[2] < 0 ) {
    if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
        Autonomous_Driving_P.one_shot_block_redun_pulse == 1.0 ) {
    } else if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
               Autonomous_Driving_P.one_shot_block_redun_pulse == 2.0 ) {
      Autonomous_Driving_DW.one_shot_block_DSTATE[1] = 0.0;
    } else {
      Autonomous_Driving_DW.one_shot_block_DSTATE[0] = 1.0;
    }
  } else if ((Autonomous_Driving_P.one_shot_block_trigger_type == 3.0 &&
              Autonomous_Driving_B.Compare_d -
              Autonomous_Driving_DW.one_shot_block_DSTATE[2] < 0 ) ||
             (Autonomous_Driving_P.one_shot_block_trigger_type == 3.0 &&
              Autonomous_Driving_B.Compare_d -
              Autonomous_Driving_DW.one_shot_block_DSTATE[2] > 0 ) ) {
    if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
        Autonomous_Driving_P.one_shot_block_redun_pulse == 1.0 ) {
    } else if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
               Autonomous_Driving_P.one_shot_block_redun_pulse == 2.0 ) {
      Autonomous_Driving_DW.one_shot_block_DSTATE[1] = 0.0;
    } else {
      Autonomous_Driving_DW.one_shot_block_DSTATE[0] = 1.0;
    }
  }

  Autonomous_Driving_DW.one_shot_block_DSTATE[2] =
    Autonomous_Driving_B.Compare_d ;
  if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
      Autonomous_Driving_DW.one_shot_block_DSTATE[1] <
      Autonomous_Driving_P.Constant2_Value_b ) {
    Autonomous_Driving_DW.one_shot_block_DSTATE[1] += 1.0;
    Autonomous_Driving_B.one_shot_block = 1.0;
  } else if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 1.0 &&
             Autonomous_Driving_DW.one_shot_block_DSTATE[1] >=
             Autonomous_Driving_P.Constant2_Value_b ) {
    Autonomous_Driving_DW.one_shot_block_DSTATE[0] = 0.0;
    Autonomous_Driving_DW.one_shot_block_DSTATE[1] = 0.0;
    Autonomous_Driving_B.one_shot_block = 0.0;
  } else if (Autonomous_Driving_DW.one_shot_block_DSTATE[0] == 0.0 ) {
    Autonomous_Driving_DW.one_shot_block_DSTATE[1] = 0.0;
    Autonomous_Driving_B.one_shot_block = 0.0;
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  Autonomous_Driving_B.DataTypeConversion1[0] = Autonomous_Driving_B.AND3;
  Autonomous_Driving_B.DataTypeConversion1[1] = Autonomous_Driving_B.AND1;
  Autonomous_Driving_B.DataTypeConversion1[2] = Autonomous_Driving_B.AND3;
  Autonomous_Driving_B.DataTypeConversion1[3] = Autonomous_Driving_B.AND1;

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   */
  if (Autonomous_Driving_B.one_shot_block >=
      Autonomous_Driving_P.Switch_Threshold_e) {
    rtb_Saturation_e = Autonomous_Driving_P.Constant1_Value_fc;
  } else {
    rtb_Saturation_e = Autonomous_Driving_P.Constant_Value_d;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S30>/Constant'
   *  Logic: '<S13>/AND2'
   *  RelationalOperator: '<S30>/Compare'
   */
  if ((rtb_Saturation_e != 0.0) || (Autonomous_Driving_B.pwmdutycycle ==
       Autonomous_Driving_P.CompareToConstant1_const)) {
    /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
     *  Constant: '<S13>/Steady Light'
     */
    Autonomous_Driving_B.DataTypeConversion1[4] =
      Autonomous_Driving_P.SteadyLight_Value;
  } else {
    /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
     *  Constant: '<S13>/Light Off'
     */
    Autonomous_Driving_B.DataTypeConversion1[4] =
      Autonomous_Driving_P.LightOff_Value;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/Steady Light'
   *  Constant: '<S31>/Constant'
   *  RelationalOperator: '<S31>/Compare'
   */
  Autonomous_Driving_B.DataTypeConversion1[5] =
    (Autonomous_Driving_B.pwmdutycycle <
     Autonomous_Driving_P.CompareToConstant2_const);
  Autonomous_Driving_B.DataTypeConversion1[6] =
    Autonomous_Driving_P.SteadyLight_Value;
  Autonomous_Driving_B.DataTypeConversion1[7] =
    Autonomous_Driving_P.SteadyLight_Value;
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* SignalConversion generated from: '<S8>/HIL Write' */
    rtb_TmpSignalConversionAtHILWri[0] = rtb_SteeringBias;
    memcpy(&rtb_TmpSignalConversionAtHILWri[1],
           &Autonomous_Driving_B.DataTypeConversion1[0], sizeof(real_T) << 3U);

    /* S-Function (hil_write_block): '<S8>/HIL Write' incorporates:
     *  Constant: '<S8>/coast ON'
     */

    /* S-Function Block: Autonomous_Driving/basicQCarIO/HIL Write (hil_write_block) */
    {
      t_error result;
      Autonomous_Driving_DW.HILWrite_DigitalBuffer =
        (Autonomous_Driving_P.coastON_Value != 0);
      result = hil_write(Autonomous_Driving_DW.HILInitialize_Card,
                         NULL, 0U,
                         &Autonomous_Driving_P.HILWrite_pwm_channels, 1U,
                         &Autonomous_Driving_P.HILWrite_digital_channels, 1U,
                         Autonomous_Driving_P.HILWrite_other_channels, 9U,
                         NULL,
                         &Autonomous_Driving_B.commandsaturation,
                         &Autonomous_Driving_DW.HILWrite_DigitalBuffer,
                         &rtb_TmpSignalConversionAtHILWri[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      }
    }

    /* RateTransition: '<Root>/Rate Transition5' */
    if (Autonomous_Driving_M->Timing.RateInteraction.TID1_2) {
      /* Bias: '<Root>/Bias1' incorporates:
       *  Gain: '<Root>/Gain'
       *  Sum: '<Root>/Subtract'
       */
      rtb_Saturation_e = (Autonomous_Driving_B.speed_cmd -
                          Autonomous_Driving_B.DesiredSpeedms) *
        Autonomous_Driving_P.Gain_Gain_p + Autonomous_Driving_P.Bias1_Bias;

      /* Saturate: '<Root>/Saturation' */
      if (rtb_Saturation_e > Autonomous_Driving_P.Saturation_UpperSat_p) {
        Autonomous_Driving_DW.RateTransition5_Buffer =
          Autonomous_Driving_P.Saturation_UpperSat_p;
      } else if (rtb_Saturation_e < Autonomous_Driving_P.Saturation_LowerSat_p)
      {
        Autonomous_Driving_DW.RateTransition5_Buffer =
          Autonomous_Driving_P.Saturation_LowerSat_p;
      } else {
        Autonomous_Driving_DW.RateTransition5_Buffer = rtb_Saturation_e;
      }

      /* End of Saturate: '<Root>/Saturation' */
    }

    /* End of RateTransition: '<Root>/Rate Transition5' */
  }

  /* Gain: '<S18>/Ki (% // m)  ' */
  Autonomous_Driving_B.Kim = Autonomous_Driving_P.Kim_Gain * rtb_Sum_a;
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* S-Function (sample_time_block): '<S14>/Sample Time' */

    /* S-Function Block: Autonomous_Driving/monitorTiming /Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &Autonomous_Driving_DW.SampleTime_PreviousTime);
        Autonomous_Driving_B.SampleTime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&Autonomous_Driving_DW.SampleTime_PreviousTime, &current_time,
               sizeof(t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    /* Constant: '<S14>/Constant' */
    Autonomous_Driving_B.Constant = Autonomous_Driving_P.Constant_Value_c;

    /* S-Function (computation_time_block): '<S14>/Computation Time' */

    /* S-Function Block: Autonomous_Driving/monitorTiming /Computation Time (computation_time_block) */
    {
      Autonomous_Driving_B.ComputationTime =
        Autonomous_Driving_DW.ComputationTime_ComputationTime.seconds +
        Autonomous_Driving_DW.ComputationTime_ComputationTime.nanoseconds * 1e-9;
    }

    /* RateTransition: '<Root>/Rate Transition4' */
    if (Autonomous_Driving_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<Root>/Rate Transition4' */
      Autonomous_Driving_B.RateTransition4[0] =
        Autonomous_Driving_DW.RateTransition4_Buffer0[0];
      Autonomous_Driving_B.RateTransition4[1] =
        Autonomous_Driving_DW.RateTransition4_Buffer0[1];
      Autonomous_Driving_B.RateTransition4[2] =
        Autonomous_Driving_DW.RateTransition4_Buffer0[2];
    }

    /* End of RateTransition: '<Root>/Rate Transition4' */

    /* RateTransition: '<Root>/Rate Transition3' */
    if (Autonomous_Driving_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition: '<Root>/Rate Transition3' */
      Autonomous_Driving_B.RateTransition3[0] =
        Autonomous_Driving_DW.RateTransition3_Buffer0[0];
      Autonomous_Driving_B.RateTransition3[1] =
        Autonomous_Driving_DW.RateTransition3_Buffer0[1];
      Autonomous_Driving_B.RateTransition3[2] =
        Autonomous_Driving_DW.RateTransition3_Buffer0[2];
    }

    /* End of RateTransition: '<Root>/Rate Transition3' */
  }
}

/* Model update function for TID0 */
void Autonomous_Driving_update0(void)  /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S28>/Integrator1' */
  Autonomous_Driving_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S27>/Integrator1' */
  Autonomous_Driving_DW.Integrator1_IWORK_p = 0;

  /* Update for Integrator: '<S26>/Integrator1' */
  Autonomous_Driving_DW.Integrator1_IWORK_o = 0;
  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    /* Update for Memory: '<S13>/Memory' */
    Autonomous_Driving_DW.Memory_PreviousInput =
      Autonomous_Driving_B.pwmdutycycle;
  }

  if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
    rt_ertODEUpdateContinuousStates(&Autonomous_Driving_M->solverInfo);
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
  if (!(++Autonomous_Driving_M->Timing.clockTick0)) {
    ++Autonomous_Driving_M->Timing.clockTickH0;
  }

  Autonomous_Driving_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Autonomous_Driving_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Autonomous_Driving_M->Timing.clockTick1)) {
    ++Autonomous_Driving_M->Timing.clockTickH1;
  }

  Autonomous_Driving_M->Timing.t[1] = Autonomous_Driving_M->Timing.clockTick1 *
    Autonomous_Driving_M->Timing.stepSize1 +
    Autonomous_Driving_M->Timing.clockTickH1 *
    Autonomous_Driving_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Autonomous_Driving_derivatives(void)
{
  XDot_Autonomous_Driving_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Autonomous_Driving_T *) Autonomous_Driving_M->derivs);

  /* Derivatives for Integrator: '<S28>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Autonomous_Driving_B.Product1_a;

  /* Derivatives for Integrator: '<S27>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = Autonomous_Driving_B.Product1_c;

  /* Derivatives for Integrator: '<S26>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_n = Autonomous_Driving_B.Product1;

  /* Derivatives for Integrator: '<S26>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Autonomous_Driving_B.Product;

  /* Derivatives for Integrator: '<S27>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_k = Autonomous_Driving_B.Product_g;

  /* Derivatives for Integrator: '<S28>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = Autonomous_Driving_B.Product_e;

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  lsat = (Autonomous_Driving_X.Integrator1_CSTATE_b <=
          Autonomous_Driving_P.Integrator1_LowerSat);
  usat = (Autonomous_Driving_X.Integrator1_CSTATE_b >=
          Autonomous_Driving_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Autonomous_Driving_B.Kim > 0.0)) ||
      (usat && (Autonomous_Driving_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE_b = Autonomous_Driving_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_b = 0.0;
  }

  /* End of Derivatives for Integrator: '<S18>/Integrator1' */
}

/* Model output function for TID2 */
void Autonomous_Driving_output2(void)
                               /* Sample time: [0.0083333333333333332s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_SampleTime;
  real_T rtb_ComputationTime;
  emxArray_int32_T_Autonomous_D_T *ii;
  emxArray_int32_T_Autonomous_D_T *jj;
  emxArray_real_T_Autonomous_Dr_T *b_0;
  emxArray_real_T_Autonomous_Dr_T *rtb_imageSize_0;
  emxArray_real_T_Autonomous_Dr_T *x;
  real_T result[2];
  real_T rtb_Add1;
  real_T rtb_Add4;
  real_T rtb_Add7;
  real_T rtb_Product4;
  real_T rtb_Product5;
  real_T rtb_SliderGain_b;
  real_T rtb_uRight0Left;
  real_T u0;
  int32_T tmp_size[2];
  int32_T b;
  int32_T b_k;
  int32_T c_nx;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T loop_ub;
  int32_T n;
  int32_T section_size_idx_0;
  uint32_T tmp;
  uint8_T section;

  /* ManualSwitch: '<S21>/1 - Right, 0 - Left' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   */
  if (Autonomous_Driving_P.uRight0Left_CurrentSetting == 1) {
    rtb_uRight0Left = Autonomous_Driving_P.Constant4_Value;
  } else {
    rtb_uRight0Left = Autonomous_Driving_P.Constant3_Value_b;
  }

  /* End of ManualSwitch: '<S21>/1 - Right, 0 - Left' */

  /* S-Function (video_capture_block): '<S10>/Video Capture' */
  /* S-Function Block: Autonomous_Driving/captureCSI/Video Capture (video_capture_block) */
  {
    t_error result;
    t_video_capture_attribute local_attr[17] = {
      { Autonomous_Driving_P.VideoCapture_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvBrightness, false }
      , { Autonomous_Driving_P.VideoCapture_Contrast,
        VIDEO_CAPTURE_PROPERTY_CONTRAST, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvContrast, false }
      , { Autonomous_Driving_P.VideoCapture_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvHue, false }
      , { Autonomous_Driving_P.VideoCapture_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvSaturation, false }
      , { Autonomous_Driving_P.VideoCapture_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvSharpness, false }
      , { Autonomous_Driving_P.VideoCapture_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvGamma, false }
      , { Autonomous_Driving_P.VideoCapture_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvColorEnable, true }
      , { Autonomous_Driving_P.VideoCapture_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvWhiteBalance, false }
      , { Autonomous_Driving_P.VideoCapture_BacklightCompensat,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvBacklightCompens, false }
      , { Autonomous_Driving_P.VideoCapture_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvGain, false }
      , { Autonomous_Driving_P.VideoCapture_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvPan, false }
      , { Autonomous_Driving_P.VideoCapture_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvTilt, false }
      , { Autonomous_Driving_P.VideoCapture_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvRoll, false }
      , { Autonomous_Driving_P.VideoCapture_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvZoom, false }
      , { Autonomous_Driving_P.VideoCapture_Exposure,
        VIDEO_CAPTURE_PROPERTY_EXPOSURE, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvExposure, false }
      , { Autonomous_Driving_P.VideoCapture_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvIris, false }
      , { Autonomous_Driving_P.VideoCapture_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvFocus, false }
    };

    video_capture_set_property(Autonomous_Driving_DW.VideoCapture_VideoCapture,
      local_attr, ARRAY_LENGTH(local_attr));
    result = video_capture_read(Autonomous_Driving_DW.VideoCapture_VideoCapture,
      &Autonomous_Driving_B.VideoCapture_o1[0]);
    Autonomous_Driving_B.VideoCapture_o2 = (result > 0);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  RateTransition: '<Root>/Rate Transition5'
   *  S-Function (video_capture_block): '<S10>/Video Capture'
   */
  if (rtb_uRight0Left != 0.0) {
    for (b_k = 0; b_k < 3; b_k++) {
      for (i_1 = 0; i_1 < 273; i_1++) {
        for (i_0 = 0; i_0 < 205; i_0++) {
          Autonomous_Driving_B.imageToThreshold[(i_0 + 205 * i_1) + 55965 * b_k]
            = Autonomous_Driving_B.VideoCapture_o1[((((int32_T)((real_T)i_1 +
            547.66666666666663) - 1) * 410 + i_0) + 336200 * b_k) + 205];
        }
      }
    }
  } else {
    for (b_k = 0; b_k < 3; b_k++) {
      for (i_1 = 0; i_1 < 273; i_1++) {
        memcpy(&Autonomous_Driving_B.imageToThreshold[b_k * 55965 + i_1 * 205],
               &Autonomous_Driving_B.VideoCapture_o1[(b_k * 336200 + i_1 * 410)
               + 205], 205U * sizeof(uint8_T));
      }
    }
  }

  if (1.0 > 205.0 - ((410.0 - Autonomous_Driving_DW.RateTransition5_Buffer) +
                     1.0)) {
    b = 0;
  } else {
    b = (int32_T)(205.0 - ((410.0 - Autonomous_Driving_DW.RateTransition5_Buffer)
      + 1.0));
  }

  for (b_k = 0; b_k < 3; b_k++) {
    for (i_1 = 0; i_1 < 273; i_1++) {
      if (0 <= b - 1) {
        memset(&Autonomous_Driving_B.imageToThreshold[b_k * 55965 + i_1 * 205],
               0, b * sizeof(uint8_T));
      }
    }
  }

  /* S-Function (image_transform_block): '<S12>/Image Transform' */

  /* S-Function Block: Autonomous_Driving/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    t_error result;
    result = image_rgb_to_hsv_uint8
      (Autonomous_Driving_DW.ImageTransform_AlgHandle,
       &Autonomous_Driving_B.imageToThreshold[0], 273, 205,
       &Autonomous_Driving_B.ImageTransform[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Gain: '<S29>/Gain' incorporates:
   *  Constant: '<S21>/Hue Max'
   *  Constant: '<S21>/Hue Min'
   *  Sum: '<S29>/Add'
   */
  rtb_Add1 = (Autonomous_Driving_P.HueMin_Value +
              Autonomous_Driving_P.HueMax_Value) *
    Autonomous_Driving_P.Gain_Gain_d;

  /* Sum: '<S29>/Add1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Gain: '<S29>/20%'
   *  Gain: '<S49>/Slider Gain'
   *  Product: '<S29>/Product'
   */
  rtb_Add1 += Autonomous_Driving_P.u0_Gain * rtb_Add1 *
    (Autonomous_Driving_P.ColorSelectingMean0_gain *
     Autonomous_Driving_P.Constant_Value_ih);

  /* Product: '<S29>/Product5' incorporates:
   *  Constant: '<S21>/Constant7'
   *  Constant: '<S21>/Hue Max'
   *  Constant: '<S21>/Hue Min'
   *  Gain: '<S29>/Gain1'
   *  Gain: '<S50>/Slider Gain'
   *  Sum: '<S29>/Subtract'
   */
  rtb_Product5 = (Autonomous_Driving_P.HueMax_Value -
                  Autonomous_Driving_P.HueMin_Value) *
    Autonomous_Driving_P.Gain1_Gain *
    (Autonomous_Driving_P.ColorSelectingWindow1_gain *
     Autonomous_Driving_P.Constant7_Value);

  /* Sum: '<S29>/Subtract1' */
  Autonomous_Driving_B.Subtract1 = rtb_Add1 - rtb_Product5;

  /* Gain: '<S29>/Gain2' incorporates:
   *  Constant: '<S21>/Sat Max'
   *  Constant: '<S21>/Sat Min'
   *  Sum: '<S29>/Add3'
   */
  rtb_Add4 = (Autonomous_Driving_P.SatMin_Value +
              Autonomous_Driving_P.SatMax_Value) *
    Autonomous_Driving_P.Gain2_Gain;

  /* Sum: '<S29>/Add4' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Gain: '<S29>/20%1'
   *  Gain: '<S47>/Slider Gain'
   *  Product: '<S29>/Product1'
   */
  rtb_Add4 += Autonomous_Driving_P.u01_Gain * rtb_Add4 *
    (Autonomous_Driving_P.ColorMixingMean0_gain *
     Autonomous_Driving_P.Constant1_Value_o);

  /* Product: '<S29>/Product4' incorporates:
   *  Constant: '<S21>/Constant6'
   *  Constant: '<S21>/Sat Max'
   *  Constant: '<S21>/Sat Min'
   *  Gain: '<S29>/Gain3'
   *  Gain: '<S48>/Slider Gain'
   *  Sum: '<S29>/Subtract2'
   */
  rtb_Product4 = (Autonomous_Driving_P.SatMax_Value -
                  Autonomous_Driving_P.SatMin_Value) *
    Autonomous_Driving_P.Gain3_Gain *
    (Autonomous_Driving_P.ColorMixingWindow1_gain *
     Autonomous_Driving_P.Constant6_Value_l);

  /* Sum: '<S29>/Subtract3' */
  Autonomous_Driving_B.Subtract3 = rtb_Add4 - rtb_Product4;

  /* Gain: '<S29>/Gain4' incorporates:
   *  Constant: '<S21>/Val Max'
   *  Constant: '<S21>/Val Min'
   *  Sum: '<S29>/Add6'
   */
  rtb_Add7 = (Autonomous_Driving_P.ValMin_Value +
              Autonomous_Driving_P.ValMax_Value) *
    Autonomous_Driving_P.Gain4_Gain;

  /* Sum: '<S29>/Add7' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Gain: '<S29>/20%2'
   *  Gain: '<S45>/Slider Gain'
   *  Product: '<S29>/Product2'
   */
  rtb_Add7 += Autonomous_Driving_P.u02_Gain * rtb_Add7 *
    (Autonomous_Driving_P.BrightnessMean0_gain *
     Autonomous_Driving_P.Constant2_Value_a);

  /* Product: '<S29>/Product3' incorporates:
   *  Constant: '<S21>/Constant5'
   *  Constant: '<S21>/Val Max'
   *  Constant: '<S21>/Val Min'
   *  Gain: '<S29>/Gain5'
   *  Gain: '<S46>/Slider Gain'
   *  Sum: '<S29>/Subtract4'
   */
  rtb_SliderGain_b = (Autonomous_Driving_P.ValMax_Value -
                      Autonomous_Driving_P.ValMin_Value) *
    Autonomous_Driving_P.Gain5_Gain *
    (Autonomous_Driving_P.BrightnessWindow1_gain *
     Autonomous_Driving_P.Constant5_Value_b);

  /* Sum: '<S29>/Subtract5' */
  Autonomous_Driving_B.Subtract5 = rtb_Add7 - rtb_SliderGain_b;

  /* Gain: '<S29>/Gain6' */
  u0 = Autonomous_Driving_P.Gain6_Gain * Autonomous_Driving_B.Subtract1;

  /* Saturate: '<S29>/Saturation' */
  if (u0 > Autonomous_Driving_P.Saturation_UpperSat_i[0]) {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[0] =
      Autonomous_Driving_P.Saturation_UpperSat_i[0];
  } else if (u0 < Autonomous_Driving_P.Saturation_LowerSat_g[0]) {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[0] =
      Autonomous_Driving_P.Saturation_LowerSat_g[0];
  } else {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[0] = u0;
  }

  if (Autonomous_Driving_B.Subtract3 >
      Autonomous_Driving_P.Saturation_UpperSat_i[1]) {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[1] =
      Autonomous_Driving_P.Saturation_UpperSat_i[1];
  } else if (Autonomous_Driving_B.Subtract3 <
             Autonomous_Driving_P.Saturation_LowerSat_g[1]) {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[1] =
      Autonomous_Driving_P.Saturation_LowerSat_g[1];
  } else {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[1] = Autonomous_Driving_B.Subtract3;
  }

  if (Autonomous_Driving_B.Subtract5 >
      Autonomous_Driving_P.Saturation_UpperSat_i[2]) {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[2] =
      Autonomous_Driving_P.Saturation_UpperSat_i[2];
  } else if (Autonomous_Driving_B.Subtract5 <
             Autonomous_Driving_P.Saturation_LowerSat_g[2]) {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[2] =
      Autonomous_Driving_P.Saturation_LowerSat_g[2];
  } else {
    /* Saturate: '<S29>/Saturation' */
    Autonomous_Driving_B.Saturation[2] = Autonomous_Driving_B.Subtract5;
  }

  /* End of Saturate: '<S29>/Saturation' */

  /* Sum: '<S29>/Add2' */
  Autonomous_Driving_B.Add2 = rtb_Add1 + rtb_Product5;

  /* Sum: '<S29>/Add5' */
  Autonomous_Driving_B.Add5 = rtb_Add4 + rtb_Product4;

  /* Sum: '<S29>/Add8' */
  Autonomous_Driving_B.Add8 = rtb_Add7 + rtb_SliderGain_b;

  /* Gain: '<S29>/Gain7' */
  u0 = Autonomous_Driving_P.Gain7_Gain * Autonomous_Driving_B.Add2;

  /* Saturate: '<S29>/Saturation1' */
  if (u0 > Autonomous_Driving_P.Saturation1_UpperSat_d[0]) {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[0] =
      Autonomous_Driving_P.Saturation1_UpperSat_d[0];
  } else if (u0 < Autonomous_Driving_P.Saturation1_LowerSat_o[0]) {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[0] =
      Autonomous_Driving_P.Saturation1_LowerSat_o[0];
  } else {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[0] = u0;
  }

  if (Autonomous_Driving_B.Add5 > Autonomous_Driving_P.Saturation1_UpperSat_d[1])
  {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[1] =
      Autonomous_Driving_P.Saturation1_UpperSat_d[1];
  } else if (Autonomous_Driving_B.Add5 <
             Autonomous_Driving_P.Saturation1_LowerSat_o[1]) {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[1] =
      Autonomous_Driving_P.Saturation1_LowerSat_o[1];
  } else {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[1] = Autonomous_Driving_B.Add5;
  }

  if (Autonomous_Driving_B.Add8 > Autonomous_Driving_P.Saturation1_UpperSat_d[2])
  {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[2] =
      Autonomous_Driving_P.Saturation1_UpperSat_d[2];
  } else if (Autonomous_Driving_B.Add8 <
             Autonomous_Driving_P.Saturation1_LowerSat_o[2]) {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[2] =
      Autonomous_Driving_P.Saturation1_LowerSat_o[2];
  } else {
    /* Saturate: '<S29>/Saturation1' */
    Autonomous_Driving_B.Saturation1[2] = Autonomous_Driving_B.Add8;
  }

  /* End of Saturate: '<S29>/Saturation1' */

  /* S-Function (image_compare_block): '<S12>/HSV Color Thresholding' */

  /* S-Function Block: Autonomous_Driving/colorThresholdingHSV/HSV Color Thresholding (image_compare_block) */
  {
    t_error result;
    t_image_comparison_type comparisons[3];
    t_uint8 minimums[3];
    t_uint8 maximums[3];
    comparisons[0] = (t_image_comparison_type)
      (Autonomous_Driving_P.HSVColorThresholding_r_comparis - 1);
    comparisons[1] = (t_image_comparison_type)
      (Autonomous_Driving_P.HSVColorThresholding_g_comparis - 1);
    comparisons[2] = (t_image_comparison_type)
      (Autonomous_Driving_P.HSVColorThresholding_b_comparis - 1);
    if ((comparisons[0] & COMPARE_WRAP) == 0) {
      if (Autonomous_Driving_B.Saturation[0] < 0) {
        minimums[0] = 0;
      } else if (Autonomous_Driving_B.Saturation[0] > 255U) {
        minimums[0] = 255U;
      } else {
        minimums[0] = (t_uint8) Autonomous_Driving_B.Saturation[0];
      }

      if (Autonomous_Driving_B.Saturation1[0] < 0) {
        maximums[0] = 0;
      } else if (Autonomous_Driving_B.Saturation1[0] > 255U) {
        maximums[0] = 255U;
      } else {
        maximums[0] = (t_uint8) Autonomous_Driving_B.Saturation1[0];
      }
    } else {
      minimums[0] = (t_uint8) (Autonomous_Driving_B.Saturation[0] - 256U * floor
        (Autonomous_Driving_B.Saturation[0] / 256U));
      maximums[0] = (t_uint8) (Autonomous_Driving_B.Saturation1[0] - 256U *
        floor(Autonomous_Driving_B.Saturation1[0] / 256U));
    }

    if ((comparisons[1] & COMPARE_WRAP) == 0) {
      if (Autonomous_Driving_B.Saturation[1] < 0) {
        minimums[1] = 0;
      } else if (Autonomous_Driving_B.Saturation[1] > 255U) {
        minimums[1] = 255U;
      } else {
        minimums[1] = (t_uint8) Autonomous_Driving_B.Saturation[1];
      }

      if (Autonomous_Driving_B.Saturation1[1] < 0) {
        maximums[1] = 0;
      } else if (Autonomous_Driving_B.Saturation1[1] > 255U) {
        maximums[1] = 255U;
      } else {
        maximums[1] = (t_uint8) Autonomous_Driving_B.Saturation1[1];
      }
    } else {
      minimums[1] = (t_uint8) (Autonomous_Driving_B.Saturation[1] - 256U * floor
        (Autonomous_Driving_B.Saturation[1] / 256U));
      maximums[1] = (t_uint8) (Autonomous_Driving_B.Saturation1[1] - 256U *
        floor(Autonomous_Driving_B.Saturation1[1] / 256U));
    }

    if ((comparisons[2] & COMPARE_WRAP) == 0) {
      if (Autonomous_Driving_B.Saturation[2] < 0) {
        minimums[2] = 0;
      } else if (Autonomous_Driving_B.Saturation[2] > 255U) {
        minimums[2] = 255U;
      } else {
        minimums[2] = (t_uint8) Autonomous_Driving_B.Saturation[2];
      }

      if (Autonomous_Driving_B.Saturation1[2] < 0) {
        maximums[2] = 0;
      } else if (Autonomous_Driving_B.Saturation1[2] > 255U) {
        maximums[2] = 255U;
      } else {
        maximums[2] = (t_uint8) Autonomous_Driving_B.Saturation1[2];
      }
    } else {
      minimums[2] = (t_uint8) (Autonomous_Driving_B.Saturation[2] - 256U * floor
        (Autonomous_Driving_B.Saturation[2] / 256U));
      maximums[2] = (t_uint8) (Autonomous_Driving_B.Saturation1[2] - 256U *
        floor(Autonomous_Driving_B.Saturation1[2] / 256U));
    }

    result = image_rgb_compare_range_uint8(&Autonomous_Driving_B.ImageTransform
      [0], 273, 205, comparisons, minimums, maximums, COMPARE_OUTPUT_COMBINED,
      &Autonomous_Driving_B.HSVColorThresholding[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* MATLAB Function: '<S19>/Quick Resize' incorporates:
   *  S-Function (image_compare_block): '<S12>/HSV Color Thresholding'
   */
  for (b_k = 0; b_k < 91; b_k++) {
    for (i_1 = 0; i_1 < 69; i_1++) {
      Autonomous_Driving_B.y_b[i_1 + 69 * b_k] =
        Autonomous_Driving_B.HSVColorThresholding[3 * b_k * 205 + 3 * i_1];
    }
  }

  /* End of MATLAB Function: '<S19>/Quick Resize' */

  /* MATLAB Function: '<S19>/Quick Resize1' incorporates:
   *  S-Function (video_capture_block): '<S10>/Video Capture'
   */
  for (b_k = 0; b_k < 3; b_k++) {
    for (i_1 = 0; i_1 < 274; i_1++) {
      for (i_0 = 0; i_0 < 137; i_0++) {
        Autonomous_Driving_B.y_m[(i_0 + 137 * i_1) + 37538 * b_k] =
          Autonomous_Driving_B.VideoCapture_o1[(3 * i_1 * 410 + 3 * i_0) +
          336200 * b_k];
      }
    }
  }

  /* End of MATLAB Function: '<S19>/Quick Resize1' */

  /* Bias: '<S19>/Bias' incorporates:
   *  Gain: '<S19>/Gain'
   *  RateTransition: '<Root>/Rate Transition5'
   *  Rounding: '<S19>/Floor'
   */
  rtb_Add1 = floor(Autonomous_Driving_P.Gain_Gain_a *
                   Autonomous_Driving_DW.RateTransition5_Buffer) +
    Autonomous_Driving_P.Bias_Bias;

  /* MATLAB Function: '<S19>/Combine images' */
  memcpy(&Autonomous_Driving_B.y_d[0], &Autonomous_Driving_B.y_m[0], 112614U *
         sizeof(uint8_T));
  Autonomous_Drivi_emxInit_real_T(&b_0, 2);

  /* MATLAB Function: '<S19>/Combine images' */
  if (rtIsNaN(rtb_Add1)) {
    i_1 = b_0->size[0] * b_0->size[1];
    b_0->size[1] = 1;
    Autono_emxEnsureCapacity_real_T(b_0, i_1);
  } else if (137.0 < rtb_Add1) {
    b_0->size[1] = 0;
  } else if (rtIsInf(rtb_Add1) && (rtb_Add1 == 137.0)) {
    i_1 = b_0->size[0] * b_0->size[1];
    b_0->size[1] = 1;
    Autono_emxEnsureCapacity_real_T(b_0, i_1);
  } else if (floor(rtb_Add1) == rtb_Add1) {
    i_1 = b_0->size[0] * b_0->size[1];
    b_0->size[0] = 1;
    b_0->size[1] = (int32_T)(137.0 - rtb_Add1) + 1;
    Autono_emxEnsureCapacity_real_T(b_0, i_1);
    loop_ub = (int32_T)(137.0 - rtb_Add1);
    for (b_k = 0; b_k <= loop_ub; b_k++) {
      b_0->data[b_k] = rtb_Add1 + (real_T)b_k;
    }
  } else {
    Autonomous_Driv_eml_float_colon(rtb_Add1, b_0);
  }

  if (70 - b_0->size[1] > 69) {
    i = 0;
    c_nx = 0;
  } else {
    i = 69 - b_0->size[1];
    c_nx = 69;
  }

  Autonomous_Drivi_emxFree_real_T(&b_0);

  /* MATLAB Function: '<S19>/Combine images' incorporates:
   *  Constant: '<S19>/Constant4'
   */
  if (Autonomous_Driving_P.Constant4_Value_a != 0.0) {
    if (rtb_uRight0Left != 0.0) {
      if (rtb_Add1 > 137.0) {
        n = 0;
        b_k = -1;
      } else {
        n = (int32_T)rtb_Add1 - 1;
        b_k = 136;
      }

      loop_ub = b_k - n;
      section_size_idx_0 = loop_ub + 1;
      for (b_k = 0; b_k < 3; b_k++) {
        for (i_1 = 0; i_1 < 91; i_1++) {
          for (i_0 = 0; i_0 <= loop_ub; i_0++) {
            Autonomous_Driving_B.section_data[(i_0 + (loop_ub + 1) * i_1) +
              (loop_ub + 1) * 91 * b_k] = Autonomous_Driving_B.y_m[((((int32_T)
              ((real_T)i_1 + 183.66666666666666) - 1) * 137 + n) + i_0) + 37538 *
              b_k];
          }
        }
      }

      loop_ub = c_nx - i;
      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          Autonomous_Driving_B.x_tmp_data[i_1 + loop_ub * b_k] = (uint8_T)(255U
            - Autonomous_Driving_B.y_b[(i + i_1) + 69 * b_k]);
        }
      }

      c_nx = loop_ub * 91;
      for (b_k = 0; b_k < c_nx; b_k++) {
        Autonomous_Driving_B.o_data[b_k] = (int8_T)rt_roundd_snf((real_T)
          Autonomous_Driving_B.x_tmp_data[b_k] / 255.0);
      }

      if (rtb_Add1 > 137.0) {
        b = 1;
      } else {
        b = (int32_T)rtb_Add1;
      }

      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          section = Autonomous_Driving_B.section_data[i_1 + section_size_idx_0 *
            b_k];
          i_0 = (int32_T)((uint32_T)Autonomous_Driving_B.y_b[(i + i_1) + 69 *
                          b_k] * section);
          if ((uint32_T)i_0 > 255U) {
            i_0 = 255;
          }

          i_0 += (uint32_T)Autonomous_Driving_B.o_data[i_1 + loop_ub * b_k] *
            section;
          if ((uint32_T)i_0 > 255U) {
            i_0 = 255;
          }

          Autonomous_Driving_B.y_d[((b + i_1) + 137 * ((int32_T)((real_T)b_k +
            183.66666666666666) - 1)) - 1] = (uint8_T)i_0;
        }
      }

      for (i = 0; i < c_nx; i++) {
        Autonomous_Driving_B.o_data[i] = (int8_T)rt_roundd_snf((real_T)
          Autonomous_Driving_B.x_tmp_data[i] / 255.0);
      }

      if (rtb_Add1 > 137.0) {
        b = 1;
      } else {
        b = (int32_T)rtb_Add1;
      }

      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          Autonomous_Driving_B.y_d[((b + i_1) + 137 * ((int32_T)((real_T)b_k +
            183.66666666666666) - 1)) + 37537] = (uint8_T)((uint32_T)
            Autonomous_Driving_B.o_data[i_1 + loop_ub * b_k] *
            Autonomous_Driving_B.section_data[(i_1 + section_size_idx_0 * b_k) +
            section_size_idx_0 * 91]);
        }
      }

      for (i = 0; i < c_nx; i++) {
        Autonomous_Driving_B.o_data[i] = (int8_T)rt_roundd_snf((real_T)
          Autonomous_Driving_B.x_tmp_data[i] / 255.0);
      }

      if (rtb_Add1 > 137.0) {
        b = 1;
      } else {
        b = (int32_T)rtb_Add1;
      }

      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          Autonomous_Driving_B.y_d[((b + i_1) + 137 * ((int32_T)((real_T)b_k +
            183.66666666666666) - 1)) + 75075] = (uint8_T)((uint32_T)
            Autonomous_Driving_B.o_data[i_1 + loop_ub * b_k] *
            Autonomous_Driving_B.section_data[(i_1 + section_size_idx_0 * b_k) +
            ((section_size_idx_0 * 91) << 1)]);
        }
      }
    } else {
      if (rtb_Add1 > 137.0) {
        n = 0;
      } else {
        n = (int32_T)rtb_Add1 - 1;
      }

      loop_ub = c_nx - i;
      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          Autonomous_Driving_B.x_tmp_data[i_1 + loop_ub * b_k] = (uint8_T)(255U
            - Autonomous_Driving_B.y_b[(i + i_1) + 69 * b_k]);
        }
      }

      c_nx = loop_ub * 91;
      for (b_k = 0; b_k < c_nx; b_k++) {
        Autonomous_Driving_B.o_data[b_k] = (int8_T)rt_roundd_snf((real_T)
          Autonomous_Driving_B.x_tmp_data[b_k] / 255.0);
      }

      if (rtb_Add1 > 137.0) {
        b = 1;
      } else {
        b = (int32_T)rtb_Add1;
      }

      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          tmp = Autonomous_Driving_B.y_m[(n + i_1) + 137 * b_k];
          i_0 = (int32_T)(Autonomous_Driving_B.y_b[(i + i_1) + 69 * b_k] * tmp);
          if ((uint32_T)i_0 > 255U) {
            i_0 = 255;
          }

          i_0 += tmp * Autonomous_Driving_B.o_data[i_1 + loop_ub * b_k];
          if ((uint32_T)i_0 > 255U) {
            i_0 = 255;
          }

          Autonomous_Driving_B.y_d[((b + i_1) + 137 * b_k) - 1] = (uint8_T)i_0;
        }
      }

      c_nx = loop_ub * 91;
      for (i = 0; i < c_nx; i++) {
        Autonomous_Driving_B.o_data[i] = (int8_T)rt_roundd_snf((real_T)
          Autonomous_Driving_B.x_tmp_data[i] / 255.0);
      }

      if (rtb_Add1 > 137.0) {
        b = 1;
      } else {
        b = (int32_T)rtb_Add1;
      }

      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          Autonomous_Driving_B.y_d[((b + i_1) + 137 * b_k) + 37537] = (uint8_T)
            ((uint32_T)Autonomous_Driving_B.y_m[((n + i_1) + 137 * b_k) + 37538]
             * Autonomous_Driving_B.o_data[i_1 + loop_ub * b_k]);
        }
      }

      c_nx = loop_ub * 91;
      for (i = 0; i < c_nx; i++) {
        Autonomous_Driving_B.o_data[i] = (int8_T)rt_roundd_snf((real_T)
          Autonomous_Driving_B.x_tmp_data[i] / 255.0);
      }

      if (rtb_Add1 > 137.0) {
        b = 1;
      } else {
        b = (int32_T)rtb_Add1;
      }

      for (b_k = 0; b_k < 91; b_k++) {
        for (i_1 = 0; i_1 < loop_ub; i_1++) {
          Autonomous_Driving_B.y_d[((b + i_1) + 137 * b_k) + 75075] = (uint8_T)
            ((uint32_T)Autonomous_Driving_B.y_m[((n + i_1) + 137 * b_k) + 75076]
             * Autonomous_Driving_B.o_data[i_1 + loop_ub * b_k]);
        }
      }
    }
  }

  /* S-Function (image_compress_block): '<S23>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/Display RGB/RGB Image Processed/Image Compress (image_compress_block) */
  {
    t_error result = 0;
    size_t image_size = 0;
    result = qjpeg_compress_start(Autonomous_Driving_DW.ImageCompress_Compress,
      true);
    if (result == 0) {
      result = qjpeg_compress_write_image_uint8
        (Autonomous_Driving_DW.ImageCompress_Compress,
         &Autonomous_Driving_B.y_d[0]);
      qjpeg_compress_stop(Autonomous_Driving_DW.ImageCompress_Compress);

      /* Get the final size of the compressed image */
      if (result >= 0) {
        result = qjpeg_compress_get_fixed_memory_destination_size
          (Autonomous_Driving_DW.ImageCompress_Compress, &image_size);
      }
    }

    /* Set the dimensions of the output signal based on the size of the compressed image */
    Autonomous_Driving_DW.ImageCompress_DIMS1 = (int) image_size;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* S-Function (channel_block): '<S23>/Channel' */

  /* S-Function Block: Autonomous_Driving/Display RGB/RGB Image Processed/Channel (channel_block) */
  {
    struct channel_info {
      t_channel_header header;
    } info;

    size_t width = 1;
    Autonomous_Driving_B.Channel = CHANNEL_1;
    info.header.data_type_id = 3;
    info.header.channel = 1;
    info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
    info.header.num_dimensions = 1;
    width *= Autonomous_Driving_DW.ImageCompress_DIMS1;
    info.header.dimension[0] = Autonomous_Driving_DW.ImageCompress_DIMS1;
    channel_fifo_add((t_channel_fifo) Autonomous_Driving_DW.Channel_PWORK.Fifo,
                     &info.header, &Autonomous_Driving_B.ImageCompress[0], width
                     * sizeof(uint8_T));
  }

  /* S-Function (image_compress_block): '<S24>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/RGB Image  Pre-Proccessing/RGB Image No Threshold/Image Compress (image_compress_block) */
  {
    t_error result = 0;
    size_t image_size = 0;
    result = qjpeg_compress_start(Autonomous_Driving_DW.ImageCompress_Compress_c,
      true);
    if (result == 0) {
      result = qjpeg_compress_write_image_uint8
        (Autonomous_Driving_DW.ImageCompress_Compress_c,
         &Autonomous_Driving_B.imageToThreshold[0]);
      qjpeg_compress_stop(Autonomous_Driving_DW.ImageCompress_Compress_c);

      /* Get the final size of the compressed image */
      if (result >= 0) {
        result = qjpeg_compress_get_fixed_memory_destination_size
          (Autonomous_Driving_DW.ImageCompress_Compress_c, &image_size);
      }
    }

    /* Set the dimensions of the output signal based on the size of the compressed image */
    Autonomous_Driving_DW.ImageCompress_DIMS1_m = (int) image_size;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* S-Function (channel_block): '<S24>/Channel' */

  /* S-Function Block: Autonomous_Driving/RGB Image  Pre-Proccessing/RGB Image No Threshold/Channel (channel_block) */
  {
    struct channel_info {
      t_channel_header header;
    } info;

    size_t width = 1;
    Autonomous_Driving_B.Channel_b = CHANNEL_2;
    info.header.data_type_id = 3;
    info.header.channel = 2;
    info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
    info.header.num_dimensions = 1;
    width *= Autonomous_Driving_DW.ImageCompress_DIMS1_m;
    info.header.dimension[0] = Autonomous_Driving_DW.ImageCompress_DIMS1_m;
    channel_fifo_add((t_channel_fifo) Autonomous_Driving_DW.Channel_PWORK_b.Fifo,
                     &info.header, &Autonomous_Driving_B.ImageCompress_h[0],
                     width * sizeof(uint8_T));
  }

  /* MATLAB Function: '<S19>/Find slope and intercept' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  RateTransition: '<Root>/Rate Transition5'
   *  S-Function (image_compare_block): '<S12>/HSV Color Thresholding'
   */
  if ((205.0 - ((410.0 - Autonomous_Driving_DW.RateTransition5_Buffer) + 1.0)) +
      1.0 > 205.0) {
    c_nx = 0;
    b = 0;
  } else {
    c_nx = (int32_T)((205.0 - ((410.0 -
      Autonomous_Driving_DW.RateTransition5_Buffer) + 1.0)) + 1.0) - 1;
    b = 205;
  }

  loop_ub = b - c_nx;
  tmp_size[0] = loop_ub;
  tmp_size[1] = 273;
  for (b_k = 0; b_k < 273; b_k++) {
    for (i_1 = 0; i_1 < loop_ub; i_1++) {
      Autonomous_Driving_B.tmp_data[i_1 + loop_ub * b_k] =
        (Autonomous_Driving_B.HSVColorThresholding[(c_nx + i_1) + 205 * b_k] > 0);
    }
  }

  Autonomous_Driv_emxInit_real_T1(&x, 1);
  Autonomous_Driv_emxInit_int32_T(&ii, 1);
  Autonomous_Driv_emxInit_int32_T(&jj, 1);

  /* MATLAB Function: '<S19>/Find slope and intercept' */
  Autonomous_Driving_eml_find(Autonomous_Driving_B.tmp_data, tmp_size, ii, jj);
  i_1 = x->size[0];
  x->size[0] = jj->size[0];
  Auton_emxEnsureCapacity_real_T1(x, i_1);
  loop_ub = jj->size[0];
  for (b_k = 0; b_k < loop_ub; b_k++) {
    x->data[b_k] = jj->data[b_k];
  }

  Autonomous_Driv_emxFree_int32_T(&jj);

  /* MATLAB Function: '<S19>/Find slope and intercept' */
  if (rtb_uRight0Left != 0.0) {
    loop_ub = x->size[0];
    for (b_k = 0; b_k < loop_ub; b_k++) {
      x->data[b_k] = 273.33333333333331 - x->data[b_k];
    }
  }

  Autonomous_Driv_emxInit_real_T1(&rtb_imageSize_0, 1);

  /* MATLAB Function: '<S19>/Find slope and intercept' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  RateTransition: '<Root>/Rate Transition5'
   */
  i_1 = rtb_imageSize_0->size[0];
  rtb_imageSize_0->size[0] = ii->size[0];
  Auton_emxEnsureCapacity_real_T1(rtb_imageSize_0, i_1);
  loop_ub = ii->size[0];
  for (b_k = 0; b_k < loop_ub; b_k++) {
    rtb_imageSize_0->data[b_k] = ((410.0 -
      Autonomous_Driving_DW.RateTransition5_Buffer) + 1.0) - (real_T)ii->
      data[b_k];
  }

  Autonomous_Driv_emxFree_int32_T(&ii);

  /* MATLAB Function: '<S19>/Find slope and intercept' */
  Autonomous_Driving_polyfit(x, rtb_imageSize_0, result);
  Autonomous_Drivi_emxFree_real_T(&rtb_imageSize_0);
  Autonomous_Drivi_emxFree_real_T(&x);

  /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/m_n'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<S19>/Find slope and intercept'
   *  ManualSwitch: '<S19>/Manual Switch'
   *  RateTransition: '<Root>/Rate Transition5'
   */
  if (rtb_uRight0Left != 0.0) {
    /* ManualSwitch: '<S19>/Manual Switch' incorporates:
     *  Constant: '<S19>/b_n'
     *  Constant: '<S21>/b_n'
     *  Gain: '<S51>/Slider Gain'
     */
    if (Autonomous_Driving_P.ManualSwitch_CurrentSetting == 1) {
      rtb_uRight0Left = Autonomous_Driving_P.b_n_Value;
    } else {
      rtb_uRight0Left = Autonomous_Driving_P.DistaneToLane0_gain *
        Autonomous_Driving_P.b_n_Value_p;
    }

    rtb_uRight0Left = ((((410.0 - Autonomous_Driving_DW.RateTransition5_Buffer)
                         + 1.0) - rtb_uRight0Left) /
                       Autonomous_Driving_P.m_n_Value - (((410.0 -
      Autonomous_Driving_DW.RateTransition5_Buffer) + 1.0) - result[1]) /
                       result[0]) * -Autonomous_Driving_P.Constant3_Value_br /
      273.33333333333331;
  } else {
    if (Autonomous_Driving_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<S19>/Manual Switch' incorporates:
       *  Constant: '<S19>/b_n'
       */
      rtb_uRight0Left = Autonomous_Driving_P.b_n_Value;
    } else {
      /* ManualSwitch: '<S19>/Manual Switch' incorporates:
       *  Constant: '<S21>/b_n'
       *  Gain: '<S51>/Slider Gain'
       */
      rtb_uRight0Left = Autonomous_Driving_P.DistaneToLane0_gain *
        Autonomous_Driving_P.b_n_Value_p;
    }

    rtb_uRight0Left = ((((410.0 - Autonomous_Driving_DW.RateTransition5_Buffer)
                         + 1.0) - rtb_uRight0Left) /
                       Autonomous_Driving_P.m_n_Value - (((410.0 -
      Autonomous_Driving_DW.RateTransition5_Buffer) + 1.0) - result[1]) /
                       result[0]) * Autonomous_Driving_P.Constant3_Value_br /
      273.33333333333331;
  }

  /* End of MATLAB Function: '<S19>/MATLAB Function' */

  /* Saturate: '<S19>/Steering Saturation1' */
  if (rtb_uRight0Left > Autonomous_Driving_P.SteeringSaturation1_UpperSat) {
    /* Saturate: '<S19>/Steering Saturation1' */
    Autonomous_Driving_B.SteeringSaturation1 =
      Autonomous_Driving_P.SteeringSaturation1_UpperSat;
  } else if (rtb_uRight0Left < Autonomous_Driving_P.SteeringSaturation1_LowerSat)
  {
    /* Saturate: '<S19>/Steering Saturation1' */
    Autonomous_Driving_B.SteeringSaturation1 =
      Autonomous_Driving_P.SteeringSaturation1_LowerSat;
  } else {
    /* Saturate: '<S19>/Steering Saturation1' */
    Autonomous_Driving_B.SteeringSaturation1 = rtb_uRight0Left;
  }

  /* End of Saturate: '<S19>/Steering Saturation1' */

  /* RateTransition: '<Root>/Rate Transition' */
  Autonomous_Driving_DW.RateTransition_Buffer0 =
    Autonomous_Driving_B.SteeringSaturation1;

  /* S-Function (sample_time_block): '<S15>/Sample Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming 1/Sample Time (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &Autonomous_Driving_DW.SampleTime_PreviousTime_g);
      rtb_SampleTime = time_difference.seconds + time_difference.nanoseconds *
        1e-9;
      memcpy(&Autonomous_Driving_DW.SampleTime_PreviousTime_g, &current_time,
             sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }
  }

  /* S-Function (computation_time_block): '<S15>/Computation Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming 1/Computation Time (computation_time_block) */
  {
    rtb_ComputationTime =
      Autonomous_Driving_DW.ComputationTime_ComputationTi_o.seconds +
      Autonomous_Driving_DW.ComputationTime_ComputationTi_o.nanoseconds * 1e-9;
  }

  /* RateTransition: '<Root>/Rate Transition4' incorporates:
   *  Constant: '<S15>/Constant'
   */
  Autonomous_Driving_DW.RateTransition4_Buffer0[0] = rtb_SampleTime;
  Autonomous_Driving_DW.RateTransition4_Buffer0[1] =
    Autonomous_Driving_P.camera_rate;
  Autonomous_Driving_DW.RateTransition4_Buffer0[2] = rtb_ComputationTime;
}

/* Model update function for TID2 */
void Autonomous_Driving_update2(void)
                               /* Sample time: [0.0083333333333333332s, 0.0s] */
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
  if (!(++Autonomous_Driving_M->Timing.clockTick2)) {
    ++Autonomous_Driving_M->Timing.clockTickH2;
  }

  Autonomous_Driving_M->Timing.t[2] = Autonomous_Driving_M->Timing.clockTick2 *
    Autonomous_Driving_M->Timing.stepSize2 +
    Autonomous_Driving_M->Timing.clockTickH2 *
    Autonomous_Driving_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output function for TID3 */
void Autonomous_Driving_output3(void)  /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_SampleTime_n;
  real_T rtb_ComputationTime_h;
  emxArray_real_T_Autonomous_Dr_T *col_vec;
  emxArray_real_T_Autonomous_Dr_T *row_vec;
  emxArray_real_T_Autonomous_Dr_T *u_flat;
  emxArray_real_T_Autonomous_Dr_T *x;
  real_T rtb_Divide[10];
  real_T bsum;
  real_T rtb_Add_k;
  real_T rtb_RateTransition2;
  real_T rtb_RateTransition2_tmp;
  real_T rtb_RateTransition2_tmp_0;
  real_T rtb_y;
  int32_T c_i;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  real32_T tmp;
  uint8_T rtb_Selector;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Autonomous_Driving_DW.obstacleDetection_SubsysRanBC);

  /* S-Function (video3d_initialize_block): '<S11>/Video3D Initialize' */

  /* S-Function Block: Autonomous_Driving/captureDepth/Video3D Initialize (video3d_initialize_block) */
  {
  }

  /* S-Function (video3d_capture_block): '<S11>/Depth' */
  /* S-Function Block: Autonomous_Driving/captureDepth/Depth (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame(Autonomous_Driving_DW.Depth_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_meters(frame, &Autonomous_Driving_B.Depth_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    Autonomous_Driving_B.Depth_o4 = (result >= 0);
    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* RateTransition: '<Root>/Rate Transition2' */
  rtb_RateTransition2 = Autonomous_Driving_B.SteeringSaturation1;

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<S21>/Stopping Distance (m)'
   *  Gain: '<S53>/Slider Gain'
   */
  rtb_Add_k = Autonomous_Driving_P.StoppingDistanceOffset0_gain *
    Autonomous_Driving_P.StoppingDistancem_Value +
    Autonomous_Driving_P.StoppingDistancem_Value;

  /* Outputs for Enabled SubSystem: '<Root>/obstacleDetection' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (Autonomous_Driving_B.Depth_o4) {
    /* MATLAB Function: '<S17>/Steering based  image subselector' incorporates:
     *  S-Function (video3d_capture_block): '<S11>/Depth'
     */
    rtb_RateTransition2 = 320.0 - rtb_RateTransition2 * 260.0 / 0.5;
    for (lastBlockLength = 0; lastBlockLength < 120; lastBlockLength++) {
      for (nblocks = 0; nblocks < 120; nblocks++) {
        Autonomous_Driving_B.region[nblocks + 120 * lastBlockLength] =
          Autonomous_Driving_B.Depth_o1[(((int32_T)(((rtb_RateTransition2 + 1.0)
          - 60.0) + (real_T)lastBlockLength) - 1) * 360 + nblocks) + 120];
      }
    }

    /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
     *  Constant: '<S17>/Constant1'
     */
    lastBlockLength = 0;
    for (nblocks = 0; nblocks < 14400; nblocks++) {
      if (Autonomous_Driving_B.region[nblocks] <
          Autonomous_Driving_P.Constant1_Value) {
        lastBlockLength++;
      }
    }

    Autonomous_Driv_emxInit_real_T1(&u_flat, 1);

    /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     */
    firstBlockLength = u_flat->size[0];
    u_flat->size[0] = lastBlockLength;
    Auton_emxEnsureCapacity_real_T1(u_flat, firstBlockLength);
    nblocks = 0;
    for (lastBlockLength = 0; lastBlockLength < 14400; lastBlockLength++) {
      rtb_y = Autonomous_Driving_B.region[lastBlockLength];
      if (rtb_y < Autonomous_Driving_P.Constant1_Value) {
        u_flat->data[nblocks] = rtb_y;
        nblocks++;
      }
    }

    nblocks = u_flat->size[0] - 1;
    lastBlockLength = 0;
    for (c_i = 0; c_i <= nblocks; c_i++) {
      if (u_flat->data[c_i] > Autonomous_Driving_P.Constant_Value) {
        lastBlockLength++;
      }
    }

    firstBlockLength = u_flat->size[0];
    u_flat->size[0] = lastBlockLength;
    Auton_emxEnsureCapacity_real_T1(u_flat, firstBlockLength);
    lastBlockLength = 0;
    for (c_i = 0; c_i <= nblocks; c_i++) {
      if (u_flat->data[c_i] > Autonomous_Driving_P.Constant_Value) {
        u_flat->data[lastBlockLength] = Autonomous_Driving_B.region[c_i];
        lastBlockLength++;
      }
    }

    if (u_flat->size[0] == 0) {
      rtb_y = 0.0;
    } else {
      if (u_flat->size[0] <= 1024) {
        firstBlockLength = u_flat->size[0];
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = u_flat->size[0] / 1024;
        lastBlockLength = u_flat->size[0] - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      rtb_y = u_flat->data[0];
      for (c_i = 2; c_i <= firstBlockLength; c_i++) {
        rtb_y += u_flat->data[c_i - 1];
      }

      for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
      {
        xblockoffset = (firstBlockLength - 1) << 10;
        bsum = u_flat->data[xblockoffset];
        if (firstBlockLength == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (c_i = 2; c_i <= hi; c_i++) {
          bsum += u_flat->data[(xblockoffset + c_i) - 1];
        }

        rtb_y += bsum;
      }
    }

    rtb_y /= (real_T)u_flat->size[0];

    /* Product: '<S17>/Divide' incorporates:
     *  Constant: '<S17>/scale'
     *  MATLAB Function: '<S17>/Steering based  image subselector'
     */
    rtb_Divide[0] = 101.0 / Autonomous_Driving_P.scale_Value;
    bsum = ((rtb_RateTransition2 + 1.0) - 60.0) /
      Autonomous_Driving_P.scale_Value;
    rtb_Divide[5] = bsum;
    rtb_Divide[1] = 101.0 / Autonomous_Driving_P.scale_Value;
    rtb_RateTransition2 = (rtb_RateTransition2 + 60.0) /
      Autonomous_Driving_P.scale_Value;
    rtb_Divide[6] = rtb_RateTransition2;
    rtb_Divide[2] = 220.0 / Autonomous_Driving_P.scale_Value;
    rtb_Divide[7] = rtb_RateTransition2;
    rtb_Divide[3] = 220.0 / Autonomous_Driving_P.scale_Value;
    rtb_Divide[8] = bsum;
    rtb_Divide[4] = 101.0 / Autonomous_Driving_P.scale_Value;
    rtb_Divide[9] = bsum;
    Autonomous_Drivi_emxFree_real_T(&u_flat);

    /* Selector: '<S17>/Selector' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion'
     */
    for (lastBlockLength = 0; lastBlockLength < 214; lastBlockLength++) {
      for (nblocks = 0; nblocks < 120; nblocks++) {
        /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
         *  Gain: '<S17>/Gain'
         *  S-Function (video3d_capture_block): '<S11>/Depth'
         */
        tmp = floorf(Autonomous_Driving_B.Depth_o1[3 * lastBlockLength * 360 + 3
                     * nblocks] * Autonomous_Driving_P.Gain_Gain_g);
        if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
          tmp = 0.0F;
        } else {
          tmp = fmodf(tmp, 256.0F);
        }

        Autonomous_Driving_B.Selector[nblocks + 120 * lastBlockLength] =
          (uint8_T)(tmp < 0.0F ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp :
                    (int32_T)(uint8_T)tmp);
      }
    }

    /* End of Selector: '<S17>/Selector' */

    /* MATLAB Function: '<S17>/Draw Lines Module' incorporates:
     *  Selector: '<S17>/Selector'
     */
    for (lastBlockLength = 0; lastBlockLength < 25680; lastBlockLength++) {
      rtb_Selector = Autonomous_Driving_B.Selector[lastBlockLength];
      Autonomous_Driving_B.img_out[lastBlockLength] = rtb_Selector;
      Autonomous_Driving_B.img_out[lastBlockLength + 25680] = rtb_Selector;
      Autonomous_Driving_B.img_out[lastBlockLength + 51360] = rtb_Selector;
    }

    Autonomous_Drivi_emxInit_real_T(&row_vec, 2);
    Autonomous_Drivi_emxInit_real_T(&col_vec, 2);
    Autonomous_Drivi_emxInit_real_T(&x, 2);

    /* MATLAB Function: '<S17>/Draw Lines Module' incorporates:
     *  Constant: '<S17>/Constant3'
     *  Product: '<S17>/Divide'
     */
    for (nblocks = 0; nblocks < 4; nblocks++) {
      bsum = rtb_Divide[nblocks + 1];
      rtb_RateTransition2_tmp = rtb_Divide[nblocks + 5];
      rtb_RateTransition2_tmp_0 = rtb_Divide[nblocks + 6];
      rtb_RateTransition2 = fmax(fabs(rtb_Divide[nblocks] - bsum), fabs
        (rtb_RateTransition2_tmp - rtb_RateTransition2_tmp_0));
      Autonomous_Driving_linspace(rtb_Divide[nblocks], bsum, rtb_RateTransition2,
        x);
      firstBlockLength = row_vec->size[0] * row_vec->size[1];
      row_vec->size[0] = 1;
      row_vec->size[1] = x->size[1];
      Autono_emxEnsureCapacity_real_T(row_vec, firstBlockLength);
      c_i = x->size[1] - 1;
      for (lastBlockLength = 0; lastBlockLength <= c_i; lastBlockLength++) {
        row_vec->data[lastBlockLength] = x->data[lastBlockLength];
      }

      for (c_i = 0; c_i < x->size[1]; c_i++) {
        row_vec->data[c_i] = rt_roundd_snf(row_vec->data[c_i]);
      }

      Autonomous_Driving_linspace(rtb_RateTransition2_tmp,
        rtb_RateTransition2_tmp_0, rtb_RateTransition2, x);
      firstBlockLength = col_vec->size[0] * col_vec->size[1];
      col_vec->size[0] = 1;
      col_vec->size[1] = x->size[1];
      Autono_emxEnsureCapacity_real_T(col_vec, firstBlockLength);
      c_i = x->size[1] - 1;
      for (lastBlockLength = 0; lastBlockLength <= c_i; lastBlockLength++) {
        col_vec->data[lastBlockLength] = x->data[lastBlockLength];
      }

      for (c_i = 0; c_i < x->size[1]; c_i++) {
        col_vec->data[c_i] = rt_roundd_snf(col_vec->data[c_i]);
      }

      for (lastBlockLength = 0; lastBlockLength < (int32_T)rtb_RateTransition2;
           lastBlockLength++) {
        bsum = rt_roundd_snf(Autonomous_Driving_P.Constant3_Value[0]);
        if (bsum < 256.0) {
          if (bsum >= 0.0) {
            Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
              + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) - 1] =
              (uint8_T)bsum;
          } else {
            Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
              + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) - 1] = 0U;
          }
        } else {
          Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
            + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) - 1] =
            MAX_uint8_T;
        }

        bsum = rt_roundd_snf(Autonomous_Driving_P.Constant3_Value[1]);
        if (bsum < 256.0) {
          if (bsum >= 0.0) {
            Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
              + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) + 25679] =
              (uint8_T)bsum;
          } else {
            Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
              + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) + 25679] =
              0U;
          }
        } else {
          Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
            + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) + 25679] =
            MAX_uint8_T;
        }

        bsum = rt_roundd_snf(Autonomous_Driving_P.Constant3_Value[2]);
        if (bsum < 256.0) {
          if (bsum >= 0.0) {
            Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
              + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) + 51359] =
              (uint8_T)bsum;
          } else {
            Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
              + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) + 51359] =
              0U;
          }
        } else {
          Autonomous_Driving_B.img_out[((int32_T)row_vec->data[lastBlockLength]
            + 120 * ((int32_T)col_vec->data[lastBlockLength] - 1)) + 51359] =
            MAX_uint8_T;
        }
      }
    }

    Autonomous_Drivi_emxFree_real_T(&x);
    Autonomous_Drivi_emxFree_real_T(&col_vec);
    Autonomous_Drivi_emxFree_real_T(&row_vec);

    /* Product: '<S17>/Multiply' incorporates:
     *  Constant: '<S17>/Constant2'
     *  Logic: '<S17>/AND'
     *  S-Function (compare_block): '<S17>/Compare'
     *  S-Function (compare_block): '<S17>/Compare1'
     *  Sum: '<S21>/Add'
     */
    Autonomous_Driving_B.Multiply = (real_T)((rtb_y >= rtb_Add_k) && (rtb_y <
      Autonomous_Driving_P.Constant2_Value)) * rtb_y;
    if (rtmIsMajorTimeStep(Autonomous_Driving_M)) {
      srUpdateBC(Autonomous_Driving_DW.obstacleDetection_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/obstacleDetection' */

  /* S-Function (image_compress_block): '<S22>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/Display Depth/Depth Camera Information/Image Compress (image_compress_block) */
  {
    t_error result = 0;
    size_t image_size = 0;
    result = qjpeg_compress_start
      (Autonomous_Driving_DW.ImageCompress_Compress_cq, true);
    if (result == 0) {
      result = qjpeg_compress_write_image_uint8
        (Autonomous_Driving_DW.ImageCompress_Compress_cq,
         &Autonomous_Driving_B.img_out[0]);
      qjpeg_compress_stop(Autonomous_Driving_DW.ImageCompress_Compress_cq);

      /* Get the final size of the compressed image */
      if (result >= 0) {
        result = qjpeg_compress_get_fixed_memory_destination_size
          (Autonomous_Driving_DW.ImageCompress_Compress_cq, &image_size);
      }
    }

    /* Set the dimensions of the output signal based on the size of the compressed image */
    Autonomous_Driving_DW.ImageCompress_DIMS1_g = (int) image_size;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* S-Function (channel_block): '<S22>/Channel' */

  /* S-Function Block: Autonomous_Driving/Display Depth/Depth Camera Information/Channel (channel_block) */
  {
    struct channel_info {
      t_channel_header header;
    } info;

    size_t width = 1;
    Autonomous_Driving_B.Channel_g = CHANNEL_0;
    info.header.data_type_id = 3;
    info.header.channel = 0;
    info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
    info.header.num_dimensions = 1;
    width *= Autonomous_Driving_DW.ImageCompress_DIMS1_g;
    info.header.dimension[0] = Autonomous_Driving_DW.ImageCompress_DIMS1_g;
    channel_fifo_add((t_channel_fifo) Autonomous_Driving_DW.Channel_PWORK_m.Fifo,
                     &info.header, &Autonomous_Driving_B.ImageCompress_o[0],
                     width * sizeof(uint8_T));
  }

  /* RateTransition: '<Root>/Rate Transition1' */
  Autonomous_Driving_DW.RateTransition1_Buffer0 = Autonomous_Driving_B.Multiply;

  /* S-Function (sample_time_block): '<S16>/Sample Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming 2/Sample Time (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &Autonomous_Driving_DW.SampleTime_PreviousTime_e);
      rtb_SampleTime_n = time_difference.seconds + time_difference.nanoseconds *
        1e-9;
      memcpy(&Autonomous_Driving_DW.SampleTime_PreviousTime_e, &current_time,
             sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }
  }

  /* S-Function (computation_time_block): '<S16>/Computation Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming 2/Computation Time (computation_time_block) */
  {
    rtb_ComputationTime_h =
      Autonomous_Driving_DW.ComputationTime_ComputationT_om.seconds +
      Autonomous_Driving_DW.ComputationTime_ComputationT_om.nanoseconds * 1e-9;
  }

  /* RateTransition: '<Root>/Rate Transition3' incorporates:
   *  Constant: '<S16>/Constant'
   */
  Autonomous_Driving_DW.RateTransition3_Buffer0[0] = rtb_SampleTime_n;
  Autonomous_Driving_DW.RateTransition3_Buffer0[1] =
    Autonomous_Driving_P.depth_rate;
  Autonomous_Driving_DW.RateTransition3_Buffer0[2] = rtb_ComputationTime_h;
}

/* Model update function for TID3 */
void Autonomous_Driving_update3(void)  /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick3"
   * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick3 and the high bits
   * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Autonomous_Driving_M->Timing.clockTick3)) {
    ++Autonomous_Driving_M->Timing.clockTickH3;
  }

  Autonomous_Driving_M->Timing.t[3] = Autonomous_Driving_M->Timing.clockTick3 *
    Autonomous_Driving_M->Timing.stepSize3 +
    Autonomous_Driving_M->Timing.clockTickH3 *
    Autonomous_Driving_M->Timing.stepSize3 * 4294967296.0;
}

/* Model wrapper function for compatibility with a static main program */
void Autonomous_Driving_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Autonomous_Driving_output0();
    break;

   case 2 :
    Autonomous_Driving_output2();
    break;

   case 3 :
    Autonomous_Driving_output3();
    break;

   default :
    break;
  }
}

/* Model wrapper function for compatibility with a static main program */
void Autonomous_Driving_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Autonomous_Driving_update0();
    break;

   case 2 :
    Autonomous_Driving_update2();
    break;

   case 3 :
    Autonomous_Driving_update3();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Autonomous_Driving_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S8>/HIL Initialize' */

  /* S-Function Block: Autonomous_Driving/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Autonomous_Driving_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Autonomous_Driving_DW.HILInitialize_Card,
       "gyro_fs=250;gyro_rate=64;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
       251);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Autonomous_Driving_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }

    if ((Autonomous_Driving_P.HILInitialize_AIPStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Autonomous_Driving_DW.HILInitialize_AIMinimums
          [0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Autonomous_Driving_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Autonomous_Driving_DW.HILInitialize_AIMaximums
          [0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Autonomous_Driving_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Autonomous_Driving_DW.HILInitialize_Card,
         Autonomous_Driving_P.HILInitialize_AIChannels, 7U,
         &Autonomous_Driving_DW.HILInitialize_AIMinimums[0],
         &Autonomous_Driving_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Autonomous_Driving_DW.HILInitialize_Card,
      Autonomous_Driving_P.HILInitialize_DIChannels, 20U,
      &Autonomous_Driving_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }

    if ((Autonomous_Driving_P.HILInitialize_DOStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Autonomous_Driving_DW.HILInitialize_Card,
        &Autonomous_Driving_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Autonomous_Driving_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    if ((Autonomous_Driving_P.HILInitialize_EIPStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_EIPEnter && is_switching)) {
      Autonomous_Driving_DW.HILInitialize_QuadratureModes[0] =
        (Autonomous_Driving_P.HILInitialize_EIQuadrature[0]);
      Autonomous_Driving_DW.HILInitialize_QuadratureModes[1] =
        (Autonomous_Driving_P.HILInitialize_EIQuadrature[1]);
      Autonomous_Driving_DW.HILInitialize_QuadratureModes[2] =
        (Autonomous_Driving_P.HILInitialize_EIQuadrature[1]);
      Autonomous_Driving_DW.HILInitialize_QuadratureModes[3] =
        (Autonomous_Driving_P.HILInitialize_EIQuadrature[1]);
      Autonomous_Driving_DW.HILInitialize_QuadratureModes[4] =
        (Autonomous_Driving_P.HILInitialize_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (Autonomous_Driving_DW.HILInitialize_Card,
         Autonomous_Driving_P.HILInitialize_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &Autonomous_Driving_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &Autonomous_Driving_DW.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] =
            Autonomous_Driving_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (Autonomous_Driving_DW.HILInitialize_Card,
         Autonomous_Driving_P.HILInitialize_EIChannels, 5U,
         &Autonomous_Driving_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    if ((Autonomous_Driving_P.HILInitialize_EIStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Autonomous_Driving_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = Autonomous_Driving_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Autonomous_Driving_DW.HILInitialize_Card,
        Autonomous_Driving_P.HILInitialize_EIChannels, 5U,
        &Autonomous_Driving_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    if ((Autonomous_Driving_P.HILInitialize_POPStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      Autonomous_Driving_DW.HILInitialize_POModeValues[0] =
        (Autonomous_Driving_P.HILInitialize_POModes[0]);

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Autonomous_Driving_DW.HILInitialize_POModeValues[1];
        for (i1=0; i1 < 7; i1++) {
          dw_POModeValues[i1] = (Autonomous_Driving_P.HILInitialize_POModes[1]);
        }
      }

      result = hil_set_pwm_mode(Autonomous_Driving_DW.HILInitialize_Card,
        Autonomous_Driving_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Autonomous_Driving_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Autonomous_Driving_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &Autonomous_Driving_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Autonomous_Driving_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            Autonomous_Driving_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Autonomous_Driving_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Autonomous_Driving_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            Autonomous_Driving_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Autonomous_Driving_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Autonomous_Driving_DW.HILInitialize_Card,
          &Autonomous_Driving_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &Autonomous_Driving_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Autonomous_Driving_DW.HILInitialize_Card,
          &Autonomous_Driving_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Autonomous_Driving_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Autonomous_Driving_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Autonomous_Driving_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Autonomous_Driving_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Autonomous_Driving_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Autonomous_Driving_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Autonomous_Driving_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (Autonomous_Driving_DW.HILInitialize_Card,
         Autonomous_Driving_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &Autonomous_Driving_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *) &Autonomous_Driving_DW.HILInitialize_POAlignValues
         [0],
         (t_pwm_polarity *) &Autonomous_Driving_DW.HILInitialize_POPolarityVals
         [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    if ((Autonomous_Driving_P.HILInitialize_POStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Autonomous_Driving_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Autonomous_Driving_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Autonomous_Driving_DW.HILInitialize_Card,
        Autonomous_Driving_P.HILInitialize_POChannels, 8U,
        &Autonomous_Driving_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    if (Autonomous_Driving_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Autonomous_Driving_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Autonomous_Driving_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Autonomous_Driving_DW.HILInitialize_Card,
         Autonomous_Driving_P.HILInitialize_POChannels, 8U,
         &Autonomous_Driving_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }

    if ((Autonomous_Driving_P.HILInitialize_OOStart && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Autonomous_Driving_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Autonomous_Driving_P.HILInitialize_OOInitial;
        }
      }

      result = hil_write_other(Autonomous_Driving_DW.HILInitialize_Card,
        Autonomous_Driving_P.HILInitialize_OOChannels, 13U,
        &Autonomous_Driving_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S8>/Unwrap 2^24' */

  /* S-Function Block: Autonomous_Driving/basicQCarIO/Unwrap 2^24 (inverse_modulus_block) */
  {
    Autonomous_Driving_DW.Unwrap224_FirstSample = true;
    Autonomous_Driving_DW.Unwrap224_Revolutions = 0;
  }

  /* Start for RateTransition: '<Root>/Rate Transition1' */
  Autonomous_Driving_B.RateTransition1 =
    Autonomous_Driving_P.RateTransition1_InitialConditio;

  /* Start for RateTransition: '<Root>/Rate Transition' */
  Autonomous_Driving_B.RateTransition =
    Autonomous_Driving_P.RateTransition_InitialCondition;

  /* Start for S-Function (sample_time_block): '<S14>/Sample Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Autonomous_Driving_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }
  }

  /* Start for RateTransition: '<Root>/Rate Transition4' */
  Autonomous_Driving_B.RateTransition4[0] =
    Autonomous_Driving_P.RateTransition4_InitialConditio;

  /* Start for RateTransition: '<Root>/Rate Transition3' */
  Autonomous_Driving_B.RateTransition3[0] =
    Autonomous_Driving_P.RateTransition3_InitialConditio;

  /* Start for RateTransition: '<Root>/Rate Transition4' */
  Autonomous_Driving_B.RateTransition4[1] =
    Autonomous_Driving_P.RateTransition4_InitialConditio;

  /* Start for RateTransition: '<Root>/Rate Transition3' */
  Autonomous_Driving_B.RateTransition3[1] =
    Autonomous_Driving_P.RateTransition3_InitialConditio;

  /* Start for RateTransition: '<Root>/Rate Transition4' */
  Autonomous_Driving_B.RateTransition4[2] =
    Autonomous_Driving_P.RateTransition4_InitialConditio;

  /* Start for RateTransition: '<Root>/Rate Transition3' */
  Autonomous_Driving_B.RateTransition3[2] =
    Autonomous_Driving_P.RateTransition3_InitialConditio;

  /* Start for S-Function (video_capture_block): '<S10>/Video Capture' */
  {
    t_video_capture_attribute local_attr[17] = {
      { Autonomous_Driving_P.VideoCapture_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvBrightness, false }
      , { Autonomous_Driving_P.VideoCapture_Contrast,
        VIDEO_CAPTURE_PROPERTY_CONTRAST, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvContrast, false }
      , { Autonomous_Driving_P.VideoCapture_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvHue, false }
      , { Autonomous_Driving_P.VideoCapture_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvSaturation, false }
      , { Autonomous_Driving_P.VideoCapture_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvSharpness, false }
      , { Autonomous_Driving_P.VideoCapture_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvGamma, false }
      , { Autonomous_Driving_P.VideoCapture_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvColorEnable, true }
      , { Autonomous_Driving_P.VideoCapture_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvWhiteBalance, false }
      , { Autonomous_Driving_P.VideoCapture_BacklightCompensat,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvBacklightCompens, false }
      , { Autonomous_Driving_P.VideoCapture_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvGain, false }
      , { Autonomous_Driving_P.VideoCapture_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvPan, false }
      , { Autonomous_Driving_P.VideoCapture_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvTilt, false }
      , { Autonomous_Driving_P.VideoCapture_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvRoll, false }
      , { Autonomous_Driving_P.VideoCapture_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvZoom, false }
      , { Autonomous_Driving_P.VideoCapture_Exposure,
        VIDEO_CAPTURE_PROPERTY_EXPOSURE, (t_boolean)
        Autonomous_Driving_P.VideoCapture_OvExposure, false }
      , { Autonomous_Driving_P.VideoCapture_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvIris, false }
      , { Autonomous_Driving_P.VideoCapture_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Autonomous_Driving_P.VideoCapture_OvFocus, false }
    };

    t_error result;

    /*printf("Opening camera video://localhost:3\n"); fflush(stdout);*/
    result = video_capture_open("video://localhost:3", 120.0, 820U, 410U,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &Autonomous_Driving_DW.VideoCapture_VideoCapture, local_attr, ARRAY_LENGTH
      (local_attr));
    if (result >= 0) {
      result = video_capture_start
        (Autonomous_Driving_DW.VideoCapture_VideoCapture);
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_transform_block): '<S12>/Image Transform' */

  /* S-Function Block: Autonomous_Driving/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    t_error result;
    result = image_rgb_to_hsv_open
      (&Autonomous_Driving_DW.ImageTransform_AlgHandle);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S23>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/Display RGB/RGB Image Processed/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Autonomous_Driving_DW.ImageCompress_Compress);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Autonomous_Driving_DW.ImageCompress_Compress, 274, 137,
           COLOR_SPACE_RGB, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Autonomous_Driving_DW.ImageCompress_Compress,
           Autonomous_Driving_P.ImageCompress_Quality);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Autonomous_Driving_DW.ImageCompress_Compress,
           &Autonomous_Driving_B.ImageCompress[0], 112614);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Autonomous_Driving_DW.ImageCompress_Compress);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S23>/Channel' */

  /* S-Function Block: Autonomous_Driving/Display RGB/RGB Image Processed/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(1, sizeof(uint8_T), 1, 112614, 1,
      (t_channel_fifo *) &Autonomous_Driving_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S24>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/RGB Image  Pre-Proccessing/RGB Image No Threshold/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Autonomous_Driving_DW.ImageCompress_Compress_c);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Autonomous_Driving_DW.ImageCompress_Compress_c, 273, 205,
           COLOR_SPACE_RGB, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Autonomous_Driving_DW.ImageCompress_Compress_c,
           Autonomous_Driving_P.ImageCompress_Quality_p);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Autonomous_Driving_DW.ImageCompress_Compress_c,
           &Autonomous_Driving_B.ImageCompress_h[0], 167895);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Autonomous_Driving_DW.ImageCompress_Compress_c);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S24>/Channel' */

  /* S-Function Block: Autonomous_Driving/RGB Image  Pre-Proccessing/RGB Image No Threshold/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(2, sizeof(uint8_T), 1, 167895, 1,
      (t_channel_fifo *) &Autonomous_Driving_DW.Channel_PWORK_b.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (sample_time_block): '<S15>/Sample Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming 1/Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Autonomous_Driving_DW.SampleTime_PreviousTime_g);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_initialize_block): '<S11>/Video3D Initialize' */

  /* S-Function Block: Autonomous_Driving/captureDepth/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0", &Autonomous_Driving_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_capture_block): '<S11>/Depth' */
  {
    t_error result;
    result = video3d_stream_open(Autonomous_Driving_DW.Video3DInitialize_Video3D,
      VIDEO3D_STREAM_DEPTH, Autonomous_Driving_P.Depth_stream_index, 100.0, 640,
      360,
      IMAGE_FORMAT_COL_MAJOR_GRAYSCALE, IMAGE_DATA_TYPE_SINGLE,
      &Autonomous_Driving_DW.Depth_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (Autonomous_Driving_P.Depth_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (Autonomous_Driving_P.Depth_Preset - 1);
        num_config_properties++;
      }

      if (Autonomous_Driving_P.Depth_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (Autonomous_Driving_P.Depth_Emitter == 1) ? 1.0 : 0.0;
        num_config_properties++;
      }

      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_WHITE_BALANCE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_EXPOSURE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      if (num_config_properties > 0) {
        video3d_stream_set_properties(Autonomous_Driving_DW.Depth_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S22>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/Display Depth/Depth Camera Information/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Autonomous_Driving_DW.ImageCompress_Compress_cq);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Autonomous_Driving_DW.ImageCompress_Compress_cq, 214, 120,
           COLOR_SPACE_RGB, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Autonomous_Driving_DW.ImageCompress_Compress_cq,
           Autonomous_Driving_P.ImageCompress_Quality_k);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Autonomous_Driving_DW.ImageCompress_Compress_cq,
           &Autonomous_Driving_B.ImageCompress_o[0], 77040);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Autonomous_Driving_DW.ImageCompress_Compress_cq);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S22>/Channel' */

  /* S-Function Block: Autonomous_Driving/Display Depth/Depth Camera Information/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 1, 77040, 1,
      (t_channel_fifo *) &Autonomous_Driving_DW.Channel_PWORK_m.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
    }
  }

  /* Start for S-Function (sample_time_block): '<S16>/Sample Time' */

  /* S-Function Block: Autonomous_Driving/monitorTiming 2/Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Autonomous_Driving_DW.SampleTime_PreviousTime_e);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
      return;
    }
  }

  Autonomous_Driving_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S28>/Integrator1' incorporates:
     *  Integrator: '<S27>/Integrator1'
     */
    if (rtmIsFirstInitCond(Autonomous_Driving_M)) {
      Autonomous_Driving_X.Integrator1_CSTATE = 0.0;
      Autonomous_Driving_X.Integrator1_CSTATE_p = 0.0;
    }

    Autonomous_Driving_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S28>/Integrator1' */

    /* InitializeConditions for Integrator: '<S27>/Integrator1' */
    Autonomous_Driving_DW.Integrator1_IWORK_p = 1;

    /* InitializeConditions for Integrator: '<S26>/Integrator1' */
    if (rtmIsFirstInitCond(Autonomous_Driving_M)) {
      Autonomous_Driving_X.Integrator1_CSTATE_n = 0.0;
    }

    Autonomous_Driving_DW.Integrator1_IWORK_o = 1;

    /* End of InitializeConditions for Integrator: '<S26>/Integrator1' */

    /* InitializeConditions for Integrator: '<S26>/Integrator2' */
    Autonomous_Driving_X.Integrator2_CSTATE =
      Autonomous_Driving_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S27>/Integrator2' */
    Autonomous_Driving_X.Integrator2_CSTATE_k =
      Autonomous_Driving_P.Integrator2_IC_f;

    /* InitializeConditions for Integrator: '<S28>/Integrator2' */
    Autonomous_Driving_X.Integrator2_CSTATE_o =
      Autonomous_Driving_P.Integrator2_IC_j;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
    Autonomous_Driving_DW.RateTransition1_Buffer0 =
      Autonomous_Driving_P.RateTransition1_InitialConditio;

    /* InitializeConditions for RateLimiter: '<S21>/Rate Limiter' */
    Autonomous_Driving_DW.PrevY = Autonomous_Driving_P.RateLimiter_IC;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    Autonomous_Driving_DW.RateTransition_Buffer0 =
      Autonomous_Driving_P.RateTransition_InitialCondition;

    /* InitializeConditions for Integrator: '<S18>/Integrator1' */
    Autonomous_Driving_X.Integrator1_CSTATE_b =
      Autonomous_Driving_P.Integrator1_IC;

    /* InitializeConditions for DiscretePulseGenerator: '<S13>/Pulsing Light' */
    Autonomous_Driving_DW.clockTickCounter = 0;

    /* InitializeConditions for Memory: '<S13>/Memory' */
    Autonomous_Driving_DW.Memory_PreviousInput =
      Autonomous_Driving_P.Memory_InitialCondition;

    /* InitializeConditions for S-Function (one_shot_block): '<S34>/one_shot_block' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    {
      Autonomous_Driving_DW.one_shot_block_DSTATE[0] = 0.0;
      Autonomous_Driving_DW.one_shot_block_DSTATE[1] = 0.0;
      Autonomous_Driving_DW.one_shot_block_DSTATE[2] = 0.0;
    }

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition4' */
    Autonomous_Driving_DW.RateTransition4_Buffer0[0] =
      Autonomous_Driving_P.RateTransition4_InitialConditio;
    Autonomous_Driving_DW.RateTransition4_Buffer0[1] =
      Autonomous_Driving_P.RateTransition4_InitialConditio;
    Autonomous_Driving_DW.RateTransition4_Buffer0[2] =
      Autonomous_Driving_P.RateTransition4_InitialConditio;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition3' */
    Autonomous_Driving_DW.RateTransition3_Buffer0[0] =
      Autonomous_Driving_P.RateTransition3_InitialConditio;
    Autonomous_Driving_DW.RateTransition3_Buffer0[1] =
      Autonomous_Driving_P.RateTransition3_InitialConditio;
    Autonomous_Driving_DW.RateTransition3_Buffer0[2] =
      Autonomous_Driving_P.RateTransition3_InitialConditio;

    /* InitializeConditions for S-Function (video3d_initialize_block): '<S11>/Video3D Initialize' */

    /* S-Function Block: Autonomous_Driving/captureDepth/Video3D Initialize (video3d_initialize_block) */
    {
      if (rtmIsFirstInitCond(Autonomous_Driving_M)) {
        t_error result = video3d_start_streaming
          (Autonomous_Driving_DW.Video3DInitialize_Video3D);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
          return;
        }
      }
    }

    /* SystemInitialize for Enabled SubSystem: '<Root>/obstacleDetection' */
    /* SystemInitialize for Outport: '<S17>/imageDepthForDisplay' */
    for (i = 0; i < 77040; i++) {
      Autonomous_Driving_B.img_out[i] =
        Autonomous_Driving_P.imageDepthForDisplay_Y0;
    }

    /* End of SystemInitialize for Outport: '<S17>/imageDepthForDisplay' */

    /* SystemInitialize for Product: '<S17>/Multiply' incorporates:
     *  Outport: '<S17>/distance (m)'
     */
    Autonomous_Driving_B.Multiply = Autonomous_Driving_P.distancem_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/obstacleDetection' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Autonomous_Driving_M)) {
      rtmSetFirstInitCond(Autonomous_Driving_M, 0);
    }
  }
}

/* Model terminate function */
void Autonomous_Driving_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S8>/HIL Initialize' */

  /* S-Function Block: Autonomous_Driving/basicQCarIO/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Autonomous_Driving_DW.HILInitialize_Card);
    hil_monitor_stop_all(Autonomous_Driving_DW.HILInitialize_Card);
    is_switching = false;
    if ((Autonomous_Driving_P.HILInitialize_DOTerminate && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Autonomous_Driving_P.HILInitialize_POTerminate && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Autonomous_Driving_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Autonomous_Driving_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Autonomous_Driving_P.HILInitialize_OOTerminate && !is_switching) ||
        (Autonomous_Driving_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Autonomous_Driving_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Autonomous_Driving_P.HILInitialize_OOFinal;
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
      result = hil_write(Autonomous_Driving_DW.HILInitialize_Card
                         , NULL, 0
                         , Autonomous_Driving_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &Autonomous_Driving_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Autonomous_Driving_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Autonomous_Driving_DW.HILInitialize_POValues[0]
                         , (t_boolean *)
                         &Autonomous_Driving_P.HILInitialize_DOFinal
                         , &Autonomous_Driving_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Autonomous_Driving_DW.HILInitialize_Card,
            Autonomous_Driving_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Autonomous_Driving_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Autonomous_Driving_DW.HILInitialize_Card,
             &Autonomous_Driving_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &Autonomous_Driving_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (Autonomous_Driving_DW.HILInitialize_Card,
             Autonomous_Driving_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             &Autonomous_Driving_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Autonomous_Driving_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Autonomous_Driving_DW.HILInitialize_Card);
    hil_monitor_delete_all(Autonomous_Driving_DW.HILInitialize_Card);
    hil_close(Autonomous_Driving_DW.HILInitialize_Card);
    Autonomous_Driving_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (video_capture_block): '<S10>/Video Capture' */
  video_capture_stop(Autonomous_Driving_DW.VideoCapture_VideoCapture);
  video_capture_close(Autonomous_Driving_DW.VideoCapture_VideoCapture);

  /* Terminate for S-Function (image_transform_block): '<S12>/Image Transform' */

  /* S-Function Block: Autonomous_Driving/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    image_rgb_to_hsv_close(Autonomous_Driving_DW.ImageTransform_AlgHandle);
  }

  /* Terminate for S-Function (image_compress_block): '<S23>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/Display RGB/RGB Image Processed/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Autonomous_Driving_DW.ImageCompress_Compress);
    Autonomous_Driving_DW.ImageCompress_Compress = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S23>/Channel' */

  /* S-Function Block: Autonomous_Driving/Display RGB/RGB Image Processed/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Autonomous_Driving_DW.Channel_PWORK.Fifo);
    Autonomous_Driving_DW.Channel_PWORK.Fifo = NULL;
  }

  /* Terminate for S-Function (image_compress_block): '<S24>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/RGB Image  Pre-Proccessing/RGB Image No Threshold/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Autonomous_Driving_DW.ImageCompress_Compress_c);
    Autonomous_Driving_DW.ImageCompress_Compress_c = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S24>/Channel' */

  /* S-Function Block: Autonomous_Driving/RGB Image  Pre-Proccessing/RGB Image No Threshold/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Autonomous_Driving_DW.Channel_PWORK_b.Fifo);
    Autonomous_Driving_DW.Channel_PWORK_b.Fifo = NULL;
  }

  /* Terminate for S-Function (video3d_initialize_block): '<S11>/Video3D Initialize' */

  /* S-Function Block: Autonomous_Driving/captureDepth/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming(Autonomous_Driving_DW.Video3DInitialize_Video3D);
    video3d_close(Autonomous_Driving_DW.Video3DInitialize_Video3D);
  }

  /* Terminate for S-Function (image_compress_block): '<S22>/Image Compress' */

  /* S-Function Block: Autonomous_Driving/Display Depth/Depth Camera Information/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Autonomous_Driving_DW.ImageCompress_Compress_cq);
    Autonomous_Driving_DW.ImageCompress_Compress_cq = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S22>/Channel' */

  /* S-Function Block: Autonomous_Driving/Display Depth/Depth Camera Information/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Autonomous_Driving_DW.Channel_PWORK_m.Fifo);
    Autonomous_Driving_DW.Channel_PWORK_m.Fifo = NULL;
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
  Autonomous_Driving_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Autonomous_Driving_update(tid);
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
  Autonomous_Driving_initialize();
}

void MdlTerminate(void)
{
  Autonomous_Driving_terminate();
}

/* Registration function */
RT_MODEL_Autonomous_Driving_T *Autonomous_Driving(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Autonomous_Driving_P.Constant2_Value = rtInf;
  Autonomous_Driving_P.RateLimiter_FallingLim = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)Autonomous_Driving_M, 0,
                sizeof(RT_MODEL_Autonomous_Driving_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Autonomous_Driving_M->solverInfo,
                          &Autonomous_Driving_M->Timing.simTimeStep);
    rtsiSetTPtr(&Autonomous_Driving_M->solverInfo, &rtmGetTPtr
                (Autonomous_Driving_M));
    rtsiSetStepSizePtr(&Autonomous_Driving_M->solverInfo,
                       &Autonomous_Driving_M->Timing.stepSize0);
    rtsiSetdXPtr(&Autonomous_Driving_M->solverInfo,
                 &Autonomous_Driving_M->derivs);
    rtsiSetContStatesPtr(&Autonomous_Driving_M->solverInfo, (real_T **)
                         &Autonomous_Driving_M->contStates);
    rtsiSetNumContStatesPtr(&Autonomous_Driving_M->solverInfo,
      &Autonomous_Driving_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Autonomous_Driving_M->solverInfo,
      &Autonomous_Driving_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Autonomous_Driving_M->solverInfo,
      &Autonomous_Driving_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Autonomous_Driving_M->solverInfo,
      &Autonomous_Driving_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Autonomous_Driving_M->solverInfo, (&rtmGetErrorStatus
      (Autonomous_Driving_M)));
    rtsiSetRTModelPtr(&Autonomous_Driving_M->solverInfo, Autonomous_Driving_M);
  }

  rtsiSetSimTimeStep(&Autonomous_Driving_M->solverInfo, MAJOR_TIME_STEP);
  Autonomous_Driving_M->intgData.y = Autonomous_Driving_M->odeY;
  Autonomous_Driving_M->intgData.f[0] = Autonomous_Driving_M->odeF[0];
  Autonomous_Driving_M->intgData.f[1] = Autonomous_Driving_M->odeF[1];
  Autonomous_Driving_M->contStates = ((real_T *) &Autonomous_Driving_X);
  rtsiSetSolverData(&Autonomous_Driving_M->solverInfo, (void *)
                    &Autonomous_Driving_M->intgData);
  rtsiSetSolverName(&Autonomous_Driving_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Autonomous_Driving_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    Autonomous_Driving_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Autonomous_Driving_M->Timing.sampleTimes =
      (&Autonomous_Driving_M->Timing.sampleTimesArray[0]);
    Autonomous_Driving_M->Timing.offsetTimes =
      (&Autonomous_Driving_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Autonomous_Driving_M->Timing.sampleTimes[0] = (0.0);
    Autonomous_Driving_M->Timing.sampleTimes[1] = (0.0016666666666666668);
    Autonomous_Driving_M->Timing.sampleTimes[2] = (0.0083333333333333332);
    Autonomous_Driving_M->Timing.sampleTimes[3] = (0.01);

    /* task offsets */
    Autonomous_Driving_M->Timing.offsetTimes[0] = (0.0);
    Autonomous_Driving_M->Timing.offsetTimes[1] = (0.0);
    Autonomous_Driving_M->Timing.offsetTimes[2] = (0.0);
    Autonomous_Driving_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(Autonomous_Driving_M, &Autonomous_Driving_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Autonomous_Driving_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Autonomous_Driving_M->Timing.perTaskSampleHitsArray;
    Autonomous_Driving_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Autonomous_Driving_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Autonomous_Driving_M, -1);
  Autonomous_Driving_M->Timing.stepSize0 = 0.0016666666666666668;
  Autonomous_Driving_M->Timing.stepSize1 = 0.0016666666666666668;
  Autonomous_Driving_M->Timing.stepSize2 = 0.0083333333333333332;
  Autonomous_Driving_M->Timing.stepSize3 = 0.01;
  rtmSetFirstInitCond(Autonomous_Driving_M, 1);

  /* External mode info */
  Autonomous_Driving_M->Sizes.checksums[0] = (2823014632U);
  Autonomous_Driving_M->Sizes.checksums[1] = (1626721889U);
  Autonomous_Driving_M->Sizes.checksums[2] = (207520485U);
  Autonomous_Driving_M->Sizes.checksums[3] = (2405446633U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[20];
    Autonomous_Driving_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &Autonomous_Driving_DW.obstacleDetection_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Autonomous_Driving_DW.obstacleDetection_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Autonomous_Driving_DW.obstacleDetection_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Autonomous_Driving_DW.obstacleDetection_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Autonomous_Driving_M->extModeInfo,
      &Autonomous_Driving_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Autonomous_Driving_M->extModeInfo,
                        Autonomous_Driving_M->Sizes.checksums);
    rteiSetTPtr(Autonomous_Driving_M->extModeInfo, rtmGetTPtr
                (Autonomous_Driving_M));
  }

  Autonomous_Driving_M->solverInfoPtr = (&Autonomous_Driving_M->solverInfo);
  Autonomous_Driving_M->Timing.stepSize = (0.0016666666666666668);
  rtsiSetFixedStepSize(&Autonomous_Driving_M->solverInfo, 0.0016666666666666668);
  rtsiSetSolverMode(&Autonomous_Driving_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Autonomous_Driving_M->blockIO = ((void *) &Autonomous_Driving_B);
  (void) memset(((void *) &Autonomous_Driving_B), 0,
                sizeof(B_Autonomous_Driving_T));

  {
    Autonomous_Driving_B.Channel = CHANNEL_0;
    Autonomous_Driving_B.Channel_b = CHANNEL_0;
    Autonomous_Driving_B.Channel_g = CHANNEL_0;
  }

  /* parameters */
  Autonomous_Driving_M->defaultParam = ((real_T *)&Autonomous_Driving_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Autonomous_Driving_X;
    Autonomous_Driving_M->contStates = (x);
    (void) memset((void *)&Autonomous_Driving_X, 0,
                  sizeof(X_Autonomous_Driving_T));
  }

  /* states (dwork) */
  Autonomous_Driving_M->dwork = ((void *) &Autonomous_Driving_DW);
  (void) memset((void *)&Autonomous_Driving_DW, 0,
                sizeof(DW_Autonomous_Driving_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Autonomous_Driving_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Autonomous_Driving_M->Sizes.numContStates = (7);/* Number of continuous states */
  Autonomous_Driving_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Autonomous_Driving_M->Sizes.numY = (0);/* Number of model outputs */
  Autonomous_Driving_M->Sizes.numU = (0);/* Number of model inputs */
  Autonomous_Driving_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Autonomous_Driving_M->Sizes.numSampTimes = (4);/* Number of sample times */
  Autonomous_Driving_M->Sizes.numBlocks = (262);/* Number of blocks */
  Autonomous_Driving_M->Sizes.numBlockIO = (58);/* Number of block outputs */
  Autonomous_Driving_M->Sizes.numBlockPrms = (351);/* Sum of parameter "widths" */
  return Autonomous_Driving_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
