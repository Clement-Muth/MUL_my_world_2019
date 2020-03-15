/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** area_color
*/

#include "my_world.h"

static void colored_four_direction(map_t *map, select_t *ci, int i)
{
    map->tile_cl[ci->near.y + i][ci->near.x + i] = ci->new_clr;
    map->tile_cl[ci->near.y + i][ci->near.x - i] = ci->new_clr;
    map->tile_cl[ci->near.y - i][ci->near.x - i] = ci->new_clr;
    map->tile_cl[ci->near.y - i][ci->near.x + i] = ci->new_clr;
    map->clr[ci->near.y + i][ci->near.x + i] = 1;
    map->clr[ci->near.y + i][ci->near.x - i] = 1;
    map->clr[ci->near.y - i][ci->near.x - i] = 1;
    map->clr[ci->near.y - i][ci->near.x + i] = 1;
}

static void colored_between_direction(map_t *maps, select_t *ci, int i)
{
    int x = i;
    int y = i;

    for (int xx = x - 1; xx != -x; --xx) {
        maps->tile_cl[ci->near.y + y][ci->near.x + xx] = ci->new_clr;
        maps->tile_cl[ci->near.y - y][ci->near.x + xx] = ci->new_clr;
        maps->clr[ci->near.y + y][ci->near.x + xx] = 1;
        maps->clr[ci->near.y - y][ci->near.x + xx] = 1;
    }
    for (int yy = y - 1; yy != -y; --yy) {
        maps->tile_cl[ci->near.y + yy][ci->near.x + x] = ci->new_clr;
        maps->tile_cl[ci->near.y + yy][ci->near.x - x] = ci->new_clr;
        maps->clr[ci->near.y + yy][ci->near.x + x] = 1;
        maps->clr[ci->near.y + yy][ci->near.x - x] = 1;
    }
}

static void colored_lastest_square_y(map_t *maps, select_t *ci, int i)
{
    int y = i;
    int x = i;

    for (int yy = y - 1; yy != -y; --yy) {
        if (inside_the_area(maps, ci, x, yy)) {
            maps->tile_cl[ci->near.y + yy][ci->near.x + x] = ci->new_clr;
            maps->clr[ci->near.y + yy][ci->near.x + x] = 1;
        }
        if (inside_the_area(maps, ci, -x, yy)) {
            maps->tile_cl[ci->near.y + yy][ci->near.x - x] = ci->new_clr;
            maps->clr[ci->near.y + yy][ci->near.x - x] = 1;
        }
    }
}

static void colored_lastest_square_x(map_t *maps, select_t *ci, int i)
{
    int x = i;
    int y = i;
    ci->end = 0;

    for (int xx = x; xx != -x - 1; --xx) {
        if (inside_the_area(maps, ci, xx, y)) {
            maps->tile_cl[ci->near.y + y][ci->near.x + xx] = ci->new_clr;
            maps->clr[ci->near.y + y][ci->near.x + xx] = 1;
        }
        if (inside_the_area(maps, ci, xx, -y)) {
            maps->tile_cl[ci->near.y - y][ci->near.x + xx] = ci->new_clr;
            maps->clr[ci->near.y - y][ci->near.x + xx] = 1;
        }
    }
}

void area_red_color(cw_t *cw, map_t *maps, select_t *ci)
{
    int i = 1;

    if (find_nearest_point_to_center(cw, maps, ci))
        return;
    maps->tile_cl[ci->near.y][ci->near.x] = ci->new_clr;
    maps->clr[ci->near.y][ci->near.x] = 1;
    for (i = 1; VERIFY && IF_INC_X && IF_INC_Y && IF_DEC_X && IF_DEC_Y; ++i) {
        colored_four_direction(maps, ci, i);
        colored_between_direction(maps, ci, i);
    }
    for (ci->end = 1; ci->end != 0; ++i) {
        colored_lastest_square_x(maps, ci, i);
        colored_lastest_square_y(maps, ci, i);
    }
}