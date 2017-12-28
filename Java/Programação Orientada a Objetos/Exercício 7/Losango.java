
public class Losango extends Paralelogramo{
	public double getArea(){
		return super.getArea()/2;
	}
	public String toString(){
		return "É um losango";
	}
	public Losango (double diagonalMaior, double diagonalMenor){
		super(diagonalMaior, diagonalMenor);
	}
}
