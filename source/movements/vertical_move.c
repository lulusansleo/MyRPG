/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** vertical_move
*/

#include "moves.h"

void move_up(PLAYER, LAYER)
{
    float limit;
    if ((limit = coll_up(layer, player)) != 0.0) {
        if ((player->pos.y - SPEED) <= limit + 16) {
            player->pos.y = SPEED - limit + 16;
        }
    } else {
        player->pos.y -= SPEED;
    }
    sfSprite_setPosition(player->sprite, player->pos);  
}

void move_down(PLAYER, LAYER)
{
    float limit;
    if ((limit = coll_down(layer, player)) != 0.0) {
        if ((player->pos.y + SPEED) <= limit) {
            player->pos.y = SPEED + limit - 16;
        }
    } else {
        player->pos.y += SPEED;
    }
    sfSprite_setPosition(player->sprite, player->pos);  
}
