#include<stdio.h>
#include<math.h>
void display(int schedule[100],int n,int trackMovement){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",schedule[i]);
	}
	printf("\nTotal track movement :%d\n",trackMovement);
}
void fcfs_scheduler(int request[100],int n,int headpos){
	int i,schedule[100],trackMovement=0;
	for(i=0;i<n;i++){
		schedule[i]=request[i];
		(i==0)?(trackMovement+=abs(request[i]-headpos)):(trackMovement+=abs(request[i]-request[i-1]));
	}
	printf("FCFS : ");
	display(schedule,n,trackMovement);
}

void sstf_scheduler(int request[100],int n,int headpos){
	int i,schedule[100],seek[2][100],trackMovement=0,j;
	for(i=0;i<n;i++){
		seek[0][i]=request[i];
		seek[1][i]=abs(request[i]-headpos);
	}
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(seek[1][j]>seek[1][j+1]){
				int temp=seek[1][j];
				seek[1][j]=seek[1][j+1];
				seek[1][j+1]=temp;
				temp=seek[0][j];
				seek[0][j]=seek[0][j+1];
				seek[0][j+1]=temp;
			}
	for(i=0;i<n;i++){
		schedule[i]=seek[0][i];
		(i==0)?(trackMovement+=seek[1][i]):(trackMovement+=abs(schedule[i]-schedule[i-1]));
	}
	printf("SSTF\n");
	display(schedule,n,trackMovement);
}
void scan_scheduler(int request[100],int n,int headpos){
	int i,schedule[100],trackMovement=0,j=0;
	int left[20],right[20],lc=0,rc=0;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(request[j]>request[j+1]){
				int temp=request[j];
				request[j+1]=request[j];
				request[j]=request[j+1];
			}
	for(i=0;i<n;i++)
		(request[i]<=headpos)?(left[lc++]=request[i]):(right[rc++]=request[i]);
	for(i=lc-1;i>=0;i--){
		schedule[j++]=left[i];
		(i==lc-1)?(trackMovement+=head-left[i]):((i==0)?(trackMovement+=left[i+1]-left[i]):(trackMovement+=left[0]));
	}
	for(i=0;i<rc;i++){
		schedule[j++]=right[i];
		(i==rc-1)?(trackMovement+=right[i]):(trackMovement+=right);
	}	
}
void main(){
	int request[100],headpos,n,tracks,trackMovement=0;
	int i;
	printf("Enter the no. of tracks\n");
	scanf("%d",&tracks);
	printf("Enter the no. of requests\n");
	scanf("%d",&n);
	printf("Enter the request array\n");
	for(i=0;i<n;i++)
		scanf("%d",&request[i]);
	printf("The current head position :\n");
	scanf("%d",&headpos);
	//fcfs_scheduler(request,n,headpos);
	sstf_scheduler(request,n,headpos);

}