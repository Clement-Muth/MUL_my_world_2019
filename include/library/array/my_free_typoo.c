/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_free_typoo
*/

#include "array.h"

void my_free_typoo(void **oo)
{
    for (int e = 0; oo[e] != NULL; e++)
        free(oo[e]);
    free(oo);
}