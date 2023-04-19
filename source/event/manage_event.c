/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** manage_event
*/

#include "gamestate.h"
#include "event.h"

layer_t *manage_event(gamestate_t *gamestate, PLAYER, layer_t *layers)
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
    }
    return (layers);
}
