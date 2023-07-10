/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** text for button
*/

#include "button.h"

void button_setup_set_text(button_t *button, sfFont **constant, char const *txt)
{
    sfVector2f rect = sfRectangleShape_getPosition(button->rect);

    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 20);
    sfText_setPosition(button->text, rect);
    sfText_setFont(button->text, constant[ARIAL]);
    sfText_setColor(button->text, sfBlack);
    sfText_setString(button->text, txt);
}
