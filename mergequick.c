#include<stdio.h>
void display(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void accept(int x[],int n)
{
	int i;
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	printf("\n");
}
void mergesort(int x[],int lb,int ub)
{
	int m;
	if(lb<ub)
	{
		m=(lb+ub)/2;
		mergesort(x,lb,m);
		mergesort(x,m+1,ub);
		merge(x,lb,m,ub);
	}
}
void merge(int x[],int lb,int m,int ub)
{
	int i=lb,j=m+1,k=0,temp[20];
	while(i<=m&&j<=ub)
		if(x[i]<x[j])
			temp[k++]=x[i++];
		else temp[k++]=x[j++];
	while(i<=m)
		temp[k++]=x[i++];
	while(j<=ub)
		temp[k++]=x[j++];
	k=0;
	for(i=lb;i<=ub;i++)
		x[i]=temp[k++];
}
void quicksort(int x[],int lb,int ub)
{
	int p;
	if(lb<ub)
	{
		p=partition(x,lb,ub);
		quicksort(x,lb,p-1);
		quicksort(x,p+1,ub);
	}
}
int partition(int x[],int lb,int ub)
{
	int val=x[lb],down=lb+1,up=ub,t;
	while(down<=up)
	{
		while(down<=up&&x[down]<=val)
			down++;
		while(x[up]>val)
			up--;
		if(down<up)
		{
			t=x[down];
			x[down]=x[up];
			x[up]=t;
		}
	}
	x[lb]=x[up];
	x[up]=val;
	return up;
}
void main()
{
	int ch;
	int n,x[100];
	while(1)
	{
	printf("Enter your choice 1.Merge Sort  2.Quick Sort 3.Exit\n");
	scanf("%d",&ch);
	if(ch==3)
		break;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	accept(x,n);
	printf("Unsorted Array : \n");
	display(x,n);
	switch(ch)
	{
		case 1:mergesort(x,0,n-1);
		       printf("Array after Merge Sort\n");
		       break;
		case 2:quicksort(x,0,n-1);
		       printf("Array after Quick Sort\n");
		       break;
		default:printf("Enter x valid choice\n");              
    }
    display(x,n);
    }
}