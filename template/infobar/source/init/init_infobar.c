/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init_infobar
*/

#include "../template/infobar/include/infobar.h"

static sfBool
init_div_section(_div_t *div, int section, int left_pos)
{
    char *fileopen[] = {LI_0, LI_1, LI_2, LI_3};
    FILE *stream = fopen(fileopen[section], "r");
    static int separator[] = {2, 4, 6, 2, 4, 2, 3, 4};
    static unsigned index = 0;
    static unsigned x = 20;
    int nbr_li[] = {7, 5, 5, 3, '\0'};
    unsigned y = 40;

    div->li = malloc(sizeof(li_t) * nbr_li[section]);
    if (!div->li) return (false);
    for (int i = 0; nbr_li[section] != i; ++i, y += 30) {
        div->li[i].p_li = create_text_from_file(div->li[i].s_li, FONT, stream, \
        (sfVector2f){x - 200, (separator[index] == i) ? y += 10 : y});
        if (separator[index] == i) index++;
        div->li[i].hovering = sfFalse;
        create_rect_shape(&div->li[i].li, (sfVector2f){350, 30}, \
        (sfVector2f){left_pos, y - 5}, BLUE_HOVER);
    }
    x += 50;
    return (true);
}

static sfBool
init_section(sfRenderWindow *window, section_t *section)
{
    FILE *stream = fopen(SECTION_FILE, "r");
    int nbr_li[] = {7, 5, 5, 3, '\0'};
    unsigned x = 7;
    unsigned div_x = 0;
    unsigned height[] = {250, 180, 190, 120};

    for (int i = 0; NB_UL != i; i++, x += 50, div_x += 50) {
        section[i].hovering = sfFalse;
        section[i].div.hovering = sfFalse;
        section[i].p_section = create_text_from_file(section[i].span_section,
        FONT, stream, (sfVector2f){x, 4});
        create_rect_shape(&section[i].div.div, (sfVector2f){350, height[i]},
        (sfVector2f){div_x, 30}, DIV_GREY);
        if (!section[i].div.div) return (sfFalse);
        if (!init_div_section(&section[i].div, i, div_x)) return (false);
        init_section_hovering(&section[i].section);
    }
    return (sfTrue);
}

sfBool
init_infobar(sfRenderWindow *window, infobar_t *infobar)
{
    infobar->nav.section = malloc(sizeof(section_t) * NB_LI_TOTAL);
    if (!infobar->nav.section) return (sfFalse);
    create_rect_shape(&infobar->nav.navbar, (sfVector2f){SET_W(100), 30}, \
    (sfVector2f){0, 0}, BLACK_GREY);
    if (!infobar->nav.navbar) return (sfFalse);
    if (!init_section(window, infobar->nav.section)) return (false);
    return (sfTrue);
}