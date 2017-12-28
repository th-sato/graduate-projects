import java.util.concurrent.Semaphore;

public class ProdutoEscalarThread implements Runnable{
    private double result;
    private static double finalResult = 0;
    private double[] vetorA, vetorB;
    private int inicio, incremento, N;
    private Semaphore sem;

    public ProdutoEscalarThread(Semaphore sem, int N, double[] vetorA, double[] vetorB, int inicio, int incremento){
        this.sem = sem;
        this.N = N;
        this.vetorA = vetorA;
        this.vetorB = vetorB;
        this.inicio = inicio;
        this.incremento = incremento;
        this.result = 0;
    }

    public void run(){
        for (int i = this.inicio; i < this.N; i+=incremento){
            result += this.vetorA[i] * this.vetorB[i];
        }
        try{
            sem.acquire();
            this.finalResult += result;
            sem.release();
        }catch(InterruptedException e){
            System.out.println("Exceção");
        }
    }

    public double getResult(){
        return this.finalResult;
    }

}
