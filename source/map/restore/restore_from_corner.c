/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** restore_from_corner
*/

#include "my_world.h"

static void restore_tile_map_up_left(cw_t *cw, map_t *maps)
{
    sfVector2i co;
    sfVector2i ic = {1, 1};

    maps->inc_t = 0;
    maps->inc_f = 0;
    maps->wa.ic_l = 0;
    maps->wa.ic_t = 0;
    for (co.y = 0; co.y < maps->height - 1; ++co.y) {
        for (co.x = 0; co.x < maps->width - 1; ++co.x) {
            restore_tile_map_loop(cw, maps, co, ic);
            restore_tile_water(maps, co, ic);
        }
    }
    for (int x = 0; x < maps->width - 1; ++x, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d
        [maps->height - 1][x], &maps->map_2d[maps->height - 1][x + 1]);
    for (int y = 0; y < maps->height - 1; ++y, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d[y]
        [maps->width - 1], &maps->map_2d[y + 1][maps->width - 1]);
}

static void restore_tile_map_up_right(cw_t *cw, map_t *maps)
{
    sfVector2i co;
    sfVector2i ic = {-1, 1};

    maps->inc_t = 0;
    maps->inc_f = 0;
    maps->wa.ic_l = 0;
    maps->wa.ic_t = 0;
    for (co.y = 0; co.y < maps->height - 1; ++co.y) {
        for (co.x = maps->width - 1; co.x > 0; --co.x) {
            restore_tile_map_loop(cw, maps, co, ic);
            restore_tile_water(maps, co, ic);
        }
    }
    for (int x =  maps->width - 1; x > 0; --x, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d
        [maps->height - 1][x], &maps->map_2d[maps->height - 1][x - 1]);
    for (int y = 0; y < maps->height - 1; ++y, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d[y]
        [0], &maps->map_2d[y + 1][0]);
}

static void restore_tile_map_down_left(cw_t *cw, map_t *maps)
{
    sfVector2i co;
    sfVector2i ic = {1, -1};

    maps->inc_t = 0;
    maps->inc_f = 0;
    maps->wa.ic_l = 0;
    maps->wa.ic_t = 0;
    for (co.y = maps->height - 1; co.y > 0; --co.y) {
        for (co.x = 0; co.x < maps->width - 1; ++co.x) {
            restore_tile_map_loop(cw, maps, co, ic);
            restore_tile_water(maps, co, ic);
        }
    }
    for (int x = 0; x < maps->width - 1; ++x, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d
        [0][x], &maps->map_2d[0][x + 1]);
    for (int y = maps->height - 1; y > 0; --y, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d[y]
        [maps->width - 1], &maps->map_2d[y - 1][maps->width - 1]);
}

static void restore_tile_map_down_right(cw_t *cw, map_t *maps)
{
    sfVector2i co;
    sfVector2i ic = {-1, -1};

    maps->inc_t = 0;
    maps->inc_f = 0;
    maps->wa.ic_l = 0;
    maps->wa.ic_t = 0;
    for (co.y = maps->height - 1; co.y > 0; --co.y) {
        for (co.x = maps->width - 1; co.x > 0; --co.x) {
            restore_tile_map_loop(cw, maps, co, ic);
            restore_tile_water(maps, co, ic);
        }
    }
    for (int x = maps->width - 1; x > 0; --x, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d
        [0][x], &maps->map_2d[0][x - 1]);
    for (int y = maps->height - 1; y > 0; --y, ++maps->inc_t)
        restore_line(maps, maps->tile_map[maps->inc_t], &maps->map_2d[y]
        [0], &maps->map_2d[y - 1][0]);
}

void restore_order_according_rotation(cw_t *cw, map_t *maps)
{
    int corner = cw->ev.rotate_h / 0.784;

    if (corner < 0)
        corner += 7;
    if (corner == 0 || corner == 7) {
        restore_bloc(cw, maps, (sfVector2i){maps->width - 1, maps->height - 1});
        restore_tile_map_up_left(cw, maps);
    } else if (corner == 1 || corner == 2) {
        restore_bloc(cw, maps, (sfVector2i){maps->width - 1, 0});
        restore_tile_map_down_left(cw, maps);
    }
    if (corner == 3 || corner == 4) {
        restore_bloc(cw, maps, (sfVector2i){0, 0});
        restore_tile_map_down_right(cw, maps);
    } else if (corner == 5 || corner == 6) {
        restore_bloc(cw, maps, (sfVector2i){0, maps->height - 1});
        restore_tile_map_up_right(cw, maps);
    }
}