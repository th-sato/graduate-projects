
public class Triangulo extends Figura{
	private double base, altura;
	public double getArea(){
		return (base*altura)/2;
	}
	public String toString(){
		return "É um triângulo";
	}
	public Triangulo(double base, double altura){
		this.base = base;
		this.altura = altura;
	}
}
