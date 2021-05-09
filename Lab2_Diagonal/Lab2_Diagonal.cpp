#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include <string>
//#include <sstream>

using namespace std;
using namespace MAIN;

int main()
{

    const int size_a = 5;
    complex<double>* arr = new complex<double>[size_a];
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


   /*DynamicArray<complex<double>> Array(arr, size_a);
   Array.Set(0, 2. + 9i);
   Array.Set(1, 6. + 1i);

   for (int i = 0; i < Array.GetSize(); i++)
   {
       cout << Array.Get(i) << endl;
   }*/

     /*ArraySequence<float> LL_d();
    LinkedList<int> LL();
    LinkedListSequence<float> LL_c();*/

    //Matrix<double> matrix(items, size_a);
    //matrix.ElemTransformOfRows(1, 2, 5);
    //matrix.ElemTransformOfCols(4, 2, 3);

    ////matrix.NormM();
    //cout << matrix.NormM() << " " << matrix.NormL() << " " << matrix.NormK();
    Vector<int> vec(elems, size_a);

    //cout << vec;

    std::string s = "123, 5.3";//input

    std::istringstream is('(' + s + ')');
    std::complex<float> c;
    is >> c;

    std::cout << "the number is " << c << "\n" << c.real() << "  " << c.imag();

    

    cout << "Hello World!\n";
    return 0;
}