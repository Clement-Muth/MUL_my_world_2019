/*
** EPITECH PROJECT, 2020
** MUL_my_world_bootstrap_2019
** File description:
** display_window
*/

#include "my_world.h"

int init_window(cw_t *cw, createf_t *create)
{
    cw->height = 1080;
    cw->width = 1920;
    cw->video_mode = (sfVideoMode){cw->width, cw->height, 32};
    cw->buffer = (fbf_t *)malloc(sizeof(fbf_t));
    cw->texture = sfTexture_create(cw->width, cw->height);
    cw->sprite = sfSprite_create();
    cw->ti.clock = sfClock_create();
    cw->buffer = framebuffer_create(cw->buffer, cw);
    cw->window = sfRenderWindow_create(cw->video_mode, "WORLD",
    sfDefaultStyle, NULL);
    cw->ti.framerate = 30;
    cw->ti.tmp_frame = 30;
    init_event(&cw->ev);
    if (!cw->window || cw->buffer == NULL || cw->sprite == NULL)
        return (1);
    return (0);
}

void create_sprite_framebuffer(cw_t *cw)
{
    sfTexture_updateFromPixels(cw->texture, cw->buffer->pixels,
    cw->width, cw->height, 0, 0);
    sfSprite_setTexture(cw->sprite, cw->texture, sfFalse);
}

int time_event_handling(cw_t *cw, map_t *maps, template_t *template,
root_t *root)
{
    static int i = 0;

    cw->ti.time = sfClock_getElapsedTime(cw->ti.clock);
    cw->ti.sec = cw->ti.time.microseconds / 1000000.0;
    while (sfRenderWindow_pollEvent(cw->window, &cw->event)) {
        if (cw->event.type == sfEvtClosed || key_pressed(sfKeyD) &&
        key_pressed(sfKeyLControl))
            window_close(cw->window);
        if (key_pressed(sfKeyLControl) && key_pressed(sfKeyO))
            openf();
        if (key_pressed(sfKeyLControl) && key_pressed(sfKeyN))
            createf(cw->window);
        poll_hovering_button(cw->window, root, template);
        if (cw->event.type == sfEvtTextEntered && i != 4)
            root->file.width[i++] = cw->event.text.unicode;
        if (event_root(cw, maps)) return (1);
    }
    return (0);
}

void put_object_on_screen(cw_t *cw, map_t *maps, template_t *template)
{
    if (cw->ev.mouse_moved == 1) {
        display_title_map(cw, maps);
        sfRenderWindow_drawSprite(cw->window, cw->sprite, NULL);
        cw->ev.mouse_moved = 0;
        draw_template(cw->window, template, maps, &cw->ev);
        sfTexture_updateFromPixels(cw->texture, cw->buffer->pixels,
        cw->width, cw->height, 0, 0);
        framebuffer_display(cw, maps);
        sfRenderWindow_display(cw->window);
        sfRenderWindow_clear(cw->window, sfBlack);
        restore_framebuffer(cw->buffer);
    }
    if (cw->ev.on == 1)
        restore_maps(cw, maps);
    sfClock_restart(cw->ti.clock);
}

void destroy_all(cw_t *cw, map_t *maps)
{
    sfClock_destroy(cw->ti.clock);
    sfTexture_destroy(cw->texture);
    sfSprite_destroy(cw->sprite);
    sfRenderWindow_destroy(cw->window);
    framebuffer_destroy(cw->buffer);
    maps_destroy(maps);
    free(maps);
}