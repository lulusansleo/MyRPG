/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** initiate_npc
*/

#include "player.h"
#include "npc.h"

entity_t *init_entity_npc(int x, int y, int type)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = (sfVector2f){(float) x, (float) y};
    entity->hp = 100;
    entity->type = type;
    entity->move = (sfVector2f){0, 0};
    entity->speed = 0.5f;
    entity->rect = (sfIntRect){0, 0, 16, 16};
    entity->texture = sfTexture_createFromFile(TXT_NPC, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setPosition(entity->sprite, entity->pos);

    entity->direction = random_direction();
    entity->mob_direction_timer = 1.0f;
    entity->mob_direction_clock = sfClock_create();

    return entity;
}
