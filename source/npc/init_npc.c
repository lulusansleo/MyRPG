/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** init_npc
*/

#include "player.h"
#include "graphical.h"

#include <stdlib.h>
#include <time.h>


int random_direction(void)
{
    int direction = rand() % 4;
    return direction;
}

void update_npc_position(entity_t *entity, int direction)
{
    float deltaTime = sfTime_asSeconds(sfClock_getElapsedTime(entity->clock));

    if (deltaTime > 0.8) {
        switch (direction) {
            case 0:
                entity->pos.y -= entity->speed;
                break;
            case 1:
                entity->pos.y += entity->speed;
                break;
            case 2:
                entity->pos.x -= entity->speed;
                break;
            case 3:
                entity->pos.x += entity->speed;
        }
        sfClock_restart(entity->clock);
    }

    sfSprite_setPosition(entity->sprite, entity->pos);
}

sfVector2f random_position(float maxX, float maxY)
{
    float x = (float)(rand() % (int)maxX);
    float y = (float)(rand() % (int)maxY);
    return (sfVector2f){x, y};
}

entity_t *init_entity_npc(char *path, float x, float y)
{
    srand(time(NULL));

    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = (sfVector2f){x, y};
    entity->speed = 8;
    entity->clock = sfClock_create();
    entity->rect = (sfIntRect){0, 0, 16, 16};
    entity->texture = sfTexture_createFromFile(path, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setPosition(entity->sprite, entity->pos);

    int direction = random_direction();
    update_npc_position(entity, direction);

    return (entity);
}

game_elements_t init_game_elements(void)
{
    game_elements_t game_elements;

    game_elements.window = initalise_window();
    game_elements.event = malloc(sizeof(sfEvent));
    game_elements.layers = initialise_layer();
    game_elements.player = init_entity(TXT_PLYR);

    game_elements.mobs = malloc(NUM_MOBS * sizeof(entity_t *));
    for (int i = 0; i < NUM_MOBS; i++) {
        sfVector2f random_pos = random_position(MAX_X, MAX_Y);
        game_elements.mobs[i] = init_entity_npc(TXT_NPC,
        random_pos.x, random_pos.y);
    }

    game_elements.npc_move_clock = sfClock_create();

    return game_elements;
}
