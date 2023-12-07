#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

#include "grid.h"
#include "parameters.h"
#include "snake.h"

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void update_events(Snake *snake)
{

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_LEFT])
    {
        update_snake_direction(snake, LEFT);
    }
    else if (keystate[SDL_SCANCODE_RIGHT])
    {
        update_snake_direction(snake, RIGHT);
    }
    else if (keystate[SDL_SCANCODE_UP])
    {
        update_snake_direction(snake, UP);
    }
    else if (keystate[SDL_SCANCODE_DOWN])
    {
        update_snake_direction(snake, DOWN);
    }
}

bool main_loop(SDL_Renderer *renderer, Snake *snake, Uint32 *lastUpdateTime)
{
    SDL_Event e;
    bool quit = false;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }

    update_events(snake);

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - *lastUpdateTime > UPDATE_INTERVAL)
    {
        move_snake(snake);
        *lastUpdateTime = currentTime;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    draw_grid(renderer);
    draw_snake(renderer, snake);
    SDL_RenderPresent(renderer);

    SDL_Delay(10);

    return quit;
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

    // Position snake_pos = {0, 0};
    Snake snake = init_snake(INIT_SNAKE_LENGTH, DOWN); //{&snake_pos, UP};
    Uint32 lastUpdateTime = 0;

    bool quit = false;
    while (!quit)
    {
        quit = main_loop(renderer, &snake, &lastUpdateTime);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}