#include "Matrix.h"
#include <iostream>

using namespace MAIN;

//template Matrix<int>;

template <class T>
Matrix<T>::Matrix() {
    /*ArraySequence<ArraySequence<T>> new_matrix();
    this->matrix = new_matrix;*/
    size = 0;
}

template <class T>
Matrix<T>::Matrix(T** items, int count) {
    for (int i = 0; i < count; i++) {
        ArraySequence<T> element;
        for (int j = 0; j < count; j++) {
            element.Append(items[i][j]);
        }
        matrix.Append(element);
    }
    size = count;
}

template <class T>
Matrix<T>::Matrix(const ArraySequence<ArraySequence<T>>& n_matrix) {
    //int count = n_matrix.dynamicArray.GetLen();
    //for (int i = 0; i < count; i++) {
    //    ArraySequence<T> element;
    //    for (int j = 0; j < count; j++) {
    //        element.Append(n_matrix.dynamicArray.Get(i).Get(j));
    //    }
    //    matrix.Append(element);
    //    size = n_matrix.dynamicArray.GetLen();
    //}
    //matrix = n_matrix;
}


template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < size; i++) {
        matrix.Get(i).Delete_ArraySequence();
    }
    matrix.Delete_ArraySequence();
    size = 0;
}

template <class T>
void Matrix<T>::DeleteMatrix() {
    for (int i = 0; i < size; i++) {
        matrix.Get(i).Delete_ArraySequence();
    }
    matrix.Delete_ArraySequence();
    size = 0;
}

template<class T>
T Matrix<T>::Get(int line, int column) {
    return matrix.Get(line).Get(column);
}

template<class T>
int Matrix<T>::GetLength() {
    return this->size;
}

template<class T>
Matrix<T> Matrix<T>::Summ(Matrix<T>& _matrix) {
    Matrix<T> new_matrix;
    for (int i = 0; i < size; i++) {
        ArraySequence<T> element;
        for (int j = 0; j < size; j++) {
            element.Append(matrix.Get(i).Get(j) + _matrix.matrix.Get(i).Get(j));
        }
        new_matrix.matrix.Append(element);
    }
    new_matrix.size = size;
    return new_matrix;
}

template<class T>
Matrix<T> Matrix<T>::Subs(Matrix<T>& _matrix) {
    Matrix<T> new_matrix;
    for (int i = 0; i < size; i++) {
        ArraySequence<T> element;
        for (int j = 0; j < size; j++) {
            element.Append(matrix.Get(i).Get(j) - _matrix.matrix.Get(i).Get(j));
        }
        new_matrix.matrix.Append(element);
    }
    new_matrix.size = size;
    return new_matrix;
}


template<class T>
Matrix<T> Matrix<T>::MultiplyOnAlpha(T alpha) {
    Matrix<T> new_matrix;
    for (int i = 0; i < size; i++) {
        ArraySequence<T> element;
        for (int j = 0; j < size; j++) {
            element.Append(matrix.Get(i).Get(j) * alpha);
        }
        new_matrix.matrix.Append(element);
    }
    new_matrix.size = size;
    return new_matrix;
}

template<class T>
void Matrix<T>::ElemTransformOfCols(int col1, int col2, T scalar) {
    Matrix<T> new_matrix;
    for (int i = 0; i < size; i++) {
        ArraySequence<T> element;
        if (i == col1) {
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(col2).Get(j) * scalar + matrix.Get(col1).Get(j));
            };
        }
        else {
            for (int j = 0; j < size; j++) {
                element.Append(matrix.Get(i).Get(j));
            }
        }
        new_matrix.matrix.Append(element);
    }
    new_matrix.size = size;
    matrix = new_matrix.matrix;
}

template<class T>
void Matrix<T>::ElemTransformOfRows(int row1, int row2, T alpha) {
    Matrix<T> new_matrix;
    for (int i = 0; i < size; i++) {
        ArraySequence<T> element;
        for (int j = 0; j < size; j++) {
            if (j == row1) {
                element.Append(matrix.Get(i).Get(row2) * alpha + matrix.Get(i).Get(row1));
            }
            else {
                element.Append(matrix.Get(i).Get(j));
            }
        }
        new_matrix.matrix.Append(element);
    }
    new_matrix.size = size;
    matrix = new_matrix.matrix;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> n_matrix) {
    matrix = n_matrix.matrix;
    size = n_matrix.size;
    return *this;
}

//template<class T>
//std::ostream& Matrix<T>::operator<< (std::ostream& cout, Matrix<T>& n_matrix) {
//    for (int j = 0; j < n_matrix.GetLength(); j++) { // по строкам
//        for (int i = 0; i < n_matrix.GetLength(); i++) {
//            cout << n_matrix.Get(j, i) << "   ";
//        }
//        cout << std::endl;
//    }
//    cout << std::endl;
//
//    return cout;
//}
