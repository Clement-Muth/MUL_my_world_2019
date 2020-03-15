/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** function
*/

#ifndef INFOBAR_FUNCTION_H_
#define INFOBAR_FUNCTION_H_


/*          Event           */
void
event_hovering_nav(sfRenderWindow *window, section_t *section);
sfBool
close_div(sfRenderWindow *window, sfRectangleShape *div);
void
event_hovering_li(sfRenderWindow *window, li_t *li);
void
event_click_nav(sfRenderWindow *window, li_t li, int i);


/*          Display         */
void
display_infobar(sfRenderWindow *window, infobar_t *infobar);


/*          Init            */
sfBool
init_infobar(sfRenderWindow *window, infobar_t *infobar);
void
init_section_hovering(sfRectangleShape **shape);


#endif /* !INFOBAR_FUNCTION_H_ */