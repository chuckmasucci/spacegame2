#ifndef player_h
#define player_h

#include <list.h>

#define SHIP_SPRITE "gfx/sprites/ship.proto1.spritesheet.png"
#define SHIP_WIDTH 73
#define SHIP_HEIGHT 122

Node** renderers[3];
void initialize_player();
void position_player_test();
void position_player_game();
void move_player(int direction);

#endif
