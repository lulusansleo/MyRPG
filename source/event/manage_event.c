/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** manage_event
*/

#include "gamestate.h"
#include "event.h"
#include "npc.h"

layer_t *manage_event(gamestate_t *gamestate, PLAYER, layer_t *layers, npc_t **mobs)
{
    while (sfRenderWindow_pollEvent(gamestate->window, gamestate->event)) {
        if (gamestate->event->type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(gamestate->window);
        if (gamestate->event->type == sfEvtKeyPressed &&
        gamestate->event->key.code == sfKeyE)
            layers = interact(player, layers, gamestate);
        if (gamestate->event->type == sfEvtKeyPressed)
            get_move(player, layers);
        if (gamestate->event->type == sfEvtKeyReleased)
            get_release(player, gamestate->event);
        if (gamestate->event->type == sfEvtKeyPressed &&
        gamestate->event->key.code == sfKeyF)
            *mobs = kill_mob(*mobs, *mobs);
        if (gamestate->event->type == sfEvtKeyPressed &&
        gamestate->event->key.code == sfKeyC)
            *mobs = add_node(*mobs, 30, 30, 1);
    }
    return (layers);
}
