/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_select_mode
*/

#include "my_world.h"

static void red_selection_mode(cw_t *cw, map_t *maps)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (cw->ev.select_effect == 1)
            area_red_z(cw, maps, &maps->ci, 1);
        else if (cw->ev.select_effect == 2)
            area_red_color(cw, maps, &maps->ci);
        cw->ev.on = 1;
    }else if (sfMouse_isButtonPressed(sfMouseRight)
    && cw->ev.select_effect == 1) {
        area_red_z(cw, maps, &maps->ci, -1);
        cw->ev.on = 1;
    }
}

static void blue_selection_mode(cw_t *cw, map_t *maps)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (cw->ev.select_effect == 1)
            area_blue_z(cw, maps, &maps->ci, 1);
        else if (cw->ev.select_effect == 2)
            area_blue_color(cw, maps, &maps->ci);
        cw->ev.on = 1;
    }else if (sfMouse_isButtonPressed(sfMouseRight)
    && cw->ev.select_effect == 1) {
        area_blue_z(cw, maps, &maps->ci, -1);
        cw->ev.on = 1;
    }
}

static void tile_selection_mode(cw_t *cw, map_t *map)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        single_tile(cw, map, 1);
        cw->ev.on = 1;
    }
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        single_tile(cw, map, -1);
        cw->ev.on = 1;
    }
}

void choice_selection(cw_t *cw, map_t *map)
{
    if (cw->ev.select_mode == 0)
        red_selection_mode(cw, map);
    else if (cw->ev.select_mode == 1)
        blue_selection_mode(cw, map);
    if (cw->ev.select_mode == 2)
        tile_selection_mode(cw, map);
}