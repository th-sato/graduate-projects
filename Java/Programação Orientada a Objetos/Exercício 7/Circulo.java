
public class Circulo extends Figura{
	private double raio;
	public double getArea(){
		return Math.PI*raio*raio;
	}
	public String toString(){
		return "É um círculo";
	}
	public Circulo (double raio){
		this.raio = raio;
	}
}
