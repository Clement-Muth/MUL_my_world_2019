/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** my_getline
*/

#include "my_getline.h"

static char *put_into_letter(static_t *_static, mobile_t *mobile)
{
    int inc_l = 0;
    char *link = malloc(sizeof(char) * (_static->cursor + READ_SIZE + 1));

    if (link == NULL)
        return (NULL);
    _static->inc_b = 0;
    for (int e = 0; e < _static->cursor; ++e, ++inc_l)
        link[inc_l] = mobile->send[e];
    if (mobile->not_fst_call)
        free(mobile->send);
    else
        mobile->not_fst_call = 1;
    for (; _static->inc_b < READ_SIZE; ++_static->inc_b, ++inc_l,
    ++_static->cursor) {
        link[inc_l] = _static->buf[_static->inc_b];
        if (if_n_or_zero_letter(_static, link, &inc_l) != 0)
            return (link);
    }
    return (link);
}

static char *get_ashes_of_letter(static_t *_static)
{
    int inc_a = 0;
    char *ashes = malloc(sizeof(char) * (READ_SIZE + 1));

    if (ashes == NULL)
        return (NULL);
    for (inc_a = 0; _static->inc_b < READ_SIZE; ++inc_a, ++_static->inc_b,
    ++_static->cursor) {
        ashes[inc_a] = _static->buf[_static->inc_b];
        if (if_n_or_zero_ashes(_static, ashes, &inc_a) != 0)
            return (ashes);
    }
    ashes[inc_a] = '\0';
    _static->cursor = inc_a;
    return (ashes);
}

static void init_getline(mobile_t *mobile, static_t *_static, int *declaration,
    int fd)
{
    mobile->read_size = 0;
    mobile->not_fst_call = 0;
    mobile->value = 0;
    if (*declaration == 0 || fd != _static->fd || fd == 0) {
        _static->fd = fd;
        _static->cursor = 0;
        _static->stay = 1;
        _static->inc_b = 0;
        _static->_bool = 0;
        *declaration = 1;
    }
}

static int ashes_and_buffer(mobile_t *mobile, static_t *_static)
{
    if (_static->cursor != 0 && _static->stay != 0) {
        mobile->not_fst_call = 1;
        mobile->send = get_ashes_of_letter(_static);
        if (mobile->send == NULL)
            return (-1);
        if (_static->stay == 3 || _static->stay == 0)
            return (1);
    }
    if (_static->_bool != 0)
        free(_static->buf);
    else
        _static->_bool = 1;
    return (0);
}

char *my_getline(int fd)
{
    mobile_t mobile;
    static static_t _static;
    static int declaration = 0;
    if (error_fd_code(fd, &_static) != 0) return (NULL);
    init_getline(&mobile, &_static, &declaration, fd);
    if ((mobile.value = ashes_and_buffer(&mobile, &_static)) != 0)
        return (mobile.value == 1 ? mobile.send : NULL);
    if (_static.stay != 0 && (_static.buf = malloc(READ_SIZE + 1)) == NULL)
        return (NULL);
    while (_static.stay > 0) {
        _static.stay = 1;
        if ((mobile.read_size = read(fd, _static.buf, READ_SIZE)) <= 0)
            return (mobile.read_size == -1 ? NULL : "ctrl d");
        _static.buf[mobile.read_size] = '\0';
        mobile.send = put_into_letter(&_static, &mobile);
        if (mobile.send == NULL) return (NULL);
        if (return_value_if_end(&mobile, &_static) != 0) return (mobile.send);
    }
    return (NULL);
}