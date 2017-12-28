
public class Celula{
	private Celula anterior;
	private Celula proximo;
	private Object elemento;
	
	public Celula (Object elemento){
		setProximo(null);
		setAnterior(null);
		setElemento(elemento);
	}
	
	public Celula getAnterior() {
		return anterior;
	}
	public void setAnterior(Celula anterior) {
		this.anterior = anterior;
	}
	public Celula getProximo() {
		return proximo;
	}
	public void setProximo(Celula proximo) {
		this.proximo = proximo;
	}
	public Object getElemento() {
		return elemento;
	}
	public void setElemento(Object elemento) {
		this.elemento = elemento;
	}
	
}
