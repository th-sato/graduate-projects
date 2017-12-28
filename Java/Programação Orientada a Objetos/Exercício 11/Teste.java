public class Teste {
	public static void main(String[] args) throws Excecao1 {
		//int v[] = new int[3];
		//int a =10/0;
		System.out.println(m(10));
		System.out.println(m(11));
		System.out.println(m(5));

	}
	
	/*public static int m(int a){
		if (a > 10 || a < 0){*/
			/*
			IllegalArgumentException e = new 
					IllegalArgumentException("Argumento inválido");
			throw e; //Lançar exceção
			*/
			/*throw new IllegalArgumentException("Argumento inválido");
		}
		return a;
	}*/
	public static int m(int a) throws Excecao1{
		if (a > 10 || a < 0){
			throw new Excecao1("Argumento inválido");
		}
		return a;
	}
	
}
