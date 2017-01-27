// Grayson Pike, 2017

#include <stdio.h>
#include "graphics/sdl_boilerplate.h"
#include "graphics/render.h"
#include "graphics/clock.h"

float delta;

bool game_grid[GRID_HEIGHT][GRID_WIDTH];

bool frame_update() {

    SDL_Event event;

    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            return false;
        }
        if(event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    return false;
                    break;
                default:
                    break;
            }
        }
    }

    delta = get_delta();

    return true;
}


int main() {

    graphics_init();
    init_clock();
    init_render();

    bool loop = true;

    while(loop) {

        loop = frame_update();
        clear_screen();
        draw_grid(delta);
        SDL_RenderPresent(renderer);

    }

    graphics_quit();

    return 0;
}