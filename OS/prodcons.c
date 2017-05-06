#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define capacity 10
int queue[capacity];
int pid=0,buffer=0,i;
pthread_cond_t empty=PTHREAD_COND_INITIALIZER; 
pthread_cond_t full=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void *Producer(){
	while(1){
		pthread_mutex_lock(&mutex);
		if(buffer==capacity){
			printf("\nQueue full,Producer waiting......\n");
			for(i=0;i<capacity;i++)
				printf("%d ",queue[i]);
			printf("\n");
			printf("Elements Present=%d\n",buffer);
			pthread_cond_wait(&empty,&mutex);
		}
		while(queue[i=rand()%10]!=0);
		queue[i]=++pid%1000;
		buffer++;
		printf("P:%d ",queue[i]);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&full);
		//sleep(0.5);
	}
}
void *Consumer(){
	while(1){
		pthread_mutex_lock(&mutex);
		if(buffer==0){
			printf("\nQueue Empty,Consumer waiting......\n");
			for(i=0;i<capacity;i++)
				printf("%d ",queue[i]);
			printf("\n");
			printf("Elements Present=%d\n",buffer);
			pthread_cond_wait(&full,&mutex);
		}

		while(queue[i=rand()%10]==0);
		printf("C:%d ",queue[i]);
		queue[i]=0;
		buffer--;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&empty);
		//sleep(1);
	}
}

void main(){
	pthread_t prod,cons;
  	pthread_create(&prod,NULL,Producer,NULL);
    pthread_create(&cons,NULL,Consumer,NULL);
    pthread_join(prod,NULL);
   	pthread_join(cons,NULL);
        
}
