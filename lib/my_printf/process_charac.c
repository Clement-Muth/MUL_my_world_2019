/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** process_charac
*/

#include "lib.h"

void printf_char(va_list str_print)
{
    char charac = va_arg(str_print, int);

    write(1, &charac, 1);
}

void printf_string(va_list str_print)
{
    char *str = m_strdup(va_arg(str_print, char *));

    write(1, str, m_strlen(str));
    free(str);
}

void printf_array(va_list str_print)
{
    char **restrict arr = va_arg(str_print, char **);
    int i = 0;

    for (i = 0; arr[i]; ++i);
    for (int n = 0; arr[n]; ++n) {
        write(1, arr[n], m_strlen(arr[n]));
        write(1, "\n", 1);
    }
}