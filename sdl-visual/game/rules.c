#include "rules.h"

int neighbors(bool grid[GRID_HEIGHT][GRID_WIDTH], int y, int x) {
    int n = 0;
    // Top
    if(y > 0 && grid[y-1][x]) { n += 1; }
    // Top Right
    if(y > 0 && x < GRID_WIDTH-1 && grid[y-1][x+1]) { n += 1; }
    // Right
    if(x < GRID_WIDTH-1 && grid[y][x+1]) { n += 1; }
    // Bottom Right
    if(y < GRID_HEIGHT-1 && x < GRID_WIDTH-1 && grid[y+1][x+1]) { n += 1; }
    // Bottom
    if(y < GRID_HEIGHT-1 && grid[y+1][x]) { n += 1; }
    // Bottom Left
    if(y < GRID_HEIGHT-1 && x > 0 && grid[y+1][x-1]) { n += 1; }
    // Left
    if(x > 0 && grid[y][x-1]) { n += 1; }
    // Top Left
    if(y > 0 && x > 0 && grid[y-1][x-1]) { n += 1; }

    return n;
}

void step_conway(bool grid[GRID_HEIGHT][GRID_WIDTH]) {

    static int new[GRID_HEIGHT][GRID_WIDTH];

    for(int i = 0; i < GRID_HEIGHT; i++) {
        for(int j = 0; j < GRID_WIDTH; j++) {

            int n = neighbors(grid, i, j);
            // If a dead cell has 3 neighbors, it becomes alive
            if(!grid[i][j]) {
                if(n == 3) {
                    new[i][j] = true;
                } else {
                    new[i][j] = false;
                }
            } else {
                // Living cells must have either 2 or 3 neighbors to
                // continue living to the next round.
                if(n == 2 || n == 3) {
                    new[i][j] = true;
                } else {
                    new[i][j] = false;
                }
            }

        }
    }

    // Fill in the grid with new state
    for(int i = 0; i < GRID_HEIGHT; i++) {
        for(int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = new[i][j];
        }
    }
}

void init_grid(bool grid[GRID_HEIGHT][GRID_WIDTH]) {
    for(int i = 0; i < GRID_HEIGHT; i++) {
        for(int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = false;
        }
    }

    grid[5][5] = true;
    grid[6][5] = true;
    grid[7][5] = true;

    grid[5][6] = true;
    grid[6][6] = true;
    grid[7][6] = true;

    grid[5][7] = true;
    grid[6][7] = true;
    grid[7][7] = true;
}