#include<stdio.h>
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void accept(int a[],int n)
{
	int i;
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n");
}
void insertion(int a[],int n)
{
	int i,j,val;
	for(i=0;i<n-1;i++)
	{
	val=a[i+1];
	for(j=i;j>=0;j--)
		if(a[j]>val)
			a[j+1]=a[j];
	    else break;
	a[j+1]=val;	
    }
}
void shell(int a[],int n)
{
int i,j,k,inc,val;
for(inc=n/2;inc>=1;inc=inc/2)
{
	for(k=0;k<inc;k++)
	{
		for(i=k;i<n-inc;i=i+inc)
		{
			val=a[i+inc];
			for(j=i;j>=k;j=j-inc)
				if(a[j]>val)
					a[j+inc]=a[j];
				else break;
		a[j+inc]=val;		
		}
	}
}
}
void main()
{
	int ch;
	int n,a[100];
	while(1)
	{
	printf("Enter your choice 1.Insertion Sort  2.Shell Sort 3.Exit\n");
	scanf("%d",&ch);
	if(ch==3)
		break;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	accept(a,n);
	printf("Unsorted Array : \n");
	display(a,n);
	switch(ch)
	{
		case 1:insertion(a,n);
		       printf("Array after Insertion Sort\n");
		       break;
		case 2:shell(a,n);
		       printf("Array after Shell Sort\n");
		       break;
		default:printf("Enter a valid choice\n");              
    }
    display(a,n);
    }
}