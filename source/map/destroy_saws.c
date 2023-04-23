/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** saws destroy
*/

#include "moving_saws.h"

void free_saws(saws_t *saws)
{
    free(saws);
}

void free_saw_draw(saw_draw_t *saw_draw)
{
    sfClock_destroy(saw_draw->clock);
    sfSprite_destroy(saw_draw->saw);
    sfTexture_destroy(saw_draw->texture);
    free(saw_draw);
}
