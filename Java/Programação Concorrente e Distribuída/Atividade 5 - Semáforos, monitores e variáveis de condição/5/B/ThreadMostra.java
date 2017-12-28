class ThreadMostra extends Thread {
    int tempo;
    Mostra m;
    public ThreadMostra (String nome, int tempo, Mostra m) { 
        super(nome);
        this.tempo = tempo;
        this.m = m;
    }

    public void run () {
       while (true) {
         try {
             Thread.sleep(tempo);
         } catch ( InterruptedException ie) {
             System.err.println(ie.toString());
         }
         m.imprimir(getName());
       }
    }
}
