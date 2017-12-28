import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.*;


public class ChatInterface extends JFrame implements Runnable{
    private final static String newline = "\n";
    private int cont;
    private JTextField mEnviada;
    private JButton enviar;
    private JTextArea mRecebida;
    private InetAddress addr;
    private DatagramSocket ds;
    private int portReceive;
    private int portSend;
    private boolean wait;

    public ChatInterface(int num, int portReceive, int portSend){
        super("Chat" + num);
        this.portReceive = portReceive;
        this.portSend = portSend;
        this.cont = 0;
        this.wait = true;
        rede();
        menu();
    }

    public void rede(){
        try{
            addr = InetAddress.getLocalHost();
            ds = new DatagramSocket(portReceive);
        } catch(UnknownHostException uhe){
            uhe.printStackTrace();
        } catch (SocketException e) {
            e.printStackTrace();
        }
    }

    public void menu (){
        setLayout(new FlowLayout());
        this.mRecebida = new JTextArea("Início do chat:\n\n");
        this.mRecebida.setPreferredSize(new Dimension(300,300));
        this.mRecebida.setLineWrap(true);
        this.mRecebida.setWrapStyleWord(true);
        this.mRecebida.setEditable(false);
        this.add(this.mRecebida);
        this.mEnviada = new JTextField(30);
        add(this.mEnviada);
        this.enviar = new JButton("Enviar");
        getRootPane().setDefaultButton(this.enviar);
        this.enviar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
            	try {
	            	//Enviar mensagem
            		mRecebida.append("E: " + mEnviada.getText() + newline);
	                byte [] msgByte = (mEnviada.getText()+cont%2).getBytes();
	                DatagramPacket pkg = new DatagramPacket(msgByte, msgByte.length, addr, portSend);
                    ds.send(pkg);
                    while(valueWait());
                    alterarWait();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                mEnviada.setText("");
                cont++;
            }
        });
        add(enviar);
    }

    @Override
    public void run() {
        try{
            while(true){
            	//Receber mensagem
                byte [] msgByte = new byte[256];
                DatagramPacket pkg = new DatagramPacket(msgByte, msgByte.length);
                this.ds.receive(pkg);
                String msgRec = new String(pkg.getData()).trim();
                if(msgRec.contains("ACK")){
                	if(msgRec.equals("ACK" + cont%2))
                    	System.out.println("Funcionou");
                	alterarWait();
                }
                else{
	                mRecebida.append("R: "+ msgRec.substring(0, msgRec.length()-1) + newline);
	                String numberACK = msgRec.substring(msgRec.length()-1, msgRec.length());;
	                msgByte = ("ACK"+numberACK).getBytes();
	                pkg = new DatagramPacket(msgByte, msgByte.length, addr, portSend);
	                ds.send(pkg);
                }
            }
        } catch (IOException e) {
            System.err.println(e);
        }
    }
    
    public synchronized void alterarWait(){
    	this.wait = !this.wait;
    }
    
    public synchronized boolean valueWait(){
    	return this.wait;
    }
}
