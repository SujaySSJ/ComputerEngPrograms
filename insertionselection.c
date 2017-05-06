#include<stdio.h>
#include<sys/time.h>
void fillfile(int n)
{
int i,k=n;
FILE *fp;
fp=fopen("INPUT.txt","w");
for(i=0;i<=n;i++)
   fprintf(fp,"%d ",k--);
fclose(fp);
} 
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
void selection(int x[],int n)
{
	int i,j,min,pos;
	for(i=0;i<n-1;i++)
	{
		min=x[i];
		pos=i;
		for(j=i+1;j<n;j++)
			if(x[j]<min)
			{
				min=x[j];
				pos=j;
			}
		x[pos]=x[i];
        x[i]=min;		
	}
}
void main()
{
struct timeval tim;
double start,end;
int x[10000],i=0;

FILE *fp;
fp=fopen("INPUT.txt","r");
fillfile(10000);
while(feof(fp)==0)
   fscanf(fp,"%d",&x[i++]);
gettimeofday(&tim,NULL);
start=tim.tv_usec ;
insertion(x,10000);
//selection(x,10000);
gettimeofday(&tim,NULL);
end=tim.tv_usec;

printf("Reverse Sorted \nTime taken by Insertion  for 10000 integers : %lf microseconds \n",end-start);   
while(feof(fp)==0)
   fscanf(fp,"%d",&x[i++]);
gettimeofday(&tim,NULL);
start=tim.tv_usec ;
selection(x,10000);
gettimeofday(&tim,NULL);
end=tim.tv_usec;

printf("\nTime taken by Selection Sort  for 10000 integers : %lf microseconds ",end-start);  
printf("\n");
fclose(fp);
}     

