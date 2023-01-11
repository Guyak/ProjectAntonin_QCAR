close all; clear;

open_system('BicyclePeterCorkePathFollow.slx')

initCoord = [0 0 0];
path = butterfly(8,8);
%path = circle(0,0,1);

plot(path(:,1), path(:,2), '*')

speedLim = 1;
accelLim = 1;
steerLim = 1;
wheelBase = 1;

simulation = sim('BicyclePeterCorkePathFollow.slx');
position = simulation.position.Data;
angle = simulation.angle.Data;

figure()
plot(position(:,1), position(:,2))
hold on
plot(initCoord(1), initCoord(2), '*r')
text(initCoord(1), initCoord(2), 'Start');
xlim([-8 8])
ylim([-8 8])

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

function p=circle(x,y,r)
%create and plot a circle with radius r and origin (x,y)
    ang=(2*pi/64):(2*pi/64):2*pi; 
    xp=r*cos(ang);
    yp=r*sin(ang);
    plot(x+xp,y+yp,"+");
    p=[xp;yp]';
end