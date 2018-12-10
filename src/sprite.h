#ifndef sprite_h
#define sprite_h

#include <SDL2/SDL.h>
#include <list.h>

#define ALPHA_MIN 0
#define ALPHA_MAX 255

typedef struct Sprite {
    int alpha;
    int flags;
    int frames;
    int visible;
    char* id;
    char* path;
    SDL_Rect* mask;
    SDL_Rect* size;
    SDL_Texture* texture;
    Node* animations;
} Sprite;

Sprite* create_sprite(char* id, char* path, int frames, SDL_Rect* size, SDL_Rect* mask);
void position_sprite(Sprite* sprite, int x, int y);
void destroy_sprite(Sprite* sprite);

#endif
