/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** framebuffer_display
*/

#include "my_world.h"

void framebuffer_display(cw_t *cw, map_t *maps)
{
    if (cw->ev.select_mode == 0)
        put_select_area_red(cw, maps, &maps->ci.area);
    else if (cw->ev.select_mode == 1)
        put_select_area_blue(cw, maps, &maps->ci.area);
}