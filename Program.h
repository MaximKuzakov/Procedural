#pragma once
#include <string>
struct ccomplex
{
    double real, imag; // действительная и мнимая части
};

struct fractions
{
    int x, y; // числитель и знаменатель
};
// структура, обобщающая все имеющиеся фигуры
struct shape
{
    // значения ключей для каждой из фигур
    enum key { CCOMPLEX, FRACTIONS};
    key k; // ключ
    std::string unit; //единица измерения 
    union // используем прямое включение
    {
        ccomplex c;
        fractions f;
    };
};
// Простейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 100 }; // максимальная длина
    int len; // текущая длина
    shape* cont[max_len];
};
