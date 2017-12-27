clear all
close all

x = [0:0.1:7];
y1 = linspace(16,16,71);
y2 = CustoVariavel(x);
y3 = CustoTotalMedio(x);
y4 = CustoVariavelMedio(x);
y5 = CustoMarginal(x);
plot(x,y1,x,y2,x,y3,x,y4,x,y5);
legend('Custo fixo', 'Custo vari�vel', 'Custo total m�dio', 'Custo vari�vel m�dio', 'Custo marginal');

title('Comportamento dos custos');
xlabel('Produ��o');
ylabel('Custo');