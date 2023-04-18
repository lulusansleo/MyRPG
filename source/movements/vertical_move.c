/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** vertical_move
*/

#include "moves.h"

void move_up(PLAYER, LAYER)
{
    player->pos.y -= player->speed;
    sfSprite_setPosition(player->sprite, player->pos);
}

void move_down(PLAYER, LAYER)
{
    player->pos.y += player->speed;
    sfSprite_setPosition(player->sprite, player->pos);
}