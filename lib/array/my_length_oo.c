/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_length_oo
*/

#include "array.h"

int my_length_oo(char **oo)
{
    int length = 0;

    for (; oo[length] != NULL; length++);
    return (length);
}