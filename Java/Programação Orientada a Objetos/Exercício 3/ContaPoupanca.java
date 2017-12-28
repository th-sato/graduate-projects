
public class ContaPoupanca extends Conta{
	private double juros;
	public ContaPoupanca(int numero, int juros){
		super(numero);
		this.juros = juros;
	}
	public void rendimento(){
		debita(((juros/100)+1)*(getSaldo()));
	}
}
