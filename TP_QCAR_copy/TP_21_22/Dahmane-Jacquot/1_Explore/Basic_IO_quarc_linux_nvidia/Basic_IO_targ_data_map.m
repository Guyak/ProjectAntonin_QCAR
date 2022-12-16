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
    ;% Auto data (Basic_IO_P)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Basic_IO_P.Throttle02to02_gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.Steeringrad05to05_gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Basic_IO_P.HILRead_analog_channels
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.HILWrite_digital_channels
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Basic_IO_P.HILRead_encoder_channels
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Basic_IO_P.HILRead_other_channels
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Basic_IO_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Basic_IO_P.HILWrite_pwm_channels
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% Basic_IO_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Basic_IO_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Basic_IO_P.HILInitialize_POFinal
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Basic_IO_P.HILInitialize_OOFinal
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Basic_IO_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Basic_IO_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Basic_IO_P.HILInitialize_EIFrequency
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Basic_IO_P.HILInitialize_POFrequency
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Basic_IO_P.HILInitialize_POInitial
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Basic_IO_P.HILInitialize_POWatchdog
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Basic_IO_P.HILInitialize_OOInitial
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Basic_IO_P.Integrator1_IC
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Basic_IO_P.Constant1_Value
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Basic_IO_P.Constant2_Value
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Basic_IO_P.Constant3_Value
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Basic_IO_P.Constant4_Value
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Basic_IO_P.Constant5_Value
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Basic_IO_P.Constant6_Value
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Basic_IO_P.Constant7_Value
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Basic_IO_P.Constant8_Value
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Basic_IO_P.Constant_Value
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Basic_IO_P.Unwrap224_Modulus
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Basic_IO_P.Integrator2_IC
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Basic_IO_P.Constant_Value_b
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Basic_IO_P.Integrator2_IC_o
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Basic_IO_P.Constant_Value_bi
	  section.data(28).logicalSrcIdx = 35;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Basic_IO_P.Integrator2_IC_n
	  section.data(29).logicalSrcIdx = 36;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Basic_IO_P.Constant_Value_d
	  section.data(30).logicalSrcIdx = 37;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Basic_IO_P.Integrator2_IC_b
	  section.data(31).logicalSrcIdx = 38;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Basic_IO_P.Constant1_Value_k
	  section.data(32).logicalSrcIdx = 39;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Basic_IO_P.directionconvention_Gain
	  section.data(33).logicalSrcIdx = 40;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Basic_IO_P.commandsaturation_UpperSat
	  section.data(34).logicalSrcIdx = 41;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Basic_IO_P.commandsaturation_LowerSat
	  section.data(35).logicalSrcIdx = 42;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Basic_IO_P.coastON_Value
	  section.data(36).logicalSrcIdx = 43;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Basic_IO_P.Gain_Gain
	  section.data(37).logicalSrcIdx = 44;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Basic_IO_P.SteeringBias_Bias
	  section.data(38).logicalSrcIdx = 45;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Basic_IO_P.Constant2_Value_h
	  section.data(39).logicalSrcIdx = 46;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Basic_IO_P.Constant3_Value_k
	  section.data(40).logicalSrcIdx = 47;
	  section.data(40).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Basic_IO_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Basic_IO_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Basic_IO_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Basic_IO_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Basic_IO_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 26;
	
	  ;% Basic_IO_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 27;
	
	  ;% Basic_IO_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 32;
	
	  ;% Basic_IO_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 34;
	
	  ;% Basic_IO_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 59;
	  section.data(7).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% Basic_IO_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Basic_IO_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Basic_IO_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Basic_IO_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Basic_IO_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Basic_IO_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 67;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Basic_IO_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 68;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Basic_IO_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 69;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Basic_IO_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 70;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Basic_IO_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 71;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Basic_IO_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 72;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Basic_IO_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 73;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Basic_IO_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 74;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Basic_IO_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 75;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Basic_IO_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 76;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Basic_IO_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 77;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Basic_IO_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 78;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Basic_IO_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 79;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Basic_IO_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 80;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Basic_IO_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 81;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Basic_IO_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 82;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Basic_IO_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 83;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Basic_IO_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 84;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Basic_IO_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 85;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Basic_IO_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 86;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Basic_IO_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 87;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Basic_IO_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 88;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Basic_IO_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 89;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Basic_IO_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 90;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Basic_IO_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 91;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Basic_IO_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 92;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Basic_IO_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 93;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Basic_IO_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 94;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Basic_IO_P.HILRead_Active
	  section.data(36).logicalSrcIdx = 95;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Basic_IO_P.HILWrite_Active
	  section.data(37).logicalSrcIdx = 96;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Basic_IO_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 98;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_P.ManualSwitch2_CurrentSetting
	  section.data(3).logicalSrcIdx = 99;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Basic_IO_P.ManualSwitch3_CurrentSetting
	  section.data(4).logicalSrcIdx = 100;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Basic_IO_P.ManualSwitch4_CurrentSetting
	  section.data(5).logicalSrcIdx = 101;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Basic_IO_P.ManualSwitch5_CurrentSetting
	  section.data(6).logicalSrcIdx = 102;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Basic_IO_P.ManualSwitch6_CurrentSetting
	  section.data(7).logicalSrcIdx = 103;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Basic_IO_P.ManualSwitch7_CurrentSetting
	  section.data(8).logicalSrcIdx = 104;
	  section.data(8).dtTransOffset = 7;
	
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
    nTotSects     = 1;
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
    ;% Auto data (Basic_IO_B)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% Basic_IO_B.headingpositiongyroscope
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_B.motorcurrent
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_B.batteryvoltage
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Basic_IO_B.encodercounts
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Basic_IO_B.HILRead_o4
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Basic_IO_B.Unwrap224
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Basic_IO_B.Product
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Basic_IO_B.Product1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Basic_IO_B.Integrator1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Basic_IO_B.Product_h
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Basic_IO_B.Product1_e
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Basic_IO_B.Integrator1_o
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Basic_IO_B.Product_j
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Basic_IO_B.Product1_m
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Basic_IO_B.Integrator1_p
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Basic_IO_B.Product_e
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Basic_IO_B.Product1_n
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    sectIdxOffset = 1;
    
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
    ;% Auto data (Basic_IO_DW)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Basic_IO_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 14;
	
	  ;% Basic_IO_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% Basic_IO_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% Basic_IO_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% Basic_IO_DW.HILRead_AnalogBuffer
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 34;
	
	  ;% Basic_IO_DW.HILRead_OtherBuffer
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 36;
	
	  ;% Basic_IO_DW.Unwrap224_PreviousInput
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Basic_IO_DW.Unwrap224_Revolutions
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.HILRead_PWORK
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_DW.HILWrite_PWORK
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Basic_IO_DW.HILRead_EncoderBuffer
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Basic_IO_DW.Integrator1_IWORK_d
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Basic_IO_DW.Integrator1_IWORK_c
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Basic_IO_DW.Integrator1_IWORK_j
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Basic_IO_DW.HILWrite_DigitalBuffer
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
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


  targMap.checksum0 = 1805362737;
  targMap.checksum1 = 3093291923;
  targMap.checksum2 = 2073862745;
  targMap.checksum3 = 1326174660;

