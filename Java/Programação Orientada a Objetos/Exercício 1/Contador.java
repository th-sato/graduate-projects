
public class Contador {
	private int cont;
	
	public int getCont() {
		return cont;
	}
	public void setCont(int cont) {
		this.cont = cont;
	}
	public void mostrarValor(){
		System.out.println("Contador: " + cont);
	}
	public void incrementar (){
		this.cont++;
	}
	public void incrementar (int cont){
		this.cont+=cont;
	}
	public void decrementar (){
		this.cont--;
	}
	public void decrementar (int cont){
		this.cont-=cont;
	}
	public Contador(){
		this.cont = 0;
	}
	public Contador(int cont){
		this.cont = cont;
	}
}
