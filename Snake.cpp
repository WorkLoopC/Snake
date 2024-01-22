#include <iostream>
#include <conio.h>
#include <windows.h>
bool gameOver;
const int width = 10;
const int height = 10;
int x, y, fruitX, fruitY, score;
enum Directon { STOP = 0, LEFT, RIGHT, UP, DOWN}; //using enum so there is less rows so i wont have to write multiple ints for the switch function 
Directon dir;

void Setup(){  //Setup basic variables that will be used throught the code
gameOver=FALSE;
x=width/2;
y=height/2;
fruitX=rand() % width;
fruitY=rand() % height;
score=0;
}

void Draw(){  //Drawning the playground (Has a smaller shape so it fits into terminal in VS code)
system("cls"); //this will clear the terminal 
for(int j=0;j<width;j++)
    std::cout<<"#";
    std::cout<<'\n';
for(int a=0;a<height;a++){
for(int k=0;k<width;k++){
    if(k==0 || k==width-2)
        std::cout<<"|";   
    if(a==x && k==y)
        std::cout<<"O";
    else if(a==fruitX && k==fruitY)
        std::cout<<"X";
    else
        std::cout<<" ";
}
std::cout<<'\n';  
}              
for(int i=0;i<width;i++){
std::cout<<"#";
    }
}
void Input()   //Setting up the keys that will be used for the basic movement
{
if (_kbhit()){
switch (_getch()){
case 'a':
    dir = LEFT;
    break;
case 'd':
    dir = RIGHT;
    break;
case 'w':
    dir = UP;
    break;
case 's':
    dir = DOWN;
    break;
case 'x':
    gameOver = true;
    break;
        }
    }
}
void Logic(){  //The actuall movement
switch(dir){
case LEFT:
    y--;
    break;    
case RIGHT:
    y++;
    break;    
case UP:
    x--;
    break; 
case DOWN:
    x++;
    break;  
}
if(y>width-3 || y<0 || x>height-1 || x<0){ //Setting up the coordinates that will make you lose when u reach them 
    gameOver = true;
    std::cout<<'\n';
    std::cout<<"***GAME OVER***"<<'\n';
    std::cout<<"Your score is:"<<score;
}
if(fruitX==x && fruitY==y){ //Setup of the "fruit"
score++;
fruitX=rand() % height;
fruitY=rand() % 7;
    }
} 
int main(){ 
Setup();
while (!gameOver){
    Draw();
    Input();
    Logic();
    Sleep(120); //Modifying the speed of the snake
    }
return 0;
}

