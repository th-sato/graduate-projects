class LogThread_JavaThread implements Runnable {
    private int n;
    private int inicio;
    private int maxThreads;
    private double [] vetor;
    private double maxValor;

    public LogThread_JavaThread(int n, int inicio, int maxThreads, double [] vetor) {
        this.n = n;
        this.inicio = inicio;
        this.maxThreads = maxThreads;
        this.vetor = vetor;
        this.maxValor = -9999999;
    }

    public void run() {
        int i;
        double aux;
        for(i=this.inicio; i<this.n; i+=this.maxThreads){
            aux = Math.log10(vetor[i]);
            if(aux > this.maxValor)
                this.maxValor = aux;
        }
    }

    public double getMaxValor(){
        return this.maxValor;
    }
}
