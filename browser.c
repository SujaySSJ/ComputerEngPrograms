#include<stdio.h>
#include<string.h>
int length1(char x[]){
	int i,j=0;
	int l=strlen(x);
	for(i=0;i<l;i++){
		switch(x[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':j++;
			
		}
	}
	i=l-4-j+1;
	return i;
	
}
int main(){
	char a[100][200];
    int n,blength[100],jlength[100];
	int i,b;
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++){
		gets(a[i]);
		blength[i]=strlen(a[i]);
		jlength[i]=length1(a[i]);
		
	}
	for(i=0;i<n;i++){
		printf("%d/%d\n",jlength[i],blength[i]);
	}
	return 0;
}