
public class Main {
	public static void main (String args[]){
		String s1 = "Testando";
		Inverte i1 = new Inverte(s1);
		System.out.println(i1.charAt(1));
		System.out.println(i1.length());
		System.out.println(i1.subSequence(1, 3));
		System.out.println(i1.toString());
	}
}
