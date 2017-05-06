#include<stdio.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

void minmax(int x[],int lb,int ub,int *fmin,int *fmax)
{
	int lmin,lmax,rmax,rmin,mid;
	if(lb==ub)
	{
		*fmin=x[lb];
		*fmax=x[lb];
		return;
	}
	if(lb==ub-1)
	{
	*fmin=min(x[lb],x[ub]);
	*fmax=max(x[lb],x[ub]);
	return;
	}
	mid=(lb+ub)/2;
	minmax(x,lb,mid,&lmin,&lmax);
	minmax(x,mid+1,ub,&rmin,&rmax);
	*fmin=min(lmin,rmin);
	*fmax=max(lmax,rmax);
	return;
}
void main()
{
	int i,n,x[100],min,max;
	printf("Enter the no of integers: ");
	scanf("%d",&n);
	printf("Enter %d integers",n);
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	minmax(x,0,n-1,&min,&max);
	printf("Maximun : %d \nMinimun : %d\n",max,min);
	
}