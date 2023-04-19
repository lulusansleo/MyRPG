/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** initiate_npc
*/

#include "player.h"
#include "npc.h"

entity_t **init_mobs(int nb_mob, layer_t layer)
{
    entity_t **mobs = malloc(sizeof(entity_t *) * nb_mob);
    for (int i = 0; i < nb_mob; i++) 
        mobs[i] = init_entity_npc(layer);
    return mobs;
}

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

entity_t *init_entity_npc(layer_t layer)
{

    sfVector2f pos = spawn_mob(layer);
    pos.x = (pos.x <= 0 ? 1 : pos.x);
    pos.y = (pos.y <= 0 ? 1 : pos.y);
    srand(time(NULL));

    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = pos;
    entity->speed = 20;
    entity->clock = sfClock_create();
    entity->rect = (sfIntRect){0, 0, 16, 16};
    entity->texture = sfTexture_createFromFile(TXT_NPC, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setPosition(entity->sprite, entity->pos);

    int direction = random_direction();
    update_npc_position(entity, direction);

    return (entity);
}