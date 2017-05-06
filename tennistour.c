#include<stdio.h>
#include<math.h>
int bk;
void rotateleft(int x[][20],int lb,int ub,int col)
{
int i,val,nextcol=col+1;
val=x[lb][col];

for(i=lb;i<=ub;i++)
	x[i][nextcol]=x[i+1][col];
x[ub][nextcol]=val;
}
void rotateright(int x[][20], int lb, int ub,int col)
{
int i,val,nextcol=col+1;
val=x[ub][col];
for(i=ub;i>=lb;i--)
	x[i][nextcol]=x[i-1][col];
x[lb][nextcol]=val;
}
void make_schedule(int a[][20],int lb,int ub)
{
int m,i,j;
if(lb==ub-1)
	{
	a[lb][0]=ub;
	a[ub][0]=lb;
	return;
	}
m=(lb+ub)/2;
make_schedule(a,lb,m) ;
make_schedule(a,m+1,ub);

for(i=m+1,j=lb;i<=ub,j<=m;i++,j++)
{
	a[i][m-lb]=j;
	a[j][m-lb]=i;
}
for(i=0,j=m-lb;i<m;i++,j++){
	rotateleft(a,lb,m,j);
    rotateright(a,m+1,ub,j);
}
}
void display(int x[][20],int r,int c)
{
int i,j;
printf("Teams\t\tDays\t\n__");
for(i=1;i<=c;i++)
	printf("%2d__",i);
printf("\n");
for(i=0;i<r;i++)	
	{
	printf("%2d|",i+1);
	for(j=0;j<c;j++)
		printf(" %2d ",x[i][j]<bk?x[i][j]+1:-1);
	printf("\n");
	}
}		
void main()
{
int i,x[20][20]={0},n,r,c,j;
printf("Enter the no. of teams\n");
scanf("%d",&n);
bk=n;
n = pow(2, ceil(log(n)/log(2)));
printf("%d\n",n);
make_schedule(x,0,n-1);
display(x,n,n-1);
}
