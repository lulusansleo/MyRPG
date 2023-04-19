/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "player.h"

entity_t *init_entity(char *path)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = (sfVector2f){50, 50};
    entity->speed = 8;
    entity->clock = sfClock_create();
    entity->rect = (sfIntRect){0, 0, 16, 16};
    entity->texture =
    sfTexture_createFromFile(TXT_PLYR, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture
(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect
(entity->sprite, entity->rect);
    sfSprite_setPosition
(entity->sprite, entity->pos);
    return (entity);
}
