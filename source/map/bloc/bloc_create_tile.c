/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** bloc_create_tile
*/

#include "my_world.h"

static sfVertexArray *create_wall(sfVector2f one, sfVector2f two,
sfVector2f three, sfVector2f four)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor c = {.r = 97, .g = 51, .b = 24, .a = 255};
    sfVertex vertex1 = {.position = one, .color = c};
    sfVertex vertex2 = {.position = two, .color = c};
    sfVertex vertex3 = {.position = three, .color = c};
    sfVertex vertex4 = {.position = four, .color = c};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

static sfVertexArray *
create_bc_line(map_t *m, sfVector2f *pt_one, sfVector2f *pt_two)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *pt_one, .color = sfWhite};
    sfVertex vertex2 = {.position = *pt_two, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static void tile_on_x_axes(map_t *map, bloc_t *bc, sfVector2i co)
{
    bc->line[bc->ic_l++] = create_bc_line(map, &map->map_2d[co.y][0],
    &bc->bloc_2d[bc->ic_b]);
    for (int x = 0; x < map->width - 1; ++x, ++bc->ic_b) {
        bc->water[bc->ic_t] = create_wall(map->wa.water_2d[co.y][x],
        map->wa.water_2d[co.y][x + 1], bc->bloc_2d[bc->ic_b + 1],
        bc->bloc_2d[bc->ic_b]);
        bc->tile[bc->ic_t++] = create_wall(map->map_2d[co.y][x], map->map_2d
        [co.y][x + 1], bc->bloc_2d[bc->ic_b + 1], bc->bloc_2d[bc->ic_b]);
        bc->line[bc->ic_l++] = create_bc_line(map, &bc->bloc_2d[bc->ic_b],
        &bc->bloc_2d[bc->ic_b + 1]);
    }
    bc->line[bc->ic_l++] = create_bc_line(map,
    &map->map_2d[co.y][map->width - 1], &bc->bloc_2d[bc->ic_b++]);
}

static void tile_on_y_axes(map_t *map, bloc_t *bc, sfVector2i co)
{
    if (co.y == map->height - 1)
        bc->line[bc->ic_l++] = create_bc_line(map, &map->map_2d[0][co.x],
        &bc->bloc_2d[bc->ic_b]);
    for (int y = 0; y < map->height - 1; ++y, ++bc->ic_b) {
        bc->water[bc->ic_t] = create_wall(map->wa.water_2d[y][co.x],
        map->wa.water_2d[y + 1][co.x], bc->bloc_2d[bc->ic_b + 1],
        bc->bloc_2d[bc->ic_b]);
        bc->tile[bc->ic_t++] = create_wall(map->map_2d[y][co.x], map->map_2d
        [y + 1][co.x], bc->bloc_2d[bc->ic_b + 1], bc->bloc_2d[bc->ic_b]);
        bc->line[bc->ic_l++] = create_bc_line(map, &bc->bloc_2d[bc->ic_b],
        &bc->bloc_2d[bc->ic_b + 1]);
    }
    if (co.y == 0)
        bc->line[bc->ic_l++] = create_bc_line(map,
        &map->map_2d[map->height - 1][co.x], &bc->bloc_2d[bc->ic_b]);
}

void create_tile_bloc(map_t *map, bloc_t *bc, sfVector2i co)
{
    bc->ic_l = 0;
    bc->ic_t = 0;
    bc->ic_b = 0;
    tile_on_x_axes(map, bc, co);
    tile_on_y_axes(map, bc, co);
}