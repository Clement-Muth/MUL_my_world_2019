/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** check_validity_input
*/

#include "csfml.h"

static sfBool
strcomp(const char *compared, const char *comparing)
{
    int i = 0;

    for (; compared[i] == comparing[i] && compared[i]; ++i);
    return (compared[i] == 0 && compared[i] == comparing[i]) ? (sfTrue) :
    (sfFalse);
}

void
reset_info(createf_t *create)
{
    create->wrong_info_file = sfTrue;
    create->title[0] = '\0';
    for (int i = 0; i != NB_ELEMENT; i++) {
        create->incr[i] = 0;
        if (i >= 1 && i <= 3) {
            create->string[i][0] = '\0';
            sfText_setString(create->text[i], "\0");
        }
    }
}

static sfBool
check_if_empty_and_not_exist(createf_t *create)
{
    if (file_exist(create->title)) {
        create->error = create_text("This file is already exist\n",
        FONT, sfRed, (sfVector2f){300, 300});
        return (sfFalse);
    }
    if (!TITLE_VERIF(create->title[0])) {
        create->error = create_text("Please specify a name for the file\n",
        FONT, sfRed, (sfVector2f){300, 300});
        return (sfFalse);
    }
    if (!SIZE_VERIF(create->string[1][0])) {
        create->error = create_text("Please specify the width\n",
        FONT, sfRed, (sfVector2f){300, 300});
        return (sfFalse);
    }
    if (!SIZE_VERIF(create->string[2][0])) {
        create->error = create_text("Please specify the height\n",
        FONT, sfRed, (sfVector2f){300, 300});
        return (sfFalse);
    }
    return (sfTrue);
}

static sfBool
check_size(createf_t *create)
{
    if (strcomp(create->string[1], "0000\0") ||
    strcomp(create->string[1], "000\0") || strcomp(create->string[1], "00\0") ||
    strcomp(create->string[1], "0\0")) {
        create->error = create_text("Please choose a larger width\n",
        FONT, sfRed, (sfVector2f){300, 300});
        return (sfFalse);
    }
    if (strcomp(create->string[2], "0000\0") ||
    strcomp(create->string[2], "000\0") || strcomp(create->string[2], "00\0") ||
    strcomp(create->string[2], "0\0")) {
        create->error = create_text("Please choose a larger height\n", FONT,
        sfRed, (sfVector2f){300, 300});
        return (sfFalse);
    }
    for (int i = 1; i != 3; i++) {
        if (strcomp(create->string[i], "0001\0") ||
        strcomp(create->string[i], "001\0") || strcomp(create->string[i], "01\0") ||
        strcomp(create->string[i], "1\0")) {
            create->error = create_text("Please choose a larger height\n", FONT,
            sfRed, (sfVector2f){300, 300});
            return (sfFalse);
        }
    }
    return (sfTrue);
}

sfBool
check_validity_input(createf_t *create)
{
    if (!check_if_empty_and_not_exist(create)) {
        reset_info(create);
        return (sfFalse);
    }
    if (!check_size(create)) {
        reset_info(create);
        return (sfFalse);
    }
    if (create->wrong_info_file) create->wrong_info_file = sfFalse;
    return (sfTrue);
}