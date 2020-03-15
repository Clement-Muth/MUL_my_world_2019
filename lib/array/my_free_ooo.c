/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_free_ooo
*/

#include "array.h"

void my_free_ooo(char ***ooo)
{
    for (int e = 0; ooo[e] != NULL; e++) {
        for (int i = 0; ooo[e][i] != NULL; i++) {
            free(ooo[e][i]);
        }
        free(ooo[e]);
    }
    free(ooo);
}