/*** 氏名(Name) 奥屋 直己
 *** 課題 3 問題 1 : ヘロンの公式で三角形の面積を求める関数を作成し、面積を求めるプログラム
 *** 提出日: 6月14日
 *** 再提出日: 6月14日]
 *** 再々提出日: 6月21日
 ***/
#include<stdio.h>
#include<math.h>

double Heron(double a,double b,double c){ //ヘロンの公式の関数
  double s_l;
  double s;
  double temp;
  
  if(a<=0 || b<=0 || c<=0)//各辺が0以下の時、-1を返す
    s_l=-1;
  else{
    s=(a+b+c)/2.0; //ヘロンの公式
    temp=s*(s-a)*(s-b)*(s-c); //ルートの中身だけ計算
    if(temp<=0) //ルートの中身tempが0以下のとき、-1を返す
      s_l=-1;
    else
      s_l=sqrt(temp);
  }
  return s_l;
}

int main(void){
  double a,b,c;
  double s_l;
  
  printf("a = ");scanf("%lf",&a); //三角形の各辺をそれぞれa,b,cに代入
  printf("b = ");scanf("%lf",&b);
  printf("c = ");scanf("%lf",&c);
  
  s_l=Heron(a,b,c); //ヘロンの公式の関数へ各辺の値を渡す
  printf("\n");
  if(s_l==-1) //関数が-1を返した時、三角形でないとする。
    printf("三角形ではありません\n");
  else
    printf("三角形の面積Sは%5.1fです。\n",s_l);
  
  return 0;
}
