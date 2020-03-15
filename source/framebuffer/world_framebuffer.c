/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** framebuffer
*/

#include "my_world.h"

fbf_t *framebuffer_create(fbf_t *buffer, cw_t *cw)
{
    buffer->width = cw->width;
    buffer->height = cw->height;
    buffer->pixels = malloc(sizeof(sfUint8) * (cw->width * cw->height) * 4);
    if (buffer->pixels == NULL)
        return (NULL);
    return (buffer);
}

void put_pixel(fbf_t *buffer, int x, int y, sfColor color)
{
    int i = 4 * buffer->width * y + x * 4;

    if (x < buffer->width && x > 0 && y < buffer->height && y > 0) {
        buffer->pixels[i] = color.r;
        buffer->pixels[i + 1] = color.g;
        buffer->pixels[i + 2] = color.b;
        buffer->pixels[i + 3] = color.a;
    }
}

void color_declaration(sfColor *clr, sfUint8 red, sfUint8 green, sfUint8 blue)
{
    clr->r = red;
    clr->g = green;
    clr->b = blue;
    clr->a = 255;
}

void restore_framebuffer(fbf_t *buffer)
{
    for (int e = 0; e < buffer->width * buffer->height * 4; e += 4) {
        buffer->pixels[e] = 0;
        buffer->pixels[e + 1] = 0;
        buffer->pixels[e + 2] = 0;
        buffer->pixels[e + 3] = 0;
    }
}

void framebuffer_destroy(fbf_t *buffer)
{
    free(buffer->pixels);
    free(buffer);
}