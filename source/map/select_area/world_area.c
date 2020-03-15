/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world_area
*/

#include "my_world.h"

int init_select_area(select_t *ci)
{
    ci->new_clr = sfBlue;
    ci->area.radius = 100;
    ci->square = malloc(sizeof(float) * 5);
    ci->max = malloc(sizeof(int) * 5);
    color_declaration(&ci->area.color, 255, 0, 0);
    if (ci->square == NULL && ci->max == NULL)
        return (1);
    return (0);
}

void area_destroy(select_t *ci)
{
    free(ci->square);
    free(ci->max);
}