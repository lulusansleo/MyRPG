/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** check_move
*/

#include "moves.h"

void get_release(PLAYER)
{
    if (sfKeyboard_isKeyPressed(LEFT))
        player->move.x = 0;
    else if (sfKeyboard_isKeyPressed(RIGHT))
        player->move.x = 0;
    if (sfKeyboard_isKeyPressed(UP))
        player->move.y = 0;
    else if (sfKeyboard_isKeyPressed(DOWN))
        player->move.y = 0;
}

void get_move(PLAYER)
{
    if (sfKeyboard_isKeyPressed(LEFT))
        player->move.x = -SPEED;
    if (sfKeyboard_isKeyPressed(RIGHT))
        player->move.x = SPEED;
    if (sfKeyboard_isKeyPressed(UP))
        player->move.y = -SPEED;
    if (sfKeyboard_isKeyPressed(DOWN))
        player->move.y = SPEED;
}

void do_move(PLAYER)
{
    sfTime time;

    time = sfClock_getElapsedTime(player->clock);
    if (sfTime_asSeconds(time) >= 0.01) {
        player->pos.x += player->move.x;
        player->pos.y += player->move.y;
        sfSprite_setPosition(player->sprite, player->pos);
        sfClock_restart(player->clock);
    }
}
