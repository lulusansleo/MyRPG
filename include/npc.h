/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "player.h"

    /*draw_npc.c*/
    void draw_mobs(entity_t **, sfRenderWindow *);
    void free_mobs(entity_t **);

    /*init_npc.c*/
    entity_t **init_mobs(int nb_mob, layer_t layer);
    sfVector2f spawn_mob(layer_t layer);
    entity_t *init_entity_npc(layer_t layer);

    /* attack_npc.c */
    float distance_npc(sfVector2f abs, sfVector2f ord);
    void attack_player(entity_t *mob, entity_t *player, float deltaTime);
    void npc_move(entity_t *player, entity_t **mobs, int num_mobs);

    /* position_npc.c */
    int random_direction(void);
    sfVector2f random_position(float, float);
    void attack_player(entity_t *mob, entity_t *player, float deltaTime);

#endif /* !NPC_H_ */
