import java.util.*;
class Hamming{
	public static void main(String[] args) {
		Scanner scr = new Scanner(System.in);
		int message[] = new int[7];
		System.out.println("Enter the message bits:");
		message[2]=scr.nextInt();
		message[4]=scr.nextInt();
		message[5]=scr.nextInt();
		message[6]=scr.nextInt();
		message[0]=getParity(message[2],message[4],message[6]);
		message[1]=getParity(message[2],message[5],message[6]);
		message[3]=getParity(message[4],message[5],message[6]);
		System.out.println("Sent Message: ");
		for (int i=0;i<message.length;i++) {
			System.out.print(message[i]);
		}
		System.out.println();
		checkMessage(sendMessage(message));
		System.out.println();
		
	}
	static int getParity(int b1,int b2,int b3){ return (b1+b2+b3)%2; }
	static int[] sendMessage(int message[]){
		int index[]={2,4,5,6};
		Random rnd = new Random();
		message[index[rnd.nextInt(4)]]=rnd.nextInt(2);
		return message;
	}
	static void checkMessage(int message[]){
		int parity[]=new int[3];
		parity[0]=getParity(message[2],message[4],message[6]);
		parity[1]=getParity(message[2],message[5],message[6]);
		parity[2]=getParity(message[4],message[5],message[6]);
		int flag[]=new int[3];
		if(parity[0]==message[0])
			flag[0]=1;
		if(parity[1]==message[1])
			flag[1]=1;
		if(parity[2]==message[3])
			flag[2]=1;
		System.out.println("The received Message");
		for (int i=0;i<message.length;i++) {
			System.out.print(message[i]);
		}
		if(flag[0]==1 && flag[1]==1 && flag[2]==1){
			System.out.println("\nMessage received correctly");
		}
		else{
			int d=0;
			if(flag[0]==0 && flag[1]==0 && flag[2]==1)
				d=2;
			if(flag[0]==0 && flag[1]==1 && flag[2]==0)
				d=4;
			if(flag[0]==1 && flag[1]==0 && flag[2]==0)
				d=5;
			if(flag[0]==0 && flag[1]==0 && flag[2]==0)
				d=6;
			System.out.println("Error at index :"+(d+1));
			message[d]=(message[d]+1)%2;
			System.out.println("\nCorrected Message :");
			for (int i=0;i<message.length;i++){
				System.out.print(message[i]);
			}
		}
	}
}