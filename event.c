/*
** EPITECH PROJECT, 2022
** My paint
** File description:
** event
*/

#include <unistd.h>
#include "graphics.h"
#include "my.h"
#include "color.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <stdio.h>

static void move_mouse_event(sfEvent *event, windowbuffer_t *window)
{
    window->menu->is_open(window->menu, &event->mouseMove);
}

static void resize_event(sfEvent *event, windowbuffer_t *window)
{
    sfVector2u size = {.x = event->size.width, .y = event->size.height};

    sfRenderWindow_setSize(window->screen, size);
    sfView_setSize(window->view, (sfVector2f) {.x = size.x, .y = size.y});
    sfView_setCenter(window->view, (sfVector2f) {size.x / 2.0, size.y / 2.0});
    sfRenderWindow_setView(window->screen, window->view);
    window->height = size.y;
    window->width = size.x;
}

void event_key_button(windowbuffer_t *window, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
        (event->key.code == sfKeyUp || event->key.code == sfKeyAdd))
        window->x += 50;
    if (event->type == sfEvtKeyPressed &&
        (event->key.code == sfKeyDown || event->key.code == sfKeySubtract))
        window->x -= 50;
    if (event->type == sfEvtMouseButtonPressed) {
        window->menu->is_clicked(window->menu, &event->mouseButton, window);
        window->menu->is_open(window->menu, &event->mouseMove);
    }
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window->screen);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        sfRenderWindow_close(window->screen);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyS) {
        save_to_jpg(window);
        save_to_png(window);
        save_to_bmp(window);
    }
}

void events_tests(sfEvent *event, windowbuffer_t *window)
{
    event_key_button(window, event);
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window->screen);
    };
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyC) {
        window->color_enum += 1;
        if (window->color_enum >= (sizeof(COLOR) / sizeof(COLOR[0])))
            window->color_enum = 0;
        window->color = COLOR[window->color_enum];
    }
    if (event->type == sfEvtMouseMoved) {
        move_mouse_event(event, window);
        print_pen(window, window->text->vertices, event,
            window->text->renderTexture);
        remove_pen(window, window->text->sprite2, event,
            window->text->renderTexture);
    }
    if (event->type == sfEvtResized) {
        resize_event(event, window);
    }
}
