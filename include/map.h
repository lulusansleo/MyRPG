/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map include
*/

#ifndef MAP_H
    #define MAP_H

    #include "graphical.h"
    #include <stdlib.h>

typedef struct tile_s {
    int type;
    int properties;
} tile_t;

typedef struct tilesheet_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} tilesheet_t;

typedef struct layer_sprites {
    tilesheet_t *wallset;
    tilesheet_t *groundset;
    tilesheet_t *objectset;
} layer_sprites_t;

void draw_layer(tile_t **layer, tilesheet_t *tileset, sfRenderWindow *window);
tile_t **initialise_map(char **buffer);
tilesheet_t *initialise_tileset(char *path);

#endif /* !MAP_H */
