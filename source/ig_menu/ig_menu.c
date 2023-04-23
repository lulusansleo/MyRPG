/*
** EPITECH PROJECT, 2023
** ig menu
** File description:
** rpg
*/

#include "gamestate.h"
#include "ig_menu.h"
#include "menu.h"

ig_menu_t *init_ig_menu(sfRenderWindow *window)
{
    ig_menu_t *ig_menu = malloc(sizeof(ig_menu_t));
    menu_button_t *buttons = malloc(sizeof(menu_button_t) * 4);
    sfFont *font = sfFont_createFromFile("ressources/font/Roboto.ttf");

    ig_menu->back_text =
    sfTexture_createFromFile("ressources/sprites/options_back.png", NULL);
    ig_menu->background = sfSprite_create();
    sfSprite_setTexture(ig_menu->background, ig_menu->back_text, sfTrue);
    sfSprite_setPosition(ig_menu->background, (sfVector2f){500, 100});
    sfSprite_setScale(ig_menu->background, (sfVector2f){0.5, 0.6});
    init_new_button(&buttons[SAVE], font, "SAVE", (sfVector2f){550, 550});
    init_new_button(&buttons[OPTIONS_IG], font,
    "OPTIONS", (sfVector2f){550, 650});
    init_new_button(&buttons[LOAD_IG], font, "LOAD", (sfVector2f){550, 750});
    init_new_button(&buttons[MENU], font, "MENU", (sfVector2f){550, 850});
    ig_menu->buttons = buttons;
    update_bounds(ig_menu->buttons, window, 4);
    update_text_pos(ig_menu->buttons, 4);
    return ig_menu;
}

void display_ig_menu(sfRenderWindow *window, ig_menu_t *ig_menu)
{
    sfRenderWindow_drawSprite(window, ig_menu->background, NULL);
    display_buttons(window, ig_menu->buttons, 4);
}

void handle_options_button(menu_t *menu, ig_menu_t *ig_menu,
                        gamestate_t *gamestate)
{
    sfRenderWindow *window = gamestate->window;

    if (ig_menu->buttons[OPTIONS_IG].state == CLICK) {
        run_options(menu, gamestate);
        update_bounds(ig_menu->buttons, window, 4);
        sfRenderWindow_clear(window, sfBlack);
    }
}

void update_ig_menu(ig_menu_t *ig_menu, menu_t *menu,
            sfRenderWindow *window, gamestate_t *gamestate)
{
    handle_options_button(menu, ig_menu, gamestate);
    update_states(ig_menu->buttons, window, 4);
    update_colors(ig_menu->buttons, sfWhite, 4);
    display_ig_menu(window, ig_menu);
    sfRenderWindow_display(window);
}

int start_ig_menu(gamestate_t *gamestate, ig_menu_t *ig_menu, menu_t *menu)
{
    sfEvent event;
    sfRenderWindow *window = gamestate->window;

    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    update_bounds(ig_menu->buttons, window, 4);
    sfSleep(sfSeconds(0.3));
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_close_event(window, event);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfSleep(sfSeconds(0.3));
            return 0;
        }
        update_ig_menu(ig_menu, menu, window, gamestate);
        if (ig_menu->buttons[MENU].state == CLICK)
            return 1;
    }
    return 0;
}
