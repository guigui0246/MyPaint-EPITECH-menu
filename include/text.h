/*
** EPITECH PROJECT, 2023
** paintmyh
** File description:
** myh
*/

#ifndef TEXT_H

    #define TEXT_H

    #include <SFML/Window.h>
    #include <SFML/Graphics/Color.h>
    #include "graphics.h"


    typedef struct text {
        sfTexture *texture;
        sfSprite *sprite;
        sfTexture *texture2;
        sfSprite *sprite2;
        sfVertexArray *vertices;
        sfVertexArray *vertices2;
        sfRenderTexture *renderTexture;
    } text_t;

    typedef struct load_text {
        sfTexture *texture;
    } load_t;

    void print_pen(windowbuffer_t* window, sfVertexArray *vertices,
        sfEvent *event, sfRenderTexture *renderTexture);
    void remove_pen(windowbuffer_t *window, sfSprite *sprite, sfEvent *event,
        sfRenderTexture *renderTexture);
    void save_to_jpg(windowbuffer_t *window);
    void save_to_png(windowbuffer_t *window);
    void save_to_bmp(windowbuffer_t *window);

#endif
