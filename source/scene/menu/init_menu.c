/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init_menu
*/

#include "my_world.h"

void
init_menu(root_t *root)
{
    char *texture[] = {MENU, CREATE_BTN, OPEN_BTN};

    root->menu.sprite = malloc(sizeof(sfSprite *) * 5);
    root->menu.texture = malloc(sizeof(sfTexture *) * 5);
    for (int i = 0; i != 3; i++) {
        root->menu.sprite[i] = sfSprite_create();
        root->menu.texture[i] = sfTexture_createFromFile(texture[i], NULL);
        sfSprite_setTexture(root->menu.sprite[i], root->menu.texture[i], \
        sfFalse);
    }
    sfSprite_setPosition(root->menu.sprite[1], (sfVector2f){70, 395});
    sfSprite_setTextureRect(root->menu.sprite[1], (sfIntRect){0, 0, 155, 42});
    sfSprite_setPosition(root->menu.sprite[2], (sfVector2f){70, 450});
    sfSprite_setTextureRect(root->menu.sprite[2], (sfIntRect){0, 0, 155, 42});
}