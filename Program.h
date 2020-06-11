#pragma once
struct ccomplex
{
    double real, imag; // действительна€ и мнима€ части
};

struct fractions
{
    int x, y; // числитель и знаменатель
};
// структура, обобщающа€ все имеющиес€ фигуры
struct shape
{
    // значени€ ключей дл€ каждой из фигур
    enum key { CCOMPLEX, FRACTIONS};
    key k; // ключ

    union // используем пр€мое включение
    {
        ccomplex c;
        fractions f;
    };
};
// ѕростейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 100 }; // максимальна€ длина
    int len; // текуща€ длина
    shape* cont[max_len];
};
