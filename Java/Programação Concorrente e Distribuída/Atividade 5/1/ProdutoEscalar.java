import java.util.Random;
import java.util.concurrent.Semaphore;

public class ProdutoEscalar {
    public static void main(String args[]){
        Semaphore sem = new Semaphore(1, true);
        int N_Threads = 8, N = 10000000;
        double [] vetorA = new double[N];
        double [] vetorB = new double[N];
        Random r = new Random();
        Thread [] th = new Thread[N_Threads];
        ProdutoEscalarThread [] pet = new ProdutoEscalarThread[N_Threads];
        double result;
        for(int i=0; i<N; i++){
            vetorA[i] = r.nextDouble();
            vetorB[i] = r.nextDouble();
        }
        long startTime = System.nanoTime();
        for(int i=0; i<N_Threads; i++) {
            pet[i] = new ProdutoEscalarThread (sem, N, vetorA, vetorB, i, N_Threads);
            th[i] = new Thread(pet[i]);
            th[i].start();
        }
        try {
            for(int i=0; i<N_Threads; i++)
                th[i].join();
        } catch (InterruptedException e){
            System.out.println("Excecao");
        }
        result = pet[0].getResult();
        long calcTime = (System.nanoTime() - startTime)/1000;
        System.out.println("Tamanho do vetor: " + N);
        System.out.println("Número de Threads: " + N_Threads);
        System.out.println("Resultado: " + result);
        System.out.println("Tempo: " + calcTime + "us.\n");
    }
}
