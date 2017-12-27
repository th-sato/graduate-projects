clear all;
close all;

%Rejeita faixa
NUM = poly([180 180]);
DEM = poly([32 1000]);

%Passa faixa
%NUM = poly([0]);
%DEM = poly([100 1000]);

G = tf(NUM, DEM);

bode(G);