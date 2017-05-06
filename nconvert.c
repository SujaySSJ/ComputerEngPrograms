 #include<stdio.h>
#include<string.h>
#define max 20
int s[max],tos=-1;
void push(int ele)
{
	s[++tos]=ele;
   
}
int pop()
{
	return s[tos];
	tos--;
}
void main()
{
	int n,r,q,i;
	printf("enter the decimal no\n");
	scanf("%d",&n);
	q=n;
	while(q>0)
	{
		r=q%2;
		push(r);
		q=q/2;
	}
	printf("The integer %d\n",n);
	for(i=tos;i>=0;i--)
		printf("%d",pop());
}

 
 /* #include<stdio.h>
int main(){
    long int decimalNumber,remainder,quotient;
    int i=1,j,temp;
    char hexadecimalNumber[100];

    printf("Enter any decimal number: ");
    scanf("%ld",&decimalNumber);

    quotient = decimalNumber;

    while(quotient!=0){
         temp = quotient % 16;

      //To convert integer into character
      if( temp < 10)
           temp =temp + 48;
      else
         temp = temp + 55;

      hexadecimalNumber[i++]= temp;
      quotient = quotient / 16;
  }

    printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
    for(j = i -1 ;j> 0;j--)
      printf("%c",hexadecimalNumber[j]);

    return 0;
} */