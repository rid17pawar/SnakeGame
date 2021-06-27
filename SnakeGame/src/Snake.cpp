#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{   //initializing Snake class objects using parameterized constructor

    //use this keyword, bcoz we have used parameter names same as variables declared.
    this->pos= pos;
    this->vel= vel;
    len=1; //initialize len variable of Snake class with 1 value initially
    direction='n'; //none, not moving initially

    body.push_back(pos); //pushing back elements inside a vector i.e. push back position of head of snake
}

void Snake::change_dir(char dir)
{
    direction=dir;
}

void Snake::move_snake()
{
    switch(direction)
    {
        case 'u': pos.Y-=vel; //to appear snake as moving up, decrease Y-axis value by velocity
                  break;

       case 'd': pos.Y+=vel; //to appear snake as moving down, increase Y-axis value by velocity
                  break;

       case 'l': pos.X-=vel; //to appear snake as moving to left, decrease X-axis value by velocity
                  break;

       case 'r': pos.X+=vel; //to appear snake as moving to right, increase X-axis value by velocity
                  break;
    }
    body.push_back(pos);
    if(body.size()>len)
    {
        body.erase(body.begin()); //erase first element from vector i.e. head of snake
    }
}

COORD Snake::get_pos()
{
    return pos;
}

bool Snake::eaten(COORD food_pos)
{
    //if snake mouth and food position is same food is eaten by snake
    if(food_pos.X== pos.X && food_pos.Y== pos.Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Snake::grow()
{
    len++;
}

bool Snake::collided()
{
    if(pos.X<1 || pos.X>WIDTH-2 || pos.Y<1 || pos.Y>HEIGHT-2)
    {
        //pos.X<1= collided with left wall, pos.X>WIDTH= collided with right wall, pos.Y<1= collided with upper wall, pos.Y>HEIGHT= collided with lower wall
        return true;
    }
    for(int i=0; i<len-1; i++)
    {
        if(pos.X==body[i].X && pos.Y==body[i].Y)
            return true;
    }
    return false;
}

vector<COORD> Snake::get_body()
{
    return body;
}
