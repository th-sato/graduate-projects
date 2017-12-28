
public class Problema5 {
	
	public void f() throws Problema4{
		try{
			g();
		}catch (Problema4 e){
			System.out.println("Erro: " + e.getMessage());
		}
	}
	public void g() throws Problema4{
		throw new Problema4(null);
	}
	public static void main(String[] args) throws Problema4 {
		Problema5 p = new Problema5();
		p.f();
	}
}
