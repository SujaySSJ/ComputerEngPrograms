#include<stdio.h>
#define max 20
int timeline[1000]={0};
typedef struct {
	int id,at,bt,wt,tat;
}Process;
Process pqueue[max];
int f=0,r=-1;
void insert(Process p){
	pqueue[++r]=p;
}
void isempty(){
	return (f==r+1);
}
Process extract(){
	return pqueue[f++];
}
void sort(Process p[20],int n){
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
void display(Process p[20],int n){
	int i;
	printf("ID AT BT\n");
	for(i=0;i<n;i++)
		printf("%2d %2d %2d\n",p[i].id,p[i].at,p[i].bt);
}

void fcfs(Process p[20],int n){
	int time=0,i=0,idle++;
	for(i=0;i<n;++i){
		for(j=0;j<p[i].bt)
			timeline[time++]=p[i].id;

	}
	
}
void main(){
	int i,n;
	Process p[20];
	a:printf("Enter the no. of processes(less than 20)");
	scanf("%d",&n);
	if(n>20){
		printf("PRocesses should be less than 20\n");
		goto a;
	}
	printf("Enter ARRival & Burst Time\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id=i+1;
	}
	sort(p,n);
	display(p,n);
}