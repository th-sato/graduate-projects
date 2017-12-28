
public class Paralelogramo extends Figura{
	private double base;
	private double altura;
	public double getArea(){
		return base*altura;
	}
	public String toString(){
		return "É um paralelogramo";
	}
	public Paralelogramo (double base, double altura){
		this.base = base;
		this.altura = altura;
	}
}
