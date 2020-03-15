/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_move_view
*/

#include "my_world.h"

void move_view_backward(cw_t *cw, map_t *m)
{
    if (cw->ev.zoom > 3)
        return;
    cw->ev.zoom *= 1.01;
    cw->ev.square_l *= 1.01;
    m->bc.bloc_height *= 1.01;
    for (int y = 0; y < m->height; ++y)
        for (int x = 0; x < m->width; ++x)
            m->map_3d[y][x].z *= 1.01;
}

void move_view_forward(cw_t *cw, map_t *m)
{
    if (cw->ev.zoom < 0.2)
        return;
    cw->ev.zoom *= 0.99;
    cw->ev.square_l *= 0.99;
    m->bc.bloc_height *= 0.99;
    for (int y = 0; y < m->height; ++y)
        for (int x = 0; x < m->width; ++x)
            m->map_3d[y][x].z *= 0.99;
}