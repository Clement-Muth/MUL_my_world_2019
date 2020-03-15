/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

void
destroy_template(sfRenderWindow *window, template_t *template);

bool
init_template(sfRenderWindow *window, template_t *template);

void
draw_template(sfRenderWindow *window, template_t *template, map_t *maps,
event_t *event);

void
init_scene(root_t *root);

void
init_menu(root_t *root);

void
draw_menu(sfRenderWindow *window, root_t *root, template_t *template);

void
draw_editor(sfRenderWindow *window, template_t *template,
map_t *map, event_t *event);

sfBool
event_hovering_button(sfRenderWindow *window, sfSprite *sprite);

void
poll_hovering_button(sfRenderWindow *window, root_t *root, \
template_t *template);

void
edit_thread(createf_t *create);

#endif /* !FUNCTION_H_ */