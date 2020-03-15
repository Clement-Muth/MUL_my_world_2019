/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** process_error
*/

#include "lib.h"

void printf_error(va_list str_print)
{
    char *error = m_strdup(va_arg(str_print, char *));

    write(2, error, m_strlen(error));
    free(error);
}