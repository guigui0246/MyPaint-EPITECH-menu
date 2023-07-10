/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** destroy drop menus
*/

#include <stdlib.h>
#include "gui.h"

static void destroy_inside(s_gui_options_t *option)
{
    while (option->next->next != NULL) {
        option = option->next;
    }
    if (option->next->type == BUTTON)
        destroy_button(option->next->option->button);
    if (option->next->type == MENU)
        destroy_drop_menu(option->next->option->menu);
    free(option->next);
    option->next = NULL;
}

static void destroy_choice(s_gui_options_t *option)
{
    if (option->type == BUTTON)
        destroy_button(option->option->button);
    if (option->type == MENU)
        destroy_drop_menu(option->option->menu);
}

void destroy_drop_menu(s_gui_drop_menu_t *drop_menu)
{
    s_gui_options_t *option;

    while (drop_menu->options != NULL) {
        option = drop_menu->options;
        if (option->next == NULL) {
            destroy_choice(option);
            free(option);
            drop_menu->options = NULL;
            break;
        }
        destroy_inside(option);
    }
    destroy_button(drop_menu->button);
    free(drop_menu);
}
