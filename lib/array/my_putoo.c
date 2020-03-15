/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_putoo
*/

#include "array.h"
#include "../my/my.h"

void my_putoo(char **oo)
{
    for (int e = 0; oo[e] != NULL; e++) {
        write(1, oo[e], my_length_o(oo[e]));
        write(1, "\n", 1);
    }
}