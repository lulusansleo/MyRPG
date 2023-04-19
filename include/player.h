/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define TXT_PLYR "./ressources/sprites/hero.png"
    #define TXT_NPC "./ressources/sprites/mob.png"
    #define NUM_MOBS 2
    #define MAX_Y 50
    #define MAX_X 50
    #define ATTACK_RADIUS 100

    #include <stdlib.h>
    #include "graphical.h"
    #include "map.h"
    typedef struct entity_s {
        sfVector2f pos;
        sfIntRect rect;
        float speed;
        sfClock *clock;
        sfTexture *texture;
        sfSprite *sprite;
        int type;
    } entity_t;

    typedef struct game_elements_s {
        sfRenderWindow *window;
        sfEvent *event;
        layer_t *layers;
        entity_t *player;
        entity_t **mobs;
        sfClock *npc_move_clock;
} game_elements_t;

    /* draw_player.c */
    void draw_player(entity_t *, sfRenderWindow *);
    game_elements_t init_game_elements(void);
    /* init_player.c */
    entity_t *init_entity(char *);

    /*draw_mob.c*/
    void draw_player(entity_t *player, sfRenderWindow *window);

    /*init_npc.c*/
    entity_t *init_entity_npc(char *path, float x, float y);
    sfVector2f random_position(float maxX, float maxY);
    void attack_player(entity_t *mob, entity_t *player, float deltaTime);
    float distance_npc(sfVector2f abs, sfVector2f ord);
    void main_move(entity_t *player, entity_t **mobs,
    sfClock *npc_move_clock, int num_mobs);
    float distance_npc(sfVector2f abs, sfVector2f ord);
    void attack_player(entity_t *mob, entity_t *player, float deltaTime);
    void main_init_npc(entity_t *player, entity_t **mobs,
    sfClock *npc_move_clock, int num_mobs);

#endif /* !PLAYER_H_ */
