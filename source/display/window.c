/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window
*/

#include "gamestate.h"

gamestate_t *initalise_gamestate(void)
{
    gamestate_t *gamestate = malloc(sizeof(gamestate_t));
    gamestate->event = malloc(sizeof(sfEvent));
    gamestate->video_mode = (sfVideoMode){1920, 1080, 120};
    gamestate->window = sfRenderWindow_create(gamestate->video_mode,
    "MyRPG", sfClose | sfResize, NULL);
    gamestate->torch_clock = sfClock_create();
    gamestate->trap_clock = sfClock_create();
    gamestate->anim = sfClock_create();
    sfRenderWindow_setFramerateLimit(gamestate->window, 60);
    gamestate->level = 1;
    gamestate->floor = 1;
    gamestate->view = sfView_create();
    gamestate->view_size = (sfVector2f) {2000, 1000};
    sfView_setSize(gamestate->view, gamestate->view_size);
    sfView_setCenter(gamestate->view, (sfVector2f) {500, 500});
    sfRenderWindow_setView(gamestate->window, gamestate->view);
    return (gamestate);
}
