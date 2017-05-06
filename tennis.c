#include<stdio.h>
void cyclic(int b[20],int m)
  {
   int i,l,t;
    l=m;
    t=b[1];
   for(i=1;i<l;i++)
   {
    b[i]=b[i+1];
   }
   b[l]=t;
  }
 void reversecyclic(int a[20],int m)
  {
   int i,l,t;
    l=m;
    t=a[l];
   for(i=l;i>1;i--)
   {
    a[i]=a[i-1];
   }
   a[1]=t;
  }
void makeschedule(int x[][50],int lb,int ub)
{
 int i,j,t,k,l,r,m,a[25],b[25];
 if (lb==ub-1)
 {
  x[lb][1]=ub;
  x[ub][1]=lb;
  return;
 }
 m=(lb+ub)/ 2;
 makeschedule(x,lb,m);
 makeschedule(x,m+1,ub);
 j=1;
 for(i=lb;i<=m;i++)
    a[j++]=i;
 j=1;
 for(i=m+1;i<=ub;i++)
    b[j++]=i;
 k=m-lb+1;
 for(i=lb;i<=m;i++)
 {
  r=1;
  for(j=lb;j<=m;j++)
    x[j][k]=b[r++];
  r=1;
  for(j=m+1;j<=ub;j++)
     x[j][k]=a[r++];
  reversecyclic(a,(m-lb)+1);
  cyclic(b,ub-m);
  k++;
 }

 return;
}
 void main()
 {
  int x[50][50],n,i,j;
  printf("Enter the no. of teams\n");
  scanf("%d",&n);
  makeschedule(x,1,n);
  printf(" ");
  for(i=1;i<n;i++)
	  printf(" %d",i);
  printf("\n");
  for(i=1;i<=n;i++)
  {
	printf("%d|",i);
   for(j=1;j<=n-1;j++)
    printf("%d ",x[i][j]);
   printf("\n");
  }
  }
