/*
** EPITECH PROJECT, 2023
** temppaint
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <SFML/Graphics/RectangleShape.h>
    #include <SFML/Graphics.h>

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED,
    OPEN,
    LOCKED,
    LOCKED_OPEN,
    FIX_OPEN,
    CLOSED
};

    #include "graphics.h"

    #ifndef BUTTON_NAME_AND_EFFECT
        #define BUTTON_NAME_AND_EFFECT

        enum BUTTON_ENUM {
            NONE_B = 0,
            FILE_B = 1,
            NEW_B = 2,
            OPEN_B = 3,
            SAVE_B = 4,
            EDIT_B = 5,
            PEN_B = 6,
            ERASER_B = 7,
            SIZE_B = 8,
            COLOR_B = 9,
            QUIT_B = 10,
            HELP_MENU_B = 11,
            ABOUT_B = 12,
            HELP_B = 13,
            S_JPG_B = 14,
            S_PNG_B = 15,
            S_BMP_B = 16,
            L_JPG_B = 17,
            L_PNG_B = 18,
            L_BMP_B = 19
        };

    #endif

    #ifndef CONSTANTS_FILES
        #define CONSTANTS_FILES
        #define ARIAL_FILE ("./Files/arial.ttf")

        enum CONSTANTS {
            ARIAL
        };
        #define SIZE_CONSTANTS 1

    #endif

    #ifndef BUTTON_MACROS
        #define BUTTON_MACROS
        #define IS_HOVER(button) (button->state == HOVER)
        #define IS_PRESSED(button) (button->state == PRESSED)
        #define IS_RELEASED(button) (button->state == RELEASED)
        #define ALL_OPEN(button) (button->state == LOCKED_OPEN)
        #define IS_LOCKED(button) (button->state == LOCKED || ALL_OPEN(button))
    #endif

    #ifndef sfGray
        #define sfGray ((sfColor) {0x88, 0x88, 0x88, 0xff})
    #endif

    #ifndef sfDarkGray
        #define sfDarkGray ((sfColor) {0x33, 0x33, 0x33, 0xff})
    #endif

    #ifndef sfLightGray
        #define sfLightGray ((sfColor) {0xb5, 0xb5, 0xb5, 0xff})
    #endif

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *,
        windowbuffer_t *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent*);
    void (*lock) (struct button_s *);
    void (*unlock) (struct button_s *);
    enum e_gui_state state;
    sfText *text;
    void (*effect) (windowbuffer_t *);
} button_t;

void button_setup_set_text(button_t *button, sfFont **constant,
    char const *txt);
button_t *init_button(sfVector2f position, sfVector2f size, void *constant,
    enum BUTTON_ENUM which_button);
void destroy_button(button_t *button);
void button_set_lock_function(button_t *button);
void button_set_event_functions(button_t *button);
void draw_button(sfRenderWindow *window, button_t *button);
sfSprite *load_pen(void);

#endif
