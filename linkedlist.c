#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int data;
	struct node *next;
}node;

node *start=NULL;
void insertbeg(int ele)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=ele;
	p->next=start;
	start=p;
}

void insertend(int ele)
{
	node *p,*q;
	p=(node *)malloc(sizeof(node));
	p->data=ele;
	p->next=NULL;
	if(start==NULL)
		start=p;
	else{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
}

void display()
{
	node *q;
	if(start==NULL){
		printf("Linked List Empty\n");
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

int count()
{
	int c=0;
	node *q=start;
	while(q!=NULL)
	{
		c++;
		q=q->next;
	}
	return c;
}

int search(int ele)
{
	node *q=start;
	while(q!=NULL)
	{
		if(q->data==ele)
			return 1;
		else q=q->next;
	}
	return 0;
}

int deletepos(int pos)
{
	int i;
	node *p,*q=start;
	for(i=0;i<pos-2;i++)
		q=q->next;
	p=q->next;
	q->next=p->next;
	return (p->data);
}

void deleteele(int ele)
{
	node *q,*z;
	if(start==NULL)
	{
		printf("Linked LIst Empty\n");
		return;
	}
	if(start->data==ele)
	{
		start=start->next;
		return;
	}
	q=start;
	while(q->next!=NULL)
	{
		z=q->next;
		if(z->data==ele)
			break;
		else q=q->next;
	}
	if(q->next==NULL)
		printf("%d is not found\n",ele);
	else {
		z=q->next;
		q->next=z->next;
		}
}

void main()
{
	int ch,ele,pos;
	while(1)
	{
		printf("Enter choice 1.Insert Begining 2.Insert End 3.Delete Element At position 4.Delete Element 5.Search 6.No. of elements 7.Display 8.Exit\n");
		scanf("%d",&ch);
        if(ch==8)
			break;
		switch(ch)
		{
			case 1:printf("Enter element to insert at begining\n");
			       scanf("%d",&ele);
				   insertbeg(ele);
				   display();
				   break;
			case 2:printf("Enter element to insert at end\n");
			       scanf("%d",&ele);
				   insertend(ele);
				   display();
				   break;	
			case 3:printf("Enter the position to delete element at\n");
		           scanf("%d",&pos);
				   printf("The deleted element %d\n",deletepos(pos));
				   display();
				   break;
			case 4:printf("Enter the element to delete\n");
		           scanf("%d",&ele);
				   deleteele(ele);
				   display();
				   break;	   
			case 5:printf("Enter the element to search\n");
			       scanf("%d",&ele);
				   if(search(ele))
					   printf("%d Found\n",ele);
				   else printf("%d Not Found\n",ele);
				   break;
			case 6:printf("The Number of Elemnts = %d \n",count());
			       break;
			case 7:display();
		           break;
            default: printf("Enter a Valid Choice\n");				   
		}
	}
}








if(q!=NULL && r!=NULL){
		if(q->flag && r->flag)
			return 1;
		if(q->flag && r->flag){
			p->size+=q->size+r->size;
			p->next=r->next;
			p->prev=q->prev;
			if(r->next!=NULL){
				temp=r->next;
				temp->prev=p;
			}
			if(q->prev!=NULL){
				temp=q->prev;
				temp->next=p;
			}
			free(q);
			free(r);
		}
	}
	else if(q!=NULL){
		if(q->flag && r!=NULL){
			if(r->flag){
				p->size+=r->size;
				p->next=r->next;
				if(r->next!=NULL){
					temp=r->next;
					temp->prev=p;
				}
				free(r);
				return 1;
			}
		}
	}
	else if(r!=NULL){
		if(r->flag && q!=NULL){
			if(q->flag){
				p->size+=q->size;
				p->prev=q->prev;
				if(q->prev!=NULL){
					temp=q->prev;
					temp->next=p;
				}
				free(q);
				return 1;
			}
		}
	}
	