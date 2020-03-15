/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_area
*/

#ifndef STRUCT_AREA_H_
#define STRUCT_AREA_H_

#include <SFML/Graphics.h>
#include "struct_framebuffer.h"

typedef struct select_s
{
    int inc;
    int end;
    int close;
    int *max;
    float *square;
    sfColor new_clr;
    sfVector2i near;
    circle_t area;
}select_t;

#endif /* !STRUCT_AREA_H_ */