
public class Problema1 extends Exception{
	
	public Problema1 (String str){
		super (str);
	}
	
	public static void main(String[] args) {
		String str = "Teste";
		try{
			if(str.length()>4)
				throw new Problema1(str);
		}catch (Exception e){
			System.out.println("Catch: "+ e.getMessage());
		}finally{
			System.out.println("Passei");
		}
	}
}
