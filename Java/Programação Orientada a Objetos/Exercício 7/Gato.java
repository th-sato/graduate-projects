
public class Gato extends Mortal{
	private int cont;
	public void mata (){
		this.cont++;
		if (cont==7){
			super.mata();
		}
	}
	public String toString (){
		if (super.isVivo() == false) return "Gato está morto"; 
		else return "Gato está vivo";
	}
	public Gato (){
		super();
		this.cont=0;
	}
}
