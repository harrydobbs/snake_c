#include <SDL.h>

#ifndef PARAMETERS_H
#define PARAMETERS_H

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define GRID_WIDTH 800
#define GRID_HEIGHT 800
#define GRID_CELL_SIZE 10

#define NUM_VERTICAL_CELLS GRID_HEIGHT / GRID_CELL_SIZE
#define NUM_HORIZONTAL_CELLS GRID_WIDTH / GRID_CELL_SIZE

#define GRID_WIDTH_OFFSET (SCREEN_WIDTH / 2) - (GRID_WIDTH / 2)
#define GRID_HEIGHT_OFFSET (SCREEN_HEIGHT / 2) - (GRID_HEIGHT / 2)

#define UPDATE_INTERVAL 50

#define INIT_SNAKE_LENGTH 10

extern SDL_Color grid_background;
extern SDL_Color grid_line_color;
extern SDL_Color grid_cursor_ghost_color;
extern SDL_Color grid_cursor_color;
extern SDL_Color snake_color;
extern SDL_Color snake_line_color;
extern SDL_Color snake_head_color;
extern SDL_Color food_color;

#endif // PARAMETERS_H
