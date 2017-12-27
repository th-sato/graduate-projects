clear all;
close all;

M = [0.00002 0.00004 0.00006]; %Em kg
M = M.*(9.8); %Peso (N)
D = [350 481 620]; % Em graus
plot(D, M, 'o', D, M), xlabel('Ângulo (º)'), ylabel('Peso (N)'), title('Força peso x Ângulo');
KT = (M(3)-M(1))/(D(3) - D(1)); % N/º