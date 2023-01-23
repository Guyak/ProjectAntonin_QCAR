/*
 * Imaging_360.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Imaging_360".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Oct 17 11:00:17 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Imaging_360.h"
#include "Imaging_360_private.h"
#include "Imaging_360_dt.h"

/* Block signals (default storage) */
B_Imaging_360_T Imaging_360_B;

/* Block states (default storage) */
DW_Imaging_360_T Imaging_360_DW;

/* Real-time model */
static RT_MODEL_Imaging_360_T Imaging_360_M_;
RT_MODEL_Imaging_360_T *const Imaging_360_M = &Imaging_360_M_;

/* Model output function */
void Imaging_360_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_VideoCapture_o2;
  boolean_T rtb_VideoCapture1_o2;
  boolean_T rtb_VideoCapture2_o2;
  boolean_T rtb_VideoCapture3_o2;
  int32_T MatrixConcatenate_tmp;
  int32_T MatrixConcatenate_tmp_0;
  int32_T i;
  int32_T i_0;
  int32_T i_1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Imaging_360_DW.display_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Imaging_360_DW.stich_SubsysRanBC);

  /* S-Function (sample_time_block): '<S5>/Sample Time' */

  /* S-Function Block: Imaging_360/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &Imaging_360_DW.SampleTime_PreviousTime);
      Imaging_360_B.actualsampletime = time_difference.seconds +
        time_difference.nanoseconds * 1e-9;
      memcpy(&Imaging_360_DW.SampleTime_PreviousTime, &current_time, sizeof
             (t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
      return;
    }
  }

  /* Constant: '<S5>/Constant' */
  Imaging_360_B.reference = Imaging_360_P.Constant_Value;

  /* S-Function (computation_time_block): '<S5>/Computation Time' */

  /* S-Function Block: Imaging_360/monitorTiming /Computation Time (computation_time_block) */
  {
    Imaging_360_B.computationtime =
      Imaging_360_DW.ComputationTime_ComputationTime.seconds +
      Imaging_360_DW.ComputationTime_ComputationTime.nanoseconds * 1e-9;
  }

  /* S-Function (video_capture_block): '<S3>/Video Capture' */
  /* S-Function Block: Imaging_360/capture360/Video Capture (video_capture_block) */
  {
    t_error result;
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture_Brightness, VIDEO_CAPTURE_PROPERTY_BRIGHTNESS,
        (t_boolean) Imaging_360_P.VideoCapture_OvBrightness, false }
      , { Imaging_360_P.VideoCapture_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture_OvContrast, false }
      , { Imaging_360_P.VideoCapture_Hue, VIDEO_CAPTURE_PROPERTY_HUE, (t_boolean)
        Imaging_360_P.VideoCapture_OvHue, false }
      , { Imaging_360_P.VideoCapture_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture_OvSaturation, false }
      , { Imaging_360_P.VideoCapture_Sharpness, VIDEO_CAPTURE_PROPERTY_SHARPNESS,
        (t_boolean) Imaging_360_P.VideoCapture_OvSharpness, false }
      , { Imaging_360_P.VideoCapture_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture_OvGamma, false }
      , { Imaging_360_P.VideoCapture_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture_BacklightCompensat,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture_OvBacklightCompens, false }
      , { Imaging_360_P.VideoCapture_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture_OvGain, false }
      , { Imaging_360_P.VideoCapture_Pan, VIDEO_CAPTURE_PROPERTY_PAN, (t_boolean)
        Imaging_360_P.VideoCapture_OvPan, false }
      , { Imaging_360_P.VideoCapture_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture_OvTilt, false }
      , { Imaging_360_P.VideoCapture_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture_OvRoll, false }
      , { Imaging_360_P.VideoCapture_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture_OvZoom, false }
      , { Imaging_360_P.VideoCapture_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture_OvExposure, false }
      , { Imaging_360_P.VideoCapture_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture_OvIris, false }
      , { Imaging_360_P.VideoCapture_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture_OvFocus, false }
    };

    video_capture_set_property(Imaging_360_DW.VideoCapture_VideoCapture,
      local_attr, ARRAY_LENGTH(local_attr));
    result = video_capture_read(Imaging_360_DW.VideoCapture_VideoCapture,
      &Imaging_360_B.VideoCapture_o1[0]);
    rtb_VideoCapture_o2 = (result > 0);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* S-Function (video_capture_block): '<S3>/Video Capture1' */
  /* S-Function Block: Imaging_360/capture360/Video Capture1 (video_capture_block) */
  {
    t_error result;
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture1_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Imaging_360_P.VideoCapture1_OvBrightness, false }
      , { Imaging_360_P.VideoCapture1_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture1_OvContrast, false }
      , { Imaging_360_P.VideoCapture1_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Imaging_360_P.VideoCapture1_OvHue, false }
      , { Imaging_360_P.VideoCapture1_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture1_OvSaturation, false }
      , { Imaging_360_P.VideoCapture1_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Imaging_360_P.VideoCapture1_OvSharpness, false }
      , { Imaging_360_P.VideoCapture1_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture1_OvGamma, false }
      , { Imaging_360_P.VideoCapture1_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture1_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture1_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture1_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture1_BacklightCompensa,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture1_OvBacklightCompen, false }
      , { Imaging_360_P.VideoCapture1_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture1_OvGain, false }
      , { Imaging_360_P.VideoCapture1_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Imaging_360_P.VideoCapture1_OvPan, false }
      , { Imaging_360_P.VideoCapture1_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture1_OvTilt, false }
      , { Imaging_360_P.VideoCapture1_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture1_OvRoll, false }
      , { Imaging_360_P.VideoCapture1_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture1_OvZoom, false }
      , { Imaging_360_P.VideoCapture1_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture1_OvExposure, false }
      , { Imaging_360_P.VideoCapture1_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture1_OvIris, false }
      , { Imaging_360_P.VideoCapture1_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture1_OvFocus, false }
    };

    video_capture_set_property(Imaging_360_DW.VideoCapture1_VideoCapture,
      local_attr, ARRAY_LENGTH(local_attr));
    result = video_capture_read(Imaging_360_DW.VideoCapture1_VideoCapture,
      &Imaging_360_B.VideoCapture1_o1[0]);
    rtb_VideoCapture1_o2 = (result > 0);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* S-Function (video_capture_block): '<S3>/Video Capture2' */
  /* S-Function Block: Imaging_360/capture360/Video Capture2 (video_capture_block) */
  {
    t_error result;
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture2_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Imaging_360_P.VideoCapture2_OvBrightness, false }
      , { Imaging_360_P.VideoCapture2_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture2_OvContrast, false }
      , { Imaging_360_P.VideoCapture2_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Imaging_360_P.VideoCapture2_OvHue, false }
      , { Imaging_360_P.VideoCapture2_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture2_OvSaturation, false }
      , { Imaging_360_P.VideoCapture2_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Imaging_360_P.VideoCapture2_OvSharpness, false }
      , { Imaging_360_P.VideoCapture2_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture2_OvGamma, false }
      , { Imaging_360_P.VideoCapture2_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture2_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture2_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture2_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture2_BacklightCompensa,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture2_OvBacklightCompen, false }
      , { Imaging_360_P.VideoCapture2_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture2_OvGain, false }
      , { Imaging_360_P.VideoCapture2_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Imaging_360_P.VideoCapture2_OvPan, false }
      , { Imaging_360_P.VideoCapture2_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture2_OvTilt, false }
      , { Imaging_360_P.VideoCapture2_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture2_OvRoll, false }
      , { Imaging_360_P.VideoCapture2_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture2_OvZoom, false }
      , { Imaging_360_P.VideoCapture2_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture2_OvExposure, false }
      , { Imaging_360_P.VideoCapture2_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture2_OvIris, false }
      , { Imaging_360_P.VideoCapture2_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture2_OvFocus, false }
    };

    video_capture_set_property(Imaging_360_DW.VideoCapture2_VideoCapture,
      local_attr, ARRAY_LENGTH(local_attr));
    result = video_capture_read(Imaging_360_DW.VideoCapture2_VideoCapture,
      &Imaging_360_B.VideoCapture2_o1[0]);
    rtb_VideoCapture2_o2 = (result > 0);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* S-Function (video_capture_block): '<S3>/Video Capture3' */
  /* S-Function Block: Imaging_360/capture360/Video Capture3 (video_capture_block) */
  {
    t_error result;
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture3_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Imaging_360_P.VideoCapture3_OvBrightness, false }
      , { Imaging_360_P.VideoCapture3_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture3_OvContrast, false }
      , { Imaging_360_P.VideoCapture3_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Imaging_360_P.VideoCapture3_OvHue, false }
      , { Imaging_360_P.VideoCapture3_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture3_OvSaturation, false }
      , { Imaging_360_P.VideoCapture3_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Imaging_360_P.VideoCapture3_OvSharpness, false }
      , { Imaging_360_P.VideoCapture3_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture3_OvGamma, false }
      , { Imaging_360_P.VideoCapture3_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture3_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture3_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture3_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture3_BacklightCompensa,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture3_OvBacklightCompen, false }
      , { Imaging_360_P.VideoCapture3_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture3_OvGain, false }
      , { Imaging_360_P.VideoCapture3_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Imaging_360_P.VideoCapture3_OvPan, false }
      , { Imaging_360_P.VideoCapture3_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture3_OvTilt, false }
      , { Imaging_360_P.VideoCapture3_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture3_OvRoll, false }
      , { Imaging_360_P.VideoCapture3_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture3_OvZoom, false }
      , { Imaging_360_P.VideoCapture3_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture3_OvExposure, false }
      , { Imaging_360_P.VideoCapture3_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture3_OvIris, false }
      , { Imaging_360_P.VideoCapture3_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture3_OvFocus, false }
    };

    video_capture_set_property(Imaging_360_DW.VideoCapture3_VideoCapture,
      local_attr, ARRAY_LENGTH(local_attr));
    result = video_capture_read(Imaging_360_DW.VideoCapture3_VideoCapture,
      &Imaging_360_B.VideoCapture3_o1[0]);
    rtb_VideoCapture3_o2 = (result > 0);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* Outputs for Enabled SubSystem: '<Root>/display' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<Root>/stich' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* Logic: '<S3>/AND' */
  if (rtb_VideoCapture_o2 && rtb_VideoCapture1_o2 && rtb_VideoCapture2_o2 &&
      rtb_VideoCapture3_o2) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      for (i_0 = 0; i_0 < 640; i_0++) {
        for (i = 0; i < 480; i++) {
          /* Concatenate: '<S6>/Matrix Concatenate' */
          MatrixConcatenate_tmp = 480 * i_0 + i;
          MatrixConcatenate_tmp_0 = MatrixConcatenate_tmp + 307200 * i_1;

          /* Concatenate: '<S6>/Matrix Concatenate' incorporates:
           *  Inport: '<S6>/front'
           *  Inport: '<S6>/left'
           *  Inport: '<S6>/rear'
           *  Inport: '<S6>/right'
           *  S-Function (video_capture_block): '<S3>/Video Capture'
           *  S-Function (video_capture_block): '<S3>/Video Capture1'
           *  S-Function (video_capture_block): '<S3>/Video Capture2'
           *  S-Function (video_capture_block): '<S3>/Video Capture3'
           */
          Imaging_360_B.MatrixConcatenate[MatrixConcatenate_tmp + 1228800 * i_1]
            = Imaging_360_B.VideoCapture_o1[MatrixConcatenate_tmp_0];
          Imaging_360_B.MatrixConcatenate[(i + 480 * (i_0 + 640)) + 1228800 *
            i_1] = Imaging_360_B.VideoCapture1_o1[MatrixConcatenate_tmp_0];
          Imaging_360_B.MatrixConcatenate[(i + 480 * (i_0 + 1280)) + 1228800 *
            i_1] = Imaging_360_B.VideoCapture2_o1[MatrixConcatenate_tmp_0];
          Imaging_360_B.MatrixConcatenate[(i + 480 * (i_0 + 1920)) + 1228800 *
            i_1] = Imaging_360_B.VideoCapture3_o1[MatrixConcatenate_tmp_0];
        }
      }
    }

    srUpdateBC(Imaging_360_DW.stich_SubsysRanBC);

    /* S-Function (channel_block): '<S4>/Channel' */

    /* S-Function Block: Imaging_360/display/Channel (channel_block) */
    {
      struct channel_info {
        t_channel_header header;
        t_int extra_dimensions[2];
      } info;

      Imaging_360_B.Channel = CHANNEL_0;
      info.header.data_type_id = 3;
      info.header.channel = 0;
      info.header.flags = 0;
      info.header.num_dimensions = 3;
      info.header.dimension[0] = 480;
      info.header.dimension[1] = 2560;
      info.header.dimension[2] = 3;
      channel_fifo_add((t_channel_fifo) Imaging_360_DW.Channel_PWORK.Fifo,
                       &info.header, &Imaging_360_B.MatrixConcatenate[0],
                       3686400 * sizeof(uint8_T));
    }

    srUpdateBC(Imaging_360_DW.display_SubsysRanBC);
  }

  /* End of Logic: '<S3>/AND' */
  /* End of Outputs for SubSystem: '<Root>/stich' */
  /* End of Outputs for SubSystem: '<Root>/display' */
}

/* Model update function */
void Imaging_360_update(void)
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
  if (!(++Imaging_360_M->Timing.clockTick0)) {
    ++Imaging_360_M->Timing.clockTickH0;
  }

  Imaging_360_M->Timing.t[0] = Imaging_360_M->Timing.clockTick0 *
    Imaging_360_M->Timing.stepSize0 + Imaging_360_M->Timing.clockTickH0 *
    Imaging_360_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Imaging_360_initialize(void)
{
  /* Start for S-Function (sample_time_block): '<S5>/Sample Time' */

  /* S-Function Block: Imaging_360/monitorTiming /Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&Imaging_360_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video_capture_block): '<S3>/Video Capture' */
  {
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture_Brightness, VIDEO_CAPTURE_PROPERTY_BRIGHTNESS,
        (t_boolean) Imaging_360_P.VideoCapture_OvBrightness, false }
      , { Imaging_360_P.VideoCapture_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture_OvContrast, false }
      , { Imaging_360_P.VideoCapture_Hue, VIDEO_CAPTURE_PROPERTY_HUE, (t_boolean)
        Imaging_360_P.VideoCapture_OvHue, false }
      , { Imaging_360_P.VideoCapture_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture_OvSaturation, false }
      , { Imaging_360_P.VideoCapture_Sharpness, VIDEO_CAPTURE_PROPERTY_SHARPNESS,
        (t_boolean) Imaging_360_P.VideoCapture_OvSharpness, false }
      , { Imaging_360_P.VideoCapture_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture_OvGamma, false }
      , { Imaging_360_P.VideoCapture_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture_BacklightCompensat,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture_OvBacklightCompens, false }
      , { Imaging_360_P.VideoCapture_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture_OvGain, false }
      , { Imaging_360_P.VideoCapture_Pan, VIDEO_CAPTURE_PROPERTY_PAN, (t_boolean)
        Imaging_360_P.VideoCapture_OvPan, false }
      , { Imaging_360_P.VideoCapture_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture_OvTilt, false }
      , { Imaging_360_P.VideoCapture_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture_OvRoll, false }
      , { Imaging_360_P.VideoCapture_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture_OvZoom, false }
      , { Imaging_360_P.VideoCapture_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture_OvExposure, false }
      , { Imaging_360_P.VideoCapture_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture_OvIris, false }
      , { Imaging_360_P.VideoCapture_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture_OvFocus, false }
    };

    t_error result;

    /*printf("Opening camera video://localhost:0\n"); fflush(stdout);*/
    result = video_capture_open("video://localhost:0", 30.0, 640U, 480U,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &Imaging_360_DW.VideoCapture_VideoCapture, local_attr, ARRAY_LENGTH
      (local_attr));
    if (result >= 0) {
      result = video_capture_start(Imaging_360_DW.VideoCapture_VideoCapture);
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video_capture_block): '<S3>/Video Capture1' */
  {
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture1_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Imaging_360_P.VideoCapture1_OvBrightness, false }
      , { Imaging_360_P.VideoCapture1_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture1_OvContrast, false }
      , { Imaging_360_P.VideoCapture1_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Imaging_360_P.VideoCapture1_OvHue, false }
      , { Imaging_360_P.VideoCapture1_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture1_OvSaturation, false }
      , { Imaging_360_P.VideoCapture1_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Imaging_360_P.VideoCapture1_OvSharpness, false }
      , { Imaging_360_P.VideoCapture1_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture1_OvGamma, false }
      , { Imaging_360_P.VideoCapture1_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture1_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture1_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture1_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture1_BacklightCompensa,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture1_OvBacklightCompen, false }
      , { Imaging_360_P.VideoCapture1_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture1_OvGain, false }
      , { Imaging_360_P.VideoCapture1_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Imaging_360_P.VideoCapture1_OvPan, false }
      , { Imaging_360_P.VideoCapture1_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture1_OvTilt, false }
      , { Imaging_360_P.VideoCapture1_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture1_OvRoll, false }
      , { Imaging_360_P.VideoCapture1_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture1_OvZoom, false }
      , { Imaging_360_P.VideoCapture1_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture1_OvExposure, false }
      , { Imaging_360_P.VideoCapture1_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture1_OvIris, false }
      , { Imaging_360_P.VideoCapture1_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture1_OvFocus, false }
    };

    t_error result;

    /*printf("Opening camera video://localhost:1\n"); fflush(stdout);*/
    result = video_capture_open("video://localhost:1", 30.0, 640U, 480U,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &Imaging_360_DW.VideoCapture1_VideoCapture, local_attr, ARRAY_LENGTH
      (local_attr));
    if (result >= 0) {
      result = video_capture_start(Imaging_360_DW.VideoCapture1_VideoCapture);
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video_capture_block): '<S3>/Video Capture2' */
  {
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture2_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Imaging_360_P.VideoCapture2_OvBrightness, false }
      , { Imaging_360_P.VideoCapture2_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture2_OvContrast, false }
      , { Imaging_360_P.VideoCapture2_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Imaging_360_P.VideoCapture2_OvHue, false }
      , { Imaging_360_P.VideoCapture2_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture2_OvSaturation, false }
      , { Imaging_360_P.VideoCapture2_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Imaging_360_P.VideoCapture2_OvSharpness, false }
      , { Imaging_360_P.VideoCapture2_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture2_OvGamma, false }
      , { Imaging_360_P.VideoCapture2_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture2_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture2_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture2_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture2_BacklightCompensa,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture2_OvBacklightCompen, false }
      , { Imaging_360_P.VideoCapture2_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture2_OvGain, false }
      , { Imaging_360_P.VideoCapture2_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Imaging_360_P.VideoCapture2_OvPan, false }
      , { Imaging_360_P.VideoCapture2_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture2_OvTilt, false }
      , { Imaging_360_P.VideoCapture2_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture2_OvRoll, false }
      , { Imaging_360_P.VideoCapture2_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture2_OvZoom, false }
      , { Imaging_360_P.VideoCapture2_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture2_OvExposure, false }
      , { Imaging_360_P.VideoCapture2_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture2_OvIris, false }
      , { Imaging_360_P.VideoCapture2_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture2_OvFocus, false }
    };

    t_error result;

    /*printf("Opening camera video://localhost:2\n"); fflush(stdout);*/
    result = video_capture_open("video://localhost:2", 30.0, 640U, 480U,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &Imaging_360_DW.VideoCapture2_VideoCapture, local_attr, ARRAY_LENGTH
      (local_attr));
    if (result >= 0) {
      result = video_capture_start(Imaging_360_DW.VideoCapture2_VideoCapture);
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video_capture_block): '<S3>/Video Capture3' */
  {
    t_video_capture_attribute local_attr[17] = {
      { Imaging_360_P.VideoCapture3_Brightness,
        VIDEO_CAPTURE_PROPERTY_BRIGHTNESS, (t_boolean)
        Imaging_360_P.VideoCapture3_OvBrightness, false }
      , { Imaging_360_P.VideoCapture3_Contrast, VIDEO_CAPTURE_PROPERTY_CONTRAST,
        (t_boolean) Imaging_360_P.VideoCapture3_OvContrast, false }
      , { Imaging_360_P.VideoCapture3_Hue, VIDEO_CAPTURE_PROPERTY_HUE,
        (t_boolean) Imaging_360_P.VideoCapture3_OvHue, false }
      , { Imaging_360_P.VideoCapture3_Saturation,
        VIDEO_CAPTURE_PROPERTY_SATURATION, (t_boolean)
        Imaging_360_P.VideoCapture3_OvSaturation, false }
      , { Imaging_360_P.VideoCapture3_Sharpness,
        VIDEO_CAPTURE_PROPERTY_SHARPNESS, (t_boolean)
        Imaging_360_P.VideoCapture3_OvSharpness, false }
      , { Imaging_360_P.VideoCapture3_Gamma, VIDEO_CAPTURE_PROPERTY_GAMMA,
        (t_boolean) Imaging_360_P.VideoCapture3_OvGamma, false }
      , { Imaging_360_P.VideoCapture3_ColorEnable,
        VIDEO_CAPTURE_PROPERTY_COLOREFFECT, (t_boolean)
        Imaging_360_P.VideoCapture3_OvColorEnable, true }
      , { Imaging_360_P.VideoCapture3_WhiteBalance,
        VIDEO_CAPTURE_PROPERTY_WHITEBALANCE, (t_boolean)
        Imaging_360_P.VideoCapture3_OvWhiteBalance, false }
      , { Imaging_360_P.VideoCapture3_BacklightCompensa,
        VIDEO_CAPTURE_PROPERTY_BACKLIGHTCOMPENSATION, (t_boolean)
        Imaging_360_P.VideoCapture3_OvBacklightCompen, false }
      , { Imaging_360_P.VideoCapture3_Gain, VIDEO_CAPTURE_PROPERTY_GAIN,
        (t_boolean) Imaging_360_P.VideoCapture3_OvGain, false }
      , { Imaging_360_P.VideoCapture3_Pan, VIDEO_CAPTURE_PROPERTY_PAN,
        (t_boolean) Imaging_360_P.VideoCapture3_OvPan, false }
      , { Imaging_360_P.VideoCapture3_Tilt, VIDEO_CAPTURE_PROPERTY_TILT,
        (t_boolean) Imaging_360_P.VideoCapture3_OvTilt, false }
      , { Imaging_360_P.VideoCapture3_Roll, VIDEO_CAPTURE_PROPERTY_ROLL,
        (t_boolean) Imaging_360_P.VideoCapture3_OvRoll, false }
      , { Imaging_360_P.VideoCapture3_Zoom, VIDEO_CAPTURE_PROPERTY_ZOOM,
        (t_boolean) Imaging_360_P.VideoCapture3_OvZoom, false }
      , { Imaging_360_P.VideoCapture3_Exposure, VIDEO_CAPTURE_PROPERTY_EXPOSURE,
        (t_boolean) Imaging_360_P.VideoCapture3_OvExposure, false }
      , { Imaging_360_P.VideoCapture3_Iris, VIDEO_CAPTURE_PROPERTY_IRIS,
        (t_boolean) Imaging_360_P.VideoCapture3_OvIris, false }
      , { Imaging_360_P.VideoCapture3_Focus, VIDEO_CAPTURE_PROPERTY_FOCUS,
        (t_boolean) Imaging_360_P.VideoCapture3_OvFocus, false }
    };

    t_error result;

    /*printf("Opening camera video://localhost:3\n"); fflush(stdout);*/
    result = video_capture_open("video://localhost:3", 30.0, 640U, 480U,
      IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
      &Imaging_360_DW.VideoCapture3_VideoCapture, local_attr, ARRAY_LENGTH
      (local_attr));
    if (result >= 0) {
      result = video_capture_start(Imaging_360_DW.VideoCapture3_VideoCapture);
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<Root>/display' */

  /* Start for S-Function (channel_block): '<S4>/Channel' */

  /* S-Function Block: Imaging_360/display/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 3, 3686400, 1,
      (t_channel_fifo *) &Imaging_360_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Imaging_360_M, _rt_error_message);
    }
  }

  /* End of Start for SubSystem: '<Root>/display' */
  {
    int32_T i;

    /* SystemInitialize for Enabled SubSystem: '<Root>/stich' */
    for (i = 0; i < 3686400; i++) {
      /* SystemInitialize for Concatenate: '<S6>/Matrix Concatenate' incorporates:
       *  Outport: '<S6>/360 view'
       */
      Imaging_360_B.MatrixConcatenate[i] = Imaging_360_P.u60view_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/stich' */
  }
}

/* Model terminate function */
void Imaging_360_terminate(void)
{
  /* Terminate for S-Function (video_capture_block): '<S3>/Video Capture' */
  video_capture_stop(Imaging_360_DW.VideoCapture_VideoCapture);
  video_capture_close(Imaging_360_DW.VideoCapture_VideoCapture);

  /* Terminate for S-Function (video_capture_block): '<S3>/Video Capture1' */
  video_capture_stop(Imaging_360_DW.VideoCapture1_VideoCapture);
  video_capture_close(Imaging_360_DW.VideoCapture1_VideoCapture);

  /* Terminate for S-Function (video_capture_block): '<S3>/Video Capture2' */
  video_capture_stop(Imaging_360_DW.VideoCapture2_VideoCapture);
  video_capture_close(Imaging_360_DW.VideoCapture2_VideoCapture);

  /* Terminate for S-Function (video_capture_block): '<S3>/Video Capture3' */
  video_capture_stop(Imaging_360_DW.VideoCapture3_VideoCapture);
  video_capture_close(Imaging_360_DW.VideoCapture3_VideoCapture);

  /* Terminate for Enabled SubSystem: '<Root>/display' */

  /* Terminate for S-Function (channel_block): '<S4>/Channel' */

  /* S-Function Block: Imaging_360/display/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo) Imaging_360_DW.Channel_PWORK.Fifo);
    Imaging_360_DW.Channel_PWORK.Fifo = NULL;
  }

  /* End of Terminate for SubSystem: '<Root>/display' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Imaging_360_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Imaging_360_update();
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
  Imaging_360_initialize();
}

void MdlTerminate(void)
{
  Imaging_360_terminate();
}

/* Registration function */
RT_MODEL_Imaging_360_T *Imaging_360(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Imaging_360_M, 0,
                sizeof(RT_MODEL_Imaging_360_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Imaging_360_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Imaging_360_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Imaging_360_M->Timing.sampleTimes = (&Imaging_360_M->
      Timing.sampleTimesArray[0]);
    Imaging_360_M->Timing.offsetTimes = (&Imaging_360_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Imaging_360_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    Imaging_360_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Imaging_360_M, &Imaging_360_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Imaging_360_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Imaging_360_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Imaging_360_M, -1);
  Imaging_360_M->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  Imaging_360_M->Sizes.checksums[0] = (2662405260U);
  Imaging_360_M->Sizes.checksums[1] = (1149459889U);
  Imaging_360_M->Sizes.checksums[2] = (408158165U);
  Imaging_360_M->Sizes.checksums[3] = (835093224U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Imaging_360_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Imaging_360_DW.display_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Imaging_360_DW.stich_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Imaging_360_M->extModeInfo,
      &Imaging_360_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Imaging_360_M->extModeInfo,
                        Imaging_360_M->Sizes.checksums);
    rteiSetTPtr(Imaging_360_M->extModeInfo, rtmGetTPtr(Imaging_360_M));
  }

  Imaging_360_M->solverInfoPtr = (&Imaging_360_M->solverInfo);
  Imaging_360_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&Imaging_360_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&Imaging_360_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Imaging_360_M->blockIO = ((void *) &Imaging_360_B);
  (void) memset(((void *) &Imaging_360_B), 0,
                sizeof(B_Imaging_360_T));

  {
    Imaging_360_B.Channel = CHANNEL_0;
  }

  /* parameters */
  Imaging_360_M->defaultParam = ((real_T *)&Imaging_360_P);

  /* states (dwork) */
  Imaging_360_M->dwork = ((void *) &Imaging_360_DW);
  (void) memset((void *)&Imaging_360_DW, 0,
                sizeof(DW_Imaging_360_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Imaging_360_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Imaging_360_M->Sizes.numContStates = (0);/* Number of continuous states */
  Imaging_360_M->Sizes.numY = (0);     /* Number of model outputs */
  Imaging_360_M->Sizes.numU = (0);     /* Number of model inputs */
  Imaging_360_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Imaging_360_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Imaging_360_M->Sizes.numBlocks = (18);/* Number of blocks */
  Imaging_360_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  Imaging_360_M->Sizes.numBlockPrms = (139);/* Sum of parameter "widths" */
  return Imaging_360_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
