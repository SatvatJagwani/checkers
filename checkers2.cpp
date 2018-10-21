/*Checkers CS101 Project;
Created by JANAK AGRAWAL(150050047;CSE) && SATVAT JAGWANI(150050053;CSE)*/

#include "checkers.h"

//Creates the checkers board
void board(){
		Rectangle r[8][8];
		for(int j=0;j<8;j++){
			for(int i=0;i<8;i++){
				r[i][j].reset(100*(i+1),100*(j+1),100,100);
			}
		}
		for(int j=0;j<8;j=j+2){
			r[j][0].setFill(1);
			r[j][2].setFill(1);
			r[j][4].setFill(1);
			r[j][6].setFill(1);
		}

		for(int j=1;j<8;j=j+2){
			r[j][1].setFill(1);
			r[j][3].setFill(1);
			r[j][5].setFill(1);
			r[j][7].setFill(1);
		}
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				r[i][j].imprint();
			}
		}
		}



//Checks whether the someone has won or not.Returns 0(nobody won), 1(user won) & 2(com won).
int win(player &user,player &com){
int i,n1;
bool com1=true;
for(i=0;i<12;i++){
int x,y,n1;
x=com.c[i].getX()/100;
y=com.c[i].getY()/100;

if(com.checkpeg(x-2,y-2,user,n1)==0&&com.checkpeg(x-1,y-1,user,n1)==2){com1=false;break;}
else if(com.checkpeg(x+2,y-2,user,n1)==0&&com.checkpeg(x+1,y-1,user,n1)==2){com1=false;break;}
}
if(com1){
for(i=0;i<12;i++){
int x,y;

x=com.c[i].getX()/100;
y=com.c[i].getY()/100;

if(com.checkpeg(x-1,y-1,user,n1)==0){com1=false;break;}
else if(com.checkpeg(x+1,y-1,user,n1)==0){com1=false;break;}
}
if(com1)return 1;
}
com1=true;
for(i=0;i<12;i++){
int x,y,n1;
x=user.c[i].getX()/100;
y=user.c[i].getY()/100;

if(user.checkpeg(x-2,y+2,com,n1)==0&&user.checkpeg(x-1,y+1,com,n1)==2){com1=false;break;}
else if(user.checkpeg(x+2,y+2,com,n1)==0&&user.checkpeg(x+1,y+1,com,n1)==2){com1=false;break;}
}
if(com1){
for(i=0;i<12;i++){
int x,y;

x=user.c[i].getX()/100;
y=user.c[i].getY()/100;

if(user.checkpeg(x-1,y+1,com,n1)==0){com1=false;break;}
else if(user.checkpeg(x+1,y+1,com,n1)==0){com1=false;break;}
}
if(com1)return 2;
}
n1=0;
for(i=0;i<12;i++)
{
if(com.c[i].getY()==100)n1++;
}
if(n1>=3)return 2;
n1=0;
for(i=0;i<12;i++)
{
if(user.c[i].getY()==800)n1++;
}
if(n1>=3)return 1;

return 0;
}





//Main Program
main_program{
initCanvas("checkers",1000,1000);
board();
player user(1), com(2);
while(1){
user.move(com);
wait(1);
if(com.move2(user)||win(user,com)==1){cout<<"Game Over; User wins;"<<endl;break;}
if(win(user,com)==2){cout<<"Game Over;Com wins;"<<endl;break;}

}

getClick();}

