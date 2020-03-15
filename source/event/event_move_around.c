/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_move_around
*/

#include "my_world.h"

void up_rotation(cw_t *cw, map_t *maps)
{
    cw->ev.rotate_v += 2;
}

void down_rotation(cw_t *cw, map_t *maps)
{
    cw->ev.rotate_v -= 2;
}

void left_rotation(cw_t *cw, map_t *maps)
{
    cw->ev.rotate_h -= 0.02;
    if (cw->ev.rotate_h <= -6.26)
        cw->ev.rotate_h = 0.0;
}

void right_rotation(cw_t *cw, map_t *maps)
{
    cw->ev.rotate_h += 0.02;
    if (cw->ev.rotate_h >= 6.26)
        cw->ev.rotate_h = 0.0;
}
