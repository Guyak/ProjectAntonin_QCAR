  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
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
    ;% Auto data (OG_LIDAR_Base_P)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.X_ic
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.Y_ic
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_P.vehicle_length
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% OG_LIDAR_Base_P.yaw_ic
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_maximum_rho
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_maximum_thet
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_minimum_rho
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_minimum_thet
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_direction
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_update_rate
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_zero_locatio
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.HILRead_encoder_channels
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.HILWrite1_other_channels
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_P.HILWrite1_pwm_channels
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 69;
      section.data(69)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.Constant_Value
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOTerminate
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOExit
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOStart
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOEnter
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POFinal
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOFinal
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 6;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AIHigh
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 7;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AILow
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 8;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIFrequency
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 9;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POFrequency
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 10;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POInitial
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 11;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POWatchdog
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 12;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOInitial
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 13;
	
	  ;% OG_LIDAR_Base_P.RangingSensor_Budget
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 14;
	
	  ;% OG_LIDAR_Base_P.RangingSensor_Period
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 15;
	
	  ;% OG_LIDAR_Base_P.RangingSensor_MaxInterpolationD
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 16;
	
	  ;% OG_LIDAR_Base_P.RangingSensor_MaxInterpolationA
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 17;
	
	  ;% OG_LIDAR_Base_P.Constant1_Value
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 18;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1Width
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 738;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1Color
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 739;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1MSize
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 742;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1MEdgeColor
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 743;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1MFaceColor
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 746;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2Width
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 749;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2Color
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 750;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2MSize
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 753;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2MEdgeColor
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 754;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2MFaceColor
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 757;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3Width
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 760;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3Color
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 761;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3MSize
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 764;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3MEdgeColor
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 765;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3MFaceColor
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 768;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4Width
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 771;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4Color
	  section.data(36).logicalSrcIdx = 49;
	  section.data(36).dtTransOffset = 772;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4MSize
	  section.data(37).logicalSrcIdx = 50;
	  section.data(37).dtTransOffset = 775;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4MEdgeColor
	  section.data(38).logicalSrcIdx = 51;
	  section.data(38).dtTransOffset = 776;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4MFaceColor
	  section.data(39).logicalSrcIdx = 52;
	  section.data(39).dtTransOffset = 779;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5Width
	  section.data(40).logicalSrcIdx = 53;
	  section.data(40).dtTransOffset = 782;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5Color
	  section.data(41).logicalSrcIdx = 54;
	  section.data(41).dtTransOffset = 783;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5MSize
	  section.data(42).logicalSrcIdx = 55;
	  section.data(42).dtTransOffset = 786;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5MEdgeColor
	  section.data(43).logicalSrcIdx = 56;
	  section.data(43).dtTransOffset = 787;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5MFaceColor
	  section.data(44).logicalSrcIdx = 57;
	  section.data(44).dtTransOffset = 790;
	
	  ;% OG_LIDAR_Base_P.Constant4_Value
	  section.data(45).logicalSrcIdx = 58;
	  section.data(45).dtTransOffset = 793;
	
	  ;% OG_LIDAR_Base_P.commandsaturation_UpperSat
	  section.data(46).logicalSrcIdx = 59;
	  section.data(46).dtTransOffset = 794;
	
	  ;% OG_LIDAR_Base_P.commandsaturation_LowerSat
	  section.data(47).logicalSrcIdx = 60;
	  section.data(47).dtTransOffset = 795;
	
	  ;% OG_LIDAR_Base_P.Constant_Value_i
	  section.data(48).logicalSrcIdx = 61;
	  section.data(48).dtTransOffset = 796;
	
	  ;% OG_LIDAR_Base_P.Kffms_Gain
	  section.data(49).logicalSrcIdx = 62;
	  section.data(49).dtTransOffset = 797;
	
	  ;% OG_LIDAR_Base_P.Constant2_Value
	  section.data(50).logicalSrcIdx = 63;
	  section.data(50).dtTransOffset = 798;
	
	  ;% OG_LIDAR_Base_P.Integrator2_IC
	  section.data(51).logicalSrcIdx = 64;
	  section.data(51).dtTransOffset = 799;
	
	  ;% OG_LIDAR_Base_P.countstorotations_Gain
	  section.data(52).logicalSrcIdx = 65;
	  section.data(52).dtTransOffset = 800;
	
	  ;% OG_LIDAR_Base_P.gearratios_Gain
	  section.data(53).logicalSrcIdx = 66;
	  section.data(53).dtTransOffset = 801;
	
	  ;% OG_LIDAR_Base_P.rotstorads_Gain
	  section.data(54).logicalSrcIdx = 67;
	  section.data(54).dtTransOffset = 802;
	
	  ;% OG_LIDAR_Base_P.wheelradius_Gain
	  section.data(55).logicalSrcIdx = 68;
	  section.data(55).dtTransOffset = 803;
	
	  ;% OG_LIDAR_Base_P.Kpms_Gain
	  section.data(56).logicalSrcIdx = 69;
	  section.data(56).dtTransOffset = 804;
	
	  ;% OG_LIDAR_Base_P.Integrator1_IC
	  section.data(57).logicalSrcIdx = 70;
	  section.data(57).dtTransOffset = 805;
	
	  ;% OG_LIDAR_Base_P.Integrator1_UpperSat
	  section.data(58).logicalSrcIdx = 71;
	  section.data(58).dtTransOffset = 806;
	
	  ;% OG_LIDAR_Base_P.Integrator1_LowerSat
	  section.data(59).logicalSrcIdx = 72;
	  section.data(59).dtTransOffset = 807;
	
	  ;% OG_LIDAR_Base_P.Motor_commandsat_UpperSat
	  section.data(60).logicalSrcIdx = 73;
	  section.data(60).dtTransOffset = 808;
	
	  ;% OG_LIDAR_Base_P.Motor_commandsat_LowerSat
	  section.data(61).logicalSrcIdx = 74;
	  section.data(61).dtTransOffset = 809;
	
	  ;% OG_LIDAR_Base_P.directionconvention_Gain
	  section.data(62).logicalSrcIdx = 75;
	  section.data(62).dtTransOffset = 810;
	
	  ;% OG_LIDAR_Base_P.commandsaturation_UpperSat_l
	  section.data(63).logicalSrcIdx = 76;
	  section.data(63).dtTransOffset = 811;
	
	  ;% OG_LIDAR_Base_P.commandsaturation_LowerSat_l
	  section.data(64).logicalSrcIdx = 77;
	  section.data(64).dtTransOffset = 812;
	
	  ;% OG_LIDAR_Base_P.SteeringBias_Bias
	  section.data(65).logicalSrcIdx = 78;
	  section.data(65).dtTransOffset = 813;
	
	  ;% OG_LIDAR_Base_P.Constant3_Value
	  section.data(66).logicalSrcIdx = 79;
	  section.data(66).dtTransOffset = 814;
	
	  ;% OG_LIDAR_Base_P.Constant_Value_j
	  section.data(67).logicalSrcIdx = 80;
	  section.data(67).dtTransOffset = 815;
	
	  ;% OG_LIDAR_Base_P.Unwrap224_Modulus
	  section.data(68).logicalSrcIdx = 81;
	  section.data(68).dtTransOffset = 816;
	
	  ;% OG_LIDAR_Base_P.Kim_Gain
	  section.data(69).logicalSrcIdx = 82;
	  section.data(69).dtTransOffset = 817;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIInitial
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POModes
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POConfiguration
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 3;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POAlignment
	  section.data(4).logicalSrcIdx = 86;
	  section.data(4).dtTransOffset = 4;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POPolarity
	  section.data(5).logicalSrcIdx = 87;
	  section.data(5).dtTransOffset = 5;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1Style
	  section.data(6).logicalSrcIdx = 88;
	  section.data(6).dtTransOffset = 6;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L1Marker
	  section.data(7).logicalSrcIdx = 89;
	  section.data(7).dtTransOffset = 7;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2Style
	  section.data(8).logicalSrcIdx = 90;
	  section.data(8).dtTransOffset = 8;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L2Marker
	  section.data(9).logicalSrcIdx = 91;
	  section.data(9).dtTransOffset = 9;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3Style
	  section.data(10).logicalSrcIdx = 92;
	  section.data(10).dtTransOffset = 10;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L3Marker
	  section.data(11).logicalSrcIdx = 93;
	  section.data(11).dtTransOffset = 11;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4Style
	  section.data(12).logicalSrcIdx = 94;
	  section.data(12).dtTransOffset = 12;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L4Marker
	  section.data(13).logicalSrcIdx = 95;
	  section.data(13).dtTransOffset = 13;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5Style
	  section.data(14).logicalSrcIdx = 96;
	  section.data(14).dtTransOffset = 14;
	
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_L5Marker
	  section.data(15).logicalSrcIdx = 97;
	  section.data(15).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.HILInitialize1_AIChannels
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DIChannels
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 7;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOChannels
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 26;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIChannels
	  section.data(4).logicalSrcIdx = 101;
	  section.data(4).dtTransOffset = 27;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIQuadrature
	  section.data(5).logicalSrcIdx = 102;
	  section.data(5).dtTransOffset = 32;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POChannels
	  section.data(6).logicalSrcIdx = 103;
	  section.data(6).dtTransOffset = 34;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOChannels
	  section.data(7).logicalSrcIdx = 104;
	  section.data(7).dtTransOffset = 35;
	
	  ;% OG_LIDAR_Base_P.RangingSensor_Range
	  section.data(8).logicalSrcIdx = 105;
	  section.data(8).dtTransOffset = 48;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.HILInitialize1_Active
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOTerminate
	  section.data(2).logicalSrcIdx = 107;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOExit
	  section.data(3).logicalSrcIdx = 108;
	  section.data(3).dtTransOffset = 2;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOTerminate
	  section.data(4).logicalSrcIdx = 109;
	  section.data(4).dtTransOffset = 3;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOExit
	  section.data(5).logicalSrcIdx = 110;
	  section.data(5).dtTransOffset = 4;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POTerminate
	  section.data(6).logicalSrcIdx = 111;
	  section.data(6).dtTransOffset = 5;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POExit
	  section.data(7).logicalSrcIdx = 112;
	  section.data(7).dtTransOffset = 6;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_CKPStart
	  section.data(8).logicalSrcIdx = 113;
	  section.data(8).dtTransOffset = 7;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_CKPEnter
	  section.data(9).logicalSrcIdx = 114;
	  section.data(9).dtTransOffset = 8;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_CKStart
	  section.data(10).logicalSrcIdx = 115;
	  section.data(10).dtTransOffset = 9;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_CKEnter
	  section.data(11).logicalSrcIdx = 116;
	  section.data(11).dtTransOffset = 10;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AIPStart
	  section.data(12).logicalSrcIdx = 117;
	  section.data(12).dtTransOffset = 11;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AIPEnter
	  section.data(13).logicalSrcIdx = 118;
	  section.data(13).dtTransOffset = 12;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOPStart
	  section.data(14).logicalSrcIdx = 119;
	  section.data(14).dtTransOffset = 13;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOPEnter
	  section.data(15).logicalSrcIdx = 120;
	  section.data(15).dtTransOffset = 14;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOStart
	  section.data(16).logicalSrcIdx = 121;
	  section.data(16).dtTransOffset = 15;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOEnter
	  section.data(17).logicalSrcIdx = 122;
	  section.data(17).dtTransOffset = 16;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_AOReset
	  section.data(18).logicalSrcIdx = 123;
	  section.data(18).dtTransOffset = 17;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOPStart
	  section.data(19).logicalSrcIdx = 124;
	  section.data(19).dtTransOffset = 18;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOPEnter
	  section.data(20).logicalSrcIdx = 125;
	  section.data(20).dtTransOffset = 19;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOStart
	  section.data(21).logicalSrcIdx = 126;
	  section.data(21).dtTransOffset = 20;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOEnter
	  section.data(22).logicalSrcIdx = 127;
	  section.data(22).dtTransOffset = 21;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOReset
	  section.data(23).logicalSrcIdx = 128;
	  section.data(23).dtTransOffset = 22;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIPStart
	  section.data(24).logicalSrcIdx = 129;
	  section.data(24).dtTransOffset = 23;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIPEnter
	  section.data(25).logicalSrcIdx = 130;
	  section.data(25).dtTransOffset = 24;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIStart
	  section.data(26).logicalSrcIdx = 131;
	  section.data(26).dtTransOffset = 25;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_EIEnter
	  section.data(27).logicalSrcIdx = 132;
	  section.data(27).dtTransOffset = 26;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POPStart
	  section.data(28).logicalSrcIdx = 133;
	  section.data(28).dtTransOffset = 27;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POPEnter
	  section.data(29).logicalSrcIdx = 134;
	  section.data(29).dtTransOffset = 28;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POStart
	  section.data(30).logicalSrcIdx = 135;
	  section.data(30).dtTransOffset = 29;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POEnter
	  section.data(31).logicalSrcIdx = 136;
	  section.data(31).dtTransOffset = 30;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_POReset
	  section.data(32).logicalSrcIdx = 137;
	  section.data(32).dtTransOffset = 31;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_OOReset
	  section.data(33).logicalSrcIdx = 138;
	  section.data(33).dtTransOffset = 32;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOFinal
	  section.data(34).logicalSrcIdx = 139;
	  section.data(34).dtTransOffset = 33;
	
	  ;% OG_LIDAR_Base_P.HILInitialize1_DOInitial
	  section.data(35).logicalSrcIdx = 140;
	  section.data(35).dtTransOffset = 34;
	
	  ;% OG_LIDAR_Base_P.RangingSensor_Active
	  section.data(36).logicalSrcIdx = 141;
	  section.data(36).dtTransOffset = 35;
	
	  ;% OG_LIDAR_Base_P.HILWrite1_Active
	  section.data(37).logicalSrcIdx = 142;
	  section.data(37).dtTransOffset = 36;
	
	  ;% OG_LIDAR_Base_P.HILRead_Active
	  section.data(38).logicalSrcIdx = 143;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_P.BodyFramePolarPlot_Mode
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
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
    nTotSects     = 2;
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
    ;% Auto data (OG_LIDAR_Base_B)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_B.RangingSensor_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_B.RangingSensor_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 720;
	
	  ;% OG_LIDAR_Base_B.RangingSensor_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 1440;
	
	  ;% OG_LIDAR_Base_B.RangingSensor_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 2160;
	
	  ;% OG_LIDAR_Base_B.Constant1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 2880;
	
	  ;% OG_LIDAR_Base_B.desired
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 3600;
	
	  ;% OG_LIDAR_Base_B.Kffms
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 3601;
	
	  ;% OG_LIDAR_Base_B.Product1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 3602;
	
	  ;% OG_LIDAR_Base_B.measured
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 3603;
	
	  ;% OG_LIDAR_Base_B.commandsaturation
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 3604;
	
	  ;% OG_LIDAR_Base_B.Integrator
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 3605;
	
	  ;% OG_LIDAR_Base_B.Integrator1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 3606;
	
	  ;% OG_LIDAR_Base_B.psi_headingrad
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 3607;
	
	  ;% OG_LIDAR_Base_B.motorcounts
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 3608;
	
	  ;% OG_LIDAR_Base_B.Unwrap224
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 3609;
	
	  ;% OG_LIDAR_Base_B.Product
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 3610;
	
	  ;% OG_LIDAR_Base_B.psidotrads
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 3611;
	
	  ;% OG_LIDAR_Base_B.v_Xms
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 3612;
	
	  ;% OG_LIDAR_Base_B.v_Yms
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 3613;
	
	  ;% OG_LIDAR_Base_B.Kim
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 3614;
	
	  ;% OG_LIDAR_Base_B.RateTransition
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 3615;
	
	  ;% OG_LIDAR_Base_B.correctedDistances
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 3619;
	
	  ;% OG_LIDAR_Base_B.steering
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 4339;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_B.Compare
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 9;
    sectIdxOffset = 2;
    
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
    ;% Auto data (OG_LIDAR_Base_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.RangingSensor_Measurements
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.AnimationSFunction_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_AIMinimums
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 6;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_AIMaximums
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 13;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_FilterFrequency
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 20;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_POSortedFreqs
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 25;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_POValues
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 26;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_OOValues
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 27;
	
	  ;% OG_LIDAR_Base_DW.BodyFramePolarPlot_XBuffer
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 40;
	
	  ;% OG_LIDAR_Base_DW.BodyFramePolarPlot_YBuffer
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 760;
	
	  ;% OG_LIDAR_Base_DW.Unwrap224_PreviousInput
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 1480;
	
	  ;% OG_LIDAR_Base_DW.Unwrap224_Revolutions
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 1481;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.RangingSensor_Sensor
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.HILInitialize1_Card
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.HILWrite1_PWORK
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_DW.HILRead_PWORK
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.HILInitialize1_DOStates
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_QuadratureModes
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% OG_LIDAR_Base_DW.HILInitialize1_InitialEICounts
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 6;
	
	  ;% OG_LIDAR_Base_DW.HILRead_EncoderBuffer
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.HILInitialize1_POSortedChans
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.BodyFramePolarPlot_IWORK
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_DW.Integrator1_IWORK
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% OG_LIDAR_Base_DW.BodyFramePolarPlot_IsFull
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% OG_LIDAR_Base_DW.Unwrap224_FirstSample
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 2397116534;
  targMap.checksum1 = 2255181284;
  targMap.checksum2 = 345482519;
  targMap.checksum3 = 736530755;

