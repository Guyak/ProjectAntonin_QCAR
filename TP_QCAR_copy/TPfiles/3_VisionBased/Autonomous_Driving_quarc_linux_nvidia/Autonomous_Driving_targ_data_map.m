  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
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
    ;% Auto data (Autonomous_Driving_P)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.camera_rate
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.depth_rate
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_P.LeftSteeringLimit_const
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_P.RightSteeringLimit_const
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_P.CompareToConstant3_const
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_P.CompareToConstant1_const
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Autonomous_Driving_P.CompareToConstant2_const
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_P.SpeedSelector1_gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_P.ColorSelectingMean0_gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Autonomous_Driving_P.ColorSelectingWindow1_gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Autonomous_Driving_P.ColorMixingMean0_gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Autonomous_Driving_P.ColorMixingWindow1_gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Autonomous_Driving_P.BrightnessMean0_gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Autonomous_Driving_P.BrightnessWindow1_gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Autonomous_Driving_P.DistaneToLane0_gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Autonomous_Driving_P.StoppingDistanceOffset0_gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.HSVColorThresholding_b_comparis
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_g_comparis
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_r_comparis
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.HILRead_analog_channels
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.HILWrite_digital_channels
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_P.HILRead_encoder_channels
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_P.HILWrite_other_channels
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_P.HILWrite_pwm_channels
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 13;
	
	  ;% Autonomous_Driving_P.Depth_stream_index
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.Video3DInitialize_active
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 167;
      section.data(167)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.distancem_Y0
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.Constant_Value
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_P.Constant1_Value
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_P.Constant2_Value
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_P.Constant3_Value
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_P.scale_Value
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_P.b_n_Value
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Autonomous_Driving_P.Constant_Value_j
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Autonomous_Driving_P.Saturation_UpperSat
	  section.data(9).logicalSrcIdx = 34;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Autonomous_Driving_P.Saturation_LowerSat
	  section.data(10).logicalSrcIdx = 35;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Autonomous_Driving_P.Constant10_Value
	  section.data(11).logicalSrcIdx = 36;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Autonomous_Driving_P.Constant8_Value
	  section.data(12).logicalSrcIdx = 37;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Autonomous_Driving_P.Constant4_Value
	  section.data(13).logicalSrcIdx = 38;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Autonomous_Driving_P.Constant3_Value_b
	  section.data(14).logicalSrcIdx = 39;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Autonomous_Driving_P.Saturation1_UpperSat
	  section.data(15).logicalSrcIdx = 40;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Autonomous_Driving_P.Saturation1_LowerSat
	  section.data(16).logicalSrcIdx = 41;
	  section.data(16).dtTransOffset = 17;
	
	  ;% Autonomous_Driving_P.Constant9_Value
	  section.data(17).logicalSrcIdx = 42;
	  section.data(17).dtTransOffset = 18;
	
	  ;% Autonomous_Driving_P.Constant_Value_i
	  section.data(18).logicalSrcIdx = 43;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOTerminate
	  section.data(19).logicalSrcIdx = 44;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOExit
	  section.data(20).logicalSrcIdx = 45;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOStart
	  section.data(21).logicalSrcIdx = 46;
	  section.data(21).dtTransOffset = 22;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOEnter
	  section.data(22).logicalSrcIdx = 47;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Autonomous_Driving_P.HILInitialize_POFinal
	  section.data(23).logicalSrcIdx = 48;
	  section.data(23).dtTransOffset = 24;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOFinal
	  section.data(24).logicalSrcIdx = 49;
	  section.data(24).dtTransOffset = 25;
	
	  ;% Autonomous_Driving_P.HILInitialize_AIHigh
	  section.data(25).logicalSrcIdx = 50;
	  section.data(25).dtTransOffset = 26;
	
	  ;% Autonomous_Driving_P.HILInitialize_AILow
	  section.data(26).logicalSrcIdx = 51;
	  section.data(26).dtTransOffset = 27;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIFrequency
	  section.data(27).logicalSrcIdx = 52;
	  section.data(27).dtTransOffset = 28;
	
	  ;% Autonomous_Driving_P.HILInitialize_POFrequency
	  section.data(28).logicalSrcIdx = 53;
	  section.data(28).dtTransOffset = 29;
	
	  ;% Autonomous_Driving_P.HILInitialize_POInitial
	  section.data(29).logicalSrcIdx = 54;
	  section.data(29).dtTransOffset = 30;
	
	  ;% Autonomous_Driving_P.HILInitialize_POWatchdog
	  section.data(30).logicalSrcIdx = 55;
	  section.data(30).dtTransOffset = 31;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOInitial
	  section.data(31).logicalSrcIdx = 56;
	  section.data(31).dtTransOffset = 32;
	
	  ;% Autonomous_Driving_P.Constant1_Value_l
	  section.data(32).logicalSrcIdx = 57;
	  section.data(32).dtTransOffset = 33;
	
	  ;% Autonomous_Driving_P.Constant2_Value_i
	  section.data(33).logicalSrcIdx = 58;
	  section.data(33).dtTransOffset = 34;
	
	  ;% Autonomous_Driving_P.Constant3_Value_j
	  section.data(34).logicalSrcIdx = 59;
	  section.data(34).dtTransOffset = 35;
	
	  ;% Autonomous_Driving_P.Constant4_Value_n
	  section.data(35).logicalSrcIdx = 60;
	  section.data(35).dtTransOffset = 36;
	
	  ;% Autonomous_Driving_P.Constant5_Value
	  section.data(36).logicalSrcIdx = 61;
	  section.data(36).dtTransOffset = 37;
	
	  ;% Autonomous_Driving_P.Constant6_Value
	  section.data(37).logicalSrcIdx = 62;
	  section.data(37).dtTransOffset = 38;
	
	  ;% Autonomous_Driving_P.Constant_Value_k
	  section.data(38).logicalSrcIdx = 63;
	  section.data(38).dtTransOffset = 39;
	
	  ;% Autonomous_Driving_P.Unwrap224_Modulus
	  section.data(39).logicalSrcIdx = 64;
	  section.data(39).dtTransOffset = 40;
	
	  ;% Autonomous_Driving_P.Integrator2_IC
	  section.data(40).logicalSrcIdx = 65;
	  section.data(40).dtTransOffset = 41;
	
	  ;% Autonomous_Driving_P.Constant_Value_h
	  section.data(41).logicalSrcIdx = 66;
	  section.data(41).dtTransOffset = 42;
	
	  ;% Autonomous_Driving_P.Integrator2_IC_f
	  section.data(42).logicalSrcIdx = 67;
	  section.data(42).dtTransOffset = 43;
	
	  ;% Autonomous_Driving_P.Constant_Value_e
	  section.data(43).logicalSrcIdx = 68;
	  section.data(43).dtTransOffset = 44;
	
	  ;% Autonomous_Driving_P.Integrator2_IC_j
	  section.data(44).logicalSrcIdx = 69;
	  section.data(44).dtTransOffset = 45;
	
	  ;% Autonomous_Driving_P.RateTransition1_InitialConditio
	  section.data(45).logicalSrcIdx = 70;
	  section.data(45).dtTransOffset = 46;
	
	  ;% Autonomous_Driving_P.Constant_Value_p
	  section.data(46).logicalSrcIdx = 71;
	  section.data(46).dtTransOffset = 47;
	
	  ;% Autonomous_Driving_P.Constant2_Value_f
	  section.data(47).logicalSrcIdx = 72;
	  section.data(47).dtTransOffset = 48;
	
	  ;% Autonomous_Driving_P.SpeedMaxms_Value
	  section.data(48).logicalSrcIdx = 73;
	  section.data(48).dtTransOffset = 49;
	
	  ;% Autonomous_Driving_P.Switch_Threshold
	  section.data(49).logicalSrcIdx = 74;
	  section.data(49).dtTransOffset = 50;
	
	  ;% Autonomous_Driving_P.RateLimiter_RisingLim
	  section.data(50).logicalSrcIdx = 75;
	  section.data(50).dtTransOffset = 51;
	
	  ;% Autonomous_Driving_P.RateLimiter_FallingLim
	  section.data(51).logicalSrcIdx = 76;
	  section.data(51).dtTransOffset = 52;
	
	  ;% Autonomous_Driving_P.RateLimiter_IC
	  section.data(52).logicalSrcIdx = 77;
	  section.data(52).dtTransOffset = 53;
	
	  ;% Autonomous_Driving_P.RateTransition_InitialCondition
	  section.data(53).logicalSrcIdx = 78;
	  section.data(53).dtTransOffset = 54;
	
	  ;% Autonomous_Driving_P.Constant1_Value_f
	  section.data(54).logicalSrcIdx = 79;
	  section.data(54).dtTransOffset = 55;
	
	  ;% Autonomous_Driving_P.Switch_Threshold_h
	  section.data(55).logicalSrcIdx = 80;
	  section.data(55).dtTransOffset = 56;
	
	  ;% Autonomous_Driving_P.commandsaturation_UpperSat
	  section.data(56).logicalSrcIdx = 81;
	  section.data(56).dtTransOffset = 57;
	
	  ;% Autonomous_Driving_P.commandsaturation_LowerSat
	  section.data(57).logicalSrcIdx = 82;
	  section.data(57).dtTransOffset = 58;
	
	  ;% Autonomous_Driving_P.Kffms_Gain
	  section.data(58).logicalSrcIdx = 83;
	  section.data(58).dtTransOffset = 59;
	
	  ;% Autonomous_Driving_P.countstorotations_Gain
	  section.data(59).logicalSrcIdx = 84;
	  section.data(59).dtTransOffset = 60;
	
	  ;% Autonomous_Driving_P.gearratios_Gain
	  section.data(60).logicalSrcIdx = 85;
	  section.data(60).dtTransOffset = 61;
	
	  ;% Autonomous_Driving_P.rotstorads_Gain
	  section.data(61).logicalSrcIdx = 86;
	  section.data(61).dtTransOffset = 62;
	
	  ;% Autonomous_Driving_P.wheelradius_Gain
	  section.data(62).logicalSrcIdx = 87;
	  section.data(62).dtTransOffset = 63;
	
	  ;% Autonomous_Driving_P.Kpms_Gain
	  section.data(63).logicalSrcIdx = 88;
	  section.data(63).dtTransOffset = 64;
	
	  ;% Autonomous_Driving_P.Integrator1_IC
	  section.data(64).logicalSrcIdx = 89;
	  section.data(64).dtTransOffset = 65;
	
	  ;% Autonomous_Driving_P.Integrator1_UpperSat
	  section.data(65).logicalSrcIdx = 90;
	  section.data(65).dtTransOffset = 66;
	
	  ;% Autonomous_Driving_P.Integrator1_LowerSat
	  section.data(66).logicalSrcIdx = 91;
	  section.data(66).dtTransOffset = 67;
	
	  ;% Autonomous_Driving_P.directionconvention_Gain
	  section.data(67).logicalSrcIdx = 92;
	  section.data(67).dtTransOffset = 68;
	
	  ;% Autonomous_Driving_P.commandsaturation_UpperSat_i
	  section.data(68).logicalSrcIdx = 93;
	  section.data(68).dtTransOffset = 69;
	
	  ;% Autonomous_Driving_P.commandsaturation_LowerSat_a
	  section.data(69).logicalSrcIdx = 94;
	  section.data(69).dtTransOffset = 70;
	
	  ;% Autonomous_Driving_P.coastON_Value
	  section.data(70).logicalSrcIdx = 95;
	  section.data(70).dtTransOffset = 71;
	
	  ;% Autonomous_Driving_P.Gain_Gain
	  section.data(71).logicalSrcIdx = 96;
	  section.data(71).dtTransOffset = 72;
	
	  ;% Autonomous_Driving_P.SteeringBias_Bias
	  section.data(72).logicalSrcIdx = 97;
	  section.data(72).dtTransOffset = 73;
	
	  ;% Autonomous_Driving_P.PulsingLight_Amp
	  section.data(73).logicalSrcIdx = 98;
	  section.data(73).dtTransOffset = 74;
	
	  ;% Autonomous_Driving_P.PulsingLight_Period
	  section.data(74).logicalSrcIdx = 99;
	  section.data(74).dtTransOffset = 75;
	
	  ;% Autonomous_Driving_P.PulsingLight_Duty
	  section.data(75).logicalSrcIdx = 100;
	  section.data(75).dtTransOffset = 76;
	
	  ;% Autonomous_Driving_P.PulsingLight_PhaseDelay
	  section.data(76).logicalSrcIdx = 101;
	  section.data(76).dtTransOffset = 77;
	
	  ;% Autonomous_Driving_P.Constant1_Value_fc
	  section.data(77).logicalSrcIdx = 102;
	  section.data(77).dtTransOffset = 78;
	
	  ;% Autonomous_Driving_P.Memory_InitialCondition
	  section.data(78).logicalSrcIdx = 103;
	  section.data(78).dtTransOffset = 79;
	
	  ;% Autonomous_Driving_P.Constant2_Value_b
	  section.data(79).logicalSrcIdx = 104;
	  section.data(79).dtTransOffset = 80;
	
	  ;% Autonomous_Driving_P.one_shot_block_trigger_type
	  section.data(80).logicalSrcIdx = 105;
	  section.data(80).dtTransOffset = 81;
	
	  ;% Autonomous_Driving_P.one_shot_block_redun_pulse
	  section.data(81).logicalSrcIdx = 106;
	  section.data(81).dtTransOffset = 82;
	
	  ;% Autonomous_Driving_P.Constant_Value_d
	  section.data(82).logicalSrcIdx = 107;
	  section.data(82).dtTransOffset = 83;
	
	  ;% Autonomous_Driving_P.Switch_Threshold_e
	  section.data(83).logicalSrcIdx = 108;
	  section.data(83).dtTransOffset = 84;
	
	  ;% Autonomous_Driving_P.Gain_Gain_p
	  section.data(84).logicalSrcIdx = 109;
	  section.data(84).dtTransOffset = 85;
	
	  ;% Autonomous_Driving_P.Bias1_Bias
	  section.data(85).logicalSrcIdx = 110;
	  section.data(85).dtTransOffset = 86;
	
	  ;% Autonomous_Driving_P.Saturation_UpperSat_p
	  section.data(86).logicalSrcIdx = 111;
	  section.data(86).dtTransOffset = 87;
	
	  ;% Autonomous_Driving_P.Saturation_LowerSat_p
	  section.data(87).logicalSrcIdx = 112;
	  section.data(87).dtTransOffset = 88;
	
	  ;% Autonomous_Driving_P.Kim_Gain
	  section.data(88).logicalSrcIdx = 113;
	  section.data(88).dtTransOffset = 89;
	
	  ;% Autonomous_Driving_P.Constant_Value_c
	  section.data(89).logicalSrcIdx = 114;
	  section.data(89).dtTransOffset = 90;
	
	  ;% Autonomous_Driving_P.RateTransition4_InitialConditio
	  section.data(90).logicalSrcIdx = 115;
	  section.data(90).dtTransOffset = 91;
	
	  ;% Autonomous_Driving_P.RateTransition3_InitialConditio
	  section.data(91).logicalSrcIdx = 116;
	  section.data(91).dtTransOffset = 92;
	
	  ;% Autonomous_Driving_P.VideoCapture_Brightness
	  section.data(92).logicalSrcIdx = 117;
	  section.data(92).dtTransOffset = 93;
	
	  ;% Autonomous_Driving_P.VideoCapture_Contrast
	  section.data(93).logicalSrcIdx = 118;
	  section.data(93).dtTransOffset = 94;
	
	  ;% Autonomous_Driving_P.VideoCapture_Hue
	  section.data(94).logicalSrcIdx = 119;
	  section.data(94).dtTransOffset = 95;
	
	  ;% Autonomous_Driving_P.VideoCapture_Saturation
	  section.data(95).logicalSrcIdx = 120;
	  section.data(95).dtTransOffset = 96;
	
	  ;% Autonomous_Driving_P.VideoCapture_Sharpness
	  section.data(96).logicalSrcIdx = 121;
	  section.data(96).dtTransOffset = 97;
	
	  ;% Autonomous_Driving_P.VideoCapture_Gamma
	  section.data(97).logicalSrcIdx = 122;
	  section.data(97).dtTransOffset = 98;
	
	  ;% Autonomous_Driving_P.VideoCapture_ColorEnable
	  section.data(98).logicalSrcIdx = 123;
	  section.data(98).dtTransOffset = 99;
	
	  ;% Autonomous_Driving_P.VideoCapture_WhiteBalance
	  section.data(99).logicalSrcIdx = 124;
	  section.data(99).dtTransOffset = 100;
	
	  ;% Autonomous_Driving_P.VideoCapture_BacklightCompensat
	  section.data(100).logicalSrcIdx = 125;
	  section.data(100).dtTransOffset = 101;
	
	  ;% Autonomous_Driving_P.VideoCapture_Gain
	  section.data(101).logicalSrcIdx = 126;
	  section.data(101).dtTransOffset = 102;
	
	  ;% Autonomous_Driving_P.VideoCapture_Pan
	  section.data(102).logicalSrcIdx = 127;
	  section.data(102).dtTransOffset = 103;
	
	  ;% Autonomous_Driving_P.VideoCapture_Tilt
	  section.data(103).logicalSrcIdx = 128;
	  section.data(103).dtTransOffset = 104;
	
	  ;% Autonomous_Driving_P.VideoCapture_Roll
	  section.data(104).logicalSrcIdx = 129;
	  section.data(104).dtTransOffset = 105;
	
	  ;% Autonomous_Driving_P.VideoCapture_Zoom
	  section.data(105).logicalSrcIdx = 130;
	  section.data(105).dtTransOffset = 106;
	
	  ;% Autonomous_Driving_P.VideoCapture_Exposure
	  section.data(106).logicalSrcIdx = 131;
	  section.data(106).dtTransOffset = 107;
	
	  ;% Autonomous_Driving_P.VideoCapture_Iris
	  section.data(107).logicalSrcIdx = 132;
	  section.data(107).dtTransOffset = 108;
	
	  ;% Autonomous_Driving_P.VideoCapture_Focus
	  section.data(108).logicalSrcIdx = 133;
	  section.data(108).dtTransOffset = 109;
	
	  ;% Autonomous_Driving_P.ImageTransform_MinPixel
	  section.data(109).logicalSrcIdx = 134;
	  section.data(109).dtTransOffset = 110;
	
	  ;% Autonomous_Driving_P.ImageTransform_MaxPixel
	  section.data(110).logicalSrcIdx = 135;
	  section.data(110).dtTransOffset = 111;
	
	  ;% Autonomous_Driving_P.ImageTransform_FocalLen
	  section.data(111).logicalSrcIdx = 136;
	  section.data(111).dtTransOffset = 112;
	
	  ;% Autonomous_Driving_P.ImageTransform_Extrapolated
	  section.data(112).logicalSrcIdx = 137;
	  section.data(112).dtTransOffset = 113;
	
	  ;% Autonomous_Driving_P.ImageTransform_Angle
	  section.data(113).logicalSrcIdx = 138;
	  section.data(113).dtTransOffset = 114;
	
	  ;% Autonomous_Driving_P.ImageTransform_RCoeff
	  section.data(114).logicalSrcIdx = 139;
	  section.data(114).dtTransOffset = 115;
	
	  ;% Autonomous_Driving_P.HueMin_Value
	  section.data(115).logicalSrcIdx = 140;
	  section.data(115).dtTransOffset = 117;
	
	  ;% Autonomous_Driving_P.HueMax_Value
	  section.data(116).logicalSrcIdx = 141;
	  section.data(116).dtTransOffset = 118;
	
	  ;% Autonomous_Driving_P.Gain_Gain_d
	  section.data(117).logicalSrcIdx = 142;
	  section.data(117).dtTransOffset = 119;
	
	  ;% Autonomous_Driving_P.u0_Gain
	  section.data(118).logicalSrcIdx = 143;
	  section.data(118).dtTransOffset = 120;
	
	  ;% Autonomous_Driving_P.Constant_Value_ih
	  section.data(119).logicalSrcIdx = 144;
	  section.data(119).dtTransOffset = 121;
	
	  ;% Autonomous_Driving_P.Gain1_Gain
	  section.data(120).logicalSrcIdx = 145;
	  section.data(120).dtTransOffset = 122;
	
	  ;% Autonomous_Driving_P.Constant7_Value
	  section.data(121).logicalSrcIdx = 146;
	  section.data(121).dtTransOffset = 123;
	
	  ;% Autonomous_Driving_P.Gain6_Gain
	  section.data(122).logicalSrcIdx = 147;
	  section.data(122).dtTransOffset = 124;
	
	  ;% Autonomous_Driving_P.SatMin_Value
	  section.data(123).logicalSrcIdx = 148;
	  section.data(123).dtTransOffset = 125;
	
	  ;% Autonomous_Driving_P.SatMax_Value
	  section.data(124).logicalSrcIdx = 149;
	  section.data(124).dtTransOffset = 126;
	
	  ;% Autonomous_Driving_P.Gain2_Gain
	  section.data(125).logicalSrcIdx = 150;
	  section.data(125).dtTransOffset = 127;
	
	  ;% Autonomous_Driving_P.u01_Gain
	  section.data(126).logicalSrcIdx = 151;
	  section.data(126).dtTransOffset = 128;
	
	  ;% Autonomous_Driving_P.Constant1_Value_o
	  section.data(127).logicalSrcIdx = 152;
	  section.data(127).dtTransOffset = 129;
	
	  ;% Autonomous_Driving_P.Gain3_Gain
	  section.data(128).logicalSrcIdx = 153;
	  section.data(128).dtTransOffset = 130;
	
	  ;% Autonomous_Driving_P.Constant6_Value_l
	  section.data(129).logicalSrcIdx = 154;
	  section.data(129).dtTransOffset = 131;
	
	  ;% Autonomous_Driving_P.ValMin_Value
	  section.data(130).logicalSrcIdx = 155;
	  section.data(130).dtTransOffset = 132;
	
	  ;% Autonomous_Driving_P.ValMax_Value
	  section.data(131).logicalSrcIdx = 156;
	  section.data(131).dtTransOffset = 133;
	
	  ;% Autonomous_Driving_P.Gain4_Gain
	  section.data(132).logicalSrcIdx = 157;
	  section.data(132).dtTransOffset = 134;
	
	  ;% Autonomous_Driving_P.u02_Gain
	  section.data(133).logicalSrcIdx = 158;
	  section.data(133).dtTransOffset = 135;
	
	  ;% Autonomous_Driving_P.Constant2_Value_a
	  section.data(134).logicalSrcIdx = 159;
	  section.data(134).dtTransOffset = 136;
	
	  ;% Autonomous_Driving_P.Gain5_Gain
	  section.data(135).logicalSrcIdx = 160;
	  section.data(135).dtTransOffset = 137;
	
	  ;% Autonomous_Driving_P.Constant5_Value_b
	  section.data(136).logicalSrcIdx = 161;
	  section.data(136).dtTransOffset = 138;
	
	  ;% Autonomous_Driving_P.Saturation_UpperSat_i
	  section.data(137).logicalSrcIdx = 162;
	  section.data(137).dtTransOffset = 139;
	
	  ;% Autonomous_Driving_P.Saturation_LowerSat_g
	  section.data(138).logicalSrcIdx = 163;
	  section.data(138).dtTransOffset = 142;
	
	  ;% Autonomous_Driving_P.Gain7_Gain
	  section.data(139).logicalSrcIdx = 164;
	  section.data(139).dtTransOffset = 145;
	
	  ;% Autonomous_Driving_P.Saturation1_UpperSat_d
	  section.data(140).logicalSrcIdx = 165;
	  section.data(140).dtTransOffset = 146;
	
	  ;% Autonomous_Driving_P.Saturation1_LowerSat_o
	  section.data(141).logicalSrcIdx = 166;
	  section.data(141).dtTransOffset = 149;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_Channel0Mi
	  section.data(142).logicalSrcIdx = 167;
	  section.data(142).dtTransOffset = 152;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_Channel0Ma
	  section.data(143).logicalSrcIdx = 168;
	  section.data(143).dtTransOffset = 153;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_Channel1Mi
	  section.data(144).logicalSrcIdx = 169;
	  section.data(144).dtTransOffset = 154;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_Channel1Ma
	  section.data(145).logicalSrcIdx = 170;
	  section.data(145).dtTransOffset = 155;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_Channel2Mi
	  section.data(146).logicalSrcIdx = 171;
	  section.data(146).dtTransOffset = 156;
	
	  ;% Autonomous_Driving_P.HSVColorThresholding_Channel2Ma
	  section.data(147).logicalSrcIdx = 172;
	  section.data(147).dtTransOffset = 157;
	
	  ;% Autonomous_Driving_P.Constant4_Value_a
	  section.data(148).logicalSrcIdx = 173;
	  section.data(148).dtTransOffset = 158;
	
	  ;% Autonomous_Driving_P.Gain_Gain_a
	  section.data(149).logicalSrcIdx = 174;
	  section.data(149).dtTransOffset = 159;
	
	  ;% Autonomous_Driving_P.Bias_Bias
	  section.data(150).logicalSrcIdx = 175;
	  section.data(150).dtTransOffset = 160;
	
	  ;% Autonomous_Driving_P.Constant3_Value_br
	  section.data(151).logicalSrcIdx = 176;
	  section.data(151).dtTransOffset = 161;
	
	  ;% Autonomous_Driving_P.m_n_Value
	  section.data(152).logicalSrcIdx = 177;
	  section.data(152).dtTransOffset = 162;
	
	  ;% Autonomous_Driving_P.b_n_Value_p
	  section.data(153).logicalSrcIdx = 178;
	  section.data(153).dtTransOffset = 163;
	
	  ;% Autonomous_Driving_P.SteeringSaturation1_UpperSat
	  section.data(154).logicalSrcIdx = 179;
	  section.data(154).dtTransOffset = 164;
	
	  ;% Autonomous_Driving_P.SteeringSaturation1_LowerSat
	  section.data(155).logicalSrcIdx = 180;
	  section.data(155).dtTransOffset = 165;
	
	  ;% Autonomous_Driving_P.Depth_Brightness
	  section.data(156).logicalSrcIdx = 181;
	  section.data(156).dtTransOffset = 166;
	
	  ;% Autonomous_Driving_P.Depth_Contrast
	  section.data(157).logicalSrcIdx = 182;
	  section.data(157).dtTransOffset = 167;
	
	  ;% Autonomous_Driving_P.Depth_Hue
	  section.data(158).logicalSrcIdx = 183;
	  section.data(158).dtTransOffset = 168;
	
	  ;% Autonomous_Driving_P.Depth_Saturation
	  section.data(159).logicalSrcIdx = 184;
	  section.data(159).dtTransOffset = 169;
	
	  ;% Autonomous_Driving_P.Depth_Sharpness
	  section.data(160).logicalSrcIdx = 185;
	  section.data(160).dtTransOffset = 170;
	
	  ;% Autonomous_Driving_P.Depth_Gamma
	  section.data(161).logicalSrcIdx = 186;
	  section.data(161).dtTransOffset = 171;
	
	  ;% Autonomous_Driving_P.Depth_WhiteBalance
	  section.data(162).logicalSrcIdx = 187;
	  section.data(162).dtTransOffset = 172;
	
	  ;% Autonomous_Driving_P.Depth_BacklightCompensation
	  section.data(163).logicalSrcIdx = 188;
	  section.data(163).dtTransOffset = 173;
	
	  ;% Autonomous_Driving_P.Depth_Gain
	  section.data(164).logicalSrcIdx = 189;
	  section.data(164).dtTransOffset = 174;
	
	  ;% Autonomous_Driving_P.Depth_Exposure
	  section.data(165).logicalSrcIdx = 190;
	  section.data(165).dtTransOffset = 175;
	
	  ;% Autonomous_Driving_P.Depth_Emitter
	  section.data(166).logicalSrcIdx = 191;
	  section.data(166).dtTransOffset = 176;
	
	  ;% Autonomous_Driving_P.StoppingDistancem_Value
	  section.data(167).logicalSrcIdx = 192;
	  section.data(167).dtTransOffset = 177;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 193;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 194;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 195;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 196;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 197;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Autonomous_Driving_P.ImageTransform_PrPoint
	  section.data(6).logicalSrcIdx = 198;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_P.ImageTransform_Interpolation
	  section.data(7).logicalSrcIdx = 199;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Autonomous_Driving_P.ImageTransform_Origin
	  section.data(8).logicalSrcIdx = 200;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Autonomous_Driving_P.ImageTransform_OOrigin
	  section.data(9).logicalSrcIdx = 201;
	  section.data(9).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.Gain_Gain_g
	  section.data(1).logicalSrcIdx = 202;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 203;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 204;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 205;
	  section.data(3).dtTransOffset = 27;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 206;
	  section.data(4).dtTransOffset = 28;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 207;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Autonomous_Driving_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 208;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 209;
	  section.data(7).dtTransOffset = 43;
	
	  ;% Autonomous_Driving_P.ImageTransform_ColorTheme
	  section.data(8).logicalSrcIdx = 210;
	  section.data(8).dtTransOffset = 56;
	
	  ;% Autonomous_Driving_P.ImageCompress_Quality
	  section.data(9).logicalSrcIdx = 211;
	  section.data(9).dtTransOffset = 57;
	
	  ;% Autonomous_Driving_P.ImageCompress_Quality_p
	  section.data(10).logicalSrcIdx = 212;
	  section.data(10).dtTransOffset = 58;
	
	  ;% Autonomous_Driving_P.Depth_Preset
	  section.data(11).logicalSrcIdx = 213;
	  section.data(11).dtTransOffset = 59;
	
	  ;% Autonomous_Driving_P.ImageCompress_Quality_k
	  section.data(12).logicalSrcIdx = 214;
	  section.data(12).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 59;
      section.data(59)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 215;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 216;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 217;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 218;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 219;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 220;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Autonomous_Driving_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 221;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 222;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 223;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Autonomous_Driving_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 224;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Autonomous_Driving_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 225;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Autonomous_Driving_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 226;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Autonomous_Driving_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 227;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 228;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 229;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 230;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 231;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Autonomous_Driving_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 232;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 233;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 234;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 235;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 236;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 237;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 238;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 239;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 240;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Autonomous_Driving_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 241;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Autonomous_Driving_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 242;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Autonomous_Driving_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 243;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Autonomous_Driving_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 244;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Autonomous_Driving_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 245;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Autonomous_Driving_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 246;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Autonomous_Driving_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 247;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 248;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Autonomous_Driving_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 249;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Autonomous_Driving_P.HILRead_Active
	  section.data(36).logicalSrcIdx = 250;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Autonomous_Driving_P.SteadyLight_Value
	  section.data(37).logicalSrcIdx = 251;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Autonomous_Driving_P.LightOff_Value
	  section.data(38).logicalSrcIdx = 252;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Autonomous_Driving_P.HILWrite_Active
	  section.data(39).logicalSrcIdx = 253;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvBrightness
	  section.data(40).logicalSrcIdx = 254;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvContrast
	  section.data(41).logicalSrcIdx = 255;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvHue
	  section.data(42).logicalSrcIdx = 256;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvSaturation
	  section.data(43).logicalSrcIdx = 257;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvSharpness
	  section.data(44).logicalSrcIdx = 258;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvGamma
	  section.data(45).logicalSrcIdx = 259;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvColorEnable
	  section.data(46).logicalSrcIdx = 260;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvWhiteBalance
	  section.data(47).logicalSrcIdx = 261;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvBacklightCompens
	  section.data(48).logicalSrcIdx = 262;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvGain
	  section.data(49).logicalSrcIdx = 263;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvPan
	  section.data(50).logicalSrcIdx = 264;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvTilt
	  section.data(51).logicalSrcIdx = 265;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvRoll
	  section.data(52).logicalSrcIdx = 266;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvZoom
	  section.data(53).logicalSrcIdx = 267;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvExposure
	  section.data(54).logicalSrcIdx = 268;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvIris
	  section.data(55).logicalSrcIdx = 269;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Autonomous_Driving_P.VideoCapture_OvFocus
	  section.data(56).logicalSrcIdx = 270;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Autonomous_Driving_P.VideoDisplay_UseHardware
	  section.data(57).logicalSrcIdx = 271;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Autonomous_Driving_P.VideoDisplay_UseHardware_b
	  section.data(58).logicalSrcIdx = 272;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Autonomous_Driving_P.VideoDisplay_UseHardware_c
	  section.data(59).logicalSrcIdx = 273;
	  section.data(59).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_P.imageDepthForDisplay_Y0
	  section.data(1).logicalSrcIdx = 274;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_P.uArm0Disarm1_CurrentSetting
	  section.data(2).logicalSrcIdx = 275;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_P.uRight0Left_CurrentSetting
	  section.data(3).logicalSrcIdx = 276;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_P.ManualSwitch_CurrentSetting
	  section.data(4).logicalSrcIdx = 277;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
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
    ;% Auto data (Autonomous_Driving_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_B.Depth_o2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_B.motorcurrent
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_B.batteryvoltage
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_B.encodercounts
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_B.Integrator1
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_B.Integrator1_p
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_B.Unwrap224
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Autonomous_Driving_B.Product
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_B.Product1
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_B.Product_g
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Autonomous_Driving_B.Product1_c
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Autonomous_Driving_B.Product_e
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Autonomous_Driving_B.Product1_a
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Autonomous_Driving_B.RateTransition1
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Autonomous_Driving_B.uArm0Disarm1
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Autonomous_Driving_B.RateTransition
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Autonomous_Driving_B.DesiredSpeedms
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Autonomous_Driving_B.desired
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Autonomous_Driving_B.Kffms
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Autonomous_Driving_B.measured
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Autonomous_Driving_B.pwmdutycycle
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Autonomous_Driving_B.commandsaturation
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Autonomous_Driving_B.Abs
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Autonomous_Driving_B.one_shot_block
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Autonomous_Driving_B.DataTypeConversion1
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Autonomous_Driving_B.Kim
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 31;
	
	  ;% Autonomous_Driving_B.SampleTime
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 32;
	
	  ;% Autonomous_Driving_B.Constant
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 33;
	
	  ;% Autonomous_Driving_B.ComputationTime
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 34;
	
	  ;% Autonomous_Driving_B.RateTransition4
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 35;
	
	  ;% Autonomous_Driving_B.RateTransition3
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 38;
	
	  ;% Autonomous_Driving_B.Subtract1
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 41;
	
	  ;% Autonomous_Driving_B.Subtract3
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 42;
	
	  ;% Autonomous_Driving_B.Subtract5
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 43;
	
	  ;% Autonomous_Driving_B.Saturation
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 44;
	
	  ;% Autonomous_Driving_B.Add2
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 47;
	
	  ;% Autonomous_Driving_B.Add5
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 48;
	
	  ;% Autonomous_Driving_B.Add8
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 49;
	
	  ;% Autonomous_Driving_B.Saturation1
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 50;
	
	  ;% Autonomous_Driving_B.SteeringSaturation1
	  section.data(39).logicalSrcIdx = 39;
	  section.data(39).dtTransOffset = 53;
	
	  ;% Autonomous_Driving_B.Depth_o3
	  section.data(40).logicalSrcIdx = 40;
	  section.data(40).dtTransOffset = 54;
	
	  ;% Autonomous_Driving_B.Multiply
	  section.data(41).logicalSrcIdx = 41;
	  section.data(41).dtTransOffset = 55;
	
	  ;% Autonomous_Driving_B.speed_cmd
	  section.data(42).logicalSrcIdx = 42;
	  section.data(42).dtTransOffset = 56;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_B.Channel
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_B.Channel_b
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_B.Channel_g
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_B.Depth_o1
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_B.VideoCapture_o1
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_B.img_out
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1008600;
	
	  ;% Autonomous_Driving_B.ImageCompress
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 1085640;
	
	  ;% Autonomous_Driving_B.ImageCompress_h
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 1198254;
	
	  ;% Autonomous_Driving_B.ImageCompress_o
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 1366149;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_B.Compare
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_B.AND3
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_B.AND1
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_B.Compare_d
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_B.VideoCapture_o2
	  section.data(5).logicalSrcIdx = 56;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_B.Depth_o4
	  section.data(6).logicalSrcIdx = 57;
	  section.data(6).dtTransOffset = 5;
	
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
    nTotSects     = 16;
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
    ;% Auto data (Autonomous_Driving_DW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.ComputationTime_BeginTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_DW.ComputationTime_ComputationTime
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Autonomous_Driving_DW.SampleTime_PreviousTime_g
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_DW.ComputationTime_BeginTime_b
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_DW.ComputationTime_ComputationTi_o
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Autonomous_Driving_DW.SampleTime_PreviousTime_e
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_DW.ComputationTime_BeginTime_p
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_DW.ComputationTime_ComputationT_om
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.one_shot_block_DSTATE
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_DW.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 10;
	
	  ;% Autonomous_Driving_DW.HILInitialize_FilterFrequency
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 17;
	
	  ;% Autonomous_Driving_DW.HILInitialize_POSortedFreqs
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 22;
	
	  ;% Autonomous_Driving_DW.HILInitialize_POValues
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 30;
	
	  ;% Autonomous_Driving_DW.HILInitialize_OOValues
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 38;
	
	  ;% Autonomous_Driving_DW.HILRead_AnalogBuffer
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 51;
	
	  ;% Autonomous_Driving_DW.Unwrap224_PreviousInput
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 53;
	
	  ;% Autonomous_Driving_DW.Unwrap224_Revolutions
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 54;
	
	  ;% Autonomous_Driving_DW.RateTransition1_Buffer0
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 55;
	
	  ;% Autonomous_Driving_DW.PrevY
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 56;
	
	  ;% Autonomous_Driving_DW.RateTransition_Buffer0
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 57;
	
	  ;% Autonomous_Driving_DW.Memory_PreviousInput
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 58;
	
	  ;% Autonomous_Driving_DW.RateTransition5_Buffer
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 59;
	
	  ;% Autonomous_Driving_DW.RateTransition4_Buffer0
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 60;
	
	  ;% Autonomous_Driving_DW.RateTransition3_Buffer0
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 63;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.ImageCompress_Compress
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.ImageCompress_Compress_c
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_DW.ImageCompress_Compress_cq
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.VideoCapture_VideoCapture
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.Video3DInitialize_Video3D
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.Depth_Video3D
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.Depth_Stream
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.ImageTransform_AlgHandle
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.HILRead_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_DW.HILWrite_PWORK
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Autonomous_Driving_DW.Scope_PWORK_j.LoggedData
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Autonomous_Driving_DW.Scope2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_DW.Scope_PWORK_d.LoggedData
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Autonomous_Driving_DW.Scope_PWORK_a.LoggedData
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Autonomous_Driving_DW.Scope_PWORK_f.LoggedData
	  section.data(8).logicalSrcIdx = 42;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Autonomous_Driving_DW.Channel_PWORK.Fifo
	  section.data(9).logicalSrcIdx = 43;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Autonomous_Driving_DW.Channel_PWORK_b.Fifo
	  section.data(10).logicalSrcIdx = 44;
	  section.data(10).dtTransOffset = 15;
	
	  ;% Autonomous_Driving_DW.Scope_PWORK_b.LoggedData
	  section.data(11).logicalSrcIdx = 45;
	  section.data(11).dtTransOffset = 16;
	
	  ;% Autonomous_Driving_DW.Channel_PWORK_m.Fifo
	  section.data(12).logicalSrcIdx = 46;
	  section.data(12).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Autonomous_Driving_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 11;
	
	  ;% Autonomous_Driving_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Autonomous_Driving_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 27;
	
	  ;% Autonomous_Driving_DW.HILRead_EncoderBuffer
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 35;
	
	  ;% Autonomous_Driving_DW.clockTickCounter
	  section.data(8).logicalSrcIdx = 54;
	  section.data(8).dtTransOffset = 36;
	
	  ;% Autonomous_Driving_DW.ImageCompress_DIMS1
	  section.data(9).logicalSrcIdx = 55;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Autonomous_Driving_DW.ImageCompress_DIMS1_m
	  section.data(10).logicalSrcIdx = 56;
	  section.data(10).dtTransOffset = 38;
	
	  ;% Autonomous_Driving_DW.ImageCompress_DIMS1_g
	  section.data(11).logicalSrcIdx = 57;
	  section.data(11).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.Integrator1_IWORK_p
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Autonomous_Driving_DW.Integrator1_IWORK_o
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.obstacleDetection_SubsysRanBC
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.ImageCompress_ScanLine
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Autonomous_Driving_DW.ImageCompress_ScanLine_d
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 6576;
	
	  ;% Autonomous_Driving_DW.ImageCompress_ScanLine_m
	  section.data(3).logicalSrcIdx = 65;
	  section.data(3).dtTransOffset = 13128;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Autonomous_Driving_DW.HILWrite_DigitalBuffer
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
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


  targMap.checksum0 = 257798187;
  targMap.checksum1 = 1097347280;
  targMap.checksum2 = 185777589;
  targMap.checksum3 = 1962578331;

