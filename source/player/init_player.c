/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "player.h"

static sfIntRect get_plyr_rect(int type)
{
    switch (type) {
        case HAND:
            return ((sfIntRect) {RECT_HAND});
        case SWORD:
            return ((sfIntRect) {RECT_SWORD});
        case BOW:
            return ((sfIntRect) {RECT_BOW});
        default:
            return ((sfIntRect) {RECT_HAND});
    }
}

static int get_dmg(int type)
{
    if (type == HAND)
        return 2;
    if (type == SWORD)
        return 50;
    if (type == BOW)
        return 5;
    return 2;
}

entity_t *init_entity(void)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = (sfVector2f){48, 48};
    entity->dir = NORTH;
    entity->type = SWORD;
    entity->hp = 100;
    entity->dmg = get_dmg(entity->type);
    entity->speed = 2;
    entity->clock = sfClock_create();
    entity->weapon = NULL;
    entity->mob_direction_clock = sfClock_create();
    entity->rect = get_plyr_rect(entity->type);
    entity->texture = sfTexture_createFromFile(TXT_PLYR, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture
(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect
(entity->sprite, entity->rect);
    sfSprite_setPosition
(entity->sprite, entity->pos);
    return (entity);
}
