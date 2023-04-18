/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** main
*/

#include "window.h"
#include "map.h"
#include "my.h"

int main(void)
{
    sfRenderWindow *window = initalise_window();
    sfEvent *event = malloc(sizeof(sfEvent));
    layer_t *layers = initialise_layer();
    free(buffer);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_layer(layers[0].tiles, layers[0].sprite_sheet, window);
        draw_layer(layers[1].tiles, layers[1].sprite_sheet, window);
        sfRenderWindow_display(window);
    }
    return (0);
}
