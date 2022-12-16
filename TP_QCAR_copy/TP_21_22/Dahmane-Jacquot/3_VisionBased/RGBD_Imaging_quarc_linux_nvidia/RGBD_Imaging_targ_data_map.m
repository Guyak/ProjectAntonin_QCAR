  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (RGBD_Imaging_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.CompareToConstant_const
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.HSVColorThresholding_b_comparis
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.ImageFindObjects_connectivity
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_g_comparis
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_r_comparis
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RGBD_Imaging_P.ImageFindObjects_sort_order
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.CompareToConstant_const_h
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.ImageFindObjects_max_pixels
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_P.ImageFindObjects_min_pixels
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_P.Depth_stream_index
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RGBD_Imaging_P.RGB_stream_index
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.Video3DInitialize_active
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.ImageFindObjects_exclude_at_edg
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_P.ImageFindObjects_largest
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.Constant_Value
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.AdjustforVFOV_Gain
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_P.AdjustforHFOV_Gain
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_P.Constant1_Value
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RGBD_Imaging_P.Constant1_Value_j
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RGBD_Imaging_P.Constant_Value_m
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
	  ;% RGBD_Imaging_P.blobLocationpx2_Y0
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 6;
	
	  ;% RGBD_Imaging_P.ImageTransform_MinPixel
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 7;
	
	  ;% RGBD_Imaging_P.ImageTransform_MaxPixel
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 8;
	
	  ;% RGBD_Imaging_P.ImageTransform_FocalLen
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 9;
	
	  ;% RGBD_Imaging_P.ImageTransform_Extrapolated
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 10;
	
	  ;% RGBD_Imaging_P.ImageTransform_Angle
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 11;
	
	  ;% RGBD_Imaging_P.ImageTransform_RCoeff
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 12;
	
	  ;% RGBD_Imaging_P.Constant_Value_c
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 14;
	
	  ;% RGBD_Imaging_P.HueThreshold_Value
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 15;
	
	  ;% RGBD_Imaging_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 16;
	
	  ;% RGBD_Imaging_P.Constant1_Value_a
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 17;
	
	  ;% RGBD_Imaging_P.Constant2_Value
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 19;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_Channel0Mi
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 21;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_Channel0Ma
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 22;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_Channel1Mi
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 23;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_Channel1Ma
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 24;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_Channel2Mi
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 25;
	
	  ;% RGBD_Imaging_P.HSVColorThresholding_Channel2Ma
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 26;
	
	  ;% RGBD_Imaging_P.Constant3_Value
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 27;
	
	  ;% RGBD_Imaging_P.Depth_Brightness
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 29;
	
	  ;% RGBD_Imaging_P.Depth_Contrast
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 30;
	
	  ;% RGBD_Imaging_P.Depth_Hue
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 31;
	
	  ;% RGBD_Imaging_P.Depth_Saturation
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 32;
	
	  ;% RGBD_Imaging_P.Depth_Sharpness
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 33;
	
	  ;% RGBD_Imaging_P.Depth_Gamma
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 34;
	
	  ;% RGBD_Imaging_P.Depth_WhiteBalance
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 35;
	
	  ;% RGBD_Imaging_P.Depth_BacklightCompensation
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 36;
	
	  ;% RGBD_Imaging_P.Depth_Gain
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 37;
	
	  ;% RGBD_Imaging_P.Depth_Exposure
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 38;
	
	  ;% RGBD_Imaging_P.Depth_Emitter
	  section.data(36).logicalSrcIdx = 49;
	  section.data(36).dtTransOffset = 39;
	
	  ;% RGBD_Imaging_P.RGB_Brightness
	  section.data(37).logicalSrcIdx = 50;
	  section.data(37).dtTransOffset = 40;
	
	  ;% RGBD_Imaging_P.RGB_Contrast
	  section.data(38).logicalSrcIdx = 51;
	  section.data(38).dtTransOffset = 41;
	
	  ;% RGBD_Imaging_P.RGB_Hue
	  section.data(39).logicalSrcIdx = 52;
	  section.data(39).dtTransOffset = 42;
	
	  ;% RGBD_Imaging_P.RGB_Saturation
	  section.data(40).logicalSrcIdx = 53;
	  section.data(40).dtTransOffset = 43;
	
	  ;% RGBD_Imaging_P.RGB_Sharpness
	  section.data(41).logicalSrcIdx = 54;
	  section.data(41).dtTransOffset = 44;
	
	  ;% RGBD_Imaging_P.RGB_Gamma
	  section.data(42).logicalSrcIdx = 55;
	  section.data(42).dtTransOffset = 45;
	
	  ;% RGBD_Imaging_P.RGB_WhiteBalance
	  section.data(43).logicalSrcIdx = 56;
	  section.data(43).dtTransOffset = 46;
	
	  ;% RGBD_Imaging_P.RGB_BacklightCompensation
	  section.data(44).logicalSrcIdx = 57;
	  section.data(44).dtTransOffset = 47;
	
	  ;% RGBD_Imaging_P.RGB_Gain
	  section.data(45).logicalSrcIdx = 58;
	  section.data(45).dtTransOffset = 48;
	
	  ;% RGBD_Imaging_P.RGB_Exposure
	  section.data(46).logicalSrcIdx = 59;
	  section.data(46).dtTransOffset = 49;
	
	  ;% RGBD_Imaging_P.RGB_Emitter
	  section.data(47).logicalSrcIdx = 60;
	  section.data(47).dtTransOffset = 50;
	
	  ;% RGBD_Imaging_P.Constant_Value_e
	  section.data(48).logicalSrcIdx = 61;
	  section.data(48).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.ImageTransform_PrPoint
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.ImageTransform_Interpolation
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_P.ImageTransform_Origin
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 3;
	
	  ;% RGBD_Imaging_P.ImageTransform_OOrigin
	  section.data(4).logicalSrcIdx = 65;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.distanceToSignm_Y0
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.ImageCompress_Quality
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.ImageTransform_ColorTheme
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_P.ImageCompress_Quality_o
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_P.ImageCompress_Quality_f
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RGBD_Imaging_P.Depth_Preset
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RGBD_Imaging_P.RGB_Preset
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_P.VideoDisplay_UseHardware
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_P.blobFound_Y0
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_P.VideoDisplay_UseHardware_g
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_P.VideoDisplay_UseHardware_d
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (RGBD_Imaging_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.Depth_o2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_B.RGB_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.Depth_o3
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_B.RGB_o3
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_B.actualsampletime
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_B.reference
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RGBD_Imaging_B.computationtime
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RGBD_Imaging_B.Constant
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% RGBD_Imaging_B.Subtract
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.Channel
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_B.Channel_o
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_B.Channel_a
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.Depth_o1
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_B.Selector
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 921600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.RGB_o1
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_B.ImageCompress
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 2764800;
	
	  ;% RGBD_Imaging_B.ImageCompress_g
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 3686400;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.ImageCompress_c
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_B.RGB_o4
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_B.Compare
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 7;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (RGBD_Imaging_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.ComputationTime_BeginTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_DW.ComputationTime_ComputationTime
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.Video3DInitialize_Video3D
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.Depth_Video3D
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_DW.RGB_Video3D
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.Depth_Stream
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.RGB_Stream
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.ImageCompress_Compress
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.ImageCompress_Compress_c
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_DW.ImageCompress_Compress_g
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.ImageFindObjects_FindHandle
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.ImageTransform_AlgHandle
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.Channel_PWORK.Fifo
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_DW.Channel_PWORK_d.Fifo
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RGBD_Imaging_DW.Channel_PWORK_f.Fifo
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.ImageCompress_DIMS1
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.ImageCompress_DIMS1_l
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RGBD_Imaging_DW.ImageCompress_DIMS1_e
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.findStopSignLocation_SubsysRanB
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.findStopSignDistance_SubsysRanB
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% RGBD_Imaging_DW.ImageCompress_ScanLine
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RGBD_Imaging_DW.ImageCompress_ScanLine_a
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 10240;
	
	  ;% RGBD_Imaging_DW.ImageCompress_ScanLine_c
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 40960;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3903265909;
  targMap.checksum1 = 2706597267;
  targMap.checksum2 = 2443891547;
  targMap.checksum3 = 2018625468;

