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
#include "moves.h"
#include "event.h"
#include "fight.h"
#include "entity.h"
#include "graphical.h"
#include "npc.h"
#include "view.h"


int main(void)
{
    gamestate_t *gamestate = initalise_gamestate();
    layer_t *layers = initialise_layer(gamestate->level, gamestate->floor);
    entity_t *player = init_entity();
    npc_t *mobs = NULL;
    mobs = add_node(mobs, 50.0, 50.0, 1);
    sfView *view = init_view(player);
    while (sfRenderWindow_isOpen(gamestate->window)) {
        sfRenderWindow_clear(gamestate->window, sfBlack);
        layers = manage_event(gamestate, player, layers, &mobs);
        collision(player, layers);
        do_move(player);
        animate_traps(layers, gamestate);
        anim_weapon(player);
        animate_entities(player, mobs, gamestate);
        npc_management(gamestate, &mobs, layers, player);
        sfView_setCenter(view, refresh_view(player, view, layers[0]));
        sfRenderWindow_clear(gamestate->window, sfBlack);
        draw_map(layers, gamestate->window);
        draw_player(player, gamestate->window);
        draw_mobs(mobs, gamestate->window);
        sfRenderWindow_setView(gamestate->window, view);
        sfRenderWindow_display(gamestate->window);
    }
    sfRenderWindow_destroy(gamestate->window);
    free(gamestate->event);
    destroy_player(player);
    free_layer(layers);
    return 0;
}
