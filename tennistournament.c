#include<stdio.h>
int a[20][20];
void leftrotate(int x[20],int lb,int ub)
{
	int i,val;
	val=x[0];
	for(i=lb;i<ub;i++)
		x[i]=x[i+1];
	x[ub]=val;
}
void rightrotate(int x[20],int lb, int ub)
{
	int i,val;
	val=x[ub];
	for(i=ub;i>lb;i--)
		x[i]=x[i-1];
	x[0]= val;
}
void makeSchedule(int x[][10],int lb, int ub)
{
	if(lb==ub-1)
	{
		x[lb][0]=ub;
		x[ub][0]=lb;
		return;
	}
	m=(lb+ub)/2;
	makeSchedule(x,lb,m);
	makeSchedule(x,m+1,ub);
	
	
}
void main()
{
	int a[]={1,2,3,4},i;
	leftrotate(a,0,3);
	for(i=0;i<4;i++)
		printf("%d	",a[i]);
	rightrotate(a,0,3);
	for(i=0;i<4;i++)
		printf("%d	",a[i]);
}