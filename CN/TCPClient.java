import java.util.*;
import java.net.*;
import java.io.*;
class TCPClient{
	public static void main(String[] args) throws Exception{
		Scanner scr = new Scanner(System.in);
		Socket socket = new Socket("localhost",9999);
		Scanner input = new Scanner(socket.getInputStream());
		PrintStream output = new PrintStream(socket.getOutputStream());
		String message;
		while(true){
			message=scr.nextLine();
			output.println("Client : "+message);
			System.out.println(input.nextLine());
		}
	}
}