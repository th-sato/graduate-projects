
import java.util.Arrays;
import java.util.Scanner;

public class Exercicio1 {
	public static void main(String[] args) {
		Scanner teclado = new Scanner (System.in);
		int vet[] =  new int[100];
		int valor, i=0;
		valor = teclado.nextInt();
		while(valor!=0){
			vet[i] = valor;
			valor = teclado.nextInt();
			//System.out.println(vet[i]);
			i++;
		}
		Arrays.sort(vet, 0, i);
		System.out.println();
		for(int j=0; j<i; j++){
			System.out.print(vet[j]+" ");
		}
		System.out.println();
	}
}
