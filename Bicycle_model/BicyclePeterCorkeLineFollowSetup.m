close all; clear;

open_system('BicyclePeterCorkeLineFollow.slx')

L = [2 -2 4];
initCoord = [8 0 pi/2];

speedLim = 1;
accelLim = 1;
steerLim = 1;
wheelBase = 1;

simulation = sim('BicyclePeterCorkeLineFollow.slx');
position = simulation.position.Data;
angle = simulation.angle.Data;

plot(position(:,1), position(:,2))
hold on
plot(initCoord(1), initCoord(2), '*r')
text(initCoord(1), initCoord(2), 'Start');
x = min(position(:,1))-1:max(position(:,1))+1;
plot(x, ((L(1)/-L(2))*x+(L(3)/-L(2))), 'k--')

