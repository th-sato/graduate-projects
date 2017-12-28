import java.util.concurrent.locks.*;

class Mostra {
   final Lock trava = new ReentrantLock();

    public void imprimir(String texto){
        trava.lock();
        System.out.print("Mostra para "+texto);
         try {
             Thread.sleep(50);
         } catch (InterruptedException ie) {
             System.err.println(ie.toString());
         }
         System.out.println(" Acabei para "+texto);
         trava.unlock();
    }
}
