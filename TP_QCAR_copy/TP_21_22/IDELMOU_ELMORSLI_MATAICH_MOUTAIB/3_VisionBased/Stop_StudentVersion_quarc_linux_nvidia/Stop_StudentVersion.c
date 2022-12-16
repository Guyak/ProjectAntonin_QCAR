/*
 * Stop_StudentVersion.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Stop_StudentVersion".
 *
 * Model version              : 5.3
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 16:09:37 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Stop_StudentVersion.h"
#include "Stop_StudentVersion_private.h"
#include "Stop_StudentVersion_dt.h"

/* Block signals (default storage) */
B_Stop_StudentVersion_T Stop_StudentVersion_B;

/* Continuous states */
X_Stop_StudentVersion_T Stop_StudentVersion_X;

/* Block states (default storage) */
DW_Stop_StudentVersion_T Stop_StudentVersion_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Stop_StudentVersion_T Stop_StudentVersion_PrevZCX;

/* Real-time model */
static RT_MODEL_Stop_StudentVersion_T Stop_StudentVersion_M_;
RT_MODEL_Stop_StudentVersion_T *const Stop_StudentVersion_M =
  &Stop_StudentVersion_M_;

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Stop_StudentVersion_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  Stop_StudentVersion_output();
  Stop_StudentVersion_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Stop_StudentVersion_output(void)
{
  /* local block i/o variables */
  real_T rtb_motorcurrent;
  real_T rtb_batteryvoltage;
  uint32_T rtb_ImageFindObjects_o2;
  uint32_T rtb_ImageFindObjects_o1;
  real32_T rtb_ImageFindObjects_o5;
  real32_T rtb_ImageFindObjects_o3[2];
  uint16_T rtb_ImageFindObjects_o4[4];
  boolean_T rtb_Depth_o4;

  /* local scratch DWork variables */
  t_blob ImageFindObjects_Blobs;
  real_T rtb_Gain_i;
  real_T rtb_SteeringBias;
  boolean_T didZcEventOccur;
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    /* set solver stop time */
    if (!(Stop_StudentVersion_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Stop_StudentVersion_M->solverInfo,
                            ((Stop_StudentVersion_M->Timing.clockTickH0 + 1) *
        Stop_StudentVersion_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Stop_StudentVersion_M->solverInfo,
                            ((Stop_StudentVersion_M->Timing.clockTick0 + 1) *
        Stop_StudentVersion_M->Timing.stepSize0 +
        Stop_StudentVersion_M->Timing.clockTickH0 *
        Stop_StudentVersion_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Stop_StudentVersion_M)) {
    Stop_StudentVersion_M->Timing.t[0] = rtsiGetT
      (&Stop_StudentVersion_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Stop_StudentVersion_DW.findStopSignDistance_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB);
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    /* S-Function (hil_read_block): '<S3>/HIL Read' */

    /* S-Function Block: Stop_StudentVersion/QCar/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(Stop_StudentVersion_DW.HILInitialize_Card,
        Stop_StudentVersion_P.HILRead_analog_channels, 2U,
        &Stop_StudentVersion_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &Stop_StudentVersion_DW.HILRead_AnalogBuffer[0],
        &Stop_StudentVersion_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      } else {
        rtb_motorcurrent = Stop_StudentVersion_DW.HILRead_AnalogBuffer[0];
        rtb_batteryvoltage = Stop_StudentVersion_DW.HILRead_AnalogBuffer[1];
        Stop_StudentVersion_B.encodercounts =
          Stop_StudentVersion_DW.HILRead_EncoderBuffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<S3>/Unwrap 2^24' */
    /* S-Function Block: Stop_StudentVersion/QCar/Unwrap 2^24 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.033333333333333333;
      real_T half_range = Stop_StudentVersion_P.Unwrap224_Modulus / 2.0;
      real_T du, dy;
      if (Stop_StudentVersion_DW.Unwrap224_FirstSample) {
        Stop_StudentVersion_DW.Unwrap224_FirstSample = false;
        Stop_StudentVersion_DW.Unwrap224_PreviousInput =
          Stop_StudentVersion_B.encodercounts;
      }

      du = (real_T) Stop_StudentVersion_B.encodercounts -
        Stop_StudentVersion_DW.Unwrap224_PreviousInput;
      if (du > half_range) {
        Stop_StudentVersion_DW.Unwrap224_Revolutions =
          Stop_StudentVersion_DW.Unwrap224_Revolutions - 1;
        dy = du - Stop_StudentVersion_P.Unwrap224_Modulus;
      } else if (du < -half_range) {
        Stop_StudentVersion_DW.Unwrap224_Revolutions =
          Stop_StudentVersion_DW.Unwrap224_Revolutions + 1;
        dy = du + Stop_StudentVersion_P.Unwrap224_Modulus;
      } else {
        dy = du;
      }

      Stop_StudentVersion_B.Unwrap224 = Stop_StudentVersion_B.encodercounts +
        Stop_StudentVersion_DW.Unwrap224_Revolutions *
        Stop_StudentVersion_P.Unwrap224_Modulus;
      Stop_StudentVersion_DW.Unwrap224_PreviousInput =
        Stop_StudentVersion_B.encodercounts;
    }
  }

  /* Integrator: '<S11>/Integrator1' */
  if (Stop_StudentVersion_DW.Integrator1_IWORK != 0) {
    Stop_StudentVersion_X.Integrator1_CSTATE = Stop_StudentVersion_B.Unwrap224;
  }

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Integrator: '<S11>/Integrator1'
   *  Integrator: '<S11>/Integrator2'
   *  Product: '<S11>/Product2'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   */
  Stop_StudentVersion_B.Product = ((Stop_StudentVersion_B.Unwrap224 -
    Stop_StudentVersion_X.Integrator1_CSTATE) -
    Stop_StudentVersion_X.Integrator2_CSTATE *
    Stop_StudentVersion_P.Constant_Value_o *
    Stop_StudentVersion_P.Constant1_Value_n) *
    Stop_StudentVersion_P.Constant2_Value_d;

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Integrator: '<S11>/Integrator2'
   */
  Stop_StudentVersion_B.Product1 = Stop_StudentVersion_P.Constant2_Value_d *
    Stop_StudentVersion_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    /* S-Function (video3d_capture_block): '<S6>/Depth' */
    /* S-Function Block: Stop_StudentVersion/captureRGBD/Depth (video3d_capture_block) */
    {
      t_video3d_frame frame;
      t_error result;
      result = video3d_stream_get_frame(Stop_StudentVersion_DW.Depth_Stream,
        &frame);
      if (result >= 0) {
        result = video3d_frame_get_meters(frame,
          &Stop_StudentVersion_B.Depth_o1[0]);

        /* Release the frame to free up its resources */
        video3d_frame_release(frame);
      }

      rtb_Depth_o4 = (result >= 0);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      }
    }

    /* S-Function (video3d_capture_block): '<S6>/RGB' */
    /* S-Function Block: Stop_StudentVersion/captureRGBD/RGB (video3d_capture_block) */
    {
      t_video3d_frame frame;
      t_error result;
      result = video3d_stream_get_frame(Stop_StudentVersion_DW.RGB_Stream,
        &frame);
      if (result >= 0) {
        result = video3d_frame_get_data(frame, &Stop_StudentVersion_B.RGB_o1[0]);

        /* Release the frame to free up its resources */
        video3d_frame_release(frame);
      }

      Stop_StudentVersion_B.RGB_o4 = (result >= 0);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      }
    }

    /* Outputs for Enabled SubSystem: '<Root>/findStopSignLocation' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (Stop_StudentVersion_B.RGB_o4) {
      /* S-Function (image_transform_block): '<S16>/Image Transform' */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/colorThresholdingHSV/Image Transform (image_transform_block) */
      {
        t_error result;
        result = image_rgb_to_hsv_uint8
          (Stop_StudentVersion_DW.ImageTransform_AlgHandle,
           &Stop_StudentVersion_B.RGB_o1[0], 1280, 720,
           &Stop_StudentVersion_B.ImageTransform[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }

      /* Constant: '<S8>/Constant' */
      Stop_StudentVersion_B.Constant = Stop_StudentVersion_P.Constant_Value_c;

      /* Gain: '<S16>/Gain' */
      rtb_Gain_i = Stop_StudentVersion_P.Gain_Gain *
        Stop_StudentVersion_B.Constant;

      /* Switch: '<S16>/Switch' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S16>/Constant1'
       *  Constant: '<S16>/Hue Threshold'
       *  Constant: '<S17>/Constant'
       *  RelationalOperator: '<S17>/Compare'
       *  Sum: '<S16>/Add3'
       *  Sum: '<S16>/Add4'
       *  Switch: '<S16>/Switch1'
       */
      if (Stop_StudentVersion_B.Constant ==
          Stop_StudentVersion_P.CompareToConstant_const) {
        rtb_SteeringBias = Stop_StudentVersion_P.Constant_Value_m;
        rtb_Gain_i = Stop_StudentVersion_P.Constant1_Value_j;
      } else {
        rtb_SteeringBias = rtb_Gain_i - Stop_StudentVersion_P.HueThreshold_Value;
        rtb_Gain_i += Stop_StudentVersion_P.HueThreshold_Value;
      }

      /* End of Switch: '<S16>/Switch' */

      /* S-Function (image_compare_block): '<S16>/HSV Color Thresholding' incorporates:
       *  Constant: '<S8>/Constant1'
       *  Constant: '<S8>/Constant2'
       */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/colorThresholdingHSV/HSV Color Thresholding (image_compare_block) */
      {
        t_error result;
        t_image_comparison_type comparisons[3];
        t_uint8 minimums[3];
        t_uint8 maximums[3];
        comparisons[0] = (t_image_comparison_type)
          (Stop_StudentVersion_P.HSVColorThresholding_r_comparis - 1);
        comparisons[1] = (t_image_comparison_type)
          (Stop_StudentVersion_P.HSVColorThresholding_g_comparis - 1);
        comparisons[2] = (t_image_comparison_type)
          (Stop_StudentVersion_P.HSVColorThresholding_b_comparis - 1);
        if ((comparisons[0] & COMPARE_WRAP) == 0) {
          if (rtb_SteeringBias < 0) {
            minimums[0] = 0;
          } else if (rtb_SteeringBias > 255U) {
            minimums[0] = 255U;
          } else {
            minimums[0] = (t_uint8) rtb_SteeringBias;
          }

          if (rtb_Gain_i < 0) {
            maximums[0] = 0;
          } else if (rtb_Gain_i > 255U) {
            maximums[0] = 255U;
          } else {
            maximums[0] = (t_uint8) rtb_Gain_i;
          }
        } else {
          minimums[0] = (t_uint8) (rtb_SteeringBias - 256U * floor
            (rtb_SteeringBias / 256U));
          maximums[0] = (t_uint8) (rtb_Gain_i - 256U * floor(rtb_Gain_i / 256U));
        }

        if ((comparisons[1] & COMPARE_WRAP) == 0) {
          if (Stop_StudentVersion_P.Constant1_Value_a[0] < 0) {
            minimums[1] = 0;
          } else if (Stop_StudentVersion_P.Constant1_Value_a[0] > 255U) {
            minimums[1] = 255U;
          } else {
            minimums[1] = (t_uint8) Stop_StudentVersion_P.Constant1_Value_a[0];
          }

          if (Stop_StudentVersion_P.Constant2_Value[0] < 0) {
            maximums[1] = 0;
          } else if (Stop_StudentVersion_P.Constant2_Value[0] > 255U) {
            maximums[1] = 255U;
          } else {
            maximums[1] = (t_uint8) Stop_StudentVersion_P.Constant2_Value[0];
          }
        } else {
          minimums[1] = (t_uint8) (Stop_StudentVersion_P.Constant1_Value_a[0] -
            256U * floor(Stop_StudentVersion_P.Constant1_Value_a[0] / 256U));
          maximums[1] = (t_uint8) (Stop_StudentVersion_P.Constant2_Value[0] -
            256U * floor(Stop_StudentVersion_P.Constant2_Value[0] / 256U));
        }

        if ((comparisons[2] & COMPARE_WRAP) == 0) {
          if (Stop_StudentVersion_P.Constant1_Value_a[1] < 0) {
            minimums[2] = 0;
          } else if (Stop_StudentVersion_P.Constant1_Value_a[1] > 255U) {
            minimums[2] = 255U;
          } else {
            minimums[2] = (t_uint8) Stop_StudentVersion_P.Constant1_Value_a[1];
          }

          if (Stop_StudentVersion_P.Constant2_Value[1] < 0) {
            maximums[2] = 0;
          } else if (Stop_StudentVersion_P.Constant2_Value[1] > 255U) {
            maximums[2] = 255U;
          } else {
            maximums[2] = (t_uint8) Stop_StudentVersion_P.Constant2_Value[1];
          }
        } else {
          minimums[2] = (t_uint8) (Stop_StudentVersion_P.Constant1_Value_a[1] -
            256U * floor(Stop_StudentVersion_P.Constant1_Value_a[1] / 256U));
          maximums[2] = (t_uint8) (Stop_StudentVersion_P.Constant2_Value[1] -
            256U * floor(Stop_StudentVersion_P.Constant2_Value[1] / 256U));
        }

        result = image_rgb_compare_range_uint8
          (&Stop_StudentVersion_B.ImageTransform[0], 1280, 720, comparisons,
           minimums, maximums, COMPARE_OUTPUT_COMBINED,
           &Stop_StudentVersion_B.HSVColorThresholding[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }

      /* S-Function (image_compress_block): '<S13>/Image Compress' */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Binary showing blob found/Image Compress (image_compress_block) */
      {
        t_error result = 0;
        size_t image_size = 0;
        result = qjpeg_compress_start
          (Stop_StudentVersion_DW.ImageCompress_Compress, true);
        if (result == 0) {
          result = qjpeg_compress_write_image_uint8
            (Stop_StudentVersion_DW.ImageCompress_Compress,
             &Stop_StudentVersion_B.HSVColorThresholding[0]);
          qjpeg_compress_stop(Stop_StudentVersion_DW.ImageCompress_Compress);

          /* Get the final size of the compressed image */
          if (result >= 0) {
            result = qjpeg_compress_get_fixed_memory_destination_size
              (Stop_StudentVersion_DW.ImageCompress_Compress, &image_size);
          }
        }

        /* Set the dimensions of the output signal based on the size of the compressed image */
        Stop_StudentVersion_DW.ImageCompress_DIMS1 = (int) image_size;
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }

      /* S-Function (channel_block): '<S13>/Channel' */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Binary showing blob found/Channel (channel_block) */
      {
        struct channel_info {
          t_channel_header header;
        } info;

        size_t width = 1;
        Stop_StudentVersion_B.Channel = CHANNEL_1;
        info.header.data_type_id = 3;
        info.header.channel = 1;
        info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
        info.header.num_dimensions = 1;
        width *= Stop_StudentVersion_DW.ImageCompress_DIMS1;
        info.header.dimension[0] = Stop_StudentVersion_DW.ImageCompress_DIMS1;
        channel_fifo_add((t_channel_fifo)
                         Stop_StudentVersion_DW.Channel_PWORK.Fifo, &info.header,
                         &Stop_StudentVersion_B.ImageCompress[0], width * sizeof
                         (uint8_T));
      }

      /* S-Function (image_compress_block): '<S15>/Image Compress' */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Raw RGB/Image Compress (image_compress_block) */
      {
        t_error result = 0;
        size_t image_size = 0;
        result = qjpeg_compress_start
          (Stop_StudentVersion_DW.ImageCompress_Compress_c, true);
        if (result == 0) {
          result = qjpeg_compress_write_image_uint8
            (Stop_StudentVersion_DW.ImageCompress_Compress_c,
             &Stop_StudentVersion_B.RGB_o1[0]);
          qjpeg_compress_stop(Stop_StudentVersion_DW.ImageCompress_Compress_c);

          /* Get the final size of the compressed image */
          if (result >= 0) {
            result = qjpeg_compress_get_fixed_memory_destination_size
              (Stop_StudentVersion_DW.ImageCompress_Compress_c, &image_size);
          }
        }

        /* Set the dimensions of the output signal based on the size of the compressed image */
        Stop_StudentVersion_DW.ImageCompress_DIMS1_l = (int) image_size;
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }

      /* S-Function (channel_block): '<S15>/Channel' */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Raw RGB/Channel (channel_block) */
      {
        struct channel_info {
          t_channel_header header;
        } info;

        size_t width = 1;
        Stop_StudentVersion_B.Channel_o = CHANNEL_2;
        info.header.data_type_id = 3;
        info.header.channel = 2;
        info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
        info.header.num_dimensions = 1;
        width *= Stop_StudentVersion_DW.ImageCompress_DIMS1_l;
        info.header.dimension[0] = Stop_StudentVersion_DW.ImageCompress_DIMS1_l;
        channel_fifo_add((t_channel_fifo)
                         Stop_StudentVersion_DW.Channel_PWORK_d.Fifo,
                         &info.header, &Stop_StudentVersion_B.ImageCompress_g[0],
                         width * sizeof(uint8_T));
      }

      /* S-Function (image_find_objects_block): '<S8>/Image Find Objects' */

      /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Image Find Objects (image_find_objects_block) */
      {
        t_blob_criteria criteria;
        t_int result;
        t_int i;
        criteria.min_pixels = Stop_StudentVersion_P.ImageFindObjects_min_pixels;
        criteria.max_pixels = Stop_StudentVersion_P.ImageFindObjects_max_pixels;
        criteria.connectivity = (t_blob_connectivity)
          (Stop_StudentVersion_P.ImageFindObjects_connectivity - 1);
        criteria.sort_order = (t_blob_sort_order)
          (Stop_StudentVersion_P.ImageFindObjects_sort_order - 1);
        criteria.largest = (Stop_StudentVersion_P.ImageFindObjects_largest != 0);
        criteria.exclude_edges =
          (Stop_StudentVersion_P.ImageFindObjects_exclude_at_edg != 0);
        result = image_find_blobs_uint8
          (Stop_StudentVersion_DW.ImageFindObjects_FindHandle,
           &Stop_StudentVersion_B.HSVColorThresholding[0], &criteria,
           &ImageFindObjects_Blobs, 1);
        if (result >= 0) {
          rtb_ImageFindObjects_o1 = (t_uint) result;
          for (i = 0; i < result; i++) {
            rtb_ImageFindObjects_o2 = ImageFindObjects_Blobs.num_pixels;
            rtb_ImageFindObjects_o3[2*i] = ImageFindObjects_Blobs.centroid_row;
            rtb_ImageFindObjects_o3[2*i + 1] =
              ImageFindObjects_Blobs.centroid_column;
            rtb_ImageFindObjects_o4[4*i] = ImageFindObjects_Blobs.min_row;
            rtb_ImageFindObjects_o4[4*i + 1] = ImageFindObjects_Blobs.min_column;
            rtb_ImageFindObjects_o4[4*i + 2] = ImageFindObjects_Blobs.max_row;
            rtb_ImageFindObjects_o4[4*i + 3] = ImageFindObjects_Blobs.max_column;
            rtb_ImageFindObjects_o5 = (t_single)
              ImageFindObjects_Blobs.num_pixels / ((t_single)
              (ImageFindObjects_Blobs.max_row - ImageFindObjects_Blobs.min_row +
               1) * (ImageFindObjects_Blobs.max_column -
                     ImageFindObjects_Blobs.min_column + 1));
          }
        } else {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }

      /* RelationalOperator: '<S14>/Compare' incorporates:
       *  Constant: '<S14>/Constant'
       */
      Stop_StudentVersion_B.Compare_c = (rtb_ImageFindObjects_o1 ==
        Stop_StudentVersion_P.CompareToConstant_const_h);

      /* Sum: '<S8>/Subtract' incorporates:
       *  Constant: '<S8>/Constant3'
       *  S-Function (image_find_objects_block): '<S8>/Image Find Objects'
       */
      Stop_StudentVersion_B.Subtract[0] = rtb_ImageFindObjects_o3[0] -
        Stop_StudentVersion_P.Constant3_Value[0];
      Stop_StudentVersion_B.Subtract[1] = rtb_ImageFindObjects_o3[1] -
        Stop_StudentVersion_P.Constant3_Value[1];
      if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
        srUpdateBC(Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB);
      }
    }

    /* End of Outputs for SubSystem: '<Root>/findStopSignLocation' */

    /* Outputs for Enabled SubSystem: '<Root>/findStopSignDistance' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    /* Logic: '<Root>/Logical Operator' */
    if (rtb_Depth_o4 && Stop_StudentVersion_B.Compare_c) {
      /* S-Function (image_compress_block): '<S12>/Image Compress' */

      /* S-Function Block: Stop_StudentVersion/findStopSignDistance/Depth Image (m)/Image Compress (image_compress_block) */
      {
        t_error result = 0;
        size_t image_size = 0;
        result = qjpeg_compress_start
          (Stop_StudentVersion_DW.ImageCompress_Compress_g, true);
        if (result == 0) {
          result = qjpeg_compress_write_image_single
            (Stop_StudentVersion_DW.ImageCompress_Compress_g,
             &Stop_StudentVersion_B.Depth_o1[0]);
          qjpeg_compress_stop(Stop_StudentVersion_DW.ImageCompress_Compress_g);

          /* Get the final size of the compressed image */
          if (result >= 0) {
            result = qjpeg_compress_get_fixed_memory_destination_size
              (Stop_StudentVersion_DW.ImageCompress_Compress_g, &image_size);
          }
        }

        /* Set the dimensions of the output signal based on the size of the compressed image */
        Stop_StudentVersion_DW.ImageCompress_DIMS1_e = (int) image_size;
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }

      /* S-Function (channel_block): '<S12>/Channel' */

      /* S-Function Block: Stop_StudentVersion/findStopSignDistance/Depth Image (m)/Channel (channel_block) */
      {
        struct channel_info {
          t_channel_header header;
        } info;

        size_t width = 1;
        Stop_StudentVersion_B.Channel_a = CHANNEL_0;
        info.header.data_type_id = 3;
        info.header.channel = 0;
        info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
        info.header.num_dimensions = 1;
        width *= Stop_StudentVersion_DW.ImageCompress_DIMS1_e;
        info.header.dimension[0] = Stop_StudentVersion_DW.ImageCompress_DIMS1_e;
        channel_fifo_add((t_channel_fifo)
                         Stop_StudentVersion_DW.Channel_PWORK_f.Fifo,
                         &info.header, &Stop_StudentVersion_B.ImageCompress_c[0],
                         width * sizeof(uint8_T));
      }

      /* Gain: '<S7>/Adjust for V-FOV' */
      rtb_Gain_i = Stop_StudentVersion_P.AdjustforVFOV_Gain *
        Stop_StudentVersion_B.Subtract[0];

      /* Gain: '<S7>/Adjust for H-FOV' */
      rtb_SteeringBias = Stop_StudentVersion_P.AdjustforHFOV_Gain *
        Stop_StudentVersion_B.Subtract[1];

      /* Selector: '<S7>/Selector' incorporates:
       *  Constant: '<S7>/Constant'
       *  Constant: '<S7>/Constant1'
       *  DataTypeConversion: '<S7>/Data Type Conversion'
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  Sum: '<S7>/Add'
       *  Sum: '<S7>/Add1'
       */
      rtb_Gain_i = floor(Stop_StudentVersion_P.Constant_Value + rtb_Gain_i);
      if (rtIsNaN(rtb_Gain_i) || rtIsInf(rtb_Gain_i)) {
        rtb_Gain_i = 0.0;
      } else {
        rtb_Gain_i = fmod(rtb_Gain_i, 65536.0);
      }

      rtb_SteeringBias = floor(rtb_SteeringBias +
        Stop_StudentVersion_P.Constant1_Value);
      if (rtIsNaN(rtb_SteeringBias) || rtIsInf(rtb_SteeringBias)) {
        rtb_SteeringBias = 0.0;
      } else {
        rtb_SteeringBias = fmod(rtb_SteeringBias, 65536.0);
      }

      /* Selector: '<S7>/Selector' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion'
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  S-Function (video3d_capture_block): '<S6>/Depth'
       */
      Stop_StudentVersion_B.Selector = Stop_StudentVersion_B.Depth_o1
        [(((rtb_SteeringBias < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
            -rtb_SteeringBias : (int32_T)(int16_T)(uint16_T)rtb_SteeringBias) -
           1) * 720 + (rtb_Gain_i < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                       -rtb_Gain_i : (int32_T)(int16_T)(uint16_T)rtb_Gain_i)) -
        1];
      if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
        srUpdateBC(Stop_StudentVersion_DW.findStopSignDistance_SubsysRanB);
      }
    }

    /* End of Logic: '<Root>/Logical Operator' */
    /* End of Outputs for SubSystem: '<Root>/findStopSignDistance' */

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/m//s'
     */
    if (Stop_StudentVersion_B.Selector < 0.4) {
      rtb_SteeringBias = 0.0;
    } else {
      rtb_SteeringBias = Stop_StudentVersion_P.ms_Value;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Saturate: '<S10>/command saturation' */
    if (rtb_SteeringBias > Stop_StudentVersion_P.commandsaturation_UpperSat) {
      rtb_SteeringBias = Stop_StudentVersion_P.commandsaturation_UpperSat;
    } else if (rtb_SteeringBias <
               Stop_StudentVersion_P.commandsaturation_LowerSat) {
      rtb_SteeringBias = Stop_StudentVersion_P.commandsaturation_LowerSat;
    }

    /* End of Saturate: '<S10>/command saturation' */

    /* Product: '<S10>/Multiply1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Stop_StudentVersion_B.desired = rtb_SteeringBias *
      Stop_StudentVersion_P.Constant_Value_j;

    /* Gain: '<S10>/Kff  (% // m//s)' */
    Stop_StudentVersion_B.Kffms = Stop_StudentVersion_P.Kffms_Gain *
      Stop_StudentVersion_B.desired;
  }

  /* Product: '<S10>/Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S5>/counts to rotations'
   *  Gain: '<S5>/gear ratios'
   *  Gain: '<S5>/rot//s to rad//s'
   *  Gain: '<S5>/wheel radius'
   */
  Stop_StudentVersion_B.measured = Stop_StudentVersion_P.countstorotations_Gain *
    Stop_StudentVersion_B.Product1 * Stop_StudentVersion_P.gearratios_Gain *
    Stop_StudentVersion_P.rotstorads_Gain *
    Stop_StudentVersion_P.wheelradius_Gain *
    Stop_StudentVersion_P.Constant_Value_j;

  /* Sum: '<S10>/Sum' */
  rtb_Gain_i = Stop_StudentVersion_B.desired - Stop_StudentVersion_B.measured;
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    /* RelationalOperator: '<S18>/Compare' incorporates:
     *  Constant: '<S18>/Constant'
     */
    Stop_StudentVersion_B.Compare = (Stop_StudentVersion_B.desired ==
      Stop_StudentVersion_P.Constant_Value_l);
  }

  /* Integrator: '<S10>/Integrator1' */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    didZcEventOccur = (((Stop_StudentVersion_PrevZCX.Integrator1_Reset_ZCE == 1)
                        != (int32_T)Stop_StudentVersion_B.Compare) &&
                       (Stop_StudentVersion_PrevZCX.Integrator1_Reset_ZCE != 3));
    Stop_StudentVersion_PrevZCX.Integrator1_Reset_ZCE =
      Stop_StudentVersion_B.Compare;

    /* evaluate zero-crossings */
    if (didZcEventOccur) {
      Stop_StudentVersion_X.Integrator1_CSTATE_o =
        Stop_StudentVersion_P.Integrator1_IC;
    }
  }

  if (Stop_StudentVersion_X.Integrator1_CSTATE_o >=
      Stop_StudentVersion_P.Integrator1_UpperSat) {
    Stop_StudentVersion_X.Integrator1_CSTATE_o =
      Stop_StudentVersion_P.Integrator1_UpperSat;
  } else if (Stop_StudentVersion_X.Integrator1_CSTATE_o <=
             Stop_StudentVersion_P.Integrator1_LowerSat) {
    Stop_StudentVersion_X.Integrator1_CSTATE_o =
      Stop_StudentVersion_P.Integrator1_LowerSat;
  }

  /* Gain: '<S3>/direction convention' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S10>/Kp (% // m//s)'
   *  Integrator: '<S10>/Integrator1'
   *  Product: '<S10>/Multiply2'
   *  Sum: '<S10>/Add'
   *  Sum: '<S10>/Add1'
   */
  rtb_SteeringBias = ((Stop_StudentVersion_P.Kpms_Gain * rtb_Gain_i +
                       Stop_StudentVersion_X.Integrator1_CSTATE_o) +
                      Stop_StudentVersion_B.Kffms) *
    Stop_StudentVersion_P.Constant_Value_j *
    Stop_StudentVersion_P.directionconvention_Gain;

  /* Saturate: '<S3>/command saturation' */
  if (rtb_SteeringBias > Stop_StudentVersion_P.commandsaturation_UpperSat_e) {
    /* Saturate: '<S3>/command saturation' */
    Stop_StudentVersion_B.commandsaturation =
      Stop_StudentVersion_P.commandsaturation_UpperSat_e;
  } else if (rtb_SteeringBias <
             Stop_StudentVersion_P.commandsaturation_LowerSat_h) {
    /* Saturate: '<S3>/command saturation' */
    Stop_StudentVersion_B.commandsaturation =
      Stop_StudentVersion_P.commandsaturation_LowerSat_h;
  } else {
    /* Saturate: '<S3>/command saturation' */
    Stop_StudentVersion_B.commandsaturation = rtb_SteeringBias;
  }

  /* End of Saturate: '<S3>/command saturation' */
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    /* Bias: '<S3>/Steering Bias' incorporates:
     *  Constant: '<S3>/Steering'
     *  Gain: '<S3>/Gain'
     */
    rtb_SteeringBias = Stop_StudentVersion_P.Gain_Gain_j *
      Stop_StudentVersion_P.Steering_Value +
      Stop_StudentVersion_P.SteeringBias_Bias;

    /* S-Function (hil_write_block): '<S3>/HIL Write' */

    /* S-Function Block: Stop_StudentVersion/QCar/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(Stop_StudentVersion_DW.HILInitialize_Card,
                         NULL, 0U,
                         &Stop_StudentVersion_P.HILWrite_pwm_channels, 1U,
                         NULL, 0U,
                         &Stop_StudentVersion_P.HILWrite_other_channels, 1U,
                         NULL,
                         &Stop_StudentVersion_B.commandsaturation,
                         NULL,
                         &rtb_SteeringBias
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      }
    }

    /* S-Function (video3d_initialize_block): '<S6>/Video3D Initialize' */

    /* S-Function Block: Stop_StudentVersion/captureRGBD/Video3D Initialize (video3d_initialize_block) */
    {
    }
  }

  /* Gain: '<S10>/Ki (% // m)  ' */
  Stop_StudentVersion_B.Kim = Stop_StudentVersion_P.Kim_Gain * rtb_Gain_i;
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    /* S-Function (sample_time_block): '<S9>/Sample Time' */

    /* S-Function Block: Stop_StudentVersion/monitorTiming /Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &Stop_StudentVersion_DW.SampleTime_PreviousTime);
        Stop_StudentVersion_B.actualsampletime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&Stop_StudentVersion_DW.SampleTime_PreviousTime, &current_time,
               sizeof(t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    /* Constant: '<S9>/Constant' */
    Stop_StudentVersion_B.reference = Stop_StudentVersion_P.Constant_Value_e;

    /* S-Function (computation_time_block): '<S9>/Computation Time' */

    /* S-Function Block: Stop_StudentVersion/monitorTiming /Computation Time (computation_time_block) */
    {
      Stop_StudentVersion_B.computationtime =
        Stop_StudentVersion_DW.ComputationTime_ComputationTime.seconds +
        Stop_StudentVersion_DW.ComputationTime_ComputationTime.nanoseconds *
        1e-9;
    }
  }
}

/* Model update function */
void Stop_StudentVersion_update(void)
{
  /* Update for Integrator: '<S11>/Integrator1' */
  Stop_StudentVersion_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(Stop_StudentVersion_M)) {
    rt_ertODEUpdateContinuousStates(&Stop_StudentVersion_M->solverInfo);
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
  if (!(++Stop_StudentVersion_M->Timing.clockTick0)) {
    ++Stop_StudentVersion_M->Timing.clockTickH0;
  }

  Stop_StudentVersion_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Stop_StudentVersion_M->solverInfo);

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
    if (!(++Stop_StudentVersion_M->Timing.clockTick1)) {
      ++Stop_StudentVersion_M->Timing.clockTickH1;
    }

    Stop_StudentVersion_M->Timing.t[1] =
      Stop_StudentVersion_M->Timing.clockTick1 *
      Stop_StudentVersion_M->Timing.stepSize1 +
      Stop_StudentVersion_M->Timing.clockTickH1 *
      Stop_StudentVersion_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Stop_StudentVersion_derivatives(void)
{
  XDot_Stop_StudentVersion_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Stop_StudentVersion_T *) Stop_StudentVersion_M->derivs);

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Stop_StudentVersion_B.Product1;

  /* Derivatives for Integrator: '<S11>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Stop_StudentVersion_B.Product;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  lsat = (Stop_StudentVersion_X.Integrator1_CSTATE_o <=
          Stop_StudentVersion_P.Integrator1_LowerSat);
  usat = (Stop_StudentVersion_X.Integrator1_CSTATE_o >=
          Stop_StudentVersion_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Stop_StudentVersion_B.Kim > 0.0)) ||
      (usat && (Stop_StudentVersion_B.Kim < 0.0))) {
    _rtXdot->Integrator1_CSTATE_o = Stop_StudentVersion_B.Kim;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_o = 0.0;
  }

  /* End of Derivatives for Integrator: '<S10>/Integrator1' */
}

/* Model initialize function */
void Stop_StudentVersion_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: Stop_StudentVersion/QCar/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qcar", "0", &Stop_StudentVersion_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Stop_StudentVersion_DW.HILInitialize_Card,
       "gyro_fs=250;gyro_rate=64;accel_fs=2;accel_rate=62.5;mag_rate=20;mag_xy=47;mag_z=83;enc1_dir=0;enc2_dir=0;enc3_dir=0;enc4_dir=0;pwm1_dshot=0;pwm2_dshot=0;pwm3_dshot=0;pwm4_dshot=0;pwm5_dshot=0;pwm6_dshot=0;pwm7_dshot=0;steer_bias=0.05;motor_limit=0.3;",
       251);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Stop_StudentVersion_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      return;
    }

    if ((Stop_StudentVersion_P.HILInitialize_AIPStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &Stop_StudentVersion_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMinimums[i1] = Stop_StudentVersion_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &Stop_StudentVersion_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 7; i1++) {
          dw_AIMaximums[i1] = Stop_StudentVersion_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Stop_StudentVersion_DW.HILInitialize_Card,
         Stop_StudentVersion_P.HILInitialize_AIChannels, 7U,
         &Stop_StudentVersion_DW.HILInitialize_AIMinimums[0],
         &Stop_StudentVersion_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (Stop_StudentVersion_DW.HILInitialize_Card,
       Stop_StudentVersion_P.HILInitialize_DIChannels, 20U,
       &Stop_StudentVersion_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      return;
    }

    if ((Stop_StudentVersion_P.HILInitialize_DOStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Stop_StudentVersion_DW.HILInitialize_Card,
        &Stop_StudentVersion_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Stop_StudentVersion_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    if ((Stop_StudentVersion_P.HILInitialize_EIPStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_EIPEnter && is_switching)) {
      Stop_StudentVersion_DW.HILInitialize_QuadratureModes[0] =
        (Stop_StudentVersion_P.HILInitialize_EIQuadrature[0]);
      Stop_StudentVersion_DW.HILInitialize_QuadratureModes[1] =
        (Stop_StudentVersion_P.HILInitialize_EIQuadrature[1]);
      Stop_StudentVersion_DW.HILInitialize_QuadratureModes[2] =
        (Stop_StudentVersion_P.HILInitialize_EIQuadrature[1]);
      Stop_StudentVersion_DW.HILInitialize_QuadratureModes[3] =
        (Stop_StudentVersion_P.HILInitialize_EIQuadrature[1]);
      Stop_StudentVersion_DW.HILInitialize_QuadratureModes[4] =
        (Stop_StudentVersion_P.HILInitialize_EIQuadrature[1]);
      result = hil_set_encoder_quadrature_mode
        (Stop_StudentVersion_DW.HILInitialize_Card,
         Stop_StudentVersion_P.HILInitialize_EIChannels, 5U,
         (t_encoder_quadrature_mode *)
         &Stop_StudentVersion_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &Stop_StudentVersion_DW.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 5; i1++) {
          dw_FilterFrequency[i1] =
            Stop_StudentVersion_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (Stop_StudentVersion_DW.HILInitialize_Card,
         Stop_StudentVersion_P.HILInitialize_EIChannels, 5U,
         &Stop_StudentVersion_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    if ((Stop_StudentVersion_P.HILInitialize_EIStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Stop_StudentVersion_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 5; i1++) {
          dw_InitialEICounts[i1] = Stop_StudentVersion_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Stop_StudentVersion_DW.HILInitialize_Card,
        Stop_StudentVersion_P.HILInitialize_EIChannels, 5U,
        &Stop_StudentVersion_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    if ((Stop_StudentVersion_P.HILInitialize_POPStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      Stop_StudentVersion_DW.HILInitialize_POModeValues[0] =
        (Stop_StudentVersion_P.HILInitialize_POModes[0]);

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Stop_StudentVersion_DW.HILInitialize_POModeValues[1];
        for (i1=0; i1 < 7; i1++) {
          dw_POModeValues[i1] = (Stop_StudentVersion_P.HILInitialize_POModes[1]);
        }
      }

      result = hil_set_pwm_mode(Stop_StudentVersion_DW.HILInitialize_Card,
        Stop_StudentVersion_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Stop_StudentVersion_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Stop_StudentVersion_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &Stop_StudentVersion_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Stop_StudentVersion_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            Stop_StudentVersion_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Stop_StudentVersion_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Stop_StudentVersion_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            Stop_StudentVersion_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Stop_StudentVersion_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Stop_StudentVersion_DW.HILInitialize_Card,
          &Stop_StudentVersion_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &Stop_StudentVersion_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (Stop_StudentVersion_DW.HILInitialize_Card,
           &Stop_StudentVersion_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &Stop_StudentVersion_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Stop_StudentVersion_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Stop_StudentVersion_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Stop_StudentVersion_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Stop_StudentVersion_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Stop_StudentVersion_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Stop_StudentVersion_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (Stop_StudentVersion_DW.HILInitialize_Card,
         Stop_StudentVersion_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &Stop_StudentVersion_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &Stop_StudentVersion_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &Stop_StudentVersion_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    if ((Stop_StudentVersion_P.HILInitialize_POStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Stop_StudentVersion_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Stop_StudentVersion_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Stop_StudentVersion_DW.HILInitialize_Card,
        Stop_StudentVersion_P.HILInitialize_POChannels, 8U,
        &Stop_StudentVersion_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    if (Stop_StudentVersion_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Stop_StudentVersion_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Stop_StudentVersion_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Stop_StudentVersion_DW.HILInitialize_Card,
         Stop_StudentVersion_P.HILInitialize_POChannels, 8U,
         &Stop_StudentVersion_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }

    if ((Stop_StudentVersion_P.HILInitialize_OOStart && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_OOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Stop_StudentVersion_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Stop_StudentVersion_P.HILInitialize_OOInitial;
        }
      }

      result = hil_write_other(Stop_StudentVersion_DW.HILInitialize_Card,
        Stop_StudentVersion_P.HILInitialize_OOChannels, 13U,
        &Stop_StudentVersion_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S3>/Unwrap 2^24' */

  /* S-Function Block: Stop_StudentVersion/QCar/Unwrap 2^24 (inverse_modulus_block) */
  {
    Stop_StudentVersion_DW.Unwrap224_FirstSample = true;
    Stop_StudentVersion_DW.Unwrap224_Revolutions = 0;
  }

  /* Start for S-Function (video3d_capture_block): '<S6>/Depth' */
  {
    t_error result;
    result = video3d_stream_open
      (Stop_StudentVersion_DW.Video3DInitialize_Video3D, VIDEO3D_STREAM_DEPTH,
       Stop_StudentVersion_P.Depth_stream_index, 30.0, 1280, 720,
       IMAGE_FORMAT_COL_MAJOR_GRAYSCALE, IMAGE_DATA_TYPE_SINGLE,
       &Stop_StudentVersion_DW.Depth_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (Stop_StudentVersion_P.Depth_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (Stop_StudentVersion_P.Depth_Preset - 1);
        num_config_properties++;
      }

      if (Stop_StudentVersion_P.Depth_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (Stop_StudentVersion_P.Depth_Emitter == 1) ? 1.0 : 0.0;
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
        video3d_stream_set_properties(Stop_StudentVersion_DW.Depth_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video3d_capture_block): '<S6>/RGB' */
  {
    t_error result;
    result = video3d_stream_open
      (Stop_StudentVersion_DW.Video3DInitialize_Video3D, VIDEO3D_STREAM_COLOR,
       Stop_StudentVersion_P.RGB_stream_index, 30.0, 1280, 720,
       IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
       &Stop_StudentVersion_DW.RGB_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (Stop_StudentVersion_P.RGB_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (Stop_StudentVersion_P.RGB_Preset - 1);
        num_config_properties++;
      }

      if (Stop_StudentVersion_P.RGB_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (Stop_StudentVersion_P.RGB_Emitter == 1) ? 1.0 : 0.0;
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
        video3d_stream_set_properties(Stop_StudentVersion_DW.RGB_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<Root>/findStopSignLocation' */

  /* Start for S-Function (image_transform_block): '<S16>/Image Transform' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    t_error result;
    result = image_rgb_to_hsv_open
      (&Stop_StudentVersion_DW.ImageTransform_AlgHandle);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S13>/Image Compress' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Binary showing blob found/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Stop_StudentVersion_DW.ImageCompress_Compress);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Stop_StudentVersion_DW.ImageCompress_Compress, 1280, 720,
           COLOR_SPACE_GRAYSCALE, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Stop_StudentVersion_DW.ImageCompress_Compress,
           Stop_StudentVersion_P.ImageCompress_Quality_o);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Stop_StudentVersion_DW.ImageCompress_Compress,
           &Stop_StudentVersion_B.ImageCompress[0], 921600);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Stop_StudentVersion_DW.ImageCompress_Compress);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S13>/Channel' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Binary showing blob found/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(1, sizeof(uint8_T), 1, 921600, 1,
      (t_channel_fifo *) &Stop_StudentVersion_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S15>/Image Compress' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Raw RGB/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Stop_StudentVersion_DW.ImageCompress_Compress_c);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Stop_StudentVersion_DW.ImageCompress_Compress_c, 1280, 720,
           COLOR_SPACE_RGB, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Stop_StudentVersion_DW.ImageCompress_Compress_c,
           Stop_StudentVersion_P.ImageCompress_Quality_f);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Stop_StudentVersion_DW.ImageCompress_Compress_c,
           &Stop_StudentVersion_B.ImageCompress_g[0], 2764800);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Stop_StudentVersion_DW.ImageCompress_Compress_c);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S15>/Channel' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Raw RGB/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(2, sizeof(uint8_T), 1, 2764800, 1,
      (t_channel_fifo *) &Stop_StudentVersion_DW.Channel_PWORK_d.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_find_objects_block): '<S8>/Image Find Objects' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Image Find Objects (image_find_objects_block) */
  {
    t_error result;
    result = image_find_blobs_initialize(1280, 720,
      &Stop_StudentVersion_DW.ImageFindObjects_FindHandle);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/findStopSignLocation' */

  /* Start for Enabled SubSystem: '<Root>/findStopSignDistance' */

  /* Start for S-Function (image_compress_block): '<S12>/Image Compress' */

  /* S-Function Block: Stop_StudentVersion/findStopSignDistance/Depth Image (m)/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Stop_StudentVersion_DW.ImageCompress_Compress_g);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Stop_StudentVersion_DW.ImageCompress_Compress_g, 1280, 720,
           COLOR_SPACE_GRAYSCALE, IMAGE_DATA_TYPE_SINGLE);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Stop_StudentVersion_DW.ImageCompress_Compress_g,
           Stop_StudentVersion_P.ImageCompress_Quality);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Stop_StudentVersion_DW.ImageCompress_Compress_g,
           &Stop_StudentVersion_B.ImageCompress_c[0], 921600);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Stop_StudentVersion_DW.ImageCompress_Compress_g);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S12>/Channel' */

  /* S-Function Block: Stop_StudentVersion/findStopSignDistance/Depth Image (m)/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 1, 921600, 1,
      (t_channel_fifo *) &Stop_StudentVersion_DW.Channel_PWORK_f.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/findStopSignDistance' */

  /* Start for S-Function (video3d_initialize_block): '<S6>/Video3D Initialize' */

  /* S-Function Block: Stop_StudentVersion/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0", &Stop_StudentVersion_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (sample_time_block): '<S9>/Sample Time' */

  /* S-Function Block: Stop_StudentVersion/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Stop_StudentVersion_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
      return;
    }
  }

  Stop_StudentVersion_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S11>/Integrator1' */
  if (rtmIsFirstInitCond(Stop_StudentVersion_M)) {
    Stop_StudentVersion_X.Integrator1_CSTATE = 0.0;
  }

  Stop_StudentVersion_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S11>/Integrator1' */

  /* InitializeConditions for Integrator: '<S11>/Integrator2' */
  Stop_StudentVersion_X.Integrator2_CSTATE =
    Stop_StudentVersion_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  Stop_StudentVersion_X.Integrator1_CSTATE_o =
    Stop_StudentVersion_P.Integrator1_IC;

  /* InitializeConditions for S-Function (video3d_initialize_block): '<S6>/Video3D Initialize' */

  /* S-Function Block: Stop_StudentVersion/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    if (rtmIsFirstInitCond(Stop_StudentVersion_M)) {
      t_error result = video3d_start_streaming
        (Stop_StudentVersion_DW.Video3DInitialize_Video3D);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        return;
      }
    }
  }

  /* SystemInitialize for Enabled SubSystem: '<Root>/findStopSignLocation' */
  /* SystemInitialize for RelationalOperator: '<S14>/Compare' incorporates:
   *  Outport: '<S8>/blobFound?'
   */
  Stop_StudentVersion_B.Compare_c = Stop_StudentVersion_P.blobFound_Y0;

  /* SystemInitialize for Sum: '<S8>/Subtract' incorporates:
   *  Outport: '<S8>/blobLocation (px) [2]'
   */
  Stop_StudentVersion_B.Subtract[0] = Stop_StudentVersion_P.blobLocationpx2_Y0;
  Stop_StudentVersion_B.Subtract[1] = Stop_StudentVersion_P.blobLocationpx2_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/findStopSignLocation' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/findStopSignDistance' */
  /* SystemInitialize for Selector: '<S7>/Selector' incorporates:
   *  Outport: '<S7>/distanceToSign (m)'
   */
  Stop_StudentVersion_B.Selector = Stop_StudentVersion_P.distanceToSignm_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/findStopSignDistance' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Stop_StudentVersion_M)) {
    rtmSetFirstInitCond(Stop_StudentVersion_M, 0);
  }
}

/* Model terminate function */
void Stop_StudentVersion_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: Stop_StudentVersion/QCar/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Stop_StudentVersion_DW.HILInitialize_Card);
    hil_monitor_stop_all(Stop_StudentVersion_DW.HILInitialize_Card);
    is_switching = false;
    if ((Stop_StudentVersion_P.HILInitialize_DOTerminate && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Stop_StudentVersion_P.HILInitialize_POTerminate && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Stop_StudentVersion_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Stop_StudentVersion_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if ((Stop_StudentVersion_P.HILInitialize_OOTerminate && !is_switching) ||
        (Stop_StudentVersion_P.HILInitialize_OOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_OOValues = &Stop_StudentVersion_DW.HILInitialize_OOValues[0];
        for (i1=0; i1 < 13; i1++) {
          dw_OOValues[i1] = Stop_StudentVersion_P.HILInitialize_OOFinal;
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
      result = hil_write(Stop_StudentVersion_DW.HILInitialize_Card
                         , NULL, 0
                         , Stop_StudentVersion_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &Stop_StudentVersion_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Stop_StudentVersion_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         , &Stop_StudentVersion_DW.HILInitialize_POValues[0]
                         , (t_boolean *)
                         &Stop_StudentVersion_P.HILInitialize_DOFinal
                         , &Stop_StudentVersion_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Stop_StudentVersion_DW.HILInitialize_Card,
            Stop_StudentVersion_P.HILInitialize_POChannels,
            num_final_pwm_outputs,
            &Stop_StudentVersion_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Stop_StudentVersion_DW.HILInitialize_Card,
             &Stop_StudentVersion_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &Stop_StudentVersion_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (Stop_StudentVersion_DW.HILInitialize_Card,
             Stop_StudentVersion_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             &Stop_StudentVersion_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Stop_StudentVersion_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Stop_StudentVersion_DW.HILInitialize_Card);
    hil_monitor_delete_all(Stop_StudentVersion_DW.HILInitialize_Card);
    hil_close(Stop_StudentVersion_DW.HILInitialize_Card);
    Stop_StudentVersion_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for Enabled SubSystem: '<Root>/findStopSignLocation' */

  /* Terminate for S-Function (image_transform_block): '<S16>/Image Transform' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    image_rgb_to_hsv_close(Stop_StudentVersion_DW.ImageTransform_AlgHandle);
  }

  /* Terminate for S-Function (image_compress_block): '<S13>/Image Compress' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Binary showing blob found/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Stop_StudentVersion_DW.ImageCompress_Compress);
    Stop_StudentVersion_DW.ImageCompress_Compress = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S13>/Channel' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Binary showing blob found/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Stop_StudentVersion_DW.Channel_PWORK.Fifo);
    Stop_StudentVersion_DW.Channel_PWORK.Fifo = NULL;
  }

  /* Terminate for S-Function (image_compress_block): '<S15>/Image Compress' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Raw RGB/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Stop_StudentVersion_DW.ImageCompress_Compress_c);
    Stop_StudentVersion_DW.ImageCompress_Compress_c = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S15>/Channel' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Raw RGB/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Stop_StudentVersion_DW.Channel_PWORK_d.Fifo);
    Stop_StudentVersion_DW.Channel_PWORK_d.Fifo = NULL;
  }

  /* Terminate for S-Function (image_find_objects_block): '<S8>/Image Find Objects' */

  /* S-Function Block: Stop_StudentVersion/findStopSignLocation/Image Find Objects (image_find_objects_block) */
  {
    image_find_blobs_destroy(Stop_StudentVersion_DW.ImageFindObjects_FindHandle);
  }

  /* End of Terminate for SubSystem: '<Root>/findStopSignLocation' */

  /* Terminate for Enabled SubSystem: '<Root>/findStopSignDistance' */

  /* Terminate for S-Function (image_compress_block): '<S12>/Image Compress' */

  /* S-Function Block: Stop_StudentVersion/findStopSignDistance/Depth Image (m)/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Stop_StudentVersion_DW.ImageCompress_Compress_g);
    Stop_StudentVersion_DW.ImageCompress_Compress_g = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S12>/Channel' */

  /* S-Function Block: Stop_StudentVersion/findStopSignDistance/Depth Image (m)/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Stop_StudentVersion_DW.Channel_PWORK_f.Fifo);
    Stop_StudentVersion_DW.Channel_PWORK_f.Fifo = NULL;
  }

  /* End of Terminate for SubSystem: '<Root>/findStopSignDistance' */

  /* Terminate for S-Function (video3d_initialize_block): '<S6>/Video3D Initialize' */

  /* S-Function Block: Stop_StudentVersion/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming(Stop_StudentVersion_DW.Video3DInitialize_Video3D);
    video3d_close(Stop_StudentVersion_DW.Video3DInitialize_Video3D);
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
  Stop_StudentVersion_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Stop_StudentVersion_update();
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
  Stop_StudentVersion_initialize();
}

void MdlTerminate(void)
{
  Stop_StudentVersion_terminate();
}

/* Registration function */
RT_MODEL_Stop_StudentVersion_T *Stop_StudentVersion(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Stop_StudentVersion_M, 0,
                sizeof(RT_MODEL_Stop_StudentVersion_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Stop_StudentVersion_M->solverInfo,
                          &Stop_StudentVersion_M->Timing.simTimeStep);
    rtsiSetTPtr(&Stop_StudentVersion_M->solverInfo, &rtmGetTPtr
                (Stop_StudentVersion_M));
    rtsiSetStepSizePtr(&Stop_StudentVersion_M->solverInfo,
                       &Stop_StudentVersion_M->Timing.stepSize0);
    rtsiSetdXPtr(&Stop_StudentVersion_M->solverInfo,
                 &Stop_StudentVersion_M->derivs);
    rtsiSetContStatesPtr(&Stop_StudentVersion_M->solverInfo, (real_T **)
                         &Stop_StudentVersion_M->contStates);
    rtsiSetNumContStatesPtr(&Stop_StudentVersion_M->solverInfo,
      &Stop_StudentVersion_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Stop_StudentVersion_M->solverInfo,
      &Stop_StudentVersion_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Stop_StudentVersion_M->solverInfo,
      &Stop_StudentVersion_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Stop_StudentVersion_M->solverInfo,
      &Stop_StudentVersion_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Stop_StudentVersion_M->solverInfo,
                          (&rtmGetErrorStatus(Stop_StudentVersion_M)));
    rtsiSetRTModelPtr(&Stop_StudentVersion_M->solverInfo, Stop_StudentVersion_M);
  }

  rtsiSetSimTimeStep(&Stop_StudentVersion_M->solverInfo, MAJOR_TIME_STEP);
  Stop_StudentVersion_M->intgData.y = Stop_StudentVersion_M->odeY;
  Stop_StudentVersion_M->intgData.f[0] = Stop_StudentVersion_M->odeF[0];
  Stop_StudentVersion_M->intgData.f[1] = Stop_StudentVersion_M->odeF[1];
  Stop_StudentVersion_M->contStates = ((real_T *) &Stop_StudentVersion_X);
  rtsiSetSolverData(&Stop_StudentVersion_M->solverInfo, (void *)
                    &Stop_StudentVersion_M->intgData);
  rtsiSetSolverName(&Stop_StudentVersion_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Stop_StudentVersion_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Stop_StudentVersion_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Stop_StudentVersion_M->Timing.sampleTimes =
      (&Stop_StudentVersion_M->Timing.sampleTimesArray[0]);
    Stop_StudentVersion_M->Timing.offsetTimes =
      (&Stop_StudentVersion_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Stop_StudentVersion_M->Timing.sampleTimes[0] = (0.0);
    Stop_StudentVersion_M->Timing.sampleTimes[1] = (0.033333333333333333);

    /* task offsets */
    Stop_StudentVersion_M->Timing.offsetTimes[0] = (0.0);
    Stop_StudentVersion_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Stop_StudentVersion_M, &Stop_StudentVersion_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Stop_StudentVersion_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Stop_StudentVersion_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Stop_StudentVersion_M, -1);
  Stop_StudentVersion_M->Timing.stepSize0 = 0.033333333333333333;
  Stop_StudentVersion_M->Timing.stepSize1 = 0.033333333333333333;
  rtmSetFirstInitCond(Stop_StudentVersion_M, 1);

  /* External mode info */
  Stop_StudentVersion_M->Sizes.checksums[0] = (4173388711U);
  Stop_StudentVersion_M->Sizes.checksums[1] = (2932255332U);
  Stop_StudentVersion_M->Sizes.checksums[2] = (2238871025U);
  Stop_StudentVersion_M->Sizes.checksums[3] = (3338504648U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    Stop_StudentVersion_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Stop_StudentVersion_DW.findStopSignDistance_SubsysRanB;
    systemRan[3] = (sysRanDType *)
      &Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB;
    systemRan[4] = (sysRanDType *)
      &Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB;
    systemRan[5] = (sysRanDType *)
      &Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB;
    systemRan[6] = (sysRanDType *)
      &Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB;
    systemRan[7] = (sysRanDType *)
      &Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB;
    rteiSetModelMappingInfoPtr(Stop_StudentVersion_M->extModeInfo,
      &Stop_StudentVersion_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Stop_StudentVersion_M->extModeInfo,
                        Stop_StudentVersion_M->Sizes.checksums);
    rteiSetTPtr(Stop_StudentVersion_M->extModeInfo, rtmGetTPtr
                (Stop_StudentVersion_M));
  }

  Stop_StudentVersion_M->solverInfoPtr = (&Stop_StudentVersion_M->solverInfo);
  Stop_StudentVersion_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Stop_StudentVersion_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&Stop_StudentVersion_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Stop_StudentVersion_M->blockIO = ((void *) &Stop_StudentVersion_B);
  (void) memset(((void *) &Stop_StudentVersion_B), 0,
                sizeof(B_Stop_StudentVersion_T));

  {
    Stop_StudentVersion_B.Channel = CHANNEL_0;
    Stop_StudentVersion_B.Channel_o = CHANNEL_0;
    Stop_StudentVersion_B.Channel_a = CHANNEL_0;
  }

  /* parameters */
  Stop_StudentVersion_M->defaultParam = ((real_T *)&Stop_StudentVersion_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Stop_StudentVersion_X;
    Stop_StudentVersion_M->contStates = (x);
    (void) memset((void *)&Stop_StudentVersion_X, 0,
                  sizeof(X_Stop_StudentVersion_T));
  }

  /* states (dwork) */
  Stop_StudentVersion_M->dwork = ((void *) &Stop_StudentVersion_DW);
  (void) memset((void *)&Stop_StudentVersion_DW, 0,
                sizeof(DW_Stop_StudentVersion_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Stop_StudentVersion_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Stop_StudentVersion_M->Sizes.numContStates = (3);/* Number of continuous states */
  Stop_StudentVersion_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Stop_StudentVersion_M->Sizes.numY = (0);/* Number of model outputs */
  Stop_StudentVersion_M->Sizes.numU = (0);/* Number of model inputs */
  Stop_StudentVersion_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Stop_StudentVersion_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Stop_StudentVersion_M->Sizes.numBlocks = (95);/* Number of blocks */
  Stop_StudentVersion_M->Sizes.numBlockIO = (31);/* Number of block outputs */
  Stop_StudentVersion_M->Sizes.numBlockPrms = (227);/* Sum of parameter "widths" */
  return Stop_StudentVersion_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
