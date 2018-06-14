#include<stdio.h>
#define N 100
int main(void){
  int n=0;
  int i,j,k=1;
  double x[N];
  double temp;
  
  printf("When you want to finish, please enter Ctrl+d\n");
  
  printf("(%d) : ",n+1);
  while(scanf("%lf",&x[n])!=EOF && n<N-1){
     n++;
     printf("(%d) : ",n+1);
  }
  printf("\n\n");
  
  printf("Before :");
  for(i=0;i<n;i++){
    printf("%6.1f ",x[i]);
  }
  printf("\n");
    
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i+1;j++){
      if(x[j]>x[j+1]){
	temp=x[j];
	x[j]=x[j+1];
	x[j+1]=temp;
      }
    }
  }
  
  printf(" After :");
  for(i=0;i<n;i++){
    printf("%6.1f ",x[i]);
  }
  
  printf("\n");
  
  return 0;
 }
