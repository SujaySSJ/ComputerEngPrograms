#include<stdio.h>
typedef struct{
	int id,wt,at,bt,rt,flag,end,tat;
}Process;
Process p[20],temp;
int schedule[200],idle=0;
unsigned int CPU_time=0;
int ready_processes(Process rp[20],int n,int curr_time){
	int i,j=0;
	for(i=0;i<n;i++)
		if(!p[i].flag && p[i].at<=curr_time){
			rp[j++]=p[i];
		}
	return j;		
}
void srtn_scheduler(Process rp[20],int rno,int n){
	int i;
	temp = rp[0];
	for(i=0;i<rno;i++)
		if(rp[i].rt<temp.rt)
			temp=rp[i];
	schedule[CPU_time++]=temp.id;
	for(i=0;i<n;i++){
		if(temp.id==p[i].id){
			p[i].rt--;
			if(p[i].rt==0){
				p[i].flag=1;
				p[i].end=CPU_time;
				p[i].tat=p[i].end-p[i].at;
				p[i].wt=p[i].tat-p[i].bt;
			}	
			break;		
		}
	}
					
}
void print_processes(int n){
	int i,atat=0,awt=0;
	printf("ID AT BT CT TAT WT\n");
	for(i=0;i<n;i++){
		printf("%2d %2d %2d %2d %2d %2d\n",p[i].id,p[i].at,p[i].bt,p[i].end,p[i].tat,p[i].wt);
		atat+=p[i].tat;
		awt+=p[i].wt;
	}
	printf("Average Turn Around Time : %d\nAverage Waiting Time : %d\nCPU Idle Time : %d\n",atat/n,awt/n,idle);	
	printf("\n");	
}
void display_schedule(){
	int i;
	for(i=0;i<CPU_time;i++){	
	   	   printf("%d ",schedule[i]);
	}
	printf("\n");   	   
}
int all_scheduled(int n){
	int i,j;
	for(i=0;i<n;i++)
		if(p[i].flag==0)
			return 0;
	return 1;		
}
void main(){
	int i,n,rno=0;
	Process rp[20];
        a:printf("Enter the no. of processes\n");
	scanf("%d",&n);
	if(n>20){
		printf("No. of processes must be less than 20\n");
		goto a;
	}
	printf("Enter the arrival and the burst time\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id=i+1;
		p[i].flag=0;
		p[i].rt=p[i].bt;
	}
	while(1){
		rno=ready_processes(rp,n,CPU_time);
		if(rno==0){
			idle++;
			schedule[CPU_time++]=0;
		}
		else 
			srtn_scheduler(rp,rno,n);
		if(all_scheduled(n))
			break;	
	}
	print_processes(n);
	display_schedule();	
			
}
