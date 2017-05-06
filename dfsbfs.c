#include<stdio.h>
int adj[20][20]={0},visited[20]={0},n;
void dfs(int node)
{
	int i;
	printf("%d  ",node+1);
	visited[node]=1;
	for(i=0;i<n;i++)
		if(adj[node][i]==1&&visited[i]==0)
			dfs(i);
}
void bfs(int node)
{
	int q[20],f=-1,r=-1,nd,i;
	visited[node]=1;
	q[++r]=node;
	while(f!=r)
	{
		nd=q[++f];
		printf("%d  ",nd+1);
		for(i=0;i<n;i++)
			if(adj[nd][i]==1&&visited[i]==0)
			{
				visited[i]=1;
				q[++r]=i;
			}
	}
}
void main()
{
	int i,e,v1,v2,node;
	printf("Enter the no. of nodes\n");
	scanf("%d",&n);
	printf("Enter the no. of edges\n");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("Enter the edge : ");
		scanf("%d%d",&v1,&v2);
		adj[v1-1][v2-1]=adj[v2-1][v1-1]=1;
	}
	printf("Enter the starting vertex for DFS\n");
	scanf("%d",&node);
	dfs(node-1);
	printf("\nEnter the starting vertex for BFS\n");
	scanf("%d",&node);
	bfs(node-1);
}