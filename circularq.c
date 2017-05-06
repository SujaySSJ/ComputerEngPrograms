#include<stdio.h>
#define max 3
int q[max],f=0,r=max-1,c=0;
void insert(int ele)
{
if(c==max)
{
	printf("QUeue overflow\n");
	return;
}
c++;
r=(r+1)%max;
q[r]=ele;

}	

int isempty()
{
	if(c==0)
		return 1;
	else return 0;
}

int del()
{
	int z;
	if(isempty())
	{
		return -1;
	
	}
	c--;
	z=q[f];
	f=(f+1)%max;
	return z;
}

int qfront()
{
	if (isempty())
		return -1;
	else return q[f];

}

void display()
{
	int i;
	if(isempty())
	{
		printf("Queue empty\n");
		return;
	}
	i=f;
	while(1)
	{
		printf("%d	",q[i]);
		if(i==r)
			break;
		i=(i+1)%max;
	}
	printf("\n");
}
int main()
{
	int ch,ele;
	while(1)
	{
		printf("Enter choice 1.INSERT 2.DELETE 3.QUEUEFRONT 4.DISPLAY 5.EXIT\n");
		scanf("%d",&ch);
		if(ch==5)
			break;
		switch(ch)
		{
		case 1: printf("Enter the element to insert\n");
		        scanf("%d",&ele);
				insert(ele);
				display();
				
				break;
		case 2: if(isempty())
				{
					printf("Queue underflow\n");
				}
				else
				{
					ele=del();
					printf("Deleted element = %d\n",ele);
					display();
					
		        }
				break;
				
				case 3: if(isempty())
				 printf("Queue empty\n");
			    else{
					ele=qfront();
					printf("Element at front =%d\n",ele);
					
					
				}
				break;
		case 4: display();
                break;
 		default:printf("Invalid choice\n");
		}
	
	}
}

	
























