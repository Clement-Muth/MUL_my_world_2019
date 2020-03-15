/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world_maps
*/

#include "my_world.h"

int init_all(cw_t *cw, map_t *m)
{
    if (init_maps(m) || init_select_area(&m->ci) || init_bloc(m, &m->bc) ||
    init_water(m, &m->wa) || init_shade(&m->sh))
        return (1);
    return (0);
}

void create_all(cw_t *cw, map_t *m)
{
    create_map_3d(cw, m);
    create_map_2d(cw, m);
    create_bloc(cw, m, (sfVector2i){m->width - 1, m->height - 1});
    create_tile_map(cw, m);
}

int init_all_and_create(cw_t *cw, map_t *maps, createf_t *create)
{
    if (create->new == 0) {
        maps->name = create->filename;
        return (maps_load(cw, maps));
    }
    maps->name = create->title;
    maps->width = my_atoi(create->string[1]);
    maps->height = my_atoi(create->string[2]);
    if (init_all(cw, maps))
        return (1);
    create_all(cw, maps);
    return (0);
}

int init_maps(map_t *maps)
{
    unsigned int line;
    unsigned int tile;

    line = maps->width * maps->height + (maps->width - 1) * (maps->height - 1);
    tile = (maps->width - 1) * (maps->height - 1);
    maps->fill_tile = malloc(sizeof(sfVertexArray *) * tile);
    maps->tile_map = malloc(sizeof(sfVertexArray *) * (line + 1));
    maps->clr = my_malloc_db(maps->height, maps->width);
    maps->tile_cl = (sfColor **)my_malloc_type(maps->height, maps->width
    , sizeof(sfColor *), sizeof(sfColor));
    maps->map_2d = (sfVector2f **)my_malloc_type(maps->height, maps->width,
    sizeof(sfVector2f *), sizeof(sfVector2f));
    maps->map_3d = (sfVector3f **)my_malloc_type(maps->height, maps->width,
    sizeof(sfVector3f *), sizeof(sfVector3f));
    if (maps->map_2d == NULL || maps->map_3d == NULL || maps->tile_map == NULL)
        return (1);
    maps->tile_map[line - 1] = NULL;
    return (0);
}

void maps_destroy(map_t *maps)
{
    my_free_typoo((void **)maps->map_2d);
    my_free_typoo((void **)maps->map_3d);
    my_free_typoo((void **)maps->tile_cl);
    my_free_oo(maps->clr);
    for (int e = 0; e < maps->inc_t; ++e)
        sfVertexArray_destroy(maps->tile_map[e]);
    for (int e = 0; e < maps->inc_f; ++e)
        sfVertexArray_destroy(maps->fill_tile[e]);
    free(maps->tile_map);
    free(maps->fill_tile);
    area_destroy(&maps->ci);
    bloc_destroy(&maps->bc);
    water_destroy(maps, &maps->wa);
    shade_destroy(&maps->sh);
}