import java.io.*;
import java.net.*;
import java.lang.String;

public class Exercicio2 {
	public static void main(String argv[]) throws Exception {
		Socket clientSocket = new Socket("172.21.209.71", 2002);

		InputStream is = clientSocket.getInputStream();
		InputStreamReader isr = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(isr);
		String response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("220")) {
			throw new Exception("220 reply not received from server.");
		}
		// Pegar uma referência para o trecho de saída do socket.
		OutputStream os = clientSocket.getOutputStream();
		// Enviar o comando HELO e pegar a resposta do servidor.
		String command = "Helo Alice\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("250")) {
			throw new Exception("250 reply not received from server.");
		}
		// Enviar o comando MAIL FROM.
		command = "MAIL FROM: <tiago.ruzzon@unifesp.br>\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("250")) {
			throw new Exception("250 reply not received from server.");
		}

		command = "RCPT TO: <tiago@D122408>\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("250")) {
			throw new Exception("250 reply not received from server.");
		}

		command = "DATA\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		command = "SUBJECT: Assunto\r\nTESTE EM JAVA\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));

		command = ".\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("250")) {
			throw new Exception("250 reply not received from server.");
		}

		command = "QUIT\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("221")) {
			throw new Exception("221 connection closed.");
		}
		clientSocket.close();
	}

}