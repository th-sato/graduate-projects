import java.io.* ;
import java.net.* ;
import java.util.* ;

public final class WebServer {
	public static void main(String arvg[]) throws Exception {
		int port = 3000;
		ServerSocket welcomeSocket = new ServerSocket (port);
		Socket socketClient;
		while (true) {
			System.out.println("Servidor ativo");
			socketClient = welcomeSocket.accept();
			HttpRequest request = new HttpRequest (socketClient);
			Thread thread = new Thread(request);
			thread.start();
		}
	}
}

final class HttpRequest implements Runnable {
	final static String CRLF = "\r\n";
	Socket socket;
	
	public HttpRequest(Socket socket) throws Exception{
		this.socket = socket;
	}
	
	@Override
	public void run() {
		try {
			processRequest();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	
	private void processRequest() throws Exception {
		InputStreamReader is = new InputStreamReader(socket.getInputStream());
		DataOutputStream os = new DataOutputStream(socket.getOutputStream());
		BufferedReader br = new BufferedReader(is);
		String requestLine = br.readLine();
		System.out.println();
		System.out.println(requestLine);
		String headerLine = null;
		while ((headerLine = br.readLine()).length() != 0) {
			System.out.println(headerLine);
		}
		StringTokenizer tokens = new StringTokenizer(requestLine);
		tokens.nextToken();
		String fileName = tokens.nextToken();
		fileName = "." + fileName;
		FileInputStream fis = null;
		Boolean fileExists = true;
		try {
			fis = new FileInputStream(fileName);
		} catch (FileNotFoundException e) {
			fileExists = false;
		}
		String statusLine = null;
		String contentTypeLine = null;
		String entityBody = null;
		if(fileExists) {
			statusLine = "HTTP/1.1 200 OK" + CRLF;
			contentTypeLine = "Content-type: " + contentType(fileName, fileExists) + CRLF;
			System.out.println("\n" + statusLine + contentTypeLine);
		} else {
			statusLine = "HTTP/1.1 404 Not Found" + CRLF;
			contentTypeLine = "Content-type: " + contentType(fileName, fileExists)+ CRLF;
			entityBody = "<HTML>" + "<HEAD><TITLE>404 Not Found</TITLE></HEAD>" +
					"<BODY>404 Not Found</BODY>" + "</HTML>";
			System.out.println("\n" + statusLine + contentTypeLine + entityBody);
		}
		os.writeBytes(statusLine);
		os.writeBytes(contentTypeLine);
		os.writeBytes(CRLF);
		if (fileExists) {
			sendBytes(fis, os);
			fis.close();
		} else {
			os.writeBytes(entityBody);
		}
		os.close();
		br.close();
		socket.close();
	}
	
	private static void sendBytes(FileInputStream fis, OutputStream os) throws Exception {
		byte[] buffer = new byte[1024];
		int bytes = 0;
		while((bytes = fis.read(buffer)) != -1 ) {
			os.write(buffer, 0, bytes);
		}
	}
	private static String contentType(String fileName, boolean exist) {
		if (!exist) return "text/html";
		if(fileName.endsWith(".htm") || fileName.endsWith(".html")) return "text/html";
		if(fileName.endsWith(".gif")) return "image/gif";
		if(fileName.endsWith(".jpeg")) return "image/jpeg";
		return "application/octet-stream";
	}
}