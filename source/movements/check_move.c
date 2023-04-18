/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** check_move
*/

#include "moves.h"

void get_move(void)
{
    if (sfKeyboard_isKeyPressed(LEFT))
        move_left(PLAYER, TILESET);
    if (sfKeyboard_isKeyPressed(RIGHT))
        move_right(PLAYER, TILESET);
    if (sfKeyboard_isKeyPressed(UP))
        move_up(PLAYER, TILESET);
    if (sfKeyboard_isKeyPressed(DOWN))
        move_down(PLAYER, TILESET);
}