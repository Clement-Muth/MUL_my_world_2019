/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** utilities
*/

#include "lib.h"

void *m_memcpy(void *dest, const void *src, size_t len)
{
    char *cdest = dest;
    const char *csrc = src;

    for (; ((*cdest++) = (*csrc++)); len--);
    return dest;
}

void *m_memalloc(size_t size)
{
    void *mem = malloc(size);

    if (mem)
        return (mem);
    free(mem);
    return (NULL);
}

char *m_strdup(char *src)
{
    size_t len = m_strlen(src) + 2;
    void *new = m_memalloc(len);

    return ((char *)m_memcpy(new, src, len));
}

int m_strlen(char *__string)
{
    int i = 0;

    while (__string[i++]);
    return (i);
}

char *m_itoa(unsigned nb)
{
    int tmp = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * 20);

    if (nb < 0) {
        free(result);
        return (NULL);
    }
    for (i = 0; nb != 0; ++i) {
        tmp = nb % 10;
        result[i] = tmp + 48;
        nb /= 10;
    }
    result[i] = '\0';
    m_revstr(result);
    return (result);
}