/*
** EPITECH PROJECT, 2020
** MUL_my_world_object_2019
** File description:
** window_event
*/

#include "my_world.h"

void line_on_off(cw_t *cw, map_t *maps)
{
    ++cw->ev.line_on;
    if (cw->ev.line_on > 2)
        cw->ev.line_on = 0;
}

int event_root(cw_t *cw, map_t *maps)
{
    void (*event[])(cw_t *, map_t *) = {left_rotation, right_rotation,
    up_rotation, down_rotation, move_view_backward, move_view_forward,
    shrink_selection_area , extend_selection_area, sun_rise, more_sun_power,
    less_sun_power, select_mode, select_effect, line_on_off, reset, save, load};
    sfKeyCode key[] = {sfKeyLeft, sfKeyRight, sfKeyUp, sfKeyDown, sfKeyX,
    sfKeyC, sfKeyA, sfKeyZ, sfKeyS, sfKeyM, sfKeyL, sfKeyP, sfKeyE, sfKeyO,
    sfKeyR, sfKeyV, sfKeyB};

    cw->ev.mouse_moved = 1;
    if (cw->event.type == sfEvtClosed)
        sfRenderWindow_close(cw->window);
    for (int ic = 0; ic < 17; ++ic) {
        if (sfKeyboard_isKeyPressed(key[ic])) {
            (*event[ic])(cw, maps);
            cw->ev.on = 1;
        }
        if (cw->ev.ret_value) return (1);
    }
    choice_selection(cw, maps);
    return (0);
}