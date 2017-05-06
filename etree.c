
#include<stdio.h>
#include<string.h>

typedef struct node
{
  char data;
  struct node *left,*right;
}node;

node *root=NULL;

node*s[50];
int tos=-1;

void push(node *ele)
{
 s[++tos]=ele;
}

node* pop()
{
  tos--;
  return (s[tos+1]);
}

int isoperand(char ch)
{
 return (ch>='A'&&ch<='Z' || ch>='a'&&ch<='z');
}

void maketree(char post[])
{
  int i,l=strlen(post);
  node *p;
  for (i=0; i<l; i++)
  {
    if(isoperand(post[i]))
    {
      p=(node*)malloc(sizeof(node));
      p->data=post[i];
      p->left=p->right=NULL;
      push(p);
    }
    else
    {
      p=(node*)malloc(sizeof(node));
      p->data=post[i];
      p->right=pop();
      p->left=pop();
      push(p);
    }
  }
  root=pop();
 }

void inorder(node *x)
{
  if (x!=NULL)
  {
     inorder(x->left);
     printf("%c ",x->data);
     inorder(x->right);
  }
}

void preorder(node *x)
{
  if (x!=NULL)
  {
     printf("%c ",x->data);
     preorder(x->left);
     preorder(x->right);
  }
}

void postorder(node *x)
{
  if (x!=NULL)
  {
     postorder(x->left);
     postorder(x->right);
     printf("%c ",x->data);
  }
}

void main()
{
  int i,l;
  node *p;
  int ch,ele;
  char postfix[50];
  printf("Enter postfix expression\n");
  gets(postfix);
  l=strlen(postfix);
  for (i=0; i<l; i++)
  {
    if(isoperand(postfix[i]))
    {
      p=(node*)malloc(sizeof(node));
      p->data=postfix[i];
      p->left=p->right=NULL;
      push(p);
    }
    else
    {
      p=(node*)malloc(sizeof(node));
      p->data=postfix[i];
      p->right=pop();
      p->left=pop();
      push(p);
    }
  }
  root=pop();
 // maketree(postfix);
  while(1)
  {   
    printf("\n\nEnter choice 1: Inorder 2:Preorder 3: Postorder 4:Exit\n");
    scanf("%d",&ch);
    if(ch==4)
       break;
    switch(ch)
    {
	case 1: inorder(root);
		break;
	case 2: preorder(root);
		break;
	case 3: postorder(root);
		break;

	default: printf("Invalid choice\n");
    }
  }
}		

 
