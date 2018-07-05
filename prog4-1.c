#include<stdio.h>
#include<stdlib.h>

#define N 10

double median(int *dat ,int i){ //中央値を求める関数medianをdouble型で定義。引数として配列datをポインタで受け取り、データ個数をiで受け取る。
  
  
  

int main(int argc ,char *argv[]){
  int i;
  int dat[N]; //データを代入する配列datをint型で定義
  
  for(i=0 ;i<argc-1 ;i++){ //引数argvから得たchar型の文字をatoi関数でint型に変換しながら配列datに代入。これを引数の個数argcからプログラム名分引いた回数繰り返す
    dat[i] = atoi(argv[i+1]); 
  }
  
  return 0;
}
