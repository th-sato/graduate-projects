
public class Problema2 extends Exception{
	String s;
	public Problema2(String s1){
		this.s = s1;
	}
	public String getString(){
		return this.s;
	}
	public static void main(String[] args) {
		String str = "TESTE";
		try{
			throw new Problema2(str);
		}
		catch (Problema2 e){
			System.out.println("Erro: " + e.getString());
		}
		finally{
			System.out.println("Passei");
		}
	}
}
