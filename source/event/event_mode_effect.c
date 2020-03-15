/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_mode_effect
*/

#include "my_world.h"

void select_mode(cw_t *cw, map_t *map)
{
    ++cw->ev.select_mode;
    if (cw->ev.select_mode > 2)
        cw->ev.select_mode = 0;
}

void select_effect(cw_t *cw, map_t *map)
{
    ++cw->ev.select_effect;
    if (cw->ev.select_effect > 2)
        cw->ev.select_effect = 0;
}
