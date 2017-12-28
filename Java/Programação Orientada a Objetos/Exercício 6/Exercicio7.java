import java.util.Scanner;
import java.util.StringTokenizer;


public class Exercicio7 {
	public static void main (String args[]){
		System.out.println("Digite seu nome: ");
		Scanner teclado = new Scanner (System.in);
		String s1, s2, c1;
		s1 = teclado.nextLine();
		StringTokenizer token = new StringTokenizer (s1);
		int i=0, j=token.countTokens();	
		while(token.hasMoreTokens()){
			s2 = token.nextToken();
			c1 = s2.substring(0, 1);
			if (i==0) System.out.print(s2+ " ");
			else if (i==j-1) System.out.print(s2);
			else{
				if (c1 == c1.toUpperCase()) System.out.print(c1 + ". ");
				else if (i==j-2) System.out.print(s2+" ");
			}
			i++;
		}
		
	}
}
