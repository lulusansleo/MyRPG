/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** initiate_npc
*/

#include "player.h"
#include "npc.h"

sfVector2f spawn_mob(layer_t layer)
{
    sfVector2f pos = random_position(MAX_X, MAX_Y);
    int x;
    int y;
    int good = 0;

    while (good != 1) {
        x = (int)(pos.x / 16);
        y = (int)(pos.y / 16);
        if (layer.tiles[y][x].type != 0) {
            good = 1;
        }
        pos = random_position(MAX_X, MAX_Y);
    }
    return pos;
}

entity_t *init_entity_npc(int x, int y, int type)
{
    sfVector2f pos = {(float) x, (float) y};
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = pos;
    entity->speed = 15;
    entity->clock = sfClock_create();
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