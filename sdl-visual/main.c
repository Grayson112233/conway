// Grayson Pike, 2017

#include <stdio.h>
#include "graphics/sdl_boilerplate.h"
#include "graphics/render.h"
#include "graphics/clock.h"
#include "game/rules.h"
#include "game/patterns.h"

// Game grid is stepped forward one cycle every STEP_DELAY seconds
#define STEP_DELAY (0.01f)

float delta;

float time_since_step = 0.0f;

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
    init_grid(game_grid);
    update_render_grid(game_grid);

    random_grid(game_grid);

    bool loop = true;

    while(loop) {

        loop = frame_update();
        clear_screen();

        // Step the grid forward one cycle every STEP_DELAY seconds
        time_since_step += delta;
        while(time_since_step > STEP_DELAY) {
            time_since_step -= STEP_DELAY;
            step_conway(game_grid);
            update_render_grid(game_grid);
        }

        draw_grid(delta);
        SDL_RenderPresent(renderer);

    }

    graphics_quit();

    return 0;
}