/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** check_move
*/

#include "moves.h"

void get_move(PLAYER, LAYER)
{
    if (sfKeyboard_isKeyPressed(LEFT))
        move_left(player, layer);
    if (sfKeyboard_isKeyPressed(RIGHT))
        move_right(player, layer);
    if (sfKeyboard_isKeyPressed(UP))
        move_up(player, layer);
    if (sfKeyboard_isKeyPressed(DOWN))
        move_down(player, layer);
    sfTime time = sfClock_getElapsedTime(player->clock);
    if (sfTime_asMilliseconds(time) >= 1) {
        sfSprite_setPosition(player->sprite, player->pos);
        sfClock_restart(player->clock);
    }
}
