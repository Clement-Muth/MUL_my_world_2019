/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_bloc
*/

#ifndef PROTO_BLOC_H_
#define PROTO_BLOC_H_

#include "../struct/struct_maps.h"
#include "../struct/struct_bloc.h"
#include "../struct/struct_window.h"

int init_bloc(map_t *maps, bloc_t *bc);
void bloc_destroy(bloc_t *bc);

void bloc_display(cw_t *cw, bloc_t *bloc);

void create_point_bloc(cw_t *cw, map_t *maps, bloc_t *bc, sfVector2i co);
void create_bloc(cw_t *cw, map_t *maps, sfVector2i co);

void create_tile_bloc(map_t *map, bloc_t *bc, sfVector2i co);

void restore_bloc(cw_t *cw, map_t *maps, sfVector2i co);

void restore_wall_line(sfVertexArray *line, sfVector2f *one,
sfVector2f *two);
void restore_wall(sfVertexArray *quads, tile_t tile, sfColor c);

#endif /* !PROTO_BLOC_H_ */