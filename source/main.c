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

#include "menu.h"
#include "ig_menu.h"

void display_game(gamestate_t *gamestate, layer_t *layers,
                    npc_t *mobs, entity_t *player)
{
    sfRenderWindow_clear(gamestate->window, sfBlack);
    draw_map(layers, gamestate->window);
    draw_mobs(mobs, gamestate->window);
    draw_player(player, gamestate->window);
    sfRenderWindow_display(gamestate->window);
}

int main(void)
{
    gamestate_t *gamestate = initalise_gamestate();
    layer_t *layers = initialise_layer(gamestate->level, gamestate->floor);
    entity_t *player = init_entity();
    //npc_t *mobs = NULL;
    npc_t *mobs = load_mobs_from_file("mobs.txt");
    //mobs = add_node(mobs, 50.0, 50.0, 1);
    sfView *view = init_view(player);
    menu_t *menu = init_menu(gamestate);
    ig_menu_t *ig_menu = init_ig_menu(gamestate->window);

    while (sfRenderWindow_isOpen(gamestate->window)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            start_ig_menu(gamestate, ig_menu, menu);
        layers = manage_event(gamestate, player, layers, &mobs);
        collision(player, layers);
        do_move(player);
        animate_traps(layers, gamestate);
        anim_weapon(player);
        animate_entities(player, mobs, gamestate);
        npc_management(gamestate, &mobs, layers, player);
        sfView_setCenter(view, refresh_view(player, view, layers[0]));
        sfRenderWindow_setView(gamestate->window, view);
        display_game(gamestate, layers, mobs, player);
    }
    sfRenderWindow_destroy(gamestate->window);
    free(gamestate->event);
    destroy_player(player);
    free_layer(layers);
    return 0;
}
