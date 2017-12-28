import java.util.Scanner;


public class Exercicio8 {
	public static void main (String args[]){
		String s1, s2 = "f", s3;
		Scanner teclado = new Scanner (System.in);
		do {
			System.out.println("Digite um texto: ");
			s1 = teclado.next();
			s2 = s1.substring(0,1);
			System.out.print(s2+" ");
			System.out.println(s1.substring(s1.length()-1,s1.length()));
			s3 = s1.substring(0,1);
		}while(s2.equalsIgnoreCase("f")==false);
	}
}
