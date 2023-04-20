/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** draw_player
*/

#include "player.h"

static sfIntRect animation(sfIntRect curr, sfIntRect origin)
{
    curr.left += 16;
    if (curr.left >= origin.left + 32)
        curr.left = origin.left;
    return curr;
}

void animate_player(entity_t *player)
{
    sfIntRect rect;
    sfTime time;
    time = sfClock_getElapsedTime(player->mob_direction_clock);
    if (sfTime_asSeconds(time) > 0.5) {
        rect = player->rect;
        if (player->type == HAND) {
            rect = animation(rect, (sfIntRect){RECT_HAND});
    }
    if (player->type == SWORD) {
        rect = animation(rect, (sfIntRect){RECT_SWORD});
    }
    if (player->type == BOW) {
        rect = animation(rect, (sfIntRect){RECT_BOW});
    }
        player->rect = rect;
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->mob_direction_clock);
    }
}

void draw_player(entity_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}
