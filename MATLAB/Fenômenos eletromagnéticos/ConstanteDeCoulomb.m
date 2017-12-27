clear all;
close all;
KT = 1.4519*10^-06;
carga = 6*10^-9;
%carga = 1*10^-3;
Distancia = [0.075 0.080 0.083 0.085 0.087]; %Metros
Distancia = Distancia + 0.04;
Angulo = [17 13 11.5 10.5 10]; %Grau
K = CalculoDaConstante(Distancia, Angulo, KT, carga);
KC = mean(K);