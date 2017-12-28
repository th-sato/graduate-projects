
import java.util.Scanner;


public class Exercicio3 {
	public static void main(String[] args) {
		Funcionario f = null;
		System.out.println("Número de funcionários: ");
		Scanner teclado = new Scanner (System.in);
		int i = teclado.nextInt();
		Funcionario vetor [] = new Funcionario [i];
		for (int j = 0; j < i; j++){
			vetor[i] = new Funcionario (teclado.next(), teclado.next(), teclado.nextDouble(), teclado.nextInt());
			//vetor[i] = new Funcionario ("Teste", "t", 4, 1);
		}
		System.out.println("Valor de X: ");
		Funcionario.funcionarios(vetor, teclado.nextInt());
	}
}