/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** bloc_wall
*/

#include "my_world.h"

void restore_wall_line(sfVertexArray *line, sfVector2f *one,
sfVector2f *two)
{
    sfVertex vertex1 = {.position = *one, .color = sfWhite};
    sfVertex vertex2 = {.position = *two, .color = sfWhite};

    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);
    sfVertexArray_setPrimitiveType(line, sfLinesStrip);
}

void restore_wall(sfVertexArray *quads, tile_t tile, sfColor c)
{
    sfVertex vertex1 = {.position = tile.one, .color = c};
    sfVertex vertex2 = {.position = tile.two, .color = c};
    sfVertex vertex3 = {.position = tile.three, .color = c};
    sfVertex vertex4 = {.position = tile.four, .color = c};

    sfVertexArray_append(quads, vertex1);
    sfVertexArray_append(quads, vertex2);
    sfVertexArray_append(quads, vertex3);
    sfVertexArray_append(quads, vertex4);
    sfVertexArray_setPrimitiveType(quads, sfQuads);
}