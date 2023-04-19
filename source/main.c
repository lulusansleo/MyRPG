/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** main
*/

#include "gamestate.h"
#include "map.h"
#include "my.h"
#include "player.h"
#include "event.h"
#include "entity.h"
#include "graphical.h"
#include "npc.h"

int main(void)
{
    gamestate_t *gamestate = initalise_gamestate();
    layer_t *layers = initialise_layer(gamestate->level, gamestate->floor);
    entity_t *player = init_entity(TXT_PLYR);
    entity_t **mobs = init_mobs(NUM_MOBS, layers[0]);
    while (sfRenderWindow_isOpen(gamestate->window)) {
        layers = manage_event(gamestate, player, layers);
        collision(player, layers);
        do_move(player);
        npc_move(player, mobs, NUM_MOBS);
        sfRenderWindow_clear(gamestate->window, sfBlack);
        draw_map(layers, gamestate->window);
        draw_player(player, gamestate->window);
        draw_mobs(mobs, gamestate->window);
        sfRenderWindow_display(gamestate->window);
        sfRenderWindow_display(gamestate->window);
    }
    sfRenderWindow_destroy(gamestate->window);
    free(gamestate->event);
    destroy_player(player);
    free_layer(layers);
    return 0;
}
