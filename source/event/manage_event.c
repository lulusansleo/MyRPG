/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** manage_event
*/

#include "event.h"

void manage_event(sfEvent *event, sfWindow *window, entity_t *player, layer_t **layers)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event->type == sfEvtKeyPressed)
            get_move(player, layers);
        if (event->type == sfEvtKeyReleased)
            get_release(player);
    }
}
