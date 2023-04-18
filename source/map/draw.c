/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map display
*/

#include "map.h"

static sfIntRect get_tile_rect(int type)
{
    sfIntRect rect = {0, 0, 16, 16};

    type -= 1;
    rect.left = (type % 18) * 16;
    rect.top = (type / 18) * 16;
    return (rect);
}

void draw_layer(tile_t **layer, tilesheet_t *tileset, sfRenderWindow *window)
{
    for (int i = 0; layer[i]; i++) {
        for (int j = 0; layer[i][j].type != -1; j++) {
            tileset->rect = get_tile_rect(layer[i][j].type);
            sfSprite_setPosition(tileset->sprite, (sfVector2f){j * 16, i * 16});
            sfSprite_setTextureRect(tileset->sprite, tileset->rect);
            if (layer[i][j].type != 0)
                sfRenderWindow_drawSprite(window, tileset->sprite, NULL);
        }
    }
}
