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
    npc_t *mobs = NULL;
    mobs = add_node(mobs, 30, 30, 1);
    while (sfRenderWindow_isOpen(gamestate->window)) {
        sfRenderWindow_clear(gamestate->window, sfBlack);
        layers = manage_event(gamestate, player, layers, &mobs);
        collision(player, layers);
        do_move(player);
        draw_map(layers, gamestate->window);
        draw_player(player, gamestate->window);
        npc_management(gamestate, &mobs, layers, player);
        sfRenderWindow_display(gamestate->window);
    }
    sfRenderWindow_destroy(gamestate->window);
    free(gamestate->event);
    destroy_player(player);
    free_layer(layers);
    return 0;
}
