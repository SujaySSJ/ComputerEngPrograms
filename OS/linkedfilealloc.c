#include <stdio.h>

typedef struct Block{
	int id,no;
	struct Block *next;
}Block;

typedef struct Directory{
	int id,no;
	Block *start;
}Directory;

Directory dir[20];
int r=0;

int areBlocksAvailable(Block block[],int n){
	int i,c=0;
	for(i=0;i<100;i++){
		if(block[i].id==0)
			c++;
		if(c==n)
			return 1;
	}
	return 0;
}

Block *getNextBlock(Block block[]){
	int i;
	for(i=0;i<100;i++){
		if(block[i].id==0)
			return &block[i];
	}
	return NULL;
}

void makeDirectoryEntry(int id,int n,Block *b){
	dir[r].id=id;
	dir[r].no=n;
	dir[r++].start=b;
}

void allocate(Block block[],int id,int n){
	int i;
	Block *b[20];
	for(i=0;i<n;i++)
		b[i]=getNextBlock(block);
	for(i=0;i<n-1;i++)
		b[i]->next=b[i+1];
	makeDirectoryEntry(id,n,b[0]);
}

void main(){
	int n,id,start,i;
	Block block[100];
	for(i=0;i<100;i++){
		block[i].no=i;
		block[i].id=0;
	}

	printf("Enter the file id\n");
	scanf("%d",&id);
	printf("Enter the no. of blocks required\n");
	scanf("%d",&n);
	start=areBlocksAvailable(block,n);
	if(start!=-1){
		allocate(block,id,n);
		printf("Space allocated to FILE:%d\n",id);
		displayFile(block,id);
	}
	else {
		printf("Space not available\n");
	}

}