#ifndef SNAKE_H
#define SNAKE_H

typedef enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
} Direction;

typedef struct Position
{
    int x;
    int y;
} Position;

typedef struct Snake
{
    Position *positions;
    Direction direction;
} Snake;

bool snake_position_is_valid(Position *pos);
bool move_snake(Snake *snake, Direction direction);
void draw_snake(SDL_Renderer *renderer, Snake *snake);

#endif