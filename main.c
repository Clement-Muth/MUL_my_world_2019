/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** main
*/

#include "my_world.h"

static void
poll_event(sfRenderWindow *window, sfEvent event, root_t *root,
template_t *template)
{
    static int i = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || key_pressed(sfKeyD) && \
        key_pressed(sfKeyLControl)) window_close(window);
        if (key_pressed(sfKeyLControl) && key_pressed(sfKeyO)) openf();
        poll_hovering_button(window, root, template);
        if (event.type == sfEvtTextEntered && i != 4)
            root->file.width[i++] = event.text.unicode;
    }
}

static void
cursor_hovering(sfRenderWindow *window, menu_t *menu)
{
    sfBool hovering = sfFalse;

    for (int i = 1; i != 3; i++) {
        if (rect_mouse_hovering(window, sprite_global_b(menu->sprite[i]))) {
            window_setcursor(window, create_cursor(sfCursorHand));
            hovering = sfTrue;
            break;
        }
    }
    if (!hovering) window_setcursor(window, create_cursor(sfCursorArrow));
}

int
main(int ac, char **av)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){VIEWPORT}
    , "My World", sfResize | sfClose, NULL);
    sfEvent event;
    template_t template;
    root_t root;
    const sfUint8 *icon =  sfImage_getPixelsPtr(sfImage_createFromFile(ICON));

    init_scene(&root);
    sfRenderWindow_setIcon(window, 1920, 1080, icon);
    if (!init_template(window, &template));
    while (sfRenderWindow_isOpen(window)) {
        poll_event(window, event, &root, &template);
        cursor_hovering(window, &root.menu);
        sfRenderWindow_clear(window, DARK_GREY);
        sfRenderWindow_setFramerateLimit(window, 60);
        draw_menu(window, &root, &template);
        sfRenderWindow_display(window);
    }
    destroy_template(window, &template);
    return (EXIT_SUCCESS);
}