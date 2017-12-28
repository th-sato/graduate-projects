
public class Mortal {
	private boolean vivo;
	public boolean isVivo(){
		return vivo;
	}
	public void mata (){
		this.vivo = false;
	}
	public Mortal (){
		this.vivo = true;
	}
}
