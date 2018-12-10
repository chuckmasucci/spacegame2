#ifndef gfx_h
#define gfx_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

SDL_Window* window;
SDL_Renderer* renderer;

int initialize_gfx();
SDL_Texture* create_sprite_texture(char* imgPath, int alpha);
int set_texture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect, int flip);
SDL_Rect* get_size_rect(int w, int h, int x, int y);
int clear();
void present();
void destroy_gfx();

#endif
