
public class Main {
	public static void main (String[] args){
		Conta c1 = new Conta(30);
		ContaPoupanca c2 = new ContaPoupanca (40, 5);
		ContaCorrente c3 = new ContaCorrente (50, 300);
		c1.imprime();
		c1.debita(40);
		c1.credita(30);
		c1.imprime();
		c2.imprime();
		c2.debita(20);
		c2.rendimento();
		c2.imprime();
		c3.imprime();
		c3.debita(40);
		c3.credita(340);
		c3.credita(1);
		c3.imprime();
		
		Banco b1 = new Banco();
		b1.addConta(c1);
		b1.addConta(c2);
		b1.addConta(c3);
		b1.abrirConta(400);
		b1.fecharConta(400);
	}
}
