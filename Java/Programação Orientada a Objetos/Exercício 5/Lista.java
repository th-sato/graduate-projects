
public class Lista{
	private Celula inicio;
	private Celula fim;
	private int qtd_elementos;
	
	public Lista (){
		setQtd_elementos(0);
	}
	
	public int getQtd_elementos() {
		return qtd_elementos;
	}
	public void setQtd_elementos(int qtd_elementos) {
		this.qtd_elementos = qtd_elementos;
	}
	public Celula getInicio() {
		return inicio;
	}
	public void setInicio(Celula inicio) {
		this.inicio = inicio;
	}
	public Celula getFim() {
		return fim;
	}
	public void setFim(Celula fim) {
		this.fim = fim;
	}
	public void insereInicio(Object elemento){
		Celula novo = new Celula(elemento);
		if (getQtd_elementos()==0){
			this.inicio = novo;
			this.fim = novo;
		}
		else{
			novo.setProximo(inicio);
			this.inicio.setAnterior(novo);
		}
		this.qtd_elementos++;
	}
	public void insereFinal(Object elemento){
		Celula novo = new Celula(elemento);
		if (getQtd_elementos()==0){
			this.fim = novo;
			this.inicio = novo;
		}
		else{
			novo.setAnterior(this.fim);
			this.fim.setProximo(novo);
		}
		this.qtd_elementos++;
	}
	/*public boolean busca(Object elemento){
		Celula atual = inicio;
		while (inicio.getElemento() != elemento){
			if ()
				
			else{
				
			}
		}
	}*/
	public void impressao(){
		Celula atual = getInicio();
		while (atual != null){
			System.out.println(atual.getElemento());
			atual = atual.getProximo ();
		}
	}
	
}
