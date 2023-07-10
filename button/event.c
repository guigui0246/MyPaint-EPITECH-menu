/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** event test for button
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics.h>
#include "button.h"
#include "graphics.h"

static sfBool is_clicked(button_t *button, sfMouseButtonEvent *event,
    windowbuffer_t *window)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (IS_LOCKED(button))
        return sfFalse;
    if (sfFloatRect_contains(&rect, event->x, event->y)) {
        sfRectangleShape_setFillColor(button->rect, sfGray);
        button->state = PRESSED;
        if (button->effect != NULL)
            button->effect(window);
        return sfTrue;
    } else {
        if (IS_PRESSED(button))
            button->state = RELEASED;
        sfRectangleShape_setFillColor(button->rect, sfWhite);
        return sfFalse;
    };
}

static sfBool is_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, event->x, event->y)) {
        sfRectangleShape_setFillColor(button->rect, sfGray);
        if (!IS_LOCKED(button) && !IS_PRESSED(button)) {
            button->state = HOVER;
            sfRectangleShape_setFillColor(button->rect, sfLightGray);
        }
        if (IS_LOCKED(button))
            sfRectangleShape_setFillColor(button->rect, sfDarkGray);
        return sfTrue;
    } else {
        sfRectangleShape_setFillColor(button->rect, sfWhite);
        if (IS_LOCKED(button))
            sfRectangleShape_setFillColor(button->rect, sfDarkGray);
        else
            button->state = NONE;
        return sfFalse;
    }
}

void button_set_event_functions(button_t *button)
{
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
}
