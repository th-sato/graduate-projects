
public class NoDeArvore {
	private int item; //Um item na arvore
	private NoDeArvore esquerda;
	private NoDeArvore direita;
	private int soma;
	
	public NoDeArvore (int valor){
		this.item = valor;
		this.soma = 0;
		this.esquerda = null;
		this.direita = null;
	}
	public void insere (int valor){
		if (valor >= this.item && this.direita == null)
			this.direita = new NoDeArvore (valor);
		else if (valor >= this.item && this.direita != null)
			this.direita.insere (valor);
		else if (valor < this.item && this.esquerda == null)
			this.esquerda = new NoDeArvore (valor);
		else 
			this.esquerda.insere(valor);
		
	}
	
	public void remover (int valor){
		if (valor >= this.direita.item && this.direita != null)
			if(valor == this.direita.item)
				this.direita = null;
			else this.direita.remover(valor);
		else if (valor < this.item && this.esquerda != null)
			if(valor == this.esquerda.item)
				this.esquerda = null;
			else this.esquerda.remover(valor);
	}
	
	public void buscar (int valor){
		if (valor == this.direita.item && this.direita != null)
			if(valor == this.direita.item)
				this.direita = null;
			else this.direita.remover(valor);
		else if (valor < this.item && this.esquerda != null)
			if(valor == this.esquerda.item)
				this.esquerda = null;
			else this.esquerda.remover(valor);
		
	}
}
