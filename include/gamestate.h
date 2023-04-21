/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window include
*/

#ifndef WINDOW_H
    #define WINDOW_H

    #include "graphical.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <stdlib.h>

    typedef struct gamestate_s {
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfClock *anim;
        sfTime time;
        sfEvent *event;
        sfVector2f mouse_pos;
        sfVector2f mouse_pos_view;
        sfView *view;
        sfVector2f view_pos;
        sfVector2f view_size;
        sfVector2f view_center;
        int level;
        int floor;
    } gamestate_t;

    gamestate_t *initalise_gamestate(void);

#endif /* !WINDOW_H */
