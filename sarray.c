void lcsum(int a[], int size){

    int start=0, end=0;
    int i;
    int curr_start =0;
    
    int maxSum =0;
    int currentSum =0;

    for(i =0 ;i<size; i++){
        currentSum  = currentSum + a[i];
        // case 1 : When ith element can be included
        // Change the end index and also update the start index.
        if(currentSum> maxSum){
            maxSum = currentSum;
            end = i;
            start = curr_start;
        }
        /*case 2 : When ith index cannot be included and 
        we need to start with i+1 index. till now our max sum
        and start and end index of that sum remain same */
        if(currentSum<0){
            curr_start = i+1;
            currentSum =0;
        }
    }
    printf("\nMaximum Sum : %d", maxSum);
    printf("\n Between (%d, %d)", start, end);
}

//Driver program
int main() {
   	int intArr[]={3, -1, -1, -1, -1, -1, 2, 0, 0, 0 };
   	//int[] intArr = {-1, 3, -5, 4, 6, -1, 2, -7, 13, -3};
   	//int[] intArr={-6,-2,-3,-4,-1,-5,-5};
   	int size = sizeof(intArr)/sizeof(intArr[0]);
    lcsum(intArr, size);
 
    return 0;
}