import java.util.Scanner;


public class Exercicio5 {
	public static void main (String args[]){
		System.out.println("Digite uma frase: ");
		Scanner teclado = new Scanner (System.in);
		String s1, s2, s3;
		s1 = teclado.nextLine();
		System.out.println("Escolha uma das palavras escrita: ");
		s2 = teclado.nextLine();
		System.out.println("Escolha uma palavra para substituir a anterior: ");
		s3 = teclado.nextLine();
		System.out.println(s1.replace(s2, s3));
	}
}
