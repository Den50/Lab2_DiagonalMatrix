#include <iostream>
#include "complex.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    int size = 10;
    int arr[10] = { 0 };
    DynamicArray<int> dyn(arr, size);

    for (int i = 0; i < dyn.GetSize(); i++)
    {
        cout << dyn.Get(i);
    }
    

    std::cout << "Hello World!\n";
}