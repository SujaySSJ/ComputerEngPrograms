#include<stdio.h>
void selection(int x[],int n){
	int i,j,val,min,pos,k;
	for(i=0;i<n-1;i++){
		min=x[i];
		pos=i;
		for(j=i+1;j<n;j++)
			if(x[j]<min){
				min=x[j];
				pos=j;
			}
		x[pos]=x[i];
		x[i]=min;
		for(k=0;k<=i;k++)
			printf("%d  ",x[k] );
		printf("\n");
	}
}
void insertion(int x[],int n){
	int i,j,val,k;
	for(i=0;i<n-1;i++){
		val=x[i+1];
		for(j=i;j>=0;j--)
			if(x[j]>val)
				x[j+1]=x[j];
			else break;
		x[j+1]=val;	
		for(k=0;k<=i+1;k++)
			printf("%d  ",x[k]);
		printf("\n");
	}
}
int partition(int x[],int lb,int ub){
	int val=x[lb],down=lb+1,up=ub,k;
	while(down<=up){
		while(down<=up&&x[down]<=val)
			down++;
		while(x[up]>val)
			up--;
		if(down<up){
			int t=x[down];
			x[down]=x[up];
			x[up]=t;
		}
		x[lb]=x[up];
		x[up]=val;
		for(k=0;k<9;k++)
			printf("%d  ",x[k] );
		printf("\n");
		return up;
	}
}
void quicksort(int x[],int lb,int ub){
	int p;
	if(lb<ub){
		p=partition(x,lb,ub);
		quicksort(x,lb,p-1);
		quicksort(x,p+1,ub);
	}
}
void merge(int x[],int lb,int m,int ub){
	int i=lb,j=m+1,k=0,temp[20];
	while(i<=m&&j<=ub)
		temp[k++]=x[i]<x[j]?x[i++]:x[j++];
	while(i<=m)
		temp[k++]=x[i++];
	while(j<=ub)
		temp[k++]=x[j++];
	k=0;
	for(i=lb;i<=ub;i++){
		x[i]=temp[k++];
		printf("%d  ",x[i] );
	}
	printf("\n");
}
void mergesort(int x[],int lb,int ub){
	int m;
	if(lb<ub){
		m=(lb+ub)/2;
		mergesort(x,lb,m);
		mergesort(x,m+1,ub);
		merge(x,lb,m,ub);
	}
}

void main(){
	int x[20]={9,8,7,6,5,4,3,2,1},n,i;
	mergesort(x,0,8);
	for(i=0;i<9;i++)
		printf("%d  ",x[i]);
	printf("\n");
}