
import java.util.Scanner;

public class Exercicio2 {
	public static double media (double vetor[], int fim){
		double soma = 0;
		for (int i=0; i <fim; i++){
			soma += vetor[i];
		}
		return soma/fim;
	}
	
	public static void main(String[] args) {
		double vetor[] = new double [100];
		Scanner teclado = new Scanner (System.in);
		int i=0;
		double valor = teclado.nextDouble();
		while(valor!=0){
			vetor[i] = valor;
			valor = teclado.nextDouble();
			//System.out.println(vet[i]);
			i++;
		}
		double media = media(vetor, i);
		System.out.println(media);
	}
}
