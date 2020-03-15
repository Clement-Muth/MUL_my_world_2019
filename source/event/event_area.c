/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_area_maps
*/

#include "my_world.h"

void shrink_selection_area(cw_t *cw, map_t *maps)
{
    maps->ci.area.radius *= 0.98;
}

void extend_selection_area(cw_t *cw, map_t *maps)
{
    maps->ci.area.radius *= 1.02;
}