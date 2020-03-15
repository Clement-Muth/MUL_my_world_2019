/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "include/lib.h"

static void (*process_fct[])(va_list) =
{
    printf_string,
    printf_array,
    printf_char,
    printf_int,
    printf_int,
    printf_pointer,
    printf_color,
    printf_error
};

static int check_flag(const char *restrict format, va_list str_print, int index,
bool F)
{
    const char *restrict flag = m_strdup((F) ? FLAG : SFLAG);
    _Bool is_flag = false;
    unsigned cflag = 0;

    for (int i = 0; flag[i]; ++i)
        if (flag[i] == format[index + 1]) {
            cflag = ((F) ? i : i + 6);
            is_flag = true;
        }
    if (is_flag == false) {
        if (F)
            return (check_flag(format, str_print, index, false));
        write(1, &format[index], 1);
        return (index);
    }
    process_fct[cflag](str_print);
    free((char *)flag);
    return (index + 1);
}

int my_printf(const char *restrict format, ...)
{
    va_list(str_print);
    va_start(str_print, format);

    for (int i = 0; format[i]; i++) {
        if ('%' == format[i])
            i = check_flag(format, str_print, i, true);
        else
            write(1, &format[i], 1);
    }
    va_end(str_print);
    return (EXIT_SUCCESS);
}