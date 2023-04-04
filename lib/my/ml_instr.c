/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_instr.c
*/

#include "mylib.h"

bool ml_instr(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return true;
    return false;
}
