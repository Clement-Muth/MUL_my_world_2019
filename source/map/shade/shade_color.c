/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** shade_color
*/

#include "my_world.h"

static sfColor color_caculation(shade_t *sh, float z, int e)
{
    sfColor color;
    float dif = 0;

    dif = z - sh->stage[e].high;
    color = sh->stage[e].cl;
    color.r += dif * sh->stage[e].ic_r;
    color.g += dif * sh->stage[e].ic_g;
    color.b += dif * sh->stage[e].ic_b;
    return (color);
}

static void sun(shade_t *sh, sfVector2i ic)
{
    if ((ic.x == 1 && ic.y == 1) || (ic.x == -1 && ic.y == -1)) {
        sh->sun_rise += PI;
        sh->sun.y = -sh->sun.y;
        sh->sun.z = -sh->sun.z;
    } else if ((ic.x == -1 && ic.y == 1) || (ic.x == 1 && ic.y == -1)) {
        sh->sun_rise += PI;
        sh->sun.y = -sh->sun.y;
        sh->sun.z = -sh->sun.z;
    }
}

static sfColor depend_rotate(map_t *m, sfVector2i co, sfVector2i ic)
{
    if (ic.y == 1 && ic.x == 1)
        return (m->tile_cl[co.y][co.x]);
    else if (ic.y == 1 && ic.x == -1)
        return (m->tile_cl[co.y][co.x - 1]);
    if (ic.y == -1 && ic.x == 1)
        return (m->tile_cl[co.y - 1][co.x]);
    return (m->tile_cl[co.y - 1][co.x - 1]);
}

sfColor shade_color(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic)
{
    float z = (m->map_3d[co.y][co.x].z + m->map_3d[co.y  + ic.y][co.x].z + m->
    map_3d[co.y][co.x  + ic.x].z + m->map_3d[co.y  + ic.y][co.x + ic.x].z) / 4;

    if (m->sh.ic.x != ic.x || m->sh.ic.y != ic.y) sun(&m->sh, ic);
    m->sh.co = co;
    m->sh.ic = ic;
    if (m->clr[co.y][co.x] == 1)
        return (shade_shadow(cw, m->map_3d, &m->sh, depend_rotate(m, co, ic)));
    if (z <= m->sh.stage[0].high)
        return (shade_shadow(cw, m->map_3d, &m->sh, m->sh.stage[0].cl));
    for (int e = 0; e < m->sh.ic_s - 1; ++e)
        if (z >= m->sh.stage[e].high && z < m->sh.stage[e + 1].high)
            return (shade_shadow(cw, m->map_3d, &m->sh,
            color_caculation(&m->sh, z, e)));
    return (shade_shadow(cw, m->map_3d, &m->sh,
    m->sh.stage[m->sh.ic_s - 1].cl));
}