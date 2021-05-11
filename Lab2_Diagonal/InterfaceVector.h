#pragma once

#include <iostream>
#include "Vector.h"
#include <complex>

using namespace std;

int chooseType();
int chooseFunction();
template<class T>
void saveVector(ArraySequence<Vector<T>>* Arr, Vector<T>* n_vector);

void InterfaceVector();
//1
void inputAndSaveVector(ArraySequence<Vector<int>>* intArr,
    ArraySequence<Vector<float>>* floatArr,
    ArraySequence<Vector<complex<int>>>* complexArr);
template <class T>
void inputVectorTyped(ArraySequence<Vector<T>>* Arr, int count);
//2
void functionWithVector(ArraySequence<Vector<int>>* intArr,
    ArraySequence<Vector<float>>* floatArr,
    ArraySequence<Vector<complex<int>>>* complexArr);
template<class T>
void functionVectorTyped(ArraySequence<Vector<T>>* Arr);

//3
void outputVector(ArraySequence<Vector<int>>* intArr,
    ArraySequence<Vector<float>>* floatArr,
    ArraySequence<Vector<complex<int>>>* complexArr);

template<class T>
void outputTypedVector(ArraySequence<Vector<T>>* Arr, int index);



