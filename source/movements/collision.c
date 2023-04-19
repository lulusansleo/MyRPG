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
#include <math.h>

int push_back(PLAYER, LAYER)
{
    int a = 0;
    int top_x = (int)floor((player->pos.x) / 16.0);
    int top_y = (int)floor((player->pos.y) / 16.0);
    int bot_x = (int)floor((player->pos.x + 16.0) / 16.0);
    int bot_y = (int)floor((player->pos.y + 16.0) / 16.0);
    if (layer[0].tiles[top_y][top_x].type != 0) {
        a += 1;
    }
    if (layer[0].tiles[top_y][bot_x].type != 0) {
        a += 2;
    }
    if (layer[0].tiles[bot_y][top_x].type != 0) {
        a += 4;
    }
    if (layer[0].tiles[bot_y][bot_x].type != 0) {
        a += 8;
    }
    if ((a == 8 || a == 2) && player->pos.x == top_x * 16)
        return (0);
    return (a);
}

static void collision_second_half(PLAYER, int a)
{
    if (a == 9 || a == 13 || a == 4) {
        player->pos.x += PUSH_BACK;
        player->pos.y -= PUSH_BACK;
    }
    if (a == 3)
        player->pos.y += PUSH_BACK;
    if (a == 5)
        player->pos.x += PUSH_BACK;
    if (a == 10)
        player->pos.x -= PUSH_BACK;
    if (a == 12)
        player->pos.y -= PUSH_BACK;

}

void collision(PLAYER, LAYER)
{
    int a = push_back(player, layer);
    if (a == 0)
        return;
    if (a == 1 || a == 6 || a == 7) {
        player->pos.y += PUSH_BACK;
        player->pos.x += PUSH_BACK;
    }
    if (a == 2 || a == 11 || a == 9) {
        player->pos.x -= PUSH_BACK;
        player->pos.y += PUSH_BACK;
    }
    if (a == 6 || a == 8 || a == 14) {
        player->pos.x -= PUSH_BACK;
        player->pos.y -= PUSH_BACK;
    }
    collision_second_half(player, a);
}
