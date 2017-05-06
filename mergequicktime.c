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
int partition(int x[],int lb,int ub)
{
int val=x[lb],down=lb+1,up=ub;
while(down<=up)
{
   while(x[down]<=val&&down<=up)
        down++;
    while(x[up]>val)
       up--;
       if(down<up)
       {
       int temp=x[down];
       x[down]=x[up];
       x[up]=temp;
       }
x[lb]=x[up];
x[up]=val;
return up;
}       
}
             
void quicksort(int x[],int lb, int ub)
{
int p;
if(lb<ub)
 {
 p=partition(x,lb,ub);
 quicksort(x,lb,p-1);
 quicksort(x,p+1,ub);
 }
}
void merge(int x[],int lb, int m ,int ub)
{
int temp[100000],i,j,k;
i=lb;
j=m+1;
k=0;
while(i<=m&&j<=ub)
       if(x[i]<=x[j])
       temp[k++]=x[i++];
       else temp[k++]=x[j++];
while(i<=m)
     temp[k++]=x[i++];
 while(j<=ub)
     temp[k++]=x[j++];
k=0;
for(i=lb;i<=ub;i++)
    x[i]=temp[k++];
}                    

void mergesort(int x[],int lb,int ub)
{
int m;
  if(lb<ub)
  {
  m=(lb+ub)/2;
  mergesort(x,lb,m);
  mergesort(x,m+1,ub);
  merge(x,lb,m,ub);
  }
}
void main()
{
struct timeval tim;
double start,end;
int x[100000],i=0;

FILE *fp;
fp=fopen("INPUT.txt","r");
fillfile(100000);
while(feof(fp)==0)
   fscanf(fp,"%d",&x[i++]);
gettimeofday(&tim,NULL);
start=tim.tv_usec ;
//quicksort(x,0,100000);   
mergesort(x,0,100000);
gettimeofday(&tim,NULL);
end=tim.tv_usec;
/*printf("Sorted Array: \n");
for(i=0;i<100000;i++)
   printf("%d ",x[i]);*/
printf("Reverse Sorted \nTime taken by MergeSort  for 100000 integers : %lf microseconds ",end-start);   
printf("\n");
fclose(fp);
}     

