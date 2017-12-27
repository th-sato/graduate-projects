close all;
clear all;

num = [(-18/8.2)*3141.6 0];
%den = [1 (10^4)/8.2];
den = poly([3141.6 628]);

G = tf(num, den);

bode(G);

grid on;
