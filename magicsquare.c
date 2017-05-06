 #include<stdio.h>
 void magicsquareodd(int x[][10],int n)
 {
 int i,r=0,c=n/2,rtemp,ctemp;
 x[0][c]=1;
 for(i=2;i<=n*n;i++)
     {
     rtemp=r;
     ctemp=c;
     r==0?r=n-1:--r;
     c==n-1?c=0:++c;
     if(x[r][c]==0)
            x[r][c]=i;
      else {
      x[++rtemp][ctemp]=i;
      r=rtemp;
      c=ctemp;
      }  
     }
 }
 void display(int x[][10],int n)
 {
 int i,j;
 for(i=0;i<n;i++){
     for(j=0;j<n;j++)
       
       printf("%3d ",x[i][j]);
       
       printf("\n");
   }      
 }
 void main()
 {
 int x[10][10]={0},n;
 printf("Enter the order of the matrix\n");
 scanf("%d",&n);
 if(n%2){
     magicsquareodd(x,n);
     display(x,n);
     }
 else printf("order must be odd");    
 }
