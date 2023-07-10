/*
** EPITECH PROJECT, 2022
** Day 13 Graphic
** File description:
** Header for graphic components
*/

#ifndef GRAPHICS_H
    #define GRAPHICS_H

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include "color.h"

typedef struct s_gui_drop_menu s_gui_drop_menu_t;
typedef struct text text_t;

enum tool_enum {
    NO = 0,
    PEN,
    ERASER
};

typedef struct windowbuffer {
    sfRenderWindow *screen;
    int width;
    int height;
    s_gui_drop_menu_t *menu;
    void **constant;
    sfView *view;
    text_t *text;
    sfColor color;
    enum tool_enum tool;
    int x;
    enum color_enum color_enum;
    sfRenderWindow *help_window;
} windowbuffer_t;

    #include "text.h"
    #include "gui.h"

void events_tests(sfEvent *event, windowbuffer_t *window);
void window_cleanup(windowbuffer_t *window);
windowbuffer_t *make_window_size(unsigned int width,
    unsigned int height, char *title);
sfSprite *load_pen(void);
void load_image(windowbuffer_t *window, char *path);

#endif
