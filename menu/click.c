/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** click
*/

#include "gui.h"

static sfBool close_all(s_gui_drop_menu_t *menu)
{
    s_gui_options_t *next = menu->options;

    if (!IS_LOCKED(menu)) {
        menu->state = CLOSED;
        sfRectangleShape_setFillColor(menu->button->rect, sfWhite);
    }
    while (next != NULL) {
        if (next->type == MENU) {
            close_all(next->option->menu);
        }
        if (next->type == BUTTON) {
            sfRectangleShape_setFillColor(next->option->button->rect, sfWhite);
        }
        next = next->next;
    }
    return sfFalse;
}

static void not_lock_to_fix_open(s_gui_drop_menu_t *menu, s_gui_options_t *next)
{
    if (!IS_LOCKED(menu))
        menu->state = FIX_OPEN;
    while (next != NULL) {
        if (next->type == MENU)
            close_all(next->option->menu);
        if (next->type == BUTTON)
            sfRectangleShape_setFillColor(next->option->button->rect, sfWhite);
        next = next->next;
    }
}

static sfBool is_clicked_while(s_gui_drop_menu_t *menu,
    sfMouseButtonEvent *event, windowbuffer_t *window)
{
    s_gui_options_t *next = menu->options;

    while (next != NULL) {
        if (next->type == BUTTON && next->option->button->is_clicked
            (next->option->button, event, window))
            return close_all(menu);
        if (next->type == MENU && next->option->menu->is_clicked
            (next->option->menu, event, window)) {
            not_lock_to_fix_open(menu, next->next);
            return sfTrue;
        }
        next = next->next;
    }
    return close_all(menu);
}

static sfBool is_clicked(s_gui_drop_menu_t *menu, sfMouseButtonEvent *event,
    windowbuffer_t *window)
{
    if (IS_LOCKED(menu->button))
        return sfFalse;
    if (menu->button->is_clicked(menu->button, event, window)) {
        if IS_FIX_OPEN(menu) {
            return close_all(menu);
        } else {
            not_lock_to_fix_open(menu, menu->options);
            return sfTrue;
        }
    }
    if (IS_OPEN(menu))
        return is_clicked_while(menu, event, window);
    return sfFalse;
}

void s_gui_drop_menu_set_click_function(s_gui_drop_menu_t *drop_menu)
{
    drop_menu->is_clicked = &is_clicked;
}
