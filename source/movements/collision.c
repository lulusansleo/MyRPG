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

int push_back(PLAYER, LAYER)
{
    int is_collide = 0;
    int x = (int) player->pos.x / 16;
    int y = (int) player->pos.y / 16;
    if (player->move.x > 0.0) {
        if ((layer[0].tiles[y][x + 1].type != 0 ||
        layer[0].tiles[y + 1][x + 1].type != 0)
        && player->pos.x + 16.0 > (float) x * 16.0 + 16.0) {
            player->pos.x = x * 16.0;
            return (1);
        }
    }
    if (player->move.x < 0.0) {
        if ((layer[0].tiles[y][x].type != 0 ||
        layer[0].tiles[y + 1][x].type != 0)
        && player->pos.x < (float) x * 16.0 + 16.0) {
            player->pos.x = x * 16.0 + 16.0;
            return (1);
        }
    }
    if (player->move.y > 0.0) {
        if ((layer[0].tiles[y + 1][x].type != 0 ||
        layer[0].tiles[y + 1][x + 1].type != 0)
        && player->pos.y + 16.0 > (float) y * 16.0 + 16.0) {
            player->pos.y = y * 16.0;
            return (1);
        }
    }
    if (player->move.y < 0.0) {
        if ((layer[0].tiles[y][x].type != 0 ||
        layer[0].tiles[y][x + 1].type != 0)
        && player->pos.y < (float) y * 16.0 + 16.0) {
            player->pos.y = y * 16.0 + 16.0;
            return (1);
        }
    }
    return (0);
}
