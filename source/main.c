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
#include "hud.h"
#include "ig_menu.h"

void display_game(gamestate_t *gamestate, layer_t *layers,
                    npc_t *mobs, entity_t *player)
{
    sfRenderWindow_clear(gamestate->window, sfBlack);
    draw_map(layers, gamestate->window);
    draw_mobs(gamestate->mobs, gamestate->window);
    display_saws(gamestate->saws, gamestate->window, gamestate->saw_draw);
    draw_player(player, gamestate->window);
    draw_layer(layers[0].tiles, layers[0].sprite_sheet, gamestate->window);
}

void anim_game(entity_t *player, layer_t *layers,
            npc_t *mobs, gamestate_t *gamestate)
{
    animate_traps(layers, gamestate);
    anim_weapon(player);
    move_saws(gamestate->saws, gamestate->saw_draw, layers);
    animate_entities(player, mobs, gamestate);
}

void run_game(menu_t *menu, ig_menu_t *ig_menu,
            gamestate_t *gamestate, npc_t *mobs)
{
    entity_t *player = gamestate->player;
    sfView *view = gamestate->view;
    layer_t *layers = initialise_layer(gamestate->level, gamestate->floor);
    hud_t *hud = init_hud();
    sfRenderWindow *window = gamestate->window;
    int status = 0;

    while (sfRenderWindow_isOpen(gamestate->window)) {
        update_stats(player);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            status = start_ig_menu(gamestate, ig_menu, menu, player);
        if (status == 1)
            return;
        update_health_bar(player->hp, 100, hud, view);
        update_xp_bar(player->xp, hud, view);
        layers = manage_event(&gamestate, player, layers, &gamestate->mobs);
        collision(player, layers);
        do_move(player);
        anim_game(player, layers, gamestate->mobs, gamestate);
        npc_management(gamestate, &gamestate->mobs, layers, player);
        sfView_setCenter(view, refresh_view(player, view, layers[0]));
        sfRenderWindow_setView(gamestate->window, view);
        display_game(gamestate, layers, mobs, player);
        display_hud(window, hud);
        sfRenderWindow_display(gamestate->window);
    }
}

int main(void)
{
    gamestate_t *gamestate = initalise_gamestate();
    layer_t *layers = initialise_layer(gamestate->level, gamestate->floor);
    menu_t *menu = init_menu(gamestate);
    ig_menu_t *ig_menu = init_ig_menu(gamestate->window);

    gamestate->saws = init_saws(layers);
    gamestate->saw_draw = init_saw_sprite();
    gamestate->player = init_entity();
    gamestate->view = init_view(gamestate->player);
    run_menu(gamestate, menu, ig_menu, gamestate->mobs);
    destroy_player(gamestate->player);
    destroy_gamestate(gamestate);
    free_layer(layers);
    return 0;
}
