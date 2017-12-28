
public class Ramo extends Mortal{
	private Ramo esquerda;
	private Ramo direita;
	public Ramo (){
		super();
	}
	public String toString (){
		if (super.isVivo() == false) return "Ramo está morto"; 
		else return "Ramo está vivo";
	}
	public void mata(){
		super.mata();
		esquerda.mata();
		direita.mata();
	}
}
