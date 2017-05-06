import java.util.*;
import java.net.*;
import java.io.*;

class StopWaitServer{
	public static void main(String[] args) throws Exception{
		ServerSocket socket = new ServerSocket(9999);
		Socket conn = socket.accept();
		Scanner input = new Scanner(conn.getInputStream());
		PrintStream output = new PrintStream(conn.getOutputStream());
		String message;
		Scanner scr = new Scanner(System.in);
		int i;
		while(true){
			i=input.nextInt();
			if(i==-1){
				System.out.println("All frames received.");
				break;
			}
			else{
				System.out.println("Frame received :"+i);
				Thread.sleep(1000);
				output.println(i);
			}
		}		
	}
}