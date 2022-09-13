//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
float foodx[100]={670,570,470,270,170,70,30, 30,30,30,30,30,30, 130,230,430,530,630,670, 670,670,670,670,670,670,

 610,510,410,310,210,100, 100,100,100,100, 200,300,400,500,610, 610,610,610,610,
 
530,430,230,130,170,  170,170,170,  270,470,530, 530,530,530, 

460,400,300,250,  240,  300,400,460, 460};
float foody[100]={60,60,60,60,60,60,60,  690,660,560,460,260,160,  690,690,690,690,690,690,  590,490,290,190,90,60,

   130,130,130,130,130,130,  200,300,500,620,  620,620,620,620,620, 520,320,220,130,


200,200,200,200,200,  270,470,555, 555,555,555, 470,270,200, 
 260,260,260,260,  475,  475,475,475,  260};
float transitx[100]={670,570,470,270,170,70,30, 30,30,30,30,30,30, 130,230,430,530,630,670, 670,670,670,670,670,670,

 610,510,410,310,210,100, 100,100,100,100, 200,300,400,500,610, 610,610,610,610,
 
530,430,230,130,170,  170,170,170,  270,470,530, 530,530,530, 

460,400,300,250,  240,  300,400,460, 460};
float transity[100]={60,60,60,60,60,60,60,  690,660,560,460,260,160,  690,690,690,690,690,690,  590,490,290,190,90,60,

   130,130,130,130,130,130,  200,300,500,620,  620,620,620,620,620, 520,320,220,130,


200,200,200,200,200,  270,470,555, 555,555,555, 470,270,200, 
 260,260,260,260,  475,  475,475,475,  260} ;
void food();
void help();
void highscores();
void pausethegame();
void menu();
void level4();
void level2();
void level3();
void randomposition();
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
                                          }



 
  //Main Canvas drawing function.
int high_score[10]={30,390,400,325,395,340,360,385,350,355};
int choice=2000;
int pausegame=20;

int direc=0;
bool restart=false;
float x2=500;
float y2=680;
float x= 250;
float y=680;
int score=33;
int lives=3;

float array[2]={x2,y2};
int space;
char charac;
int level=3;
float x3=600;
float y3=40;
int rectangle3=40;
int rectangle1=0;

           int rectangle2=0;
  float k=10.0;// steps to take
//Board *b;
void randomposition()
{
x=rand();
y=rand();
while(!( (x>420 && x<700 && y<=720 && y>=670)or (x>420 && x<700 && y>=30 && y<=100) or (x<700 && x>=660 && y>=20 && y<=680) ) )      
{
x=rand();
y=rand();
}

}
void GameDisplay(){ 
            
            
           if (pausegame==20)//calls menu function first up
          
             menu();
            
           if(choice==1)//initializes all variables to start the game all over again
           {     x2=500;
                 y2=680; 
		 x= 250;
		 y=680;
                 level=1;
		 score=33; 
		direc=0;  
		food();
                pausegame=1000;
	   }   
           
	  if(pausegame==8)//calls pausethegame() to pause the game and show menu
           pausethegame();

          
        if(restart==true)//initializes all variables to start the game all over again if lives>0
           {  x=670;
		 y=40;
		 x2= 30;
		 y2=40;
		 
		direc=0;  
		food();
                pausegame=1000;
		}  
          if (pausegame==1000 or choice==1)
      {


         restart=false;//initially its false but when condition is met it becomes  true       
        glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
       
        float width = 8.0; 
	float height = 8.0;
	float* color = colors[CYAN]; 
	float radius = 4.0; 
      
       
        //user car
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

        //opponant car
         float* oppocolor=colors[DARK_SEA_GREEN];
         DrawRoundRect(x2,y2,width,height,oppocolor,radius); // bottom left tyre
	DrawRoundRect(x2+width*3,y2,width,height,oppocolor,radius); // bottom right tyre
	DrawRoundRect(x2+width*3,y2+height*4,width,height,oppocolor,radius); // top right tyre
	DrawRoundRect(x2,y2+height*4,width,height,oppocolor,radius); // top left tyre
	DrawRoundRect(x2, y2+height*2, width, height, oppocolor, radius/2); // body left rect
	DrawRoundRect(x2+width, y2+height, width*2, height*3, oppocolor, radius/2); // body center rect
	DrawRoundRect(x2+width*3, y2+height*2, width, height, oppocolor, radius/2); // body right rect
        if(level==4)//makes another car if level is equal to 4
      {  //opponant car(2)
         float* oppcolor=colors[RED];
         DrawRoundRect(x3,y3,width,height,oppcolor,radius); // bottom left tyre
	DrawRoundRect(x3+width*3,y3,width,height,oppcolor,radius); // bottom right tyre
	DrawRoundRect(x3+width*3,y3+height*4,width,height,oppcolor,radius); // top right tyre
	DrawRoundRect(x3,y3+height*4,width,height,oppcolor,radius); // top left tyre
	DrawRoundRect(x3, y3+height*2, width, height, oppcolor, radius/2); // body left rect
	DrawRoundRect(x3+width, y3+height, width*2, height*3, oppcolor, radius/2); // body center rect
	DrawRoundRect(x3+width*3, y3+height*2, width, height, oppcolor, radius/2); // body right rect
       } 
         float* foodcolor=colors[YELLOW];
         float* backgroundcolor=colors[BLACK];
           
          choice=2000;//changing value of choice so everytime choice=1 , the arena resets 
           /* user operated green car */
	/* rectangle1 assignment used to be used in the AI for opponant car*/
           // innermost
            if(x2>=230 && x2<480 && y2>=220 && y2<=260)// right to left
           {
            x2-=k;
            rectangle1=1;
            }
            else if(x2>=450 && x2<=470 && y2>=240 && y2<=480)//top to bottom
           {
            y2-=k;
		rectangle1=1;
		}
           else if ( x2>=220 && x2<250 && y2>=240 && y2<=470)//bottom top 
           	{
		y2+=k;
		rectangle1=1;
		}
           else if(x2>=220 && x2<460 && y2>=460 && y2<=480)//left to right
           	{
		x2+=k;
		rectangle1=1;
		}
          
           //second innermost
            if(x2>=150 && x2<=530 && y2<=550 && y2>=530)//left to right
		{
		x2+=k;
		rectangle1=2;
		}
           else if ( x2>=520 && x2<=540 && y2>170 && y2<=550)//top to bottom 
           	{
		y2-=k;
 		rectangle1=2;
		}
           else if(x2>160 && x2<=540 && y2>=170 && y2<=190)//right to left
           	{
		x2-=k;
		rectangle1=2;
		}
           else if(x2>=140 && x2<=170 && y2>=170 && y2<=550)//bottom to top
           	{
		y2+=k;
		rectangle1=2;
		}           

		//third inner most rectangle
           else if(x2<=590 && x2>=80 && y2<=640 && y2>=600)
           	{
		x2+=k;
		rectangle1=3;
		}
           else if(x2>=70 && x2<=100 && y2>=100 && y2<=610)
            	{
		y2+=k;
		rectangle1=3;
		}
           else if(x2>=85 && x2<=620 && y2>=100 && y2<=120)
           	{
                x2-=k;
		rectangle1=3;
		}
          else if ( x2>=590 && x2<=610 && y2>=120 && y2<=620)
           	{
		y2-=k;
		rectangle1=3;
		}
                //fourth inner most rectangle
           else  if( x2>=10 && x2<=30 && y2<690 && y2>=30)// bottom to top
            	{
		y2+=k;
	           rectangle1=4;
		}
           else  if ( x2<=665 && x2>=10  && y2<=720 && y2>=670)//from left to rigt at the top 
       		 {	
		x2+=k;
		rectangle1=4;
		}
            else if ( x2<700 && x2>=660 && y2>=40 && y2<=690)//control to keep the car at right corner and go downwards 
           {
		y2-=k;
		rectangle1=4;
		} 
           else if( x2>=30 && x2<=680 && y2>=30 && y2<=100)//takes the car towards left
            	{
		x2-=k;
		rectangle1=4;
		}
         /*opponant operated car for level 1 and 2 and 4*/
         /* rectangle2 assignment used to be used in the AI for opponant car*/
         if(level==1 or level==2 or level==4)
     {      if(x>230 && x<480 && y>440 && y<=520)//for the inner most rectangle
          	 {
             x-=k;//right to left
             rectangle2=1;
            	}
           else if(x>=220 && x<=270 && y>240 && y<510)
         	 {
		 y-=k;//top to bottom
		rectangle2=1;
		}
           else if(x>=220 && x<460 && y>=230 && y<310)
           	{
		x+=k;//left to right
		rectangle2=1;
		}
           else if ( x>=420 && x<=470 && y>=220 && y<=520)
                {
		y+=k;//bottom to top
		rectangle2=1;
		}
           
       
           else if(x>150 && x<560 && y<590 && y>=515)//second innermost
          	{
		 x-=k;
		rectangle2=2;
		}
           else if(x>=150 && x<210 && y>170 && y<590)
           	{
		y-=k;
		rectangle2=2;
		}
           else if(x>=150 && x<520 && y>=170 && y<230)
           	{
		x+=k;
		rectangle2=2;
		}
           else if ( x>=500 && x<=560 && y>=170 && y<590)
           	{
		y+=k;
		rectangle2=2;
		}
           

          else if(x<=620 && x>=90 && y<=640 && y>=600)//third inner most rectangle
           {
	x-=k;
		rectangle2=3;
		}
           else if(x>=70 && x<=140 && y>=120 && y<=650)
          {	
		 y-=k;
		rectangle2=3;
		}
           else if(x>=70 && x<=590 && y>=100 && y<=140)
           	{
		x+=k;
		rectangle2=3;
		}
           else if ( x>=580 && x<=640 && y>=100 && y<=640)
           	{
		y+=k;
		rectangle2=3;
		}
           
           //fourth inner most rectangle
           else  if( x>=10 && x<=20 && y<=720 && y>40)//top to bottom , left
        	   {
		 y-=k;
		rectangle2=4;
		}
           else  if ( x<=700 && x>10  && y<=720 && y>=670)//from left to rigt at the top 
        	   { 
		 x-=k;
		rectangle2=4;             
            		}
           else if ( x<700 && x>=660 && y>=20 && y<=680)//control to keep the car at right corner and go upwards 
           {
		y+=k;
		rectangle2=4;
		} 
           else if( x>=10 && x<=665 && y>=30 && y<=100)//takes the car towards left
            	{
		x+=k;
		rectangle2=4;
		}
}
		    /*calling opponant operated cyan car for level 3 with double speed */  
		    if(level==3) 
		     level3();


			 /*calling 2nd opponant operated red car for level 4 */        
			 if( level==4)
			 level4();
         

           
         
/* key control of the user*/      
       if(direc==2)//right key
         { 

            if( ((x2>=10 && x2<=660)) && y2>=310 && y2<=390  )//condition to slide left and right where gap turns are and to prevent it  from going outside the gap turns         
               {
                   if(x2>=220 && x2<=300 && y2>=310 && y2<=390)//condition to prevent from going into inner most rectangle
                  {}
                  else 
                  x2+=70;
              }
         
          }
	    
         if(direc==1)//left key
         { 

            if( ((x2>=50 && x2<=670)) && y2>=310 && y2<=390  )//condition to slide left and right where gap turns are and to prevent it  from going outside the gap turns                   
               {
                   if(x2>=430 && x2<=450 && y2>=310 && y2<=390)//condition to prevent from going into inner most rectangle
                  {}
                  else 
                  x2-=70;
              }
         
          }
       if(direc==3)//upkey
         { 

            if( (x2>290 && x2<420) && y2<=640 )//condition to slide up and down where gap turns are and to prevent it  from going outside the gap turns
             {   if(y2>=240 && y2<=310)//condition to prevent from going into inner most rectangle
                  {}
                  else 
              y2+=70;
              }
         
          }
          
         
         if(direc==4)//down key
         { 
          if( x2>290 && x2<420 && (y2>=400 || y2<=310) && y2>=90)//condition to slide up and down where gap turns are and to prevent it  from going outside the gap turns
          {    if( y2<=510 and y2>=450)//condition to prevent from going into inner most rectangle
                 {}
               else
              y2-=70;
          }
          
         }
          
/*  for the space bar press for user car to increase speed */	

           // innermost
         
           if((x2>=230 && x2<480 && y2>=220 && y2<=260))// right to left
           { if(space==1)
           x2-=k;}
            else if((x2>=450 && x2<=470 && y2>=240 && y2<=480))//top to bottom
            {if(space==1)
           y2-=k;}
           else if (( x2>=220 && x2<250 && y2>=240 && y2<=470))//bottom top 
 		{if(space==1)
           y2+=k;}
           else if((x2>=220 && x2<460 && y2>=460 && y2<=480))//left to right
		{if(space==1)
           x2+=k;}
           
           //second innermost
            if((x2>=150 && x2<=530 && y2<=550 && y2>=530))//left to right
		{if(space==1)
           x2+=k;}
           else if (( x2>=520 && x2<=540 && y2>170 && y2<=550))//top to bottom 
             {if(space==1)
           y2-=k;}
           else if((x2>150 && x2<=540 && y2>=180 && y2<=190))//right to left
              {if(space==1)
           x2-=k;}
           else if((x2>=140 && x2<=170 && y2>=180 && y2<=550))//bottom to top
             {if(space==1)
           y2+=k;}
           



           else if((x2<=590 && x2>=80 && y2<=640 && y2>=600))//third
           { if(space==1)
           x2+=k;}
           else if((x2>=70 && x2<=100 && y2>=100 && y2<=610))//up
             {if(space==1)
           y2+=k;}
           else if((x2>=85 && x2<=620 && y2>=100 && y2<=120))
                {if(space==1)
           x2-=k;}
          else if (( x2>=590 && x2<=610 && y2>=120 && y2<=620))
                   {if(space==1)
           y2-=k;}
       
           else  if(( x2>=10 && x2<=30 && y2<690 && y2>=30))// bottom to top
		{if(space==1)
            y2+=k;
             }

           else  if (( x2<=665 && x2>=10  && y2<=720 && y2>=670))//from left to rigt at the top
		{if(space==1) 
             x2+=k;
		}
            else if ( (x2<700 && x2>=660 && y2>=40 && y2<=690))//control to keep the car at right corner and go downwards
		{if(space==1) 
           y2-=k; 
		}
           else if(( x2>=30 && x2<=680 && y2>=30 && y2<=100))//takes the car towards left
               {  if(space==1)
            x2-=k;
              }
            space=0;//setting it to zero again inorder that when kept pressed , only then the speed increases
 	/* AI control of the opponant car*/
	if(level==1 )
 {	
	if(x>300 && x<410 )//condition to only move at  gap turns  along x axis          
       {
            if(rectangle1+1==rectangle2 or   rectangle1-1==rectangle2)
            {
		   if(y2>y && (y<240 or y>440) )//to check when to move up and avoid moving into the most inner square
			{
			if((x>370 && x<400) or (x<310 && x>300))//condition when to move up or down
		     y+=70;
			}
		     if(y2<y &&(y<325 or y>480))//to check when to move down and avoid moving into the most inner square
			{
			if((x>370 && x<400) or (x<310 && x>300))//condition when to move up or down
		     y-=70;
			  }
            }
	 
       }
         

}
		/*calling level 2 for AI car to take all gap turns*/               
		  if(level==2)
		    level2();
         if(array[1]==y2 && array[0]!=x2 && (rectangle1==rectangle2 || rectangle1==rectangle3))// condition to check if previous x is same as this one      
         { 
                if(x2>=x)//condition to make sure subtraction below doesnt give answer in negative
         	 {
          	 if( x2-x<=10 && x2-x>=0)// condition to check car collision
          	         {
                          lives--; 
                          if(lives>0) 
                          restart=true;//for the game to start over again
                          }
          	}
        		else if(x>=x2)//condition to make sure subtraction below doesnt give answer in negative
        		 {  if( x-x2<=9 && x-x2>=0)// condition to check car collision
         			{
                                lives--; 
                                 if(lives>0) 
                                restart=true;
                                }
           			
         		 }
          }
else if( array[1]==y2 && array[0]!=x2 && (rectangle1==rectangle2|| rectangle1==rectangle3))// condition to check if previous y is same as this one
        {
                   if(y2>=y)//condition to make sure subtraction below doesnt give answer in negative
         	 {
          	 if( y2-y<=10 && y2-y>=0)// condition to check car collision
          	      {
                      lives--;
                       if(lives>0)
                      restart=true; 
                      }
                      
          	}
        		else if(y>=y2)//condition to make sure subtraction below doesnt give answer in negative
        		 {  if( y-y2<=10 && y-y2>=0)// condition to check car collision
         			{
                                 lives--;
                                   if(lives>0) 
                                  restart=true;
                                 }
           			
         		 } 
         }	

  
       //storing the present x2 and y2 in the array
            array[0]=x2;
            array[1]=y2;
          
           

        
             DrawString( 550, 780, "lives :", colors[INDIAN_RED]); //to display lives   
             DrawString( 610, 780, Num2Str(lives), colors[CYAN]); 
            
      /* drawing and collecting food*/

           for( int i=0 ; i<67 ; i++)//drawing food around the arena
          {     if( foodx[i]!=4000 && foody[i] !=4000)
              
            DrawRoundRect(foodx[i],foody[i],width,height,foodcolor,radius); // drawing food
           
           }
         int i=0;
         while( i<67)// to check array for total number of food
          {      if(foodx[i]!=4000 && foody[i] !=4000)
		 { 
                       if(foodx[i]<= x2+30 && foodx[i]>=x2-30 && foody[i]>=y2-30 && foody[i]<=y2+30)//forming  a radius of 30 around the user car to collect food
		         {
                          
		          
		          DrawRoundRect(foodx[i],foody[i],width,height,backgroundcolor,radius);//drawing black food to make it  look disappeared
		          foodx[i]=4000;//storing 4000 in the index where foo disappeared so food wont draw or collect itself over again
		          foody[i]=4000;
		           if( foodx[i]==4000 && foody[i]==4000)
		          score++;//increment in score as food collects
		         
                          
		         }
                }
               i++;
           }
            DrawString( 50, 780, "Score :", colors[INDIAN_RED]); //to display the score   
	    DrawString(120, 780,Num2Str(score) , colors[CYAN]); 
   
         
          direc=0;// making direc=0 so that the upkey, down , left or right key isnt constantly working 
         
 
      
         
	
	
         
	// Drawing Arena
	int gap_turn = 110;
	int sx = 10;
	int sy = 20;
	int sr=700;
	int swidth = sr/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[CADET_BLUE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+sr+10, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+sr+10, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
        
        for(int i=1 ; i<5 ; i++)
        { 
         if(i==4)//so as to decrease gap turn for the last rectangle
         {
         gap_turn=20;
        sx+=70;//changge in x
	sy+=70;//change in y
	sr-=140;//for change in width
          }
        else
        {
	sx+=70;
	sy+=70;
	sr-=140;
        }
       /*draws the rest of arena*/
	swidth = sr/2 - gap_turn/2;
	
        DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+sr+10, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+sr+10, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
        
        
           if(score==100)//completion of level 1
           {
            	level=2;//changes level
            	 x=670;//resets position of opponant car
 		y=40;
 		x2= 30.0;//resets position of user car
		 y2=40.0;
             food();//stores food coordinates in the food array all over agian
               score=score+33;//adds 33 so that whenever level completes , the score is a multiple of 100
           } 
           if(score==200)//completion of level 2
           {
             
            	 x=670;
 		y=40;
 		x2= 30.0;//resets position of user car
		 y2=40.0;
                level=3;//changes level
               food();//stores food coordinates in the food array all over agian
               score=score+33;//adds 33 so that whenever level completes , the score is a multiple of 100
           } 
               if(score==300)//completion of level 3
           {
              
            	 x=670;//resets position of opponant car
 		y=40;
 		x2= 30.0;//resets position of user car
		 y2=40.0;
                 x3=600;//resets position of 2nd opponant car
                 y3=600;
            level=4;//changes level
             food();//stores food coordinates in the food array all over agian
               score=score+33;//adds 33 so that whenever level completes , the score is a multiple of 100
           } 
                 if(score==400)//completion of game displays you won
                 DrawString(290, 350, "YOU WON !!!!  ", colors[LIME_GREEN]);
                  if(lives==0)
             {
                 for(int i=0 ; i<10; i++)//if score is greater than scores in high_score array then this score is saved in that array
              {    if(score>high_score[i])
                     high_score[i]=score;
		}
            }
               if(lives==0)//starts the game over again and resets everything
               {
                DrawString(260, 350, "starting the game again", colors[LIME_GREEN]);
                      level=1;
                     x=250;
		     y=680;
		      x2=500;
		      y2=680;
		      score=33; 
		      direc=0; 
                      lives=3; 
		      food();
                     pausegame=1000;

                     
               }
       } 
       
    }
      

   
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
        
	if (key==GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...//100
               direc=1;//to be used in display ftn to move left
           
	} else if (key==GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key 102*/) {
		
               direc=2;//to be used in display ftn to move right

	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key 101*/) {
		direc=3;//to be used in display ftn to move up
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key103*/) {
		direc=4;//to be used in display ftn to move down
               
	}
	
       

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
   

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if(key==32)//asigns space=1 whenever spacebar is pressed
       {  space=1;
		
       }
 	if (key == 52) /* Escape key ASCII*/
            
		exit(1); // exit the program when escape key is pressed.
	

	if (key == 'p' || key == 'P')
	{
                     if(pausegame==8)//condition to return to the game when p is pressed again
		{
			pausegame=1000;
		}
		else
		{
			pausegame=8;//pauses the game by assigning pausegame=8
                }

        }
                                     
        if(key == 49)
        { 
        	choice=1;//starts the game over again
        }
       if(key =='h' || key=='H')
       {      
              
		charac='h';//opens up the help window
      }
       if(key =='g' || key=='G')
       {      
              
		charac='g';//lets you go back to the menu or pause game from the highscores or help window
      }
       if(key =='s' || key=='S')
       {                  
		charac='s';//opens up the high scores window
      }

	
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	if(pausegame==8)//pauses the game
         {
          glutPostRedisplay();
         glutTimerFunc(60.0, Timer, 0);
         }
         else//if the game isnt paused
        { 
         glutPostRedisplay();
	glutTimerFunc(60.0, Timer, 0);
	}// once again we tell the library to call our Timer function after next 1000/FPS
        
}


/*
 * our gateway main function
 * */
int position[4];
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
        srand(time(0));
        
	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
        
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
        
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
         
          
	glutTimerFunc(60.0, Timer, 0);
        
         
	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
void pausethegame()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
         DrawString(10,520, "___________*******************_____________", colors[RED]);
         DrawString(10, 490, "Press the corresponding assignment to do so", colors[RED]);
         DrawString(10, 450, "1.START GAME", colors[RED]);
         DrawString(10 , 410, "H.HELP ", colors[RED]); 
         DrawString(10, 380, "S.HIGHSCORES", colors[RED]); 
         DrawString(10, 350, "4.EXIT", colors[RED]);
         DrawString(10, 320, "Press P to continue", colors[RED]);
         DrawString(10, 290, "___________*******************_____________", colors[RED]);
       if(charac=='h')//opens up help window 
        {
            help();
      
         } 
        if(charac=='s')//opens up the highsores window 
        {
            highscores();
      
         } 
          
}
void menu()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
         DrawString(10 , 520, "___________*******************_____________", colors[MISTY_ROSE]);
         DrawString(10, 490, "Press the corresponding assignment to do so", colors[MISTY_ROSE]);
         DrawString(10, 450, "1.START GAME", colors[MISTY_ROSE]);
         DrawString(10 , 410, "H.HELP ", colors[MISTY_ROSE]); 
         DrawString(10 , 380, "S.HIGHSCORES", colors[MISTY_ROSE]); 
         DrawString(10, 350, "4.EXIT", colors[MISTY_ROSE]);
         DrawString(10, 320, "___________*******************_____________", colors[MISTY_ROSE]);
        if(charac=='h')//opens up the help window 
        {
            help();
      
         } 
        if(charac=='s')//opens up the highscores window 
        {
            highscores();
      
         } 
       
          
}
void food()//function to save the coordiantes back to the food array
{  for( int i=0 ; i<100 ; i++)
  {    
  foodx[i]=transitx[i];
  foody[i]=transity[i];
  }
}

void help()
{ glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString(10 , 640, "___________*******************_____________ ", colors[MISTY_ROSE]);
 DrawString(10 , 610, "The green car is your car , controlled by the up , down ,left and right arrow keys. ", colors[MISTY_ROSE]);
 DrawString(10 , 580, "your task is to collect all the fuel packets without crashing into your opponant ", colors[MISTY_ROSE]);
DrawString(10 , 550, " car which will be chasing you through the gaps.  ", colors[MISTY_ROSE]);
 DrawString(10 , 520, ". you can move left ,right , up and down in the area of gap turns .  ", colors[MISTY_ROSE]);
 DrawString(10 , 490, " PRESS P for pause AND 4 to ESCAPE the game .  ", colors[LIME_GREEN]);
 DrawString(10 , 430, " PRESS G to GO BACK .  ", colors[LIME_GREEN]);
DrawString(10 , 400, "___________*******************_____________ ", colors[MISTY_ROSE]);
if(charac=='g')//help to go back to the menu 
         menu();
       
}
void highscores()
{ int sk=430;//used in loop for printing scores
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
         //writing to a file
	ofstream fout;
	fout.open ("highscores.txt"); //this function takes the name of the file that you are writing to
	
	for (int i = 0; i < 10; i++){
		fout << high_score[i] << endl;
	}
		
	fout.close();   
           string score;
	ifstream fin ("highscores.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{          
		while ( getline (fin, score) ) //this loop will run depending on the number of lines in the file
		{
		  
		  DrawString(10 , sk-=30, score, colors[LIME_GREEN]);
		  
		  
		}
		fin.close();
	}
	
	else 
		cout << "Unable to open file"; 
 DrawString(10 , 700, " PRESS G to GO BACK .  ", colors[LIME_GREEN]);
if(charac=='g')//takes you back to the menu 
        {
            menu();
      
         } 
}
void level2()//called in the display when the level reaches 2
{
    if(x>300 && x<410 )//condition to only move at  gap turns  along x axis            
       {
           if(rectangle1==rectangle2+1 or   rectangle1==rectangle2-1 )
            {
		   if(y2>y && (y<240 or y>=430) )//to check when to move up and avoid moving into the most inner square
			{if((x>370 && x<400) or (x<310 && x>300))//condition when to move up or down
		     y+=70;}
		     if(y2<y &&(y<320 or y>510))//to check when to move down and avoid moving into the most inner square
			{if((x>370 && x<400) or (x<310 && x>300))//condition when to move up or down
		     y-=70;}
	     }
       }

 else if(y>=320 && y<=430 )//condition to only move at  gap turns  along y axis
        {
		 if(rectangle1==rectangle2+1 or   rectangle1==rectangle2-1 )
            { 
           		if(x2>x && (x<210 or x>420))//to check when to move right and avoid moving into the most inner square
			{
			if((y<430 && y>400) or (y<330 && y>320))//condition when to left up or right
             		x+=70;
			}
             		if(x2<x && (x<250 or x>500))//to check when to move left and avoid moving into the most inner square
			{
			if((y<430 && y>400) or (y<330 && y>320))//condition when to left up or right
            		 x-=70;
	         	}
	   }	
	}
}
void level4()//called in the display when the level reaches 4
{    /* rectangle3 assignment to be used for AI  control of second opponant car in level4*/
     /* 2nd opponant car's movement*/
        if(x3>230 && x3<480 && y3>440 && y3<=520)//for the inner most rectangle
          	 {
             x3-=k;//right to left
             rectangle3=1;
            	}
           else if(x3>=220 && x3<=270 && y3>240 && y3<510)
         	 {
		 y3-=k;//top to bottom
		rectangle3=1;
		}
           else if(x3>=220 && x3<460 && y3>=230 && y3<310)
           	{
		x3+=k;//left to right
		rectangle3=1;
		}
           else if ( x3>=420 && x3<=470 && y3>=220 && y3<=520)
                {
		y3+=k;//bottom to top
		rectangle3=1;
		}
           
       
           else if(x3>150 && x3<560 && y3<590 && y3>=515)//second innermost most rectangle
          	{
		 x3-=k;
		rectangle3=2;
		}
           else if(x3>=150 && x3<210 && y3>170 && y3<590)
           	{
		y3-=k;
		rectangle3=2;
		}
           else if(x3>=150 && x3<520 && y3>=170 && y3<230)
           	{
		x3+=k;
		rectangle3=2;
		}
           else if ( x3>=500 && x3<=560 && y3>=170 && y3<590)
           	{
		y3+=k;
		rectangle3=2;
		}
           

          else if(x3<=620 && x3>=90 && y3<=640 && y3>=600)//third inner most rectangle
           {
	x3-=k;
		rectangle3=3;
		}
           else if(x3>=70 && x3<=140 && y3>=120 && y3<=650)
          {	
		 y3-=k;
		rectangle3=3;
		}
           else if(x3>=70 && x3<=590 && y3>=100 && y3<=140)
           	{
		x3+=k;
		rectangle3=3;
		}
           else if ( x3>=580 && x3<=640 && y3>=100 && y3<=640)
           	{
		y3+=k;
		rectangle3=3;
		}
           

           else  if( x3>=10 && x3<=20 && y3<=720 && y3>40)//fourth inner most rectangle
        	   {
		 y3-=k;//top to bottom , left
		rectangle3=4;
		}
           else  if ( x3<=700 && x3>10  && y3<=720 && y3>=670)//from left to rigt at the top 
        	   { 
		 x3-=k;
		rectangle3=4;             
            		}
           else if ( x3<700 && x3>=660 && y3>=20 && y3<=680)//control to keep the car at right corner and go upwards 
           {
		y3+=k;
		rectangle3=4;
		} 
           else if( x3>=10 && x3<=665 && y3>=30 && y3<=100)//takes the car towards left
            	{
		x3+=k;
		rectangle3=4;
		}
/* AI control for the 1st opponant*/
           if(x>300 && x<410 )//condition to only move at  gap turns  along x axis           
       {
          if(rectangle1==rectangle2+1 or   rectangle1==rectangle2-1 )
          {
           if(y2>y && (y<240 or y>=430) )//to check when to move up and avoid moving into the most inner square
		{if((x>370 && x<400) or (x<310 && x>300))//condition when to move up or down
             y+=70;}
             if(y2<y &&(y<320 or y>510))//to check when to move down and avoid moving into the most inner square
		{if((x>370 && x<400) or (x<310 && x>300))//condition when to move up or down
             y-=70;}
	   }
       }

 else if(y>=320 && y<=430 )//condition to only move at  gap turns  along y axis
        {
		  if(rectangle1==rectangle2+1 or   rectangle1==rectangle2-1 )
               {
           		if(x2>x && (x<210 or x>420))//to check when to move right and avoid moving into the most inner square
			{
			if((y<430 && y>400) or (y<330 && y>320))//condition when to left up or right
             		x+=70;
			}
             		if(x2<x && (x<250 or x>500))//to check when to move left and avoid moving into the most inner square
			{
			if((y<430 && y>400) or (y<330 && y>320))//condition when to left up or right
            		 x-=70;
	         	}
               }
	   	
	}
/* AI control for the 2nd opponant*/
    if(x3>300 && x3<410 )//condition to only move at  gap turns  along x axis       
       {
          if(rectangle1==rectangle3+1 or   rectangle1==rectangle3-1 )
            {
                if(y2>y3 && (y3<240 or y3>=430) )//to check when to move up and avoid moving into the most inner square
		{if((x3>370 && x3<400) or (x3<310 && x3>300))//condition when to move up or down
                 y3+=70;}
                if(y2<y3 &&(y3<320 or y3>510))//to check when to move udown and avoid moving into the most inner square
		{if((x3>370 && x3<400) or (x3<310 && x3>300))//condition when to move up or down
                y3-=70;}
            }
	  
       }

 else if(y3>=320 && y3<=430 )//condition to only move at  gap turns  along y axis
        {
		if(rectangle1==rectangle3+1 or   rectangle1==rectangle3-1 )
                { 
           		if(x2>x3 && (x3<210 or x3>420))//to check when to right and avoid moving into the most inner square
			{
			if((y3<430 && y3>400) or (y3<330 && y3>320))//condition when to left or right 
             		x3+=70;
			}
             		if(x2<x3 && (x3<250 or x3>500))//to check when to left and avoid moving into the most inner square
			{
			if((y3<430 && y3>400) or (y3<330 && y3>320))//condition when to left or right 
            		 x3-=70;
	         	}
                 }	
	}

}
void level3()//called in the display when the level reaches 3
/* the assignment to rectangle2 two is later used for the AI movement of opponant car and the speed now double by 2*k*/
 
{ if(x>230 && x<480 && y>440 && y<=520)//for the inner most rectangle
          	 {
             x-=2*k;//right to left
             rectangle2=1;
            	}
           else if(x>=220 && x<=270 && y>240 && y<510)
         	 {
		 y-=2*k;//top to bottom
		rectangle2=1;
		}
           else if(x>=220 && x<460 && y>=230 && y<310)
           	{
		x+=2*k;//left to right
		rectangle2=1;
		}
           else if ( x>=420 && x<=470 && y>=220 && y<=520)
                {
		y+=2*k;//bottom to top
		rectangle2=1;
		}
           
       
           else if(x>150 && x<560 && y<590 && y>=515)//second innermost rectangle
          	{
		 x-=2*k;
		rectangle2=2;
		}
           else if(x>=150 && x<=210 && y>170 && y<590)
           	{
		y-=2*k;
		rectangle2=2;
		}
           else if(x>=150 && x<520 && y>=160 && y<230)
           	{
		x+=2*k;
		rectangle2=2;
		}
           else if ( x>=500 && x<=560 && y>=160 && y<590)
           	{
		y+=2*k;
		rectangle2=2;
		}
           

          else if(x<=620 && x>=90 && y<=640 && y>=600)//third innermost rectangle
           {
	x-=2*k;
		rectangle2=3;
		}
           else if(x>=70 && x<=140 && y>=120 && y<=650)
          {	
		 y-=2*k;
		rectangle2=3;
		}
           else if(x>=70 && x<=590 && y>=100 && y<=140)
           	{
		x+=2*k;
		rectangle2=3;
		}
           else if ( x>=580 && x<=640 && y>=100 && y<=640)
           	{
		y+=2*k;
		rectangle2=3;
		}
           

           else  if( x>=10 && x<=20 && y<=720 && y>40)//fourth inner most rectangle
        	   {
		 y-=2*k;//top to bottom , left
		rectangle2=4;
		}
           else  if ( x<=700 && x>10  && y<=720 && y>=670) 
        	   { 
		 x-=2*k;//from left to right at the top
		rectangle2=4;             
            		}
           else if ( x<700 && x>=660 && y>=20 && y<=680)
           {
		y+=2*k;//control to keep the car at right corner and go upwards 
		rectangle2=4;
		} 
           else if( x>=10 && x<=665 && y>=30 && y<=100)
            	{
		x+=2*k;//takes the car towards left
		rectangle2=4;
		}
        if(x>300 && x<410 )//condition to only move at  gap turns  along x axis            
       {
        if(rectangle1==rectangle2+1 or   rectangle1==rectangle2-1 )
        {
           if(y2>y && (y<240 or y>=430) )//to check when to move up and avoid moving into the most inner square
		{if((x>360 && x<400) or (x<330 && x>300))//condition when to move up or down
             y+=70;}
             if(y2<y &&(y<320 or y>510))//to check when to move down and avoid moving into the most inner square
		{if((x>360 && x<400) or (x<330 && x>300))//condition when to move up or down
             y-=70;}
	 }
       }

 else if(y>=320 && y<=430 )//condition to only move at  gap turns  along y axis
        {         
                 if(rectangle1==rectangle2+1 or   rectangle1==rectangle2-1 )
                {
		  	if(x2>x && (x<210 or x>420))//to check when to move right and avoid moving into the most inner square
			{
			if((y<420 && y>390) or (y<340 && y>320))//condition when to left up or right
             		x+=70;
			}
             		if(x2<x && (x<250 or x>500))//to check when to move left and avoid moving into the most inner square
			{
			if((y<420 && y>390) or (y<340 && y>320))//condition when to left up or right
            		 x-=70;
	         	}
                }
	   	
	}
          }   
         
#endif /* AsteroidS_CPP_ */
