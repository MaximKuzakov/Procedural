#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

struct ccomplex {
    double real, imag; // действительная и мнимая части
};

struct fractions {
    int x, y; // числитель и знаменатель
};

//добавление нового класса 
struct polar_coordinates {
    double angle;
    int distance;
};

// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key { CCOMPLEX, FRACTIONS, POLAR};
    key k; // ключ
    // используем прямое включение
    union  {
        ccomplex c;
        fractions f;
        polar_coordinates p;
    };
};

// Простейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 100 }; // максимальная длина
    int len; // текущая длина
    shape* cont[max_len];
};

void container_Init(container& c);
void container_Clear(container& c);
void container_In(container& c, ifstream& ifst);
void container_Out(container& c, ofstream& ofst);
void Sort(container& c);
void OutComplex(container& c, ofstream& ofst);
