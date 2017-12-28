
public class ContaCorrente extends Conta{
	private double limite;
	public ContaCorrente (int numero, int limite){
		super(numero);
		this.limite = limite;
	}
	public void credita(double quantia){
		if(quantia > 0 && (getSaldo()-quantia) >= (-1)*limite)
			saldo-=quantia;
		else
			System.err.println("Saque não disponível.");
	}
	public double getLimite() {
		return limite;
	}
	public void setLimite(double limite) {
		this.limite = limite;
	}
}
