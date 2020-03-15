/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** area_hole
*/

#include "my_world.h"

int in_circle(sfVector2f p, sfVector2i m, int radius)
{
    float len = sqrt((m.x - p.x) * (m.x - p.x) + (m.y - p.y) * (m.y - p.y));

    if (len < radius)
        return (1);
    return (0);
}

void area_blue_z(cw_t *cw, map_t *m, select_t *ci, int inc)
{
    sfVector2i mouse = sfMPos(cw->window);
    int already_x = 0;
    int already_y = 0;

    for (int y = 0; y < m->height; ++y) {
        for (int x = 0; x < m->width; ++x) {
            if (in_circle(m->map_2d[y][x], mouse, ci->area.radius)) {
                m->map_3d[y][x].z += inc;
                already_x = 1;
                already_y = 1;
            } else if (already_x == 1)
                break;
        }
        if (already_x == 0 && already_y == 1)
            break;
        already_x = 0;
    }
}