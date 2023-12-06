#include <SDL.h>

#include "parameters.h"

void draw_grid(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                           grid_background.b, grid_background.a);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
                           grid_line_color.b, grid_line_color.a);

    int grid_start_X = (SCREEN_WIDTH - GRID_WIDTH) / 2 + (SCREEN_WIDTH / 2);
    int grid_start_Y = (SCREEN_HEIGHT - GRID_HEIGHT) / 2 + (SCREEN_HEIGHT / 2);

    for (int x = grid_start_X; x < 1 + GRID_WIDTH;
         x += GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(renderer, x, 0, x, GRID_HEIGHT);
    }

    for (int y = grid_start_Y; y < 1 + GRID_HEIGHT;
         y += GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(renderer, 0, y, GRID_WIDTH, y);
    }
}