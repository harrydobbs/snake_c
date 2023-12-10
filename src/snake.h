#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"

typedef struct Snake
{
    Position *body;
    int length;
    Direction dir;
} Snake;

void update_snake_direction(Snake *snake, Direction new_direction);
bool move_snake(Snake *snake);
void destroy_snake(Snake *snake);
void draw_snake(SDL_Renderer *renderer, Snake *snake);
void extend_snake(Snake *snake);
Snake init_snake(int initial_size, int init_x_position, int init_y_position, Direction initial_direction);

#endif