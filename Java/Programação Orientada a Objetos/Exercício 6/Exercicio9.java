import java.util.Scanner;


public class Exercicio9 {
	public static void main (String args[]){
		System.out.println("Quantidade de palavras a ser informada: ");
		Scanner teclado = new Scanner (System.in);
		int N = teclado.nextInt();
		String s2;
		for (int i=0; i<N; i++){
			System.out.println("Digite a palavra e a letra: ");
			String s1 = teclado.next();
			String c1 = teclado.next();
			int j=0, cont=0;
			while(j<s1.length()){
				s2 = s1.substring(j, j+1);
				if (s2.equals(c1)) cont++;
				j++;
			}
			System.out.println(cont);
		}
	}
}
