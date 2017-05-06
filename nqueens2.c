#include<stdio.h>
#include<math.h>
void nextvalue(int);
int x[10],n;
void display(int x[],int n){
  char q[20][20];
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
          q[i][j]='.';
  for(i=1;i<=n;i++)
    q[i][x[i]]='Q';
  for(i=1;i<=n;i++)
    {
      printf("%d  ",x[i]);
      for(j=1;j<=n;j++)
        printf("%c ",q[i][j]);
     printf("\n");
     } 
}
void nqueens(int k)
{
  int i;
  a: 
  nextvalue(k);
  if(x[k]==0)
    return;
  if(k==n)
  {
      printf("\n");
      display(x,n);
      printf("\n");
  }
  else nqueens(k+1);
  goto a;
}
void nextvalue(int k)
{
  int j;
  b: x[k]=((x[k]+1)%(n+1));
  if(x[k]==0)
    return;
  for(j=1;j<=k-1;j++)
    if(x[k]==x[j]||(abs(x[k]-x[j])==abs(k-j)))
      goto b;
  return;
}
void main()
{
  
  printf("enter number of queens\n");
  scanf("%d",&n);
  nqueens(1);
}
