#define size 2
#include<stdio.h>
int createindex(int x[],int n,int index[])
{
	int i,j=0;
	for(i=0;i<n;i+=size)
		index[j++]=x[i];
	index[j++]=x[n-1];
	return j;
}
int search(int x[],int n,int index[],int m,int ele)
{
	int i,j,k;
	if(ele<x[0]||ele>x[n-1])
		return 0;
	for(i=0;i<m;i++)
		if(ele<=index[i])
			break;
	j=i*size;
	if(j>n-1)
		j=n-1;
	for(k=j;k>(i-1)*size;k--)
		if(ele>=x[k])
			break;
	if(ele==x[k])
		return 1;
	else return 0;
}
void main()
{
	int m,x[50],index[20],n,i,ele;
	printf("Enter th no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	m=createindex(x,n,index);
	printf("Enter the element to be searched\n");
	scanf("%d",&ele);
	if(search(x,n,index,m,ele))
		printf("%d found",ele);
	else printf("%d not found",ele);
}





