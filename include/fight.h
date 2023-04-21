/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fight
*/

#ifndef FIGHT_H_
    #define FIGHT_H_

    #include "player.h"
    #include "map.h"
    #include "moves.h"
    #include "npc.h"

    /* collid_hitbox.c */
    sfVector2f get_wpn_pos(entity_t *player);
    entity_t *init_weapon(entity_t *player);
    sfFloatRect *get_hitbox(entity_t *entity);
    void hit(entity_t* a, entity_t *b);
    void is_hit(entity_t* a, entity_t *b);
    void attack(entity_t *player, npc_t *mobs);

    
#endif /* !FIGHT_H_ */
