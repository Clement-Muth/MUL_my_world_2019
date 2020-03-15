/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** struct
*/

#ifndef LEFTBAR_STRUCT_H_
#define LEFTBAR_STRUCT_H_

typedef struct left_part_s
{
    sfRectangleShape *shape_button_part;
    sfSprite *button_text;
    sfColor part_color;
    sfBool active;
} left_part_t;


typedef struct left_section_s
{
    left_part_t *part;
    sfSprite *sprite;
    sfRectangleShape *shape_button_section;
    sfBool active;
} left_section_t;


typedef struct left_element_s
{
    left_section_t *section;
    sfRectangleShape *shape_button_element;
    sfBool active;
} left_element_t;


typedef struct leftbar_s
{
    left_element_t *element;
    sfBool *active;
} leftbar_t;

#endif /* !LEFTBAR_STRUCT_H_ */