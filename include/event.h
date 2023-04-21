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
    #define MOBS npc_t **mobs
    #define GAMESTATE gamestate_t *gamestate

    #include "graphical.h"
    #include "player.h"
    #include "npc.h"
    #include "map.h"
    #include "gamestate.h"

    /* door.c */
    void open_door(layer_t *layers, sfVector2i pos);
    void close_door(layer_t *layers, sfVector2i pos);

    /* interact.c */
    layer_t *interact(
entity_t *player,layer_t *layers, gamestate_t *gamestate);

    /* manage_event.c */
    layer_t *manage_event(GAMESTATE, PLAYER, layer_t *layers, MOBS);

#endif /* !EVENT_H_ */
