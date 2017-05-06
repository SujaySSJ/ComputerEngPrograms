#include<stdio.h>
#define max 6
int q[max],f=0,r=-1;
void insert(int ele)
{
if(r==max-1)
{
	printf("QUeue overflow\n");
	return;
}
r++;
q[r]=ele;

}	

int isempty()
{
	if(f==r+1)
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
	z=q[f];
	f++;
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
	for(i=f;i<=r;i++)
		printf("%d	",q[i]);
	printf("\n");
}
int main()
{
	int ch,ele;
	while(1)
	{
		printf("Enter choice\n1.INSERT\n2.DELETE\n3.QUEUEFRONT\n4.DISPLAY\n5.EXIT\n");
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

	
























