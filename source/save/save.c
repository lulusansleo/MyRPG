/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** save
*/

#include "gamestate.h"

char *my_itoa(int nb)
{
    int i = 0;
    int tmp = nb;
    char *str = malloc(sizeof(char) * 100);
    for (i = 0; tmp > 0; i++) {
        tmp /= 10;
    }
    str[i] = '\0';
    for (i = i - 1; i >= 0; i--) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}

char *write_number_to_buffer(int nb, char *buffer)
{
    int i = 0;
    for (i = 0; buffer[i] != '\0'; i++);
    char *number = my_itoa(nb);
    for (int j = 0; number[j] != '\0'; j++, i++)
        buffer[i] = number[j];
    buffer[i] = '\n';
    buffer[i + 1] = '\0';
    free(number);
    return (buffer);
}

void write_save(gamestate_t *gamestate)
{
    char *buffer = malloc(sizeof(char) * 100);
    int fd = open("save.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
        return;
    buffer[0] = '\0';
    write_number_to_buffer((int) floor(gamestate->player->pos.x)
    / 16.0, buffer);
    write_number_to_buffer((int) floor(gamestate->player->pos.y)
    / 16.0, buffer);
    // write_number_to_buffer(gamestate->player->level, buffer);
    // write_number_to_buffer(gamestate->player->xp, buffer);
    write_number_to_buffer(gamestate->player->hp, buffer);
    write_number_to_buffer(gamestate->level, buffer);
    write_number_to_buffer(gamestate->floor, buffer);
    write(fd, buffer, my_strlen(buffer));
    free(buffer);
}

gamestate_t *read_save(char *filepath, gamestate_t *gamestate)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100);
    char *ptr = buffer;
    if (fd == -1)
        return (NULL);
    read(fd, buffer, 100);
    printf("%f %f\n", gamestate->player->pos.x, gamestate->player->pos.y);
    // gamestate->player->level = my_getnbr(&ptr);
    // gamestate->player->xp = my_getnbr(&ptr);
    gamestate->player->hp = my_getnbr(&ptr);
    gamestate->level = my_getnbr(&ptr);
    gamestate->floor = my_getnbr(&ptr);
    free(buffer);
    return (gamestate);
}
