/*
** EPITECH PROJECT, 2020
** library
** File description:
** my_assert
*/

#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

////////////////////////////////////////////////////////////
/// Header
///
////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#if defined __cplusplus && __GNUC_PREREQ(2, 95)
#define __VOID_CAST static_cast<void>
#else
#define __VOID_CAST (void)(0)
#endif

#define my_assert(expr) ((expr) ? __VOID_CAST : my_assert_fail(#expr, \
__FILE__, __LINE__, __func__))

/* Evalue the expr and abort if it's true */
void my_assert_fail(char *restrict __assertion, char *restrict __file,
unsigned __line, const char *__function)
            __nonnull((1, 2, 4));

#endif /* !MY_ASSERT_H_ */
