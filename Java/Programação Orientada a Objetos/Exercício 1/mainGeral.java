
public class mainGeral {
	public static void main (String[] args) {
		Triangulo t1 = new Triangulo();
		t1.setBase(20);
		t1.setAltura(40);
		t1.mostra();
		Triangulo t2 = new Triangulo(10, 30);
		t2.mostra();
		System.out.println();
		
		Retangulo r1 = new Retangulo(10, 40);
		System.out.println("A área do retângulo é " + r1.area());
		System.out.println("O perímetro do retângulo é " + r1.perimetro());
		System.out.println("Relação entre a base e altura: " + r1.relacao());
		r1.ehQuadrado();
		r1.imprimirDimensoes();
		System.out.println();
		
		int qtd_quadrados=10;
		double soma=0;
		Quadrado q1 = new Quadrado(10);
		q1.mostrar();
		q1.aumentarQuadrado (5);
		q1.mostrar();
		Quadrado[] q10 = new Quadrado [qtd_quadrados];
		for (int i=0; i<qtd_quadrados; i++){
			q10[i] = new Quadrado(15*Math.random());
			soma += q10[i].area();
		}
		System.out.println("A soma das áreas dos " + qtd_quadrados +" quadrados é: " + soma);
		System.out.println();
		
		Contador c1 = new Contador();
		c1.incrementar();
		c1.incrementar(10);
		c1.mostrarValor();
		c1.decrementar();
		c1.decrementar(4);
		c1.mostrarValor();
		Contador c2 = new Contador(10);
		c2.incrementar();
		c2.incrementar(5);
		c2.mostrarValor();
		c2.decrementar();
		c2.decrementar(7);
		c2.mostrarValor();
		
	}
}
