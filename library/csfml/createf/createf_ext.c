/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** createf_ext
*/

#include "csfml.h"

int
write_size(int i, char str[5], sfText *width, sfUint32 data)
{
    if (sfKeyboard_isKeyPressed(sfKeyBack)) {
        if (i - 1 >= 0) {
            --i;
            str[i] = '\0';
            sfText_setString(width, str);
        }
    }
    if (data < 48 || data > 57) return (i);
    else if (i != 4) {
        str[i] = data;
        str[i + 1] = '\0';
        sfText_setString(width, str);
        ++i;
    }
    return (i);
}

int
write_title(int i, char str[20], sfText *width, sfUint32 data)
{
    if (sfKeyboard_isKeyPressed(sfKeyBack)) {
        if (i - 1 >= 0) {
            --i;
            str[i] = '\0';
            sfText_setString(width, str);
        }
    }
    else if (i != 19 && PREG_MATCH) {
        str[i] = data;
        str[i + 1] = '\0';
        sfText_setString(width, str);
        ++i;
    }
    return (i);
}