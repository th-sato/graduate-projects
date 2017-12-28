import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.lang.String;

public class Exercicio3 {
	public static void main(String argv[]) throws Exception {
		Socket clientSocket = new Socket("172.21.209.71", 2001);
		String ctr = "\r\n";
		Scanner reader = new Scanner(System.in);

		InputStream is = clientSocket.getInputStream();
		InputStreamReader isr = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(isr);
		String response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("+OK")) {
			throw new Exception(response);
		}

		OutputStream os = clientSocket.getOutputStream();

		String command = "user tiago\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("+OK")) {
			throw new Exception(response);
		}

		command = "pass tabom\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("+OK")) {
			throw new Exception(response);
		}

		command = "list\r\n";
		System.out.println(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		while (!response.startsWith(".")) {
			System.out.println(response);
			response = br.readLine();
		}

		System.out.println("Enter your selection: ");
		command = reader.nextLine() + ctr;
		while (!command.startsWith("quit")) {
			os.write(command.getBytes("US-ASCII"));
			response = br.readLine();
			if (command.startsWith("retr"))
				while (!response.startsWith(".")) {
					if (response.startsWith("-ERR")) {
						throw new Exception(response);
					}
					System.out.println(response);
					response = br.readLine();
				}
			else if (command.startsWith("dele")) {
				if (!response.startsWith("+OK")) {
					throw new Exception(response);
				}
				else
					System.out.println("Deleted");
			}
			else if (command.startsWith("list")) {
				response = br.readLine();
				while (!response.startsWith(".")) {
					System.out.println(response);
					response = br.readLine();
				}
			}
			System.out.println("Enter your selection: ");
			command = reader.nextLine() + ctr;
		}
	
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		if (!response.startsWith("+OK")) {
			throw new Exception(response);
		}
		// dele retorna +OK ou -ERR se nao existe
		// retr retorna mensagem ou -ERR se nao existe ou foi deletado
	}
}