/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** lock and unlock fucntions for menu
*/

#include "gui.h"

static void lock(s_gui_drop_menu_t *drop_menu)
{
    drop_menu->state = LOCKED;
    drop_menu->button->lock(drop_menu->button);
}

static void unlock(s_gui_drop_menu_t *drop_menu)
{
    if (IS_LOCKED(drop_menu))
        drop_menu->state = NONE;
    drop_menu->button->unlock(drop_menu->button);
}

void s_gui_drop_menu_set_lock_function(s_gui_drop_menu_t *drop_menu)
{
    drop_menu->lock = &lock;
    drop_menu->unlock = &unlock;
}
