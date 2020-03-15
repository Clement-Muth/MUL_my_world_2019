/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world_isometric
*/

#include "my_world.h"

sfVector2f project_iso_point(cw_t *cw, sfVector3f ddd)
{
    sfVector2f point;

    point.x = cos(0.25) * ddd.x - cos(0.25) * ddd.y;
    point.y = sin(RADIAN(cw->ev.rotate_v)) * ddd.y +
    sin(RADIAN(cw->ev.rotate_v)) * ddd.x - ddd.z;
    return (point);
}

sfVector2f invers_project_no_rotate(cw_t *cw, map_t *maps, sfVector2i dd)
{
    sfVector2f pt;

    dd.x -= maps->move.x;
    dd.y -= maps->move.y;
    pt.x = ((dd.x / cos(0.25)) - (dd.y / sin(RADIAN(cw->ev.rotate_v))))
    * 1 / 2;
    pt.y = (dd.x / cos(0.25)) - pt.x;
    my_swapo(&pt.x, &pt.y);
    pt.y *= -1;
    return (pt);
}

sfVector2f invers_project_with_rotate(cw_t *cw, map_t *maps, sfVector2i dd)
{
    sfVector2f pt;
    sfVector2f rotate;

    dd.x -= maps->move.x;
    dd.y -= maps->move.y;
    pt.x = ((dd.x / cos(0.25)) - (dd.y / sin(RADIAN(cw->ev.rotate_v))))
    * 1 / 2;
    pt.y = (dd.x / cos(0.25)) - pt.x;
    my_swapo(&pt.x, &pt.y);
    pt.y *= -1;
    rotate.x = pt.x * cos(cw->ev.rotate_h) + pt.y * (sin(cw->ev.rotate_h));
    rotate.y = pt.y * cos(cw->ev.rotate_h) - pt.x * (sin(cw->ev.rotate_h));
    return (rotate);
}

sfVertexArray *create_line(map_t *m, sfVector2f *pt_one, sfVector2f *pt_two)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *pt_one, .color = sfWhite};
    sfVertex vertex2 = {.position = *pt_two, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *create_tile(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    m->tile_cl[co.y][co.x] = shade_color(cw, m, co, ic);
    sfVertex vertex1 = {.position = m->map_2d[co.y][co.x],
    .color = m->tile_cl[co.y][co.x]};
    sfVertex vertex2 = {.position = m->map_2d[co.y][co.x + ic.x],
    .color = m->tile_cl[co.y][co.x]};
    sfVertex vertex3 = {.position = m->map_2d[co.y + ic.y][co.x + ic.x],
    .color = m->tile_cl[co.y][co.x]};
    sfVertex vertex4 = {.position = m->map_2d[co.y + ic.y][co.x],
    .color = m->tile_cl[co.y][co.x]};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}