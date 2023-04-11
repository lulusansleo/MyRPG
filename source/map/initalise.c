/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map initialiser
*/

#include "map.h"
#include "my.h"

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

tile_t **initialise_map(char **buffer)
{
    tile_t **map = malloc(sizeof(tile_t *) * (my_array_len(buffer) + 1));
    int len = 0;
    for (len = 0; buffer[len]; len++);
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
