#include <iostream>
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

    const int size_a = 4;
    int items[size_a] = { 0, 1, 2, 3 };


    DynamicArray<string> Array();
    ArraySequence<float> LL_d();
    LinkedList<int> LL();
    LinkedListSequence<float> LL_c();

    cout << "Hello World!\n";
    return 0;
}