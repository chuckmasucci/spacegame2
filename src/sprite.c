#include "sprite.h"
#include "gfx.h"
#include <dbg.h>

Sprite* create_sprite(char* id, char* path, int frames, SDL_Rect* size, SDL_Rect* mask)
{
    Sprite* sprite = malloc(sizeof(Sprite));
    check_mem(sprite);
    sprite->alpha = ALPHA_MIN;
    sprite->animations = NULL;
    sprite->frames = frames;
    sprite->id = id;
    sprite->mask = mask;
    sprite->path = path;
    sprite->size = size;
    sprite->texture = create_sprite_texture(path, ALPHA_MAX);

    return sprite;

error:
    log_err("Sprite create failed");
    return NULL;
}

void position_sprite(Sprite* sprite, int x, int y)
{
    sprite->size->x = x;
    sprite->size->y = y;
}

void destroy_sprite(Sprite* sprite)
{
    free(sprite->mask);
    free(sprite->size);
    free(sprite);
}
