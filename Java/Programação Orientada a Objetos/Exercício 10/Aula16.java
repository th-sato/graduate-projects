import java.util.Arrays;

/*Ver:
implements Comparable<Reta>
ArrayLista<Galinha>(): lista que só permite colocar elementos do tipo Galinha
*/

public class Teste {
	private int v[] = new int[10]; 
	
	public static void main(String[] args) {
		String[] s1 = new String[10];
		Teste t = new Teste();
		Teste t1 = new Teste();
		for(int i=0; i<t.v.length; i++){
			t.v[i] = i;
			System.out.println("t.v["+i+"] = " + t.v[i]);
			System.out.println("t1.v["+i+"] = " + t1.v[i]);
			
		}
		for(int i : t.v){ //A partir do Java 1.5
			System.out.println(t.v[i]);
		}
		System.out.println();
		int[] t2 = getDezenas();
		for(int i : t2){
			System.out.println(i);
		}
	}
	public static int[] getDezenas() {
		int[] dezenas = new int[6];
		for (int i = 0; i < dezenas.length; i++) {
			dezenas[i]	=  (int) Math.ceil((Math.random()*50));
			System.out.println(dezenas[i]);
		}
		System.out.println();
		Arrays.sort(dezenas);
		return	dezenas;
	}
}
