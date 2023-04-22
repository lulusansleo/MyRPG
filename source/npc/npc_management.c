/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** npc_management
*/

#include "player.h"
#include "npc.h"
#include "moves.h"

static npc_t *check_for_depop(npc_t *npc, npc_t **mobs)
{
    if (npc->mob->hp <= 0) {
        npc_t *next = npc->next;
        *mobs = kill_mob(*mobs, npc);
        return next;
    }
    return npc->next;
}

void npc_management(gamestate_t *gamestate,
npc_t **mobs, layer_t *layers, entity_t *player)
{
    npc_t *tmp = *mobs;

    while (tmp) {
        tmp = check_for_depop(tmp, mobs);
        if (*mobs == NULL)
            return;
    }
    tmp = *mobs;
    while (tmp != NULL) {
        npc_move(player, tmp);
        collision(tmp->mob, layers);
        tmp->mob->pos.x += tmp->mob->move.x;
        tmp->mob->pos.y += tmp->mob->move.y;
        sfSprite_setPosition(tmp->mob->sprite, tmp->mob->pos);
        tmp = tmp->next;
    }
    draw_mobs(*mobs, gamestate->window);
}
