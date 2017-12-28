
public class Exercicio6 {
	public static void main(String[] args) {
		Lista l1 = new Lista ();
		l1.insere(10);
		l1.insere(20);
		l1.impressao();
		System.out.println();
		Lista l2 = l1.inverter();
		l2.impressao();
		System.out.println();
		l1.impressao();
	}
}
