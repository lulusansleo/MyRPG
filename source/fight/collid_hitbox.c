/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collid_hitbox
*/

#include "fight.h"
#include "npc.h"

static entity_t *init_weapon(entity_t *player)
{
    entity_t *weapon = malloc(sizeof(entity_t));
    weapon->type = player->type;
    weapon->pos = get_wpn_pos(player);
    return weapon;
}

static void hit(entity_t *a, entity_t *b)
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


void attack(entity_t *player, npc_t *mobs)
{
    entity_t *weapon = init_weapon(player);
    for (int i = 0; mobs; i++) {
        is_hit(weapon, mobs->mob);
    }
    if (weapon->type != BOW)
        free(weapon);
}