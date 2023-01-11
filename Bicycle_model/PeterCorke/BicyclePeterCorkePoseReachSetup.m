close all; clear;

open_system('BicyclePeterCorkePoseReach.slx')

goalPose = [5 5 pi/2];
initPose = [9 5 0];

speedLim = 1;
accelLim = 1;
steerLim = 1;
wheelBase = 1;

simulation = sim('BicyclePeterCorkePoseReach.slx');
position = simulation.position.Data;
angle = simulation.angle.Data;

plot(position(:,1), position(:,2))
hold on
plot(initPose(1), initPose(2), '*r')
text(initPose(1), initPose(2), 'Start');
plot(goalPose(1), goalPose(2), '*r')
text(goalPose(1), goalPose(2), 'Goal');