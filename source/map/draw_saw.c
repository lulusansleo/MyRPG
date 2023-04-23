/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** draw saww
*/

#include "moving_saws.h"

static int is_saw_right(int type)
{
    if (type == 54 || type == 51 || type == 48)
        return (1);
    return (0);
}

static int is_saw_left(int type)
{
    if (type == 52 || type == 49 || type == 46)
        return (1);
    return (0);
}

saw_draw_t *init_saw_sprite(void)
{
    saw_draw_t *saw = malloc(sizeof(saw_draw_t));
    saw->clock = sfClock_create();
    saw->saw = sfSprite_create();
    saw->rect = get_tile_rect(60);
    saw->texture =
    sfTexture_createFromFile("ressources/sprites/interactible.png", NULL);
    sfSprite_setTexture(saw->saw, saw->texture, sfTrue);
    sfSprite_setTextureRect(saw->saw, saw->rect);
    return (saw);
}

static void saw_pos(saws_t *saws, layer_t *layers)
{
    for (int i = 0; saws[i].pos.x != -1; i++) {
        if (saws[i].speed.x > 0 &&
        is_saw_right(layers[3].tiles[(int) saws[i].pos.y / 16]
        [(int) (saws[i].pos.x + 4) / 16].type))
            saws[i].speed.x = -saws[i].speed.x;
        if (saws[i].speed.x < 0 &&
        is_saw_left(layers[3].tiles[(int) (saws[i].pos.y / 16.0)]
        [(int) ((saws[i].pos.x + 10) / 16.0)].type))
            saws[i].speed.x = -saws[i].speed.x;
        saws[i].pos.x += saws[i].speed.x;
    }
}

void move_saws(saws_t *saws, saw_draw_t *saw_draw, layer_t *layers)
{
    sfTime time = sfClock_getElapsedTime(saw_draw->clock);
    if (sfTime_asSeconds(time) > 0.1) {
        for (int i = 0; saws[i].pos.x != -1; i++) {
            saw_pos(saws, layers);
            sfClock_restart(saw_draw->clock);
        }
    }
}

void display_saws(saws_t *saws, sfRenderWindow *window,
saw_draw_t *saw_draw)
{
    for (int i = 0; saws[i].pos.x != -1; i++) {
        sfSprite_setPosition(saw_draw->saw, saws[i].pos);
        sfRenderWindow_drawSprite(window, saw_draw->saw, NULL);
    }
}
