#include<stdio.h>
int w[20],m,n;
/*int arraysum(int n){
	int i,s=0;
	for(i=0;i<n;i++)
		s+=w[i];
	printf("%d\n",s );
	return s;
}*/
void display(int x[],int n){
	int i;
	printf("The solution is : \n");
	for(i=0;i<n;i++)
		//if(x[i]==1)
			printf("%d ",x[i]);
	printf("\n");	
}
void sumofsub(int s,int k,int r){
	int x[20],i;
	printf("%d %d %d\n",s,k,r);
	x[k]=1;
	if(s+w[k]==m)
		for(i=0;i<n;i++)
			printf("%d ",x[i]);
	else if(s+w[k]+w[k+1]<=m)
		sumofsub(s+w[k],k+1,r-w[k]);
	if(s+r-w[k]>=m && s+w[k+1]<=m){
		x[k]=0;
		sumofsub(s,k+1,r-w[k]);
	}
	return;
}
void main(){
	int i,s=0;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		s+=w[i];
	}
	printf("Enter the required sum\n");
	scanf("%d",&m);
	sumofsub(0,1,s);
}