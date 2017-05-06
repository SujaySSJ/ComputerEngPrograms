#include<stdio.h>
#include<time.h>

clock_t start,end;
void test(){
long int j=0;
if(j!=100){
	j++;
	test();
	}	
}
void main()
{
	int i=0;
start=clock();
for(i=0;i<1000;i++){
test();
}
end=clock();
double timepassed=((double)(end-start))/CLK_TCK;
printf("%f",timepassed);	
}