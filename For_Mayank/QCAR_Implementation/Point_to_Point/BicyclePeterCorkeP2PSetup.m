close all; clear;

open_system('BicyclePeterCorkeP2P_QCAR.slx')

goalCoord = [0 -2];
initCoord = [0 0 0];

speedLim = 0.2;
accelLim = 0.1;
steerLim = 0.5236;
wheelBase = 0.256;