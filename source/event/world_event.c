/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world_event
*/

#include "my_world.h"

int init_event(event_t *ev)
{
    ev->on = 1;
    ev->ret_value = 0;
    ev->line_on = 1;
    ev->select_mode = 0;
    ev->select_effect = 0;
    ev->mouse_moved = 1;
    ev->zoom = 1;
    ev->rotate_h = 0;
    ev->rotate_v = 45;
    ev->square_l = 80;
    return (0);
}