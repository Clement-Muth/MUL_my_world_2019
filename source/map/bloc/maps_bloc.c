/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** maps_bloc
*/

#include "my_world.h"

int init_bloc(map_t *maps, bloc_t *bc)
{
    unsigned int nb_bloc_point = maps->width + maps->height;

    bc->c_water = (sfColor){.r = 0, .g = 100, .b = 180, .a = 180};
    bc->soil = (sfColor) {.r = 90, .g = 51, .b = 24, .a = 255};
    bc->bloc_2d = malloc(sizeof(sfVector2f) * nb_bloc_point);
    bc->line = malloc(sizeof(sfVertexArray *) * (nb_bloc_point + 1));
    bc->tile = malloc(sizeof(sfVertexArray *) * (nb_bloc_point - 1));
    bc->water = malloc(sizeof(sfVertexArray *) * (nb_bloc_point - 1));
    if (bc->bloc_2d == NULL || bc->line == NULL || bc->tile == NULL)
        return (1);
    return (0);
}

void bloc_destroy(bloc_t *bc)
{
    free(bc->bloc_2d);
    for (int ic = 0; ic < bc->ic_l; ++ic)
        sfVertexArray_destroy(bc->line[ic]);
    for (int ic = 0; ic < bc->ic_t; ++ic) {
        sfVertexArray_destroy(bc->tile[ic]);
        sfVertexArray_destroy(bc->water[ic]);
    }
    free(bc->line);
    free(bc->tile);
    free(bc->water);
}