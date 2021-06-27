#include "Food.h"

Food::Food()
{
    gen_food();
}

void Food::gen_food()
{
    //generate random position for food
    //formula: rand()% (max-min+1)+min
    //width=50, min=1 to max=49
    //height=25, min=1 to max=24
    pos.X= rand() % (WIDTH-3) +1; //1to23 ,0 and 24 are walls
    pos.Y= rand() % (HEIGHT-3) +1; //1t048 ,0 and 49 are walls
}

COORD Food::get_pos()
{
    return pos;
}
