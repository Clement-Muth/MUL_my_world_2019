/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** water_create
*/

#include "my_world.h"

static sfVertexArray *
create_water(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor c = {.r = 0, .g = 119, .b = 200, .a = 150};
    sfVertex vertex1 = {.position = m->wa.water_2d[co.y][co.x], .color = c};
    sfVertex vertex2 = {.position = m->wa.water_2d[co.y][co.x + ic.x],
    .color = c};
    sfVertex vertex3 = {.position = m->wa.water_2d[co.y + ic.y][co.x + ic.x],
    .color = c};
    sfVertex vertex4 = {.position = m->wa.water_2d[co.y + ic.y][co.x],
    .color = c};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

static sfVertexArray *
create_water_line(map_t *m, sfVector2f *pt_one, sfVector2f *pt_two)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *pt_one, .color = sfWhite};
    sfVertex vertex2 = {.position = *pt_two, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

void create_tile_water(cw_t *cw, map_t *m, int y, int x)
{
    m->wa.tile[m->wa.ic_t++] = create_water(cw, m, (sfVector2i){x, y},
    (sfVector2i){1, 1});
    m->wa.line[m->wa.ic_l++] = create_water_line(m, &m->wa.water_2d[y][x],
    &m->wa.water_2d[y][x + 1]);
    m->wa.line[m->wa.ic_l++] = create_water_line(m, &m->wa.water_2d[y][x],
    &m->wa.water_2d[y + 1][x]);
}

void create_water_2d(cw_t *cw, map_t *maps, int y, int x)
{
    sfVector3f water_3d = maps->map_3d[y][x];

    water_3d.z = -20;
    maps->wa.water_2d[y][x] = project_iso_point(cw, water_3d);
    maps->wa.water_2d[y][x].x += maps->move.x;
    maps->wa.water_2d[y][x].y += maps->move.y;
}