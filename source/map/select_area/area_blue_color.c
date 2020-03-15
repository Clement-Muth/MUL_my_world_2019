/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** area_blue_color
*/

#include "my_world.h"

void area_blue_color(cw_t *cw, map_t *m, select_t *ci)
{
    sfVector2i mouse = sfMPos(cw->window);
    int already_x = 0;
    int already_y = 0;

    for (int y = 0; y < m->height; ++y) {
        for (int x = 0; x < m->width; ++x) {
            if (in_circle(m->map_2d[y][x], mouse, ci->area.radius)) {
                m->tile_cl[y][x] = ci->new_clr;
                m->clr[y][x] = 1;
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
