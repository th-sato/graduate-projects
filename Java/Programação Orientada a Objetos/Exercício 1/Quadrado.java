
public class Quadrado {
	private double lado;
	public double area(){
		return lado*lado;
	}
	public void mostrar(){
		System.out.println("A área do quadrado é: " + area());
	}
	public void aumentarQuadrado(double lado){
		this.lado += lado;
	}
	public Quadrado(double lado){
		this.lado = lado;
	}
}
