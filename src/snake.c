#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

#include "snake.h"
#include "parameters.h"

bool snake_position_is_valid(Position *pos)
{
    return (pos->y < NUM_VERTICAL_CELLS && pos->y >= 0 && pos->x < NUM_HORIZONTAL_CELLS && pos->x >= 0);
}

bool move_snake(Snake *snake)
{

    Position potential_position = *snake->positions;

    switch (snake->direction)
    {
    case UP:
        potential_position.y--;
        break;
    case RIGHT:
        potential_position.x++;
        break;
    case DOWN:
        potential_position.y++;
        break;
    case LEFT:
        potential_position.x--;
        break;
    }

    if (snake_position_is_valid(&potential_position))
    {
        *snake->positions = potential_position;
        return true;
    }
    return false;
}

void draw_snake(SDL_Renderer *renderer, Snake *snake)
{

    SDL_SetRenderDrawColor(renderer,
                           snake_color.r, snake_color.g,
                           snake_color.b, snake_color.a);

    int X = (SCREEN_WIDTH / 2) - (GRID_WIDTH / 2) + snake->positions->x * GRID_CELL_SIZE;
    int Y = (SCREEN_HEIGHT / 2) - (GRID_HEIGHT / 2) + snake->positions->y * GRID_CELL_SIZE;

    SDL_Rect rect;
    rect.x = X;
    rect.y = Y;
    rect.w = GRID_CELL_SIZE;
    rect.h = GRID_CELL_SIZE;

    SDL_RenderFillRect(renderer, &rect);
}

void update_snake_direction(Snake *snake, Direction new_direction)
{
    if ((new_direction == UP && snake->direction != DOWN) ||
        (new_direction == DOWN && snake->direction != UP) ||
        (new_direction == LEFT && snake->direction != RIGHT) ||
        (new_direction == RIGHT && snake->direction != LEFT))
    {
        snake->direction = new_direction;
    }
}

Snake init_snake(void)
{
    Position snake_pos = {0, 0};
    Snake snake = {&snake_pos, RIGHT};

    return snake;
}