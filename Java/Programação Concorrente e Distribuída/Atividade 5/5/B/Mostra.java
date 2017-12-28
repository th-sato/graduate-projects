import java.util.concurrent.locks.*;
class Mostra {
    int libera=0;
    public synchronized void imprimir(String texto){
         try {
            if (texto.compareTo("A")==0) while (libera!=0) wait();
            if (texto.compareTo("B")==0) while (libera!=1) wait();
            System.out.print("Mostra para "+texto);
            Thread.sleep(50);
         } catch (InterruptedException ie) {
             System.err.println(ie.toString());
         }
         libera=(libera+1)%2;
         System.out.println(" Acabei para "+texto);
         notifyAll();
    }
}
