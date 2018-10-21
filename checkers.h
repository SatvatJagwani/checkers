/*Checkers CS101 Project;
Created by JANAK AGRAWAL(150050047;CSE) && SATVAT JAGWANI(150050053;CSE)*/

#include<simplecpp>

struct player{
Circle c[12];
player(int n);//constructor
int checkpeg(int x, int y, player const & user2, int &n);//checks for peg at (x,y)
int select_peg();//selects a peg
void deselect_peg(int i);//deselects a peg
void kill(int x1, int y1, int n,player &com);//kill for user
void move(player &com);//move for user
void kill2(int n,player &user);//kill for computer
bool move2(player &user);//move for computer

};
