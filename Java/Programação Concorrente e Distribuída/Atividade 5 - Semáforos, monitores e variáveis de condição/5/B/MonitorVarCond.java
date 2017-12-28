public class MonitorVarCond {
    public static void main (String args[]) {
        Mostra m = new Mostra();
        ThreadMostra tm1 = new ThreadMostra("A",10,m);
        ThreadMostra tm2 = new ThreadMostra("B",500,m);
        tm1.start();
        tm2.start();
        try {
            tm1.join();
            tm2.join();
        } catch (InterruptedException e){
            System.out.println("Excecao");
        }
    }
}

