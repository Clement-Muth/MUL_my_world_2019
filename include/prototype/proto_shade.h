/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_color
*/

#ifndef PROTO_COLOR_H_
#define PROTO_COLOR_H_

#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"

int init_shade(shade_t *shade);
void shade_destroy(shade_t *shade);

sfColor shade_color(cw_t *cw, map_t *m, sfVector2i co, sfVector2i ic);

void cross(sfVector3f *a, sfVector3f *b, sfVector3f *n);
void normalize(sfVector3f *n);
float dot(sfVector3f *n, sfVector3f *sun);
sfVector3f vector(sfVector3f one, sfVector3f two, float angle);
sfColor shade_shadow(cw_t *cw, sfVector3f **map3d, shade_t *sh, sfColor cl);

#endif /* !PROTO_COLOR_H_ */