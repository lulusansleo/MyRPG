/*
** EPITECH PROJECT, 2023
** include hud
** File description:
** rpg
*/

#ifndef INCLUDE_HUD_H_
    #define INCLUDE_HUD_H_
    #include "graphical.h"

typedef struct hud {
    sfRectangleShape* health_back;
    sfRectangleShape* health_bar;
} hud_t;

hud_t *init_hud(void);
void update_health_bar(int health, sfRectangleShape *health_bar);

#endif /* INCLUDE_HUD_H_ */
