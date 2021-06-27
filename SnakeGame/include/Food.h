#ifndef FOOD_H
#define FOOD_H

#include<windows.h>
#include<cstdlib> //to generate random position for food

//dimensions of board
#define WIDTH 50
#define HEIGHT 25

class Food
{
    private:
        COORD pos; //position of food. if snake eats food, generate food again in another position

    public:
        Food();
        void gen_food();
        COORD get_pos();
};

#endif // FOOD_H
