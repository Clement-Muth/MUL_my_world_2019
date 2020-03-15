/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init_infobar
*/

#include "../template/leftbar/include/leftbar.h"

static sfBool
init_element_1(left_element_t *element)
{
    element->active = sfTrue;
    create_rect_shape(&element->shape_button_element, BTN_ELEM_1_SIZE,
    BTN_ELEM_1_POS, sfRed);
    element->section = malloc(sizeof(left_element_t) * 4);
    if (!element->section) return (sfFalse);
    init_section_element1(element->section);
    return (sfTrue);
}

static sfBool
init_element_2(left_element_t *element)
{
    element->active = sfFalse;
    create_rect_shape(&element->shape_button_element, BTN_ELEM_2_SIZE,
    BTN_ELEM_2_POS, sfRed);
    element->section = malloc(sizeof(left_section_t));
    if (!element->section) return (sfFalse);
    init_section_element2(element->section);
    return (sfTrue);
}

static sfBool (*init_element[])(left_element_t *element) =
{
    init_element_1,
    init_element_2
};

sfBool
init_leftbar(sfRenderWindow *window, leftbar_t *leftbar)
{
    leftbar->element = malloc(sizeof(left_element_t) * NB_BAR_ELEMENT);
    for (int i = 0; 2 != i; i++)
        if (!init_element[i](&leftbar->element[i])) return (sfFalse);
    return (sfTrue);
}