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
    ;% Auto data (Path_following_TP_2_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_P.X_ic
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_P.Y_ic
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_P.vehicle_length
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Path_following_TP_2_P.yaw_ic
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_P.HILRead_encoder_channels
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_P.HILWrite1_other_channels
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Path_following_TP_2_P.HILRead_other_channels
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Path_following_TP_2_P.HILWrite1_pwm_channels
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_P.Constant_Value
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOTerminate
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOExit
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOStart
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOEnter
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POFinal
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOFinal
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AIHigh
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AILow
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIFrequency
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POFrequency
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POInitial
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POWatchdog
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOInitial
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Path_following_TP_2_P.Speed_Value
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Path_following_TP_2_P.commandsaturation_UpperSat
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Path_following_TP_2_P.commandsaturation_LowerSat
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Path_following_TP_2_P.Constant4_Value
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Path_following_TP_2_P.Kffms_Gain
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Path_following_TP_2_P.Constant2_Value
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Path_following_TP_2_P.Integrator2_IC
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Path_following_TP_2_P.countstorotations_Gain
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Path_following_TP_2_P.gearratios_Gain
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Path_following_TP_2_P.rotstorads_Gain
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Path_following_TP_2_P.wheelradius_Gain
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Path_following_TP_2_P.Offset_Gain
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Path_following_TP_2_P.Kpms_Gain
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Path_following_TP_2_P.Integrator1_IC
	  section.data(28).logicalSrcIdx = 35;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Path_following_TP_2_P.Integrator1_UpperSat
	  section.data(29).logicalSrcIdx = 36;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Path_following_TP_2_P.Integrator1_LowerSat
	  section.data(30).logicalSrcIdx = 37;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Path_following_TP_2_P.Motor_commandsat_UpperSat
	  section.data(31).logicalSrcIdx = 38;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Path_following_TP_2_P.Motor_commandsat_LowerSat
	  section.data(32).logicalSrcIdx = 39;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Path_following_TP_2_P.directionconvention_Gain
	  section.data(33).logicalSrcIdx = 40;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Path_following_TP_2_P.commandsaturation_UpperSat_e
	  section.data(34).logicalSrcIdx = 41;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Path_following_TP_2_P.commandsaturation_LowerSat_k
	  section.data(35).logicalSrcIdx = 42;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Path_following_TP_2_P.Step1_Time
	  section.data(36).logicalSrcIdx = 43;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Path_following_TP_2_P.Step1_Y0
	  section.data(37).logicalSrcIdx = 44;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Path_following_TP_2_P.Step1_YFinal
	  section.data(38).logicalSrcIdx = 45;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Path_following_TP_2_P.Step_Time
	  section.data(39).logicalSrcIdx = 46;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Path_following_TP_2_P.Step_Y0
	  section.data(40).logicalSrcIdx = 47;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Path_following_TP_2_P.Step_YFinal
	  section.data(41).logicalSrcIdx = 48;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Path_following_TP_2_P.anglesaturation1_UpperSat
	  section.data(42).logicalSrcIdx = 49;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Path_following_TP_2_P.anglesaturation1_LowerSat
	  section.data(43).logicalSrcIdx = 50;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Path_following_TP_2_P.Constant3_Value
	  section.data(44).logicalSrcIdx = 51;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Path_following_TP_2_P.Constant_Value_n
	  section.data(45).logicalSrcIdx = 52;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Path_following_TP_2_P.Unwrap224_Modulus
	  section.data(46).logicalSrcIdx = 53;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Path_following_TP_2_P.Kim_Gain
	  section.data(47).logicalSrcIdx = 54;
	  section.data(47).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_P.HILInitialize1_EIInitial
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POModes
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POConfiguration
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POAlignment
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POPolarity
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_P.HILInitialize1_AIChannels
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DIChannels
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOChannels
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 27;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIChannels
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 28;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIQuadrature
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POChannels
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOChannels
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_P.HILInitialize1_Active
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOTerminate
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOExit
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOTerminate
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOExit
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POTerminate
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POExit
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Path_following_TP_2_P.HILInitialize1_CKPStart
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Path_following_TP_2_P.HILInitialize1_CKPEnter
	  section.data(9).logicalSrcIdx = 75;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Path_following_TP_2_P.HILInitialize1_CKStart
	  section.data(10).logicalSrcIdx = 76;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Path_following_TP_2_P.HILInitialize1_CKEnter
	  section.data(11).logicalSrcIdx = 77;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AIPStart
	  section.data(12).logicalSrcIdx = 78;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AIPEnter
	  section.data(13).logicalSrcIdx = 79;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOPStart
	  section.data(14).logicalSrcIdx = 80;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOPEnter
	  section.data(15).logicalSrcIdx = 81;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOStart
	  section.data(16).logicalSrcIdx = 82;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOEnter
	  section.data(17).logicalSrcIdx = 83;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Path_following_TP_2_P.HILInitialize1_AOReset
	  section.data(18).logicalSrcIdx = 84;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOPStart
	  section.data(19).logicalSrcIdx = 85;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOPEnter
	  section.data(20).logicalSrcIdx = 86;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOStart
	  section.data(21).logicalSrcIdx = 87;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOEnter
	  section.data(22).logicalSrcIdx = 88;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOReset
	  section.data(23).logicalSrcIdx = 89;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIPStart
	  section.data(24).logicalSrcIdx = 90;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIPEnter
	  section.data(25).logicalSrcIdx = 91;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIStart
	  section.data(26).logicalSrcIdx = 92;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Path_following_TP_2_P.HILInitialize1_EIEnter
	  section.data(27).logicalSrcIdx = 93;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POPStart
	  section.data(28).logicalSrcIdx = 94;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POPEnter
	  section.data(29).logicalSrcIdx = 95;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POStart
	  section.data(30).logicalSrcIdx = 96;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POEnter
	  section.data(31).logicalSrcIdx = 97;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Path_following_TP_2_P.HILInitialize1_POReset
	  section.data(32).logicalSrcIdx = 98;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Path_following_TP_2_P.HILInitialize1_OOReset
	  section.data(33).logicalSrcIdx = 99;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOFinal
	  section.data(34).logicalSrcIdx = 100;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Path_following_TP_2_P.HILInitialize1_DOInitial
	  section.data(35).logicalSrcIdx = 101;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Path_following_TP_2_P.HILWrite1_Active
	  section.data(36).logicalSrcIdx = 102;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Path_following_TP_2_P.HILRead_Active
	  section.data(37).logicalSrcIdx = 103;
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
    ;% Auto data (Path_following_TP_2_B)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_B.Speed
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_B.desired
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_B.Kffms
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Path_following_TP_2_B.Product1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Path_following_TP_2_B.Offset
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Path_following_TP_2_B.measured
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Path_following_TP_2_B.commandsaturation
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Path_following_TP_2_B.anglesaturation1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Path_following_TP_2_B.Integrator1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Path_following_TP_2_B.psi_headingrad
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Path_following_TP_2_B.Integrator
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Path_following_TP_2_B.motorcounts
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Path_following_TP_2_B.Unwrap224
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Path_following_TP_2_B.Product
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Path_following_TP_2_B.psidotrads
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Path_following_TP_2_B.v_Xms
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Path_following_TP_2_B.v_Yms
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Path_following_TP_2_B.Kim
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Path_following_TP_2_B.RateTransition
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Path_following_TP_2_B.TmpSignalConversionAtsfunxyInpo
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_B.Compare
	  section.data(1).logicalSrcIdx = 20;
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
    ;% Auto data (Path_following_TP_2_DW)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.AnimationSFunction_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 13;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_FilterFrequency
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 20;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_POSortedFreqs
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_POValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 33;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_OOValues
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 41;
	
	  ;% Path_following_TP_2_DW.HILRead_OtherBuffer
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 54;
	
	  ;% Path_following_TP_2_DW.Unwrap224_PreviousInput
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 56;
	
	  ;% Path_following_TP_2_DW.Unwrap224_Revolutions
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.HILInitialize1_Card
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.HILWrite1_PWORK
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_DW.HILRead_PWORK
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Path_following_TP_2_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.HILInitialize1_DOStates
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_QuadratureModes
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_InitialEICounts
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_POModeValues
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 11;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_POAlignValues
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Path_following_TP_2_DW.HILInitialize1_POPolarityVals
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 27;
	
	  ;% Path_following_TP_2_DW.HILRead_EncoderBuffer
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.HILInitialize1_POSortedChans
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Path_following_TP_2_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 24;
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


  targMap.checksum0 = 3892855609;
  targMap.checksum1 = 2444187883;
  targMap.checksum2 = 3086416714;
  targMap.checksum3 = 83877656;

