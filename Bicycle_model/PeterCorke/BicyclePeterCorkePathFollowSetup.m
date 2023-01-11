close all; clear;

open_system('BicyclePeterCorkePathFollow.slx')

initCoord = [0 0 0];
path = butterfly(8,8);

speedLim = 1;
accelLim = 1;
steerLim = 1;
wheelBase = 1;

simulation = sim('BicyclePeterCorkePathFollow.slx');
position = simulation.position.Data;
angle = simulation.angle.Data;

plot(position(:,1), position(:,2))
hold on
plot(initCoord(1), initCoord(2), '*r')
text(initCoord(1), initCoord(2), 'Start');

function p=butterfly(width, height)
    freq = 2*pi/30;
    Ts = 0.1; % Sampling time
    t = 0:Ts:30; % Simulation time
    xRef = 0 + width*sin(freq*t);
    yRef = 0 - height*sin(2*freq*t);
%     plot(xRef, yRef, "+");
%     title('Butterfly');
    p=[0 xRef ; 0 yRef]';
end