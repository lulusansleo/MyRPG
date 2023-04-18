/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#define TXT_PLYR "./map-hero.png"

#include "player.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    player->pos = (sfVector2f){50, 50};
    player->speed = 8;
    player->clock = sfClock_create();
    player->rect = (sfIntRect){0, 0, 16, 16};
    player->texture = sfTexture_createFromFile(TXT_PLYR, NULL);
    player->sprite =sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    return(player);
}