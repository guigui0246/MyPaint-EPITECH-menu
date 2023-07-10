/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RectangleShape.h>
#include "gui.h"

void show_menu(sfRenderWindow *window, s_gui_drop_menu_t *drop_menu)
{
    s_gui_options_t *next = drop_menu->options;

    draw_button(window, drop_menu->button);
    while (IS_OPEN(drop_menu) && next != NULL) {
        if (next->type == BUTTON)
            draw_button(window, next->option->button);
        if (next->type == MENU)
            show_menu(window, next->option->menu);
        next = next->next;
    }
}

static void add_menu(menu_bar_t *bar, void *constant)
{
    add_option_drop_menu_right(bar, constant, FILE_B);
    add_option_drop_menu_right(bar, constant, EDIT_B);
    add_option_drop_menu_right(bar, constant, HELP_MENU_B);
    transform_to_menu(bar->options);
    transform_to_menu(bar->options->next);
    transform_to_menu(bar->options->next->next);
}

static void file_menu(menu_bar_t *file, void *constant)
{
    add_option_drop_menu_d(file, constant, NEW_B);
    add_option_drop_menu_d(file, constant, OPEN_B);
    add_option_drop_menu_d(file, constant, SAVE_B);
    add_option_drop_menu_d(file, constant, QUIT_B);
    transform_to_menu(file->options->next);
    transform_to_menu(file->options->next->next);
    add_option_drop_menu_right(file->options->next->option->menu,
        constant, L_JPG_B);
    add_option_drop_menu_d(file->options->next->option->menu,
        constant, L_PNG_B);
    add_option_drop_menu_d(file->options->next->option->menu,
        constant, L_BMP_B);
    add_option_drop_menu_right(file->options->next->next->option->menu,
        constant, S_JPG_B);
    add_option_drop_menu_d(file->options->next->next->option->menu,
        constant, S_PNG_B);
    add_option_drop_menu_d(file->options->next->next->option->menu,
        constant, S_BMP_B);
}

menu_bar_t *generated_menu_bar(void *constant)
{
    menu_bar_t *bar = create_drop_menu((sfVector2f) {-100, 0},
        (sfVector2f) {100, 30}, constant, NONE_B);

    add_menu(bar, constant);
    file_menu(bar->options->option->menu, constant);
    add_option_drop_menu_d(bar->options->next->option->menu, constant, PEN_B);
    add_option_drop_menu_d(bar->options->next->option->menu, constant, SIZE_B);
    bar->button->lock(
        bar->options->next->option->menu->options->next->option->button);
    add_option_drop_menu_d(bar->options->next->option->menu, constant, COLOR_B);
    add_option_drop_menu_d(bar->options->next->option->menu, constant,
        ERASER_B);
    add_option_drop_menu_d(bar->options->next->next->option->menu, constant,
        ABOUT_B);
    bar->button->lock(
        bar->options->next->next->option->menu->options->option->button);
    add_option_drop_menu_d(bar->options->next->next->option->menu, constant,
        HELP_B);
    return bar;
}
