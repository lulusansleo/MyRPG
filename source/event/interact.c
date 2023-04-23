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

static layer_t *manage_floor_events(entity_t *player,
layer_t *layers, gamestate_t *gamestate, npc_t **npc)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[3].tiles[pos.y][pos.x].type;
    char fl[2]= "0";
    char lv[2]= "0";

    fl[0] += gamestate->floor;
    lv[0] += gamestate->level;
    if (type == 20 || type == 33) {
        gamestate->floor += 1;
        layers = reload_level(layers, gamestate->level, gamestate->floor);
        free_mobs(*npc);
        (*npc) = load_mobs_from_file(get_level_path(lv, fl, 6));
        return (layers);
    }
    if (type == 19 || type == 32) {
        gamestate->floor -= 1;
        layers = reload_level(layers, gamestate->level, gamestate->floor);
        free_mobs(*npc);
        (*npc) = load_mobs_from_file(get_level_path(lv, fl, 6));
        return (layers);
    }
    return (layers);
}

static void manage_door_events(entity_t *player, layer_t *layers)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[3].tiles[pos.y][pos.x].type;
    sfVector2i closest_door = find_adjacent_door(layers, pos);

    if (type == 29) {
        layers[3].tiles[pos.y][pos.x].type = 31;
        open_close_door(layers, pos);
    }
    if (type == 31) {
        layers[3].tiles[pos.y][pos.x].type = 29;
        open_close_door(layers, pos);
    }
    if ((closest_door.x != pos.x || closest_door.y != pos.y)) {
        if (is_locked_door(layers[3].tiles[closest_door.y]
        [closest_door.x].type) && player->silver_key > 0) {
            unlock_door(layers, closest_door);
            player->silver_key -= 1;
        }
    }
}

static void manage_item_events(entity_t *player, layer_t *layers)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[4].tiles[pos.y][pos.x].type;

    if (type == 15) {
        player->silver_key += 1;
        layers[4].tiles[pos.y][pos.x].type = 0;
    }
    if (type == 16) {
        player->gold_key += 1;
        layers[4].tiles[pos.y][pos.x].type = 0;
    }
}

layer_t *interact(entity_t *player, layer_t *layers,
gamestate_t *gamestate, npc_t **npc)
{
    layers = manage_floor_events(player, layers, gamestate, npc);
    manage_door_events(player, layers);
    manage_item_events(player, layers);
    return (layers);
}
