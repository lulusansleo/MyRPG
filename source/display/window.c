/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window
*/

#include "window.h"

sfRenderWindow *initalise_window(void)
{
    sfVideoMode mode = {600, 600, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(mode, "MyRPG", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
