/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_load
*/

#include "my_world.h"

static FILE *load_file(map_t *m)
{
    char *path = "save/";

    path = my_strcat_bside(path, m->name, ".legend", 0);
    return (fopen(path, "r"));
}

static void load_map_and_color(map_t *m, FILE *file)
{
    for (int y = 0; y < m->height; ++y) {
        for (int x = 0; x < m->width; ++x) {
            m->map_3d[y][x].z = read_float(file);
            m->clr[y][x] = read_char(file);
            m->tile_cl[y][x].r = read_sfuint8(file);
            m->tile_cl[y][x].g = read_sfuint8(file);
            m->tile_cl[y][x].b = read_sfuint8(file);
        }
    }
}

void load(cw_t *cw, map_t *m)
{
    FILE *file = load_file(m);

    if (file == NULL) {
        cw->ev.ret_value = 1;
        return;
    }
    maps_destroy(m);
    m->height = read_int(file);
    m->width = read_int(file);
    init_all(cw, m);
    create_all(cw, m);
    cw->ev.line_on = read_int(file);
    load_map_and_color(m, file);
    fclose(file);
}