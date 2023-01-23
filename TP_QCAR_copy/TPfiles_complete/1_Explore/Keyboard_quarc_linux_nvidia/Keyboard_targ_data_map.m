  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Keyboard_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Keyboard_P.HILRead_analog_channels
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_P.HILWrite_digital_channels
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Keyboard_P.HILRead_encoder_channels
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Keyboard_P.HILWrite_other_channels
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Keyboard_P.HILWrite_pwm_channels
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% Keyboard_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Keyboard_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Keyboard_P.HILInitialize_POFinal
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Keyboard_P.HILInitialize_OOFinal
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Keyboard_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Keyboard_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Keyboard_P.HILInitialize_EIFrequency
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Keyboard_P.HILInitialize_POFrequency
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Keyboard_P.HILInitialize_POInitial
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Keyboard_P.HILInitialize_POWatchdog
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Keyboard_P.HILInitialize_OOInitial
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Keyboard_P.Constant1_Value
	  section.data(14).logicalSrcIdx = 18;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Keyboard_P.Constant2_Value
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Keyboard_P.Constant3_Value
	  section.data(16).logicalSrcIdx = 20;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Keyboard_P.Constant4_Value
	  section.data(17).logicalSrcIdx = 21;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Keyboard_P.Constant5_Value
	  section.data(18).logicalSrcIdx = 22;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Keyboard_P.Constant6_Value
	  section.data(19).logicalSrcIdx = 23;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Keyboard_P.Constant_Value
	  section.data(20).logicalSrcIdx = 24;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Keyboard_P.Unwrap224_Modulus
	  section.data(21).logicalSrcIdx = 25;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Keyboard_P.Integrator2_IC
	  section.data(22).logicalSrcIdx = 26;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Keyboard_P.Constant_Value_b
	  section.data(23).logicalSrcIdx = 27;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Keyboard_P.Integrator2_IC_o
	  section.data(24).logicalSrcIdx = 28;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Keyboard_P.Constant_Value_bi
	  section.data(25).logicalSrcIdx = 29;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Keyboard_P.Integrator2_IC_n
	  section.data(26).logicalSrcIdx = 30;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Keyboard_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 31;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Keyboard_P.Gain1_Gain
	  section.data(28).logicalSrcIdx = 32;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Keyboard_P.directionconvention_Gain
	  section.data(29).logicalSrcIdx = 33;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Keyboard_P.commandsaturation_UpperSat
	  section.data(30).logicalSrcIdx = 34;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Keyboard_P.commandsaturation_LowerSat
	  section.data(31).logicalSrcIdx = 35;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Keyboard_P.coastON_Value
	  section.data(32).logicalSrcIdx = 36;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Keyboard_P.Gain2_Gain
	  section.data(33).logicalSrcIdx = 37;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Keyboard_P.Gain3_Gain
	  section.data(34).logicalSrcIdx = 38;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Keyboard_P.Gain_Gain_b
	  section.data(35).logicalSrcIdx = 39;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Keyboard_P.SteeringBias_Bias
	  section.data(36).logicalSrcIdx = 40;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Keyboard_P.Constant2_Value_h
	  section.data(37).logicalSrcIdx = 41;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Keyboard_P.Constant3_Value_k
	  section.data(38).logicalSrcIdx = 42;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Keyboard_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Keyboard_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 46;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Keyboard_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 47;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Keyboard_P.HostInitialize_SendBufferSize
	  section.data(6).logicalSrcIdx = 48;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Keyboard_P.HostInitialize_ReceiveBufferSiz
	  section.data(7).logicalSrcIdx = 49;
	  section.data(7).dtTransOffset = 7;
	
	  ;% Keyboard_P.HostInitialize_ThreadPriority
	  section.data(8).logicalSrcIdx = 50;
	  section.data(8).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Keyboard_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Keyboard_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 26;
	
	  ;% Keyboard_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 27;
	
	  ;% Keyboard_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 32;
	
	  ;% Keyboard_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 34;
	
	  ;% Keyboard_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 57;
	  section.data(7).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% Keyboard_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Keyboard_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Keyboard_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 62;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Keyboard_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 63;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Keyboard_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 64;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Keyboard_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 65;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Keyboard_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 66;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Keyboard_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 67;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Keyboard_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 68;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Keyboard_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 69;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Keyboard_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 70;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Keyboard_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 71;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Keyboard_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 72;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Keyboard_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 73;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Keyboard_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 74;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Keyboard_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 75;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Keyboard_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 76;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Keyboard_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 77;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Keyboard_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 78;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Keyboard_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 79;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Keyboard_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 80;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Keyboard_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 81;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Keyboard_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 82;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Keyboard_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 83;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Keyboard_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 84;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Keyboard_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 85;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Keyboard_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 86;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Keyboard_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 87;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Keyboard_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 88;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Keyboard_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 89;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Keyboard_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 90;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Keyboard_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 91;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Keyboard_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 92;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Keyboard_P.HILRead_Active
	  section.data(36).logicalSrcIdx = 93;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Keyboard_P.HostKeyboard_Enabled
	  section.data(37).logicalSrcIdx = 94;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Keyboard_P.HostKeyboard_DebugMode
	  section.data(38).logicalSrcIdx = 95;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Keyboard_P.HILWrite_Active
	  section.data(39).logicalSrcIdx = 96;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Keyboard_P.HostInitialize_RunClient
	  section.data(40).logicalSrcIdx = 97;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Keyboard_P.HostInitialize_UseWindow
	  section.data(41).logicalSrcIdx = 98;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Keyboard_P.HostInitialize_Active
	  section.data(42).logicalSrcIdx = 99;
	  section.data(42).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Keyboard_P.HostKeyboard_ScanCodes
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Keyboard_P.ManualSwitch1_CurrentSetting
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Keyboard_P.ManualSwitch2_CurrentSetting
	  section.data(4).logicalSrcIdx = 103;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Keyboard_P.ManualSwitch3_CurrentSetting
	  section.data(5).logicalSrcIdx = 104;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Keyboard_P.ManualSwitch4_CurrentSetting
	  section.data(6).logicalSrcIdx = 105;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Keyboard_P.ManualSwitch5_CurrentSetting
	  section.data(7).logicalSrcIdx = 106;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Keyboard_P.ManualSwitch6_CurrentSetting
	  section.data(8).logicalSrcIdx = 107;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Keyboard_P.ManualSwitch7_CurrentSetting
	  section.data(9).logicalSrcIdx = 108;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Keyboard_P.HostInitialize_URI
	  section.data(10).logicalSrcIdx = 109;
	  section.data(10).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Auto data (Keyboard_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Keyboard_B.motorcurrent
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_B.batteryvoltage
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_B.encodercounts
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Keyboard_B.Unwrap224
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Keyboard_B.Product
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Keyboard_B.Product1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Keyboard_B.Integrator1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Keyboard_B.Product_h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Keyboard_B.Product1_e
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Keyboard_B.Integrator1_o
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Keyboard_B.Product_j
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Keyboard_B.Product1_m
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_B.HostInitialize_o2
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_B.HostInitialize_o1
	  section.data(1).logicalSrcIdx = 13;
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
    nTotSects     = 11;
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
    ;% Auto data (Keyboard_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HostKeyboard_Lock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HostKeyboard_KeyboardState
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Keyboard_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 14;
	
	  ;% Keyboard_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 19;
	
	  ;% Keyboard_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 20;
	
	  ;% Keyboard_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 21;
	
	  ;% Keyboard_DW.HILRead_AnalogBuffer
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 34;
	
	  ;% Keyboard_DW.Unwrap224_PreviousInput
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 36;
	
	  ;% Keyboard_DW.Unwrap224_Revolutions
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HostInitialize_ConnectedHandle
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HILRead_PWORK
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_DW.HILWrite_PWORK
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_DW.HostInitialize_PWORK
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Keyboard_DW.HILRead_EncoderBuffer
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Keyboard_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_DW.Integrator1_IWORK_d
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Keyboard_DW.Integrator1_IWORK_c
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Keyboard_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Keyboard_DW.HostKeyboard_NewData
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Keyboard_DW.HILWrite_DigitalBuffer
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
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


  targMap.checksum0 = 3658771018;
  targMap.checksum1 = 4030026030;
  targMap.checksum2 = 1248826225;
  targMap.checksum3 = 3825146976;

