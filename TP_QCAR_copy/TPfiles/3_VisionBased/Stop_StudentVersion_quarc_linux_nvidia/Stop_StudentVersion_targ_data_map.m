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
    ;% Auto data (Stop_StudentVersion_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.CompareToConstant_const
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.HSVColorThresholding_b_comparis
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.ImageFindObjects_connectivity
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_g_comparis
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_r_comparis
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_P.ImageFindObjects_sort_order
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.HILRead_analog_channels
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.CompareToConstant_const_h
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_P.HILRead_encoder_channels
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_P.ImageFindObjects_max_pixels
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Stop_StudentVersion_P.ImageFindObjects_min_pixels
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Stop_StudentVersion_P.HILWrite_other_channels
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Stop_StudentVersion_P.HILWrite_pwm_channels
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 7;
	
	  ;% Stop_StudentVersion_P.Depth_stream_index
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 8;
	
	  ;% Stop_StudentVersion_P.RGB_stream_index
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.Video3DInitialize_active
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.ImageFindObjects_exclude_at_edg
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_P.ImageFindObjects_largest
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 87;
      section.data(87)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.Constant_Value
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.AdjustforVFOV_Gain
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_P.AdjustforHFOV_Gain
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_P.Constant1_Value
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_P.Constant1_Value_j
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stop_StudentVersion_P.Constant_Value_m
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Stop_StudentVersion_P.blobLocationpx2_Y0
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Stop_StudentVersion_P.ImageTransform_MinPixel
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Stop_StudentVersion_P.ImageTransform_MaxPixel
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Stop_StudentVersion_P.ImageTransform_FocalLen
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Stop_StudentVersion_P.ImageTransform_Extrapolated
	  section.data(11).logicalSrcIdx = 28;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Stop_StudentVersion_P.ImageTransform_Angle
	  section.data(12).logicalSrcIdx = 29;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Stop_StudentVersion_P.ImageTransform_RCoeff
	  section.data(13).logicalSrcIdx = 30;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Stop_StudentVersion_P.Constant_Value_c
	  section.data(14).logicalSrcIdx = 31;
	  section.data(14).dtTransOffset = 14;
	
	  ;% Stop_StudentVersion_P.HueThreshold_Value
	  section.data(15).logicalSrcIdx = 32;
	  section.data(15).dtTransOffset = 15;
	
	  ;% Stop_StudentVersion_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 33;
	  section.data(16).dtTransOffset = 16;
	
	  ;% Stop_StudentVersion_P.Constant1_Value_a
	  section.data(17).logicalSrcIdx = 34;
	  section.data(17).dtTransOffset = 17;
	
	  ;% Stop_StudentVersion_P.Constant2_Value
	  section.data(18).logicalSrcIdx = 35;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_Channel0Mi
	  section.data(19).logicalSrcIdx = 36;
	  section.data(19).dtTransOffset = 21;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_Channel0Ma
	  section.data(20).logicalSrcIdx = 37;
	  section.data(20).dtTransOffset = 22;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_Channel1Mi
	  section.data(21).logicalSrcIdx = 38;
	  section.data(21).dtTransOffset = 23;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_Channel1Ma
	  section.data(22).logicalSrcIdx = 39;
	  section.data(22).dtTransOffset = 24;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_Channel2Mi
	  section.data(23).logicalSrcIdx = 40;
	  section.data(23).dtTransOffset = 25;
	
	  ;% Stop_StudentVersion_P.HSVColorThresholding_Channel2Ma
	  section.data(24).logicalSrcIdx = 41;
	  section.data(24).dtTransOffset = 26;
	
	  ;% Stop_StudentVersion_P.Constant3_Value
	  section.data(25).logicalSrcIdx = 42;
	  section.data(25).dtTransOffset = 27;
	
	  ;% Stop_StudentVersion_P.Constant_Value_l
	  section.data(26).logicalSrcIdx = 43;
	  section.data(26).dtTransOffset = 29;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOTerminate
	  section.data(27).logicalSrcIdx = 44;
	  section.data(27).dtTransOffset = 30;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOExit
	  section.data(28).logicalSrcIdx = 45;
	  section.data(28).dtTransOffset = 31;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOStart
	  section.data(29).logicalSrcIdx = 46;
	  section.data(29).dtTransOffset = 32;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOEnter
	  section.data(30).logicalSrcIdx = 47;
	  section.data(30).dtTransOffset = 33;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POFinal
	  section.data(31).logicalSrcIdx = 48;
	  section.data(31).dtTransOffset = 34;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOFinal
	  section.data(32).logicalSrcIdx = 49;
	  section.data(32).dtTransOffset = 35;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AIHigh
	  section.data(33).logicalSrcIdx = 50;
	  section.data(33).dtTransOffset = 36;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AILow
	  section.data(34).logicalSrcIdx = 51;
	  section.data(34).dtTransOffset = 37;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIFrequency
	  section.data(35).logicalSrcIdx = 52;
	  section.data(35).dtTransOffset = 38;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POFrequency
	  section.data(36).logicalSrcIdx = 53;
	  section.data(36).dtTransOffset = 39;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POInitial
	  section.data(37).logicalSrcIdx = 54;
	  section.data(37).dtTransOffset = 40;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POWatchdog
	  section.data(38).logicalSrcIdx = 55;
	  section.data(38).dtTransOffset = 41;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOInitial
	  section.data(39).logicalSrcIdx = 56;
	  section.data(39).dtTransOffset = 42;
	
	  ;% Stop_StudentVersion_P.Constant1_Value_n
	  section.data(40).logicalSrcIdx = 57;
	  section.data(40).dtTransOffset = 43;
	
	  ;% Stop_StudentVersion_P.Constant2_Value_d
	  section.data(41).logicalSrcIdx = 58;
	  section.data(41).dtTransOffset = 44;
	
	  ;% Stop_StudentVersion_P.Constant_Value_o
	  section.data(42).logicalSrcIdx = 59;
	  section.data(42).dtTransOffset = 45;
	
	  ;% Stop_StudentVersion_P.Unwrap224_Modulus
	  section.data(43).logicalSrcIdx = 60;
	  section.data(43).dtTransOffset = 46;
	
	  ;% Stop_StudentVersion_P.Integrator2_IC
	  section.data(44).logicalSrcIdx = 61;
	  section.data(44).dtTransOffset = 47;
	
	  ;% Stop_StudentVersion_P.Depth_Brightness
	  section.data(45).logicalSrcIdx = 62;
	  section.data(45).dtTransOffset = 48;
	
	  ;% Stop_StudentVersion_P.Depth_Contrast
	  section.data(46).logicalSrcIdx = 63;
	  section.data(46).dtTransOffset = 49;
	
	  ;% Stop_StudentVersion_P.Depth_Hue
	  section.data(47).logicalSrcIdx = 64;
	  section.data(47).dtTransOffset = 50;
	
	  ;% Stop_StudentVersion_P.Depth_Saturation
	  section.data(48).logicalSrcIdx = 65;
	  section.data(48).dtTransOffset = 51;
	
	  ;% Stop_StudentVersion_P.Depth_Sharpness
	  section.data(49).logicalSrcIdx = 66;
	  section.data(49).dtTransOffset = 52;
	
	  ;% Stop_StudentVersion_P.Depth_Gamma
	  section.data(50).logicalSrcIdx = 67;
	  section.data(50).dtTransOffset = 53;
	
	  ;% Stop_StudentVersion_P.Depth_WhiteBalance
	  section.data(51).logicalSrcIdx = 68;
	  section.data(51).dtTransOffset = 54;
	
	  ;% Stop_StudentVersion_P.Depth_BacklightCompensation
	  section.data(52).logicalSrcIdx = 69;
	  section.data(52).dtTransOffset = 55;
	
	  ;% Stop_StudentVersion_P.Depth_Gain
	  section.data(53).logicalSrcIdx = 70;
	  section.data(53).dtTransOffset = 56;
	
	  ;% Stop_StudentVersion_P.Depth_Exposure
	  section.data(54).logicalSrcIdx = 71;
	  section.data(54).dtTransOffset = 57;
	
	  ;% Stop_StudentVersion_P.Depth_Emitter
	  section.data(55).logicalSrcIdx = 72;
	  section.data(55).dtTransOffset = 58;
	
	  ;% Stop_StudentVersion_P.RGB_Brightness
	  section.data(56).logicalSrcIdx = 73;
	  section.data(56).dtTransOffset = 59;
	
	  ;% Stop_StudentVersion_P.RGB_Contrast
	  section.data(57).logicalSrcIdx = 74;
	  section.data(57).dtTransOffset = 60;
	
	  ;% Stop_StudentVersion_P.RGB_Hue
	  section.data(58).logicalSrcIdx = 75;
	  section.data(58).dtTransOffset = 61;
	
	  ;% Stop_StudentVersion_P.RGB_Saturation
	  section.data(59).logicalSrcIdx = 76;
	  section.data(59).dtTransOffset = 62;
	
	  ;% Stop_StudentVersion_P.RGB_Sharpness
	  section.data(60).logicalSrcIdx = 77;
	  section.data(60).dtTransOffset = 63;
	
	  ;% Stop_StudentVersion_P.RGB_Gamma
	  section.data(61).logicalSrcIdx = 78;
	  section.data(61).dtTransOffset = 64;
	
	  ;% Stop_StudentVersion_P.RGB_WhiteBalance
	  section.data(62).logicalSrcIdx = 79;
	  section.data(62).dtTransOffset = 65;
	
	  ;% Stop_StudentVersion_P.RGB_BacklightCompensation
	  section.data(63).logicalSrcIdx = 80;
	  section.data(63).dtTransOffset = 66;
	
	  ;% Stop_StudentVersion_P.RGB_Gain
	  section.data(64).logicalSrcIdx = 81;
	  section.data(64).dtTransOffset = 67;
	
	  ;% Stop_StudentVersion_P.RGB_Exposure
	  section.data(65).logicalSrcIdx = 82;
	  section.data(65).dtTransOffset = 68;
	
	  ;% Stop_StudentVersion_P.RGB_Emitter
	  section.data(66).logicalSrcIdx = 83;
	  section.data(66).dtTransOffset = 69;
	
	  ;% Stop_StudentVersion_P.ms_Value
	  section.data(67).logicalSrcIdx = 84;
	  section.data(67).dtTransOffset = 70;
	
	  ;% Stop_StudentVersion_P.commandsaturation_UpperSat
	  section.data(68).logicalSrcIdx = 85;
	  section.data(68).dtTransOffset = 71;
	
	  ;% Stop_StudentVersion_P.commandsaturation_LowerSat
	  section.data(69).logicalSrcIdx = 86;
	  section.data(69).dtTransOffset = 72;
	
	  ;% Stop_StudentVersion_P.Constant_Value_j
	  section.data(70).logicalSrcIdx = 87;
	  section.data(70).dtTransOffset = 73;
	
	  ;% Stop_StudentVersion_P.Kffms_Gain
	  section.data(71).logicalSrcIdx = 88;
	  section.data(71).dtTransOffset = 74;
	
	  ;% Stop_StudentVersion_P.countstorotations_Gain
	  section.data(72).logicalSrcIdx = 89;
	  section.data(72).dtTransOffset = 75;
	
	  ;% Stop_StudentVersion_P.gearratios_Gain
	  section.data(73).logicalSrcIdx = 90;
	  section.data(73).dtTransOffset = 76;
	
	  ;% Stop_StudentVersion_P.rotstorads_Gain
	  section.data(74).logicalSrcIdx = 91;
	  section.data(74).dtTransOffset = 77;
	
	  ;% Stop_StudentVersion_P.wheelradius_Gain
	  section.data(75).logicalSrcIdx = 92;
	  section.data(75).dtTransOffset = 78;
	
	  ;% Stop_StudentVersion_P.Kpms_Gain
	  section.data(76).logicalSrcIdx = 93;
	  section.data(76).dtTransOffset = 79;
	
	  ;% Stop_StudentVersion_P.Integrator1_IC
	  section.data(77).logicalSrcIdx = 94;
	  section.data(77).dtTransOffset = 80;
	
	  ;% Stop_StudentVersion_P.Integrator1_UpperSat
	  section.data(78).logicalSrcIdx = 95;
	  section.data(78).dtTransOffset = 81;
	
	  ;% Stop_StudentVersion_P.Integrator1_LowerSat
	  section.data(79).logicalSrcIdx = 96;
	  section.data(79).dtTransOffset = 82;
	
	  ;% Stop_StudentVersion_P.directionconvention_Gain
	  section.data(80).logicalSrcIdx = 97;
	  section.data(80).dtTransOffset = 83;
	
	  ;% Stop_StudentVersion_P.commandsaturation_UpperSat_e
	  section.data(81).logicalSrcIdx = 98;
	  section.data(81).dtTransOffset = 84;
	
	  ;% Stop_StudentVersion_P.commandsaturation_LowerSat_h
	  section.data(82).logicalSrcIdx = 99;
	  section.data(82).dtTransOffset = 85;
	
	  ;% Stop_StudentVersion_P.Steering_Value
	  section.data(83).logicalSrcIdx = 100;
	  section.data(83).dtTransOffset = 86;
	
	  ;% Stop_StudentVersion_P.Gain_Gain_j
	  section.data(84).logicalSrcIdx = 101;
	  section.data(84).dtTransOffset = 87;
	
	  ;% Stop_StudentVersion_P.SteeringBias_Bias
	  section.data(85).logicalSrcIdx = 102;
	  section.data(85).dtTransOffset = 88;
	
	  ;% Stop_StudentVersion_P.Kim_Gain
	  section.data(86).logicalSrcIdx = 103;
	  section.data(86).dtTransOffset = 89;
	
	  ;% Stop_StudentVersion_P.Constant_Value_e
	  section.data(87).logicalSrcIdx = 104;
	  section.data(87).dtTransOffset = 90;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.ImageTransform_PrPoint
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.ImageTransform_Interpolation
	  section.data(2).logicalSrcIdx = 106;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_P.ImageTransform_Origin
	  section.data(3).logicalSrcIdx = 107;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_P.ImageTransform_OOrigin
	  section.data(4).logicalSrcIdx = 108;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIInitial
	  section.data(5).logicalSrcIdx = 109;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POModes
	  section.data(6).logicalSrcIdx = 110;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POConfiguration
	  section.data(7).logicalSrcIdx = 111;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POAlignment
	  section.data(8).logicalSrcIdx = 112;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POPolarity
	  section.data(9).logicalSrcIdx = 113;
	  section.data(9).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.distanceToSignm_Y0
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.ImageCompress_Quality
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.ImageTransform_ColorTheme
	  section.data(2).logicalSrcIdx = 116;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_P.ImageCompress_Quality_o
	  section.data(3).logicalSrcIdx = 117;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_P.ImageCompress_Quality_f
	  section.data(4).logicalSrcIdx = 118;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AIChannels
	  section.data(5).logicalSrcIdx = 119;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DIChannels
	  section.data(6).logicalSrcIdx = 120;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOChannels
	  section.data(7).logicalSrcIdx = 121;
	  section.data(7).dtTransOffset = 31;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIChannels
	  section.data(8).logicalSrcIdx = 122;
	  section.data(8).dtTransOffset = 32;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIQuadrature
	  section.data(9).logicalSrcIdx = 123;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POChannels
	  section.data(10).logicalSrcIdx = 124;
	  section.data(10).dtTransOffset = 39;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOChannels
	  section.data(11).logicalSrcIdx = 125;
	  section.data(11).dtTransOffset = 47;
	
	  ;% Stop_StudentVersion_P.Depth_Preset
	  section.data(12).logicalSrcIdx = 126;
	  section.data(12).dtTransOffset = 60;
	
	  ;% Stop_StudentVersion_P.RGB_Preset
	  section.data(13).logicalSrcIdx = 127;
	  section.data(13).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_P.VideoDisplay_UseHardware
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_P.blobFound_Y0
	  section.data(2).logicalSrcIdx = 129;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_P.VideoDisplay_UseHardware_g
	  section.data(3).logicalSrcIdx = 130;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_P.VideoDisplay_UseHardware_d
	  section.data(4).logicalSrcIdx = 131;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_P.HILInitialize_Active
	  section.data(5).logicalSrcIdx = 132;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOTerminate
	  section.data(6).logicalSrcIdx = 133;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOExit
	  section.data(7).logicalSrcIdx = 134;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOTerminate
	  section.data(8).logicalSrcIdx = 135;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOExit
	  section.data(9).logicalSrcIdx = 136;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POTerminate
	  section.data(10).logicalSrcIdx = 137;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POExit
	  section.data(11).logicalSrcIdx = 138;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Stop_StudentVersion_P.HILInitialize_CKPStart
	  section.data(12).logicalSrcIdx = 139;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Stop_StudentVersion_P.HILInitialize_CKPEnter
	  section.data(13).logicalSrcIdx = 140;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Stop_StudentVersion_P.HILInitialize_CKStart
	  section.data(14).logicalSrcIdx = 141;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Stop_StudentVersion_P.HILInitialize_CKEnter
	  section.data(15).logicalSrcIdx = 142;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AIPStart
	  section.data(16).logicalSrcIdx = 143;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AIPEnter
	  section.data(17).logicalSrcIdx = 144;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOPStart
	  section.data(18).logicalSrcIdx = 145;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOPEnter
	  section.data(19).logicalSrcIdx = 146;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOStart
	  section.data(20).logicalSrcIdx = 147;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOEnter
	  section.data(21).logicalSrcIdx = 148;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Stop_StudentVersion_P.HILInitialize_AOReset
	  section.data(22).logicalSrcIdx = 149;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOPStart
	  section.data(23).logicalSrcIdx = 150;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOPEnter
	  section.data(24).logicalSrcIdx = 151;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOStart
	  section.data(25).logicalSrcIdx = 152;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOEnter
	  section.data(26).logicalSrcIdx = 153;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOReset
	  section.data(27).logicalSrcIdx = 154;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIPStart
	  section.data(28).logicalSrcIdx = 155;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIPEnter
	  section.data(29).logicalSrcIdx = 156;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIStart
	  section.data(30).logicalSrcIdx = 157;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Stop_StudentVersion_P.HILInitialize_EIEnter
	  section.data(31).logicalSrcIdx = 158;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POPStart
	  section.data(32).logicalSrcIdx = 159;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POPEnter
	  section.data(33).logicalSrcIdx = 160;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POStart
	  section.data(34).logicalSrcIdx = 161;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POEnter
	  section.data(35).logicalSrcIdx = 162;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Stop_StudentVersion_P.HILInitialize_POReset
	  section.data(36).logicalSrcIdx = 163;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Stop_StudentVersion_P.HILInitialize_OOReset
	  section.data(37).logicalSrcIdx = 164;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOFinal
	  section.data(38).logicalSrcIdx = 165;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Stop_StudentVersion_P.HILInitialize_DOInitial
	  section.data(39).logicalSrcIdx = 166;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Stop_StudentVersion_P.HILRead_Active
	  section.data(40).logicalSrcIdx = 167;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Stop_StudentVersion_P.HILWrite_Active
	  section.data(41).logicalSrcIdx = 168;
	  section.data(41).dtTransOffset = 40;
	
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
    nTotSects     = 6;
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
    ;% Auto data (Stop_StudentVersion_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_B.Depth_o2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_B.RGB_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_B.encodercounts
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_B.Unwrap224
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_B.Product
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_B.Product1
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stop_StudentVersion_B.Depth_o3
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stop_StudentVersion_B.RGB_o3
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Stop_StudentVersion_B.desired
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Stop_StudentVersion_B.Kffms
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Stop_StudentVersion_B.measured
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Stop_StudentVersion_B.commandsaturation
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Stop_StudentVersion_B.Kim
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Stop_StudentVersion_B.actualsampletime
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Stop_StudentVersion_B.reference
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Stop_StudentVersion_B.computationtime
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Stop_StudentVersion_B.Constant
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Stop_StudentVersion_B.Subtract
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_B.Channel
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_B.Channel_o
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_B.Channel_a
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_B.Depth_o1
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_B.Selector
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 921600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_B.RGB_o1
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_B.ImageCompress
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 2764800;
	
	  ;% Stop_StudentVersion_B.ImageCompress_g
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 3686400;
	
	  ;% Stop_StudentVersion_B.ImageCompress_c
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 6451200;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_B.RGB_o4
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_B.Compare
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_B.Compare_c
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
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
    nTotSects     = 15;
    sectIdxOffset = 6;
    
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
    ;% Auto data (Stop_StudentVersion_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.ComputationTime_BeginTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_DW.ComputationTime_ComputationTime
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 14;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 19;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 27;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Stop_StudentVersion_DW.HILRead_AnalogBuffer
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 48;
	
	  ;% Stop_StudentVersion_DW.Unwrap224_PreviousInput
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 50;
	
	  ;% Stop_StudentVersion_DW.Unwrap224_Revolutions
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.Depth_Video3D
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.RGB_Video3D
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_DW.Video3DInitialize_Video3D
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.Depth_Stream
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.RGB_Stream
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.ImageCompress_Compress
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_Compress_c
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_Compress_g
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.ImageFindObjects_FindHandle
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.ImageTransform_AlgHandle
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.HILRead_PWORK
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.HILWrite_PWORK
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stop_StudentVersion_DW.Scope_PWORK_k.LoggedData
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Stop_StudentVersion_DW.Channel_PWORK.Fifo
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Stop_StudentVersion_DW.Channel_PWORK_d.Fifo
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Stop_StudentVersion_DW.Channel_PWORK_f.Fifo
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 33;
	  section.data(4).dtTransOffset = 11;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 34;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Stop_StudentVersion_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 35;
	  section.data(6).dtTransOffset = 27;
	
	  ;% Stop_StudentVersion_DW.HILRead_EncoderBuffer
	  section.data(7).logicalSrcIdx = 36;
	  section.data(7).dtTransOffset = 35;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_DIMS1
	  section.data(8).logicalSrcIdx = 37;
	  section.data(8).dtTransOffset = 36;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_DIMS1_l
	  section.data(9).logicalSrcIdx = 38;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_DIMS1_e
	  section.data(10).logicalSrcIdx = 39;
	  section.data(10).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.findStopSignLocation_SubsysRanB
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.findStopSignDistance_SubsysRanB
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.ImageCompress_ScanLine
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_ScanLine_a
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 10240;
	
	  ;% Stop_StudentVersion_DW.ImageCompress_ScanLine_c
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 40960;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stop_StudentVersion_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
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


  targMap.checksum0 = 1145381730;
  targMap.checksum1 = 3207851109;
  targMap.checksum2 = 1689980265;
  targMap.checksum3 = 433238208;

