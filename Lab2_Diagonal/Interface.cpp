#include "Interface.h"
#include <iostream>

void MainInterface() {
    int var;
    cout << "�������� �������, � ������� ������ ��������\n"
        << "\t1: ������\n"
        << "\t2: �������\n"
        << "������� �����: ";
    cin >> var;

    switch (var) {
        case 1: InterfaceVector(); break;
        case 2: InterfaceMatrix(); break;
        default: break;
    }
}