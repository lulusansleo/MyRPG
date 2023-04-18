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

void push_back(PLAYER, LAYER)
{
    int x = (int) player->pos.x / 16;
    int y = (int) player->pos.y / 16;
    if (player->move.x > 0.0) {
        if (layer[0].tiles[y][x + 1].type != 0 ||
        layer[0].tiles[y][x + 1].type != 0)
            player->pos.x -= player->move.x;
    }
}