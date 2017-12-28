
public class Lista {
	private No inicio;
	private No fim;
	private int qtd_elementos;
	public Lista (){
		this.qtd_elementos = 0;
	}
	public void insere(int elemento){
		No novo = new No(elemento);
		if (qtd_elementos == 0) {
			this.fim = novo;
			this.inicio = novo;
		} else {
			novo.setAnterior(this.fim);
			this.fim.setProximo(novo);
			this.fim = novo;
		}
		this.qtd_elementos++;	
	}
	public void removeFim() {
		No aux = this.fim;
		if (aux == null)
			System.out.println("A lista está vazia!");
		else if (this.qtd_elementos != 1) {
			this.fim = aux.getAnterior();
			this.fim.setProximo(null);
			this.qtd_elementos -= 1;
		} else {
			this.inicio = null;
			this.fim = null;
			this.qtd_elementos -= 1;
		}
	}
	private boolean buscaElemento(int elemento) {
		No aux = this.inicio;
		while (aux != null) {
			if (aux.getDado() == (elemento))
				return true;
			aux = aux.getProximo();
		}
		return false;
	}

	public void busca(int elemento) {
		if (buscaElemento(elemento))
			System.out.println("O elemento " + elemento + " está na lista!");
		else
			System.out
					.println("O elemento " + elemento + " não está na lista!");
	}
	
	public Lista inverter (){
		Lista novo = new Lista ();
		No aux = this.fim;
		while (aux!=null){
			novo.insere(aux.getDado());
			aux = aux.getAnterior();
		}
		return novo;
	}
	
	public void impressao() {
		No atual = this.inicio;
		if (atual == null)
			System.out.println("A lista está vazia!");
		else {
			while (atual != null) {
				System.out.println(atual.getDado());
				atual = atual.getProximo();
			}
		}
	}

	
}
