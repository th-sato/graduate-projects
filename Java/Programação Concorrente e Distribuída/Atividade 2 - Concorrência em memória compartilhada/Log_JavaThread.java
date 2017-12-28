import java.util.Random;

public class Log_JavaThread {
    public static void main(String args[]) {
        int MaxThreads, N, i;
        Thread[] th;
        LogThread_JavaThread[] rh;
        double maxValorGlobal;
        double [] vetor;
        double aux;
        if(args.length != 2){
            System.out.println("Indique o número de threads e o tamanho do vetor, nesta ordem");
            System.exit(1);
        }
        maxValorGlobal = -9999999;
        Random r = new Random();
        MaxThreads = Integer.parseInt(args[0]);
        N = Integer.parseInt(args[1]);
        vetor = new double[N];
        rh = new LogThread_JavaThread[MaxThreads];
        th = new Thread[MaxThreads];
        for(i=0; i<N; i++){
            vetor[i] = r.nextInt();        
        }
        long startTime = System.currentTimeMillis();
        for(i=0; i<MaxThreads; i++) {
            rh[i] = new LogThread_JavaThread (N, i, MaxThreads, vetor);
            th[i] = new Thread(rh[i]);
            th[i].start();
        }
        try {
            for(i=0; i<MaxThreads; i++) {
                th[i].join();
                aux = rh[i].getMaxValor();
                if(aux > maxValorGlobal)
                    maxValorGlobal = aux;
            }
        } catch (InterruptedException e){
            System.out.println("Excecao");
        }
		long calcTime = System.currentTimeMillis() - startTime;
        System.out.println("Número de Threads: " + MaxThreads);
        System.out.println("Resultado: " + maxValorGlobal);
        System.out.println("Tempo: " + calcTime + "ms.\n");
    }
}
