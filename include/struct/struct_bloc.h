/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_bloc
*/

#ifndef STRUCT_BLOC_H_
#define STRUCT_BLOC_H_

#include <SFML/Graphics.h>

typedef struct tile_s
{
    sfVector2f one;
    sfVector2f two;
    sfVector2f three;
    sfVector2f four;
}tile_t;

typedef struct bloc_s
{
    unsigned int ic_b;
    unsigned int ic_t;
    unsigned int ic_l;
    float bloc_height;
    sfColor c_water;
    sfColor soil;
    sfVector2f *bloc_2d;
    sfVertexArray **tile;
    sfVertexArray **water;
    sfVertexArray **line;
}bloc_t;

#endif /* !STRUCT_BLOC_H_ */