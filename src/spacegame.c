#include "enemy.h"
#include "gfx.h"
#include "player.h"
#include "render.h"
#include <dbg.h>
#include <list.h>
#include <stdio.h>

int main()
{
    initialize_gfx();
    initialize_renderers();

    initialize_player();
    initialize_enemies();

    position_player_game();

    int is_left_key_down = 0;
    int is_right_key_down = 0;
    int move_direction = 0;

    int running = 1;

    while (running) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_h:
                case SDLK_LEFT:
                    is_left_key_down = 1;
                    move_direction = -1;
                    break;
                case SDLK_l:
                case SDLK_RIGHT:
                    is_right_key_down = 1;
                    move_direction = 1;
                    break;
                case SDLK_ESCAPE:
                    running = 0;
                    break;
                case SDLK_SPACE:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                case SDLK_h:
                case SDLK_LEFT:
                    is_left_key_down = 0;
                    break;
                case SDLK_l:
                case SDLK_RIGHT:
                    is_right_key_down = 0;
                    break;
                }
                break;
            }

            if (event.type == SDL_QUIT) {
                break;
            }
        }

        render();
    }

    destroy_gfx();
    destroy_renderers();
    return 0;
}
