#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int data;
	struct node *next;
}node;
node *start=NULL;
void display()
{
	node *q;
	if(start==NULL){
		printf("Queue Empty\n");
		return;
	}
	q=start;
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
}
void insert(int ele)
{
	node *p,*q,*f;
	p=(node *)malloc(sizeof(node));
	p->data=ele;
	p->next=NULL;
	if(start==NULL)
	{
		start=p;
		return;
	}
    if(ele>start->data)
	{
		p->next=start;
		start=p;
		return;
	} 
	q=start;
	f=NULL;
	while(q!=NULL)
	{
		if(ele>q->data)
			break;
		else
		{
			f=q;
			q=q->next;
		}
	}
	p->next=f->next;
	f->next=p;
}
int delete1()
{
	node *p;
	p=(node *)malloc(sizeof(node));
	if(start==NULL)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	p->data=start->data;
	start=start->next;
	return (p->data);
}


void main()
{
	int ch,ele;
	while(1)
	{
		printf("Enter choice 1.Insert 2.Delete 3.Display 4.Exit\n");
		scanf("%d",&ch);
        if(ch==4)
			break;
		switch(ch)
		{
			case 1:printf("Enter element to insert\n");
			       scanf("%d",&ele);
				   insert(ele);
				   display();
				   break;
			case 2:if(start==NULL)
			        { 
				          printf("Queue UNderflow\n");
				          break;
					}
			       ele=delete1();
				   printf("The deleted element : %d\n",ele);
				   display();
				   break;
		
			case 3:display();
		           break;
            default: printf("Enter a Valid Choice\n");				   
		}
	}
}
