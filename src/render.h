#ifndef render_h
#define render_h

#include "sprite.h"

#define LAYER_TOP 0
#define LAYER_MIDDLE 1
#define LAYER_BOTTOM 2

void initialize_renderers();
void add_to_render(Sprite* sprite, int z_index);
void render();
void destroy_renderers();

#endif
