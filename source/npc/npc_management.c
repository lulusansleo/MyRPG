/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** npc_management
*/

#include "player.h"
#include "npc.h"
#include "moves.h"

void npc_management(gamestate_t *gamestate,
npc_t **mobs, layer_t *layers, entity_t *player)
{
    npc_t *tmp = *mobs;

    while (tmp != NULL) {
        collision(tmp->mob, layers);
        tmp = tmp->next;
    }
    npc_move(player, *mobs);
    draw_mobs(*mobs, gamestate->window);
}
