/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_reset
*/

#include "my_world.h"

void reset(cw_t *cw, map_t *m)
{
    for (int y = 0; y < m->height; ++y) {
        for (int x = 0; x < m->width; ++x) {
            m->map_3d[y][x].z = 0;
            m->clr[y][x] = 0;
        }
    }
}