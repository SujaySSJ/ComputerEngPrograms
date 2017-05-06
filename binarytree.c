#include<stdio.h>
#include<stdlib.h>
 typedef struct node
 {
	 int data;
	 struct node *left,*right;
 }node;
 
 node *root=NULL;
 
node *father(node *p)
{
	node *q;
	if(p==root)
		return NULL;
	q=root;
	while(q!=NULL)
	{
		if(q->left==p||q->right==p)
			return q;
		if(p->data<=q->data)
			q=q->left;
		else q=q->right;
	}
	return NULL;
}

node *findmax(node *r)
{
	if(r->right==NULL)
		return r;
	else return(findmax(r->right));
}

int search(int ele)
{
	node *q=root;
    while(q!=NULL)
    {
		if(q->data==ele)
			return 1;
		if(ele<q->data)
			q=q->left;
		else q=q->right;
	}
return 0;	
}

void insertele(int ele)
{
	node *p,*q;
	p=(node *)malloc(sizeof(node));
	p->data=ele;
	p->left=p->right=NULL;
	if(root==NULL)
	{
		root=p;
		return;
	}
	q=root;
	while(q!=NULL)
	{
		if(ele<=q->data)
			if(q->left==NULL)
		    {
				q->left=p;
			    return;
			}
			else q=q->left;
		else
			if(q->right==NULL)
			{
				q->right=p;
				return;
			}
			else q=q->right;
	}
}
void delete1(int ele)
{
	node *q;
	if(root==NULL)
	{
		printf("Binary search tree empty\n");
		return;
	}
	q=root;
	while(q!=NULL)
	{
		if(q->data==ele)
			break;
		if(ele<q->data)
			q=q->left;
		else q=q->right;
	}
	if(q==NULL)
	{
		printf("%d not found",ele);
		return;
	}
	if(q->left==NULL&&q->right==NULL)
	{
		if(q==root)
		{
			root==NULL;
			return;
		}
		if(father(q)->left==q)
			father(q)->left=NULL;
		else father(q)->right=NULL;
		return;
	}
	if(q->left!=NULL)
	{
		int val;
		node *max=findmax(q->left);
		val=max->data;
		delete1(val);
		q->data=val;
		return;
	}
	if(q==root)
	{
		root=root->right;
		return;
	}
	if(father(q)->left==q)
		father(q)->left=q->right;
	else father(q)->right=q->right;
}
void inorder(node *x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		printf("%d ",x->data);
		inorder(x->right);
	}
}
void preorder(node *x)
{
	if(x!=NULL)
	{
		printf("%d ",x->data);
		preorder(x->left);
		preorder(x->right);
	}
}
void postorder(node *x)
{
	if(x!=NULL)
	{
		postorder(x->left);
		postorder(x->right);
		printf("%d ",x->data);
		
	}
}
void main()
{
	int ch,ele;
	while(1)
	{
		printf("\nEnter your choice 1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.PostOrder 7.Exit\n");
		scanf("%d",&ch);
		if(ch==7)
			break;
		switch(ch)
		{
		case 1: printf("Enter the element to insert\n");
		        scanf("%d",&ele);
				insertele(ele);
				break;
		case 2: printf("Enter the element to delete\n");
                scanf("%d",&ele);
                delete1(ele);
                break;
		case 3:	printf("Enter the element to search\n");
                scanf("%d",&ele);
                search(ele);
                break;	
		case 4: printf("Inorder Traversal\n");
               	inorder(root);
                break;	
		case 5: printf("Preorder Traversal\n");
               	preorder(root);
                break;	
        case 6: printf("Postorder Traversal\n");
               	postorder(root);
                break;	
		default:printf("Enter a valid choice\n");		
        }		
	}
}


