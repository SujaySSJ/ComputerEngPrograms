#include<stdio.h>
#include<string.h>
 int main(int argc, char const *argv[])
{
  char x[20],y[20],d[20][20],lcs[20];
  int n,m,l[20][20]={0},index,i,j; 
  printf("Enter first string\n");
  gets(x);
  n=strlen(x);
  printf("Enter the second string\n");
  gets(y);
  m=strlen(y);
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(x[i]==y[j]){
        l[i+1][j+1]=l[i][j]+1;
        d[i][j]='d';
      }
      else if(l[i][j+1]>l[i+1][j]){
        l[i+1][j+1]=l[i][j+1];
        d[i][j]='u';
      }
      else {
        l[i+1][j+1]=l[i+1][j];
        d[i][j]='l';
      }
 i=n,j=m;
 index=l[n][m];
 lcs[index]='\0';
 while(j>0&&i>0){
  if(x[i-1]==y[j-1]){
    lcs[index-1]=x[i-1];
    i--;j--;index--;
  }
  else if(l[i-1][j]>l[i][j-1])
    i--;
  else j--;
 }     
 printf("\n");
 puts(lcs);
 for(i=1;i<=n;i++){

  for(j=1;j<=m;j++)
    printf("%d ",l[i][j]);
  printf("\n");
}
for(i=0;i<n;i++){

  for(j=0;j<m;j++)
    printf("%c ",d[i][j]);
  printf("\n");
}
  return 0;
}