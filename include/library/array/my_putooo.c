/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_putooo
*/

#include "array.h"
#include "../my/my.h"

void my_putooo(char ***ooo, char r_one, char r_two)
{
    for (int e = 0; ooo[e] != NULL; e++) {
        for (int i = 0; ooo[e][i] != NULL; i++) {
            write(1, ooo[e][i], my_length_o(ooo[e][i]));
            if (ooo[e][i + 1] != NULL)
                my_putc(r_one);
        }
        my_putc(r_two);
    }
}