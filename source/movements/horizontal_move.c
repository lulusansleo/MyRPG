/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** horizontal_move
*/

#include "moves.h"

void move_left(PLAYER, LAYER)
{
    player->pos.x -= player->speed;  
    sfSprite_setPosition(player->sprite, player->pos);  
}

void move_right(PLAYER,LAYER)
{
    player->pos.x += player->speed;
    sfSprite_setPosition(player->sprite, player->pos);
}
