/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** maps_create
*/

#include "my_world.h"

static void inside_create_tile_map(cw_t *cw, map_t *maps, int y, int x)
{
    maps->fill_tile[maps->inc_f++] = create_tile(cw, maps,
    (sfVector2i){x, y}, (sfVector2i){1, 1});
    maps->tile_map[maps->inc_t++] = create_line(maps, &maps->map_2d[y][x],
    &maps->map_2d[y][x + 1]);
    maps->tile_map[maps->inc_t++] = create_line(maps, &maps->map_2d[y][x],
    &maps->map_2d[y + 1][x]);
}

void create_tile_map(cw_t *cw, map_t *maps)
{
    maps->inc_t = 0;
    maps->inc_f = 0;
    maps->wa.ic_l = 0;
    maps->wa.ic_t = 0;
    for (int y = 0; y < maps->height - 1; ++y)
        for (int x = 0; x < maps->width - 1; ++x) {
            create_tile_water(cw, maps, y, x);
            inside_create_tile_map(cw, maps, y, x);
        }
    for (int x = 0; x < maps->width - 1; ++x, ++maps->inc_t, ++maps->wa.ic_l) {
        LAST_LINE_X_MAP;
        LAST_LINE_X_WATER;
    }
    for (int y = 0; y < maps->height - 1; ++y, ++maps->inc_t, ++maps->wa.ic_l) {
        LAST_LINE_Y_MAP;
        LAST_LINE_Y_WATER;
    }
}

void create_map_2d(cw_t *cw, map_t *maps)
{
    int end_x = maps->width - 1;
    int end_y = maps->height - 1;

    maps->move.y = FIND_TRANS_Y;
    maps->move.x = FIND_TRANS_X;
    maps->move.y += (cw->height / 10);
    maps->move.x += (cw->width / 10);
    for (int y = 0; y < maps->height; ++y) {
        for (int x = 0; x < maps->width; ++x) {
            create_water_2d(cw, maps, y, x);
            maps->map_2d[y][x] = project_iso_point(cw, maps->map_3d[y][x]);
            maps->map_2d[y][x].x += maps->move.x;
            maps->map_2d[y][x].y += maps->move.y;
        }
    }
}

void create_map_3d(cw_t *cw, map_t *maps)
{
    float c_x = 0;
    float c_y = 0;

    cw->ev.square_l = find_square_value(cw, maps);
    for (int y = 0; y < maps->height; ++y, c_y += cw->ev.square_l) {
        for (int x = 0; x < maps->width; ++x, c_x += cw->ev.square_l) {
            maps->map_3d[y][x].x = ROTATE_X;
            maps->map_3d[y][x].y = ROTATE_Y;
            maps->map_3d[y][x].z = 0.0;
            maps->clr[y][x] = 0;
        }
        c_x = 0;
    }
    maps->last_tile = maps->map_3d[maps->height - 1][maps->width - 1];
    maps->last_tile.z = 0;
}