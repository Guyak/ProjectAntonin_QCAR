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
    ;% Auto data (drivepoint_QCar_P)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_P.x0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_P.xg
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% drivepoint_QCar_P.arewethereyet_const
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_P.HILRead_encoder_channels
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_P.HILWrite_other_channels
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_P.HILRead_other_channels
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% drivepoint_QCar_P.HILWrite_pwm_channels
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_P.Constant_Value
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOTerminate
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOExit
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOStart
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOEnter
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% drivepoint_QCar_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOFinal
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% drivepoint_QCar_P.HILInitialize_AIHigh
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% drivepoint_QCar_P.HILInitialize_AILow
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIFrequency
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 9;
	
	  ;% drivepoint_QCar_P.HILInitialize_POFrequency
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 10;
	
	  ;% drivepoint_QCar_P.HILInitialize_POInitial
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 11;
	
	  ;% drivepoint_QCar_P.HILInitialize_POWatchdog
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 12;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOInitial
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 13;
	
	  ;% drivepoint_QCar_P.Integrator_IC
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 14;
	
	  ;% drivepoint_QCar_P.velocitygainKv_Gain
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 15;
	
	  ;% drivepoint_QCar_P.commandsaturation_UpperSat
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 16;
	
	  ;% drivepoint_QCar_P.commandsaturation_LowerSat
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 17;
	
	  ;% drivepoint_QCar_P.Constant_Value_f
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 18;
	
	  ;% drivepoint_QCar_P.Kffms_Gain
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 19;
	
	  ;% drivepoint_QCar_P.Constant2_Value
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 20;
	
	  ;% drivepoint_QCar_P.Integrator2_IC
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 21;
	
	  ;% drivepoint_QCar_P.countstorotations_Gain
	  section.data(23).logicalSrcIdx = 29;
	  section.data(23).dtTransOffset = 22;
	
	  ;% drivepoint_QCar_P.gearratios_Gain
	  section.data(24).logicalSrcIdx = 30;
	  section.data(24).dtTransOffset = 23;
	
	  ;% drivepoint_QCar_P.rotstorads_Gain
	  section.data(25).logicalSrcIdx = 31;
	  section.data(25).dtTransOffset = 24;
	
	  ;% drivepoint_QCar_P.wheelradius_Gain
	  section.data(26).logicalSrcIdx = 32;
	  section.data(26).dtTransOffset = 25;
	
	  ;% drivepoint_QCar_P.Offset_Gain
	  section.data(27).logicalSrcIdx = 33;
	  section.data(27).dtTransOffset = 26;
	
	  ;% drivepoint_QCar_P.Kpms_Gain
	  section.data(28).logicalSrcIdx = 34;
	  section.data(28).dtTransOffset = 27;
	
	  ;% drivepoint_QCar_P.Integrator1_IC
	  section.data(29).logicalSrcIdx = 35;
	  section.data(29).dtTransOffset = 28;
	
	  ;% drivepoint_QCar_P.Integrator1_UpperSat
	  section.data(30).logicalSrcIdx = 36;
	  section.data(30).dtTransOffset = 29;
	
	  ;% drivepoint_QCar_P.Integrator1_LowerSat
	  section.data(31).logicalSrcIdx = 37;
	  section.data(31).dtTransOffset = 30;
	
	  ;% drivepoint_QCar_P.Motor_commandsat_UpperSat
	  section.data(32).logicalSrcIdx = 38;
	  section.data(32).dtTransOffset = 31;
	
	  ;% drivepoint_QCar_P.Motor_commandsat_LowerSat
	  section.data(33).logicalSrcIdx = 39;
	  section.data(33).dtTransOffset = 32;
	
	  ;% drivepoint_QCar_P.Gain1_Gain
	  section.data(34).logicalSrcIdx = 40;
	  section.data(34).dtTransOffset = 33;
	
	  ;% drivepoint_QCar_P.headinggainKh_Gain
	  section.data(35).logicalSrcIdx = 41;
	  section.data(35).dtTransOffset = 34;
	
	  ;% drivepoint_QCar_P.Saturation_UpperSat
	  section.data(36).logicalSrcIdx = 42;
	  section.data(36).dtTransOffset = 35;
	
	  ;% drivepoint_QCar_P.Saturation_LowerSat
	  section.data(37).logicalSrcIdx = 43;
	  section.data(37).dtTransOffset = 36;
	
	  ;% drivepoint_QCar_P.steeringlimit_UpperSat
	  section.data(38).logicalSrcIdx = 44;
	  section.data(38).dtTransOffset = 37;
	
	  ;% drivepoint_QCar_P.steeringlimit_LowerSat
	  section.data(39).logicalSrcIdx = 45;
	  section.data(39).dtTransOffset = 38;
	
	  ;% drivepoint_QCar_P.vehiclelength_Value
	  section.data(40).logicalSrcIdx = 46;
	  section.data(40).dtTransOffset = 39;
	
	  ;% drivepoint_QCar_P.velocitylimit_UpperSat
	  section.data(41).logicalSrcIdx = 47;
	  section.data(41).dtTransOffset = 40;
	
	  ;% drivepoint_QCar_P.velocitylimit_LowerSat
	  section.data(42).logicalSrcIdx = 48;
	  section.data(42).dtTransOffset = 41;
	
	  ;% drivepoint_QCar_P.accelerationlimit_RisingLim
	  section.data(43).logicalSrcIdx = 49;
	  section.data(43).dtTransOffset = 42;
	
	  ;% drivepoint_QCar_P.accelerationlimit_FallingLim
	  section.data(44).logicalSrcIdx = 50;
	  section.data(44).dtTransOffset = 43;
	
	  ;% drivepoint_QCar_P.Constant3_Value
	  section.data(45).logicalSrcIdx = 51;
	  section.data(45).dtTransOffset = 44;
	
	  ;% drivepoint_QCar_P.Constant_Value_e
	  section.data(46).logicalSrcIdx = 52;
	  section.data(46).dtTransOffset = 45;
	
	  ;% drivepoint_QCar_P.Unwrap224_Modulus
	  section.data(47).logicalSrcIdx = 53;
	  section.data(47).dtTransOffset = 46;
	
	  ;% drivepoint_QCar_P.Kim_Gain
	  section.data(48).logicalSrcIdx = 54;
	  section.data(48).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 3;
	
	  ;% drivepoint_QCar_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 4;
	
	  ;% drivepoint_QCar_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 7;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 27;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 28;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 33;
	
	  ;% drivepoint_QCar_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 35;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
	  ;% drivepoint_QCar_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 5;
	
	  ;% drivepoint_QCar_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 6;
	
	  ;% drivepoint_QCar_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 7;
	
	  ;% drivepoint_QCar_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 75;
	  section.data(9).dtTransOffset = 8;
	
	  ;% drivepoint_QCar_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 76;
	  section.data(10).dtTransOffset = 9;
	
	  ;% drivepoint_QCar_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 77;
	  section.data(11).dtTransOffset = 10;
	
	  ;% drivepoint_QCar_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 78;
	  section.data(12).dtTransOffset = 11;
	
	  ;% drivepoint_QCar_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 79;
	  section.data(13).dtTransOffset = 12;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 80;
	  section.data(14).dtTransOffset = 13;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 81;
	  section.data(15).dtTransOffset = 14;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 82;
	  section.data(16).dtTransOffset = 15;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 83;
	  section.data(17).dtTransOffset = 16;
	
	  ;% drivepoint_QCar_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 84;
	  section.data(18).dtTransOffset = 17;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 85;
	  section.data(19).dtTransOffset = 18;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 86;
	  section.data(20).dtTransOffset = 19;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 87;
	  section.data(21).dtTransOffset = 20;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 88;
	  section.data(22).dtTransOffset = 21;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 89;
	  section.data(23).dtTransOffset = 22;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 90;
	  section.data(24).dtTransOffset = 23;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 91;
	  section.data(25).dtTransOffset = 24;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 92;
	  section.data(26).dtTransOffset = 25;
	
	  ;% drivepoint_QCar_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 93;
	  section.data(27).dtTransOffset = 26;
	
	  ;% drivepoint_QCar_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 94;
	  section.data(28).dtTransOffset = 27;
	
	  ;% drivepoint_QCar_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 95;
	  section.data(29).dtTransOffset = 28;
	
	  ;% drivepoint_QCar_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 96;
	  section.data(30).dtTransOffset = 29;
	
	  ;% drivepoint_QCar_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 97;
	  section.data(31).dtTransOffset = 30;
	
	  ;% drivepoint_QCar_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 98;
	  section.data(32).dtTransOffset = 31;
	
	  ;% drivepoint_QCar_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 99;
	  section.data(33).dtTransOffset = 32;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 100;
	  section.data(34).dtTransOffset = 33;
	
	  ;% drivepoint_QCar_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 101;
	  section.data(35).dtTransOffset = 34;
	
	  ;% drivepoint_QCar_P.HILWrite_Active
	  section.data(36).logicalSrcIdx = 102;
	  section.data(36).dtTransOffset = 35;
	
	  ;% drivepoint_QCar_P.HILRead_Active
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
    ;% Auto data (drivepoint_QCar_B)
    ;%
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_B.currentheading
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_B.positions
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% drivepoint_QCar_B.speedcommand
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% drivepoint_QCar_B.desired
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% drivepoint_QCar_B.desired_o
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% drivepoint_QCar_B.Integrator2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% drivepoint_QCar_B.Product1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% drivepoint_QCar_B.motorspeedrots
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% drivepoint_QCar_B.shaftspeedrotss
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% drivepoint_QCar_B.wheelspeedrads
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% drivepoint_QCar_B.wheelspeedms
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% drivepoint_QCar_B.Offset
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% drivepoint_QCar_B.measured
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% drivepoint_QCar_B.Sum_n
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 17;
	
	  ;% drivepoint_QCar_B.Integrator1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 18;
	
	  ;% drivepoint_QCar_B.Gain1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 19;
	
	  ;% drivepoint_QCar_B.steeringwheelangle
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% drivepoint_QCar_B.Saturation
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% drivepoint_QCar_B.steeringlimit
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% drivepoint_QCar_B.Divide
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% drivepoint_QCar_B.velocitylimit
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% drivepoint_QCar_B.accelerationlimit
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% drivepoint_QCar_B.Product
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% drivepoint_QCar_B.motorcounts
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 29;
	
	  ;% drivepoint_QCar_B.Unwrap224
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 30;
	
	  ;% drivepoint_QCar_B.Integrator1_j
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 31;
	
	  ;% drivepoint_QCar_B.Sum1
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 32;
	
	  ;% drivepoint_QCar_B.Product2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 33;
	
	  ;% drivepoint_QCar_B.Sum_e
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 34;
	
	  ;% drivepoint_QCar_B.Product_b
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 35;
	
	  ;% drivepoint_QCar_B.Kim
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 36;
	
	  ;% drivepoint_QCar_B.TmpSignalConversionAtsfunxyInpo
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 37;
	
	  ;% drivepoint_QCar_B.theta_dotrads
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_B.Compare
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_B.Compare_m
	  section.data(2).logicalSrcIdx = 35;
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
    nTotSects     = 8;
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
    ;% Auto data (drivepoint_QCar_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 7;
	
	  ;% drivepoint_QCar_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 14;
	
	  ;% drivepoint_QCar_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 19;
	
	  ;% drivepoint_QCar_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 27;
	
	  ;% drivepoint_QCar_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 35;
	
	  ;% drivepoint_QCar_DW.PrevYA
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 48;
	
	  ;% drivepoint_QCar_DW.PrevYB
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 49;
	
	  ;% drivepoint_QCar_DW.LastMajorTimeA
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 50;
	
	  ;% drivepoint_QCar_DW.LastMajorTimeB
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 51;
	
	  ;% drivepoint_QCar_DW.HILRead_OtherBuffer
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 52;
	
	  ;% drivepoint_QCar_DW.Unwrap224_PreviousInput
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 53;
	
	  ;% drivepoint_QCar_DW.Unwrap224_Revolutions
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 54;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.HILWrite_PWORK
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_DW.HeadingDiff_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_DW.heading_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 3;
	
	  ;% drivepoint_QCar_DW.steeringangle_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 4;
	
	  ;% drivepoint_QCar_DW.velocity_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 5;
	
	  ;% drivepoint_QCar_DW.HILRead_PWORK
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 6;
	
	  ;% drivepoint_QCar_DW.speedComparison_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 6;
	
	  ;% drivepoint_QCar_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 11;
	
	  ;% drivepoint_QCar_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 19;
	
	  ;% drivepoint_QCar_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 27;
	
	  ;% drivepoint_QCar_DW.HILRead_EncoderBuffer
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% drivepoint_QCar_DW.Unwrap224_FirstSample
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% drivepoint_QCar_DW.objisempty
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% drivepoint_QCar_DW.isInitialized
	  section.data(3).logicalSrcIdx = 33;
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


  targMap.checksum0 = 1887622831;
  targMap.checksum1 = 1808056908;
  targMap.checksum2 = 704291663;
  targMap.checksum3 = 2045435848;

