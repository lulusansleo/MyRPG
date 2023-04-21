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

void attack_player(entity_t *mob, entity_t *player)
{
    float angle = atan2(player->pos.y - mob->pos.y, player->pos.x - mob->pos.x);

    mob->move.x = mob->speed * cos(angle);
    mob->move.y = mob->speed * sin(angle);

}

void npc_move(entity_t *player, npc_t *head)
{
    float mob_distance = distance_npc(player->pos, head->mob->pos);

    if (mob_distance < ATTACK_RADIUS) {
        attack_player(head->mob, player);
    } else {
        float direction_elapsed =
        sfTime_asSeconds(sfClock_getElapsedTime(
        head->mob->mob_direction_clock));
        if (direction_elapsed >= head->mob->mob_direction_timer) {
            head->mob->direction = random_direction();
            sfClock_restart(head->mob->mob_direction_clock);
        }
        update_npc_position(head->mob, head->mob->direction);
    }
}