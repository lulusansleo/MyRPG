/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** mouvement&attack_npc
*/

#include "map.h"
#include "my.h"
#include "player.h"
#include "fight.h"
#include "graphical.h"
#include "npc.h"


float distance_npc(sfVector2f abs, sfVector2f ord)
{
    float dx = abs.x - ord.x;
    float dy = abs.y - ord.y;

    return sqrt(dx * dx + dy * dy);
}

static void is_attacking(entity_t *player, entity_t *mob)
{
    sfFloatRect *box_player = get_hitbox(player);
    sfFloatRect *box_mob = get_hitbox(mob);
    sfTime time;
    if (player->invicible == 0 &&
    sfFloatRect_intersects(box_player, box_mob, NULL) == sfTrue) {
        player->invicibility = sfClock_create();
        hit(mob, player);
        player->invicible = 1;
    }
    if (player->invicible == 1) {
        time = sfClock_getElapsedTime(player->invicibility);
        if (sfTime_asSeconds(time) > 5.0 && player->invicible == 1) {
            sfClock_destroy(player->invicibility);
            player->invicible = 0;
        }
    }
}

void attack_player(entity_t *mob, entity_t *player, float deltaTime)
{
    is_attacking(player, mob);
    float angle = atan2(player->pos.y - mob->pos.y, player->pos.x - mob->pos.x);

    mob->pos.x += mob->speed * deltaTime * cos(angle);
    mob->pos.y += mob->speed * deltaTime * sin(angle);
    sfSprite_setPosition(mob->sprite, mob->pos);
}

void npc_move(entity_t *player, npc_t *head)
{
    if (head == NULL)
        return;
    int direction;
    npc_t *tmp = head;
    while (tmp != NULL) {
        float deltaTime = sfTime_asSeconds(sfClock_getElapsedTime(tmp->mob->clock));
        float mob_distance = distance_npc(player->pos, tmp->mob->pos);

        if (mob_distance < ATTACK_RADIUS) {
            attack_player(tmp->mob, player, deltaTime);
        } else {
            float direction_elapsed = sfTime_asSeconds(sfClock_getElapsedTime(tmp->mob->mob_direction_clock));
            if (direction_elapsed >= tmp->mob->mob_direction_timer) {
                direction = random_direction();
                sfClock_restart(tmp->mob->mob_direction_clock);
            }
            update_npc_position(tmp->mob, direction);
        }
        sfClock_restart(tmp->mob->clock);
        tmp = tmp->next;
    }
}