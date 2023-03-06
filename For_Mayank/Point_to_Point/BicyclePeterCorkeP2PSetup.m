close all; clear;

open_system('BicyclePeterCorkeP2P.slx')

goalCoord = [5 5];
initCoord = [8 5 2*pi/3];

speedLim = 1;
accelLim = 1;
steerLim = 1;
wheelBase = 1;

simulation = sim('BicyclePeterCorkeP2P.slx');
position = simulation.position.Data;
angle = simulation.angle.Data;

plot(position(:,1), position(:,2))
hold on
plot(initCoord(1), initCoord(2), '*r')
text(initCoord(1), initCoord(2), 'Start');
plot(goalCoord(1), goalCoord(2), '*r')
text(goalCoord(1), goalCoord(2), 'Goal');