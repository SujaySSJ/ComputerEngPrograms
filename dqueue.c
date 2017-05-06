#include<stdio.h>
#define max 7
int q[max],f=max/2,r=max/2;
void insertleft(int ele)
{
if(f==-1)
 {
 printf("Queue Overflow\n");
return;
}
q[f]=ele;
f--;
}

void insertright(int ele)
{
if(r==max-1)
{
printf("Queue Underflow\n");
return;
}
q[++r]=ele;
}


int isempty()
{
if(f==r)
 return 1;
else return 0;
}

int deleteright()
{
int z;
if(isempty())
  return -1;
else
 {
z=q[r--];
return z;
 }
}

int deleteleft()
{
if(isempty())
  return -1;
else
 {
f++;
return q[f];
 }
}

void display()
{
int i;
if(isempty())
{
printf("Queue Empty");
return;
}
for(i=f+1;i<=r;i++)
    printf("%d ",q[i]);
printf("\n");
}

void main()
{
int ele,ch;
while(1)
  {
printf("Enter the choice : 1:InsertRight 2:InsertLeft 3:DeleteRight 4:DeleteLeft 5:Display 6:Exit\n");
scanf("%d",&ch);
if(ch==6)
   break;
switch(ch)
	{
case 1: printf("Enter the element to insert from right\n");
        scanf("%d",&ele);
        insertright(ele);
        display();
        break; 
case 2: printf("Enter the element to insert from left\n");
        scanf("%d",&ele);
        insertleft(ele);
        display();
        break; 
case 3: if(isempty())
               printf("Queue UNderflow\n");
        else
         {
         ele=deleteright();
         printf("The deleted element from Right : %d\n",ele);
         display();
         }
         break;
case 4: if(isempty())
               printf("Queue UNderflow\n");
        else
         {
         ele=deleteleft();
         printf("The deleted element from Left : %d\n",ele);
         display();
         }
         break;
case 5: display();
        break;
default: printf("Enter a valid choice\n");
	}
  }
}















































