
public class Problema3{

	public void lancaExcecao() throws Problema2{
		throw new Problema2("Teste");
	}
	public static void main(String[] args) throws Problema2{
		Problema3 p = new Problema3();
		try{
			p.lancaExcecao();
		}catch(Problema2 e){
			System.out.println("Erro: " + e.getString());
		}
	}
}
