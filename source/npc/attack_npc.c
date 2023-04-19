/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** mouvement&attack_npc
*/

#include "window.h"
#include "map.h"
#include "my.h"
#include "player.h"


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

void npc_move(entity_t *player, entity_t **mobs, int num_mobs)
{

    for (int i = 0; i < num_mobs; i++) {
        float deltaTime = sfTime_asSeconds(sfClock_getElapsedTime(mobs[i]->clock));
        float mob_distance = distance_npc(player->pos, mobs[i]->pos);

        if (mob_distance < ATTACK_RADIUS) {
            attack_player(mobs[i], player, deltaTime);
        } else {
            int direction = random_direction();
            update_npc_position(mobs[i], direction, deltaTime);
        }
        sfClock_restart(mobs[i]->clock);
    }

}
