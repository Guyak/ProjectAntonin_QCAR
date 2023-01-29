%% Augmented_DDPG_DCMotor- George Claudiu Andrei

clc
clear all
close all


%{ 
% 
DATA

For this example, we will assume that the input of the system is the voltage source (V) applied to the motor's armature,
while the output is the rotational speed of the shaft ydot_meas. The rotor and shaft are assumed to be rigid.
We further assume a viscous friction model, that is, the friction torque is proportional to shaft angular velocity.

The physical parameters for our example are:

(J)     moment of inertia of the rotor     0.01 kg.m^2
(b)     motor viscous friction constant    0.1 N.m.s
(Ke)    electromotive force constant       0.01 V/rad/sec
% (Kt)    motor torque constant              0.01 N.m/Amp
(R)     electric resistance                0.758 Ohm
(L)     electric inductance                0.5 H

%}

%% Physical Setup

J = 0.1;
b = 0.1;
K = 0.11;
R = 1;
L = 0.5;

%% Open the model

mdl = 'Motor_Model_DDPG'
% open_system(mdl);
agent = [mdl '/RL Agent'];

%% Define the sample time Ts 
Ts = 0.1;

%% Q Gain of LQR
Q=20;
Rr = 0.01;
%% Environment Interface

obsInfo = rlNumericSpec([4 1]); % Defining the continuous Observation State Vector
% you can define the limits of each variable using rlNumericSpec 

actInfo = rlNumericSpec([1 1],'LowerLimit',-1,'UpperLimit',1);% Defining the continuous Action State Vector;


%% Create the Environment

%env = rlSimulinkEnv("modelname",...  "modelname/RL agent block name",... obsInfo,actInfo)
% environements from utside the simulink can also 
env = rlSimulinkEnv(mdl,agent,obsInfo,actInfo);

rng(0)

%% Designing Critic

obsPath = [featureInputLayer(4,'Normalization','none','Name',"Obs")
    fullyConnectedLayer(16,"Name","fc1")
    leakyReluLayer(0.5,"Name","leakyrelu1")
    fullyConnectedLayer(16,"Name","fc2")
    additionLayer(2,"Name","add")
    leakyReluLayer(0.5,"Name","leakyrelu2")
    fullyConnectedLayer(16,"Name","fc3")
    leakyReluLayer(0.5,"Name","leakyrelu3")
    fullyConnectedLayer(1,"Name","fc4")];


actPath = [featureInputLayer(1,"Normalization","none","Name","act")
    fullyConnectedLayer(16,"Name","fc5")]; %only one here as per the existing the examples. 

%standard step
criticNetwork = layerGraph(obsPath);
  %adding the obs (states) and actions to compose...
%the total input (state+action)  
criticNetwork = addLayers(criticNetwork,actPath);

%connce the layers using actpath based feedforward NN
criticNetwork = connectLayers(criticNetwork,'fc5','add/in2');

%standard step , object creation.
criticNetwork = dlnetwork(criticNetwork);

criticOptions = rlOptimizerOptions('LearnRate',1e-4,'GradientThreshold',1,'L2RegularizationFactor',1e-4);
%to disctinguius between V funciton, Qfunction
critic = rlQValueFunction(criticNetwork,obsInfo,actInfo);


%% Designing Deterministic Actor

%{

For continuous actions, the final layer of a deterministic actor network should have one neuron for each action.  
If the actions are bounded, you can use a transfer function (such as a tanh layer) 
or a scaling layer to keep the output values within given ranges.

%}

actnet = [featureInputLayer(4,"Normalization",'none',"Name","Observations")
    fullyConnectedLayer(16,"Name","fca1")
    reluLayer("Name","relua1")
    fullyConnectedLayer(16,"Name","fca2")
    reluLayer("Name","relua2")
     fullyConnectedLayer(16,"Name","fca3")
    reluLayer("Name","relua3")
    fullyConnectedLayer(1,"Name","fca5") % this is the dimension of the output control ( 1 here), 
    %this in turn determines the number of ports in line 76
    tanhLayer('Name','tanh1')];

actorNetwork = dlnetwork(actnet);
actorOptions = rlOptimizerOptions('LearnRate',1e-3,'GradientThreshold',1,'L2RegularizationFactor',2e-4);
actor = rlContinuousDeterministicActor(actnet,obsInfo,actInfo);


%% Defining the DDPG Agent

% ou can use the rlDDPGAgent function to make a Deep Deterministic Policy Gradient agent
% from a deterministic actor and a Q-value critic.

agentOptions = rlDDPGAgentOptions(...
    'DiscountFactor',0.995,...
     "TargetSmoothFactor",1e-3,...
    'SampleTime',Ts,...
    'ActorOptimizerOptions',actorOptions,...
    'CriticOptimizerOptions',criticOptions,...
    'MiniBatchSize',128,...
    'ExperienceBufferLength',1e6);
agentOptions.NoiseOptions.Variance = 1*0.1/sqrt(Ts);% VERY IMPORTANT
agentOptions.NoiseOptions.VarianceDecayRate = 1e-6;

agent = rlDDPGAgent(actor,critic,agentOptions);

%training parameters
maxepisodes = 100;
%maxsteps = ceil(500/Ts);
opt = rlTrainingOptions(...
    'MaxEpisodes',maxepisodes,...
    'MaxStepsPerEpisode',600,...% this means 600*0.1 no of seconds=60 , with Ts=0.1
    'Verbose',false,...
    'Plots','training-progress',...
    'StopTrainingCriteria','EpisodeReward',...
    'StopTrainingValue',100000,...
    'SaveAgentCriteria','EpisodeReward',...
    'SaveAgentValue',1000000);

trainResults = train(agent,env,opt);
% trainResults.TrainingOptions.MaxEpisodes=2000;
% trainResults = train(agent,env,trainResults); %this is to continue the
% training process and 
