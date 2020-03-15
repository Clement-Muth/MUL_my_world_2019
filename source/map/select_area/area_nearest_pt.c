/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** area_nearest_pt
*/

#include "my_world.h"

static void
in_loop_nearest_pt(map_t *maps, sfVector2i *pt, sfVector2f norot, int e)
{
    if (e == 1 || e == 3)
        ++pt->y;
    if (e == 2) {
        ++pt->x;
        --pt->y;
    }
    if (pt->x < maps->width && pt->y < maps->height) {
            maps->ci.square[e] = length_vector(norot,
            maps->map_3d[pt->y][pt->x]);
        if (maps->ci.square[e] <= maps->ci.square[maps->ci.close]) {
            maps->ci.close = e;
            maps->ci.near = *pt;
        }
    }
}

void limitation_nearest_pt(map_t *maps, sfVector2i *pt)
{
    if (pt->x <= 0) pt->x = 0;
    if (pt->y <= 0) pt->y = 0;
    if (pt->x >= maps->width) pt->x = maps->width - 1;
    if (pt->y >= maps->height) pt->y = maps->height - 1;
}

int find_nearest_point_to_center(cw_t *cw, map_t *maps, select_t *ci)
{
    sfVector2i pt;
    sfVector2f mouse = invers_project_with_rotate(cw, maps, sfMPos(cw->window));
    sfVector2f norot = invers_project_no_rotate(cw, maps, sfMPos(cw->window));

    pt.x = mouse.x / cw->ev.square_l;
    pt.y = mouse.y / cw->ev.square_l;
    limitation_nearest_pt(maps, &pt);
    ci->close = 0;
    for (int e = 0; e < 4; ++e)
        in_loop_nearest_pt(maps, &pt, norot, e);
    if (!inside_the_area(maps, &maps->ci, 0, 0))
        return (1);
    return (0);
}