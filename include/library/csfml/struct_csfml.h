/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** struct
*/

#ifndef STRUCT_CSFML_H_
#define STRUCT_CSFML_H_

typedef struct openf_s
{
    int incr;
    char string[20];
    sfText *nofile;
    sfText *filename;
    sfSprite *text_entered;
    sfBool text_active;
} openf_t;


typedef struct createf_s
{
    sfText *nofile;
    sfText *text[NB_ELEMENT];
    char string[NB_ELEMENT][5];
    char title[20];
    char *filename;
    sfText *error;
    int incr[NB_ELEMENT];
    sfSprite **sprite;
    sfTexture **texture;
    sfBool *active;
    sfBool new;
    sfBool wrong_info_file;
} createf_t;

#endif /* !STRUCT_CSFML_H_ */