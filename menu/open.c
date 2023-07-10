/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** check for openned menu
*/

#include "gui.h"

static void update_option_hover(s_gui_options_t *option,
    sfMouseMoveEvent *event)
{
    while (option != NULL) {
        if (option->type == BUTTON)
            option->option->button->is_hover(option->option->button, event);
        if (option->type == MENU)
            option->option->menu->is_open(option->option->menu, event);
        option = option->next;
    }
}

static sfBool option_is_open_choice(s_gui_options_t *option,
    s_gui_drop_menu_t *drop_menu, sfMouseMoveEvent *event)
{
    if (option->type == BUTTON) {
        if (option->option->button->is_hover(option->option->button, event)) {
            update_option_hover(option->next, event);
            sfRectangleShape_setFillColor(drop_menu->button->rect, sfLightGray);
            drop_menu->state = OPEN;
            return sfTrue;
        }
    }
    if (option->type == MENU) {
        if (option->option->menu->is_open(option->option->menu, event)) {
            update_option_hover(option->next, event);
            sfRectangleShape_setFillColor(drop_menu->button->rect, sfLightGray);
            drop_menu->state = OPEN;
            return sfTrue;
        }
    }
    return sfFalse;
}

static sfBool option_is_open(s_gui_drop_menu_t *drop_menu,
    sfMouseMoveEvent *event)
{
    s_gui_options_t *option = drop_menu->options;

    while (!IS_CLOSED(drop_menu) && option != NULL) {
        if (option_is_open_choice(option, drop_menu, event))
            return sfTrue;
        option = option->next;
    }
    sfRectangleShape_setFillColor(drop_menu->button->rect, sfWhite);
    drop_menu->state = CLOSED;
    return sfFalse;
}

static sfBool is_open(s_gui_drop_menu_t *drop_menu,
    sfMouseMoveEvent *event)
{
    if (IS_FIX_OPEN(drop_menu)) {
        update_option_hover(drop_menu->options, event);
        sfRectangleShape_setFillColor(drop_menu->button->rect, sfGray);
        return sfTrue;
    }
    if (IS_LOCKED(drop_menu) || drop_menu->options == NULL) {
        sfRectangleShape_setFillColor(drop_menu->button->rect, sfDarkGray);
        return drop_menu->button->is_hover(drop_menu->button, event);
    }
    if (drop_menu->button->is_hover(drop_menu->button, event)) {
        sfRectangleShape_setFillColor(drop_menu->button->rect, sfLightGray);
        drop_menu->state = OPEN;
        return sfTrue;
    }
    return option_is_open(drop_menu, event);
}

void s_gui_drop_menu_set_open_function(s_gui_drop_menu_t *drop_menu)
{
    drop_menu->is_open = &is_open;
}
