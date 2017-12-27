clear all;
close all;

M = [0.00002 0.00004 0.00006]; %Em kg
M = M.*(9.8); %Peso (N)
D = [350 481 620]; % Em graus
plot(D, M, 'o', D, M), xlabel('�ngulo (�)'), ylabel('Peso (N)'), title('For�a peso x �ngulo');
KT = (M(3)-M(1))/(D(3) - D(1)); % N/�