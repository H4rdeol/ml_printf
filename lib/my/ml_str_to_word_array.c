/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_str_to_word_array.c
*/

#include "mylib.h"

char **ml_str_to_array(char *buf)
{
    int lines = 0;
    int cols = 0;
    char **array = NULL;

    for (int i = 0; buf[i]; i++)
        if (buf[i] == '\n') lines++;
    array = malloc(sizeof(char *) * (lines + 1));
    array[lines] = NULL;
    for (int i = 0; i < lines; i++) {
        cols = 0;
        for (; buf[cols] != '\n'; cols++);
        array[i] = malloc(sizeof(char) * (cols + 1));
        for (int j = 0; j < cols; j++) {
            array[i][j] = *buf;
            buf++;
        }
        array[i][cols] = '\0';
        while (buf[0] == '\n') buf++;
    }
    return array;
}
