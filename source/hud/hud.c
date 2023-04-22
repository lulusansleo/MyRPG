/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** hud
*/

#include "gamestate.h"
#include "hud.h"

hud_t *init_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->health_back = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->health_back, (sfVector2f){30, 5});
    sfRectangleShape_setFillColor(hud->health_back, sfBlack);
    hud->health_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->health_bar, (sfVector2f){29, 4});
    sfRectangleShape_setFillColor(hud->health_bar, sfRed);
    return hud;
}

void update_health_bar(int health, sfRectangleShape *health_bar)
{
    double new_size = (health * 29) / 100;

    if (health < 0)
        health = 0;
    if (health > 100)
        health = 100;
    sfRectangleShape_setSize(health_bar, (sfVector2f){new_size, 4});
}
