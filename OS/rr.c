#include<stdio.h>
typedef struct{
	int id,wt,at,bt,rt,flag,end,tat,tq;
}Process;
Process p[20];
int schedule[200],idle=0,time_quantum;
unsigned int CPU_time=0;
Process pqueue[2000];
int f=0,r=-1;
void insert(Process p){
	pqueue[++r]=p;
}
int isempty(){
	return (f==r+1);
}
Process extract(){
	return pqueue[f++];
}
int ready_processes(int n){
	int i,j=0;
	for(i=0;i<n;i++)
		if(!p[i].flag && p[i].at<=CPU_time)
			j++;
	return j;
}
void update_queue(int n){
	int i;
	for(i=0;i<n;i++)
		if(p[i].at==CPU_time)
			insert(p[i]);
}
void sort(int n){
	int i,j;
	Process temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].at>p[j+1].at || (p[j].at==p[j+1].at && p[j].bt>p[j+1].bt)){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
}

void rr_scheduler(int n){
	int i,j;
	Process temp;
	temp=extract();
	for(i=0;i<n;i++){
		if(temp.id==p[i].id){
			while(p[i].tq!= 0 && p[i].rt!=0){
				p[i].rt--;
				p[i].tq--;
				schedule[CPU_time++]=p[i].id;
				update_queue(n);
			}
			if(p[i].rt==0){
				p[i].flag=1;
				p[i].end=CPU_time;
				p[i].tat=p[i].end-p[i].at;
				p[i].wt=p[i].tat-p[i].bt;
			}
			else{
				p[i].tq=time_quantum;
				insert(p[i]);
			}
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
	printf("Enter the time quantum\n");
	scanf("%d",&time_quantum);
	printf("Enter the arrival and the burst time\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id=i+1;
		p[i].flag=0;
		p[i].rt=p[i].bt;
		p[i].tq=time_quantum;
	}
	sort(n);
	update_queue(n);
	while(1){
		rno=ready_processes(n);
		if(rno==0){
			idle++;
			schedule[CPU_time++]=0;
			update_queue(n);
		}
		else if(!isempty())
				rr_scheduler(n);
		if(all_scheduled(n))
			break;
	}
	print_processes(n);
	display_schedule();
}
