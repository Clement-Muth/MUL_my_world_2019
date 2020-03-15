/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_event
*/

#ifndef STRUCT_EVENT_H_
#define STRUCT_EVENT_H_

#include <SFML/Graphics.h>

typedef struct event_s
{
    int on;
    int line_on;
    int select_mode;
    int select_effect;
    int mouse_moved;
    int ret_value;
    float zoom;
    float rotate_h;
    float rotate_v;
    float square_l;
} event_t;

#endif /* !STRUCT_EVENT_H_ */