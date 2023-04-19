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

    #include "map.h"
    #include "my.h"
    #include "gamestate.h"
    #include <stdlib.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>

    typedef struct entity_s {
        sfVector2f acceleration;
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

    /* init_player.c */
    entity_t *init_entity(char *);

#endif /* !PLAYER_H_ */
