clear all;
close all;
Distancia = [0.075 0.080 0.083 0.085 0.087]; %Metros
Angulo = [17 13 11.5 10.5 10]; %Grau
plot(log10(Angulo), log10(Distancia), 'o', log10(Angulo), log10(Distancia)), xlabel('log(theta)'), ylabel('log(R)'), title('Relação funcional entre a força e a distância');
%plot(Angulo, Distancia);
%plot(Angulo, sqrt(Distancia), 'o', Angulo, sqrt(Distancia));