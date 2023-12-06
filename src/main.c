#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

#include "grid.h"
#include "parameters.h"
#include "types.h"

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

bool main_loop(SDL_Renderer *renderer)
{

    SDL_Event e;

    SDL_WaitEvent(&e);

    if (e.type == SDL_QUIT)
    {
        return true;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    draw_grid(renderer);
    SDL_RenderPresent(renderer);

    return false;
}

SDL_Window *init_window(void)
{

    SDL_Window *window = SDL_CreateWindow("Snake",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Window could not be created!\n"
               "SDL_Error: %s\n",
               SDL_GetError());
    }

    return window;
}

SDL_Renderer *init_renderer(SDL_Window *window)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        printf("Renderer could not be created!\n"
               "SDL_Error: %s\n",
               SDL_GetError());
    }

    return renderer;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not be initialized!\n"
               "SDL_Error: %s\n",
               SDL_GetError());
        return 0;
    }

    SDL_Window *window = init_window();
    if (!window)
    {
        return 0;
    }

    SDL_Renderer *renderer = init_renderer(window);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        return 0;
    }

    bool quit = false;
    while (!quit)
    {
        quit = main_loop(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}