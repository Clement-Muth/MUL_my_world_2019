/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_restore
*/

#ifndef PROTO_RESTORE_H_
#define PROTO_RESTORE_H_

#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"

void restore_order_according_rotation(cw_t *cw, map_t *maps);

void restore_maps(cw_t *cw, map_t *maps);

void restore_line(map_t *m, sfVertexArray *line, sfVector2f *one,
sfVector2f *two);

void restore_tile_map_loop(cw_t *cw, map_t *maps, sfVector2i co, sfVector2i ic);

#endif /* !PROTO_RESTORE_H_ */