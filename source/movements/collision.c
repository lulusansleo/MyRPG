/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "map.h"
#include "player.h"
#include "graphical.h"
#include "moves.h"

float coll_right(LAYER, entity_t *entity)
{ 
    sfVector2i vec = {((int) entity->pos.x) / 16, ((int) entity->pos.y) / 16};
    if (layer[0].tiles[vec.y][vec.x].type != 0) {
        return (float)((vec.x + 1) * 16);
    }
    if (layer[0].tiles[vec.y + 1][vec.x + 1].type != 0) {
        return (float)((vec.x + 1) * 16);
    }

    return 0.0;
}

float coll_left(layer_t *layer, entity_t *entity)
{ 
    sfVector2i vec = {((int) entity->pos.x) / 16, ((int) entity->pos.y) / 16};
    if (layer[0].tiles[vec.y][vec.x - 1].type != 0)
        return (float)(vec.x) * 16;
    if (layer[0].tiles[vec.y + 1][vec.x - 1].type != 0)
        return (float)((vec.x) * 16);
    return 0.0;
}

float coll_up(layer_t *layer, entity_t *entity)
{ 
    sfVector2i vec = {((int) entity->pos.x) / 16, ((int) entity->pos.y) / 16};

    if (vec.y < 1)
        return 16.0;
    if (layer[0].tiles[vec.y - 1][vec.x].type != 0)
        return (float)(vec.y) * 16;
    if (layer[0].tiles[vec.y - 1][vec.x + 1].type != 0)
        return (float)((vec.y) * 16);
    return 0.0;
}

float coll_down(layer_t *layer, entity_t *entity)
{ 
    sfVector2i vec = {((int) entity->pos.x) / 16, ((int) entity->pos.y) / 16};
    if (layer[0].tiles[vec.y + 1][vec.x].type != 0)
        return (float)(vec.y + 1) * 16;
    if (layer[0].tiles[vec.y + 1][vec.x + 1].type != 0)
        return (float)((vec.y + 1) * 16);
    return 0.0;
}
