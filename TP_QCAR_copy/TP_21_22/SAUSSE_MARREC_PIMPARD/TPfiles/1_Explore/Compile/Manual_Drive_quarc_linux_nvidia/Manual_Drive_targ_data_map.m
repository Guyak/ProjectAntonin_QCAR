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
    ;% Auto data (Manual_Drive_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.LeftSteeringLimit_const
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.RightSteeringLimit_const
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_P.CompareToConstant3_const
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_Drive_P.CompareToConstant1_const
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_Drive_P.CompareToConstant2_const
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.HILRead_analog_channels
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.HILWrite_digital_channels
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Manual_Drive_P.HILRead_encoder_channels
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Manual_Drive_P.HILWrite_other_channels
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Manual_Drive_P.HILWrite_pwm_channels
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.CompareToConstant2_const_a
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.CompareToConstant1_const_o
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 56;
      section.data(56)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.Gain1_Gain
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_P.Constant_Value
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_Drive_P.Enabled_Y0
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_Drive_P.Constant_Value_d
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Manual_Drive_P.Constant1_Value
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Manual_Drive_P.Constant_Value_b
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Manual_Drive_P.Constant_Value_f
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Manual_Drive_P.HILInitialize_OOTerminate
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Manual_Drive_P.HILInitialize_OOExit
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Manual_Drive_P.HILInitialize_OOStart
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Manual_Drive_P.HILInitialize_OOEnter
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Manual_Drive_P.HILInitialize_POFinal
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Manual_Drive_P.HILInitialize_OOFinal
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Manual_Drive_P.HILInitialize_AIHigh
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Manual_Drive_P.HILInitialize_AILow
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Manual_Drive_P.HILInitialize_EIFrequency
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Manual_Drive_P.HILInitialize_POFrequency
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Manual_Drive_P.HILInitialize_POInitial
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Manual_Drive_P.HILInitialize_POWatchdog
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Manual_Drive_P.HILInitialize_OOInitial
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Manual_Drive_P.Constant1_Value_b
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Manual_Drive_P.Constant2_Value_n
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Manual_Drive_P.Constant_Value_p
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Manual_Drive_P.Unwrap224_Modulus
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Manual_Drive_P.Integrator2_IC
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Manual_Drive_P.True_Value
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Manual_Drive_P.Switch_Threshold
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Manual_Drive_P.Bias_Bias
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Manual_Drive_P.Gain3_Gain
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Manual_Drive_P.directionconvention_Gain
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Manual_Drive_P.scaleoutputtomaxrange_Gain
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Manual_Drive_P.commandsaturation_UpperSat
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Manual_Drive_P.commandsaturation_LowerSat
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Manual_Drive_P.coastON_Value
	  section.data(35).logicalSrcIdx = 46;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Manual_Drive_P.Gain4_Gain
	  section.data(36).logicalSrcIdx = 47;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Manual_Drive_P.remappingtosteeringrange_Gain
	  section.data(37).logicalSrcIdx = 48;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Manual_Drive_P.Gain_Gain
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Manual_Drive_P.SteeringBias_Bias
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Manual_Drive_P.PulsingLight_Amp
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Manual_Drive_P.PulsingLight_Period
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Manual_Drive_P.PulsingLight_Duty
	  section.data(42).logicalSrcIdx = 53;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Manual_Drive_P.PulsingLight_PhaseDelay
	  section.data(43).logicalSrcIdx = 54;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Manual_Drive_P.Memory_InitialCondition
	  section.data(44).logicalSrcIdx = 55;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Manual_Drive_P.Constant2_Value_j
	  section.data(45).logicalSrcIdx = 56;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Manual_Drive_P.one_shot_block_trigger_type
	  section.data(46).logicalSrcIdx = 57;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Manual_Drive_P.one_shot_block_redun_pulse
	  section.data(47).logicalSrcIdx = 58;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Manual_Drive_P.Switch_Threshold_f
	  section.data(48).logicalSrcIdx = 59;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Manual_Drive_P.minvoltage_Value
	  section.data(49).logicalSrcIdx = 60;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Manual_Drive_P.maxvoltage_Value
	  section.data(50).logicalSrcIdx = 61;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Manual_Drive_P.Gain_Gain_i
	  section.data(51).logicalSrcIdx = 62;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Manual_Drive_P.countstorotations_Gain
	  section.data(52).logicalSrcIdx = 63;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Manual_Drive_P.gearratios_Gain
	  section.data(53).logicalSrcIdx = 64;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Manual_Drive_P.rotstorads_Gain
	  section.data(54).logicalSrcIdx = 65;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Manual_Drive_P.wheelradius_Gain
	  section.data(55).logicalSrcIdx = 66;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Manual_Drive_P.Constant_Value_b3
	  section.data(56).logicalSrcIdx = 67;
	  section.data(56).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 70;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Manual_Drive_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 71;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Manual_Drive_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 72;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Manual_Drive_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 27;
	
	  ;% Manual_Drive_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 28;
	
	  ;% Manual_Drive_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Manual_Drive_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Manual_Drive_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.LightOff_Value
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_P.HILInitialize_Active
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_P.HILInitialize_AOTerminate
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_Drive_P.HILInitialize_AOExit
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_Drive_P.HILInitialize_DOTerminate
	  section.data(5).logicalSrcIdx = 85;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Manual_Drive_P.HILInitialize_DOExit
	  section.data(6).logicalSrcIdx = 86;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Manual_Drive_P.HILInitialize_POTerminate
	  section.data(7).logicalSrcIdx = 87;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Manual_Drive_P.HILInitialize_POExit
	  section.data(8).logicalSrcIdx = 88;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Manual_Drive_P.HILInitialize_CKPStart
	  section.data(9).logicalSrcIdx = 89;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Manual_Drive_P.HILInitialize_CKPEnter
	  section.data(10).logicalSrcIdx = 90;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Manual_Drive_P.HILInitialize_CKStart
	  section.data(11).logicalSrcIdx = 91;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Manual_Drive_P.HILInitialize_CKEnter
	  section.data(12).logicalSrcIdx = 92;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Manual_Drive_P.HILInitialize_AIPStart
	  section.data(13).logicalSrcIdx = 93;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Manual_Drive_P.HILInitialize_AIPEnter
	  section.data(14).logicalSrcIdx = 94;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Manual_Drive_P.HILInitialize_AOPStart
	  section.data(15).logicalSrcIdx = 95;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Manual_Drive_P.HILInitialize_AOPEnter
	  section.data(16).logicalSrcIdx = 96;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Manual_Drive_P.HILInitialize_AOStart
	  section.data(17).logicalSrcIdx = 97;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Manual_Drive_P.HILInitialize_AOEnter
	  section.data(18).logicalSrcIdx = 98;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Manual_Drive_P.HILInitialize_AOReset
	  section.data(19).logicalSrcIdx = 99;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Manual_Drive_P.HILInitialize_DOPStart
	  section.data(20).logicalSrcIdx = 100;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Manual_Drive_P.HILInitialize_DOPEnter
	  section.data(21).logicalSrcIdx = 101;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Manual_Drive_P.HILInitialize_DOStart
	  section.data(22).logicalSrcIdx = 102;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Manual_Drive_P.HILInitialize_DOEnter
	  section.data(23).logicalSrcIdx = 103;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Manual_Drive_P.HILInitialize_DOReset
	  section.data(24).logicalSrcIdx = 104;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Manual_Drive_P.HILInitialize_EIPStart
	  section.data(25).logicalSrcIdx = 105;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Manual_Drive_P.HILInitialize_EIPEnter
	  section.data(26).logicalSrcIdx = 106;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Manual_Drive_P.HILInitialize_EIStart
	  section.data(27).logicalSrcIdx = 107;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Manual_Drive_P.HILInitialize_EIEnter
	  section.data(28).logicalSrcIdx = 108;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Manual_Drive_P.HILInitialize_POPStart
	  section.data(29).logicalSrcIdx = 109;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Manual_Drive_P.HILInitialize_POPEnter
	  section.data(30).logicalSrcIdx = 110;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Manual_Drive_P.HILInitialize_POStart
	  section.data(31).logicalSrcIdx = 111;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Manual_Drive_P.HILInitialize_POEnter
	  section.data(32).logicalSrcIdx = 112;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Manual_Drive_P.HILInitialize_POReset
	  section.data(33).logicalSrcIdx = 113;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Manual_Drive_P.HILInitialize_OOReset
	  section.data(34).logicalSrcIdx = 114;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Manual_Drive_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 115;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Manual_Drive_P.HILInitialize_DOInitial
	  section.data(36).logicalSrcIdx = 116;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Manual_Drive_P.HILRead_Active
	  section.data(37).logicalSrcIdx = 117;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Manual_Drive_P.GameController_AutoCenter
	  section.data(38).logicalSrcIdx = 118;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Manual_Drive_P.GameController_Enabled
	  section.data(39).logicalSrcIdx = 119;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Manual_Drive_P.SteadyLight_Value
	  section.data(40).logicalSrcIdx = 120;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Manual_Drive_P.HILWrite_Active
	  section.data(41).logicalSrcIdx = 121;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_P.GameController_ControllerNumber
	  section.data(1).logicalSrcIdx = 122;
	  section.data(1).dtTransOffset = 0;
	
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
    ;% Auto data (Manual_Drive_B)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% Manual_Drive_B.encodercounts
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_B.Unwrap224
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_B.Product
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_Drive_B.Product1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Manual_Drive_B.Product3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Manual_Drive_B.one_shot_block
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Manual_Drive_B.Product_d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Manual_Drive_B.Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Manual_Drive_B.wheelspeedms
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Manual_Drive_B.actualsampletime
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Manual_Drive_B.reference
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Manual_Drive_B.computationtime
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Manual_Drive_B.OutportBufferForEnabled
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Manual_Drive_B.GameController_o1
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_B.GameController_o2
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_B.Compare
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 33;
	
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
    nTotSects     = 11;
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
    ;% Auto data (Manual_Drive_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_DW.ComputationTime_BeginTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_DW.ComputationTime_ComputationTime
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.one_shot_block_DSTATE
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_DW.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Manual_Drive_DW.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 10;
	
	  ;% Manual_Drive_DW.HILInitialize_FilterFrequency
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 17;
	
	  ;% Manual_Drive_DW.HILInitialize_POSortedFreqs
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 22;
	
	  ;% Manual_Drive_DW.HILInitialize_POValues
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 30;
	
	  ;% Manual_Drive_DW.HILInitialize_OOValues
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 38;
	
	  ;% Manual_Drive_DW.HILRead_AnalogBuffer
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 51;
	
	  ;% Manual_Drive_DW.Unwrap224_PreviousInput
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 53;
	
	  ;% Manual_Drive_DW.Unwrap224_Revolutions
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 54;
	
	  ;% Manual_Drive_DW.Memory_PreviousInput
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.HILRead_PWORK
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_DW.HILWrite_PWORK
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Manual_Drive_DW.Scope_PWORK_p.LoggedData
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Manual_Drive_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Manual_Drive_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Manual_Drive_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 11;
	
	  ;% Manual_Drive_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Manual_Drive_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 27;
	
	  ;% Manual_Drive_DW.HILRead_EncoderBuffer
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 35;
	
	  ;% Manual_Drive_DW.clockTickCounter
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.TriggeredSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Manual_Drive_DW.HILWrite_DigitalBuffer
	  section.data(1).logicalSrcIdx = 32;
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


  targMap.checksum0 = 3049118402;
  targMap.checksum1 = 3686269761;
  targMap.checksum2 = 3026522845;
  targMap.checksum3 = 2355600375;

