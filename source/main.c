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
    layer_t *layers = initialise_layer();
    player_t *player = init_player();
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        get_move(player, layers[0]);
        sfRenderWindow_clear(window, sfBlack);
        draw_layer(layers[1].tiles, layers[1].sprite_sheet, window);
        draw_layer(layers[0].tiles, layers[0].sprite_sheet, window);
        draw_layer(layers[2].tiles, layers[2].sprite_sheet, window);
        draw_player(player, layers[0]);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    free(event);
    free_layer(layers);
    return (0);
}
