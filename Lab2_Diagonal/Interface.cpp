#include "Interface.h"
#include <iostream>

void menuAll() {
    int var;
    cout << "�������� �������, � ������� ������ ��������\n"
        << "\t1: ������\n"
        << "\t2: �������\n"
        << "������� �����: ";
    cin >> var;

    switch (var) {
        case 1: menuVector(); break;
        case 2: menuMatrix(); break;
        default: break;
    }
}