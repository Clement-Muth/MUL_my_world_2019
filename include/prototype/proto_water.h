/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_water
*/

#ifndef PROTO_WATER_H_
#define PROTO_WATER_H_

#include "../struct/struct_maps.h"
#include "../struct/struct_window.h"

int init_water(map_t *maps, water_t *water);
void water_destroy(map_t *maps, water_t *water);

void create_water_2d(cw_t *cw, map_t *maps, int y, int x);
void create_tile_water(cw_t *cw, map_t *maps, int y, int x);

void restore_tile_water(map_t *maps, sfVector2i co, sfVector2i ic);

#endif /* !PROTO_WATER_H_ */