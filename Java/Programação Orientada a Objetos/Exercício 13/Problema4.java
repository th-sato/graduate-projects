
public class Problema4 extends Exception{
	Problema3 p;
	public Problema4(Problema3 p){
		this.p = p;
	}
	public void tratar() throws Problema2{
		try{
			p.lancaExcecao();
		}catch(NullPointerException e){
			System.out.println("Erro: " + e.getMessage());
		}
	}
	public static void main(String[] args) throws Problema2 {
		Problema4 p = new Problema4(null);
		p.tratar();
	}
}
