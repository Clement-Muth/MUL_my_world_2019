/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** area_all_direction
*/

#include "my_world.h"

void inc_four_direction(map_t *map, select_t *ci, int i, int inc)
{
    map->map_3d[ci->near.y + i][ci->near.x + i].z += inc;
    map->map_3d[ci->near.y + i][ci->near.x - i].z += inc;
    map->map_3d[ci->near.y - i][ci->near.x - i].z += inc;
    map->map_3d[ci->near.y - i][ci->near.x + i].z += inc;
}

void inc_between_direction(map_t *maps, select_t *ci, int i, int inc)
{
    int x = i;
    int y = i;

    for (int xx = x - 1; xx != -x; --xx) {
        maps->map_3d[ci->near.y + y][ci->near.x + xx].z += inc;
        maps->map_3d[ci->near.y - y][ci->near.x + xx].z += inc;
    }
    for (int yy = y - 1; yy != -y; --yy) {
        maps->map_3d[ci->near.y + yy][ci->near.x + x].z += inc;
        maps->map_3d[ci->near.y + yy][ci->near.x - x].z += inc;
    }
}

void inc_lastest_square(map_t *maps, select_t *ci, int i, int inc)
{
    int x = i;
    int y = i;
    ci->end = 0;

    for (int xx = x; xx != -x - 1; --xx) {
        if (inside_the_area(maps, ci, xx, y))
            maps->map_3d[ci->near.y + y][ci->near.x + xx].z += inc;
        if (inside_the_area(maps, ci, xx, -y))
            maps->map_3d[ci->near.y - y][ci->near.x + xx].z += inc;
    }
    for (int yy = y - 1; yy != -y; --yy) {
        if (inside_the_area(maps, ci, x, yy))
            maps->map_3d[ci->near.y + yy][ci->near.x + x].z += inc;
        if (inside_the_area(maps, ci, -x, yy))
            maps->map_3d[ci->near.y + yy][ci->near.x - x].z += inc;
    }
}