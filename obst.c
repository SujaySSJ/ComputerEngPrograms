#include<stdio.h>
#include<limits.h>
typedef struct{
	int s,f;
}Key;
int sumfreq(Key key[],int i,int j){
	int s,sum=0;
	for(s=i;s<=j;s++)
		sum+=key[s].f;
	return sum;
}
int OBST(Key key[],int n){
	int i,c,j,r,mincost,cost[20][20];
	for(i=0;i<n;i++)
		cost[i][i]=key[i].f;
	for(c=2;c<=n;c++)
		for(i=0;i<=n-c+1;i++){
			j=i+c-1;
			cost[i][j]=INT_MAX;
			for(r=i;r<=j;r++){
				mincost=((r>i)?cost[i][r-1]:0) + ((r<j)?cost[r+1][j]:0) + sumfreq(key,i,j);
				cost[i][j]=mincost<cost[i][j]?mincost:cost[i][j];

			}
		}
	return cost[0][n-1];
}

void main(){
	int i,n,cost[20][20];
	Key key[20];
	printf("Enter the no. of keys\n");
	scanf("%d",&n);
	printf("Enter the key and its frequency\n");
	for(i=0;i<n;i++)
		scanf("%d %d",&key[i].s,&key[i].f);
	printf("The cost of optimal binary search tree is %d\n",OBST(key,n) );

}