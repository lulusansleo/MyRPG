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

sfView *init_view(entity_t *player)
{
    sfFloatRect viewrect = (sfFloatRect){player->pos.x, player->pos.y, 5.0, 5.0};
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f){8 * 16, 8 * 16});z//    sfView_zoom(view, 3);
    sfView_setCenter(view, player->pos);
    return view;
}

sfVector2f refresh_view(entity_t *player, sfView *view)
{
    sfView_setCenter(view, player->pos);
    sfVector2f pos = sfView_getCenter(view);
    sfVector2f size =  sfView_getSize(view);
    if (pos.x - (size.x / 2) <= 0)
        pos.x = (size.x / 2);
    if (pos.y - (size.y / 2) <= 0)
        pos.y = (size.y / 2);
    return pos;
} 

int main(void)
{
    gamestate_t *gamestate = initalise_gamestate();
    layer_t *layers = initialise_layer(gamestate->level, gamestate->floor);
    entity_t *player = init_entity(TXT_PLYR);
    entity_t **mobs = init_mobs(NUM_MOBS, layers[0]);
    sfView *view = init_view(player);
    while (sfRenderWindow_isOpen(gamestate->window)) {
        layers = manage_event(gamestate, player, layers);
        collision(player, layers);
        do_move(player);
        npc_move(player, mobs, NUM_MOBS);
        sfView_setCenter(view, refresh_view(player, view));
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
