#include <iostream>
#include "complex.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include <string>

using namespace std;
using namespace MAIN;

int main()
{
    /*const int size_c = 1;

    DynamicArray<float> dyn_string(size_c);
    DynamicArray<float> dyn_string1();
    dyn_string.Set(0, 4.1);
    dyn_string.Set(1, 2.2);

    DynamicArray<float> dyn_string_cpy(dyn_string);

    dyn_string_cpy.Print();*/
    const int size_a = 4;
    int items[size_a] = { 0, 1, 2, 3 };

    LinkedList<int> LL;
    LL.Append(4);
    LL.Prepand(-1);
    LL.Prepand(-2);
    LL.Prepand(-3);
    LL.InsertAt(10, 1);
    LL.Pop();
    //cout << LL.IsEmpty();
    LinkedList<int> LL_cpy(items, size_a);
    //LL_cpy.Concat(&LL);
    //LL_cpy.Append(1);
    /*LL_cpy.Pop();
    LL_cpy.Pop();*/

    //LL.Print();

    LL_cpy.Print();
    //LL_cpy.Print();
    /*for (int i = 0; i < 2; i++)
    {
        cout << LL_cpy.GetSubList(0, 2)->Get(i) << endl;
    }*/
    //cout << LL.GetFirst() << "  " << LL.GetLast();
    //LL.Append(12);

    //dyn_string_cpy.Print();

    cout << "Hello World!\n";
}