/*** 氏名(Name) Naoki Okuya
 *** 課題 4 問題 2 : This program is Tic-tac-toe.
 *** 提出日: 7月18日
 ***/

#include<stdio.h>
#include <string.h>

void grid(char grd[8][16]){
  int i,j;
  char num='1';
  
  strcpy(grd[0],"    1   2   3");
  
  for(i=1 ;i<=7 ;i++){
    if(i%2 == 1){
      for(j=0 ;j<15 ;j++){
	if(j<2)
	  grd[i][j]=' ';
	else
	  grd[i][j]='-';
      }
    }
    else{
      grd[i][0]=num;
      grd[i][1]=' ';
      for(j=2 ;j<15 ;j++){
	if((j-2)%4 == 0)
	  grd[i][j]='|';
	else
	  grd[i][j]=' ';
      }
      num++;
    }
  }
}

void plot_grid(char grd[8][16] ,int x ,int y ,int p){
  char mrk;
  
  mrk='X'-p*9;
  
  grd[x*2][y*4]=mrk;
}

int win_rose(char grd[8][16] ,int p){
  int i,j;
  int sum_x=0,sum_y=0;
  int sum_xy=0,sum_yx=0;
  char mrk;
  
  mrk='X'-p*9;
  
  for(i=1 ;i<=3 ;i++){
    for(j=1 ;j<=3 ;j++){
      if(grd[i*2][j*4] == mrk){
	sum_y++;
	if(sum_y == 3)
	  return 1;
      }
      if(grd[j*2][i*4] == mrk){
	sum_x++;
	if(sum_x == 3)
	  return 1;
      }
      if(i-j == 0){
	if(grd[i*2][j*4] == mrk){
	  sum_yx++;
	  if(sum_yx == 3)
	    return 1;
	}
      }
      if((i+j) == 4){
	if(grd[i*2][j*4] == mrk){
	  sum_xy++;
	  if(sum_xy == 3)
	    return 1;
	}
      }	    
    }
    sum_x=0;
    sum_y=0;
  }
  return 0;
}

int draw(int tmp[3][3]){
  int i,j;

  for(i=0 ;i<3 ;i++){
    for(j=0 ;j<3 ;j++){
      if(tmp[i][j] == 0)
	return 0;
    }
  }

  return 1;
}

int main(void){
  int i;
  int p=1;
  int x,y;
  int tmp[3][3]={};
  int drw;
  char num='1';
  char grd[8][16];
  
  grid(grd);
  
  do{
    p=(p+1)%2;
    printf("Player %d, enter row and column:",p+1);
    scanf("%d %d",&x,&y);
    
    while(x<1 || x>3 || y<1 || y>3 || tmp[x-1][y-1] == 1){
      printf("Player %d, enter row and column:",p+1);
      scanf("%d %d",&x,&y);
    }
    tmp[x-1][y-1]=1;
    
    plot_grid(grd,x,y,p);
    
    for(i=0 ;i<=7 ;i++)
      printf("%s\n",grd[i]);
    printf("\n");
    
    drw=draw(tmp);
    if(drw == 1)
      break;
    
  }while(win_rose(grd,p) != 1);
  
  if(drw == 0)
    printf("Player %d Win\n",p+1);
  else
    printf("Draw\n");
  
  return 0;
}
