
public class Circulo extends Point{
	private int raio;
	public Circulo(int x, int y, int raio){
		super(x,y);
		setRaio(raio);
	}
	public int getRaio() {
		return raio;
	}
	public void setRaio(int raio) {
		if (raio>0)
			this.raio = raio;
		else raio = 0;
	}
}
