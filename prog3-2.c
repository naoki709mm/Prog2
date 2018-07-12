/*** 氏名(Name) Naoki Okuya
 *** 課題 3 問題 2 : lychrel number
 *** 提出日: 6月21日
 ***/
#include<stdio.h>
#define N 200
long int reverse(long num){
  long int rev=0;
  while(num>0){
    rev=rev*10+num%10;
    num/=10;
  }
  return rev;
}

int lychrel(long num){
  int i;
  long rev;
  for(i=0;i<200;i++){
    rev=reverse(num);
    printf("%ld %ld¥n",num,rev);
    if(rev==num)
      return -1;
    num+=rev;
  }
  return 1;
}

int main(void){
  int low,up;
  int lyc;
  int sum[N];
  int i,j=0;

  printf("Lower:");scanf("%d",&low);
  printf("upper:");scanf("%d",&up);

  for(i=low;i<up;i++){
    lyc=lychrel(i);
    if(lyc==1){
      sum[j]=i;
      j++;
    }
  }
  printf("Lychel Number\n");
  for(i=0;i<j;i++)
    printf("%4d\n",sum[i]);

  return 0;
}
