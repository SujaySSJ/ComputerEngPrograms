#include<stdio.h>
#include<math.h>
int n,x[20];
void display(){
	char q[20][20],i,j;
	for(i=1;i<=n;i++){
		printf("%d ",x[i]);
		for(j=1;j<=n;j++){
			q[i][j]=(x[i]==j)?'Q':'.';
			printf("%c ",q[i][j] );
		}
		printf("\n");
	}
}
void nextvalue(k){
	int i,j;
	b:x[k]=(x[k]+1)%(n+1);
	if(x[k]==0)
		return;
	for(j=1;j<=k-1;j++)
		if(x[k]==x[j]||(abs(k-j)==abs(x[k]-x[j])))
			goto b;
	return;	

}
void nqueens(int k){
	a:nextvalue(k);
	if(x[k]==0)
		return;
	if(k==n){
		printf("\n");
		display();
	}
	else nqueens(k+1);
	goto a;
}
void main(){
	printf("Enter the no of queens\n");
	scanf("%d",&n);
	nqueens(1);
}