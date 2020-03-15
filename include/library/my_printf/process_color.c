/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** process_color
*/

#include "lib.h"

void printf_color(va_list str_print)
{
    my_printf(va_arg(str_print, char *));
}