import java.util.Scanner;


public class Exercicio6 {
	public static void main(String args[]){
		System.out.println("Digite uma frase: ");
		Scanner teclado = new Scanner (System.in);
		String s1=teclado.nextLine();
		System.out.println("Escolha uma palavra: ");
		String s2=teclado.nextLine();
		System.out.println("Indice: " + s1.indexOf(s2));
	}
}
