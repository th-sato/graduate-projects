K = [0:0.1:7];
L = 10./K;
plot3(K, L, ex15(K,L));
xlabel('K');
ylabel('L');
zlabel('Custo');
title('Gr�fico do custo em fun��o de K e L');
