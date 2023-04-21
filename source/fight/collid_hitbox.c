/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collid_hitbox
*/

#include "fight.h"
#include "npc.h"

void stance_sprite(entity_t *weapon)
{
    
}

static entity_t *init_weapon(entity_t *player)
{
    entity_t *weapon = malloc(sizeof(entity_t));
    weapon->type = player->type;
    weapon->pos = get_wpn_pos(player);
    weapon->clock = sfClock_create();
    weapon->alive = 1;
    weapon->texture = sfTexture_createFromFile(TXT_PLYR, NULL);
    weapon->rect = (sfIntRect) {((player->dir - 1) * 16), 0, 16, 16};
    weapon->sprite = sfSprite_create();
    sfSprite_setPosition(weapon->sprite, weapon->pos);
    sfSprite_setTexture(weapon->sprite, weapon->texture, sfTrue);
    sfSprite_setTextureRect(weapon->sprite, weapon->rect);
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

int anim_weapon(entity_t *weapon)
{
    sfTime time = sfClock_getElapsedTime(weapon->clock);
    if (sfTime_asSeconds(time) > 0.5) {
        weapon->rect.left += 16;
        if (weapon->rect.left >= 32) {
            weapon->alive = 0;
            return 0;
        }
        sfSprite_setTextureRect(weapon->sprite, weapon->rect);
        sfClock_restart(weapon->clock);
    }
    return 0;
}

void attack(entity_t *player, npc_t *mobs)
{
    player->weapon = init_weapon(player);
    while (mobs) {
        is_hit(player->weapon, mobs->mob);
        mobs = mobs->next;
    }
    if (player->weapon->type == SWORD) {
        if (player->weapon->alive == 1) {
            anim_weapon(player->weapon);
        } else { 
            sfClock_destroy(player->weapon->clock);
            sfTexture_destroy(player->weapon->texture);
            sfSprite_destroy(player->weapon->sprite);
            free(player->weapon);
        }
    }
}
