#include<stdio.h>
#include<math.h>
char a[100][100];
int n;
void printmatrix()
{
	int i,j;
	for(i=0;i<n;i++)
	{	for( j=0;j<n;j++)
		
			printf("%c  ",a[i][j]);
	printf("\n");
	}	
}
int getmarkedcol(int row){
	int i;
	for(i=0;i<n;i++)
		if(a[row][i]=='Q')
		{
			return(i);
			break;
		}
}
int feasible(int row,int col)
{
	int i,tcol;
	for(i=0;i<n;i++){
		tcol=getmarkedcol(i);
		if(col==tcol||abs(row-i)==abs(col-tcol))
			return 0;
	}
	return 1;
}
void nqueen(int row)
{
	int i,j;
	if(row<n)
	{
		for(i=0;i<n;i++)
		{
			if(feasible(row,i))
			{
				a[row][i]='Q';
				nqueen(row-1);
				a[row][i]='.';
			}
			else{
				printf("The solution is:\n");
				printmatrix();
			}
		}
	}
}
void main()
{
	int i,j;
	printf("Enter the no of queens\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]='.';
	nqueen(0);
	
}