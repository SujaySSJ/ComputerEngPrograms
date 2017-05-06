#include<stdio.h>
#define min(a,b) a<b?a:b
void display(int [][20],int);
void allpair(int cost[][20],int n,int d[][20])
{
	int i,j,k,A[20][20];
	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++)
 			A[i][j]=cost[i][j];
 	for(k=1;k<=n;k++)
 		for(i=1;i<=n;i++)
 			for(j=1;j<=n;j++){
 				d[i][j]=(A[i][j]<=A[i][k]+A[k][j])?d[i][j]:k;
 				A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
 				
 				}	
 	printf("The minimum cost matrix is \n");
 	display(A,n);
 	display(d,n);
}
void getpath(int d[][20],int n,int v1,int v2){
	if(d[v1][v2]==v1)
	{
		printf("%d-",v1,v2);
	}
	else 
		{
			getpath(d,n,v1,d[v1][v2]);
			getpath(d,n,d[v1][v2],v2);
		}

}
void display(int a[][20],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%2d ",a[i][j]);
		printf("\n");
	}
}
int main()
{
 	int i,j,n,cost[20][20],v1,v2,d[20][20];
 	
 	printf("Enter the no of vertices\n");
 	scanf("%d",&n);
 	printf("Enter the cost matrix\n");
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++)
 			scanf("%d",&cost[i][j]);
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++){
 			/*if(cost[i][j]!=0||cost[i][j]==1000)
 				d[i][j]=i;
 			else d[i][j]=-1;*/
 			d[i][j]=(cost[i][j]==0||cost[i][j]==1000)?-1:i;	
 		}
 	display(d,n);	
    printf("The cost adjacency matrix\n");
    display(cost,n);
    allpair(cost,n,d);
    //while(1)
    {
    	printf("Enter two vertices\n");
    	scanf("%d %d",&v1,&v2);
    	getpath(d,n,v1,v2);
    	printf("%d\n",v2);
    }
    return 1;
}