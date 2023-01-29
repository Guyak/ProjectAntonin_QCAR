%% DC Motor RL - George Claudiu Andrei

clc
clear all
close all

%{ 

DATA

For this example, we will assume that the input of the system is the voltage source ($V$) applied to the motor's armature,
while the output is the rotational speed of the shaft $\dot{\theta}$. The rotor and shaft are assumed to be rigid.
 We further assume a viscous friction model, that is, the friction torque is proportional to shaft angular velocity.

The physical parameters for our example are:

(J)     moment of inertia of the rotor     0.01 kg.m^2
(b)     motor viscous friction constant    0.1 N.m.s
(Ke)    electromotive force constant       0.01 V/rad/sec
(Kt)    motor torque constant              0.01 N.m/Amp
(R)     electric resistance                1 Ohm
(L)     electric inductance                0.5 H

%}
 

%% Physical Data

J = 0.1;
b = 0.1;
K = 0.11;
R = 1;
L = 0.5;

%% Define the sample time Ts and simulation duration T in seconds.
Ts = 0.1;
T = 10;
%% Open the model

mdl = 'Motor_Model_leadlag'
% open_system(mdl);
agent = [mdl '/RL Agent'];

%% Environment Interface

obsInfo = rlNumericSpec([2 1]); % Defining the obs of the environment (Speed and Error)

actInfo = rlFiniteSetSpec(0:Ts:12);  
%% Create the Environment

%env = rlSimulinkEnv("modelname",...  "modelname/RL agent block name",... obsInfo,actInfo)
env = rlSimulinkEnv(mdl,agent,obsInfo,actInfo);

%% Create DQN agent

%{

A DQN agent approximates the long-term reward, given observations and actions,
using a value function critic representation. 
DQN agents can use multi-output Q-value critic approximators, which are generally more efficient.
A multi-output approximator has observations as inputs and state-action values as outputs.
Each output element represents the expected cumulative long-term reward for taking
the corresponding continue action from the state indicated by the observation inputs.

%}

% Fix the random generator seed for reproducibility.
rng(0)

nI = obsInfo.Dimension(1);  % number of inputs (2)


nO = numel(actInfo.Elements);    % number of outputs (from -10 to 10 V)

dnn = [
    featureInputLayer(2,"Name","InputLayer_observations","Normalization","none")
    fullyConnectedLayer(32,"Name","fullyConnectedNetwork_1")
    leakyReluLayer(0.01,"Name","leakyrelu_1")
    fullyConnectedLayer(32,"Name","fullyConnectedLayer_2")
    leakyReluLayer(0.01,"Name","leakyrelu_2")
    fullyConnectedLayer(32,"Name","fullyConnectedLayer_3")
    leakyReluLayer(0.01,"Name","leakyrelu_3")
    fullyConnectedLayer(nO,"Name","fullyConnected_Layer_5")];

% dnn = [
%     featureInputLayer(nI,'Normalization','none','Name','state')
%     fullyConnectedLayer(nL_1,'Name','fc1')
%     reluLayer('Name','relu1')
%     fullyConnectedLayer(nL_2,'Name','fc2')
%     reluLayer('Name','relu2')
%     fullyConnectedLayer(nL_3,'Name','fc3')
%     reluLayer('Name','relu3')
%      fullyConnectedLayer(nL_3,'Name','fc4')
%     reluLayer('Name','relu4')
%     fullyConnectedLayer(nO,'Name','fc4')];
dnn = dlnetwork(dnn);

%% View Network Configuration
figure;
plot(layerGraph(dnn));

%% Critic Specifications

%Specify options for the critic optimizer using rlOptimizerOptions for the Agent.

criticOptions = rlOptimizerOptions('LearnRate',1e-4,'GradientThreshold',1,'L2RegularizationFactor',1e-4);

%{
Create the critic representation using the specified deep neural network and options.
We must also specify the action and observation info for the critic, which you obtain from the environment interface.
%}

critic = rlVectorQValueFunction(dnn,obsInfo,actInfo);

% To create the DQN agent, first specify the DQN agent options using rlDQNAgentOptions.

agentOptions = rlDQNAgentOptions(...
    'DiscountFactor',0.995,...
    'SampleTime',Ts,...
    'TargetSmoothFactor',1e-4,...
    'UseDoubleDQN',true,...
    'CriticOptimizerOptions',criticOptions,...
    'ExperienceBufferLength',1e6,...
    'MiniBatchSize',128);

agentOptions.EpsilonGreedyExploration.Epsilon = 0.9;
agentOptions.EpsilonGreedyExploration.EpsilonDecay = 1e-5;
agentOptions.EpsilonGreedyExploration.EpsilonMin = .02;

agent = rlDQNAgent(critic,agentOptions);

criticNet = getModel(getCritic(agent));

plot(layerGraph(criticNet));


%% Train The Agent

%{

To train the agent, first specify the training options. For this example, use the following options:
Run each training episode for at most 5000 episodes, with each episode lasting at most ceil(T/Ts) time steps.
Display the training progress in the Episode Manager dialog box (set the Plots option to training-progress)
and disable the command line display (set the Verbose option to false).
Stop training when the episode reward reaches –1. 
Save a copy of the agent for each episode where the cumulative reward is greater than –2.5.

%}

opt = rlTrainingOptions(...
    'MaxEpisodes',1000,...
    'MaxStepsPerEpisode',1000,...
    'Verbose',true,...
    'Plots',"training-progress",...
    'StopTrainingCriteria',"AverageReward",...
    'ScoreAveragingWindowLength',100,...
    'StopTrainingValue',1000);

%{
    - Stop Training Criteria = "AverageReward" => Save the agent when the running average reward over
    all episodes equals or exceeds the critical value which is 480.

    - Score Averaging Window Lenght => 5 (by default)

    - Vergose = " True " - Display training progress on the command line, specified as the logical values false (0) or true (1).
    Set to true to write information from each training episode to the MATLAB command line during training.
        
%}

trainResults = train(agent,env,opt);
% Train the agent using the train function.
% Training is a computationally intensive process that takes several hours to complete.
% To save time while running this example,



    