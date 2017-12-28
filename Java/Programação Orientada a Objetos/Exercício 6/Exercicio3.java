import java.util.Scanner;

public class Exercicio3 {
	public static void main (String args[]){
		System.out.println("Digite um texto em letras maiusculas: ");
		Scanner teclado = new Scanner (System.in);
		String s1;
		s1 = teclado.nextLine();
		System.out.println(s1.toLowerCase());
		System.out.println("Digite um texto em letras minusculas: ");
		s1 = teclado.nextLine();
		System.out.println(s1.toUpperCase());
	}
}
