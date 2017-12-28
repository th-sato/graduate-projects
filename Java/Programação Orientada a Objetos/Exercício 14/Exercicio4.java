
import java.util.Arrays;
import java.util.Scanner;

public class Exercicio4 {
	public static void main(String[] args) {
		System.out.println("Tamanho do vetor: ");
		Scanner teclado = new Scanner (System.in);
		int vet[] =  new int[teclado.nextInt()];
		int valor, i=0;
		for (int j=0; j < vet.length; j++){
			valor = teclado.nextInt();
			vet[j] = valor;
			//System.out.println(vet[i]);
		}
		Arrays.sort(vet, 0, vet.length);
		System.out.println();
		System.out.println(vet[vet.length - 1]);
	}
}
