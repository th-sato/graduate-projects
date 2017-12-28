
public class Inverte implements CharSequence{
	private StringBuffer s1;
	public Inverte(String s1){
		this.s1 = new StringBuffer (s1);
		this.s1.reverse();
	}
	public char charAt(int indice){
		return s1.charAt(indice);
	}
	public int length(){
		return s1.length();
	}
	public CharSequence subSequence(int start, int end){
		return s1.substring(start, end);
	}
	public String toString(){
		return ("String invertida: " + this.s1.toString());
	}
}
