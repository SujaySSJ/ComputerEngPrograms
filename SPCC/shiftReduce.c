#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Grammar{
	char rhs[20],lhs;
}Grammar;
Grammar prod[20];
char stack[20],top=-1;
int np;
char input[20];

void push(char c){ stack[++top]=c; }
void pop(int n){ top=top-n; }
int stackLength(){ return top+1; }

int searchRHS(char str[]){
	int i;
	for(i=0;i<np;i++)
		if(!strcmp(str,prod[i].rhs))
			return i;
	return -1;	
}
char *getStringFromStack(int length){
	int i;
	char *str=malloc(sizeof(char)*length+100);
	for(i=0;i<length;i++)
		str[i]=stack[top-(length-1)+i];
		
	str[i]='\0';
	return str;
}
int shiftReduceParser(){
	int i,iplength=strlen(input);
	char *str;
	int curr=0,comp,j=0;
	while(1){
		//printf("%d\n",stackLength());
		for(i=0;i<stackLength();i++)
			printf("%c",stack[i]);
		printf("\n");
		if(top==-1)
			push(input[curr++]);
		for(i=1;i<=stackLength();i++){
			//printf("%d\n",stackLength());
			str=getStringFromStack(i);
			//printf("%s\n",str);
			comp=searchRHS(str);
			if(comp!=-1)
				break;
		}
		if(comp!=-1){
				pop(strlen(str));
				// puts(str);
				// printf("%c\n",prod[comp].lhs);
				push(prod[comp].lhs);
		}
		else if(curr<iplength){
			push(input[curr++]);
		}
	}
	a:if(stack[top]==prod[0].lhs)
		return 1;
	else return 0;
}

void main(){
	int i=0;
	printf("No. of Productions\n");
	scanf("%d",&np);
	fflush(stdin);
	for(i=0;i<np;i++){
		scanf("%c",&prod[i].lhs);
		scanf("%s",&prod[i].rhs);
		fflush(stdin);
	}
	for(i=0;i<np;i++){
		printf("%c->%s\n",prod[i].lhs,prod[i].rhs);
	}
	gets(input);
	int result=shiftReduceParser();
	if(result)
		printf("Accepted\n");
	else printf("Rejected\n");
	//printf("input\n");
	//gets(input);
	// for(i=0;i<strlen(input);i++){
	// 	push(input[i]);
	// }
	// for(i=0;i<strlen(input)+1;i++){
	// 	printf("%s\n",getStringFromStack(i));
	// }
	//printf("Search:%d\n",searchRHS("a*a+a"));
	

}
/*
E a
E E+E
E E*E
a*a+a

*/