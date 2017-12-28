
public class Reta implements Relacao{
	private int x1, y1;
	private int x2, y2;
	public Reta (int x1, int y1, int x2, int y2){
		this.x1 = x1;
		this.x2 = x2;
		this.y1 = y1;
		this.y2 = y2;
	}
	public double distancia (){
		return Math.sqrt(x1*x2 + y1*y2);
	}
	public boolean maiorQue(Object b) {
		if (distancia() > ((Reta) b).distancia())return true;
		else return false;
	}
	public boolean menorQue(Object b) {
		if (distancia() < ((Reta) b).distancia())return true;
		else return false;
	}
	public boolean igualA(Object b) {
		if (((Reta) b).distancia() == distancia())return true;
		else return false;
	}
	
}
