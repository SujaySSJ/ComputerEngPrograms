#include<stdio.h>
typedef struct 
{
	int w,p,no;
	float pw,s;
}Item;
void sort(Item item[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(item[j].pw<item[j+1].pw){
				Item temp=item[j];
				item[j]=item[j+1];
				item[j+1]=temp;
			}
}
void display(Item item[],int n){
	int i;
	printf("W\tP\tPW\n");
    for(i=0;i<n;i++){
    	printf("%d\t%d\t%.3f\n",item[i].w,item[i].p,item[i].pw);
    }
}
void displayafter(Item item[],int n,float cp,float cw){
	int i;
	printf("N\tW\tP\tPW\tS\n");
    for(i=0;i<n;i++){
    	printf("%d\t%d\t%d\t%.3f\t%.2f\n",item[i].no,item[i].w,item[i].p,item[i].pw,item[i].s);
    }
    printf("Total Profit : %3f\nTotal Weight : %3f\n",cp,cw);
}
void knap01(Item item[],int n,int max){
	float cp=0,cw=0;
	int i,j;
	for(i=0;i<n;i++){
		if(cw+item[i].w<=max){
			item[i].s=1;
			cw+=item[i].w;
			cp+=item[i].p;
		}
		else if(cw==max)
			break;
	}
	displayafter(item,n,cp,cw);
}
void knapFrac(Item item[],int n,int max){
	float cp=0,cw=0;
	int i,j;
	for(i=0;i<n;i++){
		if(cw+item[i].w<=max){
			item[i].s=1;
			cw+=item[i].w;
			cp+=item[i].p;
		}
		else{
			item[i].s=(max-cw)/item[i].w;
			cw=max;
			cp+=item[i].s*item[i].p;
			break;
		}
			
	}
	displayafter(item,n,cp,cw);
}
void main(){
	int n,i,max,ch;
	Item item[30];
	printf("Enter the no of items\n");
	scanf("%d",&n);
	printf("w p\n");
	for(i=0;i<n;i++){
		scanf("%d %d",&item[i].w,&item[i].p);
		item[i].pw=(float)item[i].p/(float)item[i].w;
		item[i].no=i+1;
		item[i].s=0;
	}
	printf("Enter the maximum sack capacity: \n");
	scanf("%d",&max);
	display(item,n);
	sort(item,n);
	printf("Enter the Choice  1:Fractional Knapscack  2:0/1 Knapsack \n");
	scanf("%d",&ch);
	switch(ch){
		case 1:knapFrac(item,n,max);
			   break;
		case 2:knap01(item,n,max);
		       break;
		default:printf("Enter a valid input\n");
				break;       
	}
}
