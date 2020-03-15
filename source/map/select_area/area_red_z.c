/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_inc_z
*/

#include "my_world.h"

float length_vector(sfVector2f a, sfVector3f b)
{
    return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int inside_the_area(map_t *maps, select_t *ci, int x, int y)
{
    if (ci->near.x + x < 0 || ci->near.x + x >= maps->width ||
        ci->near.x + y < 0 || ci->near.y + y >= maps->height)
        return (0);
    if (length_vector(ci->area.co, maps->map_3d[ci->near.y + y][ci->near.x + x])
    < maps->ci.area.radius) {
        ++ci->end;
        return (1);
    }
    return (0);
}

void area_red_z(cw_t *cw, map_t *maps, select_t *ci, int inc)
{
    int i = 1;

    ci->inc = inc;
    if (find_nearest_point_to_center(cw, maps, ci))
        return;
    maps->map_3d[ci->near.y][ci->near.x].z += inc;
    for (i = 1; VERIFY && IF_INC_X && IF_INC_Y && IF_DEC_X && IF_DEC_Y; ++i) {
        inc_four_direction(maps, ci, i, inc);
        inc_between_direction(maps, ci, i, inc);
    }
    for (ci->end = 1; ci->end != 0; ++i) {
        inc_lastest_square(maps, ci, i, inc);
    }
}