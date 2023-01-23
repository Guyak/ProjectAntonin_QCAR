  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Imaging_360_P)
    ;%
      section.nData     = 69;
      section.data(69)  = dumData; %prealloc
      
	  ;% Imaging_360_P.Constant_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_P.VideoCapture_Brightness
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Imaging_360_P.VideoCapture_Contrast
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Imaging_360_P.VideoCapture_Hue
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Imaging_360_P.VideoCapture_Saturation
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Imaging_360_P.VideoCapture_Sharpness
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Imaging_360_P.VideoCapture_Gamma
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Imaging_360_P.VideoCapture_ColorEnable
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Imaging_360_P.VideoCapture_WhiteBalance
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Imaging_360_P.VideoCapture_BacklightCompensat
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Imaging_360_P.VideoCapture_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Imaging_360_P.VideoCapture_Pan
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Imaging_360_P.VideoCapture_Tilt
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Imaging_360_P.VideoCapture_Roll
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Imaging_360_P.VideoCapture_Zoom
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Imaging_360_P.VideoCapture_Exposure
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Imaging_360_P.VideoCapture_Iris
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Imaging_360_P.VideoCapture_Focus
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Imaging_360_P.VideoCapture1_Brightness
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Imaging_360_P.VideoCapture1_Contrast
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Imaging_360_P.VideoCapture1_Hue
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Imaging_360_P.VideoCapture1_Saturation
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Imaging_360_P.VideoCapture1_Sharpness
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Imaging_360_P.VideoCapture1_Gamma
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Imaging_360_P.VideoCapture1_ColorEnable
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Imaging_360_P.VideoCapture1_WhiteBalance
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Imaging_360_P.VideoCapture1_BacklightCompensa
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Imaging_360_P.VideoCapture1_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Imaging_360_P.VideoCapture1_Pan
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Imaging_360_P.VideoCapture1_Tilt
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Imaging_360_P.VideoCapture1_Roll
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Imaging_360_P.VideoCapture1_Zoom
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Imaging_360_P.VideoCapture1_Exposure
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Imaging_360_P.VideoCapture1_Iris
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Imaging_360_P.VideoCapture1_Focus
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Imaging_360_P.VideoCapture2_Brightness
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Imaging_360_P.VideoCapture2_Contrast
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Imaging_360_P.VideoCapture2_Hue
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Imaging_360_P.VideoCapture2_Saturation
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Imaging_360_P.VideoCapture2_Sharpness
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Imaging_360_P.VideoCapture2_Gamma
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Imaging_360_P.VideoCapture2_ColorEnable
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Imaging_360_P.VideoCapture2_WhiteBalance
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Imaging_360_P.VideoCapture2_BacklightCompensa
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Imaging_360_P.VideoCapture2_Gain
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Imaging_360_P.VideoCapture2_Pan
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Imaging_360_P.VideoCapture2_Tilt
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Imaging_360_P.VideoCapture2_Roll
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Imaging_360_P.VideoCapture2_Zoom
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Imaging_360_P.VideoCapture2_Exposure
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Imaging_360_P.VideoCapture2_Iris
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Imaging_360_P.VideoCapture2_Focus
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Imaging_360_P.VideoCapture3_Brightness
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Imaging_360_P.VideoCapture3_Contrast
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Imaging_360_P.VideoCapture3_Hue
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Imaging_360_P.VideoCapture3_Saturation
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Imaging_360_P.VideoCapture3_Sharpness
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Imaging_360_P.VideoCapture3_Gamma
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Imaging_360_P.VideoCapture3_ColorEnable
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Imaging_360_P.VideoCapture3_WhiteBalance
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Imaging_360_P.VideoCapture3_BacklightCompensa
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Imaging_360_P.VideoCapture3_Gain
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Imaging_360_P.VideoCapture3_Pan
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Imaging_360_P.VideoCapture3_Tilt
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Imaging_360_P.VideoCapture3_Roll
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Imaging_360_P.VideoCapture3_Zoom
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Imaging_360_P.VideoCapture3_Exposure
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Imaging_360_P.VideoCapture3_Iris
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Imaging_360_P.VideoCapture3_Focus
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 69;
      section.data(69)  = dumData; %prealloc
      
	  ;% Imaging_360_P.VideoDisplay_UseHardware
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_P.VideoCapture_OvBrightness
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Imaging_360_P.VideoCapture_OvContrast
	  section.data(3).logicalSrcIdx = 71;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Imaging_360_P.VideoCapture_OvHue
	  section.data(4).logicalSrcIdx = 72;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Imaging_360_P.VideoCapture_OvSaturation
	  section.data(5).logicalSrcIdx = 73;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Imaging_360_P.VideoCapture_OvSharpness
	  section.data(6).logicalSrcIdx = 74;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Imaging_360_P.VideoCapture_OvGamma
	  section.data(7).logicalSrcIdx = 75;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Imaging_360_P.VideoCapture_OvColorEnable
	  section.data(8).logicalSrcIdx = 76;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Imaging_360_P.VideoCapture_OvWhiteBalance
	  section.data(9).logicalSrcIdx = 77;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Imaging_360_P.VideoCapture_OvBacklightCompens
	  section.data(10).logicalSrcIdx = 78;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Imaging_360_P.VideoCapture_OvGain
	  section.data(11).logicalSrcIdx = 79;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Imaging_360_P.VideoCapture_OvPan
	  section.data(12).logicalSrcIdx = 80;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Imaging_360_P.VideoCapture_OvTilt
	  section.data(13).logicalSrcIdx = 81;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Imaging_360_P.VideoCapture_OvRoll
	  section.data(14).logicalSrcIdx = 82;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Imaging_360_P.VideoCapture_OvZoom
	  section.data(15).logicalSrcIdx = 83;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Imaging_360_P.VideoCapture_OvExposure
	  section.data(16).logicalSrcIdx = 84;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Imaging_360_P.VideoCapture_OvIris
	  section.data(17).logicalSrcIdx = 85;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Imaging_360_P.VideoCapture_OvFocus
	  section.data(18).logicalSrcIdx = 86;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Imaging_360_P.VideoCapture1_OvBrightness
	  section.data(19).logicalSrcIdx = 87;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Imaging_360_P.VideoCapture1_OvContrast
	  section.data(20).logicalSrcIdx = 88;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Imaging_360_P.VideoCapture1_OvHue
	  section.data(21).logicalSrcIdx = 89;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Imaging_360_P.VideoCapture1_OvSaturation
	  section.data(22).logicalSrcIdx = 90;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Imaging_360_P.VideoCapture1_OvSharpness
	  section.data(23).logicalSrcIdx = 91;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Imaging_360_P.VideoCapture1_OvGamma
	  section.data(24).logicalSrcIdx = 92;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Imaging_360_P.VideoCapture1_OvColorEnable
	  section.data(25).logicalSrcIdx = 93;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Imaging_360_P.VideoCapture1_OvWhiteBalance
	  section.data(26).logicalSrcIdx = 94;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Imaging_360_P.VideoCapture1_OvBacklightCompen
	  section.data(27).logicalSrcIdx = 95;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Imaging_360_P.VideoCapture1_OvGain
	  section.data(28).logicalSrcIdx = 96;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Imaging_360_P.VideoCapture1_OvPan
	  section.data(29).logicalSrcIdx = 97;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Imaging_360_P.VideoCapture1_OvTilt
	  section.data(30).logicalSrcIdx = 98;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Imaging_360_P.VideoCapture1_OvRoll
	  section.data(31).logicalSrcIdx = 99;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Imaging_360_P.VideoCapture1_OvZoom
	  section.data(32).logicalSrcIdx = 100;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Imaging_360_P.VideoCapture1_OvExposure
	  section.data(33).logicalSrcIdx = 101;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Imaging_360_P.VideoCapture1_OvIris
	  section.data(34).logicalSrcIdx = 102;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Imaging_360_P.VideoCapture1_OvFocus
	  section.data(35).logicalSrcIdx = 103;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Imaging_360_P.VideoCapture2_OvBrightness
	  section.data(36).logicalSrcIdx = 104;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Imaging_360_P.VideoCapture2_OvContrast
	  section.data(37).logicalSrcIdx = 105;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Imaging_360_P.VideoCapture2_OvHue
	  section.data(38).logicalSrcIdx = 106;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Imaging_360_P.VideoCapture2_OvSaturation
	  section.data(39).logicalSrcIdx = 107;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Imaging_360_P.VideoCapture2_OvSharpness
	  section.data(40).logicalSrcIdx = 108;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Imaging_360_P.VideoCapture2_OvGamma
	  section.data(41).logicalSrcIdx = 109;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Imaging_360_P.VideoCapture2_OvColorEnable
	  section.data(42).logicalSrcIdx = 110;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Imaging_360_P.VideoCapture2_OvWhiteBalance
	  section.data(43).logicalSrcIdx = 111;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Imaging_360_P.VideoCapture2_OvBacklightCompen
	  section.data(44).logicalSrcIdx = 112;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Imaging_360_P.VideoCapture2_OvGain
	  section.data(45).logicalSrcIdx = 113;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Imaging_360_P.VideoCapture2_OvPan
	  section.data(46).logicalSrcIdx = 114;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Imaging_360_P.VideoCapture2_OvTilt
	  section.data(47).logicalSrcIdx = 115;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Imaging_360_P.VideoCapture2_OvRoll
	  section.data(48).logicalSrcIdx = 116;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Imaging_360_P.VideoCapture2_OvZoom
	  section.data(49).logicalSrcIdx = 117;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Imaging_360_P.VideoCapture2_OvExposure
	  section.data(50).logicalSrcIdx = 118;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Imaging_360_P.VideoCapture2_OvIris
	  section.data(51).logicalSrcIdx = 119;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Imaging_360_P.VideoCapture2_OvFocus
	  section.data(52).logicalSrcIdx = 120;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Imaging_360_P.VideoCapture3_OvBrightness
	  section.data(53).logicalSrcIdx = 121;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Imaging_360_P.VideoCapture3_OvContrast
	  section.data(54).logicalSrcIdx = 122;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Imaging_360_P.VideoCapture3_OvHue
	  section.data(55).logicalSrcIdx = 123;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Imaging_360_P.VideoCapture3_OvSaturation
	  section.data(56).logicalSrcIdx = 124;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Imaging_360_P.VideoCapture3_OvSharpness
	  section.data(57).logicalSrcIdx = 125;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Imaging_360_P.VideoCapture3_OvGamma
	  section.data(58).logicalSrcIdx = 126;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Imaging_360_P.VideoCapture3_OvColorEnable
	  section.data(59).logicalSrcIdx = 127;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Imaging_360_P.VideoCapture3_OvWhiteBalance
	  section.data(60).logicalSrcIdx = 128;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Imaging_360_P.VideoCapture3_OvBacklightCompen
	  section.data(61).logicalSrcIdx = 129;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Imaging_360_P.VideoCapture3_OvGain
	  section.data(62).logicalSrcIdx = 130;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Imaging_360_P.VideoCapture3_OvPan
	  section.data(63).logicalSrcIdx = 131;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Imaging_360_P.VideoCapture3_OvTilt
	  section.data(64).logicalSrcIdx = 132;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Imaging_360_P.VideoCapture3_OvRoll
	  section.data(65).logicalSrcIdx = 133;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Imaging_360_P.VideoCapture3_OvZoom
	  section.data(66).logicalSrcIdx = 134;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Imaging_360_P.VideoCapture3_OvExposure
	  section.data(67).logicalSrcIdx = 135;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Imaging_360_P.VideoCapture3_OvIris
	  section.data(68).logicalSrcIdx = 136;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Imaging_360_P.VideoCapture3_OvFocus
	  section.data(69).logicalSrcIdx = 137;
	  section.data(69).dtTransOffset = 68;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Imaging_360_P.u60view_Y0
	  section.data(1).logicalSrcIdx = 138;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    ;% Auto data (Imaging_360_B)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Imaging_360_B.actualsampletime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_B.reference
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Imaging_360_B.computationtime
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Imaging_360_B.Channel
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Imaging_360_B.VideoCapture_o1
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_B.VideoCapture1_o1
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 921600;
	
	  ;% Imaging_360_B.VideoCapture2_o1
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 1843200;
	
	  ;% Imaging_360_B.VideoCapture3_o1
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 2764800;
	
	  ;% Imaging_360_B.MatrixConcatenate
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 3686400;
	
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
    nTotSects     = 4;
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
    ;% Auto data (Imaging_360_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Imaging_360_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_DW.ComputationTime_BeginTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Imaging_360_DW.ComputationTime_ComputationTime
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Imaging_360_DW.VideoCapture_VideoCapture
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_DW.VideoCapture1_VideoCapture
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Imaging_360_DW.VideoCapture2_VideoCapture
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Imaging_360_DW.VideoCapture3_VideoCapture
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Imaging_360_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_DW.Channel_PWORK.Fifo
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Imaging_360_DW.stich_SubsysRanBC
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Imaging_360_DW.display_SubsysRanBC
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 2662405260;
  targMap.checksum1 = 1149459889;
  targMap.checksum2 = 408158165;
  targMap.checksum3 = 835093224;

