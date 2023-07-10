/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** add elem to menu
*/

#include <stdlib.h>
#include "gui.h"

static s_gui_drop_menu_t *place_option(s_gui_drop_menu_t *drop_menu,
    s_gui_options_t *option, s_gui_options_t *last)
{
    if (option->option->button == NULL) {
        free(option->option);
        free(option);
        return drop_menu;
    }
    option->type = BUTTON;
    option->next = NULL;
    if (drop_menu->options == NULL)
        drop_menu->options = option;
    else
        last->next = option;
    return drop_menu;
}

static s_gui_options_t *get_last(s_gui_drop_menu_t *drop_menu)
{
    s_gui_options_t *last = NULL;

    if (drop_menu->options == NULL)
        return NULL;
    last = drop_menu->options;
    while (last->next != NULL)
        last = last->next;
    return last;
}

s_gui_drop_menu_t *add_option_drop_menu_d(s_gui_drop_menu_t *drop_menu,
    void *constant, enum BUTTON_ENUM which_button)
{
    s_gui_options_t *option = malloc(sizeof(s_gui_options_t));
    s_gui_object_t *union_opt = malloc(sizeof(s_gui_object_t));
    sfVector2f pos = sfRectangleShape_getPosition(drop_menu->button->rect);
    sfVector2f size = sfRectangleShape_getSize(drop_menu->button->rect);

    if (option == NULL || union_opt == NULL) {
        free(option);
        free(union_opt);
        return drop_menu;
    }
    option->option = union_opt;
    if (drop_menu->options != NULL)
        pos = sfRectangleShape_getPosition(
            get_last(drop_menu)->option->button->rect);
    pos.y += size.y;
    option->option->button = init_button(pos, size, constant, which_button);
    return place_option(drop_menu, option, get_last(drop_menu));
}

s_gui_drop_menu_t *add_option_drop_menu_right(s_gui_drop_menu_t *drop_menu,
    void *constant, enum BUTTON_ENUM which_button)
{
    s_gui_options_t *option = malloc(sizeof(s_gui_options_t));
    s_gui_object_t *union_opt = malloc(sizeof(s_gui_object_t));
    sfVector2f pos = sfRectangleShape_getPosition(drop_menu->button->rect);
    sfVector2f size = sfRectangleShape_getSize(drop_menu->button->rect);

    if (option == NULL || union_opt == NULL) {
        free(option);
        free(union_opt);
        return drop_menu;
    }
    option->option = union_opt;
    if (drop_menu->options != NULL)
        pos = sfRectangleShape_getPosition(
            get_last(drop_menu)->option->button->rect);
    pos.x += size.x;
    option->option->button = init_button(pos, size, constant, which_button);
    return place_option(drop_menu, option, get_last(drop_menu));
}
