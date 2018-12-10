#ifndef enemy_h
#define enemy_h

#define ENEMY_SPRITE "gfx/sprites/enemy.proto1.png"
#define ENEMY_WIDTH 74
#define ENEMY_HEIGHT 95
#define ENEMY_COUNT 8
#define ENEMY_COLUMNS 4 // Columns should not be higher than enemy count
#define ENEMY_ROWS (int)ceil((float)ENEMY_COUNT / (float)ENEMY_COLUMNS)

void initialize_enemies();

#endif
