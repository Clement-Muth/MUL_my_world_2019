/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** struct
*/

#ifndef INFOBAR_STRUCT_H_
#define INFOBAR_STRUCT_H_

typedef struct li_s
{
    sfRectangleShape *li;
    sfText *p_li;
    sfFont *font;
    string s_li;
    sfBool hovering;
} li_t;


typedef struct div_s
{
    sfRectangleShape *div;
    int *nbr_li_section;
    sfBool hovering;
    li_t *li;
} _div_t;


typedef struct section_s
{
    sfRectangleShape *section;
    sfText *p_section;
    sfFont *font;
    string span_section;
    sfBool hovering;
    _div_t div;
} section_t;


typedef struct nav_s
{
    sfRectangleShape *navbar;
    section_t *section;
} nav_t;


typedef struct infobar_s
{
    nav_t nav;
} infobar_t;

#endif /* !INFOBAR_STRUCT_H_ */