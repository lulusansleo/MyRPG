/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** interact
*/

#include "player.h"
#include "gamestate.h"
#include "map.h"
#include "npc.h"
#include "event.h"
#include <math.h>

static sfVector2i get_closest_tile(entity_t *player)
{
    sfVector2i pos = {0, 0};

    pos.x = (player->pos.x + 8) / 16;
    pos.y = (player->pos.y + 8) / 16;
    return (pos);
}

static void manage_door_events(entity_t *player, layer_t *layers, gamestate_t *gamestate)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[3].tiles[pos.y][pos.x].type;

    if (type == 29) {
        layers[3].tiles[pos.y][pos.x].type = 31;
        open_close_door(layers, pos);
    }
    if (type == 31) {
        layers[3].tiles[pos.y][pos.x].type = 29;
        open_close_door(layers, pos);
    }
}

layer_t *interact(entity_t *player, layer_t *layers, gamestate_t *gamestate)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[3].tiles[pos.y][pos.x].type;

    if (type == 20 || type == 33) {
        gamestate->floor += 1;
        layers = reload_level(layers, gamestate->level, gamestate->floor);
        return (layers);
    }
    if (type == 19 || type == 32) {
        gamestate->floor -= 1;
        layers = reload_level(layers, gamestate->level, gamestate->floor);
        return (layers);
    }
    manage_door_events(player, layers, gamestate);
    return (layers);
}
