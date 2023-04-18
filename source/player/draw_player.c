/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** draw_player
*/

#include "player.h"

void draw_player(entity_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}
