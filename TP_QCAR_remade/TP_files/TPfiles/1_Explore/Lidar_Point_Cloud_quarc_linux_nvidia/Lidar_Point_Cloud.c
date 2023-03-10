/*
 * Lidar_Point_Cloud.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lidar_Point_Cloud".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Feb  1 11:22:53 2023
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lidar_Point_Cloud.h"
#include "Lidar_Point_Cloud_private.h"
#include "Lidar_Point_Cloud_dt.h"

/* Block signals (default storage) */
B_Lidar_Point_Cloud_T Lidar_Point_Cloud_B;

/* Block states (default storage) */
DW_Lidar_Point_Cloud_T Lidar_Point_Cloud_DW;

/* Real-time model */
static RT_MODEL_Lidar_Point_Cloud_T Lidar_Point_Cloud_M_;
RT_MODEL_Lidar_Point_Cloud_T *const Lidar_Point_Cloud_M = &Lidar_Point_Cloud_M_;

/* Forward declaration for local functions */
static void Lidar_Point_Cloud_eml_sub2ind(const real_T varargin_1_data[], const
  int32_T *varargin_1_size, const real_T varargin_2_data[], int32_T idx_data[],
  int32_T *idx_size);

/* Function for MATLAB Function: '<S6>/contourToPointCloud' */
static void Lidar_Point_Cloud_eml_sub2ind(const real_T varargin_1_data[], const
  int32_T *varargin_1_size, const real_T varargin_2_data[], int32_T idx_data[],
  int32_T *idx_size)
{
  int32_T i;
  int32_T loop_ub;
  *idx_size = *varargin_1_size;
  loop_ub = *varargin_1_size;
  for (i = 0; i < loop_ub; i++) {
    idx_data[i] = ((int32_T)varargin_2_data[i] - 1) * 400 + (int32_T)
      varargin_1_data[i];
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

/* Model output function */
void Lidar_Point_Cloud_output(void)
{
  real_T rtb_Switch2;
  real_T *rtb_mapOut_0;
  int32_T b_data[720];
  int32_T i;
  int32_T temp_heading_size_idx_0;
  int32_T trueCount;

  /* S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: Lidar_Point_Cloud/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    t_error result;
    result = rplidar_read(Lidar_Point_Cloud_DW.RangingSensor_Sensor,
                          RANGING_MEASUREMENT_MODE_NORMAL,
                          Lidar_Point_Cloud_P.RangingSensor_MaxInterpolationD,
                          Lidar_Point_Cloud_P.RangingSensor_MaxInterpolationA,
                          &Lidar_Point_Cloud_DW.RangingSensor_Measurements[0],
                          720);
    if (result >= 0) {
      {
        int_T i1;
        real_T *y0 = &Lidar_Point_Cloud_B.RangingSensor_o1[0];
        real_T *y1 = &Lidar_Point_Cloud_B.RangingSensor_o2[0];
        real_T *y2 = &Lidar_Point_Cloud_B.RangingSensor_o3[0];
        real_T *y3 = &Lidar_Point_Cloud_B.RangingSensor_o4[0];
        t_ranging_measurement *dw_Measurements =
          &Lidar_Point_Cloud_DW.RangingSensor_Measurements[0];
        for (i1=0; i1 < 720; i1++) {
          y0[i1] = dw_Measurements[i1].distance;
          y2[i1] = dw_Measurements[i1].heading;
        }
      }
    } else if (result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
    }
  }

  for (i = 0; i < 720; i++) {
    /* Bias: '<S4>/Change +x to front of QCar ' incorporates:
     *  Gain: '<S4>/Change to  CCW rotation'
     */
    Lidar_Point_Cloud_B.ChangextofrontofQCar[i] =
      Lidar_Point_Cloud_P.ChangetoCCWrotation_Gain *
      Lidar_Point_Cloud_B.RangingSensor_o3[i] +
      Lidar_Point_Cloud_P.ChangextofrontofQCar_Bias;
  }

  /* MATLAB Function: '<S6>/findXYContour' */
  trueCount = 0;
  for (i = 0; i < 720; i++) {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/maximumDistance (m)'
     *  RelationalOperator: '<S7>/LowerRelop1'
     *  RelationalOperator: '<S7>/UpperRelop'
     *  Switch: '<S7>/Switch'
     */
    if (Lidar_Point_Cloud_B.RangingSensor_o1[i] >
        Lidar_Point_Cloud_P.maximumDistancem_Value) {
      rtb_Switch2 = Lidar_Point_Cloud_P.maximumDistancem_Value;
    } else if (Lidar_Point_Cloud_B.RangingSensor_o1[i] <
               Lidar_Point_Cloud_P.Constant1_Value) {
      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<S6>/Constant1'
       */
      rtb_Switch2 = Lidar_Point_Cloud_P.Constant1_Value;
    } else {
      rtb_Switch2 = Lidar_Point_Cloud_B.RangingSensor_o1[i];
    }

    /* MATLAB Function: '<S6>/findXYContour' incorporates:
     *  Constant: '<S6>/maximumDistance (m)'
     */
    if (rtb_Switch2 < Lidar_Point_Cloud_P.maximumDistancem_Value) {
      trueCount++;
    }

    /* Switch: '<S7>/Switch2' */
    Lidar_Point_Cloud_B.Switch2[i] = rtb_Switch2;
  }

  /* MATLAB Function: '<S6>/findXYContour' incorporates:
   *  Constant: '<S6>/maximumDistance (m)'
   */
  temp_heading_size_idx_0 = trueCount;
  trueCount = 0;
  for (i = 0; i < 720; i++) {
    if (Lidar_Point_Cloud_B.Switch2[i] <
        Lidar_Point_Cloud_P.maximumDistancem_Value) {
      Lidar_Point_Cloud_B.temp_heading_data[trueCount] =
        Lidar_Point_Cloud_B.ChangextofrontofQCar[i];
      trueCount++;
    }
  }

  if (0 <= temp_heading_size_idx_0 - 1) {
    memcpy(&Lidar_Point_Cloud_B.pX_data[0],
           &Lidar_Point_Cloud_B.temp_heading_data[0], temp_heading_size_idx_0 *
           sizeof(real_T));
  }

  for (trueCount = 0; trueCount < temp_heading_size_idx_0; trueCount++) {
    Lidar_Point_Cloud_B.pX_data[trueCount] = cos
      (Lidar_Point_Cloud_B.pX_data[trueCount]);
  }

  trueCount = 0;
  for (i = 0; i < 720; i++) {
    if (Lidar_Point_Cloud_B.Switch2[i] <
        Lidar_Point_Cloud_P.maximumDistancem_Value) {
      trueCount++;
    }
  }

  Lidar_Point_Cloud_DW.SFunction_DIMS2 = trueCount;
  trueCount = 0;
  for (i = 0; i < 720; i++) {
    rtb_Switch2 = Lidar_Point_Cloud_B.Switch2[i];
    if (rtb_Switch2 < Lidar_Point_Cloud_P.maximumDistancem_Value) {
      Lidar_Point_Cloud_B.X[trueCount] = rtb_Switch2 *
        Lidar_Point_Cloud_B.pX_data[trueCount];
      trueCount++;
    }
  }

  if (0 <= temp_heading_size_idx_0 - 1) {
    memcpy(&Lidar_Point_Cloud_B.pX_data[0],
           &Lidar_Point_Cloud_B.temp_heading_data[0], temp_heading_size_idx_0 *
           sizeof(real_T));
  }

  for (trueCount = 0; trueCount < temp_heading_size_idx_0; trueCount++) {
    Lidar_Point_Cloud_B.pX_data[trueCount] = sin
      (Lidar_Point_Cloud_B.pX_data[trueCount]);
  }

  trueCount = 0;
  for (i = 0; i < 720; i++) {
    if (Lidar_Point_Cloud_B.Switch2[i] <
        Lidar_Point_Cloud_P.maximumDistancem_Value) {
      trueCount++;
    }
  }

  Lidar_Point_Cloud_DW.SFunction_DIMS3 = trueCount;
  trueCount = 0;
  for (i = 0; i < 720; i++) {
    rtb_Switch2 = Lidar_Point_Cloud_B.Switch2[i];
    if (rtb_Switch2 < Lidar_Point_Cloud_P.maximumDistancem_Value) {
      Lidar_Point_Cloud_B.Y[trueCount] = rtb_Switch2 *
        Lidar_Point_Cloud_B.pX_data[trueCount];
      trueCount++;
    }
  }

  /* MATLAB Function: '<S6>/contourToPointCloud' incorporates:
   *  Constant: '<S6>/decay'
   */
  if (!Lidar_Point_Cloud_DW.mapInternal_not_empty) {
    memset(&Lidar_Point_Cloud_DW.mapInternal[0], 0, 160000U * sizeof(real_T));
    Lidar_Point_Cloud_DW.mapInternal_not_empty = true;
  } else {
    for (trueCount = 0; trueCount < 160000; trueCount++) {
      Lidar_Point_Cloud_DW.mapInternal[trueCount] *=
        Lidar_Point_Cloud_P.decay_Value;
    }
  }

  for (trueCount = 0; trueCount < Lidar_Point_Cloud_DW.SFunction_DIMS2;
       trueCount++) {
    Lidar_Point_Cloud_B.temp_heading_data[trueCount] = 200.0 -
      Lidar_Point_Cloud_B.X[trueCount] * 50.0;
  }

  i = Lidar_Point_Cloud_DW.SFunction_DIMS2;
  for (trueCount = 0; trueCount < Lidar_Point_Cloud_DW.SFunction_DIMS2;
       trueCount++) {
    Lidar_Point_Cloud_B.pX_data[trueCount] =
      Lidar_Point_Cloud_B.temp_heading_data[trueCount];
  }

  for (trueCount = 0; trueCount < Lidar_Point_Cloud_DW.SFunction_DIMS2;
       trueCount++) {
    Lidar_Point_Cloud_B.pX_data[trueCount] = rt_roundd_snf
      (Lidar_Point_Cloud_B.pX_data[trueCount]);
  }

  for (trueCount = 0; trueCount < Lidar_Point_Cloud_DW.SFunction_DIMS3;
       trueCount++) {
    Lidar_Point_Cloud_B.temp_heading_data[trueCount] = 200.0 -
      Lidar_Point_Cloud_B.Y[trueCount] * 50.0;
  }

  for (trueCount = 0; trueCount < Lidar_Point_Cloud_DW.SFunction_DIMS3;
       trueCount++) {
    Lidar_Point_Cloud_B.Switch2[trueCount] =
      Lidar_Point_Cloud_B.temp_heading_data[trueCount];
  }

  for (trueCount = 0; trueCount < Lidar_Point_Cloud_DW.SFunction_DIMS3;
       trueCount++) {
    Lidar_Point_Cloud_B.Switch2[trueCount] = rt_roundd_snf
      (Lidar_Point_Cloud_B.Switch2[trueCount]);
  }

  Lidar_Point_Cloud_eml_sub2ind(Lidar_Point_Cloud_B.pX_data, &i,
    Lidar_Point_Cloud_B.Switch2, b_data, &temp_heading_size_idx_0);
  for (trueCount = 0; trueCount < temp_heading_size_idx_0; trueCount++) {
    Lidar_Point_Cloud_DW.mapInternal[b_data[trueCount] - 1] = 1.0;
  }

  rtb_mapOut_0 = &Lidar_Point_Cloud_DW.mapInternal[0];

  /* End of MATLAB Function: '<S6>/contourToPointCloud' */

  /* S-Function (image_compress_block): '<S3>/Image Compress' */

  /* S-Function Block: Lidar_Point_Cloud/Video Compressed Display/Image Compress (image_compress_block) */
  {
    t_error result = 0;
    size_t image_size = 0;
    result = qjpeg_compress_start(Lidar_Point_Cloud_DW.ImageCompress_Compress,
      true);
    if (result == 0) {
      result = qjpeg_compress_write_image_double
        (Lidar_Point_Cloud_DW.ImageCompress_Compress, &rtb_mapOut_0[0]);
      qjpeg_compress_stop(Lidar_Point_Cloud_DW.ImageCompress_Compress);

      /* Get the final size of the compressed image */
      if (result >= 0) {
        result = qjpeg_compress_get_fixed_memory_destination_size
          (Lidar_Point_Cloud_DW.ImageCompress_Compress, &image_size);
      }
    }

    /* Set the dimensions of the output signal based on the size of the compressed image */
    Lidar_Point_Cloud_DW.ImageCompress_DIMS1 = (int) image_size;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
    }
  }

  /* S-Function (channel_block): '<S3>/Channel' */

  /* S-Function Block: Lidar_Point_Cloud/Video Compressed Display/Channel (channel_block) */
  {
    struct channel_info {
      t_channel_header header;
    } info;

    size_t width = 1;
    Lidar_Point_Cloud_B.Channel = CHANNEL_0;
    info.header.data_type_id = 3;
    info.header.channel = 0;
    info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
    info.header.num_dimensions = 1;
    width *= Lidar_Point_Cloud_DW.ImageCompress_DIMS1;
    info.header.dimension[0] = Lidar_Point_Cloud_DW.ImageCompress_DIMS1;
    channel_fifo_add((t_channel_fifo) Lidar_Point_Cloud_DW.Channel_PWORK.Fifo,
                     &info.header, &Lidar_Point_Cloud_B.ImageCompress[0], width *
                     sizeof(uint8_T));
  }

  /* S-Function (sample_time_block): '<S5>/Sample Time' */

  /* S-Function Block: Lidar_Point_Cloud/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &Lidar_Point_Cloud_DW.SampleTime_PreviousTime);
      Lidar_Point_Cloud_B.actualsampletime = time_difference.seconds +
        time_difference.nanoseconds * 1e-9;
      memcpy(&Lidar_Point_Cloud_DW.SampleTime_PreviousTime, &current_time,
             sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
      return;
    }
  }

  /* Constant: '<S5>/Constant' */
  Lidar_Point_Cloud_B.reference = Lidar_Point_Cloud_P.Constant_Value;

  /* S-Function (computation_time_block): '<S5>/Computation Time' */

  /* S-Function Block: Lidar_Point_Cloud/monitorTiming /Computation Time (computation_time_block) */
  {
    Lidar_Point_Cloud_B.computationtime =
      Lidar_Point_Cloud_DW.ComputationTime_ComputationTime.seconds +
      Lidar_Point_Cloud_DW.ComputationTime_ComputationTime.nanoseconds * 1e-9;
  }
}

/* Model update function */
void Lidar_Point_Cloud_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lidar_Point_Cloud_M->Timing.clockTick0)) {
    ++Lidar_Point_Cloud_M->Timing.clockTickH0;
  }

  Lidar_Point_Cloud_M->Timing.t[0] = Lidar_Point_Cloud_M->Timing.clockTick0 *
    Lidar_Point_Cloud_M->Timing.stepSize0 +
    Lidar_Point_Cloud_M->Timing.clockTickH0 *
    Lidar_Point_Cloud_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Lidar_Point_Cloud_initialize(void)
{
  /* Start for S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: Lidar_Point_Cloud/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    t_error result;
    result = rplidar_open("serial-cpu://localhost:2?baud='115200',word='8',parity='none',stop='1',flow='none',dsr='on'",
                          (t_ranging_distance)
                          (Lidar_Point_Cloud_P.RangingSensor_Range - 1),
                          &Lidar_Point_Cloud_DW.RangingSensor_Sensor);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S3>/Image Compress' */

  /* S-Function Block: Lidar_Point_Cloud/Video Compressed Display/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Lidar_Point_Cloud_DW.ImageCompress_Compress);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Lidar_Point_Cloud_DW.ImageCompress_Compress, 400, 400,
           COLOR_SPACE_GRAYSCALE);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Lidar_Point_Cloud_DW.ImageCompress_Compress,
           Lidar_Point_Cloud_P.ImageCompress_Quality);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Lidar_Point_Cloud_DW.ImageCompress_Compress,
           &Lidar_Point_Cloud_B.ImageCompress[0], 160000);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Lidar_Point_Cloud_DW.ImageCompress_Compress);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S3>/Channel' */

  /* S-Function Block: Lidar_Point_Cloud/Video Compressed Display/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 1, 160000, 1,
      (t_channel_fifo *) &Lidar_Point_Cloud_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
    }
  }

  /* Start for S-Function (sample_time_block): '<S5>/Sample Time' */

  /* S-Function Block: Lidar_Point_Cloud/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Lidar_Point_Cloud_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lidar_Point_Cloud_M, _rt_error_message);
      return;
    }
  }

  /* SystemInitialize for MATLAB Function: '<S6>/contourToPointCloud' */
  Lidar_Point_Cloud_DW.mapInternal_not_empty = false;
}

/* Model terminate function */
void Lidar_Point_Cloud_terminate(void)
{
  /* Terminate for S-Function (ranging_sensor_block): '<S4>/Ranging Sensor' */

  /* S-Function Block: Lidar_Point_Cloud/captureLIDAR/Ranging Sensor (ranging_sensor_block) */
  {
    rplidar_close(Lidar_Point_Cloud_DW.RangingSensor_Sensor);
    Lidar_Point_Cloud_DW.RangingSensor_Sensor = NULL;
    Lidar_Point_Cloud_DW.RangingSensor_Sensor = NULL;
  }

  /* Terminate for S-Function (image_compress_block): '<S3>/Image Compress' */

  /* S-Function Block: Lidar_Point_Cloud/Video Compressed Display/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Lidar_Point_Cloud_DW.ImageCompress_Compress);
    Lidar_Point_Cloud_DW.ImageCompress_Compress = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S3>/Channel' */

  /* S-Function Block: Lidar_Point_Cloud/Video Compressed Display/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Lidar_Point_Cloud_DW.Channel_PWORK.Fifo);
    Lidar_Point_Cloud_DW.Channel_PWORK.Fifo = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lidar_Point_Cloud_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Lidar_Point_Cloud_update();
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
  Lidar_Point_Cloud_initialize();
}

void MdlTerminate(void)
{
  Lidar_Point_Cloud_terminate();
}

/* Registration function */
RT_MODEL_Lidar_Point_Cloud_T *Lidar_Point_Cloud(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Lidar_Point_Cloud_P.RangingSensor_MaxInterpolationD = rtInf;

  /* initialize real-time model */
  (void) memset((void *)Lidar_Point_Cloud_M, 0,
                sizeof(RT_MODEL_Lidar_Point_Cloud_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lidar_Point_Cloud_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Lidar_Point_Cloud_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lidar_Point_Cloud_M->Timing.sampleTimes =
      (&Lidar_Point_Cloud_M->Timing.sampleTimesArray[0]);
    Lidar_Point_Cloud_M->Timing.offsetTimes =
      (&Lidar_Point_Cloud_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lidar_Point_Cloud_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    Lidar_Point_Cloud_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Lidar_Point_Cloud_M, &Lidar_Point_Cloud_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lidar_Point_Cloud_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Lidar_Point_Cloud_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lidar_Point_Cloud_M, -1);
  Lidar_Point_Cloud_M->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  Lidar_Point_Cloud_M->Sizes.checksums[0] = (1211782789U);
  Lidar_Point_Cloud_M->Sizes.checksums[1] = (1464375443U);
  Lidar_Point_Cloud_M->Sizes.checksums[2] = (2892337515U);
  Lidar_Point_Cloud_M->Sizes.checksums[3] = (3869942092U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Lidar_Point_Cloud_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lidar_Point_Cloud_M->extModeInfo,
      &Lidar_Point_Cloud_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lidar_Point_Cloud_M->extModeInfo,
                        Lidar_Point_Cloud_M->Sizes.checksums);
    rteiSetTPtr(Lidar_Point_Cloud_M->extModeInfo, rtmGetTPtr(Lidar_Point_Cloud_M));
  }

  Lidar_Point_Cloud_M->solverInfoPtr = (&Lidar_Point_Cloud_M->solverInfo);
  Lidar_Point_Cloud_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Lidar_Point_Cloud_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&Lidar_Point_Cloud_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lidar_Point_Cloud_M->blockIO = ((void *) &Lidar_Point_Cloud_B);
  (void) memset(((void *) &Lidar_Point_Cloud_B), 0,
                sizeof(B_Lidar_Point_Cloud_T));

  {
    Lidar_Point_Cloud_B.Channel = CHANNEL_0;
  }

  /* parameters */
  Lidar_Point_Cloud_M->defaultParam = ((real_T *)&Lidar_Point_Cloud_P);

  /* states (dwork) */
  Lidar_Point_Cloud_M->dwork = ((void *) &Lidar_Point_Cloud_DW);
  (void) memset((void *)&Lidar_Point_Cloud_DW, 0,
                sizeof(DW_Lidar_Point_Cloud_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lidar_Point_Cloud_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Lidar_Point_Cloud_M->Sizes.numContStates = (0);/* Number of continuous states */
  Lidar_Point_Cloud_M->Sizes.numY = (0);/* Number of model outputs */
  Lidar_Point_Cloud_M->Sizes.numU = (0);/* Number of model inputs */
  Lidar_Point_Cloud_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lidar_Point_Cloud_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Lidar_Point_Cloud_M->Sizes.numBlocks = (22);/* Number of blocks */
  Lidar_Point_Cloud_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  Lidar_Point_Cloud_M->Sizes.numBlockPrms = (87);/* Sum of parameter "widths" */
  return Lidar_Point_Cloud_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
