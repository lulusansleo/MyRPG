/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** draw_npc
*/

#include "player.h"

void draw_npc(entity_t *npc, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, npc->sprite, NULL);
}
