/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_strcmp.c
*/

#include "mylib.h"

bool ml_strcmp(char *word1, char *word2)
{
    int i = 0;

    while (word1[i]){
        if (word1[i] != word2[i])
            return false;
        i++;
    }
    return true;
}

bool ml_strncmp(char *word1, char *word2, int n)
{
    int i = 0;

    while (word1[i] && i < n){
        if (word1[i] != word2[i])
            return false;
        i++;
    }
    return true;
}
