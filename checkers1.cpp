/*Checkers CS101 Project;
Created by JANAK AGRAWAL(150050047;CSE) && SATVAT JAGWANI(150050053;CSE)*/

#include "checkers.h"

//Constructor
player::player(int n){
if(n==1){
for(int i=0;i<8;i=i+2){
				c[i/2].reset(100*(i+1),100,30);
				c[i/2].setColor(COLOR(220,220,220));
				c[i/2].setFill(1);
				c[i/2+4].reset(100*(i+2),200,30);
				c[i/2+4].setColor(COLOR(220,220,220));
				c[i/2+4].setFill(1);
				c[i/2+8].reset(100*(i+1),300,30);
				c[i/2+8].setColor(COLOR(220,220,220));
				c[i/2+8].setFill(1);
				}
}

else{
for(int i=0;i<8;i=i+2){
				c[i/2].reset(100*(i+2),600,30);
				c[i/2].setColor(COLOR(70,70,70));
				c[i/2].setFill(1);
				c[i/2+4].reset(100*(i+1),700,30);
				c[i/2+4].setColor(COLOR(70,70,70));
				c[i/2+4].setFill(1);
				c[i/2+8].reset(100*(i+2),800,30);
				c[i/2+8].setColor(COLOR(70,70,70));
				c[i/2+8].setFill(1);

}}}


//Checks for a peg at (x,y); Returns 0(no peg),1 (reciever peg) & 2(user2 peg). 
int player::checkpeg(int x, int y, player const & user2, int &n)
{
	if(x<1||x>8||y<1||y>8)return -1;
	int i;
	for(i=0;i<12;i++)
	{
		if(100*x==c[i].getX()&&100*y==c[i].getY()){n=i;return 1;}
	}
	for(i=0;i<12;i++)
	{
		if(100*x==user2.c[i].getX()&&100*y==user2.c[i].getY()){n=i;return 2;}
	}

	return 0;
}





//Allows the user to select the peg. Also highlights the peg.
int player::select_peg(){
int z,x,y;
while(1){
		z=getClick();
		x=z/65536;
		y=z%65536;
		if(x<50||x>850){
			cout<<"Invalid click; Click inside the board"<<endl;
			continue;}
		else x=(x+50)/100;
		if(y<50||y>850){
			cout<<"Invalid click; Click inside the board"<<endl;
			continue;}
		else y=(y+50)/100;
		break;}


int i;
			for(i=0;i<12;i++)
			{
				if(100*x==c[i].getX()&&100*y==c[i].getY())break;
			}
			if(i==12){cout<<"click on your peg"<<endl;return select_peg();}
c[i].setColor(COLOR(255,220,220));
return i;

}


//Deselcts the peg. Also unhighlight the peg.
void player::deselect_peg(int i){
c[i].setColor(COLOR(220,220,220));
}


//Check kill condition for user.
void player::kill(int x1, int y1, int n,player &com)
{

int z,x,y,n1;
if((checkpeg(x1+1,y1+1,com,n1)==2&&checkpeg(x1+2,y1+2,com,n1)==0)||(checkpeg(x1-1,y1+1,com,n1)==2&&checkpeg(x1-2,y1+2,com,n1)==0)){

while(1){
		z=getClick();
		x=z/65536;
		y=z%65536;
		if(x<50||x>850){
			cout<<"Invalid click; Click inside the board"<<endl;
			continue;}
		else x=(x+50)/100;
		if(y<50||y>850){
			cout<<"Invalid click; Click inside the board"<<endl;
			continue;}
		else y=(y+50)/100;
		break;}
if((y1==y-2&&(x1==x-2||x1==x+2))&&checkpeg(x,y,com,n1)==0&&checkpeg((x+x1)/2,y-1,com,n1)==2){c[n].moveTo(x*100,y*100);com.c[n1].moveTo(10000,10000);kill(x,y,n,com);return;}
else{deselect_peg(n);return;}
}
else deselect_peg(n);}


//Allows user to move.
void player::move(player &com){
int n=select_peg();
int z,x,y,x1,y1;
while(1){
		z=getClick();
		x=z/65536;
		y=z%65536;
		if(x<50||x>850){
			cout<<"Invalid click; Click inside the board"<<endl;
			continue;}
		else x=(x+50)/100;
		if(y<50||y>850){
			cout<<"Invalid click; Click inside the board"<<endl;
			continue;}
		else y=(y+50)/100;
		break;}
x1=c[n].getX()/100;y1=c[n].getY()/100;

int n1;
if((y1==y-1&&(x1==x-1||x1==x+1))&&checkpeg(x,y,com,n1)==0){c[n].moveTo(x*100,y*100);deselect_peg(n);return;}
else if((y1==y-2&&(x1==x-2||x1==x+2))&&checkpeg(x,y,com,n1)==0&&checkpeg((x+x1)/2,y-1,com,n1)==2){c[n].moveTo(x*100,y*100);com.c[n1].moveTo(10000,10000);kill(x,y,n,com);return;}
else {deselect_peg(n);move(com);}
}


//Check kill condition for computer.
void player::kill2(int n,player &user){
int x,y,n1;
x=c[n].getX()/100;
y=c[n].getY()/100;


if(checkpeg(x-2,y-2,user,n1)==0&&checkpeg(x-1,y-1,user,n1)==2){c[n].moveTo((x-2)*100,(y-2)*100);user.c[n1].moveTo(10000,10000);kill2(n,user);}
else if(checkpeg(x+2,y-2,user,n1)==0&&checkpeg(x+1,y-1,user,n1)==2){c[n].moveTo((x+2)*100,(y-2)*100);user.c[n1].moveTo(10000,10000);kill2(n,user);}
}



//Allows computer to move.
bool player::move2(player &user){
int i,n1;
for(i=0;i<12;i++){
int x,y,n1;
x=c[i].getX()/100;
y=c[i].getY()/100;

if(checkpeg(x-2,y-2,user,n1)==0&&checkpeg(x-1,y-1,user,n1)==2){c[i].moveTo((x-2)*100,(y-2)*100);user.c[n1].moveTo(10000,10000);wait(1);kill2(i,user);return false;break;}
else if(checkpeg(x+2,y-2,user,n1)==0&&checkpeg(x+1,y-1,user,n1)==2){c[i].moveTo((x+2)*100,(y-2)*100);user.c[n1].moveTo(10000,10000);wait(1);kill2(i,user);return false;break;}
}

for(i=0;i<12;i++){
int x,y;

x=c[i].getX()/100;
y=c[i].getY()/100;

if(checkpeg(x-1,y-1,user,n1)==0){c[i].moveTo((x-1)*100,(y-1)*100);return false;break;}
else if(checkpeg(x+1,y-1,user,n1)==0){c[i].moveTo((x+1)*100,(y-1)*100);return false;break;}
}
return true;
}
