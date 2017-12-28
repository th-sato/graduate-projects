
public class No {
	private int dado; // Um item  da  lista
	private No prox; //Ponteiro  para  o  próximo
	private No ant;
	public No (int dado){
		this.dado = dado;
		this.prox = null;
		this.ant = null;
	}

	public No getAnterior() {
		return ant;
	}

	public void setAnterior(No anterior) {
		this.ant = anterior;
	}
	
	public void setProximo(No proximo) {
		this.prox = proximo;
	}
	
	public No getProximo() {
		return this.prox;
	}

	public int getDado() {
		return dado;
	}

	public void setDado(int dado) {
		this.dado = dado;
	}
	
}