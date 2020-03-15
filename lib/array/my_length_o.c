/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_length_o
*/

#include "array.h"

int my_length_o(char *o)
{
    int length = 0;

    for (length = 0; o[length]; length++);
    return (length);
}