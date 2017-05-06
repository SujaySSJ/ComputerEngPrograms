import java.util.*;
class Time
{
	int h,m,s;
    Scanner scr = new Scanner(System.in);
	void display(){
		System.out.printf("Time is %d : %d : %d\n",h,m,s);
	}
	void accept(){
		System.out.println("Enter the ..........");
		System.out.println("Hours");
		h=scr.nextInt();
		System.out.println("Minutes");
		m=scr.nextInt();
		System.out.println("Seconds");
		s=scr.nextInt();
	}
	void timeAdd(Time x,Time y){
		int hh=x.h+y.h,mm=x.m+y.m,ss=x.s+y.s;
		if(ss<60&&mm<60){
			s=ss;
			m=mm;
			h=hh;
		}
		else if(ss>=60){
			s=ss-60;
			mm++;
			if(mm>=60){
				m=mm-60;
				h=++hh;
			}
			else{
				m=mm;
				h=hh;
			}
				
		}
		else if(mm>=60){
			s=ss;
			m=mm-60;
			h=++hh;
		}
	}
}
class TimeEx
{
	public static void main(String args[]){
		Time t1=new Time();
		Time t2=new Time();
		Time t=new Time();
		t1.accept();
		t1.display();
		t2.accept();
		t2.display();
		t.timeAdd(t1,t2);
		t.display();
		
	}
}







