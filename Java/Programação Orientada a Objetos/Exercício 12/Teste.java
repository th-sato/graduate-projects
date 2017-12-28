import java.util.Scanner;

public class Teste {
   public static void main(String[] args) {
	 Scanner teclado = new Scanner(System.in);
	 System.out.println("Intervalo de inteiros: ");
	 int inicio = teclado.nextInt();
	 int fim = teclado.nextInt();
	 System.out.println("Informe a quantidade de threads: ");
	 int threads = teclado.nextInt();
     int intervaloThread = (fim-inicio)/threads;
     Thread t[] = new Thread[threads];
     Programa p[] = new Programa[threads];
     int aux = inicio;
     int primos = 0;
     for(int i=0; i<threads; i++){
    	 p[i] = new Programa (aux, aux+intervaloThread);
    	 t[i] = new Thread (p[i]);
    	 t[i].start();
    	 //primos += p[i].getPrimos();
    	 aux += intervaloThread;
     }
     try{
    	 Thread.sleep(2000);
     }catch(InterruptedException e){
    	 e.printStackTrace();
     }
     for(int i=0; i<threads; i++){
    	 primos += p[i].getPrimos();
     }
     System.out.println("Número de primos: " + primos);
   }
 }