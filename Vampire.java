import java.util.*;
class Vampire{
	static boolean search(int a[],int n,int ele){
		for(int i=0;i<n;i++)
			if(a[i]==ele)
				return true;
		return false;	
	}
	public static void main(String args[]){
		Scanner scr= new Scanner(System.in);
		int a[],d[],vampire,bk,i=0,j=0;
		System.out.println("Enter a four digit no.");
		vampire=scr.nextInt();
		bk=vampire;
		d=new int[4];
		while(bk!=0){
			d[i++]=bk%10;
			bk/=10;
		}
		a=new int[12];
		int k=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(i==j)
					continue;
				a[k++]=d[i]*10+d[j];
			}
		}
		for(i=0;i<12;i++){
			int v1=a[i];
			int v2=vampire/v1;
			if(search(a,12,v2))
			{
				System.out.println(vampire+" is a vampire no.");
				System.out.println(v1+" * "+v2+" = "+vampire);
				break;
			}
		}
		if(i==12)
			System.out.println(vampire+" is not a vampire no.");
			
	}
}
