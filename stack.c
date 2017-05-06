#include<stdio.h>
# define max 5
# include<conio.h>
int s[max],tos=-1;
void push(int ele)
{
	if(tos==max-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	else
	{
		tos++;
		s[tos]=ele;
	}
}

int isempty()
{
	if(tos==-1)
		return 1;
	return 0;
}

int pop()
{
	int z;
	if(isempty())
	{
		return -1;
	}
	else
	{
		z=s[tos];
		tos--;
		return z;
	}
}

int stacktop()
{
	if(isempty())
	{
		return -1;
	}
	else
	{
		return s[tos];
	}
}

void display()
{
	int i;
	if(isempty())
	{
		printf("Stack empty\n");
		return;
	
	}
	else
	{
		for(i=tos;i>=0;i--)
			printf("%d	",s[i]);
	}
	printf("\n");

}

int main()
{
	int ch,ele;
	while(1)
	{
		printf("Enter choice\n1.PUSH\n2.POP\n3.STACKTOP\n4.DISPLAY\n5.EXIT\n");
		scanf("%d",&ch);
		if(ch==5)
			break;
		switch(ch)
		{
		case 1: printf("Enter the element to push\n");
		        scanf("%d",&ele);
				push(ele);
				display();
				
				break;
		case 2: if(isempty())
				{
					printf("Stack underflow\n");
				}
				else
				{
					ele=pop();
					printf("Popped element = %d\n",ele);
					display();
					
		        }
				break;
		case 3: if(isempty())
				 printf("Stack empty\n");
			    else{
					ele=stacktop();
					printf("Element on top =%d\n",ele);
					
					
				}
				break;
		case 4: display();
                break;
 		default:printf("Invalid choice\n");
		}
	
	}
}




































