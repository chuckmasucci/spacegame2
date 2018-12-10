#include "player.h"
#include "gfx.h"
#include "render.h"
#include "sprite.h"
#include <dbg.h>

Sprite* player_sprite;
Sprite* create_player_sprite();

void initialize_player()
{
    player_sprite = create_player_sprite();

    if (player_sprite != NULL) {
        add_to_render(player_sprite, LAYER_TOP);
    }
}

Sprite* create_player_sprite()
{
    SDL_Rect* player_rect;
    SDL_Rect* player_mask;

    player_rect = get_size_rect(SHIP_WIDTH, SHIP_HEIGHT, 0, 0);
    player_mask = get_size_rect(SHIP_WIDTH, SHIP_HEIGHT, 0, 0);

    player_sprite = create_sprite("player", SHIP_SPRITE, 4, player_rect, player_mask);

    return player_sprite;

error:
    SDL_Quit();
    log_err("Error while initializing player: Shutdown");
    return NULL;
}

void position_player_test()
{
    position_sprite(player_sprite, 100, 100);
}

void position_player_game()
{
    position_sprite(player_sprite, (WINDOW_WIDTH / 2) - (SHIP_WIDTH / 2), WINDOW_HEIGHT - SHIP_HEIGHT - 20);
}

void move_player(int direction)
{
}
