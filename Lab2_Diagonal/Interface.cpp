#include "Interface.h"
#include <iostream>

void menuAll() {
    int var;
    cout << "Выберете вариант, с которым будете работать\n"
        << "\t1: Вектор\n"
        << "\t2: Матрица\n"
        << "Введите число: ";
    cin >> var;

    switch (var) {
        case 1: menuVector(); break;
        case 2: menuMatrix(); break;
        default: break;
    }
}