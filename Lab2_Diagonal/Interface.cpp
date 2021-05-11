#include "Interface.h"
#include <iostream>

void MainInterface() {
    int var;
    cout << "Выберете вариант, с которым будете работать\n"
        << "\t1: Вектор\n"
        << "\t2: Матрица\n"
        << "Введите число: ";
    cin >> var;

    switch (var) {
        case 1: InterfaceVector(); break;
        case 2: InterfaceMatrix(); break;
        default: break;
    }
}