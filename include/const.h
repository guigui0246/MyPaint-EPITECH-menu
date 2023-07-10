/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** const
*/

#ifndef CONST_H_
    #define CONST_H_

    #include <stdlib.h>

typedef struct windowbuffer windowbuffer_t;

void select_pen(windowbuffer_t *window);
void select_eraser(windowbuffer_t *window);
void close_window(windowbuffer_t *window);
void save_to_jpg(windowbuffer_t *window);
void save_to_png(windowbuffer_t *window);
void save_to_bmp(windowbuffer_t *window);
void load_from_jpg(windowbuffer_t *window);
void load_from_png(windowbuffer_t *window);
void load_from_bmp(windowbuffer_t *window);
void new_im(windowbuffer_t *window);
void choose_color(windowbuffer_t *window);
void show_help(windowbuffer_t *window);

const char *BUTTON_NAME[] = {"", "File", "New", "Open", "Save (S)", "Edit",
    "Pen", "Eraser", "Size", "Color", "Quit (Esc)", "Help", "About", "Help",
    ".jpg", ".png", ".bmp", ".jpg", ".png", ".bmp"};
const void *BUTTON_EFFECT[] = {NULL,
    NULL, //File
    &new_im, //New
    NULL, //Open
    NULL, //Save
    NULL, //Edit
    &select_pen, //Pen
    &select_eraser, //Eraser
    NULL, //Size
    &choose_color, //Color
    &close_window, //Quit
    NULL, //Help_Menu
    NULL, //About
    &show_help, //Help
    &save_to_jpg, //sjpg
    &save_to_png, //spng
    &save_to_bmp, //sbmp
    &load_from_jpg, //ljpg
    &load_from_png, //lpng
    &load_from_bmp //lbmp
};

#endif
