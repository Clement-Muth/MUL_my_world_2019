/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** maps_display
*/

#include "my_world.h"

static void display_with_line(cw_t *cw, map_t *maps)
{
    int f = 0;
    int t = 0;

    for (f = 0; f < maps->inc_f; ++f) {
        sfRenderWindow_drawVertexArray(cw->window, maps->wa.tile[f], NULL);
        sfRenderWindow_drawVertexArray(cw->window, maps->fill_tile[f], NULL);
        sfRenderWindow_drawVertexArray(cw->window, maps->tile_map[t++], NULL);
        sfRenderWindow_drawVertexArray(cw->window, maps->tile_map[t++], NULL);
    }
    bloc_display(cw, &maps->bc);
    for (; t < maps->inc_t; ++t)
        sfRenderWindow_drawVertexArray(cw->window, maps->tile_map[t], NULL);
}

static void display_without_line(cw_t *cw, map_t *maps)
{
    int f = 0;

    for (f = 0; f < maps->inc_f; ++f) {
        sfRenderWindow_drawVertexArray(cw->window, maps->wa.tile[f], NULL);
        sfRenderWindow_drawVertexArray(cw->window, maps->fill_tile[f], NULL);
    }
    bloc_display(cw, &maps->bc);
}

void display_title_map(cw_t *cw, map_t *maps)
{
    if (cw->ev.line_on == 1)
        display_with_line(cw, maps);
    else
        display_without_line(cw, maps);
}