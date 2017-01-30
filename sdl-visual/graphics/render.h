// Grayson Pike, 2017

#include <stdbool.h>
#include "../main.h"

int light_grid[GRID_HEIGHT][GRID_WIDTH];

void init_render();
void clear_screen();
void update_render_grid(bool grid[GRID_HEIGHT][GRID_HEIGHT]);
void draw_grid(float delta);
