/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** lock and unlock functions for buttons
*/

#include "button.h"

static void lock(button_t *button)
{
    button->state = LOCKED;
}

static void unlock(button_t *button)
{
    if (IS_LOCKED(button))
        button->state = NONE;
}

void button_set_lock_function(button_t *button)
{
    button->lock = &lock;
    button->unlock = &unlock;
}
