#include<stdio.h>
#include<string.h>
void main(){
	int i,j,n,m,c=0;
	char t[20],p[20];
	printf("Enter a string\n");
	gets(t);
	n=strlen(t);
	printf("Enter the pattern\n");
	gets(p);
	m=strlen(p);
	for(i=0;i<=n-m;i++){
		j=0;
		while(j<m && t[i+j]==p[j])
			j++;
		if(j==m){
			printf("Pattern found at position %d\n",i+1);
			c++;
		}
	}
	if(c==0)
		printf("Pattern not found\n");

}