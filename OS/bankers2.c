#include <stdio.h>

int available[20],need[20][20],allocated[20][20],maxneed[20][20],processes,resources;
int request[20],finish[20]={0};
int tavailable[20],tneed[20][20],tallocated[20][20],tfinish[20]={0};
int allFinished(){
	int i;
	for(i=0;i<processes;i++)
		if(!finish[i])
			return 0;
	return 1;	
}
void saveData(int c){
	int i,j;
	if(c==1){
		for(i=0;i<processes;i++){
			for(j=0;j<resources;j++){
				tneed[i][j]=need[i][j];
				tallocated[i][j]=allocated[i][j];
			}
			tavailable[i]=available[i];
			tfinish[i]=finish[i];
		}
	}
	else{
		for(i=0;i<processes;i++){
			for(j=0;j<resources;j++){
				need[i][j]=tneed[i][j];
				allocated[i][j]=tallocated[i][j];
			}
			available[i]=tavailable[i];
			finish[i]=tfinish[i];
		}
	}

}
int safetyCheck(){
	int i=0,j,k=0,m;
	int change=0;
	while(!allFinished()){
		k=0;
		if(finish[i]==0){	
			for(j=0;j<resources;j++){
				if(need[i][j]<=available[j]){
					k++;
				}	
			}
		}	
		if(k==resources){
			for(j=0;j<resources;j++){
				available[j]+=allocated[i][j];
				allocated[i][j]=0;
			}
			finish[i]=1;
			change++;
		}
		if(i==processes){
			if(change==0)
				break;
			i=0;
			change=0;
		}
		else i++;
	}
	i=allFinished();
	saveData(0);
	return i;
}
int resourceRequest(int r){
	int i,j;
	for(i=0;i<resources;i++){
		if(request[i]<=need[r][i])
			continue;
		else{
			printf("Process exceeded maximum claim\n");
			return 0;
		}
	}	
	for(i=0;i<resources;i++){
		if(request[i]<=available[i])
			continue;
		else{
			printf("Not enough resources available\n");
			return 0;
		}
	}	
	saveData(1);
	for(i=0;i<resources;i++){
		available[i]-=request[i];
		allocated[r][i]+=request[i];
		need[r][i]-=request[i];
	}
	if(safetyCheck()){
		for(i=0;i<resources;i++){
			available[i]-=request[i];
			allocated[r][i]+=request[i];
			need[r][i]-=request[i];
		}
		return 1;
	}
	else return 0;
}
void display(int mat[][20]){
	int i,j;
	for(i=0;i<processes;i++){
		for(j=0;j<resources;j++)
			printf("%d ",mat[i][j] );
		printf("\n");
	}
}
void main(){
	int i,j,r;
	char ch;
	printf("Enter no. of processes\n");
	scanf("%d",&processes);
	printf("Enter the no of resources\n");
	scanf("%d",&resources);
	printf("Enter the max-need matrix\n");
	for(i=0;i<processes;i++)
		for(j=0;j<resources;j++)
			scanf("%d",&maxneed[i][j]);
	printf("Enter the allocated matrix\n");
	for(i=0;i<processes;i++)
		for(j=0;j<resources;j++)
			scanf("%d",&allocated[i][j]);
	printf("Enter the available resource array\n");
	for(i=0;i<resources;i++)
		scanf("%d",&available[i]);
	for(i=0;i<processes;i++)
		for(j=0;j<resources;j++)
			need[i][j]=maxneed[i][j]-allocated[i][j];
	saveData(1);
	if(safetyCheck())
		printf("Safe state\n");	
	else {
		printf("Deadlocked state\n");
		return;
	}
	do{
		printf("Enter the no of requesting process\n");
		scanf("%d",&r);	
		printf("Enter the request resource array\n");
		for(i=0;i<resources;i++)
			scanf("%d",&request[i]);
		if(resourceRequest(r-1)){
			printf("Request Granted\n");
		}
		else printf("Request Denied\n");
		fflush(stdin);
		printf("Enter q to quit\n");
		scanf("%c",&ch);	
	}while(ch!='q');
}



/*

3 2 1
1 2 2
2 4 3
2 5 3
1 0 1
0 2 1
2 2 1
1 3 2
1 2 2

*/