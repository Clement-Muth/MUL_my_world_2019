/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_maps
*/

#ifndef STRUCT_MAPS_H_
#define STRUCT_MAPS_H_

#include <SFML/Graphics.h>
#include "struct_area.h"
#include "struct_water.h"
#include "struct_bloc.h"
#include "struct_shade.h"

typedef struct square_s
{
    sfVector3f c_u_right;
    sfVector3f c_d_right;
    sfVector3f c_u_left;
    sfVector3f c_d_left;
    sfVector2f mv_test;
}square_t;

typedef struct map_s
{
    unsigned int width;
    unsigned int height;
    unsigned int inc_t;
    unsigned int inc_f;
    char *name;
    char **clr;
    bloc_t bc;
    select_t ci;
    water_t wa;
    shade_t sh;
    sfVector2f move;
    sfVector3f last_tile;
    sfColor **tile_cl;
    sfVector2f **map_2d;
    sfVector3f **map_3d;
    sfVertexArray **fill_tile;
    sfVertexArray **tile_map;
}map_t;

#endif /* !STRUCT_MAPS_H_ */
