/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** movingsaws
*/

#ifndef SAWS_H
    #define SAWS_H

    #include "graphical.h"
    #include "map.h"

    typedef struct saws_s {
        sfVector2f pos;
        sfVector2f speed;
    } saws_t;

    typedef struct saw_draw_s {
        sfClock *clock;
        sfSprite *saw;
        sfIntRect rect;
        sfTexture *texture;
    } saw_draw_t;

    saws_t *init_saws(layer_t *layers);
    void move_saws(saws_t *saws, saw_draw_t *saw_draw, layer_t *layers);
    void display_saws(saws_t *saws, sfRenderWindow *window, saw_draw_t *saw_draw);
    saw_draw_t *init_saw_sprite(void);
    void free_saws(saws_t *saws);
    void free_saw_draw(saw_draw_t *saw_draw);

#endif /* !SAWS_H */
