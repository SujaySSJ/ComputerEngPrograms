import java.util.*;
import java.net.*;
import java.io.*;

class TCPServer{
	public static void main(String[] args) throws Exception{
		ServerSocket socket = new ServerSocket(9999);
		Socket conn = socket.accept();
		Scanner input = new Scanner(conn.getInputStream());
		PrintStream output = new PrintStream(conn.getOutputStream());
		String message;
		Scanner scr = new Scanner(System.in);
		while(true){
			message=input.nextLine();
			System.out.println(message);
			message=scr.nextLine();
			output.println("Server: "+message);
		}		
	}
}