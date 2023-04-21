/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collid_hitbox
*/

#include "fight.h"

entity_t *init_weapon(entity_t *player)
{
    entity_t *weapon = malloc(sizeof(entity_t));
    weapon->type = player->type;
    weapon->pos = get_wpn_pos(player);
    return weapon;
}

void hit(entity_t *a, entity_t *b)
{
    b->hp -= a->dmg;
    if (b->hp <= 0)
        b->alive = 0;
}

void print_hitbox(sfFloatRect *a)
{
    printf("left :%f\ntop :%f\n",a->left,a->top);
}

void is_hit(entity_t* a, entity_t *b)
{
//    printf("is_hit ?\n");
    sfFloatRect *rect_a = get_hitbox(a);
    sfFloatRect *rect_b = get_hitbox(b);
//    print_hitbox(rect_a);
//    print_hitbox(rect_b);
    if (sfFloatRect_intersects(rect_a, rect_b, NULL) == sfTrue) {
//        printf("HIT\n");
        hit(a, b);
    }
}

void attack(entity_t *player, npc_t *mobs)
{
//    printf("attack\n");
    entity_t *weapon = init_weapon(player);
    for (int i = 0; mobs; i++) {
//        printf("pos player : %f & %f\npos weapon : %f & %f\npos mob : %f & %f\n",player->pos.x, player->pos.y, weapon->pos.x, weapon->pos.y, mobs->mob->pos.x, mobs->mob->pos.y);
        is_hit(weapon, mobs->mob);
        mobs = mobs->next;
    }
    if (weapon->type != BOW)
        free(weapon);
}