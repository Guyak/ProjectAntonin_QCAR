/*
 * Intel_Realsense.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Intel_Realsense".
 *
 * Model version              : 1.84
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 28 09:09:53 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Intel_Realsense.h"
#include "Intel_Realsense_private.h"
#include "Intel_Realsense_dt.h"

/* Block signals (default storage) */
B_Intel_Realsense_T Intel_Realsense_B;

/* Block states (default storage) */
DW_Intel_Realsense_T Intel_Realsense_DW;

/* Real-time model */
static RT_MODEL_Intel_Realsense_T Intel_Realsense_M_;
RT_MODEL_Intel_Realsense_T *const Intel_Realsense_M = &Intel_Realsense_M_;

/* Model output function */
void Intel_Realsense_output(void)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(Intel_Realsense_DW.depthDisplay_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Intel_Realsense_DW.enabledDisplay_SubsysRanBC);

  /* S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: Intel_Realsense/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
  }

  /* S-Function (video3d_capture_block): '<S3>/Depth' */
  /* S-Function Block: Intel_Realsense/captureRGBD/Depth (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame(Intel_Realsense_DW.Depth_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_meters(frame, &Intel_Realsense_B.Depth_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    Intel_Realsense_B.Depth_o4 = (result >= 0);
    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* S-Function (video3d_capture_block): '<S3>/RGB' */
  /* S-Function Block: Intel_Realsense/captureRGBD/RGB (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame(Intel_Realsense_DW.RGB_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_data(frame, &Intel_Realsense_B.RGB_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    Intel_Realsense_B.RGB_o4 = (result >= 0);
    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* Outputs for Enabled SubSystem: '<Root>/depthDisplay' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (Intel_Realsense_B.Depth_o4) {
    /* S-Function (image_transform_block): '<S4>/Image Transform' */

    /* S-Function Block: Intel_Realsense/depthDisplay/Image Transform (image_transform_block) */
    {
      t_error result;
      result = image_grayscale_to_colorized_rgb_single
        (&Intel_Realsense_B.Depth_o1[0], 1280, 720,
         Intel_Realsense_P.ImageTransform_min_pixel,
         Intel_Realsense_P.ImageTransform_max_pixel,
         Intel_Realsense_DW.ImageTransform_AlgHandle,
         &Intel_Realsense_B.ImageTransform[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
      }
    }

    /* S-Function (image_compress_block): '<S6>/Image Compress' */

    /* S-Function Block: Intel_Realsense/depthDisplay/Video Compressed Display/Image Compress (image_compress_block) */
    {
      t_error result = 0;
      size_t image_size = 0;
      result = qjpeg_compress_start(Intel_Realsense_DW.ImageCompress_Compress_m,
        true);
      if (result == 0) {
        result = qjpeg_compress_write_image_uint8
          (Intel_Realsense_DW.ImageCompress_Compress_m,
           &Intel_Realsense_B.ImageTransform[0]);
        qjpeg_compress_stop(Intel_Realsense_DW.ImageCompress_Compress_m);

        /* Get the final size of the compressed image */
        if (result >= 0) {
          result = qjpeg_compress_get_fixed_memory_destination_size
            (Intel_Realsense_DW.ImageCompress_Compress_m, &image_size);
        }
      }

      /* Set the dimensions of the output signal based on the size of the compressed image */
      Intel_Realsense_DW.ImageCompress_DIMS1_o = (int) image_size;
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
      }
    }

    /* S-Function (channel_block): '<S6>/Channel' */

    /* S-Function Block: Intel_Realsense/depthDisplay/Video Compressed Display/Channel (channel_block) */
    {
      struct channel_info {
        t_channel_header header;
      } info;

      size_t width = 1;
      Intel_Realsense_B.Channel_f = CHANNEL_0;
      info.header.data_type_id = 3;
      info.header.channel = 0;
      info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
      info.header.num_dimensions = 1;
      width *= Intel_Realsense_DW.ImageCompress_DIMS1_o;
      info.header.dimension[0] = Intel_Realsense_DW.ImageCompress_DIMS1_o;
      channel_fifo_add((t_channel_fifo) Intel_Realsense_DW.Channel_PWORK_p.Fifo,
                       &info.header, &Intel_Realsense_B.ImageCompress_i[0],
                       width * sizeof(uint8_T));
    }

    srUpdateBC(Intel_Realsense_DW.depthDisplay_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/depthDisplay' */

  /* Outputs for Enabled SubSystem: '<Root>/enabledDisplay' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (Intel_Realsense_B.RGB_o4) {
    /* S-Function (image_compress_block): '<S7>/Image Compress' */

    /* S-Function Block: Intel_Realsense/enabledDisplay/Video Compressed Display/Image Compress (image_compress_block) */
    {
      t_error result = 0;
      size_t image_size = 0;
      result = qjpeg_compress_start(Intel_Realsense_DW.ImageCompress_Compress,
        true);
      if (result == 0) {
        result = qjpeg_compress_write_image_uint8
          (Intel_Realsense_DW.ImageCompress_Compress, &Intel_Realsense_B.RGB_o1
           [0]);
        qjpeg_compress_stop(Intel_Realsense_DW.ImageCompress_Compress);

        /* Get the final size of the compressed image */
        if (result >= 0) {
          result = qjpeg_compress_get_fixed_memory_destination_size
            (Intel_Realsense_DW.ImageCompress_Compress, &image_size);
        }
      }

      /* Set the dimensions of the output signal based on the size of the compressed image */
      Intel_Realsense_DW.ImageCompress_DIMS1 = (int) image_size;
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
      }
    }

    /* S-Function (channel_block): '<S7>/Channel' */

    /* S-Function Block: Intel_Realsense/enabledDisplay/Video Compressed Display/Channel (channel_block) */
    {
      struct channel_info {
        t_channel_header header;
      } info;

      size_t width = 1;
      Intel_Realsense_B.Channel = CHANNEL_1;
      info.header.data_type_id = 3;
      info.header.channel = 1;
      info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
      info.header.num_dimensions = 1;
      width *= Intel_Realsense_DW.ImageCompress_DIMS1;
      info.header.dimension[0] = Intel_Realsense_DW.ImageCompress_DIMS1;
      channel_fifo_add((t_channel_fifo) Intel_Realsense_DW.Channel_PWORK.Fifo,
                       &info.header, &Intel_Realsense_B.ImageCompress[0], width *
                       sizeof(uint8_T));
    }

    srUpdateBC(Intel_Realsense_DW.enabledDisplay_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/enabledDisplay' */
}

/* Model update function */
void Intel_Realsense_update(void)
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
  if (!(++Intel_Realsense_M->Timing.clockTick0)) {
    ++Intel_Realsense_M->Timing.clockTickH0;
  }

  Intel_Realsense_M->Timing.t[0] = Intel_Realsense_M->Timing.clockTick0 *
    Intel_Realsense_M->Timing.stepSize0 + Intel_Realsense_M->Timing.clockTickH0 *
    Intel_Realsense_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Intel_Realsense_initialize(void)
{
  /* Start for S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: Intel_Realsense/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0", &Intel_Realsense_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_capture_block): '<S3>/Depth' */
  {
    t_error result;
    result = video3d_stream_open(Intel_Realsense_DW.Video3DInitialize_Video3D,
      VIDEO3D_STREAM_DEPTH, Intel_Realsense_P.Depth_stream_index, 30.0, 1280,
      720,
      IMAGE_FORMAT_COL_MAJOR_GRAYSCALE, IMAGE_DATA_TYPE_SINGLE,
      &Intel_Realsense_DW.Depth_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (Intel_Realsense_P.Depth_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (Intel_Realsense_P.Depth_Preset - 1);
        num_config_properties++;
      }

      if (Intel_Realsense_P.Depth_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] = (Intel_Realsense_P.Depth_Emitter ==
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
        video3d_stream_set_properties(Intel_Realsense_DW.Depth_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video3d_capture_block): '<S3>/RGB' */
  {
    t_error result;
    result = video3d_stream_open(Intel_Realsense_DW.Video3DInitialize_Video3D,
      VIDEO3D_STREAM_COLOR, Intel_Realsense_P.RGB_stream_index, 30.0, 1280, 720,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &Intel_Realsense_DW.RGB_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (Intel_Realsense_P.RGB_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (Intel_Realsense_P.RGB_Preset - 1);
        num_config_properties++;
      }

      if (Intel_Realsense_P.RGB_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] = (Intel_Realsense_P.RGB_Emitter ==
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
        video3d_stream_set_properties(Intel_Realsense_DW.RGB_Stream,
          config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<Root>/depthDisplay' */

  /* Start for S-Function (image_transform_block): '<S4>/Image Transform' */

  /* S-Function Block: Intel_Realsense/depthDisplay/Image Transform (image_transform_block) */
  {
    t_error result;
    result = image_colorization_open((t_colorization_theme)
      (Intel_Realsense_P.ImageTransform_ColorTheme - 1),
      &Intel_Realsense_DW.ImageTransform_AlgHandle);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S6>/Image Compress' */

  /* S-Function Block: Intel_Realsense/depthDisplay/Video Compressed Display/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Intel_Realsense_DW.ImageCompress_Compress_m);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Intel_Realsense_DW.ImageCompress_Compress_m, 1280, 720,
           COLOR_SPACE_RGB, IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Intel_Realsense_DW.ImageCompress_Compress_m,
           Intel_Realsense_P.ImageCompress_Quality);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Intel_Realsense_DW.ImageCompress_Compress_m,
           &Intel_Realsense_B.ImageCompress_i[0], 2764800);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Intel_Realsense_DW.ImageCompress_Compress_m);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S6>/Channel' */

  /* S-Function Block: Intel_Realsense/depthDisplay/Video Compressed Display/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 1, 2764800, 1,
      (t_channel_fifo *) &Intel_Realsense_DW.Channel_PWORK_p.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/depthDisplay' */

  /* Start for Enabled SubSystem: '<Root>/enabledDisplay' */

  /* Start for S-Function (image_compress_block): '<S7>/Image Compress' */

  /* S-Function Block: Intel_Realsense/enabledDisplay/Video Compressed Display/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&Intel_Realsense_DW.ImageCompress_Compress);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (Intel_Realsense_DW.ImageCompress_Compress, 1280, 720, COLOR_SPACE_RGB,
           IMAGE_DATA_TYPE_UINT8);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (Intel_Realsense_DW.ImageCompress_Compress,
           Intel_Realsense_P.ImageCompress_Quality_n);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (Intel_Realsense_DW.ImageCompress_Compress,
           &Intel_Realsense_B.ImageCompress[0], 2764800);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close(Intel_Realsense_DW.ImageCompress_Compress);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S7>/Channel' */

  /* S-Function Block: Intel_Realsense/enabledDisplay/Video Compressed Display/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(1, sizeof(uint8_T), 1, 2764800, 1,
      (t_channel_fifo *) &Intel_Realsense_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/enabledDisplay' */

  /* InitializeConditions for S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: Intel_Realsense/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    if (rtmIsFirstInitCond(Intel_Realsense_M)) {
      t_error result = video3d_start_streaming
        (Intel_Realsense_DW.Video3DInitialize_Video3D);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Intel_Realsense_M, _rt_error_message);
        return;
      }
    }
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Intel_Realsense_M)) {
    rtmSetFirstInitCond(Intel_Realsense_M, 0);
  }
}

/* Model terminate function */
void Intel_Realsense_terminate(void)
{
  /* Terminate for S-Function (video3d_initialize_block): '<S3>/Video3D Initialize' */

  /* S-Function Block: Intel_Realsense/captureRGBD/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming(Intel_Realsense_DW.Video3DInitialize_Video3D);
    video3d_close(Intel_Realsense_DW.Video3DInitialize_Video3D);
  }

  /* Terminate for Enabled SubSystem: '<Root>/depthDisplay' */

  /* Terminate for S-Function (image_transform_block): '<S4>/Image Transform' */

  /* S-Function Block: Intel_Realsense/depthDisplay/Image Transform (image_transform_block) */
  {
    image_colorization_close(Intel_Realsense_DW.ImageTransform_AlgHandle);
  }

  /* Terminate for S-Function (image_compress_block): '<S6>/Image Compress' */

  /* S-Function Block: Intel_Realsense/depthDisplay/Video Compressed Display/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Intel_Realsense_DW.ImageCompress_Compress_m);
    Intel_Realsense_DW.ImageCompress_Compress_m = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S6>/Channel' */

  /* S-Function Block: Intel_Realsense/depthDisplay/Video Compressed Display/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         Intel_Realsense_DW.Channel_PWORK_p.Fifo);
    Intel_Realsense_DW.Channel_PWORK_p.Fifo = NULL;
  }

  /* End of Terminate for SubSystem: '<Root>/depthDisplay' */

  /* Terminate for Enabled SubSystem: '<Root>/enabledDisplay' */

  /* Terminate for S-Function (image_compress_block): '<S7>/Image Compress' */

  /* S-Function Block: Intel_Realsense/enabledDisplay/Video Compressed Display/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(Intel_Realsense_DW.ImageCompress_Compress);
    Intel_Realsense_DW.ImageCompress_Compress = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S7>/Channel' */

  /* S-Function Block: Intel_Realsense/enabledDisplay/Video Compressed Display/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo) Intel_Realsense_DW.Channel_PWORK.Fifo);
    Intel_Realsense_DW.Channel_PWORK.Fifo = NULL;
  }

  /* End of Terminate for SubSystem: '<Root>/enabledDisplay' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Intel_Realsense_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Intel_Realsense_update();
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
  Intel_Realsense_initialize();
}

void MdlTerminate(void)
{
  Intel_Realsense_terminate();
}

/* Registration function */
RT_MODEL_Intel_Realsense_T *Intel_Realsense(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Intel_Realsense_M, 0,
                sizeof(RT_MODEL_Intel_Realsense_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Intel_Realsense_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Intel_Realsense_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Intel_Realsense_M->Timing.sampleTimes =
      (&Intel_Realsense_M->Timing.sampleTimesArray[0]);
    Intel_Realsense_M->Timing.offsetTimes =
      (&Intel_Realsense_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Intel_Realsense_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    Intel_Realsense_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Intel_Realsense_M, &Intel_Realsense_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Intel_Realsense_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Intel_Realsense_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Intel_Realsense_M, -1);
  Intel_Realsense_M->Timing.stepSize0 = 0.033333333333333333;
  rtmSetFirstInitCond(Intel_Realsense_M, 1);

  /* External mode info */
  Intel_Realsense_M->Sizes.checksums[0] = (2994739375U);
  Intel_Realsense_M->Sizes.checksums[1] = (2732139752U);
  Intel_Realsense_M->Sizes.checksums[2] = (1764617436U);
  Intel_Realsense_M->Sizes.checksums[3] = (797140321U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Intel_Realsense_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Intel_Realsense_DW.depthDisplay_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Intel_Realsense_DW.enabledDisplay_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Intel_Realsense_M->extModeInfo,
      &Intel_Realsense_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Intel_Realsense_M->extModeInfo,
                        Intel_Realsense_M->Sizes.checksums);
    rteiSetTPtr(Intel_Realsense_M->extModeInfo, rtmGetTPtr(Intel_Realsense_M));
  }

  Intel_Realsense_M->solverInfoPtr = (&Intel_Realsense_M->solverInfo);
  Intel_Realsense_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Intel_Realsense_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&Intel_Realsense_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Intel_Realsense_M->blockIO = ((void *) &Intel_Realsense_B);
  (void) memset(((void *) &Intel_Realsense_B), 0,
                sizeof(B_Intel_Realsense_T));

  {
    Intel_Realsense_B.Channel = CHANNEL_0;
    Intel_Realsense_B.Channel_f = CHANNEL_0;
  }

  /* parameters */
  Intel_Realsense_M->defaultParam = ((real_T *)&Intel_Realsense_P);

  /* states (dwork) */
  Intel_Realsense_M->dwork = ((void *) &Intel_Realsense_DW);
  (void) memset((void *)&Intel_Realsense_DW, 0,
                sizeof(DW_Intel_Realsense_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Intel_Realsense_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Intel_Realsense_M->Sizes.numContStates = (0);/* Number of continuous states */
  Intel_Realsense_M->Sizes.numY = (0); /* Number of model outputs */
  Intel_Realsense_M->Sizes.numU = (0); /* Number of model inputs */
  Intel_Realsense_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Intel_Realsense_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Intel_Realsense_M->Sizes.numBlocks = (12);/* Number of blocks */
  Intel_Realsense_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  Intel_Realsense_M->Sizes.numBlockPrms = (46);/* Sum of parameter "widths" */
  return Intel_Realsense_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
