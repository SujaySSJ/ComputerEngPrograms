import java.util.*;
class Parity{
	public static void main(String[] args) {
		Scanner scr=new Scanner(System.in);
		System.out.println("Enter the message");
		String message = scr.nextLine();
		String sentMessage = getParity(message);
		System.out.println("Message sent: "+sentMessage);
		String receivedMessage = sentMessage.charAt(0)+putError(message);
		if(sentMessage.equals(receivedMessage)==true)
			System.out.println("Message received correctly: "+receivedMessage);
		else System.out.println("Message received incorrectly: "+receivedMessage);
	}
	static String getParity(String str){
		int i,count=0;
		for (i=0;i<str.length() ;i++ ) {
			if(str.charAt(i)=='1')
				count++;
		}
		if(count%2==1)
			str="1"+str;
		else str="0"+str;
		return str;
	}
	static String putError(String str){
		int i;
		Random rnd = new Random();
		StringBuffer error = new StringBuffer(str);
		error.setCharAt(rnd.nextInt(error.length()),'0');
		return error.toString();
	}
}