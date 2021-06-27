//guard block
#ifndef SNAKE_H
#define SNAKE_H

#include<windows.h>
#include<vector>

//dimensions of board
#define WIDTH 50
#define HEIGHT 25
using namespace std;

class Snake
{
    private:
        COORD pos; //snake's position
        int len; //length of snake
        int vel; //velocity
        char direction; //direction of snake
        vector<COORD> body;

    public:
        Snake(COORD pos, int vel);
        void change_dir(char dir); //change direction of snake
        void move_snake(); //move snake in particular direction
        COORD get_pos(); //get snake's current position
        bool eaten(COORD food_pos); //check if snake ate the food
        void grow(); //to increase snake's length
        bool collided(); //check if snake has collided with any of the 4 walls
        vector<COORD> get_body(); //returns body of snake
};

#endif // SNAKE_H
