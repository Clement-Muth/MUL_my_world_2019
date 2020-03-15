/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct template_s
{
    infobar_t infobar;
    leftbar_t leftbar;
} template_t;

typedef struct menu_s
{
    sfSprite **sprite;
    sfTexture **texture;
} menu_t;


typedef struct file_s
{
    string filename;
    char width[4];
    char height[4];
} file_t;

typedef struct root_s
{
    int scene;
    sfBool new;
    file_t file;
    template_t template;
    menu_t menu;
} root_t;


#endif /* !STRUCT_H_ */