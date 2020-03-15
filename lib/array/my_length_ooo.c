/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_length_ooo
*/

#include "array.h"

int my_length_ooo(char ***ooo)
{
    int length = 0;

    for (; ooo[length] != NULL; length++);
    return (length);
}