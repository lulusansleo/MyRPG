/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** type
*/

#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "npc.h"

//int my_getnbr_pimp(char **str)
//{
//    int nb = 0;
//    int neg = 1;
//
//    while ((**str == '-' || **str == '+')) {
//        if (**str == '-')
//            neg *= -1;
//        ++(*str);
//    }
//    while ((**str >= '0' && **str <= '9')) {
//        nb = nb * 10 + **str - '0';
//        (*str)++;
//    }
//    while ((**str == ',' || **str == ' '))
//        ++(*str);
//    return (nb * neg);
//}

npc_t *add_mob_from_line(npc_t *head, char *line)
{
    int x;
    int y;
    int type;

    type = my_getnbr_pimp(&line);
    x = my_getnbr_pimp(&line);
    y = my_getnbr_pimp(&line);

    return add_node(head, x, y, type);
}

npc_t *load_mobs_from_file(const char *filepath)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    npc_t *mobs_list = NULL;

    file = fopen(filepath, "r");

    if (file == NULL) {
        return NULL;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        mobs_list = add_mob_from_line(mobs_list, line);
    }
    free(line);
    fclose(file);
    return mobs_list;
}
