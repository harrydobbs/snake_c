#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define GRID_WIDTH 600
#define GRID_HEIGHT 600

#define GRID_CELL_SIZE 20

// Declare the SDL_Color variables as extern
extern SDL_Color grid_background;
extern SDL_Color grid_line_color;
extern SDL_Color grid_cursor_ghost_color;
extern SDL_Color grid_cursor_color;

#endif // PARAMETERS_H
