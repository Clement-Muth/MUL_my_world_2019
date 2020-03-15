/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** openf
*/

#include "csfml.h"

static sfBool
init_open(sfRenderWindow *window, openf_t *open)
{
    open->nofile = create_text("No File Found.", FONT, LIGHT_GREY, \
    (sfVector2f){425, 540 / 2});
    open->filename = create_text(" ", FONT, LIGHT_GREY, \
    (sfVector2f){215, 212});
    if (!open->nofile) return (sfFalse);
    open->text_entered = create_sprite(TEXTAREA, (sfVector2f){200, 200});
    if (!open->text_entered) return (sfFalse);
    sfSprite_setTextureRect(open->text_entered, (sfIntRect){0, 0, 200, 49});
    open->text_active = sfFalse;
    open->incr = 0;
    return (sfTrue);
}

static sfBool
event_text(sfRenderWindow *window, openf_t *open, sfEvent event)
{
    if (rect_mouse_hovering(window, sprite_global_b(open->text_entered))) {
        sprite_set_trec(open->text_entered, (sfIntRect){0, 49, 200, 49});
        if (button_pressed(sfMouseLeft)) open->text_active = sfTrue;
    } else if (!open->text_active ||
    (!rect_mouse_hovering(window, sprite_global_b(open->text_entered)) &&
    open->text_active && button_pressed(sfMouseLeft))) {
        sprite_set_trec(open->text_entered, (sfIntRect){0, 0, 200, 49});
        open->text_active = sfFalse;
    }
    if (open->text_active && event.type == sfEvtTextEntered) {
        open->incr = event_write(open->incr, open->filename,
        open->string, event.text.unicode);
    }
    return (sfTrue);
}

static void
poll_event(sfRenderWindow *window, sfEvent event, openf_t *open,
createf_t *create)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) sfRenderWindow_close(window);
        if (key_pressed(sfKeyEnter) && !file_exist(open->string))
            draw_text(window, open->nofile, NULL);
        else if (key_pressed(sfKeyEnter)) {
            init_create(create, open->string);
            edit_thread(create);
            sfRenderWindow_close(window);
        }
        event_text(window, open, event);
    }
}

static void
thread(void *value)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){960, 540, 32}
    , "Open File", sfClose, NULL);
    sfEvent event;
    openf_t open;
    createf_t create;

    init_open(window, &open);
    sfRenderWindow_setPosition(window, (sfVector2i){960 / 2, 540 / 2});
    while (sfRenderWindow_isOpen(window)) {
        poll_event(window, event, &open, &create);
        sfRenderWindow_clear(window, DARK_GREY);
        sfRenderWindow_setFramerateLimit(window, 60);
        draw_sprite(window, open.text_entered, NULL);
        draw_text(window, open.filename, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    open_free(&open);
}

void
openf(void)
{
    sfThread *_thread = sfThread_create(thread, NULL);

    sfThread_launch(_thread);
    sfThread_wait(_thread);
    sfThread_destroy(_thread);
}