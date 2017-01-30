#include <time.h>
#include <stdlib.h>

#include "patterns.h"

void random_grid(bool grid[GRID_HEIGHT][GRID_WIDTH]) {

    srand(time(NULL));

    for(int i = 0; i < GRID_HEIGHT; i++) {
        for(int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = rand() % 2 == 0;
        }
    }
}