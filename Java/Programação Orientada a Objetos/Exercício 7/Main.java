
public class Main {
	public static void main (String args[]){
		Gato g1 = new Gato();
		Ramo r1 = new Ramo();
		Mortal m1 = new Mortal();
		
		if(m1.isVivo() == false) System.out.println("Morto");
		else System.out.println("Vivo");
		m1.mata();
		if(m1.isVivo() == false) System.out.println("Morto");
		else System.out.println("Vivo");
		
		System.out.println(g1.isVivo());
		for (int i=0; i<7; i++) g1.mata();
		System.out.println(g1.isVivo());
		
		String s1, s2;
		//r1.mata(); //Deu erro
		s1 = g1.toString();
		s2 = r1.toString();
		System.out.println(s1);
		System.out.println(s2);
		
	}
}
