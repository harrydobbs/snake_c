#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include <stdbool.h>

typedef struct Food
{
    Position pos;
    bool active;
} Food;

bool is_snake_on_position(Snake *snake, int x, int y);
void generate_food(Snake *snake, Food *food);
void draw_food(SDL_Renderer *renderer, Food *food);

#endif