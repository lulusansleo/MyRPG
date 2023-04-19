/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define TXT_PLYR "./ressources/sprites/hero.png"

    #include <stdlib.h>
    #include "graphical.h"

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
