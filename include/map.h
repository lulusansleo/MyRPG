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
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>

typedef struct tile_s {
    int type;
    int properties;
} tile_t;

typedef struct tilesheet_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} tilesheet_t;

typedef struct layer_s {
    tile_t **tiles;
    tilesheet_t *sprite_sheet;
} layer_t;

void draw_layer(tile_t **layer, tilesheet_t *tileset, sfRenderWindow *window);
tile_t **initialise_map(char *source);
tilesheet_t *initialise_tileset(char *path);
layer_t *initialise_layer(void);

#endif /* !MAP_H */
