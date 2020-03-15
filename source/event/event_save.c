/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event_save
*/

#include "my_world.h"

static FILE *save_file(map_t *m)
{
    char *path = "save/";

    path = my_strcat_bside(path, m->name, ".legend", 0);
    return (fopen(path, "w"));
}

static void save_map_and_color(map_t *m, FILE *file)
{
    for (int y = 0; y < m->height; ++y) {
        for (int x = 0; x < m->width; ++x) {
            write_float(m->map_3d[y][x].z, file);
            write_char(m->clr[y][x], file);
            write_sfuint8(m->tile_cl[y][x].r, file);
            write_sfuint8(m->tile_cl[y][x].g, file);
            write_sfuint8(m->tile_cl[y][x].b, file);
        }
    }
}

void save(cw_t *cw, map_t *m)
{
    FILE *file = save_file(m);

    if (file == NULL) {
        cw->ev.ret_value = 1;
        return;
    }
    write_int(m->height, file);
    write_int(m->width, file);
    write_int(cw->ev.line_on, file);
    save_map_and_color(m, file);
    fclose(file);
}