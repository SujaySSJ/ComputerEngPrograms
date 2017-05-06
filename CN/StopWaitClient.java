import java.util.*;
import java.net.*;
import java.io.*;

class StopWaitClient{

	public static void main(String[] args) throws Exception{
		
		Scanner scr = new Scanner(System.in);
		int n=scr.nextInt();
		Socket socket = new Socket("localhost",9999);
		Scanner input = new Scanner(socket.getInputStream());
		PrintStream output = new PrintStream(socket.getOutputStream());
		for(int i=0;i<n;i++){
			System.out.println("Frame "+i+" sent:");
			output.println(i);
			System.out.println("Acknowledgement for frame :"+input.nextLine());
		}
		output.println("-1");
		System.out.println("All frames sent successfully");
	}
}