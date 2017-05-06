#include<stdio.h>
#include<string.h>

int i=0,error=0;
char input[25];

void E();
void EPrime();
void T();
void TPrime();
void F();

void main(){
	printf("Enter the input string\n");
	gets(input);
	E();
	if(strlen(input)==i&&error==0)
		printf("Accepted\n");
	else printf("Rejected\n");
}

void E(){
	T();
	EPrime();
}

void EPrime(){
	if(input[i]=='+'){
		i++;
		T();
		EPrime();
	}
}

void T(){
	F();
	TPrime();
}

void TPrime(){
	if(input[i]=='*'){
		i++;
		F();
		TPrime();
	}
}

void F(){
	if(input[i]=='('){
		i++;
		E();
		if(input[i]==')')
			i++;
		else error=1;
	}
	else if(isalnum(input[i]))
		i++;
	else error=1;
}