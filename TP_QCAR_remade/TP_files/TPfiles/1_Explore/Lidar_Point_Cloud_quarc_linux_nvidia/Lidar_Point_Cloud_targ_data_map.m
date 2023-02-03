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
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_maximum_rho
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_maximum_thet
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_minimum_rho
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_minimum_thet
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_direction
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_update_rate
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_zero_locatio
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.RangingSensor_Budget
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.RangingSensor_Period
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.RangingSensor_MaxInterpolationD
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.RangingSensor_MaxInterpolationA
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lidar_Point_Cloud_P.ChangetoCCWrotation_Gain
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lidar_Point_Cloud_P.ChangextofrontofQCar_Bias
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Width
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Color
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1MSize
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1MEdgeColor
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1MFaceColor
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Width
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Color
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 18;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2MSize
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 21;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2MEdgeColor
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 22;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2MFaceColor
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 25;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Width
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 28;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Color
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 29;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3MSize
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 32;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3MEdgeColor
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 33;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3MFaceColor
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 36;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Width
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 39;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Color
	  section.data(23).logicalSrcIdx = 29;
	  section.data(23).dtTransOffset = 40;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4MSize
	  section.data(24).logicalSrcIdx = 30;
	  section.data(24).dtTransOffset = 43;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4MEdgeColor
	  section.data(25).logicalSrcIdx = 31;
	  section.data(25).dtTransOffset = 44;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4MFaceColor
	  section.data(26).logicalSrcIdx = 32;
	  section.data(26).dtTransOffset = 47;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Width
	  section.data(27).logicalSrcIdx = 33;
	  section.data(27).dtTransOffset = 50;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Color
	  section.data(28).logicalSrcIdx = 34;
	  section.data(28).dtTransOffset = 51;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5MSize
	  section.data(29).logicalSrcIdx = 35;
	  section.data(29).dtTransOffset = 54;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5MEdgeColor
	  section.data(30).logicalSrcIdx = 36;
	  section.data(30).dtTransOffset = 55;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5MFaceColor
	  section.data(31).logicalSrcIdx = 37;
	  section.data(31).dtTransOffset = 58;
	
	  ;% Lidar_Point_Cloud_P.maximumDistancem_Value
	  section.data(32).logicalSrcIdx = 38;
	  section.data(32).dtTransOffset = 61;
	
	  ;% Lidar_Point_Cloud_P.Constant1_Value
	  section.data(33).logicalSrcIdx = 39;
	  section.data(33).dtTransOffset = 62;
	
	  ;% Lidar_Point_Cloud_P.decay_Value
	  section.data(34).logicalSrcIdx = 40;
	  section.data(34).dtTransOffset = 63;
	
	  ;% Lidar_Point_Cloud_P.Constant_Value
	  section.data(35).logicalSrcIdx = 41;
	  section.data(35).dtTransOffset = 64;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Style
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L1Marker
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Style
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L2Marker
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Style
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L3Marker
	  section.data(6).logicalSrcIdx = 47;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Style
	  section.data(7).logicalSrcIdx = 48;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L4Marker
	  section.data(8).logicalSrcIdx = 49;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Style
	  section.data(9).logicalSrcIdx = 50;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_L5Marker
	  section.data(10).logicalSrcIdx = 51;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.RangingSensor_Range
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.ImageCompress_Quality
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.RangingSensor_Active
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_P.VideoDisplay_UseHardware
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_P.BodyFramePolarPlot_Mode
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
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
    nTotSects     = 4;
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
      
	  ;% Lidar_Point_Cloud_B.RangingSensor_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_B.RangingSensor_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 720;
	
	  ;% Lidar_Point_Cloud_B.RangingSensor_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 1440;
	
	  ;% Lidar_Point_Cloud_B.RangingSensor_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 2160;
	
	  ;% Lidar_Point_Cloud_B.ChangextofrontofQCar
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 2880;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_B.actualsampletime
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_B.reference
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_B.computationtime
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_B.Channel
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_B.ImageCompress
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    sectIdxOffset = 4;
    
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
      
	  ;% Lidar_Point_Cloud_DW.RangingSensor_Measurements
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
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_XBuffer
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_YBuffer
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 720;
	
	  ;% Lidar_Point_Cloud_DW.mapInternal
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 1440;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.ImageCompress_Compress
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.RangingSensor_Sensor
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.Channel_PWORK.Fifo
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.ImageCompress_DIMS1
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.SFunction_DIMS2
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lidar_Point_Cloud_DW.SFunction_DIMS3
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_IWORK
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.ImageCompress_ScanLine
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Lidar_Point_Cloud_DW.BodyFramePolarPlot_IsFull
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lidar_Point_Cloud_DW.mapInternal_not_empty
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
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


  targMap.checksum0 = 1211782789;
  targMap.checksum1 = 1464375443;
  targMap.checksum2 = 2892337515;
  targMap.checksum3 = 3869942092;

