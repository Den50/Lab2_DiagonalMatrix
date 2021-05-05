#pragma once

#include "ArraySequence.h"
#include <iostream>
#include <limits>


namespace MAIN {
    template <class T>
    class Matrix {
    private:
        ArraySequence<ArraySequence<T>> matrix;
        int size = 0;
    public:
        //Создание объекта
        Matrix() {
            ArraySequence<ArraySequence<T>> new_matrix;
            matrix = new_matrix;
            size = 0;
        }//Создание пустой матрицы

        Matrix(T** items, int count) {
            for (int i = 0; i < count; i++) {
                ArraySequence<T> element;
                for (int j = 0; j < count; j++) {
                    element.Append(items[i][j]);
                }
                matrix.Append(element);
            }
            size = count;
        }//Создание матрицы по массиву
        explicit Matrix(const ArraySequence<ArraySequence<T>>& n_matrix) {
            int count = n_matrix.dynamicArray.GetLen();
            for (int i = 0; i < count; i++) {
                ArraySequence<T> element;
                for (int j = 0; j < count; j++) {
                    element.Append(n_matrix.dynamicArray.Get(i).Get(j));
                }
                matrix.Append(element);
                size = n_matrix.dynamicArray.GetLen();
            }
            //matrix = n_matrix;
        }//Копирование исходной матрицы

        //Удаление объекта
        ~Matrix() {
            for (int i = 0; i < size; i++) {
                matrix.Get(i).Delete_ArraySequence();
            }
            matrix.Delete_ArraySequence();
            size = 0;
        }//деконструктор
        void Delete_Matrix() {
            for (int i = 0; i < size; i++) {
                matrix.Get(i).Delete_ArraySequence();
            }
            matrix.Delete_ArraySequence();
            size = 0;
        }//функция удаления

        //Декомпозиция
        T Get(int line, int column) {
            return matrix.Get(line).Get(column);
        }
        int GetSize() {
            return size;
        }
        void Set(T item, int row, int col) {
            ArraySequence<ArraySequence<T>> items;
            
            for (int i = 0; i < size; i++){
                ArraySequence<T> _item;
                for (int j = 0; j < size; j++){
                    i == row && j == col? _item.Append(item): _item.Append(this->Get(i, j));
                }
                items.Append(_item);
            }
            matrix = items;
        }

        //Операции
        Matrix<T> SumOfMatrix(Matrix<T>& b_matrix) {
            Matrix<T> new_matrix;
            for (int i = 0; i < size; i++) {
                ArraySequence<T> element;
                for (int j = 0; j < size; j++) {
                    element.Append(matrix.Get(i).Get(j) + b_matrix.matrix.Get(i).Get(j));
                }
                new_matrix.matrix.Append(element);
            }
            new_matrix.size = size;
            return new_matrix;
        }//сумма матриц

        Matrix<T> SubOfMatrix(Matrix<T>& b_matrix) {
            Matrix<T> new_matrix;
            for (int i = 0; i < size; i++) {
                ArraySequence<T> element;
                for (int j = 0; j < size; j++) {
                    element.Append(matrix.Get(i).Get(j) - b_matrix.matrix.Get(i).Get(j));
                }
                new_matrix.matrix.Append(element);
            }
            new_matrix.size = size;
            return new_matrix;
        }//разность матриц

        Matrix<T> MultOfMatrix(T scalar) {
            Matrix<T> new_matrix;
            for (int i = 0; i < size; i++) {
                ArraySequence<T> element;
                for (int j = 0; j < size; j++) {
                    element.Append(matrix.Get(i).Get(j) * scalar);
                }
                new_matrix.matrix.Append(element);
            }
            new_matrix.size = size;
            return new_matrix;
        }//Умножение на скаляр

        /*
        * Matrix norms are often used in determining the error of various numerical methods.
        * In particular, in iterative methods for solving systems of linear algebraic equations,
        * they are used to determine the error of the solution found at each iteration.
        *
        * As a rule, three types of norms are used.
        */

        // norm_M = max(Summ_j->[0, n](Abs(a_ij)))
        T NormM() {
            T _max = INT_MIN;
            for (int i = 0; i < size; i++){
                T summ = 0;
                for (int  j = 0; j < size; j++){
                    summ += abs(matrix.Get(i).Get(j));
                }
                if (summ > _max) _max = summ;
            }
            return _max;
        }
        // norm_L = max(Summ_i->[0, n](Abs(a_ij)))
        T NormL() {
            T _max = INT_MIN;
            for (int i = 0; i < size; i++) {
                T summ = 0;
                for (int j = 0; j < size; j++) {
                    summ += abs(matrix.Get(j).Get(i));
                }
                if (summ > _max) _max = summ;
            }
            return _max;
        }
        // norm_K = sqrt(Summ_i->[0, n](Summ_j->[0, n](pow(a_ij, 2))))
        T NormK() {
            T summ_Z0 = 0;
            T summ_Z1 = 0;
            for (int i = 0; i < size; i++){
                summ_Z0 += summ_Z1;
                for (int j = 0; j < size; j++){
                    summ_Z1 += pow(matrix.Get(i).Get(j), 2);
                }
            }
            return sqrt(summ_Z0);
        }

        void ElemTransformOfRows(int row1, int row2, T scalar) {
            Matrix<T> new_matrix;
            for (int i = 0; i < size; i++) {
                ArraySequence<T> element;
                if (i == row1) {
                    for (int j = 0; j < size; j++) {
                        element.Append(matrix.Get(row2).Get(j) * scalar + matrix.Get(row1).Get(j));
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
        void ElemTransformOfCols(int col1, int col2, T scalar) {
            Matrix<T> new_matrix;
            for (int i = 0; i < size; i++) {
                ArraySequence<T> element;
                for (int j = 0; j < size; j++) {
                    if (j == col1) {
                        element.Append(matrix.Get(i).Get(col2) * scalar + matrix.Get(i).Get(col1));
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


        //Перегрузка опреаторов
        Matrix<T>& operator = (Matrix<T> n_matrix) {
            matrix = n_matrix.matrix;
            size = n_matrix.size;
            return *this;
        }
        friend std::ostream& operator << (std::ostream& cout, Matrix<T>& n_matrix) {
            for (int j = 0; j < n_matrix.GetSize(); j++) { // по строкам
                for (int i = 0; i < n_matrix.GetSize(); i++) {
                    cout << n_matrix.Get(j, i) << "   ";
                }
                cout << std::endl;
            }
            cout << std::endl;

            return cout;
        }

    };
}
