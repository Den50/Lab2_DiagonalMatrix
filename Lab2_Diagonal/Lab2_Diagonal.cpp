#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "complex.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include <string>

using namespace std;
using namespace MAIN;

int main()
{

    const int size_a = 5;
    int* elems = new int[size_a];

    double** items = new double*[size_a];
    for (int i = 0; i < size_a; i++) {
        elems[i] = i * i / 2;
        items[i] = new double[size_a];
    }


    for (int i = 0; i < size_a; i++){
        for (int j = 0; j < size_a; j++)
        {
            items[i][j] = i + j;
        }
    }


    /*DynamicArray<string> Array();
    ArraySequence<float> LL_d();
    LinkedList<int> LL();
    LinkedListSequence<float> LL_c();*/

    //Matrix<double> matrix(items, size_a);
    //matrix.ElemTransformOfRows(1, 2, 5);
    //matrix.ElemTransformOfCols(4, 2, 3);

    ////matrix.NormM();
    //cout << matrix.NormM() << " " << matrix.NormL() << " " << matrix.NormK();
    Vector<int> vec(elems, size_a);

    cout << vec;


    cout << "Hello World!\n";
    return 0;
}