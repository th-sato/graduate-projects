import java.util.Scanner;


public class InputOutput {
	public static void main (String args[]){
		System.out.println("Você deseja criar um quadrado (digite 0) ou um triângulo (digite 1)?");
		Scanner teclado = new Scanner(System.in);
		int escolha, cont=0;
		escolha = teclado.nextInt();
		while ((escolha!=0 || escolha!=1) && cont==0){
			if (escolha==0){
				System.out.print("Digite o valor do lado do quadrado: ");
				Quadrado q = new Quadrado (teclado.nextInt());
				System.out.println("Área do quadrado: "+ q.area());
				System.out.println("Perímetro do quadrado: " + q.perimetro());
				cont++;
			}
			else if (escolha == 1){
				Triangulo t = new Triangulo();
				System.out.println("Digite os dados do triângulo: ");
				System.out.print("*Lado 1: ");
				t.setLado1(teclado.nextInt());
				System.out.print("*Lado 2: ");
				t.setLado2(teclado.nextInt());
				System.out.print("*Lado 3: ");
				t.setLado3(teclado.nextInt());
				if (t.ehTriangulo()==1){
					System.out.println("Área do triângulo: "+ t.area());
					System.out.println("Perímetro do triângulo: " + t.perimetro());
					if (t.getLado1()==t.getLado2() && t.getLado2() == t.getLado3())
						System.out.println("O triângulo é equilatéro!");
					else if (t.getLado1()==t.getLado2() || t.getLado2() == t.getLado3()
							|| t.getLado1()==t.getLado3())
						System.out.println("O triângulo é isósceles!");
					else{
						System.out.println("O triângulo é escaleno!");
					}
				}
				else {
					System.out.println("Erro!");
				}
				cont++;
			}
			if(cont==0){
				System.out.println("Você deseja criar um quadrado (digite 0) ou um triângulo (digite 1)?");
				escolha = teclado.nextInt();
			}
		}
	}
}
