/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #define EVENT sfEvent *event
    #define WINDOW sfWindow *window
    #define PLAYER entity_t *player

    #include "graphical.h"
    #include "player.h"
    #include "map.h"
    #include "gamestate.h"

    /* manage_event.c */
    layer_t *manage_event(gamestate_t *gamestate, entity_t *player, layer_t *);

#endif /* !EVENT_H_ */
