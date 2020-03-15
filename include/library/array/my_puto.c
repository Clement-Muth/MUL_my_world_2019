/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_puto
*/

#include "array.h"

void my_puto(char *o)
{
    write(1, o, my_length_o(o));
}