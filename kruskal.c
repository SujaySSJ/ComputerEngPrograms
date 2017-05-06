#include<stdio.h>
typedef struct{
	int s,d,w,select;
}Edge;
void sort(Edge edge[],int n){
	int i,j;
	Edge te;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(edge[j].w>edge[j+1].w)
			{
				te=edge[j];
				edge[j]=edge[j+1];
				edge[j+1]=te;
			}
}
int isSameSet(int set[][20],int u,int v){
	if(set[u][v]==1&&set[v][u]==1)
		return 1;
	return 0;
}
void copysets(int set[20][20],int n,int u,int v){
	int i;
	for(i=1;i<=n;i++)
	{
		if(set[u][i]==1)
			set[v][i]=1;
		if(set[v][i]==1)
			set[u][i]=1;
	}
}
void mergeset(int set[][20],int n,int u,int v){
	int i,j;
	copysets(set,n,u,v);
	for(i=1;i<=n;i++){
		if(set[u][i]==1)
			copysets(set,n,u,i);
		if(set[v][i]==1)
			copysets(set,n,v,i);
	}

	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",set[i][j]);
		printf("\n");
	}
	printf("\n");
}
void display(Edge edge[],int e ,int cost){
	int i;
	printf("Selected Edges in MCST are\n");
	for(i=0;i<e;i++){
		if(edge[i].select==1){
			printf("(%d,%d) : %d\n",edge[i].s,edge[i].d,edge[i].w);
		}
	}
	printf("Total Cost : %d\n",cost);
}
void main()
{
	int n,e,set[20][20]={0},i,cost=0;
	Edge edge[20];
	printf("Enter the no of vertices\n");
	scanf("%d",&n);
	printf("Enter the no of edges\n");
	scanf("%d",&e);
	printf("Enter the edges\n");
	printf("Enter Starting vertex,Destination Vertex,Weight\n");
	for(i=0;i<e;i++){
		scanf("%d %d %d",&edge[i].s,&edge[i].d,&edge[i].w);
        set[edge[i].s][edge[i].s]=1;
        set[edge[i].d][edge[i].d]=1;
	}
	sort(edge,e);
	for(i=0;i<e;i++){
			if(isSameSet(set,edge[i].s,edge[i].d)==0)
			{
				edge[i].select=1;
				cost+=edge[i].w;
				mergeset(set,n,edge[i].s,edge[i].d);
			}
	}
	display(edge,e,cost);
}
/*1 2 25
1 4 20
1 3 30
2 3 5
2 4 15
3 4 10
0 25 30 20
25 0 5 15
30 5 0 10
20 15 10 0
1 2 1
2 3 2
1 3 3
1 4 4
3 4 5
0 1 3 4
1 0 2 0
3 2 0 5
4 0 5 0
0 20 8 1000
7 0 1000 1000
15 7 0 3
1000 2 1000 0
*/
