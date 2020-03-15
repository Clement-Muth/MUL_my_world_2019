/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_area
*/

#ifndef PROTO_AREA_H_
#define PROTO_AREA_H_

#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"

int init_select_area(select_t *ci);
void area_destroy(select_t *ci);

float length_vector(sfVector2f a, sfVector3f b);
int inside_the_area(map_t *maps, select_t *ci, int x, int y);
void area_red_z(cw_t *cw, map_t *maps, select_t *ci, int inc);

void area_red_color(cw_t *cw, map_t *maps, select_t *ci);

void inc_four_direction(map_t *map, select_t *ci, int i, int inc);
void inc_between_direction(map_t *maps, select_t *ci, int i, int inc);
void inc_lastest_square(map_t *maps, select_t *ci, int i, int inc);

void limitation_nearest_pt(map_t *maps, sfVector2i *pt);
int find_nearest_point_to_center(cw_t *cw, map_t *maps, select_t *ci);

int in_circle(sfVector2f p, sfVector2i m, int radius);
void area_blue_z(cw_t *cw, map_t *maps, select_t *ci, int inc);

void area_blue_color(cw_t *cw, map_t *m, select_t *ci);

void single_tile(cw_t *cw, map_t *maps, int inc);

#endif /* !PROTO_AREA_H_ */