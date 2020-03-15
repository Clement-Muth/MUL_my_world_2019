/*
** EPITECH PROJECT, 2020
** library
** File description:
** my_assert_fail
*/

#include "include/my_assert.h"
#undef my_assert_fail
#ifndef __assertfail
#define __assertfail my_assert_fail
#endif /*__assertfail*/

void __assertfail(char *restrict __assertion, char *restrict __file,
unsigned __line, const char *__function)
{
    #ifdef DEBUG
        printf("%s: %s:%d: %s '%s' failed\n", __file, __function, __line,
            "Assertion", __assertion);
    #else
        write(2, "An error occured - Please try again\nAbandon\n", 45);
    #endif
}