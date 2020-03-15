/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** proto_event
*/

#ifndef PROTO_EVENT_H_
#define PROTO_EVENT_H_

#include <stdio.h>
#include "../struct/struct_window.h"
#include "../struct/struct_maps.h"

int init_event(event_t *ev);

int event_root(cw_t *cw, map_t *maps);

void up_rotation(cw_t *cw, map_t *maps);
void down_rotation(cw_t *cw, map_t *maps);
void left_rotation(cw_t *cw, map_t *maps);
void right_rotation(cw_t *cw, map_t *maps);

void shrink_selection_area(cw_t *cw, map_t *maps);
void extend_selection_area(cw_t *cw, map_t *maps);
void raise_or_lower_map(cw_t *cw, map_t *maps);

void move_view_backward(cw_t *cw, map_t *maps);
void move_view_forward(cw_t *cw, map_t *maps);

void sun_rise(cw_t *cw, map_t *m);
void more_sun_power(cw_t *cw, map_t *m);
void less_sun_power(cw_t *cw, map_t *m);

void choice_selection(cw_t *cw, map_t *map);

void select_mode(cw_t *cw, map_t *map);
void select_effect(cw_t *cw, map_t *map);

void reset(cw_t *cw, map_t *m);

void save(cw_t *cw, map_t *m);
void load(cw_t *cw, map_t *m);

float read_float(FILE *f);
sfUint8 read_sfuint8(FILE *f);
unsigned int read_int(FILE *f);
char read_char(FILE *f);

void write_float(float v, FILE *f);
void write_sfuint8(sfUint8 i, FILE *f);
void write_int(int i, FILE *f);
void write_char(char c, FILE *f);

#endif /* !PROTO_EVENT_H_ */