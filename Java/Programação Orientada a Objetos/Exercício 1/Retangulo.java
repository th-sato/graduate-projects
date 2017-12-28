
public class Retangulo {
	private int base;
	private int altura;
	public int area(){
		return this.base*this.altura;
	}
	public int perimetro(){
		return (2*this.base + 2*this.altura);
	}
	public double relacao(){
		return (double)this.base/(double)this.altura;
	}
	public void ehQuadrado(){
		if (base==altura) System.out.println("É um quadrado");
		else System.out.println("Não é um quadrado");
	}
	public void imprimirDimensoes(){
		System.out.println("Base do retângulo: "+ base);
		System.out.println("Altura do retângulo: "+ altura);
	}
	public Retangulo(int base, int altura){
		this.base = base;
		this.altura = altura;
	}
}
