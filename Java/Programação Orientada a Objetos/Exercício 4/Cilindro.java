
public class Cilindro extends Circulo{
	private int altura;
	public Cilindro (int x, int y, int raio, int altura){
		super(x, y, raio);
		setAltura(altura);
	}
	public int getAltura() {
		return altura;
	}
	public void setAltura(int altura) {
		if (altura > 0)
			this.altura = altura;
		else
			this.altura = 0;
	}
}
