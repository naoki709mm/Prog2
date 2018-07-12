/*** 氏名(Name) 奥屋 直己
 *** 課題 4 問題 1 : 任意の個数のデータに対して、その中央値を求める関数を作成し、中央値を求めるプログラム。
 *** 提出日: 7月12日
 ***/

#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *dat ,int num){ //バブルソートの関数。引数としてdatのポインタと配列の個数numをそれぞれint型で定義する。
  int i,j; 
  int tmp;
  int cnt;
  int sum=0;

  cnt=num-1; //配列の個数numを配列の要素数に合わせるために-1をし、変数cntに代入

  //バブルソートのメインループ文
  for(i=0 ;i<cnt ;i++){ //全体のループ回数を指定する。ここでは最大で配列の個数分ループする
    for(j=cnt ;j>i ;j--){ //配列datの後ろから走査を行う。
      if(dat[j-1] > dat[j]){ //要素数jのときの配列の値dat[j]よりも1つ前の配列の値dat[j-1]が大きい時、それぞれの値を入れ替える。
	tmp=dat[j-1];
	dat[j-1]=dat[j];
	dat[j]=tmp;
	sum++; //１回の走査で数値を入れ替えた回数を変数sumに代入する。
      }
    }
    if(sum == 0) //１回の走査で数値を入れ替えた回数sumが0だった場合、ソートは完了したとして、breakでループ文から抜ける。
      break;
    sum=0; //１回の走査が終わると入れ替えた回数sumを0で初期化を行う
  }
}

double median(int *dat ,int num){ //中央値を求める関数medianをdouble型で定義。引数として配列datをポインタで受け取り、データ個数をnumをint型で受け取る。
  int num_h;
  double med;
  int i;
  
  bubblesort(dat ,num); //配列datをバブルソートする。

  num_h=(num/2); //中央値の要素数num_hを求める。num_hはint型であるため、小数点以下は切り捨てられ、ちょうど数値の個数が奇数の時の中央値の要素数となる。
  
  if(num%2 != 0) //データの個数が奇数だった場合、配列の中央値がある要素数num_hのときの値dat[num_h]を変数medに代入する。
    med=dat[num_h];
  else //データの個数が偶数だった場合、中央値は真ん中の2つの値の平均とする。中央値の要素数num_hは真ん中２つの値の大きい方となるため、配列の値dat[num_h]とdat[num_h-1]の平均となる。
    med=(dat[num_h]+dat[num_h-1])/2.0;

  return med;
}

int main(int argc ,char *argv[]){
  int i;
  int num;
  int dat[argc-1]; //データを代入する配列datをint型で定義
  double med;
  
  num=argc-1; //引数の個数argcからプログラム名分引いたデータのみの個数を変数numに代入

  if(num == 0) //引数が与えられなかった場合、以下を表示し、プログラムを終了する
    printf("数値を入力してください\n");

  else{
    for(i=0 ;i<num ;i++){ //引数argvから得たchar型の文字をatoi関数でint型に変換しながら配列datに代入。
      dat[i] = atoi(argv[i+1]); 
    }

    med=median(dat ,num); //変数medにmedian関数でもとめた中央値を代入する。
    
    printf("median = %3.1f\n",med);
  }
  
  return 0;
}
