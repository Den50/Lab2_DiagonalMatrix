#include <iostream>
#include "Matrix.h"
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

    int** items = new int*[size_a];
    for (int i = 0; i < size_a; i++)
        items[i] = new int[size_a];


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

    Matrix<int> matrix;
    //cout << matrix;

    cout << "Hello World!\n";
    return 0;
}