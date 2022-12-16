/*
 * RGBD_Imaging.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RGBD_Imaging".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 15:47:47 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RGBD_Imaging.h"
#include "RGBD_Imaging_private.h"
#include "RGBD_Imaging_dt.h"

/* Block signals (default storage) */
B_RGBD_Imaging_T RGBD_Imaging_B;

/* Block states (default storage) */
DW_RGBD_Imaging_T RGBD_Imaging_DW;

/* Real-time model */
static RT_MODEL_RGBD_Imaging_T RGBD_Imaging_M_;
RT_MODEL_RGBD_Imaging_T *const RGBD_Imaging_M = &RGBD_Imaging_M_;

/* Model output function */
void RGBD_Imaging_output(void)
{
  /* local block i/o variables */
  uint32_T rtb_ImageFindObjects_o2;
  uint32_T rtb_ImageFindObjects_o1;
  real32_T rtb_ImageFindObjects_o5;
  real32_T rtb_ImageFindObjects_o3[2];
  uint16_T rtb_ImageFindObjects_o4[4];
  boolean_T rtb_Depth_o4;

  /* local scratch DWork variables */
  t_blob ImageFindObjects_Blobs;
  real_T rtb_Add1;
  real_T rtb_Gain;

  /* Reset subsysRan breadcrumbs */
  srClearBC(RGBD_Imaging_DW.findStopSignDistance_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RGBD_Imaging_DW.findStopSignLocation_SubsysRanB);

  /* S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: RGBD_Imaging/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
  }

  /* S-Function (video3d_capture_block): '<S3>/Depth' */
  /* S-Function Block: RGBD_Imaging/captureRGBD/Depth (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame(RGBD_Imaging_DW.Depth_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_meters(frame, &RGBD_Imaging_B.Depth_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    rtb_Depth_o4 = (result >= 0);
    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* S-Function (video3d_capture_block): '<S3>/RGB' */
  /* S-Function Block: RGBD_Imaging/captureRGBD/RGB (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame(RGBD_Imaging_DW.RGB_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_data(frame, &RGBD_Imaging_B.RGB_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    RGBD_Imaging_B.RGB_o4 = (result >= 0);
    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Outputs for Enabled SubSystem: '<Root>/findStopSignLocation' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (RGBD_Imaging_B.RGB_o4) {
    /* S-Function (image_transform_block): '<S11>/Image Transform' */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/colorThresholdingHSV/Image Transform (image_transform_block) */
    {
      t_error result;
      result = image_rgb_to_hsv_uint8(RGBD_Imaging_DW.ImageTransform_AlgHandle,
        &RGBD_Imaging_B.RGB_o1[0], 1280, 720, &RGBD_Imaging_B.ImageTransform[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      }
    }

    /* Constant: '<S5>/Constant' */
    RGBD_Imaging_B.Constant = RGBD_Imaging_P.Constant_Value_c;

    /* Gain: '<S11>/Gain' */
    rtb_Gain = RGBD_Imaging_P.Gain_Gain * RGBD_Imaging_B.Constant;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Hue Threshold'
     *  Constant: '<S12>/Constant'
     *  RelationalOperator: '<S12>/Compare'
     *  Sum: '<S11>/Add3'
     *  Sum: '<S11>/Add4'
     *  Switch: '<S11>/Switch1'
     */
    if (RGBD_Imaging_B.Constant == RGBD_Imaging_P.CompareToConstant_const) {
      rtb_Add1 = RGBD_Imaging_P.Constant_Value_m;
      rtb_Gain = RGBD_Imaging_P.Constant1_Value_j;
    } else {
      rtb_Add1 = rtb_Gain - RGBD_Imaging_P.HueThreshold_Value;
      rtb_Gain += RGBD_Imaging_P.HueThreshold_Value;
    }

    /* End of Switch: '<S11>/Switch' */

    /* S-Function (image_compare_block): '<S11>/HSV Color Thresholding' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Constant: '<S5>/Constant2'
     */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/colorThresholdingHSV/HSV Color Thresholding (image_compare_block) */
    {
      t_error result;
      t_image_comparison_type comparisons[3];
      t_uint8 minimums[3];
      t_uint8 maximums[3];
      comparisons[0] = (t_image_comparison_type)
        (RGBD_Imaging_P.HSVColorThresholding_r_comparis - 1);
      comparisons[1] = (t_image_comparison_type)
        (RGBD_Imaging_P.HSVColorThresholding_g_comparis - 1);
      comparisons[2] = (t_image_comparison_type)
        (RGBD_Imaging_P.HSVColorThresholding_b_comparis - 1);
      if ((comparisons[0] & COMPARE_WRAP) == 0) {
        if (rtb_Add1 < 0) {
          minimums[0] = 0;
        } else if (rtb_Add1 > 255U) {
          minimums[0] = 255U;
        } else {
          minimums[0] = (t_uint8) rtb_Add1;
        }

        if (rtb_Gain < 0) {
          maximums[0] = 0;
        } else if (rtb_Gain > 255U) {
          maximums[0] = 255U;
        } else {
          maximums[0] = (t_uint8) rtb_Gain;
        }
      } else {
        minimums[0] = (t_uint8) (rtb_Add1 - 256U * floor(rtb_Add1 / 256U));
        maximums[0] = (t_uint8) (rtb_Gain - 256U * floor(rtb_Gain / 256U));
      }

      if ((comparisons[1] & COMPARE_WRAP) == 0) {
        if (RGBD_Imaging_P.Constant1_Value_a[0] < 0) {
          minimums[1] = 0;
        } else if (RGBD_Imaging_P.Constant1_Value_a[0] > 255U) {
          minimums[1] = 255U;
        } else {
          minimums[1] = (t_uint8) RGBD_Imaging_P.Constant1_Value_a[0];
        }

        if (RGBD_Imaging_P.Constant2_Value[0] < 0) {
          maximums[1] = 0;
        } else if (RGBD_Imaging_P.Constant2_Value[0] > 255U) {
          maximums[1] = 255U;
        } else {
          maximums[1] = (t_uint8) RGBD_Imaging_P.Constant2_Value[0];
        }
      } else {
        minimums[1] = (t_uint8) (RGBD_Imaging_P.Constant1_Value_a[0] - 256U *
          floor(RGBD_Imaging_P.Constant1_Value_a[0] / 256U));
        maximums[1] = (t_uint8) (RGBD_Imaging_P.Constant2_Value[0] - 256U *
          floor(RGBD_Imaging_P.Constant2_Value[0] / 256U));
      }

      if ((comparisons[2] & COMPARE_WRAP) == 0) {
        if (RGBD_Imaging_P.Constant1_Value_a[1] < 0) {
          minimums[2] = 0;
        } else if (RGBD_Imaging_P.Constant1_Value_a[1] > 255U) {
          minimums[2] = 255U;
        } else {
          minimums[2] = (t_uint8) RGBD_Imaging_P.Constant1_Value_a[1];
        }

        if (RGBD_Imaging_P.Constant2_Value[1] < 0) {
          maximums[2] = 0;
        } else if (RGBD_Imaging_P.Constant2_Value[1] > 255U) {
          maximums[2] = 255U;
        } else {
          maximums[2] = (t_uint8) RGBD_Imaging_P.Constant2_Value[1];
        }
      } else {
        minimums[2] = (t_uint8) (RGBD_Imaging_P.Constant1_Value_a[1] - 256U *
          floor(RGBD_Imaging_P.Constant1_Value_a[1] / 256U));
        maximums[2] = (t_uint8) (RGBD_Imaging_P.Constant2_Value[1] - 256U *
          floor(RGBD_Imaging_P.Constant2_Value[1] / 256U));
      }

      result = image_rgb_compare_range_uint8(&RGBD_Imaging_B.ImageTransform[0],
        1280, 720, comparisons, minimums, maximums, COMPARE_OUTPUT_COMBINED,
        &RGBD_Imaging_B.HSVColorThresholding[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      }
    }

    /* S-Function (image_compress_block): '<S8>/Image Compress' */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/Binary showing blob found/Image Compress (image_compress_block) */
    {
      t_error result = 0;
      size_t image_size = 0;
      result = qjpeg_compress_start(RGBD_Imaging_DW.ImageCompress_Compress, true);
      if (result == 0) {
        result = qjpeg_compress_write_image_uint8
          (RGBD_Imaging_DW.ImageCompress_Compress,
           &RGBD_Imaging_B.HSVColorThresholding[0]);
        qjpeg_compress_stop(RGBD_Imaging_DW.ImageCompress_Compress);

        /* Get the final size of the compressed image */
        if (result >= 0) {
          result = qjpeg_compress_get_fixed_memory_destination_size
            (RGBD_Imaging_DW.ImageCompress_Compress, &image_size);
        }
      }

      /* Set the dimensions of the output signal based on the size of the compressed image */
      RGBD_Imaging_DW.ImageCompress_DIMS1 = (int) image_size;
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      }
    }

    /* S-Function (channel_block): '<S8>/Channel' */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/Binary showing blob found/Channel (channel_block) */
    {
      struct channel_info {
        t_channel_header header;
      } info;

      size_t width = 1;
      RGBD_Imaging_B.Channel = CHANNEL_1;
      info.header.data_type_id = 3;
      info.header.channel = 1;
      info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
      info.header.num_dimensions = 1;
      width *= RGBD_Imaging_DW.ImageCompress_DIMS1;
      info.header.dimension[0] = RGBD_Imaging_DW.ImageCompress_DIMS1;
      channel_fifo_add((t_channel_fifo) RGBD_Imaging_DW.Channel_PWORK.Fifo,
                       &info.header, &RGBD_Imaging_B.ImageCompress[0], width *
                       sizeof(uint8_T));
    }

    /* S-Function (image_compress_block): '<S10>/Image Compress' */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/Raw RGB/Image Compress (image_compress_block) */
    {
      t_error result = 0;
      size_t image_size = 0;
      result = qjpeg_compress_start(RGBD_Imaging_DW.ImageCompress_Compress_c,
        true);
      if (result == 0) {
        result = qjpeg_compress_write_image_uint8
          (RGBD_Imaging_DW.ImageCompress_Compress_c, &RGBD_Imaging_B.RGB_o1[0]);
        qjpeg_compress_stop(RGBD_Imaging_DW.ImageCompress_Compress_c);

        /* Get the final size of the compressed image */
        if (result >= 0) {
          result = qjpeg_compress_get_fixed_memory_destination_size
            (RGBD_Imaging_DW.ImageCompress_Compress_c, &image_size);
        }
      }

      /* Set the dimensions of the output signal based on the size of the compressed image */
      RGBD_Imaging_DW.ImageCompress_DIMS1_l = (int) image_size;
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      }
    }

    /* S-Function (channel_block): '<S10>/Channel' */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/Raw RGB/Channel (channel_block) */
    {
      struct channel_info {
        t_channel_header header;
      } info;

      size_t width = 1;
      RGBD_Imaging_B.Channel_o = CHANNEL_2;
      info.header.data_type_id = 3;
      info.header.channel = 2;
      info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
      info.header.num_dimensions = 1;
      width *= RGBD_Imaging_DW.ImageCompress_DIMS1_l;
      info.header.dimension[0] = RGBD_Imaging_DW.ImageCompress_DIMS1_l;
      channel_fifo_add((t_channel_fifo) RGBD_Imaging_DW.Channel_PWORK_d.Fifo,
                       &info.header, &RGBD_Imaging_B.ImageCompress_g[0], width *
                       sizeof(uint8_T));
    }

    /* S-Function (image_find_objects_block): '<S5>/Image Find Objects' */

    /* S-Function Block: RGBD_Imaging/findStopSignLocation/Image Find Objects (image_find_objects_block) */
    {
      t_blob_criteria criteria;
      t_int result;
      t_int i;
      criteria.min_pixels = RGBD_Imaging_P.ImageFindObjects_min_pixels;
      criteria.max_pixels = RGBD_Imaging_P.ImageFindObjects_max_pixels;
      criteria.connectivity = (t_blob_connectivity)
        (RGBD_Imaging_P.ImageFindObjects_connectivity - 1);
      criteria.sort_order = (t_blob_sort_order)
        (RGBD_Imaging_P.ImageFindObjects_sort_order - 1);
      criteria.largest = (RGBD_Imaging_P.ImageFindObjects_largest != 0);
      criteria.exclude_edges = (RGBD_Imaging_P.ImageFindObjects_exclude_at_edg
        != 0);
      result = image_find_blobs_uint8
        (RGBD_Imaging_DW.ImageFindObjects_FindHandle,
         &RGBD_Imaging_B.HSVColorThresholding[0], &criteria,
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
          rtb_ImageFindObjects_o5 = (t_single) ImageFindObjects_Blobs.num_pixels
            / ((t_single) (ImageFindObjects_Blobs.max_row -
                           ImageFindObjects_Blobs.min_row + 1) *
               (ImageFindObjects_Blobs.max_column -
                ImageFindObjects_Blobs.min_column + 1));
        }
      } else {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      }
    }

    /* RelationalOperator: '<S9>/Compare' incorporates:
     *  Constant: '<S9>/Constant'
     */
    RGBD_Imaging_B.Compare = (rtb_ImageFindObjects_o1 ==
      RGBD_Imaging_P.CompareToConstant_const_h);

    /* Sum: '<S5>/Subtract' incorporates:
     *  Constant: '<S5>/Constant3'
     *  S-Function (image_find_objects_block): '<S5>/Image Find Objects'
     */
    RGBD_Imaging_B.Subtract[0] = rtb_ImageFindObjects_o3[0] -
      RGBD_Imaging_P.Constant3_Value[0];
    RGBD_Imaging_B.Subtract[1] = rtb_ImageFindObjects_o3[1] -
      RGBD_Imaging_P.Constant3_Value[1];
    srUpdateBC(RGBD_Imaging_DW.findStopSignLocation_SubsysRanB);
  }

  /* End of Outputs for SubSystem: '<Root>/findStopSignLocation' */

  /* Outputs for Enabled SubSystem: '<Root>/findStopSignDistance' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<Root>/Logical Operator' */
  if (rtb_Depth_o4 && RGBD_Imaging_B.Compare) {
    /* S-Function (image_compress_block): '<S7>/Image Compress' */

    /* S-Function Block: RGBD_Imaging/findStopSignDistance/Depth Image (m)/Image Compress (image_compress_block) */
    {
      t_error result = 0;
      size_t image_size = 0;
      result = qjpeg_compress_start(RGBD_Imaging_DW.ImageCompress_Compress_g,
        true);
      if (result == 0) {
        result = qjpeg_compress_write_image_single
          (RGBD_Imaging_DW.ImageCompress_Compress_g, &RGBD_Imaging_B.Depth_o1[0]);
        qjpeg_compress_stop(RGBD_Imaging_DW.ImageCompress_Compress_g);

        /* Get the final size of the compressed image */
        if (result >= 0) {
          result = qjpeg_compress_get_fixed_memory_destination_size
            (RGBD_Imaging_DW.ImageCompress_Compress_g, &image_size);
        }
      }

      /* Set the dimensions of the output signal based on the size of the compressed image */
      RGBD_Imaging_DW.ImageCompress_DIMS1_e = (int) image_size;
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      }
    }

    /* S-Function (channel_block): '<S7>/Channel' */

    /* S-Function Block: RGBD_Imaging/findStopSignDistance/Depth Image (m)/Channel (channel_block) */
    {
      struct channel_info {
        t_channel_header header;
      } info;

      size_t width = 1;
      RGBD_Imaging_B.Channel_a = CHANNEL_0;
      info.header.data_type_id = 3;
      info.header.channel = 0;
      info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
      info.header.num_dimensions = 1;
      width *= RGBD_Imaging_DW.ImageCompress_DIMS1_e;
      info.header.dimension[0] = RGBD_Imaging_DW.ImageCompress_DIMS1_e;
      channel_fifo_add((t_channel_fifo) RGBD_Imaging_DW.Channel_PWORK_f.Fifo,
                       &info.header, &RGBD_Imaging_B.ImageCompress_c[0], width *
                       sizeof(uint8_T));
    }

    /* Gain: '<S4>/Adjust for V-FOV' */
    rtb_Gain = RGBD_Imaging_P.AdjustforVFOV_Gain * RGBD_Imaging_B.Subtract[0];

    /* Gain: '<S4>/Adjust for H-FOV' */
    rtb_Add1 = RGBD_Imaging_P.AdjustforHFOV_Gain * RGBD_Imaging_B.Subtract[1];

    /* Selector: '<S4>/Selector' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     *  Sum: '<S4>/Add'
     *  Sum: '<S4>/Add1'
     */
    rtb_Gain = floor(RGBD_Imaging_P.Constant_Value + rtb_Gain);
    if (rtIsNaN(rtb_Gain) || rtIsInf(rtb_Gain)) {
      rtb_Gain = 0.0;
    } else {
      rtb_Gain = fmod(rtb_Gain, 65536.0);
    }

    rtb_Add1 = floor(rtb_Add1 + RGBD_Imaging_P.Constant1_Value);
    if (rtIsNaN(rtb_Add1) || rtIsInf(rtb_Add1)) {
      rtb_Add1 = 0.0;
    } else {
      rtb_Add1 = fmod(rtb_Add1, 65536.0);
    }

    /* Selector: '<S4>/Selector' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     *  S-Function (video3d_capture_block): '<S3>/Depth'
     */
    RGBD_Imaging_B.Selector = RGBD_Imaging_B.Depth_o1[(((rtb_Add1 < 0.0 ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Add1 : (int32_T)(int16_T)
      (uint16_T)rtb_Add1) - 1) * 720 + (rtb_Gain < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Gain : (int32_T)(int16_T)(uint16_T)rtb_Gain)) - 1];
    srUpdateBC(RGBD_Imaging_DW.findStopSignDistance_SubsysRanB);
  }

  /* End of Logic: '<Root>/Logical Operator' */
  /* End of Outputs for SubSystem: '<Root>/findStopSignDistance' */

  /* S-Function (sample_time_block): '<S6>/Sample Time' */

  /* S-Function Block: RGBD_Imaging/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &RGBD_Imaging_DW.SampleTime_PreviousTime);
      RGBD_Imaging_B.actualsampletime = time_difference.seconds +
        time_difference.nanoseconds * 1e-9;
      memcpy(&RGBD_Imaging_DW.SampleTime_PreviousTime, &current_time, sizeof
             (t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      return;
    }
  }

  /* Constant: '<S6>/Constant' */
  RGBD_Imaging_B.reference = RGBD_Imaging_P.Constant_Value_e;

  /* S-Function (computation_time_block): '<S6>/Computation Time' */

  /* S-Function Block: RGBD_Imaging/monitorTiming /Computation Time (computation_time_block) */
  {
    RGBD_Imaging_B.computationtime =
      RGBD_Imaging_DW.ComputationTime_ComputationTime.seconds +
      RGBD_Imaging_DW.ComputationTime_ComputationTime.nanoseconds * 1e-9;
  }
}

/* Model update function */
void RGBD_Imaging_update(void)
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
  if (!(++RGBD_Imaging_M->Timing.clockTick0)) {
    ++RGBD_Imaging_M->Timing.clockTickH0;
  }

  RGBD_Imaging_M->Timing.t[0] = RGBD_Imaging_M->Timing.clockTick0 *
    RGBD_Imaging_M->Timing.stepSize0 + RGBD_Imaging_M->Timing.clockTickH0 *
    RGBD_Imaging_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void RGBD_Imaging_initialize(void)
{
  /* Start for S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: RGBD_Imaging/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0", &RGBD_Imaging_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_capture_block): '<S3>/Depth' */
  {
    t_error result;
    result = video3d_stream_open(RGBD_Imaging_DW.Video3DInitialize_Video3D,
      VIDEO3D_STREAM_DEPTH, RGBD_Imaging_P.Depth_stream_index, 30.0, 1280, 720,
      IMAGE_FORMAT_COL_MAJOR_GRAYSCALE, IMAGE_DATA_TYPE_SINGLE,
      &RGBD_Imaging_DW.Depth_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (RGBD_Imaging_P.Depth_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (RGBD_Imaging_P.Depth_Preset - 1);
        num_config_properties++;
      }

      if (RGBD_Imaging_P.Depth_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] = (RGBD_Imaging_P.Depth_Emitter ==
          1) ? 1.0 : 0.0;
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
        video3d_stream_set_properties(RGBD_Imaging_DW.Depth_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video3d_capture_block): '<S3>/RGB' */
  {
    t_error result;
    result = video3d_stream_open(RGBD_Imaging_DW.Video3DInitialize_Video3D,
      VIDEO3D_STREAM_COLOR, RGBD_Imaging_P.RGB_stream_index, 30.0, 1280, 720,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &RGBD_Imaging_DW.RGB_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (RGBD_Imaging_P.RGB_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (RGBD_Imaging_P.RGB_Preset - 1);
        num_config_properties++;
      }

      if (RGBD_Imaging_P.RGB_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] = (RGBD_Imaging_P.RGB_Emitter == 1)
          ? 1.0 : 0.0;
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
        video3d_stream_set_properties(RGBD_Imaging_DW.RGB_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<Root>/findStopSignLocation' */

  /* Start for S-Function (image_transform_block): '<S11>/Image Transform' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    t_error result;
    result = image_rgb_to_hsv_open(&RGBD_Imaging_DW.ImageTransform_AlgHandle);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S8>/Image Compress' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Binary showing blob found/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open(&RGBD_Imaging_DW.ImageCompress_Compress);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (RGBD_Imaging_DW.ImageCompress_Compress, 1280, 720,
           COLOR_SPACE_GRAYSCALE, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (RGBD_Imaging_DW.ImageCompress_Compress,
           RGBD_Imaging_P.ImageCompress_Quality_o);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (RGBD_Imaging_DW.ImageCompress_Compress,
           &RGBD_Imaging_B.ImageCompress[0], 921600);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(RGBD_Imaging_DW.ImageCompress_Compress);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S8>/Channel' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Binary showing blob found/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(1, sizeof(uint8_T), 1, 921600, 1,
      (t_channel_fifo *) &RGBD_Imaging_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S10>/Image Compress' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Raw RGB/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&RGBD_Imaging_DW.ImageCompress_Compress_c);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (RGBD_Imaging_DW.ImageCompress_Compress_c, 1280, 720, COLOR_SPACE_RGB,
           IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (RGBD_Imaging_DW.ImageCompress_Compress_c,
           RGBD_Imaging_P.ImageCompress_Quality_f);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (RGBD_Imaging_DW.ImageCompress_Compress_c,
           &RGBD_Imaging_B.ImageCompress_g[0], 2764800);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(RGBD_Imaging_DW.ImageCompress_Compress_c);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S10>/Channel' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Raw RGB/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(2, sizeof(uint8_T), 1, 2764800, 1,
      (t_channel_fifo *) &RGBD_Imaging_DW.Channel_PWORK_d.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_find_objects_block): '<S5>/Image Find Objects' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Image Find Objects (image_find_objects_block) */
  {
    t_error result;
    result = image_find_blobs_initialize(1280, 720,
      &RGBD_Imaging_DW.ImageFindObjects_FindHandle);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/findStopSignLocation' */

  /* Start for Enabled SubSystem: '<Root>/findStopSignDistance' */

  /* Start for S-Function (image_compress_block): '<S7>/Image Compress' */

  /* S-Function Block: RGBD_Imaging/findStopSignDistance/Depth Image (m)/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&RGBD_Imaging_DW.ImageCompress_Compress_g);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (RGBD_Imaging_DW.ImageCompress_Compress_g, 1280, 720,
           COLOR_SPACE_GRAYSCALE, IMAGE_DATA_TYPE_SINGLE);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (RGBD_Imaging_DW.ImageCompress_Compress_g,
           RGBD_Imaging_P.ImageCompress_Quality);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (RGBD_Imaging_DW.ImageCompress_Compress_g,
           &RGBD_Imaging_B.ImageCompress_c[0], 921600);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(RGBD_Imaging_DW.ImageCompress_Compress_g);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S7>/Channel' */

  /* S-Function Block: RGBD_Imaging/findStopSignDistance/Depth Image (m)/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 1, 921600, 1,
      (t_channel_fifo *) &RGBD_Imaging_DW.Channel_PWORK_f.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/findStopSignDistance' */

  /* Start for S-Function (sample_time_block): '<S6>/Sample Time' */

  /* S-Function Block: RGBD_Imaging/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&RGBD_Imaging_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
      return;
    }
  }

  /* InitializeConditions for S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: RGBD_Imaging/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    if (rtmIsFirstInitCond(RGBD_Imaging_M)) {
      t_error result = video3d_start_streaming
        (RGBD_Imaging_DW.Video3DInitialize_Video3D);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RGBD_Imaging_M, _rt_error_message);
        return;
      }
    }
  }

  /* SystemInitialize for Enabled SubSystem: '<Root>/findStopSignLocation' */
  /* SystemInitialize for RelationalOperator: '<S9>/Compare' incorporates:
   *  Outport: '<S5>/blobFound?'
   */
  RGBD_Imaging_B.Compare = RGBD_Imaging_P.blobFound_Y0;

  /* SystemInitialize for Sum: '<S5>/Subtract' incorporates:
   *  Outport: '<S5>/blobLocation (px) [2]'
   */
  RGBD_Imaging_B.Subtract[0] = RGBD_Imaging_P.blobLocationpx2_Y0;
  RGBD_Imaging_B.Subtract[1] = RGBD_Imaging_P.blobLocationpx2_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/findStopSignLocation' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/findStopSignDistance' */
  /* SystemInitialize for Selector: '<S4>/Selector' incorporates:
   *  Outport: '<S4>/distanceToSign (m)'
   */
  RGBD_Imaging_B.Selector = RGBD_Imaging_P.distanceToSignm_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/findStopSignDistance' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(RGBD_Imaging_M)) {
    rtmSetFirstInitCond(RGBD_Imaging_M, 0);
  }
}

/* Model terminate function */
void RGBD_Imaging_terminate(void)
{
  /* Terminate for S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: RGBD_Imaging/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming(RGBD_Imaging_DW.Video3DInitialize_Video3D);
    video3d_close(RGBD_Imaging_DW.Video3DInitialize_Video3D);
  }

  /* Terminate for Enabled SubSystem: '<Root>/findStopSignLocation' */

  /* Terminate for S-Function (image_transform_block): '<S11>/Image Transform' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/colorThresholdingHSV/Image Transform (image_transform_block) */
  {
    image_rgb_to_hsv_close(RGBD_Imaging_DW.ImageTransform_AlgHandle);
  }

  /* Terminate for S-Function (image_compress_block): '<S8>/Image Compress' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Binary showing blob found/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(RGBD_Imaging_DW.ImageCompress_Compress);
    RGBD_Imaging_DW.ImageCompress_Compress = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S8>/Channel' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Binary showing blob found/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo) RGBD_Imaging_DW.Channel_PWORK.Fifo);
    RGBD_Imaging_DW.Channel_PWORK.Fifo = NULL;
  }

  /* Terminate for S-Function (image_compress_block): '<S10>/Image Compress' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Raw RGB/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(RGBD_Imaging_DW.ImageCompress_Compress_c);
    RGBD_Imaging_DW.ImageCompress_Compress_c = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S10>/Channel' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Raw RGB/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo) RGBD_Imaging_DW.Channel_PWORK_d.Fifo);
    RGBD_Imaging_DW.Channel_PWORK_d.Fifo = NULL;
  }

  /* Terminate for S-Function (image_find_objects_block): '<S5>/Image Find Objects' */

  /* S-Function Block: RGBD_Imaging/findStopSignLocation/Image Find Objects (image_find_objects_block) */
  {
    image_find_blobs_destroy(RGBD_Imaging_DW.ImageFindObjects_FindHandle);
  }

  /* End of Terminate for SubSystem: '<Root>/findStopSignLocation' */

  /* Terminate for Enabled SubSystem: '<Root>/findStopSignDistance' */

  /* Terminate for S-Function (image_compress_block): '<S7>/Image Compress' */

  /* S-Function Block: RGBD_Imaging/findStopSignDistance/Depth Image (m)/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(RGBD_Imaging_DW.ImageCompress_Compress_g);
    RGBD_Imaging_DW.ImageCompress_Compress_g = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S7>/Channel' */

  /* S-Function Block: RGBD_Imaging/findStopSignDistance/Depth Image (m)/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo) RGBD_Imaging_DW.Channel_PWORK_f.Fifo);
    RGBD_Imaging_DW.Channel_PWORK_f.Fifo = NULL;
  }

  /* End of Terminate for SubSystem: '<Root>/findStopSignDistance' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  RGBD_Imaging_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  RGBD_Imaging_update();
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
  RGBD_Imaging_initialize();
}

void MdlTerminate(void)
{
  RGBD_Imaging_terminate();
}

/* Registration function */
RT_MODEL_RGBD_Imaging_T *RGBD_Imaging(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RGBD_Imaging_M, 0,
                sizeof(RT_MODEL_RGBD_Imaging_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RGBD_Imaging_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    RGBD_Imaging_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RGBD_Imaging_M->Timing.sampleTimes =
      (&RGBD_Imaging_M->Timing.sampleTimesArray[0]);
    RGBD_Imaging_M->Timing.offsetTimes =
      (&RGBD_Imaging_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RGBD_Imaging_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    RGBD_Imaging_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(RGBD_Imaging_M, &RGBD_Imaging_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RGBD_Imaging_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    RGBD_Imaging_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RGBD_Imaging_M, -1);
  RGBD_Imaging_M->Timing.stepSize0 = 0.033333333333333333;
  rtmSetFirstInitCond(RGBD_Imaging_M, 1);

  /* External mode info */
  RGBD_Imaging_M->Sizes.checksums[0] = (3903265909U);
  RGBD_Imaging_M->Sizes.checksums[1] = (2706597267U);
  RGBD_Imaging_M->Sizes.checksums[2] = (2443891547U);
  RGBD_Imaging_M->Sizes.checksums[3] = (2018625468U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    RGBD_Imaging_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &RGBD_Imaging_DW.findStopSignDistance_SubsysRanB;
    systemRan[2] = (sysRanDType *)
      &RGBD_Imaging_DW.findStopSignLocation_SubsysRanB;
    systemRan[3] = (sysRanDType *)
      &RGBD_Imaging_DW.findStopSignLocation_SubsysRanB;
    systemRan[4] = (sysRanDType *)
      &RGBD_Imaging_DW.findStopSignLocation_SubsysRanB;
    systemRan[5] = (sysRanDType *)
      &RGBD_Imaging_DW.findStopSignLocation_SubsysRanB;
    systemRan[6] = (sysRanDType *)
      &RGBD_Imaging_DW.findStopSignLocation_SubsysRanB;
    rteiSetModelMappingInfoPtr(RGBD_Imaging_M->extModeInfo,
      &RGBD_Imaging_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RGBD_Imaging_M->extModeInfo,
                        RGBD_Imaging_M->Sizes.checksums);
    rteiSetTPtr(RGBD_Imaging_M->extModeInfo, rtmGetTPtr(RGBD_Imaging_M));
  }

  RGBD_Imaging_M->solverInfoPtr = (&RGBD_Imaging_M->solverInfo);
  RGBD_Imaging_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&RGBD_Imaging_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&RGBD_Imaging_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  RGBD_Imaging_M->blockIO = ((void *) &RGBD_Imaging_B);
  (void) memset(((void *) &RGBD_Imaging_B), 0,
                sizeof(B_RGBD_Imaging_T));

  {
    RGBD_Imaging_B.Channel = CHANNEL_0;
    RGBD_Imaging_B.Channel_o = CHANNEL_0;
    RGBD_Imaging_B.Channel_a = CHANNEL_0;
  }

  /* parameters */
  RGBD_Imaging_M->defaultParam = ((real_T *)&RGBD_Imaging_P);

  /* states (dwork) */
  RGBD_Imaging_M->dwork = ((void *) &RGBD_Imaging_DW);
  (void) memset((void *)&RGBD_Imaging_DW, 0,
                sizeof(DW_RGBD_Imaging_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RGBD_Imaging_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 24;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  RGBD_Imaging_M->Sizes.numContStates = (0);/* Number of continuous states */
  RGBD_Imaging_M->Sizes.numY = (0);    /* Number of model outputs */
  RGBD_Imaging_M->Sizes.numU = (0);    /* Number of model inputs */
  RGBD_Imaging_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  RGBD_Imaging_M->Sizes.numSampTimes = (1);/* Number of sample times */
  RGBD_Imaging_M->Sizes.numBlocks = (54);/* Number of blocks */
  RGBD_Imaging_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  RGBD_Imaging_M->Sizes.numBlockPrms = (84);/* Sum of parameter "widths" */
  return RGBD_Imaging_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
