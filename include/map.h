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
    sfVector2i size;
} layer_t;

tilesheet_t *initialise_tileset(char *path);
layer_t *initialise_layer(int level, int floor);
char *get_level_path(char *level, char *floor, int type);
char *get_level_path(char *level, char *floor, int type);

/* get_size .c */
sfVector2i get_size_map(layer_t layer);

/* reload level */
layer_t *reload_level(layer_t *layer, int level, int floor);

#endif /* !MAP_H */
