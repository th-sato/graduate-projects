
public class CarroContador {
	private String marca, placa;
	private int kilometragem;
	private Contador vezesAcelerou = new Contador();
	private Contador vezesFreou = new Contador();
	private Contador vezesLigou = new Contador();
	public Contador getVezesFreou() {
		return vezesFreou;
	}
	public void setVezesFreou(Contador vezesFreou) {
		this.vezesFreou = vezesFreou;
	}
	public Contador getVezesLigou() {
		return vezesLigou;
	}
	public void setVezesLigou(Contador vezesLigou) {
		this.vezesLigou = vezesLigou;
	}
	public CarroContador (String m, String p, int k) {
		marca = m;
		placa = p;
		kilometragem = k;
	}
	public String getMarca() {
		return marca;
	}
	public void setMarca(String marca) {
		this.marca = marca;
	}
	public String getPlaca() {
		return placa;
	}
	public void setPlaca(String placa) {
		this.placa = placa;
	}
	public int getKilometragem() {
		return kilometragem;
	}
	public void setKilometragem(int kilometragem) {
		this.kilometragem = kilometragem;
	}
	public void ligarCarro() {
		this.vezesLigou.incrementar();
	}
	public void acelerarCarro(int intensidade) {
		this.vezesAcelerou.incrementar();
	}
	public void frearCarro(int intensidade) {
		this.vezesFreou.incrementar();
	}
	
}
