/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** draw_npc
*/

#include "player.h"

void draw_mobs(entity_t **mobs, sfRenderWindow *window)
{
    for (int i = 0; i < NUM_MOBS; i++) {
        sfRenderWindow_drawSprite(window, mobs[i]->sprite, NULL);
    }
}

void free_mobs(entity_t **mobs)
{
    for (int i = 0; i < NUM_MOBS; i++) {
        sfTexture_destroy(mobs[i]->texture);
        sfSprite_destroy(mobs[i]->sprite);
        sfClock_destroy(mobs[i]->clock);
        free(mobs[i]);
    }
    free (mobs);
}
