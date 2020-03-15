/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init
*/

#include "csfml.h"

void
init_field(createf_t *create, char **texture, sfVector2f *p, sfVector2f *t)
{
    create->wrong_info_file = sfFalse;
    create->new = 1;
    for (int i = 0, y = 0; NB_ELEMENT != i; i++) {
        create->incr[i] = 0;
        create->active[i] = sfFalse;
        create->sprite[i] = sfSprite_create();
        create->texture[i] = sfTexture_createFromFile(texture[i], NULL);
        sfSprite_setTexture(create->sprite[i], create->texture[i], sfFalse);
        if (i >= 1 && i < 4) {
            sprite_set_pos(create->sprite[i], p[i]);
            sprite_set_trec(create->sprite[i], (sfIntRect){0, 0, 99, 49});
            create->text[i] = create_text(NULL, FONT, sfWhite, t[i]);
            y += 80;
        }
        if (i >= 4) {
            sprite_set_pos(create->sprite[i], p[i]);
            sprite_set_trec(create->sprite[i], (sfIntRect){0, 0, 155, 42});
        }
    }
}