/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_square_root.c
*/

int ml_sqrt(int nb)
{
    if (nb < 0)
        return 0;
    else if (nb == 1)
        return 1;
    for (int i = 1; i <= nb / 2; i++)
        if (i * i == nb)
            return i;
    return 0;
}
