/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** traps
*/

#include "map.h"
#include "gamestate.h"

static int assign_trap_type(int type)
{
    if (type == 58)
        return 57;
    if (type == 57)
        return 56;
    if (type == 56)
        return 55;
    if (type == 55)
        return 58;
    return (type);
}

static void animate_all_traps(layer_t *layers)
{
    for (int i = 0; layers[3].tiles[i]; i++)
        for (int j = 0; layers[3].tiles[i][j].type != -1; j++)
            layers[3].tiles[i][j].type =
            assign_trap_type(layers[3].tiles[i][j].type);
}

void animate_traps(layer_t *layers, gamestate_t *gamestate)
{
    sfTime time = sfClock_getElapsedTime(gamestate->trap_clock);
    float timer = sfTime_asSeconds(time);

    if (timer >= 0.5) {
        animate_all_traps(layers);
        sfClock_restart(gamestate->trap_clock);
    }
}
