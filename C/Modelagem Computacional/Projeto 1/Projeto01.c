#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define delta_t 0.01
#define pi 3.14

main(){
    float v0, h0, theta, m, k, t0=0, g=10;
    FILE* arquivo = fopen("Dados.txt", "w");
    //Leitura de dados
    printf("Velocidade inicial (m/s): ");
    scanf ("%f", &v0);
    printf ("Altura inicial do corpo (m): ");
    scanf ("%f", &h0);
    printf ("Ângulo de lançamento (Graus): ");
    scanf ("%f", &theta);
    //Convertendo o valor do ângulo para radianos
    theta = (pi*theta)/180;
    printf ("Massa do corpo (kg): ");
    scanf ("%f", &m);
    printf ("Parâmetro do atrito: ");
    scanf ("%f", &k);
    //Dividindo a velocidade nos eixos x e y.
    float v0x = v0 * cos(theta), v0y = v0 * sin(theta);
    float t, v=v0, vx=v0x, vy=v0y, h=h0;
    //Energia Potencial (K), Energia potencial gravitacional (U) e Energia total (Mecânica - E)
    float K=(m*pow(v0, 2))/2, U=m*g*h0, E=K+U;
    fprintf(arquivo, "%f, ", h0);
    fprintf(arquivo, "%f, ", v0);
    fprintf(arquivo, "%f, ", t0);
    fprintf(arquivo, "%f, ", K);
    fprintf(arquivo, "%f, ", U);
    fprintf(arquivo, "%f\n", E);
    for (t=delta_t; h>0; t+=delta_t){
        //velocidade em x
        vx = vx - ((k*vx)/m)*delta_t;
        //velocidade em x
        vy = vy + (-g - (k*vy)/m)*delta_t; //Colocamos a gravidade, valendo 9.8. Porém, ela vale -9.8 já que a força da gravidade é sempre contrária ao eixo positivo em y.
        //módulo da velocidade
        v = sqrt(pow(vx,2)+pow(vy,2));
        h = h + vy * delta_t;
        //Caso a altura seja negativa, colocamos o valor dela como zero assim como a velocidade em y e recalculamos o módulo da velocidade.
        if(h<0) {
            h=0;
            vy=0;
            v = sqrt(pow(vx,2)+pow(vy,2));
        }
        fprintf(arquivo, "%f, ", h);
        fprintf(arquivo, "%f, ", v);
        fprintf(arquivo, "%f, ", t);
        //energia cinética
        K=(m*pow(v, 2))/2;
        fprintf(arquivo, "%f, ", K);
        //energia potencial
        U=m*g*h;
        fprintf(arquivo, "%f, ", U);
        //energia total
        E=K+U;
        fprintf(arquivo, "%f\n", E);
    }
    //fechar o arquivo
    fclose(arquivo);
}

