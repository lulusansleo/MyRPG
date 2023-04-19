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
#include "event.h"

int main(void)
{
    sfRenderWindow *window = initalise_window();
    sfEvent *event = malloc(sizeof(sfEvent));
    layer_t *layers = initialise_layer(1, 1);
    entity_t *player = init_entity(TXT_PLYR);
    while (sfRenderWindow_isOpen(window)) {
        manage_event(event, window, player, layers);
        collision(player, layers);
        do_move(player);
        sfRenderWindow_clear(window, sfBlack);
        draw_map(layers, window);
        draw_player(player, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    free(event);
    free_entity(player);
    free_layer(layers);
    return(0);
}
