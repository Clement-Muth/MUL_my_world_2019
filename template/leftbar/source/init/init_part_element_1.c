/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init_part_element_1
*/

#include "my_world.h"

sfBool
init_part_section1_element1(left_part_t *part)
{
    sfColor color_tab[] = {BLUE_GREEN, BLUE_PRUPLE, PURPLE_BLUE, PURPLE_RED,
    RED_PURPLE, ORANGE_RED, RED_ORANGE, ORANGE_YELLOW, YELLOW_ORANGE,
    YELLOW_GREEN, GREEN_YELLOW, GREEN_BLUE};

    for (int i = 0, y = 172; 12 != i; i++, y += 62) {
        create_rect_shape(&part[i].shape_button_part, (sfVector2f){45, 45},
        (sfVector2f){180, y}, sfRed);
        if (!part[i].shape_button_part) return (sfFalse);
        part[i].part_color = color_tab[i];
    }
    return (sfTrue);
}

sfBool
init_part_section2_element1(left_part_t *part)
{
    for (int i = 0, y = 172; 2 != i; i++, y += 62) {
        create_rect_shape(&part[i].shape_button_part, (sfVector2f){45, 45},
        (sfVector2f){180, y}, sfRed);
        if (!part[i].shape_button_part) return (sfFalse);
    }
    return (sfTrue);
}

sfBool
init_part_section3_element1(left_part_t *part)
{
    part->button_text = create_sprite(CREATE_BTN, (sfVector2f){300, 300});
    if (!part->button_text) return (sfFalse);
    return (sfTrue);
}