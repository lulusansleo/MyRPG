/*
** EPITECH PROJECT, 2023
** ig menu
** File description:
** rpg
*/

#ifndef IG_MENU_H_
    #define IG_MENU_H_
    #include "menu.h"

typedef enum ig_buttons {
    SAVE,
    LOAD_IG,
    OPTIONS_IG,
    MENU
} ig_buttons_t;

typedef struct ig_menu {
    sfTexture *back_text;
    sfSprite *background;
    menu_button_t *buttons;
} ig_menu_t;

ig_menu_t *init_ig_menu(sfRenderWindow* window);
void start_ig_menu(gamestate_t *gamestate, ig_menu_t *ig_menu, menu_t *menu);

#endif /* IG_MENU_H_ */
