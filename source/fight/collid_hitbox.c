/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collid_hitbox
*/

#include "fight.h"
#include "npc.h"


void hit(entity_t *a, entity_t *b)
{
    b->hp -= a->dmg;
    if (b->hp <= 0) {
        b->alive = 0;
    }
}

static void is_hit(entity_t* a, entity_t *b)
{
    sfFloatRect *rect_a = get_hitbox(a);
    sfFloatRect *rect_b = get_hitbox(b);
    if (sfFloatRect_intersects(rect_a, rect_b, NULL) == sfTrue) {
        hit(a, b);
    }
    free(rect_a);
    free(rect_b);
}

void free_mob(entity_t *mob)
{
    sfClock_destroy(mob->mob_direction_clock);
    sfTexture_destroy(mob->texture);
    sfSprite_destroy(mob->sprite);
}

void attack(entity_t *player, npc_t *mobs)
{
    if (!player->weapon)
        player->weapon = init_weapon(player);
    anim_weapon(player);
    if (mobs == NULL)
        return;
    if (player->weapon) {
        while (mobs) {
            is_hit(player->weapon, mobs->mob);
            mobs = mobs->next;
        }
    }
}
