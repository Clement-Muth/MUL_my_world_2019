/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world_loop
*/

#include "my_world.h"

static int independant_frame(cw_t *cw)
{
    float frame = 1.0 / cw->ti.tmp_frame;
    float frame_up = 1.0 / (cw->ti.framerate + 1);

    if (cw->ti.sec > frame_up) {
        ++cw->ti.tmp_frame;
        return (1);
    } else if (cw->ti.sec > frame) {
        if (cw->ti.tmp_frame > cw->ti.framerate)
            --cw->ti.tmp_frame;
        return (1);
    }
}

void world_loop(createf_t *create)
{
    cw_t cw;
    map_t *maps = malloc(sizeof(map_t));
    template_t template;
    root_t root;

    if (maps == NULL || init_window(&cw, create) != 0 ||
    init_all_and_create(&cw, maps, create))
    create_sprite_framebuffer(&cw);
    init_template(cw.window, &template);
    init_scene(&root);
    while (sfRenderWindow_isOpen(cw.window)) {
        time_event_handling(&cw, maps, &template, &root);
        if (independant_frame(&cw))
            put_object_on_screen(&cw, maps, &template);
        sfRenderWindow_setFramerateLimit(cw.window, 60);
    }
    destroy_all(&cw, maps);
}

void
edit_thread(createf_t *create)
{
    sfThread *_thread;

    _thread = sfThread_create(world_loop, (void *)create);
    sfThread_launch(_thread);
    sfThread_wait(_thread);
    sfThread_destroy(_thread);
}