// Grayson Pike, 2017

#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include "render.h"
#include "sdl_boilerplate.h"

// Intensity of cells are reduced by 1 every DELAY seconds
// (Lower value = less burn-in)
#define DELAY 0.01f

float time_since_decay = 0.0f;

void init_render() {
    // Set light grid to all 0's
    for(int i = 0; i < GRID_HEIGHT; i++) {
        for(int j = 0; j < GRID_WIDTH; j++) {
            light_grid[i][j] = 0;
        }
    }
    light_grid[99][99] = 255;
}

void clear_screen() {
    // Clear the screen with a white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void set_grid(bool game_grid[GRID_HEIGHT][GRID_WIDTH]) {
    for(int i = 0; i < GRID_HEIGHT; i++) {
        for(int j = 0; j < GRID_WIDTH; j++) {
            if(game_grid[i][j]) {
                light_grid[i][j] = 255;
            }
        }
    }
}

void draw_grid(float delta) {

    // Reduce intensity of already lit cells by 1 every DELAY seconds
    time_since_decay += delta;
    while(time_since_decay > DELAY) {
        time_since_decay -= DELAY;
        for(int i = 0; i < GRID_HEIGHT; i++) {
            for(int j = 0; j < GRID_WIDTH; j++) {
                if(light_grid[i][j] > 0) {
                    light_grid[i][j] -= 1;
                }
            }
        }
    }

    int width = WIDTH / GRID_WIDTH;
    int height = HEIGHT / GRID_HEIGHT;

    // SDL_Rect object to draw grid squares with
    SDL_Rect rect = {
        0,
        0,
        width,
        height
    };

    int intensity = 0;
    
    for(int i = 0; i < GRID_HEIGHT; i++) {
        rect.y = i * height;
        for(int j = 0; j < GRID_WIDTH; j++) {
            intensity = 255 - light_grid[i][j];
            rect.x = j * width;
            if(intensity == 0) {
                //printf("Drawing black at %d, %d\n", rect.x, rect.y);
            }
            SDL_SetRenderDrawColor(renderer, intensity, intensity, intensity, 0xFF);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}