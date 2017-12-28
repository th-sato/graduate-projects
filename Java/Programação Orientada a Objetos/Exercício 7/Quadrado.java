
public class Quadrado extends Retangulo{
	public double getArea(){
		return super.getArea();
	}
	public String toString(){
		return "É um quadrado";
	}
	public Quadrado (double lado){
		super(lado, lado);
	}
}
