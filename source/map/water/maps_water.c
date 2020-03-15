/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** maps_water
*/

#include "my_world.h"

int init_water(map_t *maps, water_t *water)
{
    unsigned int tile_map_len = 0;

    tile_map_len = maps->width * maps->height + (maps->width - 1) *
    (maps->height - 1);
    water->water_2d = (sfVector2f **)my_malloc_type(maps->height, maps->width,
    sizeof(sfVector2f *), sizeof(sfVector2f));
    water->tile = malloc(sizeof(sfVertexArray *) * (maps->width - 1) *
    (maps->height - 1));
    water->line = malloc(sizeof(sfVertexArray *) * (tile_map_len + 1));
    if (water->water_2d == NULL || water->tile == NULL || water->line == NULL)
        return (1);
    return (0);
}

void water_destroy(map_t *maps, water_t *water)
{
    my_free_typoo((void **)water->water_2d);
    for (int e = 0; e < maps->inc_t; ++e)
        sfVertexArray_destroy(water->line[e]);
    for (int e = 0; e < maps->inc_f; ++e)
        sfVertexArray_destroy(water->tile[e]);
    free(water->line);
    free(water->tile);
}