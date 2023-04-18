/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** moves
*/

#ifndef MOVES_H_
    #define MOVES_H_

    #define PX player->pos.x
    #define PY player->pos.y
    #define SPEED player->speed
    #define PLAYER player_t *player
    #define TILESET tilesheet *tileset

    #include <stdio.h>
    #include "graphical.h"
    
    typedef struct player_t {
        sfVector2f pos;
        sfIntRect rect;
    } player_s;

    /* horizontal_move.c */
    void get_move(void);
    void move_left(void);
    void move_right(void);
    void move_up(void);
    void move_down(void);

#endif /* !MOVES_H_ */
