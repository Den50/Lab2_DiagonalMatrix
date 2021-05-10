#include "InterfaceVector.h"

using namespace MAIN;
int chooseType() {
    int type;
    cout << "Выберете тип, с которым будете работать: \n"
        << "\t1: int\n"
        << "\t2: float\n"
        << "\t3: complex\n"
        << "Введите число: ";
    cin >> type;

    return type;
}
int chooseFunction() {
    int func;
    cout << "Выберете функцию, которую нужно произвести над векторами: \n"
        << "\t1: Суммировать вектора\n"
        << "\t2: Вычесть один вектор из другого\n"
        << "\t3: Умножить вектор на скаляр\n"
        << "\t4: Нормализовать вектор\n"
        << "\t5: Скалярное умножение векторов\n"
        << "Введите число: ";
    cin >> func;

    return func;
}
template<class T>
void saveVector(ArraySequence<Vector<T>>* Arr, Vector<T>* n_vector) {
    Arr->Append(n_vector);
}

template<class T>
void outputTypedVector(ArraySequence<Vector<T>>* Arr, int index) {
    auto k = Arr->Get(index);
    cout << k << endl;
}

void menuVector() {
    auto* intArr = new ArraySequence<Vector<int>>;
    auto* floatArr = new ArraySequence<Vector<float>>;
    auto* complexArr = new ArraySequence<Vector<complex<int>>>;

    int oper;
    while (true) {
        cout << "Выберете операцию: \n"
            << "\t1: Ввести и запомнить вектор\n"
            << "\t2: Выполнить операцию над векторами\n"
            << "\t3: Вывести вектор в консоль\n"
            << "\t4: Закончить выполнение программы\n"
            << "Введите число: ";
        cin >> oper;

        if (oper == 4)
            break;

        switch (oper) {
        case 1: inputAndSaveVector(intArr, floatArr, complexArr); break;
        case 2: functionWithVector(intArr, floatArr, complexArr); break;
        case 3: outputVector(intArr, floatArr, complexArr); break;
        default: break;
        }
    }
}

void inputAndSaveVector(ArraySequence<Vector<int>>* intArr,
    ArraySequence<Vector<float>>* floatArr,
    ArraySequence<Vector<complex<int>>>* complexArr) {

    int type = chooseType();
    int count;
    cout << "Введите размерность вектора:";
    cin >> count;

    switch (type) {
    case 1: inputVectorTyped(intArr, count); break;
    case 2: inputVectorTyped(floatArr, count); break;
    case 3: inputVectorTyped(complexArr, count); break;
    default: break;
    }
}

template<class T>
void inputVectorTyped(ArraySequence<Vector<T>>* Arr, int count) {
    cout << "Введите координаты вектора по порядку ";
    ArraySequence<T> n_arr;
    T item;
    for (int i = 0; i < count; i++) {
        cin >> item;
        n_arr.Append(item);
    }
    Vector<T> n_vector(n_arr);
    Arr->Append(n_vector);
}

void functionWithVector(ArraySequence<Vector<int>>* intArr,
    ArraySequence<Vector<float>>* floatArr,
    ArraySequence<Vector<complex<int>>>* complexArr) {

    int type = chooseType();

    switch (type) {
    case 1: functionVectorTyped(intArr); break;
    case 2: functionVectorTyped(floatArr); break;
    case 3: functionVectorTyped(complexArr); break;
    default: break;
    }
}

template<class T>
void functionVectorTyped(ArraySequence<Vector<T>>* Arr) {
    int func = chooseFunction();
    int len = Arr->GetLength();
    int indexOfArr1 = -1;
    int indexOfArr2 = -1;

    if (func == 3 || func == 4) {
        cout << "В памяти находится \"" << len << "\" векторов" << endl;
        cout << "Выберете индекс вектора, с которым хотите работать:";
        cin >> indexOfArr1;
        if (indexOfArr1 >= len || indexOfArr1 < 0) {
            cout << "Вектора с таким индексом нет в памяти!" << endl;
            func = -1;
        }
    }
    else {
        cout << "В памяти находится \"" << len << "\" векторов" << endl;
        cout << "Выберете индексы векторов, с которыми хотите работать:";
        cin >> indexOfArr1;
        cin >> indexOfArr2;
        if (indexOfArr1 >= len || indexOfArr1 < 0 || indexOfArr2 >= len || indexOfArr2 < 0) {
            cout << "Вектора с таким индексом нет в памяти!" << endl;
            func = -1;
        }
    }

    T scalar;
    switch (func) {
    default:
        break;
    case 1:
        Arr->Append(Arr->Get(indexOfArr1).SumOfVectors(Arr->Get(indexOfArr2)));
        break;
    case 2:
        Arr->Append(Arr->Get(indexOfArr1).SubOfVectors(Arr->Get(indexOfArr2)));
        break;
    case 3:
        cout << "Введите скаляр, на который будете умножать:";
        cin >> scalar;
        Arr->Append(Arr->Get(indexOfArr1).MulOfVectors(scalar));
        break;
    case 4:
        Arr->Append(Arr->Get(indexOfArr1).Normalization());
        break;
    case 5:
        T result;
        result = Arr->Get(indexOfArr1).ScalarMulOfVectors(Arr->Get(indexOfArr2));
        cout << "А вот и результат умножения:" << result << endl;
        break;
    }//результат записывается в последнюю ячейку памяти массива

    if (func != 5) {
        Vector<T> resultVector(Arr->Get(Arr->GetLength() - 1));
        cout << resultVector << endl;
    }
}

void outputVector(ArraySequence<Vector<int>>* intArr,
    ArraySequence<Vector<float>>* floatArr,
    ArraySequence<Vector<complex<int>>>* complexArr) {

    int type = chooseType();
    int index;

    cout << "Введите индекс вектора, который хотите вывести:";
    cin >> index;

    switch (type) {
    case 1: outputTypedVector(intArr, index); break;
    case 2: outputTypedVector(floatArr, index); break;
    case 3: outputTypedVector(complexArr, index); break;
    default: break;
    }

}

