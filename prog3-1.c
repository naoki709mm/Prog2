#include<stdio.h>
#include<math.h>

double Heron(double a,double b,double c){
  double S;
  double s;
  
  if(a<=0 || b<=0 || c <=0)
    return -1;
  s=(a+b+c)/2.0;
  S=sqrt(s*(s-a)*(s-b)*(s-c));
  
  return S;
}

int main(void){
  double a,b,c;
  double S;
  
  printf("a = ");scanf("%lf",&a);
  printf("b = ");scanf("%lf",&b);
  printf("c = ");scanf("%lf",&c);

  S=Heron(a,b,c);
  if(S==-1){
    printf("\n");
    printf("エラー\n");
  }
  else{
    printf("\n");
    printf("三角形の面積Sは%5.1fです。\n",S);
  }
    
  return 0;
}
