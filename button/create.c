/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** create a button
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics.h>
#include "button.h"
#include "const.h"

button_t *init_button(sfVector2f position, sfVector2f size, void *constant,
    enum BUTTON_ENUM which_button)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL) {
        free(button);
        return NULL;
    }
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    button->state = NONE;
    button->effect = BUTTON_EFFECT[which_button];
    button_setup_set_text(button, constant, BUTTON_NAME[which_button]);
    button_set_event_functions(button);
    button_set_lock_function(button);
    return button;
}
