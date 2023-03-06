close all; clear;

open_system('BicyclePeterCorkePoseReach.slx')

goalPose = [5 5 pi];
initPose = [9 5 pi];

speedLim = 1;
accelLim = 0.2;
steerLim = 0.5236;
wheelBase = 0.256;