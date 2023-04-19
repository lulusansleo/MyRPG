/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** init_npc
*/

#include "player.h"

int random_direction(void)
{
    int direction = rand() % 4;
    return direction;
}

sfVector2f random_position(float maxX, float maxY)
{
    float x = (float)(rand() % (int)maxX);
    float y = (float)(rand() % (int)maxY);
    return (sfVector2f){x, y};
}

void update_npc_position(entity_t *entity, int direction, float time)
{

    switch (direction) {
        case 0:
            entity->pos.y -= entity->speed;
            break;
        case 1:
            entity->pos.y += entity->speed;
            break;
        case 2:
            entity->pos.x -= entity->speed;
            break;
        case 3:
            entity->pos.x += entity->speed;
    }
    if (time >= 1) {
        sfSprite_setPosition(entity->sprite, entity->pos);
        sfClock_restart(entity->clock);
    }

}

