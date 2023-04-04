/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_pow.c
*/

float ml_pow_float(int nb, int p)
{
    float tmp = 1.0f;

    if (p >= 0) {
        for (int i = 0; i < p; i++)
            tmp *= nb;
    } else {
        for (int i = 0; i > p; i--)
            tmp /= nb;
    }
    return tmp;
}

int ml_pow_int(int nb, int p)
{
    int tmp = 1;

    for (int i = 0; i < p; i++)
        tmp *= nb;
    return tmp;
}
