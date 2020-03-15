/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** createf
*/

#include "csfml.h"

static void
init_creating(sfRenderWindow *window, createf_t *create)
{
    char *texture[] = {MENU_CREATE, BUTTON, BUTTON, BUTTON, CANCEL_BTN,
    CONFIRM_BTN};
    sfVector2f p[NB_ELEMENT] = {{930, 210}, {930, 195}, {930, 275}, {920, 120}
    , {930, 720}, {1100, 720}};
    sfVector2f t[NB_ELEMENT] = {{940, 220}, {945, 210}, {945, 290}, {945, 133}};

    create->sprite = malloc(sizeof(sfSprite *) * NB_ELEMENT);
    create->texture = malloc(sizeof(sfTexture *) * NB_ELEMENT);
    create->active = malloc(sizeof(sfBool) * NB_ELEMENT);
    init_field(create, texture, p, t);
    sfSprite_setScale(create->sprite[3], (sfVector2f){3, 1});
}

static void
poll_event(sfRenderWindow *window, sfEvent event, createf_t *create)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || key_pressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (rect_mouse_hovering(window, sprite_global_b(create->sprite[4])) &&
        button_pressed(sfMouseLeft))
            sfRenderWindow_close(window);
        for (int i = 1; i != NB_ELEMENT && i != 4; i++)
            if (button_pressed(sfMouseLeft) && !rect_mouse_hovering(window,
            sprite_global_b(create->sprite[i]))) create->active[i] = sfFalse;
        event_create(window, create);
        event_text_entered(window, event, create);
    }
}

static void
cursor_hovering(sfRenderWindow *window, createf_t create)
{
    sfBool hovering = sfFalse;

    for (int i = 1; i != NB_ELEMENT; i++) {
        if (rect_mouse_hovering(window, sprite_global_b(create.sprite[i]))) {
            window_setcursor(window, create_cursor(sfCursorHand));
            hovering = sfTrue;
            break;
        }
    }
    if (!hovering) window_setcursor(window, create_cursor(sfCursorArrow));
}

static void
thread(void *value)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1280, 800, 32}
    , "Create File", sfNone, NULL);
    sfEvent event;
    createf_t create;

    init_creating(window, &create);
    sfRenderWindow_setPosition(window, (sfVector2i){320, 90});
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, DARK_GREY);
        cursor_hovering(window, create);
        sfRenderWindow_setFramerateLimit(window, 60);
        for (int i = 0; i != NB_ELEMENT; i++)
            sfRenderWindow_drawSprite(window, create.sprite[i], NULL);
        poll_event(window, event, &create);
        createf_draw(window, create);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

void
createf(sfRenderWindow *window)
{
    sfThread *_thread = sfThread_create(thread, NULL);

    window_setcursor(window, create_cursor(sfCursorNotAllowed));
    sfThread_launch(_thread);
    sfThread_wait(_thread);
    sfThread_destroy(_thread);
    window_setcursor(window, create_cursor(sfCursorArrow));
}