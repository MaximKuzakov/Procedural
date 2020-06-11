#pragma once
struct ccomplex
{
    double real, imag; // �������������� � ������ �����
};

struct fractions
{
    int x, y; // ��������� � �����������
};
// ���������, ���������� ��� ��������� ������
struct shape
{
    // �������� ������ ��� ������ �� �����
    enum key { CCOMPLEX, FRACTIONS};
    key k; // ����

    union // ���������� ������ ���������
    {
        ccomplex c;
        fractions f;
    };
};
// ���������� ��������� �� ������ ����������� �������
struct container {
    enum { max_len = 100 }; // ������������ �����
    int len; // ������� �����
    shape* cont[max_len];
};
