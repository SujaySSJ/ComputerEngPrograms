#include<stdio.h>
# define max 50
#include<string.h>
char s[max],tos=-1;
void push(char ele)
{
s[++tos]=ele;	
}
int isempty()
{
	return(tos==-1);
}
char pop()
{
	char c=s[tos];
	tos--;
	return c;
}
char stacktop()
{
	return (s[tos]);
}
int ipr(char c)
{
	switch(c)
	{
		case ')':return 3;
		case '/':
		case '*':
		case '%':return 2;
		case '+':
		case '-':return 1;
	}
	return -1;
}
int rpr(char c)
{
	switch(c)
	{
		case '(':return 0;
		case '/':
		case '*':
		case '%':return 2;
		case '+':
		case '-':return 1;
	}
	return -1;
}

int isoperand(char ch)
{
	if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
		return 1;
	return 0;
}
 void convert(char in[],char pre[])
 {
	 int i,l=strlen(in),k=0;
	 char ele;
	 for(i=0;i<l;i++)
	 {
		 if(in[i]==')')
			 push(in[i]);
		 else if(in[i]=='(')
			 while(1)
			 {
				 ele=pop();
				 if(ele==')')
					 break;
				 pre[k++]=ele;
			 }
			 
			 else if(isoperand(in[i]))
				 pre[k++]=in[i];
			 else if(isempty())
				 push(in[i]);
			 else if(ipr(in[i])>rpr(stacktop()))
				 push(in[i]);
			 else 
			 {
				 while(isempty()==0&&ipr(in[i])<=rpr(stacktop()))
				 {
					 ele=pop();
					 pre[k++]=ele;
				 
				 }
				 push(in[i]);
				 
					
			 }
			 
			 
	 }
	 while(isempty()==0)
	 {
		 ele=pop();
		 pre[k++]=ele;
	 }
	 pre[k]='\0';
	 
 }
 void main()
 {
	 char in[max],pre[max];
	 printf("Enter the infix equation :\n");
	 gets(in);
	 strrev(in);
	 convert(in,pre);
	 strrev(pre);
	 printf("prefix Equation = %s \n",pre);
 }
 
 
 