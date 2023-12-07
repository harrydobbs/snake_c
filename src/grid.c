#include <SDL.h>

#include "parameters.h"

void draw_grid(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                           grid_background.b, grid_background.a);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
                           grid_line_color.b, grid_line_color.a);

    int grid_start_X = (SCREEN_WIDTH / 2) - (GRID_WIDTH / 2);
    int grid_start_Y = (SCREEN_HEIGHT / 2) - (GRID_HEIGHT / 2);

    for (int x = grid_start_X; x < GRID_WIDTH + grid_start_X + 1;
         x += GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(renderer, x, grid_start_Y, x, grid_start_Y + GRID_HEIGHT);
    }

    for (int y = grid_start_Y; y < GRID_HEIGHT + grid_start_Y + 1;
         y += GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(renderer, grid_start_X, y, grid_start_X + GRID_WIDTH, y);
    }
}