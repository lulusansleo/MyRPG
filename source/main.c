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
#include "graphical.h"


int main(void)
{
    sfRenderWindow *window = initalise_window();
    sfEvent *event = malloc(sizeof(sfEvent));
    layer_t *layers = initialise_layer(1, 1);
    entity_t *player = init_entity(TXT_PLYR);
    entity_t **mobs = init_mobs(NUM_MOBS, layers[0]);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event->type == sfEvtKeyPressed)
                get_move(player, layers);
            if (event->type == sfEvtKeyReleased)
                get_release(player);
        }
        collision(player, layers);
        do_move(player);
        npc_move(player, mobs, NUM_MOBS);
        sfRenderWindow_clear(window, sfBlack);
        draw_map(layers, window);
        draw_player(player, window);
        draw_mobs(mobs, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    free(event);
    free_layer(layers);
    return 0;
}
