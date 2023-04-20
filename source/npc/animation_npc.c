/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** animation_npc
*/

#include "player.h"
#include "npc.h"

//void move_rect(my_game_t *animRect)
//{
//    float seconds;
//    sfTime time = sfClock_getElapsedTime(animRect->my_nian->clock);
//    seconds = time.microseconds / 1000000.0;
//
//    if (seconds > 0.2) {
//        if (animRect->my_nian->rect.left >= 750)
//            animRect->my_nian->rect.left = 0;
//        else
//            animRect->my_nian->rect.left += 150;
//        sfSprite_setTextureRect (animRect->my_nian->my_sprite,
//        animRect->my_nian->rect);
//        sfClock_restart(animRect->my_nian->clock);
//    }
//}
//
//void anim_mob(entity_t *animNpc)
//{
//    float AsSeconds;
//
//    sfTime time = sfClock_getElapsedTime(animNpc->sprite);
//
//    AsSeconds = time.microseconds / 1000000.0;
//
//    if (AsSeconds > 0.2) {
//        if (animNpc->sprite)
//    }
//
//    
//}