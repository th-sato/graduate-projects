
public class Triangulo {
	private double base;
	private double altura;
	public double area(){
		return (base*altura)/2;
	}
	public void mostra(){
		System.out.println("A base do triângulo é " + base);
		System.out.println("A altura do triângulo é " + altura);
	}
	public double getBase(){
		return this.base;
	}
	public double getAltura(){
		return this.altura;
	}
	public void setBase (double base){
		this.base = base;
	}
	public void setAltura (double altura){
		this.altura = altura;
	}
	public Triangulo(){
		this.base = 1;
		this.altura = 1;
	}
	public Triangulo(double base, double altura){
		this.base = base;
		this.altura = altura;
	}
}
