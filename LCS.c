#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char x[20],y[20],d[20][20];
	int n,m,l[20][20]={0},i,j;
	printf("Enter the first string\n");
	gets(x);
	n=strlen(x);
	printf("Enter the second string\n");
	gets(y);
	m=strlen(y);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(x[i]==y[j]){
				l[i+1][j+1]=l[i][j]+1;
				d[i][j]='d';
			}
			else if (l[i][j+1]>l[i+1][j])
			{
				l[i+1][j+1]=l[i][j+1];
				d[i][j]='u';
			}
			else{
				l[i+1][j+1]=l[i+1][j];
				d[i][j]='l';
			}
	{
		int index=l[n][m];
		char lcs[20];
		lcs[index]='\0';
		i=n;j=m;
		while(i>0&&j>0){
			if(x[i-1]==y[j-1]){
				lcs[index-1]=x[i-1];
				i--;j--;index--;
			}
			 else if (l[i-1][j] > l[i][j-1])
         		i--;
     		 else
         		j--;
		}	
		printf("The longest common subsequence:\n");
		puts(lcs);
	}		

	printf("\n");		
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++)
			printf("%d ",l[i][j]);
		printf("\n");
	}				
		printf("\n");		
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%c ",d[i][j]);
		printf("\n");
	}	
	return 0;
}