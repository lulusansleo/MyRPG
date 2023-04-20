/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** mouvement&attack_npc
*/

#include "map.h"
#include "my.h"
#include "player.h"
#include "npc.h"


float distance_npc(sfVector2f abs, sfVector2f ord)
{
    float dx = abs.x - ord.x;
    float dy = abs.y - ord.y;

    return sqrt(dx * dx + dy * dy);
}

void attack_player(entity_t *mob, entity_t *player, float deltaTime)
{
    float angle = atan2(player->pos.y - mob->pos.y, player->pos.x - mob->pos.x);

    mob->pos.x += mob->speed * deltaTime * cos(angle);
    mob->pos.y += mob->speed * deltaTime * sin(angle);

    sfSprite_setPosition(mob->sprite, mob->pos);
}

void npc_move(entity_t *player, npc_t *head)
{
    if (head == NULL)
        return;
    npc_t *tmp = head; 
    while (tmp != NULL) {
        float deltaTime = sfTime_asSeconds(sfClock_getElapsedTime(tmp->mob->clock));
        float mob_distance = distance_npc(player->pos, tmp->mob->pos);

        if (mob_distance < ATTACK_RADIUS) {
            attack_player(tmp->mob, player, deltaTime);
        } else {
            float direction_elapsed = sfTime_asSeconds(sfClock_getElapsedTime(tmp->mob->mob_direction_clock));
            if (direction_elapsed >= tmp->mob->mob_direction_timer) {
                tmp->mob->move = random_position(2.0, 2.0);
                sfClock_restart(tmp->mob->mob_direction_clock);
            }
            update_npc_position(tmp->mob, deltaTime);
        }
        sfClock_restart(tmp->mob->clock);
        tmp = tmp->next;
    }
}