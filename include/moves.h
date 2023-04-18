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
    #define LAYER layer_t *layer

    #include <stdio.h>
    #include "graphical.h"
    #include "moves.h"
    #include "map.h"
    #include "player.h"

    /* check_move.c */
    void get_move(PLAYER, LAYER);

    /* horizontal_move.c */
    void move_left(PLAYER, LAYER);
    void move_right(PLAYER, LAYER);

    /*vertical_move.c */
    void move_up(PLAYER, LAYER);
    void move_down(PLAYER, LAYER);

#endif /* !MOVES_H_ */
