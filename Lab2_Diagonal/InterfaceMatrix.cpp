#include "InterfaceMatrix.h"

using namespace MAIN;

int chooseTypeMatrix() {
    int type;
    cout << "Выберете тип, с которым будете работать: \n"
        << "\t1: int\n"
        << "\t2: float\n"
        << "\t3: complex\n"
        << "Введите число: ";
    cin >> type;

    return type;
}
int chooseFunctionMatrix() {
    int func;
    cout << "Выберете функцию, которую нужно произвести над матрицами: \n"
        << "\t1: Суммировать матрицы\n"
        << "\t2: Вычесть одну матрицу из другой\n"
        << "\t3: Умножить матрицу на скаляр\n"
        << "\t4: Элементарное преобразование столбцов\n"
        << "\t5: Элементарное преобразование строк\n"
        << "Введите число: ";
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
        cout << "Выберете операцию: \n"
            << "\t1: Ввести и запомнить матрицу\n"
            << "\t2: Выполнить операцию над матрицами\n"
            << "\t3: Вывести матрицу в консоль\n"
            << "\t4: Закончить выполнение программы\n"
            << "Введите число: ";
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
    cout << "Введите размерность матрицы:";
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
    cout << "Введем массив -> " << endl;
    for (int i = 0; i < count; i++) {
        cout << "Введите по порядку элементы \"" << i << "\" строки матрицы" << endl;
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
        cout << "В памяти находится \"" << len << "\" матриц" << endl;
        cout << "Выберете индекс матрицы, с которой хотите работать:";
        cin >> indexOfArr1;
        if (indexOfArr1 >= len || indexOfArr1 < 0) {
            cout << "Матрицы с таким индексом нет в памяти!" << endl;
            func = -1;
        }
    }
    else {
        cout << "В памяти находится \"" << len << "\" матриц" << endl;
        cout << "Выберете индексы матриц, с которыми хотите работать:";
        cin >> indexOfArr1;
        cin >> indexOfArr2;
        if (indexOfArr1 >= len || indexOfArr1 < 0 || indexOfArr2 >= len || indexOfArr2 < 0) {
            cout << "Матрицы с таким индексом нет в памяти!" << endl;
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
            cout << "Нельзя складывать матрицы разных размерностей!!!" << endl;
            problem = 1;
            break;
        }
        Arr->Append(Arr->Get(indexOfArr1).SumOfMatrix(Arr->Get(indexOfArr2)));
        break;
    case 2:
        if (Arr->Get(indexOfArr1).GetSize() != Arr->Get(indexOfArr2).GetSize()) {
            cout << "Нельзя складывать матрицы разных размерностей!!!" << endl;
            problem = 1;
            break;
        }
        Arr->Append(Arr->Get(indexOfArr1).SubOfMatrix(Arr->Get(indexOfArr2)));
        break;
    //case 3:
    //    cout << "Введите скаляр, на который будете умножать:";
    //    cin >> scalar;
    //    Arr->Append(Arr->Get(indexOfArr1).MultOfMatrix(scalar));
    //    break;
    }
    //case 4:
    //    cout << "Введите скаляр, на который будете умножать столбец:";
    //    cin >> scalar;
    //    cout << "Матрица состоит из \"" << size << "\" строк и столбцов" << endl;
    //    cout << "Введите индекс столбца, которой нужно умножить на скаляр:";
    //    cin >> column2;
    //    cout << "Введите индекс столбца, к которому нужно прибавить другой столбец умноженнй на скаляр:";
    //    cin >> column1;
    //    Arr->Get(indexOfArr1).ElemTransformOfColumns(column1, column2, scalar);
    //    Arr->Append(Arr->Get(indexOfArr1));
    //    break;
    //case 5:
    //    cout << "Введите скаляр, на который будете умножать строку:";
    //    cin >> scalar;
    //    cout << "Матрица состоит из \"" << size << "\" строк и столбцов" << endl;
    //    cout << "Введите индекс строки, которой нужно умножить на скаляр:";
    //    cin >> line2;
    //    cout << "Введите индекс строки, к которой нужно прибавить другую строку умноженную на скаляр:";
    //    cin >> line1;
    //    Arr->Get(indexOfArr1).ElemTransformOfLines(line1, line2, scalar);
    //    Arr->Append(Arr->Get(indexOfArr1));
    //}//результат записывается в последнюю ячейку памяти массива

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

    cout << "Введите индекс матрицы, который хотите вывести:";
    cin >> index;

    switch (type) {
    case 1: outputTypedMatrix(intArr, index); break;
    case 2: outputTypedMatrix(floatArr, index); break;
    case 3: outputTypedMatrix(complexArr, index); break;
    default: break;
    }
}

