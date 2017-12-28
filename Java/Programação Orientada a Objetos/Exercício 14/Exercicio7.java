
public class Exercicio7 {
	static void imprimeAlgo(int nivel) {
		if (nivel == 0) {
			System.out.print("*");
		}
		else{
			System.out.print("[");
			imprimeAlgo(nivel - 1);
			System.out.print(",");
			imprimeAlgo(nivel - 1);
			System.out.println("]");
		}
	}
	public static void main(String[] args) {
		Exercicio7 test = new Exercicio7 ();
		test.imprimeAlgo(0);
		System.out.println();
		test.imprimeAlgo(1);
		System.out.println();
		test.imprimeAlgo(2);
		System.out.println();
		test.imprimeAlgo(3);
		System.out.println();
	}
	
}