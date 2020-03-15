/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** restore_tile_line
*/

#include "my_world.h"

void restore_line(map_t *m, sfVertexArray *line, sfVector2f *one,
sfVector2f *two)
{
    sfVertex vertex1 = {.position = *one, .color = sfWhite};
    sfVertex vertex2 = {.position = *two, .color = sfWhite};

    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);
    sfVertexArray_setPrimitiveType(line, sfLinesStrip);
}

static void restore_tile(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic)
{
    sfColor c = shade_color(cw, m, co, ic);
    sfVertex vertex1 = {.position = m->map_2d[co.y][co.x], .color = c};
    sfVertex vertex2 = {.position = m->map_2d[co.y][co.x + ic.x], .color = c};
    sfVertex vertex3 = {.position = m->map_2d[co.y + ic.y][co.x + ic.x],
    .color = c};
    sfVertex vertex4 = {.position = m->map_2d[co.y + ic.y][co.x], .color = c};

    sfVertexArray_append(m->fill_tile[m->inc_f], vertex1);
    sfVertexArray_append(m->fill_tile[m->inc_f], vertex2);
    sfVertexArray_append(m->fill_tile[m->inc_f], vertex3);
    sfVertexArray_append(m->fill_tile[m->inc_f], vertex4);
    sfVertexArray_setPrimitiveType(m->fill_tile[m->inc_f], sfQuads);
}

void restore_tile_map_loop(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic)
{
    restore_tile(cw, m, co, ic);
    ++m->inc_f;
    restore_line(m, m->tile_map[m->inc_t++], &m->map_2d[co.y][co.x],
    &m->map_2d[co.y][co.x + ic.x]);
    restore_line(m, m->tile_map[m->inc_t++], &m->map_2d[co.y][co.x],
    &m->map_2d[co.y + ic.y][co.x]);
}