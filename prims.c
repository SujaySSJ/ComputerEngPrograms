#include<stdio.h>
#include<limits.h>
int extractmin(int d[],int n,int r,int q[]){
	int i,min,pos=0;
	min=1000;

	for(i=1;i<=n;i++){
		if(q[i]==1){
			if(d[i]<min)
			{
				min=d[i];
				pos=i;
			}
		}
	}	
	//d[r]=1000;
	return pos;		

}
int isempty(int q[],int n)
{
	int i=1;
	while(i<=n)
		if(q[i++]==1)
			return 0;
	return 1;	
}

void main()
{
	int w[10][10]={0},d[10],pre[10],q[10];
	int i,j,n,r,u,v,cost=0;
	printf("Enter the order of weight matrix\n");
	scanf("%d",&n);
	printf("Enter the weight matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&w[i][j]);
	for(i=1;i<=n;i++){
		q[i]=1;
		d[i]=INT_MAX;
		pre[i]=-1;
	}
	printf("Enter the staring node\n");
	scanf("%d",&r);
	d[r]=0;
	while(isempty(q,n)==0)
	{
		u=extractmin(d,n,r,q);
		q[u]=0;
		for(v=1;v<=n;v++)
			if(w[u][v]!=0 && q[v]==1)
				if(w[u][v]<d[v])
				{
					d[v]=w[u][v];
					pre[v]=u;
				}
	}
	d[r]=0;
	printf("The selected edges are\n");
	for(i=1;i<=n;i++)
	{
		if(d[i]!=0){
			printf("(%d,%d)=%d\n",i,pre[i],d[i]);
			cost+=w[i][pre[i]];
		}
	}
	printf("Total cost : %d\n",cost);
}
