/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** horizontal_move
*/

#include "moves.h"

void move_left(PLAYER, LAYER)
{
    float limit;
    if ((limit = coll_left(layer, player)) != 0.0) {
        if ((player->pos.x - SPEED) <= limit) {
            player->pos.x = SPEED - limit + 16;
        }
    } else {
        player->pos.x -= SPEED;
    }
}

void move_right(PLAYER,LAYER)
{
    float limit;
    if ((limit = coll_right(layer, player)) != 0.0) {
        if ((player->pos.x + SPEED) >= limit)
            player->pos.x = SPEED + limit - 16;
    } else {
        player->pos.x += SPEED;
    }
}
