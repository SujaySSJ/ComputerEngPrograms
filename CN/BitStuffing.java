import java.util.*;
class BitStuffing{
	public static void main(String[] args) {
		Scanner scr = new Scanner(System.in);
		System.out.println("Enter Message");
		StringBuffer message = new StringBuffer(scr.nextLine());
		String str = "01111110";
		message=stuff(message);
		System.out.println(message);
		message=addFlags(message);
		System.out.println(message);
		message=removeFlags(message);
		System.out.println(message);
		message=destuff(message);
		System.out.println(message);
	}
	static StringBuffer stuff(StringBuffer str){
		int count=0,i;
		for (i=0;i<str.length();i++) {
			if(str.charAt(i)=='1')
				count++;
			if(count==5){
				str.insert(++i,"0");
				count=0;
			}
		}
		return str;
	}
	static StringBuffer addFlags(StringBuffer str){
		str.insert(0,"01111110");
		str.append("01111110");
		return str;
	}
	static StringBuffer removeFlags(StringBuffer str){
		return new StringBuffer(str.substring(8,str.length()-8));
	}
	static StringBuffer destuff(StringBuffer str){
		int i,count=0;
		for(i=0;i<str.length();i++){
			if(str.charAt(i)=='1')
				count++;
			if(count==5){
				str.deleteCharAt(i+1);
				count=0;
			}
		}
		return str;
	}
}