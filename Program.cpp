#include "Program.h"
#define when_c_is_full 100
using namespace std;

// Ввод параметров обобщенной фигуры из файла
void complex_In(ccomplex& c, ifstream& ifst) {
    bool flag = 1;
    ifst >> c.real;
    if (ifst.fail())
        flag = 0;
    if (ifst.eof())
        flag = 0;
    if (c.real <= 0)
        flag = 0;
    ifst >> c.imag;
    if(c.imag <= 0)
        flag = 0;
    if (ifst.fail())
        flag = 0;
    if (ifst.eof())
        flag = 0;
    if (flag == 0) {
        cout << "\nError input comlex numbers" << endl;
}
    
void complex_Out(ccomplex& c, ofstream& ofst) {
    ofst << "It is a Complex: " << c.real << " + " << c.imag << "i" << endl;
    cout << "It is a Complex: " << c.real << " + " << c.imag << "i" << endl;
}
    
//новая функция для ЛР2
double real_complex(ccomplex& c) {
    return sqrt(pow(c.imag, 2) + pow(c.real, 2));
}
    
void fractions_In(fractions& f, ifstream& ifst) {
    bool flag = 1;
    ifst >> f.x;
    if (ifst.fail())
        flag = 0;
    if (ifst.eof())
        flag = 0;
    if (f.x <= 0)
        flag = 0;
    ifst >> f.y;
    if (ifst.fail())
        flag = 0;
    if (ifst.eof())
        flag = 0;
    if (f.y <= 0)
        flag = 0;
    if (flag == 0) {
        cout << "\n\n\nError input fractions numbers" << endl << endl << endl;
    }
}

void fractions_Out(fractions& f, ofstream& ofst) {
    ofst << "It is a Fraction: " << f.x << "/" << f.y;
    cout << "It is a Fraction: " << f.x << "/" << f.y;
}
    
void coordinates_In(polar_coordinates& p, ifstream& ifst) {
    bool flag = 1;
    ifst >> p.angle;
    if (ifst.fail())
        flag = 0;
    if (ifst.eof())
        flag = 0;
    if (p.angle <= 0)
        flag = 0;
    
    ifst >> p.distance;
    if (ifst.fail())
        flag = 0;
    if (ifst.eof())
        flag = 0;
    if (p.distance <= 0)
        flag = 0;
    
    if (flag == 0) {
        cout << "\n\n\nError input polar coordinates" << endl << endl << endl;
    }
}
    
void coordinates_Out(polar_coordinates& p, ofstream& ofst) {
    ofst << "These are polar coordinates: " << p.angle << " (angle), " 
        << p.distance << " (distance)" << endl;
    cout << "These are polar coordinates: " << p.angle << " (angle), " 
        << p.distance << " (distance)" << endl;
}
    
//новая функция для ЛР2
double real_fractions(fractions& f) {
    double result = (double)f.x;
    return result / f.y;
}
    
double Real(shape& s) {
    switch (s.k) {
    case shape::key::CCOMPLEX:
        return real_complex(s.c);
    case shape::key::FRACTIONS:
        return real_fractions(s.f);
    // нет способа привести полярные координаты к действительному числу
    case shape::key::POLAR:
        return 0.0;
    default:
        return -1;
    }
}
    
// Cравнение ключей двух программных объектов
bool Compare(shape* first, shape* second) {
    return Real(*first) < Real(*second);
}
    
// Сортировка содержимого контейнера
void Sort(container& c) {
    for (int i = 0; i < c.len - 1; i++) {
        for (int j = i + 1; j < c.len; j++) {
            if (Compare(c.cont[i], c.cont[j])) {
                shape* tmp = c.cont[i];
                c.cont[i] = c.cont[j];
                c.cont[j] = tmp;
            }
        }
    }
}
    
// Инициализация контейнера
void container_Init(container& c) {
    c.len = 0;
}
    
// Очистка контейнера от элементов
void container_Clear(container& c) {
    for (int i = 0; i < c.len; i++)
        delete c.cont[i];
    c.len = 0;
}

//----------------------------------------------------
shape* shape_In(ifstream& ifst) {
    shape* sp;
    int k;
    ifst >> k;
    switch (k)
    {
    case 1:
        sp = new shape;
        sp->k = shape::key::CCOMPLEX;
        complex_In(sp->c, ifst);
        return sp;
    case 2:
        sp = new shape;
        sp->k = shape::key::FRACTIONS;
        fractions_In(sp->f, ifst);
        //считывание количества символов в строке единицы измерения
        int amount;
        ifst >> amount;
        //считывание строки нового поля - единица измерения
        for (int i = 0; i < amount; i++) {
            char sb;
            ifst >> sb;
            sp->unit.push_back(sb);
        }
        return sp;
    case 3:
        sp = new shape;
        sp->k = shape::key::POLAR;
        coordinates_In(sp->p, ifst);
        return sp;
    default:
        return 0;
    }
}

void shape_Out(shape& s, ofstream& ofst) {
    switch (s.k) {
    case shape::key::CCOMPLEX:
        complex_Out(s.c, ofst);
        break;
    case shape::key::FRACTIONS:
        fractions_Out(s.f, ofst);
        cout << s.unit << endl;
        ofst << s.unit << endl;
        break;
    case shape::key::POLAR:
        coordinates_Out(s.p, ofst);
        break;
    default:
        ofst << "Incorrect numbers!" << endl;
    }
}
    
// Ввод содержимого контейнера
void container_In(container& c, ifstream& ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = shape_In(ifst)) != 0) {
            c.len++;
            if (c.len == when_c_is_full) {
                cout << "Container is full" << endl;
                break;
            }
        }
    }
}
    
// Вывод только первого ключа
void OutComplex(container& c, ofstream& ofst) {
    ofst << "Only Complex." << endl;
    cout << "Only Complex." << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        cout << i << ": ";
        //Включение вывода приведения чисел к действительному числу, при вызове функции OnlyComplex
        if (c.cont[i]->k == shape::CCOMPLEX) {
            shape_Out(*(c.cont[i]), ofst);
            ofst << "Real equivalent = " << Real(*c.cont[i]) << endl;
            cout << "Real equivalent = " << Real(*c.cont[i]) << endl;
        }
        else {
            ofst << endl;
            cout << endl;
        }
    }
}
    
// вывод содержимого контейнера в указанный поток
void container_Out(container& c, ofstream& ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    cout << "Container contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        cout << i << ": ";
        shape_Out(*(c.cont[i]), ofst);
        ofst << "Real equivalent = " << Real(*c.cont[i]) << endl;
        cout << "Real equivalent = " << Real(*c.cont[i]) << endl;
    }
}
