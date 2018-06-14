/*** 氏名(Name)　奥屋 直己
 *** 課題 2 問題 3 : (問題の概要1行程度「行列とベクトルの積を求めるプログラム」など)
 *** 提出日: 6月7日
 ***/

#include<stdio.h>
#define L 100 
#define M 100
#define N 100
int main(void){
  int l,m,n;
  int i,j,k;
  double a[L][M];
  double b[M][N];
  double x[L][N]={};
  
  printf("l : ");scanf("%d",&l);
  printf("m : ");scanf("%d",&m);
  printf("n : ");scanf("%d",&n);
  
  printf("行列の要素を空白区切りで入力してください\n");
  printf("A = ");
  for(i=0;i<l;i++){
    if(i>0)
      printf("    "); //入力の列を揃えるために"A = "と同じサイズの空白を２回目以降表示させる
    for(j=0;j<m;j++){
      scanf("%lf",&a[i][j]);//入力された行列の列を空白区切りで配列aに入力し、改行で次の行の入力へ移行する。
    }
  }
  
  printf("\n");
  printf("B = "); 
  for(i=0;i<m;i++){
    if(i>0)
      printf("    ");
    for(j=0;j<n;j++){
      scanf("%lf",&b[i][j]);
    }
  }
  
  //xの計算
  for(i=0;i<l;i++){ //計算結果の行列Xはl×nの行列となるためループ回数i,jをそれぞれl,nとする
    for(j=0;j<n;j++){
      for(k=0;k<m;k++){ //行列Xの1要素あたりの計算回数は行列Aの列mと同じとなるためループ回数kをmとする。
	x[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  
  printf("\nX = ");
  for(i=0;i<l;i++){
    if(i>0)
      printf("    ");
    for(j=0;j<n;j++){
      printf("%4.1f ",x[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
