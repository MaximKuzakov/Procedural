#include "Program.h"
#include <fstream>
#include <iostream>
#include <cmath>
#define when_c_is_full 100
using namespace std;

// ���� ���������� ���������� ������ �� �����
void complex_In(ccomplex& c, ifstream& ifst)
{
    ifst >> c.real >> c.imag;
}
void complex_Out(ccomplex& c, ofstream& ofst)
{
    ofst << "It is a Complex: " << c.real << " + " << c.imag << "i" << endl;
    cout << "It is a Complex: " << c.real << " + " << c.imag << "i" << endl;
}
void fractions_In(fractions& f, ifstream& ifst)
{
    ifst >> f.x >> f.y;
}
void fractions_Out(fractions& f, ofstream& ofst)
{
    ofst << "It is a Fraction: " << f.x << "/" << f.y << endl;
    cout << "It is a Fraction: " << f.x << "/" << f.y << endl;
}
// ������������� ����������
void container_Init(container& c)
{
    c.len = 0;
}
// ������� ���������� �� ��������� (������������ ������)
void container_Clear(container& c)
{
    for (int i = 0; i < c.len; i++)
        delete c.cont[i];
    c.len = 0;
}

//----------------------------------------------------
shape* shape_In(ifstream& ifst)
{
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
        return sp;
    default:
        return 0;
    }
}

void shape_Out(shape& s, ofstream& ofst)
{
    switch (s.k)
    {
    case shape::key::CCOMPLEX:
        complex_Out(s.c, ofst);
        break;
    case shape::key::FRACTIONS:
        fractions_Out(s.f, ofst);
        break;
    default:
        ofst << "Incorrect numbers!" << endl;
    }
}
// ���� ����������� ���������� �� ���������� ������
void container_In(container& c, ifstream& ifst)
{

    while (!ifst.eof())
    {
        if ((c.cont[c.len] = shape_In(ifst)) != 0)
        {
            c.len++;
            if (c.len == when_c_is_full)
            {
                cout << "Container is full" << endl;
                break;
            }
        }
    }
}
// ����� ����������� ���������� � ��������� �����
void container_Out(container& c, ofstream& ofst)
{
    ofst << "Container contains " << c.len << " elements." << endl;
    cout << "Container contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++)
    {
        ofst << i << ": ";
        cout << i << ": ";
        shape_Out(*(c.cont[i]), ofst);
    }
}