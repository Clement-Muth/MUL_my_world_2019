/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** water_restore
*/

#include "my_world.h"

static void restore_water_line(sfVertexArray *line, sfVector2f *one,
sfVector2f *two)
{
    sfVertex vertex1 = {.position = *one, .color = sfWhite};
    sfVertex vertex2 = {.position = *two, .color = sfWhite};

    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);
    sfVertexArray_setPrimitiveType(line, sfLinesStrip);
}

static void restore_water_tile(sfVertexArray *quads, sfVector2f **map_2d,
sfVector2i co, sfVector2i ic)
{
    sfColor c = {.r = 0, .g = 119, .b = 200, .a = 150};
    sfVertex vertex1 = {.position = map_2d[co.y][co.x], .color = c};
    sfVertex vertex2 = {.position = map_2d[co.y][co.x + ic.x], .color = c};
    sfVertex vertex3 = {.position = map_2d[co.y + ic.y][co.x + ic.x],
    .color = c};
    sfVertex vertex4 = {.position = map_2d[co.y + ic.y][co.x], .color = c};

    sfVertexArray_append(quads, vertex1);
    sfVertexArray_append(quads, vertex2);
    sfVertexArray_append(quads, vertex3);
    sfVertexArray_append(quads, vertex4);
    sfVertexArray_setPrimitiveType(quads, sfQuads);
}

void restore_tile_water(map_t *maps, sfVector2i co, sfVector2i ic)
{
    restore_water_tile(maps->wa.tile[maps->wa.ic_t++], maps->wa.water_2d,
    co, ic);
    restore_water_line(maps->wa.line[maps->wa.ic_l++],
    &maps->wa.water_2d[co.y][co.x], &maps->wa.water_2d[co.y][co.x + ic.x]);
    restore_water_line(maps->wa.line[maps->wa.ic_l++],
    &maps->wa.water_2d[co.y][co.x], &maps->wa.water_2d[co.y + ic.y][co.x]);
}