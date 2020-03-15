/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** process_nbr
*/

#include "lib.h"

void printf_int(va_list str_print)
{
    char *str = m_itoa(va_arg(str_print, int));

    write(1, str, m_strlen(str));
    free(str);
}

void printf_hexa(va_list str_print)
{
    unsigned long long nbr = va_arg(str_print, unsigned long long);
    char *string = m_memalloc(sizeof(char *) * m_intlen(nbr) + 3);
    int i = 0;

    if (nbr < 9) {
        free(string);
        my_printf("%d", nbr);
        return;
    }
    for (i = 0; nbr >= 1; ++i, nbr /= 16)
        string[i] = (nbr % 16 > 9) ? ((nbr % 16) + 87) : ((nbr % 16) + 48);
    string[i] = '\0';
    my_printf("%s", m_revstr(string));
    free(string);
}

void printf_pointer(va_list str_print)
{
    my_printf("0x");
    printf_hexa(str_print);
}