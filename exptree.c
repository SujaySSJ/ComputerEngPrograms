#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct node
{
	char data;
	struct node *left,*right;
}node;
node *root=NULL;
node *s[100];
int tos=-1;
void push(node *p)
{
	s[++tos]=p;
}
node *pop()
{
	return s[tos--];
}
void inorder(node *x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		printf("%c ",x->data);
		inorder(x->right);
	}
}
void preorder(node *x)
{
	if(x!=NULL)
	{
		printf("%c ",x->data);
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
		printf("%c ",x->data);
		
	}
}

void main()
{
	char postfix[100],c;
	int i;
	node *p;
	printf("Enter the postfix expression\n");
	gets(postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		if(isalpha(postfix[i]))
		{
			p=(node *)malloc(sizeof(node));
			p->data=postfix[i];
			p->left=NULL;
			p->right=NULL;
			push(p);
		}
		else
		{
			p=(node *)malloc(sizeof(node));
			p->data=postfix[i]; 
			p->right=pop();
			p->left=pop();
		    push(p);
		}
	}
	root=pop();
	printf("\nPostorder Expression : ");
	postorder(root);
	printf("\nInorder Expression : ");
    inorder(root);
	printf("\nPreorder Expression : ");
	preorder(root);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
