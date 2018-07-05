/*** 氏名(Name) 奥屋 直己
 *** 課題 4 問題 1 : 任意の個数のデータに対して、その中央値を求める関数を作成し、中央値を求めるプログラム。
 *** 提出日: 7月5日
 ***/

#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *dat ,int num){ //バブルソートの関数。引数としてdatのポインタと配列の個数numをそれぞれint型で定義する。
  int i,j; 
  int tmp;
  int sum=0;
  
  for(i=0 ;i<num-1 ;i++){
    for(j=num-1 ;j>i ;j--){
      if(dat[j-1] > dat[j]){
	tmp=dat[j-1];
	dat[j-1]=dat[j];
	dat[j]=tmp;
	sum++;
      }
    }
    if(sum == 0)
      break;
    sum=0;
  }
}

double median(int *dat ,int num){ //中央値を求める関数medianをdouble型で定義。引数として配列datをポインタで受け取り、データ個数をnumをint型で受け取る。
  int num_h;
  double med;
  
  bubblesort(dat ,num);
  
  num_h=num/2;
  
  if(num%2 != 0)
    med=dat[num_h+1];
  else
    med=(dat[num_h-1]+dat[num_h])/2.0;

  return med;
}

int main(int argc ,char *argv[]){
  int i;
  int num;
  int dat[argc-1]; //データを代入する配列datをint型で定義
  double med;
    
  num=argc-1; //引数の個数argcからプログラム名分引いたデータのみの個数を変数numに代入
  
  for(i=0 ;i<num ;i++){ //引数argvから得たchar型の文字をatoi関数でint型に変換しながら配列datに代入。
    dat[i] = atoi(argv[i+1]); 
  }
  
  med=median(dat ,num);
  
  printf("median = %3.1f\n",med);
  
  return 0;
}
