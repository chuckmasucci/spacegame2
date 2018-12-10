#include "render.h"
#include "animate.h"
#include "gfx.h"
#include "sprite.h"
#include <dbg.h>
#include <list.h>

Node** renderers[3];
Node* render_top = NULL;
Node* render_middle = NULL;
Node* render_bottom = NULL;

void animate_sprite_frames(Sprite* sprite);

void initialize_renderers()
{
    renderers[LAYER_TOP] = &render_top;
    renderers[LAYER_MIDDLE] = &render_middle;
    renderers[LAYER_BOTTOM] = &render_bottom;
}

void add_to_render(Sprite* sprite, int z_index)
{
    Node** queue = renderers[z_index];
    check(sprite != NULL, "Null sprite added to render queue");
    check(queue != NULL, "Null queue from array");
    List_push(queue, sprite);

error:
    return;
}

void render()
{
    Node* queue = *renderers[0];
    Node* current_item = queue;
    Sprite* render_sprite;
    SDL_Texture* sprite_texture;
    int queue_amt = List_count(queue);
    int flip_texture = 0;
    clear();
    for (int i = 0; i < queue_amt; i++) {
        render_sprite = (Sprite*)current_item->data;

        if (render_sprite) {
            if (render_sprite->frames) {
                animate_sprite_frames(render_sprite);
            }
            set_texture(render_sprite->texture, render_sprite->mask, render_sprite->size, flip_texture);

            if (current_item->next != NULL) {
                current_item = current_item->next;
            } else {
                current_item = queue;
            }
        }
    }
    present();
}

void animate_sprite_frames(Sprite* sprite)
{
    SDL_Rect* mask = (SDL_RectEmpty(sprite->mask)) ? NULL : sprite->mask;
    int frame = (SDL_GetTicks() / SPRITE_FRAME_DELAY) % sprite->frames;
    mask->y = frame * mask->h;
}

void destroy_renderers()
{
    Node* queue = *renderers[0];
    Node* current_item = queue;
    int queue_amt = List_count(queue);
    for (int i = 0; i < queue_amt; i++) {
        if (current_item != NULL) {
            destroy_sprite(current_item->data);
        }
        if (current_item->next != NULL) {
            current_item = current_item->next;
        } else {
            break;
        }
    }
    List_cleanup(&queue);
}
