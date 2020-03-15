/*
** EPITECH PROJECT, 2020
** MUL_my_world_object_2019
** File description:
** maps_restore
*/

#include "my_world.h"

static void restore_map_3d(cw_t *cw, map_t *maps)
{
    float c_x = 0;
    float c_y = 0;

    for (int y = 0; y < maps->height; ++y, c_y += cw->ev.square_l) {
        for (int x = 0; x < maps->width; ++x, c_x += cw->ev.square_l) {
            maps->map_3d[y][x].x = ROTATE_X;
            maps->map_3d[y][x].y = ROTATE_Y;
        }
        c_x = 0;
    }
    maps->last_tile = maps->map_3d[maps->height - 1][maps->width - 1];
    maps->last_tile.z = 0;
}

static void clear_vertex_array(map_t *maps)
{
    for (int e = 0; e < maps->inc_t; ++e) {
        sfVertexArray_clear(maps->tile_map[e]);
        sfVertexArray_clear(maps->wa.line[e]);
    }
    for (int e = 0; e < maps->inc_f; ++e) {
        sfVertexArray_clear(maps->fill_tile[e]);
        sfVertexArray_clear(maps->wa.tile[e]);
    }
}

void restore_maps(cw_t *cw, map_t *maps)
{
    restore_map_3d(cw, maps);
    create_map_2d(cw, maps);
    clear_vertex_array(maps);
    restore_order_according_rotation(cw, maps);
    cw->ev.on = 0;
}