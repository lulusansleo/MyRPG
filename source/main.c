/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** main
*/

#include "window.h"
#include "map.h"
#include "my.h"
#include "player.h"

int main(void)
{
    sfRenderWindow *window = initalise_window();
    sfEvent *event = malloc(sizeof(sfEvent));
    layer_t *layers = initialise_layer(1, 1);
    entity_t *player = init_entity(TXT_PLYR);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        get_move(player, layers[0]);
        sfRenderWindow_clear(window, sfBlack);
        draw_map(layers, window);
        draw_player(player, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    free(event);
    free_layer(layers);
    return(0);
}
