/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** manage_event
*/

#include "gamestate.h"
#include "event.h"
#include "npc.h"
#include "fight.h"

static void key_pressed(GAMESTATE, PLAYER, layer_t *layers, MOBS)
{
    if (gamestate->event->key.code == sfKeyE)
        layers = interact(player, layers, gamestate);
    if (gamestate->event->key.code == sfKeySpace)
        attack(player, *mobs);
    if (gamestate->event->key.code == sfKeyF)
        *mobs = kill_mob(*mobs, *mobs);
    if (gamestate->event->key.code == sfKeyC)
        *mobs = add_node(*mobs, 30, 30, 1);
    get_move(player);
}

layer_t *manage_event(GAMESTATE, PLAYER, layer_t *layers, MOBS)
{
    while (sfRenderWindow_pollEvent(gamestate->window, gamestate->event)) {
        if (gamestate->event->type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(gamestate->window);
        if (gamestate->event->type == sfEvtKeyReleased)
            get_release(player, gamestate->event);  
        if (gamestate->event->type == sfEvtKeyPressed)
            key_pressed(gamestate, player, layers, mobs);          
    }
    return (layers);
}
