#include "gfx.h"
#include <dbg.h>

int initialize_gfx()
{
    int init = SDL_Init(SDL_INIT_VIDEO);
    check(init >= 0, "Could not initialize SDL: %s", SDL_GetError());

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    check(window != NULL, "Could not create window: %s", SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    check(renderer != NULL, "Could not create renderer: %s", SDL_GetError());

    return 0;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");
    return -1;
}

int clear()
{
    int render_clear = SDL_RenderClear(renderer);
    check(render_clear == 0, "Could not set texture: %s", SDL_GetError());

    return 0;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return -1;
}

SDL_Texture* create_sprite_texture(char* imgPath, int alpha)
{
    SDL_Surface* sprite_surface = IMG_Load(imgPath);
    check(sprite_surface, "Could not load image: %s, error = %s", imgPath, SDL_GetError())
        SDL_Texture* sprite_texture
        = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    check(sprite_texture, "Could not create texture: %s", SDL_GetError());
    SDL_SetTextureAlphaMod(sprite_texture, alpha);

    SDL_FreeSurface(sprite_surface);

    return sprite_texture;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return NULL;
}

int set_texture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect, int flip)
{
    int render_copy = (!flip) ? SDL_RenderCopy(renderer, texture, srcRect, destRect) : SDL_RenderCopyEx(renderer, texture, srcRect, destRect, 0, NULL, SDL_FLIP_VERTICAL);
    check(render_copy == 0, "Could not set texture: %s", SDL_GetError());

    return 0;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return -1;
}

void present()
{
    SDL_RenderPresent(renderer);
}

SDL_Rect* get_size_rect(int w, int h, int x, int y)
{
    SDL_Rect* rect;
    rect = malloc(sizeof(SDL_Rect));
    check_mem(rect);

    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;

    return rect;

error:
    log_err("Rect memory error");

    return NULL;
}

void destroy_gfx()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
