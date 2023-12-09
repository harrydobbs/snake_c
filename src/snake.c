#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "snake.h"
#include "parameters.h"

Snake init_snake(int initial_size, Direction inital_direction)
{
    Position *body = malloc(initial_size * sizeof(Position));

    Snake snake = {body, initial_size, inital_direction};

    for (int i = 0; i < initial_size; ++i)
    {
        body[i] = (Position){0, i};
    }
    return snake;
}

void destroy_snake(Snake *snake)
{
    if (snake != NULL)
    {
        free(snake->body);
        snake->body = NULL;
    }
}

void extend_snake(Snake *snake)
{
    snake->length++;
    snake->body = realloc(snake->body, snake->length * sizeof(Position));
    snake->body[snake->length - 1] = snake->body[snake->length - 2];
}

bool is_position_inside_grid(Position pos)
{
    return (pos.y < NUM_VERTICAL_CELLS && pos.y >= 0 &&
            pos.x < NUM_HORIZONTAL_CELLS && pos.x >= 0);
}

bool is_snake_self_intersecting(Snake *snake, Position potential_position)
{
    for (int i = 2; i < snake->length; i++)
    {
        if (snake->body[i].x == potential_position.x &&
            snake->body[i].y == potential_position.y)
        {
            printf("Collision body: (%i, %i), head: (%i, %i)", snake->body[i].x,
                   snake->body[i].y, potential_position.x, potential_position.y);
            return true;
        }
    }
    return false;
}

bool move_snake(Snake *snake)
{

    Position potential_position = snake->body[0];

    switch (snake->dir)
    {
    case UP:
        potential_position.y--;
        break;
    case DOWN:
        potential_position.y++;
        break;
    case LEFT:
        potential_position.x--;
        break;
    case RIGHT:
        potential_position.x++;
        break;
    }

    if (!is_position_inside_grid(potential_position))
    {
        return false;
    }

    if (is_snake_self_intersecting(snake, potential_position))
    {
        return false;
    }

    for (int i = snake->length - 1; i > 0; i--)
    {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = potential_position;

    return true;
}

void update_snake_direction(Snake *snake, Direction new_direction)
{
    if ((new_direction == UP && snake->dir != DOWN) ||
        (new_direction == DOWN && snake->dir != UP) ||
        (new_direction == LEFT && snake->dir != RIGHT) ||
        (new_direction == RIGHT && snake->dir != LEFT))
    {
        snake->dir = new_direction;
    }
}

void draw_snake(SDL_Renderer *renderer, Snake *snake)
{

    SDL_SetRenderDrawColor(renderer,
                           snake_head_color.r, snake_head_color.g,
                           snake_head_color.b, snake_head_color.a);

    SDL_Rect rect;
    rect.x = GRID_WIDTH_OFFSET + snake->body[0].x * GRID_CELL_SIZE;
    rect.y = GRID_HEIGHT_OFFSET + snake->body[0].y * GRID_CELL_SIZE;
    rect.w = GRID_CELL_SIZE;
    rect.h = GRID_CELL_SIZE;
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer,
                           snake_color.r, snake_color.g,
                           snake_color.b, snake_color.a);

    for (int i = 1; i < snake->length; i++)
    {

        SDL_Rect rect;
        rect.x = GRID_WIDTH_OFFSET + snake->body[i].x * GRID_CELL_SIZE;
        rect.y = GRID_HEIGHT_OFFSET + snake->body[i].y * GRID_CELL_SIZE;
        rect.w = GRID_CELL_SIZE;
        rect.h = GRID_CELL_SIZE;
        SDL_RenderFillRect(renderer, &rect);
    }
}