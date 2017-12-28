
import javax.swing.*;

public class UdpChat {
    static private int portReceive1 = 1234;
    static private int portSend1 = 2345;
    static private int portReceive2 = 2345;
    static private int portSend2 = 1234;
    public static void main(String[] args) {
        ChatInterface chat1 = new ChatInterface(1, portReceive1, portSend1);
        ChatInterface chat2 = new ChatInterface(2, portReceive2, portSend2);

        chat1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        chat1.setSize(400,400);
        chat1.setVisible(true);
        Thread t1 = new Thread(chat1);
        t1.start();

        chat2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        chat2.setSize(400,400);
        chat2.setVisible(true);
        Thread t2 = new Thread(chat2);
        t2.start();

        try{
            t1.join();
            t2.join();
        }catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}