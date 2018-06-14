/*** 氏名(Name) 奥屋 直己
 *** 課題 3 問題 1 : ヘロンの公式で三角形の面積を求める関数を作成し、面積を求めるプログラム
 *** 提出日: 6月14日
 ***/
#include<stdio.h>
#include<math.h>

double Heron(double a,double b,double c){ //ヘロンの公式の関数
  double S;
  double s;
  
  if(a<=0 || b<=0 || c<=0) //三角形の各辺が0以下の時、-1を返す
    return -1;
  
  s=(a+b+c)/2.0; //ヘロンの公式
  S=sqrt(s*(s-a)*(s-b)*(s-c));
  return S;
}

int main(void){
  double a,b,c;
  double S;
  
  printf("a = ");scanf("%lf",&a); //三角形の各辺をそれぞれa,b,cに代入
  printf("b = ");scanf("%lf",&b);
  printf("c = ");scanf("%lf",&c);
  
  S=Heron(a,b,c); //ヘロンの公式の関数へ各辺の値を渡す
  if(S==-1){ //関数が-1を返した時、エラーを表示
    printf("\n");
    printf("エラー\n");
  }
  else{
    printf("\n");
    printf("三角形の面積Sは%5.1fです。\n",S);
  }
  
  return 0;
}
