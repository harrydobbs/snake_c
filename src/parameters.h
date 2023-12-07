#include <SDL.h>

#ifndef PARAMETERS_H
#define PARAMETERS_H

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

#define GRID_WIDTH 1000
#define GRID_HEIGHT 1000
#define GRID_CELL_SIZE 5

#define NUM_VERTICAL_CELLS GRID_HEIGHT / GRID_CELL_SIZE
#define NUM_HORIZONTAL_CELLS GRID_WIDTH / GRID_CELL_SIZE

#define UPDATE_INTERVAL 50

extern SDL_Color grid_background;
extern SDL_Color grid_line_color;
extern SDL_Color grid_cursor_ghost_color;
extern SDL_Color grid_cursor_color;
extern SDL_Color snake_color;
extern SDL_Color snake_line_color;

#endif // PARAMETERS_H
