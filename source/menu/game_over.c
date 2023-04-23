/*
** EPITECH PROJECT, 2023
** game over
** File description:
** rpg
*/

#include "menu.h"

game_over_t *init_game_over(void)
{
    game_over_t *game_over = malloc(sizeof(game_over_t));
    menu_button_t *button = malloc(sizeof(menu_button_t));

    game_over->font = sfFont_createFromFile("ressources/font/over.ttf");
    game_over->text = sfText_create();
    sfText_setFont(game_over->text, game_over->font);
    init_new_button(button, game_over->font, "MENU", (sfVector2f){840, 700});
    sfText_setColor(button->text, sfRed);
    sfRectangleShape_setFillColor(button->button, sfBlack);
    sfText_setFont(game_over->text, game_over->font);
    sfText_setString(game_over->text, "GAME OVER");
    sfText_setCharacterSize(game_over->text, 100);
    sfText_setPosition(game_over->text, (sfVector2f){600, 200});
    game_over->button = button;
    return game_over;
}

void display_game_over(sfRenderWindow *window, game_over_t *game_over)
{
    sfEvent event;

    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    update_bounds(game_over->button, window, 1);
    update_text_pos(game_over->button, 1);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_close_event(window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, game_over->text, NULL);
        sfRenderWindow_drawRectangleShape(window,
        game_over->button->button, NULL);
        sfRenderWindow_drawText(window, game_over->button->text, NULL);
        update_states(game_over->button, window, 1);
        update_colors(game_over->button, sfBlack, 1);
        sfRenderWindow_display(window);
        if (game_over->button->state == CLICK)
            return;
    }
}
