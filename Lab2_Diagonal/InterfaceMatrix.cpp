#include "InterfaceMatrix.h"

using namespace MAIN;

int chooseTypeMatrix() {
    int type;
    cout << "�������� ���, � ������� ������ ��������: \n"
        << "\t1: int\n"
        << "\t2: float\n"
        << "\t3: complex\n"
        << "������� �����: ";
    cin >> type;

    return type;
}
int chooseFunctionMatrix() {
    int func;
    cout << "�������� �������, ������� ����� ���������� ��� ���������: \n"
        << "\t1: ����������� �������\n"
        << "\t2: ������� ���� ������� �� ������\n"
        << "\t3: �������� ������� �� ������\n"
        << "\t4: ������������ �������������� ��������\n"
        << "\t5: ������������ �������������� �����\n"
        << "������� �����: ";
    cin >> func;

    return func;
}
template<class T>
void outputTypedMatrix(ArraySequence<Matrix<T>>* Arr, int index) {
    auto k = Arr->Get(index);
    cout << k << endl;
}
void menuMatrix() {
    auto* intArr = new ArraySequence<Matrix<int>>;
    auto* floatArr = new ArraySequence<Matrix<float>>;
    auto* complexArr = new ArraySequence<Matrix<complex<int>>>;

    int oper;
    while (true) {
        cout << "�������� ��������: \n"
            << "\t1: ������ � ��������� �������\n"
            << "\t2: ��������� �������� ��� ���������\n"
            << "\t3: ������� ������� � �������\n"
            << "\t4: ��������� ���������� ���������\n"
            << "������� �����: ";
        cin >> oper;

        if (oper == 4)
            break;

        switch (oper) {
        case 1: inputAndSaveMatrix(intArr, floatArr, complexArr); break;
        case 2: functionWithMatrix(intArr, floatArr, complexArr); break;
        case 3: outputMatrix(intArr, floatArr, complexArr); break;
        default: break;
        }
    }
}

void inputAndSaveMatrix(ArraySequence<Matrix<int>>* intArr,
    ArraySequence<Matrix<float>>* floatArr,
    ArraySequence<Matrix<complex<int>>>* complexArr) {
    int type = chooseTypeMatrix();
    int count;
    cout << "������� ����������� �������:";
    cin >> count;

    switch (type) {
    case 1: inputMatrixTyped(intArr, count); break;
    case 2: inputMatrixTyped(floatArr, count); break;
    case 3: inputMatrixTyped(complexArr, count); break;
    default: break;
    }
}
template <class T>
void inputMatrixTyped(ArraySequence<Matrix<T>>* Arr, int count) {
    //T *arr[count];
    T** arr = new T * [count];
    cout << "������ ������ -> " << endl;
    for (int i = 0; i < count; i++) {
        cout << "������� �� ������� �������� \"" << i << "\" ������ �������" << endl;
        T* arrcolumn = new T[count];
        for (int j = 0; j < count; j++) {
            cin >> arrcolumn[j];
        }
        arr[i] = arrcolumn;
    }

    Matrix<T> n_matrix(arr, count);
    Arr->Append(n_matrix);
}

void functionWithMatrix(ArraySequence<Matrix<int>>* intArr,
    ArraySequence<Matrix<float>>* floatArr,
    ArraySequence<Matrix<complex<int>>>* complexArr) {
    int type = chooseTypeMatrix();

    switch (type) {
    case 1: functionMatrixTyped(intArr); break;
    case 2: functionMatrixTyped(floatArr); break;
    case 3: functionMatrixTyped(complexArr); break;
    default: break;
    }
}

template<class T>
void functionMatrixTyped(ArraySequence<Matrix<T>>* Arr) {
    int func = chooseFunctionMatrix();
    int len = Arr->GetLength();
    int indexOfArr1 = -1;
    int indexOfArr2 = -1;

    if (func == 3 || func == 4 || func == 5) {
        cout << "� ������ ��������� \"" << len << "\" ������" << endl;
        cout << "�������� ������ �������, � ������� ������ ��������:";
        cin >> indexOfArr1;
        if (indexOfArr1 >= len || indexOfArr1 < 0) {
            cout << "������� � ����� �������� ��� � ������!" << endl;
            func = -1;
        }
    }
    else {
        cout << "� ������ ��������� \"" << len << "\" ������" << endl;
        cout << "�������� ������� ������, � �������� ������ ��������:";
        cin >> indexOfArr1;
        cin >> indexOfArr2;
        if (indexOfArr1 >= len || indexOfArr1 < 0 || indexOfArr2 >= len || indexOfArr2 < 0) {
            cout << "������� � ����� �������� ��� � ������!" << endl;
            func = -1;
        }
    }

    int size = Arr->Get(indexOfArr1).GetSize();

    T scalar;
    int line1;
    int line2;
    int column1;
    int column2;
    int problem = 0;
    switch (func) {
    default:
        break;
    case 1:
        if (Arr->Get(indexOfArr1).GetSize() != Arr->Get(indexOfArr2).GetSize()) {
            cout << "������ ���������� ������� ������ ������������!!!" << endl;
            problem = 1;
            break;
        }
        Arr->Append(Arr->Get(indexOfArr1).SumOfMatrix(Arr->Get(indexOfArr2)));
        break;
    case 2:
        if (Arr->Get(indexOfArr1).GetSize() != Arr->Get(indexOfArr2).GetSize()) {
            cout << "������ ���������� ������� ������ ������������!!!" << endl;
            problem = 1;
            break;
        }
        Arr->Append(Arr->Get(indexOfArr1).SubOfMatrix(Arr->Get(indexOfArr2)));
        break;
    //case 3:
    //    cout << "������� ������, �� ������� ������ ��������:";
    //    cin >> scalar;
    //    Arr->Append(Arr->Get(indexOfArr1).MultOfMatrix(scalar));
    //    break;
    }
    //case 4:
    //    cout << "������� ������, �� ������� ������ �������� �������:";
    //    cin >> scalar;
    //    cout << "������� ������� �� \"" << size << "\" ����� � ��������" << endl;
    //    cout << "������� ������ �������, ������� ����� �������� �� ������:";
    //    cin >> column2;
    //    cout << "������� ������ �������, � �������� ����� ��������� ������ ������� ��������� �� ������:";
    //    cin >> column1;
    //    Arr->Get(indexOfArr1).ElemTransformOfColumns(column1, column2, scalar);
    //    Arr->Append(Arr->Get(indexOfArr1));
    //    break;
    //case 5:
    //    cout << "������� ������, �� ������� ������ �������� ������:";
    //    cin >> scalar;
    //    cout << "������� ������� �� \"" << size << "\" ����� � ��������" << endl;
    //    cout << "������� ������ ������, ������� ����� �������� �� ������:";
    //    cin >> line2;
    //    cout << "������� ������ ������, � ������� ����� ��������� ������ ������ ���������� �� ������:";
    //    cin >> line1;
    //    Arr->Get(indexOfArr1).ElemTransformOfLines(line1, line2, scalar);
    //    Arr->Append(Arr->Get(indexOfArr1));
    //}//��������� ������������ � ��������� ������ ������ �������

    if (problem != 1) {
        Matrix<T> resultMatrix(Arr->Get(Arr->GetLength() - 1));
        cout << resultMatrix << endl;
    }
}

void outputMatrix(ArraySequence<Matrix<int>>* intArr,
    ArraySequence<Matrix<float>>* floatArr,
    ArraySequence<Matrix<complex<int>>>* complexArr) {

    int type = chooseTypeMatrix();
    int index;

    cout << "������� ������ �������, ������� ������ �������:";
    cin >> index;

    switch (type) {
    case 1: outputTypedMatrix(intArr, index); break;
    case 2: outputTypedMatrix(floatArr, index); break;
    case 3: outputTypedMatrix(complexArr, index); break;
    default: break;
    }
}

