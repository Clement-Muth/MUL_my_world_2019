/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** function
*/

#ifndef FUNCTION_CSFML_H_
#define FUNCTION_CSFML_H_

/*          Main Function           */

void
open_free(openf_t *open);

sfSprite *
create_sprite(char *texture_file_name, sfVector2f position);

void
openf(void);

sfBool
create_rect_shape(sfRectangleShape **shape, sfVector2f size, sfVector2f position
, sfColor color);

void
edit_thread();

void
init_create(createf_t *create, char *filename);

int
event_write(int i, sfText *text, char *str, char data);

sfBool
file_exist(char *filename);

sfText *
create_text_from_file(char *string, char *fontpath, FILE *stream, \
sfVector2f position);

sfText *
create_text(char *string, char *fontpath, sfColor color, sfVector2f position);

sfBool
rect_mouse_hovering(sfRenderWindow *window, sfFloatRect rect);

sfBool
check_validity_input(createf_t *create);

void
reset_info(createf_t *create);

void
createf(sfRenderWindow *window);

/*          Created Function            */

void
createf_draw(sfRenderWindow *window, createf_t create);

void
init_field(createf_t *create, char **texture, sfVector2f *p,
sfVector2f *t);


/*          Event           */
void
event_create(sfRenderWindow *window, createf_t *create);

void
event_text_entered(sfRenderWindow *window, sfEvent event, createf_t *create);

int
write_size(int i, char str[4], sfText *width, sfUint32 data);

int
write_title(int i, char str[20], sfText *width, sfUint32 data);

#endif /* !FUNCTION_CSFML_H_ */