public class Programa implements Runnable {
   private int inicio;
   private int fim;
   private int primos;
   public void run () {
	 int cont;
     for(int i= inicio; i<fim; i++){
    	 cont = 0;
    	 int j=2;
    	 while(i%j==0 && j<i){
    		 cont++;
    	 }
    	 if(cont==0){
    		 primos++;
    		 System.out.println("Numero primo: " + i);
    	 }
     }
   }
	public int getPrimos() {
		return primos;
	}
	public void setPrimos(int primos) {
		this.primos = primos;
	}
	public int getInicio() {
		return inicio;
	}
	public void setInicio(int inicio) {
		this.inicio = inicio;
	}
	public int getFim() {
		return fim;
	}
	public void setFim(int fim) {
		this.fim = fim;
	}
	public Programa(int inicio, int fim){
		this.inicio = inicio;
		this.fim = fim;
		this.primos = 0;
	}
 }