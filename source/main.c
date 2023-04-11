/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** main
*/

#include "window.h"
#include "map.h"
#include "my.h"

int main(void)
{
    sfRenderWindow *window = initalise_window();
    sfEvent *event = malloc(sizeof(sfEvent));
    int fd = open("ressources/first_level/walls.txt", O_RDONLY);
    struct stat st;
    char *buffer;
    stat("ressources/first_level/walls.txt", &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    char **double_array = my_str_to_word_array_sep(buffer, '\n');
    tilesheet_t *tileset = initialise_tileset("ressources/sprites/walls.png");
    // for (int i = 0; double_array[i]; i++)
    //     my_printf("%s\n", double_array[i]);
    tile_t **map = initialise_map(double_array);
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j].type != -1; j++) {
            my_printf("%d ", map[i][j].type);
        }
        my_printf("\n");
    }
    free(buffer);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_layer(map, tileset, window);
        sfRenderWindow_display(window);
    }
    return (0);
}
