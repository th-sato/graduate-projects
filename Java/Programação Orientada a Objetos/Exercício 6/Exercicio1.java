import java.util.Scanner;


public class Exercicio1 {
	public static void main (String args[]){
		System.out.println("Digite um texto: ");
		Scanner teclado = new Scanner (System.in);
		String s1;
		s1 = teclado.nextLine();
		System.out.println("Numero de caracteres digitados: " + s1.length());
	}
}
