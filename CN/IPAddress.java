import java.util.*;

class IPAddress{
	public static void main(String[] args) {
		Scanner scr=new Scanner(System.in);
		System.out.println("Enter an IP Address:");
		String ipaddr=scr.nextLine();
		String ipParts[]=ipaddr.split("\\.");
		int ipPart1=Integer.parseInt(ipParts[0]);
		if(ipPart1<128 && ipPart1>=0){
			System.out.println("Class A\nSubnet Mask: 255.0.0.0");
		}
		if(ipPart1<192 && ipPart1>=128){
			System.out.println("Class B\nSubnet Mask: 255.255.0.0");
		}
		if(ipPart1<224 && ipPart1>=192){
			System.out.println("Class C\nSubnet Mask: 255.255.255.0");
		}
		if(ipPart1<240 && ipPart1>=224){
			System.out.println("Class D");
		}
		if(ipPart1<256 && ipPart1>=240){
			System.out.println("Class E");
		}
	}
}