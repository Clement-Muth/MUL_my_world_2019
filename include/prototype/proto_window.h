/*
** EPITECH PROJECT, 2020
** MUL_my_world_object_2019
** File description:
** proto_window
*/

#ifndef PROTO_WINDOW_H_
#define PROTO_WINDOW_H_

#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"

int init_window(cw_t *cw, createf_t *create);
void create_sprite_framebuffer(cw_t *cw);
int time_event_handling(cw_t *cw, map_t *maps, template_t *template,
root_t *root);
void put_object_on_screen(cw_t *cw, map_t *maps, template_t *template);
void destroy_all(cw_t *cw, map_t *maps);

#endif /* !PROTO_WINDOW_H_ */
