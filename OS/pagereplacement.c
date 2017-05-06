#include<stdio.h>
#include<conio.h>
#include<math.h>
int frame[20]={0},fsize,f=0;
void insert(int page){ 
	frame[f]=page;
	(f==fsize-1)?(f=0):(++f);
}
int isPresent(int page){
	int i;
	for(i=0;i<fsize;i++){
		if(frame[i]==page)
			return 1;
	}
	return 0;
}

void fcfs_replacement(int request[20],int pages){
	int i,j,pagefault=0;
	for(i=0;i<pages;i++){
		for(j=0;j<fsize;j++){
			printf("%d ",frame[j]);
		}
		if(!isPresent(request[i])){
			insert(request[i]);
			pagefault++;
		}
		printf("\n");
	}
	printf("Page Faults : %d",pagefault);
}
void lruInsert(int request[],int pages,int page,int j){
	int i,k,flag[20],min=1000;
	for(i=0;i<fsize;i++)
		if(!frame[i]){
			frame[i]=page;
			return;
		}
	for(i=0;i<fsize;i++){
		for(k=j-1;k>=0;k--){
			if(frame[i]==request[k]){
				flag[i]=k;
				break;
			}
		}
	}
	for(i=0;i<fsize;i++){
		if(flag[i]<min){
			min=flag[i];
			k=i;
		}
	}	
	frame[k]=page;
}
void lru_replacement(int request[],int pages){
	int i,pagefault=0,j;
	for(i=0;i<pages;i++){
		for(j=0;j<fsize;j++){
			printf("%d ",frame[j]);
		}
		if(!isPresent(request[i])){
			lruInsert(request,pages,request[i],i);
			pagefault++;
		}
		printf("\n");
	}
	for(j=0;j<fsize;j++){
			printf("%d ",frame[j]);
	}
	printf("\nPage Faults : %d",pagefault);	
}
void lfuInsert(int request[],int pages,int page,int j){
	int i,k,count[20]={0},min=100;
	for(i=0;i<fsize;i++)
		if(!frame[i]){
			frame[i]=page;
			return;
		}
	for(i=0;i<fsize;i++){
		for(k=0;k<j;k++){
			if(frame[i]==request[k])
				count[i]++;
		}
	}
	for(i=0;i<fsize;i++){
		if(count[i]<=min){
			min=count[i];
			k=i;
		}
	}	
	frame[k]=page;
}
void lfu_replacement(int request[],int pages){
	int i,pagefault=0,j;
	for(i=0;i<pages;i++){
		for(j=0;j<fsize;j++){
			printf("%d ",frame[j]);
		}
		if(!isPresent(request[i])){
			lfuInsert(request,pages,request[i],i);
			pagefault++;
		}
		printf("\n");
	}
	for(j=0;j<fsize;j++){
			printf("%d ",frame[j]);
	}
	printf("\nPage Faults : %d",pagefault);	
}
void main(){
	int pages,request[20],i;
	printf("Enter the frame size\n");
	scanf("%d",&fsize);
	printf("Enter the no. of requests\n");
	scanf("%d",&pages);
	printf("Enter the page-requests\n");
	for(i=0;i<pages;i++)
		scanf("%d",&request[i]);
	//fcfs_replacement(request,pages);
	//lru_replacement(request,pages);
	lfu_replacement(request,pages);
}