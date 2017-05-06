#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Block{
	int id,size,flag;
	struct Block *next,*prev;
}Block;

Block *start=NULL;

Block *createTask(int id,int size,int flag){
	Block *new=(Block *)malloc(sizeof(Block));
	new->size=size;
	new->id=id;
	new->flag=flag;
	new->next=new->prev=NULL;
	return new;
}
Block *bestFit(int size){
	Block *traverse=start,*find=start;
	while(traverse!=NULL){
		if(traverse->size>=size && traverse->flag==0){
			if(traverse->size<=find->size)
				find=traverse;
		}
		traverse=traverse->next;
	}
	if(find->size<size)
		return NULL;
	return find;
}
Block *worstFit(int size){
	Block *traverse=start,*find=start;
	while(traverse!=NULL){
		if(traverse->size>=size && traverse->flag==0){
			if(find->size<=traverse->size)
				find=traverse;
		}
		traverse=traverse->next;
	}
	if(find->size<size)
		return NULL;
	return find;
}
Block *firstFit(int size){
	Block *traverse=start;
	while(traverse!=NULL){
		if(traverse->size>=size && traverse->flag==0)
			return traverse;
		traverse=traverse->next;
	}
	return NULL;
}
int insert(int id,int size,int ch){
	Block *new=createTask(id,size,1);
	Block *p=(ch==1)?bestFit(size):((ch==2)?worstFit(size):firstFit(size));
	Block *z;
	if(p==NULL)
		return 0;
	if(size==p->size){
		p->flag=1;
		p->id=id;
		free(new);
	}
	else{
		p->size-=size;
		new->next=p->next;
		p->next=new;
		new->prev=p;
		if(new->next!=NULL){
			z=new->next;
			z->prev=new;
		}
	}
	return 1;
}
int checkHoles(Block *p){
	Block *q=p->prev,*r=p->next;
	if(q==NULL && r==NULL)
		return 0;
	else if(q!=NULL && r!=NULL){
		if(!q->flag && !r->flag)
			return 2;
	}
	else if(q!=NULL)
		if(!q->flag)
			return -1;
	else if(r!=NULL)
		if(!r->flag)
			return 1;
	return 0;			
}
int delete(int id){
	Block *p=start,*q,*r,*temp;
	int s;
	while(p!=NULL){
		if(p->id==id)
			break;
		p=p->next;
	}
	if(p==NULL)
		return 0;
	p->id=0;
	p->flag=0;
	q=p->prev;
	r=p->next;
	s=checkHoles(p);
	if(s==2){
		p->size+=q->size+r->size;
		if(q==start)
			start=start->next;
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
		free(q),free(r);
	}
	else if(s==1){
		p->size+=r->size;
		p->next=r->next;
		if(r->next!=NULL){
			temp=r->next;
			temp->prev=p;
		}
		free(r);
	}
	else if(s==-1){
		p->size+=q->size;
		if(q==start)
			start=start->next;
		p->prev=q->prev;
		if(q->prev!=NULL){
			temp=q->prev;
			temp->next=p;
		}
		free(q);
	}
	return 1;
}
void display(){
	Block *q=start;
	while(q!=NULL){
		printf("%d:%d:%s --> ",q->id,q->size,(q->flag==0)?"Hole":"Task");
		q=q->next;
	}
	printf("END\n\n");
}
void main(){
	Block *new=createTask(0,100,0);
	start=new;
	int id,size,strategy,ch;
	while(1){
		printf("Your choice : 1.Insert 2.Delete 3.Quit  : ");
		scanf("%d",&ch);
		if(ch==3)
			break;
		switch(ch){
			case 1: printf("Enter Id and Size : ");
			       	scanf("%d %d",&id,&size);
					printf("1.Best 2.Worst 3.First : ");
					scanf("%d",&ch);
					switch(ch){
						case 1: if(!insert(id,size,1))
			       					printf("Not inserted.\n");
			       				break;	
			       		case 2: if(!insert(id,size,2))
			       					printf("Not inserted.\n");
			       				break;	
			       		case 3: if(!insert(id,size,3))
			       					printf("Not inserted.\n");
			       				break;
			       		default: printf("Enter correct value\n");							
					}
			       display();
			       break;
			case 2: printf("Enter Id : ");
					scanf("%d",&id);
					if(!delete(id))
						printf("Not Deleted\n");
					display();
					break;
			default: printf("Enter Correct Value\n");			
		}
	}
}