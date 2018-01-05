#include <stdio.h>
#include <stdlib.h>
#define T 20000
#define dt 0.01

double popDengue(double D0, double homem, double libelula, double aguap);
double popHomem(double H0, double comida, double dengue);
double popLibelula(double L0, double dengue);
double popComida(double C0, double homem);
double popAguaParada(double aguaParada0, double homem);

double popHomem(double H0, double comida, double dengue){
        double k0=0.001475, k1=0.0009, k2=0.00017; //Constantes
        double deltaH = H0*(-k0 - k1*dengue + k2*comida)*dt;
        double H = deltaH + H0;
        return H;
}

double popDengue(double D0, double homem, double libelula, double aguap){
        double k0=0.000002, k1=0.001, k2 = 0.000039, k3=0.0000012;//Constantes
        double deltaD = D0*(k0*homem - k1 - k2*libelula + k3*aguap)*dt;
        double D = deltaD + D0;
        return D;
}

double popLibelula(double L0, double dengue){
        double k0=0.051, k1=0.00058; //Constantes
        double deltaL = L0*(-k0 + k1*dengue)*dt;
        double L = deltaL + L0;
        return L;
}

double popComida(double C0, double homem){
        double k0=0.0085, k1=0.00000785; //Constantes
        double deltaC = C0*(k0 - k1*homem)*dt;
        double C = deltaC + C0;
        return C;
}

double popAguaParada(double aguaParada0, double homem){
    double k0=0.018338, k1=0.0000169;
    double deltaAgp = aguaParada0*(-k0 + k1*homem)*dt;
    double Agp = deltaAgp + aguaParada0;
    return Agp;
}

int main(void){
    double i;
    double D, H, L, C, Agp; //Valores finais
    /* D = dengue, H = homem, L = libélula, C = comida, Crt = Crotalária, Ab = Abelha, Agp = Água parada */
    double H0=200, D0=100, L0=40, C0=200, Agp0=40; //Valores iniciais
	FILE *arq = fopen("Dados.txt", "w");
	D=D0; H=H0; L=L0; C=C0; Agp=Agp0;
	int cont=0;
	for (i=0; i<T; i+=dt){
        D = popDengue(D, H, L, Agp);
        H = popHomem(H, C, D);
        L = popLibelula(L, D);
        C = popComida(C, H);
        Agp = popAguaParada(Agp, H);
        //fprintf (arq, "%lf %lf %lf %lf %lf %lf\n", H, D, L, C, Agp, i);
        if(cont%100==0) fprintf (arq, "%lf %lf %lf %lf %lf %lf\n", H, D, L, C, Agp, i); //Filtrar a quantidade de dados
        cont++;
	}
	printf ("%lf %lf %lf %lf %lf %lf\n", H, D, L, C, Agp, i);
	/*Acabando com a libélula*/
	H0=200; D0=100; L0=0; C0=200; Agp0=20; cont=0;
	D=D0; H=H0; L=L0; C=C0; Agp=Agp0;
	FILE *arq2 = fopen("Dados2.txt", "w");
	for (i=0; i<T; i+=dt){
        D = popDengue(D, H, L, Agp);
        H = popHomem(H, C, D);
        L = popLibelula(L, D);
        C = popComida(C, H);
        Agp = popAguaParada(Agp, H);
        //fprintf (arq, "%lf %lf %lf %lf %lf %lf\n", H, D, L, C, Agp, i);
        if(cont%100==0) fprintf (arq2, "%lf %lf %lf %lf %lf %lf\n", H, D, L, C, Agp, i); //Filtrar a quantidade de dados
        cont++;
	}
    printf ("%lf %lf %lf %lf %lf %lf\n", H, D, L, C, Agp, i);
	fclose(arq);
	fclose(arq2);
	return 0;
}

