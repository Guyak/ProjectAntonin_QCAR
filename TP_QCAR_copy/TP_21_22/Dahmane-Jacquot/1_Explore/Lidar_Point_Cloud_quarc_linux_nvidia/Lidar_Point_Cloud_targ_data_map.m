  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Lidar_Point_Cloud_P)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_maximum_rho
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_maximum_rho
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_maximum_thet
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_maximum_theta
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_minimum_rho
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_minimum_rho
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_minimum_thet
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_minimum_theta
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_direction
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_direction
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_update_rate
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_update_rate
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_zero_locatio
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_zero_location
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 59;
      section.data(59)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.RangingSensor1_Budget
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.RangingSensor1_Period
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.RangingSensor1_MaxInterpolation
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.RangingSensor1_MaxInterpolati_f
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lidar_Point_Cloud_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Width
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 724;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Color
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 725;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1MSize
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 728;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1MEdgeColor
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 729;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1MFaceColor
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 732;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Width
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 735;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Color
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 736;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2MSize
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 739;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2MEdgeColor
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 740;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2MFaceColor
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 743;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Width
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 746;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Color
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 747;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3MSize
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 750;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3MEdgeColor
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 751;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3MFaceColor
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 754;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Width
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 757;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Color
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 758;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4MSize
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 761;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4MEdgeColor
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 762;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4MFaceColor
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 765;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Width
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 768;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Color
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 769;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5MSize
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 772;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5MEdgeColor
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 773;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5MFaceColor
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 776;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1Width
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 779;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1Color
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 780;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1MSize
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 783;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1MEdgeColor
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 784;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1MFaceColor
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 787;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2Width
	  section.data(36).logicalSrcIdx = 49;
	  section.data(36).dtTransOffset = 790;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2Color
	  section.data(37).logicalSrcIdx = 50;
	  section.data(37).dtTransOffset = 791;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2MSize
	  section.data(38).logicalSrcIdx = 51;
	  section.data(38).dtTransOffset = 794;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2MEdgeColor
	  section.data(39).logicalSrcIdx = 52;
	  section.data(39).dtTransOffset = 795;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2MFaceColor
	  section.data(40).logicalSrcIdx = 53;
	  section.data(40).dtTransOffset = 798;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3Width
	  section.data(41).logicalSrcIdx = 54;
	  section.data(41).dtTransOffset = 801;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3Color
	  section.data(42).logicalSrcIdx = 55;
	  section.data(42).dtTransOffset = 802;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3MSize
	  section.data(43).logicalSrcIdx = 56;
	  section.data(43).dtTransOffset = 805;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3MEdgeColor
	  section.data(44).logicalSrcIdx = 57;
	  section.data(44).dtTransOffset = 806;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3MFaceColor
	  section.data(45).logicalSrcIdx = 58;
	  section.data(45).dtTransOffset = 809;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4Width
	  section.data(46).logicalSrcIdx = 59;
	  section.data(46).dtTransOffset = 812;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4Color
	  section.data(47).logicalSrcIdx = 60;
	  section.data(47).dtTransOffset = 813;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4MSize
	  section.data(48).logicalSrcIdx = 61;
	  section.data(48).dtTransOffset = 816;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4MEdgeColor
	  section.data(49).logicalSrcIdx = 62;
	  section.data(49).dtTransOffset = 817;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4MFaceColor
	  section.data(50).logicalSrcIdx = 63;
	  section.data(50).dtTransOffset = 820;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5Width
	  section.data(51).logicalSrcIdx = 64;
	  section.data(51).dtTransOffset = 823;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5Color
	  section.data(52).logicalSrcIdx = 65;
	  section.data(52).dtTransOffset = 824;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5MSize
	  section.data(53).logicalSrcIdx = 66;
	  section.data(53).dtTransOffset = 827;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5MEdgeColor
	  section.data(54).logicalSrcIdx = 67;
	  section.data(54).dtTransOffset = 828;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5MFaceColor
	  section.data(55).logicalSrcIdx = 68;
	  section.data(55).dtTransOffset = 831;
	
	  ;% Lidar_Point_Cloud_P.maximumDistancem_Value
	  section.data(56).logicalSrcIdx = 69;
	  section.data(56).dtTransOffset = 834;
	
	  ;% Lidar_Point_Cloud_P.Constant1_Value_c
	  section.data(57).logicalSrcIdx = 70;
	  section.data(57).dtTransOffset = 835;
	
	  ;% Lidar_Point_Cloud_P.decay_Value
	  section.data(58).logicalSrcIdx = 71;
	  section.data(58).dtTransOffset = 836;
	
	  ;% Lidar_Point_Cloud_P.Constant_Value
	  section.data(59).logicalSrcIdx = 72;
	  section.data(59).dtTransOffset = 837;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Style
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Marker
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Style
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Marker
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Style
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Marker
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Style
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Marker
	  section.data(8).logicalSrcIdx = 80;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Style
	  section.data(9).logicalSrcIdx = 81;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Marker
	  section.data(10).logicalSrcIdx = 82;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1Style
	  section.data(11).logicalSrcIdx = 83;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L1Marker
	  section.data(12).logicalSrcIdx = 84;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2Style
	  section.data(13).logicalSrcIdx = 85;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L2Marker
	  section.data(14).logicalSrcIdx = 86;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3Style
	  section.data(15).logicalSrcIdx = 87;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L3Marker
	  section.data(16).logicalSrcIdx = 88;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4Style
	  section.data(17).logicalSrcIdx = 89;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L4Marker
	  section.data(18).logicalSrcIdx = 90;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5Style
	  section.data(19).logicalSrcIdx = 91;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_L5Marker
	  section.data(20).logicalSrcIdx = 92;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.RangingSensor1_Range
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.RangingSensor1_Active
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.VideoDisplay_UseHardware
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_Mode
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.PolarFigure_Mode
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
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
    nTotSects     = 3;
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
    ;% Auto data (Lidar_Point_Cloud_B)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_B.RangingSensor1_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_B.RangingSensor1_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1300;
	
	  ;% Lidar_Point_Cloud_B.RangingSensor1_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2600;
	
	  ;% Lidar_Point_Cloud_B.RangingSensor1_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3900;
	
	  ;% Lidar_Point_Cloud_B.Constant1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5200;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_B.actualsampletime
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_B.reference
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_B.computationtime
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_B.correctedDistances
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_B.Channel
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 8;
    sectIdxOffset = 3;
    
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
    ;% Auto data (Lidar_Point_Cloud_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.RangingSensor1_Measurements
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.ComputationTime_BeginTime
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_DW.ComputationTime_ComputationTime
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_XBuffer
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_YBuffer
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 720;
	
	  ;% Lidar_Point_Cloud_DW.PolarFigure_XBuffer
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 1440;
	
	  ;% Lidar_Point_Cloud_DW.PolarFigure_YBuffer
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 721440;
	
	  ;% Lidar_Point_Cloud_DW.mapInternal
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 1441440;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.RangingSensor1_Sensor
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.Channel_PWORK.Fifo
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.SFunction_DIMS2
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.SFunction_DIMS3
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_IWORK
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.PolarFigure_IWORK
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_IsFull
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.PolarFigure_IsFull
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_DW.mapInternal_not_empty
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
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


  targMap.checksum0 = 88827182;
  targMap.checksum1 = 2593209677;
  targMap.checksum2 = 3330169660;
  targMap.checksum3 = 3389867906;

