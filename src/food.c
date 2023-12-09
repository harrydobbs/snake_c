#include <stdio.h>
#include <stdbool.h>

#include "parameters.h"
#include "snake.h"
#include "food.h"

void generate_food(Snake *snake, Food *food)
{
    bool validPosition = false;
    while (!validPosition)
    {
        int x = rand() % NUM_HORIZONTAL_CELLS;
        int y = rand() % NUM_VERTICAL_CELLS;

        if (!is_snake_on_position(snake, x, y))
        {
            validPosition = true;
            food->pos.x = x;
            food->pos.y = y;
            food->active = true;
            printf("%i %i", x, y);
        }
    }
}

bool is_snake_on_position(Snake *snake, int x, int y)
{
    if (snake == NULL)
    {
        return false;
    }

    for (int i = 0; i < snake->length; ++i)
    {
        if (snake->body[i].x == x &&
            snake->body[i].y == y)
        {
            return true;
        }
    }

    return false;
}

void draw_food(SDL_Renderer *renderer, Food *food)
{

    SDL_SetRenderDrawColor(renderer,
                           food_color.r, food_color.g,
                           food_color.b, food_color.a);

    SDL_Rect rect;
    rect.x = GRID_WIDTH_OFFSET + food->pos.x * GRID_CELL_SIZE;
    rect.y = GRID_HEIGHT_OFFSET + food->pos.y * GRID_CELL_SIZE;
    rect.w = GRID_CELL_SIZE;
    rect.h = GRID_CELL_SIZE;
    SDL_RenderFillRect(renderer, &rect);
};
