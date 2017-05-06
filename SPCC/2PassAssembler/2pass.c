#include<stdio.h>
#include<string.h>

typedef struct Input{
	char label[10],mnemonic[10],op1[10],op2[10];
}Input;

void main(){
	FILE *fp;
	int c,i=0;
	fp=fopen("in.txt","r");
	Input input[20];
	char str[20];
	fgets(str,20,fp);
	puts(str);
	fgets(str,20,fp);
	puts(str);
	char s[256];
strcpy(s, "pg1 start  ");
char* token = strtok(str, " ");
  printf("%s\n",str);

while (token) {
    printf("token: %s\n", token);
    token = strtok(NULL, " ");
}
}