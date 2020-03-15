/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** function
*/

#ifndef LEFTBAR_FUNCTION_H_
#define LEFTBAR_FUNCTION_H_


/*          Event           */
void
event_change_element(sfRenderWindow *window, left_element_t *element,
left_element_t *all_element);

void
event_change_section(sfRenderWindow *window, left_section_t *section,
left_section_t *all_section);


/*          Display         */
void
display_leftbar(sfRenderWindow *window, leftbar_t *leftbar, map_t *map,
event_t *event);


/*          Init            */
sfBool
init_leftbar(sfRenderWindow *window, leftbar_t *leftbar);

sfBool
init_section_element1(left_section_t *section);

sfBool
init_section_element2(left_section_t *section);

sfBool
init_part_section1_element1(left_part_t *part);

sfBool
init_part_section2_element1(left_part_t *part);

sfBool
init_part_section3_element1(left_part_t *part);

#endif /* !LEFTBAR_FUNCTION_H_ */