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
    game_elements_t game_elements = init_game_elements();
    while (sfRenderWindow_isOpen(game_elements.window)) {
        while (sfRenderWindow_pollEvent(game_elements.window,
        game_elements.event)) {
            if (game_elements.event->type == sfEvtClosed)
                sfRenderWindow_close(game_elements.window);
        }
        get_move(game_elements.player, game_elements.layers[0]);
        main_move(game_elements.player, game_elements.mobs,
        game_elements.npc_move_clock, NUM_MOBS);
        sfRenderWindow_clear(game_elements.window, sfBlack);
        for (int i = 0; i < 4; i++) {
            draw_layer(game_elements.layers[i].tiles,
            game_elements.layers[i].sprite_sheet, game_elements.window);
        }
        draw_player(game_elements.player, game_elements.window);
        for (int i = 0; i < NUM_MOBS; i++) {
            draw_player(game_elements.mobs[i], game_elements.window);
        }
        sfRenderWindow_display(game_elements.window);
    }
    sfRenderWindow_destroy(game_elements.window);
    free(game_elements.event);
    free_layer(game_elements.layers);
    free(game_elements.mobs);

    return 0;
}
