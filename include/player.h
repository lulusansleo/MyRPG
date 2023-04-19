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
    #define MAX_Y 200
    #define MAX_X 200
    #define ATTACK_RADIUS 100

    #include "window.h"
    #include "map.h"
    #include "my.h"
    #include <stdlib.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>

    typedef struct entity_s {
        sfVector2f move;
        sfVector2f pos;
        sfIntRect rect;
        float speed;
        sfClock *clock;
        sfTexture *texture;
        sfSprite *sprite;
        int type;
    } entity_t;

    /* draw_player.c */
    void draw_player(entity_t *, sfRenderWindow *);
    //game_elements_t init_game_elements(void);

    /* init_player.c */
    entity_t *init_entity(char *);

    /*draw_npc.c*/
    void draw_mobs(entity_t **, sfRenderWindow *);
    void free_mobs(entity_t **);

    /*init_npc.c*/
    entity_t **init_mobs(int nb_mob, layer_t layer);
    sfVector2f spawn_mob(layer_t layer);
    entity_t *init_entity_npc(layer_t layer);

    sfVector2f random_position(float maxX, float maxY);
    int random_direction(void);
    void attack_player(entity_t *mob, entity_t *player, float deltaTime);
    float distance_npc(sfVector2f abs, sfVector2f ord);
    void npc_move(entity_t *player, entity_t **mobs, int num_mobs);
    float distance_npc(sfVector2f abs, sfVector2f ord);
    void attack_player(entity_t *mob, entity_t *player, float deltaTime);

#endif /* !PLAYER_H_ */
