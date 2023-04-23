/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** saws
*/

#include "moving_saws.h"

static int check_saw(int type)
{
    if (type == 52 || type == 49 || type == 46)
        return (1);
    return (0);
}

static int count_saws(layer_t layer)
{
    int count = 0;
    for (int i = 0; layer.tiles[i]; i++)
        for (int j = 0; layer.tiles[i][j].type != -1; j++)
            count += check_saw(layer.tiles[i][j].type);
    return (count);
}

static saws_t *get_pos_line(layer_t layer, saws_t *saws,
int i, int *count)
{
    for (int j = 0; layer.tiles[i][j].type != -1; j++) {
        if (check_saw(layer.tiles[i][j].type)) {
            saws[*count].pos = (sfVector2f){j * 16.0, i * 16.0};
            *count += 1;
        }
    }
    return (saws);
}

static saws_t *get_pos_saws(layer_t layer, saws_t *saws)
{
    int *count = malloc(sizeof(int));
    *count = 0;
    for (int i = 0; layer.tiles[i]; i++) {
        get_pos_line(layer, saws, i, count);
    }
    free(count);
    return (saws);
}

saws_t *init_saws(layer_t *layers)
{
    int count = count_saws(layers[3]);
    saws_t* saws = malloc(sizeof(saws_t) * count + 1);
    for (int i = 0; i < count; i++) {
        saws[i].speed = (sfVector2f){0.2, 0};
    }
    saws = get_pos_saws(layers[3], saws);
    saws[count].pos = (sfVector2f){-1, -1};
    return (saws);
}
