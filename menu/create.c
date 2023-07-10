/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** create drop menu
*/

#include <stdlib.h>
#include "gui.h"

s_gui_drop_menu_t *create_drop_menu(sfVector2f position, sfVector2f size,
    void *constant, enum BUTTON_ENUM which_button)
{
    s_gui_drop_menu_t *menu = malloc(sizeof(s_gui_drop_menu_t));

    if (menu == NULL)
        return NULL;
    menu->button = init_button(position, size, constant, which_button);
    if (menu->button == NULL) {
        free(menu);
        return NULL;
    }
    menu->options = NULL;
    s_gui_drop_menu_set_open_function(menu);
    s_gui_drop_menu_set_lock_function(menu);
    s_gui_drop_menu_set_click_function(menu);
    menu->state = CLOSED;
    return menu;
}

void transform_to_menu(s_gui_options_t *option)
{
    s_gui_drop_menu_t *menu = malloc(sizeof(s_gui_drop_menu_t));

    if (menu == NULL)
        return;
    menu->button = option->option->button;
    menu->options = NULL;
    s_gui_drop_menu_set_open_function(menu);
    s_gui_drop_menu_set_lock_function(menu);
    s_gui_drop_menu_set_click_function(menu);
    menu->state = CLOSED;
    option->option->menu = menu;
    option->type = MENU;
}
