#include "enemy.h"
#include "gfx.h"
#include "render.h"
#include "sprite.h"
#include <dbg.h>

Sprite* enemy_sprite;
Sprite* create_enemy_sprite();
int enemy_count = 0;

void initialize_enemies()
{
    for (int i = 0; i < 4; i++) {
        create_enemy_sprite();

        if (enemy_sprite != NULL) {
            add_to_render(enemy_sprite, LAYER_TOP);
        }
        enemy_count++;
    }
}

Sprite* create_enemy_sprite()
{
    SDL_Rect* enemy_rect;
    SDL_Rect* enemy_mask;

    enemy_rect = get_size_rect(ENEMY_WIDTH, ENEMY_HEIGHT, 0, 0);
    enemy_mask = get_size_rect(ENEMY_WIDTH, ENEMY_HEIGHT, 0, 0);

    char* sprite_name = malloc(10 * sizeof(char));
    sprintf(sprite_name, "enemy%d", enemy_count);

    enemy_sprite = create_sprite(sprite_name, ENEMY_SPRITE, 0, enemy_rect, enemy_mask);

    return enemy_sprite;

error:
    SDL_Quit();
    log_err("Error while initializing player: Shutdown");
    return NULL;
}
