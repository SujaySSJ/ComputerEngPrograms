#include<stdio.h>
void sort(float p[],float w[],int n)
{
	int i,j;
	float ptemp,wtemp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if((p[i]/w[i])<(p[j]/w[j]))
			{
				ptemp=p[i],wtemp=w[i];
				p[i]=p[j],w[i]=w[j];
				p[j]=ptemp,w[j]=wtemp;
			}
		}
	}
}
float * Fknap(float p[],float w[],int n,int m,float *cw,float *cp)
{
	int i;
	float x[20]={0};
	sort(p,w,n);
	*cp=*cw=0;
	for(i=0;i<n;i++)
	{
		if((*cw+w[i])<m)
		{
			x[i]=1;
			*cw+=w[i];
			*cp+=p[i];
		}
		else
		{
			x[i]=(m-*cw)/w[i];
			*cw=m;
			*cp+=x[i]*p[i];
			break;
		}
	}
	return x;
}
void display(float a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%f	 ",a[i]);
	
}
void main()
{
	float *x,p[20],w[20],fp,fw;
	int n,m,i;
	printf("Enter the no of objects\n");
	scanf("%d",&n);
	printf("Enter the maximum capacity of the sack\n");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		printf("Weight and Profit Object %d\n",i+1);
		scanf("%f %f",&w[i],&p[i]);
	}
	x=Fknap(p,w,n,m,&fw,&fp);
	display(p,n);
	display(w,n);
	display(x,n);
}

