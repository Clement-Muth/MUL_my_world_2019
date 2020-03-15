/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_sun
*/

#include "my_world.h"

void sun_rise(cw_t *cw, map_t *m)
{
    if ((m->sh.ic.x == 1 && m->sh.ic.y == 1)
    || (m->sh.ic.x == -1 && m->sh.ic.y == -1)) {
        m->sh.sun.z = cos(m->sh.sun_rise);
        m->sh.sun.y = sin(m->sh.sun_rise);
    } else if ((m->sh.ic.x == -1 && m->sh.ic.y == 1)
    || (m->sh.ic.x == 1 && m->sh.ic.y == -1)) {
        m->sh.sun.z = cos(m->sh.sun_rise);
        m->sh.sun.y = sin(m->sh.sun_rise);
    }
    m->sh.sun_rise += 0.005;
}

void more_sun_power(cw_t *cw, map_t *m)
{
    if (m->sh.sun_power < 35)
        ++m->sh.sun_power;
}

void less_sun_power(cw_t *cw, map_t *m)
{
    if (m->sh.sun_power > 0)
        --m->sh.sun_power;
}