/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** bloc_restore
*/

#include "my_world.h"

static void restore_tile_on_x_axes(map_t *map, bloc_t *bc, sfVector2i co)
{
    restore_wall_line(bc->line[bc->ic_l++], &map->map_2d[co.y][0],
        &bc->bloc_2d[bc->ic_b]);
    for (int x = 0; x < map->width - 1; ++x, ++bc->ic_b) {
        restore_wall(bc->water[bc->ic_t],
            (tile_t){map->wa.water_2d[co.y][x], map->wa.water_2d[co.y][x + 1],
            bc->bloc_2d[bc->ic_b + 1], bc->bloc_2d[bc->ic_b]}, bc->c_water);
        restore_wall(bc->tile[bc->ic_t++],
            (tile_t){map->map_2d[co.y][x], map->map_2d[co.y][x + 1],
            bc->bloc_2d[bc->ic_b + 1], bc->bloc_2d[bc->ic_b]}, bc->soil);
        restore_wall_line(bc->line[bc->ic_l++], &bc->bloc_2d[bc->ic_b],
            &bc->bloc_2d[bc->ic_b + 1]);
    }
    restore_wall_line(bc->line[bc->ic_l++], &map->map_2d[co.y][map->width - 1],
        &bc->bloc_2d[bc->ic_b++]);
}

static void restore_tile_on_y_axes(map_t *map, bloc_t *bc, sfVector2i co)
{
    if (co.y == map->height - 1)
        restore_wall_line(bc->line[bc->ic_l++], &map->map_2d[0][co.x],
            &bc->bloc_2d[bc->ic_b]);
    for (int y = 0; y < map->height - 1; ++y, ++bc->ic_b) {
        restore_wall(bc->water[bc->ic_t],
            (tile_t){map->wa.water_2d[y][co.x], map->wa.water_2d[y + 1][co.x],
            bc->bloc_2d[bc->ic_b + 1], bc->bloc_2d[bc->ic_b]}, bc->c_water);
        restore_wall(bc->tile[bc->ic_t++],
            (tile_t){map->map_2d[y][co.x], map->map_2d[y + 1][co.x],
            bc->bloc_2d[bc->ic_b + 1], bc->bloc_2d[bc->ic_b]}, bc->soil);
        restore_wall_line(bc->line[bc->ic_l++], &bc->bloc_2d[bc->ic_b],
            &bc->bloc_2d[bc->ic_b + 1]);
    }
    if (co.y == 0)
        restore_wall_line(bc->line[bc->ic_l++],
            &map->map_2d[map->height - 1][co.x], &bc->bloc_2d[bc->ic_b]);
}

void restore_tile_bloc(cw_t *cw, map_t *map, bloc_t *bc, sfVector2i co)
{
    bc->ic_l = 0;
    bc->ic_t = 0;
    bc->ic_b = 0;
    restore_tile_on_x_axes(map, bc, co);
    restore_tile_on_y_axes(map, bc, co);
}

void restore_bloc(cw_t *cw, map_t *maps, sfVector2i co)
{
    create_point_bloc(cw, maps, &maps->bc, co);
    for (int ic = 0; ic < maps->bc.ic_l; ++ic)
        sfVertexArray_clear(maps->bc.line[ic]);
    for (int ic = 0; ic < maps->bc.ic_t; ++ic) {
        sfVertexArray_clear(maps->bc.tile[ic]);
        sfVertexArray_clear(maps->bc.water[ic]);
    }
    restore_tile_bloc(cw, maps, &maps->bc, co);
}