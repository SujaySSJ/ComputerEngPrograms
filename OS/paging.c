#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	int pageno,present;
}Page;
int *frame;
void initalise(Page *pagetable,int pages){
	int i=0;
	while(i<pages){
		pagetable[i].pageno=i;
		pagetable[i++].present=0;
	}
}
void loadPages(Page *pagetable,int pages,int frames){
	int i;
	for(i=0;i<frames;i++){
		frame[i]=pagetable[i].pageno;
		pagetable[i].present=1;
	}
}
void displayFrame(int frames){
	int i;
	for(i=0;i<frames;i++){
		printf("Frame:%d -> Page:%d\n",i,frame[i]);
	}
	printf("\n");
}
int getFrame(int pno,int frames){
	int i;
	for(i=0;i<frames;i++)
		if(frame[i]==pno)
			return i;
	return 0;	
}
void main(){
	int i,pages,frames,vrsize,phsize,pagesize;
	Page *pagetable;
	int laddress,offset,pno;
	printf("Enter the size of Physical Memory and Virtual Memory(in KB)");
	scanf("%d %d",&phsize,&vrsize);
	printf("Enter the page size : ");
	scanf("%d",&pagesize);
	pages=ceil((float)vrsize/pagesize);
	frames=ceil((float)phsize/pagesize);
	pagetable=(Page *)malloc(sizeof(Page)*pages);
	frame=(int *)malloc(sizeof(int));
	initalise(pagetable,pages);
	loadPages(pagetable,pages,frames);
	displayFrame(frames);
	printf("Enter the logical address\n");
	scanf("%d",&laddress);
	pno=laddress/(pagesize*1024);
	offset=laddress%(pagesize*1024);
	i=getFrame(pno,frames);
	if(i){
		printf("Frame : %d , Offset : %d\n",i,offset);
		printf("Physical Address : %d\n",i*pagesize*1024+offset);
	}
	else{
		printf("Page not available\n");
	}


}