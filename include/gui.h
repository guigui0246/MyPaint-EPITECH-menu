/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** gui
*/

#ifndef GUI_H_
    #define GUI_H_

    #include "button.h"

    #ifndef MENU_MACROS
        #define MENU_MACROS
        #define IS_FIX_OPEN(menu) (menu->state == FIX_OPEN || ALL_OPEN(menu))
        #define IS_OPEN(menu) (menu->state == OPEN || IS_FIX_OPEN(menu))
        #define IS_CLOSED(menu) (menu->state == CLOSED || IS_LOCKED(menu))
    #endif

enum object_type {
    _ = 0,
    BUTTON,
    MENU
};

enum e_gui_state;
enum BUTTON_ENUM;
struct s_gui_drop_menu;
typedef struct button_s button_t;

typedef union s_gui_object_s {
    button_t *button;
    struct s_gui_drop_menu *menu;
} s_gui_object_t;

typedef struct s_gui_options {
    union s_gui_object_s *option;
    enum object_type type;
    struct s_gui_options *next;
} s_gui_options_t;

typedef struct s_gui_drop_menu {
    struct button_s *button;
    struct s_gui_options *options;
    sfBool (*is_open)(struct s_gui_drop_menu *, sfMouseMoveEvent *event);
    enum e_gui_state state;
    void (*lock) (struct s_gui_drop_menu *);
    void (*unlock) (struct s_gui_drop_menu *);
    sfBool (*is_clicked)(struct s_gui_drop_menu *, sfMouseButtonEvent *,
    windowbuffer_t *);
} s_gui_drop_menu_t;

typedef struct s_gui_drop_menu menu_bar_t;

s_gui_drop_menu_t *create_drop_menu(sfVector2f position, sfVector2f size,
    void *constant, enum BUTTON_ENUM which_button);
void transform_to_menu(s_gui_options_t *option);
s_gui_drop_menu_t *add_option_drop_menu_d(s_gui_drop_menu_t *drop_menu,
    void *constant, enum BUTTON_ENUM which_button);
s_gui_drop_menu_t *add_option_drop_menu_right(s_gui_drop_menu_t *drop_menu,
    void *constant, enum BUTTON_ENUM which_button);
void s_gui_drop_menu_set_lock_function(s_gui_drop_menu_t *drop_menu);
void s_gui_drop_menu_set_click_function(s_gui_drop_menu_t *drop_menu);
void s_gui_drop_menu_set_open_function(s_gui_drop_menu_t *drop_menu);
void show_menu(sfRenderWindow *window, s_gui_drop_menu_t *drop_menu);
void destroy_drop_menu(s_gui_drop_menu_t *drop_menu);
menu_bar_t *generated_menu_bar(void *constant);

#endif
