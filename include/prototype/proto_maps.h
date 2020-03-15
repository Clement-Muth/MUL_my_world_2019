/*
** EPITECH PROJECT, 2020
** MUL_my_world_object_2019
** File description:
** proto_maps
*/

#ifndef PROTO_MAPS_H_
#define PROTO_MAPS_H_

#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"

#define sfMPos sfMouse_getPositionRenderWindow
#define sfVxAr_app sfVertexArray_append

int init_all(cw_t *cw, map_t *m);
void create_all(cw_t *cw, map_t *m);
int init_all_and_create(cw_t *cw, map_t *maps, createf_t *create);
int init_maps(map_t *maps);
void maps_destroy(map_t *maps);

void create_tile_map(cw_t *cw, map_t *maps);
void create_fill_tile_map(map_t *maps);
void create_map_2d(cw_t *cw, map_t *maps);
void create_map_3d(cw_t *cw, map_t *maps);

sfVector2f project_iso_point(cw_t *cw, sfVector3f ddd);
sfVector2f invers_project_no_rotate(cw_t *cw, map_t *maps, sfVector2i dd);
sfVector2f invers_project_with_rotate(cw_t *cw, map_t *maps, sfVector2i dd);
sfVertexArray *create_line(map_t *m, sfVector2f *pt_one, sfVector2f *pt_two);
sfVertexArray *create_tile(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic);

void display_title_map(cw_t *cw, map_t *maps);

int find_square_value(cw_t *cw, map_t *map);

int maps_load(cw_t *cw, map_t *m);

#endif /* !PROTO_MAPS_H_ */
