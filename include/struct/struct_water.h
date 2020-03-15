/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_water
*/

#ifndef STRUCT_WATER_H_
#define STRUCT_WATER_H_

#include <SFML/Graphics.h>

typedef struct water_s
{
    unsigned int ic_l;
    unsigned int ic_t;
    sfVector2f **water_2d;
    sfVertexArray **line;
    sfVertexArray **tile;
}water_t;

#endif /* !STRUCT_WATER_H_ */