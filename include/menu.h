/*
** EPITECH PROJECT, 2023
** menu
** File description:
** rpg
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "graphical.h"
    #include "gamestate.h"
    #include "npc.h"

typedef enum button_state {
    HOVER,
    CLICK,
    BASIC
} button_state_t;

typedef enum button_name {
    NEW,
    LOAD,
    OPTIONS,
    QUIT,
} button_name_t;

typedef struct menu_button {
    sfFloatRect button_bounds;
    sfRectangleShape* button;
    button_state_t state;
    sfText *text;
} menu_button_t;

typedef struct options {
    sfTexture *back_text;
    sfSprite *background;
    sfFont *font;
    menu_button_t *res_buttons;
    menu_button_t *fps_buttons;
    menu_button_t *vol_buttons;
    sfText *res_text;
    sfText *fps_text;
    sfText *vol_text;
    sfText *options_text;
    sfTexture *text_back_arrow;
    sfSprite *back_arrow;
    sfFloatRect arrow_bounds;
} options_t;

typedef struct menu {
    menu_button_t *buttons;
    sfTexture *back_text;
    sfSprite *background;
    options_t *options;
} menu_t;

typedef struct ig_menu {
    sfTexture *back_text;
    sfSprite *background;
    menu_button_t *buttons;
} ig_menu_t;

void run_menu(gamestate_t *gamestate, menu_t *menu,
    ig_menu_t *ig_menu, npc_t *mobs);
menu_button_t *init_buttons(void);
void update_bounds(menu_button_t *buttons, sfRenderWindow* window, int nb);
void update_states(menu_button_t *buttons, sfRenderWindow *window, int nb);
void update_colors(menu_button_t *buttons, sfColor color, int nb);
void update_text_pos(menu_button_t *buttons, int nb);
menu_t *init_menu(gamestate_t *gamestate);
void run_options(menu_t *menu, gamestate_t *gamestate);
void init_new_button(menu_button_t *button, sfFont *font, char *str,
sfVector2f button_pos);
void display_buttons(sfRenderWindow *window, menu_button_t *buttons, int nb);
void init_opt_buttons(options_t *options, sfRenderWindow *window);
void update_all_bounds(sfRenderWindow* window, options_t *options);
void update_all_buttons(sfRenderWindow *window, options_t *options);
void resize_window(sfRenderWindow *window, options_t *options);
void change_fps(sfRenderWindow *window, options_t *options);
void handle_close_event(sfRenderWindow *window, sfEvent event);

#endif /* MENU_H_ */
