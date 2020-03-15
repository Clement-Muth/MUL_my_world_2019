/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_framebuffer
*/

#ifndef STRUCT_FRAMEBUFFER_H_
#define STRUCT_FRAMEBUFFER_H_

#include <SFML/Graphics.h>

typedef struct color_s
{
    int dark;
    sfUint8 red;
    sfUint8 green;
    sfUint8 blue;
    sfUint8 alpha;
}color_t;

typedef struct circle_s
{
    sfColor color;
    sfVector2f co;
    double radius;
}circle_t;

#endif /* !STRUCT_FRAMEBUFFER_H_ */