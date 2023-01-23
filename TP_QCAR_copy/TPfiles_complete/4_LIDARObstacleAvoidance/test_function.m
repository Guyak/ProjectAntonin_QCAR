[speed, steering, Y] = avoidanceStrategy(0.4, 20*pi/180, 0.2)

function [speed , steering, Y]  = avoidanceStrategy(distance, headings, desired_speed)
    X = headings == 0*pi/180
    
    X1 = headings <= 30*pi/180
    X2 = headings >= 330*pi/180
    
    Y = distance <= 0.5 & distance >= 0.1
    Y1 = distance <= 1 & distance >= 0.1
    
    calc1 = X1.*Y1
    calc4 = X2.*Y1
    
   
    if max(calc1) == 1 && max(calc4) == 1 %  in the cone, atleast one point is present in point cloud map
        if sum(calc1) > sum(calc4)
            speed = desired_speed;
            steering = 0.5; % angle is proposed for steering, 0.5 seeme the maximum that it can turn to
        else
            speed = desired_speed;
            steering = -0.5;
        end
    
    else
        speed =desired_speed;
        steering = 0;
    end
end