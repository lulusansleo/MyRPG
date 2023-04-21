/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fight
*/

#ifndef FIGHT_H_
    #define FIGHT_H_

    #define SWORD_TXT "./ressources/sprites/swoosh-animation.png"
    #include "player.h"
    #include "map.h"
    #include "moves.h"
    #include "npc.h"

    /* collid_hitbox.c */
    void attack(entity_t *player, npc_t *mobs);

    /*get_utils.c */
    sfVector2f get_wpn_pos(entity_t *player);
    sfFloatRect *get_hitbox(entity_t *entity);


#endif /* !FIGHT_H_ */
