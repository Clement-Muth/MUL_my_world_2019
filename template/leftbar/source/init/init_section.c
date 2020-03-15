/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init_section
*/

#include "my_world.h"

static sfBool (*init_part_section_element[])(left_part_t *part) =
{
    init_part_section1_element1,
    init_part_section2_element1,
    init_part_section3_element1
};

sfBool
init_section_element1(left_section_t *section)
{
    char *texture[] = {BRUSH_COLOR, BRUSH_BRUSH, BRUSH_SIZE};
    int p_y[] = {165, 206, 251};
    int nb_part_section[] = {12, 2, 1};

    for (int i = 0; i != NB_SECTION_ELEMENT_1; i++) {
        create_rect_shape(&section[i].shape_button_section,
        BTN_ELEM_1_SECT_SIZE, BTN_ELEM_1_SECT_POS, sfRed);
        create_rect_shape(&section[i].shape_button_section,
        BTN_ELEM_1_SECT_SIZE, BTN_ELEM_1_SECT_POS, sfRed);
        if (!section[i].shape_button_section) return (sfFalse);
        section[i].active = (i != 0) ? (sfFalse) : (sfTrue);
        section[i].sprite = create_sprite(texture[i], (i == 0) ?
        LEFTBAR_POS : (sfVector2f){0, -454});
        if (!section[i].sprite) return (sfFalse);
        section[i].part = malloc(sizeof(left_part_t) * nb_part_section[i]);
        if (!section[i].part) return (sfFalse);
        if (!init_part_section_element[i](section[i].part)) return (sfFalse);
    }
    return (sfTrue);
}

sfBool
init_section_element2(left_section_t *section)
{
    create_rect_shape(&section->shape_button_section,
    BTN_ELEM_2_SECT_SIZE, BTN_ELEM_2_SECT_POS, sfRed);
    if (!section->shape_button_section) return (sfFalse);
    section->active = sfTrue;
    section->sprite = create_sprite(SHADOW, LEFTBAR_POS);
    if (!section->sprite) return (sfFalse);
    return (sfTrue);
}