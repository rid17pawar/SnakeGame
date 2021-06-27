#include <iostream>
#include<cstdlib> //library to use console commands within code [commands that we use on cmd directly eg. ls, cls]
#include<windows.h> //library allows to control cursor's position on console
#include<conio.h> //to capture keystrokes
#include<ctime> //to provide seed to random function, to generate diff. random value each time program is opened.
#include<vector> //to use vector to store snake body parts

//custom header files
#include "Snake.h"
#include "Food.h"

//defining macros
//returns square of x
#define sq(x) x*x
//dimensions of board
#define WIDTH 50
#define HEIGHT 25

using namespace std;

//create snake
Snake snake({WIDTH/2, HEIGHT/2}, 1); //position=center and velocity=1 char at a time
//create food
Food food;

int score=0; //calculate score

//functions
void board()
{
    //x-coordinate and y-coordinate values to position objects on screen [snake and food]
    COORD snake_pos= snake.get_pos();
    COORD food_pos= food.get_pos();

    vector<COORD> snake_body= snake.get_body();

    //show current scores
    cout<<"scores: "<<score<<"\n\n";
    //outer loop for no. of rows, inner for no. of columns
    for(int i=0; i<HEIGHT; i++)
    {
        cout<<"\t\t#";  //adding left wall at each row
        for(int j=0; j<WIDTH-2; j++)
        {
            if(i==0 || i==HEIGHT-1)
            {
                //print walls at top and bottom of board
                cout<<"#";
            }
            else if(i==snake_pos.Y && j+1==snake_pos.X)
            {
                cout<<"0"; //if coordinates match print object i.e. snake head
            }
            else if(i==food_pos.Y && j+1==food_pos.X)
            {
                cout<<"*"; //if coordinates match print object i.e. food
            }
            else
            {   //print space
                bool isBodyPart=false;
                for(int k=0; k<snake_body.size(); k++)
                {  //if coordinate match with snake bodypart position show snake bodypart. else show 1 space.
                    if(i==snake_body[k].Y && j+1==snake_body[k].X)
                    {
                        cout<<"o"; //snake body
                        isBodyPart=true;
                        break;
                    }
                }
                if(!isBodyPart)
                {    cout<<" ";    }
            }
        }
        cout<<"#"<<endl;  //adding right wall at each row
    }
}

int main()
{
    score=0; //initial score will be zero
    srand(time(NULL)); //set seed for rand()

    bool game_over= false;
    while(!game_over)
    {
        board();
        //kbhit= keyboard hit, its value will be true if u press any key
        if(kbhit())
        {   //getch= gets the key pressed by user
            switch(getch())
            {
                case 'w': snake.change_dir('u'); //direction= up
                           break;

                case 'a': snake.change_dir('l'); //direction= left
                           break;

                case 's': snake.change_dir('d'); //direction= down
                           break;

                case 'd': snake.change_dir('r'); //direction= right
                           break;
            }
        }

        if(snake.collided())
        {
            game_over=true; //stop game
        }

        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score= score+10; //for each successful attempt give 10 scores
        }

        snake.move_snake(); //to update the board

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0} );  //reposition cursor to start, to redraw board with new snake position and length
    }

    //when game ends i.e. snake collides on wall
     for(int i=0; i<HEIGHT; i++)
    {
        cout<<"\t\t#";  //adding left wall at each row
        if(i==11)
        {
            cout<<" GAME OVER !!!  FINAL SCORES= "<<score;
            continue; //skip inner loop for that row
        }
        //for all other rows
        for(int j=0; j<WIDTH-2; j++)
        {
            cout<<" ";
        }
        cout<<"#"<<endl; //adding right wall at row
    }

    getch();
    return 0;
}
