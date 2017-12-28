
public class Banco {
	private Conta[] contas;
	private int numContas;
	public Banco(){
		contas = new Conta[100];
		numContas = 0;
	}
	public void addConta(Conta c) {
		contas[numContas] = c;
		numContas++;
	}
	public void atualizaPoupanca(){
		int i;
		for (i=0; i<numContas; i++){
			if (contas[i] instanceof ContaPoupanca){
				((ContaPoupanca)contas[i]).rendimento();
			}
		}
	}
	public void cartaCorrente(){
		int i;
		for (i=0; i<numContas; i++){
			if (contas[i] instanceof ContaCorrente){
				if (((ContaCorrente)contas[i]).getLimite()==contas[i].saldo)
					System.out.println("A conta está no limite!");
			}
		}
	}
	public void abrirConta(int num){
		contas[numContas] = new Conta(num);
		numContas++;
	}
	private void deslocarConta(int i){
		int j;
		for (j=i; j<(numContas-1); j++){
			contas[j] = contas [j+1];
		}
		contas[j-1]=null;
	}
	public void fecharConta(int num){
		for(int i=0; i<numContas; i++){
			if (contas[i].getNumero() == num){
				deslocarConta(i);
				numContas--;
			}
			else if (i == numContas-1)System.err.println("Número de conta errado!");
		}
	}
}
