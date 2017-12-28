public class ProdutoEscalarThread implements Runnable{
    private double result;
    private static double finalResult = 0;
    private double[] vetorA, vetorB;
    private int inicio, incremento, N;
    private static Object syncObject = new Object();

    public ProdutoEscalarThread(int N, double []vetA, double [] vetB, int inicio, int incremento){
        this.vetorA = vetA;
        this.vetorB = vetB;
        this.N = N;
        this.inicio = inicio;
        this.incremento = incremento;
        this.result = 0;
    }

    public void run(){
        for (int i = this.inicio; i < this.N; i+=this.incremento){
            this.result += this.vetorA[i] * this.vetorB[i];
        }
        synchronized(syncObject) {
            this.finalResult += this.result;
        }
    }

    public double getResult(){
        return this.finalResult;
    }

}
