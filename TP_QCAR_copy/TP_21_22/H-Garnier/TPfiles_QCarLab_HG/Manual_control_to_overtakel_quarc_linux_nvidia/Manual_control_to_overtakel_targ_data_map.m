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
    ;% Auto data (Manual_control_to_overtakel_P)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_P.X_ic
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_P.Y_ic
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_P.vehicle_length
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_control_to_overtakel_P.x0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_control_to_overtakel_P.xg
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Manual_control_to_overtakel_P.yaw_ic
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Manual_control_to_overtakel_P.Bicycle_accel
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Manual_control_to_overtakel_P.Bicycle_alim
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Manual_control_to_overtakel_P.arewethereyet_const
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Manual_control_to_overtakel_P.Bicycle_steer_rate
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Manual_control_to_overtakel_P.Bicycle_vlim
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_P.HILRead_encoder_channels
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_P.HILWrite1_other_channels
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_P.HILWrite1_pwm_channels
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_P.Constant_Value
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOTerminate
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOExit
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOStart
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOEnter
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POFinal
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOFinal
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AIHigh
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AILow
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIFrequency
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POFrequency
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POInitial
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POWatchdog
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOInitial
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Manual_control_to_overtakel_P.steeringratelimit_IC
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Manual_control_to_overtakel_P.accelerationlimit_IC
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Manual_control_to_overtakel_P.velocitygainKv_Gain
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Manual_control_to_overtakel_P.commandsaturation_UpperSat
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Manual_control_to_overtakel_P.commandsaturation_LowerSat
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Manual_control_to_overtakel_P.Constant4_Value
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Manual_control_to_overtakel_P.Kffms_Gain
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Manual_control_to_overtakel_P.Constant2_Value
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Manual_control_to_overtakel_P.Integrator2_IC
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Manual_control_to_overtakel_P.countstorotations_Gain
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Manual_control_to_overtakel_P.gearratios_Gain
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Manual_control_to_overtakel_P.rotstorads_Gain
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Manual_control_to_overtakel_P.wheelradius_Gain
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Manual_control_to_overtakel_P.Offset_Gain
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Manual_control_to_overtakel_P.Kpms_Gain
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Manual_control_to_overtakel_P.Integrator1_IC
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Manual_control_to_overtakel_P.Integrator1_UpperSat
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Manual_control_to_overtakel_P.Integrator1_LowerSat
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Manual_control_to_overtakel_P.Motor_commandsat_UpperSat
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Manual_control_to_overtakel_P.Motor_commandsat_LowerSat
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Manual_control_to_overtakel_P.directionconvention_Gain
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Manual_control_to_overtakel_P.commandsaturation_UpperSat_e
	  section.data(36).logicalSrcIdx = 49;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Manual_control_to_overtakel_P.commandsaturation_LowerSat_k
	  section.data(37).logicalSrcIdx = 50;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Manual_control_to_overtakel_P.Constant3_Value
	  section.data(38).logicalSrcIdx = 51;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Manual_control_to_overtakel_P.Gain_Gain
	  section.data(39).logicalSrcIdx = 52;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Manual_control_to_overtakel_P.Constant_Value_n
	  section.data(40).logicalSrcIdx = 53;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Manual_control_to_overtakel_P.Unwrap224_Modulus
	  section.data(41).logicalSrcIdx = 54;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Manual_control_to_overtakel_P.Kim_Gain
	  section.data(42).logicalSrcIdx = 55;
	  section.data(42).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIInitial
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POModes
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POConfiguration
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POAlignment
	  section.data(4).logicalSrcIdx = 59;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POPolarity
	  section.data(5).logicalSrcIdx = 60;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AIChannels
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DIChannels
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOChannels
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 27;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIChannels
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 28;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIQuadrature
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POChannels
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOChannels
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_P.HILInitialize1_Active
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOTerminate
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOExit
	  section.data(3).logicalSrcIdx = 70;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOTerminate
	  section.data(4).logicalSrcIdx = 71;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOExit
	  section.data(5).logicalSrcIdx = 72;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POTerminate
	  section.data(6).logicalSrcIdx = 73;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POExit
	  section.data(7).logicalSrcIdx = 74;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_CKPStart
	  section.data(8).logicalSrcIdx = 75;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_CKPEnter
	  section.data(9).logicalSrcIdx = 76;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_CKStart
	  section.data(10).logicalSrcIdx = 77;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_CKEnter
	  section.data(11).logicalSrcIdx = 78;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AIPStart
	  section.data(12).logicalSrcIdx = 79;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AIPEnter
	  section.data(13).logicalSrcIdx = 80;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOPStart
	  section.data(14).logicalSrcIdx = 81;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOPEnter
	  section.data(15).logicalSrcIdx = 82;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOStart
	  section.data(16).logicalSrcIdx = 83;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOEnter
	  section.data(17).logicalSrcIdx = 84;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_AOReset
	  section.data(18).logicalSrcIdx = 85;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOPStart
	  section.data(19).logicalSrcIdx = 86;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOPEnter
	  section.data(20).logicalSrcIdx = 87;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOStart
	  section.data(21).logicalSrcIdx = 88;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOEnter
	  section.data(22).logicalSrcIdx = 89;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOReset
	  section.data(23).logicalSrcIdx = 90;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIPStart
	  section.data(24).logicalSrcIdx = 91;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIPEnter
	  section.data(25).logicalSrcIdx = 92;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIStart
	  section.data(26).logicalSrcIdx = 93;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_EIEnter
	  section.data(27).logicalSrcIdx = 94;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POPStart
	  section.data(28).logicalSrcIdx = 95;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POPEnter
	  section.data(29).logicalSrcIdx = 96;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POStart
	  section.data(30).logicalSrcIdx = 97;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POEnter
	  section.data(31).logicalSrcIdx = 98;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_POReset
	  section.data(32).logicalSrcIdx = 99;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_OOReset
	  section.data(33).logicalSrcIdx = 100;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOFinal
	  section.data(34).logicalSrcIdx = 101;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Manual_control_to_overtakel_P.HILInitialize1_DOInitial
	  section.data(35).logicalSrcIdx = 102;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Manual_control_to_overtakel_P.HILWrite1_Active
	  section.data(36).logicalSrcIdx = 103;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Manual_control_to_overtakel_P.HILRead_Active
	  section.data(37).logicalSrcIdx = 104;
	  section.data(37).dtTransOffset = 36;
	
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
    ;% Auto data (Manual_control_to_overtakel_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_B.Fcn
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_B.accelerationlimit
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_B.Product
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_control_to_overtakel_B.Integrator
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Manual_control_to_overtakel_B.Integrator1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Manual_control_to_overtakel_B.distanceerror
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Manual_control_to_overtakel_B.speedcommand
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Manual_control_to_overtakel_B.desired
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Manual_control_to_overtakel_B.Product1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Manual_control_to_overtakel_B.Offset
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Manual_control_to_overtakel_B.measured
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Manual_control_to_overtakel_B.commandsaturation
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Manual_control_to_overtakel_B.psi_headingrad
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Manual_control_to_overtakel_B.motorcounts
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Manual_control_to_overtakel_B.Unwrap224
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Manual_control_to_overtakel_B.Product_e
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% Manual_control_to_overtakel_B.psidotrads
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% Manual_control_to_overtakel_B.v_Xms
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Manual_control_to_overtakel_B.v_Yms
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Manual_control_to_overtakel_B.Kim
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Manual_control_to_overtakel_B.TmpSignalConversionAtsfunxyInpo
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_B.Compare
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_B.Compare_c
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
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
    nTotSects     = 7;
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
    ;% Auto data (Manual_control_to_overtakel_DW)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 14;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 27;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_OOValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Manual_control_to_overtakel_DW.PrevY
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% Manual_control_to_overtakel_DW.PrevY_l
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 49;
	
	  ;% Manual_control_to_overtakel_DW.Unwrap224_PreviousInput
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 50;
	
	  ;% Manual_control_to_overtakel_DW.Unwrap224_Revolutions
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_Card
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.HILWrite1_PWORK
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_DW.Scope2_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Manual_control_to_overtakel_DW.Scope3_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Manual_control_to_overtakel_DW.HILRead_PWORK
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Manual_control_to_overtakel_DW.Scope_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_DOStates
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_QuadratureModes
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_InitialEICounts
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_POModeValues
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 11;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_POAlignValues
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_POPolarityVals
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 27;
	
	  ;% Manual_control_to_overtakel_DW.HILRead_EncoderBuffer
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.HILInitialize1_POSortedChans
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_control_to_overtakel_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
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


  targMap.checksum0 = 1479782620;
  targMap.checksum1 = 501783324;
  targMap.checksum2 = 1555476693;
  targMap.checksum3 = 240606374;

