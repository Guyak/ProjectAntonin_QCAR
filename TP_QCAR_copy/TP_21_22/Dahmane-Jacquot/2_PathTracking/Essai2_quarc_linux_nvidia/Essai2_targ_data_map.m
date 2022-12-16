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
    ;% Auto data (Essai2_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Essai2_P.X_ic
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_P.Y_ic
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_P.vehicle_length
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Essai2_P.yaw_ic
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Essai2_P.PIDController_P
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Essai2_P.HILRead1_encoder_channels
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_P.HILRead1_other_channels
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Essai2_P.HILWrite2_other_channels
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Essai2_P.HILWrite2_pwm_channels
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% Essai2_P.HILInitialize2_OOTerminate
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_P.HILInitialize2_OOExit
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_P.HILInitialize2_OOStart
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Essai2_P.HILInitialize2_OOEnter
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Essai2_P.HILInitialize2_POFinal
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Essai2_P.HILInitialize2_OOFinal
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Essai2_P.HILInitialize2_AIHigh
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Essai2_P.HILInitialize2_AILow
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Essai2_P.HILInitialize2_EIFrequency
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Essai2_P.HILInitialize2_POFrequency
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Essai2_P.HILInitialize2_POInitial
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Essai2_P.HILInitialize2_POWatchdog
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Essai2_P.HILInitialize2_OOInitial
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Essai2_P.Constant1_Value
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Essai2_P.Integrator2_IC
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Essai2_P.countstorotations_Gain
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Essai2_P.gearratios_Gain
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Essai2_P.rotstorads_Gain
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Essai2_P.wheelradius_Gain
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Essai2_P.Offset_Gain
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Essai2_P.Integrator_IC
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Essai2_P.Constant_Value
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Essai2_P.Constant6_Value
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Essai2_P.Gain_Gain
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Essai2_P.commandsaturation1_UpperSat
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Essai2_P.commandsaturation1_LowerSat
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Essai2_P.Constant5_Value
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Essai2_P.Constant7_Value
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Essai2_P.Constant8_Value
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Essai2_P.Constant_Value_a
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Essai2_P.Unwrap21_Modulus
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Essai2_P.Constant_Value_n
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Essai2_P.Integrator2_IC_f
	  section.data(33).logicalSrcIdx = 41;
	  section.data(33).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Essai2_P.HILInitialize2_EIInitial
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_P.HILInitialize2_POModes
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_P.HILInitialize2_POConfiguration
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Essai2_P.HILInitialize2_POAlignment
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Essai2_P.HILInitialize2_POPolarity
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Essai2_P.HILInitialize2_AIChannels
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_P.HILInitialize2_DIChannels
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Essai2_P.HILInitialize2_DOChannels
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 27;
	
	  ;% Essai2_P.HILInitialize2_EIChannels
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 28;
	
	  ;% Essai2_P.HILInitialize2_EIQuadrature
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Essai2_P.HILInitialize2_POChannels
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Essai2_P.HILInitialize2_OOChannels
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% Essai2_P.HILInitialize2_Active
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_P.HILInitialize2_AOTerminate
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_P.HILInitialize2_AOExit
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Essai2_P.HILInitialize2_DOTerminate
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Essai2_P.HILInitialize2_DOExit
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Essai2_P.HILInitialize2_POTerminate
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Essai2_P.HILInitialize2_POExit
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Essai2_P.HILInitialize2_CKPStart
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Essai2_P.HILInitialize2_CKPEnter
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Essai2_P.HILInitialize2_CKStart
	  section.data(10).logicalSrcIdx = 63;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Essai2_P.HILInitialize2_CKEnter
	  section.data(11).logicalSrcIdx = 64;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Essai2_P.HILInitialize2_AIPStart
	  section.data(12).logicalSrcIdx = 65;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Essai2_P.HILInitialize2_AIPEnter
	  section.data(13).logicalSrcIdx = 66;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Essai2_P.HILInitialize2_AOPStart
	  section.data(14).logicalSrcIdx = 67;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Essai2_P.HILInitialize2_AOPEnter
	  section.data(15).logicalSrcIdx = 68;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Essai2_P.HILInitialize2_AOStart
	  section.data(16).logicalSrcIdx = 69;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Essai2_P.HILInitialize2_AOEnter
	  section.data(17).logicalSrcIdx = 70;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Essai2_P.HILInitialize2_AOReset
	  section.data(18).logicalSrcIdx = 71;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Essai2_P.HILInitialize2_DOPStart
	  section.data(19).logicalSrcIdx = 72;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Essai2_P.HILInitialize2_DOPEnter
	  section.data(20).logicalSrcIdx = 73;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Essai2_P.HILInitialize2_DOStart
	  section.data(21).logicalSrcIdx = 74;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Essai2_P.HILInitialize2_DOEnter
	  section.data(22).logicalSrcIdx = 75;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Essai2_P.HILInitialize2_DOReset
	  section.data(23).logicalSrcIdx = 76;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Essai2_P.HILInitialize2_EIPStart
	  section.data(24).logicalSrcIdx = 77;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Essai2_P.HILInitialize2_EIPEnter
	  section.data(25).logicalSrcIdx = 78;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Essai2_P.HILInitialize2_EIStart
	  section.data(26).logicalSrcIdx = 79;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Essai2_P.HILInitialize2_EIEnter
	  section.data(27).logicalSrcIdx = 80;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Essai2_P.HILInitialize2_POPStart
	  section.data(28).logicalSrcIdx = 81;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Essai2_P.HILInitialize2_POPEnter
	  section.data(29).logicalSrcIdx = 82;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Essai2_P.HILInitialize2_POStart
	  section.data(30).logicalSrcIdx = 83;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Essai2_P.HILInitialize2_POEnter
	  section.data(31).logicalSrcIdx = 84;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Essai2_P.HILInitialize2_POReset
	  section.data(32).logicalSrcIdx = 85;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Essai2_P.HILInitialize2_OOReset
	  section.data(33).logicalSrcIdx = 86;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Essai2_P.HILInitialize2_DOFinal
	  section.data(34).logicalSrcIdx = 87;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Essai2_P.HILInitialize2_DOInitial
	  section.data(35).logicalSrcIdx = 88;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Essai2_P.HILRead1_Active
	  section.data(36).logicalSrcIdx = 89;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Essai2_P.HILWrite2_Active
	  section.data(37).logicalSrcIdx = 90;
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
    ;% Auto data (Essai2_B)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Essai2_B.Product1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_B.Offset
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_B.headingpositiongyroscope
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Essai2_B.Constant
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Essai2_B.Sum
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Essai2_B.ProportionalGain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Essai2_B.motorcounts
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Essai2_B.HILRead1_o3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Essai2_B.Integrator
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Essai2_B.Integrator1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Essai2_B.psi_headingrad
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Essai2_B.Unwrap21
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Essai2_B.Product
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Essai2_B.Integrator1_l
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Essai2_B.Product_b
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Essai2_B.Product1_f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Essai2_B.psidotrads
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Essai2_B.v_Xms
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Essai2_B.v_Yms
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Essai2_B.RateTransition
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
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
    nTotSects     = 7;
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
    ;% Auto data (Essai2_DW)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Essai2_DW.AnimationSFunction_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_DW.HILInitialize2_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% Essai2_DW.HILInitialize2_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 13;
	
	  ;% Essai2_DW.HILInitialize2_FilterFrequency
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 20;
	
	  ;% Essai2_DW.HILInitialize2_POSortedFreqs
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% Essai2_DW.HILInitialize2_POValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 33;
	
	  ;% Essai2_DW.HILInitialize2_OOValues
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 41;
	
	  ;% Essai2_DW.HILRead1_OtherBuffer
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 54;
	
	  ;% Essai2_DW.Unwrap21_PreviousInput
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 56;
	
	  ;% Essai2_DW.Unwrap21_Revolutions
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Essai2_DW.HILInitialize2_Card
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Essai2_DW.HILRead1_PWORK
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_DW.HILWrite2_PWORK
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Essai2_DW.HILInitialize2_DOStates
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_DW.HILInitialize2_QuadratureModes
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Essai2_DW.HILInitialize2_InitialEICounts
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Essai2_DW.HILInitialize2_POModeValues
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 11;
	
	  ;% Essai2_DW.HILInitialize2_POAlignValues
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Essai2_DW.HILInitialize2_POPolarityVals
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 27;
	
	  ;% Essai2_DW.HILRead1_EncoderBuffer
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Essai2_DW.HILInitialize2_POSortedChans
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Essai2_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Essai2_DW.Integrator1_IWORK_m
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Essai2_DW.Unwrap21_FirstSample
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


  targMap.checksum0 = 1809551046;
  targMap.checksum1 = 1287788468;
  targMap.checksum2 = 268289483;
  targMap.checksum3 = 3368718399;

