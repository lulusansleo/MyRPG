/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window include
*/

#ifndef WINDOW_H
    #define WINDOW_H

    #include "map.h"
    #include "graphical.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include "player.h"

    typedef struct gamestate_s {
        sfClock *trap_clock;
        sfClock *torch_clock;
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
        entity_t *player;
        int level;
        int floor;
    } gamestate_t;

    gamestate_t *initalise_gamestate(void);
    //void run_game(menu_t *menu, ig_menu_t *ig_menu, gamestate_t *gamestate,
    //npc_t *mobs);
    /* traps */
    void animate_traps(layer_t *layers, gamestate_t *gamestate);

#endif /* !WINDOW_H */
