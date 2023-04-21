/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** door
*/

#include "map.h"
#include "gamestate.h"

static int is_a_door(int type)
{
    if (type <= 14 && type >= 1) {
        return (1);
    }
    return (0);
}

static sfVector2i find_closest_door(layer_t *layers, sfVector2i pos)
{
    if (is_a_door(layers[3].tiles[pos.y - 1][pos.x - 1].type) == 1) {
        pos.y -= 1;
        pos.x -= 1;
        return (pos);
    }
    if (is_a_door(layers[3].tiles[pos.y + 1][pos.x + 1].type) == 1) {
        pos.y += 1;
        pos.x += 1;
        return (pos);
    }
    if (is_a_door(layers[3].tiles[pos.y + 1][pos.x - 1].type) == 1) {
        pos.y += 1;
        pos.x -= 1;
        return (pos);
    }
    if (is_a_door(layers[3].tiles[pos.y - 1][pos.x + 1].type) == 1) {
        pos.y -= 1;
        pos.x += 1;
        return (pos);
    }
    return (pos);
}

void open_door(layer_t *layers, sfVector2i pos)
{
    sfVector2i closest_door = find_closest_door(layers, pos);
    layers[3].tiles[closest_door.y][closest_door.x].type += 1;
    layers[0].tiles[closest_door.y][closest_door.x].type = 0;
}

void close_door(layer_t *layers, sfVector2i pos)
{
    sfVector2i closest_door = find_closest_door(layers, pos);
    layers[3].tiles[closest_door.y][closest_door.x].type -= 1;
    layers[0].tiles[closest_door.y][closest_door.x].type = 108;
}
