/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** area_tile_color
*/

#include "my_world.h"

int find_center_tile(cw_t *cw, map_t *maps, select_t *ci)
{
    sfVector2i pt;
    sfVector2f mouse = invers_project_with_rotate(cw, maps, sfMPos(cw->window));

    pt.x = mouse.x / cw->ev.square_l;
    pt.y = mouse.y / cw->ev.square_l;
    limitation_nearest_pt(maps, &pt);
    maps->ci.near = pt;
    if (!inside_the_area(maps, &maps->ci, 0, 0))
        return (1);
    return (0);
}

void inc_z_single_tile(map_t *maps, select_t *ci, int i, int inc)
{
    maps->map_3d[ci->near.y][ci->near.x].z += inc;
    if (ci->near.y + i < maps->height && IF_INC_Y)
        maps->map_3d[ci->near.y + i][ci->near.x].z += inc;
    if (ci->near.x + i < maps->width && IF_DEC_Y)
        maps->map_3d[ci->near.y][ci->near.x + i].z += inc;
    if (ci->near.x + i < maps->width && ci->near.y + i < maps->height &&
    IF_INC_X)
        maps->map_3d[ci->near.y + i][ci->near.x + i].z += inc;
}

void single_tile(cw_t *cw, map_t *m, int inc)
{
    sfVector2i mouse = sfMPos(cw->window);
    sfVector2i co = {-1 , -1};
    int radius = cw->ev.square_l + 10;

    for (int y = 0; y < m->height; ++y) {
        for (int x = 0; x < m->width; ++x) {
            if (in_circle(m->map_2d[y][x], mouse, radius)) {
                co.y = y;
                co.x = x;
            }
        }
    }
    if (co.y != -1 && cw->ev.select_effect == 1)
        m->map_3d[co.y][co.x].z += inc;
    else if (co.y != -1 && cw->ev.select_effect == 2)
        m->tile_cl[co.y][co.x] = m->ci.new_clr;
}