/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** createf_event
*/

#include "csfml.h"

void
event_text_entered(sfRenderWindow *window, sfEvent event, createf_t *create)
{
    for (int i = 1; i != NB_ELEMENT; i++) {
        if (i == 3 && create->active[3] && event.type == sfEvtTextEntered) {
            create->incr[3] = write_title(create->incr[3], create->title,
            create->text[3], event.text.unicode);
            break;
        }
        if (create->active[i] && event.type == sfEvtTextEntered) {
            create->incr[i] = write_size(create->incr[i], create->string[i],
            create->text[i], event.text.unicode);
        }
    }
}

static void
event_click(sfRenderWindow *window, createf_t *create, int i)
{
    if (button_pressed(sfMouseLeft) && 4 == i) sfRenderWindow_close(window);
    if (button_pressed(sfMouseLeft) && 5 == i) {
        if (check_validity_input(create)) {
            sfRenderWindow_close(window);
            edit_thread(create);
        }
        else reset_info(create);
    }
}

void
event_create(sfRenderWindow *window, createf_t *create)
{
    for (int i = 1; i != NB_ELEMENT && i != 4; i++) {
        if (rect_mouse_hovering(window,
        sprite_global_b(create->sprite[i])) || create->active[i]) {
            sfMouse_isButtonPressed(sfMouseLeft) &&
            (create->active[i] = sfTrue);
            sfSprite_setTextureRect(create->sprite[i], RECT_NORM);
        } else
            sfSprite_setTextureRect(create->sprite[i], RECT_HOVER);
    }
    for (int i = 4; i != NB_ELEMENT; i++) {
        if (rect_mouse_hovering(window, sprite_global_b(create->sprite[i]))) {
            event_click(window, create, i);
            sfSprite_setTextureRect(create->sprite[i], (sfIntRect){0, 42, 155,
            42});
        } else {
            sfSprite_setTextureRect(create->sprite[i], (sfIntRect){0, 0, 155,
            42});
        }
    }
}