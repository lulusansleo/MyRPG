/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map initialiser
*/

#include "map.h"
#include "my.h"

char **get_array_from_source(char *source)
{
    int fd = open(source, O_RDONLY);
    struct stat st;
    char *buffer;
    stat(source, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    char **double_array = my_str_to_word_array_sep(buffer, '\n');
    free(buffer);
    return (double_array);
}

int my_getnbr_pimp(char **str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (**str == '-' || **str == '+') {
        if (**str == '-')
            neg *= -1;
        ++(*str);
    }
    while (**str >= '0' && **str <= '9') {
        nb = nb * 10 + **str - '0';
        (*str)++;
    }
    while (**str == ',' || **str == ' ')
        ++(*str);
    return (nb * neg);
}

tile_t *getnbr_on_line(char **line, tile_t *map_line, int len)
{
    for (int i = 0; i < len; i++) {
        map_line[i].type = my_getnbr_pimp(line);
    }
    map_line[len].type = -1;
    return (map_line);
}

tile_t **initialise_map(char *source)
{
    char **buffer = get_array_from_source(source);
    tile_t **map = malloc(sizeof(tile_t *) * (my_array_len(buffer) + 1));
    int len = 0;
    for (len = 0; buffer[0][len] != '\0'; len++);
    char *copy = malloc(sizeof(char) * (my_strlen(buffer[0]) + 1));
    char *tmp = copy;

    map[my_array_len(buffer)] = NULL;
    for (int i = 0; buffer[i]; i++) {
        map[i] = malloc(sizeof(tile_t) * (len + 1));
        copy = tmp;
        copy = my_strncpy(copy, buffer[i], my_strlen(buffer[i]));
        map[i] = getnbr_on_line(&copy, map[i], len);
        free(buffer[i]);
    }
    free(buffer);
    return (map);
}

layer_t *initialise_layer(void)
{
    layer_t *layer = malloc(sizeof(layer_t) * 3);
    layer[0].tiles = initialise_map("ressources/first_level/walls.txt");
    layer[0].sprite_sheet = initialise_tileset("ressources/sprites/walls.png");
    layer[1].tiles = initialise_map("ressources/first_level/floor.txt");
    layer[1].sprite_sheet = initialise_tileset("ressources/sprites/floor.png");
// layer[2].tiles = initialise_map("ressources/first_level/objects.txt");
// layer[2].sprite_sheet = initialise_tileset("ressources/sprites/objects.png");
    return (layer);
}
