/*
** EPITECH PROJECT, 2023
** temppaint
** File description:
** button
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics.h>
#include "button.h"

void draw_button(sfRenderWindow *window, button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}

void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfText_destroy(button->text);
    free(button);
}
