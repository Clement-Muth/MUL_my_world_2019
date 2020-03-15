/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_framebuffer
*/

#ifndef PROTO_FRAMEBUFFER_H_
#define PROTO_FRAMEBUFFER_H_

#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"
#include "../struct/struct_framebuffer.h"

fbf_t *framebuffer_create(fbf_t *buffer, cw_t *cw);
void put_pixel(fbf_t *buffer, int x, int y, sfColor color);
void color_declaration(sfColor *clr, sfUint8 red, sfUint8 green, sfUint8 blue);
void restore_framebuffer(fbf_t *buffer);
void framebuffer_destroy(fbf_t *buffer);

void framebuffer_display(cw_t *cw, map_t *maps);
void put_select_area_red(cw_t *cw, map_t *maps, circle_t *area);
void put_select_area_blue(cw_t *cw, map_t *maps, circle_t *area);

#endif /* !PROTO_FRAMEBUFFER_H_ */