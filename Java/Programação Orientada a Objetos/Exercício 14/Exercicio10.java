import java.util.LinkedList;

public class Exercicio10 {
	private LinkedList fil; //fila
	
	public void desenfilera (){
		fil.remove(0); //Remove o primeiro elemento
	}
	
	public void enfilera (Object dado){		
		fil.add(fil.size(), dado); //adiciona no início
	}

	public boolean vazio (){
		if (fil.size()==0) //Se a quantidade de elementos é igual a zero
			return true; //Está vazio
		else
			return false; //Ainda há elementos
	}
}
