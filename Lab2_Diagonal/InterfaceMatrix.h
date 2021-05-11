#pragma once

#include "Matrix.h"
#include <complex>
#include <iostream>

using namespace std;

int chooseTypeMatrix();
int chooseFunctionMatrix();
void InterfaceMatrix();

//1
void inputAndSaveMatrix(ArraySequence<Matrix<int>>* intArr,
    ArraySequence<Matrix<float>>* floatArr,
    ArraySequence<Matrix<complex<int>>>* complexArr);
template <class T>
void inputMatrixTyped(ArraySequence<Matrix<T>>* Arr, int count);
//2
void functionWithMatrix(ArraySequence<Matrix<int>>* intArr,
    ArraySequence<Matrix<float>>* floatArr,
    ArraySequence<Matrix<complex<int>>>* complexArr);
template<class T>
void functionMatrixTyped(ArraySequence<Matrix<T>>* Arr);
//3
void outputMatrix(ArraySequence<Matrix<int>>* intArr,
    ArraySequence<Matrix<float>>* floatArr,
    ArraySequence<Matrix<complex<int>>>* complexArr);
template<class T>
void outputTypedMatrix(ArraySequence<Matrix<T>>* Arr, int index);
