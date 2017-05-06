#include<stdio.h>

typedef struct Block{
	int id,no;
}Block;

typedef struct Directory{
	int id,start,no;
}Directory;

Directory dir[20];
int r=0;

void makeDirectoryEntry(int id,int start,int no){
	dir[r].id=id;
	dir[r].no=no;
	dir[r++].start=start;
}

int areBlocksAvailable(Block block[],int n){
	int i,c=0;
	for(i=0;i<100;i++){
		if(!block[i].id)
			c++;
		else c=0;
		if(c==n)
			return i-n+1;
	}
	printf("break\n");
	return -1;
}

void allocate(Block block[],int id, int n,int start){
	int i;
	for(i=start;i<n;i++){
		block[i].id=id;
	}
	makeDirectoryEntry(id,start,n);
}
void displayFile(Block block[],int id){
	int i,j;
	Directory file;
	for(i=0;i<r;i++){
		if(dir[i].id==id){
			file=dir[i];
		}
	}
	printf("File id : %d\n",file.no);
	printf("Starting Block : %d\nFinal Block : %d\n",file.start,file.start+file.no-1);
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
		allocate(block,id,n,start);
		printf("Space allocated to FILE:%d\n",id);
		displayFile(block,id);
	}
	else {
		printf("Space not available\n");
	}

}