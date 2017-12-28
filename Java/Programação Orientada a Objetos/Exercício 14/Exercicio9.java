import java.util.LinkedList;

public class Exercicio9 {
	private LinkedList pil; //Pilha
	
	public void pop (){
		//Remover o último elemento
		pil.remove(pil.size());		
	}
	
	public void push (Object dado){		
		//Inserir no final
		pil.add(pil.size(), dado);
	}

	public Object top (){
		//Retornar o valor do topo
		return pil.get(pil.size());
	}
}
