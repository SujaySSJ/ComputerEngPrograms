#include<stdio.h>
#include<math.h>
void nextvalue(int);
int x[10],n,adj[20][20],m,c=0;
void display(){
  int i;
  for(i=1;i<=n;i++)
    printf("%d",x[i]);
}
void graphcolouring(int k)
{
  int i;
  a: 
  nextvalue(k);
  if(x[k]==0)
    return;
  if(k==n)
  {
      printf("\n");
      //display(x,n);
      printf("%d\n",m);
      c++;
      printf("\n");
  }
  else graphcolouring(k+1);
  goto a;
}
void nextvalue(int k)
{
  int j;
  b: x[k]=((x[k]+1)%(m+1));
  if(x[k]==0)
    return;
  for(j=1;j<=k-1;j++)
    if(x[k]==x[j]&&adj[j][k]==1)
      goto b;
  return;
}
void main()
{
  int i,j;
  printf("Enter the no of vertices\n");
  scanf("%d",&n);
  //printf("Enter the available colours\n");
  //scanf("%d",&m);
  m=2;
  printf("Enter the adjacency matrix\n");
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&adj[i][j]);
    graphcolouring(1);
    a:if(c==0){
      graphcolouring(1);
      m++;
    }
    if(c==0)
      goto a;


  
}
