/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_color
*/

#ifndef STRUCT_COLOR_H_
#define STRUCT_COLOR_H_

#include <SFML/Graphics.h>

typedef struct stage_s
{
    sfColor cl;
    int high;
    float ic_r;
    float ic_g;
    float ic_b;
}stage_t;

typedef struct shade_s
{
    int ic_s;
    float sun_power;
    float sun_rise;
    stage_t *stage;
    sfVector2i co;
    sfVector2i ic;
    sfVector3f sun;
}shade_t;

#endif /* !STRUCT_COLOR_H_ */