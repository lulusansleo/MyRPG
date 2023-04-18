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
    #define LEFT sfKeyQ 
    #define RIGHT sfKeyD
    #define UP sfKeyZ
    #define DOWN sfKeyS

    #include <stdio.h>
    #include "graphical.h"
    
    typedef struct player_t {
        sfVector2f pos;
        sfIntRect rect;
    } player_s;

    /* check_move.c */
    void get_move(void);

    /* horizontal_move.c */
    void move_left(PLAYER, TILESET);
    void move_right(PLAYER, TILESET);

    /*vertical_move.c */
    void move_up(PLAYER, TILESET);
    void move_down(PLAYER, TILESET);

#endif /* !MOVES_H_ */
