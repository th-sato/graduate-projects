
public class Triangulo {
	private double base;
	private double altura;
	private double lado1;
	private double lado2;
	private double lado3;
	public double area(){
		double p = (lado1+lado2+lado3)/2;
		return Math.sqrt(p*(p-lado1)*(p-lado2)*(p-lado3));
	}
	public int ehTriangulo(){
		if (Math.abs (getLado1() - getLado2()) < getLado3() &&
		getLado3()<(getLado1()+getLado2())
		&& Math.abs (getLado1() - getLado3())<getLado2() &&
		(getLado1() + getLado3())>getLado2() &&
		Math.abs (getLado2() - getLado3())<getLado1() &&
		(getLado2() + getLado3())>getLado1())
			return 1;
		else return 0;
			
	}
	public double perimetro(){
		return lado1+lado2+lado3;
	}
	public void mostra(){
		System.out.println("A base do triângulo é " + base);
		System.out.println("A altura do triângulo é " + altura);
	}
	public double getBase(){
		return this.base;
	}
	public double getLado1() {
		return lado1;
	}
	public void setLado1(double lado1) {
		this.lado1 = lado1;
	}
	public double getLado2() {
		return lado2;
	}
	public void setLado2(double lado2) {
		this.lado2 = lado2;
	}
	public double getLado3() {
		return lado3;
	}
	public void setLado3(double lado3) {
		this.lado3 = lado3;
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
