/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** bloc_create
*/

#include "my_world.h"

void create_point_bloc(cw_t *cw, map_t *maps, bloc_t *bc, sfVector2i co)
{
    sfVector3f bloc_3d;

    bc->ic_b = 0;
    for (int x = 0; x <= maps->width - 1; ++x, ++bc->ic_b) {
        bloc_3d = maps->map_3d[co.y][x];
        if (bloc_3d.z > bc->bloc_height)
            bloc_3d.z = bc->bloc_height;
        bc->bloc_2d[bc->ic_b] = project_iso_point(cw, bloc_3d);
        bc->bloc_2d[bc->ic_b].x += maps->move.x;
        bc->bloc_2d[bc->ic_b].y += maps->move.y;
    }
    for (int y = 0; y <= maps->height - 1; ++y, ++bc->ic_b) {
        bloc_3d = maps->map_3d[y][co.x];
        if (bloc_3d.z > bc->bloc_height)
            bloc_3d.z = bc->bloc_height;
        bc->bloc_2d[bc->ic_b] = project_iso_point(cw, bloc_3d);
        bc->bloc_2d[bc->ic_b].x += maps->move.x;
        bc->bloc_2d[bc->ic_b].y += maps->move.y;
    }
}

static void init_bloc_height(map_t *maps, bloc_t *bloc)
{
    bloc->bloc_height = (maps->width + maps->height) / 2;

    if (bloc->bloc_height < 100) bloc->bloc_height = 100;
    if (bloc->bloc_height > 200) bloc->bloc_height = 200;
    bloc->bloc_height *= -1;
}

void create_bloc(cw_t *cw, map_t *maps, sfVector2i co)
{
    init_bloc_height(maps, &maps->bc);
    create_point_bloc(cw, maps, &maps->bc, co);
    create_tile_bloc(maps, &maps->bc, co);
}