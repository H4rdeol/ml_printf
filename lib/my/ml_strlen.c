/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_strlen.c
*/

int ml_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
