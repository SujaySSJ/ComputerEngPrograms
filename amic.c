#include<stdio.h>
#include<conio.h>
int main()
{
 int num1=0,num2=0,n,s1=0,s2=0,i;
 printf("Enter the integer to display amicable pairs upto n");
 scanf("%d",&n);
while(num1<n)
 {
	 num1++;
	 for(num2=num1;num2<=num2;num2++)
	 {
	 for(i=1; i<num1 ; i++)
	 {
	   if(num1%i==0)
		  s1=s1+i;
	 }
	 for(i=1; i<num2 ; i++)
	 {
	   if(num2%i==0)
		  s2=s2+i;
	 }
	 if(num1==s2 && num2==s1)
	  printf("(%d %d) ",num1,num2);
	}
 
 }
 getch();
 return 0;
}