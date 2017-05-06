#include<stdio.h>
#include<sys/time.h>
void insertion(int a[],int n)
{
	int i,j,val;
	for(i=0;i<n-1;i++)
	{
	val=a[i+1];
	for(j=i;j>=0;j--)
		if(a[j]>val)
			a[j+1]=a[j];
	    else break;
	a[j+1]=val;	
    }
}
void fillfile(int n){
	FILE *fp;
	fp=fopen("INPUT.txt","w");
	int i,k=n;
	for(i=0;i<n;i++)
		fprintf(fp,"%d ",k--);
	fclose(fp);
}
void display(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void main(){
	struct timeval tim;
	double t1,t2;
	FILE *fp;
	int x[10000],i=0,j;
	fillfile(10000);
	fp=fopen("INPUT.txt","r");
	while(feof(fp)==0)
		fscanf(fp,"%d",&x[i++]);
	i--;
	gettimeofday(&tim,NULL);
	t1=tim.tv_sec;//+tim.tv_usec;
	insertion(x,i);
	gettimeofday(&tim,NULL);
	t2=tim.tv_sec;//+tim.tv_usec;
	
	display(x,i);
	printf("Time passed=%lf microseconds",t2-t1);
	fclose(fp);
	
}