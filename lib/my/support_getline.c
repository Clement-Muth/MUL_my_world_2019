/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** support_getline
*/

#include "my_getline.h"

int if_n_or_zero_letter(static_t *_static, char *link, int *inc_l)
{
     if (_static->buf[_static->inc_b] == '\n') {
        link[++*inc_l] = '\0';
        ++_static->inc_b;
        ++_static->cursor;
        _static->stay = 2;
        return (1);
    } else if (_static->buf[_static->inc_b] == '\0') {
        link[++*inc_l] = '\0';
        _static->stay = 0;
        return (1);
    }
    return (0);
}

int if_n_or_zero_ashes(static_t *_static, char *ashes, int *inc_a)
{
    if (_static->buf[_static->inc_b] == '\n') {
        ashes[++*inc_a] = '\0';
        ++_static->inc_b;
        ++_static->cursor;
        _static->stay = 3;
        return (1);
    } else if (_static->buf[_static->inc_b] == '\0') {
        ashes[++*inc_a] = '\0';
        _static->stay = 0;
        return (1);
    }
    return (0);
}

int return_value_if_end(mobile_t *mobile, static_t *_static)
{
    if ((_static->stay == 2 || _static->stay == 0) && _static->fd != 0)
        return (1);
    if ((_static->stay == 2 || _static->stay == 0) && _static->fd == 0) {
        free(_static->buf);
        return (1);
    }
    return (0);
}

int error_fd_code(int fd, static_t *_static)
{
    if (fd == ERROR_FREE_BUF) {
        free(_static->buf);
        return (-1);
    }
    return (0);
}