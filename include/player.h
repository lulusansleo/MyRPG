/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <stdlib.h>
    #include "graphical.h"

    typedef struct player_s {
        sfVector2f pos;
        sfIntRect rect;
        float speed;
        sfClock *clock;
        sfTexture *texture;
        sfSprite *sprite;
    } player_t;

#endif /* !PLAYER_H_ */
