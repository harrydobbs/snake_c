#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

typedef struct Food
{
    int lifetime;
    Position pos;
};

void spawn_food();

#endif