#include <stdio.h>

int available[20],need[20][20],allocation[20][20],max[20][20],n,m;
int request[20],finish[20]={0};

void accept(int mat[][20]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&mat[i][j]);
}

void get_need(){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j]=max[i][j]-allocation[i][j];
}

int need_check(int p,int available[]){
	int i,j;
	for(i=0;i<m;i++){
		if(need[p][i]<=available[i])
			continue;
		else return 0;
	}
	return 1;
}

int check_safety(){
	int i,j;
	int work[20];
	for(i=0;i<m;i++)
		work[i]=available[i];
	for(i=0;i<n;i++){
		printf("%d\n",finish[i]);
		if(finish[i]==0 && need_check(i,work)){
			for(j=0;j<m;j++)
				work[j]+=allocation[i][j];
			finish[i]=1;
			i=0;
		}
	}
	for(i=0;i<n;i++)
		if(!finish[i])
			return 0;
	return 1;	
}
void display_state(){
	if(check_safety())
		printf("Safe state\n");
	else printf("Deadlocked state\n");
}
int resource_request(int r){
	int i,j=0;
	for(i=0;i<m;i++){
		if(request[j]<=need[r][j])
			continue;
		else {
			printf("Process excceded maximum claim\n");
			return -1;
		}	
	}
	for(i=0;i<m;i++){
		if(request[i]<=available[i])
			continue;
		else {
			printf("Not enough resources available\n");
			return -1;
		}	
	}
	for(i=0;i<m;i++){
		available[i]-=request[i];
		allocation[r][i]+=request[i];
		need[r][i]-=request[i];
	}
	return 1;

}
int main(int argc, char const *argv[])
{
	int i,j,r;
	char ch;
	printf("Enter the no. of esses\n");
	scanf("%d",&n);
	printf("Enter the no. of resources\n");
	scanf("%d",&m);
	printf("Enter the available array\n");
	for(i=0;i<m;i++)
		scanf("%d",&available[i]);
	printf("Enter the maximum need matrix\n");
	accept(max);
	printf("Enter the allocated matrix\n");
	accept(allocation);
	get_need();
	display_state();
	do{
		printf("Enter the number of requesting process\n");
		scanf("%d",&r);
		printf("Enter the request array\n");
		for(i=0;i<m;i++)
			scanf("%d",request[i]);
		if(resource_request(r))
			printf("Resource allocated.\nSystem in safe state\n");
		else printf("Resource UNALLOCATED.\n");
		printf("Enter 'q' to quit\n");
		scanf("%c",&ch);
	}while(ch!='q');		
	return 0;
}