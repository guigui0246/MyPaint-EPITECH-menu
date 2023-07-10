/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** header
*/

#ifndef MY_H
    #define MY_H

    #ifndef bool
        typedef unsigned char bool_t;
        #define bool bool_t;
    #endif
    #ifndef true
        #define true (1)
    #endif
    #ifndef false
        #define false (0)
    #endif
    #ifndef min
        #define min(a, b) ((a) < (b) ? (a) : (b))
    #endif
    #ifndef max
        #define max(a, b) ((a) < (b) ? (b) : (a))
    #endif

    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);

#endif
